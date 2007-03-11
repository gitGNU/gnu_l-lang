//You can test this function with strace to see when write()s are done.
Int test ()
{
  //By default, output is unbuffered. Contrary to C, the following is sent
  //even without a trailing \n.
  print ("Hello, world!");

  //When output is unbuffered, the output is sent at the end of the print
  //sequence.  Here, only one write syscall is needed.
  print ("The result of 3+3 is : ", 3+3,
	 "\nand the result of 3*3 is : ", 3*3, "\n");

  //To bufferize, use the buffered keyword.  It accumulates results in
  //a buffer, and send it when it wants, or explicit flush.
  buffered {
    print ("This is not sent right now.");
    print ("\n Neither is this \n");
  }

  //Back to unbuffered output, all the previously accumulated buffer
  //is flushed:
  print ("Now everything appear on the screen\n");

  //You can also explicitly flush the output:
  buffered print ("Buffered string\n");
  flush ();

  //You can also switch back to unbuffered output in a buffered
  //output:
  buffered {
    print ("This is buffered\n");
    unbuffered {
      print ("This is unbuffered\n");
      print ("This also.\n");
    }
    print ("Back to buffered\n");
  }

  //Test some formatters.
  print ("Toto\n", 25:hex, "\n", 25, "\n", 25:dec, "\n");
  (2)
}
