/* analysis.c - Generic pre-analysis
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


/* This code handle all the processing needed before compiling can
   begin. For example:

   - Type definitions, and relationship
   - Function definition
   - Overload definition
   - Class definition
   - Generic definition
   - Parse definition ...

*/   




/* XXX: type definitions should be treated here.  */

/* XXX: also here should be recorded the association generic =>
   function + type of the function.  */


/* Associate to each defined generic a type.  Returns a list of forms
   to compile. (i.e. a list of (define function ... ), the rest is
   stripped.  Or maybe we should have another generic to enclose form
   generation in it.)  */

#include <assert.h>

#include <l/string.h>

#include "../objects/pair.h"
#include "../objects/function.h"
#include "../parser/form.h"

#include "c-to-l.h"
#include "analysis.h"

#include <l/sys/panic.h>
#include <l/sys/global.h>
#include <l/access.h>
#include <l/creator.h>

/*__thread*/ analysis_t current_analysis;

/*__thread*/ /*list_t to_compile_list;*/  /* List of things to compile,
  with type parameter.

  Note: this list should be global; this would allow for instance
  one-pass compilation of closures.

  Note: some things need to be compiled first, like generics and type
  functions.  

  XXX: it is in fact a list of function_t
  */

//list_t generic_compile_list;
/* List of generics to compile.  They should be compiled before the
   function list.  */

/* If generic compilation depends on another generics, we should add
   another level.  Maybe the "absolute dependencies" should be stored
   instead, i.e. the need to compile sth before sth else. */


/* Definers and define form.  */

/* The function used to define an object.

   Exemple: (define class 'toto'
               (define member 'truc' ...))

	       Truc is a member of class toto.

   Standard definers: function, type.

   Other definer: overloaded_function, global, thread_local ...
                  generic
                  macro
                  parse_hook
		  constant
		  pci_interface (par exemple pour un device driver dans un noyau)
		  service (pour du CORBA)
   */
MAKE_STATIC_HASH_TABLE (definer_hash);

/* A hash Symbol -> Global.  */
MAKE_STATIC_HASH_TABLE (global_hash);
extern hash_table_t generic_hash;

typedef void (*definer_t)(symbol_t, symbol_t, form_t);

/* XXX: for recursive types: just use a lazy evaluation technique, we
   transform a type definition to a type only when the type is needed. */
void
define_type (symbol_t define_symbol, symbol_t name, type_form_t type_form)
{
  Base_Type t = define_type_type_form (id_form (name), -1, -1, type_form);

  assert (t->type_type == BASE_TYPE);
  
  /*  Does not really belong here, but more to a "high-level type
     definition processing" part of the compiler.  */
  define_derived_creator( t, name);
  define_accesser (t, derived_accesser);
  define_left_accesser (t, derived_left_accesser);
}

/* A type alias is just another name for the same type.  It is
   equivalent to C's typedef. */
void
define_type_alias (symbol_t define_symbol, symbol_t name,
		   type_form_t type_form)
{
  Type type = intern_type (type_form);
  associate_type_with_type_form( id_form( name), type);
  // puthash (name, type, type_hash);
}


/* Transitional, while moving analysis.c to expand-define.  */
static void
do_nothing()
{
}


list_t
analyze (list_t form_list)
{
  current_analysis = MALLOC (analysis);
  
  list_t result = NULL;

  list_t *result_ptr = &result;
  
  FOREACH (element, form_list)
    {
      form_t form = CAR (element);
      //      *result_ptr = CONS (form, NULL);
      //      result_ptr = &((*result_ptr)->next);
      
      if(is_form (form, generic_form))
	{
	  generic_form_t gform = (generic_form_t) form;
	  if(gform->head == SYMBOL (define))
	    {
	      symbol_t type_defined, name;
	      type_defined = ((id_form_t) (CAR (gform->form_list)))->value;
	      name = ((id_form_t) (CAR (gform->form_list->next)))->value;
	      form_t subform = CAR (gform->form_list->next->next);
	      
	      *result_ptr = CONS (form, NULL);
	      result_ptr = &((*result_ptr)->next);
	      
	      definer_t definer = gethash (type_defined, definer_hash);

	      if(definer == NULL)
		panic ("Unknown definer\n");
	      definer (type_defined, name, subform);
	    }
	}
    }

  return result;
}

#define DEFINE_DEFINER(string__, function__)			\
do {								\
  puthash (intern (string__), function__, definer_hash);	\
 } while(0)


void
init_analysis ()
{
  //  DEFINE_DEFINER ("function", define_function);
  DEFINE_DEFINER ("function", do_nothing);
  DEFINE_DEFINER ("global", do_nothing);
  DEFINE_DEFINER ("type", define_type);
  DEFINE_DEFINER ("type_alias", define_type_alias);
  //  DEFINE_DEFINER ("generic", define_generic);
  DEFINE_DEFINER ("expander", do_nothing);

  define_type_string ("Int", sizeof(int), __alignof__ (int), NULL);
  define_type_string ("Bool", sizeof(int), __alignof__ (int), NULL); 
  define_type_string ("Type", sizeof(int), __alignof__ (int), NULL);
  define_type_string ("Function", sizeof(int), __alignof__ (int), NULL);
  define_type_string ("Symbol", sizeof(int), __alignof__ (int), NULL);
  define_type_string ("String", sizeof(int), __alignof__ (int), NULL);

  /* Label should have a type of -1, like functions, but for now
     we need them to be of size 0.  */
  define_type_string ("Label", 0, 0, NULL);

    /* XXX: void is not really the () type : because we allow (int) to
     coerce into void? Or is it? */
  //define_type_string ("Void", -1, -1, NULL); /* Void has no size.  */
  eval_cstring( "type_alias Void = ();");

}
