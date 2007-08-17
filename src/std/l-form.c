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

#if 0
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
#endif


/* Transforms "3 + i" into "generic_form( '+', CONS( int_form( 3),
   CONS( id_form( 'i'))))"

   IDs in id_list and forms beginning by $ or $@ are not expanded this
   way.  This is useful when defining macros.  */
   
   
generic_form_t
expand_form_rec (generic_form_t form, list_t id_list)
{
  if(is_form (form, atomic_form))
    {
      if(is_form (form, int_form))
	return generic_form_symbol (SYMBOL (Int_Form), CONS (form, NULL));

      if(is_form (form, id_form))
	{
	  Symbol id = (((id_form_t)form)->value);
	  FOREACH( element, id_list)
	    {
	      if(CAR( element) == id)
		return form;
	    }
	  return generic_form_symbol (SYMBOL (Id_Form), CONS (symbol_form( id), NULL));

	}

      if(is_form (form, quoted_symbol_form))
	return generic_form_symbol (SYMBOL (Symbol_Form), CONS (form, NULL));

      if(is_form (form, float_form))
	return generic_form_symbol (SYMBOL (Float_Form), CONS (form, NULL));

      if(is_form (form, string_form))
	return generic_form_symbol (SYMBOL (String_Form), CONS (form, NULL));
      if(is_form( form, expanded_form))
	return expand_form_rec( ((expanded_form_t)form)->return_form, NULL);
      
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
	
	form_t new_form = expand_form_rec(subform, id_list);

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

  return generic_form_symbol (SYMBOL (Compound_Form),
			      CONS (symbol_form (head),
				    CONS (new_form_list,
					  NULL)));
}

  
generic_form_t
expand_form (generic_form_t form)
{
  form_t the_form = CAR (form->form_list);

  form_t returned_form = expand_form_rec (the_form, NULL);

  assert (returned_form);

  //  lispify (returned_form);
  return returned_form;
}


/* These functions are only temporary, and we be replaced by proper
   pattern matching on types.  */
int
is_compound_form( form_t f)
{
  return is_form( f, compound_form);
}

int
is_id_form( form_t f)
{
  return is_form( f, id_form);
}

int
is_symbol_form( form_t f)
{
  return is_form( f, quoted_symbol_form);
}

int
is_int_form( form_t f)
{
  return is_form( f, int_form);
}


int
is_string_form( form_t f)
{
  return is_form( f, string_form);
}


void
init_l_form (void)
{
  #undef Form

  eval_cstring( "type Form = struct {"
		"form_type_: Int;} *;");

  eval_cstring( "type Id_Form = struct { form_type_: Int;"
		"value : Symbol;} *;");

  eval_cstring( "type Int_Form = struct { form_type_: Int;"
		"value : Int;} *;");

  eval_cstring( "type Symbol_Form = struct { form_type_: Int;"
		"value : Symbol;} *;");

  eval_cstring( "type String_Form = struct { form_type_: Int;"
		"value : String;} *;");
  
  eval_cstring( "type Compound_Form = struct {"
		"form_type_: Int;"
		"head: Symbol;"
		"garbage_:Int;"
                "form_list: List< Form>; } *;");

  eval_cstring( "type Expanded_Form = struct { form_type_: Int;"
		"original_form : Form;"
		"return_form: Form;"
		"type: Type ;} *;");

  
  //  define_parse (SYMBOL (Form), form_parse);
  define_expander (SYMBOL (Form), expand_form);
  
  DEFINE_C_FUNCTION (print_form, "Form -> Int");
  DEFINE_C_FUNCTION (Int_Form, "Int -> Form");
  DEFINE_C_FUNCTION (Symbol_Form, "Symbol -> Form");
  DEFINE_C_FUNCTION (Id_Form, "Symbol -> Form");
  DEFINE_C_FUNCTION (String_Form, "String -> Form");
  DEFINE_C_FUNCTION (Compound_Form,
		     "(Symbol, List< Form>) -> Form");

  DEFINE_C_FUNCTION( is_compound_form, "(Form) -> Bool");
  DEFINE_C_FUNCTION( is_id_form, "Form -> Bool");
  DEFINE_C_FUNCTION( is_symbol_form, "Form -> Bool");
  DEFINE_C_FUNCTION( is_string_form, "Form -> Bool");
  DEFINE_C_FUNCTION( is_int_form, "Form -> Bool");
  
  /* In fact, Expanded_Form<-Form.  */
  DEFINE_C_FUNCTION (expand, "Form -> Expanded_Form");
}
