// Note: in the future, we could allow to declare macro return type too.
// But this only makes sense if the macro is hygienic.

// Sample macro; takes one parameter which is used in the macro.
macro assert( condition) = 
  if( condition == cast( Bool, 0))
    {
      print( "Testing Assertion ");
      print_form( Form( condition));
      print( " failed, so this worked.\n")
    };

// Here, condition is expanded and checked that it is Bool at the
// beginning of the macro.  In the future, this will also be the basis
// of macro overloading (which is, in turn, responsible for function and
// operator overloading)
macro assert_expanded( condition:Bool) = 
  if( condition == cast( Bool, 0))
    {
      print( "Testing Assertion ");
      print_form( Form( condition));
      print( " failed, so this worked.\n")
    };

// This macro shows the difference between assert and assert_expanded.
macro add_25( i:Int) = (25 + i);

//  // The last parameter can end with an ellipsis; in which case it is
//  // the list of the remaining parameters( so, a list of Forms).
//  // This is yet unimplemented.
//  macro panic( params...) =
//  {
//    print( "Fatal error: ", @params);
//    exit( 3);
//  };

// Finally, when we have parsers we can combine the definition of a parse and
// a macro into one unique definition:

//parse_macro while '(' @(condition:Expression( Bool)) ')' @(body:Expression) =
//macro while( condition:Bool, body)
macro whileee( condition:Bool, body) =
	loop {
	  if(condition == cast( Bool, 0))
	    break;
	  body;
};

//We should also allow $ in macros to do more complicated work than
//juste templating in macro; for that you can already use the full
//expander.

function test() -> Void =
{
  let j = 3;
  // This tests expansion of variable used here.
  assert( j == 0);
  assert_expanded( j == 0);

  // This shows the difference between assert and assert_expanded.
  assert( add_25( j) == 29);
  assert_expanded( add_25( j) == 29);

  let i = 0;
  whileee(i <= 10, {i = i + 1});
  print( "I: ", i, "\n");
  ();
};

//
//En gros, les macros ca diffère des expanders surtout par leur forme.
//
//macro assert(a)
//{
// if(a) { ... }
//}
//
//Tandis que
//
//expander assert(a)
//{
// if($a$) { ... }
//}
//
//En fait, on fait une transformation d'une macro en un expander.
//
//Les paramètres des macros peuvent etre types:
//
//macro (assert:Bool)
//
//Dans ce cas, les paramètres de la macro sont expandés avant le
//traitement de la macro (sinon ils ne le sont qu'après). Cela peut
//servir pour vérifier le typage des arguments (en fait, ca sert
//qu'à ca au début), mais après ca pourra aussi servir à avoir des
//macros polymorphes (par exemple, le if sur les listes.)
