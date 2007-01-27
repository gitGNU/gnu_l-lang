/* hash.c - Hash tables handling.
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

#include <l/sys/hash.h>
#include "../compiler/c-to-l.h"
#include <l/type.h>
#include <assert.h>

/* Hash table support is efficient, but may seem basic to people
   accustomed to Common Lisp, Perl or Ruby hashes.  There are no
   default value, no default function executed, and no check that the
   value in gethash is really here.  If you want all that, use a
   different type.  
   
   XXX: what we could do to make it typesafe later, is to mandate that
   the return type can be Null (i.e. a pointer|null, or an Int); and
   if it cannot be, then we check it automatically (and throw an
   exception if null).

   If he wants, the user can then use his type|Null in the Hash, and
   then assert that his values are not null; but it will have to do
   that explicitly.  Or he could use an unsafe_hash that would do
   that automatically.  */
   
   

/* Transforms Hash(From_Type,To_Type) into
   (Hash(From_Type,To_Type)) make_hash_table();
*/
generic_form_t
expand_hash (generic_form_t form)
{
  type_form_t new_type_form = generic_form_symbol (SYMBOL (cast),
						   CONS (form,
							 CONS (generic_form_symbol (SYMBOL (make_hash_table),
										    NULL),
							       NULL)));
  return new_type_form;
}


form_t
hash_accesser(Type type,
	      expanded_form_t accessed,
	      expanded_form_t accessor)
{
  type_form_t tf = type->type_form;
  generic_form_t gf = tf;

  assert (is_form (gf, generic_form));
  assert (gf->head == SYMBOL (Hash));
  
  type_form_t from_form = CAR (gf->form_list);
  type_form_t to_form = CAR (gf->form_list->next);

  Type from_type = intern_type (from_form);
  
  /* Needed only when we will directly create an expanded form.  
     Type to_type = intern_type (to_form); */

  type_check (from_type, accessor->type);

  form_t casted_key = generic_form_symbol (SYMBOL (cast),
					   CONS (generic_form_symbol (SYMBOL (pointer),
								      CONS (id_form (SYMBOL (Void)),
									    NULL)),
						 CONS (accessor, NULL)));
  
  form_t casted_hash = generic_form_symbol (SYMBOL (cast),
					    CONS (id_form (SYMBOL (Hash_Table)),
						  CONS (accessed, NULL)));

  form_t all = generic_form_symbol (SYMBOL (cast),
				    CONS (to_form,
					  CONS (generic_form_symbol (SYMBOL (gethash),
								     CONS (casted_key,
									   CONS (casted_hash,
										 NULL))),
						NULL)));
  lispify (all);
  return all;
}


form_t
hash_left_accesser(Type type,
		   expanded_form_t accessed,
		   expanded_form_t accessor,
		   expanded_form_t expression)
{
  type_form_t tf = type->type_form;
  generic_form_t gf = tf;

  assert (is_form (gf, generic_form));
  assert (gf->head == SYMBOL (Hash));
  
  type_form_t from_form = CAR (gf->form_list);
  type_form_t to_form = CAR (gf->form_list->next);

  Type from_type = intern_type (from_form);
  
  /* Needed only when we will directly create an expanded form.  
     Type to_type = intern_type (to_form); */

  type_check (from_type, accessor->type);

  form_t casted_key = generic_form_symbol (SYMBOL (cast),
					   CONS (generic_form_symbol (SYMBOL (pointer),
								      CONS (id_form (SYMBOL (Void)),
									    NULL)),
						 CONS (accessor, NULL)));
  
  form_t casted_hash = generic_form_symbol (SYMBOL (cast),
					    CONS (id_form (SYMBOL (Hash_Table)),
						  CONS (accessed, NULL)));


  form_t casted_expression = generic_form_symbol (SYMBOL (cast),
						  CONS (generic_form_symbol (SYMBOL (pointer),
									     CONS (id_form (SYMBOL (Void)),
										   NULL)),
							CONS (expression, NULL)));

  form_t all = generic_form_symbol (SYMBOL (puthash),
				    CONS (casted_key,
					  CONS (casted_expression,
						CONS (casted_hash,
						      NULL))));
  lispify (all);
  return all;
}

/* Create a type given a type form (Hash From_Type_Form
   To_Type_Form).  */
Type
make_type_Hash (generic_form_t form)
{
  type_form_t defining_type_form = base_type_form (SYMBOL (Hash_Table));
  Base_Type the_type = define_type_type_form (form, -1, -1, defining_type_form);

  assert(the_type->type_type == BASE_TYPE);

  define_accesser (the_type, hash_accesser);
  define_left_accesser (the_type, hash_left_accesser);
  /* Create the accessor and left accessor for the type.  */
  
  return the_type;
}



void
init_hash (void)
{
  /* These functions are needed so that the macros can work; but they
     should not be used directly.  */
  eval_cstring ("type Hash_Table = Void *;");
  DEFINE_C_FUNCTION (make_hash_table, "Hash_Table <- ()");

  /* XXX: gethash should also tell if there was a value or not.  */
  DEFINE_C_FUNCTION (gethash, "Void * <- (Void *, Hash_Table)");
  DEFINE_C_FUNCTION (puthash, "Void <- (Void *, Void *, Hash_Table)");

  /* XXX: remove should also work: remove(table['toto'] would remove
     the entry 'toto' from the table.  */
  
  define_expander (SYMBOL (Hash), expand_hash);
   
  define_type_constructor (SYMBOL (Hash), bprint_type_misc, make_type_Hash);
  
  /* There should also be a Hash_String constructor, for hashes built
     from strings.  */
}
