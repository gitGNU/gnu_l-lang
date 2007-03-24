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
#include <assert.h>



/* Expand all.  */

/* This should split the list of expansions into list of one
   categories, then call the categories one after the other according
   to some precedence graph. For now, this precedence graph is
   static, but with user-defined definers this will change.  */

list_t
expand_all_function_and_global( list_t form_list)
{
  /* There should be two passes: one get the types of all the
     functions, and the other compiles them.

     Note: globals and functions should be analysed at the same time,
     they are interdependent.
     
     For now, the first pass is done by analysis.c.  */

  /* This is hacky : because of the generator we re-reverse the order of
     function creation.  */
  
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
	  form_t lambda_form = CAR( df->form_list->next->next);
	  
	  expform = create_expanded_form(define_form(SYMBOL(function),
						     name, expand(lambda_form)),
					 NULL);
	}
      else
	{
	  assert( form_type == SYMBOL( global));
	  form_t type_form = CAR( df->form_list->next->next);
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

      /* XXX: for now.  */
      if(form_type != SYMBOL( global)
	 && form_type != SYMBOL( function))
	continue;
      
      assert( form_type == SYMBOL( global)
	      || form_type == SYMBOL( function));
      
      puthash( form_type, CONS( df, gethash( form_type, ht)), ht);
    }

  /* This should use a precedence graph between type forms.  */
  list_t funlist = reverse( gethash( SYMBOL( function), ht));
  list_t globlist = gethash( SYMBOL( global), ht);
  globlist = nconc( globlist, funlist);
    
  if(globlist)
    return expand_all_function_and_global(globlist);
  else
    return NULL;
  
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
