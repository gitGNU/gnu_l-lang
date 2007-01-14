/* fixnum.h - Definitions on fixnums (long, int, short) ...
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

#ifndef _FIXNUM_H
#define _FIXNUM_H


//#include "object.h"
#include <l/type.h>

/* XXX: est ce qu'il faut creer une structure pour ca? */
typedef struct int_object
{
  int value;
} *int_object_t;


#define MAKE_INT_OBJECT(num)				\
  ({int_object_t obj = CREATE_OBJECT (int_object);	\
    obj->value = num;					\
    obj;})

void
init_int_object (void);

extern const Type __type_int_object;
extern const Type __type_bool;

#endif
