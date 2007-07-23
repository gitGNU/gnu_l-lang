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


/* The print library is optimised for ease of use and fast printing.
   No temporary string manipulation should be necessary; all printing
   is done directly in the current output buffer; the buffer is then
   sent at once only when "flush" is encountered.

   Printing use the type of the argument to retrieve how it is
   printed.  For a type to be printable, a "printer" has to be
   recorded, which is a special kind of expander.

   Additionnally, arguments of prints may be accompagned by formatting
   instructions.

   For instance, print( "Hello|", 25,"|" 5:bin, "|",
                        list( 255, 31):format_list( hex, ", "))
    would print

    "Hello|25|101|ff, 1f

    because it is expanded into

    print_String( "Hello|");
    print_Int( 25);
    print_String( "|");
    print_Int_Bin( 5);
    print_String( "|");
    {
      let temp_list_ = list( 255, 31);
      print_Int_Hex( temp_list_.head);
      foreach( let temp_ in temp_list_.tail)
        {
          print_String( ", ");
          print_Int_Hex( temp_);
        }
    }
*/
  

#include <l/std/output.h> /* For print_string.  */
#include <l/expand.h> /* For print_string.  */
#include <l/sys/panic.h> /* For print_string.  */
#include <l/sys/hash.h>
#include <l/std/print.h>
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
define_printer (Type type, Printer printer)
{
  puthash (type, printer, printer_hash);
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
	expanded_form_t expform;
	form_t formatter;
	
	if(is_form( subform, generic_form)
	   && (((generic_form_t) subform)->head == intern( "@label")
	       || ((generic_form_t) subform)->head == intern( "label")))
	   
	  {
	    /* There is a formatter.  */
	    list_t form_list = ((generic_form_t) subform)->form_list;
	    expform = expand( CAR( form_list->next));
	    formatter = CAR( form_list);
	  }
	else
	  {
	    expform = expand (subform);
	    formatter = NULL;
	  }
	
	Type type = expform->type;
	Printer symb = gethash (type, printer_hash);
	
	if(!symb)
	  panic ("no printer found for %s\n", asprint_type (type));

	*mapped_form_list_ptr = CONS (symb( expform, formatter), NULL);
	
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

  return seq_form (mapped_form_list);
}

/* Some common printers.  */

form_t
String_printer(expanded_form_t exp, form_t formatter)
{
  if(formatter != NULL)
    panic( "No formatter exists for String\n");
  
  return generic_form_symbol( SYMBOL( print_String),
			      CONS( exp, NULL));
}

form_t
Int_printer( expanded_form_t exp, form_t formatter)
{
  Symbol symb;
  
  if(formatter == NULL)
    {
      symb = SYMBOL( print_Int_Dec);
      goto next;
    }
  else if(is_form( formatter, id_form))
    {
      Symbol format = ((id_form_t) formatter)->value;
      if(format == SYMBOL( dec))
	{
	  symb = SYMBOL( print_Int_Dec);
	  goto next;
	}
      else if(format == SYMBOL( hex))
	{
	  symb = SYMBOL( print_Int_Hex);
	  goto next;
	}
      else if(format == SYMBOL( bin))
	{
	  symb = SYMBOL( print_Int_Bin);
	  goto next;
	}
    }
  compile_error( "Unknown formatter\n");

 next:
  return generic_form_symbol( symb,
			      CONS( exp, NULL));
}

form_t
Symbol_printer( expanded_form_t exp, form_t formatter)
{
  if(formatter != NULL)
    panic( "No formatter exists for Symbol\n");
  
  return generic_form_symbol( SYMBOL( print_Symbol),
			      CONS( exp, NULL));
}

void
print_Int_Hex( unsigned int i)
{
  const char *nums = "0123456789abcdef";
  String string = alloca( sizeof(struct string) + 10);
  char *s = (char *) string  + sizeof(struct string);
  s[0] = '0';
  s[1] = 'x';
  memset( s+2, '0', 8);

  char *ps = s + 9;
  while(i)
    {
      int k = i & 0xf;
      *ps-- = nums[k];
      i >>= 4;
    }

  string->length = 10;
  string->content = s;
  print_String( string);
}

void
print_Int_Dec (int i)
{
#define BASE 10
#define MAX_NUM_LEN 11 /* log_{base}(2 ^ 32) + 1 (for the minus sign)*/
  String s = alloca (sizeof(struct string) + MAX_NUM_LEN);

  char *string_start = (char *) s  + sizeof(struct string);

  int j;
  
  if( i >= 0)
    {
      j = MAX_NUM_LEN - 1;
      do
	{
	  int k = i % 10;
	  string_start[j] = '0' + k; /* Does not work when base > 10.  */
	  j--;
	  i = i/BASE;
	} while(i);
    }
  else
    {
      /* We want to correctly print 0b100...00 */
      unsigned int new_i = - (i/10);
      j = MAX_NUM_LEN - 2;
      do
	{
	  int k = new_i % 10;
	  string_start[j] = '0' + k; /* Does not work when base > 10.  */
	  j--;
	  new_i = new_i/BASE;
	} while(new_i);
      string_start[MAX_NUM_LEN - 1] = '0' -(i%10);
      string_start[j--] = '-';
    }
    
  s->length = (MAX_NUM_LEN - 1) - j;
  s->content = string_start + j + 1;
  
  print_String (s);
  #undef BASE
  #undef MAX_NUM_LEN
}

/* print_Word: prints into hexadecimal.  */
void
print_Symbol( Symbol s)
{
  // print_string( STRING( "'"));
  print_String( STRING( s->name));
  //  print_string( STRING( "'"));
}



void
init_print (void)
{
  is_buffered = 0;
  define_expander(SYMBOL(print), expand_print);
  define_expander(SYMBOL(unbuffered), expand_unbuffered);
  define_expander(SYMBOL(buffered), expand_buffered);
  define_parse (SYMBOL (buffered), parse_buffered);
  define_parse (SYMBOL (unbuffered), parse_unbuffered);

  define_printer (TYPE ("String"), String_printer);
  define_printer (TYPE ("Int"), Int_printer);
  define_printer (TYPE ("Symbol"), Symbol_printer);
  DEFINE_C_FUNCTION (print_Int_Dec, "Void <- Int");
  DEFINE_C_FUNCTION (print_Int_Hex, "Void <- Int");
  
  //  define_printer (TYPE_ ("Int"), SYMBOL (print_Int));
  DEFINE_C_FUNCTION (print_Symbol, "Void <- Symbol");
  //  define_printer (TYPE_ ("Symbol"), SYMBOL (print_Symbol));
}
