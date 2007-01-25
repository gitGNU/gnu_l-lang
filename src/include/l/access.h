/* access.h - Accesser handling.
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

#ifndef _ACCESS_H
#define _ACCESS_H

#include <l/type.h>

typedef form_t(*Accesser)(Type, expanded_form_t, expanded_form_t);

void
define_accesser (Type type, Accesser accesser);

/* General accessers.  */

/* Struct accessers can access their fields.  */
expanded_form_t
struct_accesser(Type type,
		expanded_form_t accessed,
		expanded_form_t accessor);


/* The pointer accesser adds a deref to the accessed type, and tries
again.  This allows to write a.x (instead of C's a->x) when a is of
type struct { Int x;} *.  */
expanded_form_t
pointer_accesser(Type type,
		 expanded_form_t accessed,
		 expanded_form_t accessor);

#endif
