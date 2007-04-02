/* left-expand.c - Lvalue expander.
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

#include <assert.h>
#include <l/expand.h>
#include <l/sys/panic.h>

/* A hash Symbol->Left_Expander. */
MAKE_STATIC_HASH_TABLE (left_expander_hash);

void
define_left_expander(symbol_t symbol, left_expander_t expander)
{
  puthash(symbol, expander, left_expander_hash);
}

/* Left expander.

   The role of the left expander takes place when one want to expand
   an expression of the form (= (f a) (g b)).  While the second
   expression (g b) is expanded normally, transforming (g b) into (g'
   b'), with the left expander we can behave as the above for was (f a
   (g' b')); but instead of using the normal f expander, we use its
   left_expander.
*/
expanded_form_t
left_expand (form_t assignee, expanded_form_t expression)
{
   if(is_form (assignee, atomic_form))
    {
      expanded_form_t expanded_assignee = expand(assignee);
      
      /* XXX: Type checking should be performed here, with eventual
	 coersion, and subtyping verification.  */
      if(expression->type != expanded_assignee->type)
	panic("Type mismatch: %s and %s", asprint_type(expression->type),
	      asprint_type(expanded_assignee->type));

      return create_expanded_form(generic_form_symbol(intern("="),
						      CONS(expanded_assignee,
							   CONS(expression,
								NULL))),
				  expanded_assignee->type);
    }


   assert (is_form (assignee, generic_form));
  
  generic_form_t gform = (generic_form_t) assignee;

  symbol_t head = gform->head;
      
  left_expander_t lexpander = gethash (head, left_expander_hash);

  if(lexpander == NULL)
    panic("Error : no left expander defined for %s\n", head->name);

  gform = lexpander (gform, expression);

  return gform;
  
}

expanded_form_t
left_expand_deref (generic_form_t form, expanded_form_t expression)
{
  form_t refed = CAR(form->form_list);
  expanded_form_t exp_refed = expand(refed);
  
  Type type = exp_refed->type;
  Type pointed_type = get_pointed_type(type);
  
  expanded_form_t exp_deref = create_expanded_form(generic_form_symbol(SYMBOL(deref),
								       CONS(exp_refed, NULL)),
						   pointed_type);
  
  return create_expanded_form (generic_form_symbol (intern ("="),
						    CONS (exp_deref,
							  CONS (expression,
								NULL))));
}

expanded_form_t
left_expand_tuple (generic_form_t form, expanded_form_t expression)
{
  /* XXX: all tuples with '_' should not be in the resulting tuple.
     Same for "optional" arguments.  */


  /* XXX: also for things like (hash['i'], hash['j']) = ..., it should
     be expanded.  In these case, we are forced to use a temporary
     variable to hold the result, i.e:

     let temp = 3+4;
     ...
     puthash(i, tetmp);

     That's no big deal, it will be eliminated when we have ssa form.

     */

  /* To maintain the tuple semantics, we need to copy the expression.  */

  /* In fact, it is here that tuple affectation is sequentialized.  */
  
  list_t id_list;
  list_t assign_form_list;
  {
    list_t *id_list_ptr = &id_list;
    list_t *assign_form_list_ptr = &assign_form_list;

    generic_form_t gform = expression->return_form;
    assert( is_form( gform, generic_form));
    assert( gform->head == SYMBOL( tuple));

    FOREACH( element, gform->form_list)
      {
	expanded_form_t subexpr = CAR( element);
	
	Symbol tuple_copy = gensym( "tuple");
	*id_list_ptr = CONS( tuple_copy, NULL);
	id_list_ptr = &((*id_list_ptr)->next);
	
	form_t copy_form = generic_form_symbol( intern( "="),
						CONS( generic_form_symbol( SYMBOL( let),
									   CONS( id_form( tuple_copy),
										 NULL)),
						      CONS( subexpr,
							    NULL)));
	*assign_form_list_ptr = CONS( expand( copy_form), NULL);
	assign_form_list_ptr = &((*assign_form_list_ptr)->next);
      }
    *assign_form_list_ptr = NULL;
    *id_list_ptr = NULL;
  }
    
  /* Now, left-expand the left forms normally.  */

  list_t cur_id = id_list;
  list_t second_assign_list;
  {
    list_t *second_assign_list_ptr = &second_assign_list;
    
    FOREACH( element, form->form_list)
      {
	assert( cur_id); /* XXX: for now. */
	Symbol id = CAR( cur_id);
	*second_assign_list_ptr = CONS( left_expand( CAR( element), expand( id_form( id))),
					NULL);
	second_assign_list_ptr = &((*second_assign_list_ptr)->next);
	cur_id = cur_id->next;
      }
    *second_assign_list_ptr = NULL;
  }

  assert( cur_id == NULL);

  form_t return_form = seq_form( CONS( seq_form( assign_form_list),
				       CONS( seq_form( second_assign_list),
					     NULL)));
  return expand( return_form);
}

#include <l/sys/type.h>
expanded_form_t
left_expand_let( generic_form_t form, expanded_form_t expression)
{
  id_form_t id_form = CAR( form->form_list);
  assert( is_form( id_form, id_form));

  form_t type_form;

  Type id_type;
  
  if( form->form_list->next)
    {
      type_form = CAR( form->form_list->next);
      id_type = intern_type( type_form);
      type_check( id_type, expression->type);
    }
  else
    {
      type_form = expression->type->type_form;
      id_type = expression->type;
    }
  
  expanded_form_t exp_let = create_expanded_form(generic_form_symbol(SYMBOL(let),
								     CONS(id_form,
									  CONS( type_form,
										NULL))),
						 id_type);

  /* We could also transform the form into
     (seq (let type id) (= type expression)) */ 
  insert_id(id_form->value, 0, SPECIES_VARIABLE, id_type);
  
  return create_expanded_form (generic_form_symbol (intern ("="),
						    CONS (exp_let,
							  CONS (expression,
								NULL))),
			       id_type);
}

void
init_left_expand (void)
{
  define_left_expander (SYMBOL (deref), left_expand_deref);
  define_left_expander (SYMBOL (let), left_expand_let);
  define_left_expander (SYMBOL (tuple), left_expand_tuple);
}
