//Duplicates

compile_time
Int Character( s:Symbol)
{
  character_from_symbol( s)
}

////////////////////////////////
type Letter = Int;

compile_time type Character_Range = struct { min:Int;
                                max:Int; }*;

compile_time type Character_Set = List( Character_Range);

compile_time Int min( a:Int, b:Int)
{
  if(a <= b) a else b
}

compile_time Int max( a:Int, b:Int)
{
  if(a <= b) b else a
}


// Permet d'ecrire let cs = Character_Set( 'a'-'z','A'-'Z','_')
//compile_time expander Character_Set( form)
//{
//  let new_list = make_list( {
//    foreach( let subform in form.form_list)
//    {
//      if(is_compound_form( subform))
//	{
//	  let cf = cast( Compound_Form, subform);
//	  //assert( cf.head == '-');
//	  let min_form = cf.form_list.head;
//	  let max_form = cf.form_list.tail.head;
//	  make( Form( Character_Range( min:Character( $min_form$),
//				       max:Character( $max_form$))));
//	}
//      else
//	{
//	  make( Form( Character_Range( min:Character( $subform$),
//				       max:Character( $subform$))));
//	}
//    };
//    ()
//    });
//
//  print_form( Form( cast( Character_Set, list( $@new_list$))));
//  Form( cast( Character_Set, list( $@new_list$)))
//  //  Form( 3);
//}

//compile_time Character_Set
//union_Character_Set( cs1_:Character_Set, cs2_:Character_Set)
//{
//  //XXX: as 
//  
////  let cs2 = cast( List( Character_Range), cs2_);
////  let cs1 = cast( List( Character_Range), cs1_);
////
////  let cr1 = cs1.head;
////  let cr2 = cs2.head;
////  
////  let new_list = make_list( {
////      loop {
////	if(cr2.min <= cr1.max + 1 || cr1.min <= cr2.max + 1)
////	  {
////	    //There is an "intersection"
////	    let min = min( cr2.min, cr1.min);
////	    let max = max( cr2.max, cr1.max);
////	    make( Character_Range( min:min, max:max));
////	    }
////	}
//}

compile_time Character_Set
sort_Character_Set (cr_list:List (Character_Range))
{
  let new_cr_list = cast( List( Character_Range), 0);
  foreach( let cr in cr_list)
    {
      let new_cr_list_ptr = &new_cr_list;

      loop {
	if(*new_cr_list_ptr == cast( List( Character_Range), 0))
	  {
	    *new_cr_list_ptr = cons( cr, cast( List( Character_Range), 0));
	    break;
	  }
	
	let next_cr = *new_cr_list_ptr;
	if(cr.max < next_cr.head.min)
	  {
	    let pair = cons( cr, next_cr);
	    *new_cr_list_ptr = pair;
	    break;
	  }

	new_cr_list_ptr = &((*new_cr_list_ptr).tail);
      }
    }
  cast( Character_Set, new_cr_list);
}



compile_time Character_Set
make_Character_Set( form_:Form)
{
  let form = cast( Compound_Form, form_);
  let new_list = make_list( {
    foreach( let subform in form.form_list)
    {
      if(is_compound_form( subform))
	{
	  let cf = cast( Compound_Form, subform);
	  //assert( cf.head == '-');
	  let min_form = cast( Int_Form, cf.form_list.head);
	  let max_form = cast( Int_Form, cf.form_list.tail.head);
	  assert( is_int_form( cast( Form, min_form)));
	  assert( is_int_form( cast( Form, max_form)));

	  make( Character_Range( min:min_form.value,
				 max:max_form.value));
	}
      else
	{
	  let symbol_form = cast( Int_Form, subform);
	  assert( is_int_form( cast( Form, symbol_form)));

	  make( Character_Range( min:symbol_form.value,
				 max:symbol_form.value));
	}
    };
    ()
    });

  sort_Character_Set(new_list);
}

compile_time Character_Set
get_inverse_Character_Set( cs:Character_Set)
{
  // Assumes that the character set is sorted.
  if(cs == cast( Character_Set, 0))
    {
      cast( Character_Set, list( Character_Range( min:1, max:255)))
    }
  else
    {
      let csl = cast( List( Character_Range), cs);
      let first = csl.head;

      let inverse = make_list( {
	  if(first.min != 0)
	    {
	      make( Character_Range( min:0, max:first.min - 1));
	    }

	  let prec = first.max + 1;
	  foreach( let cr in csl.tail)
	    {
	      make( Character_Range( min:prec, max:cr.min - 1));
	      prec = cr.max + 1;
	    }

	  if(prec < 256)
	    {
	      make( Character_Range( min:prec, max:255));
	    }
	  ;()});
      
      cast( Character_Set, inverse)
	}
}    
  
compile_time Character_Set
make_inverse_Character_Set( form:Form)
{
  get_inverse_Character_Set( make_Character_Set( form))
}


compile_time Void
print_Character_Set( s:Character_Set)
{
  let cl = cast( List( Character_Range), s);

  foreach( let cr in cl)
    {
      print( "min:", cr.min, ", max:", cr.max, "\n");
    }
  
}

// Tests whether C is in character set CS.
compile_time Form
is_in_Character_Set_condition( id_form:Form, cs:Character_Set)
{
  let final_cond = Form( cast( Bool, 0)};
  
  foreach( let cr in cast( List( Character_Range), cs))
    {
      let cond = if(cr.min == cr.max)
	{
	  Form( $id_form$ == $Int_Form(cr.min)$)
	} 
      else
	{
	  Form( $id_form$ >= $Int_Form(cr.min)$ && $id_form$ <= $Int_Form(cr.max)$)
	};
      final_cond = Form( $cond$ || $final_cond$);
    }
  final_cond;
}

//
//Void
//test()
//{
// let cs:Character_Set = cast( Character_Set, list( Character_Range( min:Character( '0'),
//								    max:Character( '9'))));
//  print_Character_Set( cs);
//  print_form( is_in_Character_Set_condition( Id_Form( 'toto'), cs));
////  let cs= Character_Set( '0'-'9');
////  print_Character_Set( cs);
////  let cs2 = Character_Set( 'a'-'z', 'A'-'Z', '_');
////  print_Character_Set( cs2);
//  
//
//  make_Character_Set( Compound_Form( '[]', list( Form( 22-33), Form( 44-55), Form( 35-41))));
//  ();
//  
//  
//}
