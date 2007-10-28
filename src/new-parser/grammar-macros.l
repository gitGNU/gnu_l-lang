// These macros are good examples on how to use the parse language to
// parse standard patterns, but they are useful in real too.

//XXX: tester aver des $ aussi.
grammar_macro @Left_Infix_Operator<operators, subrule, this_rule> = 
  form:subrule
  (id:operators form2:subrule form:{Compound_Form( id,
						   list( form,
							 form2))})*
  {form};

//XXX: this is the maybe_empty separator. Useful e.g. as arguments to C functions
//Would be better with a type for null which would coerce into anything;
//for now we can return only list of forms.
grammar_macro @Separator<separator, rule> =
  arg_list:{cast( List< Form>, 0)}
  ( arg1:rule
    arg_list:(separator arg:rule {make( arg)})*
    arg_list:{cons( arg1, arg_list)} )?
  {arg_list};

//XXX: this is the maybe_empty separator. Useful e.g. as arguments to C functions
//Would be better with a type for null which would coerce into anything;
//for now we can return only list of forms.
grammar_macro @Maybe_Empty_Separator<separator, rule> = @Separator<separator, rule>;

//This separator should not be an empty list.
grammar_macro @Non_Empty_Separator<separator, rule> =
  arg1:rule
  arg_list:(separator arg:rule {make( arg)})*
  {cons( arg1, arg_list)}; 

grammar_macro @Right_Infix_Operator< operators, subrule, this_rule> =
  form:subrule
  (id:operators form2:this_rule
   form:{Compound_Form( id, list( form, form2))})?
{form};


grammar_macro @Unary_Prefix_Operator< operators, subrule, this_rule> =
  ( op:operators form:this_rule {Compound_Form( op, list( form))}
  | form:subrule);

// Surround a rule by this macro when the rule's content is intended to be a replacement
// XXX: should check that use of replacement is ok by using a dynamically scoped variable
// XXX: we should define a Replacement2, with two $$, when $ cannot be used (e.g. in perl code)
grammar_macro @Replacement< rule> = __rep_symb:('$@'|'$')//{if(replacable == false)
                				           //parse_error( "Replacement not allowed here\n")}
				    __rep_exp:rule '$' {Compound_Form( __rep_symb, list( __rep_exp))};

// Use this when a rule can be replaced. The rule must then return a Form.
grammar_macro @Replaceable< rule> = ( @Replacement<Code.Sequence> 
				   | rule );



// Allows a rule to use replacements in the subrules.
// The idea is to forbid replacements outside of the Form macro.
// XXX: should set the dynamically scoped variable
grammar_macro @Allow_Replacement<rule> = rule;



// Other tips:
//
// - ? with else:
//   One can notice that rule? is equivalent to ( rule |).
//   To get a else, juste do result:(rule | {else})

// - Separator or Terminator:
// In some cases, a symbol can be used for both (for instance, the ,
// in C enums). The following should work:
//   '{' exp:Expression? exp_list:(';' Expression?)* '}'


//grammar_macro @Replacable
//grammar_expander @''
//grammar_expander @""

