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

extern const Type __type_function;
//extern const type_t __type_compiling_function;
extern const Type __type_generic;
//extern const type_t __type_boolean_relation;



#endif
