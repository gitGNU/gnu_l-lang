/* code.c - Memory management routines for code production.
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

#include "memory.h"
#include "code.h"

jit_state _lightning_ip_ptr;
#define _jit _lightning_ip_ptr


/* Allocate room for code and set the IP pointer */
void *
allocate_code_space (size_t size)
{
  jit_insn* code_buffer = xmalloc (size);
  void *ret = jit_set_ip (code_buffer).ptr;

  return ret;
}

/* Realloc (downsize) and flush the code region.  */
void
finish_code (void *ptr)
{
  // printf ("ptr %p JIT_GET_IP.ptr %p diff %x\n", ptr, jit_get_ip ().ptr,
  //	  (char *) jit_get_ip ().ptr - (char *) ptr);
  jit_flush_code (ptr, jit_get_ip ().ptr);
  xrealloc (ptr, (char *) jit_get_ip ().ptr - (char *) ptr);
}
