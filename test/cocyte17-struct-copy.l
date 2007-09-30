function test() -> Int =
{
  //Use of a compound literal.
  let p:struct { x:Int; y:Int; } = struct(x:3, y:4);

  print ("p.x", p.x, "p.y", p.y);
  
  let q:struct { x:Int; y:Int; };

  q = p;

  print ("q.x", q.x, "q.y", q.y);

  let r:struct { x:Int; y:Int;};
  let pr:struct { x:Int; y:Int;} * = &r;

  *pr = q;

  print ("r.x", r.x, "r.y", r.y);

  let s:struct { x:Int; y:Int;};
  
  s = *pr;

  print ("s.x", s.x, "s.y", s.y);

  let t:struct { i:Int; p:struct { x:Int; y:Int; }; j:Int;};

  t.p = s;

  print ("t.p.x", t.p.x, "t.p.y", t.p.y);

  let u:struct { x:Int; y:Int;};

  u = t.p;

  print ("u.x", u.x, "u.y", u.y);

  print ("v.x", struct (x:3,y:4).x,
	 "v.y", struct (x:3,y:4).y);

  let w = struct (a:3, b:struct (x:4, y:5));
  w.b.y
};
