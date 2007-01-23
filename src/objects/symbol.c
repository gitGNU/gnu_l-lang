/* symbol.c - Operations on symbol objects.
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

#include "symbol.h"
#include "../memory/memory.h"
#include <string.h>
#include "namespace.h"
#include "hash.h"

static unsigned int sym_nb = 0;

symbol_t
gensym(char *root)
{
  char *mem = malloc(strlen(root) + 11);
  sprintf(mem, "#%s%d", root, sym_nb++);

  return intern(mem);
}
