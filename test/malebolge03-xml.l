XML_Node test ()
{
  let String str = "test string";
  let XML_Node node = XML (<fact2>4<foo>toto</foo>$str</fact2>);
  print_xml(node);
  node
}
