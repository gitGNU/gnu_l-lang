/* expand-define.c - Definer expansion.
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


/* At the end, this is where all definitions should be processed:
   user definitions, types, macros, functions, globals...

   The main problem is inter-dependency between the definitions.  User
   definitions, that expand into other definitions, should come first,
   but they are a bit special.

   Then types should be evaluated at once, then macros at once, then
   functions and globals at once (for each of them, there can be inter
   dependencies).

   TODO: when this is featureful enough, remove analyze.c and use only this.
   */

/* A definer can expand into a list of forms.  */


#include <l/expand.h>
#include <l/sys/panic.h>
#include <assert.h>
#include <l/global.h>



/* Functions and globals expansion.  */

#include <l/sys/global.h>

/* A hash Symbol -> Global.  */
MAKE_STATIC_HASH_TABLE (global_hash);

void
define_global( symbol_t name, Type type,
	       void *address)
{
  global_t glob = MALLOC( global);
  glob->global_type = NORMAL_GLOBAL;
  glob->type = type;
  glob->handling_backend = NULL;
  glob->for_backend = address;

  puthash( name, glob, global_hash);
}

void
define_function( Symbol name, Type type, void *address)
{
  define_global(  name, type, address);
  define_expander(name, expand_function);
}

expanded_form_t
expand_function_definition( Symbol name, generic_form_t lambda_form)
{
  assert( is_form( lambda_form, generic_form)
	  && lambda_form->head == SYMBOL( lambda));
  form_t return_type = CAR (lambda_form->form_list);
  generic_form_t parameters = CAR (lambda_form->form_list->next);
  Type function_type = intern_type( function_type_form (return_type,
								  parameters));

  define_function( name, function_type, NULL);
	  
  /* XXX Why do we expand this.  */
  return create_expanded_form(define_form(SYMBOL(function),
					  name, expand(lambda_form)),
			      NULL);
}

list_t
expand_all_function_and_global( list_t form_list)
{
  /* There should be two passes: one get the types of all the
     functions, and the other compiles them.

     Note: globals and functions should be analysed at the same time,
     they are interdependent.
     
     For now, the first pass is done by analysis.c.  */
  
  list_t exp_form_list;
  {
    list_t *exp_form_list_ptr = &exp_form_list;
    
  FOREACH( element, form_list)
    {
      generic_form_t df = CAR( element);
      assert( is_form(  df, generic_form));
      assert( df->head == SYMBOL( define));
      
      id_form_t form_typef = CAR(df->form_list);
      assert( is_form( form_typef, id_form));
      Symbol form_type = form_typef->value;

      id_form_t name_form = CAR( df->form_list->next);
      assert( is_form( name_form, id_form));
      Symbol name = name_form->value;

      expanded_form_t expform;
	
      if(form_type == SYMBOL( function))
	{
	  generic_form_t lambda_form = CAR( df->form_list->next->next);

	  expform = expand_function_definition( name, lambda_form);
	}
      else
	{
	  assert( form_type == SYMBOL( global));
	  form_t type_form = CAR( df->form_list->next->next);
	  define_global( name, intern_type( type_form), NULL);
	  expform = create_expanded_form(define_form(SYMBOL(global),
						  name, type_form),
					 NULL);
	}
      *exp_form_list_ptr = CONS( expform, NULL);
      exp_form_list_ptr = &((*exp_form_list_ptr)->next);
    }

  *exp_form_list_ptr = NULL;
  }

  return exp_form_list;
}

/* Expanders.  */


/* Expand and dynamically compiles the expanders.  */

list_t
expand_all_expanders( list_t form_list)
{
  /* IL faut creer deux listes, avec le meme body: une liste
     d'expanders, et une liste de fonctions.  Les fonctions sont a
     compiler immediatement. Quoique en fait c'est la meme liste,
     l'une contenue dans l'autre. */

  
  list_t expander_list;
  {
    list_t *expander_list_ptr = &expander_list;
    
    FOREACH( element, form_list)
      {
	generic_form_t df = CAR( element);
	assert( is_form(  df, generic_form));
	assert( df->head == SYMBOL( define));
	
	id_form_t form_typef = CAR(df->form_list);
	assert( is_form( form_typef, id_form));
	Symbol form_type = form_typef->value;
	assert( form_type == SYMBOL( expander));
		
	id_form_t name_form = CAR( df->form_list->next);
	assert( is_form( name_form, id_form));
	Symbol name = name_form->value;

	generic_form_t tlabel_form = CAR( df->form_list->next->next);
	assert( is_form( tlabel_form, generic_form));
	assert( tlabel_form->head == SYMBOL( label));

	id_form_t parameter_namef = CAR( tlabel_form->form_list);
	assert( is_form( parameter_namef, id_form));
	form_t parameters = new_tuple_form( CONS( label_form_symbol( parameter_namef->value,
								     id_form( SYMBOL( Compound_Form))),
						  NULL));
	
	form_t body = CAR(tlabel_form->form_list->next);
	/* Create a function.  */
	
	form_t tlambda_form = lambda_form( base_type_form( SYMBOL( Form)),
					   parameters,
					   body);

	char *funname_ = malloc( strlen( name->name) + 20);
	strcpy( funname_, name->name);
	strcat( funname_, "##expander_function");
	Symbol funname = intern( funname_);
	free( funname_);

	expanded_form_t exp_function_form = expand_function_definition( funname,
									tlambda_form);
	generate( exp_function_form);
	define_expander( name, get_global_address( funname));
	
	*expander_list_ptr = CONS( define_form( SYMBOL( expander), name,
						exp_function_form),
				   NULL);
	expander_list_ptr = &((*expander_list_ptr)->next);

	/* Construct the expander form.  */
      }
    *expander_list_ptr = NULL;
  }

  return NULL;//expander_list;
}


/* Types.  */


#include <l/sys/type.h>
#include <l/access.h>
/* XXX: for recursive types: just use a lazy evaluation technique, we
   transform a type definition to a type only when the type is needed. */
void
define_type (symbol_t name, type_form_t type_form)
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
define_type_alias (symbol_t name,
		   type_form_t type_form)
{
  Type type = intern_type (type_form);
  associate_type_with_type_form( id_form( name), type);
}

list_t
expand_all_types( list_t form_list)
{
    
  list_t type_form_list;
  {
    list_t *type_form_list_ptr = &type_form_list;
    
    FOREACH( element, form_list)
      {
	generic_form_t df = CAR( element);
	assert( is_form(  df, generic_form));
	assert( df->head == SYMBOL( define));
	
	id_form_t form_typef = CAR(df->form_list);
	assert( is_form( form_typef, id_form));
	Symbol form_type = form_typef->value;
	assert( form_type == SYMBOL( type)
		|| form_type == SYMBOL( type_alias));
		
	id_form_t name_form = CAR( df->form_list->next);
	assert( is_form( name_form, id_form));
	Symbol name = name_form->value;

	generic_form_t type_form = CAR( df->form_list->next->next);
	
	form_t exp_type_form = define_form( SYMBOL( form_type),
					    name,
					    type_form);

	if(form_type == SYMBOL( type))
	  define_type( name, type_form);
	else
	  define_type_alias( name, type_form);
	  
	*type_form_list_ptr = CONS( exp_type_form, NULL);
	type_form_list_ptr = &((*type_form_list_ptr)->next);

	/* Construct the expander form.  */
      }
    *type_form_list_ptr = NULL;
  }

  return type_form_list;
}


/* Expand all.  */

/* This should split the list of expansions into list of one
   categories, then call the categories one after the other according
   to some precedence graph. For now, this precedence graph is
   static, but with user-defined definers this will change.  */

list_t
expand_all( list_t form_list)
{
  /* First, split into the different lists.  */
  hash_table_t ht = make_hash_table();

  FOREACH( element, form_list)
    {
      generic_form_t df = CAR( element);
      assert( is_form(  df, generic_form));
      assert( df->head == SYMBOL( define));
      
      id_form_t form_typef = CAR(df->form_list);
      assert( is_form( form_typef, id_form));
      Symbol form_type = form_typef->value;
      
      puthash( form_type, CONS( df, gethash( form_type, ht)), ht);
    }

  /* This should use a precedence graph between type forms.  */
  /* First the user definitions( that expand into other definitions)
     should be expanded, then the types, then the expanders, then the
     functions, then the globals.  */

  list_t type_list = gethash( SYMBOL( type), ht);
  list_t type_alias_list = gethash( SYMBOL( type_alias), ht);
  type_list = reverse( nconc( type_list, type_alias_list));

  list_t expanded_type_list;
  if(type_list)
    expanded_type_list = expand_all_types( type_list);
  
  
  list_t expander_list = reverse( gethash( SYMBOL( expander), ht));
  list_t expanded_expander_list = NULL;
  if( expander_list)
    expanded_expander_list = expand_all_expanders( expander_list);

  /* Reverse of the funlist is necessary because we cannot compile
     functions when they are not in order.  */
     
  list_t funlist = reverse( gethash( SYMBOL( function), ht));
  list_t globlist = gethash( SYMBOL( global), ht);
  globlist = nconc( globlist, funlist);

  list_t expanded_fun_list = NULL;
  if(globlist)
    expanded_fun_list =  expand_all_function_and_global(globlist);

  return nconc( expanded_fun_list, expanded_expander_list);
}



#if 0
/* A hash symbol->definer.  */
MAKE_STATIC_HASH_TABLE( real_definer_hash);

list_t
expand_define(generic_form_t form)
{
  symbol_form_t function = CAR(form->form_list);
  if(function->value == SYMBOL(function))
    {
      symbol_form_t name_form = CAR(form->form_list->next);
      symbol_t name = name_form->value;
      
      form_t lambda_form = CAR(form->form_list->next->next);
      
      
      return create_expanded_form(define_form(SYMBOL(function),
					      name, expand(lambda_form)),
				  NULL);
    }
    assert( function->value == SYMBOL( global));
    symbol_form_t name_form = CAR(form->form_list->next);
    symbol_t name = name_form->value;

    form_t type_form = CAR( form->form_list->next->next);
    return create_expanded_form(define_form(SYMBOL(global),
					    name, type_form),
				NULL);
    
      
  //  return create_expanded_form(form, NULL);
  /* XXX: replace the body form by the expanded body form.  *///NO!!
}
#endif
