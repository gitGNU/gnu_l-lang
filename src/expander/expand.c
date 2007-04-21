/* expand.c - Handles code expansion, and base expanders.
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


/* One of the main features of L is the ability to define expanders,
   which are functions that transfor a chunk of code (a form) into
   another (more complicated) one.

   In the most general sense this allow the definition of
   domain-specific languages inside L (with or without the combinaison
   with the parser modification), or more generally, to introduce new
   constructs in the language.

   An expander translates a form into another form.  Generally, the
   to-expand form (i.e. the input to the expander) is a compound form,
   which looks like head(subform1, subform2, subform3).

   Expansion calls the expander associated to head.  The association
   is made by calling define_expander('head_symbol', expander).

   Expansion is a recursive process: subforms inside a form can also
   be expanded, and so on.  The rule to use (in order to prevent
   exponential expansiation) is that any form can be expanded only
   once.  However, the expanded subform (the result of the expansion)
   can be used at several place in the expanded form.  A subform can
   never be expanded.

   Another rule is: never use a subform 'as is' in the expanded
   form. Either decompose it manually, or expand it.  For now the
   compiler does it for you; this isn't guaranteed for the future.

   Contrary to Lisp, expansion in L is typed.  Along with the expanded
   form, the type of the form is returned.  Expansion of a form can
   thus be parametrized by the type of its input.  This allows, for
   instance, definition of a foreach expander that acts differently if
   it is iterating on a list or on a hash.  Other informations are
   also returned by an expander; this will mainly allow optimisations
   in the expansion process.
   
   A special kind of expander is the macro.  This is a simple expander
   in which all subforms are expanded.  This has a simpler user
   interface, and allows to use predefined algorithms for selection of
   expander function from the type of the arguments (for instance, one
   may use CLOS-like multiple-dispatch overload resolution function,
   somebody else Java-like single-dispatch one, etc...).  Incidently,
   overload resolution of functions is implemented by macros.
*/


/* Order in definition:



   - If an expander is used in another macro, it must be defined
   first, or in the current processed chunk.  
  
   - If a macro is used in a function, it must also be defined first, 
   or in the currend processed chunk.  

     - If a function is used in a function, it ...*/

/* Example: expansion of list.

   list(a,b,c) -> cons(a,cons(b, cons(c, cast(List(type(a)), 0))))
               -> ...

   The parameters a,b,c are expanded twice: once in the list
   expansion, once in the cons.

   So we have to record when forms have been expanded.

   Later, we may be able to transform the macro definition to
   macro-expand everything at once.

*/

#include <l/expand.h>
#include <l/sys/type.h>
#include <l/sys/panic.h>

#include <assert.h>

#define panic(format, ...)						\
  do {fprintf (stderr, "error: " format, ## __VA_ARGS__); asm("int $3"); exit (1); } while(0)

/* This function should also be the only one that does type checking,
   and more generally to construct expanded forms.  */


/* Main functions and helper.  */

MAKE_STATIC_HASH_TABLE(expander_hash);



expanded_form_t
create_expanded_form(form_t form, Type type)
{
  assert(!(is_form(form, expanded_form)));

  expanded_form_t expanded_form = new_form(expanded);

  expanded_form->return_form = form;
  expanded_form->type = type;
  
  return expanded_form;
}




/*
XXX: translate_id for id translation.  We could thus make
current_block and current_function static.
*/

/* Note: this can also be useful for symbol-macros, as present in
   Common Lisp.  */
expanded_form_t
expand_id(symbol_t symbol);

/* A maybe_expanded_form_t is a form that may be expanded:

 Either the last bit is set to 0, and we have a regular form_t, or the
 last bit is set to 1, and we have an expanded_form_t.

 The user functions always take a form_t as an argument; as we don't
 reexpand a form twice.  */


expanded_form_t
expand (form_t form)
{
  assert(((int) form & 1) == 0);

  if(is_form (form, atomic_form))
    {
      
      if(is_form (form, expanded_form))
	{
	  /* The form has already been expanded.  */
	  return form;
	}
      
      if(is_form (form, int_form))
	{
	  return create_expanded_form(form, intern_type(base_type_form(SYMBOL(Int))));
	}

      if(is_form(form, id_form))
	{
	  return expand_id(((id_form_t) form)->value);
	}
      if(is_form (form, quoted_symbol_form))
	{
	  return create_expanded_form(form, intern_type(base_type_form(SYMBOL(Symbol))));
	}
      if(is_form (form, string_form))
	{
	  return create_expanded_form(form, intern_type(base_type_form(SYMBOL(String))));
	}

	//	return typed_form (TYPE (symbol), form);
      panic("Here");

    }
  
  assert (is_form (form, generic_form));
  
  generic_form_t gform = (generic_form_t) form;

  for(;;) {
      /* XXX: problem if we want to redefine if to take lists as
      arguments for instance, we would loop for ever. So for now, we
      just look if the returned symbol is the same.

      Or now, we could use the "already expanded" mecanism to do the
      difference: newly created forms would be re-expanded, whereas
      old forms would not be.

      We could make the expand_info into the forms; but if we
      duplicate the forms, the expand info is different.

      In the future we will have cocyte::if and malebolge::if, and
      that will solve the problem.  (We would expand until we find
      something in the cocyte namespace). */

      symbol_t head = gform->head;
      
      expander_t expander = gethash (head, expander_hash);

      if(expander == NULL)
	panic("Error : no expander defined for %s\n", head->name);

      gform = expander (gform);

      if(is_form( gform, expanded_form))
	break;

      if(is_form( gform, atomic_form))
	{
	  gform = expand( gform);
	  break;
	}
  }

  assert(is_form(gform, expanded_form));

  return gform;
}



/* Block and local variable definition.  */
typedef struct id_info
{
  /* Species of the variable.  */
  Species species;
  
  /* Type of the variable.  */
  Type type;

  /* Misc information: is the variable global, is the variable
     thread_local, is the variable constant, is the variable an alias
     (with a different type) to another variable, if the variable has
     been used...  */
  union
  {
    Symbol unique_name; /* This is used to rename variables so that
			   there is no shadowing.  */
  };
} *id_info_t;

/* A table ID -> IType (for now; later we may ).  */
typedef hash_table_t id_table_t;

typedef struct block
{
  id_table_t id_table;
  struct block *next;
} *block_t;

static block_t block_list = NULL;

static void
new_block(void)
{
  block_t new_block = MALLOC(block);
  new_block->next = block_list;
  new_block->id_table = make_hash_table();
  block_list = new_block;
}

static void
remove_block(void)
{
  block_list = block_list->next;

  /* XXX: Traverse the hash table to find unused variables and so
     on?  */
}

Symbol
uniquify( Symbol s)
{
  char buffer[1024];

  static int i = 0;
  sprintf( buffer, "%s#u#%d", s->name, i);
  return intern( buffer);
}

#include <stdarg.h>
Symbol
insert_id( symbol_t symbol, int can_shadow, Species species, ...)
{
  va_list ap;
  va_start( ap, species);

  int is_shadowing = 0;
  {
    /* Check if id is already present.  */
    block_t cur_block = block_list;
    id_info_t id_info;
    while(cur_block)
      {
	if((id_info = gethash(symbol, cur_block->id_table)))
	  {
	    is_shadowing = 1;
	    /* Later, it should be permitted to shadow an id when
	       told explicitely, but only in a new scope( and id_table).  */
	  }
	cur_block = cur_block->next;
      }
  }
    
  if(can_shadow == 0 && is_shadowing)
    panic( "ID %s shadows an existing identifier\n", symbol->name);

  id_info_t ii = MALLOC(id_info);
  ii->species = species;

  switch(species)
    {
    case SPECIES_VARIABLE:
      {
	Type t;
	t = va_arg( ap, Type);
	ii->type = t;
	if(is_shadowing)
	  {
	    ii->unique_name = uniquify( symbol);
	  }
	else
	  {
	    ii->unique_name = symbol;
	  }
	break;
      }
    case SPECIES_LABEL:
      {
	
	break;
      }
    default:
      panic( "Don't know yet how to handle species %d\n", species);
    }
  
  puthash(symbol, ii, block_list->id_table);

  va_end( ap);
  return ii->unique_name;
}


#include <l/sys/global.h>

expanded_form_t
expand_id_no_fail(symbol_t symbol)
{
  block_t cur_block = block_list;
  id_info_t id_info;
  while(cur_block)
    {
      if((id_info = gethash(symbol, cur_block->id_table)))
	{
	  goto next;
	}
      cur_block = cur_block->next;
    }

  /* Not a local id.  Maybe it is global.  */
  global_t glob = gethash( symbol, global_hash);

  if(glob)
    {
      /* XXX: we could tell the expander this is a global.  */
      return create_expanded_form( id_form( symbol),
				   glob->type);
    }

  /* This is an error.  */
  return NULL;

 next:

  switch(id_info->species)
    {
    case SPECIES_VARIABLE:
      return create_expanded_form(id_form(id_info->unique_name),
				  id_info->type);
      
    case SPECIES_LABEL:
      /* This is a bit hacky; we can get rid of @get_label when
	 the compiler can directly reuse the expander's id.  */
      return create_expanded_form(generic_form_symbol( intern( "@get_label"),
						       CONS( id_form( symbol),
							     NULL)),
				  TYPE( "Label"));

    default:
      compile_error ( "This species cannot be expanded\n");
    }
}

expanded_form_t
expand_id( symbol_t symbol)
{
  expanded_form_t exp = expand_id_no_fail( symbol);

  if(exp == NULL)
    panic("Id %s was not found\n", symbol->name);
  return exp;
}


/* XXX: allow when the announced return type is a tuple of less
   components than the body.
 */

expanded_form_t
expand_lambda(generic_form_t form)
{
  form_t return_type_form = CAR (form->form_list);
  generic_form_t parameters = CAR (form->form_list->next);
  generic_form_t body = CAR (form->form_list->next->next);

  /* Create a new block containing the passed arguments;  */
  assert(block_list == NULL);
  new_block();


  FOREACH(element, parameters->form_list)
    {
      generic_form_t gf = CAR(element);
      assert(gf->head == SYMBOL(label));

      symbol_form_t id_form = CAR(gf->form_list);
      assert(is_form(id_form, symbol_form));

      type_form_t type_form = CAR(gf->form_list->next);

      symbol_t id = id_form->value;
      Type type = intern_type(type_form);

      insert_id(id, 0, SPECIES_VARIABLE, type);
    }
  
  expanded_form_t expanded_body = expand(body);
  
  remove_block();
  assert(block_list == NULL);


  Type return_type = intern_type(return_type_form);

  /* TODO: The user may announce only a supertype of the returned
     type.  */
  if(return_type != expanded_body->type)
    panic("Function body's return type (%s) does not match"
	  "the given return type(%s)\n", asprint_type_form(return_type_form),
	  asprint_type(expanded_body->type));

  /* Create the function type form.  */
  type_form_t function_form = function_type_form(return_type_form, parameters);

  expanded_form_t eform = create_expanded_form(lambda_form(return_type_form,
							   parameters,
							   expanded_body),
					       intern_type(function_form));



  return eform;
  
 }



expanded_form_t
expand_block(generic_form_t form)
{
  if(form->form_list == NULL)
    panic ("Blocks cannot be empty\n"); /* Or empty blocks could be void.  */
    
  new_block();

  /* MAP expand on the forms; return the type of the last one.  */
  list_t expanded_form_list;
  
  list_t *expanded_form_list_ptr = &expanded_form_list;
  expanded_form_t last_element = NULL;

  FOREACH(element, form->form_list)
    {
      last_element = expand(CAR(element));
      *expanded_form_list_ptr = CONS(last_element, NULL);
      expanded_form_list_ptr = &((*expanded_form_list_ptr)->cdr);
    }
  *expanded_form_list_ptr = NULL;

  /* Add all the needed variables at the beginning of the block.  */
  {
    Symbol Index = 0;
    id_info_t *PValue;
    JLF(PValue, *block_list->id_table, Index);
    while (PValue != NULL)
      {
	id_info_t ii = *PValue;
	if(ii->species == SPECIES_VARIABLE)
	  {
	    expanded_form_t explet = create_expanded_form( generic_form_symbol( SYMBOL( let),
										CONS(id_form( ii->unique_name),
										     CONS( ii->type->type_form,
											   NULL))),
							   ii->type);
	    expanded_form_list = CONS( explet,
				       expanded_form_list);
	  }
	JLN(PValue, *block_list->id_table, Index);
      }
  }
  

  
  remove_block();
  /* The final type is the last one.  */
  return create_expanded_form(block_form(expanded_form_list),
			      last_element->type);
}


expanded_form_t
expand_seq(generic_form_t form)
{
  /* MAP expand on the forms; return the type of the last one.  */
  list_t expanded_form_list;
  
  list_t *expanded_form_list_ptr = &expanded_form_list;
  expanded_form_t last_element = NULL;

  FOREACH(element, form->form_list)
    {
      last_element = expand(CAR(element));
      *expanded_form_list_ptr = CONS(last_element, NULL);
      expanded_form_list_ptr = &((*expanded_form_list_ptr)->cdr);
    }
  *expanded_form_list_ptr = NULL;
  
  /* The final type is the last one.  */
  return create_expanded_form(seq_form(expanded_form_list),
			      last_element->type);
}

expanded_form_t
expand_let(generic_form_t form)
{
  type_form_t type_form = CAR (form->form_list->next);
  id_form_t id_form = CAR (form->form_list);

  symbol_t id = id_form->value;
  Type type = intern_type(type_form);

  insert_id(id, 1, SPECIES_VARIABLE, type);

  /* ID should be expanded.  */
  return create_expanded_form(//generic_form_symbol( SYMBOL( let),
			      /*		   CONS(*/ id_form,
			      //							 CONS( type_form,
			      //							       NULL))),
			      type);
}

expanded_form_t
expand_assign(generic_form_t form)
{
  form_t assignee = CAR (form->form_list);
  
  form_t expression = CAR (form->form_list->next);

  /* XXX: here we should use a lvalue-expander function.

     Ie, transform (= (foo ...) (bar ...)) into:
     (expandedfoo ... (expanded bar ...))

     See setf in Common Lisp.

     This will allow destructuring like in
     let head -> tail = list;
     or let assignee -> expression -> -| = form.form_list;
  */

  expanded_form_t expanded_expression = expand(expression);
  expanded_form_t expanded_assignee = left_expand(assignee,
						  expanded_expression);

  return expanded_assignee;
}

expanded_form_t
expand_tuple (generic_form_t form)
{
  assert (form->head == SYMBOL (tuple));
  
  list_t new_form_list;
  list_t type_list;
  {
    list_t *new_form_list_ptr = &new_form_list;
    list_t *type_list_ptr = &type_list;
    FOREACH (element, form->form_list)
      {
	expanded_form_t expform= expand (CAR (element));
	
	*new_form_list_ptr = CONS (expform, NULL);
	new_form_list_ptr = &((*new_form_list_ptr)->next);

	*type_list_ptr = CONS (expform->type->type_form, NULL);
	type_list_ptr = &((*type_list_ptr)->next);
      }
    *new_form_list_ptr = NULL;
    *type_list_ptr = NULL;
  }

  return create_expanded_form (new_tuple_form (new_form_list),
			       intern_type (tuple_type_form (type_list)));
}

/* struct(x:exp1, y:exp2) creates a (stack) structure of type struct
   {typeof(exp1) x; typeof(exp2) y; }; */
expanded_form_t
expand_struct (generic_form_t form)
{
    /* MAP expand on the forms; return the type of the last one.  */
  list_t component_list;
  list_t type_form_list;
  
  list_t *component_list_ptr = &component_list;
  list_t *type_form_list_ptr = &type_form_list;

  FOREACH(element, form->form_list)
    {
      generic_form_t genform = CAR (element);
      assert (is_form (genform, generic_form));
      assert (genform->head == SYMBOL (label));
      assert (genform->form_list && genform->form_list->next
	      && !genform->form_list->next->next);

      id_form_t id_form = CAR (genform->form_list);
      assert (is_form (id_form, id_form));
      //      Symbol label_symb = 

      expanded_form_t expform = expand (CAR (genform->form_list->next));
      *type_form_list_ptr = CONS (label_form (id_form,
					      expform->type->type_form),
				  NULL);
      type_form_list_ptr = &((*type_form_list_ptr)->next);
      
      *component_list_ptr = CONS(create_expanded_form (label_form (id_form,
								   expform),
						       expform->type),
				 NULL);
      component_list_ptr = &((*component_list_ptr)->cdr);
    }
  
  *type_form_list_ptr = NULL;
  *component_list_ptr = NULL;

  type_form_t struct_type_form = generic_form_symbol (SYMBOL (struct),
						      type_form_list);

  Type struct_type = intern_type (struct_type_form);
  
  /* The final type is the last one.  */
  return create_expanded_form(generic_form_symbol (SYMBOL (struct),
						   component_list),
			      struct_type);
}

/* Note: labels serve different purpose in L; but when they are
   regularly expanded, they are a label for a goto.  Other use cases
   (such as naming passed parameters to a function or macros) must
   extract the label directly.

   Note: labels can have, or not, an argument.
   */
expanded_form_t
expand_label (generic_form_t form)
{
  assert( form->form_list);
  id_form_t id_form = CAR (form->form_list);
  assert (is_form (id_form, id_form));

  insert_id( id_form->value, 1, SPECIES_LABEL);


  if(form->form_list->next)
    {
      expanded_form_t expform = expand (CAR (form->form_list->next));

      return create_expanded_form( generic_form_symbol( SYMBOL( seq),
							CONS( create_expanded_form( generic_form_symbol( SYMBOL( label),
													 CONS( id_form,
													       NULL)),
										    TYPE( "Void")),
							      CONS( expform,
								    NULL))),
				   expform->type);
    }
  else
    {
      return create_expanded_form( generic_form_symbol( SYMBOL( label),
							CONS( id_form,
							      NULL)),
				   TYPE( "Void"));
    }
}

expanded_form_t
expand_goto (generic_form_t form)
{
  form_t label = CAR( form->form_list);

  form_t explabel;
  symbol_t goto_type;
  
  if(is_form( label, id_form))
    {
      goto_type = intern( "@goto_constant");
      explabel = label;
    }
  else
    {
      goto_type = intern( "@goto_variable");
      explabel = expand( label);
      assert( ((expanded_form_t)explabel)->type == TYPE( "Label"));
    }

  
  
  return create_expanded_form (generic_form_symbol( goto_type,
						    CONS( explabel,
							  NULL)),
			       TYPE( "Void"));
}

expanded_form_t
expand_at_get_label( generic_form_t form)
{
  assert( form->form_list && !form->form_list->next);
  id_form_t sid_form = CAR( form->form_list);
  Symbol symbol = sid_form->value;
  
  block_t cur_block = block_list;
  id_info_t id_info;
  while(cur_block)
    {
      if((id_info = gethash(symbol, cur_block->id_table)))
	{
	  goto next;
	}
      cur_block = cur_block->next;
    }
  
  /* THe label was not found, but that's OK, it can be defined later.  */
  goto end;

 next:

  /*If it was found, it must be a label.  */
  if( id_info->species != SPECIES_LABEL)
    panic( "Label was expected, species %d was given", id_info->species);

 end:
  return create_expanded_form(generic_form_symbol( intern( "@get_label"),
						   CONS( id_form( symbol),
							 NULL)),
			      TYPE( "Label *"));
}



/* Function call.  */

/* We transform "foo(bar, baz)" (parsed into (foo bar baz)) 
   into (funcall foo bar baz).

   Here, if a function is overloaded, we would call the appropriate
   function.

   We also take the keyword arguments (with label) and default
   arguments in the transformation.

   The type of the parameters passed are checked; coercion may be
   performed.
  */

#include "../objects/function.h"

expanded_form_t
expand_function(generic_form_t form)
{
  symbol_t head = form->head;

  

  /* XXX: retrieve function name from function.  */
  global_t global = gethash( head, global_hash);
  
  symbol_t function_name = head;
//  Function_Type function_type = function->type;
  Function_Type function_type = global->type;

  assert(function_type->type_type == FUNCTION_TYPE);

  Type return_type = function_type->return_type;

  /* XXX: reorder the function along the labels.  For instance,
     transform make_point(y:3, x:4) into make_point(4, 3, 0);.
     Some macros will need that too.
  */

  /* MAP expand on the forms; return the type of the last one.  */
  list_t expanded_form_list;

  {
    list_t *expanded_form_list_ptr = &expanded_form_list;
    expanded_form_t last_element = NULL;
    
    FOREACH(element, form->form_list)
      {
	last_element = expand(CAR(element));
	/* XXX: check type.  */
	*expanded_form_list_ptr = CONS(last_element, NULL);
	expanded_form_list_ptr = &((*expanded_form_list_ptr)->cdr);
      }
    *expanded_form_list_ptr = NULL;
  }

  expanded_form_list = CONS(//create_expanded_form(id_form(function_name),
			    //						 intern_type(base_type_form(SYMBOL(Symbol)))),
			    expand_id( function_name),
			    expanded_form_list);

  return create_expanded_form(generic_form_symbol(SYMBOL(funcall), expanded_form_list),
			      return_type);
}

/* Expands funcall( expr, args).  No reorganisation here.  */
expanded_form_t
expand_funcall( generic_form_t form)
{
  assert( form->form_list);
  expanded_form_t fun_form = expand( CAR( form->form_list));
  if(fun_form->type->type_type != FUNCTION_TYPE)
    {
      compile_error( "%s is not a function\n", asprint_type( fun_form->type));
    }

  list_t expform_list;
  {
    int i = 0;
    Tuple_Type parameters = ((Function_Type) fun_form->type)->parameters_type;

    list_t *expform_list_ptr = &expform_list;
    
    
    FOREACH( element, form->form_list->next)
      {
	if(i >= parameters->length)
	  compile_error( "Error: too much parameters given\n");

	expanded_form_t expsubform = expand( CAR( element));
	type_check( expsubform->type, parameters->fields[i]);
	
	(*expform_list_ptr) = CONS( expsubform, NULL);
	expform_list_ptr = &((*expform_list_ptr)->next);
	i++;
      }

    if(i != parameters->length)
      compile_error( "Error: too few parameters given\n");

    *expform_list_ptr = NULL;
  }
  return create_expanded_form( generic_form_symbol( SYMBOL( funcall),
						    CONS( fun_form,
							  expform_list)),
			       ((Function_Type) fun_form->type)->return_type);
}

//expanded_form_t
//expand_overload();



/* Operators.  */

/* Here, we transform (+ 1 2) into (+_int 1 2), and (+ 1.0 i) into
   (+_float 1.0 i) for every operator (+,-,/,*).

   We could also transform (+ 1 2 3) into (+_int (+_int 1 2) 3) etc.., but the
   standard syntax makes it useless.  Other syntaxes (e.g. Lisp) would
   just replace the expander.

   XXX: We should distinguish signed int from unsigned int operations,
   especially since *_signed_int is different form *_unsigned_int.
*/


expanded_form_t
expand_binary_operator(generic_form_t form) 
{
  symbol_t head = form->head;

  /* The operator should be one of /+-* */
  assert(strlen(head->name) == 1);

  /* We take only two arguments.  */
  assert(form->form_list && form->form_list->next
	 && !form->form_list->next->next);

  form_t arg1 = CAR(form->form_list);
  form_t arg2 = CAR(form->form_list->next);

  expanded_form_t exp_arg1 = expand(arg1);
  expanded_form_t exp_arg2 = expand(arg2);

  if(exp_arg1->type != exp_arg2->type)
    {
      panic("Error: the two arguments do not have the same type %s %s\n",
	    asprint_type(exp_arg1->type), asprint_type(exp_arg2->type));
    }

  Type type = exp_arg1->type;

  char *type_representation = asprint_type(type);
  char *newstring = malloc(2 + strlen(type_representation));
  newstring[0] = head->name[0];
  newstring[1] = '_';
  strcpy(newstring+2, type_representation);

  symbol_t new_head = intern(newstring);

  return create_expanded_form(generic_form_symbol(new_head,
						  CONS(exp_arg1,
						       CONS(exp_arg2, NULL))),
			      type);
}

expanded_form_t
expand_unary_operator( generic_form_t form)
{
  symbol_t head = form->head;

  /* We take only one arguments.  */
  assert(form->form_list && !form->form_list->next);

  form_t arg1 = CAR(form->form_list);

  expanded_form_t exp_arg1 = expand(arg1);

  Type type = exp_arg1->type;

  symbol_t new_head;
  
  if( type == TYPE( "Int"))
    {
      new_head = SYMBOL( unary_minus_Int);
    }
  else if( type == TYPE( "Float"))
    {
      new_head = SYMBOL( unary_minus_Float);
    }
  else panic( "Unary operator applied to an unknown type\n");
  
  return create_expanded_form(generic_form_symbol(new_head,
						  CONS(exp_arg1,NULL)),
			      type);
}



/* Conditionals.  */

/* If. 

   We check that the type of if is boolean, and that the same type is
   returned in the two branches.

   It would be easy, for instance, to allow the if(list) construct
   here; also the if(pointer) ...
*/


expanded_form_t
expand_if(generic_form_t form) 
{
  form_t condition_form = CAR(form->form_list);
  form_t then_form = CAR(form->form_list->next);
  form_t else_form = NULL;

  expanded_form_t exp_cond_form = expand(condition_form);

  if(exp_cond_form->type != intern_type(base_type_form(SYMBOL(Bool))))
    panic("Type mismatch: Bool expected, %s given\n", asprint_type(exp_cond_form->type));

  expanded_form_t exp_then_form = expand(then_form);
  expanded_form_t exp_else_form = NULL;

  if(form->form_list->next->next)
    {
      else_form = CAR(form->form_list->next->next);
      exp_else_form = expand(else_form);

      if(exp_then_form->type != exp_else_form->type)
	panic("Type of the then (%s) and the else (%s) should be the same\n", 
	      asprint_type(exp_then_form->type),
	      asprint_type(exp_else_form->type));

      return create_expanded_form(if_form(exp_cond_form, exp_then_form, exp_else_form),
				  exp_then_form->type);
    }

  return create_expanded_form(if_form(exp_cond_form, exp_then_form, NULL),
			      exp_then_form->type);
}

/* == should work for any type whose size is that of one word.  The
   requirement is that both sides of the equality are the same.  */
expanded_form_t
expand_equal(generic_form_t form) 
{
  form_t arg1 = CAR(form->form_list);
  form_t arg2 = CAR(form->form_list->next);

  expanded_form_t exp_arg1 = expand(arg1);
  expanded_form_t exp_arg2 = expand(arg2);

  if(exp_arg1->type != exp_arg2->type)
    {
      panic("Type mismatch in ==: arg1 = %s, arg2 = %s\n",
	    asprint_type(exp_arg1->type),
	    asprint_type(exp_arg2->type));
    }

  return create_expanded_form(generic_form_symbol(intern("=="),
						  CONS(exp_arg1,
						       CONS(exp_arg2,
							    NULL))),
			      intern_type(base_type_form(SYMBOL(Bool))));
}

/* Same than for ==  */
expanded_form_t
expand_different(generic_form_t form)
{
  form_t arg1 = CAR(form->form_list);
  form_t arg2 = CAR(form->form_list->next);

  expanded_form_t exp_arg1 = expand(arg1);
  expanded_form_t exp_arg2 = expand(arg2);

  if(exp_arg1->type != exp_arg2->type)
    {
      panic("Type mismatch in ==: arg1 = %s, arg2 = %s\n",
	    asprint_type(exp_arg1->type),
	    asprint_type(exp_arg2->type));
    }

  return create_expanded_form(generic_form_symbol(intern("!="),
						  CONS(exp_arg1,
						       CONS(exp_arg2,
							    NULL))),
			      intern_type(base_type_form(SYMBOL(Bool))));
}


expanded_form_t
expand_binary_relationship(generic_form_t form) 
{
  symbol_t head = form->head;

  /* The operator should be one of < <= => > */
  assert(strlen(head->name) <= 2);

  /* We take only two arguments.  */
  assert(form->form_list && form->form_list->next
	 && !form->form_list->next->next);

  form_t arg1 = CAR(form->form_list);
  form_t arg2 = CAR(form->form_list->next);

  expanded_form_t exp_arg1 = expand(arg1);
  expanded_form_t exp_arg2 = expand(arg2);

  Type int_type = intern_type(base_type_form(SYMBOL(Int)));
  
  if(exp_arg1->type != int_type || exp_arg2->type != int_type)
    {
      panic("Error: the two arguments are not of type Int: %s %s\n",
	    asprint_type(exp_arg1->type), asprint_type(exp_arg2->type));
    }


  /* The generator does only (signed) Int for now.  */

  char *type_representation = "Int";
  char *newstring = malloc(3 + strlen(type_representation));
  newstring[0] = head->name[0];
  if(head->name[1])
    {
      newstring[1] = head->name[1];
      newstring[2] = '_';
      strcpy(newstring+3, type_representation);
    }
  else
    {
      newstring[1] = '_';
      strcpy(newstring+2, type_representation);
    }

  symbol_t new_head = intern(newstring);

  return create_expanded_form(generic_form_symbol(new_head,
						  CONS(exp_arg1,
						       CONS(exp_arg2, NULL))),
			      intern_type(base_type_form(SYMBOL(Bool))));
}

/* Logical operations */
expanded_form_t
expand_logical_or(generic_form_t form)
{
   form_t arg1 = CAR(form->form_list);
   form_t arg2 = CAR(form->form_list->next);
   
   expanded_form_t exp_arg1 = expand(arg1);
   expanded_form_t exp_arg2 = expand(arg2);

   type_check( exp_arg1->type, TYPE( "Bool"));
   type_check( exp_arg2->type, TYPE( "Bool"));

  return create_expanded_form(generic_form_symbol(intern("@logical_or"),
						  CONS(exp_arg1,
						       CONS(exp_arg2,
							    NULL))),
			      intern_type(base_type_form(SYMBOL(Bool))));
}

expanded_form_t
expand_logical_and(generic_form_t form)
{
   form_t arg1 = CAR(form->form_list);
   form_t arg2 = CAR(form->form_list->next);
   
   expanded_form_t exp_arg1 = expand(arg1);
   expanded_form_t exp_arg2 = expand(arg2);

   type_check( exp_arg1->type, TYPE( "Bool"));
   type_check( exp_arg2->type, TYPE( "Bool"));

  return create_expanded_form(generic_form_symbol(intern("@logical_and"),
						  CONS(exp_arg1,
						       CONS(exp_arg2,
							    NULL))),
			      intern_type(base_type_form(SYMBOL(Bool))));
}


expanded_form_t
expand_logical_not(generic_form_t form)
{
   form_t arg1 = CAR(form->form_list);
   
   expanded_form_t exp_arg1 = expand(arg1);

   type_check( exp_arg1->type, TYPE( "Bool"));

  return create_expanded_form(generic_form_symbol(intern("@not"),
						  CONS(exp_arg1,
						       NULL)),
			      intern_type(base_type_form(SYMBOL(Bool))));
}




/* We should also transform >= into >=_signed_int or >=_unsigned_int
   ... */




/* expand_list: as list isn't a core construct, it can return a form
   instead of an expanded form.  It can return an expanded form if it
   does not want that there is a further expansion.  */


/* Type conversion.  */

/* Cast should never be used directly.  In fact, cast should not be
   directly accessible.  */
expanded_form_t
expand_cast(generic_form_t form) 
{
  form_t type_form = CAR(form->form_list);
  form_t expression = CAR(form->form_list->next);

  Type type = intern_type(type_form);
  expanded_form_t exp = expand(expression);

  /* Eventually check that sizes are compatible?  */

  /* XXX: type_form should be of type type? */
  return create_expanded_form(generic_form_symbol(SYMBOL(cast),
						  CONS(create_expanded_form(type_form,
									    TYPE ("Type")),
						       CONS(exp, NULL))),
			      type);
}


/* Pointers, referencing and dereferencing.  */

expanded_form_t 
expand_ref(generic_form_t form)
{
  form_t expression = CAR(form->form_list);
  expanded_form_t exp_exp = expand(expression);

  Type type = exp_exp->type;
  Type pointer_type = get_pointer_type(type);
  
  return create_expanded_form(generic_form_symbol(SYMBOL(ref),
						  CONS(exp_exp, NULL)),
			      pointer_type);
}

expanded_form_t 
expand_deref(generic_form_t form)
{
  form_t expression = CAR(form->form_list);
  expanded_form_t exp_exp = expand(expression);

  Type type = exp_exp->type;
  Type pointed_type = get_pointed_type(type);
  
  return create_expanded_form(generic_form_symbol(SYMBOL(deref),
						  CONS(exp_exp, NULL)),
			      pointed_type);
}


/* Expander definition and  initialisation.  */

void
define_expander(symbol_t symbol, expander_t expander)
{
  puthash(symbol, expander, expander_hash);
}

void
init_expand (void)
{
  init_expand_define();
  
  define_expander(SYMBOL(lambda), expand_lambda);
  define_expander(SYMBOL(block), expand_block);
  define_expander(SYMBOL(seq), expand_seq);
  define_expander(SYMBOL(let), expand_let);
  define_expander(SYMBOL(cast), expand_cast);

  define_expander(intern("="), expand_assign);
  define_expander(SYMBOL (struct), expand_struct);
  define_expander(SYMBOL (label), expand_label);
  
  define_expander(intern( "@and"), expand_logical_and);
  define_expander(intern( "@or"), expand_logical_or);
  define_expander(intern( "@not"), expand_logical_not);
  define_expander(SYMBOL (goto), expand_goto);
  define_expander(intern( "@get_label"), expand_at_get_label);
  define_expander(SYMBOL (tuple), expand_tuple);
  define_expander(SYMBOL(ref), expand_ref);
  define_expander(SYMBOL(deref), expand_deref);

  define_expander(SYMBOL(if), expand_if);
  define_expander(intern("=="), expand_equal);
  define_expander(intern("!="), expand_different);
  define_expander(intern(">="), expand_binary_relationship);
  define_expander(intern("<="), expand_binary_relationship);
  define_expander(intern("<"), expand_binary_relationship);
  define_expander(intern(">"), expand_binary_relationship);


  define_expander(intern("+"), expand_binary_operator);
  define_expander(intern("-"), expand_binary_operator);
  define_expander(intern("*"), expand_binary_operator);
  define_expander(intern("/"), expand_binary_operator);

  define_expander(intern("unary_minus"), expand_unary_operator);
  
  define_expander(SYMBOL(let), expand_let);
   define_expander(SYMBOL(funcall), expand_funcall);
  //  define_expander(SYMBOL(toto), expand_function);
  /* After we have expanded everything, for now we should strip the
expand info so that the cocyte compiler has a normal tree. In the
future, the cocyte compiler will take the expanded tree as its
input.  */

  init_left_expand ();
  init_access ();
  init_expand_loop();
}
