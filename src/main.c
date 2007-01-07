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

//typedef void (*void_to_void_t)(void);
typedef int (*void_to_int_t)(void);

extern hash_table_t function_hash;

int
main (int argc, char **argv)
{
  init ();

  assert (argc > 1);

  list_t form_list = parse_file (argv[1]);

  FOREACH (element, form_list)
    {
      form_t form = CAR (element);
      lispify (form);//write_form_to_xml (form);
    }

  list_t to_compile = analyze (form_list);
  
  FOREACH (element, to_compile)
    {
      form_t form = CAR (element);
      //write_form_to_xml (form);
      expanded_form_t expand_info = expand(form);

      /* XXX: strip the expanded form.  */
      form_t expanded_form = expand_info->return_form;

      printf("EXPANDED FORM\n");
      lispify(expand_info);
      generate (expanded_form);
    }

  //  function_t odd_function = symbol_value (SYMBOL (odd));
  function_t test_function = gethash (SYMBOL (test), function_hash);//symbol_value (SYMBOL (test));

  function_t toto_function = gethash (SYMBOL (fact), function_hash);
  //  function_t odd_function = symbol_value (SYMBOL (odd));
  void_to_int_t test = test_function->address;
  
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
