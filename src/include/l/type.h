/* type.h - User-visible type handling.
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

#ifndef _MY_TYPE_H
#define _MY_TYPE_H

#include <l/sys/hash.h>
#include "../objects/symbol.h"

typedef struct my_type *Type;

/* Get a type from a C string.  */
Type TYPE (const char *type_name);


/* Type constructor handling, e.g. List(Int)  */

typedef void (*Type_Printer)(Buffer, form_t);
typedef Type (*Type_Maker)(generic_form_t);

int i;
/* Defines a new type constructon for symbol NAME, with printer PRINT_FUNCTION
   (default bprint_type_misc) and maker MAKE_FUNCTION  */
void
define_type_constructor (Symbol name,
			 Type_Printer print_function,
			 Type_Maker make_function);


/* Prints the generic type form in the buffer in a generic way.  */
void bprint_type_misc (Buffer, generic_form_t);


/* Try to make form FORM fit into type T (e.g. it could be a subtype).  */
void *
coerced_form( /*expanded_form_t*/ void * form, Type t);


#endif
