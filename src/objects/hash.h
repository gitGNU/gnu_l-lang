/* hash.h - Hash tables management.
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

#ifndef _HASH_H
#define _HASH_H

#include <Judy.h>
#include "../memory/memory.h"

typedef void * hash_table;
typedef void ** hash_table_t;

#define MAKE_STATIC_HASH_TABLE(hash_table_name)			\
  static hash_table hash_table_name##__ = NULL;			\
  hash_table_t hash_table_name = & hash_table_name##__;


static inline hash_table_t
make_hash_table (void)
{
  hash_table_t ht = xmalloc (sizeof(hash_table));
  *ht = NULL;
  return ht;
}

#if 0
static inline void
init_hash_table (hash_table_t tab)
{
  *tab = NULL;
}
#endif

static inline unsigned int
gethash (void * key, hash_table_t table)
{
  PWord_t Pvalue;
  JLG (Pvalue, *table, (Word_t) key);
  return (Pvalue ? *Pvalue : 0);
}

static inline void
puthash (void * key, void * value, hash_table_t table)
{
  PWord_t PValue;
  JLI (PValue, *table, (Word_t) key);
  *PValue = (Word_t) value;
}

#if 0
/* Key and value must be previously defined.  En fait on peut pas
   definir MAPHASH parce qu'il faut tester PValue au milieu.
   */
#define MAPHASH(key, value, hash)					\
  for(({Word_t key##__ = 0;						\
	PWord_t P##value##__;						\
	JLF (P##value##__, *(hash), key##__);				\
	key = (typeof (key)) key##__;					\
	value = (typeof (value)) *P##value##__; });			\
  ;									\
      ({Word_t key##__ = (Word_t) key;					\
	PWord_t P##value##__;						\
	JLN (P##value##__, *(hash), key##__);				\
	key = (typeof (key)) key##__;					\
	value = (typeof (value)) *P##value##__;				\
      }))
#endif



/* key et PValue must be previously defined.  MAPHASH2 because we
   iterate on the pointer on pvalues, so that we can change them.

   Usage :

   symbol_t depends_on_symbol;
   depends_on_information_t *pvalue;
   hash_table_t hash = symbol->depends_on;

  MAPHASH2 (depends_on_symbol, pvalue, hash)
    {
      printf ("%s %d\n", depends_on_symbol->name, (*pvalue)->type);
      *pvalue = NULL;  Changes the value of the hash.  
    }

   */
#define MAPHASH2(key, Pvalue, hash)					\
  for(({Word_t key##__ = 0;						\
	PWord_t Pvalue##__;						\
	JLF (Pvalue##__, *(hash), key##__);				\
	key = (typeof (key)) key##__;					\
	Pvalue = (typeof (Pvalue)) Pvalue##__; });			\
      (Pvalue);								\
      ({Word_t key##__ = (Word_t) key;					\
	PWord_t Pvalue##__;						\
	JLN (Pvalue##__, *(hash), key##__);				\
	key = (typeof (key)) key##__;					\
	Pvalue = (typeof (Pvalue)) Pvalue##__;				\
      }))


#define remhash(key, table)


#endif
