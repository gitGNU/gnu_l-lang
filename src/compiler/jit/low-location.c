/* low-location.c - 
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

#include "low-location.h"
#include "../../memory/memory.h"

#include <l/sys/panic.h>

#define unimplemented(condition)				\
  do {if(condition) panic ("Unimplemented\n");} while(0)	\


/* XXX: use the same low location for each register.  */

low_location_t
register_location (register_t reg)
{
  allocate_data_register (reg);
  
  low_location_t ll = MALLOC (low_location);
  ll->location_type = REGISTER;
  ll->reg = reg;

  return ll;
}

low_location_t
function_argument (unsigned int number)
{
  low_location_t ll = MALLOC (low_location);
  ll->location_type = FUNCTION_PARAMETER;
  ll->parameter_number = number;

  return ll;
}

low_location_t
any_register_location (void)
{
  register_t reg = allocate_free_data_register ();

  if(reg == REG_NO_REGISTER)
    {
      reg = choose_register_to_spill ();
      spill (reg);

      allocate_data_register (reg);
      //      panic ("Implement choose register to _spill\n");
      //      register_t reg = choose_register_to_spill ();
      //      spill (reg);
      
      //     panic ("Spilling is needed\n");
//      spill (the_reg--);
//      if(the_reg < REG_V0)
//	the_reg = REG_V2;
//
//      reg = allocate_free_data_register ();
//
//      assert (reg = the_reg);
    }
  
  low_location_t ll = MALLOC (low_location);
  ll->location_type = REGISTER;
  ll->reg = reg;

  return ll;
}

low_location_t
constant_value_location (unsigned int value)
{
  low_location_t ll = MALLOC (low_location);
  ll->location_type = CONSTANT;
  ll->value = value;

  return ll;
}

low_location_t
stack_low_location (int offset)
{
  return indirection (offset, register_location (REG_FP));
}
		   

low_location_t
indirection (int offset, low_location_t loc)
{
  low_location_t ll = MALLOC (low_location);
  ll->flags = 0;
  ll->location_type = INDIRECTION;
  ll->loc = loc;
  ll->offset = offset;
  ll->constant_offset = 1;
  ll->offset_reg = REG_NO_REGISTER;
  
  return ll;
}

low_location_t
registerize (low_location_t loc);


void
move_between_low_locations_register_indirection (low_location_t from,
						 low_location_t to)
{
  assert (from->location_type == REGISTER);
  assert (to->location_type == INDIRECTION);

  //  unimplemented (to->loc->location_type != REGISTER);
  unimplemented (to->register_offset);
  unimplemented (!to->constant_offset);
  
  if(to->loc->location_type == REGISTER)
    {
      if(to->constant_offset)
	{
	  jit_stxi_ui (to->offset, corresponding_register[to->loc->reg],
		       corresponding_register[from->reg]);
	}
    }
  else
    {
      low_location_t l2 = registerize(to->loc);
      assert(to->constant_offset);
      jit_stxi_ui (to->offset, corresponding_register[l2->reg],
		   corresponding_register[from->reg]);
      assert(l2->reg != from->reg);
      free_data_register(l2->reg);
    }
}

static void
move_between_low_locations_register_register (low_location_t from,
					      low_location_t to)
{
  jit_movr_ui (corresponding_register[to->reg],
	       corresponding_register[from->reg]);
}

static void
move_between_low_locations_register_any (low_location_t from,
					 low_location_t to)
{
  assert (from->location_type == REGISTER);
  assert (to->location_type != CONSTANT);
  
  switch(to->location_type)
    {
    case REGISTER:
      move_between_low_locations_register_register (from, to);
      break;

    case INDIRECTION:
      move_between_low_locations_register_indirection (from, to);
      break;
      
      //    case INDIRECTION: unimplemen
      //      break;

    default: unimplemented (1);
    }
}


static void
move_between_low_locations_constant_register (low_location_t from,
					      low_location_t to)
{
   assert (from->location_type == CONSTANT);
   assert (to->location_type == REGISTER);

   jit_movi_ui (corresponding_register[to->reg], from->value);
}

static void
move_between_low_locations_constant_indirection (low_location_t from,
						 low_location_t to)
{
  assert (from->location_type == CONSTANT);
  assert (to->location_type == INDIRECTION);

  low_location_t reg = any_register_location ();

  move_between_low_locations_constant_register (from, reg);
  move_between_low_locations_register_indirection (reg, to);

  free_data_register (reg->reg);
}

static void
move_between_low_locations_constant_any (low_location_t from,
					 low_location_t to)
{
  assert (from->location_type == CONSTANT);

  assert (to->location_type == REGISTER || to->location_type == INDIRECTION);

  if(to->location_type == REGISTER)
    move_between_low_locations_constant_register (from, to);
  else
    move_between_low_locations_constant_indirection (from, to);
}

static void
move_between_low_locations_indirection_register (low_location_t from,
						 low_location_t to)
{
   assert (from->location_type == INDIRECTION);
   assert (to->location_type == REGISTER);
   assert (to->reg > 0 && to->reg <= LAST_REG_NUMBER);
   
   unimplemented (from->constant_offset != 1);
   unimplemented (from->register_offset);

   if(from->loc->location_type == REGISTER)
     {
       jit_ldxi_ui (corresponding_register[to->reg],
		    corresponding_register[from->loc->reg],
		    from->offset);
     }
   else
     {
       //       assert (from->loc->location_type == INDIRECTION);
       /* We reuse the to register.  */
       move_between_low_locations_any_register (from->loc, to);
       move_between_low_locations_indirection_register (indirection (from->offset, to),
							to);
     }
}


static void
move_between_low_locations_indirection_any (low_location_t from,
					    low_location_t to)
{
   assert (from->location_type == INDIRECTION);
   
   //   unimplemented (from->loc->location_type != REGISTER);
   unimplemented (from->constant_offset != 1);
   unimplemented (from->register_offset);

   if(to->location_type == REGISTER)
     {
       move_between_low_locations_indirection_register (from, to);
     }
   else
     {
       low_location_t loc = any_register_location ();
       move_between_low_locations_indirection_register (from, loc);
       move_between_low_locations_register_any (loc, to);
       free_data_register (loc->reg);
     }
//   
//   jit_ldxi_ui (corresponding_register[to->reg],
//		corresponding_register[from->loc->reg],
//		from->offset);
}

static void
move_between_low_locations_funparm_register (low_location_t from,
					     low_location_t to)
{
  assert (from->location_type == FUNCTION_PARAMETER);
  assert (to->location_type == REGISTER);
  jit_getarg_ui (corresponding_register[to->reg], from->parameter_number);
}

static void
move_between_low_locations_funparm_any (low_location_t from,
					low_location_t to)
{
  assert (from->location_type == FUNCTION_PARAMETER);

  if(to->location_type == REGISTER)
    move_between_low_locations_funparm_register (from, to);
  else
    {
      assert (to->location_type == INDIRECTION);
      low_location_t reg = any_register_location ();

      move_between_low_locations_funparm_register (from, reg);
      move_between_low_locations_register_indirection (reg, to);
      free_data_register (reg->reg);
    }
}

void
move_between_low_locations_any_register (low_location_t from,
					 low_location_t to)
{
  assert (to->location_type == REGISTER);

  switch(from->location_type)
    {
    case REGISTER:
      move_between_low_locations_register_register (from, to);
      break;

    case INDIRECTION:
      move_between_low_locations_indirection_register (from, to);
      break;

    case FUNCTION_PARAMETER:
      move_between_low_locations_funparm_register (from, to);
      break;

    case CONSTANT:
      move_between_low_locations_constant_register (from, to);
      break;
      
    default: panic ("error\n");
    }
}

#define compile_error panic

void
move_between_low_locations (low_location_t from, low_location_t to)
{
  if(to->location_type == CONSTANT)
    compile_error ("Cannot move value to a constant.\n");

  if(to->location_type == FUNCTION_PARAMETER)
    compile_error ("Moving to an argument not implemented yet.\n");
     
  if(from->location_type == CONSTANT)
    move_between_low_locations_constant_any (from, to);
  else if(from->location_type == REGISTER)
    move_between_low_locations_register_any (from, to);
  else if(from->location_type == INDIRECTION)
    move_between_low_locations_indirection_any (from, to);
  else if (from->location_type == FUNCTION_PARAMETER)
    move_between_low_locations_funparm_any (from, to);
    
  else panic ("Unimplemented\n");
}

/* Be careful and watch if your calls to registerize should set
   register_location too.  */
low_location_t
registerize (low_location_t loc)
{
  if(loc->location_type == REGISTER)
    panic ("Here\n");

  low_location_t l2 = any_register_location ();

  assert (l2->reg != REG_NO_REGISTER);

  if(loc->location_type == CONSTANT)
    move_between_low_locations_constant_register (loc, l2);
  else if(loc->location_type == INDIRECTION)
    move_between_low_locations_indirection_register (loc, l2);
  else
    {
      assert (loc->location_type == FUNCTION_PARAMETER);
      move_between_low_locations_funparm_register (loc, l2);
    }

  return l2;
}



#if 0
move_between_locations


low_location_t
allocate_stack_variable ()
{
  
}
  
low_location_t
allocate_temp_result ()
{
  
}
#endif
