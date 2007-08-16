/* expand-loop.c - Loop expansion.
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


#include <l/expand.h>
#include <l/sys/panic.h>
#include <assert.h>


/* Basic loop expansion.  */

typedef struct loop_info
{
  /* Name of the loop.  */
  Symbol loop_name;

  /* Label name for jumping out of the loop.  */
  Symbol break_label;

  /* Label name when continuing, if needed; else null.  The last bit
     contains 1 if the label was defined by @set_continue.  */
  Symbol continue_label;

  /* If several loops are stacked one over the other.  */
  struct loop_info *enclosing_loop;
} *loop_info_t;

/* __thread */ struct loop_info *loop_list = 0;


/* This is useful to identify what label correspond to which loop in
   Cocytus.  */
static Symbol
create_loop_label( Symbol loop_name, char *additional_string)
{
  unsigned int loop_name_len = strlen( loop_name->name);
  unsigned int add_len = strlen( additional_string);
  
  char *gensym_root = malloc( loop_name_len + add_len + 1);
  assert( gensym_root);
  memcpy( gensym_root, loop_name->name, loop_name_len);
  memcpy( gensym_root + loop_name_len, additional_string, add_len);
  gensym_root[loop_name_len + add_len] = 0;

  Symbol symb = gensym_c( gensym_root);
  free( gensym_root);

  return symb;
}

/* Loops can have a name; if no one is provided, one is automatically
   given.

   But how to give names to a loop? The Perl loop_name: loop is nice;
   maybe we can just tell the parser that a macro can be "labelized",
   in which case it would pass the label as a label keyword argument
   to it.
*/
expanded_form_t
expand_loop(generic_form_t form)
{
  loop_info_t li = MALLOC( loop_info);
  li->loop_name = gensym_c( "loop");
  li->continue_label = NULL;
  li->break_label = create_loop_label( li->loop_name, "_end");
  li->enclosing_loop = loop_list;
  loop_list = li;
  
  form_t expression = CAR(form->form_list);
  expanded_form_t exp_exp = expand(expression);

  assert( loop_list == li);
  
  expanded_form_t return_form;

  Symbol begin_label = create_loop_label( li->loop_name, "_begin");

  /* Surrounds the code by a begin_loop label and a goto the beginning
     of this loop.  */
  return_form = seq_form( CONS( label_form_symbol( begin_label, NULL),
				CONS( exp_exp,
				      CONS( generic_form_symbol( SYMBOL( goto),
								 CONS( id_form( begin_label),
								       NULL)),
					    NULL))));

  /* Inserts the break label.  */
  return_form =  seq_form( CONS( return_form,
				 CONS( label_form_symbol( li->break_label, NULL),
				       NULL)));

  /* Inserts a continue label at the start of the loop, if necessary.  */
  if(loop_list->continue_label /* A continue_label is needed.  */
     && !((int) loop_list->continue_label & 1)) /* But wasn't set by @set_cont. */
    {
      return_form = label_form_symbol( loop_list->continue_label,
				       return_form);
    }

  loop_list = loop_list->enclosing_loop;

  return return_form;
}

/* Break can take a loop name as an argument; if not, latest loop
   (innermost) is used.  */
expanded_form_t
expand_break(generic_form_t form)
{
  if (form->form_list)
    panic( "Loop argument is not supported for now\n");
  return expand( generic_form_symbol( SYMBOL( goto),
				      CONS( id_form( loop_list->break_label),
					    NULL)));
}

/* Continue can take a loop name as an argument; if not, latest loop
   (innermost) is used.  */
expanded_form_t
expand_continue( generic_form_t form)
{
  if (form->form_list)
    panic( "Loop argument is not supported for now\n");
  Symbol label_symbol;

  struct loop_info *loop = loop_list;
  
  if(loop->continue_label)
    {
      label_symbol = ((int) loop->continue_label & ~1);
    }
  else
    {
      label_symbol = loop->continue_label
	= create_loop_label( loop->loop_name, "_continue");
    }

  return expand( generic_form_symbol( SYMBOL( goto),
				      CONS( id_form( label_symbol),
					    NULL)));
}

/* Inserts a continue label.  If not called, the default continue
   label is the beginning of the loop.  */
expanded_form_t
expand_at_set_continue( generic_form_t form)
{
  /* @set_continue does not take a loop name argument; it sets the
     label in the current loop.  */
  assert( !form->form_list);
  struct loop_info *loop = loop_list;

  if(loop->continue_label == NULL)
    {
      loop->continue_label = create_loop_label( loop->loop_name, "_continue");
    }
  else if((int) loop->continue_label & 1)
    {
      compile_error( "Loop %s has two continue targets.\n",
		     loop->loop_name->name);
    }
  
  loop->continue_label = ((int) loop->continue_label | 1);
  
  return expand( label_form_symbol( (int)loop->continue_label & ~1,
				    NULL));
}

/* C loops.  */

form_t while_sharp__sharp_expander_function( form_t arg);



void
init_expand_loop( void)
{
  define_expander(SYMBOL(loop), expand_loop);
  define_expander(SYMBOL(break), expand_break);
  define_expander(SYMBOL(continue), expand_continue);
  define_expander(intern( "@set_continue"), expand_at_set_continue);

  define_expander( SYMBOL( while), while_sharp__sharp_expander_function);
}
