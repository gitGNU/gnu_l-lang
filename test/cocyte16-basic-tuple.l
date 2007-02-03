//Basic tuple support.
Int test ()
{
  let Int a;
  let Int b;
  let Int c;
  let Int d;
  let Int e;
  let Int f;
  let Int g;

  let struct { Int x; Int y; } p;
  
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
}

