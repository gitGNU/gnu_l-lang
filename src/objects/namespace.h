/* namespace.h - Namespace handling.
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

#ifndef _NAMESPACE_H
#define _NAMESPACE_H

#include "symbol.h"

/* A namespace is just a symbol table (containing all the symbols in
   the namespace) and some additional informations.  */


typedef struct namespace
{
  /* The symbol table containing all the symbols in the namespace.  */
  symbol_table_t symbol_table;

  /* XXX: Namespaces should have a symbol for accessing the namespace from L. */
  symbol_t handle;
} *namespace_t;


/* The symbol table containing the namespaces symbol.  */
extern symbol_table_t namespace_table;

/* The namespace for L objects.  */
extern namespace_t l_namespace;

/* The namespace for C objects.  */
extern namespace_t c_namespace;

/* The namespace for user objects (default namespace for user programs).  */
extern namespace_t user_namespace;

/* A list of current "using" namespaces */

/* A pointer to the current namespace.  */
extern namespace_t default_namespace;


/* Define INTERN, INTERN_INTO, FIND_SYMBOL, FIND_SYMBOL_INTO */
/* Should even be functions. */


symbol_t
intern_into (const char *string, namespace_t ns);

symbol_t
internn_into (const char *string, size_t n, namespace_t ns);

symbol_t
intern (const char *string);

/* Same as intern, but use only the first n characters.*/
symbol_t
internn (const char *string, size_t size);

symbol_t
find_symbol_into (const char *string, namespace_t ns);

symbol_t
find_symbol (const char *string);

/* Initialize the namespace subsystem.  */
void
init_namespace (void);

//extern const type_t __type_namespace;


#endif
