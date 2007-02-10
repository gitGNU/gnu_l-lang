//Test creators
type Index = Int;
type Point = struct { Int x; Int y;};
type Int_Ptr = Int *;
type Index2 = Index;
type Point_Ptr = struct { Int x; Int y;} *;
type Potato = Index *;
type Potato_Ptr = Index **;

Index test()
{
  //Test basic creators.
  let Int i = Int( 3);
  let String s = String( "toto");

  //Test derived creators.
  let Index id = Index( 3);
  let Index2 id2 = Index2( Index( 4));
  let Point p = Point( x:3, y:4);

  //Test automatic allocation of pointers.
  let Int_Ptr ip2 = Int_Ptr( 7);
  let Point_Ptr pp = Point_Ptr( x:24, y:43);
  print( "pp.x:", pp.x, "pp.y:", pp.y);

  //Test explicit allocation.
  let Int_Ptr ip = Int_Ptr( alloc:auto, 3);
  let Point_Ptr pp2 = Point_Ptr( alloc:malloc, x:24, y:43);
  print( "pp2.x:", pp2.x, "pp2.y:", pp2.y);

  //Dereferencing a derived type does not work for now.
  print( "Ip pointe sur:", *( cast( pointer( Int),
				    ip)));
  print( "Ip2 pointe sur:", *( cast( pointer( Int),
				     ip2)));

  let Potato p2 = Potato( Index( 8));

  //Test multiple pointers allocation.
  let Potato_Ptr p_ptr = Potato_Ptr( alloc:malloc, alloc:auto, Index( 9));
  print( "p_ptr pointe sur:", **( cast( pointer( pointer( Int)),
					p_ptr)));

  Index( p.x + p.y)
}
