/* support.c - Support C code for the c outputer.
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
#define _GNU_SOURCE //asprintf
#include <stdio.h>

#include <l/expand.h>
#include <l/std/print.h>
#include <l/string.h>
#include <l/sys/panic.h>
#include "../compiler/c-to-l.h"
#include <assert.h>

form_t Expanded_Form_printer( expanded_form_t form, form_t formatter)
{
  /* For now, we can format Forms only using the gnu_c format.  */
  assert( formatter && is_form( formatter, id_form)
	  && ((id_form_t) formatter)->value == SYMBOL( gnu_c));

  return generic_form_symbol( SYMBOL( c_output_form),
			      CONS( form, NULL));
}

void *lispify( void*);

list_t
expanded_form_list_from_file_name( String s)
{
  char *cstring = make_C_string_from_L_string( s);
  printf( "%s|\n", cstring);
  list_t form_list = parse_file(cstring );
  
  list_t expanded_form_list = expand_form_list( form_list);

  return expanded_form_list;
}

Symbol
convert_id(Symbol s)
{
  /* Transform the L ids into valid C ones.  */
  char buffer[1024];
  char *current = buffer;
  char *current_symbol = s->name;

  for(;;)
    {
      switch(*current_symbol)
	{
	case 0:
	  *current = 0;
	  goto end;

	case '#' :
	  strcpy( current, "_sharp_");
	  current += 7;
	  break;

	case '-':
	  *current = '_';
	  break;
	  
	default:
	  *current = *current_symbol;
	  current++;
	  break;
	}
      current_symbol++;
    }
  
 end:
  return intern( buffer);//intern( make_heap_string( buffer));
}

String
convert_string(String s)
{
  /* Transform the L ids into valid C ones.  */
  char buffer[1024];
  char *current = buffer;
  char *current_string = s->content;

  while(current_string < s->content + s->length)
    {
      switch(*current_string)
	{
	case 0:
	  panic( "PB");

	case '\n':
	  strcpy( current, "\\n");
	  current += 2;
	  break;

	case '"':
	  strcpy( current, "\\\"");
	  current += 2;
	  break;

	case '-':
	  *current = '_';
	  current++;
	  break;
	  
	  
	default:
	  *current = *current_string;
	  current++;
	  break;
	}
      current_string++;
    }
  
 end:
  return maken_heap_string( buffer, current-buffer);
}


String
quote_string(String s)
{
  /* Transform the L ids into valid C ones.  */
  char buffer[1024];
  char *current = buffer;
  char *current_string = s->content;

  while(current_string < s->content + s->length)
    {
      switch(*current_string)
	{
	case 0:
	  panic( "PB");

	case '\n':
	  strcpy( current, "\\n");
	  current += 2;
	  break;

	case '"':
	  strcpy( current, "\\\"");
	  current += 2;
	  break;
	  
	default:
	  *current = *current_string;
	  current++;
	  break;
	}
      current_string++;
    }
  
 end:
  return maken_heap_string( buffer, current-buffer);
}


int
get_string_length( String s)
{
  return s->length;
}

String
convert_id_as_string(Symbol s)
{
  /* Transform the L ids into valid C ones.  */
  char buffer[1024];
  char *current = buffer;
  char *current_string = s->name;

  while(*current_string)
    {
      switch(*current_string)
	{
	case 0:
	  panic( "PB");

	case '\n':
	  strcpy( current, "\\n");
	  current += 2;
	  break;

	case '"':
	  strcpy( current, "\\\"");
	  current += 2;
	  break;
	  
	  
	default:
	  *current = *current_string;
	  current++;
	  break;
	}
      current_string++;
    }
  
 end:
  return maken_heap_string( buffer, current-buffer);
}

void
mangle_type_name_rec( char **start, form_t type_form)
{
  /* For open parenthesis, we put a __O__; for a close, a __C__,
     and for a comma, a __c__ */
  if(is_form( type_form, id_form))
    {
      strcpy( *start, ((id_form_t) type_form)->value->name);
      *start += strlen( *start);
    }
  else
    {
      assert( is_form( type_form, generic_form));
      generic_form_t cf = type_form;
      strcpy( *start, ((generic_form_t) type_form)->head->name);
      *start += strlen( *start);
      memcpy( *start, "__O__", 5);
      *start +=5;
      
      if(cf->form_list == NULL)
	{
	  memcpy( *start, "__C__", 6);
	  *start += 5;
	  return;
	}
	
      form_t first = CAR( cf->form_list);
      mangle_type_name_rec( start, first);

      FOREACH( element, cf->form_list->next)
	{
	  memcpy( *start, "__c__", 5);
	  *start += 5;
	  mangle_type_name_rec( start, CAR( element));
	}
      
      memcpy( *start, "__C__", 6);
      *start += 5;
    }
}


#include <l/sys/type.h>
Symbol
mangle_type_name( Type t)
{
  assert( t->type_type == BASE_TYPE);
  /* For now.  */
  if(is_form( t->type_form, id_form))
    return ((id_form_t) t->type_form)->value;

  char buffer[1024];
  char *start = buffer;
  mangle_type_name_rec( &start, t->type_form);

  /* L Types are in a different namespace than functions etc; this is
     used to differentiate them. */
  strcpy( start, "__type");

  return intern( buffer);
  //  return make_heap_string( ((id_form_t) t->type_form)->value->name);
  
}

String
type_to_string( Type t)
{
  return make_heap_string( asprint_type( t));
}


Symbol
prepend_star( Symbol s)
{
  unsigned int len = strlen( s->name) + 1;
  char *str = malloc( len+2);
  str[0] = '*';
  memcpy( str+1, s->name, len);
  str[len] = 0;
  Symbol sstar = intern( str);
  free( str);
  return sstar;
}

#include <l/sys/global.h>
Type
get_global_type( Symbol name)
{
  global_t glob = gethash( name, global_hash);
  assert( glob);
  return glob->type;
}

String
file_name_non_directory( String filename)
{
  char *save_end;
  char *end = save_end = filename->content + filename->length;

  for(;;)
    {
      if(end <= filename->content)
	break;
      if(*end == '/')
	{
	  end++;
	  break;
	}
      end--;
    }
  return maken_heap_string( end, save_end - end);
}

String
file_name_non_extension( String filename)
{
  char *save_end;
  char *end = save_end = filename->content + filename->length;

  for(;;)
    {
      if(end <= filename->content)
	break;
      if(*end == '.')
	{
	  break;
	}
      end--;
    }
  return maken_heap_string( filename->content, end - filename->content);
}


void
init_c_output_support()
{
  define_printer( TYPE( "Expanded_Form"), Expanded_Form_printer);
  DEFINE_C_FUNCTION( lispify, "Void <- Form");
  DEFINE_C_FUNCTION( convert_id, "Symbol <- Symbol");
  DEFINE_C_FUNCTION( convert_id_as_string, "String <- Symbol");
  DEFINE_C_FUNCTION( convert_string, "String <- String");
  DEFINE_C_FUNCTION( quote_string, "String <- String");
  DEFINE_C_FUNCTION( expanded_form_list_from_file_name,
		     "List( Compound_Form) <- String");
  DEFINE_C_FUNCTION( intern_type, "Type <- Form");
  DEFINE_C_FUNCTION( mangle_type_name, "Symbol <- Type");
  DEFINE_C_FUNCTION( type_to_string, "String <- Type");
  DEFINE_C_FUNCTION( prepend_star, "Symbol <- Symbol");
  DEFINE_C_FUNCTION( get_global_type, "Type <- Symbol");
  DEFINE_C_FUNCTION( file_name_non_directory, "String <- String");
  DEFINE_C_FUNCTION( file_name_non_extension, "String <- String");
  DEFINE_C_FUNCTION( get_string_length, "Int <- String");
}

//list_
