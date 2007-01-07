/* lightning-extended.h - Extensions to lightning
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

#ifndef _LIGHTNING_EXTENDED_H
#define _LIGHTNING_EXTENDED_H


/* Make sure lightning macros are already defined before these extensions */
#include <lightning.h>

#include <assert.h>


/* Extensions for framepointer management */
#ifndef JIT_FP
#error "Pour l'instant on ne fait que le x86"
#endif

#define JITE_FP JIT_FP


/* Offset to add between the start of FP and the first local variable
   on the stack.  */
#define JITE_OFFSET_FROM_LOCAL_ARG -12  




/* You may need to generate code very fast without having any
   analyzes, then you may need these macros that keep some space to be
   backwritten later.   */


/* Retain some spaces for some future (unknown yet) instructions  */
/* We put the reserved space in the first byte of the retained space
   and we return the address after.  */
/*  */
/* XXX: to be portable, we must do an inline function instead.  */
//#define jite_retain_space (size)
static inline
void *jite_retain_space (unsigned char size)
{
  unsigned char *start_ip = (unsigned char *) jit_get_ip ().cptr;
  assert (size > 0 && size < 255);
  *start_ip = size;
  /* XXX: check if size respect instruction alignement?  */
  jit_set_ip ((start_ip + size));
  return start_ip;
}


/* Dans instr, il faut essayer de mettre des "grandes operandes", si
   par exemple c'est des entiers, car les instructions peuvent prendre
   differentes taille en fonction de l'operande. */
/* Comment faire ca sans GNU C */
#define jite_retain_space_for(instr)		\
({						\
  unsigned char *start_ip = jit_get_ip ().cptr;	\
  instr;					\
  *start_ip = ((unsigned char *) jit_get_ip ().cptr - start_ip);	\
  start_ip;								\
 })


#define jite_occupy_space(pointer, instr)			\
{								\
  void *cur_ip = jit_get_ip ().ptr;				\
  unsigned char size = * (unsigned char *) pointer;		\
  jit_set_ip (pointer);						\
  instr;							\
  assert (jit_get_ip ().cptr <= (char *) pointer + size);	\
  while (jit_get_ip ().cptr < ((char *)pointer + size))		\
    {jit_nop ();} /* Fill with nop */				\
  assert (jit_get_ip ().cptr == (char *) pointer + size);	\
  jit_set_ip (cur_ip);						\
}
	  
	  
#endif
