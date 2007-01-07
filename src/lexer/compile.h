/* compile.h - Compile an automaton
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

#ifndef COMPILE_H
#define COMPILE_H

#include "types.h"

typedef void (*dfa_state_to_void_t)(dfa_state_t);

void_to_ui_t
compile_dfa_automaton (dfa_automaton_t automaton,
		       dfa_state_to_void_t compile_get_next,
		       void_to_void_t compile_ungetc
		       );


/* For a string. Et ca fera une bonne introduction a ldi, ldxi et extr
   et sti. Et a l'integration C/assembleur.  Evidememnt on pourrait
   utiliser getc, mais plus tard il vaut mieux mmaper le fichier en
   memoire, donc ca reviendra aux strings. */
void
compile_get_next_string (dfa_state_t state);

#endif
