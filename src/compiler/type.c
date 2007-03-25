/* type.c - Type manipulations
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

/* Type handling is common to the compiler and expander part.  The
   difference is that the compiler part ensures test equality when
   necessary (function calls and affectations), whereas the expander
   part allows subtyping and coercion.  */


//XXX: reexpliquer
/* Type handling needs three type of operations.

   Type mangling means transformation of the type representation to a
   small string (this transformation is at least an injective
   function).  This small string is then used in a hash table; this is
   the basis for testing type equality.  For now, type mangling means
   type printing; but this may change (for performance reasons) in the
   future.

   Type making min makes the type, and calculates the size and
   alignement constraints of the type. These functions must end as
   soon as they can; for instance, there is no need for a pointer type
   to calculate the size of its subtypes.


   These three operations must be defined for all type
   constructors. The basic type constructors are: pointer, struct,
   tuple, function.  Any other type constructor can be constructed
   using these for ones.

   


   Separation of size and alignment calculating from type making is
   necessary due to recursive types.

   For instance:

   type Int_List = struct { Int i; Int_List l; } *;

   You need to know that size of Int_List is sizeof(void *) before
   constructing the type.

   Rule is: you cannot construct a type until you know its size.

*/




#include "../parser/form.h"
#include <l/sys/type.h>
#include <l/sys/creator.h>
#include <string.h>
#include <assert.h>

#define compile_error panic
#define compile_warning panic


#define panic(format, ...)						\
  do { fprintf (stderr, format, ## __VA_ARGS__);			\
    asm("int $3"); } while(0)

/* This defines a "write" buffer.  */
typedef struct buffer { char *start; char *end; char *current; } *Buffer;
void
buffer_putchar (Buffer buffer, char c)
{
  if(buffer->current >= buffer->end)
     panic ("Buffer too short\n"); /* XXX: realloc a new buffer.  */

  *buffer->current++ = c;
}

void
buffer_puts (Buffer buffer, char *str)
{
  unsigned int len = strlen (str) + 1;
  if(buffer->current + len >= buffer->end)
    panic ("Buffer too short\n");

  memcpy (buffer->current, str, len);

  buffer->current += (len - 1);
}


/* Type form printing function.  */

/* A symbol->Type_Printer hash. */
MAKE_STATIC_HASH_TABLE (print_type_hash);

#define buffer_too_short()			\
  do {panic ("Buffer too short\n"); } while(0)

void
bprint_type (Buffer buffer, form_t form)
{
  unsigned int cur_size = buffer->end - buffer->current;
  
  if(is_form (form, id_form))
    {
      symbol_t symbol = ((id_form_t) form)->value;
      buffer_puts (buffer, symbol->name);

      return;
    }

  assert (is_form (form, generic_form));

  symbol_t head = ((generic_form_t) form)->head;

  Type_Printer tp = (Type_Printer) gethash (head, print_type_hash);

  if(tp == NULL)
    panic ("Unknown type printer: %s\n", head->name);

  tp (buffer, (form_t) form);

  *buffer->current = 0;
}

void
bprint_type_tuple (Buffer buffer, generic_form_t form)
{
  
  buffer_putchar (buffer, '(');

  FOREACH (element, form->form_list)
    {
      form_t subform = CAR (element);

      bprint_type (buffer, subform);

      if(element->next)
	buffer_putchar (buffer, ',');
    }

  buffer_putchar (buffer, ')');
}

void
bprint_type_function (Buffer buffer, generic_form_t form)
{
  form_t return_form = CAR (form->form_list);
  form_t parameters_form = CAR (form->form_list->next);

  bprint_type (buffer, return_form);
  buffer_putchar (buffer,'<');
  buffer_putchar (buffer,'-');

  bprint_type (buffer, parameters_form);

  // printf ("FUNCTION TYPE: %s\n", buffer->start);
}

void
bprint_type_struct (Buffer buffer, generic_form_t form)
{
  buffer_puts (buffer, "struct{");
  
  FOREACH (element, form->form_list)
    {
      generic_form_t label_form = CAR(element);
      assert(is_form(label_form, generic_form));
      assert(label_form->head == SYMBOL(label));
      form_t type = CAR(label_form->form_list->next);
      id_form_t idf = CAR (label_form->form_list);
      symbol_t name =  idf->value;

      bprint_type (buffer, type);
      buffer_putchar (buffer, ' ');
      buffer_puts (buffer, name->name);
      buffer_putchar (buffer, ';');
    }

  buffer_putchar (buffer, '}');
}

void
bprint_type_pointer (Buffer buffer, generic_form_t form)
{
  form_t subform = CAR (form->form_list);
  
  bprint_type (buffer, subform);
  buffer_putchar (buffer, '*');
}

void
bprint_type_label (Buffer buffer, generic_form_t form)
{
  id_form_t label = CAR (form->form_list);
  form_t subform = CAR (form->form_list->next);
//
//  buffer_puts (buffer, label->value->name);
//  buffer_putchar (buffer, ':');
  bprint_type (buffer, subform);
}

void
bprint_type_misc (Buffer buffer, generic_form_t form)
{
  buffer_puts (buffer, form->head->name);
  buffer_putchar (buffer, '(');

  FOREACH (element, form->form_list)
    {
      form_t type = CAR (element);

      bprint_type (buffer, type);
      if(element->next)
	buffer_putchar (buffer, ',');
    }

  buffer_putchar (buffer, ')');
}




void
print_type (form_t form)
{
  struct buffer buf;
  
  char the_buf[1024];

  buf.start = the_buf;
  buf.end = the_buf + 1024;
  buf.current = the_buf;

  bprint_type (&buf, form);

  printf ("%s\n",the_buf);
  
}

char *
asprint_type_form (form_t form)
{
  struct buffer buf;
  
  char* the_buf = malloc (1024);

  buf.start = the_buf;
  buf.end = the_buf + 1024;
  buf.current = the_buf;

  bprint_type (&buf, form);

  return the_buf;
}


char *
asprint_type (Type t)
{
  asprint_type_form (t->type_form);
}


  


//For a pointer: returns 4,4.

//For a tuple: throw an error.

//For a function: throw an error too.

//For a struct: calculates the size and alignement of all its
//components.  

//For misc types: for now, transforms the type form and calculate the
//size from it.


//It would be nice if the struct operation for calculating types need
//not be performed twice.

//IDEE: quand on met une valeur a un type, ca peut etre SIZE_UNKNOWN
//ou SIZE_BEING_CALCULATED (resp -1 et -2); si on retombe sur being
//calculated c'est la l'erreur.

//Dans get_type, on calcule et on en interne le plus possible.
//Dans un deuxième temps, on calcule et on interne tout le reste.

//




/* Maximum type making.  */

/* On peut creer le type en une seule passe: on passe le type qu'on
   est en train de creer a la fonction */


/* En fait il faut :

   -Un ensemble de fonctions pour afficher le type

   -On se sert de ca pour faire une fonction intern type

   -On utilise la fonction intern_type pour construire le type.
*/

Type intern_type (struct type_form * form);

/* A hash symbol->Type_Maker */
MAKE_STATIC_HASH_TABLE (make_type_hash);


static Type
make_type_tuple (generic_form_t form)
{
  tuple_type_t type = MALLOC (tuple_type);
  unsigned int len = length (form->form_list);
  type->length = len;
  type->fields = xmalloc (len * sizeof(Type));
  
  int i = 0;
  for (list_t element = form->form_list;
       element ;
       element = element->next)
    {
      type->fields[i++] = intern_type (CAR (element));
    }
  
  type->size = -1;
  type->alignment = -1;
  type->type_form = form;
  type->type_type = TUPLE_TYPE;
  
  return type;
  
}

static Type
make_type_function (generic_form_t form)
{
  form_t return_form = CAR (form->form_list);
  form_t parameters_form = CAR (form->form_list->next);

  function_type_t type = MALLOC (function_type);
  type->size = -1;
  type->alignment = -1;
  type->type_form = form;
  type->return_type = intern_type (return_form);
  type->parameters_type = intern_type (parameters_form);
  type->type_type = FUNCTION_TYPE;
  //type->parameters_type = intern_type (form->type_form_list);
  return type;
}

#include <l/access.h>

static Type
make_type_struct (generic_form_t form)
{
  Struct_Type type = MALLOC (struct_type);
  unsigned int current_offset = 0;

  hash_table_t field_hash = make_hash_table ();
  
  FOREACH (element, form->form_list)
    {
      generic_form_t label_form = CAR(element);
      assert(is_form(label_form, generic_form));
      assert(label_form->head == SYMBOL(label));
      form_t type_form = CAR(label_form->form_list->next);
      id_form_t idf = CAR (label_form->form_list);
      
      offset_type_t ot = MALLOC (offset_type);
      
      Type field_type = intern_type (type_form);
      
      //XXX: handle alignment
      
      ot->offset = current_offset;
      current_offset += field_type->size;
      
      ot->type = field_type;
      
      puthash (idf->value, ot, field_hash);
    }
  
  type->size = current_offset;
  type->alignment = -1;
  type->type_form = form;

  type->type_type = STRUCT_TYPE;
  type->field_hash = field_hash;

  define_accesser (type, struct_accesser);
  define_left_accesser (type, struct_left_accesser);
  define_creator (type, struct_creator);
  return type;
}

/* Are we defining types, in which case the handling of pointer types
   has to be delayed to handle recursive definition. Outside of
   definitions, it is impossible to have recursive types, so it is
   safe to define the pointer type immediately.  */
static int is_defining_type;

/* The list of types that were not made because of recursive types.  */
static list_t uncomplete_types;


/* The handling of pointer types has to be split when handling the definition
   of a recursive type.   This is the last part.  */
static Type
finish_type_pointer( Pointer_Type type)
{
  assert( type->type_type == POINTER_TYPE);
  
  generic_form_t type_form = type->type_form;
  form_t pointed_type_form = CAR (type_form->form_list);
  
  type->pointed_type = intern_type( pointed_type_form);

  /*  Finish the pointed type.  */
  define_accesser (type, pointer_accesser);
  define_left_accesser (type, pointer_left_accesser);

  /* For a pointer, it depends on what you point on.
     type Fries = Potato *;
     let Fries f = Fries( Potato( 4)); should work
     let Fries f = Fries( 4); should not.
     
     type Fries_Ptr = Potato **;
     let Fries_Ptr f = Fries_Ptr( Potato( 4)); take the same argument as Fries
     
     type Point = struct { Int x; Int y;} *;
     let Point p = Point( x:3, y:4);
  */
  if( type->pointed_type->type_type == BASE_TYPE)
    define_creator (type, indirect_pointer_creator);
  else define_creator (type, direct_pointer_creator);

  return type;
}


static Type
make_type_pointer (generic_form_t form)
{
  Pointer_Type type = MALLOC (pointer_type);

  type->size = sizeof(void*);
  type->alignment = __alignof__ (void *);
  type->type_form = form;

  type->type_type = POINTER_TYPE;

  if(is_defining_type)
    {
      type->pointed_type = NULL;

      /* We did not calculated the pointed type, so it is yet uncomplete.  */
      uncomplete_types = CONS( type, uncomplete_types);
      return type;
    }
  
  return finish_type_pointer( type);
}

static Type
make_type_label (generic_form_t form)
{
  id_form_t label = CAR (form->form_list);
  generic_form_t subform = CAR (form->form_list->next);

  return intern_type (subform);
}


Pointer_Type
get_pointer_type (Type ptype)
{
  return intern_type (indirection_type_form (ptype->type_form));
}

Type
get_pointed_type (Pointer_Type type)
{
  if(type->type_type != POINTER_TYPE)
    compile_error ("Trying to get pointed type of something that is not a pointer\n");

  return type->pointed_type;
}

static Type
make_type (generic_form_t form)
{
  if(!is_form (form, generic_form))
    {
      /* We are using an unknown type.  */
      assert (is_form (form, id_form));
      panic ("Type %s is not known\n", asprint_type_form (form));
    }

  
  symbol_t head = ((generic_form_t) form)->head;

  Type_Maker tm = gethash (head, make_type_hash);

  if(tm == NULL)
    panic ("Unknown type generator: %s\n", head->name);

  return tm (form);
}


//MAKE_STATIC_HASH_TABLE (string_to_type_hash);
static Pvoid_t string_to_type = (Pvoid_t) NULL;

Type
associate_type_with_type_form( struct type_form *form,
			       Type type)
{
  struct buffer buf;
    
  char the_buf[1024];

  buf.start = the_buf;
  buf.end = the_buf + 1024;
  buf.current = the_buf;

  bprint_type (&buf, form);

  Type *PValue;

  JSLG (PValue, string_to_type, buf.start);

  if(PValue)
    {
      assert (*PValue);
      return *PValue;
    }
 
  assert(type->size != 0);
  JSLI (PValue, string_to_type, buf.start);
  assert (PValue);
  assert (*PValue == NULL || *PValue==type); /* XXX: Hack when pre-creating.  */
  *PValue = type;

  return type;
}


Type intern_type (struct type_form * form)
{
  struct buffer buf;
    
  char the_buf[1024];

  buf.start = the_buf;
  buf.end = the_buf + 1024;
  buf.current = the_buf;

  bprint_type (&buf, form);

  Type *PValue;

  JSLG (PValue, string_to_type, buf.start);

  if(PValue)
    {
      assert (*PValue);
      return *PValue;
    }

  Type type = make_type( form);
  
  assert(type->size != 0);
  JSLI (PValue, string_to_type, buf.start);
  assert (PValue);
  assert (*PValue == NULL || *PValue==type); /* XXX: Hack when pre-creating.  */
  *PValue = type;

  return type;
}


Type TYPE (const char *name)
{
  return intern_type (string_to_type_form (name));
}

/* Interns the type, but does not fill its attributes.  */
static Base_Type
pre_create_type (struct type_form *form)
{
  struct buffer buf;
    
  char the_buf[1024];

  buf.start = the_buf;
  buf.end = the_buf + 1024;
  buf.current = the_buf;

  bprint_type (&buf, form);

  Type *PValue;

  JSLG (PValue, string_to_type, buf.start);

  if(PValue)
    compile_error ("Error: calling pre_create_type on an already defined type form, %s\n", buf.start);

  /* When creating a new type, it is either of the form "Symbol" or
     Type_Cons(Symbol1, Symbol2, ...)

     In any case, we create a base type.  */

  Base_Type type = MALLOC (base_type);

  type->type_type = BASE_TYPE;
  type->type_form = form;
  type->size = ~(~0L >> 1); /* The littlest negative number  */
  type->alignment = -1;

  JSLI (PValue, string_to_type, buf.start);
  assert (PValue);
  assert (*PValue == NULL);
  *PValue = type;

  return type;
}


/* Defines a new type.  COMES_FROM may be NULL; if not, the new type
   should have the same sizes and alignments than the old one. */

Type
define_type_type_form (type_form_t tf, unsigned int size,
		       unsigned int alignment, type_form_t comes_from)
{
  Base_Type new_type;

  Type old_type = NULL;
  
  if(comes_from)
    {
      /* Now, precalculate the real size of the type.  This makes the
	 types recursively, unless it encounters a pointer (in which
	 case the type is made, but the sub types of the pointer is
	 not made.)  This is necessary for defining recursive types.
      */

      int save_is_defining_type = is_defining_type;
      is_defining_type = 1;
      list_t save_uncomplete_types = uncomplete_types;
      uncomplete_types = NULL;
      
      old_type = intern_type (comes_from);

      new_type = pre_create_type (tf);
      /* Size and alignment should not be passed when a originator
	 form is given.  */
      new_type->size = old_type->size;
      new_type->alignment = old_type->alignment;
      new_type->origin_type = old_type;

      /* Now finish all the uncomplete types.  */
      /* Note : for handling doubly recursive types, all the uncomplete types
	 should just be handled at the end, when all types are defined. */
      list_t this_uncomplete_types = uncomplete_types;
      uncomplete_types = NULL;
      is_defining_type = 0;
      
      FOREACH( element, this_uncomplete_types)
	{
	  Pointer_Type type = CAR( element);
	  finish_type_pointer( type);
	}
      
      uncomplete_types = save_uncomplete_types;
      is_defining_type = save_is_defining_type;
      return new_type;
    }

  new_type = pre_create_type( tf);
  new_type->origin_type = old_type;
  new_type->size = size;
  new_type->alignment = alignment;
  assert( uncomplete_types == NULL);


  return new_type;
}

Type define_type_string (char *name, unsigned int size,
			 unsigned int alignment, type_form_t comes_from)
{
  type_form_t tf = string_to_type_form (name);
  define_type_type_form (tf, size, alignment, comes_from);
}




void
define_type_constructor (Symbol name,
			 Type_Printer print_function,
			 Type_Maker make_function)
{
  puthash (name, print_function, print_type_hash);
  puthash (name, make_function, make_type_hash);
}

void
new_init_type ()
{
  is_defining_type = 0;
  uncomplete_types = NULL;
  define_type_constructor (SYMBOL (tuple),
			   bprint_type_tuple, make_type_tuple);
  define_type_constructor (SYMBOL (function), bprint_type_function,
			   make_type_function);
  define_type_constructor (SYMBOL (struct),
			   bprint_type_struct, make_type_struct);
  define_type_constructor (SYMBOL (pointer),
			   bprint_type_pointer, make_type_pointer);
  define_type_constructor (SYMBOL (label),
			   bprint_type_label, make_type_label);
}
