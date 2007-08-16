// Finally, when we have parsers we can combine the definition of a parse and
// a macro into one unique definition:

//parse_macro while '(' @(condition:Expression( Bool)) ')' @(body:Expression) =
//macro while( condition:Bool, body)
macro while( condition:Bool, body) =
	loop {
	  if(condition == cast( Bool, 0))
	    break;
	  body;
};