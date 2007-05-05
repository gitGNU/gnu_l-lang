
Bool
is_even( i:Int)
{
  if( i == 0) cast( Bool, 1) else is_odd( i - 1)
}

Bool
is_odd( i:Int)
{
  if(i == 0) cast( Bool, 0) else is_even( i - 1)
}

Void
test()
{
  if(is_odd( 3))
    print( "3 is odd\n");

  if(!is_odd( 4))
    print( "4 is not odd\n");

  if(is_even( 3))
    {
      print( "ERROR");
      exit( 3);
    }
  else print( "3 is not even\n");

  if(is_even( 83344))
    print( "4 is even\n");
}
