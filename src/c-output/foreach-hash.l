type Foreach_All_Type = struct { type_type:Int;
                         type_form:Form;
                         size:Int;
                         alignment:Int;
                       };

type Foreach_Real_Type = struct { common_:Foreach_All_Type; }* ;

type Foreach_Expanded_Form = struct { form_type_: Int;
                                      original_form : Form;
				      return_form: Form;
				      type: Foreach_Real_Type ;} *;

//attribute Foreach_Expanded_Form exp.type_form = exp.type.common_.type_form;

expander
foreach_hash (form)
{
  //  assert( form.form_list);
  let var_form = form.form_list.head;
  //  assert( form.form_list.tail);
  let hash_form = expand( form.form_list.tail.head);
  //  assert( form.form_list.tail.tail);
  let body = form.form_list.tail.tail.head;

  let hash_type_form = cast( Foreach_Expanded_Form, hash_form).type.common_.type_form;
  let hash_type_form_compound = cast( Compound_Form, hash_type_form);
  let from_type = hash_type_form_compound.form_list.head;
  let to_type = hash_type_form_compound.form_list.tail.head;
  
 // let loop_name = 'toto';
 // let var_form =  Form ((let key, let value));
 // let hash_form = Form (ht);
 // let body = Form( print( cast( Symbol, key), "/", cast( Int, value), "\n"));

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

//Void
//test()
//{
//  ht = Hash( Symbol, Int);
//  ht['tata'] = 52;
//  ht['toto'] = 23;
//  foreach_hash( (let key, let value), ht,
//		print( key , "/", value, "\n"));
//  let ht2 = Hash( Symbol, Symbol);
//  ht2['truc'] = 'toti';
//  
//  foreach_hash( (let key, let value), ht2,
//		print( key , "/", value, "\n"));
//  //  test_hash_expander();
//  ();
//}
