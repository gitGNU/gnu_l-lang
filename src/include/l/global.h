/* global.h - Interface to global values
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

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <l/sys/global.h>

/* Note: the current gestion of the globals is bad.  Globals should
   apply to all things that have a global name, and should be
   differenciated by a "definer type".  For instance, a grammar, an
   expander, etc... are globals.

   Some globals of different definer types can have the same name and
   some can't. Thus definer types should be grouped together.

   To prevent name clashesd, "modules" should help protecting distinct
   names. These modules are just different namespaces.
*/

typedef struct global
{
  global_type_t global_type;

  union {
    /* Address of the global, for global variables. We put it first so as
     not to have offset calculation for getting it, when the global is
     used dynamically in PIC code.  */
    void *address;

    /* Form by which the constant is replaced, for constant values.  */
    expanded_form_t expression;

    void *param1;
  };

  union
  {
    /* Type of the global, when it is a global variable. */
    Type type;

    void *param2;
  };
} *global_t;



static inline void*
get_global( Symbol name)
{
  global_t glob = gethash( name, global_hash);
  return glob;
}

/* If there is no address, use NULL.  */
void
define_global_variable( Symbol name, Type type, void *address);

#endif
