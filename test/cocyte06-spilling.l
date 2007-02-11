//Tests spilling of temporary values.
Int test ()
{
  let i:Int = 4;
  let j:Int = 5;

  let truc:Symbol = 'test';

  let c:Int = 3;
  
   1 + j;
   1 + j;

   c = (1 + i) + ((1 + i) + ((1 + i) + ((1 + i) + j)));

   c
}
