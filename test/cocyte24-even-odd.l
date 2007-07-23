
function is_even( i:Int) -> Bool = 
{
  if( i == 0) cast( Bool, 1) else is_odd( i - 1)
};

function is_odd( i:Int) -> Bool = 
{
  if( i == 0) cast( Bool, 0) else is_even( i - 1)
};

function test() -> Void = 
{
  if( is_odd( 3))
    print( "3 is odd\n");

  if( not( is_odd( 4)))
    print( "4 is not odd\n");

  if( is_even( 3))
    {
      print( "ERROR");
      exit( 3);
    }
  else print( "3 is not even\n");

  if( is_even( 83344))
    print( "4 is even\n");
};
