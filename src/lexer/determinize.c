/* determinize.c - Determinize an automaton
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

#include "transitions.h"
#include "character_set.h"
#include "article2.h"
#include "nfa.h"
#include <assert.h>

#include "determinize.h"
//typedef dfa_state_t dfa_automaton_t;
#undef CONS
#define CONS(element, list)			\
  ({typeof (element) element_ = element;	\
    element_->next = list;			\
    element_;})

#undef FOREACH
#define FOREACH(element, list)				\
  for(element = list; element; element = element->next)


/* Cherche state dans state_list, et si il n'y est pas, retourne NULL */
dfa_state_t
find_state (thompson_state_list_t state_list, dfa_state_t all_states)
{
  dfa_state_t cur;

  FOREACH (cur, all_states)
    {
      if(is_equal (cur->states, state_list))
	return cur;
    }

  return NULL;
}

/* Cree un etat, mais pas ses transitions.  */
dfa_state_t
create_state (thompson_state_list_t state_list, dfa_state_t *all_states)
{
  assert (find_state (state_list, *all_states) == NULL);
  if(state_list)
    {
      if (state_list->car == NULL)
	asm("jmp 0");
    }
  
  dfa_state_t new_all;
  new_all = MALLOC (dfa_state);
  new_all->states = state_list;
  new_all->next = *all_states;
  
  *all_states = new_all;
  return new_all;
}

  #undef MAKE_PAIR

#define MAKE_PAIR(elem1, elem2)			\
  ({pair_t pair = MALLOC(pair);			\
    pair->car = elem1;				\
    pair->cdr = elem2;				\
    pair;})



/* Calcule la list_transition de l'epsilon closure de l'etat.  Calcule
   aussi l'epsilon closure de l'etat. */
void
make_eclosure_list_transition (thompson_state_t state)
{
  transition_t transition;
  thompson_state_list_t epsilon_closure = MAKE_PAIR (state, NULL);
  list_transition_t e_closure_transitions = NULL;
  unsigned int terminal = 0;
  
  /* On le marque comme etant en train d'etre fait. */
  
  FOREACH (transition, state->transitions)
    {
      if (transition->character == EPSILON)
	{
	  if (!transition->state->epsilon_closure)
	    {
	      assert (!transition->state->e_closure_transitions);
	      make_eclosure_list_transition (transition->state);
	    }

	  /* Rajoute l'epsilon closure de l'etat cible en gardant la
	     liste triee. XXX non bien plus complique que ca. */
	  e_closure_transitions =
	    merge_list_transition_into (transition->state->e_closure_transitions,
					e_closure_transitions);
	  epsilon_closure = union_set (epsilon_closure,
				       transition->state->epsilon_closure);

	  /* XXX: on peut ici faire sois reconnaitre differents
	     langages en meme temps, sois reconnaitre qu'un etat peut
	     appartenir a plusieurs langages: pas bien. */
	  terminal |= transition->state->terminal;
	}
      else
	{
	  /* Rajoute nos propres transitions a l'eclosure list. */
	  e_closure_transitions =
	    merge_list_transition_into (make_list_transitions (transition),
					e_closure_transitions);
	}
    }

  state->e_closure_transitions = e_closure_transitions;
  state->epsilon_closure = epsilon_closure;
  state->terminal |= terminal;
  

  /* XXX: est ce que ca peut etre fait maintenant? Je pense oui.
     En tout cas pas avant sinon on boucle.
     */
  FOREACH (transition, state->transitions)
    {
      if(transition->character != EPSILON)
	{
	  /* Et on cree les epsilon_closure_transitions de ces
	     autres. */
	  if (!transition->state->epsilon_closure)
	    {
	      assert (!transition->state->e_closure_transitions);
	      make_eclosure_list_transition (transition->state);
	    }
	}
    }
}

/* XXX: il faut faire l'union des epsilon closures des states que l'on
   trouve. */

void
recursive_fun (dfa_state_t state, dfa_state_t *all_states)
{
  /* XXX ca va pas.  On va pas faire la reunion de tous les etats de
     l'epsilon closure puisqu'on l'a deja faite.  C'est pourquoi la
     liste d'etat ne va pas comporter tous les elements de l'epsilon
     closure, mais juste les etats d'arrivee des fleches, et ceux ci
     contiennent deja toutes les informations utiles. */

  /* Il faudra quand meme voir si l'etat final dans l'epsilon closure
     et ca dira si l'etat est final ou non.  */
  
  /* Etape 1: on a les transitions de chaque etat de la liste d'etats.
     Il faut encore les merger.
  */

  list_transition_t transitions = NULL;
  
  pair_t iter;

  unsigned int terminal = 0;
  
  for (iter = state->states; iter; iter = CDR (iter))
    {
      thompson_state_t nfa_state = CAR (iter);

//      printf ("Transitions:\n");
//      display_list_transition (transitions);
//      printf ("E closure :\n");
//
//      display_list_transition (nfa_state->e_closure_transitions);
//      printf ("New transitions :\n");
//
      transitions = merge_list_transition_into (transitions,
						nfa_state->e_closure_transitions);
      if (nfa_state->terminal)
	terminal = nfa_state->terminal;

      //      display_list_transition (transitions);
      
    }

  state->transitions = NULL;
  state->terminal = terminal;
  
  list_transition_t transition;
  
//  printf ("---------------\nEtat %p :\n", state);
//  display_set (state->states);
//  display_list_transition (transitions);
//  
  FOREACH (transition, transitions)
    {
      dfa_state_t to_state;
      if ((to_state = find_state (transition->states, *all_states)))
	{
	  dfa_transition_t dfa_transition = MALLOC (dfa_transition);
	  dfa_transition->character = transition->character;
	  dfa_transition->state = to_state;

	  state->transitions = CONS (dfa_transition, state->transitions);
	}
      else
	{
	  to_state = create_state (transition->states, all_states);
	  /* XXX: rajouter une dfa_transition.  */

	  dfa_transition_t dfa_transition = MALLOC (dfa_transition);
	  dfa_transition->character = transition->character;
	  dfa_transition->state = to_state;
	  state->transitions = CONS (dfa_transition, state->transitions);

	  recursive_fun (to_state, all_states);
	}
    }
}

  

dfa_state_t 
determinize (thompson_automaton_t automaton)
{

  /* Computes all the epsilon closures and transitions for each
     state.  */
  make_eclosure_list_transition (automaton->initial);

  /* The list of all states in the new automaton.  */
  dfa_state_t all_states = NULL;

  dfa_state_t initial_state = create_state (MAKE_PAIR (automaton->initial, NULL),
					     &all_states);

  


  recursive_fun (initial_state, &all_states);
  

  /* The initial state is so the last in the list.  */

  
  /* Maintenant, on peut gicler l'ancien automate.  */

  /* Il ne faut pas gicler les anciens character_set_t car on les a
     repris. */

  /* En fait c'est ici qu'on devrait indexer et passer sous forme de
     tableau.  */

  /* Ici, assert que le premier element est bien l'initial state. */
  return all_states;
}

void
display_dfa_automaton (dfa_state_t automaton)
{
  FILE * file = fopen ("out2.dot","w");
  fprintf (file, "digraph dfa_automaton {\n");

  dfa_state_t state;
  //  struct dfa_state const * state;

  FOREACH (state, automaton)
    {
      fprintf (file, "\"%p\" [label=\"%p ", state, state);
      display_set_file (file, state->states);
      if(state->terminal)
	fprintf (file, "\" color=green];\n");
      else
	fprintf (file, "\"];\n");

      dfa_transition_t transition;
      FOREACH (transition, state->transitions)
	{
	  fprintf (file, "\"%p\" -> \"%p\" [label=\"", state, transition->state);
	  display_character_set_file (file, transition->character);
	  fprintf (file, "\"];\n");
	}
    }

  fprintf (file, "};\n");
  fclose (file);
}

dfa_automaton_t
indexate_automaton (dfa_state_t state_list)
{
  dfa_state_t state;
  unsigned int index = 0;
  
  FOREACH (state, state_list)
    {
      state->index = index++;
    }

  /* XXX OK, this is ugly. */
  unsigned int size = index;

  FOREACH (state, state_list)
    {
      state->index = size - 1 -  state->index;
    }

  
  dfa_state_t *table = CALLOC (index, dfa_state_t);

  /* XXX: dans cet ordre pour que le premier soit l'element initial. */
  FOREACH (state, state_list)
    {
      table[--index] = state;
    }

  assert (index == 0);
  dfa_automaton_t automaton = MALLOC (dfa_automaton);
  automaton->states = table;
  automaton->nb_states = size;
    
  return automaton;
}


/* Etapes:

   1/On parcoure le nfa, et pour chaque etat on calcule la
   transition_list de son epsilon closure.

   2/On applique l'algo suivant sur l'epsilon closure de l'etat initial:

   En gros on merge les transitions lists pour chaque etat compose.

 */





//
//int
//main (int argc, char **argv)
//{
//  char *regexp = "[fgh]([ab]|z)+([cd]e)*";
//
//  thompson_automaton_t automaton = parse_regexp (regexp);
//  
//  printf ("hello\n");
//
//  return 0;
//}
