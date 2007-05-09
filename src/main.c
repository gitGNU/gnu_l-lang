/* main.c - Main
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

/* XXX: should be kept minimal -- contains only the code to launch the
   L REPL (with every L features).   */

/* For now it contains also code for testing.  */

#include "parser/parse.h"
#include "compiler/generate.h"
#include <l/expand.h>
#include <assert.h>
#include "objects/function.h"
#include <l/string.h>

//typedef void (*void_to_void_t)(void);
typedef int (*void_to_int_t)(void);

#include <l/global.h>
int
main (int argc, char **argv)
{
  init ();

  
  //  eval (make_heap_string ("Int test() { 2 }"));
  assert (argc > 1);

  eval_file (argv[1]);

  global_t glob = get_global( SYMBOL( test));
  assert( glob);
  void_to_int_t test = glob->address;
  assert( test);

  Symbol s = find_owning_function( test);
  printf( "Symbol %s\n", s->name);

  printf ("ICI: test =%p \n", test);
  int result = test ();

  printf ("TEST result: %d\n", result);

  
  //run_analysis (CONS (form, NULL));
  //  compile (form);
  
  //
  //char *test_string = "x = y + (3, 4) + { function (4, 5); 3 + 4 }";
  //
  //
  //
  ////  char *test_string= "function (4, 5) + 3 * (4 + 5) * 6";
  ////char *test_string = "3 + 4";
  //
  //char *test = test_string;
  //
  //parse (test, strlen (test));
  //printf ("toto\n");
}
