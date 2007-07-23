//Tests compilation of functions with arguments, and checks argument
//passing order.

function sub_two_ints (a:Int, b:Int) -> Int =
{ a - b };

function test () -> Int =
{
  let i:Int = sub_two_ints (8, 2);
  i
};
 
