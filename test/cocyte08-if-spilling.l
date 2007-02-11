//Tests spilling in different branches of an if.
Int test ()
{
  let i:Int = 4;
  let j:Int = 5;

  let c:Int = 3;
  
   1 + j;
   1 + j;
  
   c = ((1 + i) + ((1 + i) + ((if(i == 4) (i + 1) + j  else 3) + j)));
   c
}
