/* creator.c - Creator handling.
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

/* Creator are the standard high-level way to create new objects.
   To each Type is associated one creator.

   The creator is not the constructor: the constructor will often be a
   more easy to use wrapper around the creator. The creator does not
   have any notion of public and private field, whether the
   constructor has; and so on.


   XXX TODO:

   Int, Float, String creators.
   
   derived_creator, qui remplace Type_Derive(...)  par
   Type_Derive(Type_Dorigine(...)) (en gros appelle le creator du type
   d'origine et rajoute seulement un cast).

   struct_creator, qui inspecte que les arguments sont bien passés
   dans le bon ordre, ou alors les remet dans l'ordre (et insère des
   casts) pour que ca crée bien la struct que l'on veut creer

   pointer_creator, qui fait la meme chose mais récupère aussi le
   paramètre alloc.

   On aura aussi des creators attachés aux types construits, comme
   List(Int) Hash(Symbol, Int)

   Mon nouveau fichier de test est new-creator.l
   
   */

#include <assert.h>
#include <l/sys/type.h>
#include <l/sys/panic.h>
#include <l/form.h>
#include "../compiler/c-to-l.h"
#include <l/sys/hash.h>
#include <l/creator.h>

/* A creator is the way by which all objects of a certain types have
   to be created.  It handles memory allocation and assignment of the
   initial values.

   The constructor for a type (which is an expander) can be redefined,
   for instance because some values have a default, or some other are
   internal to the type and not exposed.

   But the constructor always remains accessible, and the association
   type->constructor is immutable.
 
   A Creator takes a type and a list of forms as an argument, and
   renders an expanded form.

   The idea is that Creators should be called that way (and they will
   one day):

     Creator(Int)(3);
     Creator(struct {Int x; Int y;})(y:3, x:4); //Notice the order can be reversed.
     Creator(Index)(3);               //Index is created with type Index = Int;
     Creator(Index2)(Index(3));       //and Index2 with type Index2 = Index;
     Creator(Point)(x:4, y:3);        //and type Point = struct{Int x; Int y;};
     Creator(Int *)(3);               //Handles allocation automatically by default,
     Creator(struct ... *)(x:4, y:5); //but it can be specified with the alloc param.
     Creator(Int_Ptr)(3);             //type Int_Ptr = Int *;
     Creator(Int_Ptr_Ptr)(3);         //type Int_Ptr = Int **;
     Creator(Point_Ptr)(x:3, y:4);    //type Point_Ptr = struct {Int x; Int y;}*;

   Note the difference between derived types' constructors: some
   derived types are constructed by passing an object of the type from
   which they are derived (e.g. Index, Index2, Int_Ptr), and some must
   be passed only the same parameters than their parent's constructor(
   Point, Point_Ptr).  In the later case, we say that the creator is
   directly derived from the other one, and in the former it is
   indirectly derived.

   By default, newly created types (created with type Nom_Type = ...)
   are assigned an expander that calls the appropriate Creator. For
   instance, you can then write:

     type Point = struct { Int x; Int y;} *;
     
     let ps = Point( x:3, y:4); //same as let ps = Creator (Point)( x:3, y:4);

   This expander function is the constructor of the type.  This
   constructor may be changed at will; but to create an object of type
   Point, it should nevertheless call the creator for Point.

   For pointer types (and those that derives from it), the creator
   also handles the allocation of the object. For instance:

     let Int * pi = Creator(Int *)( 3); // Creates an Int that contains 3
                                        // in the heap, and return its pointer.
     type Point = struct { Int x; Int y;} *;
     let ps = Point( x:3, y:4);

   Allocation can be specified with the alloc parameter, for instance:
     				      
     let p = Point(alloc:malloc, x:3, y:4);   //Use malloc
     let p = Point(alloc:stack, x:3, y:4);    //Replaces alloca
     let p = Point(alloc:refcount, x:3, y:4); //Use a reference counter
     let p = Point(alloc:marksweep, x:3, y:4);//Use a mark&sweep gc algorithm
     let p = Point(alloc:gc, x:3, y:4);       //Use the most appropriate gc
     let p = Point(alloc:auto, x:3, y:4);     //Use the best non-manual
                                              // allocation method.

   Without an alloc parameter, the default allocation method is
   auto. In the future, the default allocation method for a type will
   be specifiable when the type is created.
     
   Note that pointer objects can also be created by the ref (&)
   construct, but objects whose types are derived from pointer types
   cannot be created that way.
   That is:

   let Int i; let Int *pi = &i;  //OK
   type Int_Ptr = Int *;         //The only way to create an
                                 //Int_Ptr is to use its creator.
 */



/* Creator_hash is a hash Type->Creator.  */
MAKE_STATIC_HASH_TABLE (creator_hash)

/* The original creator for a type is always accessible through this
   function.  */
Creator
get_creator( Type t)
{
  Creator c = gethash (t, creator_hash);
  assert (c);
  return c;
}


void
define_creator( Type t, Creator c)
{
  puthash (t, c, creator_hash);
}

/* Derived creators.  */

expanded_form_t
direct_derived_creator( Base_Type t, list_t form_list);

expanded_form_t
indirect_derived_creator( Base_Type t, list_t form_list);

expanded_form_t
call_creator_same_name (generic_form_t form);

void
define_derived_creator( Base_Type t, Symbol name)
{
  assert( t->type_type == BASE_TYPE);
  define_expander (name, call_creator_same_name);

  Type type = t->origin_type;

  switch( type->type_type)
    {
      /* A derived creator for a BASE_TYPE must be called as in the
	 following example:
	 type Potato = Int;
	 type Fries = Potato;
	 let Fries f = Fries( Potato( 4));
	 and not: let Fries f = Fries( 4);
	     
	 This is because when you create a new type from a base_type,
	 you do it to differentiate it from the first one.
      */
    case BASE_TYPE:
      define_creator (t, indirect_derived_creator);

      return;
      /* For a derived struct type, it is called like that:
	 type Point = struct { Int x; Int y;};
	 let Point p = Point( x:3, y:4);
	 and not: let Point p = Point( struct { x:3, y:4};);
      */
    case STRUCT_TYPE:
      define_creator (t, direct_derived_creator);
      return;
      
      /* For a derived pointer, we rely on the pointer type creator. */
    case POINTER_TYPE:
      define_creator( t, direct_derived_creator);
      return;
	  
    default: panic( "Should not be reached\n");
    }
}

/* This is the creator for base types: Int, Float, String, later Word
   (when we can parse hexa). It is used of the form: Type(value),
   where value is of type Type. We check that value is indeed of type
   Type.

   This creator is not here only for completeness; it is also used as
   a base for use by derived creators.  */
expanded_form_t
base_type_creator( Type to_type, list_t form_list)
{
  assert (form_list && !form_list->next);

  form_t expression = CAR( form_list);
  
  expanded_form_t expanded_exp = expand (expression);

  assert (to_type->type_type == BASE_TYPE);
  
  if(to_type != expanded_exp->type)
    panic ("%s given where %s expected\n",
	   asprint_type (expanded_exp->type),
	   asprint_type (to_type));

  return expanded_exp;
}


/* Takes a struct_type_form, a form, and returns an expanded_form list
   that looks like (label1:expanded_form1, label2:expanded_form2),
   where expanded_form1 is the type of label1 of the struct, and the
   labels appear in the order of the struct.

   If tail is not NULL, returns the unparsed elements of FORM in tail,
   else throw an error if there are any left.
*/
   
static list_t
check_struct_parameters( generic_form_t struct_type_form,
			 list_t form_list,
			 list_t *tail)
{
  list_t element;

  list_t expression_list;
  {
    list_t *expression_list_ptr = &expression_list;

    list_t cur_type = struct_type_form->form_list;
    element = form_list;
    for(cur_type = struct_type_form->form_list;
	cur_type;
	cur_type = cur_type->next)
      {
	if(element == NULL)
	  panic ("Not enough elements given\n");
	
	generic_form_t expression = CAR (element);
	expanded_form_t expanded_exp = expand (expression);
	element = element->next;
	
	/* Get the expanded form's label.  */
	id_form_t exp_id_form = CAR (expression->form_list);
	assert (is_form (exp_id_form, id_form));
	Symbol exp_label = exp_id_form->value;

	/* Get the type label.  */
	generic_form_t type_form = CAR (cur_type);
	id_form_t type_id_form = CAR (type_form->form_list);
	assert (is_form (type_id_form, id_form));
	Symbol type_label = type_id_form->value;

	if(exp_label != type_label)
	  panic ("Label mismatch\n");

	/* Check type.  */
	type_check (intern_type (CAR (type_form->form_list->next)),
		    expanded_exp->type);
	
	*expression_list_ptr = CONS (expanded_exp, NULL);
	expression_list_ptr = &((*expression_list_ptr)->next);
      }

    *expression_list_ptr = NULL;
  }

  if(tail)
    *tail = element->next;
  else if(element != NULL)
    panic ("Some elements given are not in the struct\n");

  return expression_list;
}


expanded_form_t
struct_creator (Type type, list_t form_list)
{
  assert( type->type_type == STRUCT_TYPE);
  generic_form_t struct_type_form = type->type_form;

  list_t expression_list = check_struct_parameters (struct_type_form,
						    form_list,
						    NULL);
  
  expanded_form_t struct_form = create_expanded_form (generic_form_symbol (SYMBOL (struct),
									   expression_list),
						      type);
}

/* A helper function for the *_pointer_creator functions.  */
static expanded_form_t
create_pointed_form( Pointer_Type pointer_type,
		     expanded_form_t exp_form)
{
  Type pointed_type = pointer_type->pointed_type;
    /* Now return the complete form, that allocates the memory.
     i.e., do something like
     { let Pointed_Type *_temp;
       _temp = ( Pointed_Type *) GC_alloc( Pointed_Type.size);  (or malloc, or alloca ...)
       *_temp = $exp_form; where exp_form is the creator for the pointed_type
       (Type) temp }
  */
  type_form_t pointed_type_form = pointed_type->type_form;
  type_form_t pointer_type_form = generic_form_symbol( SYMBOL( pointer),
						       CONS( pointed_type_form, NULL));
  id_form_t temp_id_form = id_form( gensym( "pointer_alloc"));

  form_t let_f = generic_form_symbol( SYMBOL( let),
				      CONS( pointer_type_form,
					    CONS( temp_id_form,
						  NULL)));

  form_t alloc_form = generic_form_symbol( intern( "="),
					   CONS( temp_id_form,
						 CONS( generic_form_symbol( SYMBOL( cast),
									    CONS( pointer_type_form,
										  CONS( generic_form_symbol( SYMBOL( GC_alloc),
													     CONS( int_form( pointed_type->size),
														   NULL)),
											NULL))),
						       NULL)));

  form_t assign_form = generic_form_symbol( intern( "="),
					    CONS( generic_form_symbol( SYMBOL( deref),
								       CONS( temp_id_form,
									     NULL)),
						  CONS( exp_form,
							NULL)));

  form_t result_form = generic_form_symbol( SYMBOL( cast),
					    CONS( pointer_type->type_form,
						  CONS( temp_id_form,
							NULL)));

  form_t all_form = generic_form_symbol( SYMBOL( block),
					 CONS( let_f,
					       CONS( alloc_form,
						     CONS( assign_form,
							   CONS( result_form,
								 NULL)))));
  return expand( all_form);
}


expanded_form_t
indirect_pointer_creator( Type type_, list_t argument_list)
{
  Pointer_Type type = type_;
  assert( type->type_type == POINTER_TYPE);
  
  /* For now, we force alloc: to be eventually the first parameter.
     In the future, we should rework this function to remove this
     limitation.  */

  
  /* By default, we use garbage collected memory.  But we should use
     gc by default for symbols created with record, and malloc for
     symbols created with struct ... *.  */
  Symbol alloc_symbol = SYMBOL( gc);

  assert( argument_list);
  generic_form_t gform = CAR( argument_list);
  if( is_form( gform, generic_form))
    {
      if( gform->head == SYMBOL( label))
	{
	  assert( gform->form_list);
	  assert( gform->form_list->next);
	  id_form_t label_id = CAR( gform->form_list);
	  assert( is_form( label_id, id_form));
	  if( label_id->value == SYMBOL( alloc))
	    {
	      /* We should handle this generally, so that new
		 allocateurs can be constructed.  For now, we check
		 that the alloc is one of gc or malloc.  */
	      id_form_t alloc_id = CAR( gform->form_list->next);
	      alloc_symbol = alloc_id->value;

	      assert( alloc_symbol == SYMBOL( gc)
		      || alloc_symbol == SYMBOL( malloc)
		      || alloc_symbol == SYMBOL( auto));
	      argument_list = argument_list->next;
	    }
	}
    }

  /* There should be only one remaining argument.  */
  assert( argument_list && !argument_list->next);

  form_t object_form = CAR( argument_list);
  expanded_form_t exp_object_form = expand( object_form);

  type_check( exp_object_form->type, type->pointed_type);

  return create_pointed_form( type, exp_object_form);
}

expanded_form_t
direct_pointer_creator( Type type_, list_t argument_list)
{
  Pointer_Type type = type_;
  assert( type->type_type == POINTER_TYPE);
  
  /* For now, we force alloc: to be eventually the first parameter.
     In the future, we should rework this function to remove this
     limitation.  */

  
  /* By default, we use garbage collected memory.  But we should use
     gc by default for symbols created with record, and malloc for
     symbols created with struct ... *.  */
  Symbol alloc_symbol = SYMBOL( gc);

  assert( argument_list);
  generic_form_t gform = CAR( argument_list);
  if( is_form( gform, generic_form))
    {
      if( gform->head == SYMBOL( label))
	{
	  assert( gform->form_list);
	  assert( gform->form_list->next);
	  id_form_t label_id = CAR( gform->form_list);
	  assert( is_form( label_id, id_form));
	  if( label_id->value == SYMBOL( alloc))
	    {
	      /* We should handle this generally, so that new
		 allocateurs can be constructed.  For now, we check
		 that the alloc is one of gc or malloc.  */
	      id_form_t alloc_id = CAR( gform->form_list->next);
	      alloc_symbol = alloc_id->value;

	      assert( alloc_symbol == SYMBOL( gc)
		      || alloc_symbol == SYMBOL( malloc)
		      || alloc_symbol == SYMBOL( auto));
	      argument_list = argument_list->next;
	    }
	}
    }


  /* Calls the pointed type's creator, without the alloc argument if
     it was present.  */
  Type pointed_type = type->pointed_type;
    
  Creator cr = get_creator( pointed_type);
  expanded_form_t exp_form = cr( pointed_type, argument_list);

  return create_pointed_form( type, exp_form);
}

/* Indirect-derived creators must be passed an object of the type from
   which it is derived as an argument.

   For instance:
   type Potato = Int;
   type Banana = Potato;
   let Banana b = Banana( Potato( 3));

   This is extended for handling the pointers, too:

   type Potato = Int;
   type Banana = Potato **;
   let Banana b = Banana( Potato( 3)); 
   
   */
expanded_form_t
indirect_derived_creator( Base_Type t, list_t form_list)
{
  assert( t->type_type == BASE_TYPE);
  assert( t->type_form);

  int num_indirection = 0;
  Type argument_type = t->origin_type;

  assert( form_list && !form_list->next);
  expanded_form_t exp_form = expand( CAR( form_list));
  type_check( argument_type, exp_form->type);

  if( num_indirection > 0)
    {
      Creator cr = get_creator( t->origin_type);
      exp_form = cr( t->origin_type, CONS( exp_form, NULL));
    }
  
  return create_expanded_form( generic_form_symbol( SYMBOL( cast),
						    CONS( create_expanded_form( t->type_form,
										TYPE( "Type")),
							  CONS( exp_form,
								NULL))),
			       t);
}

/* Direct derived creators must be passed the same argument list as an
   argument.

   For instance:
   type Potato = Int;
   type Banana = Potato;
   let Banana b = Banana( 3);

*/
expanded_form_t
direct_derived_creator( Base_Type t, list_t form_list)
{
  assert( t->type_type == BASE_TYPE);
  assert( t->origin_type);
  assert( t->type_form);

  Creator cr = get_creator( t->origin_type);

  expanded_form_t exp_form = cr( t->origin_type, form_list);
  
  return create_expanded_form( generic_form_symbol( SYMBOL( cast),
						    CONS( create_expanded_form( t->type_form,
										TYPE( "Type")),
							  CONS( exp_form,
								NULL))),
			       t);
}

/* This expander takes a form like Point(....), and will call the
   creator for the type Point.  */
expanded_form_t
call_creator_same_name (generic_form_t form)
{
  assert (is_form (form, generic_form));
  Symbol to_type_symbol = form->head;

  Base_Type to_type = intern_type (id_form (to_type_symbol));

  Creator cr = get_creator (to_type);

  expanded_form_t exp_form = cr (to_type, form->form_list);

  /* For the sake of speed, we can mandate that creators return expanded forms.  */
  assert( is_form( exp_form, expanded_form));
  return exp_form;
}

/* This does not really belong here, but whatever.  */
void *
GC_alloc( size_t size)
{
  return xmalloc( size);
}

void
init_creator ()
{
  define_creator (TYPE ("Int"), base_type_creator);
  define_expander (SYMBOL (Int), call_creator_same_name);

  define_creator (TYPE ("String"), base_type_creator);
  define_expander (SYMBOL (String), call_creator_same_name);

  define_creator (TYPE ("Symbol"), base_type_creator);
  define_expander (SYMBOL (Symbol), call_creator_same_name);

  DEFINE_C_FUNCTION( GC_alloc, "Void * <- Int");
}
