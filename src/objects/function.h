/* function.h - Function handling
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


#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <l/sys/type.h>
#include "pair.h"
#include "symbol.h"
#include <l/sys/hash.h>
#include "../parser/form.h"


typedef void (*void_to_void_t)(void);
typedef unsigned int (*void_to_ui_t)(void);

typedef unsigned int bool;

#define true (0 == 0)
#define false (0 == 1)



extern hash_table_t function_hash;
/* XXX : there should be a whole type hierarchy for functions, like
   there is for forms.  So they could be dynamically
   recognizables.  */

typedef struct function
{
  /* Name of the function.  */
  symbol_t name;
  
  /* Address of the function, or NULL if not (yet) defined.  */
  void *address;

  /* Type of the function. */
  Function_Type type;

  /* Number of arguments to the function.  */
  unsigned int nb_arguments;

  /* NB_ARGUMENT-sized array with parameters name.  Use a short hash
     instead?  */
  symbol_t *arguments_name;

  /* Default values.  */
  unsigned int *default_values;

  /* A word in which a bit is set if, and only if there is a default
     value.  */
  unsigned int has_default_value;
  
  /* Hash table : symbol_t function_name => void * data : contains the
     list of functions this one depends on, and associated data on the
     dependency.  For now, the data is a list_t of jit_insn * where
     the function is called, so we can backpatch it later.  */
  //  hash_table_t needed_functions;

  /* Hash table: symbol_t function_name => void *data.  Contains the
     list of function which depends on this one. Data can be something
     different that in needed_functions.  */
  //  hash_table_t used_by_functions;
} *function_t;

#if 0
typedef type_t (*tCompile)(struct form* form, bool is_context_void);

/* Could be named "builtin function" */
typedef struct compiling_function
{
  /* Address of the function. (May be null if the function is actually
     a special form) */
  void *address;

  /* Type of the function. (Also null if the function is a special
     form). */
  type_t type;

  /* special way to compile this function.  */
  tCompile compile;
} *compiling_function_t;
#endif

typedef struct location* (*GenericCompile)(void *form, Type t/*, void *function_info*/);

/* XXX: could take further arguments, like the generic it is
   compiling.  */

typedef struct generic
{
  //  void *address;

  /* For compatibility with former compiling functions.  */
  //  unsigned int useless1;
  //  unsigned int useless2;
  GenericCompile compile;
} *generic_t;

/* The context of a boolean relation should never be void.  */
//typedef boolean_expression_patches_t (*brCompile)(struct pair*);

/* A boolean relation is a supertype of a function.  It can be used as
   a function (and then returns a bool), but most often it has to be
   compiled in a special way.  Note: compile could be NULL, to have a
   generic way on how to handle boolean relations. 
   */
//typedef struct boolean_relation
//{
//  /* Address of the "boolean relation function".  */
//  void *address;
//
//  /* Type of the function. It has to return a bool. (which can in fact
//     be any non-zero value.)  */
//  type_t type;
//
//  hash_table_t needed_functions;
//  
//  hash_table_t used_by_functions;
//  
//  /* How to compile this function.  It should return a
//     boolean_expression_patches_t.  */
//  brCompile compile;
//} *boolean_relation_t;


/* Initialize the pair subsystem.  */
void
init_function (void);

extern const Type __type_function;
//extern const type_t __type_compiling_function;
extern const Type __type_generic;
//extern const type_t __type_boolean_relation;



#endif
