/* creator.h - Creator handling.
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

#ifndef _CREATOR_H
#define _CREATOR_H

#include <l/sys/creator.h>

/* A creator is expected to return an expanded form.  */
/* XXX: a creator prend un form en argument, et pas un expanded form:
   sinon ca marche pas pour les trucs comme alloc:gc, et puis de toute
   facon c'est moins general.

   Par contre il est raisonable de demander que les forms en sortie du
   creator sont bien expandees.

   Finalement, c'est une liste de form que ca prend, vu qu'on ne se
   soucie pas du nom par lequelle il est appelle.

   */
   
typedef expanded_form_t (*creator_t)(Type, list_t);
typedef creator_t Creator;

Creator
get_creator( Type t);

void
define_derived_creator( Base_Type t, Symbol name);

#endif
