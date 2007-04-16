//Already defined in support.
//type Expanded_Form = struct { form_type_: Int;
//                              original_form : Form;
//                              return_form: Form;
//                              type: Type ;} *;

type Expanded_Compound_Form = struct { useless_form_type_ : Int;
                                       useless2: Int;
                                       return_form_ : Compound_Form;
                                       type: Type ;} *;

attribute Expanded_Compound_Form exp.head = right:exp.return_form_.head;
attribute Expanded_Compound_Form exp.form_list = right:cast( List( Expanded_Form),
							     exp.return_form_.form_list);


global c_output_hash:Hash( Symbol, (Void <- Expanded_Compound_Form)*);

//Set of the functions (in the future, also globals) needed
global globals_needed:Hash( Symbol, Bool);

global stdout_descriptor:Output_Descriptor;

global output_file_descriptor:Output_Descriptor;
global inc_file_descriptor:Output_Descriptor;

expander print_error( form)
{
  Form( {let save_od_ = current_output_descriptor;
         current_output_descriptor = stdout_descriptor;
	 print( $@form.form_list$);
	 flush();
         current_output_descriptor = save_od_})
}

//XXX: temporary, because Form( condition) is really expansive.
macro assert( condition) = 
  if( condition == cast( Bool, 0))
    {
      print_error( "Assertion ");
      print_form( Form( condition));
      print_error( " failed\n");
      exit( 3)
    };

expander panic( form)
{
  Form({current_output_descriptor = stdout_descriptor;
      print( "Panic : ", $@form.form_list$);
      flush();
      exit( 3)})
}

////////////////////////////////////////
Bool
is_compound_form( f:Form)
{
  let rf = cast( Form, f);
  rf.form_type_ == 1811939328
}

Bool
is_expanded_form( f:Form)
{
  f.form_type_ == -536870912
}
   

Bool
is_id_form( f:Form)
{
  let rf = cast( Form, f);
  rf.form_type_ == -1342177280
}


Bool
is_int_form( f:Form)
{
  let rf = cast( Form, f);
  rf.form_type_ == -2147483648
}

Bool
is_symbol_form( f:Form)
{
  let rf = cast( Form, f);
  rf.form_type_ == -1073741824
}


Bool
is_string_form( f:Form)
{
  let rf = cast( Form, f);
  rf.form_type_ == -1610612736
}


////////////////////////////////////////
include "c-output/c-output-type.l";


///////////////////////////////////////
Void
c_output_form( expf:Expanded_Form)
{ buffered {
    let f = expf.return_form;
    if( is_compound_form( f))
      {
	let cf = cast( Compound_Form, f);
	let fun = c_output_hash[cf.head];
	if(fun == cast( (Void <- Expanded_Compound_Form)*, 0))
	  {
	    panic( "No output function defined for ", cf.head, "\n");
	  }

	funcall( *fun, cast( Expanded_Compound_Form, expf));
      }
    else
      {
	if( is_id_form( f))
	  {
	    let id_form = cast( Id_Form, f);
	    print( convert_id( id_form.value));
	  }
	else if( is_int_form( f))
	  {
	    let int_form = cast( Int_Form, f);
	    print( int_form.value);
	  }
	else if( is_symbol_form( f))
	  {
	    //Should be initialised once and always used after that.
	    let symbol_form = cast( Symbol_Form, f);
	    print( 'intern( "', convert_id_as_string( symbol_form.value), '")');
	  }
	else if( is_string_form( f))
	  {
	    //Should be initialised once and always used after that.
	    let string_form = cast( String_Form, f);
	    let string = convert_string( string_form.value);
	    print( '(&(struct { unsigned int len; char *content;}){strlen( "',
		   string, '"), "', string, '"})');
	  }
      
	else
	  {
	    panic( "f.form_type_=", cast( Form, f).form_type_);
	  }
      }
  }
}

//////////////////////////////
//A macro would be useful here.

Void
c_output_add_int( cf:Expanded_Compound_Form)
{
  buffered print( "((int) ", cf.form_list.head:gnu_c,
		  " + (int) ", cf.form_list.tail.head:gnu_c, ")");
}

Void
c_output_mul_int( cf:Expanded_Compound_Form)
{
  buffered print( "((int) ", cf.form_list.head:gnu_c,
		  " * (int) ", cf.form_list.tail.head:gnu_c, ")");
}

Void
c_output_sub_int( cf:Expanded_Compound_Form)
{
  buffered print( "((int) ", cf.form_list.head:gnu_c,
		  " - (int) ", cf.form_list.tail.head:gnu_c, ")");
}

Void
c_output_div_int( cf:Expanded_Compound_Form)
{
  buffered print( "((int) ", cf.form_list.head:gnu_c,
		  " / (int) ", cf.form_list.tail.head:gnu_c, ")");
}

Void
c_output_unary_minus_int( cf:Expanded_Compound_Form)
{
  buffered print( "(- (int) ", cf.form_list.head:gnu_c,")");
}



Void
c_output_ge_int( cf:Expanded_Compound_Form)
{
  buffered print( "((int) ", cf.form_list.head:gnu_c,
		  " >= (int) ", cf.form_list.tail.head:gnu_c, ")");
}

Void
c_output_gt_int( cf:Expanded_Compound_Form)
{
  buffered print( "((int) ", cf.form_list.head:gnu_c,
		  " > (int) ", cf.form_list.tail.head:gnu_c, ")");
}


Void
c_output_le_int( cf:Expanded_Compound_Form)
{
  buffered print( "((int) ", cf.form_list.head:gnu_c,
		  " <= (int) ", cf.form_list.tail.head:gnu_c, ")");
}

Void
c_output_lt_int( cf:Expanded_Compound_Form)
{
  buffered print( "((int) ", cf.form_list.head:gnu_c,
		  " < (int) ", cf.form_list.tail.head:gnu_c, ")");
}


Void
c_output_different( cf:Expanded_Compound_Form)
{
  buffered print( "(", cf.form_list.head:gnu_c,
		  " != ", cf.form_list.tail.head:gnu_c, ")");
}


Void
c_output_equal( cf:Expanded_Compound_Form)
{
  buffered print( "(", cf.form_list.head:gnu_c,
		  " == ", cf.form_list.tail.head:gnu_c, ")");
}

///////////////////////////
//And also here, to extract all the constituents of an expanded compound form.

Void
c_output_access_struct( cf:Expanded_Compound_Form)
{
  buffered {
    print( "(", cf.form_list.head:gnu_c, ".");
    assert( is_symbol_form( cf.form_list.tail.head.return_form));
    print( cast( Symbol_Form, cf.form_list.tail.head.return_form).value, ")");
  }
}

Void
c_output_assign( cf:Expanded_Compound_Form)
{
  buffered {
    print( "(");
    c_output_form( cf.form_list.head);
    print( " = ");
    c_output_form( cf.form_list.tail.head);
    print( ")");
  }
}

//We always output blocks as GNU C's statement expressions.
Void
c_output_block( cf:Expanded_Compound_Form)
{
  buffered {
    print( "({\n");
    foreach( let subform in cf.form_list)
      {
	print( subform:gnu_c, ";\n");
      }
    print( "})\n");
  }
}

Void
c_output_cast( cf:Expanded_Compound_Form)
{
  buffered {
    print( "((");
    c_output_type( '', intern_type( cf.form_list.head.return_form));
    print( ") ", cf.form_list.tail.head:gnu_c, ")");
  }
}

Void
c_output_deref( cf:Expanded_Compound_Form)
{
  buffered print( "(* ", cf.form_list.head:gnu_c, ")");
}


Void
c_output_funcall( cf:Expanded_Compound_Form)
{
  //XXX: There must be a first pass so that the arguments are processed in order.
  let function = cf.form_list.head;
  if(is_id_form( function.return_form))
    {
      globals_needed[cast( Id_Form, function.return_form).value] = cast( Bool, 1);
    }
  buffered {
    print( "(", function:gnu_c, ")(");
    if(cf.form_list.tail != cast( List( Expanded_Form), 0))
      {
	print( cf.form_list.tail.head:gnu_c);
	foreach( let subform in cf.form_list.tail.tail)
	  print( ", ", subform:gnu_c);
      }
    print( ")");
  }
}


Void
c_output_if( cf:Expanded_Compound_Form)
{
  let condition = cf.form_list.head;
  let then = cf.form_list.tail.head;
  buffered {
    if(cf.form_list.tail.tail == cast( List( Expanded_Form), 0))
      {
	print( "({if( ", condition:gnu_c, ")\n{\n", then:gnu_c, ";}})\n");
      }
    else
      {
	let elsef = cf.form_list.tail.tail.head;
	print( "((", condition:gnu_c, ")?\n(",
	       then:gnu_c, "):\n(",
	       elsef:gnu_c, "))");
      }
  }
}

Void
c_output_get_label( cf:Expanded_Compound_Form)
{
  assert( cf.form_list.tail == cast( List( Expanded_Form), 0));
  assert( is_id_form( cast( Form, cf.form_list.head)));
  let label_form = cast( Id_Form, cf.form_list.head);
  buffered print( "&&", convert_id( label_form.value));
}

Void
c_output_goto_constant( cf:Expanded_Compound_Form)
{
  assert( cf.form_list.tail == cast( List( Expanded_Form), 0));
  let id_form = cast( Id_Form, cf.form_list.head);
  assert( is_id_form( cast( Form, id_form)));
  
  buffered print( "({goto ", convert_id( id_form.value), ";})");
}

Void
c_output_goto_variable( cf:Expanded_Compound_Form)
{
  assert( cf.form_list.tail == cast( List( Expanded_Form), 0));
  assert( is_compound_form( cf.form_list.head.return_form));
  assert( cast( Compound_Form, cf.form_list.head.return_form).head == 'deref');
  print( "({goto *",
	 cast( Expanded_Compound_Form, cf.form_list.head).form_list.head:gnu_c,
	 ";})");
}



Void
c_output_label( cf:Expanded_Compound_Form)
{
  assert( cf.form_list.tail == cast( List( Expanded_Form), 0));
  assert( is_id_form( cast( Form, cf.form_list.head)));
  let label_form = cast( Id_Form, cf.form_list.head);
  buffered print( "((void) 0);", convert_id( label_form.value), ":((void) 0)");
}


//We rely on the fact that lets are at the beginning of blocks after expansion.
Void
c_output_let( cf:Expanded_Compound_Form)
{
  buffered {
    assert( is_id_form( cast( Form, cf.form_list.head)));
    c_output_type( convert_id( cast( Id_Form, cf.form_list.head).value),
		   intern_type( cast( Form, cf.form_list.tail.head)));
  }
}

Void
c_output_ref( cf:Expanded_Compound_Form)
{
  buffered {
    print( "(&", cf.form_list.head:gnu_c, ")");
  }
}

Void
c_output_seq( cf:Expanded_Compound_Form)
{
  buffered {
    assert( cf.form_list != cast( List( Expanded_Form), 0));
    print( cf.form_list.head:gnu_c);
    foreach( let subform in cf.form_list.tail)
      {
	print( ",\n", subform:gnu_c);
      }
  }
}

//We output C99 compound literals; we use the type information for that.
Void
c_output_struct( cf:Expanded_Compound_Form)
{
  buffered {
    print( "((");
    c_output_type( '', cf.type);
    print( "){");

    { let subform_ = cf.form_list.head;
      assert( is_compound_form( subform_.return_form));
      assert( cast( Compound_Form, subform_.return_form).head == 'label');
      let form_subform = cast( Expanded_Compound_Form, subform_).form_list.tail.head;
      print(form_subform:gnu_c); }
    
    foreach( let subform_ in cf.form_list.tail)
      {
	assert( is_compound_form( subform_.return_form));
	assert( cast( Compound_Form, subform_.return_form).head == 'label');
	let form_subform = cast( Expanded_Compound_Form, subform_).form_list.tail.head;
	print(", ", form_subform:gnu_c);
      }
    print( "})");
  }
}

Void
c_output_tuple( cf:Expanded_Compound_Form)
{
  if(cf.form_list == cast( List( Expanded_Form), 0))
    {
      // Return explicit void.  
      print( "((void) 0)");
    }
  else panic( "Unimplemented\n");
}

Void
init_c_output()
{
  c_output_hash = cast( Hash( Symbol, ((Void) <- Expanded_Compound_Form)*), make_hash_table());
  //  c_output_hash = Hash( Symbol, (Void <- Expanded_Compound_Form)*);
  c_output_hash['+_Int'] = &c_output_add_int;
  c_output_hash['*_Int'] = &c_output_mul_int;
  c_output_hash['-_Int'] = &c_output_sub_int;
  c_output_hash['/_Int'] = &c_output_div_int;
  c_output_hash['unary_minus_Int'] = &c_output_unary_minus_int;
  c_output_hash['>=_Int'] = &c_output_ge_int;
  c_output_hash['>_Int'] = &c_output_gt_int;
  c_output_hash['<=_Int'] = &c_output_le_int;
  c_output_hash['<_Int'] = &c_output_lt_int;
  c_output_hash['=='] = &c_output_equal;
  c_output_hash['!='] = &c_output_different;

  c_output_hash['='] = &c_output_assign;
  c_output_hash['[]_Struct'] = &c_output_access_struct;
  c_output_hash['block'] = &c_output_block;
  c_output_hash['cast'] = &c_output_cast;
  c_output_hash['deref'] = &c_output_deref;
  c_output_hash['funcall'] = &c_output_funcall;
  c_output_hash['if'] = &c_output_if;
  c_output_hash['@get_label'] = &c_output_get_label;
  c_output_hash['@goto_constant'] = &c_output_goto_constant;
  c_output_hash['@goto_variable'] = &c_output_goto_variable;
  c_output_hash['label'] = &c_output_label;
  c_output_hash['let'] = &c_output_let;
  c_output_hash['ref'] = &c_output_ref;
  c_output_hash['seq'] = &c_output_seq;
  c_output_hash['struct'] = &c_output_struct;
  c_output_hash['tuple'] = &c_output_tuple;

  init_output_type();
}

//////////////////////////////////////////////////

Void
c_output_function_definition( name:Symbol, l_:Form)
{
  assert( is_expanded_form( l_));
  //L is a lambda form.
  let l = cast( Expanded_Form, l_).return_form;
  assert( is_compound_form( l));
  assert( cast( Compound_Form, l).head == 'lambda');
  
  let form_list = cast( List( Form), cast( Compound_Form, l).form_list);

  let return_type = form_list.head;
  c_output_type( '', intern_type( return_type));
  print( " ", name, "(");
  let parameters_type = cast( Compound_Form, form_list.tail.head);
  assert( parameters_type.head == 'tuple');

  if(parameters_type.form_list == cast( List( Form), 0))
    print( "void");
  else
    {
      let first_parameter = cast( Compound_Form, parameters_type.form_list.head);
      assert( first_parameter.head == 'label');
      let first_param_name = cast( Id_Form, first_parameter.form_list.head);
      let first_param_type = first_parameter.form_list.tail.head;
  
      c_output_type( '', intern_type( cast( Form, first_param_type)));
      print( " ", first_param_name.value);
   
      foreach( let parameter
	       in cast( List( Compound_Form), parameters_type.form_list.tail))
	{
	  print( ", ");
	  assert( first_parameter.head == 'label');
	  let param_name = cast( Id_Form, parameter.form_list.head);
	  let type = parameter.form_list.tail.head;
  
	  c_output_type( '', intern_type( cast( Form, type)));
	  print( " ", param_name.value);
	}
    }
  print( ")\n{\nreturn ");
  print( cast( Expanded_Form, form_list.tail.tail.head):gnu_c);
  print( ";}\n\n");
  //let return_type_form = 
}


Void
c_output_global_definition( name:Symbol, form_type:Form)
{
  c_output_type( name, intern_type( form_type));
  print( ";\n\n");
}



Void
c_output_definition( f:Compound_Form)
{
  assert( is_compound_form( cast( Form,f)));
  assert( f.head == 'define');
  let form_list = cast( List( Form), cast( Compound_Form, f).form_list);
  assert( is_id_form( form_list.head));
  let species = cast( Id_Form, form_list.head).value;
  
  assert( is_id_form( form_list.tail.head));
  let name = cast( Id_Form, form_list.tail.head).value;
  
  if(species == 'function')
    {
      c_output_function_definition( name, cast( Form, form_list.tail.tail.head));
    }
  else if(species == 'type')
    {
      ();
      //c_output_type_definition( name, cast( Form, form_list.tail.tail.head));
    }
  else if(species == 'global')
    {
      c_output_global_definition( name, form_list.tail.tail.head);
      ();
    }
  else if(species == 'expander')
    {
      ();
    }
  else if(species == 'attribute')
    {
      ();
    }
  else
    {
      print_error( "Species '", species, "'\n");
      panic( "Not implemented\n");
    }
}

Void
doit( l_file:String, out_c_file:String, out_inc_file:String)
{
  globals_needed = Hash( Symbol, Bool);
  reinit_types();

  
  stdout_descriptor = current_output_descriptor;
  output_file_descriptor = make_output_descriptor_write_file( out_c_file);
  inc_file_descriptor = make_output_descriptor_write_file( out_inc_file);

  let form_list = expanded_form_list_from_file_name( l_file);

  current_output_descriptor = output_file_descriptor;
  
  print( '#include "', file_name_non_directory( out_inc_file), '"', "\n");

  foreach( let f in form_list)
    c_output_definition( f);

  print( 'void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( "TEST result: %d", test_ptr());flush();}', "\n");
  flush();

  //The types of the functions we use must be outputed too.
  foreach( (let symbol, let misc_) in globals_needed)
    {
      let t:Type = get_global_type( symbol);
      type_definition_needed[t] = cast( Bool, 1);
    }

  //XXX: And the types of the globals.
  current_output_descriptor = inc_file_descriptor;
  output_all_type_definitions(); //Output the types definitions

  foreach( (let symbol, let misc_) in globals_needed)
    {
      let t:Type = get_global_type( symbol);
      c_output_type( symbol, t);
      print( ";\n");
    }

  // XXX: We don't print the globals for now.
  print( "Output_Descriptor__type current_output_descriptor;\n",
	 "Output_Descriptor__type stdout_descriptor;\n");
  flush();
}


Void
test ()
{
  stdout_descriptor = current_output_descriptor;
  init_c_output();

//  let form_list = expanded_form_list_from_file_name( "../test/cocyte01-function-definition.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte02-let.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte03-funcall.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte04-funcall-args.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte05-inner-blocks.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte06-spilling.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte07-if.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte08-if-spilling.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte09-cast.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte10-loop.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte11-recursive-functions.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte12-structures.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte13-pointers.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte14-types.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte15-rec-types.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte16-basic-tuple.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte17-struct-copy.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte18-bool-values.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte19-goto.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte20-expected-type.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte21-globals.l");
//  let form_list = expanded_form_list_from_file_name( "../test/cocyte22-funcall.l");
    
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge01-pointer-access.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge02-list.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge03-xml.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge04-print.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge05-hash.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge06-form.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge07-creator.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge08-let-wo-type.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge09-foreach.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge10-expanders.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge11-macros.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge12-virtual-attributes.l");
//  let form_list = expanded_form_list_from_file_name( "../test/malebolge13-shadow.l");

//  let form_list = expanded_form_list_from_file_name( "c-output/c-output-type.l");
//  let form_list = expanded_form_list_from_file_name( "c-output/foreach-hash.l");
//  let form_list = expanded_form_list_from_file_name( "c-output/c-output.l");

  doit("c-output/c-output.l", "c-output/c-output.c", "c-output/c-output.inc");
  //  doit("to_output.l", "to_output.c", "to_output.inc");
}