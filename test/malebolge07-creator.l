//Test creators
type Index = Int;
type Point = struct { x:Int; y:Int;};
type Int_Ptr = Int *;
type Index2 = Index;
type Point_Ptr = struct { x:Int; y:Int;} *;
type Potato = Index *;
type Potato_Ptr = Index **;

function test() -> Index = 
{
  //Test basic creators.
  let i:Int = Int( 3);
  let s:String = String( "toto");

  //Test derived creators.
  let id:Index = Index( 3);
  let id2:Index2 = Index2( Index( 4));
  let p:Point = Point( x:3, y:4);

  //Test automatic allocation of pointers.
  let ip2:Int_Ptr = Int_Ptr( 7);
  let pp:Point_Ptr = Point_Ptr( x:24, y:43);
  print( "pp.x:", pp.x, "pp.y:", pp.y);

  //Test explicit allocation.
  let ip:Int_Ptr = Int_Ptr( alloc:auto, 3);
  let pp2:Point_Ptr = Point_Ptr( alloc:malloc, x:24, y:43);
  print( "pp2.x:", pp2.x, "pp2.y:", pp2.y);

  //Dereferencing a derived type does not work for now.
  print( "Ip pointe sur:", *( cast( Int *,
				    ip)));
  print( "Ip2 pointe sur:", *( cast( pointer<Int>,
				     ip2)));

  let p2:Potato = Potato( Index( 8));

  //Test multiple pointers allocation.
  let p_ptr:Potato_Ptr = Potato_Ptr( alloc:malloc, alloc:auto, Index( 9));
  print( "p_ptr pointe sur:", **( cast( pointer<pointer<Int>>,
					p_ptr)));

  Index( p.x + p.y)
};
