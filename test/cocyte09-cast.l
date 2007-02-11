//Tests unconditional if, and cast expressions.
Int test ()
{
  let c:Int = 3;
  if (cast (Bool, 1))
    c = 2;
  c
}
