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

compile_time global head_set_hash:Hash( Symbol, Character_Set);
//Temporary?
compile_time global rules_hash:Hash( Symbol, Form);

// Character set for .; could (or not) contain \n for instance.
compile_time global dot_character_set:Character_Set;

// Associates a grammar to a grammar name. Usefule for inter-grammar
// dependencies.
compile_time global grammar_hash:Hash( Symbol, Form);


// Computes the Head_Set of a grammar rule. For now, it is a character set.
// But as we want LL( *) parsing, in the future it will be a graph.
// The second argument is a list of "next rules"; the head is the closest.
// This is used to compute follow sets.
compile_time Character_Set
head_set( parse_form:Form, next_rules:List( Form))
{
  //  print_form( parse_form);
  let cs:Character_Set;
  if(is_compound_form( parse_form))
    {
      let cf = cast( Compound_Form, parse_form);
      if(cf.head == '[]')
	{
	  cs = make_Character_Set( cast( Form, cf));
	  ();
	}
      else if(cf.head == '[^]')
	{
	  cs = make_inverse_Character_Set( cast( Form, cf));
	  ();
	}
      else if(cf.head == ' ')
	{
	  //XXX: make a concatenation here.
	  cs = head_set( cf.form_list.head, cf.form_list.tail);
	  ();
	}
      else if(cf.head == '<>')
	{
	  cs = head_set( cf.form_list.tail.head, next_rules);
	  ();
	}
      else if(cf.head == '|')
	{
	  //We do the union of the character sets.
	  assert( cf.form_list != cast( List( Form), 0));
	  let cs_ = cast( List( Void *), head_set( cf.form_list.head, next_rules));
	  foreach( let rule in cf.form_list.tail)
	    {
	      //XXX: as the rules are normally disjoint, we do not need a real
	      //union here.
	      //cs = union_Character_Set( head_set( rule, next_rules), cs);
	      cs_ = append( cast( List( Void *), head_set( rule, next_rules)), cs_);
	    }
	  cs = cast( Character_Set, cs_);
	  ();
	}
      else if(cf.head == '{}')
	{
	  if(next_rules == cast( List( Form), 0))
	   {
	     panic( "Error in {}\n");
	   }
	  cs = head_set( next_rules.head, next_rules.tail);
	  ();
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
	 if(next_rules == cast( List( Form), 0))
	   {
	     panic( "Error in _\n");
	   }
	 cs = head_set( next_rules.head, next_rules.tail);
	 ();
       }
     else
       {
	 cs = head_set_hash[rule_name];
	 if(cs == cast( Character_Set, 0))
	   {
	 //This is used to prevent infinite recursion
	     head_set_hash[rule_name] = cast( Character_Set, -1);
	     cs = head_set( rules_hash[rule_name], cast( List( Form), 0));
	 if(cs == cast( Character_Set, -1))
	   {
	     print( "Error: infinite recursion in rule ", rule_name, "\n");
	     exit( 3);
	   }
	 head_set_hash[rule_name] = cs;
	   }
	 ();
       }
   }
  else if(is_string_form( parse_form))
    {
      let head = string_element( cast( String_Form, parse_form).value,
				 0);
      cs = cast( Character_Set, list( Character_Range( min:head, max:head)));
      ();
    }
  else {print( "Not handled\n"); print_form( parse_form); exit( 3);}
  
  //  let cs = make_Character_Set( cast( Compound_Form, Form( toto( '0'-'9'))));
  //  print_Character_Set( cs);
  cs
    
}

compile_time global id_used:Hash( Symbol, Type);

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
compile_time Form
grammar_expander_rec (parse_form:Form, next_rules:List( Form))
{
  if(is_compound_form( parse_form))
    {
      let cf = cast( Compound_Form, parse_form);
      if(cf.head == '[]' || cf.head == '[^]')
	{
	  //We don't care about the content of the character set.
	  Form( read_char())
	}
      else if(cf.head == '<>')
	{
	  //We need two parameters.
	  let id_form = cast( Id_Form, cf.form_list.head);
	  let id = id_form.value;
	  let left_form = cast( Form, id_form);

	  let subrule = cf.form_list.tail.head;
	  let right_form = grammar_expander_rec(subrule, next_rules);

	  // This should go away when we have context-dependent expanders.
	  if( is_compound_form( subrule)
	      && cast( Compound_Form, subrule).head == '*'
	      || cast( Compound_Form, subrule).head == '+')
	    {
	      right_form = Form( make_list( $right_form$));
	    }
	  
	  let exp_right_form = expand( right_form);

	  if(id_used[id] == cast( Type, 0))
	    {
	      //	      id_used[id] = exp_right_form.type;
	      id_used[id] = cast( Type, 1);//exp_right_form.type;
	      expand(Compound_Form( 'let',
				    list( cast( Form, id_form),
					  exp_right_form.type.type_form)));
	      
	    }
	  Form( $left_form$ = $cast(Form, exp_right_form)$)
	}
      else if(cf.head == '{}')
	{
	  Form( seq( $@cf.form_list$))
	}
      else if(cf.head == ' ')
	{
	  let fl = make_list( {
	      let grammar_rule_it = cf.form_list;
	      while(grammar_rule_it != cast( List( Form), 0))
		{
		  let grammar_rule = grammar_rule_it.head;
		  let grammar_tail = grammar_rule_it.tail;
		  make( grammar_expander_rec( grammar_rule, grammar_tail));
		  grammar_rule_it = grammar_tail;
		} ()});
	  //	      foreach( let grammar_rule in cf.form_list)
		//XXX next is really important here.
	  //		make( grammar_expander_rec( grammar_rule, cast(List( Form), 0))); ()});
	  Form( seq( $@fl$))
	}
      else if(cf.head == '|')
	{
	  let peeked_char = gensym( "peeked_char_alt");
	  let peeked_char_form = Id_Form( peeked_char);

	  let else_form = Form( parse_error());
	  
	  foreach( let grammar_rule in cf.form_list)
	    {
	      let char_set = head_set( grammar_rule, next_rules);
	      else_form = Form( if($is_in_Character_Set_condition(peeked_char_form,
								  char_set)$)
				  $grammar_expander_rec( grammar_rule, next_rules)$
				else $else_form$);
	    }
	  Form( block( $Compound_Form('let',
				    list( peeked_char_form))$ = peek_char(),
		     $else_form$))
	}
      else if(cf.head == '*')
	{
	  let repeated_rule = cf.form_list.head;
	  let char_set = head_set( repeated_rule, cast( List( Form), 0));

	  let peeked_char = gensym( "peeked_char_star");
	  let peeked_char_form = Id_Form( peeked_char);

	  Form(loop {
	      $Compound_Form('let', list( peeked_char_form))$ = peek_char();
	      if(!($is_in_Character_Set_condition( peeked_char_form, char_set)$))
		break;
	      $grammar_expander_rec(repeated_rule, next_rules)$;
		})
	}
      else if(cf.head == '?')
	{
	  let maybe_rule = cf.form_list.head;
	  let char_set = head_set( maybe_rule, cast( List( Form), 0));
	  let peeked_char = gensym( "peeked_char_maybe");
	  let peeked_char_form = Id_Form( peeked_char);

	  Form({
	      $Compound_Form('let', list( peeked_char_form))$ = peek_char();
	      if($is_in_Character_Set_condition( peeked_char_form, char_set)$)
		$grammar_expander_rec(maybe_rule, next_rules)$;
		})
	}
      else
	{
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
      else if(id_form.value == '.')
	{
	  Form( read_char())
	}
      else Form( funcall( $Id_Form(intern_string(concat( "parse_", id_form.value.name)))$))
	}
  else if(is_string_form( parse_form))
    {
      //Read the first character; check the other.
      //For now we check them all.
      let cl = string_to_int_list( cast( String_Form, parse_form).value);
      let form_list = make_list( {
      foreach( let Int in cl)
	{
	  //print( "Int: ", int, " ");
	  //XXX: we don't make any check.
	  make( Form( read_char()))
	    }; ()});
      Form( seq( $@form_list$))
	
    }
  else
    {
      print( "FORM PROBLEM\n");
      print_form( parse_form);
      Form( imp2)
	}
}

compile_time Form expand_grammar_rule( rule:Form)
{
//  id_used = Hash( Symbol, Type);
//
//  let function_body = grammar_expander_rec( rule, cast( List( Form), 0));
//
//  let var_decl_list = make_list( {
//  foreach( (let id, let type) in id_used)
//    {
//      make( 1);
//    }; ()});
//
  Form( ());
}

expander grammar_expander( form_)
{
  //XXX: we should tell the expander that we create a block here
  //so that all the allocated variables are defined in here.
  id_used = Hash( Symbol, Type);
  let rule = cast( Symbol_Form, form_.form_list.head).value;
  if(rules_hash[rule] == cast( Form, 0))
    {
      print( "Unknown rule\n", rule);
      exit( 3);
    }
  
  let form = grammar_expander_rec(rules_hash[rule], cast( List( Form), 0));

  //  print_form( cast( Form, form));
  form;
}

List( Form)
grammar_produce_function_definitions( grammar_:Form)
{
  let grammar = cast( Compound_Form, grammar_);
  let grammar_name = cast( Id_Form, grammar.form_list.tail.tail.head).value;
  let rule_list = cast( List( Compound_Form), grammar.form_list.tail.tail.tail);
  
  dot_character_set = cast( Character_Set, list( Character_Range( min:1, max:255)));
  rules_hash = cast( Hash( Symbol, Form), make_hash_table());
  head_set_hash = Hash( Symbol, Character_Set);
  
  // Fill the rule_hash.
  foreach( let rule in rule_list)
    {
      //      print_form( rule);
      let rule_name = cast( Id_Form, rule.form_list.head).value;
      let form = cast( Form, rule.form_list.tail.head);
      rules_hash[rule_name] = form;
    }

  // Create the functions.

  let form_list = make_list( {
  foreach( let rule in rule_list)
    {
      let rule_name = cast( Id_Form, rule.form_list.head).value;
      let function_name = intern_string( concat( "parse_", rule_name.name));

      let form = cast( Form, rule.form_list.tail.head);
  
      let function_body = grammar_expander_rec( form, cast( List( Form), 0));

      let exp_function_body = expand( Compound_Form( 'block',
						     list( function_body)));

      let lambda_form = Compound_Form( 'lambda',
				       list( exp_function_body.type.type_form,
					     Compound_Form( 'tuple',
							    cast( List( Form), 0)),
					     exp_function_body.return_form));

      let function_form = Compound_Form( 'define',
					 list( Id_Form( 'function'),
					       Id_Form( function_name),
					       lambda_form));
      make( function_form);
    }; ()});
  
  form_list;
}

Void
test()
{
    let rule = Compound_Form( 'define',
			    list( Id_Form( 'rule'),
				  Id_Form( 'Comment'),
				  Compound_Form( ' ',
					 list( String_Form( "//"),
					       Compound_Form( '*',
							      list( Compound_Form( '[^]',
										   list( Int_Form( 10))))),
					       Compound_Form( '[]',
							      list( Int_Form( 10)))))));
    let grammar = Compound_Form( 'define',
				 list( Id_Form( 'grammar'),
				       Id_Form( 'test_grammar'),
				       rule));

    grammar_produce_function_definitions( grammar);

  //  Form( ());
  //  expand_init_test();
  ();
}