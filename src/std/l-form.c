/* l-form.c - Form handling from L.
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
#include <l/form.h>
#include "../compiler/c-to-l.h"

void
print_form (form_t form);

#include "../parser/form.h"
#include "../parser/buffer.h"
#include "../parser/parse.h"

/* Form parser.

   For now, we parse only expressions and statement.  Later, we could
   parle any predefined rule in the same way: we could use
   let Form f = Form(rule:definer, function f = $a);

   Maybe the Form parser should be used differently: we could have
   let f = Expression(...)
   let f = Statement(...)
   let f = Definition(...)

   This is yet unclear.  
 */
statement_or_expression_t
form_parse (form_t *form, Read_Buffer buf)
{
  char c;
  do {
    c = buffer_getchar (buf);
  } while(c == ' ');

  assert (c == '(');

  l_parse_statement_or_expression (form, buf);

  *form = generic_form_symbol (SYMBOL (Form), CONS (*form, NULL));
  
  /* It is a hack, but the close paren token has just been eaten by
     the parser.  */
  return ~(EXPRESSION);
}

generic_form_t
expand_form_rec (generic_form_t form)
{
  if(is_form (form, atomic_form))
    {
      if(is_form (form, int_form))
	return generic_form_symbol (SYMBOL (Int_Form), CONS (form, NULL));

      if(is_form (form, id_form))
	return generic_form_symbol (SYMBOL (Id_Form), CONS (symbol_form (((id_form_t)form)->value), NULL));

      if(is_form (form, quoted_symbol_form))
	return generic_form_symbol (SYMBOL (Symbol_Form), CONS (form, NULL));

      if(is_form (form, float_form))
	return generic_form_symbol (SYMBOL (Float_Form), CONS (form, NULL));

      if(is_form (form, string_form))
	return generic_form_symbol (SYMBOL (String_Form), CONS (form, NULL));

      panic ("Here\n");
    }

  assert (is_form (form, generic_form));

  Symbol head = ((generic_form_t) form)->head;
  list_t form_list = ((generic_form_t) form)->form_list;

  if(form->head == intern ("$"))
    {
      /* There must be only one argument.  */
      assert (form_list && form_list->next == NULL);

      expanded_form_t exp_form = expand (CAR (form_list));

      if(exp_form->type != TYPE ("Form"))
	panic ("Error: $can replace only forms.  \n");

      return exp_form;
    }
  
  if(form->head == intern ("$@"))
    {
      panic ("Should not be reached\n");
      /* To handle $@, we return NULL here; then we detect this fact,
	 and handle it in the caller.  */
      return NULL;
    }

  /* We transform the form_list a,b,c into
     cons(a, cons(b, cons(c, cast(List(Form), NULL)))),
     like as when we expand list(a,b,c).  */
  
  generic_form_t new_form_list;
  {
    generic_form_t *new_form_list_ptr = &new_form_list;
    
    FOREACH(element, form_list)
      {
	form_t subform = CAR (element);

	if(is_form (subform, generic_form))
	  {
	    generic_form_t gsubform = (generic_form_t) subform;
	    
	    if(gsubform->head == intern ("$@"))
	      {
		assert (gsubform->form_list && gsubform->form_list->next == NULL);
		expanded_form_t new_subform = expand(CAR (gsubform->form_list));

		if(element->next)
		  panic ("Not yet handled, must use append\n");

		*new_form_list_ptr = new_subform;
		goto end;
		
	      }
	  }
	
	form_t new_form = expand_form_rec(subform);

	*new_form_list_ptr = generic_form_symbol(SYMBOL(cons),
						 CONS(new_form,
						      CONS(NULL,
							   NULL)));
	new_form_list_ptr = &((*new_form_list_ptr)->form_list->next->car);
      }

    *new_form_list_ptr = generic_form_symbol(SYMBOL(cast),
					     CONS(generic_form_symbol(SYMBOL(List),
								      CONS(id_form (SYMBOL (Form)),
									   NULL)),
						  CONS(int_form(0),
						       NULL)));
  }

 end:

  return generic_form_symbol (SYMBOL (Generic_Form_Function),
			      CONS (symbol_form (head),
				    CONS (new_form_list,
					  NULL)));
}

  
generic_form_t
expand_form (generic_form_t form)
{
  form_t the_form = CAR (form->form_list);

  form_t returned_form = expand_form_rec (the_form);

  assert (returned_form);

  //  lispify (returned_form);
  return returned_form;
}

void
init_l_form (void)
{
  #undef Form

  eval_cstring( "type Form = struct {"
		"form_type_: Int;} *;");

  eval_cstring( "type Compound_Form = struct {"
		"form_type_: Int;"
		"head: Symbol;"
		"garbage_:Int;"
                "form_list: List( Form); } *;");

  define_parse (SYMBOL (Form), form_parse);
  define_expander (SYMBOL (Form), expand_form);
  
  DEFINE_C_FUNCTION (print_form, "Int<-Form");
  DEFINE_C_FUNCTION2 ("Int_Form", int_form, "Form<-Int");
  DEFINE_C_FUNCTION2 ("Symbol_Form", symbol_form, "Form<-Symbol");
  DEFINE_C_FUNCTION2 ("Id_Form", id_form, "Form<-Symbol");
  DEFINE_C_FUNCTION2 ("String_Form", string_form, "Form<-String");
  DEFINE_C_FUNCTION2 ("Generic_Form_Function",
		      generic_form_symbol,
		      "Form<-(Symbol, List(Form))");

}
