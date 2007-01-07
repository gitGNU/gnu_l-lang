/* pair.h - Operation on pairs.
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

#ifndef _PAIR_H
#define _PAIR_H

//#warning "pair.h"

typedef struct pair *pair_t;

/* A list is really a pair OR nil.  */
typedef pair_t list_t;


//#include "object.h" 

struct pair {
  void *car; /* En fait un object_t */
  union {
    /*object_t*/ void * cdr;
    struct pair *next; 	/* Useful when using GDB */
  };
};

//DEFINE_OBJECT (pair, {
//    object_t car;
//    union {
//      object_t cdr;
//      struct pair *next; 	/* Useful when using GDB */
//    };
//  });

/* XXX: on devrait avoir un moyen de creer des listes facilement en
   partant du début. Ca sera un de mes premiers opérateurs.

   Par exemple:

   pair_t seq(int n) {i = 0; make_list(lambda() {i++})}
   
   */


#define MAKE_PAIR()				\
  CREATE_OBJECT (pair)

//#warning "CONS DEFINED"
#define CONS(elem1, elem2)			\
  ({pair_t pair = MALLOC (pair);			\
    pair->car = (void *) elem1;			\
    pair->cdr = (void *) elem2;			\
    pair;})


#define CAR(pair)				\
  (((pair_t)pair)->car)

#define CDR(pair)				\
  (((pair_t) pair)->cdr)

#define PUSH(elem, list)			\
  ({list = CONS (elem, list);})

#define POP(list)				\
({object_t elem = CAR (list);			\
  list = CDR (list);				\
  elem;})

#undef FOREACH
#define FOREACH(element, list)					\
  for(list_t element = list; element; element = element->next)

#undef FREE_LIST
#define FREE_LIST(list)							\
  ({									\
    list_t element = list;						\
    while (element)							\
      {									\
	list_t element_next = element->next;				\
	xfree (element);						\
	element = element_next;						\
      }})


/* XXX: Je suis pas encore sur de est ce que NIL doit valoir NULL ou
   une valeur. Au moins comme ca on pourra changer plus tard. */
#define NIL NULL


unsigned int
length (list_t list);

list_t
reverse (list_t list);

list_t
nconc (list_t list1, list_t list2);


//#include "type.h"
/* Initialize the pair subsystem.  */
void
init_pair (void);
extern const struct type * __type_pair;



#endif
