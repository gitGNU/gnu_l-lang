/* determinize.h - Determinize an automaton
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

#ifndef DETERMINIZE_H
#define DETERMINIZE_H

#include "character_set.h"
#include "nfa.h"

typedef struct dfa_transition
{
  character_set_t character;
  struct dfa_state *state;
  struct dfa_transition *next;
} * dfa_transition_t;

typedef struct dfa_state
{
  thompson_state_list_t states;
  unsigned int terminal;
  dfa_transition_t transitions;
  unsigned int index; 		/* We index each state.  */
//  void *start_ip;  //Les mettre ici ca fait une indirection de moins, mais ca doit pas changer grand chose.
  //  patch_list_t patches;
  struct dfa_state *next;
} *dfa_state_t;

/* L'etat 0 doit etre l'etat initial. */
typedef struct dfa_automaton
{
  dfa_state_t *states;
  unsigned int nb_states;
} *dfa_automaton_t;


dfa_state_t 
determinize (thompson_automaton_t automaton);

dfa_automaton_t
indexate_automaton (dfa_state_t state_list);

#endif
