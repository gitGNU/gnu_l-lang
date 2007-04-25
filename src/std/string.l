macro with_output_to_string(body) =
{
  let od_ = make_string_output_descriptor();
  let save_od_ = current_output_descriptor;
  current_output_descriptor = od_;
  body;
  let str_:String = string_output_descriptor_to_string (od_);
  current_output_descriptor = save_od_;
  str_
};

Void
toto()
{
  print( "Test3\n");
}

//Teste l'output to string; a commiter quand on aura rajoute un joli "with_output_to_string { ... }"
Int test ()
{
///  with_open_file (write:"toto.txt")
///    {
///       print ("Hello toto\n");
///    }
/// print ("Done\n");
//  let od = make_string_output_descriptor();
//  let save_od = current_output_descriptor;
//  current_output_descriptor = od;
//  print( "Test1");
//  print( "Test2");
//  let str:String = string_output_descriptor_to_string (od);
//  current_output_descriptor = save_od;
//  print (str);
//  3

 let s:String = with_output_to_string({ print( "Test1\n");
     print( "Test2\n");
     toto() });

  print( "s: |", s, "|\n");
  //let String = with_output_to_string { ... }
  3
}
