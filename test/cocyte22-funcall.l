//Funcall with variable functions.
Int my_test (i:Int, j:Int)
{
  3 * i + j;
}


//Taking address of yet undefined functions does not work for now.
Int test ()
{
//  let fun_ptr: (Int <- (Int, Int)) * = &my_test;
  let fun2 = &my_test;

  let i:Int = funcall (*fun2, 3, 4);
  i
}