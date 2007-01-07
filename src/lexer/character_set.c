/* character-set.c - Operations on character sets.
   Copyright (C) 2007 Matthieu Lemerre <racin@free.fr>

   This file is part of the L programming language.

   The L programming language is free software; you can redistribute it 
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.
   
   The L programming language is distributed in the hope that it will be 
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty 
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
   GNU Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public License
   along with the L programming language; see the file COPYING.  If not,
   write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
   Boston, MA  02110-1301  USA.  */


/*
  The internal representation of a character set is a sorted list of
  disjoints intervals.
  */

/* XXX: a la compilation, si un des trucs de depart est 0 ou 255, pas
   besoin de le tester en fait.

   C'est surtout important si une des transitions est '.'
   */

#include "article2.h"
#include <assert.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>

#include "character_set.h"


#define MIN(a,b) (a<b ? a : b)
#define MAX(a,b) (a>b ? a : b)

void
display_character_set (character_set_t character_set);

character_set_t
copy_character_set (character_set_t char_set)
{
  character_set_t cur_cs, all_copy, *cur_copy = &all_copy;
  
  FOREACH (cur_cs, char_set)
    {
      *cur_copy = MALLOC (character_set);
      (*cur_copy)->min = cur_cs->min;
      (*cur_copy)->max = cur_cs->max;
      cur_copy = &((*cur_copy)->next);
    }
  *cur_copy = NULL;
  return all_copy;
}

/* Returns a new set, union of the two passed as arguments.
   If possible, char_set1 should be the bigger char_set.
   
   In fact, char_set2 need not to be sorted. (but this will change later)

   TODO: a faster version using the fact that the two character sets
   are all ready sorted.
*/
character_set_t
union_character_set (character_set_t char_set1, character_set_t char_set2)
{
  
  /* We need this because we need the previous. */
  struct character_set fake;
  /* Ca va poser des problemes avec les intervalles qui commencent par 1. */
  fake.min = 0;
  fake.max = -2;

  fake.next = copy_character_set (char_set1);
  character_set_t char_set = copy_character_set (char_set2);
  
  character_set_t cur = char_set;

  while(cur)
    {
      
      character_set_t cur_next = cur->next; /* We will change cur. */

      character_set_t previous = &fake;
      
      while (true)
	{
	  if(previous->next == NULL || cur->min < previous->next->min)
	    {
	      
	      letter_t min = cur->min, max = cur->max;
	      character_set_t next = previous->next;

	      character_set_t to_modify;
	      
	      if ((signed int) cur->min <= (signed int) previous->max + 1)
		{
		  /* We need to merge with the previous.  */
		  assert (previous != &fake);

		  //		  printf ("Need merge\n");
		  /* In this case, we need to change previous to
		     respect the ordering in sorted.  */

		  to_modify = previous;
		  min = previous->min;
		  max = MAX (previous->max, max);
		  free (cur);
		}
	      else
		{
		  to_modify = cur;
		  previous->next = cur;
		}
	      
	      while (next && max >= (next->min) - 1)
		{
		  max = MAX (next->max, max);
		  character_set_t next_next = next->next;
		  free (next);
		  next = next_next;
		}

	      to_modify->min = min;
	      to_modify->max = max;
	      to_modify->next = next;

	      break;
	    }

	  previous = previous->next;
	  //cur_min = previous->min;

	}

      //      printf ("current :");
      //      display_character_set (fake.next);
      cur = cur_next;
    }
  return fake.next;
}

/* Destructive.  */
static character_set_t
sort_character_set (character_set_t char_set)
{
  character_set_t sorted = union_character_set (NULL, char_set);
  free_character_set (char_set);
  return sorted;
}


#if 0
/* On va plutot considerer que tous les characteres sont des
   intervalles, et on n'aura qu'a verifier a la compilation si min =
   max tout simplement. */

/* We need to sort character sets because intesection is then much
   quicker to calculate. Problem is that we don't respect the order of
   the user, which could have chosen to put the most likely characters
   first. Bad luck.

   Good news: we can do some optimisations on character sets (reduce
   and simplify it). */

/* This is destructive. */

/* On peut reutiliser le meme algorithme pour l'union.  En fait cet
   algorithme devrait utiliser l'union non triee. */
static character_set_t
sort_character_set (character_set_t char_set)
{
  /* Sort by insertion, dans l'ordre croissant. */

  /* At each step, none of the elements in sorted can be merged
     together.  */
  
  character_set_t sorted = NULL;
  character_set_t cur;

  //  FOREACH (cur, char_set)
  for (cur = char_set; cur;)
    {
      character_set_t cur_next = cur->next;
      character_set_t *cur_sorted;

      cur_sorted = &sorted;
      while (1)
	{
	  if (*cur_sorted == 0)
	    {
	      /* cur i */
	      *cur_sorted = cur;
	      cur->next = 0;
	      break;
	    }
	  else if (cur->min >= (*cur_sorted)->min)
	    {
	      /* Put this segment after the current, or merge it.   */
	      /* We need to sign the test because *cur_sorted->min can be 0. */
	      if ((signed int) (*cur_sorted)->max >= (signed int) (cur->min) - 1)
		//	      if ((*cur_sorted)->max >= (cur->min) - 1)
		{
		  /* The two intervals can be merged.  */
		  if ((*cur_sorted)->next && (*cur_sorted)->next->min <= cur->max + 1)
		    {
		      /* It can also merges with the follower */
		      (*cur_sorted)->max = (*cur_sorted)->next->max;
		      (*cur_sorted)->next = (*cur_sorted)->next->next;
		      free ((*cur_sorted)->next);
		    }
		  else
		    {
		      (*cur_sorted)->max = MAX ((*cur_sorted)->max, cur->max);
		    }
		  free (cur);
		  break;
		}
	    }
	  else if (cur->max <= (*cur_sorted)->max)
	    {
	      /* Put this segment before the current, or merge it.  */
	      if ((*cur_sorted)->min <= (cur->max) + 1)
		{
		  /* The two intervals can be merged.  */
		  (*cur_sorted)->min = MIN ((*cur_sorted)->min, cur->min);
		  free (cur);
		  break;
		}
	      else
		{
		  /* They can't. Put this one before the other.  */
		  cur->next = *cur_sorted;
		  *cur_sorted = cur;
		  break;
		}
	    }
	  cur_sorted = &((*cur_sorted)->next);
	}
      cur = cur_next;
    }
  return sorted;
}
#endif

void
free_character_set (character_set_t char_set)
{
  character_set_t iter = char_set;

  while(iter)
    {
      character_set_t temp = iter->next;
      free (iter);
      iter = temp;
    }
  /*  */
}


/* Gives the complement character set of ORIGINAL. */
character_set_t
complement_character_set (const character_set_t original)
{
  character_set_t cur;

  character_set_t all_new;
  character_set_t *cur_new;
  
  if (original == NULL)
    {
      all_new = MALLOC (character_set);
      all_new->min = 0;
      all_new->max = 255;
      all_new->next = NULL;
      return all_new;
    }

  if (original->min != 0)
    {
      all_new = MALLOC (character_set);
      all_new->min = 0;
      all_new->max = original->min - 1;
      all_new->next = NULL;
      cur_new = &(all_new->next);

    }
  else
    {
      all_new = NULL;
      cur_new = &all_new;
    }

  letter_t prec = original->max + 1;

  
  FOREACH (cur, original->next)
    {
      *cur_new = MALLOC (character_set);
      (*cur_new)->min = prec;
      (*cur_new)->max = cur->min - 1;
      prec = cur->max + 1;
      cur_new = &((*cur_new)->next);
    }

  if (prec == 256)
    {
      *cur_new = NULL;
    }
  else
    {
      *cur_new = MALLOC (character_set);
      (*cur_new)->min = prec;
      (*cur_new)->max = 255;
      (*cur_new)->next = NULL;
    }
  return all_new;
}

/* TODO: write real optimised function, instead of using
   A and B = comp(comp(A) ou comp(B))
   .  */
character_set_t
intersection_character_set (character_set_t char_set1, character_set_t char_set2)
{
//  printf ("Intersection de \n");
//  display_character_set (char_set1);
//  display_character_set (char_set2);
  
  character_set_t cchar_set1 = complement_character_set (char_set1);
  character_set_t cchar_set2 = complement_character_set (char_set2);

//  printf ("Complements:\n");
//  display_character_set (cchar_set1);
//  display_character_set (cchar_set2);
  
  character_set_t cchar_set = union_character_set (cchar_set1, cchar_set2);
  
//  printf ("Union:\n");
//  display_character_set (cchar_set);
//
  character_set_t char_set = complement_character_set (cchar_set);

//  printf ("Resutat:\n");
//  display_character_set (char_set);

  
  free_character_set (cchar_set1);
  free_character_set (cchar_set2);
  free_character_set (cchar_set);

  return char_set;
}

/* Fait A \ B. */
/* Complement unoptimise.  */
character_set_t
minus_character_set (character_set_t char_set1, character_set_t char_set2)
{
  //  character_set_t intersection = intersection_character_set (char_set1, char_set2);
  //  character_set_t cintersection = complement_character_set (intersection);

  //  free (intersection);

  //  character_set_t result = intersection_character_set (cintersection, char_set1);
  //  free (cintersection);

  character_set_t cchar_set2 = complement_character_set (char_set2);
  character_set_t minus = intersection_character_set (cchar_set2, char_set1);

  free_character_set (cchar_set2);
  
  return minus;
}


#if 0
bool
is_better_character_set_than_complement (character_set_t char_set)
{
  unsigned int count = 0;
  unsigned int comp_count = 0;
  character_set_t iter;
  
  unsigned int last = 0;

  FOREACH (iter, char_set)
    {
      if (iter->min - last == 0)
	assert (iter->min == 0);
      else if (iter->min - last == 1)
	comp_count ++;
      else
	comp_count += 2;

      if (iter->max == iter->min)
	count++;
      else if(iter->max == 255) /* XXX: hard coded 255 */
	count++;
      else
	count += 2;
    }

  //  if (count == comp_count)
  //    {
  //      fprintf (
  return (count < comp_count); 	/* XXX < est bien meilleur que <=: pourquoi? */
}
#endif

/* Tell if a character set is better than its complement.

   We put 2 points for an interval, and 1 for a single-point interval,
   and we tell what is the better, the set or its complement.

   This is useful for having the optimal automaton.

   En fait on devrait compter que 1 pour 0-x et x-255, si on les
   optimise. 0-x est jamais utilise je pense.
   
 */
bool
is_better_character_set_than_complement (character_set_t char_set)
{
  unsigned int count = 0;
  unsigned int comp_count = 1; 	/* UN saut inconditionnel en plus */
  character_set_t iter;
  
  unsigned int last = 0;

  //  return true;
  //  return true;
  /* return false;*/

  /* XXX: si on fait que retourner true,
				   on a un temps de reponse bien
				   meilleur. c'est bizarre. */

  /* Et que false: encore mieux. */

  /* On  doit perdre trop de temps sur cette fonction en fait, car si on fait le return a la fin ca chie aussi.  */
  FOREACH (iter, char_set)
    {
      if (iter->min - last == 1)
	{
	  assert (last == 0 && iter->min == 1);
	  comp_count ++;
	}
      else if (iter->min - last == 0)
	{
	  assert (last == 0 && iter->min == 0);
	}
      else if (iter->min - last == 2)
	comp_count ++;
      else
	{
	//  if(iter->min - last <= 2)
	//    {
	//      fprintf (stderr, "%d %d\n", iter->min, last);
	//      display_character_set_file (stderr, char_set);
	//      assert (iter->min - last > 2);
	//    }
	//  assert (iter->min - last > 2);

	  //	  fprintf (stderr, "plus deux, %d %d\n", iter->min, last);
	comp_count += 2;
	}

      last = iter->max;
      
      if (iter->max == iter->min)
	count++;
      else if(iter->max == 255) /* XXX: hard coded 255 */
	count++;
      else if(iter->min == 0) 	/* XXX: hard coded 0 */
	count++;
      else
	count += 2;
    }

//  if (count == comp_count)
//    {
//      fprintf (stderr, "Ils sont egaux (%d %d)\n", count, comp_count);
//      //      display_character_set_file (stderr, char_set);
//      fprintf (stderr, "\n");
//      //      display_character_set_file (stderr, complement_character_set (char_set));
//      fprintf (stderr, "\n");
//    }


  return (count <= comp_count); 	/* XXX < est bien meilleur que <=: pourquoi? */
}


character_set_t
parse_character_set (char *textual_representation, char **new_ptr)
{
  char *current = textual_representation;

  character_set_t all;
  character_set_t *cur_cs = &all;

  int negate = 0;
  
  switch(*textual_representation)
    {
    case '[':
      current++;
      //      assert (*(current)  != '^'); 	/* Not supported yet.  */
      if (*current == '^')
	{
	  negate = 1;
	  current++;
	}
      
      while(*current != ']')  	/* XXX: quand il est en premier.  */
	{
	  *cur_cs = MALLOC (character_set);
	  (*cur_cs)->min = *current; /* Min and letter are the same field
					of the union.  */
	  if(*(++current) == '-') 	/* C'est ici qu'on incremente current. */
	    {
	      char max = *(++current); 
	      assert (max != ']');	/* Quand - est en dernier c'est permis aussi */
	      (*cur_cs)->max = max;
	      //	  (*cur_cs)->type = CHAR_SET_INTERVAL;
	      current++;
	    }
	  else
	    {
	      //	  (*cur_cs)->type = CHAR_SET_LETTER;
	      (*cur_cs)->max = (*cur_cs)->min;
	    }
	    
	  cur_cs = &((*cur_cs)->next);
	}

      *cur_cs = NULL;
      all = sort_character_set (all);

      break;

#if 0      
    case '.': 			/* XXX: tout sauf newline */
      all = MALLOC (character_set);
      all->next = NULL;
      all->min = 1;
      all->max = 255;
      break;

#else      
      /* Tout sauf newline. Ca c'est pour grep, sinon ca marche pas. */
    case '.':
      all = MALLOC (character_set);
      all->next = MALLOC (character_set);
      all->min = 1;
      all->max = '\n' - 1;
      all->next->next = NULL;
      all->next->min = '\n' + 1;
      all->next->max = 255;
      break;
#endif
      
    default:
      all = MALLOC (character_set);
      all->next = NULL;
      all->min = *current;
      all->max = *current;
      break;
    }

  current++;
  *new_ptr = current;

  if (negate)
    {
      character_set_t cs = complement_character_set (all);
      free_character_set (all);

      /* Ugly hack to remove the 0 */
      if(cs->min == 0)
	cs->min = 1;
      return cs;
    }
  
  return all;
}



/* For debugging.  */
void
display_character_set_file (FILE *fp, character_set_t character_set)
{
  if (character_set == 0)
    {
      fprintf (fp, "\\\\epsilon");
      return;
    }

  if (!is_better_character_set_than_complement (character_set))
    {
      fprintf (fp, "^");
      character_set_t comp = complement_character_set (character_set);
      display_character_set_file (fp, comp);
      free_character_set (comp);
      return;
    }
  character_set_t cur;

  
//  fprintf (fp, "[");
//
//  FOREACH (cur, character_set)
//    {
//      if(cur->min == cur->max)
//	{
//	  if(cur->min == '\n')
//	    fprintf (fp, "\\\\n");
//	  else if(cur->min == 0)
//	    fprintf (fp, "\\\\0");
//	  else if(cur->min == '\\')
//	    fprintf (fp, "\\\\");
//	  else if(cur->min == '"')
//	    fprintf (fp, "\\\"");
//	  else
//	    fprintf (fp, "%c", (char) cur->min);
//	}
//      else
//	{
//	  if(cur->min == '\n')
//	    fprintf (fp, "\\\\n-%c", (char) cur->max);
//	  else if(cur->min == 0)
//	    fprintf (fp, "\\\\0-%c", (char) cur->max);
//	  else if(cur->max == '\n')
//	    fprintf (fp, "%c-\\\\n",(char) cur->min);
//	  else
//	    fprintf (fp, "%c-%c",(char) cur->min, (char) cur->max);
//	}
//      //      if (cur->type == CHAR_SET_INTERVAL)
//	
//	//      else if (cur->type == CHAR_SET_LETTER)
//	//      else
//	//	{
//	//	  assert (cur->type == CHAR_SET_NEGATION);
//	  //	  fprintf (fp, "^");
//	  //	}
//    }
//  fprintf (fp, "]");
//
  fprintf (fp, " (");

  FOREACH (cur, character_set)
    {
      if(cur->min == cur->max)
	fprintf (fp, "%d ", (int) cur->min);
      else
	fprintf (fp, " %d-%d ", (int) cur->min,  (int) cur->max);
      //      if (cur->type == CHAR_SET_INTERVAL)
	
      //      else if (cur->type == CHAR_SET_LETTER)
      //      else
      //	{
      //	  assert (cur->type == CHAR_SET_NEGATION);
      //	  fprintf (fp, "^");
      //	}
    }

  fprintf (fp, ")");
  
  //  fprintf (fp, "\n");

  
}

void
display_character_set (character_set_t character_set)
{
  display_character_set_file (stdout, character_set);
  printf ("\n");
}

/* XXX: [a-bd-gc] n'a pas l'air de marcher. */

#if 0
/* For testing.  */
int
main (int argc, char **argv)
{
  char *ptr = "abcd[a-zfgTg].truc[a]";
//
//  while(*ptr)
//    {
//      character_set_t char_set = parse_character_set (ptr, &ptr);
//      display_character_set (char_set);
//    }
//    
  
  character_set_t char_set = parse_character_set ("[abd-zB-Fg]", &ptr);
  character_set_t char_set2 = parse_character_set ("[cAV-X]", &ptr);
  character_set_t char_set4 = parse_character_set ("[abd-zc-fD-T`]", &ptr);

  display_character_set (char_set);
  display_character_set (char_set2);
  display_character_set (char_set4);

  //  character_set_t char_set3 = union_character_set (char_set, char_set2);
  //  display_character_set (char_set3);

  character_set_t char_set5 = intersection_character_set (char_set, char_set4);
  display_character_set (char_set5);

  character_set_t char_set6 = parse_character_set ("[ce]", &ptr);
  //    character_set_t char_set7 = complement_character_set (char_set6);

  character_set_t char_set8 = intersection_character_set (char_set4, char_set6);
  display_character_set (char_set8);
  
  free_character_set (char_set);
  free_character_set (char_set2);
  free_character_set (char_set4);
  free_character_set (char_set5);
  free_character_set (char_set6);
  free_character_set (char_set8);
  
//  character_set_t char_set9 = parse_character_set (".", &ptr);
//  display_character_set (char_set9);
//
//  character_set_t char_set10 = complement_character_set (char_set9);
//  display_character_set (char_set10);
//
//  character_set_t char_set11 = complement_character_set (char_set10);
//  display_character_set (char_set11);
//
  
  
  //  character_set_t char_set = create_character_set ("[abd-zg]");
  
  //  character_set_t char_set = create_character_set ("[abgd-zB-F]");
  //  character_set_t char_set = create_character_set ("[abcg]");
  //      character_set_t char_set = create_character_set ("[bac]");

  
  //  char_set = sort_character_set (char_set);

  //  display_character_set (char_set);

  printf ("Hello\n");

  return 0;
}
#endif
