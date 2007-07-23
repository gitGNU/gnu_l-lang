//Tests loop by computing a factorial iteratively.
function fact(n:Int) -> Int = 
{
  let i:Int = 0;
  let result:Int = 1;
  loop
   { i = i + 1;
     result = result * i;
     if (i >= n)
       break;
   };
  result
};

function trac() -> Void =
{
  {
    let i:Int = 0; 1 };
  1;
};

function test2() -> Void =
{
//
//  {
//  let i:Int = 0;
//  let j:Int = 0;
//
//  outer_loop:
//    loop {
//      i = i + 1;
//
//      loop{
//	j = j + 1;
//	if(j == 10)
//	  {
//	    if (i == 10)
//	      break outer_loop;
//	    break;
//	  }
//      }
//
//      print( "Not reached\n");
//    }
//
//    print( "i: ", i, "j: ", j, "\n");
//  }

  {
  let i:Int = 0;
    loop
      {
	i = i + 1;
	if (i <= 3)
	  continue;
	print( i);
	break;
      };
  };
  
  
  //Expansion of a for (let i = 0, i <= 3, i++) { if (i == 2) continue;}

  {
  let i:Int = 0;
    loop
      {
	
	print (i);
	
	if (i == 2)
	  continue;
	
	//This defines where the continue; statement will jump; 
	//default is the beginning of the loop
	continue:
	  i = i+1;
	//  if (not (i <= 3))
	if (i > 3)
	  break;
      };
  };
};

//Int test ()
function test() -> Int =
{
  //Test continue.
  let i:Int = 0;
  loop
  {
    i = i+1;
    if (i <= 10)
      continue;
    print ("Hello\n");
    break;
  };
  print (i, "\n");

  test2();
  print( "\n");
  
  fact (8) //40320
};
