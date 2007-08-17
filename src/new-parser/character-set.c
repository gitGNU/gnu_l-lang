/* Automatically generated : do not edit!*/
#include "character-set.inc"
Int__type  Character(Symbol__type  s)
{
return ({
(character_from_symbol)(s);
})
;}

Int__type  min(Int__type  a, Int__type  b)
{
return ({
((((int) a <= (int) b))?
(a):
(b));
})
;}

Int__type  max(Int__type  a, Int__type  b)
{
return ({
((((int) a <= (int) b))?
(b):
(a));
})
;}

Character_Set__type  sort_Character_Set(List__O__Character_Range__C____type__type  cr_list)
{
return ({
List__O__Character_Range__C____type__type new_cr_list;
({(new_cr_list = ((List__O__Character_Range__C____type__type ) 0));
({
List__O__Character_Range__C____type__type _sharp_iterator356;
(_sharp_iterator356 = cr_list);
({({_sharp__sharp_loop357_begin365:;
({
Character_Range__type cr;
({if( (_sharp_iterator356 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop357_end358;});}})
;
(cr = ((* ((struct struct0x08554d10 *) _sharp_iterator356)).car));
({
List__O__Character_Range__C____type__type *new_cr_list_ptr;
({(new_cr_list_ptr = (&new_cr_list));
({({_sharp__sharp_loop359_begin363:;
({
List__O__Character_Range__C____type__type next_cr;
({({if( ((* new_cr_list_ptr) == ((List__O__Character_Range__C____type__type ) 0)))
{
({
({((* new_cr_list_ptr) = ({
struct struct0x08554d10 *_sharp_pair_361;
({_sharp_pair_361;
(_sharp_pair_361 = ((struct struct0x08554d10 *) (alloc_cons_cell)()));});
(((* _sharp_pair_361).car) = cr);
(((* _sharp_pair_361).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_361);
})
);
({goto _sharp__sharp_loop359_end360;});
((void) 0);});
})
;}})
;
(next_cr = (* new_cr_list_ptr));
({if( ((int) ((* ((struct struct0x08552a38 *) cr)).max) < (int) ((* ((struct struct0x08552a38 *) ((* ((struct struct0x08552da8 *) next_cr)).head))).min)))
{
({
List__O__Character_Range__C____type__type pair;
({(pair = ({
struct struct0x08554d10 *_sharp_pair_362;
({_sharp_pair_362;
(_sharp_pair_362 = ((struct struct0x08554d10 *) (alloc_cons_cell)()));});
(((* _sharp_pair_362).car) = cr);
(((* _sharp_pair_362).cdr) = next_cr);
((List__O__Character_Range__C____type__type ) _sharp_pair_362);
})
);
((* new_cr_list_ptr) = pair);
({goto _sharp__sharp_loop359_end360;});
((void) 0);});
})
;}})
;
(new_cr_list_ptr = (&((* ((struct struct0x08552da8 *) (* new_cr_list_ptr))).tail)));
((void) 0);});
})
;
({goto _sharp__sharp_loop359_begin363;});});
_sharp__sharp_loop359_end360:;});
((void) 0);});
})
;
_sharp__sharp_loop357_continue364:;
(_sharp_iterator356 = ((* ((struct struct0x08554d10 *) _sharp_iterator356)).cdr));
})
;
({goto _sharp__sharp_loop357_begin365;});});
_sharp__sharp_loop357_end358:;});
})
;
((Character_Set__type ) new_cr_list);});
})
;}

Character_Set__type  make_Character_Set(Form__type  form_)
{
return ({
void **_sharp_make_list_ptr367;
List__O__Character_Range__C____type__type new_list;
Compound_Form__type form;
({(form = ((Compound_Form__type ) form_));
(new_list = ({
List__O__Character_Range__C____type__type _sharp_make_list366;
({_sharp_make_list366;
_sharp_make_list_ptr367;
(_sharp_make_list_ptr367 = ((void *) (&_sharp_make_list366)));
({
({({
List__O__Form__C____type__type _sharp_iterator369;
(_sharp_iterator369 = ((* ((struct struct0x0805eec0 *) form)).form_list));
({({_sharp__sharp_loop370_begin384:;
({
Form__type subform;
({if( (_sharp_iterator369 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop370_end371;});}})
;
(subform = ((* ((struct struct0x08067cc8 *) _sharp_iterator369)).car));
({
(((is_compound_form)(subform))?
(({
struct struct0x08552a38 *_sharp_pointer_alloc378;
Int_Form__type max_form;
Int_Form__type min_form;
Compound_Form__type cf;
({(cf = ((Compound_Form__type ) subform));
(min_form = ((Int_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head)));
(max_form = ((Int_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail))).head)));
({if( ((is_int_form)(((Form__type ) min_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_1));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_int_form"), ({
struct struct0x08067cc8 *_sharp_pair_374;
({_sharp_pair_374;
(_sharp_pair_374 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_374).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_373;
({_sharp_pair_373;
(_sharp_pair_373 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_373).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_373).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_372;
({_sharp_pair_372;
(_sharp_pair_372 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_372).car) = (Id_Form)(intern( "min_form")));
(((* _sharp_pair_372).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_372);
})
);
((List__O__Form__C____type__type ) _sharp_pair_373);
})
));
(((* _sharp_pair_374).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_374);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_2));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
({if( ((is_int_form)(((Form__type ) max_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_3));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_int_form"), ({
struct struct0x08067cc8 *_sharp_pair_377;
({_sharp_pair_377;
(_sharp_pair_377 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_377).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_376;
({_sharp_pair_376;
(_sharp_pair_376 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_376).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_376).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_375;
({_sharp_pair_375;
(_sharp_pair_375 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_375).car) = (Id_Form)(intern( "max_form")));
(((* _sharp_pair_375).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_375);
})
);
((List__O__Form__C____type__type ) _sharp_pair_376);
})
));
(((* _sharp_pair_377).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_377);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_4));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
({((* _sharp_make_list_ptr367) = (alloc_cons_cell)());
(((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr367))).car) = ((void *) ((Character_Range__type ) ({_sharp_pointer_alloc378;
(_sharp_pointer_alloc378 = ((struct struct0x08552a38 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc378) = ((struct struct0x08552a38 ){((* ((struct struct0x08059d10 *) min_form)).value), ((* ((struct struct0x08059d10 *) max_form)).value)}));
((struct struct0x08552a38 *) _sharp_pointer_alloc378);}))));
(_sharp_make_list_ptr367 = (&((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr367))).cdr)));
((void) 0);});
((void) 0);});
})
):
(({
struct struct0x08552a38 *_sharp_pointer_alloc382;
Int_Form__type symbol_form;
({(symbol_form = ((Int_Form__type ) subform));
({if( ((is_int_form)(((Form__type ) symbol_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_5));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_int_form"), ({
struct struct0x08067cc8 *_sharp_pair_381;
({_sharp_pair_381;
(_sharp_pair_381 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_381).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_380;
({_sharp_pair_380;
(_sharp_pair_380 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_380).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_380).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_379;
({_sharp_pair_379;
(_sharp_pair_379 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_379).car) = (Id_Form)(intern( "symbol_form")));
(((* _sharp_pair_379).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_379);
})
);
((List__O__Form__C____type__type ) _sharp_pair_380);
})
));
(((* _sharp_pair_381).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_381);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_6));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
({((* _sharp_make_list_ptr367) = (alloc_cons_cell)());
(((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr367))).car) = ((void *) ((Character_Range__type ) ({_sharp_pointer_alloc382;
(_sharp_pointer_alloc382 = ((struct struct0x08552a38 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc382) = ((struct struct0x08552a38 ){((* ((struct struct0x08059d10 *) symbol_form)).value), ((* ((struct struct0x08059d10 *) symbol_form)).value)}));
((struct struct0x08552a38 *) _sharp_pointer_alloc382);}))));
(_sharp_make_list_ptr367 = (&((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr367))).cdr)));
((void) 0);});
((void) 0);});
})
));
})
;
_sharp__sharp_loop370_continue383:;
(_sharp_iterator369 = ((* ((struct struct0x08067cc8 *) _sharp_iterator369)).cdr));
})
;
({goto _sharp__sharp_loop370_begin384;});});
_sharp__sharp_loop370_end371:;});
})
;
((void) 0);});
})
;
((* _sharp_make_list_ptr367) = ((void *) 0));
_sharp_make_list366;});
})
);
(sort_Character_Set)(new_list);});
})
;}

Character_Set__type  get_inverse_Character_Set(Character_Set__type  cs)
{
return ({
(((cs == ((Character_Set__type ) 0)))?
(({
struct struct0x08552a38 *_sharp_pointer_alloc385;
((Character_Set__type ) ({
struct struct0x08554d10 *_sharp_pair_386;
({_sharp_pair_386;
(_sharp_pair_386 = ((struct struct0x08554d10 *) (alloc_cons_cell)()));});
(((* _sharp_pair_386).car) = ((Character_Range__type ) ({_sharp_pointer_alloc385;
(_sharp_pointer_alloc385 = ((struct struct0x08552a38 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc385) = ((struct struct0x08552a38 ){1, 255}));
((struct struct0x08552a38 *) _sharp_pointer_alloc385);})));
(((* _sharp_pair_386).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_386);
})
);
})
):
(({
void **_sharp_make_list_ptr388;
List__O__Character_Range__C____type__type inverse;
List__O__Character_Range__C____type__type csl;
Character_Range__type first;
({(csl = ((List__O__Character_Range__C____type__type ) cs));
(first = ((* ((struct struct0x08552da8 *) csl)).head));
(inverse = ({
List__O__Character_Range__C____type__type _sharp_make_list387;
({_sharp_make_list387;
_sharp_make_list_ptr388;
(_sharp_make_list_ptr388 = ((void *) (&_sharp_make_list387)));
({
Int__type prec;
({({if( (((* ((struct struct0x08552a38 *) first)).min) != 0))
{
({
struct struct0x08552a38 *_sharp_pointer_alloc389;
({({((* _sharp_make_list_ptr388) = (alloc_cons_cell)());
(((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr388))).car) = ((void *) ((Character_Range__type ) ({_sharp_pointer_alloc389;
(_sharp_pointer_alloc389 = ((struct struct0x08552a38 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc389) = ((struct struct0x08552a38 ){0, ((int) ((* ((struct struct0x08552a38 *) first)).min) - (int) 1)}));
((struct struct0x08552a38 *) _sharp_pointer_alloc389);}))));
(_sharp_make_list_ptr388 = (&((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr388))).cdr)));
((void) 0);});
((void) 0);});
})
;}})
;
(prec = ((int) ((* ((struct struct0x08552a38 *) first)).max) + (int) 1));
({
List__O__Character_Range__C____type__type _sharp_iterator391;
(_sharp_iterator391 = ((* ((struct struct0x08552da8 *) csl)).tail));
({({_sharp__sharp_loop392_begin396:;
({
Character_Range__type cr;
({if( (_sharp_iterator391 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop392_end393;});}})
;
(cr = ((* ((struct struct0x08554d10 *) _sharp_iterator391)).car));
({
struct struct0x08552a38 *_sharp_pointer_alloc394;
({({((* _sharp_make_list_ptr388) = (alloc_cons_cell)());
(((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr388))).car) = ((void *) ((Character_Range__type ) ({_sharp_pointer_alloc394;
(_sharp_pointer_alloc394 = ((struct struct0x08552a38 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc394) = ((struct struct0x08552a38 ){prec, ((int) ((* ((struct struct0x08552a38 *) cr)).min) - (int) 1)}));
((struct struct0x08552a38 *) _sharp_pointer_alloc394);}))));
(_sharp_make_list_ptr388 = (&((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr388))).cdr)));
((void) 0);});
(prec = ((int) ((* ((struct struct0x08552a38 *) cr)).max) + (int) 1));
((void) 0);});
})
;
_sharp__sharp_loop392_continue395:;
(_sharp_iterator391 = ((* ((struct struct0x08554d10 *) _sharp_iterator391)).cdr));
})
;
({goto _sharp__sharp_loop392_begin396;});});
_sharp__sharp_loop392_end393:;});
})
;
({if( ((int) prec < (int) 256))
{
({
struct struct0x08552a38 *_sharp_pointer_alloc397;
({({((* _sharp_make_list_ptr388) = (alloc_cons_cell)());
(((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr388))).car) = ((void *) ((Character_Range__type ) ({_sharp_pointer_alloc397;
(_sharp_pointer_alloc397 = ((struct struct0x08552a38 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc397) = ((struct struct0x08552a38 ){prec, 255}));
((struct struct0x08552a38 *) _sharp_pointer_alloc397);}))));
(_sharp_make_list_ptr388 = (&((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr388))).cdr)));
((void) 0);});
((void) 0);});
})
;}})
;
((void) 0);
((void) 0);});
})
;
((* _sharp_make_list_ptr388) = ((void *) 0));
_sharp_make_list387;});
})
);
((Character_Set__type ) inverse);});
})
));
})
;}

Character_Set__type  make_inverse_Character_Set(Form__type  form)
{
return ({
(get_inverse_Character_Set)((make_Character_Set)(form));
})
;}

void  print_Character_Set(Character_Set__type  s)
{
return ({
List__O__Character_Range__C____type__type cl;
({(cl = ((List__O__Character_Range__C____type__type ) s));
({
List__O__Character_Range__C____type__type _sharp_iterator399;
(_sharp_iterator399 = cl);
({({_sharp__sharp_loop400_begin403:;
({
Character_Range__type cr;
({if( (_sharp_iterator399 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop400_end401;});}})
;
(cr = ((* ((struct struct0x08554d10 *) _sharp_iterator399)).car));
({
({({(print_String)(((String__type) &__string_7));
(print_Int_Dec)(((* ((struct struct0x08552a38 *) cr)).min));
(print_String)(((String__type) &__string_8));
(print_Int_Dec)(((* ((struct struct0x08552a38 *) cr)).max));
(print_String)(((String__type) &__string_9));
(maybe_flush)();});
({if( ((((int) ((* ((struct struct0x08552a38 *) cr)).min) > (int) 255))||(((int) ((* ((struct struct0x08552a38 *) cr)).max) > (int) 255))))
{
({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_10));
(print_String)(((String__type) &__string_11));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;
})
;}})
;
((void) 0);});
})
;
_sharp__sharp_loop400_continue402:;
(_sharp_iterator399 = ((* ((struct struct0x08554d10 *) _sharp_iterator399)).cdr));
})
;
({goto _sharp__sharp_loop400_begin403;});});
_sharp__sharp_loop400_end401:;});
})
;});
})
;}

Character_Set__type  union_Character_Set(Character_Set__type  cs1_, Character_Set__type  cs2_)
{
return ({
List__O__Character_Range__C____type__type cs1;
List__O__Character_Range__C____type__type cs2;
({(cs1 = ((List__O__Character_Range__C____type__type ) cs1_));
(cs2 = ((List__O__Character_Range__C____type__type ) cs2_));
(sort_Character_Set)(((List__O__Character_Range__C____type__type ) (append)(((List__O__pointer__O__Void__C____C____type__type ) cs1), ((List__O__pointer__O__Void__C____C____type__type ) cs2))));});
})
;}

List__O__Character_Set__C____type__type  union_Character_Set_List(List__O__Character_Set__C____type__type  csl1, List__O__Character_Set__C____type__type  csl2)
{
return ({
void **_sharp_make_list_ptr405;
List__O__Character_Set__C____type__type l2;
List__O__Character_Set__C____type__type l1;
List__O__Character_Set__C____type__type new_list;
({(l1 = csl1);
(l2 = csl2);
(new_list = ({
List__O__Character_Set__C____type__type _sharp_make_list404;
({_sharp_make_list404;
_sharp_make_list_ptr405;
(_sharp_make_list_ptr405 = ((void *) (&_sharp_make_list404)));
({
({({_sharp__sharp_loop406_continue408:;
({({_sharp__sharp_loop406_begin409:;
({
({(((l1 != ((List__O__Character_Set__C____type__type ) 0)))?
(({
({({if( (l2 != ((List__O__Character_Set__C____type__type ) 0)))
{
({
({({((* _sharp_make_list_ptr405) = (alloc_cons_cell)());
(((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr405))).car) = ((void *) (union_Character_Set)(((* ((struct struct0x08553628 *) l1)).head), ((* ((struct struct0x08553628 *) l2)).head))));
(_sharp_make_list_ptr405 = (&((* (* ((struct struct0x08563308 **) _sharp_make_list_ptr405))).cdr)));
((void) 0);});
(l2 = ((* ((struct struct0x08553628 *) l2)).tail));
(l1 = ((* ((struct struct0x08553628 *) l1)).tail));
({goto _sharp__sharp_loop406_continue408;});
((void) 0);});
})
;}})
;
({goto _sharp__sharp_loop406_end407;});
((void) 0);});
})
):
(({if( (l2 != ((List__O__Character_Set__C____type__type ) 0)))
{
({
({({goto _sharp__sharp_loop406_end407;});
((void) 0);});
})
;}})
));
({goto _sharp__sharp_loop406_end407;});
((void) 0);});
})
;
({goto _sharp__sharp_loop406_begin409;});});
_sharp__sharp_loop406_end407:;});});
((void) 0);});
})
;
((* _sharp_make_list_ptr405) = ((void *) 0));
_sharp_make_list404;});
})
);});
})
;}

Form__type  is_in_Character_Set_condition(List__O__Character_Set__C____type__type  cs_list)
{
return ({
Int__type i;
Form__type final_final_cond;
Form__type final_cond;
({final_cond;
(final_final_cond = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_411;
({_sharp_pair_411;
(_sharp_pair_411 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_411).car) = (Id_Form)(intern( "Bool")));
(((* _sharp_pair_411).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_410;
({_sharp_pair_410;
(_sharp_pair_410 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_410).car) = (Int_Form)(1));
(((* _sharp_pair_410).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_410);
})
);
((List__O__Form__C____type__type ) _sharp_pair_411);
})
));
(i = 0);
({
List__O__Character_Set__C____type__type _sharp_iterator413;
(_sharp_iterator413 = cs_list);
({({_sharp__sharp_loop414_begin438:;
({
Character_Set__type cs;
({if( (_sharp_iterator413 == ((List__O__Character_Set__C____type__type ) 0)))
{
({goto _sharp__sharp_loop414_end415;});}})
;
(cs = ((* ((struct struct0x0857e0e0 *) _sharp_iterator413)).car));
({
Form__type get_form;
({(get_form = (Compound_Form)(intern( "new_peek_char"), ({
struct struct0x08067cc8 *_sharp_pair_416;
({_sharp_pair_416;
(_sharp_pair_416 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_416).car) = (Int_Form)(i));
(((* _sharp_pair_416).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_416);
})
));
(i = ((int) i + (int) 1));
(final_cond = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_418;
({_sharp_pair_418;
(_sharp_pair_418 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_418).car) = (Id_Form)(intern( "Bool")));
(((* _sharp_pair_418).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_417;
({_sharp_pair_417;
(_sharp_pair_417 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_417).car) = (Int_Form)(0));
(((* _sharp_pair_417).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_417);
})
);
((List__O__Form__C____type__type ) _sharp_pair_418);
})
));
({
List__O__Character_Range__C____type__type _sharp_iterator420;
(_sharp_iterator420 = ((List__O__Character_Range__C____type__type ) cs));
({({_sharp__sharp_loop421_begin434:;
({
Character_Range__type cr;
({if( (_sharp_iterator420 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop421_end422;});}})
;
(cr = ((* ((struct struct0x08554d10 *) _sharp_iterator420)).car));
({
Form__type cond;
({(cond = (((((* ((struct struct0x08552a38 *) cr)).min) == ((* ((struct struct0x08552a38 *) cr)).max)))?
(({
(Compound_Form)(intern( "=="), ({
struct struct0x08067cc8 *_sharp_pair_424;
({_sharp_pair_424;
(_sharp_pair_424 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_424).car) = get_form);
(((* _sharp_pair_424).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_423;
({_sharp_pair_423;
(_sharp_pair_423 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_423).car) = (Int_Form)(((* ((struct struct0x08552a38 *) cr)).min)));
(((* _sharp_pair_423).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_423);
})
);
((List__O__Form__C____type__type ) _sharp_pair_424);
})
);
})
):
(({
(Compound_Form)(intern( "@and"), ({
struct struct0x08067cc8 *_sharp_pair_430;
({_sharp_pair_430;
(_sharp_pair_430 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_430).car) = (Compound_Form)(intern( ">="), ({
struct struct0x08067cc8 *_sharp_pair_426;
({_sharp_pair_426;
(_sharp_pair_426 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_426).car) = get_form);
(((* _sharp_pair_426).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_425;
({_sharp_pair_425;
(_sharp_pair_425 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_425).car) = (Int_Form)(((* ((struct struct0x08552a38 *) cr)).min)));
(((* _sharp_pair_425).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_425);
})
);
((List__O__Form__C____type__type ) _sharp_pair_426);
})
));
(((* _sharp_pair_430).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_429;
({_sharp_pair_429;
(_sharp_pair_429 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_429).car) = (Compound_Form)(intern( "<="), ({
struct struct0x08067cc8 *_sharp_pair_428;
({_sharp_pair_428;
(_sharp_pair_428 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_428).car) = get_form);
(((* _sharp_pair_428).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_427;
({_sharp_pair_427;
(_sharp_pair_427 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_427).car) = (Int_Form)(((* ((struct struct0x08552a38 *) cr)).max)));
(((* _sharp_pair_427).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_427);
})
);
((List__O__Form__C____type__type ) _sharp_pair_428);
})
));
(((* _sharp_pair_429).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_429);
})
);
((List__O__Form__C____type__type ) _sharp_pair_430);
})
);
})
)));
(final_cond = (Compound_Form)(intern( "@or"), ({
struct struct0x08067cc8 *_sharp_pair_432;
({_sharp_pair_432;
(_sharp_pair_432 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_432).car) = cond);
(((* _sharp_pair_432).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_431;
({_sharp_pair_431;
(_sharp_pair_431 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_431).car) = final_cond);
(((* _sharp_pair_431).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_431);
})
);
((List__O__Form__C____type__type ) _sharp_pair_432);
})
));
((void) 0);});
})
;
_sharp__sharp_loop421_continue433:;
(_sharp_iterator420 = ((* ((struct struct0x08554d10 *) _sharp_iterator420)).cdr));
})
;
({goto _sharp__sharp_loop421_begin434;});});
_sharp__sharp_loop421_end422:;});
})
;
(final_final_cond = (Compound_Form)(intern( "@and"), ({
struct struct0x08067cc8 *_sharp_pair_436;
({_sharp_pair_436;
(_sharp_pair_436 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_436).car) = final_final_cond);
(((* _sharp_pair_436).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_435;
({_sharp_pair_435;
(_sharp_pair_435 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_435).car) = final_cond);
(((* _sharp_pair_435).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_435);
})
);
((List__O__Form__C____type__type ) _sharp_pair_436);
})
));
((void) 0);});
})
;
_sharp__sharp_loop414_continue437:;
(_sharp_iterator413 = ((* ((struct struct0x0857e0e0 *) _sharp_iterator413)).cdr));
})
;
({goto _sharp__sharp_loop414_begin438;});});
_sharp__sharp_loop414_end415:;});
})
;
final_final_cond;});
})
;}
