/* list_set.h - Operations on lists and sets
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

#ifndef LIST_SET_H
#define LIST_SET_H

#include "article2.h"
#include <stdio.h>

#include "../objects/pair.h"


#if 0

typedef struct pair
{
  //  void *car;
  struct thompson_state *car;
  struct pair *cdr;
} *pair_t;

#define MAKE_PAIR(elem1, elem2)			\
  ({pair_t pair = MALLOC(pair);			\
    pair->car = elem1;				\
    pair->next = elem2;				\
    (void *) pair;})

#define CAR(pair)				\
  (((pair_t)pair)->car)

#define CDR(pair)				\
  (((pair_t) pair)->cdr)



#endif

pair_t
copy_list (pair_t list);

bool
member (void *element, pair_t list);


/* Set specific.  */

/* A set is just an ordered list.  */
typedef pair_t set_t;

set_t
union_set (set_t set1, set_t set2);

set_t
insert_set (void *element, set_t set);

void
display_set (set_t set);

void
display_set_file (FILE *file, set_t set);

/* Could be a cool convention, instead of the trailing p, to use is_
   or has_ for predicates. */
bool
is_equal (pair_t list1, pair_t list2);

#endif
