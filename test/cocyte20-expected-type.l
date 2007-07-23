//Test correct discard of unwanted results.
function test () -> Int =
{
  let i:Int = 0;

  &i;  //Void expecetd type.
  //*i;  //Sshould throw an error.

  let pi:Int * = &i;

  *pi; //Void expected type.

  3
};
