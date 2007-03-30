/* expand.c - Handles code expansion.
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

#ifndef EXPAND_H
#define EXPAND_H

#include "../../parser/form.h"

/* For now, we convey only type infomation in the malebolge compiler.
   In the future, there will be additional info for determining if a
   function is const, pure, reentrant, if the arguments can be
   allocated on the stack... */

/* The following trick is used: an expanded form is considered as an
   normal atomic form by the expand function.  */
#define Expanded_Form					    \
  struct						    \
  {							    \
    Atomic_Form;					    \
							    \
    /* The original form.  */				    \
    form_t original_form;				    \
    							    \
    /* The returned, translated form.  */		    \
    form_t return_form;					    \
    							    \
    /* The type of the returned form.  */			\
    Type type;							\
    								\
    /* Other informations will go in a hash or alist. Maybe*/	\
    /* return_form and type would also go in that hash.  */	\
    								\
  } 

Define_Form(expanded_form, Expanded_Form);

/* The expand function, responsible for local expansion (inside functions). */
expanded_form_t
expand (form_t form);

/* The expander functions that the user write take a form as an
   argument, and return an expanded form.  

   In the future, we may request to return an expanded form, when we
   have an easy to use syntax to do that.  */
typedef form_t (*expander_t)(form_t);

/* Register a new expander function, associated to SYMBOL.  */
void
define_expander(symbol_t symbol, expander_t expander);

/* The classic function expander.  */
expanded_form_t
expand_function(generic_form_t form);


/* Left expansion.  */
  
typedef form_t (*left_expander_t)(form_t, expanded_form_t);

void
define_left_expander(symbol_t symbol, left_expander_t expander);



/* Creating new ids in a scope.  */

/* New ids local to a scope aren't necessarily variables; they can be
   macro (like Common Lisp macrolet), or local functions, or local
   constants...  For now, species are an enum, but this should be
   changed into a symbol, as it is done for global species.  */
typedef enum species_t { SPECIES_VARIABLE,
			 SPECIES_MACRO,
			 SPECIES_LABEL,
			 SPECIES_CONSTANT,
			 SPECIES_FUNCTION } Species;

#include <stdarg.h>
void
insert_id( symbol_t symbol, int can_shadow, Species species, ...);


#endif
