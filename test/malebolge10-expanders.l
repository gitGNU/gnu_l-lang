expander my_assert( form)
{
  let condition = form.form_list.head;
  Form( if( $condition$ == cast( Bool, 0))
	  {
	    print( "Testing Assertion ");
	    print_form( Form( $condition$));
	    print( " failed, so this worked.\n");
	    //exit( 3)
	  })
}


expander
toto( form)
{
  Form( 3 * $form.form_list.head$ + 1)
}

expander my_log( form)
{
  //Expanders must be defined in-order, so toto has to be defined first.
  let i = toto (25+3);
  Form( print( "logging: ", $Int_Form (i)$, " : ", $@form.form_list$)
	     //exit( 3)
	)
}

Void
test()
{
 foreach (let i in list (1, 0))
  {
    my_assert( i == 0);
  }

 let j = 3;
 my_log( "Testing j = ", j, "\nSeems to work\n");
 
}
