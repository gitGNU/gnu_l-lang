//Funcall with variable functions.
function my_test (i:Int, j:Int) -> Int = 
{
  print( "In my_test\n");
  3 * i + j
};


//Taking address of yet undefined functions does not work for now.
function test () -> Int =
{
//  let fun_ptr: (Int <- (Int, Int)) * = &my_test;
  let fun2 = &my_test;

  let i:Int = funcall (*fun2, 3, 4);
  i
};
