//Test usage of pointers
Int
test ()
{
  let Int x = 3;
  let Int *px = &x;

  let Int y = *px;
  test_function (*px);
  //let int y = *px;

  *px = 4;
  x + y
}
