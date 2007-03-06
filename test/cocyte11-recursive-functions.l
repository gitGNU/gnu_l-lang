// Recursive factorial with a if-statement
Int fact2 (n:Int)
{
  let a:Int; 
  if( n == 0)
    a = 1;
  else
    a = n * fact2( n - 1);
  a
}

//Recursive factorial with a if expression
Int fact (n:Int)
{
  if (n > 1) 
    n * fact (n - 1)
  else 1
}

Int test ()
{
  fact (8);
  fact2 (8)
}


//We should test when test calls fact3, and fact3 is defined below.
//But this won't work until we can patch access to global variables.
