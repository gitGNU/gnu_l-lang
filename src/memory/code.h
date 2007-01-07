/* code.h - Memory management routines for code production.
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

#ifndef _CODE_H
#define _CODE_H

/* Every file in the project shouldn't include lightning.h except by
   using this file. */
#include <lightning.h>

extern jit_state _lightning_ip_ptr;
#define _jit _lightning_ip_ptr


/* Allocate room for code and set the IP pointer */
void *
allocate_code_space (size_t size);

/* Realloc (downsize) and flush the code region.  */
void
finish_code (void *ptr);

#endif
