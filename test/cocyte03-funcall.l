//This tests multiple function definition, and calling of a simple function without arguments.

function toto() -> Int = {3};

function test() -> Int = 
{
  let i:Int = toto();
  i
};
