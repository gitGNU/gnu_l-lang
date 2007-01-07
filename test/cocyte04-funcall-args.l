//Tests compilation of functions with arguments, and checks argument
//passing order.

Int sub_two_ints (Int a, Int b)
{ a - b }

Int test ()
{
  let Int i = sub_two_ints (8, 2);
  i
}
 
