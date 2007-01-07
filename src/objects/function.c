/* function.c - Function handling.
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

#include <string.h>
#include "function.h"
#include "symbol.h"
#include "../memory/memory.h"
//#include "object.h"
#include "type.h"
#include "namespace.h"

struct type __type_function_;

const Type __type_function = &__type_function_;

struct type __type_compiling_function_;

const type_t __type_compiling_function = &__type_compiling_function_;

struct type __type_generic_;

const Type __type_generic = &__type_generic_;


struct type __type_boolean_relation_;

const type_t __type_boolean_relation = &__type_boolean_relation_;


extern symbol_table_t l_symbol_table; 

#if 0
static void
write_function (object_t function_)
{
  DEBUG_CHECK_TYPE (function_, function);
  printf ("<function>");
}

static void
write_compiling_function (object_t function_)
{
  DEBUG_CHECK_TYPE (function_, compiling_function);
  printf ("<compiling-function>");
}

static void
write_boolean_relation (object_t function_)
{
  DEBUG_CHECK_TYPE (function_, boolean_relation);
  printf ("<boolean-relation>");
}
#endif

void
init_function (void)
{
  char *fun = strdup ("function");
  char *cfun = strdup ("compiling_function");
  char *bfun = strdup ("boolean_relation");
  char *gfun = strdup ("generic");
  
  symbol_t fun_sym = intern_into (fun, l_namespace);
  symbol_t cfun_sym = intern_into (cfun, l_namespace);
  symbol_t bfun_sym = intern_into (bfun, l_namespace);
  symbol_t gfun_sym = intern_into (gfun, l_namespace);
  
  //__type_function_.name = fun;
  //  __type_function_.writer = write_function;
  __type_function_.size = 0;
  
  //  __type_compiling_function_.name = cfun;
  //  __type_compiling_function_.writer = write_compiling_function;
  __type_compiling_function_.size = 0;

  //  __type_boolean_relation_.name = bfun;
  //  __type_boolean_relation_.writer = write_boolean_relation;
  __type_boolean_relation_.size = 0;

  __type_generic_.size = 0;
}
