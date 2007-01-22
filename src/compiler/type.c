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
#include <l/type.h>
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

typedef void (*Type_Printer)(Buffer, form_t);

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
    panic ("Unknown type generator: %s\n", head->name);

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
asprint_type (form_t form)
{
  struct buffer buf;
  
  char* the_buf = malloc (1024);

  buf.start = the_buf;
  buf.end = the_buf + 1024;
  buf.current = the_buf;

  bprint_type (&buf, form);

  return the_buf;
}


#if 0
/* Minimum type making.  */

/* A Min_Type_Maker returns the Type it made, and a list of types to
   finish later */
typedef Type (*Min_Type_Maker)(generic_form_t, list_t *);

Type intern_type (struct type_form * form);

/* A hash symbol->Min_Type_Maker */
MAKE_STATIC_HASH_TABLE (make_type_min_hash);


Type
min_make_type (generic_form_t form, list_t *to_make_list)
{
  assert (is_form (form, generic_form));
  
  symbol_t head = ((generic_form_t) form)->head;

  Min_Type_Maker tm = gethash (head, make_type_min_hash);

  if(tm == NULL)
    panic ("Unknown type generator: %s\n", head->name);

  return tm (form, to_make_list);
}


Type
min_make_tuple_type (generic_form_t form, list_t *to_make_list)
{
  compile_error ("Error in type: shouldn't be reached.\n");
}

Type
min_make_function_type (generic_form_t form, list_t *to_make_list)
{
  compile_error ("Error in type: shouldn't be reached.\n");
}

Type
min_make_pointer_type (generic_form_t form, list_t *to_make_list)
{
  Pointer_Type type = MALLOC (pointer_type);

  form_t type_form = CDR (CAR (form->form_alist));

  type->size = sizeof(void*);
  type->alignment = __alignof__ (void *);
  type->type_form = form;
  
  type->pointed_type = NULL;

  type->type_type = POINTER_TYPE;

  *to_make_list = CONS (type, *to_make_list);
  
  return type;
}

Type
make_type_struct (generic_form_t form);

Type
min_make_struct_type_min (generic_form_t form, list_t *to_make_list)
{
  return make_type_struct (form);
}



#endif
  


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

typedef Type (*Type_Maker)(generic_form_t);

Type intern_type (struct type_form * form);

/* A hash symbol->Type_Maker */
MAKE_STATIC_HASH_TABLE (make_type_hash);


Type
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

Type
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

Type
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
  return type;
}

Type
make_type_pointer (generic_form_t form)
{
  Pointer_Type type = MALLOC (pointer_type);

  form_t type_form = CAR (form->form_list);

  type->size = sizeof(void*);
  type->alignment = __alignof__ (void *);
  type->type_form = form;
  
  type->pointed_type = intern_type (type_form);

  type->type_type = POINTER_TYPE;

  return type;
}

Type
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

Type
make_type (generic_form_t form)
{
  if(!is_form (form, generic_form))
    {
      /* We are using an unknown type.  */
      assert (is_form (form, id_form));
      panic ("Type %s is not known\n", asprint_type (form));
    }

  
  symbol_t head = ((generic_form_t) form)->head;

  Type_Maker tm = gethash (head, make_type_hash);

  if(tm == NULL)
    panic ("Unknown type generator: %s\n", head->name);

  return tm (form);
}


//MAKE_STATIC_HASH_TABLE (string_to_type_hash);
static Pvoid_t string_to_type = (Pvoid_t) NULL;

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

  Type type = make_type (form);

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

/* This creates a type according to the type form, but:

    - It does not recurse
    
    - It does not calculate size and alignement, just indicate that
      they are unknown.
   */
Base_Type pre_create_type (struct type_form *form)
{
  printf ("Pre creating\n");
  lispify (form);
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

Type define_type_type_form (type_form_t tf, unsigned int size,
			    unsigned int alignment, type_form_t comes_from)
{
  Base_Type new_type = pre_create_type (tf);

  Type old_type = NULL;
  
  if(comes_from)
    {
      old_type = intern_type (comes_from);

      /* This detects that the size of the type couldn't be
	 calculated.  But for now, it catches too much errors, because
	 the struct it uses could be defined later.  */
      if(old_type->size & ~(~0L >> 1))
	compile_error ("Error: Defining a recursive type that"
		       "does not go through a pointer\n");

      /* Size and alignment should not be passed when a originator
	 form is given.  */
      size = old_type->size;
      alignment = old_type->alignment;
    }

  new_type->origin_type = old_type;
  new_type->size = size;
  new_type->alignment = alignment;

  return new_type;
  
    /* First, pre_creates the type.  Hum in fact, to support doubly
       recursive structure definitions, this step should be done
       earlier, at analysis time.  Or maybe we could patch types.  No
       no.

       What we should do if: is we depend on a type that is not yet
       defined, just precreate the current one; and make it completly
       later (put it into a patch list).

       */
}

Type define_type_string (char *name, unsigned int size,
			 unsigned int alignment, type_form_t comes_from)
{
  type_form_t tf = string_to_type_form (name);
  define_type_type_form (tf, size, alignment, comes_from);
  
}



/* XXX: temporary, should be defined in L.  Needed for generic
   definition.  */

/* XXX: we need recursive types to do it in fact; we can't do it
   otherwise.  In fact, a List(Int) is a BASE_TYPE pointing to a
   recursive struct.  The operations on lists make the necessary
   casts.  */

/* List(Int) is defined as:

   type List(Int) = struct { Int car; List(Int) cdr; } *;
*/
Type
make_type_List (generic_form_t form)
{
  Base_Type the_type = pre_create_type(form);

  form_t type_listed = CAR(form->form_list);

  form_t value_form = 
    generic_form_symbol(SYMBOL(pointer),
			CONS(generic_form_symbol(SYMBOL(struct),
						 CONS(label_form_symbol(SYMBOL(head),
									type_listed),
						      CONS(label_form_symbol(SYMBOL(tail),
									     form),
							   NULL))),
			     NULL));

/* Note that List(Int) is not an alias to the struct, but a different
   type; this makes usage of acessor macros for list elements
   mandatory.

   This isn't necessasrily cumbersome; the form
   let first -> second -> rest = list
   is quite elegant.  */


  Type type = intern_type (value_form);
  
  assert(!(type->size & ~(~0L >> 1)));

  /* Due to the fact that we use symbols as indexes for type hash,
     we must use a generated symbol in the type hash.

     Instead, we should not use the type hash at all, and use the
     "pointed type" function in the BASE_TYPE.  */

  /* XXX: make the_type points to type.  */
  assert(the_type->type_type == BASE_TYPE);

  /* XXX: Make a function derive_new_type or smthg.  */
  the_type->origin_type = type;
  the_type->size = type->size;
  the_type->alignment = type->alignment;


//  DEFINE_TYPE_SYMBOL (name, new_type, type->size, type->alignment);

  //panic ("To implement\n");
  return the_type;
}











#define DEFINE_TYPE_CREATOR(name)		\
  do {						\
    puthash (SYMBOL (name), bprint_type_##name, print_type_hash);	\
    puthash (SYMBOL (name), make_type_##name, make_type_hash);		\
  } while(0)

void
new_init_type ()
{
  DEFINE_TYPE_CREATOR (tuple);
  DEFINE_TYPE_CREATOR (function);
  DEFINE_TYPE_CREATOR (struct);
  DEFINE_TYPE_CREATOR (pointer);
  DEFINE_TYPE_CREATOR (label);
  
  puthash (SYMBOL (List), bprint_type_misc, print_type_hash);
  puthash (SYMBOL (List), make_type_List, make_type_hash);
}










#if 0
/* The algorithm for creating types has two pass:

   1/First pass: we compute the size and alignement for each type
   defined, for which they are not yet computed.

   2/We construct the type.

As each recursive type must pass through a pointer indirection, we are
guaranteed to finish.

Ex: 
type Int_List = struct { int i; Int_List next; } *;    Immediatly finds that Int_List is of size 4, then constructs it.
type Int_List2 = struct { int i; Int_List2 *next; };   Finds that Int_List2 *is of size 4, then constructs Int_List.
*/

/* Takes a form alist and gives back the size and the alignment.  */

/* XXX: takes also the type for which it is used.  */
typedef unsigned int (*size_alignment_function_t)(type_t, unsigned int *, generic_form_t);

typedef struct type_constructor
{
  size_alignment_function_t get_size_alignment;
}  *Type_Generator;

/* A hash Symbol->Type_Generator */
MAKE_STATIC_HASH_TABLE (type_generator_hash);

/*XXX: appeler ces functions des type generators. Voir la page de cforall*/


/* Size and alignement functions.  */

unsigned int
compile_type_get_size_alignment(unsigned int *p_alignment, form_t form)
{
  if(is_form(form, atomic_form))
    {
      if(!is_form(form, id_form))
	compile_error("Cannot get size and alignment of %s\n", lispify(form));

      symbol_t symbol = ((id_form_t) id)->value;
      type_t type = gethash(symbol, type_hash);  /* XXX: Non, il peut y avoir des variables temporaires?*/

      *p_alignment = type->alignment;
      return type->size;
    }

  assert(is_form(form, generic_form));
  
  symbol_t head = ((generic_form_t) form)->head;

  Type_Generator tg = gethash(head, type_generator_hash);

  if(tg == NULL)
    compile_error("Unknown type generator: %s\n", head->name);

  return tg->get_size_alignment(p_alignment, form);
}

/* XXX: Some of these base functions are architecture-dependent.  */
unsigned int
compile_indirection_size_alignment(unsigned int *p_alignment, form_t form)
{
  *p_alignment = __alignof__(void *);
  return sizeof(void *);
}

unsigned int
compile_tuple_size_alignment(unsigned int *p_alignment, form_t form)
{
  compile_error("Invalid use of tuple\n");
}

unsigned int
compile_struct_size_alignment(unsigned int *p_alignment, form_t form)
{
  /* XXX: Si on peut calculer sa taille, alors on peut calculer
l'offset de tous les champs.  Le calcul des offsets de tous les champs
peut donc se faire ici */

}













void
new_init_type()
{
  
}
#endif
