/* support.c - Support for the parser.
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

#include <stdio.h>

#include <l/expand.h>
#include <l/std/print.h>
#include <l/string.h>
#include <l/sys/panic.h>
#include "../compiler/c-to-l.h"
#include <assert.h>

static char *parser_current_pointer;
static char *parser_end_pointer;

void
set_parser_support_to( String s)
{
  parser_current_pointer = s->content;
  parser_end_pointer = s->content + s->length;
}

char *
get_parser_support( void)
{
  return parser_current_pointer;
}
		    

int
peek_char(void)
{
  return (int) (*parser_current_pointer);
}

int
new_peek_char(int i )
{
  return (int) parser_current_pointer[i];
}

int
read_char()
{
  if(parser_current_pointer >= parser_end_pointer)
    return 0;
  else return (*parser_current_pointer++);
}

char *
get_point_pos(void)
{
  return parser_current_pointer;
}

// Create a string from what is parsed for a symbol.
String
get_parsed_string_symbol(unsigned int size, char *start, char *end)
{
  char *new_string = malloc( size);
  int i = 0;
  char *curptr = start;
  
  while(curptr < end)
    {
      if(*curptr == '\\')
	{
	  switch(*(++curptr))
	    {
	    case '\\' : new_string[i++] = '\\'; break;
	    case 'n' : new_string[i++] = '\n'; break;
	    case 't': new_string[i++] = '\t'; break;
	    default : panic( "UNIMPLEMENTED\n");
	    }
	  curptr++;
	}
      else new_string[i++] = *(curptr++);
    }

  assert( i == size);
  return maken_heap_string( new_string, size);
}

// Create a string from what is parsed for a string.
// Multi-component strings (like "aa" "bb" are concatened. 
String
get_parsed_string_string(unsigned int size, char *start, char *end)
{
  char *new_string = malloc( size);
  int i = 0;
  char *curptr = start + 1;
  
  while(curptr < end - 1)
    {
      if(*curptr == '\\')
	{
	  switch(*(++curptr))
	    {
	    case '\\' : new_string[i++] = '\\'; break;
	    case 'n' : new_string[i++] = '\n'; break;
	    case 't': new_string[i++] = '\t'; break;
	    default : panic( "UNIMPLEMENTED\n");
	    }
	  curptr++;
	}
      else if(*curptr == '"')
	{
	  while(*(++curptr)!= '"');
	  curptr++;
	}
      else new_string[i++] = *(curptr++);
    }
  
  assert( i == size);
  maken_heap_string( new_string, size);
}


String
substring(char *start, char *end)
{
  return maken_heap_string( start, end-start);
}

int
string_element( String s, unsigned int num)
{
  if(s->length <= num)
    {
      panic( "Asking for character number %d, string has only %d characters\n",
	     num, s->length);
    }
  return s->content[num];
}

#include "../parser/buffer.h"
form_t
_l__parse__parse_grammar__Expression()
{
  Read_Buffer rb = MALLOC( read_buffer);
  rb->current = parser_current_pointer;
  rb->end = parser_end_pointer;
  rb->start = parser_current_pointer;

  form_t form = l_parse_expression( rb);

  parser_current_pointer = rb->current;
  /* This is hacky: as the L parser has one lexer token in advance,
     which is }, we just decrement the parser_current_pointer by
     one.  */
  parser_current_pointer--;

  free( rb);
  
  return form;
  //return generic_form_symbol( SYMBOL( toto), NULL);
}

form_t
_l__parse__parse_grammar__Type()
{
  Read_Buffer rb = MALLOC( read_buffer);
  rb->current = parser_current_pointer;
  rb->end = parser_end_pointer;
  rb->start = parser_current_pointer;

  form_t form = l_parse_type( rb);

  parser_current_pointer = rb->current;
  /* This is hacky: as the L parser has one lexer token in advance,
     which is =, we just decrement the parser_current_pointer by
     one.  */
  parser_current_pointer--;

  free( rb);

  //return   generic_form_symbol( SYMBOL( Type), CONS( form, NULL));
  return form;
}

Symbol
intern_string( String s);

/* This is used to parse text tokens "as a whole". */
form_t
parse_symbol( String s)
{
  int i;
  for(i = 0; i < s->length; i++)
    {
      if(read_char() != s->content[i])
	panic( "Error while reading symbol %s\n", make_C_string_from_L_string( s));
    }
  
  /* Parse spacing.  */
  _l__parse__parse_grammar__Spacing();
  
  return intern_string( s);
}


/* Defines the parse_* functions.  */
void
pre_define_function( Symbol symbol, form_t return_type_form)
{
  define_global( symbol,
		 intern_type( function_type_form( return_type_form,
						  tuple_type_form( NULL))),
		 NULL);
}

extern hash_table_t expander_hash;

/* We need that because we use standard macros for grammar macros,
   so grammar expander are regular expanders.  */
form_t
call_grammar_macro( Symbol macro_name, form_t form)
{
  char *funname_ = malloc( strlen( macro_name->name) + 30);
  strcpy( funname_, macro_name->name);
  strcat( funname_, "##grammar_macro");
  Symbol funname = intern( funname_);
  free( funname_);

  /* Retrieve the expander function.  */
  expander_t expander = gethash( funname, expander_hash);
  if(expander == NULL)
    panic( "There is no grammar macro for %s\n", funname->name);

  form_t expform = expander( form);

  return expform;
}




int
character_from_symbol( Symbol s)
{
  return (int) s->name[0];
}

list_t
string_to_int_list( String s)
{
  list_t list;
  list_t *list_ptr = &list;

  for(int i = 0; i < s->length; i++)
    {
      char next = s->content[i];
      if(next == '\\')
	{
	  switch( s->content[++i])
	    {
	    case 0:
	      next = 0;
	      break;
	    case 'n':
	      next = '\n';
	      break;
	    case 't':
	      next = '\t';
	      break;
	    default:
	      next = s->content[i];
	    }
	}
      *list_ptr = CONS( next, NULL);
      list_ptr = &((*list_ptr)->next);
    }
  *list_ptr = NULL;
  return list;
}


//XXX: should go (in an extended version allowing concatenating of an
//arbitrary number of strings) in string.c
String
concat( String s1, String s2)
{
  unsigned int len = s1->length + s2->length;
  char *string = malloc( len);
  memcpy( string, s1->content, s1->length);
  memcpy( string + s1->length, s2->content, s2->length);
  String s = MALLOC( string);
  s->content = string;
  s->length = len;
  return s;
}

//This one also
String
get_symbol_name( Symbol s)
{
  return make_heap_string( s->name);
}

Symbol
intern_string( String s)
{
  return intern( make_C_string_from_L_string( s));
}
  

/* This is for testing that the parser can auto-parse itself.  */
String
get_test_string()
{
  
char *string = "grammar parse_grammar = {"
"  rule Spacing:Character = [ \\n\\t]* ;"
"  rule Alpha:Character = [a-zA-Z_] ;"
"  rule Alpha_Num:Character = [a-zA-Z_0-9] ;"
"  "
"  "
"  rule Identifier:Symbol = <start:_> Alpha Alpha_Num* <end:_>"
"  { intern_string( substring( start, end))} ;"
""
"  rule Escaped_Character:Character = [\\\\] ( \"n\" {10}"
"                                          | \"t\"  {9}"
"		                          | [^tn] ) ;"
"  "
"  rule Maybe_Escaped_Character:Character = Escaped_Character | [^\\\\] ;"
"  rule Maybe_Escaped_Character_Character_Range:Character = Escaped_Character|[^\\]\\\\];"
""
"  rule String:Form = [\"] <start:_> ( Escaped_Character | [^\\\"\\\\])* <end:_> [\"]"
"                       {String_Form( substring( start, end))} ;"
"  "
"  rule Character_Range:Form ="
"                         <max:<min:Maybe_Escaped_Character_Character_Range>>"
"                         (\"-\" <max:Maybe_Escaped_Character>)?"
"                         { if(min == max) Int_Form( min) "
"			     else Compound_Form('-', list( Int_Form( min),"
"							   Int_Form( max))) } ;"
""
"  rule Character_Set:Form = "
"                       <char_selector:{'[]'}>"
"                       \"[\" (\"^\" <char_selector:{'[^]'}>)?"
"                       <cr_list:( <cr:Character_Range> { make( cr) })*> \"]\""
"                       { Compound_Form( char_selector, cr_list) } ;"
""
"  rule Callable_Rule:Form = <id:Identifier> {Id_Form( id)};"
""
"  rule Semantic_Action:Form = \"{\" <exp:Expression> \"}\""
"                              {Compound_Form( '{}', list( exp))};"
"  "
"  rule Grouping:Form = \"<\" <id:Identifier> \":\" <form:Rule> \">\""
"                       { Compound_Form( '<>', list( Id_Form( id), form)) };"
""
"  rule Primary:Form = (String"
"		       | Character_Set "
"		       | Callable_Rule"
"		       | Grouping"
"		       | Semantic_Action"
"		       | \"(\" <r:Rule> \")\" {r});"
""
"  rule Postfix:Form = <form:Primary> ( <start:_> (\"?\" | \"*\" | \"+\") <end:_>"
"				       <form:{ Compound_Form( intern_string( substring( start,end)),"
"							      list( form)) }>)?"
"                      { form };"
"  "
"  rule Sequence:Form = Spacing <post_list:(<post:Postfix>  Spacing {make( post)})*>"
"                       { if( post_list.tail == cast( List( Form), 0)) post_list.head"
"			   else Compound_Form( ' ', post_list) };"
""
"  rule Alternative:Form = <prim:Sequence>"
"                          (\"|\" Spacing <sec:Sequence>"
"			   <prim:{ Compound_Form( '|', list( prim, sec)) }>)*"
"                          { prim };"
""
"  rule Rule:Form = Alternative;"
""
"  rule Grammar_Rule:Form = \"rule\" Spacing <id:Identifier> \":\" <ret_type:Type>"
"                           Spacing \"=\" Spacing <r:Rule> Spacing \";\" Spacing"
"                           { Compound_Form( 'rule', list( Id_Form( id),"
"							  ret_type,"
"							  r)) };"
"  "
"  rule Grammar:Form = \"grammar\" Spacing <id:Identifier> Spacing \"=\" Spacing"
"                      \"{\" <gr_list:(<gr:Grammar_Rule> {make( gr)})*> \"}\" Spacing \";\""
"                      { Compound_Form( 'define',"
"				       cons( Id_Form( 'grammar'),"
"					     cons( Id_Form( id),"
"						   gr_list))) };"
  "};";

 return make_heap_string( string);

}

void
parse_error(void)
{
  printf( "Parse error\n");
  exit( 3);
}

void
init_newparser_support()
{
  DEFINE_C_FUNCTION( set_parser_support_to, "Void <- String");
  DEFINE_C_FUNCTION( new_peek_char, "Int <- (Int)");
  DEFINE_C_FUNCTION( peek_char, "Int <- ()");
  DEFINE_C_FUNCTION( read_char, "Int <- ()");
  DEFINE_C_FUNCTION( call_grammar_macro, "Form <- (Symbol, Form)");
  DEFINE_C_FUNCTION( parse_symbol, "Symbol <- (String)");
  DEFINE_C_FUNCTION( character_from_symbol, "Int <- Symbol");
  DEFINE_C_FUNCTION( concat, "String <- (String, String)");
  DEFINE_C_FUNCTION( get_symbol_name, "String <- (Symbol)");
  DEFINE_C_FUNCTION( intern_string, "Symbol <- (String)");
  DEFINE_C_FUNCTION( get_point_pos, "Int <- ()");
  DEFINE_C_FUNCTION( substring, "String <- (Int, Int)");
  DEFINE_C_FUNCTION( get_parsed_string_string, "String <- (Int, Int, Int)");
  DEFINE_C_FUNCTION( get_parsed_string_symbol, "String <- (Int, Int, Int)");
  DEFINE_C_FUNCTION( string_to_int_list, "List( Int) <- (String)");
  DEFINE_C_FUNCTION( string_element, "Int <- (String, Int)");
  DEFINE_C_FUNCTION( _l__parse__parse_grammar__Expression, "Form <- ()");
  DEFINE_C_FUNCTION( _l__parse__parse_grammar__Type, "Form <- ()");
  DEFINE_C_FUNCTION( pre_define_function, "Void <- (Symbol, Form)");
  DEFINE_C_FUNCTION( get_test_string, "String <- ()");

  eval_cstring( "type Exit = struct { dummy:Int;}*;");
  DEFINE_C_FUNCTION( parse_error, "Exit <- ()");

  init_grammar_expander();
  init__parse_l();
}
