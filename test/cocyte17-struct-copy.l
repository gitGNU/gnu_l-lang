Int test ()
{
  //Use of a compound literal.
  let struct { Int x; Int y; } p = struct(x:3, y:4);

  print ("p.x", p.x, "p.y", p.y);
  
  let struct { Int x; Int y; } q;

  q = p;

  print ("q.x", q.x, "q.y", q.y);

  let struct { Int x; Int y;} r;
  let struct { Int x; Int y;} * pr = &r;

  *pr = q;

  print ("r.x", r.x, "r.y", r.y);

  let struct { Int x; Int y;} s;
  
  s = *pr;

  print ("s.x", s.x, "s.y", s.y);

  let struct { Int i; struct { Int x; Int y; } p; Int j;} t;

  t.p = s;

  print ("t.p.x", t.p.x, "t.p.y", t.p.y);

  let struct { Int x; Int y;} u;

  u = t.p;

  print ("u.x", u.x, "u.y", u.y);
  
  q.y
}
