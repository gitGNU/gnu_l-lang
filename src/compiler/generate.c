/* generate.c - Machine code generator.
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

/* This generate :

   - Uses compile_branch_aware for compiling branches, if etc...

   - Uses compile_branch_discard_results when we do not expect a
     result (for performance, fall backs to the the normal functions
     if there isn't a discard_results function and then free the
     location.)
   
   - Uses high locations and rely on them for typing.

   - Uses the label abstraction for jumping.
   
  - On a un probleme pour le if quand plusieurs locations sont
    retournees. Une solution serait d'utiliser
    ensure_unifiable(location) pour le if, qui allouerait un espace
    dans le bloc du if pour mettre le resultat, et unify(location1,
    location2) dans le else pour qu'on recuperer les deux resultats au
    meme endroit.

   - On aura aussi un probleme pour le let a ... et le a n'est affecte
     que dans un bloc.  Le mieux ce serait de faire du first fit (avec
     fit pour la size et les contraintes d'alignement) sur la pile en
     fait; i.e. on bourrine comme des cons.  


TODO:

 - types as standard generics.  Just use "compile_type" when
   necessary, which would return a type.

   We could use "lispify" as a base for intern_type_new
   
   So type functions need two functions: one for pretty-printing
   itself, one for creating a type.

- Automatic posteriori generic type checking.  Each generic would have
  a type; the generic is compiled, and it is checked that the typing
  is correct.

  A posteriori is necessary for efficiency; for instance, when
  compiling named blocks.

*/
   

#include <assert.h>
#include "backend.h"
#include "../parser/form.h"

#include "../objects/pair.h" 
#include "../objects/symbol.h" 
#include <l/string.h>
#include "../objects/function.h" 
#include "../objects/hash.h" 

#include "c-to-l.h"

#define panic(format, ...)						\
  do {fprintf (stderr, "error: " format, ## __VA_ARGS__); asm("int $3"); exit (1); } while(0)
#define compile_error panic
#define compile_warning panic

MAKE_STATIC_HASH_TABLE (generic_hash);
//MAKE_STATIC_HASH_TABLE (type_hash);
MAKE_STATIC_HASH_TABLE (function_hash);

//XXX: generics should be called "language constructs"

#include <l/expand.h>

location_t
compile (expanded_form_t form);

location_t
compile_function_call (generic_form_t form);


location_t
compile (expanded_form_t expform)
{
  assert(is_form(expform, expanded_form));
  form_t form = expform->return_form;

  if (is_form (form, atomic_form))
    {
      if (is_form (form, int_form))
	{
	  return constant_value (TYPE ("Int"), ((int_form_t) form)->value);
	}
      else if (is_form (form, id_form))
	{
	  return get_location (((id_form_t) form)->value);
	}
      else if (is_form (form, quoted_symbol_form))
	{
	  return constant_value (TYPE ("Symbol"), ((quoted_symbol_form_t) form)->value);
	}
      else if(is_form (form, string_form))
	{
	  return constant_value (TYPE ("String"), ((string_form_t) form)->value);
	}
      else panic ("Form compilation unimplemented\n");
    }
  
  assert (is_form (form, generic_form));
  
  /* XXX: how to do (*a).b(x)? */
  symbol_t symbol = ((compound_form_t) form)->head;
  generic_t generic = gethash (symbol, generic_hash);

  if (generic == NULL)
    compile_error ("Call to unknown generic: %s\n", symbol->name);

  /* XXX: In the future, generic could be called with the "funcall"
     function, that take a list and pass all the arguments in the
     stack, according to the function type.  */

   return generic->compile (form);
}


/* XXX: not yet implemented

   This function is really useful for high_level optimisation.

   It acts like compile, but if there exists an optimized function
   when the return value is discarded, then use that one instead.

   For instance, map() when the result list is discarded is just
   foreach(). Not creating the list is an important optimisation.
   
   number tells how many values are expected. 
   
   bitfield tells what value is wanted or not.  For instance, a bit
   value of 101 tells that the second value is the one not wanted.

   XXX: for now bitfield is limited to 32.

   Some people may like to have a general rule that loop returns a
   list with each except if the result is discarded.  This is possible
   thanks to compile_discard.
  */
   
location_t
compile_discard (form_t form, unsigned int bitfield)
{
  panic ("Not yet implemented\n");
  compile (form);
}

void
type_check (Type to, Type from)
{
  if(from != to)
    panic ("Type mismatch: trying to make an expression"
	   " of type |%s| in place of something of type |%s|\n",
	   asprint_type (from->type_form), asprint_type (to->type_form));
}

#include <l/expand.h>

void
compile_function (symbol_t define_symbol, symbol_t name, expanded_form_t expform)
{
  generic_form_t form = expform->return_form;
  assert (define_symbol == SYMBOL (function));

  form_t return_type = CAR (form->form_list);
  generic_form_t parameters = CAR (form->form_list->next);
  generic_form_t body = CAR (form->form_list->next->next);
  
  generate_function_start (name, parameters);

  // XXX: if void, calls compile_branche_discard_results instead.
  // */
  location_t return_loc = compile (body);

  //  type_t given_return_type = intern_type (form->type->return_type);
  // check_type(given_return_type, return_loc->type);
  
  return_function_value (return_loc);

  free_location (return_loc);

  //  form_t type = function_type_form (return_type, parameters);
  form_t type = return_type;
  
  function_t fn = generate_function_end ();
  //  fn->type = intern_type (type);
  //  fn->has_default_value = 0;

  //  fn->nb_arguments = length (parameters->form_alist);

  /* XXX: put either the adress of the function, or the form? */
  // fn

  puthash (name, fn, function_hash);

  DEFINE_GENERIC_SYMBOL (name, compile_function_call);
}

#if 0
typedef void (*definer_t)(symbol_t, symbol_t, form_t);

location_t
compile_define (generic_form_t form)
{
  symbol_form_t sf = CDR (CAR (form->form_alist));
  
  assert (is_form (sf, symbol_form));
  symbol_t type_symbol = sf->value; 

  definer_t definer = gethash (type_symbol, definer_hash);

  if(definer == NULL)
    {
      panic ("Trying to define an unknown object: %s\n", type_symbol->name);
    }
  
  symbol_form_t name_form = CDR (CAR (form->form_alist->next));
  symbol_t name = name_form->value;

  definer (type_symbol, name, CDR (CAR (form->form_alist->next->next)));

  //  compile_new_function (name, CDR (CAR (form->form_alist->next->next)));

  return NULL;//void_location ();
}
#endif


/* Standard special forms.  */

location_t
compile_seq (generic_form_t form)
{
  list_t args = form->form_list;

  if(args == NULL)
    {
      /* XXX If there are no elements in the sequence, we return void.  */
      panic ("Unimplemented\n");
    }
  
  while (args->next)
    {
      location_t return_location = compile (args->car);

      /* All but the last location are used.  */
      free_location (return_location);

      args = args->next;
    }

  location_t return_location = compile (args->car);

  return return_location;
}

location_t
compile_block (generic_form_t form)
{
  create_block ();
  
  location_t loc = compile_seq (form);
  
  delete_block ();

  return loc;
}

location_t
compile_let (generic_form_t form)
{
  /* XXX: should location_table management be done here?  */

  type_form_t type_form = CAR (form->form_list);
  Type type = NULL;

  assert(type_form);
  if(type_form)
    {
      //     assert (is_form (type_form, type_form));

      type = intern_type (type_form);
    }

  id_form_t id_form = CAR (form->form_list->next);
  assert (is_form (id_form, id_form));

  symbol_t id = id_form->value;
  
  /* If there is no type symbol, we just pass NULL.  */
  create_stack_variable (type, id);

  /* Return void location.  */
  location_t location = void_location ();

  location->type = TYPE ("Void");
  
  return location;
}

location_t
compile_assign (generic_form_t form)
{
  form_t assignee = CAR (form->form_list);
  
  form_t expression = CAR (form->form_list->next);

  location_t exp_loc = compile (expression);

  location_t ass_loc = compile (assignee);

  type_check (location_type (ass_loc), location_type (exp_loc));
  
  /* XXX: if move from and to compound location: An aliasing analysis
     has to be done here to see if there is a need for temporary
     values, and how many of them.

     Only pointers of the same type can have the same location, and
     thus need a temporary value.

     This could be done by graph algorithms between the from and to
     location.  */
  
  move_between_locations (exp_loc, ass_loc);

  free_location (ass_loc);

  // free_location (exp_loc);
  /* Exp_loc will be freed if not reused by the caller of '='.  */
  return exp_loc;
}


/* Ref is the & operator in C.  It applies only to l-valuables
   expressions.  

   XXX: maybe we should have a "compile_lvalue" context (as we have
   the "compile_boolean one" for computing lvalues?  With that we
   could easily determine if we have the right to compute the address
   or not.

   We also need to do stuff like: f(3) = 23; that being equivalent to
   toto[35 + 3] = 23/4; i.e. to apply functions depending on the
   inequality.

   We could use that for the coercion mecanism.
*/
location_t
compile_ref (generic_form_t form)
{
  /* XXX: we don't check that we can compute the address.  */
  form_t expression = CAR (form->form_list);

  location_t exp_loc = compile (expression);

  location_t address = get_address_of(exp_loc);

  location_type(address) = get_pointer_type (location_type (exp_loc));
    
    //intern_type(indirection_type_form(location_type(exp_loc)->type_form));

  free_location(exp_loc);

  return address;
}

/* Most pointers operations will be hidden in the malebolge  */
location_t
compile_deref (generic_form_t form)
{
  /* XXX: we don't check that we can compute the address.  */
  form_t expression = CAR (form->form_list);

  location_t exp_loc = compile (expression);

  if(location_type (exp_loc)->type_type != POINTER_TYPE)
    compile_error ("Only a pointer can be dereferenced\n");
  /* The type must be an indirection */
//  if(location_type(exp_loc)->type_form->type_form_type 
//     != INDIRECTION_TYPE_FORM)
//    {
//      panic("Only a pointer can be dereferenced\n");
//    }

  location_t value = get_value_of(exp_loc);

  location_type(value) = get_pointed_type (location_type (exp_loc));
  free_location(exp_loc);

  return value;
}

/* This is the totally unsafe cast.  In the malebolge, you would
   rather use convert/coerce that performs type checking and type
   transformation. */
location_t
compile_cast (generic_form_t form)
{
  expanded_form_t exp_type_form = CAR(form->form_list);
  type_form_t type_form = exp_type_form->return_form;

  /*XXX: in the future we will accept any form.  */
 // if(!(is_form(type_form, symbol_form)))
 //    panic("First argument to cast sould be a typeform\n");
 //
 // type_form = base_type_form(((symbol_form_t) type_form)->value);
  form_t expression = CAR (form->form_list->next);

  location_t exp_loc = compile(expression);

  location_t new_loc = cast_location(intern_type(type_form), exp_loc);
  
  free_location(exp_loc);

  return new_loc;
}


#if 0
location_t
compile_tuple (generic_form_t form)
{
  /* XXX: we just need a list of locations, the rest will be in the
     type?  */

  /* XXX: but interning the tuple each time is time consuming and
     useless.  */

  /* The tuple type does not contain the symbols, it is useless.  A
  tuple type is just (T1,T2,T3...)

  The transformation of f(a:int, b:float) into f(float,int) is done by
  the function caller in the case of functions, and by
  compile_generics in the case of generics.  */


  assert (is_form (form, generic_form));

  list_t location_alist = NULL;
  list_t *ptr = &location_alist;

  FOREACH (element, form->form_alist)
    {
      form_t int_or_symbol_form = CAR (CAR (element));
      form_t subform = CDR (CAR (element));

      location_t loc = compile (subform);

      *ptr = CONS (CONS (int_or_symbol_form, loc), NULL);
    }

  location_t location = compound_location ();

  //  compound_location (
  //  tuple
  
}

location_t
compile_function_call (generic_form_t form)
{
  assert (is_form (form, generic_form));

  compile_tuple (form);
  
  /* XXX: compile tuple location.  */

  panic ("Compile tuple location\n");
  /* XXX: call backend-specific part to compile the tuple.  */
  
}

/* Function call handling.  */

/* Compile a call to an unknown function (but known generic).  */
location_t
compile_function_call_unknown_function (generic_form_t form)
{
  /* XXX Put it in the list of functions to compile.  So we compile
     only the needed functions, with the good types?  Could be an
     idea.  We should also compile the "public" functions (i.e. usable
     from the outside).  */


  /* */

  panic ("Not implemented\n");
  
  
  
}
#endif


/* Compile a call to a function already generated.  */
location_t
compile_function_call (generic_form_t form)
{
  assert(form->head == SYMBOL(funcall));

  expanded_form_t expanded_symbol_form = CAR(form->form_list);
  symbol_form_t symbol_form = expanded_symbol_form->return_form;
  symbol_t head = symbol_form->value;
  list_t args = form->form_list->next;
	 

  function_t function = gethash (head, function_hash);

  assert (function); /* For now, the function has to be already defined.
			
			We can't determine the type of the return
			anyway for now; so we will have to do a short
			"generic analysis" which gives the type of the
			generic, and when the function isn't compiled
			yet, mark it as to be compiled, and when
			compiled backpatch every calls to it. */
  
  assert (function->type->type_type == FUNCTION_TYPE);

  location_t locations[function->nb_arguments];

  {
    int i = 0;
    FOREACH (element, args)
      {
	locations[i++] = compile (CAR (element));
      }

    if(i != function->nb_arguments)
      compile_error ("Wrong number of arguments: %d passed, %d expected\n",
		     i, function->nb_arguments);
  }


  Type *fields;

  assert (function->type->type_type == FUNCTION_TYPE);
  assert (function->type->parameters_type->type_type == TUPLE_TYPE);
  
  fields = ((Tuple_Type) ((Function_Type) function->type)->parameters_type)->fields;
      
  
    for(int i = 0; i < function->nb_arguments; i++)
    {
      char *type_loc = asprint_type (location_type (locations[i])->type_form);
      char *type_fields = asprint_type (fields[i]->type_form);

      if(location_type (locations[i]) != fields[i])
	compile_error ("Type mismatch in funcall %s : passing a %s instead of a %s "
		       "for argument number %d\n",
		       form->head->name,
		       type_loc,
		       type_fields,
		       //asprint_type (((Tuple_Type) ((Function_Type) function->type)->parameters_type)->fields[i]),
		       i);
    }
  
  
  
  /* XXX: check args, perform coercion.  We should have a coerce.c for
     that.

     When is coercion should be left undefined, because coercion
     should have no side effects, so can be performed either here or
     when each individual argument of the called function is compiled.  */
     
  location_t loc = function_call (function, function->nb_arguments, locations);

  /* Free the passed parameters.  */
  for(int i = 0; i < function->nb_arguments; i++)
    {
      free_location (locations[i]);
    }
  
  location_type (loc) = ((Function_Type) function->type)->return_type;

  return loc;
  
  
  panic ("To reimplement later\n");

#if 0
  /* XXX: it is important that compilation is done from left to
     right.  */
  unsigned int filled_arguments = 0;

  FOREACH (element, form->form_alist)
    {
      form_t int_or_symbol_form  = CAR (CAR (element));
      form_t value_form  = CDR (CAR (element));

      unsigned int arg_number;

      if(is_form (int_or_symbol_form, int_form))
	{
	  arg_number = ((int_form_t) int_or_symbol_form)->value;
	}
      else
	{
	  assert (is_form (int_or_symbol_form, int_form));
	  symbol_t key = ((symbol_form_t) int_or_symbol_form)->value;

	  for(int i = 0; i < function->nb_arguments; i++)
	    {
	      if(key == function->arguments_name[i])
		{
		  arg_number = i;
		  goto next;
		}
	    }
	  compile_error ("The key %s cannot be used for form %s:\n",
			 key->name,
			 form->head->name);
	}
    next:

      if(filled_arguments & (1 << arg_number))
	{
	  compile_error ("Parameter %d (key %s) has been passed twice\n",
			 arg_number,
			 function->arguments_name[arg_number]->name);
	}

      filled_arguments |= (1 << arg_number);

      locations[arg_number] = compile (value_form);
    }
  
  /* Now check whether we need default values, and whether we can
     provide them.  */

  if ((~filled_arguments & (~function->has_default_value))
      & ((1 << function->nb_arguments) - 1))
    {
      compile_error ("Some parameters ommited don't have a default value\n");
    }

  if(!filled_arguments & ((1 << function->nb_arguments) - 1))
    panic ("Unimplemented\n");

  Type *fields;

  assert (function->type->type_type == FUNCTION_TYPE);
  assert (function->type->parameters_type->type_type == TUPLE_TYPE);
  //  if(function->type->type_type == TUPLE_TYPE)
  //    {
      fields = ((Tuple_Type) ((Function_Type) function->type)->parameters_type)->fields;
//    }
//  else
//    {
//      panic ("HERE\n");
//      fields = &((Function_Type) function->type)->parameters_type;
//    }
      
      if(function->type->parameters_type->length != filled_arguments)
	compile_error ("Error when calling %s: %d arguments given, expecting %d\n",
		       function->name->name,
		       filled_arguments,
		       function->type->parameters_type->length);
		       
		       
      
    for(int i = 0; i < function->nb_arguments; i++)
    {
      char *type_loc = asprint_type (location_type (locations[i])->type_form);
      char *type_fields = asprint_type (fields[i]->type_form);

      if(location_type (locations[i]) != fields[i])
	compile_error ("Type mismatch in funcall %s : passing a %s instead of a %s "
		       "for argument number %d\n",
		       form->head->name,
		       type_loc,
		       type_fields,
		       //asprint_type (((Tuple_Type) ((Function_Type) function->type)->parameters_type)->fields[i]),
		       i);
    }
  
  
  
  /* XXX: check args, perform coercion.  We should have a coerce.c for
     that.

     When is coercion should be left undefined, because coercion
     should have no side effects, so can be performed either here or
     when each individual argument of the called function is compiled.  */
     
  location_t loc = function_call (function, function->nb_arguments, locations);

  /* Free the passed parameters.  */
  for(int i = 0; i < function->nb_arguments; i++)
    {
      free_location (locations[i]);
    }
  
  location_type (loc) = ((Function_Type) function->type)->return_type;

  return loc;
  #endif

}


/* Access handling */

location_t
type_does_not_have_accessor (Type type, form_t form)
{
  compile_error ("Type %s does not have accessor\n",asprint_type (type));
}


#if 0
location_t
struct_accessor (location_t loc, form_t form)
{
  if(!is_form (form, quoted_symbol_form))
    {
      compile_error ("Must use a symbol to access type %s\n",
		     asprintf_type (location_type (loc)));
    }

  symbol_t symbol = ((quoted_symbol_form_t) form)->value;
  
  hash_table_t hash_table = location_type (loc)->accesser.data;

  location_t return_loc = get_struct_field (loc, symbol);
  
}
#endif

location_t
compile_access (generic_form_t form)
{
  form_t accessed_form = CAR (form->form_list);

  expanded_form_t exp_accessor_form = CAR (form->form_list->next);

  location_t accessed_location = compile (accessed_form);
  //  location_t accessor_location = compile (accessor_form);

  Type type = location_type (accessed_location);

  if(type->type_type != STRUCT_TYPE)
    {
      compile_error ("Can't get field access for something that is not a function\n");
    }
  
  //  location_t new_loc = //type->accesser.accesser_function (accessed_location,
    //							 accessor_form);
  //location_t new_loc = struct_accessor (accessed_location, accessor_form);

  assert(is_form(exp_accessor_form, expanded_form));
  form_t accessor_form = exp_accessor_form->return_form;

  if(!is_form (accessor_form, quoted_symbol_form))
    {
      compile_error ("Must use a symbol to access type %s\n",
		     asprint_type (location_type (accessed_location)));
    }

  
  location_t new_loc = get_struct_field (accessed_location,
					 ((quoted_symbol_form_t) accessor_form)->value);

  free_location (accessed_location);

  return new_loc;
  //  if(
}



/* Branching: labels, goto, loops ... */

typedef struct loop_info
{
  symbol_t name;  /* Name of the loop, or NULL if not named.  */
  backward_label_t start_label; /* Label starting the loop.  */
  forward_label_t end_label; /* Label ending the loop.  */
  struct loop_info *next;
} *loop_info_t;

/* __thread  */ static loop_info_t current_loops;


/* XXX: a loop can have a name or not.  */
location_t
compile_loop (generic_form_t form)
{
  loop_info_t loop_info = MALLOC (loop_info);
  loop_info->next = current_loops;
  current_loops = loop_info;

  loop_info->start_label = make_label_here ();
  loop_info->end_label = make_forward_label ();

  /* Now compile the interior of the loop.  */
  location_t location = compile (CAR (form->form_list));

  /* Check that the inner loop doesn't return a value? */
  free_location (location);

  goto_label (loop_info->start_label);
  put_label_here (loop_info->end_label);
  
}

location_t
compile_break (generic_form_t form)
{
  goto_label (current_loops->end_label);

  location_t loc = void_location ();
  location_type (loc) = TYPE ("Void");
  
  return loc;
}

location_t
compile_continue (generic_form_t form)
{
  goto_label (current_loops->start_label);

  location_t loc = void_location ();
  location_type (loc) = TYPE ("Void");
  return loc;
}

/* XXX: the goto construct only allows goto in the forward direction?
   No that would be another level.  But, it only allows goto to labes
   in its current block or enclosing block.  */




/* XXX: use a boolean hash.  */
MAKE_STATIC_HASH_TABLE (boolean_hash);


#define DEFINE_BOOLEAN_OP(name)						\
boolean_expression_switch_t			                        \
compile_##name##_boolean (generic_form_t form)				\
{									\
  form_t form1 = CAR (form->form_list);					\
  form_t form2 = CAR (form->form_list->next);				\
									\
  location_t loc1 = compile (form1);					\
  location_t loc2 = compile (form2);					\
									\
  boolean_expression_switch_t bes = make_##name##_switch (loc1, loc2);	\
									\
  free_location (loc1);							\
  free_location (loc2);							\
									\
  return bes;								\
}									\
									\
location_t								\
compile_##name (generic_form_t form)					\
{									\
  boolean_expression_switch_t bes = compile_##name##_boolean (form);	\
									\
  /* XXX: we should use Cmovcc if possible.  */				\
									\
  panic ("Not yet implemented\n");					\
}

DEFINE_BOOLEAN_OP (eq)
DEFINE_BOOLEAN_OP (lt)
DEFINE_BOOLEAN_OP (gt)
DEFINE_BOOLEAN_OP (le)
DEFINE_BOOLEAN_OP (ge)
DEFINE_BOOLEAN_OP (ne)

boolean_expression_switch_t
compile_boolean (expanded_form_t expform)
{
  assert(is_form(expform, expanded_form));
  form_t form = expform->return_form;

  if(is_form(form, generic_form))
    {
      generic_form_t gform = (generic_form_t) form;

      boolean_expression_switch_t (*boolean_generic)(generic_form_t form) = gethash (gform->head, boolean_hash);

      if(boolean_generic)
	{
	  boolean_expression_switch_t bes = boolean_generic (form);
	  return bes;
	}
    }

  
  /* Compile as a standard generic.  */

  location_t loc = compile(expform);

  type_check(TYPE("Bool"), location_type(loc));

  location_t loc2 = constant_value(location_type(loc), 0);
  
  boolean_expression_switch_t bes = make_ne_switch(loc, loc2);
	
  free_location(loc);
  free_location(loc2);
  
  return bes;
}


boolean_expression_switch_t
compile_not_boolean (generic_form_t form)
{
  form_t subform = CAR (form->form_list);

  boolean_expression_switch_t bes = compile_boolean (subform);

  forward_label_t fl = bes->true_jump;

  bes->true_jump = bes->false_jump;
  bes->false_jump = fl;

  return bes;
}

location_t
compile_not (generic_form_t form)
{
  panic ("Not implemented\n");
}


location_t
compile_if (generic_form_t form)
{
  form_t expression_form = CAR (form->form_list);

  form_t then_form = CAR (form->form_list->next);

  form_t else_form = NULL;

  if(form->form_list->next->next)
    else_form = CAR (form->form_list->next->next);

  boolean_expression_switch_t bes = compile_boolean (expression_form);

  put_label_here (bes->true_jump);

  /* XXX: on devrait peut etre faire start_then; start else; end else;
  ca serait bien pour la generation de code C et meme pour le jit, on
  ferait des trucs differents si il y a un else ou non.  */

  create_execution_path_branch ();
  /* XXX: il faut spiller de la meme maniere dans les deux branches.  */  
  location_t then_loc = compile (then_form);
  join_execution_path_branch ();
  
  if(else_form)
    {
      location_t unified_loc = make_unifiable_location (then_loc);
      /* Make then_loc unifiable.  */
      forward_label_t end_label = make_forward_label ();
      goto_label (end_label);
      
      put_label_here (bes->false_jump);
      location_t else_loc = compile (else_form);

      /* Unify the locations.  */
      unify_location (unified_loc, else_loc);
      put_label_here (end_label);

      return (unified_loc);
    }
  else
    {
      put_label_here (bes->false_jump);
      free_location (then_loc);

      location_t loc = void_location ();
      location_type (loc) = TYPE ("Void");
      return loc;
    }
}


location_t
uncompiled_generic (generic_form_t form)
{
  panic ("Here\n");
}




/* Standard operators.  */



#define DEFINE_OP(name_)						\
location_t								\
compile_##name_ (generic_form_t form)					\
{									\
  /* XXX: call compile_compound?  */					\
									\
  form_t first_arg = CAR (form->form_list);				\
  form_t second_arg = CAR (form->form_list->next);			\
									\
  location_t loc1 = compile (first_arg);				\
  location_t loc2 = compile (second_arg);				\
									\
  assert (loc1->type == TYPE ("Int"));				\
  assert (loc2->type == TYPE ("Int"));				\
									\
  /* XXX: check type, and try to coerce into int, unsigned int, or float?.  */ \
  location_t result = name_##_int_locations (loc1, loc2);		\
									\
  assert (result->type == TYPE ("Int"));				\
									\
  if(result == loc1 || result == loc2)					\
    assert (result->ref_count == 2);					\
									\
  free_location (loc1);							\
  free_location (loc2);							\
									\
  return result;							\
}

DEFINE_OP (add)
DEFINE_OP (mul)
DEFINE_OP (sub)


/* XXX: ++ and -- are really simple to do now.

   post_incr: on cree une valeur temporaire, et on incremente.
   pre_incr: on incremente, et on retourne la valeur.

   En fait c'est un bon exemple de generic ajoute. Et aussi un exemple
   de truc rajoutable dans les differents hook du parseur (prefix
   unary operation, postfix unary operation).
 */





void generate (generic_form_t form)
{
  /* XXX: the form should really be "(compile nom_du_bout_de_code form)"  */
  
  assert (is_form (form, generic_form));
  assert (form->head == SYMBOL (define));

  symbol_form_t sf = CAR (form->form_list);
 
  assert (is_form (sf, symbol_form));
  symbol_t type_symbol = sf->value; 

  assert (type_symbol == SYMBOL (function));
  
  symbol_form_t name_form = CAR (form->form_list->next);
  symbol_t name = name_form->value;


  compile_function (type_symbol, name, CAR (form->form_list->next->next));
}

//void *define_type;
//void *define_function;

//#define DEFINE_TYPE(name__, type__, size__, alignment__)		\
//  do {									\
//    symbol_t symbol_name = intern (name__);				\
//									\
//    /*type__->definer = definer__;*/					\
//    type__->size = size__;						\
//    type__->alignment = alignment__;					\
//    type__->type_form = base_type_form (symbol_name);			\
//									\
//    puthash (symbol_name, type__, type_hash);				\
//  } while(0)

int
test_function (int i)
{
  printf ("Test function: i= %d\n", i);
}

void
init_generate (void)
{
  current_loops = NULL;
  //  init_backend ();

  DEFINE_GENERIC ("+_Int", compile_add);
  DEFINE_GENERIC ("*_Int", compile_mul);
  DEFINE_GENERIC ("-_Int", compile_sub);

  
  DEFINE_GENERIC ("=", compile_assign);
  DEFINE_GENERIC ("[]_Struct", compile_access);
  
  DEFINE_GENERIC ("block", compile_block);
  //DEFINE_GENERIC ("define", compile_define);
  DEFINE_GENERIC ("let", compile_let);
  DEFINE_GENERIC ("deref", compile_deref);
  DEFINE_GENERIC ("cast", compile_cast);
  DEFINE_GENERIC ("ref", compile_ref);
  DEFINE_GENERIC ("seq", compile_seq);
  DEFINE_GENERIC ("funcall", compile_function_call);

  DEFINE_GENERIC ("loop", compile_loop);
  DEFINE_GENERIC ("break", compile_break);
  DEFINE_GENERIC ("continue", compile_continue);

  DEFINE_GENERIC ("if", compile_if);

#define DEFINE_BOOLEAN_GENERIC(string, name)				\
  puthash (intern (string), compile_##name##_boolean, boolean_hash);	\
  DEFINE_GENERIC (string, compile_##name)

  DEFINE_BOOLEAN_GENERIC ("==", eq);
  DEFINE_BOOLEAN_GENERIC ("<=_Int", le);
  DEFINE_BOOLEAN_GENERIC ("<_Int", lt);
  DEFINE_BOOLEAN_GENERIC (">=_Int", ge);
  DEFINE_BOOLEAN_GENERIC (">_Int", gt);
  DEFINE_BOOLEAN_GENERIC ("!=", ne);
  DEFINE_BOOLEAN_GENERIC ("!", not);

  /* XXX: */

  DEFINE_C_FUNCTION (test_function, "Int<-Int");

  /* XXX: the type Form is defined twice */
  //  extern Type TYPE (Form);
  define_type_string ("Form", sizeof(void *), __alignof__ (void *), NULL);

  DEFINE_C_FUNCTION (compile, "Int <- Form");

}


void init_location ()
{
}

void run_analysis ()
{
}

/* Retrieve the value associated to ID for use by the compiler.  */
//void *
//symbol_value (symbol_t id, type_t expected_type) {}
