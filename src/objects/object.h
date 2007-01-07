/* object.h - Operations on objects
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

#ifndef _OBJECT_H
#define _OBJECT_H

#error "Nobody should use this anymore"

//
//typedef struct object
//{
//  unsigned int object_info; 	/* XXX: is in fact a bitfield.  */
//
//  /* Je mettrait bien dans object_info un pointeur sur le type, avec
//     le tout dernier bit pour le mark and sweep du garbage
//     collection, et l'avant dernier dit si une allocation est "untyped",  */
//  
//  /* XXX: ici on pourrait faire une union des structs courantes, en
//     les declarant comme 0-sized arrays.  */
//  
//} *object_t;//

typedef void * object_t;

#include <Judy.h>

/* XXX: For now we use a JudyL for type information, but it would be
   better if we could use the word before the pointer instead, but
   this would cause problems with the GC.  */

/* Du coup on stocke le pointeur après, et on dit ou il est dans une
   table de correspondance. Ca permet au moins de tester le
   concept. */
extern Pvoid_t _object_type;

/* For simple objects, you can just pass the type name (e.g symbol,
   pair) */
#define CREATE_OBJECT(type)						\
  ({									\
    struct								\
    {									\
      struct type type;							\
      type_t info; /*XXX: pas seulement le type, mais aussi le GC etc*/	\
    } *alloc;								\
    /* XXX: Pas xmalloc, mais le malloc avec un GC */			\
    alloc = xmalloc (sizeof (*alloc));					\
    type_t **p_value;							\
    /* XXX: il faut un finalizer pour nettoyer la table object_type. */ \
    JLI (p_value, _object_type, (Word_t) alloc);			\
    assert (*p_value == NULL);/* Sinon ca veut dire qu'on a mal nettoye */ \
    *p_value = &(alloc->info);						\
    alloc->info = TYPE(type);						\
    /*    alloc->object = 0;*/ 		/* XXX: put type info. Il suffit */ \
    /*d'avoir un enum avec les differents */				\
    /*			   types? */					\
(type##_t) alloc;})

/* For complex objects, you have to pass the type_t */
#define CREATE_COMPLEX_OBJECT(type_t)						\
  ({									\
    struct								\
    {									\
      struct type type;							\
      struct object object;						\
    } *alloc;								\
    /* XXX: Pas xmalloc, mais le malloc avec un GC */			\
    alloc = xmalloc (sizeof (*alloc));					\
    struct object **p_value;						\
    /* XXX: il faut un finalizer pour nettoyer la table object_type. */ \
    JLI (p_value, _object_type, alloc);					\
    assert (*p_value == 0);/* Sinon ca veut dire qu'on a mal nettoye */ \
    *p_value = &(alloc->object);					\
    /*    alloc->object = 0;*/ 		/* XXX: put type info. Il suffit */ \
    /*d'avoir un enum avec les differents */				\
    /*			   types? */					\
(type##_t) alloc;})





//#define OBJECT_INFO(object)				
//  (object_t) ((char *) object - sizeof (struct object))


/* XXX: c'est pas des void* */

#define PTYPE_OF(object) 		/* Pointer to TYPE_OF. Permet de modifier? */( \
    {type_t **Pvalue;							\
      JLG(Pvalue, _object_type, (Word_t) object);			\
      Pvalue;})

#define TYPE_OF(object)				\
  ({type_t **Pvalue;				\
    Pvalue = PTYPE_OF (object);				\
    type_t value = ((Pvalue != NULL && *Pvalue != NULL) ? **Pvalue : NULL); \
    value;})

#include <assert.h>

#define DEBUG_CHECK_TYPE(object, type)	\
  assert (TYPE_OF (object) == TYPE (type))



/* DEFINE_OBJECT defines two structures: one with and the other
   without the type information.

   On devrait pouvoir faire sans, parce que c'est moche.

   */
//#define DEFINE_OBJECT(nom, contents)		
//  typedef struct nom##_object			
//  {						
//    struct object object_info;			
//    struct contents;				
//  } * nom##object_t;				
//						
//  typedef struct nom				
//  contents					
//  ; *nom##_t;					
//

#include "../memory/memory.h"

#include <assert.h>

/* XXX: Attention a la taile du struct object: il faut etre sur de
   pouvoir recuperer le pointeur. D'ou l'assert*/

/* XXX: il faudra faire des trucs pour etre safe sur les objets
   alloues mais qui n'ont pas d'information en dessous; il suffit que
   quand on fait un MALLOC, a chaque fois on cree un truc pour dire
   que c'est faux.  Sinon on va faire de la merde.
   */

#include "type.h"


#endif
