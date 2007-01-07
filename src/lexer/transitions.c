/* transitions.c - Operations on transitions.
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


/* Pour la gestion de la memoire: a chaque etape on fait un gros
   malloc, et quand on a tout recupere a la phase suivante on peut
   faire un gros free. IL suffit d'avoir un xmalloc1, xmalloc2 etc. */

#include "character_set.h"
#include "article2.h"
#include "nfa.h"

#include <assert.h>

/* XXX: it's not the same cons */
#undef CONS
#define CONS(element, list)			\
  ({typeof (element) element_ = element;	\
    element_->next = list;			\
    element_;})


#undef MAKE_PAIR

#define MAKE_PAIR(elem1, elem2)			\
  ({pair_t pair = MALLOC(pair);			\
    pair->car = elem1;				\
    pair->cdr = elem2;				\
    pair;})

#undef FOREACH
#define FOREACH(element, list)				\
  for(element = list; element; element = element->next)


#if 0
/* Transforme une transition en une transition list. */
list_transition_t
make_list_transition (transition_t transition)
{
  transition_t cur_transition = transition;
  list_transition_t cur;
    
  cur = MALLOC (list_transition);
  cur->character = copy_character_set (cur_transition->character);
  cur->states = MAKE_PAIR (cur_transition->state, NULL);

  cur->next = NULL;
  return cur;
}
#endif

/* Transforme un ensemble de transitions en un ensemble de transitions
   list.

   XXX  Dans les thompson automatons par construction, les characters sets
   sont disjoints, donc la transformation est simple.

   Sinon il faudrait faire gaffe. */
list_transition_t
make_list_transitions (transition_t transition)
{
  transition_t cur_transition;
  list_transition_t all, *cur = &all;

  FOREACH (cur_transition, transition)
    {
      *cur = MALLOC (list_transition);
      (*cur)->character = copy_character_set (cur_transition->character);
      (*cur)->states = MAKE_PAIR (cur_transition->state, NULL);
      cur = &((*cur)->next);
    }

  *cur = NULL;
  return all;
}



//typedef struct thompson_state_list
//{
//  struct thompson_state *car;
//  struct thompson_state_list *cdr;
//} *thompson_state_list_t;




/* C'est O(|from| * |dest|). */
/* Merge deux listes de transition. Si une meme lettre peut aller dans
   plusieurs etats, on l'indique.  */

/* Non en fait c'est pas into, vu que dest peut pas etre reutilisee
   telle quelle non plus, vu que certaines transition vont dans
   plusieurs etats.   */

/* On suppose donc que les character_set de chacune des deux
   list_transitions sont disjoints.  Ca ne marche donc pas pour
   transformer un etat en une liste d'etat propre. */
list_transition_t
merge_list_transition_into (list_transition_t from, list_transition_t dest)
{
  list_transition_t cur_from, cur_dest;
  list_transition_t newdest = NULL;
  FOREACH (cur_from, from)
    {
      character_set_t from_cs = cur_from->character;
      FOREACH (cur_dest, dest)
	{
	  character_set_t intersection =
	    intersection_character_set (cur_from->character, cur_dest->character);

	  if(intersection)
	    {
	      list_transition_t transition = MALLOC(list_transition);
	      transition->character = intersection;
	      transition->states = union_set (cur_from->states,
					      cur_dest->states);
	      newdest = CONS (transition, newdest);

	      character_set_t remaining_from =
		minus_character_set (from_cs, intersection);

	      from_cs = remaining_from;

	      if (from_cs == NULL)
		break; 		/* Les intersections suivantes seront
				   toutes vides.  */
	    }
	}
      if (from_cs)
	{
	  /* Il y a des transitions qui ne vont que dans les etats de from */
	  list_transition_t transition = MALLOC(list_transition);
	  transition->character = from_cs;
	  transition->states = cur_from->states;
	      
	  newdest = CONS (transition, newdest);
	}
    }

  /* Calcule le character set union de toutes les transitions from,
     prend son complementaire, intersecte ca avec tous les dests un a
     un, et a chaque fois ca donne les dest tout seuls.  */
  
  character_set_t cs_from_union = NULL;

  FOREACH (cur_from, from)
    {
      /* XXX: il y a un sens de l'union plus rapide. (une seule
	 insertion).  */
      cs_from_union = union_character_set (cs_from_union, cur_from->character);
    }

  cs_from_union = complement_character_set (cs_from_union);

  FOREACH (cur_dest, dest)
    {
      character_set_t intersection =
	/* XXX: la aussi un sens est surement plus rapide. */
	/* XXX: on petu surement reduire cs_from_union en meme temps.  */
	intersection_character_set (cs_from_union, cur_dest->character);

      if (intersection)
	{
	  /* Il y a des transitions qui ne vont que dans les etats de dest */
	  list_transition_t transition = MALLOC(list_transition);
	  transition->character = intersection;
	  transition->states = cur_dest->states;
	  
	  newdest = CONS (transition, newdest);
	}
    }

  return newdest;
}

void
display_list_transition (list_transition_t lt)
{
  list_transition_t iter;

  FOREACH (iter, lt)
    {
      display_character_set (iter->character);
      printf ("-> (");

      pair_t pair;
      for (pair = iter->states; pair; pair = pair->cdr)
	{
	  printf ("%p ", pair->car);
	}
      printf (")\n\n");
    }
  printf ("\n");
  
}

void
test_merge_list_transition_into ()
{
  char * ptr;
  
  character_set_t character1 = parse_character_set ("[a-g]", &ptr);
  character_set_t character2 = parse_character_set ("[d-k]", &ptr);

  transition_t trans1 = MALLOC (transition);
  transition_t trans2 = MALLOC (transition);

  trans1->character = character1;
  trans2->character = character2;

  trans1->state = (void *) 1;
  trans2->state = (void *) 2;

  trans1->next = NULL;
  trans2->next = NULL;
  
  list_transition_t ltrans1 = make_list_transitions (trans1);
  list_transition_t ltrans2 = make_list_transitions (trans2);
  
  display_list_transition (ltrans1);
  display_list_transition (ltrans2);

  list_transition_t ltrans3 = merge_list_transition_into (ltrans1, ltrans2);

  display_list_transition (ltrans3);

  
  
  //  thompson_automaton_t automaton = parse_regexp ("
}

#if 0
int
main (int argc, char **argv)
{
  //test_merge_list_transition_into ();
  thompson_automaton_t automaton = parse_regexp ("([a-f]|[b-h])");
  //    thompson_automaton_t automaton = parse_regexp ("[a-f]d");
  //  display_automaton (automaton);
  make_eclosure_list_transition (automaton->initial);
				 
  return 0;
}
#endif

#if 0
thompson_state_list_t
epsilon_closure (thompson_state_list_t state_list)
{
  thompson_state_list_t copy = copy_list (state_list);
  thompson_state_list_t cur;
  FOREACH (cur, state_list)
    {
      transition_t transition;
      FOREACH (transition, cur->state->transitions)
	{
	  if (transition->character == EPSILON)
	    push_state (transition->state, copy);
	}
    }
  return copy;
}
#endif
