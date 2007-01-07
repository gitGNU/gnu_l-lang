/* memory.c - Memory management operations.
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

#include <error.h>
#include <string.h>
#include <stdlib.h>

void *
xmalloc (size_t size)
{
  void * ptr = malloc (size);
  if (ptr == NULL)
    error (1, 1 , "Not enough memory for size %d\n",size);
  memset (ptr, -1, size); 	/* Pour detecter les trucs non initialises.  */
  return ptr;
}


void *
xrealloc (void *ptr, size_t size)
{
  void * newptr = realloc (ptr, size);
  if (newptr == NULL)
    error (1, 1 , "Not enough memory or realloc error.\n");
  /*  memset (ptr, -1, size);*/ 	
  return newptr;
}

void *
xfree (void *ptr)
{
  if(ptr == (void *) 0x8065ac0)
    asm("int $3");
  printf ("Freeing %p\n", ptr);
  free (ptr);
}
