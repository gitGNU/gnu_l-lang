//Many of these functions could be part of a more general "interval/union of intervals library":
//union, intersection, minus.

//Duplicates

compile_time function
Character( s:Symbol) -> Int =
{
  character_from_symbol( s)
};

////////////////////////////////
type Letter = Int;

compile_time type Character_Range = struct { min:Int;
                                max:Int; }*;

//compile_time type Character_Set = List< Character_Range>;
compile_time type Character_Set = List( Character_Range);

compile_time function min( a:Int, b:Int) -> Int =
{
  if(a <= b) a else b
};

compile_time function max( a:Int, b:Int) -> Int =
{
  if(a <= b) b else a
};


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
////  let cs2 = cast( List< Character_Range>, cs2_);
////  let cs1 = cast( List< Character_Range>, cs1_);
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

compile_time function
sort_Character_Set (cr_list:List< Character_Range>) -> Character_Set = 
{
  let new_cr_list = cast( List< Character_Range>, 0);
  foreach( let cr in cr_list)
    {
      let new_cr_list_ptr = &new_cr_list;

      loop {
	if(*new_cr_list_ptr == cast( List< Character_Range>, 0))
	  {
	    *new_cr_list_ptr = cons( cr, cast( List< Character_Range>, 0));
	    break;
	  };
	
	let next_cr = *new_cr_list_ptr;
	if(cr.max < next_cr.head.min)
	  {
	    let pair = cons( cr, next_cr);
	    *new_cr_list_ptr = pair;
	    break;
	  };

	new_cr_list_ptr = &((*new_cr_list_ptr).tail);
      };
    };
  cast( Character_Set, new_cr_list)
};



compile_time function
make_Character_Set( form_:Form) -> Character_Set = 
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

  sort_Character_Set(new_list)
};

compile_time function
get_inverse_Character_Set( cs:Character_Set) -> Character_Set = 
{
  // Assumes that the character set is sorted.
  if(cs == cast( Character_Set, 0))
    {
      cast( Character_Set, list( Character_Range( min:1, max:255)))
    }
  else
    {
      let csl = cast( List< Character_Range>, cs);
      let first = csl.head;

      let inverse = make_list( {
	  if(first.min != 0)
	    {
	      make( Character_Range( min:0, max:first.min - 1));
	    };

	  let prec = first.max + 1;
	  foreach( let cr in csl.tail)
	    {
	      make( Character_Range( min:prec, max:cr.min - 1));
	      prec = cr.max + 1;
	    };

	  if(prec < 256)
	    {
	      make( Character_Range( min:prec, max:255));
	    };
	  ;()});
      
      cast( Character_Set, inverse)
	}
};    
  
compile_time function
make_inverse_Character_Set( form:Form) -> Character_Set = 
{
  get_inverse_Character_Set( make_Character_Set( form))
};


compile_time function
print_Character_Set( s:Character_Set) ->  Void = 
{
  let cl = cast( List< Character_Range>, s);

  foreach( let cr in cl)
    {
      print( "min:", cr.min, ", max:", cr.max, "\n");
      if(cr.min > 255 or cr.max > 255)
	{panic( "Bad min or max\n")};

    }
  
};

//Enough it the character sets do not intersec.
compile_time function
union_Character_Set( cs1_:Character_Set, cs2_:Character_Set) -> Character_Set = 
{
  let cs1 = cast( List< Character_Range>, cs1_);
  let cs2 = cast( List< Character_Range>, cs2_);

  //  let new_cs = make_list( {
  sort_Character_Set( cast( List< Character_Range>,
			    append( cast( List< Void *>, cs1),
				    cast( List< Void *>, cs2))))
};


//Should return a graph(for LL( *)) (at least a tree for LL( k)) instead;
//but for now we parse too large.
compile_time function
union_Character_Set_List( csl1:List< Character_Set>, csl2:List< Character_Set>) -> List< Character_Set> = 
{
  let l1 = csl1;
  let l2 = csl2;
  let new_list = make_list({loop {
    if(l1 != cast( List< Character_Set>, 0))
      {
	if(l2 != cast( List< Character_Set>, 0))
	  {
	    make( union_Character_Set( l1.head, l2.head));
	    l2 = l2.tail;
	    l1 = l1.tail;
	    continue;
	  };

	//	foreach( let cs1 in l1) make( cs1);
	break;
      }
    else if(l2 != cast( List< Character_Set>, 0))
      {
	//	foreach( let cs2 in l2) make( cs2);
	break;
      };

    break;
      };})
    
			   
  
};


// Tests whether C is in character set CS.
compile_time function
is_in_Character_Set_condition(cs_list:List< Character_Set>) ->  Form = 
{
  let final_cond:Form;
  let final_final_cond = Form( cast( Bool, 1));

  let i = 0;
  
  foreach( let cs in cs_list)
    {
      let get_form = Form( new_peek_char( $Int_Form(i)$));
      i = i + 1;
      final_cond = Form( cast( Bool, 0));
      foreach( let cr in cast( List< Character_Range>, cs))
	{
	  let cond = if(cr.min == cr.max)
	    {
	      Form( $get_form$ == $Int_Form(cr.min)$)
	    } 
	  else
	    {
	      Form( $get_form$ >= $Int_Form(cr.min)$ and $get_form$ <= $Int_Form(cr.max)$)
		};
	  final_cond = Form( $cond$ or $final_cond$);
	};
      final_final_cond = Form( $final_final_cond$ and $final_cond$);
    };
  final_final_cond
};

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
