
Void
test ()
{
  if (!(3 == 2 || 4 == 2))
    print ("or: OK\n");

  if(!(3 == 3 && 4 == 2))
    print( "and: OK\n");
  
  if(cast( Bool, 1))
    print( "Hello normal\n");
  
  if(!cast( Bool, 0))
    print( "Hello\n");

  let t1 = (3 == 2 || 3 == 3);
  let t2 = (3 == 3 || 3 == 2);
  let t3 = (3 == 3 || 2 == 2);
  let f4 = (3 == 2 || 2 == 3);
  
  let f5 = (3 == 2 && 3 == 3);
  let f6 = (3 == 3 && 3 == 2);
  let t7 = (3 == 3 && 2 == 2);
  let f8 = (3 == 2 && 2 == 3);

  let t9 = !(3 > 4);

  let t10 = (3 == 4 || 5 == 5  && 6 == 6 || 7 == 8);

  let f11 = !cast( Bool, 3);
  
  print( " t1: ", cast( Int, t1),
	 " t2: ", cast( Int, t2),
	 " t3: ", cast( Int, t3),
	 " f4: ", cast( Int, f4),
	 " f5: ", cast( Int, f5),
	 " f6: ", cast( Int, f6),
	 " t7: ", cast( Int, t7),
	 " f8: ", cast( Int, f8),
	 " t9: ", cast( Int, t9),
	 " t10: ", cast( Int, t10),
	 " f11: ", cast( Int, f11),
	 "\n");
  ();
  let l = &&toto;
  goto(*l);

  print( "Not printed\n");
  exit( 3);
  
 toto:
  print( "After toto\n");

  //let b = !cast( Bool, 3);
  
}
