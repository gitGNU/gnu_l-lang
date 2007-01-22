/* operations.c - Standard operations
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


#include <Judy.h>
#include "../../objects/symbol.h"
#include "../../memory/code.h"
#include "../backend.h"
#include "lightning-extended.h"
#include "../../objects/function.h"
#include "low-location.h"
#include "location.h"

#include <l/sys/panic.h>

/* Else, we would have to transform it into a temp location.  */
static inline void
assert_is_temp_location (location_t loc)
{
  //  assert (loc->all == 0);
  assert (loc->automatic_variable == 0 && loc->compound_location == 0);
}


#if 0
//The code for addition is left to see and modify.  */

static inline int
add_int_constant_constant (unsigned int value1, unsigned int value2)
{
  return (int) value1 + (int) value2;
}

static inline void
add_int_constant_register (int value1, register_t reg2)
{
  jit_addi_i (corresponding_register[reg2],
	      corresponding_register[reg2],
	      value1);
}

static inline void
add_int_register_constant (register_t reg1, int value2)
{
  jit_addi_i (corresponding_register[reg1],
	      corresponding_register[reg1],
	      value2);
}


/* Additional argument is in which register should the result be put.  */
static inline void
add_int_register_register (register_t reg1, register_t reg2,
		       register_t where_result)
{
  assert (where_result == reg1 || where_result == reg2);
  jit_addr_i (corresponding_register[where_result],
	      corresponding_register[reg1],
	      corresponding_register[reg2]);
}

static location_t
add_int_locations_constant_any (location_t loc1, location_t loc2)
{
  assert (loc1->low_location->location_type == CONSTANT);

  int value1 = loc1->low_location->value;
  low_location_t low_loc2 = loc2->low_location;
  
  switch(low_loc2->location_type)
    {
    case CONSTANT:
      return constant_value (TYPE ("Int")),
			     add_int_constant_constant (value1,
							low_loc2->value));
      
    case REGISTER:
      if(loc2->ref_count == 1)
	{
	  assert_is_temp_location (loc2);

	  /* The location won't be freed, and we reuse it.  */
	  loc2->ref_count++;

	  reuse_register (low_loc2->reg);
	  add_int_constant_register (value1, low_loc2->reg);
	  return loc2;
	}
      else
	{
	  panic ("Not implemented yet\n");
	} /* Todo when variables are in registers.  */
      
    default:
      {
	low_location_t reg2 = registerize (low_loc2);

	add_int_constant_register (value1, reg2->reg);

	location_t retloc = temporary_location (TYPE ("Int"), reg2);

	register_locations[reg2->reg] = retloc;

	return retloc;
      }
    }

  /* Never reached. */
  assert (1);
}

static location_t
add_int_locations_register_reuse_any (location_t loc1, location_t loc2)
{
  assert (loc1->ref_count == 1);

  /* Else transform it.  */
  assert_is_temp_location (loc1);

  register_t reg1 = loc1->low_location->reg;
  low_location_t low_loc2 = loc2->low_location;
  
  assert_is_temp_location (loc1);

  /* The location won't be freed, and we reuse it.  */
  loc1->ref_count++;
      
  reuse_register (reg1);

  switch(low_loc2->location_type)
    {
    case CONSTANT:
      add_int_register_constant (reg1, low_loc2->value);
      break;

    case REGISTER:
      add_int_register_register (reg1, low_loc2->reg, reg1);
      break;

    default:
      {
	low_location_t lreg2 = registerize (low_loc2);
	add_int_register_register (reg1, lreg2->reg, reg1);
	free_data_register (lreg2->reg);
      }
    }

  assert (loc1->type == TYPE ("Int"));
  return loc1;
}

static location_t
add_int_locations_register_any (location_t loc1, location_t loc2)
{
  if(loc1->ref_count == 1)
    {
      return add_int_locations_register_reuse_any (loc1, loc2);
    }
  else panic ("Not yet implemented\n");
}

location_t
add_int_locations (location_t loc1, location_t loc2)
{
  switch(loc1->low_location->location_type)
    {
    case CONSTANT:
      return add_int_locations_constant_any (loc1, loc2);

    case REGISTER:
      return add_int_locations_register_any (loc1, loc2);

    default:
      {
	low_location_t low_loc= registerize (loc1->low_location);
	location_t new_loc = temporary_location (TYPE ("Int"), low_loc);

	add_int_locations_register_reuse_any (new_loc, loc2);
	
	assert (new_loc->ref_count == 2);
	new_loc->ref_count = 1;

	register_locations[low_loc->reg] = new_loc;
	
	return new_loc;
      }
    }
}



#endif



#define DEFINE_INT_OPERATION_SEMI_COMMUTATIVE(name1, name_reverse)	\
static inline void							\
name1##_int_constant_register (int value1, register_t reg2)		\
{									\
  jit_##name_reverse##i_i (corresponding_register[reg2],		\
	      corresponding_register[reg2],				\
	      value1);							\
}									\
									\
static inline void							\
name1##_int_register_constant (register_t reg1, int value2)		\
{									\
  jit_##name1##i_i (corresponding_register[reg1],			\
	      corresponding_register[reg1],				\
	      value2);							\
}									\
									\
									\
/* Additional argument is in which register should the result be put.  */ \
static inline void							\
name1##_int_register_register (register_t reg1, register_t reg2,	\
		       register_t where_result)				\
{									\
  assert (where_result == reg1 || where_result == reg2);		\
  assert (where_result == reg1); /* For the moment.  */			\
  jit_##name1##r_i (corresponding_register[where_result],		\
	      corresponding_register[reg1],				\
	      corresponding_register[reg2]);				\
}

#define DEFINE_INT_OPERATION_COMMUTATIVE(name)		\
  DEFINE_INT_OPERATION_SEMI_COMMUTATIVE(name, name)



#define DEFINE_INT_OPERATION_FRONT(name_)                               \
static location_t							\
name_##_int_locations_constant_any (location_t loc1, location_t loc2)	\
{									\
  assert (loc1->low_location->location_type == CONSTANT);		\
									\
  int value1 = loc1->low_location->value;				\
  low_location_t low_loc2 = loc2->low_location;				\
									\
  switch(low_loc2->location_type)					\
    {									\
    case CONSTANT:							\
      return constant_value (TYPE ("Int"),				\
			     name_##_int_constant_constant (value1,	\
							low_loc2->value)); \
									\
    case REGISTER:							\
      if(loc2->ref_count == 1)						\
	{								\
	  assert_is_temp_location (loc2);				\
									\
	  /* The location won't be freed, and we reuse it.  */		\
	  loc2->ref_count++;						\
									\
	  reuse_register (low_loc2->reg);				\
	  name_##_int_constant_register (value1, low_loc2->reg);	\
	  return loc2;							\
	}								\
      else								\
	{								\
	  panic ("Not implemented yet\n");				\
	} /* Todo when variables are in registers.  */			\
									\
    default:								\
      {									\
	low_location_t reg2 = registerize (low_loc2);			\
									\
	name_##_int_constant_register (value1, reg2->reg);		\
									\
	location_t retloc = temporary_location (TYPE ("Int"), reg2); \
									\
	register_locations[reg2->reg] = retloc;				\
									\
	return retloc;							\
      }									\
    }									\
									\
  /* Never reached. */							\
  assert (1);								\
}									\
									\
static location_t							\
name_##_int_locations_register_reuse_any (location_t loc1, location_t loc2)	\
{									\
  assert (loc1->ref_count == 1);					\
									\
  /* Else transform it.  */						\
  assert_is_temp_location (loc1);					\
									\
  register_t reg1 = loc1->low_location->reg;				\
  low_location_t low_loc2 = loc2->low_location;				\
									\
  assert_is_temp_location (loc1);					\
									\
  /* The location won't be freed, and we reuse it.  */			\
  loc1->ref_count++;							\
									\
  reuse_register (reg1);						\
									\
  switch(low_loc2->location_type)					\
    {									\
    case CONSTANT:							\
      name_##_int_register_constant (reg1, low_loc2->value);		\
      break;								\
									\
    case REGISTER:							\
      name_##_int_register_register (reg1, low_loc2->reg, reg1);	\
      break;								\
									\
    default:								\
      {									\
	low_location_t lreg2 = registerize (low_loc2);			\
	name_##_int_register_register (reg1, lreg2->reg, reg1);		\
	free_data_register (lreg2->reg);				\
      }									\
    }									\
									\
  assert (loc1->type == TYPE ("Int"));				\
  return loc1;								\
}									\
									\
static location_t							\
name_##_int_locations_register_any (location_t loc1, location_t loc2)	\
{									\
  if(loc1->ref_count == 1)						\
    {									\
      return name_##_int_locations_register_reuse_any (loc1, loc2);	\
    }									\
  else panic ("Not yet implemented\n");					\
}									\
									\
location_t								\
name_##_int_locations (location_t loc1, location_t loc2)		\
{									\
  switch(loc1->low_location->location_type)				\
    {									\
    case CONSTANT:							\
      return name_##_int_locations_constant_any (loc1, loc2);		\
									\
    case REGISTER:							\
      return name_##_int_locations_register_any (loc1, loc2);		\
									\
    default:								\
      {									\
	low_location_t low_loc= registerize (loc1->low_location);	\
	location_t new_loc = temporary_location (TYPE ("Int"), low_loc); \
									\
	name_##_int_locations_register_reuse_any (new_loc, loc2);	\
									\
	assert (new_loc->ref_count == 2);				\
	new_loc->ref_count = 1;						\
									\
	register_locations[low_loc->reg] = new_loc;			\
									\
	return new_loc;							\
      }									\
    }									\
}

static inline int
add_int_constant_constant (unsigned int value1, unsigned int value2)
{
  return (int) value1 + (int) value2;
}
  
DEFINE_INT_OPERATION_COMMUTATIVE(add)
DEFINE_INT_OPERATION_FRONT (add)

static inline int
mul_int_constant_constant (unsigned int value1, unsigned int value2)
{
  return (int) value1 * (int) value2;
}


DEFINE_INT_OPERATION_COMMUTATIVE(mul)
DEFINE_INT_OPERATION_FRONT (mul)

/* XXX: for sub, ther exists rsb in lightning.  */
static inline int
sub_int_constant_constant (unsigned int value1, unsigned int value2)
{
  return (int) value1 - (int) value2;
}

DEFINE_INT_OPERATION_SEMI_COMMUTATIVE(sub, rsb)
DEFINE_INT_OPERATION_FRONT (sub)



static inline int
div_int_constant_constant (unsigned int value1, unsigned int value2)
{
  return (int) value1 / (int) value2;
}


