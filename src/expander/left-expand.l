include "include/l/form.l";
include "include/l/type.l";

/* A pattern match has two parts:
   - a verification part that checks whether there is a match
   - an extraction part that binds variables to values as requested.
*/   

/* XXX: This should be defined in a file form.l  */

/* This is compile_time only because of a bug in the order of treatment of
   type_alias vs type. */
compile_time type Pattern_Return = struct {
  verification:Form;
  extraction:Form;
}* ;

type_alias Left_Expander = ((Compound_Form, Expanded_Form) -> Pattern_Return)*;
//type_alias Left_Expander = ((Compound_Form, Expanded_Form) -> Form)*;
// Really, should be type Left_Expander = .... + subtype Left_Expander ....
// where .... is in both case ((Compound_Form, Expanded_Form) -> Form)*.
// This should be shortened as:
//type Left_Expander < ((Compound_Form, Expanded_Form) -> Form)*;

global left_expander_hash:Hash<Symbol, Left_Expander>;

function
define_left_expander( symbol:Symbol, expander:Left_Expander) -> Void =
{
  left_expander_hash[symbol] = expander;
};

function
init__left_expand() -> Void =
{
  left_expander_hash = cast( Hash<Symbol, Left_Expander>, make_hash_table());
  left_expander_hash['let'] = &left_expand_let;
  left_expander_hash['@deref'] = &left_expand_deref;
  left_expander_hash['deref'] = &left_expand_deref;
  left_expander_hash['tuple'] = &left_expand_tuple;
};

/* Maybe should be in expand_equal directly.  */
function
left_expand( assignee:Form, expression:Expanded_Form) -> Form =
{
  let pr = left_expand_rec( assignee, expression);

  //XXX: transformer toute les verifications en assertions.
  pr.extraction
};


function
left_expand_rec( assignee:Form, expression:Expanded_Form) -> Pattern_Return =
{
  if( not( is_compound_form( assignee)))
    {
      let expanded_assignee = expand( assignee);
      Pattern_Return( verification:Form(()),
		      extraction:Expanded_Form( Form( $expanded_assignee$ = $coerced_form( expression,
											   expanded_assignee.type)$),
						expanded_assignee.type))
    }
  else
    {
      let gform = cast( Compound_Form, assignee);

      // Contrary to regular expand, here we don't expand indefinitely. If
      // this is is to happen, regular expansion of = take care of left expanding
      // the lvalues "indefinitely"
      
      let head = gform.head;
      let lexpander = left_expander_hash[head];
      if( lexpander == cast( Left_Expander, 0))
	{
	  panic( "Error: no left expander defined for ", head);
	};
      
      funcall( *lexpander, gform, expression)
    }
};


function
left_expand_let( cf:Compound_Form, expression:Expanded_Form) -> Pattern_Return =
{
  let id_form = cast( Id_Form, cf.form_list.head);

  let id_type:Type;

  let new_expression:Form;
  
  if(cf.form_list.tail != cast( List<Form>, 0))
    {
      /* A type has been given.  */
      let type_form = cf.form_list.tail.head;
      id_type = intern_type( type_form);
      new_expression = coerced_form( expression, id_type);
    }
  else
    {
      new_expression = expression;
      id_type = expression.type;
    };

  let new_symbol = insert_local_variable( id_form.value, id_type);
  
  let exp_let = Expanded_Form( Id_Form( new_symbol),
			       id_type);

  Pattern_Return( verification:Form( ()),
		  extraction:Expanded_Form( Form( $exp_let$ = $new_expression$),
					    id_type))
};

function
left_expand_deref( cf:Compound_Form, expression:Expanded_Form) -> Pattern_Return =
{
  let refed = cf.form_list.head;
  let expanded_refed = expand( refed);

  let type = expanded_refed.type;
  let pointed_type = cast( Pointer_Type, type).pointed_type;

  let exp_deref = Expanded_Form( Form( deref( $expanded_refed$)),
				 pointed_type);

  Pattern_Return( verification:Form( ()),
		  extraction:Expanded_Form( Form( $exp_deref$ = $expression$),
					    pointed_type))
};

/* Note: With expansion of tuples we really begin patterning, so _
   should be expanded for instance; and there is sub-expansion.

   Note: the semantic of (a, b, ..., c) = (d, e, ... f) can be one of:

   - Eval( d, e, ... f); then affect that to( a, b, ... c)
   - Eval d, then put in a; eval e, then put it in b; ... eval f, then put it in c.

   The two semantics are the same in most cases, where a, b, or c
   don't appear in the right expression.  It is the case in particular
   in function calls and function returns; and in all normal
   operations using tuple (for instance, "big int" operations or
   non-real operations).

   The problem is that if the first semantic seems more natural (it
   allows writing things like (a,b) = (b,a) for instance), it is also
   less efficient (because there is a need to copy the right
   expression temporarily, and elimining this copy is difficult
   because of pointer aliasing).

   I thus think that the low-level language should provide tuple
   operations for the more efficient second semantics (which would
   then be used for all common operations of passing arguments or big
   ints, etc), along with additional functions for
   permutation/exchange of the values of a tuple; and the high level
   language should provide both the low-level and the more natural
   meaning, the later being bound on () and the former on Tuple<> or
   Simple_Tuple<> or something.

   This function could provide the meaning for () by transforming this
   on two affectations: one to a temporary Tuple<>, the second from
   it.  There are additional complications because some affectations
   will be transformed into something else, for instance to a call to
   `puthash'.
*/
function
left_expand_tuple (cf:Compound_Form, expression:Expanded_Form) -> Pattern_Return =
{

  /* We infact have a need for simultaneous making of two lists.  */
  let id_list:List<Symbol>;
  let assign_form_list:List<Expanded_Form>;
  {
    let id_list_ptr = &id_list;
    let assign_form_list_ptr = &assign_form_list;

    let gform = cast( Compound_Form, expression.return_form);
    assert( is_compound_form( gform));
    assert( gform.head == 'tuple');

    foreach( let subexpr in gform.form_list)
      {
	let tuple_copy = gensym( "tuple");
	*id_list_ptr = cons( tuple_copy, cast( List<Symbol>, 0));
	id_list_ptr = &((*id_list_ptr).tail);
	
	let copy_form = Form( let $Id_Form(tuple_copy)$ = $subexpr$);
	
	*assign_form_list_ptr = cons( expand( copy_form), cast( List<Expanded_Form>, 0));
	assign_form_list_ptr = &((*assign_form_list_ptr).tail);
      };
    *assign_form_list_ptr = cast( List<Expanded_Form>, 0);
    *id_list_ptr = cast( List<Symbol>, 0);
  };
    
  /* Now, left-expand the left forms normally.  */
  let cur_id = id_list;
  let second_assign_list:List<Form>;
  {
    let second_assign_list_ptr = &second_assign_list;
    
    foreach( let cur_form in cf.form_list)
      {
	assert( cur_id != cast( List<Symbol>, 0)); /* XXX: for now. */
	let id = cur_id.head;
	*second_assign_list_ptr = cons( left_expand( cur_form, expand( Id_Form( id))),
					cast( List<Form>, 0));
	second_assign_list_ptr = &((*second_assign_list_ptr).tail);
	cur_id = cur_id.tail;
      };
    
    *second_assign_list_ptr = cast( List<Form>, 0);
  };

  assert( cur_id == cast( List<Symbol>, 0));
  let return_form = Form( ($Compound_Form( 'seq', cast( List<Form>,
							assign_form_list))$;
			   $Compound_Form( 'seq', second_assign_list)$));
  
  Pattern_Return( verification:Form( ()),
		  extraction:expand( return_form))
};

function
test() -> Int =
{
  if(false)
    {
      /* This is necessary because c_output is incomplete.  */
      left_expand_let( cast( Compound_Form, 0), cast( Expanded_Form, 0));
      left_expand_deref( cast( Compound_Form, 0), cast( Expanded_Form, 0));
      left_expand_tuple( cast( Compound_Form, 0), cast( Expanded_Form, 0));
    };
  3
};

//include "parser/form.l";
//include "include/l/form.l";