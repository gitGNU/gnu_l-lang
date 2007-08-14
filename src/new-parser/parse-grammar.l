
global glob_i:Int;

include "new-parser/character-set.l";
include "new-parser/grammar-macros.l";

compile_time type Exit = struct { dummy:Int;}*;

// XXX: c'est un Int pour satisfaire Digit_or_Alpha, mais en fait ca devrait etre
// n'importe quoi (type Exit)
compile_time function
parse_error() -> Exit = 
{
  print( "Parse error\n");
  exit( 3);
  cast( Exit, 3)
};

compile_time type_alias Character = Int;

grammar parse_grammar = {
  rule Comment:Int = "//" [^\n]* "\n" ;
  rule Spacing:Void = ([ \n\t]|Comment)* ;
  rule Alpha:Character = [a-zA-Z_] ;
  rule Alpha_Num:Character = [a-zA-Z_0-9] ;
  
  
  rule Identifier:Symbol = start:_ Alpha Alpha_Num* end:_
  { intern_string( substring( start, end))} ;

  rule Escaped_Character:Character = [\\] ( "n" {10}
                                          | "t"  {9}
		                          | [^tn] ) ;
  
  rule Maybe_Escaped_Character:Character = Escaped_Character | [^\\] ;
  rule Maybe_Escaped_Character_Character_Range:Character = Escaped_Character|[^\]\\];

  rule String:Form = ["] start:_ ( Escaped_Character | [^\"\\])* end:_ ["]
                       {String_Form( substring( start, end))} ;
  rule Symbol:Form = ['] start:_ ( Escaped_Character | [^\'\\])* end:_ [']
                       {Symbol_Form( intern_string( substring( start, end)))} ;
  
  rule Character_Range:Form = min:Maybe_Escaped_Character_Character_Range
                         ("-" max:Maybe_Escaped_Character
                              {Compound_Form('-', list( Int_Form( min),
							Int_Form( max)))}
			  | {Int_Form( min)});
  

  rule Character_Set:Form =
                       "[" char_selector:( "^" {'[^]'}
		                         | {'[]'})
                       cr_list:( cr:Character_Range { make( cr) })* "]"
                       { Compound_Form( char_selector, cr_list) } ;

  rule Callable_Rule_or_Binding:Form = id:Identifier form:{Id_Form( id)}
    ("." id2:Identifier {Compound_Form( '.',
					list( form,
					      Id_Form(id2)))}
    | ":" form2:Postfix {Compound_Form( ':',
					list( form,
					      form2))}
    | {form});
  
  rule Semantic_Action:Form = "{" Spacing exp:Code.Sequence "}"
                              {Compound_Form( '{}', list( exp))};


  rule Semantic_Predicate:Form = "&" form:Primary //Sequence //Semantic_Action
                                 {Compound_Form( '&', list( form))};
  // cast( Compound_Form, form).form_list)};
  
  rule Rule_Macro:Form = "@" id:Identifier
                         "<" Spacing form_list:@Separator<("," Spacing), Rule> ">"
                         {Compound_Form( '@',
					 list( Compound_Form( id, form_list)))};

  
  // This is used in rule_macros.
  rule Replacement:Form = "$" exp:Code.Sequence "$" {Compound_Form( '$', list( exp))};

  rule Primary:Form = (String
		       | Symbol
		       | Character_Set 
		       | Callable_Rule_or_Binding
		       | Semantic_Action
		       | Semantic_Predicate
		       | Rule_Macro
		       | Replacement
		       | "(" Spacing r:Rule ")" {r});

  rule Postfix:Form = form:Primary ( op:('?' | '*' | '+')
				     { Compound_Form( op,
						      list( form)) }
				   | {form} );

  // Due to technical restrictions in head set calculation,
  // for now we use + instead of * for a sequence.
  rule Sequence:Form = post_list:(post:Postfix  Spacing {make( post)})+
                       { if( post_list.tail == cast( List< Form>, 0)) post_list.head
			   else Compound_Form( ' ', post_list) };

  rule Alternative:Form = @Right_Infix_Operator<("|" Spacing {'|'}), Sequence, Alternative>;
  

  rule Rule:Form = Alternative;

  rule Grammar_Rule:Form = "rule" Spacing
                                  id:Identifier form_list:{cast( List< Form>, 0)}
                                  ("<" form_list:@Separator( ',', (param:Identifier ":" type:Type.Type
							     {Compound_Form( 'label',
									     list( Id_Form( param),
										   type))}))
				   ">")?
                               ":" ret_type:Type.Type
                               Spacing "=" Spacing r:Rule Spacing ";" Spacing
                               { Compound_Form( 'rule', list( Id_Form( id),
							      ret_type,
							      Compound_Form( 'tuple',
									     form_list),
							      r)) };

  rule Grammar:Form = "grammar" Spacing Grammar_End;

  rule Grammar_End:Form = id:Identifier Spacing "=" Spacing
  "{" Spacing gr_list:(gr:Grammar_Rule {make( gr)})* "}" Spacing ";"
  {  Compound_Form( 'define',
		    cons( Id_Form( 'grammar'),
			  cons( Id_Form( id),
				gr_list))) } ;


  // Grammar macro; should use the @Separator grammar_macro.
  rule Grammar_Macro:Form = "grammar_macro" Spacing Grammar_Macro_End;

  rule Grammar_Macro_End:Form = "@" id:Identifier
     "<" Spacing form_list:( ">" {cast( List< Form>, 0)}
                            | arg1:Identifier Spacing
     		              rest_list:(','  arg:Identifier {make( Id_Form( arg))})*
           		      ">" { cons( Id_Form( arg1), rest_list)} )
     Spacing '=' rule:Rule ';'
     {Compound_Form( 'define',
		     list( Id_Form( 'grammar_macro'),
			   Id_Form( id),
			   Compound_Form( 'tuple',
					  form_list),
			   rule))} ;

  //  rule Test:Form = "rule" Spacing num:0 {Form($num$)};//("toto" { num = num + 1})* {Form( num)};

};


function
test () -> Void =
{

  set_parser_support_to( "rule Spacing<i:Int,j:Symbol>:Character = [ \n\t]* [^a-b]  ;");
  //set_parser_support_to( "rule Spacing:Character = [ \n\t]* ;");
  let form3 = parse( parse_grammar.Grammar_Rule);
  print_form( form3);
  //  exit( 3);
  //  set_parser_support_to( "rule toto:Int = [a-zA-Z_]*|toto tata|{print( 'hello')}|hello:toto|[a-z] truc;  ");
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

  //  let s = get_test_string();
  //    print( s);

  //  let form = parse (parse_grammar.Grammar_Rule);// _Grammar_Rule();
  //  set_parser_support_to( s);
  //set_parser_support_to( "grammar parse_grammar = {   rule Spacing:Character = [ \n\t]* ; };");

  set_parser_support_to( "grammar parse_grammar = { rule truc<i:Int>:Int = toto.tata 'ouf'?; rule test:toto = @Separator(',', truc) ')' a to;");
  let form = parse (parse_grammar.Grammar);
  print_form( form);

  //  set_parser_support_to( "grammar_macro @Left_Infix_Operator(operators, subrule) = form:$subrule$ (id:$operators$ form2:$subrule$ form:{Compound_Form( id, list( form, form2))})* {form};");
  set_parser_support_to( "rule toto<a:Int>:Form = tata:truc taff @toto< truc>");
  let form2 = parse (parse_grammar.Grammar_Rule);

  
  print_form( form2);
};
