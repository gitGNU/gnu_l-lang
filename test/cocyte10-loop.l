//Tests loop by computing a factorial iteratively.
Int fact (Int n)
{
  let Int i = 0;
  let Int result = 1;
  loop
   { i = i + 1;
     result = result * i;
     if (i >= n)
       break;
   }
  result
}


Int test ()
{
  fact (8) //40320
}
