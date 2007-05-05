// Temporary file for bootstrapping.

include "new-parser/grammar-expander.l";

expander init_grammar_hash( form)
{
  dot_character_set = cast( Character_Set, list( Character_Range( min:1, max:255)));
  rules_hash = cast( Hash( Symbol, Form), make_hash_table());
  head_set_hash = Hash( Symbol, Character_Set);
  
  //grammar_rule Digit = <d:[0-9]> { d - Character( '0')} ;
  rules_hash['Digit'] = Compound_Form( ' ',
				       list( Compound_Form( '<>',
							    list( Id_Form( 'd'),
								  Compound_Form( '[]', list( Form( $Int_Form(Character( '0'))$-$Int_Form(Character( '9'))$))))),
					     Compound_Form( '{}',
							    list( Form( d - Character( '0'))))));

  //grammar_rule Hexa_Digit = (<d:[0-9]> { d - Character( '0')}
  //                          /<d:[a-f]> { d - Character( 'a') + 10}) ;
  rules_hash['Hexa_Digit'] = Compound_Form( '|',
					    list( Compound_Form( ' ',
								 list( Compound_Form( '<>',
										      list( Id_Form( 'd'),
											    Compound_Form( '[]',
													   list( Form( $Int_Form(Character( '0'))$-$Int_Form(Character( '9'))$))))),
								       Compound_Form( '{}',
										      list( Form( d - Character( '0')))))),
						  Compound_Form( ' ',
								 list( Compound_Form( '<>',
										      list( Id_Form( 'd'),
											    Compound_Form( '[]',
													   list( Form( $Int_Form(Character( 'a'))$-$Int_Form(Character( 'f'))$))))),
								       Compound_Form( '{}',
										      list( Form( d - Character( 'a') + 10)))))));
						  
  //grammar_rule Unsigned_Number = <n:{0}> (<d:Digit> {n*=10; n+=d})* {n} ;
  rules_hash['Unsigned_Number'] = Compound_Form( ' ',
						 list( Compound_Form( '<>',
								      list( Id_Form( 'n'),
									    Compound_Form( '{}',
											   list( Form( 0))))),
						       Compound_Form( '*',
								      list( Compound_Form( ' ',
											   list( Compound_Form( '<>',
														list( Id_Form( 'd'),
														      Id_Form( 'Digit'))),
												 Compound_Form( '{}',
														list( Form( seq( n = n*10, n = n+d)))))))),
						       Compound_Form( '{}',
								      list( Form( n)))));

  
  //grammar_rule Digit_Or_Alpha =  (Digit / [a-z]) ;
  rules_hash['Digit_or_Alpha'] = Compound_Form( '|',
						list( Id_Form( 'Digit'),
						      Compound_Form( '[]',
								     list( Form( $Int_Form(Character( 'a'))$-$Int_Form(Character( 'z'))$)))));



////////////////////////////////////////////////////////////////

  //grammar_rule Comment = "//" [^\n]* \n
  rules_hash['Comment'] = Compound_Form( ' ',
					 list( String_Form( "//"),
					       Compound_Form( '*',
							      list( Compound_Form( '[^]',
										   list( Int_Form( 10))))),
					       Compound_Form( '[]',
							      list( Int_Form( 10)))));
					       
  
  //grammar_rule Spacing = ([ \n\t]|Comment)* ;
  rules_hash['Spacing'] = Compound_Form( '*',
					 list( Compound_Form( '|',
							      list( Compound_Form( '[]',
										   list( Int_Form(Character( ' ')),
											 Int_Form(10),
											 Int_Form(9))),
								    Id_Form( 'Comment')))));
  //grammar_rule Alpha = [a-zA-Z_] ;
  rules_hash['Alpha'] = Compound_Form( '[]',
				       list( Form( $Int_Form(Character(  'a'))$-$Int_Form(Character(  'z'))$),
					     Form( $Int_Form(Character(  'A'))$-$Int_Form(Character(  'Z'))$),
					     Form( $Int_Form(Character(  '_'))$)));

  //grammar_rule Alpha_Num = [a-zA-Z_0-9] ;
  rules_hash['Alpha_Num'] = Compound_Form( '[]',
					   list( Form( $Int_Form(Character(  'a'))$-$Int_Form(Character(  'z'))$),
						 Form( $Int_Form(Character(  'A'))$-$Int_Form(Character(  'Z'))$),
						 Form( $Int_Form(Character(  '_'))$),
						 Form( $Int_Form(Character(  '0'))$-$Int_Form(Character(  '9'))$)));

  //grammar_rule Escaped_Character = "\" ("n" { 10 } | "\" { 92 } | ['] {39} | ["] {34} | [t] {9})
  //grammar_rule Escaped_Character = "\" ([n] { 10 } | [t] {9} | [^nt])
  rules_hash['Escaped_Character'] = Compound_Form( ' ',
						   list( Compound_Form( '[]',
									list( Int_Form( 92))),
							 Compound_Form( '|',
									list( Compound_Form( ' ',
											     list( String_Form( "n"),
												   Compound_Form( '{}',
														  list( Int_Form( 10))))),
									      Compound_Form( ' ',
											     list( String_Form( "t"),
												   Compound_Form( '{}',
														  list( Int_Form( 9))))),
									      Compound_Form( '[^]',
											     list( Int_Form( Character( 'n')),
												   Int_Form( Character( 't'))))))));
  //grammar_rule Maybe_Escaped_Character = Escaped_Character|[^\];
  rules_hash['Maybe_Escaped_Character'] = Compound_Form( '|',
							 list( Id_Form( 'Escaped_Character'),
							       Compound_Form( '[^]',
									      list( Int_Form( 92)))));

  //grammar_rule Maybe_Escaped_Character_Character_Range = Escaped_Character|[^]\];
  rules_hash['Maybe_Escaped_Character_Character_Range'] = Compound_Form( '|',
									 list( Id_Form( 'Escaped_Character'),
									       Compound_Form( '[^]',
											      list( Int_Form( 92),
												    Int_Form( Character( ']'))))));
  
  
  //grammar_rule Identifier = <start:_> Alpha Alpha_Num* <end:_>
  //                         { intern( substring( start, end))} ;
  rules_hash['Identifier'] = Compound_Form( ' ',
					    list(
						 Compound_Form( '<>',
								list( Form( start),
								      Id_Form( '_'))),
						 Form( Alpha),
						 Compound_Form( '*',
								list( Form( Alpha_Num))),
						 Compound_Form( '<>',
								list( Form( end),
								      Id_Form( '_'))),
						 Compound_Form( '{}',
								list( Form( intern_string( substring( start, end)))))));

  //grammar_rule Character_Range = <max:<min:Maybe_Escaped_Character_Character_Range>> ("-" <max:Maybe_Escaped_Character>)? { Character_Range( min:min, max:max) }
  rules_hash['Character_Range'] = Compound_Form( ' ',
						 list( Compound_Form( '<>',
								      list( Id_Form( 'min'),
									    Compound_Form( '<>',
											   list( Id_Form( 'max'),
												 Id_Form( 'Maybe_Escaped_Character_Character_Range'))))),
						       //												 Compound_Form( '[^]',
						       //														list( Form( $Int_Form(Character(  ']'))$))))))),
						       Compound_Form( '?',
								      list( Compound_Form( ' ',
											   list( Form( "-"),
												 Compound_Form( '<>',
														list( Id_Form( 'max'),
														      Id_Form( 'Maybe_Escaped_Character'))))))),
						       Compound_Form( '{}',
								      // list( Form( Character_Range( min:min, max:max))))));
								      list( Form( if(min == max) Int_Form( min) else Compound_Form('-', list( Int_Form( min),
																	      Int_Form( max))))))));

  //   As we have a +, ] can be used as a Character Range when placed at
  //   the beginning.
  // grammar_rule Character_Set = <char_selector:{'[]'}> "[" ("^" <char_selector:{'[^]'}>)? <cr_list:( <cr:Character_Range> {make( cr)})*> "]" { Compound_Form( char_selector, cr_list)}
  rules_hash['Character_Set'] = Compound_Form( ' ',
					       list( Compound_Form( '<>',
								    list( Id_Form( 'char_selector'),
									  Compound_Form( '{}',
											 list( Form( '[]'))))),
						     String_Form( "["),
						     Compound_Form( '?',
								    list( Compound_Form( ' ',
											 list( String_Form( "^"),
											       Compound_Form( '<>',
													      list( Id_Form( 'char_selector'),
														    Compound_Form( '{}',
																   list( Form( '[^]'))))))))),
						     Compound_Form( '<>',
								    list( Id_Form( 'cr_list'),
									  Compound_Form( '*',
											 list( Compound_Form( ' ',
													     list( Compound_Form( '<>',
																  list( Id_Form( 'cr'),
																	Id_Form( 'Character_Range'))),
														   Compound_Form( '{}',
																  list( Form( make( cr)))))))))),
						    String_Form( "]"),
						    Compound_Form( '{}',
								   list( Form( Compound_Form( char_selector, cr_list))))));
  
  //  grammar_rule String = ["] <start:_> ( Escaped_Character | [^"\\])* <end:_> ["]
  //                {String_Form( substring( start, end))} ;
  rules_hash['String'] = Compound_Form( ' ',
					list( Compound_Form( '[]',
							     list( Int_Form( Character( '"')),
								   Int_Form( 39))), //'\''
					      Compound_Form( '<>',
							     list( Form( start),
								   Id_Form( '_'))),
					      Compound_Form( '*',
							     list( Compound_Form( '|',
										  list( Id_Form( 'Escaped_Character'),
											Compound_Form( '[^]',
												       list( Int_Form( Character( '"')),
													     Int_Form( Character( '\\')))))))),
					      Compound_Form( '<>',
							     list( Form( end),
								   Id_Form( '_'))),
					      Compound_Form( '[]',
							     list( Int_Form( Character( '"')),
								   Int_Form( 39))),
					      Compound_Form( '{}',
							     list( Form( String_Form( substring( start, end)))))));

  //grammar_rule Callable_Rule = <id:Identifier> {Id_Form( id)}
  rules_hash['Callable_Rule'] = Compound_Form( ' ',
					       list( Compound_Form( '<>',
								    list( Id_Form( 'id'),
									  Id_Form( 'Identifier'))),
						     Compound_Form( '{}',
								    list( Form( Id_Form( id))))));

  //grammar_rule Semantic_Action = "{" <exp:Expression> "}" {Compound_Form( '{}', list( exp))}
  rules_hash['Semantic_Action'] = Compound_Form( ' ',
						 list( String_Form( "{"),
						       Compound_Form( '<>',
								      list( Id_Form( 'exp'),
									    Id_Form( 'Expression'))),
						       String_Form( "}"),
						       Compound_Form( '{}',
								      list( Form( Compound_Form( '{}',
												 list( exp)))))));

  //grammar_rule Grouping = "<" <id:Identifier> ":" <form:Rule> ">" {Compound_Form( '<>', list( Id_Form( id), form))}
  rules_hash['Grouping'] = Compound_Form( ' ',
					  list( String_Form( "<"),
						Compound_Form( '<>',
							       list( Id_Form( 'id'),
								     Id_Form( 'Identifier'))),
						String_Form( ":"),
						Compound_Form( '<>',
							       list( Id_Form( 'form'),
								     Id_Form( 'Rule'))),
						String_Form( ">"),
						Compound_Form( '{}',
							       list( Form( Compound_Form( '<>',
											  list( Id_Form( id),
												form)))))));
  
  //grammar_rule Primary = (String | Character_Set |
  // Callable_Rule | Grouping | Semantic | "(" <r:Rule> ")" {r}
  rules_hash['Primary'] = Compound_Form( '|',
					 list( Id_Form( 'Character_Set'),
					       Id_Form( 'String'),
					       Id_Form( 'Callable_Rule'),
					       Id_Form( 'Semantic_Action'),
					       Id_Form( 'Grouping'),
					       Compound_Form( ' ',
							      list( String_Form( "("),
								    Compound_Form( '<>',
										   list( Id_Form( 'r'),
											 Id_Form( 'Rule'))),
								    String_Form( ")"),
								    Compound_Form( '{}',
										   list( Form( r)))))));

  //grammar_rule Postfix = <form:Primary> ( <start:_> ("?" | "*" | "+") <end:_>
  //                                        <form:{Compound_Form( intern( substring( start,end)),
  //                                                              list( form))}>)?
  //                                        { form}
  rules_hash['Postfix'] = Compound_Form( ' ',
					 list( Compound_Form( '<>',
							      list( Id_Form( 'form'),
								    Id_Form( 'Primary'))),
					       Compound_Form( '?',
							      list( Compound_Form( ' ',
										   list( Compound_Form( '<>',
													list( Id_Form( 'start'),
													      Id_Form( '_'))),
											 Compound_Form( '|',
													list( String_Form( "?"),
													      String_Form( "*"),
													      String_Form( "+"))),
											 Compound_Form( '<>',
													list( Id_Form( 'end'),
													      Id_Form( '_'))),
											 Compound_Form( '<>',
													list( Id_Form( 'form'),
													      Compound_Form( '{}',
															     list( Form( Compound_Form( intern_string( substring( start, end)),
																			list( form))))))))))),
					       Compound_Form( '{}',
							      list( Form( form)))));

  // Empty rule( epsilon) will be (' ')
  // grammar_rule Sequence = Spacing <post_list:(<post:Postfix>  Spacing {post})*> {Compound_Form( ' ', post_list)}
  rules_hash['Sequence'] = Compound_Form( ' ',
					  list( Id_Form( 'Spacing'),
						Compound_Form( '<>',
							       list( Id_Form( 'post_list'),
								     Compound_Form( '*',
										    list( Compound_Form( ' ',
													 list( Compound_Form( '<>',
															      list( Id_Form( 'post'),
																	     Id_Form( 'Postfix'))),
													       Id_Form( 'Spacing'),
													       Compound_Form( '{}',
															      list( Form( make( post)))))))))),
						Compound_Form( '{}',
							       list( Form( Compound_Form( ' ',
											  post_list))))));

  
  //grammar_rule Alternative = Sequence ("|" Sequence)*
  //grammar_rule Alternative = <prim:Sequence> ("|" Spacing <sec:Sequence> <prim:{Compound_Form( '|', list( prim, sec))}>)* {prim}
  rules_hash['Alternative'] = Compound_Form( ' ',
					     list( Compound_Form( '<>',
								  list( Id_Form( 'prim'),
									Id_Form( 'Sequence'))),
						   Compound_Form( '*',
								  list( Compound_Form( ' ',
										       list( String_Form( "|"),
											     Id_Form( 'Spacing'),
											     Compound_Form( '<>',
													    list( Id_Form( 'sec'),
														  Id_Form( 'Sequence'))),
											     Compound_Form( '<>',
													    list( Id_Form( 'prim'),
														  Compound_Form( '{}',
																 list( Form( Compound_Form( '|',
																			    list( prim, sec))))))))))),
						   Compound_Form( '{}',
								  list( Form( prim)))));

  //grammar_rule Rule = Alternative
  rules_hash['Rule'] = Id_Form( 'Alternative');

  //grammar_rule Grammar_Rule = "rule" Spacing <id:Identifier> Spacing "=" Spacing <r:Rule> Spacing ";" Spacing
  rules_hash['Grammar_Rule'] = Compound_Form( ' ',
					      list( String_Form( "rule"),
						    Id_Form( 'Spacing'),
						    Compound_Form( '<>',
								   list( Id_Form( 'id'),
									 Id_Form( 'Identifier'))),
						    Id_Form( 'Spacing'),
						    String_Form( "="),
						    Id_Form( 'Spacing'),
						    Compound_Form( '<>',
								   list( Id_Form( 'r'),
									 Id_Form( 'Rule'))),
						    Id_Form( 'Spacing'),
						    String_Form( ";"),
						    Id_Form( 'Spacing'),
						    Compound_Form( '{}',
								   list( Form( Compound_Form( 'rule',
											      list( Id_Form( id),
												    r)))))));

  //grammar_rule Grammar = "grammar" Spacing <id:Identifier> Spacing "=" Spacing "{" <gr_list:(<gr:Grammar_Rule> {make( gr)})*> "}" Spacing ";"
  // { Compound_Form( 'define', cons( Id_Form( 'grammar') cons( Id_Form( id), gr_list)))}
  
  rules_hash['Grammar'] = Compound_Form( ' ',
					 list( //String_Form( "grammar"),
					       Id_Form( 'Spacing'),
					       Compound_Form( '<>',
							      list( Id_Form( 'id'),
								    Id_Form( 'Identifier'))),
					       Id_Form( 'Spacing'),
					       String_Form( "="),
					       Id_Form( 'Spacing'),
					       String_Form( "{"),
					       Id_Form( 'Spacing'),
					       Compound_Form( '<>',
							      list( Id_Form( 'gr_list'),
								    Compound_Form( '*',
										   list( Compound_Form( ' ',
													list( Compound_Form( '<>',
															     list( Id_Form( 'gr'),
																   Id_Form( 'Grammar_Rule'))),
													      Compound_Form( '{}',
															     list( Form( make( gr)))))))))),
					       String_Form( "}"),
					       Id_Form( 'Spacing'),
					       String_Form( ";"),
					       Id_Form( 'Spacing'),
					       Compound_Form( '{}',
							      list( Form( Compound_Form( 'define', cons( Id_Form( 'grammar'),
													 cons( Id_Form( id),
													       gr_list))))))));
  
  Form( 0);
}

Void
call_init_grammar_hash()
{
  init_grammar_hash();
  ()
}

////////////////////////////////


Int
parse_Digit ()
{
  grammar_expander('Digit');
  //  let d = read_char();
  //XXX: insert a check here, that char is between '0' and '9'.
  //  d - Character( '0');
}


Int
parse_Hexa_Digit()
{
  grammar_expander( 'Hexa_Digit');
}

Int
parse_Unsigned_Number()
{
  grammar_expander( 'Unsigned_Number');
}


Int
parse_Digit_or_Alpha()
{
  grammar_expander( 'Digit_or_Alpha');
  // let c_ = peek_char();
}

Int
parse_Alpha()
{
  grammar_expander( 'Alpha');
}

Int
parse_Alpha_Num()
{
  grammar_expander( 'Alpha_Num');
}

Int
parse_Comment()
{
  grammar_expander( 'Comment');
}


Void
parse_Spacing()
{
  grammar_expander( 'Spacing');
}


Symbol
parse_Identifier()
{
  grammar_expander( 'Identifier');
  // let c_ = peek_char();
}

Int
parse_Escaped_Character()
{
  grammar_expander( 'Escaped_Character');
}

Int
parse_Maybe_Escaped_Character()
{
  grammar_expander( 'Maybe_Escaped_Character');
}

Int
parse_Maybe_Escaped_Character_Character_Range()
{
  grammar_expander( 'Maybe_Escaped_Character_Character_Range');
}


//Character_Range
Form
parse_Character_Range()
{
  grammar_expander( 'Character_Range');
  // let c_ = peek_char();
}

Form
parse_Character_Set()
{
  grammar_expander( 'Character_Set');
  // let c_ = peek_char();
}

Form
parse_String()
{
  grammar_expander( 'String');
}

Form
parse_Semantic_Action()
{
  grammar_expander( 'Semantic_Action');
}

Form
parse_Callable_Rule()
{
  grammar_expander( 'Callable_Rule');
}

Form
parse_Rule()
{
  panic( "Should not be called\n");
  //Fake, must be defined because we don't handle double recursivity
  cast( Form, 0);
}

Form
parse_Grouping()
{
  grammar_expander( 'Grouping');
}


Form
parse_Primary()
{
  grammar_expander( 'Primary');
}

Form
parse_Postfix()
{
  grammar_expander( 'Postfix');
}

Form
parse_Sequence()
{
  grammar_expander( 'Sequence');
}


Form
parse_Alternative()
{
  grammar_expander( 'Alternative');
}

Form
parse_Rule()
{
  grammar_expander( 'Rule');
}

Form
parse_Grammar_Rule()
{
  grammar_expander( 'Grammar_Rule');
}

Form
parse_Grammar()
{
  grammar_expander( 'Grammar');
}


Void
test()
{
  call_init_grammar_hash();
  set_parser_support_to( "2ab43");
  let d = parse_Digit();
  let d2 = parse_Digit_or_Alpha();
  let d3 = parse_Hexa_Digit();
  let d4 = parse_Unsigned_Number();
  
  print( "Parse: ", d, "\n");
  print( "Parse: ", d2, "\n");
  print( "Parse: ", d3, "\n");
  print( "Parse: ", d4, "\n");

  set_parser_support_to( "toto23,24");
  let d5 = parse_Identifier();

  print( "Identifier :", d5, "|");
  
  //  set_parser_support_to( "_a-z");
  set_parser_support_to( "a-z_");

  let cr1 = parse_Character_Range();
  let cr2 = parse_Character_Range();
  
  //  print( "cr1 ", cr1.min, " ", cr1.max, " cr2 ", cr2.min, " ", cr2.max, "\n");

 set_parser_support_to( "[a-z_\\n]");
 set_parser_support_to( "[^\\]\\-a-z_\\n]");

 let cs_form = parse_Character_Set();

 print( "CSFORM\n");
 print_form( cs_form);

 let cs = make_Character_Set( cs_form);
 print_Character_Set( cs);

 // set_parser_support_to( "{print( 'hello')}");
 // set_parser_support_to( "[a-zA-Z_]*|toto tata|{print( 'hello')}|<hello:toto|[a-z] truc>");


 // let form = parse_Alternative();
  //let form = parse_Character_Set();

 // set_parser_support_to( "<a:toto>");
 // let form = parse_Grouping();

// set_parser_support_to( "<form:Primary> ( <start:_> ([?] | [*] | [+]) <end:_> <form:{Compound_Form( intern( substring( start,end)), list( form))}>)? { form}");
//
// let form = parse_Rule();

 set_parser_support_to( "rule toto = [a-zA-Z_]*|toto tata|{print( 'hello')}|<hello:toto|[a-z] truc>;  ");

 set_parser_support_to( "<toto:{'[]'}> //toto");

 
 //let form = parse_Rule();
 // let form = parse_Grammar_Rule();
// print_form( form);
 ();
}
