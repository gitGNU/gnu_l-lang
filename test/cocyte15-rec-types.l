//typealias Int = int;
//type Int = int;


type Int_List = struct
		{ Int head;
		  Int_List tail; } *;
  
//Note that the position of the pointer has changed.
type Int_List2 = struct
		 { Int head;
		   Int_List2 *tail; }*;


//doubly-recursive types. Don't work for now.
//type Toto = struct
//	    { Int o;
//	      Tata b; }*;
////
//type Tata = struct
//	    { Int a;
//	      Toto b; } *;
//  
//Not recursive type. Do not work yet.
//type Notrec = struct
//	      { Int i;
//		Sub_Notrec j; };
//
//type Sub_Notrec = struct
//		  { Int x;
//		    Int y; };
//		

Int
test ()
{
  let struct { Int head; Int_List tail; }* i;
  let Int_List b;

  if((*i).tail == b) 0 else 1

//  let struct { Int o; Tata b; }* o;
//  //  let Toto o;
//  let Tata a;
//  
//  if((*o).b == a) 0 else 1
  //  if((*a).b == o) 0 else 1

}
