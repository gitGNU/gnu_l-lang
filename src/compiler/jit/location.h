/* location.h - 
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

#ifndef _LOCATION_H
#define _LOCATION_H

#include "low-location.h"
#include "../../objects/pair.h"

#if 0
struct location
{
  /* Type is the first element, this is important for LOCATION_TYPE to
     work.  */
  type_t type;

  int ref_count;

  union
  {
    struct
    {
      unsigned int automatic_variable : 1;
      unsigned int compound_location : 1;
      unsigned int void_location: 1;
    };
    unsigned int all;
  };
  
  low_location_t low_location;

  union
  {
    /* For stack variables.  */
    struct memory_block *mb;

    /* For compound locations. */
    list_t location_alist;
  };
};
#endif


#endif
