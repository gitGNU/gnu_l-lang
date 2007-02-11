//Test declaration and usage of structure
Int test ()
{
  let n:Int = 3;
  let point:struct { x:Int; y:Int; };
  let i:Int = n;

  point.x = 29;
  n = point.x;
  let a:Int = point.x;
  point.y = point.x;

  point.x = n;
  point.y = n;
  test_function (point.x + point.y) //58
}
