/* character-set.h - Operations on character sets.
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

#ifndef CHARACTER_SET_H
#define CHARACTER_SET_H

#include <stdio.h>

typedef unsigned int letter_t;

typedef struct character_set
{
  letter_t min;
  letter_t max;
  struct character_set *next;
} * character_set_t;

character_set_t
intersection_character_set (character_set_t char_set1, character_set_t char_set2);

character_set_t
complement_character_set (const character_set_t original);

void
free_character_set (character_set_t char_set);

character_set_t
union_character_set (character_set_t char_set1, character_set_t char_set2);
  
character_set_t
parse_character_set (char *textual_representation, char **new_ptr);

character_set_t
single_char_character_set (char c);

character_set_t
copy_character_set (character_set_t char_set);

character_set_t
minus_character_set (character_set_t char_set1, character_set_t char_set2);

void
display_character_set (character_set_t character_set);

void
display_character_set_file (FILE *file, character_set_t character_set);

unsigned int
is_better_character_set_than_complement (character_set_t char_set);
#endif
