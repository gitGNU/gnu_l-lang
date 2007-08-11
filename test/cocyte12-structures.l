//Test declaration and usage of structure
function test () -> Int = 
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
  print (point.x + point.y, "\n"); //58
  point.y;

  let t:struct { i:Int; p:struct { x:Int; y:Int; }; j:Int;};

  t.i = 3;

  t.p.x = 4;
  t.p.x
};
