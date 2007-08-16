/* Automatically generated : do not edit!*/
#include "expand-loop.aux.inc"
Form__type  while_sharp__sharp_expander_function(Compound_Form__type  _sharp_form317)
{
return ({
Form__type body;
Form__type condition;
(condition = ((Form__type ) (expand)(((* ((struct struct0x0805efd0 *) ((* ((struct struct0x0805ee20 *) _sharp_form317)).form_list))).head))));
(body = ((* ((struct struct0x0805efd0 *) ((* ((struct struct0x0805efd0 *) ((* ((struct struct0x0805ee20 *) _sharp_form317)).form_list))).tail))).head));
(Compound_Form)(intern( "loop"), ({
struct struct0x080b27b8 *_sharp_pair_328;
({_sharp_pair_328;
(_sharp_pair_328 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_328).car) = (Compound_Form)(intern( "@block"), ({
struct struct0x080b27b8 *_sharp_pair_327;
({_sharp_pair_327;
(_sharp_pair_327 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_327).car) = (Compound_Form)(intern( "@seq"), ({
struct struct0x080b27b8 *_sharp_pair_326;
({_sharp_pair_326;
(_sharp_pair_326 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_326).car) = (Compound_Form)(intern( "if"), ({
struct struct0x080b27b8 *_sharp_pair_323;
({_sharp_pair_323;
(_sharp_pair_323 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_323).car) = (Compound_Form)(intern( "=="), ({
struct struct0x080b27b8 *_sharp_pair_321;
({_sharp_pair_321;
(_sharp_pair_321 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_321).car) = condition);
(((* _sharp_pair_321).cdr) = ({
struct struct0x080b27b8 *_sharp_pair_320;
({_sharp_pair_320;
(_sharp_pair_320 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_320).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080b27b8 *_sharp_pair_319;
({_sharp_pair_319;
(_sharp_pair_319 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_319).car) = (Id_Form)(intern( "Bool")));
(((* _sharp_pair_319).cdr) = ({
struct struct0x080b27b8 *_sharp_pair_318;
({_sharp_pair_318;
(_sharp_pair_318 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_318).car) = (Int_Form)(0));
(((* _sharp_pair_318).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_318);
})
);
((List__O__Form__C____type__type ) _sharp_pair_319);
})
));
(((* _sharp_pair_320).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_320);
})
);
((List__O__Form__C____type__type ) _sharp_pair_321);
})
));
(((* _sharp_pair_323).cdr) = ({
struct struct0x080b27b8 *_sharp_pair_322;
({_sharp_pair_322;
(_sharp_pair_322 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_322).car) = (Compound_Form)(intern( "break"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_322).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_322);
})
);
((List__O__Form__C____type__type ) _sharp_pair_323);
})
));
(((* _sharp_pair_326).cdr) = ({
struct struct0x080b27b8 *_sharp_pair_325;
({_sharp_pair_325;
(_sharp_pair_325 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_325).car) = body);
(((* _sharp_pair_325).cdr) = ({
struct struct0x080b27b8 *_sharp_pair_324;
({_sharp_pair_324;
(_sharp_pair_324 = ((struct struct0x080b27b8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_324).car) = (Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_324).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_324);
})
);
((List__O__Form__C____type__type ) _sharp_pair_325);
})
);
((List__O__Form__C____type__type ) _sharp_pair_326);
})
));
(((* _sharp_pair_327).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_327);
})
));
(((* _sharp_pair_328).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_328);
})
);
})
;}
