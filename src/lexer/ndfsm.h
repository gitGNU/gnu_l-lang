/* ndfsm.h - Non deterministic finite state machines
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

#ifndef NDFSM_H
#define NDFSM_H

thompson_automaton_t
thompson_char_set (character_set_t character_set);


thompson_automaton_t
thompson_empty ();

thompson_automaton_t
thompson_or (thompson_automaton_t automaton1, thompson_automaton_t automaton2);

thompson_automaton_t
thompson_seq (thompson_automaton_t automaton1, thompson_automaton_t automaton2);

thompson_automaton_t
thompson_plus (thompson_automaton_t automaton);

thompson_automaton_t
thompson_star (thompson_automaton_t automaton);

#endif
