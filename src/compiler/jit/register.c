/* register-allocation.c - 
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

/* This register allocator is really simple and doesn't even associate
   frequently used variables with a register.

   Its goal is rather to give free registers for storing intermediate
   results in.  For instance, (a + b) * (c + d) need to store the
   result of (a + b) while computing (c + d).  These temporary results
   are stored preferably in registers.

   Spilling is also handled here.  */


/* http://graphics.stanford.edu/~seander/bithacks.html */

#include "register.h"

struct location *register_locations[DATA_REGISTER_NUMBER];

/* Used to control that the register was really allocated.  */
static unsigned int used_data_registers;
static unsigned int used_fp_registers;

//static list_t free_registers;

//static inline int
//is_caller_saved (register_t reg) {return (1 << reg) & 7;}

unsigned int register_lru_counter[DATA_REGISTER_NUMBER];

static int lru_counter = 0;


register_t
allocate_free_data_register (void)//unsigned int constraint, unsigned int preference)
{
  /* http://graphics.stanford.edu/~seander/bithacks.html */
  register unsigned int v = ~used_data_registers;

  if(!v)
    return REG_NO_REGISTER;
  
  register unsigned int r = 0; // result of log2(v) will go here
  
  if (v & 0xF0) { v >>= 4; r |= 4; } 
  if (v & 0x0C) { v >>= 2; r |= 2; } 
  if (v & 0x02) { v >>= 1; r |= 1; }

  /* Set the found bit.  */
  assert (!(used_data_registers & (1 << r)));
  used_data_registers |= (1 << r);
  assert (r != REG_RET && r != REG_FP);
  assert (r != REG_R0 && r != REG_R1 && r != REG_R2);

  printf ("REGISTER USED: %d\n", r);

  register_lru_counter[r] = ++lru_counter;
  assert (register_locations[r] == NULL);
  return r;
}

void
allocate_data_register (register_t reg)
{
  /* XXX: handle them separately . */
  if(reg == REG_FP || reg == REG_RET)
    return;

  printf ("REGISTER USED (forced): %d\n", reg);
  //  panic ("Allocate data register\n");
  assert (!(used_data_registers & (1 << reg)));
  used_data_registers |= (1 << reg);

  register_lru_counter[reg] = ++lru_counter;
  assert (register_locations[reg] == NULL);
}

void
free_data_register (register_t reg)
{
  assert (register_locations[reg] == NULL);
  assert (reg != REG_RET && reg != REG_FP);
  assert (used_data_registers & (1 << reg));
  used_data_registers &= ~(1 << reg);

  assert (reg != -1);
  printf ("REGISTER FREED: %d\n", reg);

  register_lru_counter[reg] = ~0;
}

void
reinit_registers (void)
{
  used_data_registers = ~0;
  used_data_registers &= ~((1 << REG_V0) | (1 << REG_V1) | (1 << REG_V2));
  //  used_data_registers &= ~((1 << REG_R0) | (1 << REG_R1) | (1 << REG_R2));
  used_fp_registers = 0;

  for(int i = 0; i < DATA_REGISTER_NUMBER; i++)
    {
      register_locations[i] = NULL;
      register_lru_counter[i] = ~0;
    }

  lru_counter = 0;
}

register_t
choose_register_to_spill (void)
{
  assert (used_data_registers & (1 << REG_V0));
  assert (used_data_registers & (1 << REG_V1));
  assert (used_data_registers & (1 << REG_V2));
  
  register_t lowest_index = 0;
  unsigned int lowest = register_lru_counter[0];
  /* Takes the lowest number */
  for(int i = 1; i < DATA_REGISTER_NUMBER; i++)
    {
      if(register_lru_counter[i] < lowest)
	{
	  lowest_index = i;
	  lowest = register_lru_counter[i];
	}
    }

  //  free_data_register (lowest_index);
  
  return lowest_index;
}

void
reuse_register (register_t reg)
{
  register_lru_counter[reg] = ++lru_counter;
}



/* The stack of used spilling vars.

   More than one element can be freed at once, this is useful e.g. for
   functions.
 */
