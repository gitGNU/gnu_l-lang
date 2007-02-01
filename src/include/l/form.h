/* form.h - Form functions.
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

#ifndef _FORM_H
#define _FORM_H

#include "../parser/form.h"

/* These functions go in <l/form.h>, because they should be easily
   accessible from C.  But the Form(in conjonction with $ and $@) will
   be the only interface to L programs.
*/

int_form_t
int_form (int value);

float_form_t
float_form (float value);

symbol_form_t
id_form (symbol_t value);

quoted_symbol_form_t
symbol_form (symbol_t value);

string_form_t
string_form (string_t value);

generic_form_t
generic_form_symbol (symbol_t head, list_t list);

generic_form_t
generic_form (id_form_t head, list_t list);


#endif
