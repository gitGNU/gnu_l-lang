/* parse.c - basic C-like parser.
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

/* XXX: en L la description de la grammaire se fera tres facilement:

  Il y aura la liste des operateurs infixes, avec leur niveau de
  priorite, et leur associativite,


  Grammaire de C: http://kbs.cs.tu-berlin.de/~jutta/c/ANSI-C-grammar-y.html
  
 */

//http://en.wikipedia.org/wiki/Parsing_expression_grammar

//product := product '*' product
//         | product '/' product
//         | product '%' product
//
//term    := product
//         | term '+' term
//         | term '-' term

#define _GNU_SOURCE 		/* For strndup */
#include <string.h>
#include <assert.h>

//#include "../symtab/symbols.h"
#include "form.h"
#include "../objects/symbol.h" 
#include <l/string.h>
#include "../objects/pair.h" 

/* For the final implementation :

   - We would just define the parser, the scanner could be deduced
     from the list of operators.  The reduced_token would be directly
     returned by the scanner; suffices to put a \\| between the
     different operators in a reduced_token class.

     (Except if some tokens are used with different purposes, such as
     unary * and unary -)

   - The fact that we have an expression and statement could be
     encoded directly in the form_t.  The last bit of a form_t is
     unused and could be for this purpose.

     That way, if_form, block_form... could be the one that returns
     statement or expressions, depending on the arguments.

   - In fact we would have:

   type Expression = Form : expression;
   type Statement = Form :  statement;

   expression and statement would be type attributes.

   - When detecting a parse error, the colon and line should be
     printed, along with what has been parsed, and why it is
     incorrect.

     Exemple: in 'a = if (toto) 3; else 4;'

     We should return an error message like this: 'Error: statement
     "if (toto) 3; else 4;" given, expression expected'

     This should help the user to find that a superfluous semicolon
     has been used. */


/* Functions to create forms. */


/* Tokens management.  */



/* XXX: Rename that read-object instead. */

/* XXX: should not be here. It should be the USER symbol table.  */
symbol_table_t symbol_table;

/* XXX: in the parser: separate just '=' from truc= like +=. */
/* Idea: we should allow things like remove_if= for destructive functions.  */


void
init_parser (void)
{
  /* XXX: should not be here */
  INIT_SYMBOL_TABLE (symbol_table);
}



#include <l/string.h>

/* Takes a string, parses it as a whole, and return the abstract
   syntax forest (list of forms).  */
list_t parse (String string)
{
  set_parser_support_to( string);
  list_t form_list = _l__parse__Top_Level__All();
  return form_list;
}


/* TODO: parse_with_parser, to parse a string with a different
parser.  */


/* The subgrammar for types.  We should also have our own lexer (for
   '<-', which is only in types) */



type_form_t
string_to_type_form (char *string)
{
  //  printf ("STRING TO TYPE FORM %s\n", string);
  set_parser_support_to( STRING( string));
  form_t form = _l__parse__Type__Type();
  return form;
}

