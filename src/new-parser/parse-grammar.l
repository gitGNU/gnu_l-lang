
global glob_i:Int;

grammar parse_grammar = {
  rule Spacing = [ \n\t]* ;
  rule Alpha = [a-zA-Z_] ;
  rule Alpha_Num = [a-zA-Z_0-9] ;
  
  
  rule Identifier = <start:_> Alpha Alpha_Num* <end:_>
  { intern( substring( start, end))} ;

  rule Escaped_Character = [\\] ( "n" {10}
                                 | "t"  {9}
				 | [^tn] ) ;
  
  rule Maybe_Escaped_Character = Escaped_Character | [^\\] ;
  rule Maybe_Escaped_Character_Character_Range = Escaped_Character|[^\]\\];

  //  rule String = ["] <start:_> ( Escaped_Character | [^"\\])* <end:_> ["]
  //                {String_Form( substring( start, end))} ;
  
  rule Character_Range = <max:<min:Maybe_Escaped_Character_Character_Range>>
                         ("-" <max:Maybe_Escaped_Character>)?
                         { Character_Range( min:min, max:max) } ;

  rule Character_Set = <char_selector:{'[]'}>
                       "[" ("^" <char_selector:{'[^]'}>)?
                       <cr_list:( <cr:Character_Range> { make( cr) })*> "]"
                       { Compound_Form( char_selector, cr_list) } ;

  rule Callable_Rule = <id:Identifier> {Id_Form( id)};

  rule Semantic_Action = "{" <exp:Expression> "}"
                         {Compound_Form( '{}', list( exp))};
  
  rule Grouping = "<" <id:Identifier> ":" <form:Rule> ">"
                  { Compound_Form( '<>', list( Id_Form( id), form)) };

  rule Primary = (String
		  | Character_Set 
		  | Callable_Rule
		  | Grouping
		  | Semantic
		  | "(" <r:Rule> ")" {r});

  rule Postfix = <form:Primary> ( <start:_> ("?" | "*" | "+") <end:_>
				  <form:{ Compound_Form( intern( substring( start,end)),
							 list( form)) }>)?
                 { form };
  
  rule Sequence = Spacing <post_list:(<post:Postfix>  Spacing {post})*>
                  { Compound_Form( ' ', post_list) };

  rule Alternative = <prim:Sequence>
                     ("|" Spacing <sec:Sequence> <prim:{ Compound_Form( '|', list( prim, sec)) }>)*
                     { prim };


  rule Rule = Alternative;

  rule Grammar_Rule = "rule" Spacing <id:Identifier> Spacing "=" Spacing
                      <r:Rule> Spacing ";" Spacing
                      { Compound_Form( 'rule', list( Id_Form( id), r)) };
  
  rule Grammar = "grammar" Spacing <id:Identifier> Spacing "=" Spacing
                 "{" <gr_list:(<gr:Grammar_Rule> {make( gr)})*> "}" Spacing ";"
                 { Compound_Form( 'define',
				  cons( Id_Form( 'grammar'),
					cons( Id_Form( id),
					      gr_list))) };
  
};

Void
test ()
{

}
