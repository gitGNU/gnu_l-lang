// New grammar for L.
// Copyright (C) 2007 Matthieu Lemerre <racin@free.fr>

compile_time type Exit = struct { dummy:Int;}*;

compile_time type_alias Character = Int;

compile_time expander
Character( form)
{
  let symbol_form = cast( Symbol_Form, form.form_list.head);
  let num = character_from_symbol( symbol_form.value);
  Form( $Int_Form(num)$)
}

compile_time Exit
parse_error()
{
  print( "Parse error\n");
  exit( 3);
  cast( Exit, 3);
}

include "new-parser/grammar-macros.l";


//XXX: the *_Form rules should store the line and character number.
// 
// This comprenhends the lexical elements of the L grammar, but not
// the operators. This should be re-used by most L-specific grammars.
grammar Lexical = {
  rule Comment:Int = "//" [^\n]* "\n" ;
  rule Spacing:Void = ([ \n\t]|Comment)* ;
  rule Alpha:Character = [a-zA-Z_] ;
  rule Alpha_Num:Character = [a-zA-Z_0-9] ;
  rule Digit:Character = d:[0-9] { d - Character( '0')};
  rule Hexa_Digit:Character = (Digit | d:[a-f] { d - Character( 'a')});

  rule Decimal_Number:Int = n:( d:[1-9] {d - Character( '0')})
  (d:Digit {{n = n*10; n = n+d}})* {n};
  rule Hexadecimal_Number:Int = "0x" n:{0}
                                (d:Hexa_Digit {{n = n*16; n = n+d}})* {n};
  rule Number:Int = Decimal_Number | Hexadecimal_Number;
  rule Number_Form:Form = n:Number Spacing {Int_Form( n)};
  
  rule Id:Symbol = start:_ Alpha Alpha_Num* end:_ Spacing
  { intern_string( substring( start, end))} ;
  rule Id_Form:Form = id:Id { Id_Form( id)};

  // XXX: Escaped + number too, like \033
  rule Escaped_Character:Character = [\\] ( "n" {10}
                                          | "t"  {9}
		                          | [^tn] ) ;

  // Here we only count the size needed; the actual string is computed after.
  rule Symbol:Symbol = i:{0} ['] start:_ (([^\'\\] | [\\] [\\nt]) i:{i + 1})* end:_ ['] Spacing
                           { intern_string( get_parsed_string_symbol( i, start, end))};

  rule Symbol_Form:Form = s:Symbol {Symbol_Form( s)};
  
  // Here we only count the size needed; the actual string is computed after.
  rule String:String = i:{0} start:_ (["] (([^\'\\] | [\\] [\\nt]) i:{i + 1})* end:_ ["] Spacing)+
                           { get_parsed_string_string( i, start, end)};

  rule String_Form:Form = s:String {String_Form( s)};

  rule Any:Form = (Id_Form
		  |Number_Form
		  |Symbol_Form
		  |String_Form );

};

// Hash table to call macro parsing functions.
compile_time global parse_macro_hash:Hash( Symbol, (Form <- (Symbol))*);

// This is the grammar for L code, i.e. what is inside a function.
grammar Code = {
  // import Lexical;
  rule Primary:Form =
  form:( id:Lexical.Id //Begin by an id
	   funptr:{parse_macro_hash[id]} 
	   ( &{funptr != cast( (Form <- Symbol)*, 0)} //semantic predicate
	       { funcall( *funptr, id) }         // macro handling
	   | '(' form_list:Expression_List ')' //function handling
	       { Compound_Form( id, form_list)}
	   | ':' exp:Expression { Compound_Form( '@label',
						 list( Id_Form( id),
						       exp)) }
	   | {Id_Form( id)})
       | Lexical.String_Form
       | Lexical.Symbol_Form
       | Lexical.Number_Form
       | '(' expl:Expression_List ')'
           { if(expl == cast( List( Form), 0)
		|| expl.tail != cast( List( Form), 0))
	       Compound_Form( '@tuple', expl)
	       else expl.head }
       | '{' seq:Sequence_List '}'
           { Compound_Form( '@block', seq) }
	 );

  rule Postfix:Form = form:Primary ( '[' form2:Expression ']'
                                       form:{Compound_Form( '@access',
							    list( form, form2))}
                                     | '.' id:Lexical.Id
				       form:{Compound_Form( '@access',
						       list( form, Symbol_Form( id)))}
                                     | '(' form_list:Expression_List ')'
				       form:{Compound_Form( '@funcall',
							    cons( form, form_list))}
//				     | '++' form:{Compound_Form( '@post_++',
//								 list( form))}
//				     | '--' form:{Compound_Form( '@post_--',
//								 list( form))})?
				     )?

                      {form};
				       
  rule Unary_Operator:Form = @Unary_Prefix_Operator( ( '-' {'@unary_minus'}
                                                     | '&' {'@ref'}
	                                             | '*' {'@deref'}
						     | '--' {'@pre_--'}
                       			             | '++' {'@pre_++'}
 					             ), Postfix, Unary_Operator);
  
  rule Multiplicative:Form = @Left_Infix_Operator< '*', Unary_Operator, Multiplicative>;
  rule Additive:Form = @Left_Infix_Operator< ('+'|'-'), Multiplicative, Additive>;
  rule Shift:Form = @Left_Infix_Operator< ('>>'|'<<'), Additive, Shift>;
  rule Relational:Form = @Left_Infix_Operator< ('>'|'>='|'<'|'<='), Shift, Relational>;
  rule Equality:Form = @Left_Infix_Operator< '==', Relational, Equality>;
  rule Bitwise_And:Form = @Left_Infix_Operator< '|', Equality, Bitwise_And>;
  rule Bitwise_Xor:Form = @Left_Infix_Operator< '^', Bitwise_And, Bitwise_Xor>;
  rule Bitwise_Ior:Form = @Left_Infix_Operator< '|', Bitwise_Xor, Bitwise_Ior>;
  rule Logical_And:Form = @Left_Infix_Operator<('and' {'@and'}),Bitwise_Ior, Logical_And>;
  rule Logical_Or:Form = @Left_Infix_Operator< ('or' {'@or'}), Logical_And, Logical_Or>;
  rule Assignment:Form = @Right_Infix_Operator< '=', Logical_Or, Assignment>;
  
  rule Expression:Form = Assignment;

  //Parse a list of expression separated by semicolons, i.e. of the form
  // exp1;exp2;....;exp3.
  // if an exp is empty (comprising the first or last), it is replaced by (), i.e. void.
  rule Sequence_List:List( Form) = tup:{Compound_Form( '@tuple', cast( List( Form), 0))}
                                   exp:(Expression|{tup}) exp_list:(';' e:(Expression|{tup}) {make( e)})*
                                   {cons( exp, exp_list)};

  // Parses as before, but returns a @seq with a simplification.
  // Note: ';' can be viewed as a low priority seq operator, with priority lower than =.
  rule Sequence:Form = sl:Sequence_List { if( sl.tail != cast( List( Form), 0))
                                            Compound_Form( '@seq', sl)
					  else sl.head };

  // An expression list, a comma-separated list of Sequences. Should be surrounded
  // by delimiters, like (). ',' can be viewed as an even lower priority operator than ','.
  rule Expression_List:List( Form) = @Separator< ',', Sequence>;
};

grammar Type = {
  rule Base_Type:Form = id:Lexical.Id 
                        form:(// Structures.
			       &{id == 'struct'} '{'
			       form_list:(lab_type:Labeled_Type ';'
				          {make( lab_type)})* '}'
			        {Compound_Form( 'struct', form_list)}
			      // Misc. constructed types.
			     | "<" form_list2:@Separator(',', Type) ">"
			       {Compound_Form( id, form_list2)}
			      // Base types.
			     | {Id_Form( id)})
                        Lexical.Spacing {form};        

  rule Tuple_Type:Form = ( "(" form_list:@Separator<',', Type> ")"
                           {Compound_Form( '@tuple', form_list)}
                         | Base_Type);
  
  rule Indirection_Type:Form = form:Tuple_Type ('*' form:{Compound_Form( '*', list( form))})*
                               {form};
  
  rule Function_Type:Form = @Right_Infix_Operator( '->', Indirection_Type, Function_Type);
  rule Type:Form = Function_Type;

  rule Labeled_Type:Form = idf:Lexical.Id_Form ":" type:Type {Compound_Form( ':', list(idf , type))};
  
};

grammar Macro = {
//  //import Code
//  //import Lexical
  rule let<symb:Symbol>:Form = id:Lexical.Id_Form typel:{cast( List( Form), 0)}
                               (":" type:Type.Type typel:{list( type)})?
                               {Compound_Form( 'let', cons( id, typel))};

  rule if<symb:Symbol>:Form = '(' cond:Code.Expression ')'
                              exp:Code.Expression 
                              // No else is equivalent to "else void".
                               exp2:( 'else' Code.Expression
				    | {Form( () )})
                               {Compound_Form( 'if', list( cond, exp, exp2))};

  // This type of construct is common, and the parser should be shared between them.
  rule loop<symb:Symbol>:Form = exp:Code.Expression
                                {Compound_Form( symb, list( exp))};
  
};


compile_time global parse_top_level_hash:Hash( Symbol, (Form <- (Symbol))*);

// For global, top-level definitions.
grammar Top_Level = {
  rule Top:Form = id:Lexical.Id {{let funptr = parse_top_level_hash[id];
			     if(funptr == cast( (Form <- Symbol)*, 0))
			       panic( "Parse error: unknown definer '", id, "'\n");
				  funcall( *funptr, id)}};

  // Common definers:
  
  rule function<fsymb:Symbol>:Form = name:Lexical.Id
                                        '(' params:@Separator<',', Type.Labeled_Type> ')'
                                        '->' ret_type:Type.Type '=' body:Code.Expression ';'
  { Compound_Form( 'define',
		   list( Id_Form( fsymb),
			 Compound_Form( ':',
					list( Id_Form( name),
					      Compound_Form( 'lambda',
							     list( Compound_Form( '->',
										  list( Compound_Form( '@tuple',
												       params),
											ret_type)),
								   body))))))};
  rule global<fsymb:Symbol>:Form = ltype:Type.Labeled_Type
                                   { Compound_Form( 'define',
						    list( Id_Form( fsymb),
							  ltype))};
			 
  
};

Void test_top()
{
  set_parser_support_to( "function add_three( i:Int) -> Int = i + 3 + 'toto\n' ;");
  let form = parse( Top_Level.Top);
  print_form( form);
  ();
}


Void test_type()
{
  set_parser_support_to( "truc<toto**,List<Int,Float>*> -> (void*, Hash<struct { a:Int; b:List<Float>; }*, ()>)***");
  let form = parse( Type.Type);
  print_form( form);
  ();
}


Void
init__parse_l()
{
  parse_macro_hash = cast( Hash( Symbol, (Form <- (Symbol))*), make_hash_table());
  parse_macro_hash['let'] = &get_parse_function( Macro.let);
  parse_macro_hash['if'] = &get_parse_function( Macro.if);
  parse_macro_hash['loop'] = &get_parse_function( Macro.loop);

  parse_top_level_hash = cast( Hash( Symbol, (Form <- (Symbol))*), make_hash_table());
  parse_top_level_hash['function'] = &get_parse_function( Top_Level.function);
  
  ();
}

Void
test()
{
  init__parse_l();

  test_top();
  test_type();


  set_parser_support_to( "1 + {} + () + {truc; 25; 64} + {troc;52;} + (22;23,33) + (34) + (35;36;)");
  //set_parser_support_to( "1 + {} + {truc; 25; 64}");
  //  set_parser_support_to( "{truc;}");
  //set_parser_support_to( "{a;}");
  let block_form = parse( Code.Expression);
  print_form( block_form);

  set_parser_support_to( "id:Form = 3");
  let exp = parse( Macro.let, 'let');
  print_form( exp);

  set_parser_support_to( "(truc == 25) 3 + 023 else 23");
  //exp = parse( Macro.if, 'if');
  //  exp = funcall( get_parse_function( Macro.if), 'if');
  exp = funcall( *parse_macro_hash['if'], 'if');
  print_form( exp);


  set_parser_support_to( "loop 1 + truc: if (truc == 25) tat + toto( ta, 23) else let i = 3");
  exp = parse( Code.Expression);
  print_form( exp);
  
  exit(1);

  
  //set_parser_support_to( "toto + 3 * x");
  //  set_parser_support_to( "toto : truc = tric = toto + &3 * truc - 4(3); *toto = @truc< 25, 42> - @ta<> + @to< ve>");
  set_parser_support_to( "toat.truc + 22[toto] - 43(*truc  + 12, 22) + thing() + thing2( param:stuff)");
  let id = parse( Code.Expression);
  print_form( id);
//
//
//  set_parser_support_to( "thing = stuff > staff >> stoof");
//  set_parser_support_to( "staff > stoof >> struff > truc");
//  set_parser_support_to( "or or and");
  set_parser_support_to( "- --x - -- -y");
  id = parse( Code.Expression);
  print_form( id);
//
  //  set_parser_support_to( "13 - 43(*truc  + 12, 22)");
  set_parser_support_to( "13 - 43");
  let form = parse( Code.Expression);
  print_form( form);
  
  //  set_parser_support_to( "uoto *  3");
  //   let id = parse( Code.Multiplicative);
   //   print( "HEllo ", id, "\n");
  ();
}
