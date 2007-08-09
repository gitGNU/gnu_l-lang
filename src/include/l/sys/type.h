/* type.h - Internal type definition.
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

#ifndef _SYS_TYPE_H
#define _SYS_TYPE_H

#include <l/type.h>

typedef enum { STRUCT_TYPE, FUNCTION_TYPE, TUPLE_TYPE,
	       BASE_TYPE, POINTER_TYPE } type_type_t;


#define TYPE_CONTENT						\
{								\
  type_type_t type_type;					\
								\
  /* Type form of the type.  */					\
  struct type_form *type_form;					\
								\
  /* Size of the type, if meaningful.  */			\
  unsigned int size;							\
								\
  /* Alignment constraints of the type, if meaningful.  */	\
  unsigned int alignment;					\
}

struct my_type TYPE_CONTENT;

typedef struct tuple_type
{
  struct TYPE_CONTENT;
  /* Number of elements;  */
  unsigned int length;
  Type *fields;
} *tuple_type_t;

typedef tuple_type_t Tuple_Type;



typedef struct function_type
{
  struct TYPE_CONTENT;
  Type return_type;
  Type parameters_type;
} *function_type_t;

typedef function_type_t Function_Type;



typedef struct offset_type
{
  unsigned int offset;
  Type type;
} *offset_type_t;

typedef struct struct_type
{
  struct TYPE_CONTENT;
  hash_table_t field_hash;
} *struct_type_t;

typedef struct_type_t Struct_Type;



typedef struct pointer_type
{
  struct TYPE_CONTENT;

  Type pointed_type;
} *pointer_type_t;

typedef pointer_type_t Pointer_Type;

typedef struct base_type
{
  struct TYPE_CONTENT;

  void *misc_data;

  /* The type from which it is defined.  Maybe NULL if there isn't, or
     itself (only for Word8, Word16 and Word32) */
  Type origin_type;
} *base_type_t;

typedef base_type_t Base_Type;
  
#undef TYPE_CONTENT


#endif
