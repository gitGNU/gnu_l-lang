//Test the handling and creation of Forms.
Int test_while (Form condition, Form body)
{
  let Form while_form = Form (
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
  let Form f3 = Form (3 + 4);
  print_form (f3);

  let Form f2 = Form (let Int i = $f3;);
  print_form (f2);

  let Form f = Form (3 + x * 4);

  let List (Form) fl = list (f2, f3);

  let Form test_form_list = Form ({let Int i = 3;
                                    {$f; $@fl};
				    i = 4;
				    $@list (f3, f2); });
  print_form (test_form_list);

  test_while (Form (i >= 0),
  	      Form (i = i - 1;));

  4
}
