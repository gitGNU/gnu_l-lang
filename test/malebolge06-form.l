//Test the handling and creation of Forms.
Int test_while (condition:Form, body:Form)
{
  let while_form:Form = Form (
     loop {
       if(!($condition))
	 break;
       $body;
     }
			      );

  print_form (while_form)
}

Int test ()
{
  let f3:Form = Form( 3 + 4);
  print_form (f3);

  let f2:Form = Form( let i:Int = $f3;);
  print_form (f2);

  let f:Form = Form( 3 + x * 4);

  let fl:List(Form) = list (f2, f3);

  let test_form_list:Form = Form({let i:Int = 3;
                                    {$f; $@fl};
				    i = 4;
				    $@list (f3, f2); });
  print_form (test_form_list);

  test_while (Form( i >= 0),
  	      Form( i = i - 1;));

  4
}
