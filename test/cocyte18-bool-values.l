//Test booleans are correct values.

Bool
function (Int i)
{
  i <= 4
}

//Ensures that print is really void.
Void
void_function (String message)
{
  cast (Void, print (message))
}


Bool
test ()
{
  let Int i = 4;
  print (cast (Int, i < 3));
  print (cast (Int, i > 3));

  //Test void locations (non-)unification.
  if (function (5))
   void_function ("Weird, 5 <= 4")
  else void_function ("OK, 5 > 4");

  i <= 4
}