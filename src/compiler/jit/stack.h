/* stack.h - Stack management.
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

#ifndef _STACK_H
#define _STACK_H

extern int min_offset_used;

typedef struct memory_block
{
  int offset;
  unsigned int size;

  /* To change the next of the previous memory block.  */
  struct memory_block **previous_next;

  
  struct memory_block *next;
} * memory_block_t;

void
reinit_stack ();

void
free_memory_block (memory_block_t block);

memory_block_t
allocate_memory_block (unsigned int size);


#endif
