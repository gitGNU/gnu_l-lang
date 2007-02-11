//Tests inner blocks as expressions; multiple variables at the same
//stack location.
Int test ()
{
  let c:Int = { let a:Int = 3;
		let b:Int = 4;
		a + b};

  let d:Int = { let e:Int = c + c;
  		e };
  1 - d // doit renvoyer -13
}
