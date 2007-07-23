type Point = struct { x:Int;
                      y:Int; } *;

function test () -> Int =
{
  let i:Int;
  i = 3;

  let j = 4;
  i + j;

  print( 3 + (let k = 6));
  k;

  let p = Point( x:2, y:let u = 5);
  print( "P:", p.x, p.y);

  if( u != 5)
    print( "Error\n");

  let s = struct( x:3, y:4);

  s.x + s.y
};
