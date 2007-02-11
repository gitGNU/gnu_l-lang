//Tests loop by computing a factorial iteratively.
Int fact (n:Int)
{
  let i:Int = 0;
  let result:Int = 1;
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
