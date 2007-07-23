// Variable shadowing.
// This is handled by the malebolge; the cocytus does not permit shadowing.
// Even in malebolge, such a bad practice should be discouraged
// maybe even enabled only on request by the programmer.
function test () -> Int =
{
  let a = 4;
  {
    let b = a + (let a = 3);
    print( "a: ", a, ", b:", b, "\n");
  };
  a
};
