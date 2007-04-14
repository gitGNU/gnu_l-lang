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

  //  DEFINE_C_FUNCTION (expand, "Void *<-Form");
  //  DEFINE_C_FUNCTION (compile, "Void <-Form");

}
