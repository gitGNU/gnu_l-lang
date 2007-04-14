// Label testing. The thing to note regarding L labels is that
// Labels's scope is the block where they are defined, not the whole function.
// This means that you cannot call goto outside of an enclosing scope, unlike in C.
// But you can have different scopes with the same label name, and they won't be
// in conflict.
// This also means that a label in an inside scope can "shadow" a label in
// an outside scope; but you can have only one label of the same name in one scope.

//Backward labels.
Int
test1()
{
 let i:Int = 24;

 toto:
  
  i = i - 1;

  print( i, " ");

  //Simple gotos
  if(i == 23)
    goto (toto);

  // Computed gotos, using GNU C's syntax.
  let l:Label * = &&toto;
  if(i == 22)
    goto (*l);
  
  i
}

//Forward Labels
Int
test2()
{
 let i:Int = 24;

  {
    //A forward computed goto, that goes beyond its scope.
  let l:Label * = &&toto;
    
    if(i == 24)
      goto( *l);
  }

  i = i - 1;

  //And a regular goto.  Both must be patched to the same target.
  if( i == 24)
    goto(toto);
    
 toto:
  print( i, " ");

  i
}


//Labels and scopes
//As the labels are in two different scopes, it is legal that
//they have the same name
Void
test3()
{
  {
    goto(toto);

  toto:;
  }

  print( "Control is here\n");
  
  {//Warning: this is not yet handled by the GNU C outputter.
    goto(toto);

    toto:;
  }

  print( "Control is there\n");

}


//Labels and scopes 2: this is forbidden
//Void
//test4()
//{
//  print( "Control is here\n");
//  
//  goto(toto);
//
// toto:
//  print( "Control is there\n");
//
//  {
//    //Label shadowing.
//    goto(toto);
//      toto:;
//  }
//  print( "Control is out there\n");
//}




Void
test()
{
  test1();
  test2();
  test3();
}
