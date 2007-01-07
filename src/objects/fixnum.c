/* fixnum.c - Definitions on fixnums (long, int, short) ...
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



#include "fixnum.h"
#include "symbol.h"
#include "../memory/memory.h"
//#include "type.h"
#include "../compiler/type.h"
#include <string.h>
#include "namespace.h"


struct base_type __type_int_object_;

const Type __type_int_object = &__type_int_object_;

struct base_type __type_bool_;

const Type __type_bool = &__type_bool_;

struct base_type __type_type_;

const Type __type_type = &__type_type_;

struct base_type __type_void_;

const Type __type_void = &__type_void_;



extern symbol_table_t l_symbol_table;

#if 0
static void
write_int_object (object_t int_)
{
  DEBUG_CHECK_TYPE (int_, int_object);
  int_object_t int_object = int_;
  printf ("%d", int_object->value);
}

static void
create_int_object (location_t location, pair_t args)
{
  DEBUG_CHECK_TYPE (args, pair);

  location->type = TYPE (int_object);
  
  if (args)
    {
      assert (args->next == NULL);
      int_object_t io = (int_object_t) args->car;
      DEBUG_CHECK_TYPE (io, int_object);
      int *loc = xmalloc (sizeof (int));
      *loc = io->value;
      location->location = loc;
    }
}
#endif


void
init_int_object (void)
{
  char *string = strdup ("int");
  
  symbol_t int_object = intern_into (string, l_namespace);
  // location_t loc = create_location (int_object, global_location_table);
  //  loc->type = TYPE (type);
  //  loc->location = __type_int_object;
  //__type_int_object_.name = int_object;
  //  __type_int_object_.writer = write_int_object;
  //__type_int_object_.size = sizeof (int);
  //__type_int_object_.creater = create_int_object;
}
