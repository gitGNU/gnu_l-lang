//Automatic access to pointer structures.  I.e, transforms point.x into (*point).x
Int
test ()
{
  let struct {Int x; Int y;} the_point;

  the_point.x = 3;
  the_point.y = 4;

  let struct {Int x; Int y;} *point = &the_point;

  if(point.x != (*point).x)
    test_function(point.y);

  point.y = 5;
  point.x + point.y
}
