/* form.h - Operation on forms.
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

#ifndef _SYS_FORM_H
#define _SYS_FORM_H

//typedef struct type_form * type_form_t;

#include "../objects/symbol.h"
//#include "../objects/type.h"
/* Some structures that do not belong to the form tree.  */

#if 0
typedef struct variable_declaration 
{
  struct type_form * type;
  
  /*type_t*/ /*symbol_t type;*/			/* The variable type, or NULL if not
				   specified/not yet infered. */
  symbol_t name;  		/* The variable name.  */
} *variable_declaration_t;
#endif



/* A form is, as defined in the common lisp hyperspec, an object meant
   to be evaluated.  

   The form should contain all informations available by the parser.
   For instance, the parser cannot differentiate between a function
   call, a special form, or a macro call. Thus we have the same type
   for all of them : Compound_Form.  But the parser can distinguate
   the atomic forms.

Form = Compound_Form | Atomic_Form

Atomic_Form = Int_Form | Float_Form | String_Form | Symbol_Form | Quoted_Symbol_Form 
   
   Still, there are some compound forms that the parser can
   differentiate, because of the use of special keywords or syntactic
   extensions.

Compound_Form = Unknown_Compound_Form | Known_Compound_Form

Known_Compound_Form = Block | Let | Define | Lambda

   This should be extensible.  For instance, one could add quote.

   Atomic should also be extensible.

   We identify a type in a type tree by an integer with several
   bitfields :

   - The first bit selects between compound form or atomic form

   - If a compound form, then the second bit selects between an
     unknown or known form

   - The two following bits selects between the known compound form.

   - If not a compound form, then we need three bits to select between
     the atomic form.

You can then use masks to test if an expression is of a certain type:

if(type & type_known_compound_form == type_known_compound_form)

even if it is a subtype of the type.
     
What L should provide is automatic gestion of this kind of tree.

NOTE: an unkwown compound form does just mean that we don't know which
kind of compound form it is at parsing time; it may be a macro or a
function call for instance.



At the different stages of the compilation, different form trees will
be produced, the final is compilable (and analyzable).

For instance, the macro will be expanded, and some blocks will be
replaced by others (for instance, at one moment we could rattach a
variable to its defining block).
*/


/* XXX: make form a first-class object.  */

/* XXX: equal_Form should be renamed assign_form? */
#define DEFINE_FORM_TYPE(value, parent, bits_before, bits_in)	\
  ((value << (32 - (bits_before + bits_in))) | parent)

#define DEFINE_FORM_TYPE_MASK(value, parent, bits_before, bits_in)	\
  ( ~0 << (32 - (bits_before + bits_in)))
  //(~(1 << (32 - (bits_before + bits_in) ) -1))

//#if (value >= 2^bits_in)
//#error "Not enough bits for type to fit"
//#endif


enum form_type_
  {
    /* XXX: pour l'instant il n'y a que des expressions, donc inutile de le tester.  */
    compound_form_type = DEFINE_FORM_TYPE (0, 0, 0, 1),
    atomic_form_type = DEFINE_FORM_TYPE (1, 0, 0, 1),

    int_form_type = DEFINE_FORM_TYPE (0, atomic_form_type, 1, 3),
    float_form_type = DEFINE_FORM_TYPE (1, atomic_form_type, 1, 3),
    string_form_type = DEFINE_FORM_TYPE (2, atomic_form_type, 1, 3),
    symbol_form_type = DEFINE_FORM_TYPE (3, atomic_form_type, 1, 3),
    id_form_type = DEFINE_FORM_TYPE (3, atomic_form_type, 1, 3),
    quoted_symbol_form_type = DEFINE_FORM_TYPE (4, atomic_form_type, 1, 3),
    type_form_type = DEFINE_FORM_TYPE (5, atomic_form_type, 1, 3),
    expanded_form_type = DEFINE_FORM_TYPE (6, atomic_form_type, 1, 3),
    
    unknown_compound_form_type = DEFINE_FORM_TYPE (0, compound_form_type, 1, 1),
    known_compound_form_type = DEFINE_FORM_TYPE (1, compound_form_type, 1, 1),

    generic_form_type = DEFINE_FORM_TYPE (11, known_compound_form_type, 2, 4),
  };

enum
  {
    /* XXX: pour l'instant il n'y a que des expressions, donc inutile de le tester.  */
    compound_form_type_mask = DEFINE_FORM_TYPE_MASK (0, 0, 0, 1),
    atomic_form_type_mask = DEFINE_FORM_TYPE_MASK (1, 0, 0, 1),

    int_form_type_mask = DEFINE_FORM_TYPE_MASK (0, atomic_form_type_mask, 1, 3),
    float_form_type_mask = DEFINE_FORM_TYPE_MASK (1, atomic_form_type_mask, 1, 3),
    string_form_type_mask = DEFINE_FORM_TYPE_MASK (2, atomic_form_type_mask, 1, 3),
    symbol_form_type_mask = DEFINE_FORM_TYPE_MASK (3, atomic_form_type_mask, 1, 3),
    id_form_type_mask = DEFINE_FORM_TYPE_MASK (3, atomic_form_type_mask, 1, 3),
    quoted_symbol_form_type_mask = DEFINE_FORM_TYPE_MASK (4, atomic_form_type_mask, 1, 3),
    type_form_type_mask = DEFINE_FORM_TYPE_MASK (5, atomic_form_type_mask, 1, 3),
    expanded_form_type_mask = DEFINE_FORM_TYPE_MASK (6, atomic_form_type_mask, 1, 3),
    
    unknown_compound_form_type_mask = DEFINE_FORM_TYPE_MASK (0, compound_form_type_mask, 1, 1),
    known_compound_form_type_mask = DEFINE_FORM_TYPE_MASK (1, compound_form_type_mask, 1, 1),

    generic_form_type_mask = DEFINE_FORM_TYPE_MASK (11, known_compound_form_type_mask, 2, 4),
  };


typedef union form_type
{
  enum form_type_ all;
  //  unsigned long all;
  

//  unsigned int is_atomic: 1;
//
//  unsigned int atomic_type : 4; /* The first bit and the three after.  */
//
//  unsigned int is_known_compound_type : 2; /* The first and the second bit */
//
//  unsigned int known_compound_type : 4; /* The two first and the two after.  */
} form_type_t;

#include "../objects/pair.h"

#define Define_Form(struct_name, macro)		\
  typedef struct struct_name			\
  {						\
    form_type_t form_type;			\
    macro;					\
  } *struct_name##_t

#define Form					\
struct {					\
    /*char *file_name;*/			\
    /*  unsigned int line_number;*/		\
}

/* A Form need not be an expression, we should try to make each form
   an expression (even if the return type does not seem useful).  For
   now, each type is an expression.  */

#define Expression_Form					      \
struct {						      \
  Form;							      \
    /*  type_t expression_type;*/ /* Return type of the expression. */	\
}
  

#define Atomic_Form Expression_Form

#define Generic_Atomic_Form			\
struct {					\
  Atomic_Form;					\
  void * value;					\
}


#define Int_Form				\
struct {					\
  Atomic_Form;					\
  int value;					\
}


/* Base type is ill-named, because it can be a user-defined type (not
   necessarily int or float) */
   
enum type_form_type  { STRUCT_TYPE_FORM, BASE_TYPE_FORM, INDIRECTION_TYPE_FORM,
		       ARRAY_TYPE_FORM, SUM_TYPE_FORM, FUNCTION_TYPE_FORM,
		       TUPLE_TYPE_FORM };

#define Type_Form						\
  struct {							\
      Atomic_Form;							\
      enum type_form_type type_form_type; /* XXX: merge with the form type. */ \
      									\
      union {								\
	  symbol_t base_type_name; /* For BASE_TYPE_FORM */		\
	  struct type_form *type_form; /* For POINTER and ARRAY */	\
	  list_t type_form_list; /* For SUM, TUPLE */				\
	  struct type_form *parameters; /* For FUNCTION; should be a tuple type form XXX or a regular form  */		\
	  /*list_t type_form_alist;*/ /* For TUPLE, STRUCT.  A list of variable declarations in fact.  */ \
	  list_t field_list; /* For STRUCT; a list of cons symbol . type_form */ \
      };								\
      									\
      union								\
    {									\
      unsigned int arity; /* For TUPLE */				\
      unsigned int struct_parameters; /* For STRUCT, Like, specified alignment, or \
					 can the fields be moved */	\
      struct type_form * return_type; /* For FUNCTION.  */		\
	};								\
      									\
      									\
      int value;							\
  }


#define Float_Form				\
struct {					\
  Atomic_Form;					\
  float value;					\
}

//XXX: should be ID_Form
#define Symbol_Form				\
struct {					\
  Atomic_Form;					\
  symbol_t value;				\
}

//XXX: this one should be symbol_form
#define Quoted_Symbol_Form			\
struct {					\
  Atomic_Form;					\
  symbol_t value;				\
}

#define String_Form				\
struct {					\
  Atomic_Form;					\
  char * value;				        \
}

#define Compound_Form				\
struct {					\
  Expression_Form;				\
  symbol_t head;				\
}


/* XXX: On a un probleme: pour les appels aux macros, on ne peut pas dire
   si les parametres sont une simple liste ou sont vraiment un form.
   On ne peut le dire qu'apres la phase de macro-expansion.  */

/* XXX: Du coup les macros pourraient toujours manipuler des listes en
   fait.  */

/* XXX: pour l'instant on va ignorer ce probleme vu qu'on a pas de
   macros.  */


/* XXX: retirer ce tuple_form.  */
#define Unknown_Compound_Form			\
struct {					\
    Compound_Form;				\
    struct tuple_form * args;			\
}


#define Function_Form				\
struct {					\
    Unknown_Compound_Form;			\
    unsigned int nb_args;			\
}						\

#define Macro_Form				\
struct {					\
    Unknown_Compound_Form;			\
}						\


#define Known_Compound_Form Compound_Form

/* En fait on a besoin que d'une seule forme pour les formes
   composees: la generics compound form.

   Au besoin on pourra rajouter un champs void *info pour associer des
   infos a la form.

   Le type de la form est identifiable par le head de la form, tout
   simplement.
   */
#define Generic_Compound_Form			\
struct {					\
  Compound_Form;				\
  unsigned int form_list_length;		\
  list_t form_list;				\
}


#define Let_Compound_Form			\
struct {					\
    Known_Compound_Form;			\
    type_form_t type;				\
    symbol_t name;				\
    /*expression_form_t initial_value;*/ /* Pas d'initial value : il suffit de mettre un = derriere. */ \
  }

#define Define_Compound_Form			\
struct {					\
    Known_Compound_Form;			\
    symbol_t type;				\
    symbol_t name;				\
    void * initial_value; /* Can be a form, or anything, depending on
			     what we define. It just needs to be
			     parsed.  */ \
  }

#define Block_Compound_Form			\
struct {					\
    Known_Compound_Form;			\
    struct seq_form *forms;			\
  }

/* Seq is like a block, but does not create a new scope.  */
/* En fait seq est elle meme une liste : on pourrait avoir struct
   seq_form {form_t form; seq_form_t rest;} */
#define Seq_Compound_Form			\
struct {					\
    Known_Compound_Form;			\
    list_t form_list; /* A list of forms.  */	\
  }


#define Lambda_Compound_Form			\
struct {					\
    Known_Compound_Form;			\
    list_t parameters; /* XXX: parameters should be a form, even if not in this tree?  It is a list of struct variable_declaration. */\
    unsigned int parameters_number;					\
    /*    symbol_t return_type; */					\
    type_form_t type;							\
    expression_form_t body;			\
  }

#define Equal_Compound_Form			\
struct {					\
    Known_Compound_Form;			\
    form_t assignee; /*XXX: should be a "setter expression" */	\
    expression_form_t expression;			\
  }

#define If_Compound_Form					\
  struct {							\
    Known_Compound_Form;					\
    expression_form_t condition;				\
    expression_form_t then_form;				\
    expression_form_t else_form;				\
}

#define Tuple_Compound_Form					\
  struct {							\
    Known_Compound_Form;					\
    list_t form_list;						\
    unsigned int length;					\
}

#define Loop_Compound_Form					\
  struct {							\
    Known_Compound_Form;					\
    expression_form_t repeated_form;				\
}

#define Break_Compound_Form					\
  struct {							\
    Known_Compound_Form;					\
}

#define Continue_Compound_Form					\
  struct {							\
    Known_Compound_Form;					\
}


//#define Labeled_Statement

Define_Form (form, Form);
Define_Form (expression_form, Expression_Form);
Define_Form (atomic_form, Generic_Atomic_Form);
Define_Form (int_form, Int_Form);
Define_Form (float_form, Float_Form);
Define_Form (id_form, Symbol_Form);
Define_Form (symbol_form, Symbol_Form);
Define_Form (quoted_symbol_form, Quoted_Symbol_Form);
Define_Form (string_form, String_Form);
Define_Form (type_form, Type_Form);

Define_Form (compound_form, Compound_Form);
Define_Form (unknown_compound_form, Unknown_Compound_Form);
Define_Form (generic_form, Generic_Compound_Form);

#define new_form(type)				\
  ({type##_form_t form = MALLOC (type##_form);		\
    form->form_type.all = type##_form_type;	\
    form;})

#define is_form(form, form_type_)					\
  ((form->form_type.all & form_type_##_type_mask) == form_type_##_type)


//form_t
//sexp_to_form (object_t obj);



#include <l/expand.h> //For the expanded form

#if 0
struct type_form
{
  enum type_form_type type_form_type; /* XXX: merge with the form type. */

  union {
    symbol_t base_type_name; /* For BASE_TYPE_FORM */
    struct type_form *type_form; /* For POINTER and ARRAY */
    list_t type_form_list; /* For SUM, TUPLE, FUNCTION */
    list_t field_list; /* For STRUCT; a list of cons symbol . type_form */
  };

  union
  {
    unsigned int arity; /* For TUPLE */
    unsigned int struct_parameters; /* For STRUCT, Like, specified alignment, or
				       can the fields be moved */
    type_form_t return_type /* For FUNCTION.  */
  };
};
#endif


/* The type tree should be the following:

   Form := Id_Form(Symbol value)
         | Int_Form(Int value)
         | Float_Form(Float value)
         | String_Form(String value)
         | Symbol_Form(Symbol value)
         | Generic_Form(xxx head, Form:List list)
         | Type_Form
         | Custom new forms here, for input of bignums or anything.

Before adding a new custom form, you should instead use a custom
syntax to a generic form. For instance, 'toto' could eventually be
translated to Symbol("toto").  

   Type_Form :=  Base_Type_Form (Symbol base_type_name)
              |  Pointer_Type_Form (Type_Form type_form)
              |  Array_Type_Form (Type_Form type_Form, Unsigned_Int arity)
              |  Sum_Type_Form (Type_Form:List type_form_list)
              |  Function_Type_Form(Type_Form return_type, Type_Form : List type_form_list)
              |  Struct_Type_Form(Struct_Field : List field_list);
              
- A Tuple just has 0,1,.. as struct parameters.              
- A union declares several structures, and freely coerce between them.  

*/

type_form_t
function_type_form (type_form_t return_type,
		    type_form_t parameters);


type_form_t
base_type_form (symbol_t name);

type_form_t
tuple_type_form (list_t type_form_list);

#endif
