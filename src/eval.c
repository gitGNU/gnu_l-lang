/* eval.c - Evaluates a code string.
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


/* Eval performs the necessary actions from the code:
   - Defined objects are added to the objects known to L
   - Top level code is evaluated
   etc.  */

#include <l/string.h>
#include "objects/pair.h"
#include "parser/parse.h"
#include <assert.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

list_t
parse_file( char *file_name)
{
  unsigned int fd = open (file_name, O_RDONLY);
  struct stat the_stat;

  stat (file_name, &the_stat);
  off_t length_ = the_stat.st_size;

  char *string = mmap (0, length_, PROT_READ, MAP_SHARED, fd, 0);

  /* XXX: for now, make arrangements so that the string is zero
     terminated.  This copies the buffer.  */
  assert (string != (void *) -1);

  String s = make_heap_string (string);

  list_t form_list = parse( s);
  
  munmap (string, length_);
  close (fd);
  return form_list;
}

list_t
expand_form_list( list_t to_compile)
{
  return expand_all( to_compile);
#if 0  
  /* Now, expand all forms.

     Here also, expand should take a form list as an argument; this
     allows non-linear definitions.
     */
  list_t expanded_form_list;

  {
    list_t *expanded_form_list_ptr = &expanded_form_list;
    
    FOREACH (element, to_compile)
      {
	form_t form = CAR (element);
	expanded_form_t expanded_form = expand_define(form);
	
	//	form_t expanded_form = expand_info->return_form;
	*expanded_form_list_ptr = CONS (expanded_form->return_form, NULL);
	expanded_form_list_ptr = &((*expanded_form_list_ptr)->next);
      }

    *expanded_form_list_ptr = NULL;
  }
  return expanded_form_list;
  #endif
}

void
generate_list( list_t expanded_form_list)
{
  /* Now, compiles all the created forms.  Same as before: should take
     a form list as an argument.
  */
  FOREACH (element, expanded_form_list)
    {
      form_t form = CAR (element);
      //      lispify (form);
      generate (form);
    }  
}


void
eval_file (char *file_name)
{
  list_t form_list = parse_file( file_name);

  list_t to_compile = analyze (form_list);
  
  list_t expanded_form_list = expand_form_list( to_compile);

  generate_list( expanded_form_list);
}

void
eval (String s)
{
  /* First run the parser.  */
  list_t form_list = parse (s);

  /* Launch the analyzer.  But this is wrong.  We should just launch
     the cocyte compiler on the form list after expansion and
     transformation. The cocyte compiler would know only type
     declarations and function definitions.

     One of the transformations would be to put top level forms into a
     temporary function to execute it.  */
     
  list_t to_compile = analyze (form_list);
  

  list_t expanded_form_list = expand_form_list( to_compile);

  generate_list( expanded_form_list);

}

/* This is useful from C code.  */
void
eval_cstring (char *string)
{
  eval (make_heap_string (string));
}
