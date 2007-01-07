/* parse.h - parser declaration.
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

#ifndef _PARSE_H
#define _PARSE_H

#include "form.h"
#include "buffer.h"


/* Hooking into the parser.  */

typedef enum {STATEMENT = 0, EXPRESSION = 1} statement_or_expression_t;

typedef statement_or_expression_t (*parse_hook_function_t) (form_t *, Read_Buffer buf);

void
define_parse (symbol_t symbol, parse_hook_function_t function);


form_t
parse (char *string, unsigned int length);

list_t
parse_file (char *file_name);


/* Functions usable in parsing code.  */

#define parse_error_if_message(expr, message)	\
  do { if(expr) { printf ("ERROR: " #message "\n"); asm("int $3"); exit (3); }} while(0)

#define parse_error_if(expr)				\
  do {if(expr) { printf ("ERROR:" #expr); exit (3);}} while(0)

#define parse_error_if_not_statement(se, message)			\
  do { parse_error_if_message (se != STATEMENT, message); } while(0)

#define parse_error_if_not_expression(se, message)			\
  do { parse_error_if_message (se != EXPRESSION, message); } while(0)



static form_t parse_expression ();

static form_t parse_statement ();


/* Sometimes we may want either a statement or an expression, and do
   something depending on what we got.

   An exemple may be a when macro :

   macro (Expression|Statement)
   when '(' @(Expression condition) ')' @(Expression|Statement exp_or_stat)
   {
     if( typeof(exp_or_stat) == Expression)
       {
         return @if(condition, exp_or_stat, @symbol(null))
       }
     else
       {
         return @if(condition, exp_or_stat)
       }  
   }

   In expressions like a = when(toto) f(x); there are two possible parse trees:

   - Either as a = when(toto) {f(x);}, i.e. with f(x); as a statement,
     which is incorrect.

   - Either as a = { when(toto) f(x) }; i.e with f(x) as an expression.

   The second one is the correct one, because a wants a value from the
   when form.  */

/* Try to parse a statement; return an expression if it isn't.  */
static statement_or_expression_t parse_statement_or_expression (form_t *form);

/* Try to parse an expression; returns a statement if it isn't.  */
//static statement_or_expression_t parse_expression_or_statement (form_t *form);



/* Operator related definitions.  */
#define DECLARE_PARSE_OPERATOR_LEFT(rule_name, reduced_token, next_rule_name) \
  static statement_or_expression_t					\
  parse_##rule_name##_expression (form_t *form);


/* Define a left-associative operator.  */
#define DEFINE_PARSE_OPERATOR_LEFT(rule_name, reduced_token, next_rule_name) \
static statement_or_expression_t					\
parse_##rule_name##_expression (form_t *form)				\
{									\
  /* form_t curform = parse_term ();*/					\
  form_t curform;							\
  statement_or_expression_t se = parse_##next_rule_name##_expression (&curform); \
  if (se == STATEMENT)							\
    {									\
      *form = curform;							\
      return STATEMENT;							\
    }									\
									\
  while (accept (reduced_token##_RTK))					\
    {									\
      symbol_t operator = current_token.symbol;				\
      form_t operator_form = id_form (operator);			\
      form_t second_form;						\
      statement_or_expression_t se2;					\
      se2 = parse_##next_rule_name##_expression (&second_form);		\
      parse_error_if_not_expression (se2,				\
				     "Expression expected, statement given\n");	\
									\
      list_t form_list = CONS (curform, CONS (second_form, NULL));	\
      curform = function_form (operator_form, form_list);		\
    }									\
									\
  *form = curform;							\
  return EXPRESSION;							\
}


/* Define a right-associative operator.  */
#define DEFINE_PARSE_OPERATOR_RIGHT(rule_name, reduced_token, next_rule_name)


/* XXX: il faut aussi parser les '[', '(', '{' et les cas speciaux. */


#endif
