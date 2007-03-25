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
	  assert( is_form( lambda_form, generic_form));
	  assert( lambda_form->head == SYMBOL( lambda));

	  form_t return_type = CAR (lambda_form->form_list);
	  generic_form_t parameters = CAR (lambda_form->form_list->next);
	  form_t function_type = intern_type( function_type_form (return_type,
								  parameters));

	  define_global(  name, function_type, NULL);
	  define_expander(name, expand_function);

	  /* XXX Why do we expand this.  */
	  expform = create_expanded_form(define_form(SYMBOL(function),
						     name, expand(lambda_form)),
					 NULL);
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

  
  list_t fun_form_list;
  {
    list_t *fun_form_list_ptr = &fun_form_list;
    
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
								     id_form( SYMBOL( Form))),
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
	
	form_t function_form = define_form( SYMBOL( function),
					    funname,
					    tlambda_form);
	*fun_form_list_ptr = CONS( function_form, NULL);
	fun_form_list_ptr = &((*fun_form_list_ptr)->next);

	/* Construct the expander form.  */
      }
    *fun_form_list_ptr = NULL;
  }

  /* Compiles all the functions.  */
  list_t expanded_funs = expand_all_function_and_global( fun_form_list);
  generate_list( expanded_funs);

  list_t expander_list;
  {
    list_t *expander_list_ptr = &expander_list;
    list_t fun_element;
    list_t exp_element;
    
    for(exp_element = form_list, fun_element = expanded_funs;
	exp_element;
	exp_element = exp_element->next, fun_element = fun_element->next)
      {
	assert( fun_element);

	generic_form_t df = CAR( exp_element);
	id_form_t name_form = CAR( df->form_list->next);
	Symbol name = name_form->value;

	expanded_form_t exp_df2 = CAR( fun_element);
	assert( is_form( exp_df2, expanded_form));
	generic_form_t df2 = exp_df2->return_form;
	assert( is_form(  df2, generic_form));
	assert( df2->head == SYMBOL( define));

	id_form_t fun_name_form = CAR( df2->form_list->next);
	assert( is_form( fun_name_form, id_form));

	/* Finally defines the expander.  */
	define_expander( name, get_global_address( fun_name_form->value));

	/* We return an expanded expander for use in backends (for
	   instance, the C backend).  */
	*expander_list_ptr = define_form( SYMBOL( expander), name, df2);
	expander_list_ptr = &((*expander_list_ptr)->next);
      }
    assert( fun_element == NULL);
    *expander_list_ptr = NULL;
  }

  return NULL;//expander_list;
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

  
  list_t expander_list = gethash( SYMBOL( expander), ht);
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
