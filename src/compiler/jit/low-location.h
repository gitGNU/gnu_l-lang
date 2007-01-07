/* low-location.h - 
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

#ifndef _LOW_LOCATION_H
#define _LOW_LOCATION_H

#include "register.h"

/* A low location is used only by one high location, so a counter
   isn't needed.  */

/* When registerizing or spilling, the high location should be
   affected.  How to do that efficiently?  We can either:
   - have a backpointer to the high location and change it.
   - or modify ourselves, thus keeping the pointer valid.
*/

/* Low locations are backend specific.  Here are the ones for jit.

   For C it would be totally different. */

/* The prime responsability of the low location management is to
   ensure that no data is ever corrupted (i.e. erased)  */


typedef enum { CONSTANT, INDIRECTION, REGISTER, FUNCTION_PARAMETER } low_location_type_t;

typedef struct low_location
{
  union {
    struct
    {
      unsigned int location_type : 4;
      
      /* If indirection has a constant offset.  XXX: we could always
	 have a constant offset, but sometimes it would be 0.*/
      unsigned int constant_offset : 1;
      
      /* If indirection has a register offset.  */
      unsigned int register_offset : 1;
    };
    unsigned int flags;
  };

  union
  {
    /* For constants.  */
    unsigned int value;

    /* For registers.  */
    register_t reg;

    /* For function parameter.  */
    int parameter_number;

    
    /* For indirections.  */
    struct
    {
      int offset;
      register_t offset_reg;
      struct low_location *loc;
    };
  };
  
} * low_location_t;


low_location_t
register_location (register_t reg);

low_location_t
constant_value_location (unsigned int value);

low_location_t
stack_low_location (int offset);

low_location_t
indirection (int offset, low_location_t loc);

low_location_t
function_argument (unsigned int number);

#endif

