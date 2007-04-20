/* backend.c - Implementation of the backend.h interface for JIT.
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


/* The jit backend aims at being fast.  In particular, generation is
   done in one pass.

   We try to generate not too bad code when possible, while retaining
   one-pass compilation.  This forces to do quite a few back
   patches.  */

#include <Judy.h>
#include "../../objects/symbol.h"
//#include "../../objects/type.h"
#include <l/type.h>
#include "../../memory/code.h"
#include "../backend.h"
#include "lightning-extended.h"
#include "../../objects/function.h"
#include "low-location.h"
#include "location.h"
#include "stack.h"
#include "register.h"

#include <l/sys/panic.h>

#define compile_error panic

/* For debugging purposes.  */
static int locations_created = 0;

void
debug_new_location (location_t location)
{
  // if(location == 0x80596a8 || location == 0x8059720)
  //    asm("int $3");
}

#define NEW_LOCATION(type_)			\
  ({location_t location = MALLOC (location);	\
    location->type = type_;			\
    location->ref_count = 1;			\
    location->all = 0;				\
    locations_created ++;			\
    debug_new_location (location);						\
    /*  printf ("NEW location : number = %d\n", locations_created); */	\
    location; })

location_t
constant_value (Type type, unsigned int value)
{
  location_t location = NEW_LOCATION (type);
  location->low_location = constant_value_location (value);

  return location;
}

location_t
function_parameter (Type type, unsigned int number)
{
  location_t location = NEW_LOCATION (type);
  location->low_location = function_argument (number);
  return location;
}

location_t
stack_location (Type type, memory_block_t mb)
{
  location_t location = NEW_LOCATION (type);
  location->low_location = stack_low_location (mb->offset);
  location->mb = mb;
  
  return location;
}

/* Creates a temporary location for lloc.  The content is not copied!  */
location_t
temporary_location (Type type, low_location_t lloc)
{
  static count = 0;
  location_t loc = NEW_LOCATION (type);
  loc->low_location = lloc;
  
  return loc;
}

/* Makes a copy of a location; this location can then be erased, its
   contents are still accessible by the copy.  */
location_t
copy_location (location_t location)
{
  low_location_t reg = registerize (location->low_location);
  location_t loc = temporary_location (location->type,
				       reg);
  register_locations[reg->reg] = loc;
  return loc;
}

location_t
compound_location (unsigned int len, location_t *locations)
{
  /* We don't need to fill the type: the type of the componud location
     is a tuple type of all the individual locations.  We then just
     need to know that a location is a compound location to check its
     type against other compound locations. */
  
  location_t location = NEW_LOCATION (NULL);
  location->compound_location = 1;
  location->location_length = len;
  location->locations = locations;

  return location;
}

/* A void location is just an empty compound.  We could always use the
   same.*/
location_t
void_location (void)
{
  location_t location = NEW_LOCATION (TYPE( "Void"));
  location->compound_location = 1;
  location->location_length = 0;
  location->locations = (void *) -1;
  
  return location;
  //  return compound_location (NULL);
  //  location_t location = temporary_location (TYPE (void), NULL);
  //  return location;
}

location_t
global_location( Type type, void *address)
{
  //  assert( locations_created == 0);
  location_t loc = NEW_LOCATION (type);
  loc->low_location = indirection(0, constant_value_location( address));

  locations_created--; /* A global location does not count.  */
  //  assert( locations_created == 0);
  return loc;
}

#define compile_error panic




/*
typedef struct spill_alist
  {
    register_t reg;
    location_t location;
    struct spill_alist *next;
  } *spill_alist_t;
*/

  /* A word, set to 1 if the register has been spilled.  */
static  unsigned int registers_spilled;

  /* List of spilled registers, to unspill at the end of the if.
     XXX: in fact, there is no reason to index it by register.
     */
static  location_t spilled_locations[DATA_REGISTER_NUMBER];
  //  spill_alist_t spill_alist;


void
spill (register_t reg)
{
  assert (reg >= 0);
  assert (register_locations[reg] != NULL);

  registers_spilled |= (1 << reg);
  
  
  location_t to_spill_location = register_locations[reg];
  assert (to_spill_location);
  assert (to_spill_location->low_location->location_type == REGISTER);
  assert (to_spill_location->low_location->reg == reg);
  
  to_spill_location->spilled_location = 1;
  to_spill_location->spilled_register = reg;

  spilled_locations[reg] = to_spill_location;
  
  if(to_spill_location == 0x80596a8 || to_spill_location == 0x8059720)
    asm("int $3");
  
  low_location_t ll = to_spill_location->low_location;
  
  Type type = to_spill_location->type;

  memory_block_t block = allocate_memory_block (type->size);
  
  to_spill_location->low_location = stack_low_location (block->offset);

  to_spill_location->mb = block;

  move_between_low_locations_register_indirection (ll,
						   to_spill_location->low_location);
  
  register_locations[reg] = NULL;

  free_data_register (reg);
}

/* Move between big locations move things bigger than a word.  */
static
move_between_big_locations (location_t from, location_t to)
{
  assert (from->type == to->type);
  assert (from->low_location->location_type == INDIRECTION);
  assert (to->low_location->location_type == INDIRECTION);

  for(int i = 0; i < from->type->size; i += sizeof(int))
    {
      low_location_t from_low_location = indirection (from->low_location->offset + i,
						      from->low_location->loc);
      low_location_t to_low_location = indirection (to->low_location->offset + i,
						    to->low_location->loc);
      move_between_low_locations (from_low_location, to_low_location);
    }

  /* We create temporary "small" locations, and access them
     individually.  */
}


static void
move_between_compound_locations (location_t from, location_t to)
{
  assert (from->compound_location && to->compound_location);

  assert (from->location_length == to->location_length);
  
  /* The solution we use is to allocate a bunch of temporary locations
     to hold the results of to; and then move all that to from.

     In the future, this would be optimised once converted to SSA
     form.  */
  location_t temporary_locations[from->location_length];

  for(int i = 0; i < from->location_length; i++)
    {
      assert (!(to->locations[i]->compound_location));
      
      temporary_locations[i] = copy_location (from->locations[i]);
    }

  /* We move from the end to the beginning to minimize spilling,
     because spilling is done LRU style.  */

  for(int i = from->location_length - 1; i >= 0; i--)
    {
      move_between_locations (temporary_locations[i], to->locations[i]);
      free_location (temporary_locations[i]);
    }
}

/* XXX: Here, when registerizing a location, the new registerized
   version would be written here.  */
void
move_between_locations (location_t from, location_t to)
{
  if(from->compound_location ^ to->compound_location)
    panic ("Trying to move between a compound and a non compound location\n");
  
  if(to->compound_location == 1)
    {
      move_between_compound_locations (from, to);
      return;
    }

  if(to->type->size > sizeof(int))
    move_between_big_locations (from, to);
  
  move_between_low_locations (from->low_location, to->low_location);
}

/* Retrieve the location associated to symbol ID.  */
//location_t
//get_location (symbol_t symbol)
//{
//  location_t *pvalue;
//
//  if(!symbol->location_table)
//    {
//      printf ("ASSERT Symbol->location table failed for symbol %s\n",
//	      symbol->name);
//      asm("jmp 0");
//    }
//  void **table = CAR (symbol->location_table);
//  JLG (pvalue, *table, (Word_t) symbol);
//
//  if (pvalue == NULL)
//    {
//      compile_error ("Unknown symbol: %s\n", symbol->name);
//      asm("int $3");
//    }
//  return *pvalue;
//}

void
free_location (location_t location)
{
  // if(location == 0x80596a8 || location == 0x8059720)
  //    asm("int $3");
  
  assert (location->ref_count > 0);
  
  if(--location->ref_count == 0)
    {
      locations_created--;

      //      printf ("Free location : locations left = %d\n", locations_created);
      if(location->compound_location)
	{
	  assert (!location->spilled_location);
	  for(int i = 0; i < location->location_length; i++)
	    free_location (location->locations[i]);

	  //	  free (location->locations);
	  return;
	}
      if(location->low_location->location_type == REGISTER)
	{
	  register_locations[location->low_location->reg] = NULL;
	  free_data_register (location->low_location->reg);
	  return;
	}
      if(location->spilled_location)
	{
	  registers_spilled &= ~(1 << location->spilled_register);

	  /* This case happens, for instance if two locations on the
	     same register are spilled in the same path, then
	     path_info_list->spilled_locations[] is set to NULL once
	     for each location.  */
	  //assert (path_info_list->spilled_locations[location->spilled_register]);
	  spilled_locations[location->spilled_register] = NULL; /* Not really useful. */
		  
	}
      //      if(location->automatic_variable)
    }
  /* XXX: to implement*/
}



/* 
XXX: en fait il faut bien un compteur de reference

Par exemple, quand on aura  a = { let b = 4; b }, alors a la creation du let, la refrence vaut 1, au b, la refrence vaut 2,
  a la fin du block, la refrence vaut plus que 1, et une fois affectee, elle vaut 0 et disparait.

  Donc free location ne devrait s'occuper que des cas sur un registre ou sur la pile : les autres locations on s'en fout.

  On pourra verifier que la pile et les registres sont vides quand on a tout compile.

  Et il faut rajouter une fonction add_reference(location) quand on renvoie la meme location mais plusieurs fois.

  Dans le backend C, on s'en tape des references, mais dans les backends compile c'est important.
*/



//__thread
void *function_start;

void *allocate_stack_space_ptr;

typedef hash_table_t location_table_t;

typedef struct block
{
  location_table_t location_table;

  /* Hash table label_name => list( refs_to_patchs).  */
  hash_table_t forward_refs;
  struct block *next;
} *block_t;

/* The block containing the global values.  */
static void *global_location_hash_table_ = NULL;

static struct block global_block_ = {.location_table = &global_location_hash_table_,
                                     .next = NULL };
static const block_t global_block = &global_block_;

static block_t block_list = &global_block_;

/* We have minimal debug info, that helps knowing the name of the
   function that faulted.  For more precise informations, we should
   associate to each expanded form an interval like this one; and
   the original forms of the expanded forms would then be helpful. */
typedef struct debug_info
{
  void *start;
  void *end;
  symbol_t funname;
} *debug_info_t;

/* A list of debug info.  A black-red tree would be better.  */
list_t function_offsets = NULL;

symbol_t
find_owning_function( unsigned int i)
{
  void *address = (void *) i;
  FOREACH( element, function_offsets)
    {
      debug_info_t di = CAR( element);
      if(address >= di->start && address <= di->end)
	return di->funname;
    }
  return intern( "<Not found>");
}

/* Parameters is a tuple form.  */
void *
generate_function_start (symbol_t name, generic_form_t parameters)
{
  /* XXX: allocate space for the code.  */
  function_start = allocate_code_space (4096);
  reinit_registers ();
  reinit_stack ();
  assert( block_list == global_block);
  //  block_list = global_block;

  create_block ();

  jit_prolog (length (parameters->form_list));
  
  {
    FOREACH (element, parameters->form_list)
      {
	int i = jit_arg_ui ();
	generic_form_t label_form = CAR (element);
	assert (label_form->head == SYMBOL (label));

	type_form_t tf = CAR (label_form->form_list->next);
	symbol_t param_name = ((id_form_t) CAR (label_form->form_list))->value;

	Type type = intern_type (tf);
      
	puthash (param_name, function_parameter (type, i),
		 block_list->location_table);
      }
  }

  allocate_stack_space_ptr = jite_retain_space_for (jit_addi_ui (JIT_SP,
								 JIT_SP,
								 0xe0e0e0e0));
  /* XXX: init parameters.  */

  //Some debug info
  debug_info_t di = MALLOC( debug_info);
  di->start = function_start;
  di->funname = name;

  function_offsets = CONS( di, function_offsets);
  
  return function_start;
}

//int min_stack_offset = JITE_OFFSET_FROM_LOCAL_ARG;

void 
generate_function_end ()
{
  delete_block ();
  
  assert (block_list == global_block);

  assert (locations_created == 0);
  
  jite_occupy_space (allocate_stack_space_ptr,
		     jit_addi_ui (JIT_SP, JIT_SP,
				  (JITE_OFFSET_FROM_LOCAL_ARG 
				   + min_offset_used/*current_function.max_offset*/)));

  //  printf("STACK OFFSET: %d\n", min_offset_used);
  
  /* Finish the code, release the memory.  */
  finish_code (function_start);

  /* Patches all calls to redefine the function call.  */
  //link_symbol_address (current_function->name, function_start);

  /* Put some minimal debug informations.  */
  debug_info_t di = CAR( function_offsets);
  di->end = jit_get_ip().vptr;
  
  return;
}

void
create_block (void)
{
  block_t block = MALLOC (block);
  block->location_table = make_hash_table ();
  block->forward_refs = make_hash_table();
  block->next = block_list;
  block_list = block;
}

void
delete_block (void)
{
  location_table_t location_table = block_list->location_table;
  
  /* XXX: delete all variables in the stack.  */

  Word_t index = 0;
  Word_t *pvalue;

  JLF (pvalue, *location_table, index);

  while(pvalue != NULL)
    {
      location_t loc = * (location_t *) pvalue;
      
      //      printf ("Stack variable: %s %d\n", ((symbol_t) index)->name, loc->ref_count);
      
      JLN (pvalue, *location_table, index);

      free_location (loc);
    }
  
  JLFA (index, *location_table);

  //  printf ("Bytes freed:%d\n", index);
  
  /* Move all unresolved forward references to the enclosing scope.  */
  {
    hash_table_t ht = block_list->forward_refs;
    index = 0;
    
    JLF( pvalue, *ht, index);

    if(pvalue && !block_list->next)
      {
	/* There are still forward labels, but we have reached the
	   outermost block.  */
	compile_error( "Goto to an undefined label: %s\n", ((Symbol) index)->name);
      }
    
    while(pvalue != NULL)
      {
	//	printf( "Symbol:%s\n", ((Symbol)index)->name);
	list_t old_refs = gethash( index, block_list->next->forward_refs);
	list_t refs_to_append = *pvalue;

	list_t element;
	for(element = refs_to_append; element->next; element = element->next);
	element->next = old_refs;
	
	puthash( index, refs_to_append, block_list->next->forward_refs);

	JLN( pvalue, *ht, index);
      }
    JLFA( index, *ht);
  }

  block_list = block_list->next;
}


/* XXX: Pour les variables

   - Pour les variables sur pile: on peut leur associer un registre
     avec leur contenu.  A la fin d'un block if, on les ecris dans la
     stack si leur contenu a change.

   - Pour les autres locations (heap, variables globales): on peut
     lire dans le registre, mais quand on ecris, on ecris aussi dans
     la memoire. (et aussi dans le registre).

   - Quand on fait un registerize, c'est la qu'on peut decider de
     mettre une variable dans un registre.
*/

location_t
create_anonymous_stack_variable (Type type)
{
  /* For compound variables: we allocate a set of locations.  */
  if(type->type_type == TUPLE_TYPE)
    {
      /* Only Void is handled for now.  */
      assert( type == TYPE( "Void"));
      return void_location();
    }
      
  memory_block_t block = allocate_memory_block (type->size);
  location_t location = stack_location (type, block);
  return location;
}


/* When type is NULL, we allocate the stack space on the first
affectation. This is not a problem even in then / else branches:

- If creating a location in a then, it will also be used in the else
  branch.  As the else branch is not yet compiled, the stack location
  will also be free in the else branch.

- If creating the location in the else branch, it just means that the
  then branch didn't touched the location.  Thus we don't care if it
  used the stack space, since the variable contains garbage
  anyway.  */
void create_stack_variable (Type type, symbol_t name)
{
  memory_block_t block = allocate_memory_block (type->size);

  location_t location = stack_location (type, block);

  if(gethash (name, block_list->location_table))
    compile_error ("Error: a variable %s is already definid in this scope\n",
		   name->name);
  
  puthash (name, location, block_list->location_table);
}

void create_global_variable_at( Type type, symbol_t name, void *address)
{
  location_t location = global_location( type, address);
  //  assert( global_block == block_list);
  puthash (name, location, global_block->location_table);
}

void create_global_variable( Type type, symbol_t name)
{
  void *data = xmalloc( type->size);
  /* Global data is 0 when untouched.  */
  memset( data, 0, type->size); 
  create_global_variable_at( type, name, data);
}

/* Retrieve the location associated to symbol ID.  */
location_t
get_location (symbol_t id)
{
  /* Go through the list of blocks to get the location.  */
  /* XXX: the location_table could be also associated to the symbol in
     another hash table.  */
  //  block_t element;
  location_t loc;
  
  for(block_t element = block_list; element; element = element->next)
    {
      loc = gethash (id, element->location_table);
      if(loc)
	goto next;
    }
  compile_error ("Symbol %s is never defined\n",id->name);
  
 next:
  /* XXX: for special variables, it won't be like this.  */

  /* Increments the reference counter.  */
  loc->ref_count ++;

  return loc;
}


location_t
get_label( symbol_t id)
{
  location_t loc;
  
  for(block_t element = block_list; element; element = element->next)
    {
      loc = gethash (id, element->location_table);
      if(loc)
	goto label_known;
    }
  
  /* If the label is not yet known, creates a forward label that
     will be patched later  */

  /* This is a bit hacky, but patching a constant( in possible
     multiple places) is not handled right now, so this ensure that
     the patch must be applied only here.  But this makes jumps to
     forward labels a bit less efficient. */

  low_location_t lloc = any_register_location();
  void *ref = jite_retain_space_for(jit_movi_ui( corresponding_register[lloc->reg], 0xfefefefe));
  loc = temporary_location( TYPE( "Label *"), lloc);
  register_locations[lloc->reg] = loc;

  list_t old_ref_list = gethash( id, block_list->forward_refs);
  puthash(id, CONS( CONS( ref, lloc->reg), old_ref_list),
	  block_list->forward_refs);
  
  return loc;
  
  /* If the label is known, return its address.  */

 label_known:
  loc->ref_count++;
  
  return loc;
}

void
backend_compile_goto_constant( Symbol symb)
{
  /* XXX: improve this: we should jump directly to the right place.  */
  location_t loc = get_label( symb);
  low_location_t lloc = loc->low_location;

  if(lloc->location_type == CONSTANT)
    jit_jmpi( lloc->value);
  else if(lloc->location_type == REGISTER)
    {
      jit_jmpr( corresponding_register[lloc->reg]);
    }
  else
    {
      low_location_t reg = registerize( lloc);
      jit_jmpr( corresponding_register[reg->reg]);
      free_data_register( reg->reg);
    }
  free_location( loc);
}


void
backend_compile_goto_variable( location_t loc)
{
  assert( loc->low_location->location_type == INDIRECTION
  	  && loc->low_location->offset == 0);
  low_location_t lloc = loc->low_location->loc;

  if(lloc->location_type == CONSTANT)
    jit_jmpi( lloc->value);
  else if(lloc->location_type == REGISTER)
    {
      jit_jmpr( corresponding_register[lloc->reg]);
    }
  else
    {
      //      assert( lloc->location_type == INDIRECTION
      //	      && lloc->offset == 0);
      low_location_t reg = registerize( lloc);
      jit_jmpr( corresponding_register[reg->reg]);
      free_data_register( reg->reg);
    }
}

/* Insert a label in the current block.  */
void
insert_label( symbol_t id)
{
  /* Check that label does not already exists.  */
  for(block_t element = block_list; element; element = element->next)
    {
      location_t loc = gethash (id, element->location_table);
      if(loc)
	compile_error( "Label %s appears twice in the same scope\n", id->name);
    }

  
  list_t *cons_ref_list;
  if((cons_ref_list = gethash( id, block_list->forward_refs)))
    {
      /* We got a forward label attached to this one, Patch all refs to it.  */
      FOREACH( element, cons_ref_list)
	{
	  pair_t cons_ref = CAR( element);
	  void *ref = CAR( cons_ref);
	  register_t reg = (register_t) CDR( cons_ref);	  

	  void *current_ip = jit_get_ip().ptr;
	  jite_occupy_space( ref, jit_movi_ui( corresponding_register[reg],
					       current_ip));
      	}
      remhash( id, block_list->forward_refs);
    }
    
  location_t location = temporary_location( TYPE( "Label *"),
					    // indirection(0,
					    constant_value_location( jit_get_ip().vptr));//);
  puthash (id, location, block_list->location_table);
}


void
return_function_value (location_t location)
{
  /* XXX: What about compound locations?  */
  if( location->type != TYPE( "Void"))
    {
      /* XXX: free REG_RET? */
      low_location_t ll = register_location (REG_RET);
      
      move_between_low_locations (location->low_location, ll);
      
    }
  
  /* Restore the stack pointer */
  jit_addi_i (JIT_SP, JITE_FP, JITE_OFFSET_FROM_LOCAL_ARG);

  /* XXX: move location to JIT_RET.  */
  jit_ret ();
}

location_t
function_call (location_t funloc/*function_t function*/, unsigned int loc_size,
	       location_t *loc_array)
{
  /* XXX: Save the used registers that can be destroyed by the
     function call (R0, R1, R2).  */
  Function_Type function_type = funloc->type;
  assert( function_type->type_type == FUNCTION_TYPE);
  int nb_arguments = function_type->parameters_type->length;
  
  assert (loc_size == nb_arguments);
  
  /* XXX: use these registers too.  */
  assert (register_locations[REG_R0] == NULL);
  assert (register_locations[REG_R1] == NULL);
  assert (register_locations[REG_R2] == NULL);

  assert( funloc->low_location->location_type == INDIRECTION);
  if(funloc->low_location->loc->location_type != CONSTANT)
    {
      if(funloc->low_location->loc->location_type != REGISTER)
	{
	  low_location_t reg = registerize( funloc->low_location->loc);
	  jit_movr_ui( corresponding_register[REG_R0],
		       corresponding_register[reg->reg]);
	  free_data_register( reg->reg);
	}
      else
	{
	  jit_movr_ui( corresponding_register[REG_R0],
		       corresponding_register[funloc->low_location->loc->reg]);
	}
    }
  
  jit_prepare_i (nb_arguments);

  for(int i = nb_arguments - 1; i >= 0; i--)
    {
      low_location_t from = loc_array[i]->low_location;

      if(from->location_type == REGISTER)
	{
	  jit_pusharg_i (corresponding_register[from->reg]);
	}
      else
	{
	  /* XXX: allocate this reg only once.  */
	  low_location_t reg = any_register_location ();

	  move_between_low_locations_any_register (from, reg);
	  jit_pusharg_ui (corresponding_register[reg->reg]);

	  free_data_register (reg->reg);
	}
    }

  /* Get the pointer address.  */
  void *ref = jit_get_ip ().vptr;

  if( funloc->low_location->location_type == INDIRECTION
      && funloc->low_location->loc->location_type == CONSTANT)
    {
      jit_finish (funloc->low_location->loc->value);

      //record_symbol_needed (current_function->name, ref, function->name);
    }
  else
    {
      jit_finishr( corresponding_register[REG_R0]);
    }
      
      /* XXX: if not yet compiled, put it in the to patch list.  */
      low_location_t reg = any_register_location ();

  jit_retval (corresponding_register[reg->reg]);


  /* XXX  Return the type */

  location_t loc = temporary_location (NULL, reg);

  register_locations[reg->reg] = loc;
  return loc;
}


/* Labels.  */

/* Creates a new label. Can be used for forward references.  */
forward_label_t make_forward_label (void)
{
  forward_label_t label = MALLOC (label);

  label->is_forward_label = 1;
  label->patch_list = NULL;

  return label;
}

/* Creates a jump to a label (backward or forward reference).  */
void goto_label (label_t label)
{
  if(label->is_forward_label)
    {
      void *ref = jit_jmpi (jit_forward ());
      label->patch_list = CONS (ref, label->patch_list);
    }
  else
    {
      jit_jmpi (label->address);
    }
}

/* If the label was a forward.  */
backward_label_t put_label_here (forward_label_t label)
{
  assert (label->is_forward_label == 1);

  void * address = jit_get_ip ().ptr;
  
  label->is_forward_label = 0;

  FOREACH (element, label->patch_list)
    {
      jit_patch_at (CAR (element), address);
    }

  label->address = address;

  return label;

  /* XXX: if the goto is juste before the label, just removes it.  */
}

/* Faster combinaison for make_label followed by put_label_here.  To
use when the reference isn't forward.  */
backward_label_t make_label_here ()
{
  return put_label_here (make_forward_label ());
}


/* Conditionals.  */

#if 0
boolean_expression_switch_t make_eq_switch (location_t loc1, location_t loc2)
{
  low_location_t lloc1 = loc1->low_location, lloc2 = loc2->low_location;


  backward_label_t entry_point = make_label_here ();
  void *ref_true;
  
  switch(lloc1->location_type)
    {
    case CONSTANT:
      {
	int value1 = lloc1->value;
	
	switch(lloc2->location_type)
	  {
	  case CONSTANT: panic ("Not yet implemented\n");
	  case REGISTER: ref_true = jit_beqi_i (jit_forward (),
						corresponding_register[lloc2->reg],
						value1);
	    break;
	  default:
	    {
	      low_location_t reg = registerize (lloc2);
	      ref_true = jit_beqi_i (jit_forward (),
				     corresponding_register[reg->reg],
				     value1);
	      free_data_register (reg->reg);
	    }
	  }
      }
      break;
      
    case REGISTER:
      {
	register_t reg1 = lloc1->reg;
	switch(lloc2->location_type)
	  {
	  case CONSTANT:
	    ref_true = jit_beqi_ui (jit_forward (),
				    corresponding_register[reg1],
				    lloc2->value);
	    break;
	  case REGISTER:
	    ref_true = jit_beqr_ui (jit_forward (),
				    corresponding_register[reg1],
				    corresponding_register[lloc2->reg]);
	    break;
	  default:
	    {
	      low_location_t reg = registerize (lloc2);
	      ref_true = jit_beqi_i (jit_forward (),
				     corresponding_register[reg1],
				     corresponding_register[reg->reg]);
	      free_data_register (reg->reg);
	    }
	  }
      }
      
      break;
    default:
      {
	low_location_t reg = registerize (lloc1);
	register_t reg1 = reg->reg;
	switch(lloc2->location_type)
	  {
	  case CONSTANT:
	    ref_true = jit_beqi_ui (jit_forward (),
				    corresponding_register[reg1],
				    lloc2->value);
	    break;
	  case REGISTER:
	    ref_true = jit_beqr_ui (jit_forward (),
				    corresponding_register[reg1],
				    corresponding_register[lloc2->reg]);
	    break;
	  default:
	    {
	      low_location_t reg2 = registerize (lloc2);
	      ref_true = jit_beqi_i (jit_forward (),
				     corresponding_register[reg1],
				     corresponding_register[reg2->reg]);
	      free_data_register (reg2->reg);
	    }
	  }
	break;
      }
    }

  void *ref_false = jit_jmpi (jit_forward ());

  boolean_expression_switch_t bes = MALLOC (boolean_expression_switch);

  bes->entry_point = entry_point;

  forward_label_t true_jump = MALLOC (label);
  true_jump->is_forward_label = 1;
  true_jump->patch_list = CONS (ref_true, NULL);
  bes->true_jump = true_jump;

  forward_label_t false_jump = MALLOC (label);
  false_jump->is_forward_label = 1;
  false_jump->patch_list = CONS (ref_false, NULL);
  bes->false_jump = false_jump;

  return bes;
}
#endif


#define DEFINE_BOOLEAN_SWITCH_MAKER(name, nameinv)				\
boolean_expression_switch_t make_##name##_switch (location_t loc1, location_t loc2) \
{									\
  low_location_t lloc1 = loc1->low_location, lloc2 = loc2->low_location; \
									\
									\
  backward_label_t entry_point = make_label_here ();			\
  void *ref_true;							\
									\
  switch(lloc1->location_type)						\
    {									\
    case CONSTANT:							\
      {									\
	int value1 = lloc1->value;					\
									\
	switch(lloc2->location_type)					\
	  {								\
	    /*case CONSTANT: panic ("Not yet implemented\n");*/		\
	  case REGISTER: ref_true = jit_b##nameinv##i_i (jit_forward (),	\
						corresponding_register[lloc2->reg], \
						value1);		\
	    break;							\
	  default:							\
	    {								\
	      low_location_t reg = registerize (lloc2);			\
	      ref_true = jit_b##nameinv##i_i (jit_forward (),		\
				     corresponding_register[reg->reg],	\
				     value1);				\
	      free_data_register (reg->reg);				\
	    }								\
	  }								\
      }									\
      break;								\
									\
    case REGISTER:							\
      {									\
	register_t reg1 = lloc1->reg;					\
	switch(lloc2->location_type)					\
	  {								\
	  case CONSTANT:						\
	    ref_true = jit_b##name##i_ui (jit_forward (),		\
				    corresponding_register[reg1],	\
				    lloc2->value);			\
	    break;							\
	  case REGISTER:						\
	    ref_true = jit_b##name##r_ui (jit_forward (),		\
				    corresponding_register[reg1],	\
				    corresponding_register[lloc2->reg]); \
	    break;							\
	  default:							\
	    {								\
	      low_location_t reg = registerize (lloc2);			\
	      ref_true = jit_b##name##i_i (jit_forward (),		\
				     corresponding_register[reg1],	\
				     corresponding_register[reg->reg]);	\
	      free_data_register (reg->reg);				\
	    }								\
	  }								\
      }									\
									\
      break;								\
    default:								\
      {									\
	low_location_t reg = registerize (lloc1);			\
	register_t reg1 = reg->reg;					\
	switch(lloc2->location_type)					\
	  {								\
	  case CONSTANT:						\
	    ref_true = jit_b##name##i_ui (jit_forward (),		\
				    corresponding_register[reg1],	\
				    lloc2->value);			\
	    break;							\
	  case REGISTER:						\
	    ref_true = jit_b##name##r_ui (jit_forward (),		\
				    corresponding_register[reg1],	\
				    corresponding_register[lloc2->reg]); \
	    break;							\
	  default:							\
	    {								\
	      low_location_t reg2 = registerize (lloc2);		\
	      ref_true = jit_b##name##r_i (jit_forward (),		\
				     corresponding_register[reg1],	\
				     corresponding_register[reg2->reg]); \
	      free_data_register (reg2->reg);				\
	    }								\
	  }								\
	free_data_register (reg->reg);					\
	break;								\
      }									\
    }									\
									\
  void *ref_false = jit_jmpi (jit_forward ());				\
									\
  boolean_expression_switch_t bes = MALLOC (boolean_expression_switch);	\
									\
  bes->entry_point = entry_point;					\
									\
  forward_label_t true_jump = MALLOC (label);				\
  true_jump->is_forward_label = 1;					\
  true_jump->patch_list = CONS (ref_true, NULL);			\
  bes->true_jump = true_jump;						\
									\
  forward_label_t false_jump = MALLOC (label);				\
  false_jump->is_forward_label = 1;					\
  false_jump->patch_list = CONS (ref_false, NULL);			\
  bes->false_jump = false_jump;						\
									\
  return bes;								\
}

DEFINE_BOOLEAN_SWITCH_MAKER (eq, eq)
DEFINE_BOOLEAN_SWITCH_MAKER (ne, ne)
DEFINE_BOOLEAN_SWITCH_MAKER (gt, lt)
DEFINE_BOOLEAN_SWITCH_MAKER (ge, le)
DEFINE_BOOLEAN_SWITCH_MAKER (lt, gt)
DEFINE_BOOLEAN_SWITCH_MAKER (le, ge)


/* Misc.  */
location_t
get_struct_field (location_t loc, symbol_t symbol)
{
  assert (loc->low_location->location_type == INDIRECTION);

  low_location_t orig = loc->low_location;

  assert (loc->type->type_type == STRUCT_TYPE);
  hash_table_t ht = ((Struct_Type) loc->type)->field_hash;
  
  offset_type_t ot = gethash (symbol, ht);
  if(ot == NULL)
    panic("The field does not exist for this struct");
  
  low_location_t low_location = indirection (orig->offset + ot->offset,
					     orig->loc);

  return temporary_location (ot->type, low_location);
}

location_t
get_address_of(location_t loc)
{
  assert (loc->low_location->location_type == INDIRECTION);

  low_location_t lloc = loc->low_location;

  low_location_t newloc = any_register_location();

  move_between_low_locations_any_register(lloc->loc, newloc);

  if(lloc->offset != 0)
    {
      jit_addi_i(corresponding_register[newloc->reg],
		 corresponding_register[newloc->reg],
		 lloc->offset);
    }

  if(lloc->offset_reg != REG_NO_REGISTER)
    panic("Adress with offset register not yet implemented. \n");

  return temporary_location(NULL, newloc);
}

location_t
get_value_of(location_t loc)
{
  location_t value = temporary_location(NULL, 
					indirection(0, loc->low_location));
  return value;
}

location_t
cast_location(Type type, location_t loc)
{
  if(loc->ref_count > 1)
    {
      location_t new_loc = temporary_location(type, loc->low_location);
      return new_loc;
    }
  else
    {
      loc->type = type;
      loc->ref_count++;
      return loc;
    }
}

/* Takes a boolean switch, and transforms that to a register location
   that contains 1 if the jump was true, else 0.  */
location_t
bes_to_location( boolean_expression_switch_t bes)
{
  /* Allocate a register location.  */
  low_location_t reg = any_register_location ();
  location_t loc = temporary_location( TYPE( "Bool"), reg);
  register_locations[reg->reg] = loc;

  put_label_here( bes->true_jump);
  move_between_low_locations_constant_register( constant_value_location( 1),
						reg);
  forward_label_t end_label = make_forward_label();
  goto_label( end_label);
  
  put_label_here( bes->false_jump);
  move_between_low_locations_constant_register( constant_value_location( 0),
						reg);
  put_label_here( end_label);
  return loc;
}
