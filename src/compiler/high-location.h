/* high-location.h - High-level locations.
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

#ifndef _HIGH_LOCATION_H
#define _HIGH_LOCATION_H

/* XXX: je suis pas sur que la separation high location/low location
   vaille la peine.  Par contre il faut une interface unique entre le
   code generator et les locations.  */

/* En plus il faut faire attention, si on registerize les variables:
   il faut bien faire la meme chose dans le if et dans le else, donc
   en sortie ces deux doivent etre harmonises */

/*
       - High level: indirections, registers, constant values, stack
                     locations, function parameters and arguments

         Even higher level? constant, function parameters and
         arguments, automatic variable, global variable, temporary
         result.
*/

/* XXX: compound locations? on pourrait passer des compounds
   en parametre des fonctions  */
   
typedef enum { CONSTANT, AUTOMATIC_VARIABLE, STATIC_VARIABLE,
	       GLOBAL_VARIABLE, TEMPORARY_RESULT, FUNCTION_PARAMETER,
	       FUNCTION_ARGUMENT, INDIRECTION, COMPOUND_LOCATION,
	       FIELD_ACCESS, ARRAY_ACCESS } high_location_type_t;

/* Function argument becomes useless, replaced by compound
   location.  */

/* On pourrait differencier les compound statements des structs, en ce
   qu'une struct est un morceau de memoire contigu et pas un compound
   statement. */

// un type block_return_result?  ou alors ca serait un flag.  Pareil
// on pourrait avoir des flags pour les retours des ifs et elses.
typedef struct high_location
{
  /* Type of location.  */
  high_location_type_t location_type;

  /* Type of the object it contains.  */
  type_t type;

  /* The low location containing the high location, or NULL if not
     yet computed.  */
  struct low_location * low_location;

  /* How many functions rely on this location.  When it reaches 0, it
     is freed.  */
  unsigned int ref_count;
  
  /* For now, we put all here.  */

  /* For indirections ,field access and array access: */
  struct high_location * high_location;

  union {
    /* For constants: XXX: we should allow different sizes.  */
    unsigned int value;
    
    /* For field access: */
    symbol_t field_name;

    /* For array access: */
    struct high_location *offset_location;

    /* For compound locations:  It is
       an alist ((symbol_form | int_form) . high_location) */
    list_t location_list;

    /* Normal location (e.g. the stack for automatic variable, a
       register for temp results). XXX: part of the backend.  */
    struct low_location * normal_location;
  };

} * high_location_t;


/* For all the following functions, there must be a low_... counter
   part. */
high_location_t constant (type_t type, unsigned int value);

high_location_t automatic_variable (type_t type, symbol_t name);

/* XXX: on pourrait tres bien faire function(a).toto donc faire un
   field access sur un temporary result.

   De toute facon, tout ce dont on a besoin pour un field access,
   c'est que la low_location aie une indirection en premier.
*/
high_location_t temporary_result (type_t type);

high_location_t function_parameter (type_t type);


/* A compound location is made by agglutining several locations
   together.  It enables transmission of several results at once.  */
high_location_t compound_location (list_t locations);


/* Decrements the counter, and free the location if unneeded.  */
void free_location (high_location_t location);


void
move_between_locations (high_location_t from, high_location_t to)
{
  /* Check type, i.e. performs coercion if possible and needed. */


  /* Performs the low move_between_locations */


  /* XXX: could return a temporary result for faster subsequent
     moves? */
}


/* Returns a temporary result high location.  */
high_location_t
add_location ()
{
  /* Check type.  */


  /* Can call the floating point, int or unsigned int operation,
     according to the type. */


  /* Create a new temporary result with the location in it.  */
}

/* ...: the other operations.  */



/* Misc functions.  */
void
new_block ();

void
delete_block ();
  
