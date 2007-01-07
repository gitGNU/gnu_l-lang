/* transitions.h - Operations on transitions.
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

#ifndef TRANSITIONS_H
#define TRANSITIONS_H

#include "list_set.h"
#include "character_set.h"

/* Transitions originelles, character_set->un state.  Normallement les
   character sets ne sont pas forcement disjoints, mais dans un
   automate de thompson c'est le cas, et c'est quelque chose qu'on
   utilise.
 */
typedef struct transition
{
  character_set_t character;
  struct thompson_state *state;
  struct transition *next;
} *transition_t;


/* Transitions character_set->list_state. Les character sets sont
   forcement disjoints. */
typedef struct list_transition
{
  character_set_t character;
  set_t states; 		/* Liste des etats */
  struct list_transition *next;
} *list_transition_t;



/* C'est O(|from| * |dest|). */
/* Merge deux listes de transition. Si une meme lettre peut aller dans
   plusieurs etats, on l'indique.  */

/* Non en fait c'est pas into, vu que dest peut pas etre reutilisee
   telle quelle non plus, vu que certaines transition vont dans
   plusieurs etats.   */

/* On suppose donc que les character_set de chacune des deux
   list_transitions sont disjoints.  Ca ne marche donc pas pour
   transformer un etat en une liste d'etat propre. */
list_transition_t
merge_list_transition_into (list_transition_t list1, list_transition_t list2);

list_transition_t
make_list_transitions (transition_t transition);


#endif
