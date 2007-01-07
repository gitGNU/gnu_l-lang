//Tests spilling of temporary values.
Int test ()
{
  let Int i = 4;
  let Int j = 5;

  let Symbol truc = 'test';

  let Int c = 3;
  
   1 + j;
   1 + j;

   c = (1 + i) + ((1 + i) + ((1 + i) + ((1 + i) + j)));

   c
}
