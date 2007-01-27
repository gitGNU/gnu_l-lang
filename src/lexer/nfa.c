/* nfa.c - Operations on NFSM
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

/* XXX: les character sets pourraient servir a d'autres choses en
   fait.  */

#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
//#include <error.h>
//#include <string.h>

#include "character_set.h"

#include "article2.h"

#include "nfa.h"

#undef CONS
#define CONS(element, list)			\
  ({typeof (element) element_ = element;	\
    element_->next = list;			\
    element_;})

#undef POP
#undef PUSH

#define PUSH(element, list)			\
  list = CONS (element, list)

#define POP(list)				\
  ({typeof(list) element = list;		\
    list = list->next;				\
    element;})

#undef FOREACH
#define FOREACH(element, list)				\
  for(element = list; element; element = element->next)



static thompson_state_t
thompson_state_initialize (thompson_state_t state)
{
  state->transitions = NULL;
  state->epsilon_closure = NULL;
  state->e_closure_transitions = NULL;
  state->terminal = 0;
  return state;
}
  

/* Character set is either a character set or EPSILON for epsilon
   transitions.  */
void
add_transition (character_set_t character_set,
		thompson_state_t from_state, thompson_state_t to_state)
{
  transition_t transition = MALLOC (transition);
  transition->character = character_set;
  transition->state = to_state;
  from_state->transitions = CONS (transition, from_state->transitions);
}

thompson_automaton_t
thompson_char_set (character_set_t character_set)
{
  thompson_automaton_t automaton = MALLOC (thompson_automaton);
  thompson_state_t initial = NEW (thompson_state);
  thompson_state_t final = NEW (thompson_state);
  add_transition (character_set, initial, final);

  automaton->initial = initial;
  automaton->final = final;

  return automaton;
}

thompson_automaton_t
thompson_empty ()
{
  thompson_automaton_t automaton = MALLOC (thompson_automaton);
  thompson_state_t initial = NEW (thompson_state);

  automaton->initial = initial;
  automaton->final = initial;

  return automaton;
}

thompson_automaton_t
thompson_paren_marker () 		/* Juste un marqueur special pour les open paren. */
{
  thompson_automaton_t automaton = MALLOC (thompson_automaton);
  automaton->initial = 0;
  automaton->final = (void *) '(';

  return automaton;
}

thompson_automaton_t
thompson_pipe_marker () 		/* Juste un marqueur special pour les '|'. */
{
  thompson_automaton_t automaton = MALLOC (thompson_automaton);
  automaton->initial = 0;
  automaton->final = (void *) '|';

  return automaton;
}

bool
thompson_is_marker (thompson_automaton_t automaton)
{
  if(automaton->initial == 0)
    {
      //      assert (automaton->final == 0);
      return true;
    }
  return false;
}


/* XXX: ne pas allouer un nouvel automate.  */
thompson_automaton_t
thompson_or (thompson_automaton_t automaton1, thompson_automaton_t automaton2)
{
  thompson_automaton_t or_automaton = MALLOC (thompson_automaton);
  thompson_state_t initial = NEW (thompson_state);
  thompson_state_t final = NEW (thompson_state);
  or_automaton->initial = initial;
  or_automaton->final = final;
  add_transition (EPSILON, initial, automaton1->initial);
  add_transition (EPSILON, initial, automaton2->initial);
  add_transition (EPSILON, automaton1->final, final);
  add_transition (EPSILON, automaton2->final, final);
  
  free (automaton1);
  free (automaton2);
  return or_automaton;
}

thompson_automaton_t
thompson_seq (thompson_automaton_t automaton1, thompson_automaton_t automaton2)
{
  thompson_automaton_t seq_automaton = MALLOC (thompson_automaton);
  seq_automaton->initial = automaton1->initial;
  seq_automaton->final = automaton2->final;
  
  add_transition (EPSILON, automaton1->final, automaton2->initial);

  free (automaton1);
  free (automaton2);
  /* We coulde delete only one automaton, and only change the other.
     It would be faster.  */
  return seq_automaton;
}

thompson_automaton_t
thompson_plus (thompson_automaton_t automaton)
{
  add_transition (EPSILON, automaton->final, automaton->initial);
  return automaton;
}

/* Star = ou(empty, +) */
thompson_automaton_t
thompson_star (thompson_automaton_t automaton)
{
  thompson_state_t initial = NEW (thompson_state);
  thompson_state_t final = NEW (thompson_state);
  add_transition (EPSILON, automaton->final, automaton->initial);
  add_transition (EPSILON, initial, automaton->initial);
  add_transition (EPSILON, automaton->final, final);
  add_transition (EPSILON, initial, final);
  automaton->initial = initial;
  automaton->final = final;
  return automaton;
}

/* Truc un peu base sur la méthode des priorités.  */
thompson_automaton_t
parse_regexp (char *regexp)
{
    /* Parse une regexp mise sous forme postfixee. */
  char *current = regexp;

  character_set_t char_set;
  thompson_automaton_t stack = NULL;
  PUSH (thompson_paren_marker (), stack);
  
  while (1)
    {
      //      printf ("current: %c\n", *current);
      //      sleep (0.1);
      
      
      switch(*current)
	{
	  thompson_automaton_t automaton1, automaton2;
	case 0:
	case ')':
	case '|':
	  
	  /* Sequentiate all the elements since the last open
	     parenthesis or start. */
	  //	  assert (stack);
	  //	  assert (stack->next == NULL);

	  automaton2 = POP (stack);
	  assert (automaton2); 	/* XXX: en vrai, on peut utiliser
				   l'automate qui reconnait vide
				   ici. */
	  while(!thompson_is_marker (automaton1 = POP (stack)))
	    {
	      automaton2 = thompson_seq (automaton1, automaton2);
	    }

	  char final = ((char) automaton1->final); /* XXX: une union serait quandmeme plus propre... */
	  free (automaton1);
	  
	  if (final == '|')
	    {
	      automaton1 = POP (stack);
	      automaton2 = thompson_or (automaton1, automaton2);
	    }
	  
	  if (*current == '|')
	    {
	      PUSH (automaton2, stack);
	      PUSH (thompson_pipe_marker (), stack);
	      *current++;
	    }
	  else if(*current)
	    {
	      PUSH (automaton2, stack);
	      current++;
	    }
	  else			/* fin de la regexp */
	    {
	      if(!automaton2 || thompson_is_marker (automaton2))
		{
		  error (1,1, "Malformed regexp\n");
		  asm("jmp 0");
		  exit (1);
		}
	      automaton2->final->terminal = 1; /* XXX: numero de la regexp plutot. */
	      return automaton2;
	    }
	  break;
      
	case '*': automaton1 = POP (stack);
	  automaton1 = thompson_star (automaton1);
	  PUSH (automaton1, stack);
	  current++;
	  break;

	case '+': automaton1 = POP (stack);
	  automaton1 = thompson_plus (automaton1);
	  PUSH (automaton1, stack);
	  current++;
	  break;

	case '(': 
	  PUSH (thompson_paren_marker (), stack); 	/* Marqueur pour indiquer la
						   precedente parenthese.  */
	  current++;
	  break;

	  //	case '|': automaton1 = POP (stack);
	  //	  automaton2 = POP (stack);
	  //	  current++;
	  //	  break;

	case '\\':
	  current++; 		/* Le prochain charactere doit etre
				   traite normalement. */
	  char_set = single_char_character_set (*current);
	  current++;
	  automaton2 = thompson_char_set (char_set);
	  PUSH (automaton2, stack);
	  break;
	  
	default: char_set = parse_character_set (current, &current);
	  //	  automaton1 = POP (stack);
	  automaton2 = thompson_char_set (char_set);
	  PUSH (automaton2, stack);

	    //	  PUSH (thompson_seq (automaton1, automaton2), stack);
	}
    }

  error (1,1, "Never reached\n");
  stack->final->terminal = 1; 	/* XXX: will be the number of the
				   regexp later.  */
  return stack;
}



/* XXX: Peut etre mettre ca dans nfa.c, parce qu'on depend du fait
   qu'on a un thompson automaton quand meme. ou alors faire ca
   independant, en specifiant le numero de la regexp dans
   parse_regexp. */

/* Create a scanner. Takes NB regular expressions (passed as strings)
   as arguments. Returns a scanner function, which takes a pointer to
   a string as an argument, and scans the last token, updating the
   pointer and returning the regexp number.

   If CAN_INTERSECT is true, the languages specified by the regexp can
   intersects (i.e. a word can match several regexp at the same time);
   in that case you can't specify more than 31 regexp, because the
   regexp are numbered 1,2,4,8 etc.., and the word returned is a AND
   of the numbers.

   Else, you can provide up to 2^32 regexps; if the regexps intersect
   make_scanner returns an error.
   */
thompson_automaton_t
make_scanner_automaton (int can_intersect, int nb, ...)
{
  va_list ap;
  int i;

  assert (!can_intersect || nb <= 31);

  thompson_state_t initial = NEW (thompson_state);

  va_start (ap, nb);

  for (i = 1; i <= nb; i++)
    {
      char *regexp = va_arg (ap, char *);
      //      printf ("%d %d %s\n", nb, i, regexp);
      thompson_automaton_t automaton = parse_regexp (regexp);//va_arg (ap, char *));
      add_transition (EPSILON, initial, automaton->initial);
      if (can_intersect)
	automaton->final->terminal = 1 << (i - 1);
      else
	automaton->final->terminal = i;
    }
  //    printf ("%d: %s\n", i, va_arg (ap, char *));

  thompson_state_t final = NEW (thompson_state);
  thompson_automaton_t all_automaton = MALLOC (thompson_automaton);
  all_automaton->initial = initial;
  all_automaton->final = final;
  va_end (ap);

  return all_automaton;
}


void
display_state (thompson_state_t state, FILE *file)
{
  state->epsilon_closure = (void *) 1;
  transition_t transition;
  
  FOREACH (transition, state->transitions)
    {
      fprintf (file, "\"%p\" -> \"%p\" [label=\"", state, transition->state);
      display_character_set_file (file, transition->character);
      fprintf (file, "\"];\n");
    }
  
  FOREACH (transition, state->transitions)
    {
      if(transition->state->epsilon_closure == 0)
	display_state (transition->state, file);
    }
}

void
clean_after_display (thompson_state_t state)
{
  state->epsilon_closure = 0;
  transition_t transition;
  
  FOREACH (transition, state->transitions)
    {
      if(transition->state->epsilon_closure == (void *) 1)
	clean_after_display (transition->state);
    }
}

void
display_automaton (thompson_automaton_t thompson)
{
  FILE * file = fopen ("out.dot","w");
  fprintf (file, "digraph automaton {\n");

  thompson_state_t state = thompson->initial;

  display_state (state, file);

  fprintf (file, "}\n");
  fclose (file);

  clean_after_display (thompson->initial);
}

  




/* Some theory.


   If you have A1 which recognizes L1, and A2 which recognizes L2,
   then you build the automaton which recognizes:

   L1L2 by putting an epsilon-transition between each final state of
   A1 and the initial state of A2.

   L1+ by putting an epsilon transition between the final states of A1
   and the initial state of A1. If moreover you put before the initial
   state of A1 a state which an epsilon transition between the two,
   and declare the first to be initial and final, then you recognize
   L1*.

   L1 U L2 by adding an initial state with 2 epsilon transition from
   it to the initial states of A1 and A2.

   L1? pas dur non plus.

   XXX: non ca c'est faux. Il faut rajouter un etat avec une epsilon
   transition au debut, sinon on risque de reconnaitre de la merde.

   Il y a un automate minimal.

   Construction de Thomson: pas tres dur, voir pdf.

   Direct un truc fini:
   http://www.lifl.fr/~marquet/ens/cu/igrep.html

   Minimisation
   http://fastnet.univ-brest.fr/~gire/COURS/COMPIL_IUP/node207.html
   
   
 */
