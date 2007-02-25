//Test definition of new types
//This creates a new type, Index, which is like an int, but cannot be
//interverted with an int.  To create an index, you have to do : let i = Index(24);
type Index = Int;

//Integer is just an alias for Int; they are the same type.
type_alias Integer = Int;

// Thus let i:Int = 3 is correct.

//define int i = 3;

Index correct (n:Int)
{ let i:Index; // = Index(23);
  i }

//Index incorrect (int n)
//{
//  let Index i = 23;
//  i
//}

//int incorrect2 (int n)
//{
//  let int i = 23;
//  let Index j = i;
//  i
//}

//Index incorrect3 (int n)
//{
//  let int i = 3;
//  i
//}

//int incorrect4 (int n)
//{
//  let Index i;
//  i
//}


//int incorrect5 ()
//{
//  let int i;
//  let Index j;
//  let int a = if(1) i else j;
//  a
//}

//int incorrect6 ()
//{
//  let int t = 3 == 2;
//  t
//}

Int square (n:Integer)
{
  n * n
}


Int test ()
{
  let i:Int = 8;
  let p:Int = square (i);
  p
}

//int test ()
//{
//  let int i = 3 + 3;
//  i
//}



//Note the *.  It is important.  Maybe we will have a shortcut for
//struct {...} * for newcomers; like record.
type Point = struct
	     { x:Int;
	       y:Int; } *;



//Point
//add_point (a:Point, b:Point)
//{
//  let Point c = Point(); /* Just allocates a Point.  */
//  c.x = a.x + b.x; /* We don't differenciate -> and . */
//  c.y = a.y + b.y;
//  c
//}


//the future.
//int test (int n)
//{
//  let Point a = Point (x:3, y:5);
//  let b = Point (x:4, y:2);
//
//  let d = add_point (a,b);
//
//  print (d);
//  print (d.x);  /* We don't differenciate -> and .  */
//}


