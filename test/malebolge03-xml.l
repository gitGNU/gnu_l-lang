//XML_Node test ()
function test () -> XML_Node =
{
  let str:String = "test string";
  let node:XML_Node = XML (<fact2>4<$str$><foo>toto</foo>to<$1; "toto"$>ta$str$tu</fact2>);
  print_xml(node);
  node
};
