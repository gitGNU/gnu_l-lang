// These macros are good examples on how to use the parse language to
// parse standard patterns, but they are useful in real too.

//XXX: tester aver des $ aussi.
grammar_macro @Left_Infix_Operator<operators, subrule, this_rule> = 
  form:subrule
  (id:operators form2:subrule form:{Compound_Form( id,
						   list( form,
							 form2))})*
  {form};

//Would be better with a type for null which would coerce into anything;
//for now we can return only list of forms.
grammar_macro @Separator<separator, rule> =
  arg_list:{cast( List( Form), 0)}
  ( arg1:rule
    arg_list:(separator arg:rule {make( arg)})*
    arg_list:{cons( arg1, arg_list)} )?
  {arg_list};

grammar_macro @Right_Infix_Operator< operators, subrule, this_rule> =
  form:subrule
  (id:operators form2:this_rule
   form:{Compound_Form( id, list( form, form2))})?
{form};


grammar_macro @Unary_Prefix_Operator< operators, subrule, this_rule> =
  ( op:operators form:this_rule {Compound_Form( op, list( form))}
  | form:subrule);


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

