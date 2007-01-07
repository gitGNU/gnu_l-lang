//Tests inner blocks as expressions; multiple variables at the same
//stack location.
Int test ()
{
  let Int c = { let Int a = 3;
		let Int b = 4;
		a + b};

  let Int d = { let Int e = c + c;
  		e };
  1 - d // doit renvoyer -13
}
