type Test_Type = struct { key:Int;
                          name:String;} *;

function test () -> Int = 
{
  let li = list( 1, 2, 3);
  foreach( let a in li)
    print( "A: ", a);

  //a does not exist here.
  print( "\n");

  let ls = list ("toto", "tata", "tutu");
  let s:String;

  foreach( s in ls)
    print( s, "\n");

  //s is now the last element of the list.
  print( "One more: ", s, "\n");

  let lt = list( Test_Type( key:3, name:"trois"),
		 Test_Type( key:1, name: "un"),
		 Test_Type( key:2, name: "deux"));

  //You can use regular break; and continue; statements.  */
  let t:Test_Type;
  foreach( t in lt)
    {
      if(t.key == 3)
	continue
      else if(t.key == 1)
	break;
    };

  // t is still accessible at the end of the loop.
  print( "T.name: ", t.name, "\n");
		 
  
  3
};
