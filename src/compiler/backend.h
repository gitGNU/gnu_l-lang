/* backend.h - Functions that a backend must implement.
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

#ifndef _BACKEND_H
#define _BACKEND_H

#include "../objects/symbol.h"

/* XXX: functions also should be backend-specific.  */
#include "../objects/function.h"

typedef struct location * location_t;


/* XXX: location should be backend-specific.  */
struct location
{
  /* Type is the first element, this is important for LOCATION_TYPE to
     work.  */
  Type type;

  int ref_count;

  union
  {
    struct
    {
      unsigned int automatic_variable : 1;
      unsigned int compound_location : 1;
      unsigned int spilled_location: 1; /* 1 if the location has been
					   spilled. */

      unsigned int spilled_register : 8; /* If the register was
					    spilled, what register was
					    it.  */
    };
    unsigned int all;
  };
  
  struct low_location  *low_location;

  union
  {
    /* For stack variables.  */
    struct memory_block *mb;

    /* For compound locations. */
    list_t location_alist;

  };
};

/* XXX: these two should also be defined by the backend.  */

/* Locations must have a type.  */
#define location_type(loc) (* (Type *) loc)

#define compound_location_alist(loc)				\
  ({ assert (loc->compound_location); loc->location_alist; })


/* Create a location with constant value VALUE.  */
location_t
constant_value (Type type, unsigned int value);

location_t
void_location (void);

/* Create a stack variable (automatic) in the current block.  type may
   be NULL, the backend will know its type when the location is
   needed.

   This works because there must be at least an affectation to the
   stack before it is read, else we are reading an unitialized value.
   XXX This may not be true with gotos, though.  */
//void
//create_stack_variable (type_t type, symbol_t name);

/* Retrieve the location associated to symbol ID.  */
location_t
get_location (symbol_t id);

/* Retrieve the value associated to ID for use by the compiler.
 */
void *
symbol_value (symbol_t id, Type expected_type);

void
free_location (location_t location);

/* Create a new compound location.  */
location_t
compound_location (list_t alist);


/* Begin generating a function.  PARAMETERS is a tuple.  */
void
generate_function_start (symbol_t name, generic_form_t parameters);

/* End function generation.  */
void *
generate_function_end (void);

/* Beginning of a new block.  */
void
create_block ();

/* End of a new block.  */
void
delete_block ();

/* Value returned by the function.  */
void
return_function_value (location_t location);


location_t
function_call (function_t function, unsigned int loc_size,
	       location_t *loc_array);


/* Labels and branching.  */

/* XXX: labels should be private.  */
/* XXX: Could we use the same mecanism for patching calls to
   not yet defined functions?  Don't think so. */

/* XXX: should we use different types for backward and forward labels?
   And goto label would act differently if we use one or the other.  */

/* LLL: We would have:

   type Forward_Label;
   type Backward_Label;
   type Label = Forward_Label | Backward_Label;

   coerce Forward_Label Label;
   coerce Backward_Label Label;
   
   Forward_Label make_label (Void);
   Void goto_label(Forward_Label);
   Void goto_label(Backward_Label);
   Void goto_label(Label);

   We may not use the Backward_Label we get back.
   (Backward_Label:opt) put_label_here (Forward_Label label); 
   
   Backward_Label make_label_here(Void);

   The direct use of Forward and Bacwkard labels will allow a small
   optimisation in some cases. 

   We can't do itin C, because we need to modify the list_t in forward
   labels.  A reference like in C++ would be nice for this.  
*/

/* Address of the function.  */

typedef struct label
{
  short is_forward_label;
  union
  {
    void *address;
    list_t patch_list;
  };
} *label_t;

typedef label_t backward_label_t;

/* List of patches to apply.  */
typedef label_t forward_label_t;


/* Creates a new label. Can be used for forward references.  */
forward_label_t make_forward_label (void);

/* Creates a jump to a label (backward or forward reference).  */
void goto_label (label_t label);

/* If the label was a forward.  */
backward_label_t put_label_here (forward_label_t label);

/* Faster combinaison for make_label followed by put_label_here.  To
use when the reference isn't forward.  */
backward_label_t make_label_here ();


/* Conditionals.  */
typedef struct boolean_expression_switch {
  backward_label_t entry_point;  /* Entry point of the boolean expression.  */
  forward_label_t true_jump;	 /* List of entries to patch if the
				    expression is true. */
  forward_label_t false_jump;     /* List of entries to patch if the
				     expression is false. */
} *boolean_expression_switch_t;

boolean_expression_switch_t make_eq_switch (location_t loc1, location_t loc2);
  


/* Standard operations.  */
location_t
add_int_locations (location_t loc1, location_t loc2);

location_t
sub_int_locations (location_t loc1, location_t loc2);

location_t
mul_int_locations (location_t loc1, location_t loc2);



/* Misc.  */
location_t
get_struct_field (location_t loc, symbol_t symbol);

#endif
