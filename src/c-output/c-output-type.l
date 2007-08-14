// Type handling has two main functions:
// c_output_type output a type along with a given name, and records that this type is needed
// c_output_type_definition outputs the definitions.

//////////////////////////////
// Type handling

global inc_file_descriptor:Output_Descriptor;

type Common_To_All_Type = struct { type_type:Int;
                         type_form:Form;
                         size:Int;
                         alignment:Int;
                       };

type Real_Type = struct { common_:Common_To_All_Type; }* ;

type Base_Type = struct { common_:Common_To_All_Type;
                          misc_data_:Int;
                          origin_type:Type; } *;

// Only Type should be exposed; but we also need Base_Type's original type.
attribute Type t.type_form = cast( Real_Type, t).common_.type_form;
attribute Base_Type t.type_form = cast( Real_Type, t).common_.type_form;

// This could be done using the type form.
function
is_struct_type( t:Type) -> Bool =
{
  let nt = cast( Real_Type, t);
  nt.common_.type_type == 0
};

function
is_base_type( t:Type) -> Bool =
{
  let nt = cast( Real_Type, t);
  nt.common_.type_type == 3
};

function
is_pointer_type( t:Type) -> Bool =
{
  let nt = cast( Real_Type, t);
  nt.common_.type_type == 4
};

function
is_tuple_type( t:Type) -> Bool =
{
  let nt = cast( Real_Type, t);
  nt.common_.type_type == 2
};

function
is_function_type( t:Type) -> Bool =
{
  let nt = cast( Real_Type, t);
  nt.common_.type_type == 1
};

//Set to 1 if there is a need to output the definition
global type_definition_needed:Hash< Type, Bool>;

//Set to 1 when the type has been outputed.
global has_been_outputed:Hash< Type, Bool>;

//This outputs an object name of type TYPE.
function
c_output_type( name:Symbol, t:Type) -> Void =
{
  type_definition_needed[t] = cast( Bool, 1);
  if(is_base_type( t))
    {
      let bt = cast( Base_Type, t);
      if(bt.origin_type == cast( Type, 0))
	{
	  assert( is_id_form( bt.type_form));
	  print( cast( Id_Form, bt.type_form).value);
	}
      else print( mangle_type_name( t));
      
      print( "__type ", name);
    }
  else if(is_struct_type( t))
    {
      print( "struct struct", hex:cast( Int, t),
	     " ", name);
    }
  else if(is_pointer_type( t))
    {
      //For now, we call prepend_star as a workaround.
      c_output_type( prepend_star( name), intern_type( cast( Compound_Form,
							     t.type_form).form_list.head));
    }
  else if(is_tuple_type( t))
    {
      let tf = cast( Compound_Form, t.type_form);
      if(tf.form_list == cast( List< Form>, 0))
	{
	  print( "void ", name);
	}
      else 
	{
	  print_form( t.type_form);
	  panic( "Non void tuples not implemented\n");
	}
    }
  else if(is_function_type( t))
    {
      let form_list = cast( Compound_Form, t.type_form).form_list;
      let return_type = intern_type( form_list.head);
      c_output_type( '', return_type);
      print( "(", name, ")");

      let parameters = cast( Compound_Form, form_list.tail.head);
      if(parameters.form_list == cast( List< Form>, 0))
	{
	  print( "(void)");
	}
      else
	{
	  print( "(");
	  c_output_type('',  intern_type( parameters.form_list.head));
	  foreach( let parameter in parameters.form_list.tail)
	    {
	      print( ", ");
	      c_output_type('', intern_type( parameter));
	    };
	  print( ")");
	};
    }
  else {
      print_form( t.type_form);
      panic( "Unimplemented\n");
  };
};

//This output the type definitions.
function
c_output_type_definition(t:Type) -> Void =
{
  if(has_been_outputed[t] == cast( Bool, 0))
    {
      has_been_outputed[t] = cast( Bool, 1);
      if(is_base_type( t))
	{
	  let bt = cast( Base_Type, t);
	  if(bt.origin_type == cast( Type,0))
	    {
	      //We found a base type, like Word.
	      goto( end);
	    };
      
	  if(has_been_outputed[bt.origin_type])
	    {goto (next);};
	  c_output_type_definition( bt.origin_type);

	next:
	  print( "typedef ");
	  c_output_type( mangle_type_name( t),
			 bt.origin_type);
	  print( "__type");
	  print( ";\n");
	}
      else if(is_struct_type( t))
	{
	  let tf = t.type_form;
	  // Define all the yet undefined types.
	  foreach( let label_form_ in cast( Compound_Form, tf).form_list)
	    {
	      assert( is_compound_form( label_form_));
	      let label_form = cast( Compound_Form, label_form_);
	      assert( label_form.head == 'label');
	      let subtf = label_form.form_list.tail.head;
	      let subtype = intern_type( subtf);
	      if(has_been_outputed[subtype])
		continue;
	      c_output_type_definition( subtype);
	    };

	  print( "struct struct", hex:cast( Int, t), " {\n");
	  foreach( let label_form_ in cast( Compound_Form, tf).form_list)
	    {
	      let label_form = cast( Compound_Form, label_form_);
	      assert( is_id_form( label_form.form_list.head));
	      let field_name = cast( Id_Form, label_form.form_list.head).value;
	      let subtf = label_form.form_list.tail.head;
	      let subtype = intern_type( subtf);
	      //	      print_error( "Field name: ", field_name, "|struct: ",
	      //			   hex:cast( Int, t),"|");
	      //	      lispify( subtf);
	      //	      print_error( "\n");
	      c_output_type( field_name, subtype);
	      print( ";\n");
	    };
	  print( "};\n");
      
	  //D'abord, on definit tous les sous types.
	  //HERE
	}
      else if(is_pointer_type( t))
	{
	  let tf = cast( Compound_Form, t.type_form);
	  // If we point to a struct, we don't need to explicit it.
	  if(is_compound_form( tf.form_list.head))
	    {
	      let ptf = cast( Compound_Form, tf.form_list.head);
	      if(ptf.head == 'struct')
		goto (end);
	    };
	  // Else we have.  
	  c_output_type_definition( intern_type( tf.form_list.head));
	}
      else if(is_function_type( t))
	{
	  //For functions, just make sure that the return and parameter types are known
	  let tf = cast( Compound_Form, t.type_form);
	  let to_type = intern_type( tf.form_list.head);
	  c_output_type_definition( to_type);
	  let from_type = intern_type( tf.form_list.tail.head);
	  c_output_type_definition( from_type);
	}
      else if(is_tuple_type( t))
	{
	  let tf = cast( Compound_Form, t.type_form);
	  foreach( let subform in tf.form_list)
	    {
	      let type = intern_type( subform);
	      c_output_type_definition( type);
	    }
	}
    };
 end:
};

function
output_all_type_definitions() -> Void =
{
  let save_descriptor = current_output_descriptor;
  //  inc_file_descriptor = make_output_descriptor_write_file( "cocyte01.inc");
  current_output_descriptor = inc_file_descriptor;
  print( "typedef int Int__type;\n",
	 "typedef int Bool__type;\n",
	 "typedef void *Type__type;\n",
	 "typedef void* Label__type;\n",
	 "typedef void Void__type;\n",
	 "typedef struct {} * Symbol__type;\n\n",
	 "typedef struct {unsigned int len; char *content;} * String__type;\n\n");

  print( "Symbol__type intern( const char * string);\n");
  print( "Void__type print_Int_Dec( int i);\n");
  print( "Void__type print_String( String__type s);\n");
  print( "void maybe_flush( void);\n");
  print( "String__type make_heap_string( char *s);\n");
  print( "\n");
  flush();
  current_output_descriptor = save_descriptor;
  ();
  
  //XXX: use remhash.
  foreach( (let type, let bool) in type_definition_needed)
    {
      if( bool)
	{ c_output_type_definition( type);
	}
    }
};

function
reinit_types() -> Void =
{
  type_definition_needed = Hash( Type, Bool);
  has_been_outputed = Hash( Type, Bool);
  ();
};

function
init_output_type() -> Void =
{

//  let save_descriptor = current_output_descriptor;
//  //  inc_file_descriptor = make_output_descriptor_write_file( "cocyte01.inc");
//  current_output_descriptor = inc_file_descriptor;
//  print( "typedef int Int__type;\n",
//	 "typedef int Bool__type;\n",
//	 "typedef void *Type__type;\n",
//	 "typedef void* Label__type;\n",
//	 "typedef void Void__type;\n",
//	 "typedef struct {} * Symbol__type;\n\n",
//	 "typedef struct {unsigned int len; char *content;} * String__type;\n\n");
//
//  print( "Symbol__type intern( const char * string);\n");
//  print( "Void__type print_Int_Dec( int i);\n");
//  print( "Void__type print_String( String__type s);\n");
//  print( "void maybe_flush( void);\n");
//  print( "String__type make_heap_string( char *s);\n");
//  print( "\n");
//  flush();
//  current_output_descriptor = save_descriptor;
//  ();
};


//Void
//test()
//{
//  type_definition_needed = Hash( Type, Bool);
//
//
//  type_definition_needed[intern_type( Form( Tete))] = cast( Bool, 1);
//
//  ();
////  type_definition_needed[intern_type( Form( Int_List))]= cast( Bool, 1);
////  type_definition_needed[intern_type( Form( Toto))] = cast( Bool, 1);
////  type_definition_needed[intern_type( Form( Titi))] = cast( Bool, 1);
//    
//
//  //  c_output_type_definition( intern_type( Form( Tata)));
//  //  c_output_type_definition( intern_type( Form( Toto)));
//  //c_output_type_definition( intern_type( Form( Int_List)));
//  
//  //  c_output_type( 'toto', intern_type( struct { i:Int; l:Int_List;} *))
//  //				     Form( Int_List)));
//  
//}


//Void
//c_output_type( tf:Form)
//{
//  buffered {
//    if(is_id_form( tf))
//      {
//	let type_ = intern_type( tf);
//	assert( is_base_type( type_));
//	let btype = cast( Base_Type, type_);
//	
//	if(btype.origin_type == type_)
//	  panic( "Same as origin type\n");
//	
//	if(btype.origin_type == cast( Type, 0))
//	  {
//	    let type_symbol = cast( Id_Form, tf).value;
//	    print( type_symbol);
//	  }
//	else
//	  {
//	    
//	    lispify( cast( struct {common_:All_Type;}*,
//				 btype.origin_type).common_.type_form);
//	  }
//      }
//    else if(is_compound_form( tf))
//      {
//	let symbol = cast( Compound_Form, tf).head;
//	if(symbol == 'struct')
//	  {
//	    print( "struct {\n");
//	    foreach( let label_form_ in cast( Compound_Form, tf).form_list)
//	      {
//		let label_form = cast( Compound_Form, label_form_);
//		assert( is_compound_form( cast( Form, label_form)));
//		assert( cast( Compound_Form, label_form).head == 'label');
//		let name = cast( Id_Form, label_form.form_list.head).value;
//		let type = cast( Form, label_form.form_list.tail.head);
//		c_output_type( type);
//		print( " ", name, ";\n");
//	      }
//	    print( "}");
//	  }
//	else if(symbol == 'pointer')
//	  {
//	    let pointed_type_form = cast( Form,
//					  cast( Compound_Form, tf).form_list.head);
//	    c_output_type( pointed_type_form);
//	    print( "*");
//	  }
//	else panic( "Unknown, not handled for now. ");
//      }
//    else panic( "Not simple type\n");
//  }
//}
