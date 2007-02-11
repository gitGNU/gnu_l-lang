//Tests compilation of functions with arguments, and checks argument
//passing order.

Int sub_two_ints (a:Int, b:Int)
{ a - b }

Int test ()
{
  let i:Int = sub_two_ints (8, 2);
  i
}
 
