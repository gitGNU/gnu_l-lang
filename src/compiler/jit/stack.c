/* stack.c - Stack management.
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

#include "stack.h"
#include "../../objects/pair.h"
#include "../../memory/memory.h"
#include <assert.h>
#include "lightning-extended.h"

int min_offset_used;
//static int current_offset;

#define NULL ((void *) 0)

/* The free blocks of memory.  Sorted by offset (the stack grows
   downward, top of the stack first).  */
static memory_block_t free_list = NULL;

/* The used blocks of memory.  Does not need to be sorted, so it is
   not.  XXX: in fact the used list is useless, except for checking
   that everything is freed at the end.  */
static memory_block_t used_list = NULL;


void
reinit_stack ()
{
  // min_offset_used = 0;
  min_offset_used = JITE_OFFSET_FROM_LOCAL_ARG;
};

/* Stack is allocated using first fit; because most of the elements
   used are of sizeof(word) size,


   Fit means fit both the size and alignement constraints. */


void
free_memory_block (memory_block_t block)
{
  /* XXX: merge with the previous and the following.  Our stack grows
     too much.  */
  
  /* Remove ourselves from the used list.  */
  *(block->previous_next) = block->next;


  if(free_list == NULL)
    {
      free_list = block;
      block->previous_next = &free_list;
      block->next = NULL;
      return;
    }
  
  memory_block_t cur;
  
  for(cur = free_list; cur; cur = cur->next)
    {
      if(block->offset < cur->offset)
	{
	  /* Free blocks cannot have shared memory.  */
	  assert (cur->offset - cur->size >= block->offset);

	  if (cur->offset - cur->size == block->offset)
	    {
	      /* Merge the blocks.  */
	      cur->size += block->size;
	      xfree (block);
	      return;
	    }
	  else
	    {
	      /* Insert the block in the block list.  */
	      block->next = cur;
	      *(cur->previous_next) = block;
	      return;
	    }
	}
    }

  /* We are at the bottom of the queue.  */
  cur->next = block;
  block->next = NULL;
}


memory_block_t
allocate_memory_block (unsigned int size)
{
  assert ((size & (sizeof(int) - 1)) == 0); /* Size must be a multiple
					     of four for now.  */

  for(memory_block_t block  = free_list; block; block = block->next)
  /* XXX: alignement constraints.  */
    {
      if(block->size >= size)
	{
	  memory_block_t mb;
	  if(block->size == size)
	    {
	      *(block->previous_next) = block->next;
	      
	      mb = block;
		}
	  else
	    {
	      mb = MALLOC (memory_block);
	      mb->offset = block->offset;
	      mb->size = size;
	      
	      block->size -= size;
	      block->offset -= size;
	    }
	  
	  mb->next = used_list;
	  mb->previous_next = &used_list;
	  used_list = mb;
	  
	  return mb;
	}
    }

  /* Allocate a new block.  */
  memory_block_t mb = MALLOC (memory_block);

  /* Asserts that the stack grows downward.  */
  mb->offset = min_offset_used - size;
  mb->size = size;

  mb->next = used_list;
  mb->previous_next = &used_list;
  used_list = mb;
  
  min_offset_used -= size;
  
  return mb;
}


#if 0
/* Unit testing.  */
void
unit_test ()
{
  memory_block_t mb1 = allocate_memory_block (4);
  memory_block_t mb2 = allocate_memory_block (4);
  memory_block_t mb3 = allocate_memory_block (4);
  memory_block_t mb4 = allocate_memory_block (4);
  memory_block_t mb5 = allocate_memory_block (4);

  free_memory_block (mb1);

  memory_block_t mb6 = allocate_memory_block (4);

  assert (free_list == NULL);

  free_memory_block (mb5);

  free_memory_block (mb3);
  free_memory_block (mb4);
  
}
#endif


/* Before, I had forced a certain disposition for the stack :

   stack = |stack_frame1|stack_frame2|stack_frame3|
   stack_frame = |auto variables|temp locations|

   I don't remember what probleme there was with it. 

   It simplifies the conditionals?
   */
