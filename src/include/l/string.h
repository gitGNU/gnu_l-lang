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

#include "../../memory/memory.h"

/* Having the content of the string not coded in it allows for sharing
   of substrings.  But beware of memory reclamation!  I suggest that
   Strings should use a special-purpose String garbage collector
   designed to cope with this problem.  */
typedef struct string
{
  unsigned int length;
  char *content;
  //  char content[0];
} *string_t;

typedef string_t String;

#include <string.h>

/* Creates a L String from a C char *.  */
static inline String
make_heap_string (const char *chars)
{
  unsigned int str_len = strlen (chars);

  /* For compatibility with C, we still put a trailing 0.  */
  String string = xmalloc (str_len + sizeof(struct string) + 1);
  char *string_start = (char *) string  + sizeof(struct string);
  string->length = str_len;
  string->content = string_start;
  memcpy (string_start, chars, str_len + 1);
  return string;
}


/* Creates a L String from the first N strings a C char *.  */
static inline String
maken_heap_string (const char *chars, unsigned int n)
{
  String string = xmalloc (n + sizeof(struct string) + 1);
  char *string_start = (char *) string  + sizeof(struct string);
  string->length = n;
  string->content = string_start;
  memcpy (string_start, chars, n);
  /* Only for compatibility.  */
  string_start[n] = 0;
  return string;
}


/* Creates a wrapper string arounds a given string, for use in C
   programs.  */
#define STRING( c)				\
  (&(struct string){strlen( c), c})


/* Creates a C string from a L string.  Must be explicitly freed.  */
static inline char*
make_C_string_from_L_string (String s)
{
  char *cs = malloc (s->length + 1);
  memcpy (cs, s->content, s->length);
  cs[s->length] = 0;
  return cs;
}

#endif
