/* global.h - Handling of global symbols.
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

/* A hash Symbol -> Global.  */
extern hash_table_t global_hash;

/* The global ID name space has the global values, the constant
   values, the thread local values...
   
   Maybe these will be only type qualifiers at the end.

   This is for use only in the backends, and in expand_id.  */
typedef enum { NORMAL_GLOBAL,
               CONSTANT_GLOBAL,
               THREAD_LOCAL_GLOBAL } global_type_t;

typedef struct global
{
  global_type_t global_type;
  Type type;

  /* Which backend has compiled this global.  Later, we will use this
     for one backend to be able to use globals created in different
     backends.   */
  void *handling_backend;

  /* Backend-specific info.  */
  void *for_backend;
} *global_t;


#endif
