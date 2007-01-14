/* form.c - Form creation, and a simple Lisp-like parser.
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

#include "form.h"

#include "../objects/pair.h"
#include "../objects/symbol.h"
#include "../objects/type.h"
#include "../objects/fixnum.h"
#include "../compiler/c-to-l.h"
#include <l/string.h>

#include <l/sys/panic.h>

/* XXX: should we initialize expression_type.  */
int_form_t
int_form (int value)
{
  int_form_t intform = new_form (int);
  intform->value = value;
  //  intform->expression_type = TYPE (int);
  return intform;
}

float_form_t
float_form (float value)
{
  float_form_t floatform = new_form (float);
  //  floatform->expression_type = TYPE (float);
  floatform->value = value;
  return floatform;
}

symbol_form_t
id_form (symbol_t value)
{
  symbol_form_t symform = new_form (id);
  symform->value = value;
  //  symform->expression_type = NULL;
  return symform;
}

quoted_symbol_form_t
symbol_form (symbol_t value)
{
  quoted_symbol_form_t qsymform = new_form (quoted_symbol);
  qsymform->value = value;
  return qsymform;
}

string_form_t
string_form (string_t value)
{
  string_form_t sform = new_form (string);
  sform->value = value;
  return sform;
}


#if 0
generic_form_t
generic_form_symbol_alist (symbol_t head, list_t form_alist)
{
  generic_form_t generic_form = new_form (generic);
  generic_form->form_alist = form_alist;
  generic_form->form_list_length = length (form_alist);
  generic_form->head = head;
  return generic_form;
}


generic_form_t
generic_form_alist (id_form_t head, list_t form_alist)
{
  assert (is_form (head, id_form));
  return generic_form_symbol_alist (head->value, form_alist);
//
//  generic_form_t generic_form = new_form (generic);
//  generic_form->form_alist = form_alist;
//  generic_form->form_list_length = length (form_alist);
//  generic_form->head = head->value;
//  return generic_form;
}


generic_form_t
generic_form_symbol (symbol_t head, list_t list)
{
  list_t alist = NULL;
  list_t *ptr = &alist;

  int i = 0;
  
  FOREACH (element, list)
    {
      *ptr = CONS (CONS (int_form (i++), CAR (element)),
		   NULL);
      ptr = &((*ptr)->next);
    }

  return generic_form_symbol_alist (head, alist);
}
#endif
generic_form_t
generic_form_symbol (symbol_t head, list_t list)
{
  generic_form_t gf = new_form (generic);
  gf->form_list = list;
  gf->form_list_length = length (list);
  gf->head = head;
  return gf;
}

generic_form_t
generic_form (id_form_t head, list_t list)
{
  assert (is_form (head, id_form));
  return generic_form_symbol (head->value, list);
}

generic_form_t
label_form (id_form_t label_, form_t form)
{
  //  assert(is_form(label_,symbol_form));
  return generic_form_symbol (SYMBOL (label), CONS (label_,
						    CONS (form, NULL)));
}

generic_form_t
label_form_symbol (symbol_t label, form_t form)
{
  label_form (id_form (label), form);
}


generic_form_t
access_form (form_t form, form_t param)
{
  list_t list = CONS (param, NULL);
  list = CONS (form, list);
  return generic_form_symbol (intern ("[]"), list);
}

/* Void is a tuple_form with zero value.  */
tuple_form_t
void_form ()
{
  tuple_form_t tuple_form = new_form (tuple);
  tuple_form->head = intern ("tuple");
  tuple_form->form_list = NULL;
  tuple_form->length = 0;
  return tuple_form;  
}

#if 0
tuple_form_t
tuple_form (list_t form_list)
{
  panic ("Here\n");
  tuple_form_t tuple_form = new_form (tuple);
  tuple_form->head = intern ("tuple");
  tuple_form->form_list = form_list;
  tuple_form->length = length (form_list);
  return tuple_form;  
}
#endif
generic_form_t
new_tuple_form (list_t form_list)
{
  return generic_form_symbol (SYMBOL (tuple), form_list);
}


generic_form_t
tuple_form (list_t form_list)
{
  panic ("Check caller\n");
  return generic_form_symbol (SYMBOL (tuple), form_list);
}


#if 0
tuple_form_t
tuple_form_alist (list_t form_alist)
{
  panic ("here\n");
  //  generic_form_symbol_alist (SYMBOL (tuple), form_alist);
}
#endif

#if 0
/* XXX: la fonction appellee n'est pas forcement un symbole
   constant.   */
/* XXX: in fact what we need here is overloading.  */
function_form_t
function_form_tuple (form_t head_form, form_t args)
{
  panic ("Here\n");
  assert (is_form (head_form, symbol_form));
  assert (is_form (args, tuple_form));
  function_form_t funform = new_form (function);
  //  funform->expression_type = NULL;
  funform->head = ((function_form_t) head_form)->head;
  funform->args = args;
  return funform;
}
#endif

#if 0
/* Function form with a simple list.  */
function_form_t
function_form (form_t head_form, list_t arg_list)
{
  panic ("Here\n");
  assert (is_form (head_form, symbol_form));
  tuple_form_t args = new_tuple_form (arg_list);
  return function_form_tuple (head_form, args);
}
#endif


/* Args is a tuple.  */
generic_form_t
function_form (form_t head_form, list_t args)
{
  generic_form (head_form, args);
}

/* Args is a tuple.  */
generic_form_t
function_form_tuple (form_t head_form, generic_form_t args)
{
  assert (args->head == SYMBOL (tuple));
  function_form (head_form, args->form_list);
}




#if 0
/* XXX: plutot @let? */
let_form_t
let_form (type_form_t type, symbol_t name/*, expression_form_t initial_value*/)
{
  let_form_t letform = new_form (let);
  letform->head = find_symbol ("let");
  letform->type = type;
  letform->name = name;
  //  letform->initial_value = initial_value;
  return letform;
}
#endif

generic_form_t
let_form (type_form_t type, symbol_t name/*, expression_form_t initial_value*/)
{
  list_t list = NULL;
  PUSH (id_form (name), list);
  PUSH (type, list);

  return generic_form_symbol (intern ("let"), list);
}


generic_form_t
define_form (symbol_t type, symbol_t name, /*expression_*/form_t initial_value)
{
  return generic_form_symbol (intern ("define"),
			      CONS (id_form (type),
				    CONS (id_form (name),
					  CONS (initial_value, NULL))));
  
//  define_form_t defineform = new_form (define);
//  defineform->head = find_symbol ("define");
//  defineform->type = type;
//  defineform->name = name;
//  defineform->initial_value = initial_value;
//  return defineform;
}


#if 0
/* XXX: il faut "applatir" les listes de seq_form dans seq_form, c'est
   un de ses roles.  Ca simplifie apres pour les blocks.  */
seq_form_t
seq_form (list_t form_list)
{
  seq_form_t seqform = new_form (seq);
  seqform->head = intern ("seq");
  seqform->form_list = form_list;
  return seqform;  
}
#endif

generic_form_t
seq_form (list_t form_list)
{
  return generic_form_symbol (intern ("seq"), form_list);
}
  

#if 0
block_form_t
block_form (list_t form_list)
{
  block_form_t blockform = new_form (block);
  blockform->head = intern ("block");
  blockform->forms = seq_form (form_list);
  return blockform;  
}
#endif

generic_form_t
block_form (list_t form_list)
{
  return generic_form_symbol (intern ("block"), form_list);
}



//lambda_form_t
//lambda_form (type_form_t type, list_t parameters,
//	     /*expression_*/form_t expression)
//{
//  lambda_form_t lambdaform = new_form (lambda);
//  lambdaform->head = intern ("lambda");
//  //  lambdaform->return_type = return_type;
//  lambdaform->type = type;
//  lambdaform->parameters = parameters;
//  lambdaform->parameters_number = length (parameters);
//  lambdaform->body = expression;
//  return lambdaform;  
//}

generic_form_t
lambda_form (type_form_t type, form_t parameters,
	     form_t expression)
{
  //(lambda return_type:int
  //        body:(block (+ 1 3))
  //        parameters: (tuple x:Int y:Int))
  list_t params = CONS (type,
			CONS (parameters,
			      CONS (expression, NULL)));
  
  return generic_form_symbol (SYMBOL (lambda), params);
}

generic_form_t
equal_form (form_t assignee, /*expression_*/form_t expression)
{
  list_t form_list = CONS (assignee, CONS (expression, NULL));
  return generic_form_symbol (intern ("="), form_list);
//  equal_form_t equalform = new_form (equal);
//  equalform->head = find_symbol ("=");
//  equalform->assignee = assignee;
//  equalform->expression = expression;
//  return equalform;
}

generic_form_t
if_form (expression_form_t condition, expression_form_t then_form,
	 expression_form_t else_form)
{
  list_t form_list;
  if(else_form)
    form_list = CONS(condition, CONS(then_form , CONS(else_form, NULL)));
  else
    form_list = CONS(condition, CONS(then_form , NULL));
    
  return generic_form_symbol(intern("if"), form_list);
}


generic_form_t
loop_form (form_t statement)
{
  return generic_form_symbol (intern ("loop"), CONS (statement, NULL));
//  loop_form_t loopform = new_form (loop);
//  loopform->head = intern ("loop");
//  loopform->repeated_form = statement;
//  return loopform;
}

generic_form_t
break_form ()
{
//  break_form_t breakform = new_form (break);
//  breakform->head = intern ("break");
//  return breakform;
  return generic_form_symbol (intern ("break"), NULL);
}

  
generic_form_t
continue_form ()
{
//  break_form_t breakform = new_form (break);
//  breakform->head = intern ("break");
//  return breakform;
  return generic_form_symbol (intern ("continue"), NULL);
}

  
#if 0
  
continue_form_t
continue_form ()
{
  continue_form_t continueform = new_form (continue);
  continueform->head = intern ("continue");
  return continueform;
}
#endif


#if 0
form_t
sexp_to_form (object_t obj);

static list_t
sexp_list_to_form_list (list_t sexp_list)
{
  //  write_object (sexp_list);
  list_t form_list = NULL;
  for (list_t *newlist = &form_list; sexp_list; sexp_list = sexp_list->next,
	 newlist = &(*newlist)->next)
    {
      *newlist = CONS (sexp_to_form (sexp_list->car), NULL);
    }
  return form_list;
}

/* XXX: on ne tiens pas compte de la macroexpansion ici.  */
form_t
sexp_to_form (object_t obj)
{
  type_t type = TYPE_OF (obj);

  if(type == TYPE (int_object))
    {
      int_object_t io = (int_object_t) obj;
      return (form_t) int_form (io->value);
    }
  
  if(type == TYPE (symbol))
    {
      symbol_t symbol = (symbol_t) obj;
      return (form_t) symbol_form (symbol);
    }

  if(type == TYPE (pair))
    {
      pair_t pair = (pair_t) obj;
      assert (TYPE_OF (pair->car) == TYPE (symbol));

      symbol_t head = pair->car;

      if(head == find_symbol ("let"))
	{
	  return (form_t) let_form (pair->next->car, pair->next->next->car);
				    // sexp_to_form (pair->next->next->next->car));
	}

      if(head == find_symbol ("define"))
	{
	  return (form_t) define_form (pair->next->car, pair->next->next->car,
				       sexp_to_form (pair->next->next->next->car));
	}

      if(head == find_symbol ("block"))
	{
	  return (form_t) block_form (sexp_list_to_form_list (pair->next));
	}

//      if(head == find_symbol ("lambda"))
//	{
//	  list_t parameter_list;
//	  list_t *pl_ptr = &parameter_list;
//
//	  FOREACH (element, (list_t) pair->next->next->car)
//	    {
//	      variable_declaration_t vd = MALLOC (variable_declaration);
//	      *pl_ptr = MALLOC (pair);
//	      (*pl_ptr)->car = vd;
//	      pl_ptr = &((*pl_ptr)->next);
//	      vd->type = /*symbol_value (*/ (symbol_t) ((pair_t) element->car)->car;
//	      vd->name = (symbol_t)  (((pair_t) element->car)->next->car);
//	    }
//
//	  *pl_ptr = NULL;
//	  return (form_t) lambda_form (pair->next->car, parameter_list,
//				       sexp_to_form (pair->next->next->next->car));
//				       //block_form (sexp_list_to_form_list (pair->next->next->next)));
//	}
      if(head == find_symbol ("="))
	{
	  return (form_t) equal_form (pair->next->car,
				      sexp_to_form (pair->next->next->car));
				       //block_form (sexp_list_to_form_list (pair->next->next->next)));
	}
      if(head == find_symbol ("if"))
	{
	  return (form_t) if_form (sexp_to_form (pair->next->car),
				   sexp_to_form (pair->next->next->car),
				   sexp_to_form (pair->next->next->next->car));
				       //block_form (sexp_list_to_form_list (pair->next->next->next)));
	}

      return (form_t) function_form_tuple (sexp_to_form ((symbol_t) pair->car),
					   tuple_form (sexp_list_to_form_list (pair->next)));
      //xfunction_form functionform = new_form (
					     //      unknown_compound_form_t ucf = new_form (unknown_compound);
      //xo      ucf->head = 
      
      
    }
      
  //write_object (obj);
  return NULL;
}
#endif

#if 0
void
write_type_form_to_xml (type_form_t typeform);

/* Write form so that it looks like C code.  */
void
write_form_to_xml (form_t form)
{
  //  printf ("Yeah write form to XML\n");

  //  printf ("form type: %x symbol: %x atomic %x atomic_mask: %x form &mask: %x\n", form->form_type.all, symbol_form_type, atomic_form_type, atomic_form_type_mask, form->form_type.all & atomic_form_type_mask);
  if(is_form (form, atomic_form))
    {
      printf ("<atom type=");

      if(is_form (form, int_form))
	{
	  printf ("\"int\" value=%d />\n", ((int_form_t) form)->value);
	}
      else if(is_form (form, symbol_form))
	{
	  symbol_t symbol = ((symbol_form_t) form)->value;
	  printf ("\"id\" value=\"0x%x\" name=\"%s\" />\n", symbol, symbol->name);
	}
      else if(is_form (form, quoted_symbol_form))
	{
	  symbol_t symbol = ((quoted_symbol_form_t) form)->value;
	  printf ("\"symbol\" value=\"0x%x\" name=\"%s\" />\n", symbol, symbol->name);
	}
      else if(is_form (form, type_form))
	{
	  printf ("\"type\" value=\n");
	  write_type_form_to_xml (form);
	  printf (" />\n");
	}
      else panic ("problem\n");
      
    }
  else
    {
      if(is_form (form, function_form))
	{
	  printf ("<function_call name=\"%s\">\n", ((function_form_t) form)->head->name);
	  write_form_to_xml (((function_form_t) form)->args);
	  printf ("</function_call>\n");
	}
      else if(is_form (form, tuple_form))
	{
	  printf ("<tuple length=\"%d\">\n", ((tuple_form_t) form)->length);
	  int i = 0;
	  FOREACH (element, ((tuple_form_t) form)->form_list)
	    {
	      printf ("<element number=\"%d\">",i);
	      write_form_to_xml (element->car);
	      printf ("</element>");
	      i++;
	    }
	  assert (i == ((tuple_form_t) form)->length);
	  printf ("</tuple>\n");
	}
      else if(is_form (form, equal_form))
	{
	  //	  assert (is_form (((equal_form_t) form)->assignee, symbol_form));
	  printf ("<assign>\n<assignee>");
	  write_form_to_xml (((equal_form_t) form)->assignee);
	  printf ("</assignee>\n<expression>");
	  write_form_to_xml (((equal_form_t) form)->expression);
	  printf ("</expression>\n</assign>\n");
	  //	  printf ("<assign id=\"%s\">\n", ((symbol_form_t) ((equal_form_t) form)->assignee)->value->name);
	  //	  write_form_to_xml (((equal_form_t) form)->expression);
	  //	  printf ("</assign>\n");
	}
      else if(is_form (form, seq_form))
	{
	  printf ("<seq>\n");
	  FOREACH (element, ((seq_form_t) form)->form_list)
	    {
	      write_form_to_xml (element->car);
	    }
	  printf ("</seq>\n");
	}
      else if(is_form (form, block_form))
	{
	  printf ("<block>\n");
	  write_form_to_xml (((block_form_t )form)->forms);
	  printf ("</block>\n");
	}
      else if(is_form (form, let_form))
	{
	  let_form_t letform = (let_form_t) form;
	  printf ("<let>");
	  write_type_form_to_xml (letform->type);
	  printf ("<name>%s</name>\n",letform->name->name);
	  //	  write_form_to_xml (letform->initial_value);
	  //	  printf ("</let>");
	}
//      else if (is_form (form, lambda_form))
//	{
//	  printf ("<lambda parameters_number=\"%d\">\n", ((lambda_form_t) form)->parameters_number);;
//	  FOREACH (element, ((lambda_form_t) form)->parameters)
//	    {
//	      variable_declaration_t vd = CAR (element);
//	      printf ("<parameter>\n");
//	      write_type_form_to_xml (vd->type);
//	      printf ("<name>%s</name>\n",vd->name->name);
//	    }
//	  
//	  write_form_to_xml (((lambda_form_t) form)->body);
//	  printf ("</lambda>\n");
//	}
      else if (is_form (form, if_form))
	{
	  printf ("<if>\n");
	  write_form_to_xml (((if_form_t) form)->condition);
	  write_form_to_xml (((if_form_t) form)->then_form);
	  if(((if_form_t) form)->else_form)
	    write_form_to_xml (((if_form_t) form)->else_form);
	  printf ("</if>\n");
	}
      else if (is_form (form, define_form))
	{
	  define_form_t defform = (define_form_t) form;
	  printf ("<define type=\"%s\" name=\"%s\">\n",
		  defform->type->name,
		  defform->name->name);
	  if(defform->type == SYMBOL (function))
	    write_form_to_xml (defform->initial_value);
	  printf ("</define>\n");
	}
      else if (is_form (form, loop_form))
	{
	  loop_form_t loopform = (loop_form_t) form;
	  printf ("<loop>\n");
	  write_form_to_xml (loopform->repeated_form);
	  printf ("</loop>");
	}
      else if (is_form (form, break_form))
	{
	  printf ("<break />\n");
	}
      else if (is_form (form, continue_form))
	{
	  printf ("<continue />\n");
	}
      else if (is_form (form, generic_form))
	{
	  generic_form_t gf = (generic_form_t) form;
	  printf ("<generic head=\"%s\" nb=\"%d\">\n", gf->head->name,
		  gf->form_list_length);
	  FOREACH (element, gf->form_alist)
	    {
	      printf ("<param id=\"");
	      write_form_to_xml (CAR ((pair_t) element->car));
	      printf ("\">");
	      write_form_to_xml (CDR ((pair_t) element->car));
	      printf ("</param>\n");
	    }
	  printf ("</generic>\n");
	}
      else panic ("problem 2");
    }
}
#endif

form_t
strip_expanded(expanded_form_t form)
{
  if(!is_form(form, expanded_form))
    return form;

  assert(is_form(form, expanded_form));

  form_t the_form = form->return_form;

  if(is_form(the_form, atomic_form))
    return the_form;

  generic_form_t gform = the_form;
  symbol_t head = gform->head;

  list_t form_list;
  list_t* form_list_ptr = &form_list;

  FOREACH(element, gform->form_list)
    {
      *form_list_ptr = MALLOC(pair);
      (*form_list_ptr)->car = strip_expanded(CAR(element));
       form_list_ptr = &((*form_list_ptr)->next);
    }

  *form_list_ptr = NULL;
  
  return generic_form_symbol(head, form_list);

}



void lispify_rec (form_t form, int indent, int cur_indent)
{
  for(int i = 0; i < cur_indent; i++)
    putchar (' ');

  if(is_form (form, atomic_form))
    {
      if(is_form (form, int_form))
	{
	  printf ("%d", ((int_form_t) form)->value);
	}
      else if(is_form (form, symbol_form))
	{
	  symbol_t symbol = ((symbol_form_t) form)->value;
	  printf ("%s", symbol->name);
	}
      else if(is_form (form, quoted_symbol_form))
	{
	  symbol_t symbol = ((quoted_symbol_form_t) form)->value;
	  printf ("'%s'", symbol->name);
	}
      else if(is_form (form, type_form))
	{
	  // write_type_form (form);
	  print_type (form);
	}
      else if(is_form (form, string_form))
	{
	  char *string = ((string_form_t) form)->value;
	  printf ("\"%s\"", string);
	}
      else if(is_form(form, expanded_form))
	{
	  lispify_rec(((expanded_form_t) form)->return_form, indent, cur_indent);
	}
      else panic ("problem\n");
    }
  else
    {
      if (is_form (form, generic_form))
	{
	  generic_form_t gf = (generic_form_t) form;

	  char *string;

	  int len = asprintf (&string, "(%s", gf->head->name);
	  printf ("%s", string);

	  free (string);

	  if(gf->form_list_length == 0)
	    {
	      putchar (')');
	      return;
	    }
	  else
	    {
	      assert (gf->form_list_length > 0);
	      //	      lispify_rec (CDR (CAR (gf->form_alist)), indent + len + 1, 1);
	      lispify_rec (CAR (gf->form_list), indent + len + 1, 1);

	      list_t element = gf->form_list;
	      
	      while(element->next)
		{
		  //  form_t subform = CDR (CAR (element));
		  form_t subform = CAR (element);
		  if(is_form(subform, expanded_form))
		    subform = ((expanded_form_t)subform)->return_form;
		  
		  if(is_form (subform, atomic_form))
		    {
		      cur_indent = 1;
		    }
		  else
		    {
		      assert (is_form (subform, generic_form)); 
		      putchar ('\n');
		      cur_indent = indent + len + 1;
		    }
		  element = element->next;
		  lispify_rec (CAR (element), indent + len + 1, cur_indent);
		}
	      putchar (')');
	      return;
	    }
	}
      else panic ("HERE\n");
//	{
//	  assert (is_form (form, lambda_form));
//	  {
//	    printf ("\n       (lambda (");
//	    FOREACH (element, ((lambda_form_t) form)->parameters)
//	      {
//		variable_declaration_t vd = CAR (element);
//		//		printf ("<parameter>\n");
//		lispify_rec (vd->type, 0, 0);
//		//		printf ("<name>%s</name>\n",vd->name->name);
//	      }
//
//	    printf (")\n");
//	    lispify_rec (((lambda_form_t) form)->body, 7, 7);
//	    //	    printf ("\n\n");
//	    //	    printf ("</lambda>\n");
//	  }
//	}
	
    }
}


void
lispify (form_t form)
{
  if(is_form(form, expanded_form))
    form = strip_expanded(form);
  lispify_rec (form, 0, 0);
  printf ("\n\n");
}

void
print_form (form_t form)
{
  lispify (form);
}

static struct type __type_Form_;

const Type __type_Form = &__type_Form_;

extern accesser_t without_accessor;


form_t
seq_form2 (form_t form, form_t form2)
{
  seq_form (CONS (form, CONS (form2, NULL)));
}

form_t
ith_form (generic_form_t form, int i)
{
  assert (is_form (form, generic_form));
  list_t l = form->form_list;
  
  for(int j = 0; j<i; j++)
    {
      if(l == NULL)
	panic ("In ith_form: asking for a form too far\n");

      l = l->next;
    }

  return CAR (l);
}


void
init_form (void)
{
  #undef Form
  DEFINE_TYPE ("Form", TYPE (Form), sizeof(form_t), __alignof__ (form_t));

  DEFINE_C_FUNCTION (print_form, "int<-Form");
  DEFINE_C_FUNCTION2 ("Int_Form", int_form, "Form<-int");
  DEFINE_C_FUNCTION2 ("Symbol_Form", symbol_form, "Form<-Symbol");

  DEFINE_C_FUNCTION2 ("loop_form", loop_form, "Form<-(Form)");
  DEFINE_C_FUNCTION2 ("if_form", if_form, "Form<-(Form,Form,Form)");
  DEFINE_C_FUNCTION2 ("break_form", break_form, "Form<-()");
  DEFINE_C_FUNCTION2 ("seq_form2", seq_form2, "Form<-(Form,Form)");

  
  DEFINE_C_FUNCTION2 ("ith_form", ith_form, "Form<-(Form,int)");
  DEFINE_C_FUNCTION2 ("print_form", print_form, "void<-(Form)");

  
  //DEFINE_C_FUNCTION2 ("seq_form", seq_form, "Form<-Form");
  //  DEFINE_C_FUNCTION2 ("if_form", seq_form, "Form<-Form");


  
  /* XXX: it would be cool to have something to transform a generic
     that takes a infinite number of arguments into a function that
     takes the list as its argument.  */

  
}
