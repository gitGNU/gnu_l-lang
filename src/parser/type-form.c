/* type_form.c - Type Form manipulations.
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

#include "form.h"


//type_form_t
//force_tuple_type_form (list_t type_form_list)
//{
//  type_form_t tf = new_form (type);
//  tf->type_form_type = TUPLE_TYPE_FORM;
//  tf->type_form_list = type_form_list;
//  return tf;
//}

//XXX: type forms should be regular forms: i.e. base types would be
//symbols, other would be generics.
#if 0
type_form_t
tuple_type_form (list_t type_form_list)
{
  
    if(type_form_list && type_form_list->next == NULL)
    {
      return CAR (type_form_list);
    }

  type_form_t tf = new_form (type);
  tf->type_form_type = TUPLE_TYPE_FORM;
  tf->type_form_list = type_form_list;
  return tf;
}

type_form_t
indirection_type_form (type_form_t form)
{
  type_form_t tf = new_form (type);
  tf->type_form_type = INDIRECTION_TYPE_FORM;
  tf->type_form = form;
  return tf;
}

type_form_t
function_type_form (type_form_t return_type,
		    type_form_t parameters)
{
  type_form_t tf = new_form (type);
  tf->type_form_type = FUNCTION_TYPE_FORM;
  tf->return_type = return_type;
  //  tf->type_form_list = parameter_list;
  tf->parameters = parameters;//tuple_type_form (parameter_list);
  return tf;
}


type_form_t
base_type_form (symbol_t name)
{
  type_form_t tf = new_form (type);

  tf->type_form_type = BASE_TYPE_FORM;
  tf->base_type_name = name;

  return tf;
}
#endif


type_form_t
force_tuple_type_form (list_t type_form_list)
{
  return generic_form_symbol (SYMBOL (tuple), type_form_list);
}

type_form_t
tuple_type_form (list_t type_form_list)
{
    if(type_form_list && type_form_list->next == NULL)
    {
      return CAR (type_form_list);
    }

    
    return generic_form_symbol (SYMBOL (tuple), type_form_list);
}

type_form_t
base_type_form (symbol_t name)
{
  return id_form (name);
}

type_form_t
indirection_type_form (type_form_t form)
{
  list_t list = CONS (form, NULL);

  return generic_form_symbol (SYMBOL (pointer), list);
}

type_form_t
function_type_form (type_form_t return_type,
		    type_form_t parameters)
{
  if(!(is_form (parameters, generic_form)
       && ((generic_form_t) parameters)->head == intern ("tuple")))
    {
      list_t l = CONS (parameters, NULL);
      parameters = force_tuple_type_form (l);
    }
//  if(!(is_form (return_type, generic_form)
//       && ((generic_form_t) return_type)->head == intern ("tuple")))
//    {
//      list_t l = CONS (return_type, NULL);
//      return_type = force_tuple_type_form (l);
//    }
  list_t list = CONS (return_type, CONS (parameters, NULL));
  return generic_form_symbol (SYMBOL (function), list);
}

