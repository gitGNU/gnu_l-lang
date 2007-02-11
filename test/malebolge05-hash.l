//Test hashing.
Int test ()
{
  let table:Hash( Symbol, Int) = Hash( Symbol, Int);

  //Test affectations.  Test that it returns the affected value.  
  table.foo = table.bar = 8;
  if(table.foo == table.bar)
    print ("Double affectation succeed: OK\n");

  //Syntax check
  if(table.foo == table['foo'])
    print ("Both syntax are the same : OK\n");

  let s:struct { h:Hash( Symbol, Int); };
  s.h = table;

  if(s.h.foo == s.h['bar'])
    print ("Works inside a struct : OK\n");

  //Test for another key type.
  let hash_int:Hash( Int, Int) = Hash( Int, Int);
  hash_int[3] = 25;
  hash_int[3];


  //Test Hashstrings.
  
  let stable:Hash_String( Int) = Hash_String( Int);
  
  let i:Int;
  
  i = stable["toto"];
  stable["tata"] = stable["toto"] = 3;
  stable["tata"]
    
}
