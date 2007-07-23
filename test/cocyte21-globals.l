
global i:Int;

function test2 () -> Int =
{
  i = 8;
  2
};

function test () -> Int = 
{
 i = 3;
 j = 4;
 test2 ();
 i + 2 + j
};

//Globals defined after do work now.
global j:Int;
