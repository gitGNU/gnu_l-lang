//Test hashing.
Int test ()
{
  let Hash (Symbol, Int) table = Hash (Symbol, Int);

  //Test affectations.  Test that it returns the affected value.  
  table.foo = table.bar = 8;
  if(table.foo == table.bar)
    print ("Double affectation succeed: OK\n");

  //Syntax check
  if(table.foo == table['foo'])
    print ("Both syntax are the same : OK\n");

  let struct { Hash (Symbol, Int) h; } s;
  s.h = table;

  if(s.h.foo == s.h['bar'])
    print ("Works inside a struct : OK\n");

  let Hash (Int, Int) hash_int = Hash (Int, Int);
  hash_int[3] = 25;
  hash_int[3]
    
}
