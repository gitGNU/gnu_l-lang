//Automatic access to pointer structures.  I.e, transforms point.x into (*point).x
Int
test ()
{
  let the_point:struct {x:Int; y:Int;};

  the_point.x = 3;
  the_point.y = 4;

  let point:struct {x:Int; y:Int;} * = &the_point;

  if(point.x != (*point).x)
    test_function(point.y);

  point.y = 5;
  point.x + point.y
}
