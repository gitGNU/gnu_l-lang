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
#include <string.h>



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
