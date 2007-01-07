/* list_set.c - Operations on lists and sets
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

#include "list_set.h"

pair_t
copy_list (pair_t list)
{
  pair_t newlist, *curnew = &newlist;
  pair_t iter;
  //  for(iter = &list; *iter; iter = &((*iter)->cdr);
  for(iter = list; iter; iter = iter->cdr)
    {
      *curnew = MALLOC (pair);
      (*curnew)->car = iter->car;
      curnew = &((*curnew)->cdr);
    }

  *curnew = NULL;
  
  return newlist;
}

bool
member (void *element, pair_t list)
{
  pair_t iter;

  for(iter = list; iter; iter = iter->cdr)
    {
      if(CAR (iter) == element)
	return true;
    }
  return false;
}

/* Could be a cool convention, instead of the trailing p, to use is_
   or has_ for predicates. */
bool
is_equal (pair_t list1, pair_t list2)
{
  pair_t iter1= list1, iter2 = list2;
  
  while (iter1 && iter2)
    {
      if (CAR (iter1) != CAR (iter2))
	return false;

      iter1 = CDR (iter1);
      iter2 = CDR (iter2);
    }

  if (iter1 || iter2)
    return false;

  return true;
}

bool
is_set (pair_t list)
{
  error (1,1,"unimplemented");
  return true;
}



/* Les thompson_state_list sont des ensembles et pas des listes. */
/* On pourrait la garder triee ca serait quand meme plus rapide. */
/* Meme si on modifie sur place, il faut reaffecter car on a pu
   modifier le premier element.  */
pair_t
my_insert_set (void *element, pair_t list)
{
  pair_t all = list;
  pair_t *iter;
  for (iter = &all; *iter; iter = &((*iter)->cdr))
    {
      if ((*iter)->car == element)
	return all;
    }

  *iter = MALLOC (pair);
  (*iter)->cdr = NULL;
  (*iter)->car = element;
  return all;
}

set_t
insert_set (void *element, set_t list)
{
  pair_t all = list;
  pair_t *iter = &all;

  while (true)
    {
      if ((*iter) == NULL)
	break;
      
      if ((*iter)->car == element)
	return all;

      if ((*iter)->car > element)
	break;
      
      iter = &((*iter)->cdr);
    }
	
  *iter = MALLOC (pair);
  (*iter)->cdr = NULL;
  (*iter)->car = element;
  return all;
}

set_t
union_set (set_t set1, set_t set2)
{
  pair_t set = copy_list (set1);

  pair_t iter = set2, iter_next;;

  while (iter)
    {
      iter_next = iter->cdr;
      set = insert_set (iter->car, set);
      iter = iter_next;
    }
  return set;
}

void
display_set_file (FILE *file, set_t set)
{
  fprintf (file, "{");

  pair_t iter = set;
  for (iter = set; iter; iter = CDR (iter))
    {
      fprintf (file, "%p ", iter->car);
    }

  fprintf (file, "}");
}

void
display_set (set_t set)
{
  display_set_file (stdout, set);

  printf ("\n");
}
