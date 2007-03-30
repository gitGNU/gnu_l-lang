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

#include "parse.h"
//#include "../symtab/symbols.h"
#include "form.h"
#include "buffer.h"
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

form_t
int_form (int value);


form_t
float_form (float value);


form_t
id_form (symbol_t value);

form_t
symbol_form (symbol_t value);

form_t
access_form (form_t form, form_t param);

form_t 
tuple_form (list_t form_list);

generic_form_t
generic_form (id_form_t head, list_t form_list);

//#define function_form generic_form

#if 0
form_t
function_form (symbol_t head, list_t form_list);

form_t
function_form_tuple (symbol_t head, form_t form);
#endif


/* XXX: plutot @let? */
form_t
let_form (symbol_t type, symbol_t name);



form_t
define_form (symbol_t type, symbol_t name, form_t initial_value);


form_t
block_form (list_t form_list);


form_t
lambda_form (type_form_t type, list_t parameters,
	     form_t expression);

form_t
equal_form (symbol_t symbol, form_t expression);


form_t
if_form (form_t condition, form_t then_form,
	 form_t else_form);

form_t
loop_form (form_t statement);

form_t
break_form ();

form_t
continue_form ();

form_t
seq_form (list_t form_list);

/* Tokens management.  */



/* XXX: Rename that read-object instead. */

/* XXX: should not be here. It should be the USER symbol table.  */
symbol_table_t symbol_table;

/* We could (or not) put the keywords in it. */
typedef enum token_type
  { CHARACTER_TK = 1,
    STRING_TK,
    SYMBOL_TK,
    ID_TK ,
    BLANK_TK, 
    DECIMAL_TK,
    OPEN_PAREN_TK,
    CLOSE_PAREN_TK,
    PLUS_TK,
    MINUS_TK,
    STAR_TK,
    SLASH_TK,
    EQUAL_TK,
    EQUAL_EQUAL_TK,
    GREATER_EQUAL_TK,
    GREATER_THAN_TK,
    LESSER_THAN_TK,
    LESSER_EQUAL_TK,
    DIFFERENT_TK,
    AND_TK,
    OR_TK,
    NOT_TK,
    COMMA_TK,
    SEMICOLON_TK,
    COLON_TK,
    DOT_TK,
    AMPERSAND_TK,
    OPEN_BRACE_TK,
    CLOSE_BRACE_TK,
    OPEN_SQUARE_BRACKET_TK,
    CLOSE_SQUARE_BRACKET_TK,
    DOLLAR_TK,
    DOLLAR_SPLICE_TK,
    FUNCTION_TYPE_TK,
    COMMENT_TK,
    ALL_TK = COMMENT_TK} token_type_t;

#include "../lexer/lexer.h"

typedef int (*Pchar_ui_to_Pvoid_t)(void **, char *, size_t);

#define parse_error(string, args...)					\
  do {printf ("Parse error in %s" string, scanner_pointer, ## args);	\
      asm("int $3"); exit (1);} while(0)


static char *scanner_pointer; 
static void_to_ui_t generated_scanner;

/* A simplified type in order to test less symbols.  There should be a
   table TOKEN->REDUCED_TOKEN */
typedef enum reduced_token_type
  {
    ERROR_RTK = 0,
    NO_RTK = 0,
    DECIMAL_RTK,
    SYMBOL_RTK,
    STRING_RTK,
    ID_RTK,
    ADDITIVE_RTK,
    MULTIPLICATIVE_RTK,
    UNARY_RTK,
    RELATIONAL_RTK,
    EQUALITY_RTK,
    ASSIGNMENT_RTK,
    OPEN_PAREN_RTK,
    CLOSE_PAREN_RTK,
    COMMA_RTK,
    SEMICOLON_RTK,
    COLON_RTK,
    DOT_RTK,
    EQUAL_RTK,
    OPEN_BRACE_RTK,
    CLOSE_BRACE_RTK,
    OPEN_SQUARE_BRACKET_RTK,
    CLOSE_SQUARE_BRACKET_RTK,
    DOLLAR_RTK,
    FUNCTION_TYPE_RTK,
    
  } reduced_token_type_t;

struct token
{
  reduced_token_type_t type;
  union  {
    float floating_point;
    int integer;
    symbol_t symbol;
    symbol_t id;
    string_t string;
  };
};


/* The token counter shows the start of the circular buffer of k+1 tokens.  */
int token_counter = 0;

struct token tokens[2];  	/* k L+ 1 for a LL(k) grammar.  */

#define current_token (tokens[token_counter])
#define next_token (tokens[((token_counter + 1) & 1)])

/* Renvoie true si le parsing c'est fini, sinon update le token.  */
static void
get_next_token (void)
{
  char *start = scanner_pointer;

  int result_scanning;

  //  printf ("current: %s\n", scanner_pointer);

  do
    {
      start = scanner_pointer;

      if (*start == 0)
	{
	  current_token.type = NO_RTK;
	  token_counter++;
	  token_counter &= 1;
	  return;
	}

      result_scanning = generated_scanner ();
    }   while(result_scanning == BLANK_TK || result_scanning == COMMENT_TK);


  //  printf ("SCANNER CALLED: %s (%d)\n", strndup (start, scanner_pointer - start), result_scanning);


  /* XXX: construire une table pour prendre les decisions sur ca.  On
     pourrait faire une table avec l'adresse des labels, et on
     sauterait dans ca.

     La table serait TK => label ou sauter.
     */
  if(result_scanning == DECIMAL_TK)
    {
      /* Atoi has some troubles with 0x80000000.  */
      current_token.integer = (unsigned int) atoll (start);
      current_token.type = DECIMAL_RTK;
    }
  else if(result_scanning == ID_TK)
    {
      char *name = strndup (start, scanner_pointer - start);
      current_token.id = intern (name);
      current_token.type = ID_RTK;
      free (name);
    }
  else if(result_scanning == SYMBOL_TK)
    {
      char *name = strndup (start + 1, scanner_pointer - start - 2);
      /* XXX: why - 2? why -1 does not work.  */
      current_token.symbol = intern (name);
      current_token.type = SYMBOL_RTK;
      free (name);
    }
  else if(result_scanning == PLUS_TK || result_scanning == MINUS_TK)
    {
      char *name = strndup (start, scanner_pointer - start);
      current_token.symbol = intern (name);
      current_token.type = ADDITIVE_RTK;
      free (name);
    }
  else if(result_scanning == STAR_TK || result_scanning == SLASH_TK)
    {
      char *name = strndup (start, scanner_pointer - start);
      current_token.symbol = intern (name);
      current_token.type = MULTIPLICATIVE_RTK;
      free (name);
    }
  else if(result_scanning == OPEN_PAREN_TK)
    {
      current_token.type = OPEN_PAREN_RTK;
    }
  else if(result_scanning == CLOSE_PAREN_TK)
    {
      current_token.type = CLOSE_PAREN_RTK;
    }
  else if(result_scanning == COMMA_TK)
    {
      current_token.type = COMMA_RTK;
    }
  else if(result_scanning == SEMICOLON_TK)
    {
      current_token.type = SEMICOLON_RTK;
    }
  else if(result_scanning == COLON_TK)
    {
      current_token.type = COLON_RTK;
    }
  else if(result_scanning == DOT_TK)
    {
      current_token.type = DOT_RTK;
    }
  else if(result_scanning == OPEN_BRACE_TK)
    {
      current_token.type = OPEN_BRACE_RTK;
    }
  else if(result_scanning == CLOSE_BRACE_TK)
    {
      current_token.type = CLOSE_BRACE_RTK;
    }
  else if(result_scanning == OPEN_SQUARE_BRACKET_TK)
    {
      current_token.type = OPEN_SQUARE_BRACKET_RTK;
    }
  else if(result_scanning == CLOSE_SQUARE_BRACKET_TK)
    {
      current_token.type = CLOSE_SQUARE_BRACKET_RTK;
    }
  else if(result_scanning == DOLLAR_TK || result_scanning == DOLLAR_SPLICE_TK)
    {
      char *name = strndup (start, scanner_pointer - start);
      current_token.id = intern (name);
      current_token.type = DOLLAR_RTK;
      free (name);
    }
  else if(result_scanning == FUNCTION_TYPE_TK)
    {
      current_token.type = FUNCTION_TYPE_RTK;
    }
  else if(result_scanning == EQUAL_TK) /* =, /=, +=, -= ... */
    {
      /* We can do the transformation directly here, if it is a += or
	 something.  */
      char *name = strndup (start, scanner_pointer - start);
      current_token.symbol = intern (name);
      current_token.type = ASSIGNMENT_RTK;
      free (name);
    }
  else if(result_scanning == EQUAL_EQUAL_TK || result_scanning == DIFFERENT_TK)
    {
      char *name = strndup (start, scanner_pointer - start);
      current_token.symbol = intern (name);
      current_token.type = EQUALITY_RTK;
      free (name);
    }
  else if(result_scanning == GREATER_EQUAL_TK || result_scanning == GREATER_THAN_TK
	  || result_scanning == LESSER_EQUAL_TK || result_scanning == LESSER_THAN_TK)
    {
      char *name = strndup (start, scanner_pointer - start);
      current_token.symbol = intern (name);
      current_token.type = RELATIONAL_RTK;
      free (name);
    }
  else if(result_scanning == NOT_TK 
	  || result_scanning == AMPERSAND_TK
	  || result_scanning == STAR_TK
	  || result_scanning == AND_TK)
    {
      /* We parsed &&.  */
      switch(result_scanning)
	{
	case AND_TK:
	  current_token.id = intern( "@get_label");
	  break;
	  
	case STAR_TK:
	  current_token.id = intern( "deref");
	  break;

	case AMPERSAND_TK:
	  current_token.id = intern( "ref");
	  break;

	default:
	  {
	    char *name = strndup (start, scanner_pointer - start);
	    current_token.id = intern (name);
	    free (name);
	  }
	}
      current_token.type = UNARY_RTK;
    }
  else if(result_scanning == STRING_TK)
    {
      /* Transforms the \n into real line return.  */
      char *newstring = malloc( scanner_pointer - start - 2);
      char *savnewstring = newstring;
      for( char *str = start + 1; str < scanner_pointer -1;)
	{
	  if(*str == '\\')
	    {
	      switch(*(str+1))
		{
		case 'n':
		  *newstring++ = '\n';
		  break;
		  
		case 't':
		  *newstring++ = '\t';
		  break;

		case '\\':
		  *newstring++ = '\\';
		  break;
		  
		case '\'':
		  *newstring++ = '\'';
		  break;

		case '\"':
		  *newstring++ = '\"';
		  break;
		}		  
	      str += 2;
	      continue;
	    }

	  *newstring++ = *str++;
	}

      current_token.string = maken_heap_string (savnewstring,
						newstring - savnewstring);
      current_token.type = STRING_RTK;
    }
  
  else parse_error ("Unrecognized token\n");
  
  token_counter++;
  token_counter &= 1;
  
  //  return token.type;
}

/* Accept a token and advance to the next.  */
static bool
accept (reduced_token_type_t rtk)
{
  if (rtk == next_token.type)
    {
      get_next_token ();
      return 1;
    }
  return 0;
}

/* XXX: For improved error codes, expect should take a string as an
   argument, for telling in what we where when we expected the
   token.  */
static void
expect (reduced_token_type_t rtk)
{
  if (rtk == next_token.type)
    {
      get_next_token ();
      return;
    }

  fprintf (stderr, "In %s\n", scanner_pointer);
  parse_error ("Unexpected token type: %d\n", next_token.type);
}

/* XXX: in the parser: separate just '=' from truc= like +=. */
/* Idea: we should allow things like remove_if= for destructive functions.  */


static statement_or_expression_t parse_block (form_t *form);

static statement_or_expression_t parse_if (form_t *form);

static statement_or_expression_t parse_let (form_t *form);

static statement_or_expression_t parse_loop (form_t *form);

static statement_or_expression_t parse_break (form_t *form);

static statement_or_expression_t parse_continue (form_t *form);

static statement_or_expression_t parse_while (form_t *form);

static statement_or_expression_t parse_cast (form_t *form);

static statement_or_expression_t parse_foreach( form_t *form);

static statement_or_expression_t parse_type_declaration (form_t *form);

type_form_t parse_type_form (void);

/* This hash table associate the keyword starting a parse hook (for
   instance for macros) to the associated parsing function.  */
MAKE_STATIC_HASH_TABLE (parse_hook_hash_table);
//hash_table parse_hook_hash_table_ = NULL;
//hash_table_t parse_hook_hash_table = & parse_hook_hash_table_;

void
define_parse (symbol_t symbol, parse_hook_function_t function)
{
  puthash (symbol, function, parse_hook_hash_table);
}

static parse_hook_function_t
get_parse (symbol_t symbol)
{
  (void *) gethash (symbol, parse_hook_hash_table);
}

void
init_parser (void)
{
  /* XXX: should not be here */
  INIT_SYMBOL_TABLE (symbol_table);

  generated_scanner = make_string_scanner (&scanner_pointer,
					   false, ALL_TK,
					   "'.'",
					   /*"\"(\\.|[^\\\"])*\"",*/ /* C'est celle la la norme, et ca marche pas.  */
					   //					   "\"([^\"\\]|\\[\"\\])*\"", /* XXX: pourquoi celle la ne marche pas? */
					   //					   "\"([^\"\\]|\\[\\])*\"", /* XXX: pourquoi celle la ne marche pas? */
					   /* Celle d'emacs: 		    "\"\[^\\\"]|\\\\.)*\"\\|'([^\\']|\\\\.)*'" */
					   "\"[^\"]*\"", //* Une simple qui marche.  */
					   "'[^']*'",
					   //"\"([^\"\\]|\\.)*\"",
					   "[a-zA-Z_][a-zA-Z0-9_]*",
					   "[ \t\n]+",
					   "[0-9][0-9]*", /* 					   "[1-9][0-9]*"  Because octals begin by 0. */
					   "\\(",
					   "\\)",
					   "\\+",
					   "-",
					   "\\*",
					   "/",
					   "=",
					   "==",
					   ">=",
					   ">",
					   "<",
					   "<=",
					   "!=",
					   "&&",
					   "\\|\\|",
					   "!",
					   ",",
					   ";",
					   ":",
					   "\\.",
					   "&",
					   "{",
					   "}",
					   "\\[",
					   "\\]",
					   "$",
					   "$@",
					   "<-",
					   "//.*\n"
					   );


  define_parse (SYMBOL (if), parse_if);
  define_parse (SYMBOL (let), parse_let);
  define_parse (SYMBOL (loop), parse_loop);
  define_parse (SYMBOL (break), parse_break);
  define_parse (SYMBOL (continue), parse_continue);


  /* A macro, could be added later.  */
  define_parse (SYMBOL (while), parse_while);
  define_parse (SYMBOL (foreach), parse_foreach);
  define_parse (SYMBOL (cast), parse_cast);

}


/* XXX: Je suis pas sur pour le truc "expression ou statement".

   L'idee c'est de differencier if(3) function(x) else function(y)
   de if(3) function(x); else function(y);

   Ca permet de rendre un cote un peu plus fonctionnel.  Mais si c'est
   des emmerdements, on laissera tomber.

   Ca permet de detecter si une fonction retourne void, c'est en fait
   le seul vrai interet.
   */

/* En fait on n'a pas de statemements, on a que des expressions
   ou des "statement_or_expressions". */

/* Ca vient du fait que dans un bloc, on sait pas si on va parser un
   statement ou une expression a chaque fois. Suivant ce qu'on a, ca
   doit etre la fin du bloc ou non.

   Il y a des fois ou on sait qu'on recherce une expression et pas un
   statement, comme apres un = par exemple.

   Enfin, le if par exemple peut etre soit une expression soit un
   statement, avec une syntaxe differente pour les deux.

   le let n'est permissible que dans un expression_or_statement par
   exemple, idem pour loop

   (on va considerer le let comme un statement pur, tout comme le
   loop).
   
   */

typedef enum {NOT_A_MACRO = 2} macro_type_t; /* rend aussi STATEMENT ou EXPRESSION, i.e a statement_or_macro_t*/


/* Cleaned up grammar.  */



/* The formal L grammar is the following one : */






/* In practice, L is not parsed like this, because of all the back ups
   we would have to do when we try to parse a block expression when it
   is a block statement, for instance.

   Thus, each rule returns something telling whether it parsed an
   expression or a statement.  */

//DECLARE_PARSE_OPERATOR_RIGHT (sequential, SEQUENTIAL, assignment)
//DECLARE_PARSE_OPERATOR_RIGHT (assignment, ASSIGNMENT, logical)
DECLARE_PARSE_OPERATOR_LEFT (logical, LOGICAL, bit)
DECLARE_PARSE_OPERATOR_LEFT (bit, BIT, equality)
DECLARE_PARSE_OPERATOR_LEFT (equality, EQUALITY, relational)
DECLARE_PARSE_OPERATOR_LEFT (relational, RELATIONAL, shift)
DECLARE_PARSE_OPERATOR_LEFT (shift, SHIFT, additive)
DECLARE_PARSE_OPERATOR_LEFT (additive, ADDITIVE, multiplicative)
DECLARE_PARSE_OPERATOR_LEFT (multiplicative, MULTIPLICATIVE, primary)





/* Exemple de derecursivisation a gauche.  */
static statement_or_expression_t
parse_postfix_expression (form_t *form);

static statement_or_expression_t 
parse_tuple (form_t *form);

static form_t parse_all ();

static form_t parse_term ();

static form_t parse_factor ();

static statement_or_expression_t
parse_unary_expression (form_t *form);

static statement_or_expression_t
parse_postfix_expression (form_t *form);

static statement_or_expression_t
parse_primary_expression (form_t *form);

static form_t parse_expression_not_macro ();

static form_t
parse_def (void);

static statement_or_expression_t
parse_atomic (form_t *form);

/* temp name. */
static statement_or_expression_t
parse_assignment_expression (form_t *form);

static statement_or_expression_t
parse_label_expression (form_t *form);


static form_t
parse_function_definition ();

static form_t
parse_variable_declaration ();

static void
parse_initialize (void)
{
  /* We start with the next token ready.  Current_token should not be
     used.  */
  token_counter = 1;
  get_next_token ();
  token_counter = 0;
}

static form_t
parse_all ()
{
  form_t form;

  if(next_token.type == ID_RTK)
    {
      if(next_token.id == SYMBOL (type))
	{
	  parse_type_declaration (&form);
	  return form;
	}
      else if(next_token.id == SYMBOL(global))
	{
	  expect( ID_RTK);

	  expect( ID_RTK);
	  symbol_t symbol = current_token.id;
	  expect( COLON_RTK);
	  type_form_t type_form = parse_type_form();

	  form = define_form( SYMBOL( global),
				      symbol,
				      type_form);
	  expect( SEMICOLON_RTK);
	  return form;
	}
      else if(next_token.id == SYMBOL( expander))
	{
	  expect( ID_RTK);
	  expect( ID_RTK);
	  symbol_t name = current_token.id;
	  expect( OPEN_PAREN_RTK);
	  expect( ID_RTK);
	  symbol_t param = current_token.id;
	  expect( CLOSE_PAREN_RTK);
	  form_t body;
	  statement_or_expression_t se = parse_statement_or_expression( &body);
	  form = define_form( SYMBOL( expander), name,
			      label_form_symbol( param, body));
	  return form;
	}
      else if(next_token.id == SYMBOL (type_alias))
	{
	  parse_type_declaration (&form);
	  return form;
	}
      else if(next_token.id == SYMBOL( macro))
	{
	  expect( ID_RTK);
	  expect( ID_RTK);
	  symbol_t name = current_token.id;
	  expect( OPEN_PAREN_RTK);
	  list_t parameters;
	  if(accept( CLOSE_PAREN_RTK))
	    parameters = NULL;
	  else
	    {
	      list_t *parameters_ptr = &parameters;
	      while(1)
		{
		  expect( ID_RTK);
		  symbol_t param_name = current_token.id;
		  form_t param_form = id_form( param_name);
		  if(accept( COLON_RTK))
		    {
		      type_form_t type_form = parse_type_form();
		      param_form = label_form( param_form, type_form);
		    }

		  *parameters_ptr = CONS( param_form, NULL);
		  parameters_ptr = &((*parameters_ptr)->next);
		  
		  if(accept( CLOSE_PAREN_RTK))
		    {
		      *parameters_ptr = NULL;
		      break;
		    }

		  expect( COMMA_RTK);
		}
	    }

	  form_t tuple_form = new_tuple_form( parameters);
	  expect( ASSIGNMENT_RTK);
	  //	  form_t expression = parse_expression();
	  //	  expect( SEMICOLON_RTK);
	  form_t expression = parse_statement();

	  form = generic_form_symbol (SYMBOL( define),
				      CONS( id_form( SYMBOL( macro)),
					    CONS( id_form( name),
						  CONS( tuple_form,
							CONS( expression,
							      NULL)))));
	  return form;
	}
      else if(next_token.id == SYMBOL (def))
	{
	  form = parse_def ();
	  return form;
	}
    }
  
  form = parse_function_definition ();

  return form;
  /* Expect end */
}

#if 0


static form_t
parse_type ()
{
  /* Les types sont des symboles dont la premiere lettre est une
     majuscule, ou let, int, float, double ...

     Et pour les type qualifiers on fait comment?

     let i : static, int valeur : private;

     Le probleme c'est que le parsing est ambigu : on sait pas
     differencier int * a de b * a sans utiliser une table des
     symboles et connaitre les types avant de parser.

     tant qu'on a pas de pointeur ca va.

     Ou alors il suffira d'utiliser ^ ou autre pour les pointeurs, au lieu de *.

     Non on va dire que toutes les declarations d'objets commencent
     par let, et apres c'est la grammaire de let.
     
     */
  if (next_token.type == ID_RTK)
    {
      if(next_token.symbol == SYMBOL (int));
      accept (ID_RTK);
    }
}
#endif

/* In L, there isn't any stament, but an expression followed by a ;
   means an expression which returns void (i.e. expression, ()).
   */
/* In this function, we try to return a statement, and we return an
   expression if we really cannot.  */
static statement_or_expression_t
parse_statement_or_expression (form_t *form)
{
  /* XXX: parser le NULL statement.  */
  statement_or_expression_t se = parse_label_expression (form);
  if(se == STATEMENT)
    return STATEMENT;
  else if (accept (SEMICOLON_RTK))
    return STATEMENT;
  return EXPRESSION;
  
  /* XXX : append void to the expression. */
}

static form_t
parse_statement ()
{
  form_t retform;
  statement_or_expression_t se = parse_statement_or_expression (&retform);
  parse_error_if (se == EXPRESSION);
  return retform;
}

#if 0
/* XXX: we don't have a real type grammar for now. */
static symbol_t
parse_type ()
{
  expect (ID_RTK);

  return current_token.id;
  
}
#endif

static form_t
parse_variable_declaration ()
{
  expect( ID_RTK);
  symbol_t id = current_token.id;

  expect( COLON_RTK); 
  //  variable_declaration_t vd = MALLOC (variable_declaration);
  form_t type = parse_type_form ();

  return label_form_symbol (id, type);
}


static form_t
parse_function_parameter_list (void)
{
  expect (OPEN_PAREN_RTK);

  list_t parameter_list;
  list_t *parameter_list_ptr = &parameter_list;
  
  if(accept (CLOSE_PAREN_RTK))
    return new_tuple_form (NULL);
  
  while (1)
    {
//      
//      variable_declaration_t vd = MALLOC (variable_declaration);
//      vd->type = parse_type_form ();
//
//      expect (ID_RTK);
//      vd->name = current_token.id;
      form_t vd = parse_variable_declaration ();

      *parameter_list_ptr = MALLOC (pair);
      CAR (*parameter_list_ptr) = vd;
      parameter_list_ptr = &CDR (*parameter_list_ptr);

      if(accept (COMMA_RTK))
	continue;
      else
	{
	  expect (CLOSE_PAREN_RTK);
	  break;
	}
    }
  *parameter_list_ptr = NULL;
  return new_tuple_form (parameter_list);
}

static form_t
parse_def (void)
{
  expect (ID_RTK);

  assert (current_token.symbol == SYMBOL (def));

  expect (ID_RTK);

  assert (current_token.symbol == SYMBOL (generic));

  expect (ID_RTK);

  symbol_t name = current_token.id;

  list_t parameter_list = parse_function_parameter_list ();

  form_t body;
  statement_or_expression_t se = parse_block (&body);

  //  define_form (intern ("generic"), name, lambda_form
  
  
  //TODO: remove lambda_form
  return define_form (intern ("generic"),
		      name,
		      lambda_form (base_type_form (SYMBOL (Form)),
				   parameter_list,
				   body));
  
}



static form_t
parse_function_definition ()
{
  type_form_t return_type = parse_type_form ();
  expect (ID_RTK);
  symbol_t name = current_token.id;

  form_t parameters = parse_function_parameter_list ();

  //  list_t type_forms_list = NULL;


  //type_forms_list = map car parameter_list;
//  {
//    list_t *ptr = &type_forms_list;
//
//    for(list_t element = parameter_list; element; element = element->next)
//      {
//	pair_t vd = CAR (element);
//	*ptr = CONS (CDR (vd), NULL);
//	ptr = &(CDR (*ptr));
//      }
//  }
  
  type_form_t type = //function_type_form (return_type,
    //			 tuple_type_form (type_forms_list));
     return_type;
  
  form_t block;

  statement_or_expression_t se = parse_block (&block);
  // assert (se == EXPRESSION);

  return define_form (intern ("function"),
		      name,
		      lambda_form (type, parameters, block));
}

#if 0
/*  */
static form_t
parse_expression_or_object_declaration ()
{
  if (next_token.type == ID_RTK && next_token.id == SYMBOL (let))
    return parse_object_declaration ();
  else
    return parse_expression ();
}
#endif

/* XXX: separate expressions-only, and statements-anly, and put
   statement or expression in all?  */

/* Ou alors on tente de parser, et on dit ce qu'on a reussit a
   parser. (un statement ou une expression).  En fonction du contexte,
   ca sera bon ou pas. */

/* Le boolean dit si on a parse un statement ou une expression.  */

static macro_type_t
parse_macro (form_t *form)
{
  /* XXX: it is annoying that we test twice the first symbol in
     parse_block, parse_if... */
     
  if(next_token.type == OPEN_BRACE_RTK)
    {
      return parse_block (form);
    }
  if(next_token.type == DOLLAR_RTK)
    {
      symbol_t symbol = next_token.id;
      expect (DOLLAR_RTK);
      form_t exp_form = parse_expression ();
      expect( DOLLAR_RTK);
      *form = generic_form_symbol (symbol, CONS (exp_form, NULL));
      return EXPRESSION;
    }
  else if (next_token.type == ID_RTK)
    {
      parse_hook_function_t phf = get_parse (next_token.id);
      if(phf)
	{
	  Read_Buffer buf = MALLOC (read_buffer);
	  buf->current = scanner_pointer;
	  
	  /* The other fields are not important.  */
	  char *save_scanner_pointer = scanner_pointer;
	  
	  int mt = phf (form, buf);

	  /* Hack.  */
	  if(mt < 0)
	    {
	      mt = ~mt;
	      /* The custom parser used a different scanner.  */
		 
	      scanner_pointer = buf->current;

	      /* Reinitialize the flux of tokens.  */
	      parse_initialize ();
	    }
	  return mt;
	}
    }
  
  return NOT_A_MACRO;
  //return NULL;
}



/* block_statement := '{' statement* '}' */
/* block_expression := '{' statement* expression '}' */

/* Pour pouvoir parser un block_expression, on passe donc par
   parse_statement_or_expression, qui tente de parser un statement, et
   si il peut pas rend une expression (L'idee c'est de bouffer le
   ';').

   Par statement on entend "general statement", on accepte donc les
   let par exemple.
   */
static statement_or_expression_t
parse_block (form_t *form)
{
  /* We need at least something in the brace.  */

  list_t form_list;
  list_t *form_list_ptr = &form_list;

  expect (OPEN_BRACE_RTK);
  while (1)
    {
      *form_list_ptr = MALLOC (pair);
      //      (*form_list_ptr)->car = parse_expression_or_object_declaration ();
      statement_or_expression_t se;
      se = parse_statement_or_expression (&((*form_list_ptr)->car));

      form_list_ptr = &((*form_list_ptr)->next);

      if (se == STATEMENT)
	{
	  if (accept (CLOSE_BRACE_RTK))
	    {
	      *form_list_ptr = NULL;
	      *form = block_form (form_list);
	      return STATEMENT;
	    }
	  else continue;
	  
	}
      else
	{
	  expect (CLOSE_BRACE_RTK);
	  *form_list_ptr = NULL;
	  *form = block_form (form_list); 
	  return EXPRESSION;
	}
    }
}

/* if_expression := 'if' '(' expression ')' expression 'else' expression */
/* if_statement  := 'if' '(' expression ')' statement ['else' statement] */
/* => if_statement_or_expression := 'if' statement_or_expression ['else' statement_or_expression]*/

/* Les parentheses sont pour differencier deux expressions a la
   suite : on peut pas mettre deux expressions a la suite, c'est
   ambigu. */
static statement_or_expression_t
parse_if (form_t *form)
{
  expect (ID_RTK);
  assert (current_token.id == intern ("if"));
 
  expect (OPEN_PAREN_RTK);
  form_t boolean_form;
  boolean_form = parse_expression ();
  expect (CLOSE_PAREN_RTK);

  statement_or_expression_t soe;
  form_t then_form;

  soe = parse_statement_or_expression (&then_form);

  if (soe == EXPRESSION)
    {
      /* After an expression, we absolutely need a else. */
      expect (ID_RTK);
      parse_error_if_message (current_token.id != intern ("else"),
			  "An if expression needs a else branch");
      form_t else_form = parse_expression ();
      
      *form = if_form (boolean_form, then_form, else_form);
      
      return EXPRESSION;
    }
  else
    {
      if (next_token.type == ID_RTK && next_token.id == intern ("else"))
	{
	  expect (ID_RTK);
	  form_t else_form = parse_statement ();
	  *form = if_form (boolean_form, then_form, else_form);
	  return STATEMENT;
	}
      else
	{
	  *form = if_form (boolean_form, then_form, NULL);
	  return STATEMENT;
	}
    }
}

/* A declaration of an object begins by a let (so an object
   declaration is also called let form.)

   object_declaration := 'let' type? id { '=' expression }? {',' id { '=' expression }? } *

   pour l'instant type n'est qu'un simple identifiant.

   Plus tard, pour qu'on aie pas d'ambiguite, on demandera des
   parentheses autour de type si c'est qqch de different.

   Mais en general, on pourra utiliser juste let; le type specifier
   permet de rendre le code plus lisible et de faire des verifications
   en plus, c'est tout.

   object_declaration := 'let' id {':' type? {':' kind_list}? }?  
   kind_list = kind | kind ',' kind_list;
   
   */
static statement_or_expression_t
parse_let (form_t *form)
{
  expect (ID_RTK);

  assert (current_token.id == SYMBOL (let));

  expect (ID_RTK);

  symbol_t name = current_token.id;

  if( accept( COLON_RTK))
    {
      type_form_t type = parse_type_form ();
      if( accept( COLON_RTK))
	{
	  panic( "Kinds are not supported for now\n");
	}

      *form = generic_form_symbol( SYMBOL( let),
				   CONS( id_form( name),
					 CONS( type,
					       NULL)));
      return EXPRESSION;

    }

  *form = generic_form_symbol( SYMBOL( let),
			       CONS( id_form( name),
				     NULL));
  return EXPRESSION;
  //  symbol_t type = parse_type ();


#if 0  
  if(accept (ASSIGNMENT_RTK))
    {
      form_t exp = parse_expression ();
      form_t assign_form = equal_form (id_form (name), exp);
      list_t form_list = CONS (letform, CONS (assign_form, NULL));
      letform = seq_form (form_list);
    }

  /* COMA */
  expect (SEMICOLON_RTK);
  
  *form = letform;
  return EXPRESSION;//STATEMENT;
#endif

  panic( "Here\n");
  //  return let_form (NULL
  //  printf ("YEAH LET\n");
  
}

/* loop_statement := 'loop' statement  */
/* On peut donner un nom a un loop statement comme en Perl:
   loop_name : loop_statemement */
static statement_or_expression_t
parse_loop (form_t *form)
{
  expect (ID_RTK);
  assert (current_token.id == intern ("loop"));

  form_t repeat_form = parse_statement ();
  *form = loop_form (repeat_form);
  return STATEMENT;
}

/* XXX: break and continue should be only keywords in the "loop"
   sublanguage, and should be translated to gotos.  */

/* break_statement := 'break' ';' */
/* Plus tard, on pourra recevoir le nom de la boucle d'où on veut
   sortir, et peut être une valeur si on veut faire des
   loop_expressions. */
static statement_or_expression_t
parse_break (form_t *form)
{
  expect (ID_RTK);
  assert (current_token.id == intern ("break"));
  expect (SEMICOLON_RTK);
  *form = break_form ();
  return STATEMENT;
}

/* continue_statement := 'continue' ';' */
/* Plus tard on pourra aussi recevoir le nom d'une boucle.  */
static statement_or_expression_t
parse_continue (form_t *form)
{
  expect (ID_RTK);
  assert (current_token.id == intern ("continue"));
  if(next_token.type == COLON_RTK)
    {
      expect( COLON_RTK);
      /* if we are used as a label, then return the @set_continue
	 special form. */
      *form = generic_form_symbol( intern( "@set_continue"),
				   NULL);

      form_t newform;
      statement_or_expression_t se = parse_statement_or_expression( &newform);
      *form = seq_form (CONS( *form, CONS( newform, NULL)));
      return se;
    }
  //
  //  }
  //  expect (SEMICOLON_RTK);
  *form = continue_form ();
  //  return STATEMENT;
  return EXPRESSION;
}

/* XXX: un 'skip' statement pour ne pas re-evaluer la condition dans
   la boucle while, comme en Perl? ou alors non, ca sera implemente
   par des macros?  */

#if 0
/* XXX un parse statement_or_expression? */

static statement_or_expression_t
parse_statement_or_expression (form_t *form)
{
  macro_type_t mt = parse_macro (form);

  switch (mt)
    {
    case NOT_A_MACRO: break;
    default:
      printf ("MACRO PARSEE: \n");
      write_form_to_xml (*form);
      return mt;
    }

  /* Sinon on parse une expression, et si c'est suivi d'un ';' on dit
     statement, sinon on dit expression. */

  /* Ca marceh parce qu'un statement, c'est soit une macro, soit une expression avec un ; derriere.
  
  /* XXX: si ca commence par un label, il faut que ce soit un
     statement derriere.  */
  *form = parse_expression_not_macro ();
  if(accept (SEMICOLON_RTK))
    return STATEMENT;
  
  return EXPRESSION;
}

//XXX: TODO les macros-expressions doivent etre prioritaires, et pour cela il faut les placer tout a la fin de l'arbre de parsing.
//Pour les statements, on peut bien les mettre en premier puisqu'il n'y a pas de problemes avec les operateurs etc.
//Il faut que des trucs comme if (a) 2 else 4 + 5 puissent marcher.
#endif

#if 0
static form_t
parse_statement ()
{
  form_t form;
  statement_or_expression_t se = parse_statement_or_expression (&form);
  parse_error_if_message (se == EXPRESSION,
			  "Statement expected, expression given\n");

  return form;
}

static form_t
parse_statement_not_macro ()
{
    /* En fait, un statement c'est un statement_or_expression ou un ';'
     ou  une expression suivie d'un ';' */

  /* C'est important que ca soit les seuls cas pour
     parse_statement_or_expression par exemple.  */

  /* Hum, il y a aussi le cas des labeled statements, mais on le
     reglera plus tard.  */
  form_t form = parse_expression_not_macro ();
  expect (SEMICOLON_RTK);
  return form;
}

  



#endif

/* XXX: Should call parse_statement_or_expression.  */
static form_t
parse_expression ()
{
#if 0
  if (next_token.type == ID_RTK || next_token.type == OPEN_BRACE_RTK)
    {
      form_t form;
      switch (parse_macro (&form))
	{
	case NOT_A_MACRO : break;
	case EXPRESSION : return form;
	case STATEMENT : parse_error ("Expression expected,"
					    "statement <nom_statement> given\n");
	default : parse_error ("Compiler error\n");
	}
    }
#endif
  form_t form;
  statement_or_expression_t se = parse_label_expression (&form);
  //    statement_or_expression_t se = parse_statement_or_expression (&form);
  parse_error_if_message (se == STATEMENT,
			  "Statement given, expression expected\n");
  return form;
};



/* In L, a label can be any expression; it is not mandatory that it is
   an ID. The "colon" is then an operator/separator with a very low
   priority, which is right-associative.

   One may think that for instance, let (i:Int) and (let i):Int would
   conflict; but notice that L grammar is defined as a PEG and is then
   unambiguous; and parsing macros is prioritary over parsing
   expressions.
*/
static statement_or_expression_t
parse_label_expression (form_t *form)
{
  statement_or_expression_t se;
  se = parse_assignment_expression (form);

  if(next_token.type == COLON_RTK)
    {
      /* XXX: for now, mais on peut le riterer. */
      //      assert (current_token.type == ID_RTK);
      //      assert (is_form (*form, id_form));
      accept (COLON_RTK);
      form_t new_form;
      se = parse_label_expression (&new_form);
      
      *form = label_form (*form, new_form);
    }
  return se;
}



static statement_or_expression_t
parse_assignment_expression (form_t *form)
{
  /* parse_unary_expression(); */
  form_t assignment_form;
  statement_or_expression_t se = parse_equality_expression (&assignment_form);

  if (se == STATEMENT)
    {
      *form = assignment_form;
      return STATEMENT;
    }
  if (accept (ASSIGNMENT_RTK))
    {
      assert (current_token.symbol == SYMBOL (=));

      form_t second_form;
      statement_or_expression_t se2 = parse_assignment_expression (&second_form);
      /* We are right-associative.  */

      assignment_form = equal_form (assignment_form, second_form);
    }
  *form = assignment_form;
  return EXPRESSION;
  //  return assignment_form;
}

DEFINE_PARSE_OPERATOR_LEFT (equality, EQUALITY, relational)
DEFINE_PARSE_OPERATOR_LEFT (relational, RELATIONAL, additive)
DEFINE_PARSE_OPERATOR_LEFT (additive, ADDITIVE, multiplicative)
DEFINE_PARSE_OPERATOR_LEFT (multiplicative, MULTIPLICATIVE, unary)

static statement_or_expression_t
parse_unary_expression (form_t *form)
{
  if (accept (UNARY_RTK))
    {
      form_t operator_form = id_form (current_token.symbol);
      form_t second_form;
      statement_or_expression_t se = parse_unary_expression (&second_form);
      *form = function_form (operator_form, CONS (second_form, NULL));
      return se;
    }
  else if(accept(MULTIPLICATIVE_RTK))
    {
      if(current_token.id == intern("*"))
	{
	  form_t operator_form = id_form (intern("deref"));
	  form_t second_form;
	  statement_or_expression_t se = parse_unary_expression (&second_form);
	  *form = function_form (operator_form, CONS (second_form, NULL));
	  return se;
	}
      else parse_error("Invalid unary token\n");
    }
  else if(accept( ADDITIVE_RTK))
    {
      if( current_token.id == intern( "-"))
	{
	  form_t operator_form = id_form (intern("unary_minus"));
	  form_t second_form;
	  statement_or_expression_t se = parse_unary_expression (&second_form);
	  *form = function_form (operator_form, CONS (second_form, NULL));
	  return se;
	}
      else parse_error("Invalid unary token\n");
    }
  
  /*XXX: unary minus, ampersand */
  return parse_postfix_expression (form);
}

/* Exemple de derecursivisation a gauche.  */
static statement_or_expression_t
parse_postfix_expression (form_t *form)
{
  form_t cur_form;
  statement_or_expression_t se = parse_primary_expression (&cur_form);

  if (se == STATEMENT)
    {
      *form = cur_form;
      return STATEMENT;
    }
  
  while(1)
    {
      if (next_token.type == OPEN_PAREN_RTK)
	{
	  form_t tuple_form;
	  statement_or_expression_t se = parse_tuple (&tuple_form);
	  cur_form = function_form_tuple (cur_form, tuple_form);
	}
      else if (accept (DOT_RTK)) /* a.x is a shortcut for a['x'] */
	{
	  expect (ID_RTK);

	  cur_form = access_form (cur_form, symbol_form (current_token.symbol));
	  //	  return EXPRESSION; /* XXX: isn't that wrong.  */
	}
      else if (accept (OPEN_SQUARE_BRACKET_RTK))
	{
	  form_t expression = parse_expression ();
	  cur_form = access_form (cur_form, expression);
	  expect (CLOSE_SQUARE_BRACKET_RTK);
	}

      
      //	else
      //	if (accept (OPEN_BRACKET
      //	if (accept (DOT

      else break;
	
    }

  *form = cur_form;
  return EXPRESSION;
}

/* In L we have tuples, which can be seen as arrays of

   It is in fact a struct whose fields are named 0,1,2 ...

   Tuples can be keyeds: i.e. (toto:4, num:5) is also a tuple, with
   fields toto and num. 
   */
static statement_or_expression_t 
parse_tuple (form_t *form)
{
  expect (OPEN_PAREN_RTK); 

  if (accept (CLOSE_PAREN_RTK))
    {
      *form = new_tuple_form (NULL);
      return EXPRESSION;
      /* Return NULL */
    }
  
  list_t tuple_content;
  list_t *tuple_content_ptr = &tuple_content;
  while(1)
    {

      *tuple_content_ptr = MALLOC (pair);
      (*tuple_content_ptr)->car = parse_expression ();
      tuple_content_ptr = &((*tuple_content_ptr)->next);
      
      if (accept (COMMA_RTK))
	{
	  continue;
	}
      else
	{
	  expect (CLOSE_PAREN_RTK);
	
	  *tuple_content_ptr = NULL;

	  /* Cree un tuple form.  */
	  *form = new_tuple_form (tuple_content);
	  return EXPRESSION;
	}
    }
}

static statement_or_expression_t
parse_primary_expression (form_t *form)
{

  #if 0
  /* Cautious: it could be a normal pair. */
  if (next_token.type == OPEN_PAREN_RTK)
    {
      tuple_form_t tform = (tuple_form_t) parse_tuple ();
      /* If the tuple was single, we can extract it.  This is not
	 mandatory, juste simpler for after.  */
      form_t form = (form_t) tform;
      if (tform->length == 1)
	{
	  form = CAR (tform->form_list);
	  assert (CDR (tform->form_list) == 0);
	  free (tform->form_list);
	  free (tform);
	}
      return form;
    }
  #endif

  { macro_type_t mt = parse_macro (form);
    if (mt != NOT_A_MACRO)
      return (statement_or_expression_t) mt;
  }

  
#if 0  
    /*else*/ if (next_token.type == OPEN_BRACE_RTK)
    {
      return parse_block (form);
    }
#endif

  if(next_token.type == OPEN_PAREN_RTK)
    {
      generic_form_t tuple_form;
      statement_or_expression_t se = parse_tuple (&tuple_form);
      assert (se == EXPRESSION);

      /* If the tuple was single, we can extract it.
	 Because single values are tuple of arity one.
	 
	 This is not mandatory, juste simpler for after.  */
      if (tuple_form->form_list_length == 1)
	{
	  *form = CAR (tuple_form->form_list);
	  assert (CDR (tuple_form->form_list) == 0);
	  free (tuple_form->form_list);
	  free (tuple_form);
	  return EXPRESSION;
	}
      else
	{
	  *form = tuple_form;
	  return EXPRESSION;
	}
    }
  
  return parse_atomic (form);
}

static statement_or_expression_t
parse_atomic (form_t *form)
{
  if (accept (ID_RTK))
    {
      // XXX: should be an id_form
      *form = id_form (current_token.id); 
      return EXPRESSION;
    }
  else if (accept (DECIMAL_RTK))
    {
      *form = int_form (current_token.integer);
      return EXPRESSION;
    }
  else if (accept (SYMBOL_RTK))
    {
      *form = symbol_form (current_token.symbol);
      return EXPRESSION;
    }
  else if (accept (STRING_RTK))
    {
      *form = string_form (current_token.string);
      return EXPRESSION;
    }

  /* Nothing worked; thus we got the null expression, that we
     transcript into an explicit void.  */
  *form = new_tuple_form(NULL);
  return EXPRESSION;
  
  parse_error ("Atomic expected\n");
  //STRING_RTK, FLOAT_RTK 
  
  /*  XXX: parse null expression here? */
  //  else asm("int $3");
}



#include <l/string.h>

/* Takes a string, parses it as a whole, and return the abstract
   syntax forest (list of forms).  */
list_t parse (String string)
{
  scanner_pointer = string->content;

  /* For now, because of the lexer, we need the string to be 0-terminated.  */
  assert (string->content[string->length] == 0);

  
  parse_initialize ();

  list_t list;
  list_t *list_ptr = &list;
  do {
    form_t form = parse_all ();//parse (scanner_pointer, length_);

    *list_ptr = MALLOC (pair);
    CAR (*list_ptr) = form;
    list_ptr = &CDR (*list_ptr);
  } while (scanner_pointer < string->content + string->length);

  *list_ptr = NULL;
  return list;
}

/* TODO: parse_with_parser, to parse a string with a different
parser.  */


/* The subgrammar for types.  We should also have our own lexer (for
   '<-', which is only in types) */



type_form_t parse_type_form (void);
type_form_t parse_base_type (void);

form_t parse_misc_constructed_type (void);
type_form_t parse_tuple_type_form (void);
type_form_t parse_function_type_form (void);
type_form_t parse_struct_type (void);
type_form_t parse_indirection_type_form(void);

/* A type is one of these :
  
   type := int | float
         | 'struct' '{' {type id ';'}* '}'
         | type '|' type
         | '(' type { ',' type }* ')'
         | type '<-' type
	 | type '*'
	 | type '['']'
         
   type_declaration := 'type' id '=' type ';'

   * et '[]' sont les plus prioritaires (aussi prioritaires)
   entre <- et |, heu ...

   On va mettre <- en plus prioritaire.
   
   a | b <- c | d == (a | (b <- c) | d)
   c <- d | a <- b ==  (c <- d) | (a <- b)

   int * <- c [] == ((int *) <- (c []))
*/

/* So we have:

    type_declaration := 'type' id '=' type ';' 
    
    type := sum_type
         
    //Here, we don't really care whether sum_type is left or right-associative
    sum_type := function_type
              | sum_type '|' function_type
              

    //for curryfication, function_type is left-associative
    function_type := postfix_type
                   | function_type [ '<-' postfix_type ]

    //Note that we don't have "reference types": they are useless in L.
    postfix_type := struct_type
                  | struct_type '*'
                  | struct_type '[]'

    //When we define a new struct, we use Toto to design a pointer to the
    //struct, and struct Toto for the actual struct.
    struct_type := 'struct' '{' {type id ';'}* '}'
                 | '(' type { ',' type }* ')'
                 | base_type

    base_type := id                 

/* Ref:
   XXX:http://www.csse.monash.edu.au/~damian/papers/HTML/ModestProposal.html*/

static statement_or_expression_t
parse_type_declaration (form_t *form)
{
  expect (ID_RTK);

  symbol_t define_symbol = current_token.id;
  assert (define_symbol == SYMBOL (type) || define_symbol == SYMBOL (type_alias));

  expect (ID_RTK);

  symbol_t type_name = current_token.id;

  expect (ASSIGNMENT_RTK);

  type_form_t type_form = parse_type_form ();

  expect (SEMICOLON_RTK);

  /* XXX: create a corresponding define form.  */
  *form = define_form (define_symbol, type_name, (form_t) type_form);

  return STATEMENT;
}

generic_form_t
parse_struct (form)
{
  expect (ID_RTK);
  assert (current_token.id == SYMBOL (struct));
  
  expect (OPEN_BRACE_RTK);

  type_form_t tf = new_form (type);
  tf->type_form_type = STRUCT_TYPE_FORM;

  list_t form_list;
  {
    list_t *form_list_ptr = &form_list;
    
    while(!accept (CLOSE_BRACE_RTK))
      {

	*form_list_ptr = MALLOC(pair);
	(*form_list_ptr)->car = parse_variable_declaration ();
	form_list_ptr = &((*form_list_ptr)->cdr);
	expect (SEMICOLON_RTK);
      }
    *form_list_ptr = NULL;
  }

  return generic_form_symbol (SYMBOL (struct), form_list);

  #if 0
  expect (ID_RTK);
  assert (current_token.id == SYMBOL (struct));

  expect (OPEN_BRACE_RTK);

  type_form_t tf = new_form (type);
  tf->type_form_type = STRUCT_TYPE_FORM;

  list_t form_alist;
  {
    list_t *form_alist_ptr = &form_alist;
    
    while(!accept (CLOSE_BRACE_RTK))
      {
	*form_alist_ptr = MALLOC (pair);
	(*form_alist_ptr)->car = parse_variable_declaration ();
	form_alist_ptr = &((*form_alist_ptr)->cdr);
	expect (SEMICOLON_RTK);
      }
    *form_alist_ptr = NULL;
  }

  return generic_form_symbol_alist (SYMBOL (struct), form_alist);
	#endif			    
}


type_form_t parse_type_form (void)
{
  /* XXX: on pourrait rajouter ici le fait que c'est un type.  */
  return parse_function_type_form ();
}

//The <- Type operator is left  associative.
type_form_t parse_function_type_form (void)
{
  type_form_t curform = parse_indirection_type_form ();

  while (accept (FUNCTION_TYPE_RTK))
    {
      type_form_t second_form = parse_indirection_type_form ();
      curform = function_type_form (curform, second_form);
    }
  
  return curform;
}

//The * type operator is postfix.
type_form_t parse_indirection_type_form(void)
{
  type_form_t type_form = parse_tuple_type_form();

  while (accept(MULTIPLICATIVE_RTK))
    {
      if(current_token.symbol != intern("*"))
	{
	  panic("Parse error\n");
	}
      type_form = indirection_type_form(type_form);
    }

  return type_form;
}



type_form_t parse_tuple_type_form (void)
{
  if(accept (OPEN_PAREN_RTK))
    {
      if(accept (CLOSE_PAREN_RTK))
	{
	  //void type.
	  return tuple_type_form (NULL);
	}
      else
	{
	  list_t l;
	  list_t *l_ptr = &l;

	  for(;;)
	    {
	      form_t form = parse_type_form ();
	      
	      *l_ptr = CONS (form, NULL);
	      l_ptr = &((*l_ptr)->next);
	      
	      if(!accept (COMMA_RTK))
		{
		  expect (CLOSE_PAREN_RTK);
		  *l_ptr = NULL;

		  return tuple_type_form (l);
		}
	    }
	}
    }
  
  type_form_t form = parse_struct_type ();
  list_t list = CONS (form, NULL);
  return tuple_type_form (list);
}

/* XXX: here, we could put all constructed types (except <- of
   course) */
type_form_t parse_struct_type (void)
{
  if (next_token.type == ID_RTK)
    {
      if(next_token.id == SYMBOL (struct))
	{
	  return parse_struct ();
	}
    }
  return parse_misc_constructed_type ();
}

/* Parses things like List(Int), or Pair(Void *, Bool) */
form_t
parse_misc_constructed_type (void)
{
  expect (ID_RTK);

  symbol_t symbol = current_token.id;

  if(accept (OPEN_PAREN_RTK))
    {
      if(accept (CLOSE_PAREN_RTK))
	return generic_form_symbol (symbol, NULL);

      list_t list;
      list_t *plist = &list;
      
      while(1)
	{
	  form_t form = parse_type_form ();

	  *plist = MALLOC (pair);
	  (*plist)->car = form;
	  plist = &((*plist)->cdr);
	  
	  if(accept (CLOSE_PAREN_RTK))
	    {
	      *plist = NULL;
	      return generic_form_symbol (symbol, list);
	    }

	  expect (COMMA_RTK);
	}
    }
  else return base_type_form (current_token.id);
}

#if 0
type_form_t parse_base_type (void)
{
  expect (ID_RTK);

  return base_type_form (current_token.id);
//  type_form_t tf = new_form (type);
//
//  tf->type_form_type = BASE_TYPE_FORM;
//  tf->base_type_name = current_token.id;
//  
//  return tf;
}
#endif

/* Parsers that don't belong here, but are here while there isn't a
   good interface to the L lexer and L parser.  */

/* while is a demo (and a standard) macro.  */
/* while will be defined like this:
   macro while '(' @(Expression exp) ')' @(Statement stat)
   {
     @loop(@seq(@if(@!(exp), @break),
                stat))
   }
*/   
static statement_or_expression_t
parse_while (form_t *form)
{
  expect (ID_RTK);
  assert (current_token.id == intern ("while"));

  expect (OPEN_PAREN_RTK);
  form_t exp = parse_expression ();
  expect (CLOSE_PAREN_RTK);

  form_t stat = parse_statement ();

  list_t form_list = CONS (if_form (function_form (id_form (SYMBOL (!)),
						   CONS (exp, NULL)),
				    break_form (),
				    NULL),
			   CONS (stat, NULL));
  *form = loop_form (seq_form (form_list));
  
  return STATEMENT;
}

static statement_or_expression_t
parse_cast (form_t *form)
{
  expect (ID_RTK);
  assert (current_token.id == intern ("cast"));

  expect (OPEN_PAREN_RTK);
  form_t type_form = parse_type_form ();
  expect( COMMA_RTK);
  form_t exp = parse_expression();
  expect (CLOSE_PAREN_RTK);

  *form = generic_form_symbol( SYMBOL( cast),
			       CONS( type_form,
				     CONS( exp, NULL)));
  return EXPRESSION;
}


static statement_or_expression_t
parse_foreach( form_t *form)
{
  expect( ID_RTK);
  assert( current_token.id == SYMBOL( foreach));

  expect( OPEN_PAREN_RTK);
  form_t iterator = parse_expression();
  expect( ID_RTK);
  assert( current_token.id == SYMBOL( in));
  form_t collection = parse_expression();
  expect( CLOSE_PAREN_RTK);

  form_t body = parse_statement();

  *form = generic_form_symbol( SYMBOL( foreach),
			       CONS( iterator,
				     CONS( collection,
					   CONS( body,
						 NULL))));
  return STATEMENT;
}



/* This function makes exporting C functions to L much more easy.  But
   it's a ugly hack; the parser interface should be better.

   Must not be used while parsing something else.  */
type_form_t
string_to_type_form (char *string)
{
  //  printf ("STRING TO TYPE FORM %s\n", string);
  scanner_pointer = string;
  parse_initialize ();
  type_form_t tf = parse_type_form ();
  //  lispify (tf);
  return tf;
}


/* These functions help calling a sub-help parser.  In the future, the
   L parser will use the same buffer than the rest; so this won't be
   needed.  */
form_t
l_parse_expression (Read_Buffer buf)
{
  scanner_pointer = buf->current;
  parse_initialize ();
  form_t tf = parse_expression ();
  buf->current = scanner_pointer;
  return tf;
}

form_t
l_parse_statement (Read_Buffer buf)
{
  scanner_pointer = buf->current;
  parse_initialize ();
  form_t tf = parse_statement ();
  buf->current = scanner_pointer;
  return tf;
}

statement_or_expression_t
l_parse_statement_or_expression (form_t *form, Read_Buffer buf)
{
  scanner_pointer = buf->current;
  parse_initialize ();
  statement_or_expression_t se = parse_statement_or_expression (form);
  buf->current = scanner_pointer;
  return se;
}

/* Yet another hacky function.  */
symbol_t
l_parse_id(Read_Buffer buf)
{
  scanner_pointer = buf->current;
  parse_initialize ();
  assert(next_token.type == ID_RTK);
  buf->current = scanner_pointer;
  return(next_token.id);
}

//l_parse_statement...
