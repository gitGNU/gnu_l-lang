//Test usage of pointers
Int
test ()
{
  let x:Int = 3;
  let px:Int * = &x;

  let y:Int = *px;
  test_function (*px);
  //let int y = *px;

  *px = 4;
  x + y
}
