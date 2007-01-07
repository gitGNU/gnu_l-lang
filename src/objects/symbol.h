/* symbol.h - Operations on symbols.
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

#ifndef SYMBOL_H
#define SYMBOL_H

#include "../compiler/type.h"
#include "hash.h"

/* For now, a symbol is still a pointer; later it will be just an
   integer.  */
typedef struct symbol
{
  char *name;
} *symbol_t;

typedef symbol_t Symbol;



extern const Type TYPE(symbol);
extern const Type TYPE(quoted_symbol);



/* Interning symbols.  */ 

typedef hash_table_t symbol_table_t;

/* XXX: for the moment we do an intern, but in the feature only one
   intern should be needed, and a global variable should keep the
   symbol value. */
#define SYMBOL(name)				\
  (intern (#name))


#define INIT_SYMBOL_TABLE(sym_table)		\
  (sym_table = (symbol_table_t) NULL)

/* Return the symbol whose name is STRING in SYM_TABLE, creating the
   symbol if needed. STRING must have been malloced and must NOT be
   used after this macro has been used.  */
#define INTERN_IN_SYMBOL_TABLE(string_, sym_table)					\
  ({symbol_t *p_value;							\
    unsigned char *my_string_ = (unsigned char *) string_;		\
      JSLI (p_value, sym_table, my_string_);				\
    if (!(*p_value))							\
      {									\
	*p_value = MALLOC(symbol);					\
	(*p_value)->name = string_;					\
      }									\
    else								\
      {									\
	free (string_);							\
	string_ = (char *) (-1);					\
	  /*(*p_value)->string; Ensure that string won't be used. */	\
      }									\
    *p_value;								\
  })

#define FIND_SYMBOL_IN_SYMBOL_TABLE(string_, sym_table)		\
({symbol_t *p_value;						\
  unsigned char *my_string_ = (unsigned char *) string_;	\
  JSLG (p_value, sym_table, my_string_);			\
  symbol_t ret = (p_value ? *p_value : NULL);			\
  ret;})
//  ret;})

symbol_t
gensym(char *root);


#endif
