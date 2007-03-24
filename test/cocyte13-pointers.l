//Test usage of pointers
Int
test ()
{
  let x:Int = 3;
  let px:Int * = &x;

  let y:Int = *px;
  print (*px, "\n");
  //let int y = *px;

  *px = 4;
  x + y
}
