//Basic tuple support.
function test() -> Int =
{
  let a:Int;
  let b:Int;
  let c:Int;
  let d:Int;
  let e:Int;
  let f:Int;
  let g:Int;

  let p:struct { x:Int; y:Int; };
  
  (a, b) = (3, 2);

  print ("a: ", a, "\nb: ", b, "\n");

  (a, b) = (b, a);

  print ("a: ", a, "\nb: ", b, "\n");

  (p.x, p.y) = (a, b);

  print ("p.x: ", p.x, "\np.y: ", p.y, "\n");

  (p.y, p.x) = (p.x, p.y);

  print ("p.x: ", p.x, "\np.y: ", p.y, "\n");
  
  (a, b, c, d, e, f, g) = (1, 2, 3, 4, 5, 6, 7);
  print (a, b, c, d, e, f, g);

  2
};

