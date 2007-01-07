/* link.c - Put the symbols at their right place
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


/* We group the linking information by function definition.  So, when
   a function is dismissed, all the related information is too.  */

/* When the symbol is already known, the ref is immediatly patched.
   In all case, the ref will be repatched every time the symbol is
   redefined.  */

#include <Judy.h>
#include "../../objects/hash.h"
#include "../../objects/pair.h"
#include "../../objects/symbol.h"
#include "../../memory/code.h"
#include "lightning-extended.h"
#include "../../objects/function.h"

#include <l/sys/panic.h>

MAKE_STATIC_HASH_TABLE (link_hash)
MAKE_STATIC_HASH_TABLE (symbol_address_hash)

void 
record_symbol_needed (symbol_t function_being_compiled,
                      void *ref,  /* Ref to patch.  */
		      symbol_t symbol)
{
  assert (symbol != ~0);
  hash_table_t symbol_link_hash = gethash (symbol, link_hash);
  if(symbol_link_hash == NULL)
    {
      symbol_link_hash = make_hash_table ();
      puthash (symbol, symbol_link_hash, link_hash);
    }
  
  list_t ref_list = gethash (function_being_compiled, symbol_link_hash);

  ref_list = CONS (ref, ref_list);

  puthash (function_being_compiled, ref_list, symbol_link_hash);

  void *address;
  if((address = gethash (symbol, symbol_address_hash)))
    {
      /* jit_patch_at (ref, address); */
      /* For now, we can't do a real patch, so we do this instead.
	 We assume that call is the first instruction.  */
      
    }
}

/* When linking (or relinking) a symbol and an address, all functions
   that depends on the symbol must be patched.  */
void link_symbol_address (symbol_t symbol, void *address)
{
  hash_table_t symbol_link_hash = gethash (symbol, link_hash);
  if(symbol_link_hash == NULL)
    {
      symbol_link_hash = make_hash_table ();
      puthash (symbol, symbol_link_hash, link_hash);
    }

  Word_t Index = 0;
  list_t *pvalue;

  void *saveip = jit_get_ip ().vptr;
  
  JLF (pvalue, *symbol_link_hash, Index);
  while(pvalue)
    {
      list_t patch_list = *pvalue;

      FOREACH (element, patch_list)
	{
	  printf ("ELEMENT: %p\n", CAR (element));
	  jit_set_ip (CAR (element));
	  jit_calli (address);
	}
      JLN (pvalue, *symbol_link_hash, Index);
    }

  jit_set_ip (saveip);
  puthash (symbol, address, symbol_address_hash);
}

/* dependencies is just a list of all the generics used.
   XXX: beware of namespace handling here.  */
void
register_function_generic_dependencies (symbol_t function,
					list_t dependencies)
{
  panic ("Not yet implemented\n");
}

/* XXX: we should handle recompilation on generic redefinition.

   The best would be, when a function should be recompiled, to link
   all references to that function to another function, so that upon
   the first call to the function, it is recompiled.

   This is not so difficult to achieve: for each function, we could
   create a special handler function, which would then call the
   recompile function.

   The recompile function would get the return address from its stack
   (using __builtin_return_address), and infer from that which
   function it should recompile.  It then patches all the necessary
   functions.

   At the end, recompile returns the address of the new function, and
   the handler function jumps to that address.

   Note that at least one register needs to be screwed up for this,
   the one used for the return address and the jump.  Well in fact we
   could do the jump from the recompile function, and then it would be
   ok.

   We will do that once we have a L inline assembler.  We'll also have
   the ability to turn closures into functions. */
