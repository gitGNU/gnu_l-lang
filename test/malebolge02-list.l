//typecons Pair(a,b) = struct {a fst; b snd;} *; //Traduit en def typecons Pair (a,b) (struct ('fst' . a) ('snd' . b))

//typecons List(a) = Null | Pair(a, List(a));  //Traduit en def typecons List (a) (| Null (Pair a (List a)))

//Ces typecons sont en fait juste des fonctions typeform->typeform

//D'ailleurs les |, struct, etc des typeforms devraient etre des
//generic comme les autres.

//| est un generic qui prend un nombre quelquonque d'argument et cree
//les fonctions qui vont bien. Le deconstructeur correspondant est match {type1: ... type2: ... default:...}


// Pour le moment:
// 1 Pouvoir creer un type List(Int) (ou List de n'importe quoi)
// 2 Faire des generics car et cdr, qui renvoient des objets du bon type (i.e. car et cdr sont fait mains)
// 3 On aura aussi besoin d'un generic is_list_empty()  Bool<-List


//Des generics pas communs: moi je ense a qqch comme loop, mais qui creererait un 
//nouvel element d'une liste a chaque iteration (dans l'ordre).

//Et des helpers associes, comme make_list_for, make_list_while ...


//Au final, il faudra aussi avoir des parser hooks pour pouvoir rajouter l'operateur ->: a->b = Pair (a,b)

//type Int = int;
//type Int_List = struct { Int head; Int_List tail; } *;
//
//
//Int_List
//cons (Int car, Int_List cdr)
//{
//  struct { Int head; Int_List tail; } ;
//}
//

//type Int = int;
type Int_List = struct { head:Int; 
                         tail:Int_List; } *;

List(Int) test()
{
  //Pour l'instant on peut pas en mettre trop car expand_cons est appelle exponentiellement.
  //  let List(Int) li = list(1);
  //  let List(Int) li = list(1, 2, 3);
  //  let List(Int) li = cons(1, cons(2, cons(3, cons(4, cons(5, cons(6, cons(7, cons(8, cast(List(Int),0)))))))));
  //  let List(Int) li = list(1, 2);
  //  let List(Int) li = cons(2, cons(1, cast(List(Int), 0)));

  let li:List(Int) = list(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
			  14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
			  25, 26, 27, 28, 29, 30, 31, 32, 33);

//  let List(Int) li = cast(List(Int), 0);// = make_int_list (1,2,3);
//
//  li = cons(2,3);
//
//  li = cons(1,
//	    cons(2,
//		 cons(3,
//		      li)));
////
//  let void * pv = alloc_cons_cell();
//
//  let struct { Int car; List(Int) cdr; } * pair = cast(pointer(struct(label(car,Int),
//								      label(cdr, List(Int)))), pv);

  //  (*pair).car = 'toto';
//  (*pair).cdr = li;
//
//  li = cast(List(Int), pair);
//
//  pair = cast(pointer(struct(label(car,Int),
//			     label(cdr, List(Int)))), alloc_cons_cell());
//
//  (*pair).car = 2;
//  (*pair).cdr = li;
//
//  li = cast(List(Int), pair);
//
//
//
  print_int_list(li);

  print( li.head);
  print( li.tail.head);
  li.head = 24;
  print_int_list(li);
  li.tail = cast( List( Int), 0);
  print_int_list( li);

//
					   
  //  li = cons(1, li);

  //  Int *px = malloc(Int);

  //  let List(List(Int)) lli;
  //let Int_List i = cast (Int_List, 0);
  //
  //i
    //    3   
  li
}

