/* init.c - Init every L subsystem.
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


/* Note : This initialisation file should be generated automaticaly by
   L according to the different features a program need, and their
   dependencies.  */

#include "compiler/c-to-l.h"
extern void *compile( void*);

void *declare_block_begin( void*);
void *declare_block_end( void*);
void *declare_function_begin( void*);
void *declare_function_end( void*);


void
init ()
{
  //  init_namespace ();
  // init_read_object ();
  //  init_symbol ();
  //  init_int_object ();
  //  init_pair ();
  //  init_string ();
  //  init_function ();
  new_init_type ();
  //init_type ();

  //Exporting C functions to L requires the parser to be initialized
  init_parser ();


  init_expand ();

  init_location ();
  init_analysis ();
  init_generate ();

  init_library ();
  init_c_output_support();
  init_newparser_support();

  /* Things that don't really have a place anywhere.  */
  eval_cstring( "compile_time type Common_To_All_Type = struct { type_type:Int;"
		"type_form:Form;"
		"size:Int;"
		"alignment:Int;"
		"};"
		"compile_time type Real_Type = struct { common_:Common_To_All_Type; }* ;"
		"compile_time attribute Type t.type_form = cast( Real_Type, t).common_.type_form;");

  eval_cstring( "compile_time attribute Symbol s.name = get_symbol_name( s);");

  

  DEFINE_C_FUNCTION( declare_block_begin, "()<- ()");
  DEFINE_C_FUNCTION( declare_block_end, "Expanded_Form <- (List( Form))");
  DEFINE_C_FUNCTION( declare_function_begin, "() <- (Compound_Form, Form)");
  DEFINE_C_FUNCTION( declare_function_end, "Expanded_Form <- (Expanded_Form)");

  

  
  //  DEFINE_C_FUNCTION (expand, "Void *<-Form");
  //  DEFINE_C_FUNCTION (compile, "Void <-Form");

}
