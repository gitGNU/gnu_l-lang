/* analysis.c - Generic pre-analysis
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


/* This code handle all the processing needed before compiling can
   begin. For example:

   - Type definitions, and relationship
   - Function definition
   - Overload definition
   - Class definition
   - Generic definition
   - Parse definition ...

*/   




/* XXX: type definitions should be treated here.  */

/* XXX: also here should be recorded the association generic =>
   function + type of the function.  */


/* Associate to each defined generic a type.  Returns a list of forms
   to compile. (i.e. a list of (define function ... ), the rest is
   stripped.  Or maybe we should have another generic to enclose form
   generation in it.)  */

#include <assert.h>

#include <l/string.h>

#include "../objects/pair.h"
#include "../objects/function.h"
#include "../parser/form.h"

#include "c-to-l.h"
#include "analysis.h"

#include <l/sys/panic.h>
#include <l/sys/global.h>
#include <l/access.h>
#include <l/creator.h>



void
init_analysis ()
{
  define_type_string ("Int", sizeof(int), __alignof__ (int), NULL);
  define_type_string ("Bool", sizeof(int), __alignof__ (int), NULL); 
  define_type_string ("Type", sizeof(int), __alignof__ (int), NULL);
  define_type_string ("Function", sizeof(int), __alignof__ (int), NULL);
  define_type_string ("Symbol", sizeof(int), __alignof__ (int), NULL);
  define_type_string ("String", sizeof(int), __alignof__ (int), NULL);

  /* Label should have a type of -1, like functions, but for now
     we need them to be of size 0.  */
  define_type_string ("Label", 0, 0, NULL);

    /* XXX: void is not really the () type : because we allow (int) to
     coerce into void? Or is it? */
  //define_type_string ("Void", -1, -1, NULL); /* Void has no size.  */
  eval_cstring( "type_alias Void = ();");

}
