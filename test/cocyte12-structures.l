//Test declaration and usage of structure
int test ()
{
  let Int n = 3;
  let struct { Int x; Int y; } point;
  let Int i = n;

  point.x = 29;
  n = point.x;
  let Int a = point.x;
  point.y = point.x;

  point.x = n;
  point.y = n;
  test_function (point.x + point.y) //58
}
