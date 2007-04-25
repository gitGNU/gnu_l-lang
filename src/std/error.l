expander print_error( form)
{
  Form( {let save_od_ = current_output_descriptor;
         current_output_descriptor = stderr_output_descriptor;
	 print( $@form.form_list$);
	 flush();
         current_output_descriptor = save_od_; ()
	 })
}

//XXX: temporary, because Form( condition) is really expansive.
macro assert( condition) = 
  if( condition == cast( Bool, 0))
    {
      print_error( "Assertion ");
      print_form( Form( condition));
      print_error( " failed\n");
      exit( 2)
    };

expander panic( form)
{
  Form({print_error( "Panic : ", $@form.form_list$);
      exit( 3)})
}


Void
test ()
{
  print_error ("Hello\n");
  assert( 0 == 1);

}
