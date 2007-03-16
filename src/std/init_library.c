/* init_library.c - 
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


void
init_library ()
{
  //  panic( "Changer le nom iteration en foreach, cleanifier un peu le code et les
  //commentaires, et foreach c'est bon\n");
  
  init_creator ();
  init_foreach();
 
  init_print ();
  init_list ();
  init_xml ();
  init_output ();
  init_hash ();
  init_l_form ();
 
  
}
