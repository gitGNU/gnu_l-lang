/* string.h - String handling.
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

#ifndef _L_STRING_H
#define _L_STRING_H

#include <l/type.h>

typedef struct string
{
  unsigned int length;
  char content[0];
} *string_t;

typedef string_t String;

#include <string.h>

/* Creates a L String from a C char *.  */
static inline String
make_heap_string (const char *chars)
{
  unsigned int str_len = strlen (chars);
  String string = xmalloc (str_len + sizeof(struct string));
  string->length = str_len;
  memcpy (string->content, chars, str_len);
  return string;
}


/* Creates a L String from the first N strings a C char *.  */
static inline String
maken_heap_string (const char *chars, unsigned int n)
{
  String string = xmalloc (n + sizeof(struct string));
  string->length = n;
  memcpy (string->content, chars, n);
  return string;
}



extern const Type __type_string;

#endif
