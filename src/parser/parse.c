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
    LOGICAL_OR_RTK,
    LOGICAL_AND_RTK,
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
	  || result_scanning == STAR_TK)
    {
      /* We parsed &&.  */
      switch(result_scanning)
	{
	case NOT_TK:
	  current_token.id = intern( "@not");
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
  else if(result_scanning == OR_TK)
    {
      current_token.id = intern( "@or");
      current_token.type = LOGICAL_OR_RTK;
    }
  else if(result_scanning == AND_TK)
    {
      current_token.id = intern( "@and");
      current_token.type = LOGICAL_AND_RTK;
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


static statement_or_expression_t parse_type_declaration (form_t *form);

type_form_t parse_type_form (void);

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
}




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
      else if(next_token.id == SYMBOL (type_alias))
	{
	  parse_type_declaration (&form);
	  return form;
	}
    }

  panic( "Should not be reached\n");
  //  form = parse_function_definition ();
  form = -2;

  return form;
  /* Expect end */
}

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

/* XXX: separate expressions-only, and statements-anly, and put
   statement or expression in all?  */

/* Ou alors on tente de parser, et on dit ce qu'on a reussit a
   parser. (un statement ou une expression).  En fonction du contexte,
   ca sera bon ou pas. */

/* Le boolean dit si on a parse un statement ou une expression.  */



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
l_parse_type (Read_Buffer buf)
{
  scanner_pointer = buf->current;
  parse_initialize ();
  form_t tf = parse_type_form ();
  buf->current = scanner_pointer;
  return tf;
}


//l_parse_statement...
