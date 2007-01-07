// Recursive factorial with a if-statement
Int fact2 (Int n)
{
  let Int a; 
  if( n == 0)
    a = 1;
  else
    a = n * fact2( n - 1);
  a
}

//Recursive factorial with a if expression
Int fact (Int n)
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