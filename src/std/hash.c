/* hash.c - Hash tables handling.
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

#include <l/sys/hash.h>
#include <l/sys/panic.h>
#include "../compiler/c-to-l.h"
#include <l/type.h>
#include <assert.h>
#include <l/form.h>

/* Hash table support is efficient, but may seem basic to people
   accustomed to Common Lisp, Perl or Ruby hashes.  There are no
   default value, no default function executed, and no check that the
   value in gethash is really here.  If you want all that, use a
   different type.  
   
   XXX: what we could do to make it typesafe later, is to mandate that
   the return type can be Null (i.e. a pointer|null, or an Int); and
   if it cannot be, then we check it automatically (and throw an
   exception if null).

   If he wants, the user can then use his type|Null in the Hash, and
   then assert that his values are not null; but it will have to do
   that explicitly.  Or he could use an unsafe_hash that would do
   that automatically.  */


form_t
hash_foreach_expander( Symbol loop_name, form_t var_form,
		       expanded_form_t hash_form, form_t body);

/* Transforms Hash(From_Type,To_Type) into
   (Hash(From_Type,To_Type)) make_hash_table();
*/
generic_form_t
expand_hash (generic_form_t form)
{
  type_form_t new_type_form = generic_form_symbol (SYMBOL (cast),
						   CONS (form,
							 CONS (generic_form_symbol (SYMBOL (make_hash_table),
										    NULL),
							       NULL)));
  return new_type_form;
}

form_t
hash_accesser(Type type,
	      expanded_form_t accessed,
	      expanded_form_t accessor)
{
  type_form_t tf = type->type_form;
  generic_form_t gf = tf;

  assert (is_form (gf, generic_form));
  assert (gf->head == SYMBOL (Hash));
  
  type_form_t from_form = CAR (gf->form_list);
  type_form_t to_form = CAR (gf->form_list->next);

  Type from_type = intern_type (from_form);
  
  /* Needed only when we will directly create an expanded form.  
     Type to_type = intern_type (to_form); */

  type_check (from_type, accessor->type);

  form_t casted_key = generic_form_symbol (SYMBOL (cast),
					   CONS (generic_form_symbol (SYMBOL (pointer),
								      CONS (id_form (SYMBOL (Void)),
									    NULL)),
						 CONS (accessor, NULL)));
  
  form_t casted_hash = generic_form_symbol (SYMBOL (cast),
					    CONS (id_form (SYMBOL (Hash_Table)),
						  CONS (accessed, NULL)));

  form_t all = generic_form_symbol (SYMBOL (cast),
				    CONS (to_form,
					  CONS (generic_form_symbol (SYMBOL (gethash),
								     CONS (casted_key,
									   CONS (casted_hash,
										 NULL))),
						NULL)));
  return all;
}


form_t
hash_left_accesser(Type type,
		   expanded_form_t accessed,
		   expanded_form_t accessor,
		   expanded_form_t expression)
{
  type_form_t tf = type->type_form;
  generic_form_t gf = tf;

  assert (is_form (gf, generic_form));
  assert (gf->head == SYMBOL (Hash));
  
  type_form_t from_form = CAR (gf->form_list);
  type_form_t to_form = CAR (gf->form_list->next);

  Type from_type = intern_type (from_form);
  Type to_type = intern_type (to_form);
  
  /* Needed only when we will directly create an expanded form.  
     Type to_type = intern_type (to_form); */

  type_check (from_type, accessor->type);
  type_check (to_type, expression->type);

  form_t casted_key = generic_form_symbol (SYMBOL (cast),
					   CONS (generic_form_symbol (SYMBOL (pointer),
								      CONS (id_form (SYMBOL (Void)),
									    NULL)),
						 CONS (accessor, NULL)));
  
  form_t casted_hash = generic_form_symbol (SYMBOL (cast),
					    CONS (id_form (SYMBOL (Hash_Table)),
						  CONS (accessed, NULL)));


  form_t casted_expression = generic_form_symbol (SYMBOL (cast),
						  CONS (generic_form_symbol (SYMBOL (pointer),
									     CONS (id_form (SYMBOL (Void)),
										   NULL)),
							CONS (expression, NULL)));

  form_t all = generic_form_symbol (SYMBOL (puthash),
				    CONS (casted_key,
					  CONS (casted_expression,
						CONS (casted_hash,
						      NULL))));
  form_t casted_all = generic_form_symbol( SYMBOL( cast),
					   CONS( to_form,
						 CONS( all,
						       NULL)));
  
  return casted_all;
}

/* Create a type given a type form (Hash From_Type_Form
   To_Type_Form).  */
Type
make_type_Hash (generic_form_t form)
{
  Type from_type = intern_type( CAR( form->form_list));
  Type to_type = intern_type( CAR( form->form_list->next));
  if(from_type->size != sizeof(void*) || to_type->size != sizeof(void*))
    compile_error( "%s and %s must be of pointer size\n",
		   asprint_type( from_type), asprint_type( to_type));
  
  type_form_t defining_type_form = base_type_form (SYMBOL (Hash_Table));
  Base_Type the_type = define_type_type_form (form, -1, -1, defining_type_form);

  assert(the_type->type_type == BASE_TYPE);

  define_accesser (the_type, hash_accesser);
  define_left_accesser (the_type, hash_left_accesser);
  define_foreach_expander( the_type, hash_foreach_expander);
  /* Create the accessor and left accessor for the type.  */
  
  return the_type;
}

/* Hash strings.  */


/* Transforms Hash_String(To_Type) into
   (Hash_String(From_Type,To_Type)) make_hash_string_table();
*/
generic_form_t
expand_hash_string (generic_form_t form)
{
  type_form_t new_type_form = generic_form_symbol (SYMBOL (cast),
						   CONS (form,
							 CONS (generic_form_symbol (SYMBOL (make_hash_string_table),
										    NULL),
							       NULL)));
  return new_type_form;
}

form_t
hash_string_accesser(Type type,
		     expanded_form_t accessed,
		     expanded_form_t accessor)
{
  type_form_t tf = type->type_form;
  generic_form_t gf = tf;

  assert (is_form (gf, generic_form));
  assert (gf->head == SYMBOL (Hash_String));
  
  type_form_t to_form = CAR (gf->form_list);

  /* Needed only when we will directly create an expanded form.  
     Type to_type = intern_type (to_form); */

  type_check (TYPE ("String"), accessor->type);

  form_t casted_hash = generic_form_symbol (SYMBOL (cast),
					    CONS (id_form (SYMBOL (Hash_String_Table)),
						  CONS (accessed, NULL)));

  form_t all = generic_form_symbol (SYMBOL (cast),
				    CONS (to_form,
					  CONS (generic_form_symbol (SYMBOL (gethash_string),
								     CONS (accessor,
									   CONS (casted_hash,
										 NULL))),
						NULL)));
  return all;
}

form_t
hash_string_left_accesser(Type type,
			  expanded_form_t accessed,
			  expanded_form_t accessor,
			  expanded_form_t expression)
{
  type_form_t tf = type->type_form;
  generic_form_t gf = tf;

  assert (is_form (gf, generic_form));
  assert (gf->head == SYMBOL (Hash_String));
  
  type_form_t to_form = CAR (gf->form_list);

  /* Needed only when we will directly create an expanded form.  
     Type to_type = intern_type (to_form); */

  type_check (TYPE ("String"), accessor->type);

  form_t casted_hash = generic_form_symbol (SYMBOL (cast),
					    CONS (id_form (SYMBOL (Hash_String_Table)),
						  CONS (accessed, NULL)));


  form_t casted_expression = generic_form_symbol (SYMBOL (cast),
						  CONS (generic_form_symbol (SYMBOL (pointer),
									     CONS (id_form (SYMBOL (Void)),
										   NULL)),
							CONS (expression, NULL)));

  form_t all = generic_form_symbol (SYMBOL (puthash_string),
				    CONS (accessor,
					  CONS (casted_expression,
						CONS (casted_hash,
						      NULL))));
  return all;
}


/* Create a type given a type form (Hash_String To_Type_Form).  */
Type
make_type_Hash_String (generic_form_t form)
{
  type_form_t defining_type_form = base_type_form (SYMBOL (Hash_String_Table));
  Base_Type the_type = define_type_type_form (form, -1, -1, defining_type_form);

  assert(the_type->type_type == BASE_TYPE);

  define_accesser (the_type, hash_string_accesser);
  define_left_accesser (the_type, hash_string_left_accesser);
  /* Create the accessor and left accessor for the type.  */
  
  return the_type;
}


/* Hash iterator.  */
pair_t
alloc_cons_cell(void);

/* Comes from

Form
foreach_hash (form:Compound_Form)
{
  //  assert( form.form_list);
  let var_form = form.form_list.head;
  //  assert( form.form_list.tail);
  let hash_form = expand( form.form_list.tail.head);
  //  assert( form.form_list.tail.tail);
  let body = form.form_list.tail.tail.head;

  let hash_type_form = cast( Expanded_Form, hash_form).type.common_.type_form;
  let hash_type_form_compound = cast( Compound_Form, hash_type_form);
  let from_type = hash_type_form_compound.form_list.head;
  let to_type = hash_type_form_compound.form_list.tail.head;

  Form ({ let Index_:Int = 0;
      let hash_ = $hash_form$;
      let PValue_:Void **;
      PValue_ = JudyLFirst (*cast( Void **,hash_), cast( Void *, &Index_), 0);
      loop {
	if(PValue_ == cast( Void**, 0))
	  break;
	$var_form$ = ($Compound_Form('cast', list( from_type,
						   Form( Index_)))$,
		      $Compound_Form('cast', list( to_type,
						   Form( *PValue_)))$);
	$body$;
	PValue_ = JudyLNext( *cast( Void **, hash_), cast( Void *,&Index_), 0);
      }})
}
*/


form_t
hash_foreach_expander( Symbol loop_name, form_t var_form,
		       expanded_form_t hash_form, form_t body)
{
  generic_form_t hash_type_form_compound;
  form_t hash_type_form;
  form_t from_type;
  form_t to_type;
  hash_type_form = hash_form->type->type_form;
  hash_type_form_compound = ((generic_form_t ) hash_type_form);
  from_type = CAR( hash_type_form_compound->form_list);
  to_type = CAR( hash_type_form_compound->form_list->next);
  form_t ret_form = (generic_form_symbol)(intern( "block"), ({
struct pair *_sharp_pair_831;
_sharp_pair_831,
(_sharp_pair_831 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_831).car) = (generic_form_symbol)(intern( "="), ({
struct pair *_sharp_pair_774;
_sharp_pair_774,
(_sharp_pair_774 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_774).car) = (generic_form_symbol)(intern( "let"), ({
struct pair *_sharp_pair_772;
_sharp_pair_772,
(_sharp_pair_772 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_772).car) = (id_form)(intern( "Index_")));
(((* _sharp_pair_772).cdr) = ({
struct pair *_sharp_pair_771;
_sharp_pair_771,
(_sharp_pair_771 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_771).car) = (id_form)(intern( "Int")));
(((* _sharp_pair_771).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_771);
})
);
((list_t ) _sharp_pair_772);
})
));
(((* _sharp_pair_774).cdr) = ({
struct pair *_sharp_pair_773;
_sharp_pair_773,
(_sharp_pair_773 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_773).car) = (int_form)(0));
(((* _sharp_pair_773).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_773);
})
);
((list_t ) _sharp_pair_774);
})
));
(((* _sharp_pair_831).cdr) = ({
struct pair *_sharp_pair_830;
_sharp_pair_830,
(_sharp_pair_830 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_830).car) = (generic_form_symbol)(intern( "="), ({
struct pair *_sharp_pair_777;
_sharp_pair_777,
(_sharp_pair_777 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_777).car) = (generic_form_symbol)(intern( "let"), ({
struct pair *_sharp_pair_775;
_sharp_pair_775,
(_sharp_pair_775 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_775).car) = (id_form)(intern( "hash_")));
(((* _sharp_pair_775).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_775);
})
));
(((* _sharp_pair_777).cdr) = ({
struct pair *_sharp_pair_776;
_sharp_pair_776,
(_sharp_pair_776 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_776).car) = hash_form);
(((* _sharp_pair_776).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_776);
})
);
((list_t ) _sharp_pair_777);
})
));
(((* _sharp_pair_830).cdr) = ({
struct pair *_sharp_pair_829;
_sharp_pair_829,
(_sharp_pair_829 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_829).car) = (generic_form_symbol)(intern( "let"), ({
struct pair *_sharp_pair_781;
_sharp_pair_781,
(_sharp_pair_781 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_781).car) = (id_form)(intern( "PValue_")));
(((* _sharp_pair_781).cdr) = ({
struct pair *_sharp_pair_780;
_sharp_pair_780,
(_sharp_pair_780 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_780).car) = (generic_form_symbol)(intern( "pointer"), ({
struct pair *_sharp_pair_779;
_sharp_pair_779,
(_sharp_pair_779 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_779).car) = (generic_form_symbol)(intern( "pointer"), ({
struct pair *_sharp_pair_778;
_sharp_pair_778,
(_sharp_pair_778 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_778).car) = (id_form)(intern( "Void")));
(((* _sharp_pair_778).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_778);
})
));
(((* _sharp_pair_779).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_779);
})
));
(((* _sharp_pair_780).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_780);
})
);
((list_t ) _sharp_pair_781);
})
));
(((* _sharp_pair_829).cdr) = ({
struct pair *_sharp_pair_828;
_sharp_pair_828,
(_sharp_pair_828 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_828).car) = (generic_form_symbol)(intern( "="), ({
struct pair *_sharp_pair_795;
_sharp_pair_795,
(_sharp_pair_795 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_795).car) = (id_form)(intern( "PValue_")));
(((* _sharp_pair_795).cdr) = ({
struct pair *_sharp_pair_794;
_sharp_pair_794,
(_sharp_pair_794 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_794).car) = (generic_form_symbol)(intern( "JudyLFirst"), ({
struct pair *_sharp_pair_793;
_sharp_pair_793,
(_sharp_pair_793 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_793).car) = (generic_form_symbol)(intern( "deref"), ({
struct pair *_sharp_pair_786;
_sharp_pair_786,
(_sharp_pair_786 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_786).car) = (generic_form_symbol)(intern( "cast"), ({
struct pair *_sharp_pair_785;
_sharp_pair_785,
(_sharp_pair_785 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_785).car) = (generic_form_symbol)(intern( "pointer"), ({
struct pair *_sharp_pair_783;
_sharp_pair_783,
(_sharp_pair_783 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_783).car) = (generic_form_symbol)(intern( "pointer"), ({
struct pair *_sharp_pair_782;
_sharp_pair_782,
(_sharp_pair_782 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_782).car) = (id_form)(intern( "Void")));
(((* _sharp_pair_782).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_782);
})
));
(((* _sharp_pair_783).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_783);
})
));
(((* _sharp_pair_785).cdr) = ({
struct pair *_sharp_pair_784;
_sharp_pair_784,
(_sharp_pair_784 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_784).car) = (id_form)(intern( "hash_")));
(((* _sharp_pair_784).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_784);
})
);
((list_t ) _sharp_pair_785);
})
));
(((* _sharp_pair_786).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_786);
})
));
(((* _sharp_pair_793).cdr) = ({
struct pair *_sharp_pair_792;
_sharp_pair_792,
(_sharp_pair_792 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_792).car) = (generic_form_symbol)(intern( "cast"), ({
struct pair *_sharp_pair_790;
_sharp_pair_790,
(_sharp_pair_790 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_790).car) = (generic_form_symbol)(intern( "pointer"), ({
struct pair *_sharp_pair_787;
_sharp_pair_787,
(_sharp_pair_787 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_787).car) = (id_form)(intern( "Void")));
(((* _sharp_pair_787).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_787);
})
));
(((* _sharp_pair_790).cdr) = ({
struct pair *_sharp_pair_789;
_sharp_pair_789,
(_sharp_pair_789 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_789).car) = (generic_form_symbol)(intern( "ref"), ({
struct pair *_sharp_pair_788;
_sharp_pair_788,
(_sharp_pair_788 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_788).car) = (id_form)(intern( "Index_")));
(((* _sharp_pair_788).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_788);
})
));
(((* _sharp_pair_789).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_789);
})
);
((list_t ) _sharp_pair_790);
})
));
(((* _sharp_pair_792).cdr) = ({
struct pair *_sharp_pair_791;
_sharp_pair_791,
(_sharp_pair_791 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_791).car) = (int_form)(0));
(((* _sharp_pair_791).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_791);
})
);
((list_t ) _sharp_pair_792);
})
);
((list_t ) _sharp_pair_793);
})
));
(((* _sharp_pair_794).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_794);
})
);
((list_t ) _sharp_pair_795);
})
));
(((* _sharp_pair_828).cdr) = ({
struct pair *_sharp_pair_827;
_sharp_pair_827,
(_sharp_pair_827 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_827).car) = (generic_form_symbol)(intern( "loop"), ({
struct pair *_sharp_pair_826;
_sharp_pair_826,
(_sharp_pair_826 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_826).car) = (generic_form_symbol)(intern( "block"), ({
struct pair *_sharp_pair_825;
_sharp_pair_825,
(_sharp_pair_825 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_825).car) = (generic_form_symbol)(intern( "if"), ({
struct pair *_sharp_pair_803;
_sharp_pair_803,
(_sharp_pair_803 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_803).car) = (generic_form_symbol)(intern( "=="), ({
struct pair *_sharp_pair_801;
_sharp_pair_801,
(_sharp_pair_801 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_801).car) = (id_form)(intern( "PValue_")));
(((* _sharp_pair_801).cdr) = ({
struct pair *_sharp_pair_800;
_sharp_pair_800,
(_sharp_pair_800 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_800).car) = (generic_form_symbol)(intern( "cast"), ({
struct pair *_sharp_pair_799;
_sharp_pair_799,
(_sharp_pair_799 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_799).car) = (generic_form_symbol)(intern( "pointer"), ({
struct pair *_sharp_pair_797;
_sharp_pair_797,
(_sharp_pair_797 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_797).car) = (generic_form_symbol)(intern( "pointer"), ({
struct pair *_sharp_pair_796;
_sharp_pair_796,
(_sharp_pair_796 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_796).car) = (id_form)(intern( "Void")));
(((* _sharp_pair_796).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_796);
})
));
(((* _sharp_pair_797).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_797);
})
));
(((* _sharp_pair_799).cdr) = ({
struct pair *_sharp_pair_798;
_sharp_pair_798,
(_sharp_pair_798 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_798).car) = (int_form)(0));
(((* _sharp_pair_798).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_798);
})
);
((list_t ) _sharp_pair_799);
})
));
(((* _sharp_pair_800).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_800);
})
);
((list_t ) _sharp_pair_801);
})
));
(((* _sharp_pair_803).cdr) = ({
struct pair *_sharp_pair_802;
_sharp_pair_802,
(_sharp_pair_802 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_802).car) = (generic_form_symbol)(intern( "break"), ((list_t ) 0)));
(((* _sharp_pair_802).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_802);
})
);
((list_t ) _sharp_pair_803);
})
));
(((* _sharp_pair_825).cdr) = ({
struct pair *_sharp_pair_824;
_sharp_pair_824,
(_sharp_pair_824 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_824).car) = (generic_form_symbol)(intern( "="), ({
struct pair *_sharp_pair_807;
_sharp_pair_807,
(_sharp_pair_807 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_807).car) = var_form);
(((* _sharp_pair_807).cdr) = ({
struct pair *_sharp_pair_806;
_sharp_pair_806,
(_sharp_pair_806 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_806).car) = (generic_form_symbol)(intern( "tuple"), ({
struct pair *_sharp_pair_805;
_sharp_pair_805,
(_sharp_pair_805 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_805).car) = (generic_form_symbol)(intern( "cast"), ({
struct pair *_sharp_pair_767;
_sharp_pair_767,
(_sharp_pair_767 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_767).car) = from_type);
(((* _sharp_pair_767).cdr) = ({
struct pair *_sharp_pair_766;
_sharp_pair_766,
(_sharp_pair_766 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_766).car) = (id_form)(intern( "Index_")));
(((* _sharp_pair_766).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_766);
})
);
((list_t ) _sharp_pair_767);
})
));
(((* _sharp_pair_805).cdr) = ({
struct pair *_sharp_pair_804;
_sharp_pair_804,
(_sharp_pair_804 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_804).car) = (generic_form_symbol)(intern( "cast"), ({
struct pair *_sharp_pair_770;
_sharp_pair_770,
(_sharp_pair_770 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_770).car) = to_type);
(((* _sharp_pair_770).cdr) = ({
struct pair *_sharp_pair_769;
_sharp_pair_769,
(_sharp_pair_769 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_769).car) = (generic_form_symbol)(intern( "deref"), ({
struct pair *_sharp_pair_768;
_sharp_pair_768,
(_sharp_pair_768 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_768).car) = (id_form)(intern( "PValue_")));
(((* _sharp_pair_768).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_768);
})
));
(((* _sharp_pair_769).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_769);
})
);
((list_t ) _sharp_pair_770);
})
));
(((* _sharp_pair_804).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_804);
})
);
((list_t ) _sharp_pair_805);
})
));
(((* _sharp_pair_806).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_806);
})
);
((list_t ) _sharp_pair_807);
})
));
(((* _sharp_pair_824).cdr) = ({
struct pair *_sharp_pair_823;
_sharp_pair_823,
(_sharp_pair_823 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_823).car) = body);
(((* _sharp_pair_823).cdr) = ({
struct pair *_sharp_pair_822;
_sharp_pair_822,
(_sharp_pair_822 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_822).car) = (generic_form_symbol)(intern( "="), ({
struct pair *_sharp_pair_821;
_sharp_pair_821,
(_sharp_pair_821 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_821).car) = (id_form)(intern( "PValue_")));
(((* _sharp_pair_821).cdr) = ({
struct pair *_sharp_pair_820;
_sharp_pair_820,
(_sharp_pair_820 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_820).car) = (generic_form_symbol)(intern( "JudyLNext"), ({
struct pair *_sharp_pair_819;
_sharp_pair_819,
(_sharp_pair_819 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_819).car) = (generic_form_symbol)(intern( "deref"), ({
struct pair *_sharp_pair_812;
_sharp_pair_812,
(_sharp_pair_812 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_812).car) = (generic_form_symbol)(intern( "cast"), ({
struct pair *_sharp_pair_811;
_sharp_pair_811,
(_sharp_pair_811 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_811).car) = (generic_form_symbol)(intern( "pointer"), ({
struct pair *_sharp_pair_809;
_sharp_pair_809,
(_sharp_pair_809 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_809).car) = (generic_form_symbol)(intern( "pointer"), ({
struct pair *_sharp_pair_808;
_sharp_pair_808,
(_sharp_pair_808 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_808).car) = (id_form)(intern( "Void")));
(((* _sharp_pair_808).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_808);
})
));
(((* _sharp_pair_809).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_809);
})
));
(((* _sharp_pair_811).cdr) = ({
struct pair *_sharp_pair_810;
_sharp_pair_810,
(_sharp_pair_810 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_810).car) = (id_form)(intern( "hash_")));
(((* _sharp_pair_810).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_810);
})
);
((list_t ) _sharp_pair_811);
})
));
(((* _sharp_pair_812).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_812);
})
));
(((* _sharp_pair_819).cdr) = ({
struct pair *_sharp_pair_818;
_sharp_pair_818,
(_sharp_pair_818 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_818).car) = (generic_form_symbol)(intern( "cast"), ({
struct pair *_sharp_pair_816;
_sharp_pair_816,
(_sharp_pair_816 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_816).car) = (generic_form_symbol)(intern( "pointer"), ({
struct pair *_sharp_pair_813;
_sharp_pair_813,
(_sharp_pair_813 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_813).car) = (id_form)(intern( "Void")));
(((* _sharp_pair_813).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_813);
})
));
(((* _sharp_pair_816).cdr) = ({
struct pair *_sharp_pair_815;
_sharp_pair_815,
(_sharp_pair_815 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_815).car) = (generic_form_symbol)(intern( "ref"), ({
struct pair *_sharp_pair_814;
_sharp_pair_814,
(_sharp_pair_814 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_814).car) = (id_form)(intern( "Index_")));
(((* _sharp_pair_814).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_814);
})
));
(((* _sharp_pair_815).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_815);
})
);
((list_t ) _sharp_pair_816);
})
));
(((* _sharp_pair_818).cdr) = ({
struct pair *_sharp_pair_817;
_sharp_pair_817,
(_sharp_pair_817 = ((struct pair *) (alloc_cons_cell)()));
(((* _sharp_pair_817).car) = (int_form)(0));
(((* _sharp_pair_817).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_817);
})
);
((list_t ) _sharp_pair_818);
})
);
((list_t ) _sharp_pair_819);
})
));
(((* _sharp_pair_820).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_820);
})
);
((list_t ) _sharp_pair_821);
})
));
(((* _sharp_pair_822).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_822);
})
);
((list_t ) _sharp_pair_823);
})
);
((list_t ) _sharp_pair_824);
})
);
((list_t ) _sharp_pair_825);
})
));
(((* _sharp_pair_826).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_826);
})
));
(((* _sharp_pair_827).cdr) = ((list_t ) 0));
((list_t ) _sharp_pair_827);
})
);
((list_t ) _sharp_pair_828);
})
);
((list_t ) _sharp_pair_829);
})
);
((list_t ) _sharp_pair_830);
})
);
((list_t ) _sharp_pair_831);
    }));
  return ret_form;
}


hash_table_t
make_hash_table (void)
{
  hash_table_t ht = xmalloc (sizeof(hash_table));
  *ht = NULL;
  return ht;
}

#include <Judy.h>

void *
gethash (void * key, hash_table_t table)
{
  PWord_t Pvalue;
  JLG (Pvalue, *table, (Word_t) key);
  return (Pvalue ? (void *) *Pvalue : (void *) 0);
}

void *
puthash (void * key, void * value, hash_table_t table)
{
  PWord_t PValue;
  JLI (PValue, (*table), (Word_t) key);
  *PValue = (Word_t) value;
  return value;
}

hash_string_table_t
make_hash_string_table (void)
{
  hash_string_table_t ht = xmalloc (sizeof(hash_table));
  *ht = NULL;
  return ht;
}

#include <Judy.h>

void *
gethash_string (String key, hash_string_table_t table)
{
  PWord_t Pvalue;
  JHSG (Pvalue, *table, key->content, key->length);
  return (Pvalue ? (void *) *Pvalue : (void *) 0);
}

void *
puthash_string (String key, void * value, hash_string_table_t table)
{
  PWord_t PValue;
  JHSI (PValue, *table, key->content, key->length);
  *PValue = (Word_t) value;
  return value;
}



void
init_hash (void)
{
  /* These functions are needed so that the macros can work; but they
     should not be used directly.  */
  /* We should have: type Hash_Table = Pointer, with Pointer being a
     Word on most machines.  */
  eval_cstring ("type Hash_Table = Void *;");
  DEFINE_C_FUNCTION (make_hash_table, "Hash_Table <- ()");

  /* XXX: gethash should also tell if there was a value or not.  */
  DEFINE_C_FUNCTION (gethash, "Void * <- (Void *, Hash_Table)");
  DEFINE_C_FUNCTION (puthash, "Void * <- (Void *, Void *, Hash_Table)");

  DEFINE_C_FUNCTION( JudyLFirst, "Void ** <- (Void *, Void *, Int)");
  DEFINE_C_FUNCTION( JudyLNext, "Void ** <- (Void *, Void *, Int)");
  
  /* XXX: remove should also work: remove(table['toto'] would remove
     the entry 'toto' from the table.  */
  
  define_expander (SYMBOL (Hash), expand_hash);
   
  define_type_constructor (SYMBOL (Hash), bprint_type_misc, make_type_Hash);

  /* Hash strings.  */
  eval_cstring ("type Hash_String_Table = Void *;");
  DEFINE_C_FUNCTION (make_hash_string_table, "Hash_String_Table <- ()");

  DEFINE_C_FUNCTION (gethash_string, "Void * <- (String, Hash_String_Table)");
  DEFINE_C_FUNCTION (puthash_string, "Void * <- (String, Void *, Hash_String_Table)");

  define_expander (SYMBOL (Hash_String), expand_hash_string);
  define_type_constructor (SYMBOL (Hash_String),
			   bprint_type_misc,
			   make_type_Hash_String);
  
}
