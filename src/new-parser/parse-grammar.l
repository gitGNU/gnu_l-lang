
global glob_i:Int;

include "new-parser/character-set.l";

compile_time type Exit = struct { dummy:Int;}*;

// XXX: c'est un Int pour satisfaire Digit_or_Alpha, mais en fait ca devrait etre
// n'importe quoi (type Exit)
compile_time Exit
parse_error()
{
  print( "Parse error\n");
  exit( 3);
  cast( Exit, 3);
}

compile_time type_alias Character = Int;

grammar parse_grammar = {
  rule Comment:Int = "//" [^\n]* "\n" ;
  rule Spacing:Void = ([ \n\t]|Comment)* ;
  rule Alpha:Character = [a-zA-Z_] ;
  rule Alpha_Num:Character = [a-zA-Z_0-9] ;
  
  
  rule Identifier:Symbol = <start:_> Alpha Alpha_Num* <end:_>
  { intern_string( substring( start, end))} ;

  rule Escaped_Character:Character = [\\] ( "n" {10}
                                          | "t"  {9}
		                          | [^tn] ) ;
  
  rule Maybe_Escaped_Character:Character = Escaped_Character | [^\\] ;
  rule Maybe_Escaped_Character_Character_Range:Character = Escaped_Character|[^\]\\];

  rule String:Form = ["] <start:_> ( Escaped_Character | [^\"\\])* <end:_> ["]
                       {String_Form( substring( start, end))} ;
  
  rule Character_Range:Form =
                         <max:<min:Maybe_Escaped_Character_Character_Range>>
                         ("-" <max:Maybe_Escaped_Character>)?
                         { if(min == max) Int_Form( min) 
			     else Compound_Form('-', list( Int_Form( min),
							   Int_Form( max))) } ;

  rule Character_Set:Form = 
                       <char_selector:{'[]'}>
                       "[" ("^" <char_selector:{'[^]'}>)?
                       <cr_list:( <cr:Character_Range> { make( cr) })*> "]"
                       { Compound_Form( char_selector, cr_list) } ;

  rule Callable_Rule:Form = <id:Identifier> <form:{Id_Form( id)}>
                            ("." <id:Identifier> <form:{Compound_Form( '.',
								       list( form,
									     Id_Form(id)))}>)?
                            {form};

  rule Semantic_Action:Form = "{" <exp:Expression> "}"
                              {Compound_Form( '{}', list( exp))};
  
  rule Grouping:Form = "<" <id:Identifier> ":" <form:Rule> ">"
                       { Compound_Form( '<>', list( Id_Form( id), form)) };

  rule Primary:Form = (String
		       | Character_Set 
		       | Callable_Rule
		       | Grouping
		       | Semantic_Action
		       | "(" <r:Rule> ")" {r});

  rule Postfix:Form = <form:Primary> ( <start:_> ("?" | "*" | "+") <end:_>
				       <form:{ Compound_Form( intern_string( substring( start,end)),
							      list( form)) }>)?
                      { form };
  
  rule Sequence:Form = Spacing <post_list:(<post:Postfix>  Spacing {make( post)})*>
                       { if( post_list.tail == cast( List( Form), 0)) post_list.head
			   else Compound_Form( ' ', post_list) };

  rule Alternative:Form = <prim:Sequence>
                          ("|" Spacing <sec:Sequence>
			   <prim:{ Compound_Form( '|', list( prim, sec)) }>)*
                          { prim };

  rule Rule:Form = Alternative;

  rule Grammar_Rule:Form = "rule" Spacing <id:Identifier> ":" <ret_type:Type>
                           Spacing "=" Spacing <r:Rule> Spacing ";" Spacing
                           { Compound_Form( 'rule', list( Id_Form( id),
							  ret_type,
							  r)) };

  rule Grammar:Form = "grammar" Spacing <id:Identifier> Spacing "=" Spacing
  "{" Spacing <gr_list:(<gr:Grammar_Rule> {make( gr)})*> "}" Spacing ";"
  {  Compound_Form( 'define',
		    cons( Id_Form( 'grammar'),
			  cons( Id_Form( id),
				gr_list))) } ;

  //  rule Test:Form = "rule" Spacing <num:0> {Form($num$)};//("toto" { num = num + 1})* {Form( num)};

};

Void
test ()
{

  set_parser_support_to( "rule Spacing:Character = [ \n\t]* ;");
  //  set_parser_support_to( "rule toto:Int = [a-zA-Z_]*|toto tata|{print( 'hello')}|<hello:toto|[a-z] truc>;  ");
  //  set_parser_support_to( "rule toto:Int = [a-zA-Z_]*;");
  //  let form = parse_Grammar_Rule( );
  //   set_parser_support_to( "[a-zA-Z_]*");//let form = parse_Rule();
  //  let form = parse_Character_Set();

  //  set_parser_support_to( "rule*  [a]    totototo|truc");
  //  let form = parse_Test();
  //  let form = parse_Postfix();
  //  let form = parse_Alternative();
  //  set_parser_support_to( "[a]");
  //set_parser_support_to( "a-e");
  //let form = parse_Character_Range();
    //  let form =parse_Character_Set();

  let s = get_test_string();
  //  print( s);

  let form = parse (parse_grammar.Grammar_Rule);// _Grammar_Rule();
  set_parser_support_to( s);
  //set_parser_support_to( "grammar parse_grammar = {   rule Spacing:Character = [ \n\t]* ; };");

  set_parser_support_to( "grammar parse_grammar = { rule truc:Int = toto.tata; };");
  form = parse (parse_grammar.Grammar);
  print_form( form);
 ();

}
