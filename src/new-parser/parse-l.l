
// New grammar for L.
// Copyright (C) 2007 Matthieu Lemerre <racin@free.fr>

compile_time type Exit = struct { dummy:Int;}*;

compile_time type_alias Character = Int;

compile_time expander
Character( form) =
{
  let symbol_form = cast( Symbol_Form, form.form_list.head);
  let num = character_from_symbol( symbol_form.value);
  Form( $Int_Form(num)$)
};

compile_time function
parse_error() ->  Exit =
{
  print( "Parse error\n");
  exit( 3);
  cast( Exit, 3)
};

include "new-parser/grammar-macros.l";

//XXX: the *_Form rules should store the line and character number.
// 
// This comprenhends the lexical elements of the L grammar, but not
// the operators. This should be re-used by most L-specific grammars.
grammar Lexical = {
  rule Comment:Int = "//" [^\n]* "\n" ;
  //XXX: Maybe Spacing should have a +, and other parts could use Spacing? if they want.
  rule Spacing:Void = ([ \n\t]|Comment)* ;
  rule Alpha:Character = [a-zA-Z_] ;
  rule Alpha_Num:Character = [a-zA-Z_0-9] ;
  rule Digit:Character = d:[0-9] { d - Character( '0')};
  rule Octal_Digit:Character = d:[0-7] { d - Character( '0')};
  rule Hexa_Digit:Character = (Digit | d:[a-f] { d - Character( 'a') + 10});

  rule Decimal_Number:Int = n:( d:[1-9] {d - Character( '0')})
  (d:Digit {{n = n*10; n = n+d}})* {n};
  rule Hexadecimal_Number_End:Int = n:{0}
                                (d:Hexa_Digit {{n = n*16; n = n+d}})* {n};
  rule Octal_Number_End:Int = n:{0}
                                (d:Octal_Digit {{n = n*8; n = n+d}})* {n};
  
  rule Number:Int = Decimal_Number | "0" ("x" Hexadecimal_Number_End
					 |Octal_Number_End);
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
  rule String:String = i:{0} start:_ (["] (([^\"\\] | [\\] [\\nt]) i:{i + 1})* end:_ ["] Spacing)+
                           { get_parsed_string_string( i, start, end)};

  rule String_Form:Form = s:String {String_Form( s)};

  rule Any:Form = (Id_Form
		  |Number_Form
		  |Symbol_Form
		  |String_Form );

};

// Hash table to call macro parsing functions.
//compile_time oldglobal parse_macro_hash:Hash( Symbol, (Form <- (Symbol))*);
compile_time global parse_macro_hash:Hash< Symbol, (Symbol -> Form)*>;

// This is the grammar for L code, i.e. what is inside a function.
grammar Code = {
  // import Lexical;
  rule Primary:Form =
  form:( id:Lexical.Id //Begin by an id
	   funptr:{parse_macro_hash[id]} 
	   ( &{funptr != cast( (Symbol -> Form)*, 0)} //semantic predicate
	       { funcall( *funptr, id) }         // macro handling
	     //	     | '(' form_list:@Separator<',', Expression> ')'//normal macro/function handling
	     | '(' form_list:Expression_List ')'//normal macro/function handling
	       { Compound_Form( id, form_list)}
	   | ':' exp:Maybe_Expression { Compound_Form( '@label',
						       list( Id_Form( id),
							     exp)) }
	   | {Id_Form( id)})
       | Lexical.String_Form
       | Lexical.Symbol_Form
       | Lexical.Number_Form
	 //       | @Replacement<exp:Expression>
       | @Replacement<Sequence>
       | '(' expl:Expression_List ')'
           { if(expl == cast( List< Form>, 0)
		or expl.tail != cast( List< Form>, 0))
	       Compound_Form( 'tuple', expl) // should be @tuple.
	       else expl.head }
       | '{' seq:Maybe_Empty_Sequence '}'
           { Compound_Form( '@block', list( seq)) }
	 );

  rule Postfix:Form = form:Primary ( '[' form2:Expression ']'
                                       form:{Compound_Form( '[]',
							    list( form, form2))}
                                     | '.' id:Lexical.Id
				       form:{Compound_Form( '[]',
						       list( form, Symbol_Form( id)))}
                                     | '(' form_list:Expression_List ')'
				       form:{Compound_Form( 'funcall',
							    cons( form, form_list))}
//				     | '++' form:{Compound_Form( '@post_++',
//								 list( form))}
//				     | '--' form:{Compound_Form( '@post_--',
//								 list( form))})?
				     )*

                      {form};
				       
  rule Unary_Operator:Form = @Unary_Prefix_Operator( ( '-' {'@unary_minus'}
                                                     | '&&' {'@get_label'}
                                                     | '&' {'@ref'}
	                                             | '*' {'@deref'}
						     | '--' {'@pre_--'}
                       			             | '++' {'@pre_++'}
 					             ), Postfix, Unary_Operator);
  
  rule Multiplicative:Form = @Left_Infix_Operator< '*', Unary_Operator, Multiplicative>;
  rule Additive:Form = @Left_Infix_Operator< ('+'|'-'), Multiplicative, Additive>;
  rule Shift:Form = @Left_Infix_Operator< ('>>'|'<<'), Additive, Shift>;
  rule Relational:Form = @Left_Infix_Operator< ('>='|'>'|'<='|'<'), Shift, Relational>;
  rule Equality:Form = @Left_Infix_Operator< ('=='|'!='), Relational, Equality>;
  rule Bitwise_And:Form = @Left_Infix_Operator< '|', Equality, Bitwise_And>;
  rule Bitwise_Xor:Form = @Left_Infix_Operator< '^', Bitwise_And, Bitwise_Xor>;
  rule Bitwise_Ior:Form = @Left_Infix_Operator< '|', Bitwise_Xor, Bitwise_Ior>;
  rule Logical_And:Form = @Left_Infix_Operator<('and' {'@and'}),Bitwise_Ior, Logical_And>;
  rule Logical_Or:Form = @Left_Infix_Operator< ('or' {'@or'}), Logical_And, Logical_Or>;
  rule Assignment:Form = @Right_Infix_Operator< '=', Logical_Or, Assignment>;

  rule Expression:Form = Assignment;

  rule Maybe_Expression:Form = (Expression
				|{Compound_Form( 'tuple', cast( List< Form>, 0))});
  
  // For now, we have two types of sequence: maybe_empty or non empty.
  // 
  // The non empty is here for parse reasons only: because () gives a
  // tuple containing one tuple, and in general the content of
  // parenthesis expect expressions.

  // Parse a list of expression separated by semicolons, i.e. of the form
  // exp1;exp2;....;exp3.
  // if an exp is empty (comprising the first or last), it is replaced by (), i.e. void.
  // Note: ';' can be viewed as a low priority seq operator, with priority lower than =.
  rule Maybe_Empty_Sequence:Form = tup:{Compound_Form( 'tuple', cast( List< Form>, 0))} //should be @tuple.
     ((exp:Expression (exp_list:( ';' exp2:(Expression|{tup}) {make( exp2)})+
		         {Compound_Form( '@seq', cons( exp, exp_list))}
		      |{exp}))
      |{tup});

  // Parse a list of expression separated by semicolons, i.e. of the form
  // exp1;exp2;....;exp3.
  // if an exp is empty (comprising the first or last), it is replaced by (), i.e. void.
  // Note: ';' can be viewed as a low priority seq operator, with priority lower than =.
  rule Non_Empty_Sequence:Form = 
      exp:Expression (exp_list:( ';' exp2:Expression {make( exp2)})+
                        {Compound_Form( '@seq', cons( exp, exp_list))}
		     |{exp});

  rule Sequence:Form = Non_Empty_Sequence;
                                    
  // An expression list, a comma-separated list of Sequences. Should be surrounded
  // by delimiters, like (). ',' can be viewed as an even lower priority operator than ','.
  rule Expression_List:List< Form> = @Separator< ',', Non_Empty_Sequence>;
  
  
  
};

grammar Type = {
  rule Base_Type:Form = id:Lexical.Id 
                        form:(// Structures.
			       &{id == 'struct'} '{'
			       form_list:(lab_type:Labeled_Type ';'
				          {make( lab_type)})* '}'
			        {Compound_Form( 'struct', form_list)}
			      // Misc. constructed types.
			     | '<' form_list2:@Separator(',', Type) ">"
			       {Compound_Form( id, form_list2)}
			      // Base types.
			     | {Id_Form( id)})
                        Lexical.Spacing {form};        

  rule Tuple_Type:Form = ( '(' form_list:@Separator<',', Type> ')'
                           {Compound_Form( 'tuple', form_list)} // should be @tuple.
                         | Base_Type);
  
  rule Indirection_Type:Form = form:Tuple_Type ('*' form:{Compound_Form( '*', list( form))})*
                               {form};
  
  rule Function_Type:Form = @Right_Infix_Operator( '->', Indirection_Type, Function_Type);
  rule Type:Form = Function_Type;

  // XXX: Probably should allow a spacing after the ":" here.
  rule Labeled_Type:Form = idf:Lexical.Id_Form ":" type:Type {Compound_Form( ':', list(idf , type))};
  
};

grammar Macro = {
//  //import Code
//  //import Lexical
//  rule let<symb:Symbol>:Form = id:Lexical.Id_Form typel:{cast( List< Form>, 0)}
//                               (":" type:Type.Type typel:{list( type)})?
//                               {Compound_Form( 'let', cons( id, typel))};

  rule let<symb:Symbol>:Form = id:Lexical.Id_Form 
                               typel:(":" type:Type.Type {list( type)}
			             | {cast( List< Form>, 0)})
                               {Compound_Form( 'let', cons( id, typel))};

  rule if<symb:Symbol>:Form = '(' cond:Code.Expression ')'
                              exp:Code.Expression
                              // No else is equivalent to "if (exp;()) else ()".
                              elsel:( 'else' exp2:Code.Expression {list( exp2)}
			            | {cast( List< Form>, 0)})
                              {Compound_Form( 'if', cons( cond, cons( exp, elsel)))};
  

  // This type of construct is common, and the parser should be shared between them.
  rule loop_like<symb:Symbol>:Form = exp:Code.Expression
                                {Compound_Form( symb, list( exp))};


  // This one is also common.
  rule while_like<symb:Symbol>:Form = '(' cond:Code.Expression ')' body:Code.Expression
                                      {Compound_Form( 'while',
						      list( cond, body))};

  
  // This one should be also shared.
  rule break<symb:Symbol>:Form = {Compound_Form( 'break', cast( List< Form>, 0))};

  // continue jumps to the continue set point, which can be set using the continue: special label.
  rule continue<symb:Symbol>:Form = (':' exp:Code.Maybe_Expression
                                       {Compound_Form( '@seq',
						       list( Compound_Form( '@set_continue',
									    cast( List< Form>, 0)),
							     exp))}
                                    | {Compound_Form( 'continue', cast( List< Form>, 0))});

  rule foreach<symb:Symbol>:Form = '(' var:Code.Expression 'in' collect:Code.Expression ')'
                                     body:Code.Expression
                                     {Compound_Form( 'foreach', list( var, collect, body))};


  rule cast<symb:Symbol>:Form = '(' type:Type.Type ',' exp:Code.Expression ')'
                                {Compound_Form( 'cast', list( type, exp))};
  
  //Is it useful?
//  rule print<symb:Symbol>:Form = '(' fl:@Maybe_Empty_Separator<',', (exp:Code.Expression
//								     (':' exp2:Code.Expression
//								      {Compound_Form( '@label',
//										      list( exp, exp2))}
//								      |{exp}))> ')'
//                                          {Compound_Form( 'print', fl)};
  rule Form<symb:Symbol>:Form = '(' exp:@Replacable<Code.Expression> ')'
                                  {Compound_Form( 'Form', list( exp))};

  rule XML<fsymb:Symbol>:Form = '(' form:XML_Parser.Content ')' {Compound_Form( 'XML',
										list( form))};
};


//compile_time oldglobal parse_top_level_hash:Hash( Symbol, (Form <- (Symbol))*);
compile_time global parse_top_level_hash:Hash< Symbol, (Symbol -> Form)*>;

// For global, top-level definitions.
grammar Top_Level = {

  // Observe how regular expressions determinist automatons can be emulated.
  // Note that with proper tail call optimisation (as performed by
  // gcc), this construct is efficient.
  //  rule Star_Comment_End:Int = ("*" ("/"
  //				   | . Star_Comment_End)
  //			      | . Star_Comment_End);
  
  // Without tail call optimisation or native support for regular expressions,
  // this accelerates things a lot in most cases.
  rule Star_Comment_End:Int = [^*]* ("*"+ ("/"
					   | Star_Comment_End)
				     |Star_Comment_End);
  
  rule Comment:Int = "/" ("/" [^\n]* "\n"
			  |"*" Star_Comment_End);
  //XXX: Maybe Spacing should have a +, and other parts could use Spacing? if they want.
  rule Spacing:Void = ([ \n\t]|Comment)* ;
  
  rule All:List< Form> = Spacing list:(form:Top Spacing {make( form)})*  {list};

  
  rule Top:Form = id:Lexical.Id {{let funptr = parse_top_level_hash[id];
			     if(funptr == cast( (Symbol -> Form)*, 0))
			       panic( "Parse error: unknown definer '", id, "'\n");
				  funcall( *funptr, id)}};

  // Common definers:
  
  rule function<fsymb:Symbol>:Form = name:Lexical.Id
                                        '(' params:@Separator<',', Type.Labeled_Type> ')'
                                        '->' ret_type:Type.Type '=' body:Code.Expression ';'
  { Compound_Form( 'define',
		   list( Id_Form( fsymb),
			 Id_Form( name),
			 Compound_Form( 'lambda',
					list( ret_type,
					      Compound_Form( 'tuple', //should be @tuple.
							     params),
					      body))))};
  rule global<fsymb:Symbol>:Form = name:Lexical.Id ":" type:Type.Type ';'//ltype:Type.Labeled_Type
                                   { Compound_Form( 'define',
						    list( Id_Form( fsymb),
							  Id_Form( name),
							  type))};

  //Works for both type and type alias.
  rule type<fsymb:Symbol>:Form = type_name:Lexical.Id_Form '=' type:Type.Type ';'
                                 {Compound_Form( 'define',
						 list( Id_Form( fsymb),
						       type_name,
						       type))};
  
  rule expander<fsymb:Symbol>:Form = name:Lexical.Id_Form '(' param:Lexical.Id_Form ')' '='
                                     body:Code.Expression ';'
                                     {Compound_Form( 'define',
						     list( Id_Form( fsymb),
							   name,
							   Compound_Form( ':',
									  list( param,
										body))))};

  rule macro<fsymb:Symbol>:Form = macro_name:Lexical.Id_Form '(' params:@Maybe_Empty_Separator<',', (name:Lexical.Id_Form
												     (":" type:Type.Type {Compound_Form( ':',
																	 list( name,
																	       type))}
												       | {name}))> ')' '='
                                  body:Code.Expression ';'
                                  {Compound_Form( 'define',
						  list( Id_Form( fsymb),
							macro_name,
							Compound_Form( 'tuple', params),
							body))};


  rule attribute_component:Form = ('left' '(' name:Lexical.Id_Form ")" ':' exp:Code.Expression
                                    {Compound_Form( 'label',
						    list( Compound_Form( 'left',
									 list( name)),
							  exp))}
                                   | Code.Expression);

  rule attributes_components:Form = ( '(' att1:attribute_component 
				      (',' att2:attribute_component ')'
				       {Compound_Form( 'tuple', list( att1, att2))}
				      | ')' {att1})
                                    | attribute_component);
  
  rule attribute<fsymb:Symbol>:Form = type:Type.Type objname:Lexical.Id "." fieldname:Lexical.Id '='
                                      expression:attributes_components ';'
  {Compound_Form( 'define',
		  list( Id_Form( fsymb),
			type,
			Id_Form( objname),
			Id_Form( fieldname),
			expression))};

  rule compile_time<fsymb:Symbol>:Form = any:Top {Compound_Form( 'define',
								 list( Id_Form( fsymb),
								       any))};

  rule include<fsymb:Symbol>:Form = filename:Lexical.String ';'
  {parse_include_filename( filename)};

  rule grammar_macro<fsymb:Symbol>:Form = parse_grammar.Grammar_Macro_End;
  rule grammar<fsymb:Symbol>:Form = parse_grammar.Grammar_End;
  
  
};

// Should not be here; will be moved elsewhere as soon as possible.
// Note: this is really a basic XML parser for demonstration.
// A real one can be constructed from this EBNF http://www.jelks.nu/XML/xmlebnf.html
grammar XML_Parser = {


  // We use $...$ for replacements. If one want to insert a $, one must
  // use $$, similarly to the XQuery language convention of doubling braces.
  
  //CharData a un Replacement
  rule CharData:Form = start:_ [^<]+ end:_ {String_Form( get_parsed_string_string( end - start, start - 1, end))};

  rule Content_List:List<Form> = ("<" ( "/" {cast( List< Form>, 0)}
                                      | form:( "$" exp:Code.Sequence "$" ">" {Compound_Form( '$', list( exp))}
                                             | Tagged_Compound)
					  cl:Content_List {cons( form, cl)})
                                 | cd:CharData cl:Content_List {cons( cd, cl)});
  
  rule Tagged_Compound:Form = id:Lexical.Id ">" cl:Content_List id2:Lexical.Id ">" {Compound_Form( id, cl)};

  rule Content:Form = "<" Tagged_Compound;
};

function test_xml() -> Void =
{
  //  set_parser_support_to( "<fact2>4<foo>toto</foo>$str</fact2>function add_three( i:Int) -> Int = i + 3 + 'toto\n' ;");
  set_parser_support_to( "1 + XML( <fact2>4<foo>to<$1 + thing$>to</foo>24<$str;tu$></fact2>) + 3");
  let exp = parse( Code.Expression);
  print_form( exp);

  set_parser_support_to( "<fact2>4<foo>toto</foo>24<$str$></fact2>function add_three( i:Int) -> Int = i + 3 + 'toto\n' ;");
  let xml = parse( XML_Parser.Content);
  print_form( xml);

  let form = parse( Top_Level.Top);
  print_form( form);
};
  

function test_top() -> Void = 
{
  set_parser_support_to( "function add_three( i:Int) -> Int = i + 3 + 'toto\n' ;");
  let form = parse( Top_Level.Top);
  print_form( form);

  set_parser_support_to( "global c_output_hash:Hash<Symbol, ((Expanded_Compound_Form)-> Void)*>;");
  form = parse( Top_Level.Top);
  print_form( form);

  //  /* troeuc * ta*/
  set_parser_support_to( "/* tasoeu *-*-/* aa */ global parse_macro_hash:Hash<Symbol, (Symbol -> Form)*>;");
  set_parser_support_to( "type Index = Int; type_alias Integer = Int;");
  set_parser_support_to( "compile_time type Index = Int; type_alias Integer = Int;");
  set_parser_support_to( "attribute Point p.name = (left( arg): name_table[p] = arg,"
			 "right: name_table[p]);");
  set_parser_support_to( "attribute Point3D p.x = p.p_.x;");
  set_parser_support_to( "attribute Duration d.second = right:cast( Int, d);");
//  set_parser_support_to( "macro assert( condition) = "
//			 "if( condition == cast( Bool, 0))     {"
//			 "print_form( Form( condition));"
//			 "};");
  set_parser_support_to( "attribute Duration d.second = right:cast( Int, d) * 3600;"
			 "attribute Duration d.minute = (right:cast( Int, cast( Int, d)*60));"
			 "attribute Duration d.hour = right:cast( Int, d);");
  
  let list_form = parse( Top_Level.All);

  foreach( let f in list_form)
  {
    print( "Form: ");
    print_form( f);
    print( "\n");
  };
  
};


function test_type() -> Void = 
{
  set_parser_support_to( "truc<toto**,List<Int,Float>*> -> (void*, Hash<struct { a:Int; b:List<Float>; }*, ()>)***");
  let form = parse( Type.Type);
  print_form( form);
};


function
init__parse_l() -> Void =
{
  //  parse_macro_hash = cast( Hash( Symbol, (Form <- (Symbol))*), make_hash_table());
  parse_macro_hash = cast( Hash< Symbol, (Symbol -> Form)*>, make_hash_table());
  parse_macro_hash['let'] = &get_parse_function( Macro.let);
  parse_macro_hash['cast'] = &get_parse_function( Macro.cast);
  parse_macro_hash['if'] = &get_parse_function( Macro.if);
  parse_macro_hash['loop'] = &get_parse_function( Macro.loop_like);
  parse_macro_hash['while'] = &get_parse_function( Macro.while_like);
  parse_macro_hash['buffered'] = &get_parse_function( Macro.loop_like);
  parse_macro_hash['unbuffered'] = &get_parse_function( Macro.loop_like);
  parse_macro_hash['foreach'] = &get_parse_function( Macro.foreach);
  parse_macro_hash['Form'] = &get_parse_function( Macro.Form);
  parse_macro_hash['XML'] = &get_parse_function( Macro.XML);
  parse_macro_hash['break'] = &get_parse_function( Macro.break);
  parse_macro_hash['continue'] = &get_parse_function( Macro.continue);
  //  parse_macro_hash['print'] = &get_parse_function( Macro.print);

  parse_top_level_hash = cast( Hash< Symbol, (Symbol -> Form)*>, make_hash_table());
  parse_top_level_hash['function'] = &get_parse_function( Top_Level.function);
  parse_top_level_hash['global'] = &get_parse_function( Top_Level.global);
  parse_top_level_hash['expander'] = &get_parse_function( Top_Level.expander);
  parse_top_level_hash['type'] = &get_parse_function( Top_Level.type);
  parse_top_level_hash['type_alias'] = &get_parse_function( Top_Level.type);
  parse_top_level_hash['macro'] = &get_parse_function( Top_Level.macro);
  parse_top_level_hash['include'] = &get_parse_function( Top_Level.include);
  parse_top_level_hash['grammar'] = &get_parse_function( Top_Level.grammar);
  parse_top_level_hash['grammar_macro'] = &get_parse_function( Top_Level.grammar_macro);
  parse_top_level_hash['attribute'] = &get_parse_function( Top_Level.attribute);
  parse_top_level_hash['compile_time'] = &get_parse_function( Top_Level.compile_time);
};

function test() -> Void =
{
  init__parse_l();
    
  test_top();
  exit( 3);

  test_xml();

  
  test_type();


  //  set_parser_support_to( "1 + &&a + &r + 011 >= 3 + 0 + 0xf0 + {} + () + {truc; toto( 22); truc( empty()); truc( 1,2)} + {troc;52;} + (22;23,33) + (34) + (35;36) + tata( 1;2,3)");
  //set_parser_support_to( "1 + {} + () + {truc; toto( 22); truc( empty()); truc( 1,2)} + {troc;52;} + (22;23,33) + (34) + (35;36;) + tata( 1;2,3)");
  //set_parser_support_to( "1 + {} + {truc; 25; 64}");
  //  set_parser_support_to( "{truc;}");
  //  set_parser_support_to( "{a}");
  //  set_parser_support_to( "1 + {} + () + {truc; toto( 22); truc( empty()); truc( 1,2)} + {troc;52;} + (22;23,33) + (34) + (35;36;) + toto()");
  //set_parser_support_to( "(35;36;)");
  set_parser_support_to( "$3$ + 1 + toto + 1 + Form( $ 3 $ + toto)");
  let block_form = parse( Code.Expression);
  print_form( block_form);

  exit( 3);
  
  set_parser_support_to( "id:Form = 3");

  // This is an artifice for C output, which does not handle the functions otherwise.
  let exp = parse( Macro.let, 'let');
   exp = parse( Macro.if, 'let');
   exp = parse( Macro.Form, 'let');
   exp = parse( Macro.XML, 'let');
   exp = parse( Macro.loop_like, 'let');
   exp = parse( Macro.while_like, 'let');
   exp = parse( Macro.cast, 'let');
   exp = parse( Macro.break, 'let');
   exp = parse( Macro.continue, 'let');
   exp = parse( Macro.foreach, 'let');
   exp = parse( Top_Level.function, 'let');
   exp = parse( Top_Level.global, 'let');
   exp = parse( Top_Level.expander, 'let');
   exp = parse( Top_Level.type, 'let');
   exp = parse( Top_Level.macro, 'macro');
   exp = parse( Top_Level.include, 'macro');
   exp = parse( Top_Level.grammar, 'macro');
   exp = parse( Top_Level.grammar_macro, 'macro');
   exp = parse( Top_Level.attribute, 'let');
   exp = parse( Top_Level.compile_time, 'let');
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
};
