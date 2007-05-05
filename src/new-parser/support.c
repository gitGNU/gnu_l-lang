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
peek_char()
{
  return (int) (*parser_current_pointer);
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
parse_Expression()
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
      *list_ptr = CONS( s->content[i], NULL);
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
  


void
init_newparser_support()
{
  DEFINE_C_FUNCTION( set_parser_support_to, "Void <- String");
  DEFINE_C_FUNCTION( peek_char, "Int <- ()");
  DEFINE_C_FUNCTION( read_char, "Int <- ()");
  DEFINE_C_FUNCTION( character_from_symbol, "Int <- Symbol");
  DEFINE_C_FUNCTION( concat, "String <- (String, String)");
  DEFINE_C_FUNCTION( get_symbol_name, "String <- (Symbol)");
  DEFINE_C_FUNCTION( intern_string, "Symbol <- (String)");
  DEFINE_C_FUNCTION( get_point_pos, "Int <- ()");
  DEFINE_C_FUNCTION( substring, "String <- (Int, Int)");
  DEFINE_C_FUNCTION( string_to_int_list, "List( Int) <- (String)");
  DEFINE_C_FUNCTION( string_element, "Int <- (String, Int)");
  DEFINE_C_FUNCTION( parse_Expression, "Form <- ()");
}
