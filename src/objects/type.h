/* type.h - Type objects. 
   Copyright (C) 2006 Matthieu Lemerre <racin@free.fr>

   This file is part of the L programming language.

   The L programming language is free software; you can redistribute
   it and/or modify it under the terms of the GNU Lesser General
   Public License as published by the Free Software Foundation; either
   version 2, or (at your option) any later version.
   
   The L programming language is distributed in the hope that it will
   be useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with the L programming language; see the file COPYING.  If
   not, write to the Free Software Foundation, 675 Mass Ave,
   Cambridge, MA 02139, USA.  */

#ifndef _TYPE_H
#define _TYPE_H

typedef struct type *type_t;

/* For base types. */
#define TYPE(type_name)				\
  __type_##type_name

#if 0
#define DEFINE_TYPE(name__, type__)				\
  {									\
    location_t loc1 = create_location (intern (name__), global_location_table); \
    loc1->location = type__;						\
    loc1->type = TYPE (type);						\
  }
#endif

//#include "object.h"
#include "pair.h"
//#include "../compiler/location.h"
#include "symbol.h"
#include "namespace.h"
#include "../parser/form.h"

#if 0
/* Un type est vraiment un arbre, dont les feuilles sont des types de
   base, et les autres noeuds sont | (type somme), X (type produit),
   -> (fonction), type tableau ... Et en fait c'est meme pas un arbre,
   car il peut être cyclique. 
   */

/* A writer takes an object as an argument, and write its
   representation.  */

//typedef void (*writer_t)(object_t);


/* La fonction creater est appellee si non NULL. Elle peut par exemple
   allouer un objet sur la pile (et augmenter la valeur du stack
   pointer), ou sur le tas, ou par un garbage collector...

   Si la fonction creater est appellee et que taille objet = 0, alors
   on peut etre sur qu'il y aura une allocation sur la pile, dans ce
   cas le compilateur doit agir en consequence. 
   
   */

//typedef void (*setter_t)(location_t, list_t); /* Used for instance by compile_equal.  */
//typedef void (*creater_t)(location_t, list_t); /* Allocate space for an object and eventually affect it.  */
//typedef void (*destructor_t)(location_t); /* Destruct an object at the end of scope, or when garbage collected or freed.  */
//typedef void * creater_t;
/* Really should be typedef void (*creater_t)(location_t, list_t) */


//typedef void (*definer_t)(struct form *, void *);

/* A combination of an offset and a type, for use in struct types.  */
typedef struct offset_type
{
  unsigned int offset;
  type_t type;
} *offset_type_t;
#endif

//An accesser function is really a closure. */
//typedef struct location* (*accesser_t)(form_t form);
typedef struct accesser
{
  struct location* (*accesser_function)(type_t type, struct form * form);
  void *data;
  
} accesser_t;

/* A definer takes a parameter and the initial value.  For instance,
the function definer takes the function name and the function form as
an argument, and compiles the function.

It also patches the previously defined functions which depends on
it.  */

struct type {
  /* Un truc pour le GC. */

  /* Size of the object, or 0 if variable or has to be specially
     handled. (In this case the size of the object is not known, but
     generally the creater function will be called.
     */
  size_t size;

  /* Alignment constraints of the type.  */
  unsigned int alignment;

  /* Symbol naming the type, or NULL if it is an anonymous type.  */
  //  struct symbol *name;

  /* XXX: the name should be given only by the type form.  */

  
  union
  {
    /* Symbol naming the type, for a base type.  */
    struct symbol * base_type_name;

    /* For struct types, the hash table mapping a field to its offset,
       and type of the field.  */
    hash_table_t field_hash;

    /* For array types, the type pointed to, and the size of the array.  */
    struct
    {
      size_t array_size; /* In number of elements.  */

      type_t type_array; 
    };


    /* For function types.  */
    struct
    {
      type_t return_type;

      type_t parameters_type; /* XXX: this one is a tuple type.  */
      //      list_t parameters_type;
    };

    /* For Tuple types.  */
    struct
    {
      /* Number of elements.  */
      unsigned int length;

      type_t *fields;
    };
    
    /* For indirection types */
    struct
    {
      type_t pointed_type;
      /* XXX: max index? Could be useful for arrays, for checking */
    };

  };

  /* A function to print an object of the type.  OBSOLETE.  */
  //writer_t writer;

  /* The function used to create objects of the type.  */
  //definer_t definer;

  /* The function used (at compile time) to create new objects of the type.  */
  //  creater_t creater;

  /* The function used (at compile time) when the object is destroyed.
     NULL if not needed.  */
  //  destructor_t destructor;

  /* The function used (at compile time) when doing an access.  */
  accesser_t accesser;  /* Take the access form as an argument, and
			   return a location.  */
  
  struct type_form *type_form;
};

/* This function returns a type from a type_form, creating it if
   necessary.  Thus two different type_forms being equal returns
   however the same type.

   (At least for now, because calculation of the size of the type is
   done here) The base types refered to in the type form have to
   already exist.
*/
//type_t intern_type (struct type_form * form);

/* Output a textual representation of the type.  */
void
write_type (type_t type);

/* Name a type with a symbol.  */
static inline void
name_type (type_t type, symbol_t symbol)
{
  /* Two steps: set the name of TYPE to SYMBOL, and sets the value of
     symbol to type.  */
}

char *
asprintf_type (type_t type);

void
write_type_form_to_xml (struct type_form *typeform);

/* IDEE: implementation des types | (ou du @ pour les pointeurs qui peuvent etre null)

   Il suffit, dans le block dans lequel on a fait le test, de faire un
   shadow de la variable (mais ou c'est en fait la meme) avec un type
   different plus precis.

   Ce sera fait avec le nouveau generic "match" ou "match_type"
   
*/


/* XXX: evidemment, cette fonction peut compier un appel vers une
   fonction utilisee au runtime.  */

#include "symbol.h"

extern /*const*/ type_t __type_type;
//extern /*const*/ type_t __type_void;

//#define SIZE_OF (type)

//#include "../compiler/location.h"

extern hash_table_t type_hash;

#endif
