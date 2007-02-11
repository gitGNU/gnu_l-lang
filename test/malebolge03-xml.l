XML_Node test ()
{
  let str:String = "test string";
  let node:XML_Node = XML (<fact2>4<foo>toto</foo>$str</fact2>);
  print_xml(node);
  node
}
