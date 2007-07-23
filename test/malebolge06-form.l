//Test the handling and creation of Forms.

function test_while (condition:Form, body:Form) -> Int = 
{
  let while_form:Form = Form (
     loop {
       if( not( $condition$))
	 break;
       $body$;
     }
			      );

  print_form (while_form)
};


function test () -> Int =
{
  let f3:Form = Form( 3 + 4);
  print_form (f3);

  let f2:Form = Form( let i:Int = $f3$);
  print_form (f2);

  let f:Form = Form( 3 + x * 4);

  let fl:List<Form> = list (f2, f3);

  let test_form_list:Form = Form({let i:Int = 3;
                                    {$f$; $@fl$};
				    i = 4;
				    $@list (f3, f2)$ });
  print_form (test_form_list);

  test_while (Form( i >= 0),
  	      Form( i = i - 1));

  4
};

//(define function test (lambda Int (tuple)
//                (block (= (let f3 Form)
//                          (Form (+ 3 4)))
//                       (print_form f3)
//                       (= (let f2 Form)
//                          (Form (= (let i Int)
//                                   ($ f3))))
//                       (print_form f2)
//                       (= (let f Form)
//                          (Form (+ 3 (* x 4))))
//                       (= (let fl (List Form))
//                          (list f2 f3))
//                       (= (let test_form_list Form)
//                          (Form (block (= (let i Int)
//                                          3)
//                                       (block ($ f)
//                                              ($@ fl))
//                                       (= i 4)
//                                       ($@ (list f3 f2)))))
//                       (print_form test_form_list)
//                       (test_while (Form (>= i 0))
//                                   (Form (= i (- i 1))))
//                       4)))
