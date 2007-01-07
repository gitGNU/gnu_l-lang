/* article2.h -- Some definitions. 
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
#ifndef ARTICLE2_H
#define ARTICLE2_H

//#include <lightning.h>

#include "types.h"


/* General. */


#if 0


/* Character set */

typedef enum character_type {CHAR_SET_LETTER, CHAR_SET_INTERVAL,
			     CHAR_SET_NEGATION} character_type_t;


/* XXX: tout declarer static parce qu'en fait tout peut etre inline. */

/* Pourrait etre utilise comme base pour une "super-fast regex
   library".  Encore plus rapide si on arrive a faire de la
   compilation incrémentale (c'est à dire qu'a mesure qu'on tape la
   regexp, on ne fait qu'améliorer l'automate sans tout rechanger).

   Comparer les perf avec PCRE.

   Il faudrait rajouter le support pour la création de groupe ()
   aussi, les operateurs non-greedy
*/

/* Idee: si on veut reconnaitre plusieurs regexp en meme temps, il
   suffit de mettre quand c'est un etat final, un etat final de quelle
   regexp. Donc 0 = etat non final, sinon un champ de bit pour dire a
   quels langages ca appartient (ca fait 32 regexp simultanement,
   c'est pas mal). Et comme ca on peut continuer a utiliser getc, et
   c'est bien plus rapide.

   Faudrait voir si c'est ce que fait flex.
*/


//typedef letter_t (*letter_getter_t)(); /* Fonction qui renvoie la
//					  prochaine lettre. Non
//					  plutot: fonction qui genere
//					  le code a generer pour
//					  recuperer la prochaine
//					  lettre.  Par exemple, ca
//					  peut etre un increment d'un
//					  pointeur. */
//
/* Represente un intervalle []. Un seul charactere a est representé
   par [a].  */



//typedef enum character_type {LETTER, INTERVAL} character_type_t;

typedef struct machin
{
  int truc;
} *machin_t;

typedef struct character_class
{
  character_type_t type;	/* Intervalle ou charactere ou charactere special \d* ou negation de character class. */
  union
  {
    letter_t letter;		/* Pour un seul charactere */
    struct
    {
      letter_t min;
      letter_t max;
    };
  };
  struct character_class *next;
} * character_class_t;

typedef struct transition
{

  character_set_t character;
  struct state *state;
  
  struct transition *next;
} *transition_t;

typedef struct state
{
  unsigned int final;
  transition_t transitions;
  void *patch_list;		/* Liste des patches à appliquer sur l'automate.  */
  void *ip; 			/* Adresse de début. */
  struct state *next;
} *state_t ;

typedef struct patch
{
  struct patch *next;
  jit_insn *ref;
} *patch_t;


/* On devrait plutot appeller ca patch_to_destination */
typedef struct patch_list
{
  patch_t patches;
  state_t state;
  struct patch_list *next;
} *patch_list_t;


/* On va prendre comme convention que le premier etat est l'etat
   initial.  */
typedef struct automaton
{
  state_t state_list;
} *automaton_t;

#endif

//typedef unsigned int (*void_to_ui_t)(void);

#define MAKE_STACK_TYPE(type)			\
  typedef struct type##_stack			\
  {						\
    struct type element__;			\
    struct type##_stack *next;			\
  } * type##_stack_t


#if 0
#define CONS(element, list)			\
  ({typeof (element) element_ = element;	\
    element_->next = list;			\
    element_;})

#define PUSH(element, list)			\
  list = CONS (element, list)

#define POP(list)				\
  ({typeof(list) element = list;		\
    list = list->next;				\
    element;})


#endif

#undef FOREACH
#define FOREACH(element, list)				\
  for(element = list; element; element = element->next)

/* On peut aussi l'appeler new. */
#define MALLOC(type)				\
  (type##_t) xmalloc(sizeof(struct type))

/* On peut aussi l'appeler new. */
#define CALLOC(size, type)			\
  (type *) xmalloc(size * sizeof(type))


/* Non new c'est malloc + initialisation. */
#define NEW(type)				\
  (type##_initialize (MALLOC (type)))

#define DELETE(type, ptr)			\
  (type##_delete (ptr))

#undef FREE_LIST
#define FREE_LIST (ptr)				\
  ({						\
    typeof (ptr) ptr_cur = ptr;			\
						\
while(ptr_cur)					\
  {						\
    typeof (ptr) ptr_next;			\
    ptr_next = ptr_cur->next;			\
    free (ptr_cur);				\
    ptr_cur = ptr->next;			\
  }})

#if 0
patch_t 			/* XXX Plutot patch_list_t?  */
compile_transition(transition_t transition);

patch_list_t
compile_transitions(transition_t transitions);


jit_insn *
compile_character (bool negation, 
		   character_class_t character,
		   state_t state);

#endif
#if 0

#include <error.h>
#include <string.h>

static void *
xmalloc (size_t size)
{
  void * ptr = malloc (size);
  if (ptr == NULL)
    error (1, 1 , "Not enough memory\n");
  memset (ptr, -1, size); 	/* Pour detecter les trucs non initialises.  */
  return ptr;
}


static void *
xrealloc (void *ptr, size_t size)
{
  void * newptr = realloc (ptr, size);
  if (newptr == NULL)
    error (1, 1 , "Not enough memory\n");
  /*  memset (ptr, -1, size);*/ 	
  return newptr;
}
#endif

#endif
