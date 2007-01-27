/* print.c - Printer definition and base printing functions.
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

#include <l/std/output.h> /* For print_string.  */
#include <l/expand.h> /* For print_string.  */
#include <l/sys/panic.h> /* For print_string.  */
#include <l/sys/hash.h>
#include "../compiler/c-to-l.h"
#include "../parser/parse.h"

/* __thread */ static int is_buffered = 0;


/* FORM is of the form (buffered BODY).  Just set non_interactive to
   1, so that print_macro does not call maybe_flush().  */
expanded_form_t
expand_buffered(generic_form_t form)
{
  is_buffered++;

  form_t body = CAR (form->form_list);
  
  expanded_form_t expbody = expand (body);

  is_buffered--;
  
  return expbody;
}

/* Buffered is followed by a statement;  so it can be called like this:

   buffered {
     print(...);
     print(...);
   }

   or like this: buffered print(...);
   or like this: buffered (print(...)); 
*/
statement_or_expression_t
parse_buffered (form_t *form, Read_Buffer buf)
{
  form_t body = l_parse_statement (buf);
  *form = generic_form_symbol (SYMBOL (buffered), CONS (body, NULL));
  return STATEMENT;
}

/* FORM is of the form (with_non_interactive_output_macro BODY).  Just
   set non_interactive to 1, so that print_macro does not call
   maybe_flush().  */
expanded_form_t
expand_unbuffered(generic_form_t form)
{
  is_buffered--;

  form_t body = CAR (form->form_list);
  
  expanded_form_t expbody = expand (body);

  is_buffered++;
  
  return expbody;
}

/* Unbuffered is parsed exactly like buffered.  */
statement_or_expression_t
parse_unbuffered (form_t *form, Read_Buffer buf)
{
  form_t body = l_parse_statement (buf);
  *form = generic_form_symbol (SYMBOL (unbuffered), CONS (body, NULL));
  return STATEMENT;
}


/* A hash Type->symbol.  Symbol may name a function, a macro
   ... anything expandable.  */
MAKE_STATIC_HASH_TABLE (printer_hash);

/* Defines printing for type TYPE to be done by calling expander named
   by SYMBOL.   */
void
define_printer (Type type, symbol_t symbol)
{
  puthash (type, symbol, printer_hash);
}


/* Printing is done under the form (print arg1 arg2 arg3 ... argn).
   Prints each args in turn, using the type-dependant printer for
   ARG.
   
   If we are in an unbuffered context, also calls maybe_flush() at the end
   of the print_sequence.  */
form_t expand_print (generic_form_t form) {
  list_t form_list = form->form_list;

  list_t mapped_form_list;

  /* TODO: if the list contains only one string element, and we are in
     an unbuffered context, copy can be done directly.  */
  
  { list_t *mapped_form_list_ptr = &mapped_form_list;
    
    FOREACH (element, form_list)
      {
	
	form_t subform = CAR (element);
	expanded_form_t expform = expand (subform);
	Type type = expform->type;
	Symbol symb = gethash (type, printer_hash);
	
	if(!symb)
	  panic ("no printer found for %s\n", asprint_type (type));

	*mapped_form_list_ptr = CONS (generic_form_symbol (symb,
							   CONS (expform, NULL)),
				      NULL);
	mapped_form_list_ptr = &((*mapped_form_list_ptr)->next);
      }

    if(!is_buffered)
      {
	*mapped_form_list_ptr = CONS (generic_form_symbol (SYMBOL (maybe_flush), NULL),
				      NULL);
	mapped_form_list_ptr = &((*mapped_form_list_ptr)->next);
      }
    *mapped_form_list_ptr = NULL;
  }

  return block_form (mapped_form_list);
}

/* Some common printers.  */

void
print_Int (int i)
{
#define BASE 10
#define MAX_NUM_LEN 10 /* log_base(2 ^ 32) */
  String s = alloca (sizeof(struct string) + MAX_NUM_LEN);

  char *string_start = (char *) s  + sizeof(struct string);
  
  int j = MAX_NUM_LEN - 1;
  do
    {
      int k = i % 10;
      string_start[j] = '0' + k; /* Does not work when base > 10.  */
      j--;
      i = i/BASE;
    } while(i);

  s->length = (MAX_NUM_LEN - 1) -j;
  s->content = string_start + j + 1;

  print_string (s);
  #undef BASE
  #undef MAX_NUM_LEN
}

/* print_Word: prints into hexadecimal.  */

void
init_print (void)
{
  is_buffered = 0;
  define_expander(SYMBOL(print), expand_print);
  define_expander(SYMBOL(unbuffered), expand_unbuffered);
  define_expander(SYMBOL(buffered), expand_buffered);
  define_parse (SYMBOL (buffered), parse_buffered);
  define_parse (SYMBOL (unbuffered), parse_unbuffered);

  
  define_printer (TYPE_ ("String"), SYMBOL (print_String));

  DEFINE_C_FUNCTION (print_Int, "Void <- Int");
  define_printer (TYPE_ ("Int"), SYMBOL (print_Int));
}
