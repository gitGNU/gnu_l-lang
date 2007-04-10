//Variable shadowing.
//This is handled by the malebolge; the cocytus does not permit shadowing.

Int test ()
{
  let a = 4;
  {
    let b = a + (let a = 3);
    print( "a: ", a, ", b:", b, "\n");
  }
  a
}
