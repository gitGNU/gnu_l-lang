/* Automatically generated : do not edit!*/
#include "make-list.inc"
List__O__List_Maker_Element__C____type__type make_list_list;

void  test(void)
{
return ({
void **_sharp_make_list_ptr399;
void **_sharp_make_list_ptr417;
List__O__Int__C____type__type newlist;
List__O__Symbol__C____type__type list;
(newlist = ({
List__O__Int__C____type__type _sharp_make_list398;
_sharp_make_list398,
_sharp_make_list_ptr399,
(_sharp_make_list_ptr399 = ((void *) (&_sharp_make_list398))),
({
({
List__O__Int__C____type__type _sharp_iterator405;
(_sharp_iterator405 = ({
struct struct0x08504cc8 *_sharp_pair_404;
_sharp_pair_404,
(_sharp_pair_404 = ((struct struct0x08504cc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_404).car) = 1);
(((* _sharp_pair_404).cdr) = ({
struct struct0x08504cc8 *_sharp_pair_403;
_sharp_pair_403,
(_sharp_pair_403 = ((struct struct0x08504cc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_403).car) = 2);
(((* _sharp_pair_403).cdr) = ({
struct struct0x08504cc8 *_sharp_pair_402;
_sharp_pair_402,
(_sharp_pair_402 = ((struct struct0x08504cc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_402).car) = 3);
(((* _sharp_pair_402).cdr) = ({
struct struct0x08504cc8 *_sharp_pair_401;
_sharp_pair_401,
(_sharp_pair_401 = ((struct struct0x08504cc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_401).car) = 4);
(((* _sharp_pair_401).cdr) = ((List__O__Int__C____type__type ) 0));
((List__O__Int__C____type__type ) _sharp_pair_401);
})
);
((List__O__Int__C____type__type ) _sharp_pair_402);
})
);
((List__O__Int__C____type__type ) _sharp_pair_403);
})
);
((List__O__Int__C____type__type ) _sharp_pair_404);
})
);
((void) 0);_sharp__sharp_loop406_begin409:((void) 0),
({
Int__type element;
({if( (_sharp_iterator405 == ((List__O__Int__C____type__type ) 0)))
{
({goto _sharp__sharp_loop406_end407;});}})
;
(element = ((* ((struct struct0x08504cc8 *) _sharp_iterator405)).car));
({
((* _sharp_make_list_ptr399) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08508a70 **) _sharp_make_list_ptr399))).car) = ((void *) ((int) 3 * (int) element))),
(_sharp_make_list_ptr399 = (&((* (* ((struct struct0x08508a70 **) _sharp_make_list_ptr399))).cdr)));
})
;
((void) 0);_sharp__sharp_loop406_continue408:((void) 0);
(_sharp_iterator405 = ((* ((struct struct0x08504cc8 *) _sharp_iterator405)).cdr));
})
,
({goto _sharp__sharp_loop406_begin409;}),
((void) 0);_sharp__sharp_loop406_end407:((void) 0);
})
;
((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr399) = ((void *) 0)),
_sharp_make_list398;
})
);
({
List__O__Int__C____type__type _sharp_iterator411;
(_sharp_iterator411 = newlist);
((void) 0);_sharp__sharp_loop412_begin415:((void) 0),
({
Int__type element;
({if( (_sharp_iterator411 == ((List__O__Int__C____type__type ) 0)))
{
({goto _sharp__sharp_loop412_end413;});}})
;
(element = ((* ((struct struct0x08504cc8 *) _sharp_iterator411)).car));
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Element: "), "Element: "})),
(print_Int_Dec)(element),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "\n"), "\n"})),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop412_continue414:((void) 0);
(_sharp_iterator411 = ((* ((struct struct0x08504cc8 *) _sharp_iterator411)).cdr));
})
,
({goto _sharp__sharp_loop412_begin415;}),
((void) 0);_sharp__sharp_loop412_end413:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "-------\n"), "-------\n"})),
(maybe_flush)();
(list = ({
List__O__Symbol__C____type__type _sharp_make_list416;
_sharp_make_list416,
_sharp_make_list_ptr417,
(_sharp_make_list_ptr417 = ((void *) (&_sharp_make_list416))),
({
((* _sharp_make_list_ptr417) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08508a70 **) _sharp_make_list_ptr417))).car) = ((void *) intern( "toto"))),
(_sharp_make_list_ptr417 = (&((* (* ((struct struct0x08508a70 **) _sharp_make_list_ptr417))).cdr)));
((* _sharp_make_list_ptr417) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08508a70 **) _sharp_make_list_ptr417))).car) = ((void *) intern( "tata"))),
(_sharp_make_list_ptr417 = (&((* (* ((struct struct0x08508a70 **) _sharp_make_list_ptr417))).cdr)));
})
,
((* _sharp_make_list_ptr417) = ((void *) 0)),
_sharp_make_list416;
})
);
({
List__O__Symbol__C____type__type _sharp_iterator419;
(_sharp_iterator419 = list);
((void) 0);_sharp__sharp_loop420_begin423:((void) 0),
({
Symbol__type element;
({if( (_sharp_iterator419 == ((List__O__Symbol__C____type__type ) 0)))
{
({goto _sharp__sharp_loop420_end421;});}})
;
(element = ((* ((struct struct0x0850ebb0 *) _sharp_iterator419)).car));
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Element: "), "Element: "})),
(print_Symbol)(element),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "\n"), "\n"})),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop420_continue422:((void) 0);
(_sharp_iterator419 = ((* ((struct struct0x0850ebb0 *) _sharp_iterator419)).cdr));
})
,
({goto _sharp__sharp_loop420_begin423;}),
((void) 0);_sharp__sharp_loop420_end421:((void) 0);
})
;
})
;}

Form__type  make_list_sharp__sharp_expander_function(Compound_Form__type  form)
{
return ({
struct struct0x08058fc0 *_sharp_pointer_alloc326;
Form__type list_type_form;
Form__type listed_type_form;
Expanded_Form__type expsubform;
Expanded_Form__type let_symb_ptr;
List_Maker_Element__type lme;
Symbol__type symb_ptr;
Form__type id_symb;
Form__type id_symb_ptr;
Symbol__type symb;
Form__type subform;
(symb = (gensym)((&(struct { unsigned int len; char *content;}){strlen( "make_list"), "make_list"})));
(id_symb = (Id_Form)(symb));
(symb_ptr = (gensym)((&(struct { unsigned int len; char *content;}){strlen( "make_list_ptr"), "make_list_ptr"})));
(id_symb_ptr = (Id_Form)(symb_ptr));
(lme = ((List_Maker_Element__type ) _sharp_pointer_alloc326,
(_sharp_pointer_alloc326 = ((struct struct0x08058fc0 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc326) = ((struct struct0x08058fc0 ){symb_ptr, ((Type__type ) 0)})),
((struct struct0x08058fc0 *) _sharp_pointer_alloc326)));
(make_list_list = ({
struct struct0x08477088 *_sharp_pair_327;
_sharp_pair_327,
(_sharp_pair_327 = ((struct struct0x08477088 *) (alloc_cons_cell)()));
(((* _sharp_pair_327).car) = lme);
(((* _sharp_pair_327).cdr) = make_list_list);
((List__O__List_Maker_Element__C____type__type ) _sharp_pair_327);
})
);
(subform = ((* ((struct struct0x0805e8a8 *) ((* ((struct struct0x0805e670 *) form)).form_list))).head));
(let_symb_ptr = (expand)((Compound_Form)(intern( "let"), ({
struct struct0x0808ecc8 *_sharp_pair_331;
_sharp_pair_331,
(_sharp_pair_331 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_331).car) = id_symb_ptr);
(((* _sharp_pair_331).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_330;
_sharp_pair_330,
(_sharp_pair_330 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_330).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_329;
_sharp_pair_329,
(_sharp_pair_329 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_329).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_328;
_sharp_pair_328,
(_sharp_pair_328 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_328).car) = (Id_Form)(intern( "Void")));
(((* _sharp_pair_328).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_328);
})
));
(((* _sharp_pair_329).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_329);
})
));
(((* _sharp_pair_330).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_330);
})
);
((List__O__Form__C____type__type ) _sharp_pair_331);
})
)));
(expsubform = (expand)(subform));
({if( (((* ((struct struct0x08058fc0 *) lme)).type_listed) == ((Type__type ) 0)))
{
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Error: make_list must contain at least one call to make()\n"), "Error: make_list must contain at least one call to make()\n"})),
(maybe_flush)();
(exit)(3);
})
;}})
;
(listed_type_form = (((struct struct0x0808d1d0 ) ((* ((struct struct0x0808d458 *) ((Real_Type__type ) ((* ((struct struct0x08058fc0 *) lme)).type_listed)))).common_)).type_form));
(list_type_form = (Compound_Form)(intern( "List"), ({
struct struct0x0808ecc8 *_sharp_pair_332;
_sharp_pair_332,
(_sharp_pair_332 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_332).car) = listed_type_form);
(((* _sharp_pair_332).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_332);
})
));
(make_list_list = ((* ((struct struct0x08475678 *) make_list_list)).tail));
((Form__type ) (expand)((Compound_Form)(intern( "block"), ({
struct struct0x0808ecc8 *_sharp_pair_353;
_sharp_pair_353,
(_sharp_pair_353 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_353).car) = (Compound_Form)(intern( "seq"), ({
struct struct0x0808ecc8 *_sharp_pair_352;
_sharp_pair_352,
(_sharp_pair_352 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_352).car) = (Compound_Form)(intern( "let"), ({
struct struct0x0808ecc8 *_sharp_pair_334;
_sharp_pair_334,
(_sharp_pair_334 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_334).car) = id_symb);
(((* _sharp_pair_334).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_333;
_sharp_pair_333,
(_sharp_pair_333 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_333).car) = list_type_form);
(((* _sharp_pair_333).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_333);
})
);
((List__O__Form__C____type__type ) _sharp_pair_334);
})
));
(((* _sharp_pair_352).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_351;
_sharp_pair_351,
(_sharp_pair_351 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_351).car) = ((Form__type ) let_symb_ptr));
(((* _sharp_pair_351).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_350;
_sharp_pair_350,
(_sharp_pair_350 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_350).car) = (Compound_Form)(intern( "="), ({
struct struct0x0808ecc8 *_sharp_pair_340;
_sharp_pair_340,
(_sharp_pair_340 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_340).car) = id_symb_ptr);
(((* _sharp_pair_340).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_339;
_sharp_pair_339,
(_sharp_pair_339 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_339).car) = (Compound_Form)(intern( "ref"), ({
struct struct0x0808ecc8 *_sharp_pair_338;
_sharp_pair_338,
(_sharp_pair_338 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_338).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808ecc8 *_sharp_pair_337;
_sharp_pair_337,
(_sharp_pair_337 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_337).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_335;
_sharp_pair_335,
(_sharp_pair_335 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_335).car) = (Id_Form)(intern( "Void")));
(((* _sharp_pair_335).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_335);
})
));
(((* _sharp_pair_337).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_336;
_sharp_pair_336,
(_sharp_pair_336 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_336).car) = id_symb);
(((* _sharp_pair_336).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_336);
})
);
((List__O__Form__C____type__type ) _sharp_pair_337);
})
));
(((* _sharp_pair_338).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_338);
})
));
(((* _sharp_pair_339).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_339);
})
);
((List__O__Form__C____type__type ) _sharp_pair_340);
})
));
(((* _sharp_pair_350).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_349;
_sharp_pair_349,
(_sharp_pair_349 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_349).car) = ((Form__type ) expsubform));
(((* _sharp_pair_349).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_348;
_sharp_pair_348,
(_sharp_pair_348 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_348).car) = (Compound_Form)(intern( "="), ({
struct struct0x0808ecc8 *_sharp_pair_346;
_sharp_pair_346,
(_sharp_pair_346 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_346).car) = (Compound_Form)(intern( "deref"), ({
struct struct0x0808ecc8 *_sharp_pair_341;
_sharp_pair_341,
(_sharp_pair_341 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_341).car) = id_symb_ptr);
(((* _sharp_pair_341).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_341);
})
));
(((* _sharp_pair_346).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_345;
_sharp_pair_345,
(_sharp_pair_345 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_345).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808ecc8 *_sharp_pair_344;
_sharp_pair_344,
(_sharp_pair_344 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_344).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_342;
_sharp_pair_342,
(_sharp_pair_342 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_342).car) = (Id_Form)(intern( "Void")));
(((* _sharp_pair_342).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_342);
})
));
(((* _sharp_pair_344).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_343;
_sharp_pair_343,
(_sharp_pair_343 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_343).car) = (Int_Form)(0));
(((* _sharp_pair_343).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_343);
})
);
((List__O__Form__C____type__type ) _sharp_pair_344);
})
));
(((* _sharp_pair_345).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_345);
})
);
((List__O__Form__C____type__type ) _sharp_pair_346);
})
));
(((* _sharp_pair_348).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_347;
_sharp_pair_347,
(_sharp_pair_347 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_347).car) = id_symb);
(((* _sharp_pair_347).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_347);
})
);
((List__O__Form__C____type__type ) _sharp_pair_348);
})
);
((List__O__Form__C____type__type ) _sharp_pair_349);
})
);
((List__O__Form__C____type__type ) _sharp_pair_350);
})
);
((List__O__Form__C____type__type ) _sharp_pair_351);
})
);
((List__O__Form__C____type__type ) _sharp_pair_352);
})
));
(((* _sharp_pair_353).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_353);
})
)));
})
;}

Form__type  make_sharp__sharp_expander_function(Compound_Form__type  form)
{
return ({
Expanded_Form__type exp_subform;
List_Maker_Element__type top;
Symbol__type symb_ptr;
Form__type id_symb;
Form__type subform;
Type__type type_listed;
Type__type type;
({if( (make_list_list == ((List__O__List_Maker_Element__C____type__type ) 0)))
{
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Error: Trying to make an element outside of a make_list\n"), "Error: Trying to make an element outside of a make_list\n"})),
(maybe_flush)();
(exit)(3);
})
;}})
;
(top = ((* ((struct struct0x08475678 *) make_list_list)).head));
(symb_ptr = ((* ((struct struct0x08058fc0 *) top)).ptr_name));
(id_symb = (Id_Form)(symb_ptr));
(type_listed = ((* ((struct struct0x08058fc0 *) top)).type_listed));
(subform = ((* ((struct struct0x0805e8a8 *) ((* ((struct struct0x0805e670 *) form)).form_list))).head));
(exp_subform = (expand)(subform));
(type = ((* ((struct struct0x0805f0a8 *) exp_subform)).type));
(((type_listed != ((Type__type ) 0)))?
(({
({if( (type_listed != type))
{
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Type mismatch: trying to make an heterogeneous list\n"), "Type mismatch: trying to make an heterogeneous list\n"})),
(maybe_flush)();
(exit)(3);
})
;}})
;
})
):
(({
(((* ((struct struct0x08058fc0 *) top)).type_listed) = type);
((void) 0);
})
));
(Compound_Form)(intern( "seq"), ({
struct struct0x0808ecc8 *_sharp_pair_397;
_sharp_pair_397,
(_sharp_pair_397 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_397).car) = (Compound_Form)(intern( "="), ({
struct struct0x0808ecc8 *_sharp_pair_356;
_sharp_pair_356,
(_sharp_pair_356 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_356).car) = (Compound_Form)(intern( "deref"), ({
struct struct0x0808ecc8 *_sharp_pair_354;
_sharp_pair_354,
(_sharp_pair_354 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_354).car) = id_symb);
(((* _sharp_pair_354).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_354);
})
));
(((* _sharp_pair_356).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_355;
_sharp_pair_355,
(_sharp_pair_355 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_355).car) = (Compound_Form)(intern( "alloc_cons_cell"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_355).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_355);
})
);
((List__O__Form__C____type__type ) _sharp_pair_356);
})
));
(((* _sharp_pair_397).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_396;
_sharp_pair_396,
(_sharp_pair_396 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_396).car) = (Compound_Form)(intern( "="), ({
struct struct0x0808ecc8 *_sharp_pair_376;
_sharp_pair_376,
(_sharp_pair_376 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_376).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808ecc8 *_sharp_pair_371;
_sharp_pair_371,
(_sharp_pair_371 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_371).car) = (Compound_Form)(intern( "deref"), ({
struct struct0x0808ecc8 *_sharp_pair_369;
_sharp_pair_369,
(_sharp_pair_369 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_369).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808ecc8 *_sharp_pair_368;
_sharp_pair_368,
(_sharp_pair_368 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_368).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_366;
_sharp_pair_366,
(_sharp_pair_366 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_366).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_365;
_sharp_pair_365,
(_sharp_pair_365 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_365).car) = (Compound_Form)(intern( "struct"), ({
struct struct0x0808ecc8 *_sharp_pair_364;
_sharp_pair_364,
(_sharp_pair_364 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_364).car) = (Compound_Form)(intern( "label"), ({
struct struct0x0808ecc8 *_sharp_pair_359;
_sharp_pair_359,
(_sharp_pair_359 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_359).car) = (Id_Form)(intern( "car")));
(((* _sharp_pair_359).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_358;
_sharp_pair_358,
(_sharp_pair_358 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_358).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_357;
_sharp_pair_357,
(_sharp_pair_357 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_357).car) = (Id_Form)(intern( "Void")));
(((* _sharp_pair_357).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_357);
})
));
(((* _sharp_pair_358).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_358);
})
);
((List__O__Form__C____type__type ) _sharp_pair_359);
})
));
(((* _sharp_pair_364).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_363;
_sharp_pair_363,
(_sharp_pair_363 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_363).car) = (Compound_Form)(intern( "label"), ({
struct struct0x0808ecc8 *_sharp_pair_362;
_sharp_pair_362,
(_sharp_pair_362 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_362).car) = (Id_Form)(intern( "cdr")));
(((* _sharp_pair_362).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_361;
_sharp_pair_361,
(_sharp_pair_361 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_361).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_360;
_sharp_pair_360,
(_sharp_pair_360 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_360).car) = (Id_Form)(intern( "Void")));
(((* _sharp_pair_360).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_360);
})
));
(((* _sharp_pair_361).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_361);
})
);
((List__O__Form__C____type__type ) _sharp_pair_362);
})
));
(((* _sharp_pair_363).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_363);
})
);
((List__O__Form__C____type__type ) _sharp_pair_364);
})
));
(((* _sharp_pair_365).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_365);
})
));
(((* _sharp_pair_366).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_366);
})
));
(((* _sharp_pair_368).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_367;
_sharp_pair_367,
(_sharp_pair_367 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_367).car) = id_symb);
(((* _sharp_pair_367).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_367);
})
);
((List__O__Form__C____type__type ) _sharp_pair_368);
})
));
(((* _sharp_pair_369).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_369);
})
));
(((* _sharp_pair_371).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_370;
_sharp_pair_370,
(_sharp_pair_370 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_370).car) = (Symbol_Form)(intern( "car")));
(((* _sharp_pair_370).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_370);
})
);
((List__O__Form__C____type__type ) _sharp_pair_371);
})
));
(((* _sharp_pair_376).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_375;
_sharp_pair_375,
(_sharp_pair_375 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_375).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808ecc8 *_sharp_pair_374;
_sharp_pair_374,
(_sharp_pair_374 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_374).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_372;
_sharp_pair_372,
(_sharp_pair_372 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_372).car) = (Id_Form)(intern( "Void")));
(((* _sharp_pair_372).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_372);
})
));
(((* _sharp_pair_374).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_373;
_sharp_pair_373,
(_sharp_pair_373 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_373).car) = ((Form__type ) exp_subform));
(((* _sharp_pair_373).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_373);
})
);
((List__O__Form__C____type__type ) _sharp_pair_374);
})
));
(((* _sharp_pair_375).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_375);
})
);
((List__O__Form__C____type__type ) _sharp_pair_376);
})
));
(((* _sharp_pair_396).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_395;
_sharp_pair_395,
(_sharp_pair_395 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_395).car) = (Compound_Form)(intern( "="), ({
struct struct0x0808ecc8 *_sharp_pair_394;
_sharp_pair_394,
(_sharp_pair_394 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_394).car) = id_symb);
(((* _sharp_pair_394).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_393;
_sharp_pair_393,
(_sharp_pair_393 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_393).car) = (Compound_Form)(intern( "ref"), ({
struct struct0x0808ecc8 *_sharp_pair_392;
_sharp_pair_392,
(_sharp_pair_392 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_392).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808ecc8 *_sharp_pair_391;
_sharp_pair_391,
(_sharp_pair_391 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_391).car) = (Compound_Form)(intern( "deref"), ({
struct struct0x0808ecc8 *_sharp_pair_389;
_sharp_pair_389,
(_sharp_pair_389 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_389).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808ecc8 *_sharp_pair_388;
_sharp_pair_388,
(_sharp_pair_388 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_388).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_386;
_sharp_pair_386,
(_sharp_pair_386 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_386).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_385;
_sharp_pair_385,
(_sharp_pair_385 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_385).car) = (Compound_Form)(intern( "struct"), ({
struct struct0x0808ecc8 *_sharp_pair_384;
_sharp_pair_384,
(_sharp_pair_384 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_384).car) = (Compound_Form)(intern( "label"), ({
struct struct0x0808ecc8 *_sharp_pair_379;
_sharp_pair_379,
(_sharp_pair_379 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_379).car) = (Id_Form)(intern( "car")));
(((* _sharp_pair_379).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_378;
_sharp_pair_378,
(_sharp_pair_378 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_378).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_377;
_sharp_pair_377,
(_sharp_pair_377 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_377).car) = (Id_Form)(intern( "Void")));
(((* _sharp_pair_377).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_377);
})
));
(((* _sharp_pair_378).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_378);
})
);
((List__O__Form__C____type__type ) _sharp_pair_379);
})
));
(((* _sharp_pair_384).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_383;
_sharp_pair_383,
(_sharp_pair_383 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_383).car) = (Compound_Form)(intern( "label"), ({
struct struct0x0808ecc8 *_sharp_pair_382;
_sharp_pair_382,
(_sharp_pair_382 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_382).car) = (Id_Form)(intern( "cdr")));
(((* _sharp_pair_382).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_381;
_sharp_pair_381,
(_sharp_pair_381 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_381).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x0808ecc8 *_sharp_pair_380;
_sharp_pair_380,
(_sharp_pair_380 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_380).car) = (Id_Form)(intern( "Void")));
(((* _sharp_pair_380).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_380);
})
));
(((* _sharp_pair_381).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_381);
})
);
((List__O__Form__C____type__type ) _sharp_pair_382);
})
));
(((* _sharp_pair_383).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_383);
})
);
((List__O__Form__C____type__type ) _sharp_pair_384);
})
));
(((* _sharp_pair_385).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_385);
})
));
(((* _sharp_pair_386).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_386);
})
));
(((* _sharp_pair_388).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_387;
_sharp_pair_387,
(_sharp_pair_387 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_387).car) = id_symb);
(((* _sharp_pair_387).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_387);
})
);
((List__O__Form__C____type__type ) _sharp_pair_388);
})
));
(((* _sharp_pair_389).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_389);
})
));
(((* _sharp_pair_391).cdr) = ({
struct struct0x0808ecc8 *_sharp_pair_390;
_sharp_pair_390,
(_sharp_pair_390 = ((struct struct0x0808ecc8 *) (alloc_cons_cell)()));
(((* _sharp_pair_390).car) = (Symbol_Form)(intern( "cdr")));
(((* _sharp_pair_390).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_390);
})
);
((List__O__Form__C____type__type ) _sharp_pair_391);
})
));
(((* _sharp_pair_392).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_392);
})
));
(((* _sharp_pair_393).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_393);
})
);
((List__O__Form__C____type__type ) _sharp_pair_394);
})
));
(((* _sharp_pair_395).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_395);
})
);
((List__O__Form__C____type__type ) _sharp_pair_396);
})
);
((List__O__Form__C____type__type ) _sharp_pair_397);
})
);
})
;}

void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( "TEST result: %d", test_ptr());flush();}
