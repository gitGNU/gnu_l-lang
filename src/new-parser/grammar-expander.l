include "new-parser/character-set.l";

// Next version should do macro expansion as a first step;
// Comprising expansion of rule? in ( rule |), or '' and "".
// 
// also should pass as an argument of grammar_expander_rec whether
// the result is needed( useful for implementing make_list correctly without using make,
// as well as for interning symbols.
// It should return a graph, and handle next_rules more efficiently
// ( e.g. as a list of list, no append).
//
//It could optimise the common case ((rule1|rule2) rule3)* by changing the default action
//when not in a character set by not being parse_error.
// 
//It should have the sequencing operator, ->, used for expressiong LL( k) parsing.
//
//It should handle the case (a|b|) well, using a else for the last condition. This specification
//allows to write generic rules, that have different follow sets depending on when they are called;
//for instance a rule Maybe_Symbol:Symbol =  (Symbol|{'default'}) is OK.
//
//With the else semantics, we can translate( a|b| ..) as if(..) a else if()..  else ... i.e.:
//(a|b|c) <=> (a|( b|c))
//
//
//There is a need for correct handling of semantic predicates. This is made simpler with the
//translation with the else semantics (i.e. ordered choice).
//
// It should check and detect all parse errors; i.e. it should really read strings and so on,
// event if it is sometimes read twice, unless it can avoid it.
// 
// Also, expansion of 'symbol' in conditionals should perform additional
// checks to validate the symbol; this is for not validating - instead of ->
// for instance.

// Dynamic-scope variable.
compile_time global grammar_name:Symbol;

//Rendered useless by get_parse_function.
compile_time function
function_name_from_grammar_and_rule( grammar_name:Symbol,
				     rule_name:Symbol) -> String =
{
  concat( "_l__parse__", concat( convert_id( grammar_name).name,
				 concat( "__", convert_id( rule_name).name)))
};


//Get a function name from its description of type head( grammar.rule)
expander get_parse_function( form) =
{
  let form2 = form.form_list.head;
  assert( is_compound_form( form2));
  let cf2 = cast( Compound_Form, form2);
  print_form( form2);
  assert( cf2.head == '[]');

  let grammar_id_form = cf2.form_list.head;
  let rule_id_form = cf2.form_list.tail.head;
  assert( is_id_form( grammar_id_form));
  //  assert( is_symbol_form( rule_id_form));

  let grammar = cast( Id_Form, grammar_id_form).value;
  let rule = cast( Id_Form, rule_id_form).value;

  
  Id_Form(intern_string( function_name_from_grammar_and_rule( grammar,
							      rule)))
};


//compile_time type Exit = struct { dummy:Int;}*;

// XXX: c'est un Int pour satisfaire Digit_or_Alpha, mais en fait ca devrait etre
// n'importe quoi (type Exit)
//compile_time Exit
//parse_error()
//{
//  print( "Parse error\n");
//  exit( 3);
//  cast( Exit, 3);
//}

// A hash grammar_name -> rule_name -> Character_Set
compile_time global head_set_hash:Hash< Symbol, Hash< Symbol, List< Character_Set>>>;

// A hash grammar_name -> rule_name -> Form
compile_time global rules_hash:Hash< Symbol, Hash< Symbol, Form>>;

// Character set for .; could (or not) contain \n for instance.
//compile_time global dot_character_set:Character_Set;

// Associates a grammar to a grammar name. Usefule for inter-grammar
// dependencies.
compile_time global grammar_hash:Hash< Symbol, Form>;


// Computes the Head_Set of a grammar rule. For now, it is a List< Character set>.
// But as we want a beter LL( *) parsing, in the future it will be a graph.
// The second argument is a list of "next rules"; the head is the closest.
// This is used to compute follow sets.
compile_time function
head_set( parse_form:Form, next_rules:List< Form>) -> List< Character_Set> =
{
  //  print_form( parse_form);
  let cs:Character_Set;
  let cs_list:List< Character_Set>;
  if(is_compound_form( parse_form))
    {
      let cf = cast( Compound_Form, parse_form);
      if(cf.head == '[]')
	{
	  cs_list = list( make_Character_Set( cast( Form, cf)));
	}
      else if(cf.head == '[^]')
	{
	  cs_list = list( make_inverse_Character_Set( cast( Form, cf)));
	}
      else if(cf.head == ' ')
	{
	  //XXX: make a concatenation of the second argument here?
	  cs_list = head_set( cf.form_list.head, cf.form_list.tail);
	}
      else if(cf.head == ':')
	{
	  cs_list = head_set( cf.form_list.tail.head, next_rules);
	}
      else if(cf.head == '|')
	{
	  //We do the union of the character sets.
	  assert( cf.form_list != cast( List< Form>, 0));
	  let cs_ = head_set( cf.form_list.head, next_rules);
	  foreach( let rule in cf.form_list.tail)
	    {
	      //XXX: as the rules are normally disjoint, we do not need a real
	      //union here.
	      //cs = union_Character_Set( head_set( rule, next_rules), cs);
	      //cs_ = append( cast( List< Void *>, head_set( rule, next_rules)), cs_);
	      cs_ = union_Character_Set_List( head_set( rule, next_rules), cs_);
	    };
	  //	  cs_list = list( sort_Character_Set( cast( List< Character_Range>, cs_)));
	  cs_list = cs_;
	}
      else if(cf.head == '*')
	{
	  let cs_ = union_Character_Set_List( head_set( cf.form_list.head,
							cf.form_list.tail),
					      head_set( next_rules.head,
							next_rules.tail));
	  cs_list = cs_;
	}
      else if(cf.head == '+')
	{
	  cs_list = head_set( cf.form_list.head, cf.form_list.tail);
	}
      else if(cf.head == '{}')
	{
	  if(next_rules == cast( List< Form>, 0))
	   {
	     cs_list = cast( List< Character_Set>, 0);
	     //	     print_form( cast( Form, cf));
	     //	     panic( "Error in {}\n");
	   }
	  else {cs_list = head_set( next_rules.head, next_rules.tail);};
	}
      else if(cf.head == '.')
	{
	  let save_grammar_name = grammar_name;
	  grammar_name = cast( Id_Form, cf.form_list.head).value;
	  let rule_name = cast( Id_Form, cf.form_list.tail.head).value;
	  assert( head_set_hash[grammar_name] != cast( Hash< Symbol, List< Character_Set>>, 0));
	  cs_list = head_set_hash[grammar_name][rule_name];
	  if(cs_list == cast( List< Character_Set>, 0))
	    {
	      //This is used to prevent infinite recursion
	      head_set_hash[grammar_name][rule_name] = cast( List< Character_Set>, -1);
	      let named_rule = rules_hash[grammar_name][rule_name];
	      if(named_rule == cast( Form, 0))
		{
		  panic( "Trying to calculate the head set of an unknown rule: ", rule_name, "\n");
		};
	      cs_list = head_set( named_rule, cast( List< Form>, 0));
	      if(cs_list == cast( List< Character_Set>, -1))
		{
		  print( "Error: infinite recursion in rule ", rule_name, "\n");
		  exit( 3);
		};
	 
	      head_set_hash[grammar_name][rule_name] = cs_list;
	    };
	 grammar_name = save_grammar_name;
	}
      else if(cf.head == '@')
	{
	  // XXX: many cases should be reduced to this one.
	  // XXX: this case should be expanded once instead of dynamically.
	  let form = cf.form_list.head;
	  assert( is_compound_form( form));
	  let form_head = cast( Compound_Form, form).head;

	  let grammar_form = call_grammar_macro( form_head, form);
	  cs_list = head_set( grammar_form, next_rules);
	}
      else {
	print( "Unimplemented :|", cf.head, "|\n");
	print_form( parse_form);
	exit( 3);
      }
    }
 else if( is_id_form( parse_form))
   {
     let rule_name = cast( Id_Form, parse_form).value;
     if(rule_name == '_')
       {
	 //_ should be interpreted like (something?)
	 if(next_rules == cast( List< Form>, 0))
	   {
	     panic( "Error in _\n");
	   };
	 cs_list = head_set( next_rules.head, next_rules.tail);
       }
     else
       {
	 assert( head_set_hash[grammar_name] != cast( Hash< Symbol, List< Character_Set>>, 0));
	 cs_list = head_set_hash[grammar_name][rule_name];
	 if(cs_list == cast( List< Character_Set>, 0))
	   {
	     //This is used to prevent infinite recursion
	     head_set_hash[grammar_name][rule_name] = cast( List< Character_Set>, -1);
	     let named_rule = rules_hash[grammar_name][rule_name];
	     if(named_rule == cast( Form, 0))
	       {
		 panic( "Trying to calculate the head set of an unknown rule: ", rule_name, "\n");
	       };
	     cs_list = head_set( named_rule, cast( List< Form>, 0));
	     if(cs_list == cast( List< Character_Set>, -1))
	       {
		 print( "Error: infinite recursion in rule ", rule_name, "\n");
		 exit( 3);
	       };
	 
	     head_set_hash[grammar_name][rule_name] = cs_list;
	   };
       }
   }
  else if(is_string_form( parse_form))
    {
      let head = string_element( cast( String_Form, parse_form).value,
				 0);
      cs_list = list( cast( Character_Set, list( Character_Range( min:head, max:head))));
      ();
    }
  else if(is_symbol_form( parse_form))
    {
      //A symbol needs a "check" from the rule following the current one to be validated.
      let l = string_to_int_list(  cast( Symbol_Form, parse_form).value.name);
      cs_list = make_list foreach( let head in l)
	    {
	      make( cast( Character_Set, list( Character_Range( min:head, max:head))));
	    };
      //A symbol needs a "check" from the rule following the current one to be validated.
      //Useful when for instance = is prioritary over ==
      //TODO
    }
  
  else {print( "Not handled\n"); print_form( parse_form); exit( 3);};
  
  //  let cs = make_Character_Set( cast( Compound_Form, Form( toto( '0'-'9'))));
  //  print_Character_Set( cs);
  //foreach( cs in cs_list) print_Character_Set( cs);
  cs_list
    
};

// Return a Form usable as a condition for knowing whether to take the branch.
compile_time function
head_set_function( parse_form:Form) -> Form =
{
  let ret_form = cast( Form, 0);

  // This introduction of & is a bit hacky, and only works on semantic predicates.
  let cop_form = parse_form;
  while (is_compound_form( cop_form)
	 and cast( Compound_Form, cop_form).head == ' ')
    cop_form = cast( Compound_Form, cop_form).form_list.head;

  if(is_compound_form( cop_form))
  {
    // XXX: se faire toutes les sequences en boucle( ' ') avant ca.
    let cf = cast( Compound_Form, cop_form);
    if(cf.head == '&')
      {
	assert( is_compound_form( cf.form_list.head)
		and cast( Compound_Form, cf.form_list.head).head == '{}');
	ret_form = grammar_expander_rec( cf.form_list.head, cast( List< Form>, 0));
      };
  };
  
 // C output does not support gotos in compound expressions.
 if(ret_form == cast( Form, 0))
   { 
     let ret_set = head_set( parse_form, cast( List< Form>, 0));
     
     ret_form = is_in_Character_Set_condition( ret_set);
   };
 ret_form
};

compile_time global id_used:Hash< Symbol, Type>;


compile_time global semantic_condition_then:struct {condition:Form; then:List< Form>;};
  


// Transforms a form into a real grammar.
// parse form is constituted of a list of compound form whose head can be:
// <>: diamond forms (for grouping, calling other rules)
// {}: brace forms (for semantic actions)
// []: character sets
// / : an ordered alternative (for ordered choices)
// /e: an alternative that also contains epsilon
// * : A repetition
// & : A syntactic predicate
// &{}: A semantic predicate
// ' ': A sequence i.e., 'A B' means( parses A, then B)
// '': a token (must be validated by checking their queue)
// "": equivalent to a suit of character sets
// 
// It can also be an Id, in which case the corresponding rule is
// called( eventually with previously-defined parameters).
//
// If the id is '_', it returns the current string pointer. This can after be used
// in a substring operation to extract the substring.
//
// If the id is '.', it is replaced by "dot_character_range" (by default 1-255)

//The second argument is a list of "next rules", used for follow_set computation.
compile_time function
grammar_expander_rec (parse_form:Form, next_rules:List< Form>) -> Form =
{
  if(is_compound_form( parse_form))
    {
      let cf = cast( Compound_Form, parse_form);
      if(cf.head == '[]' or cf.head == '[^]')
	{
	  //We don't care about the content of the character set.
	  Form( read_char())
	}
      else if(cf.head == ':')
	{
	  //We need two parameters.
	  let id_form = cast( Id_Form, cf.form_list.head);
	  let id = id_form.value;
	  let left_form = cast( Form, id_form);

	  let subrule = cf.form_list.tail.head;
	  let right_form = grammar_expander_rec(subrule, next_rules);

	  // This should go away when we have context-dependent expanders.
	  if( is_compound_form( subrule)
	      and cast( Compound_Form, subrule).head == '*'
	      or cast( Compound_Form, subrule).head == '+')
	    {
	      right_form = Form( make_list( $right_form$));
	    };
	  
	  let exp_right_form = expand( right_form);

	  if(id_used[id] == cast( Type, 0))
	    {
	      //	      id_used[id] = exp_right_form.type;
	      id_used[id] = cast( Type, 1);//exp_right_form.type;
	      expand(Compound_Form( 'let',
				    list( cast( Form, id_form),
					  exp_right_form.type.type_form)));
	      
	    };
	  Form( $left_form$ = $cast(Form, exp_right_form)$)
	}
      else if(cf.head == '{}')
	{
	  Form( seq( $@cf.form_list$))
	}
      else if(cf.head == ' ')
	{
	  let fl = make_list {
	      let grammar_rule_it = cf.form_list;
	      while(grammar_rule_it != cast( List< Form>, 0))
		{
		  let grammar_rule = grammar_rule_it.head;
		  let grammar_tail = grammar_rule_it.tail;
		  make( grammar_expander_rec( grammar_rule, grammar_tail));
		  grammar_rule_it = grammar_tail;
		}};
	  //	      foreach( let grammar_rule in cf.form_list)
		//XXX next is really important here.
	  //		make( grammar_expander_rec( grammar_rule, cast(List< Form>, 0))); ()});
	  Form( seq( $@fl$))
	}
      else if(cf.head == '|')
	{
	  // | directly transates to a if(..) THEN else ELSE. This is why it is
	  // a right-associative binary operator.
	  // Notice that the choices are thus ordered; this is important for semantic
	  // predicates and semantic actions (e.g., min:('a' {23} | {32})
	  if(cast( Bool, 1))
	    {
	      assert( cf.form_list != cast( List< Form>, 0)
		      and cf.form_list.tail != cast( List< Form>, 0)
		      and cf.form_list.tail.tail == cast( List< Form>, 0));

	      let maybe_rule = cf.form_list.head;
	      let cond_form = head_set_function( maybe_rule);
	  
	  Form({
	      if($cond_form$)
		$grammar_expander_rec(maybe_rule, next_rules)$
		else
		  $grammar_expander_rec(cf.form_list.tail.head, next_rules)$
		    })
	    }
	  else
	    {
	  
	  // Special case when the head_set of a subrule is empty
	  // (it can happen only once, preferably at the end):
	  // We translate it into a else condition.
	  // For instance, (a{1}|{0}) => if(peek_char()=='a') 1 else 0;
	  // b? => (b {...}|) => if(peek_char() == 'b') ... else ();
	  let peeked_char = gensym( "peeked_char_alt");
	  let peeked_char_form = Id_Form( peeked_char);

	  let orig_else_form_ptr = cast( Form*, 0);
	  let else_form = Form( parse_error());

	  let number_rule_empty = 0;

	  let form_list = cf.form_list;
	  
	  foreach( let grammar_rule in form_list)
	    {
	      //	      let char_set = head_set( grammar_rule, next_rules);
	      let char_set = head_set( grammar_rule, cast( List< Form>, 0));
	      if(char_set == cast( List< Character_Set>, 0))
		{
		  number_rule_empty = number_rule_empty + 1;
		  if(number_rule_empty > 1)
		    panic( "An alternative must have at most one empty rule");
		  assert( orig_else_form_ptr != cast( Form*, 0));
		  //		  print_form( else_form);
		  *orig_else_form_ptr = grammar_expander_rec( grammar_rule, cast( List< Form>, 0));
		  //		  print_form( else_form);
		}
	      else
		{
		  else_form = Form( if($is_in_Character_Set_condition(char_set)$)
				      $grammar_expander_rec( grammar_rule, next_rules)$
				      else $else_form$);
		  if(orig_else_form_ptr == cast( Form*, 0))
		    {
		      let cfe = cast( Compound_Form, else_form);
		      orig_else_form_ptr = &(cfe.form_list.tail.tail.head);
		    };
		};
	    };

	  let ret_form = Form( block( $Compound_Form('let',
						     list( peeked_char_form))$ = peek_char(),
				      $else_form$));
	  ret_form
	    }
	}
      else if(cf.head == '*')
	{
	  let repeated_rule = cf.form_list.head;
	  let cond_form = head_set_function( repeated_rule);

	  let peeked_char = gensym( "peeked_char_star");
	  let peeked_char_form = Id_Form( peeked_char);

	  Form(loop {
	      if( not( $cond_form$))
		break;
	      $grammar_expander_rec(repeated_rule, next_rules)$;
		})
	}
      else if(cf.head == '+')
	{
	  // Expand into a do .. while like loop.
	  let repeated_rule = cf.form_list.head;
	  let cond_form = head_set_function( repeated_rule);

	  Form(loop {
	      $grammar_expander_rec(repeated_rule, next_rules)$;
	      if( not( $cond_form$))
		break;
		})
	}
      else if(cf.head == '?')
	{
	  let maybe_rule = cf.form_list.head;
	  let cond_form = head_set_function( maybe_rule);

	  Form({
	      if($cond_form$)
		$grammar_expander_rec(maybe_rule, next_rules)$;
	    })
	}
      else if(cf.head == '.')
	{
	  let gram_name = cast( Id_Form, cf.form_list.head).value;
	  let rule_name = cast( Id_Form, cf.form_list.tail.head).value;
	  Form( funcall( $Id_Form(intern_string( function_name_from_grammar_and_rule( gram_name,
										      rule_name)))$))
	}
      else if(cf.head == '@')
	{
	  // XXX: this case should be expanded once instead of dynamically.

	  let form = cf.form_list.head;
	  assert( is_compound_form( form));
	  let form_head = cast( Compound_Form, form).head;

	  let grammar_form = call_grammar_macro( form_head, form);
	  //	  print_form( grammar_form);
	  grammar_expander_rec( grammar_form, next_rules)
	}
      else if(cf.head == '&')
	{
	  Form( ())
	  
//	  panic( "Utiliser un head set special et creer une fonction head_set_function");
//	  semantic_condition_then.condition = cf.form_list.head;
//	  semantic_condition_then.then = cf.form_list.tail;
//	  // XXX: this can cause segmentation faults when undetected. Should return a void value instead.
//	  cast( Form, 0)
	}
      else
	{
	  print_form( cast( Form, cf));
	  panic( "unknown head:", cf.head, "\n");
	  Form( imp)
	}
    }
  else if(is_id_form( parse_form))
    {
      let id_form = cast( Symbol_Form, parse_form);
      if(id_form.value == '_')
	{
	  Form( funcall( get_point_pos))
	}
      else Form( funcall( $Id_Form(intern_string( function_name_from_grammar_and_rule( grammar_name,
										       id_form.value)))$))
	}
  else if(is_string_form( parse_form))
    {
      //Read the first character; check the other.
      //For now we check them all.
      let cl = string_to_int_list( cast( String_Form, parse_form).value);
      let form_list = make_list foreach( let Int in cl)
      {
	  //print( "Int: ", int, " ");
	  //XXX: we don't make any check.
	  make( Form( read_char()))
      };
      Form( seq( $@form_list$))
    }
  else if(is_symbol_form( parse_form))
    {
      // XXX: symbols should be confirmed by a following character, to
      // prevent e.g. '-' to be parsed instead of '->'.
      let symbol = cast( Symbol_Form, parse_form).value;
      Form( parse_symbol( $String_Form(symbol.name)$))
    }
  else
    {
      panic( "FORM PROBLEM\n");
      print_form( parse_form);
      Form( imp2)
	}
};


//compile_time function
//expand_grammar_rule( rule:Form) -> Form =
//{
////  id_used = Hash( Symbol, Type);
////
////  let function_body = grammar_expander_rec( rule, cast( List< Form>, 0));
////
////  let var_decl_list = make_list( {
////  foreach( (let id, let type) in id_used)
////    {
////      make( 1);
////    }; ()});
////
//  Form( ());
//};

// Allow to call a rule to parse from outside.
// Future additional arguments may include the string
// to parse and parameters to the rule.
expander parse( form) =
{
  Form( funcall( get_parse_function( $form.form_list.head$),
		 $@form.form_list.tail$))
};

expander grammar_expander( form_) =
{
  //XXX: we should tell the expander that we create a block here
  //so that all the allocated variables are defined in here.
  id_used = Hash( Symbol, Type);
  let rule = cast( Symbol_Form, form_.form_list.head).value;
  if(rules_hash[grammar_name][rule] == cast( Form, 0))
    {
      print( "Unknown rule\n", rule);
      exit( 3);
    };

  grammar_name = 'parse_grammar';
  let form = grammar_expander_rec(rules_hash[grammar_name][rule], cast( List< Form>, 0));

  //  print_form( cast( Form, form));
  form
};

function
expand_grammar_list( grammar_list:List< Compound_Form>) -> List< Form> =
{
  rules_hash = cast( Hash< Symbol, Hash< Symbol, Form>>, make_hash_table());
  head_set_hash = cast( Hash< Symbol, Hash< Symbol, List< Character_Set>>>,
			make_hash_table());
  
  //Fill the rule_hashes, set head_set_hash and predefines the functions.
  foreach( let grammar in grammar_list)
    {
      grammar_name = cast( Id_Form, grammar.form_list.tail.head).value;
      rules_hash[grammar_name] = cast( Hash< Symbol, Form>, make_hash_table());
      head_set_hash[grammar_name] = cast( Hash< Symbol, List< Character_Set>>,
					  make_hash_table());
      
      let rule_list = cast( List< Compound_Form>, grammar.form_list.tail.tail);
      
      foreach( let rule in rule_list)
	{
	  let rule_name = cast( Id_Form, rule.form_list.head).value;
	  let form = cast( Form, rule.form_list.tail.tail.tail.head);
	  rules_hash[grammar_name][rule_name] = form;
	  pre_define_function( intern_string( function_name_from_grammar_and_rule( grammar_name,
										   rule_name)),
			       rule.form_list.tail.head);
	};
    };

  //Creates the functions.
  let form_list = make_list foreach( let grammar in grammar_list)
	{
	  grammar_name = cast( Id_Form, grammar.form_list.tail.head).value;

	  let rule_list = cast( List< Compound_Form>, grammar.form_list.tail.tail);
	  foreach( let rule in rule_list)
	    {
	      let rule_name = cast( Id_Form, rule.form_list.head).value;
	      let function_name = intern_string( function_name_from_grammar_and_rule( grammar_name,
										      rule_name));
	      let return_type_form = rule.form_list.tail.head;
	      let params = cast( Compound_Form, rule.form_list.tail.tail.head);
	      let form = cast( Form, rule.form_list.tail.tail.tail.head);
	      
	      id_used = cast( Hash< Symbol, Type>, make_hash_table());
	      declare_function_begin( params, return_type_form);
	      declare_block_begin();
	      
	      let function_body = grammar_expander_rec( form, cast( List< Form>, 0));
	      let exp_function_body = declare_block_end( list( function_body));
	      let lambda_form = declare_function_end( exp_function_body);
	      let function_form = Compound_Form( 'define',
						 list( Id_Form( 'function'),
						       Id_Form( function_name),
						       lambda_form.return_form));
	      make( function_form);
	    };
	};

  form_list
};

function
test() -> Void = 
{
 //   let rule = Compound_Form( 'define',
 //			    list( Id_Form( 'rule'),
 //				  Id_Form( 'Void'),
 //				  Id_Form( 'Comment'),
 //				  Compound_Form( ' ',
 //					 list( String_Form( "//"),
 //					       Compound_Form( '*',
 //							      list( Compound_Form( '[^]',
 //										   list( Int_Form( 10))))),
 //					       Compound_Form( '[]',
 //							      list( Int_Form( 10)))))));
 //   let grammar = Compound_Form( 'define',
 //				 list( Id_Form( 'grammar'),
 //				       Id_Form( 'test_grammar'),
 //				       rule));
 //
 //   grammar_produce_function_definitions( grammar);

  //  Form( ());
  //  expand_init_test();
  ();
};
