type Flower = Int;
type Rose = Int;
type Lys = Int;

// Defines Rose as a (nominal)subtype of Flower.  This mean that every value
// of type Rose is also of type Flower (the contrary is untrue).
// Normally you should declare a subtyping relationship between two types only
// if the first is structurally a subtype of the second. This condition may be
// checked in the future.
subtype Rose < Flower;

// Another subtype. a Lys can't be used instead of a Rose, though.
subtype Lys < Flower;


function test () -> Rose =
//function test () -> Flower =
//function test () -> Lys =
{
  let a = Int(3);
  a;
  let f = Flower( 4);
  f;
  let r = Rose( 5);
  
  //  r  = f; // Should not work
  // f = r; // Should work.
  r
};
