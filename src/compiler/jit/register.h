/* register.h - 
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

#ifndef _REGISTER_H
#define _REGISTER_H

#include "../../memory/code.h"
#include <assert.h>

typedef enum { REG_NO_REGISTER = -1,
	       REG_R0 = 0, REG_R1 = 1, REG_R2 = 2,
	       REG_V0 = 3, REG_V1 = 4, REG_V2 = 5,
	       REG_FP = 6, REG_RET = 7, DATA_REGISTER_NUMBER = 6, LAST_REG_NUMBER = 7 } register_t_;

#define register_t register_t_

static const int corresponding_register[] = { JIT_R0, JIT_R1, JIT_R2,
					      JIT_V0, JIT_V1, JIT_V2,
					      JIT_FP, JIT_RET
};


/* The locations using the registers have to put here the fact that
   they use the register.  */
extern struct location *register_locations[DATA_REGISTER_NUMBER];

static inline int
is_caller_saved (register_t reg) {return (1 << reg) & 7;}

register_t
allocate_free_data_register (void);

void
allocate_data_register (register_t reg);

void
free_data_register (register_t reg);

void
reinit_registers (void);

register_t
choose_register_to_spill (void);

/* Use when you reuse a register and change its content.  */
void
reuse_register (register_t reg);

#endif
