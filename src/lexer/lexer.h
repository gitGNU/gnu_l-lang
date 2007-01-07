/* lexer.h - Interface to the lexical scanner.
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

#ifndef _LEXER_H
#define _LEXER_H

#include "nfa.h"
#include "determinize.h"
#include "compile.h"
#include "../memory/code.h"

/* XXX: we can't make a function of this because we cannot pass the
   arguments back to  make_scanner_automaton */

/* Makes a string scanner.  The string scanner is a void_to_uit_t
   function which scans NB regular expressions provided as variadic
   arguments, starting the scanning from the char *pointer whose
   address is STRING_PTR, and returning a number corresponding to the
   matched regular expressions.

   If CAN_INTERSECT is false, then the regular expressions languages
   cannot intersect, and the number returned is the position in the
   regular expression list, starting at 1.

   If CAN_INTERSECT is true, the number returned is a bitwise-OR of
   2^{position in the regular expression list}.

   In both case, 0 is returned if no match is found.
   */
#define make_string_scanner(string_ptr, can_intersect, nb, ...)		\
  ({char **_my_string_ptr = string_ptr;					\
    void								\
      _my_compile_get_next_string (dfa_state_t state)			\
    {									\
      jit_ldi_p (JIT_R1, _my_string_ptr);				\
      jit_ldr_uc (JIT_R0, JIT_R1);					\
      jit_extr_uc_ui (JIT_R0, JIT_R0);					\
									\
      jit_addi_p (JIT_R1, JIT_R1, 1);					\
      jit_sti_p (_my_string_ptr, JIT_R1);				\
    }									\
									\
									\
    void								\
      _my_compile_ungetc (void)						\
    {									\
      jit_ldi_p (JIT_R1, _my_string_ptr);				\
      jit_subi_p (JIT_R1, JIT_R1, 1);					\
      jit_sti_p (_my_string_ptr, JIT_R1);				\
    }									\
    thompson_automaton_t _my_automaton;					\
    _my_automaton = make_scanner_automaton (can_intersect, nb,		\
					    __VA_ARGS__);		\
    display_automaton (_my_automaton);					\
    dfa_state_t _dfa_states = determinize (_my_automaton);		\
    display_dfa_automaton (_dfa_states);				\
    dfa_automaton_t _dfa_automaton = indexate_automaton (_dfa_states);	\
    void_to_ui_t fun;							\
    fun = compile_dfa_automaton (_dfa_automaton,			\
				 _my_compile_get_next_string,		\
				 _my_compile_ungetc);			\
fun;})




#endif
