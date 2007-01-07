/* namespace.c - Namespace handling.
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

#define _GNU_SOURCE 		/* For strndup */
#include <string.h>

#include "namespace.h"
#include <l/sys/panic.h>

symbol_table_t namespace_table;

static struct namespace l_namespace_, c_namespace_, user_namespace_;

namespace_t l_namespace = &l_namespace_, c_namespace = &c_namespace_,
  user_namespace = &user_namespace_;

namespace_t default_namespace = &l_namespace_;

//struct type __type_namespace_;

//const type_t __type_namespace = &__type_namespace_;

#if 0
static void
write_namespace (object_t namespace_)
{
  DEBUG_CHECK_TYPE (namespace_, namespace);
  panic ("Not yet implemented\n");
}
#endif

void
init_namespace (void)
{
  INIT_SYMBOL_TABLE (namespace_table);
  INIT_SYMBOL_TABLE (l_namespace_.symbol_table);
  INIT_SYMBOL_TABLE (c_namespace_.symbol_table);
  INIT_SYMBOL_TABLE (user_namespace_.symbol_table);

  
  /* XXX: create the symbols for the namespaces.  */
  //__type_namespace_.name = intern_into ("namespace", l_namespace);
  //__type_namespace_.writer = write_namespace;
}

symbol_t
intern_into (const char *string, namespace_t ns)
{
  char *my_string = strdup (string);
  symbol_t symbol = INTERN_IN_SYMBOL_TABLE (my_string,
					    ns->symbol_table);
  return symbol;
}

symbol_t
internn_into (const char *string, size_t n, namespace_t ns)
{
  char *my_string = strndup (string, n);
  symbol_t symbol = INTERN_IN_SYMBOL_TABLE (my_string,
					    ns->symbol_table);
  return symbol;
}


symbol_t
intern (const char *string)
{
  return intern_into (string, default_namespace);
}

/* Same as intern, but use only the first n characters.*/
symbol_t
internn (const char *string, size_t size)
{
  return internn_into (string, size, default_namespace);
}


symbol_t
find_symbol_into (const char *string, namespace_t ns)
{
  return FIND_SYMBOL_IN_SYMBOL_TABLE (string, ns->symbol_table);
}

symbol_t
find_symbol (const char *string)
{
  return find_symbol_into (string, default_namespace);
}
