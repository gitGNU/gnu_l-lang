/* c_to_l.h - Exporting C into L
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

#ifndef _C_TO_L_H
#define _C_TO_L_H

#include "../objects/function.h"
#include <l/sys/hash.h>
#include "backend.h"
#include "../parser/form.h"
#include <l/expand.h>

extern hash_table_t generic_hash;
extern hash_table_t function_hash;

location_t
compile_function_call (generic_form_t form);

#define DEFINE_GENERIC_SYMBOL(symbol__, compiler__)		\
  do {							\
  generic_t generic = MALLOC (generic);			\
  generic->compile = compiler__;			\
  printf("Creationg generic: %s\n", symbol__->name);	\
  puthash (symbol__, generic, generic_hash);	\
 } while(0)


#define TYPE_(string) intern_type (string_to_type_form (string))

#define DEFINE_C_FUNCTION2(name1_, name2_, type_string)			\
  do {									\
    									\
    function_t fn = MALLOC (function);					\
    									\
    fn->address = name2_;						\
    fn->type = intern_type (string_to_type_form (type_string));		\
    fn->has_default_value = 0;						\
    fn->nb_arguments = (fn->type->parameters_type->type_type		\
			== TUPLE_TYPE ?					\
			((Tuple_Type) fn->type->parameters_type)->length \
			: 1);						\
    symbol_t c_function_name = intern (name1_);				\
    fn->name = c_function_name;						\
									\
    puthash (c_function_name, fn, function_hash);			\
    /*DEFINE_GENERIC_SYMBOL (c_function_name, compile_function_call); */\
    define_expander(c_function_name, expand_function);			\
  } while(0)

#define DEFINE_C_FUNCTION(name_, type_string)	\
  DEFINE_C_FUNCTION2 (#name_, name_, type_string)

#define DEFINE_GENERIC(string__, compiler__)		\
  do {							\
  generic_t generic = MALLOC (generic);			\
  generic->compile = compiler__;			\
  puthash (intern (string__), generic, generic_hash);	\
 } while(0)


#endif
