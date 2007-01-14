/* string.c - Operation on strings
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

#include <l/string.h>
#include "symbol.h"
#include "../memory/memory.h"
#include "type.h"
#include <string.h>
#include "namespace.h"

struct type __type_string_;

const Type __type_string = &__type_string_;

extern symbol_table_t l_symbol_table;

#if 0
static void
write_string (object_t string_)
{
  DEBUG_CHECK_TYPE (string_, string);
  string_t string = (string_t) string_;
  printf ("\"%s\"", string->value);
}
#endif

void
init_string (void)
{
  char *string_ = strdup ("string");
  
  symbol_t string = intern_into (string_, l_namespace);
  //__type_string_.name = string;
  //  __type_string_.writer = write_string;
  __type_string_.size = 0;
}
