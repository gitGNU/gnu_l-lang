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

#ifndef NFA_H
#define NFA_H

#define EPSILON ((character_set_t) 0)

#include "transitions.h"
#include "article2.h"

typedef pair_t thompson_state_list_t;

/* XXX: should be renamed nfa_state */
typedef struct thompson_state
{
  transition_t transitions;
  thompson_state_list_t epsilon_closure;
  list_transition_t e_closure_transitions; /* Transitions de l'epsilon
					 closure de l'etat.  En fait
					 je crois qu'on s'en tape un
					 peu de ca, sauf pour savoir
					 si un etat est final ou
					 non. */
  unsigned int terminal; 		/* Donne le numero du langage reconnu
				   si on termine dans cet etat. */
} *thompson_state_t;


//
//typedef struct thompson_state
//{
//  transition_t transitions;
//  transition_t e_closure_transitions; /* Transitions de l'epsilon
//					 closure de l'etat. */
//} *thompson_state_t;

/* A thompson automaton has only one final state, and can have epsilon
   transitions. */
typedef struct thompson_automaton
{
  // thompson_state_t state_list; // Useless in fact, since all states
  // are reachable by following the links.
  thompson_state_t initial;
  thompson_state_t final;
  struct thompson_automaton *next;
} *thompson_automaton_t;

thompson_automaton_t
parse_regexp (char *regexp);

void
display_automaton (thompson_automaton_t thompson);

thompson_automaton_t
make_scanner_automaton (int can_intersect, int nb, ...);

/* thompson_automaton_t */
/* thompson_char_set (character_set_t character_set); */

/* thompson_automaton_t */
/* thompson_empty (); */

/* thompson_automaton_t */
/* thompson_or (thompson_automaton_t automaton1, thompson_automaton_t automaton2); */

/* thompson_automaton_t */
/* thompson_seq (thompson_automaton_t automaton1, thompson_automaton_t automaton2); */

/* thompson_automaton_t */
/* thompson_plus (thompson_automaton_t automaton); */

/* thompson_automaton_t */
/* thompson_star (thompson_automaton_t automaton); */




#endif
