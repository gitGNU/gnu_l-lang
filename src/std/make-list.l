//Uses list.c as support

type Common_To_All_Type = struct { type_type:Int;
                         type_form:Form;
                         size:Int;
                         alignment:Int;
                       };

type Real_Type = struct { common_:Common_To_All_Type; }* ;

expander make_list (form)
{
  let symb = gensym ("make_list");
  let id_symb = Id_Form( symb);
  
  let symb_ptr = gensym ("make_list_ptr");
  let id_symb_ptr = Id_Form( symb_ptr);

  let lme = List_Maker_Element( ptr_name:symb_ptr,
				type_listed:cast( Type, 0));
  make_list_list = cons( lme,
			 make_list_list);
  //assert( form.form_list.head)
  let subform = form.form_list.head;

  let let_symb_ptr = expand( Compound_Form('let', list( id_symb_ptr,
							Form( pointer( pointer( Void))))));
  let expsubform = expand( subform);

  if(lme.type_listed == cast( Type, 0))
    {
      print( "Error: make_list must contain at least one call to make()\n");
      exit( 3);
    }
  let listed_type_form = cast( Real_Type, lme.type_listed).common_.type_form;
  let list_type_form = Compound_Form( 'List', list( listed_type_form));

  make_list_list = make_list_list.tail;
  
  cast( Form, expand( Form(  {seq( $Compound_Form('let', list( id_symb, list_type_form))$,
				   $cast(Form, let_symb_ptr)$,
				   $id_symb_ptr$ = &cast( Void*, $id_symb$),
				   $cast(Form, expsubform)$,
				   *$id_symb_ptr$ = cast( Void *, 0),
				   $id_symb$)})))
}

expander make( form)
{
  if(make_list_list == cast( List( List_Maker_Element), 0))
    {
      print( "Error: Trying to make an element outside of a make_list\n");
      exit( 3);
    }
  let top = make_list_list.head;

  let symb_ptr = top.ptr_name;
  let id_symb = Id_Form( symb_ptr);
  let type_listed = top.type_listed;

  let subform = form.form_list.head;
  let exp_subform = expand( subform);
  let type = exp_subform.type;

  if(type_listed != cast( Type, 0))
    {
      if(type_listed != type)
	{
	  print( "Type mismatch: trying to make an heterogeneous list\n");
	  exit( 3);
	}
    }
  else
    {
      top.type_listed = type;
      ();
    }
  
  Form( seq( *$id_symb$ = alloc_cons_cell(),
	     (*cast( struct {car:Void*; cdr:Void*;}**,
		     $id_symb$)).car = cast( Void *, $cast(Form, exp_subform)$),
	     $id_symb$ = &((*cast( struct {car:Void*; cdr:Void*;}**,
				   $id_symb$)).cdr)));
}

Void
test()
{
  let newlist = make_list( {
      foreach( let element in list( 1,2,3,4))
	{
	  make( 3*element);
	};()});

  foreach( let element in newlist)
    {
      print( "Element: ", element, "\n");
    }
  print( "-------\n");

  let list = make_list( {make( 'toto'); make( 'tata')});

  foreach( let element in list)
    {
      print( "Element: ", element, "\n");
    }

  //  let list3 = make_list({});
  //  make( 23);
  //  make_list( {make( 'toto'); make( 3)});
}
