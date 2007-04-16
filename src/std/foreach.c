/* iteration.c - Controls iteration.
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


/* Foreach expansion is quite simple: to each type, we just associate a
   macro that helps traversing the collection.  */

#include <l/expand.h>
#include <l/sys/panic.h>
#include <l/sys/type.h>

#include <assert.h>



typedef form_t (*Foreach_Expander) ( Symbol loop_name, form_t var_form,
				     expanded_form_t list_form, form_t body);


/* A hash type->iterator expander.  */						       
MAKE_STATIC_HASH_TABLE( iterator_expander_hash);

void
define_foreach_expander (Type type, Foreach_Expander ie)
{
  puthash (type, ie, iterator_expander_hash);
}

/*
  Note: foreach is "autoscoped", meaning that it creates
  an implicit scope around itself.

  This allows to use foreach( let a in li) { ... } with `a' being
  local to the foreach.
 */
form_t
expand_foreach( generic_form_t form)
{
  /* We expect 3 arguments; maybe 4 when we can name foreach
     loops.  */
  assert( form->form_list && form->form_list->next
	  && form->form_list->next->next
	  && !form->form_list->next->next->next);

  form_t element = CAR( form->form_list);
  form_t iteree = CAR( form->form_list->next);
  form_t body = CAR( form->form_list->next->next);

  Symbol loop_name;

  /* XXX: use the supplied loop name, if any.  */
  loop_name = gensym_c( "foreach");

  expanded_form_t exp_iteree = expand( iteree);

  Foreach_Expander ie = gethash( exp_iteree->type, iterator_expander_hash);
  if (ie == NULL)
    {
      panic( "Cannot iterate across type %s\n",
	     asprint_type( exp_iteree->type));
    }
  
  return ie( loop_name, element, exp_iteree, body);
}

  

/* Some iterator expanders.  */

/* We transform:
  (foreach (let a) li body)
into

{ let temp1:li.type = li
   loop {
      if( temp1 == 0)
        break;
       let a = temp1.car;
       body
	 continue: 
       temp1 = temp1->next;
  }
}

Foreach handles continue and break statements; in the future,
remove(), insert_after() and insert_before() statements will be added.
*/      
form_t
list_foreach_expander( Symbol loop_name, form_t var_form,
		       expanded_form_t list_form, form_t body)
{
  type_form_t list_type_form = list_form->type->type_form;
  type_form_t type_listed_form = CAR( ((generic_form_t) (list_type_form))->form_list);
  
  Symbol sym = gensym_c( "iterator");
  id_form_t id_sym = id_form( sym);
  
  form_t my_let_form = let_form( list_form->type->type_form, sym);
  form_t bind_iteration = generic_form_symbol( intern( "="),
					       CONS( my_let_form,
						     CONS( list_form,
							   NULL)));
  
  form_t if_form = generic_form_symbol( SYMBOL( if),
					CONS( generic_form_symbol( intern( "=="),
								   CONS( id_sym,
									 CONS( generic_form_symbol( SYMBOL( cast),
												    CONS( list_form->type->type_form,
													  CONS( int_form( 0),
														NULL))),
									       NULL))),
					      CONS( generic_form_symbol( SYMBOL( break),
									 NULL),
						    NULL)));

  type_form_t cons_type_form = generic_form_symbol( SYMBOL( pointer),
							CONS( generic_form_symbol( SYMBOL( struct),
										   CONS( label_form_symbol( SYMBOL( car),
													    type_listed_form),
											 CONS( label_form_symbol( SYMBOL( cdr),
														  list_type_form),
											       NULL))),
							      NULL));
						    
  form_t cast_cons_type_form = generic_form_symbol( SYMBOL( cast),
						    CONS( cons_type_form,
							  CONS( id_sym,
								NULL)));
							  
  form_t bind_iterator = generic_form_symbol( intern( "="),
					      CONS( var_form,
						    CONS( generic_form_symbol ( intern( "[]"),
										CONS( cast_cons_type_form,
										      CONS( symbol_form( SYMBOL( car)),
											    NULL))),
							  NULL)));
					      
  form_t do_step = generic_form_symbol( intern( "="),
					CONS( id_sym,
					      CONS( generic_form_symbol ( intern( "[]"),
									  CONS( cast_cons_type_form,
										CONS( symbol_form( SYMBOL( cdr)),
										      NULL))),
							  NULL)));
  

  form_t loop_form = generic_form_symbol( SYMBOL( loop),
					  CONS( generic_form_symbol( SYMBOL( block),
								     CONS( if_form,
									   CONS( bind_iterator,
										 CONS( body,
										       CONS( generic_form_symbol( intern( "@set_continue"), NULL),
											     CONS( do_step,
												   NULL)))))),
						NULL));
						      
  
  form_t final_form = generic_form_symbol( SYMBOL( block),
					   CONS( bind_iteration,
						 CONS( loop_form,
						       NULL)));
  
  //  lispify( final_form);
  return expand( final_form);
}

/* A special kind of foreach expanders is Generators:
   
   generator
   Int fibonnaci(u0, u1)
   {
     let (a, b) = (u0, u1);
     loop { yield a;
           (a, b) = (b, a+b);
          }
   }

   foreach( let( unminus1, un) = fibonnaci( 0, 1))
   {
     if( unminus1 >= 380)
      break;
   }

Generators functions return a Generator type; and the following
function will handle generators.*/
//form_t
//generator_iterator_expander()


void
init_foreach()
{
  define_expander( SYMBOL( foreach), expand_foreach);
}
