/* access.c - Accesser handling.
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

#include <l/expand.h>
#include <l/access.h>
#include <l/sys/panic.h>
#include <assert.h>

/* Accesser hash is a hash Type->Accesser */
MAKE_STATIC_HASH_TABLE (accesser_hash);

form_t
expand_access(generic_form_t form)
{
  assert (is_form (form, generic_form));
	  
  form_t accessed = CAR (form->form_list);
  
  form_t accessor = CAR (form->form_list->next);

  expanded_form_t expanded_accessed = expand(accessed);
  expanded_form_t expanded_accessor = expand(accessor);

  Type accessed_type = expanded_accessed->type;

  Accesser accesser = gethash (accessed_type, accesser_hash);

  if(accesser == NULL)
    {
      panic ("There isn't any accessor for type %s\n",
	     asprint_type (accessed_type));
    }

  return accesser (accessed_type, expanded_accessed, expanded_accessor);
}

/*XXX: lvalue accesser hash, and lvalue expander function.  */

void
define_accesser (Type type, Accesser accesser)
{
  puthash (type, accesser, accesser_hash);
}

#include <l/sys/type.h>

expanded_form_t
struct_accesser(Type type_,
		expanded_form_t accessed,
		expanded_form_t accessor)
{
  Struct_Type type = type_;
  assert(type->type_type == STRUCT_TYPE);

  symbol_form_t accessor_symbol_form = accessor->return_form;
  if(!is_form(accessor_symbol_form, quoted_symbol_form))
    {
      panic("Struct accessors must be constant symbols\n");
    }
  
  symbol_t accessor_symbol = accessor_symbol_form->value;
  offset_type_t offset_type = gethash(accessor_symbol, type->field_hash);

  return create_expanded_form(generic_form_symbol(intern("[]_Struct"),
						  CONS(accessed,
						       CONS(accessor,
							    NULL))),
			      offset_type->type);
}

/* If we try an access on a pointer, automatically add a deref.  This
   eliminates the need of the C -> operation, makes the code clearer
   and more general (hence, more generic macros can be made).  */
expanded_form_t
pointer_accesser(Type type_,
		 expanded_form_t accessed,
		 expanded_form_t accessor)
{
  Pointer_Type type = type_;
  assert(type->type_type == POINTER_TYPE);

  Type pointed_type = get_pointed_type(type);
  
  /* XXX: should not be struct_accesser, but any accesser.  */
  return struct_accesser(pointed_type,
			 create_expanded_form(generic_form_symbol(SYMBOL(deref),
								  CONS(accessed, NULL)),
					      pointed_type),
			 accessor);
}


/* Left accesser handling.  */

/* Left accesser hash is a hash Type->Left Accesser.  */
MAKE_STATIC_HASH_TABLE (left_accesser_hash);

void
define_left_accesser(symbol_t symbol, Left_Accesser expander)
{
  puthash(symbol, expander, left_accesser_hash);
}


form_t
left_expand_access(generic_form_t form,
		   expanded_form_t expression)
{
  form_t accessed = CAR (form->form_list);
  
  form_t accessor = CAR (form->form_list->next);

  expanded_form_t expanded_accessed = expand(accessed);
  expanded_form_t expanded_accessor = expand(accessor);

  Type accessed_type = expanded_accessed->type;

  Left_Accesser laccesser = gethash (accessed_type, left_accesser_hash);

  if(laccesser == NULL)
    {
      panic ("There isn't any left accessor for type %s\n",
	     asprint_type (accessed_type));
    }

  return laccesser (accessed_type, expanded_accessed,
		    expanded_accessor, expression);
}

expanded_form_t
struct_left_accesser(Type type_,
		     expanded_form_t accessed,
		     expanded_form_t accessor,
		     expanded_form_t expression)
{
  Struct_Type type = type_;
  assert(type->type_type == STRUCT_TYPE);

  symbol_form_t accessor_symbol_form = accessor->return_form;
  if(!is_form(accessor_symbol_form, quoted_symbol_form))
    {
      panic("Struct accessors must be constant symbols\n");
    }
  
  symbol_t accessor_symbol = accessor_symbol_form->value;
  offset_type_t offset_type = gethash(accessor_symbol, type->field_hash);

  expanded_form_t left_form = create_expanded_form (generic_form_symbol(intern("[]_Struct"),
									CONS(accessed,
									     CONS(accessor,
										  NULL))),
						    offset_type->type);
  
  return create_expanded_form(generic_form_symbol (intern ("="),
						   CONS (left_form,
							 CONS (expression,
							       NULL))),
			      offset_type->type);
}

/* If we try an access on a pointer, automatically add a deref.  This
   eliminates the need of the C -> operation, makes the code clearer
   and more general (hence, more generic macros can be made).  */
expanded_form_t
pointer_left_accesser(Type type_,
		      expanded_form_t accessed,
		      expanded_form_t accessor,
		      expanded_form_t expression)
{
  Pointer_Type type = type_;
  assert(type->type_type == POINTER_TYPE);

  Type pointed_type = get_pointed_type(type);
  
  /* XXX: should not be struct_accesser, but any accesser.  */
  return struct_left_accesser(pointed_type,
			      create_expanded_form (generic_form_symbol(SYMBOL(deref),
									CONS(accessed, NULL))),
			      accessor,
			      expression);
}



void
init_access ()
{
  define_expander(intern("[]"), expand_access);
  define_left_expander(intern("[]"), left_expand_access);
}
