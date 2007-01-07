/* pair.c - Operations on pairs.
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

#include "pair.h"
#include "symbol.h"
#include "../memory/memory.h"
#include "type.h"
#include <string.h>
#include "namespace.h"

struct type __type_pair_;

const struct type *__type_pair = &__type_pair_;

extern symbol_table_t l_symbol_table; 

/* XXX: on devrait faire une fonction "normale" et une fonction pretty
   print. */

#if 0
static void
write_pair (object_t pair_)
{
  DEBUG_CHECK_TYPE (pair_, pair);
  pair_t pair = (pair_t) pair_;
  pair_t curpair;
  
  printf ("(");
  curpair = pair;
  while(TYPE_OF (curpair->next) == TYPE (pair))
    {
      write_object (curpair->car);
      printf (" ");
      curpair = curpair->next;
    }

  write_object (curpair->car);

  if (curpair->next)
    {
      printf (" . ");
      write_object (curpair->next);
    }
  else
    {
      printf (")\n");
    }
//  
//  
//  
//  if(TYPE_OF (pair->car) == TYPE (pair))
//    printf ("\n");
//  printf ("(");
//  write_object (pair->car);
//  if(pair->cdr == NULL)
//    {
//      printf (")\n");
//      return;
//    }
//  
//  if(TYPE_OF (pair->cdr) != TYPE (pair))
//    printf (" . ");
//  
//  write_object (pair->cdr);
//  printf (")");
}
#endif

void
init_pair (void)
{
  char *string = strdup ("pair");
  
  symbol_t pair = intern_into (string, l_namespace);
  //__type_pair_.name = pair;
  //__type_pair_.writer = write_pair;
  __type_pair_.size = sizeof (struct pair);
}



unsigned int
length (list_t list)
{
  
  unsigned int i = 0;
  //  list_t element;
  //  FOREACH (element, list)
  for(list_t element = list; element; element = element->next)
    i++;
  return i;
}

list_t
nconc (list_t list1, list_t list2)
{
  list_t list = list1;
  list_t *plist = &list;
  for (plist = &(list); *plist; plist = &(*plist)->next);

  *plist = list2;

  return list;
}

list_t
reverse (list_t list)
{
  list_t newlist = NULL;

  FOREACH (element, list)
    {
      element->next = newlist;
      newlist = element;
    }

  return newlist;
}
