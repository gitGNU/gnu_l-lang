/* expand-define.c - Definer expansion.
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


/* At the end, this is where all definitions should be processed:
   user definitions, types, macros, functions, globals...

   The main problem is inter-dependency between the definitions.  User
   definitions, that expand into other definitions, should come first,
   but they are a bit special.

   Then types should be evaluated at once, then macros at once, then
   functions and globals at once (for each of them, there can be inter
   dependencies).

   TODO: when this is featureful enough, remove analyze.c and use only this.
   */

/* A definer can expand into a list of forms.  */


#include <l/expand.h>
#include <l/sys/panic.h>
#include <assert.h>
#include <l/global.h>



/* Functions and globals expansion.  */

#include <l/sys/global.h>

/* A hash Symbol -> Global.  */
MAKE_STATIC_HASH_TABLE (global_hash);

void
define_global( symbol_t name, Type type,
	       void *address)
{
  global_t glob = gethash( name, global_hash);
  if(glob)
    {
      glob->type = type;
      glob->address = address;
      /* XXX: should have a relocation list and patch all the
	 relocations on redefinition. */
      return;
    }
  
  glob = MALLOC( global);
  glob->global_type = NORMAL_GLOBAL;
  glob->type = type;
  glob->address = address;

  puthash( name, glob, global_hash);
}

void
define_function( Symbol name, Type type, void *address)
{
  define_global(  name, type, address);
  define_expander(name, expand_function);
}

expanded_form_t
expand_function_definition( Symbol name, generic_form_t lambda_form)
{
  assert( is_form( lambda_form, generic_form)
	  && lambda_form->head == SYMBOL( lambda));
  form_t return_type = CAR (lambda_form->form_list);
  generic_form_t parameters = CAR (lambda_form->form_list->next);
  Type function_type = intern_type( function_type_form (return_type,
								  parameters));

  define_function( name, function_type, NULL);
	  
  return define_form(SYMBOL(function),
		     name, expand(lambda_form));
}

list_t
expand_all_function_and_global( list_t form_list)
{

  /* First pass: declare all the globals' type and functions' expanders.  */
  FOREACH( element, form_list)
    {
      generic_form_t df = CAR( element);
      assert( is_form(  df, generic_form));
      assert( df->head == SYMBOL( define));
      
      id_form_t form_typef = CAR(df->form_list);
      assert( is_form( form_typef, id_form));
      Symbol form_type = form_typef->value;

      id_form_t name_form = CAR( df->form_list->next);
      assert( is_form( name_form, id_form));
      Symbol name = name_form->value;

      expanded_form_t expform;
	
      if(form_type == SYMBOL( function))
	{
	  generic_form_t lambda_form = CAR( df->form_list->next->next);

	  assert( is_form( lambda_form, generic_form)
		  && lambda_form->head == SYMBOL( lambda));
	  form_t return_type = CAR (lambda_form->form_list);
	  generic_form_t parameters = CAR (lambda_form->form_list->next);
	  form_t type_form = function_type_form (return_type, parameters);
	  Type function_type = intern_type( type_form);

	  define_function( name, function_type, NULL);
	}
      else
	{
	  assert( form_type == SYMBOL( global));
	  form_t type_form = CAR( df->form_list->next->next);
	  define_global( name, intern_type( type_form), NULL);
	  expform = define_form(SYMBOL(global),
				name, type_form);
	}
    }


  
  /* There should be two passes: one get the types of all the
     functions, and the other compiles them.

     Note: globals and functions should be analysed at the same time,
     they are interdependent.
     
     For now, the first pass is done by analysis.c.  */
  
  list_t exp_form_list;
  {
    list_t *exp_form_list_ptr = &exp_form_list;
    
  FOREACH( element, form_list)
    {
      generic_form_t df = CAR( element);
      assert( is_form(  df, generic_form));
      assert( df->head == SYMBOL( define));
      
      id_form_t form_typef = CAR(df->form_list);
      assert( is_form( form_typef, id_form));
      Symbol form_type = form_typef->value;

      id_form_t name_form = CAR( df->form_list->next);
      assert( is_form( name_form, id_form));
      Symbol name = name_form->value;

      expanded_form_t expform;
	
      if(form_type == SYMBOL( function))
	{
	  generic_form_t lambda_form = CAR( df->form_list->next->next);

	  expform = expand_function_definition( name, lambda_form);
	}
      else
	{
	  assert( form_type == SYMBOL( global));
	  form_t type_form = CAR( df->form_list->next->next);
	  define_global( name, intern_type( type_form), NULL);
	  expform = define_form(SYMBOL(global),
				name, type_form);
	}
      *exp_form_list_ptr = CONS( expform, NULL);
      exp_form_list_ptr = &((*exp_form_list_ptr)->next);
    }

  *exp_form_list_ptr = NULL;
  }

  return exp_form_list;
}

/* Misc definitions: expander, macros, user definitions...  */

/* For now, all these definitions are processed in-order.  Later, this
   will depend on what other definitions it creates (for instance,
   macro definition would create expanders; class definition would
   create expanders and types; but attributes definitions wouldn't
   create many things. */

typedef expanded_form_t (*Definer)( Symbol define_type,
				    form_t name_form,
				    list_t rest);

MAKE_STATIC_HASH_TABLE( definer_hash);

void
define_definer( Symbol s, Definer d)
{
  puthash( s, d, definer_hash);
}

/* A define hash associates a symbol to a definer.  */

static expanded_form_t
expand_expander( Symbol expander,
		 id_form_t name_form,
		 list_t rest)
{
  assert( is_form( name_form, id_form));
  Symbol name = name_form->value;
  //  assert( expander == SYMBOL( expander));

  generic_form_t tlabel_form = CAR( rest);
  assert( is_form( tlabel_form, generic_form));
  assert( tlabel_form->head == SYMBOL( label));
  
  id_form_t parameter_namef = CAR( tlabel_form->form_list);
  assert( is_form( parameter_namef, id_form));
  form_t parameters = new_tuple_form( CONS( label_form_symbol( parameter_namef->value,
							       id_form( SYMBOL( Compound_Form))),
					    NULL));
	
  form_t body = CAR(tlabel_form->form_list->next);
  /* Create a function.  */
  
  form_t tlambda_form = lambda_form( base_type_form( SYMBOL( Form)),
				     parameters,
				     body);
  
  char *funname_ = malloc( strlen( name->name) + 20);
  strcpy( funname_, name->name);
  strcat( funname_, "##expander_function");
  Symbol funname = intern( funname_);
  free( funname_);
  
  expanded_form_t exp_function_form = expand_function_definition( funname,
								  tlambda_form);
  generate( exp_function_form);
  global_t glob = get_global( funname);
  define_expander( name, glob->address);

  return define_form( SYMBOL( expander), name,
		      exp_function_form);
}

static expanded_form_t
expand_macro( Symbol macro,
	      id_form_t name_form,
	      list_t rest)
{
  assert( is_form( name_form, id_form));
  Symbol name = name_form->value;
  
  assert( rest && rest->next && !rest->next->next);
  
  generic_form_t parameters = CAR( rest);
  generic_form_t body = CAR( rest->next);

  /* XXX: expands the parameters, check their number, etc.  */

  Symbol expander_parameter_name = gensym_c( "form");
  
  list_t id_list;
  list_t prepare_list;
  list_t *prepare_list_ptr = &prepare_list;
  {
    int num_next = 0;
    list_t *id_list_ptr = &id_list;
  
    FOREACH( element, parameters->form_list)
      {
	form_t parameter = CAR( element);
	Symbol parameter_name;
	form_t parameter_form_type;

	if(is_form( parameter, id_form))
	  {
	    parameter_name = ((id_form_t)parameter)->value;
	    parameter_form_type = NULL;
	  }
	else
	  {
	    assert( is_form( parameter, generic_form));
	    generic_form_t gparameter = parameter;
	    assert( gparameter->head == SYMBOL( label));
	    assert( gparameter->form_list && gparameter->form_list->next);
	    assert( is_form( (form_t) CAR( gparameter->form_list), id_form));
	    parameter_name = ((id_form_t) CAR( gparameter->form_list))->value;
	    parameter_form_type = ((id_form_t) CAR( gparameter->form_list->next));
	  }
	

	/* Add let parameter_name = form.form_list.( tail)*.head.   */
	form_t form = id_form( expander_parameter_name);
	form = generic_form_symbol( intern( "[]"),
				    CONS( form,
					  CONS( symbol_form( SYMBOL( form_list)),
						NULL)));
	
	for(int i = 0; i < num_next; i++)
	  {
	    form = generic_form_symbol( intern( "[]"),
					CONS( form,
					      CONS( symbol_form( SYMBOL( tail)),
						    NULL)));
	  }
	/* XXX Add: assert( form_.form_list.tail*).  */
	form = generic_form_symbol( intern( "[]"),
				    CONS( form,
					  CONS( symbol_form( SYMBOL( head)),
						NULL)));

	if(parameter_form_type)
	  {
	    form = generic_form_symbol( SYMBOL( cast),
					CONS( id_form( SYMBOL( Form)),
					      CONS( generic_form_symbol( SYMBOL( expand),
									 CONS( form,
									       NULL)),
						    NULL)));
	    /* A simple expand would not suffice, because there can be
	       parameters whose type is not known here.  Expansion
	       of the parameters must happen on the caller's side.

	       Here, the type should be checked.  Later, it will even
	       be used for macro overloading.  
	       */
	    //	    panic( "Pre-Expansion of the macro parameters not implemented\n");
	  }
	form_t tlet_form = let_form( id_form( SYMBOL( Form)), parameter_name);
	form_t assign_form = generic_form_symbol( intern( "="),
						  CONS( tlet_form,
							CONS( form,
							      NULL)));
	*prepare_list_ptr = CONS( assign_form, NULL);
	prepare_list_ptr = &((*prepare_list_ptr)->next);
	*id_list_ptr = CONS( parameter_name, NULL);
	id_list_ptr = &((*id_list_ptr)->next);
	num_next++;
      }
    *id_list_ptr = NULL;
  }

  form_t form_exp_body =  expand_form_rec( body, id_list);
  *prepare_list_ptr = CONS(form_exp_body, NULL);
  (*prepare_list_ptr)->next = NULL;

  form_t new_body = block_form( prepare_list);
  
  return expand_expander( NULL, name_form, CONS( label_form_symbol( expander_parameter_name,
								    new_body),
						 NULL));
  //  lispify( parameters);
  //  lispify( body);
}


#include <l/access.h>

typedef form_t( *Virtual_Accesser)(expanded_form_t);
typedef form_t( *Virtual_Left_Accesser)(expanded_form_t, form_t);

/* A hash table Type -> Hash_Table( Symbol -> Virtual_Accesser) that
   associates to a type a hash table associating a field to an
   expander function.
*/
MAKE_STATIC_HASH_TABLE( virtual_attributes_hash);
MAKE_STATIC_HASH_TABLE( virtual_left_attributes_hash);


static form_t
virtual_accesser( Type type,
		  expanded_form_t accessed,
		  expanded_form_t accessor)
{
  hash_table_t field_hash = gethash( type, virtual_attributes_hash);

  symbol_form_t accessor_symbol_form = accessor->return_form;
  if(!is_form(accessor_symbol_form, quoted_symbol_form))
    {
      goto not_virtual_attribute;
    }
  symbol_t accessor_symbol = accessor_symbol_form->value;

  Virtual_Accesser fun = gethash( accessor_symbol, field_hash);
  if(fun)
    {
      return fun( accessed);
    }
  
 not_virtual_attribute:
  {
    Accesser defalt = gethash( intern( "_"), field_hash);
    if(defalt == NULL)
      {
	panic ("There isn't any accessor for type %s\n",
	       asprint_type (accessed->type));
      }
    return defalt(type, accessed, accessor);
  }
}

static form_t
virtual_left_accesser( Type type,
		       expanded_form_t accessed,
		       expanded_form_t accessor,
		       expanded_form_t expression)
{
  hash_table_t field_hash = gethash( type, virtual_left_attributes_hash);

  symbol_form_t accessor_symbol_form = accessor->return_form;
  if(!is_form(accessor_symbol_form, quoted_symbol_form))
    {
      goto not_virtual_attribute;
    }
  symbol_t accessor_symbol = accessor_symbol_form->value;

  Virtual_Left_Accesser fun = gethash( accessor_symbol, field_hash);
  if(fun)
    {
      return fun( accessed, expression);
    }
  
 not_virtual_attribute:
  {
    Left_Accesser defalt = gethash( intern( "_"), field_hash);
    if(defalt == NULL)
      {
	panic ("There isn't any left accessor for type %s\n",
	       asprint_type (accessed->type));
      }
    return defalt(type, accessed, accessor, expression);
  }
}



static expanded_form_t
expand_attribute( Symbol macro,
		  form_t type_form,
		  list_t rest)
{
  Type type = intern_type( type_form);

  assert( rest);
  id_form_t obj_name_form = CAR( rest);
  assert( is_form( obj_name_form, id_form));
  Symbol obj_name = obj_name_form->value;

  assert( rest->next);
  id_form_t field_name_form = CAR( rest->next);
  assert( is_form( field_name_form, id_form));
  Symbol field_name = field_name_form->value;

  assert( rest->next->next);
  form_t last_arg = CAR( rest->next->next);
  assert( !rest->next->next->next);

  form_t body = NULL;
  form_t left_body = NULL;

  Symbol expression_name;
  
  if(is_form( last_arg, generic_form))
    {
      generic_form_t glast_arg = last_arg;
      if(glast_arg->head == SYMBOL( tuple))
	{
	  /* We got a tuple: both the left and right body were
	     given.  */
	  assert( glast_arg->form_list
		  && glast_arg->form_list->next
		  && !glast_arg->form_list->next->next);
	  FOREACH( element, glast_arg->form_list)
	    {
	      generic_form_t glabel = CAR( element);
	      assert( is_form( glabel, generic_form));
	      assert( glabel->head == SYMBOL( label));

	      if(is_form( (form_t) CAR( glabel->form_list), generic_form))
		{
		  generic_form_t left_form = CAR( glabel->form_list);
		  assert( left_form->head == SYMBOL( left));
		  assert( is_form( (form_t) CAR( left_form->form_list), id_form));
		  assert( body == NULL);

		  left_body = CAR( glabel->form_list->next);
		  expression_name = ((id_form_t) CAR( left_form->form_list))->value;
		}
	      else
		{
		  assert( is_form( (form_t) CAR( glabel->form_list), id_form));
		  assert( ((id_form_t) CAR( glabel->form_list))->value == SYMBOL( right));
		  body = CAR( glabel->form_list->next);
		}
	    }
	  goto next;
	}
      else if(glast_arg->head == SYMBOL( label))
	{
	  generic_form_t glabel = glast_arg;
	  /* A label form: the user wants either a read only or write
	     only attribute.  */
	  if(is_form( (form_t) CAR( glabel->form_list), generic_form))
	    {
	      generic_form_t left_form = CAR( glabel->form_list);
	      assert( left_form->head == SYMBOL( left));
	      assert( is_form( (form_t) CAR( left_form->form_list), id_form));
	      assert( body == NULL);
	      
	      left_body = CAR( glabel->form_list->next);
	      expression_name = ((id_form_t) CAR( left_form->form_list))->value;
	    }
	  else
	    {
	      assert( is_form( (form_t) CAR( glabel->form_list), id_form));
	      assert( ((id_form_t) CAR( glabel->form_list))->value == SYMBOL( right));
	      body = CAR( glabel->form_list->next);
	    }
	  goto next;
	}
    }

  /* Neither a tuple, nor a label: then we assume that the argument
     given works for  both left and right body.  */
  body = last_arg;
  expression_name = gensym_c( "expression");
  left_body = generic_form_symbol( intern( "="),
				   CONS( body,
					 CONS( id_form( expression_name),
					       NULL)));
 next:

  /* Create and compile the virtual_accesser.  */
  if(body)
    {
      form_t replaced_body = expand_form_rec( body, CONS( obj_name, NULL));
    
      form_t parameters = new_tuple_form( CONS( label_form_symbol( obj_name,
								   id_form( SYMBOL( Form))),
						NULL));
      form_t tlambda_form = lambda_form( base_type_form( SYMBOL( Form)),
					 parameters,
					 replaced_body);
      char *name = asprint_type( type);
      char *funname_ = malloc( strlen( name) + 30);
      strcpy( funname_, name);
      strcat( funname_, "##virtual_attribute_function");
      Symbol funname = intern( funname_);
      free( funname_);
    
      expanded_form_t exp_function_form = expand_function_definition( funname,
								      tlambda_form);
      generate( exp_function_form);

      global_t glob = get_global( funname);
      Virtual_Accesser va = glob->address;
      assert( va);
    
      /* Now install the virtual attribute accesser as the new accesser.  */
      Accesser old_accesser = get_accesser( type);
      hash_table_t field_hash;
      if(old_accesser != virtual_accesser)
	{
	  define_accesser( type, virtual_accesser);
	  field_hash = make_hash_table();
	  puthash( intern( "_"), old_accesser, field_hash);
	  puthash( type, field_hash, virtual_attributes_hash);
	}
      else
	{
	  field_hash = gethash( type, virtual_attributes_hash);
	}
    
      puthash( field_name, va, field_hash);
    }

  /* Do the same to the left accessor.  */
  if(left_body)
    {
      form_t replaced_left_body = expand_form_rec( left_body,
						   CONS( obj_name,
							 CONS( expression_name,
							       NULL)));

    
    
      form_t parameters = new_tuple_form( CONS( label_form_symbol( obj_name,
								   id_form( SYMBOL( Form))),
						CONS( label_form_symbol( expression_name,
									 id_form( SYMBOL( Form))),
						      NULL)));
      form_t tlambda_form = lambda_form( base_type_form( SYMBOL( Form)),
					 parameters,
					 replaced_left_body);
      char *name = asprint_type( type);
      char *funname_ = malloc( strlen( name) + 40);
      strcpy( funname_, name);
      strcat( funname_, "##virtual_left_attribute_function");
      Symbol funname = intern( funname_);
      free( funname_);
    
      expanded_form_t exp_function_form = expand_function_definition( funname,
								      tlambda_form);
      generate( exp_function_form);

      global_t glob = get_global( funname);
      Virtual_Left_Accesser va = glob->address;
      assert( va);
    
      Accesser old_left_accesser = get_left_accesser( type);
      hash_table_t left_field_hash;
      if(old_left_accesser != virtual_left_accesser)
	{
	  define_left_accesser( type, virtual_left_accesser);
	  left_field_hash = make_hash_table();
	  puthash( intern( "_"), old_left_accesser, left_field_hash);
	  puthash( type, left_field_hash, virtual_left_attributes_hash);
	}
      else
	{
	  left_field_hash = gethash( type, virtual_left_attributes_hash);
	}
    
      puthash( field_name, va, left_field_hash);
    }
  return define_form( SYMBOL( attribute), id_form( SYMBOL( name)),
		      NULL);
}

/* A hash symbol->function.  */
MAKE_STATIC_HASH_TABLE (grammar_macro_hash);



/* Expand and dynamically compiles the expanders.  */

list_t
expand_all_misc( list_t form_list)
{
  /* IL faut creer deux listes, avec le meme body: une liste
     d'expanders, et une liste de fonctions.  Les fonctions sont a
     compiler immediatement. Quoique en fait c'est la meme liste,
     l'une contenue dans l'autre. */

  
  list_t expander_list;
  {
    list_t *expander_list_ptr = &expander_list;
    
    FOREACH( element, form_list)
      {
	generic_form_t df = CAR( element);
	assert( is_form(  df, generic_form));
	assert( df->head == SYMBOL( define));
	
	id_form_t form_typef = CAR(df->form_list);
	assert( is_form( form_typef, id_form));
	Symbol form_type = form_typef->value;
		
	id_form_t name_form = CAR( df->form_list->next);

	Definer definer = gethash( form_type, definer_hash);
	assert( definer);
	
	expanded_form_t exp_form = definer( form_type,
					    name_form,
					    df->form_list->next->next);
	
	*expander_list_ptr = CONS( exp_form, NULL);
	expander_list_ptr = &((*expander_list_ptr)->next);

	/* Construct the expander form.  */
      }
    *expander_list_ptr = NULL;
  }

  return expander_list;
}


/* Types.  */


#include <l/sys/type.h>
#include <l/access.h>
/* XXX: for recursive types: just use a lazy evaluation technique, we
   transform a type definition to a type only when the type is needed. */
void
define_type (symbol_t name, type_form_t type_form)
{
  Base_Type t = define_type_type_form (id_form (name), -1, -1, type_form);

  assert (t->type_type == BASE_TYPE);
  
  /*  Does not really belong here, but more to a "high-level type
     definition processing" part of the compiler.  */
  define_derived_creator( t, name);
  define_accesser (t, derived_accesser);
  define_left_accesser (t, derived_left_accesser);
}

/* A type alias is just another name for the same type.  It is
   equivalent to C's typedef. */
void
define_type_alias (symbol_t name,
		   type_form_t type_form)
{
  Type type = intern_type (type_form);
  associate_type_with_type_form( id_form( name), type);
}

list_t
expand_all_types( list_t form_list)
{
    
  list_t type_form_list;
  {
    list_t *type_form_list_ptr = &type_form_list;
    
    FOREACH( element, form_list)
      {
	generic_form_t df = CAR( element);
	assert( is_form(  df, generic_form));
	assert( df->head == SYMBOL( define));
	
	id_form_t form_typef = CAR(df->form_list);
	assert( is_form( form_typef, id_form));
	Symbol form_type = form_typef->value;
	assert( form_type == SYMBOL( type)
		|| form_type == SYMBOL( type_alias));
		
	id_form_t name_form = CAR( df->form_list->next);
	assert( is_form( name_form, id_form));
	Symbol name = name_form->value;

	generic_form_t type_form = CAR( df->form_list->next->next);
	
	form_t exp_type_form = define_form( SYMBOL( type),
					    name,
					    type_form);

	if(form_type == SYMBOL( type))
	  define_type( name, type_form);
	else
	  define_type_alias( name, type_form);
	  
	*type_form_list_ptr = CONS( exp_type_form, NULL);
	type_form_list_ptr = &((*type_form_list_ptr)->next);

	/* Construct the expander form.  */
      }
    *type_form_list_ptr = NULL;
  }

  return type_form_list;
}


/* Expand all.  */

/* This should split the list of expansions into list of one
   categories, then call the categories one after the other according
   to some precedence graph. For now, this precedence graph is
   static, but with user-defined definers this will change.  */

list_t
expand_all( list_t form_list)
{
  /* First, split into the different lists.  */
  hash_table_t ht = make_hash_table();

  FOREACH( element, form_list)
    {
      generic_form_t df = CAR( element);
      assert( is_form(  df, generic_form));
      assert( df->head == SYMBOL( define));
      
      id_form_t form_typef = CAR(df->form_list);
      assert( is_form( form_typef, id_form));
      Symbol form_type = form_typef->value;
      
      puthash( form_type, CONS( df, gethash( form_type, ht)), ht);
    }

  /* First, we get the compile_time things.  */
  list_t compile_time_list_ = reverse( gethash( SYMBOL( compile_time), ht));

  list_t expanded_compile_time_list = NULL;
  if(compile_time_list_)
    {
      list_t compile_time_list;
      {
	list_t *compile_time_list_ptr = &compile_time_list;
	FOREACH( element, compile_time_list_)
	  {
	    generic_form_t cf = CAR( element);
	    *compile_time_list_ptr = CONS( CAR( cf->form_list->next), NULL);
	    compile_time_list_ptr = &((*compile_time_list_ptr)->next);
	  }
	*compile_time_list_ptr = NULL;
      }

      list_t exp_ctl = expand_all( compile_time_list);
      generate_list( exp_ctl);
      expanded_compile_time_list = CONS( generic_form_symbol( SYMBOL( define),
							      CONS( id_form( SYMBOL( compile_time)),
								    CONS( id_form( SYMBOL( toto)),
									  exp_ctl))),
					 NULL);
    }

  /* Before the grammars come the grammar macros. */
  list_t grammar_macro_list = gethash( SYMBOL( grammar_macro), ht);
  if(grammar_macro_list)
    {
      list_t grammar_macro_function_list;
      list_t *grammar_macro_function_list_ptr = &grammar_macro_function_list;
      FOREACH( grammar_macro_, grammar_macro_list)
	{

	  generic_form_t grammar_macro = CAR( grammar_macro_);
	  symbol_t macro_name = ((id_form_t) CAR( grammar_macro->form_list->next))->value;

	  form_t body = CAR( grammar_macro->form_list->next->next->next);
	  generic_form_t parameters = CAR( grammar_macro->form_list->next->next);
	  char *funname_ = malloc( strlen( macro_name->name) + 30);
	  strcpy( funname_, macro_name->name);
	  strcat( funname_, "##grammar_macro");
	  Symbol funname = intern( funname_);
	  free( funname_);
	  
	  form_t exp_form = expand_macro( NULL, id_form( funname),
					    CONS( parameters,
						  CONS( body,
							NULL)));
	}
      /* XXX: fill grammar_macro_function_list. */
      *grammar_macro_function_list_ptr = NULL;
    }

  
  /* This is hacky; for now we just expand the grammars here.  */
  list_t grammar_list = gethash( SYMBOL( grammar), ht);

  list_t grammar_function_list = NULL;
  if(grammar_list)
    {
      grammar_function_list = expand_grammar_list( grammar_list);
    }

  
  /* This should use a precedence graph between type forms.  */
  /* First the user definitions( that expand into other definitions)
     should be expanded, then the types, then the expanders, then the
     functions, then the globals.  */

  list_t type_list = gethash( SYMBOL( type), ht);
  list_t type_alias_list = gethash( SYMBOL( type_alias), ht);
  type_list = reverse( nconc( type_list, type_alias_list));

  list_t expanded_type_list = NULL;
  if(type_list)
    expanded_type_list = expand_all_types( type_list);
  
  
  list_t expander_list = reverse(nconc( gethash( SYMBOL( attribute), ht),
					nconc( gethash( SYMBOL( macro), ht),
					       gethash( SYMBOL( expander), ht))));
  list_t expanded_expander_list = NULL;
  if( expander_list)
    expanded_expander_list = expand_all_misc( expander_list);

  /* Reverse of the funlist is necessary because we cannot compile
     functions when they are not in order.  */
     
  list_t funlist = reverse( gethash( SYMBOL( function), ht));
  list_t globlist = gethash( SYMBOL( global), ht);
  globlist = nconc( globlist, nconc( funlist, grammar_function_list));

  list_t expanded_fun_list = NULL;
  if(globlist)
    expanded_fun_list =  expand_all_function_and_global(globlist);

  return nconc( expanded_compile_time_list,
		nconc( expanded_type_list,
		       nconc( expanded_fun_list, expanded_expander_list)));
}




void
init_expand_define(void)
{
  define_definer( SYMBOL( expander), expand_expander);
  define_definer( SYMBOL( macro), expand_macro);
  define_definer( SYMBOL( attribute), expand_attribute);
}

#if 0
/* A hash symbol->definer.  */
MAKE_STATIC_HASH_TABLE( real_definer_hash);

list_t
expand_define(generic_form_t form)
{
  symbol_form_t function = CAR(form->form_list);
  if(function->value == SYMBOL(function))
    {
      symbol_form_t name_form = CAR(form->form_list->next);
      symbol_t name = name_form->value;
      
      form_t lambda_form = CAR(form->form_list->next->next);
      
      
      return define_form(SYMBOL(function),
			 name, expand(lambda_form));
    }
    assert( function->value == SYMBOL( global));
    symbol_form_t name_form = CAR(form->form_list->next);
    symbol_t name = name_form->value;

    form_t type_form = CAR( form->form_list->next->next);
    return define_form(SYMBOL(global),
		       name, type_form);
      
  //  return create_expanded_form(form, NULL);
  /* XXX: replace the body form by the expanded body form.  *///NO!!
}
#endif
