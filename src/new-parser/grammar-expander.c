/* Automatically generated : do not edit!*/
#include "grammar-expander.inc"
Hash__O__Symbol__c__Type__C____type__type id_used;

Hash__O__Symbol__c__Form__C____type__type grammar_hash;

Character_Set__type dot_character_set;

Hash__O__Symbol__c__Hash__O__Symbol__c__Form__C____C____type__type rules_hash;

Hash__O__Symbol__c__Hash__O__Symbol__c__Character_Set__C____C____type__type head_set_hash;

Symbol__type grammar_name;

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
(new_cr_list = ((List__O__Character_Range__C____type__type ) 0));
({
List__O__Character_Range__C____type__type _sharp_iterator338;
(_sharp_iterator338 = cr_list);
((void) 0);_sharp__sharp_loop339_begin347:((void) 0),
({
Character_Range__type cr;
({if( (_sharp_iterator338 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop339_end340;});}})
;
(cr = ((* ((struct struct0x0851e1e0 *) _sharp_iterator338)).car));
({
List__O__Character_Range__C____type__type *new_cr_list_ptr;
(new_cr_list_ptr = (&new_cr_list));
((void) 0);_sharp__sharp_loop341_begin345:((void) 0),
({
List__O__Character_Range__C____type__type next_cr;
({if( ((* new_cr_list_ptr) == ((List__O__Character_Range__C____type__type ) 0)))
{
({
((* new_cr_list_ptr) = ({
struct struct0x0851e1e0 *_sharp_pair_343;
_sharp_pair_343,
(_sharp_pair_343 = ((struct struct0x0851e1e0 *) (alloc_cons_cell)()));
(((* _sharp_pair_343).car) = cr);
(((* _sharp_pair_343).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_343);
})
);
({goto _sharp__sharp_loop341_end342;});
})
;}})
;
(next_cr = (* new_cr_list_ptr));
({if( ((int) ((* ((struct struct0x0851b408 *) cr)).max) < (int) ((* ((struct struct0x0851b408 *) ((* ((struct struct0x0851b798 *) next_cr)).head))).min)))
{
({
List__O__Character_Range__C____type__type pair;
(pair = ({
struct struct0x0851e1e0 *_sharp_pair_344;
_sharp_pair_344,
(_sharp_pair_344 = ((struct struct0x0851e1e0 *) (alloc_cons_cell)()));
(((* _sharp_pair_344).car) = cr);
(((* _sharp_pair_344).cdr) = next_cr);
((List__O__Character_Range__C____type__type ) _sharp_pair_344);
})
);
((* new_cr_list_ptr) = pair);
({goto _sharp__sharp_loop341_end342;});
})
;}})
;
(new_cr_list_ptr = (&((* ((struct struct0x0851b798 *) (* new_cr_list_ptr))).tail)));
})
,
({goto _sharp__sharp_loop341_begin345;}),
((void) 0);_sharp__sharp_loop341_end342:((void) 0);
})
;
((void) 0);_sharp__sharp_loop339_continue346:((void) 0);
(_sharp_iterator338 = ((* ((struct struct0x0851e1e0 *) _sharp_iterator338)).cdr));
})
,
({goto _sharp__sharp_loop339_begin347;}),
((void) 0);_sharp__sharp_loop339_end340:((void) 0);
})
;
((Character_Set__type ) new_cr_list);
})
;}

Character_Set__type  make_Character_Set(Form__type  form_)
{
return ({
void **_sharp_make_list_ptr349;
List__O__Character_Range__C____type__type new_list;
Compound_Form__type form;
(form = ((Compound_Form__type ) form_));
(new_list = ({
List__O__Character_Range__C____type__type _sharp_make_list348;
_sharp_make_list348,
_sharp_make_list_ptr349,
(_sharp_make_list_ptr349 = ((void *) (&_sharp_make_list348))),
({
({
List__O__Form__C____type__type _sharp_iterator351;
(_sharp_iterator351 = ((* ((struct struct0x0805ee90 *) form)).form_list));
((void) 0);_sharp__sharp_loop352_begin366:((void) 0),
({
Form__type subform;
({if( (_sharp_iterator351 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop352_end353;});}})
;
(subform = ((* ((struct struct0x080663e8 *) _sharp_iterator351)).car));
({
(((is_compound_form)(subform))?
(({
struct struct0x0851b408 *_sharp_pointer_alloc360;
Int_Form__type max_form;
Int_Form__type min_form;
Compound_Form__type cf;
(cf = ((Compound_Form__type ) subform));
(min_form = ((Int_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head)));
(max_form = ((Int_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail))).head)));
({if( ((is_int_form)(((Form__type ) min_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_1)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_int_form"), ({
struct struct0x080663e8 *_sharp_pair_356;
_sharp_pair_356,
(_sharp_pair_356 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_356).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080663e8 *_sharp_pair_355;
_sharp_pair_355,
(_sharp_pair_355 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_355).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_355).cdr) = ({
struct struct0x080663e8 *_sharp_pair_354;
_sharp_pair_354,
(_sharp_pair_354 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_354).car) = (Id_Form)(intern( "min_form")));
(((* _sharp_pair_354).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_354);
})
);
((List__O__Form__C____type__type ) _sharp_pair_355);
})
));
(((* _sharp_pair_356).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_356);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_2)),
(maybe_flush)();
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
(print_String)(((String__type) &__string_3)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_int_form"), ({
struct struct0x080663e8 *_sharp_pair_359;
_sharp_pair_359,
(_sharp_pair_359 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_359).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080663e8 *_sharp_pair_358;
_sharp_pair_358,
(_sharp_pair_358 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_358).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_358).cdr) = ({
struct struct0x080663e8 *_sharp_pair_357;
_sharp_pair_357,
(_sharp_pair_357 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_357).car) = (Id_Form)(intern( "max_form")));
(((* _sharp_pair_357).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_357);
})
);
((List__O__Form__C____type__type ) _sharp_pair_358);
})
));
(((* _sharp_pair_359).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_359);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_4)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
((* _sharp_make_list_ptr349) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr349))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc360,
(_sharp_pointer_alloc360 = ((struct struct0x0851b408 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc360) = ((struct struct0x0851b408 ){((* ((struct struct0x0805e110 *) min_form)).value), ((* ((struct struct0x0805e110 *) max_form)).value)})),
((struct struct0x0851b408 *) _sharp_pointer_alloc360)))),
(_sharp_make_list_ptr349 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr349))).cdr))),
((void) 0);
})
):
(({
struct struct0x0851b408 *_sharp_pointer_alloc364;
Int_Form__type symbol_form;
(symbol_form = ((Int_Form__type ) subform));
({if( ((is_int_form)(((Form__type ) symbol_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_5)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_int_form"), ({
struct struct0x080663e8 *_sharp_pair_363;
_sharp_pair_363,
(_sharp_pair_363 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_363).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080663e8 *_sharp_pair_362;
_sharp_pair_362,
(_sharp_pair_362 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_362).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_362).cdr) = ({
struct struct0x080663e8 *_sharp_pair_361;
_sharp_pair_361,
(_sharp_pair_361 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_361).car) = (Id_Form)(intern( "symbol_form")));
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
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_6)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
((* _sharp_make_list_ptr349) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr349))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc364,
(_sharp_pointer_alloc364 = ((struct struct0x0851b408 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc364) = ((struct struct0x0851b408 ){((* ((struct struct0x0805e110 *) symbol_form)).value), ((* ((struct struct0x0805e110 *) symbol_form)).value)})),
((struct struct0x0851b408 *) _sharp_pointer_alloc364)))),
(_sharp_make_list_ptr349 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr349))).cdr))),
((void) 0);
})
));
})
;
((void) 0);_sharp__sharp_loop352_continue365:((void) 0);
(_sharp_iterator351 = ((* ((struct struct0x080663e8 *) _sharp_iterator351)).cdr));
})
,
({goto _sharp__sharp_loop352_begin366;}),
((void) 0);_sharp__sharp_loop352_end353:((void) 0);
})
;
((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr349) = ((void *) 0)),
_sharp_make_list348;
})
);
(sort_Character_Set)(new_list);
})
;}

Character_Set__type  get_inverse_Character_Set(Character_Set__type  cs)
{
return ({
(((cs == ((Character_Set__type ) 0)))?
(({
struct struct0x0851b408 *_sharp_pointer_alloc367;
((Character_Set__type ) ({
struct struct0x0851e1e0 *_sharp_pair_368;
_sharp_pair_368,
(_sharp_pair_368 = ((struct struct0x0851e1e0 *) (alloc_cons_cell)()));
(((* _sharp_pair_368).car) = ((Character_Range__type ) _sharp_pointer_alloc367,
(_sharp_pointer_alloc367 = ((struct struct0x0851b408 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc367) = ((struct struct0x0851b408 ){1, 255})),
((struct struct0x0851b408 *) _sharp_pointer_alloc367)));
(((* _sharp_pair_368).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_368);
})
);
})
):
(({
void **_sharp_make_list_ptr370;
List__O__Character_Range__C____type__type inverse;
List__O__Character_Range__C____type__type csl;
Character_Range__type first;
(csl = ((List__O__Character_Range__C____type__type ) cs));
(first = ((* ((struct struct0x0851b798 *) csl)).head));
(inverse = ({
List__O__Character_Range__C____type__type _sharp_make_list369;
_sharp_make_list369,
_sharp_make_list_ptr370,
(_sharp_make_list_ptr370 = ((void *) (&_sharp_make_list369))),
({
Int__type prec;
({if( (((* ((struct struct0x0851b408 *) first)).min) != 0))
{
({
struct struct0x0851b408 *_sharp_pointer_alloc371;
((* _sharp_make_list_ptr370) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr370))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc371,
(_sharp_pointer_alloc371 = ((struct struct0x0851b408 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc371) = ((struct struct0x0851b408 ){0, ((int) ((* ((struct struct0x0851b408 *) first)).min) - (int) 1)})),
((struct struct0x0851b408 *) _sharp_pointer_alloc371)))),
(_sharp_make_list_ptr370 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr370))).cdr))),
((void) 0);
})
;}})
;
(prec = ((int) ((* ((struct struct0x0851b408 *) first)).max) + (int) 1));
({
List__O__Character_Range__C____type__type _sharp_iterator373;
(_sharp_iterator373 = ((* ((struct struct0x0851b798 *) csl)).tail));
((void) 0);_sharp__sharp_loop374_begin378:((void) 0),
({
Character_Range__type cr;
({if( (_sharp_iterator373 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop374_end375;});}})
;
(cr = ((* ((struct struct0x0851e1e0 *) _sharp_iterator373)).car));
({
struct struct0x0851b408 *_sharp_pointer_alloc376;
((* _sharp_make_list_ptr370) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr370))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc376,
(_sharp_pointer_alloc376 = ((struct struct0x0851b408 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc376) = ((struct struct0x0851b408 ){prec, ((int) ((* ((struct struct0x0851b408 *) cr)).min) - (int) 1)})),
((struct struct0x0851b408 *) _sharp_pointer_alloc376)))),
(_sharp_make_list_ptr370 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr370))).cdr))),
((void) 0);
(prec = ((int) ((* ((struct struct0x0851b408 *) cr)).max) + (int) 1));
})
;
((void) 0);_sharp__sharp_loop374_continue377:((void) 0);
(_sharp_iterator373 = ((* ((struct struct0x0851e1e0 *) _sharp_iterator373)).cdr));
})
,
({goto _sharp__sharp_loop374_begin378;}),
((void) 0);_sharp__sharp_loop374_end375:((void) 0);
})
;
({if( ((int) prec < (int) 256))
{
({
struct struct0x0851b408 *_sharp_pointer_alloc379;
((* _sharp_make_list_ptr370) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr370))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc379,
(_sharp_pointer_alloc379 = ((struct struct0x0851b408 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc379) = ((struct struct0x0851b408 ){prec, 255})),
((struct struct0x0851b408 *) _sharp_pointer_alloc379)))),
(_sharp_make_list_ptr370 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr370))).cdr))),
((void) 0);
})
;}})
;
((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr370) = ((void *) 0)),
_sharp_make_list369;
})
);
((Character_Set__type ) inverse);
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
(cl = ((List__O__Character_Range__C____type__type ) s));
({
List__O__Character_Range__C____type__type _sharp_iterator381;
(_sharp_iterator381 = cl);
((void) 0);_sharp__sharp_loop382_begin385:((void) 0),
({
Character_Range__type cr;
({if( (_sharp_iterator381 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop382_end383;});}})
;
(cr = ((* ((struct struct0x0851e1e0 *) _sharp_iterator381)).car));
({
(print_String)(((String__type) &__string_7)),
(print_Int_Dec)(((* ((struct struct0x0851b408 *) cr)).min)),
(print_String)(((String__type) &__string_8)),
(print_Int_Dec)(((* ((struct struct0x0851b408 *) cr)).max)),
(print_String)(((String__type) &__string_9)),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop382_continue384:((void) 0);
(_sharp_iterator381 = ((* ((struct struct0x0851e1e0 *) _sharp_iterator381)).cdr));
})
,
({goto _sharp__sharp_loop382_begin385;}),
((void) 0);_sharp__sharp_loop382_end383:((void) 0);
})
;
})
;}

Form__type  is_in_Character_Set_condition(Form__type  id_form, Character_Set__type  cs)
{
return ({
Form__type final_cond;
(final_cond = (Compound_Form)(intern( "cast"), ({
struct struct0x080663e8 *_sharp_pair_387;
_sharp_pair_387,
(_sharp_pair_387 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_387).car) = (Id_Form)(intern( "Bool")));
(((* _sharp_pair_387).cdr) = ({
struct struct0x080663e8 *_sharp_pair_386;
_sharp_pair_386,
(_sharp_pair_386 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_386).car) = (Int_Form)(0));
(((* _sharp_pair_386).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_386);
})
);
((List__O__Form__C____type__type ) _sharp_pair_387);
})
));
({
List__O__Character_Range__C____type__type _sharp_iterator389;
(_sharp_iterator389 = ((List__O__Character_Range__C____type__type ) cs));
((void) 0);_sharp__sharp_loop390_begin403:((void) 0),
({
Character_Range__type cr;
({if( (_sharp_iterator389 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop390_end391;});}})
;
(cr = ((* ((struct struct0x0851e1e0 *) _sharp_iterator389)).car));
({
Form__type cond;
(cond = (((((* ((struct struct0x0851b408 *) cr)).min) == ((* ((struct struct0x0851b408 *) cr)).max)))?
(({
(Compound_Form)(intern( "=="), ({
struct struct0x080663e8 *_sharp_pair_393;
_sharp_pair_393,
(_sharp_pair_393 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_393).car) = id_form);
(((* _sharp_pair_393).cdr) = ({
struct struct0x080663e8 *_sharp_pair_392;
_sharp_pair_392,
(_sharp_pair_392 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_392).car) = (Int_Form)(((* ((struct struct0x0851b408 *) cr)).min)));
(((* _sharp_pair_392).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_392);
})
);
((List__O__Form__C____type__type ) _sharp_pair_393);
})
);
})
):
(({
(Compound_Form)(intern( "@and"), ({
struct struct0x080663e8 *_sharp_pair_399;
_sharp_pair_399,
(_sharp_pair_399 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_399).car) = (Compound_Form)(intern( ">="), ({
struct struct0x080663e8 *_sharp_pair_395;
_sharp_pair_395,
(_sharp_pair_395 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_395).car) = id_form);
(((* _sharp_pair_395).cdr) = ({
struct struct0x080663e8 *_sharp_pair_394;
_sharp_pair_394,
(_sharp_pair_394 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_394).car) = (Int_Form)(((* ((struct struct0x0851b408 *) cr)).min)));
(((* _sharp_pair_394).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_394);
})
);
((List__O__Form__C____type__type ) _sharp_pair_395);
})
));
(((* _sharp_pair_399).cdr) = ({
struct struct0x080663e8 *_sharp_pair_398;
_sharp_pair_398,
(_sharp_pair_398 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_398).car) = (Compound_Form)(intern( "<="), ({
struct struct0x080663e8 *_sharp_pair_397;
_sharp_pair_397,
(_sharp_pair_397 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_397).car) = id_form);
(((* _sharp_pair_397).cdr) = ({
struct struct0x080663e8 *_sharp_pair_396;
_sharp_pair_396,
(_sharp_pair_396 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_396).car) = (Int_Form)(((* ((struct struct0x0851b408 *) cr)).max)));
(((* _sharp_pair_396).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_396);
})
);
((List__O__Form__C____type__type ) _sharp_pair_397);
})
));
(((* _sharp_pair_398).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_398);
})
);
((List__O__Form__C____type__type ) _sharp_pair_399);
})
);
})
)));
(final_cond = (Compound_Form)(intern( "@or"), ({
struct struct0x080663e8 *_sharp_pair_401;
_sharp_pair_401,
(_sharp_pair_401 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_401).car) = cond);
(((* _sharp_pair_401).cdr) = ({
struct struct0x080663e8 *_sharp_pair_400;
_sharp_pair_400,
(_sharp_pair_400 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_400).car) = final_cond);
(((* _sharp_pair_400).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_400);
})
);
((List__O__Form__C____type__type ) _sharp_pair_401);
})
));
})
;
((void) 0);_sharp__sharp_loop390_continue402:((void) 0);
(_sharp_iterator389 = ((* ((struct struct0x0851e1e0 *) _sharp_iterator389)).cdr));
})
,
({goto _sharp__sharp_loop390_begin403;}),
((void) 0);_sharp__sharp_loop390_end391:((void) 0);
})
;
final_cond;
})
;}

String__type  function_name_from_grammar_and_rule(Symbol__type  grammar_name, Symbol__type  rule_name)
{
return ({
(concat)(((String__type) &__string_10), (concat)((get_symbol_name)((convert_id)(grammar_name)), (concat)(((String__type) &__string_11), (get_symbol_name)((convert_id)(rule_name)))));
})
;}

Exit__type  parse_error(void)
{
return ({
(print_String)(((String__type) &__string_12)),
(maybe_flush)();
(exit)(3);
((Exit__type ) 3);
})
;}

Character_Set__type  head_set(Form__type  parse_form, List__O__Form__C____type__type  next_rules)
{
return ({
Character_Set__type cs;
cs;
(((is_compound_form)(parse_form))?
(({
Compound_Form__type cf;
(cf = ((Compound_Form__type ) parse_form));
(((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "[]")))?
(({
(cs = (make_Character_Set)(((Form__type ) cf)));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "[^]")))?
(({
(cs = (make_inverse_Character_Set)(((Form__type ) cf)));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( " ")))?
(({
(cs = (head_set)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head), ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail)));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "<>")))?
(({
(cs = (head_set)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail))).head), next_rules));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "|")))?
(({
List__O__pointer__O__Void__C____C____type__type cs_;
({if( ((((* ((struct struct0x0805ee90 *) cf)).form_list) != ((List__O__Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_13)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x080663e8 *_sharp_pair_410;
_sharp_pair_410,
(_sharp_pair_410 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_410).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x080663e8 *_sharp_pair_405;
_sharp_pair_405,
(_sharp_pair_405 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_405).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_405).cdr) = ({
struct struct0x080663e8 *_sharp_pair_404;
_sharp_pair_404,
(_sharp_pair_404 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_404).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_404).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_404);
})
);
((List__O__Form__C____type__type ) _sharp_pair_405);
})
));
(((* _sharp_pair_410).cdr) = ({
struct struct0x080663e8 *_sharp_pair_409;
_sharp_pair_409,
(_sharp_pair_409 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_409).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080663e8 *_sharp_pair_408;
_sharp_pair_408,
(_sharp_pair_408 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_408).car) = (Compound_Form)(intern( "List"), ({
struct struct0x080663e8 *_sharp_pair_406;
_sharp_pair_406,
(_sharp_pair_406 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_406).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_406).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_406);
})
));
(((* _sharp_pair_408).cdr) = ({
struct struct0x080663e8 *_sharp_pair_407;
_sharp_pair_407,
(_sharp_pair_407 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_407).car) = (Int_Form)(0));
(((* _sharp_pair_407).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_407);
})
);
((List__O__Form__C____type__type ) _sharp_pair_408);
})
));
(((* _sharp_pair_409).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_409);
})
);
((List__O__Form__C____type__type ) _sharp_pair_410);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_14)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(cs_ = ((List__O__pointer__O__Void__C____C____type__type ) (head_set)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head), next_rules)));
({
List__O__Form__C____type__type _sharp_iterator412;
(_sharp_iterator412 = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail));
((void) 0);_sharp__sharp_loop413_begin416:((void) 0),
({
Form__type rule;
({if( (_sharp_iterator412 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop413_end414;});}})
;
(rule = ((* ((struct struct0x080663e8 *) _sharp_iterator412)).car));
({
(cs_ = (append)(((List__O__pointer__O__Void__C____C____type__type ) (head_set)(rule, next_rules)), cs_));
})
;
((void) 0);_sharp__sharp_loop413_continue415:((void) 0);
(_sharp_iterator412 = ((* ((struct struct0x080663e8 *) _sharp_iterator412)).cdr));
})
,
({goto _sharp__sharp_loop413_begin416;}),
((void) 0);_sharp__sharp_loop413_end414:((void) 0);
})
;
(cs = (sort_Character_Set)(((List__O__Character_Range__C____type__type ) cs_)));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "*")))?
(({
List__O__pointer__O__Void__C____C____type__type cs_;
(print_form)(((Form__type ) cf));
(cs_ = (append)(((List__O__pointer__O__Void__C____C____type__type ) (head_set)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head), ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail))), ((List__O__pointer__O__Void__C____C____type__type ) (head_set)(((* ((struct struct0x0805f088 *) next_rules)).head), ((* ((struct struct0x0805f088 *) next_rules)).tail)))));
(cs = (sort_Character_Set)(((List__O__Character_Range__C____type__type ) cs_)));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "+")))?
(({
(cs = (head_set)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head), ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail)));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "{}")))?
(({
({if( (next_rules == ((List__O__Form__C____type__type ) 0)))
{
({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_15)),
(print_String)(((String__type) &__string_16)),
(maybe_flush)();
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
(cs = (head_set)(((* ((struct struct0x0805f088 *) next_rules)).head), ((* ((struct struct0x0805f088 *) next_rules)).tail)));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( ".")))?
(({
Symbol__type save_grammar_name;
Symbol__type rule_name;
(save_grammar_name = grammar_name);
(grammar_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head)))).value));
(rule_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail))).head)))).value));
({if( ((((Hash__O__Symbol__c__Character_Set__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))) != ((Hash__O__Symbol__c__Character_Set__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_17)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x080663e8 *_sharp_pair_424;
_sharp_pair_424,
(_sharp_pair_424 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_424).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x080663e8 *_sharp_pair_418;
_sharp_pair_418,
(_sharp_pair_418 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_418).car) = (Id_Form)(intern( "head_set_hash")));
(((* _sharp_pair_418).cdr) = ({
struct struct0x080663e8 *_sharp_pair_417;
_sharp_pair_417,
(_sharp_pair_417 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_417).car) = (Id_Form)(intern( "grammar_name")));
(((* _sharp_pair_417).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_417);
})
);
((List__O__Form__C____type__type ) _sharp_pair_418);
})
));
(((* _sharp_pair_424).cdr) = ({
struct struct0x080663e8 *_sharp_pair_423;
_sharp_pair_423,
(_sharp_pair_423 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_423).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080663e8 *_sharp_pair_422;
_sharp_pair_422,
(_sharp_pair_422 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_422).car) = (Compound_Form)(intern( "Hash"), ({
struct struct0x080663e8 *_sharp_pair_420;
_sharp_pair_420,
(_sharp_pair_420 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_420).car) = (Id_Form)(intern( "Symbol")));
(((* _sharp_pair_420).cdr) = ({
struct struct0x080663e8 *_sharp_pair_419;
_sharp_pair_419,
(_sharp_pair_419 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_419).car) = (Id_Form)(intern( "Character_Set")));
(((* _sharp_pair_419).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_419);
})
);
((List__O__Form__C____type__type ) _sharp_pair_420);
})
));
(((* _sharp_pair_422).cdr) = ({
struct struct0x080663e8 *_sharp_pair_421;
_sharp_pair_421,
(_sharp_pair_421 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_421).car) = (Int_Form)(0));
(((* _sharp_pair_421).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_421);
})
);
((List__O__Form__C____type__type ) _sharp_pair_422);
})
));
(((* _sharp_pair_423).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_423);
})
);
((List__O__Form__C____type__type ) _sharp_pair_424);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_18)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(cs = ((Character_Set__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__Character_Set__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash)))))));
({if( (cs == ((Character_Set__type ) 0)))
{
({
Form__type named_rule;
((Character_Set__type ) (puthash)(((void *) rule_name), ((void *) ((Character_Set__type ) (- (int) 1))), ((Hash_Table__type ) ((Hash__O__Symbol__c__Character_Set__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
(named_rule = ((Form__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash)))))));
({if( (named_rule == ((Form__type ) 0)))
{
({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_19)),
(print_String)(((String__type) &__string_20)),
(print_Symbol)(rule_name),
(print_String)(((String__type) &__string_21)),
(maybe_flush)();
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
(cs = (head_set)(named_rule, ((List__O__Form__C____type__type ) 0)));
({if( (cs == ((Character_Set__type ) (- (int) 1))))
{
({
(print_String)(((String__type) &__string_22)),
(print_Symbol)(rule_name),
(print_String)(((String__type) &__string_23)),
(maybe_flush)();
(exit)(3);
})
;}})
;
((Character_Set__type ) (puthash)(((void *) rule_name), ((void *) cs), ((Hash_Table__type ) ((Hash__O__Symbol__c__Character_Set__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
})
;}})
;
(grammar_name = save_grammar_name);
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "@")))?
(({
Form__type grammar_form;
Symbol__type form_head;
Form__type form;
(form = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head));
({if( ((is_compound_form)(form) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_24)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x080663e8 *_sharp_pair_425;
_sharp_pair_425,
(_sharp_pair_425 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_425).car) = (Id_Form)(intern( "form")));
(((* _sharp_pair_425).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_425);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_25)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(form_head = ((* ((struct struct0x0805ee90 *) ((Compound_Form__type ) form))).head));
(grammar_form = (call_grammar_macro)(form_head, form));
(cs = (head_set)(grammar_form, next_rules));
((void) 0);
})
):
(({
(print_String)(((String__type) &__string_26)),
(print_Symbol)(((* ((struct struct0x0805ee90 *) cf)).head)),
(print_String)(((String__type) &__string_27)),
(maybe_flush)();
(print_form)(parse_form);
(exit)(3);
})
))))))))))))))))))));
})
):
((((is_id_form)(parse_form))?
(({
Symbol__type rule_name;
(rule_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) parse_form))).value));
(((rule_name == intern( "_")))?
(({
({if( (next_rules == ((List__O__Form__C____type__type ) 0)))
{
({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_28)),
(print_String)(((String__type) &__string_29)),
(maybe_flush)();
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
(cs = (head_set)(((* ((struct struct0x0805f088 *) next_rules)).head), ((* ((struct struct0x0805f088 *) next_rules)).tail)));
((void) 0);
})
):
(({
({if( ((((Hash__O__Symbol__c__Character_Set__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))) != ((Hash__O__Symbol__c__Character_Set__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_30)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x080663e8 *_sharp_pair_433;
_sharp_pair_433,
(_sharp_pair_433 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_433).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x080663e8 *_sharp_pair_427;
_sharp_pair_427,
(_sharp_pair_427 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_427).car) = (Id_Form)(intern( "head_set_hash")));
(((* _sharp_pair_427).cdr) = ({
struct struct0x080663e8 *_sharp_pair_426;
_sharp_pair_426,
(_sharp_pair_426 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_426).car) = (Id_Form)(intern( "grammar_name")));
(((* _sharp_pair_426).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_426);
})
);
((List__O__Form__C____type__type ) _sharp_pair_427);
})
));
(((* _sharp_pair_433).cdr) = ({
struct struct0x080663e8 *_sharp_pair_432;
_sharp_pair_432,
(_sharp_pair_432 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_432).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080663e8 *_sharp_pair_431;
_sharp_pair_431,
(_sharp_pair_431 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_431).car) = (Compound_Form)(intern( "Hash"), ({
struct struct0x080663e8 *_sharp_pair_429;
_sharp_pair_429,
(_sharp_pair_429 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_429).car) = (Id_Form)(intern( "Symbol")));
(((* _sharp_pair_429).cdr) = ({
struct struct0x080663e8 *_sharp_pair_428;
_sharp_pair_428,
(_sharp_pair_428 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_428).car) = (Id_Form)(intern( "Character_Set")));
(((* _sharp_pair_428).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_428);
})
);
((List__O__Form__C____type__type ) _sharp_pair_429);
})
));
(((* _sharp_pair_431).cdr) = ({
struct struct0x080663e8 *_sharp_pair_430;
_sharp_pair_430,
(_sharp_pair_430 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_430).car) = (Int_Form)(0));
(((* _sharp_pair_430).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_430);
})
);
((List__O__Form__C____type__type ) _sharp_pair_431);
})
));
(((* _sharp_pair_432).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_432);
})
);
((List__O__Form__C____type__type ) _sharp_pair_433);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_31)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(cs = ((Character_Set__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__Character_Set__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash)))))));
({if( (cs == ((Character_Set__type ) 0)))
{
({
Form__type named_rule;
((Character_Set__type ) (puthash)(((void *) rule_name), ((void *) ((Character_Set__type ) (- (int) 1))), ((Hash_Table__type ) ((Hash__O__Symbol__c__Character_Set__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
(named_rule = ((Form__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash)))))));
({if( (named_rule == ((Form__type ) 0)))
{
({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_32)),
(print_String)(((String__type) &__string_33)),
(print_Symbol)(rule_name),
(print_String)(((String__type) &__string_34)),
(maybe_flush)();
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
(cs = (head_set)(named_rule, ((List__O__Form__C____type__type ) 0)));
({if( (cs == ((Character_Set__type ) (- (int) 1))))
{
({
(print_String)(((String__type) &__string_35)),
(print_Symbol)(rule_name),
(print_String)(((String__type) &__string_36)),
(maybe_flush)();
(exit)(3);
})
;}})
;
((Character_Set__type ) (puthash)(((void *) rule_name), ((void *) cs), ((Hash_Table__type ) ((Hash__O__Symbol__c__Character_Set__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
})
;}})
;
((void) 0);
})
));
})
):
((((is_string_form)(parse_form))?
(({
struct struct0x0851b408 *_sharp_pointer_alloc434;
Int__type head;
(head = (string_element)(((* ((struct struct0x0805baa0 *) ((String_Form__type ) parse_form))).value), 0));
(cs = ((Character_Set__type ) ({
struct struct0x0851e1e0 *_sharp_pair_435;
_sharp_pair_435,
(_sharp_pair_435 = ((struct struct0x0851e1e0 *) (alloc_cons_cell)()));
(((* _sharp_pair_435).car) = ((Character_Range__type ) _sharp_pointer_alloc434,
(_sharp_pointer_alloc434 = ((struct struct0x0851b408 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc434) = ((struct struct0x0851b408 ){head, head})),
((struct struct0x0851b408 *) _sharp_pointer_alloc434)));
(((* _sharp_pair_435).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_435);
})
));
((void) 0);
})
):
((((is_symbol_form)(parse_form))?
(({
struct struct0x0851b408 *_sharp_pointer_alloc436;
Int__type head;
(head = (string_element)((get_symbol_name)(((* ((struct struct0x08059be8 *) ((Symbol_Form__type ) parse_form))).value)), 0));
(cs = ((Character_Set__type ) ({
struct struct0x0851e1e0 *_sharp_pair_437;
_sharp_pair_437,
(_sharp_pair_437 = ((struct struct0x0851e1e0 *) (alloc_cons_cell)()));
(((* _sharp_pair_437).car) = ((Character_Range__type ) _sharp_pointer_alloc436,
(_sharp_pointer_alloc436 = ((struct struct0x0851b408 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc436) = ((struct struct0x0851b408 ){head, head})),
((struct struct0x0851b408 *) _sharp_pointer_alloc436)));
(((* _sharp_pair_437).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_437);
})
));
((void) 0);
})
):
(({
(print_String)(((String__type) &__string_37)),
(maybe_flush)();
(print_form)(parse_form);
(exit)(3);
})
))))))));
cs;
})
;}

Form__type  grammar_expander_rec(Form__type  parse_form, List__O__Form__C____type__type  next_rules)
{
return ({
(((is_compound_form)(parse_form))?
(({
Compound_Form__type cf;
(cf = ((Compound_Form__type ) parse_form));
(((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "[]")))||((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "[^]")))))?
(({
(Compound_Form)(intern( "read_char"), ((List__O__Form__C____type__type ) 0));
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "<>")))?
(({
Expanded_Form__type exp_right_form;
Form__type subrule;
Form__type left_form;
Id_Form__type id_form;
Symbol__type id;
Form__type right_form;
(id_form = ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head)));
(id = ((* ((struct struct0x08059be8 *) id_form)).value));
(left_form = ((Form__type ) id_form));
(subrule = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail))).head));
(right_form = (grammar_expander_rec)(subrule, next_rules));
({if( (((is_compound_form)(subrule))&&((((((* ((struct struct0x0805ee90 *) ((Compound_Form__type ) subrule))).head) == intern( "*")))||((((* ((struct struct0x0805ee90 *) ((Compound_Form__type ) subrule))).head) == intern( "+")))))))
{
({
(right_form = (Compound_Form)(intern( "make_list"), ({
struct struct0x080663e8 *_sharp_pair_438;
_sharp_pair_438,
(_sharp_pair_438 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_438).car) = right_form);
(((* _sharp_pair_438).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_438);
})
));
})
;}})
;
(exp_right_form = (expand)(right_form));
({if( (((Type__type ) (gethash)(((void *) id), ((Hash_Table__type ) id_used))) == ((Type__type ) 0)))
{
({
((Type__type ) (puthash)(((void *) id), ((void *) ((Type__type ) 1)), ((Hash_Table__type ) id_used)));
(expand)((Compound_Form)(intern( "let"), ({
struct struct0x080663e8 *_sharp_pair_440;
_sharp_pair_440,
(_sharp_pair_440 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_440).car) = ((Form__type ) id_form));
(((* _sharp_pair_440).cdr) = ({
struct struct0x080663e8 *_sharp_pair_439;
_sharp_pair_439,
(_sharp_pair_439 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_439).car) = (((struct struct0x08064ef0 ) ((* ((struct struct0x08065108 *) ((Real_Type__type ) ((* ((struct struct0x0805f900 *) exp_right_form)).type)))).common_)).type_form));
(((* _sharp_pair_439).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_439);
})
);
((List__O__Form__C____type__type ) _sharp_pair_440);
})
));
})
;}})
;
(Compound_Form)(intern( "="), ({
struct struct0x080663e8 *_sharp_pair_442;
_sharp_pair_442,
(_sharp_pair_442 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_442).car) = left_form);
(((* _sharp_pair_442).cdr) = ({
struct struct0x080663e8 *_sharp_pair_441;
_sharp_pair_441,
(_sharp_pair_441 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_441).car) = ((Form__type ) exp_right_form));
(((* _sharp_pair_441).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_441);
})
);
((List__O__Form__C____type__type ) _sharp_pair_442);
})
);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "{}")))?
(({
(Compound_Form)(intern( "seq"), ((* ((struct struct0x0805ee90 *) cf)).form_list));
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( " ")))?
(({
void **_sharp_make_list_ptr444;
List__O__Form__C____type__type fl;
(fl = ({
List__O__Form__C____type__type _sharp_make_list443;
_sharp_make_list443,
_sharp_make_list_ptr444,
(_sharp_make_list_ptr444 = ((void *) (&_sharp_make_list443))),
({
List__O__Form__C____type__type grammar_rule_it;
(grammar_rule_it = ((* ((struct struct0x0805ee90 *) cf)).form_list));
((void) 0);_sharp__sharp_loop445_begin447:((void) 0),
({if( (!((grammar_rule_it != ((List__O__Form__C____type__type ) 0)))))
{
({goto _sharp__sharp_loop445_end446;});}})
,
({
List__O__Form__C____type__type grammar_tail;
Form__type grammar_rule;
(grammar_rule = ((* ((struct struct0x0805f088 *) grammar_rule_it)).head));
(grammar_tail = ((* ((struct struct0x0805f088 *) grammar_rule_it)).tail));
((* _sharp_make_list_ptr444) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr444))).car) = ((void *) (grammar_expander_rec)(grammar_rule, grammar_tail))),
(_sharp_make_list_ptr444 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr444))).cdr))),
((void) 0);
(grammar_rule_it = grammar_tail);
})
,
({goto _sharp__sharp_loop445_begin447;}),
((void) 0);_sharp__sharp_loop445_end446:((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr444) = ((void *) 0)),
_sharp_make_list443;
})
);
(Compound_Form)(intern( "seq"), fl);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "|")))?
(({
Form__type else_form;
Form__type peeked_char_form;
Symbol__type peeked_char;
(peeked_char = (gensym)(((String__type) &__string_38)));
(peeked_char_form = (Id_Form)(peeked_char));
(else_form = (Compound_Form)(intern( "parse_error"), ((List__O__Form__C____type__type ) 0)));
({
List__O__Form__C____type__type _sharp_iterator449;
(_sharp_iterator449 = ((* ((struct struct0x0805ee90 *) cf)).form_list));
((void) 0);_sharp__sharp_loop450_begin456:((void) 0),
({
Form__type grammar_rule;
({if( (_sharp_iterator449 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop450_end451;});}})
;
(grammar_rule = ((* ((struct struct0x080663e8 *) _sharp_iterator449)).car));
({
Character_Set__type char_set;
(char_set = (head_set)(grammar_rule, next_rules));
(else_form = (Compound_Form)(intern( "if"), ({
struct struct0x080663e8 *_sharp_pair_454;
_sharp_pair_454,
(_sharp_pair_454 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_454).car) = (is_in_Character_Set_condition)(peeked_char_form, char_set));
(((* _sharp_pair_454).cdr) = ({
struct struct0x080663e8 *_sharp_pair_453;
_sharp_pair_453,
(_sharp_pair_453 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_453).car) = (grammar_expander_rec)(grammar_rule, next_rules));
(((* _sharp_pair_453).cdr) = ({
struct struct0x080663e8 *_sharp_pair_452;
_sharp_pair_452,
(_sharp_pair_452 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_452).car) = else_form);
(((* _sharp_pair_452).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_452);
})
);
((List__O__Form__C____type__type ) _sharp_pair_453);
})
);
((List__O__Form__C____type__type ) _sharp_pair_454);
})
));
})
;
((void) 0);_sharp__sharp_loop450_continue455:((void) 0);
(_sharp_iterator449 = ((* ((struct struct0x080663e8 *) _sharp_iterator449)).cdr));
})
,
({goto _sharp__sharp_loop450_begin456;}),
((void) 0);_sharp__sharp_loop450_end451:((void) 0);
})
;
(Compound_Form)(intern( "block"), ({
struct struct0x080663e8 *_sharp_pair_461;
_sharp_pair_461,
(_sharp_pair_461 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_461).car) = (Compound_Form)(intern( "="), ({
struct struct0x080663e8 *_sharp_pair_459;
_sharp_pair_459,
(_sharp_pair_459 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_459).car) = (Compound_Form)(intern( "let"), ({
struct struct0x080663e8 *_sharp_pair_457;
_sharp_pair_457,
(_sharp_pair_457 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_457).car) = peeked_char_form);
(((* _sharp_pair_457).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_457);
})
));
(((* _sharp_pair_459).cdr) = ({
struct struct0x080663e8 *_sharp_pair_458;
_sharp_pair_458,
(_sharp_pair_458 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_458).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_458).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_458);
})
);
((List__O__Form__C____type__type ) _sharp_pair_459);
})
));
(((* _sharp_pair_461).cdr) = ({
struct struct0x080663e8 *_sharp_pair_460;
_sharp_pair_460,
(_sharp_pair_460 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_460).car) = else_form);
(((* _sharp_pair_460).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_460);
})
);
((List__O__Form__C____type__type ) _sharp_pair_461);
})
);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "*")))?
(({
Form__type repeated_rule;
Character_Set__type char_set;
Form__type peeked_char_form;
Symbol__type peeked_char;
(repeated_rule = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head));
(char_set = (head_set)(repeated_rule, ((List__O__Form__C____type__type ) 0)));
(peeked_char = (gensym)(((String__type) &__string_39)));
(peeked_char_form = (Id_Form)(peeked_char));
(Compound_Form)(intern( "loop"), ({
struct struct0x080663e8 *_sharp_pair_471;
_sharp_pair_471,
(_sharp_pair_471 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_471).car) = (Compound_Form)(intern( "block"), ({
struct struct0x080663e8 *_sharp_pair_470;
_sharp_pair_470,
(_sharp_pair_470 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_470).car) = (Compound_Form)(intern( "="), ({
struct struct0x080663e8 *_sharp_pair_464;
_sharp_pair_464,
(_sharp_pair_464 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_464).car) = (Compound_Form)(intern( "let"), ({
struct struct0x080663e8 *_sharp_pair_462;
_sharp_pair_462,
(_sharp_pair_462 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_462).car) = peeked_char_form);
(((* _sharp_pair_462).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_462);
})
));
(((* _sharp_pair_464).cdr) = ({
struct struct0x080663e8 *_sharp_pair_463;
_sharp_pair_463,
(_sharp_pair_463 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_463).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_463).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_463);
})
);
((List__O__Form__C____type__type ) _sharp_pair_464);
})
));
(((* _sharp_pair_470).cdr) = ({
struct struct0x080663e8 *_sharp_pair_469;
_sharp_pair_469,
(_sharp_pair_469 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_469).car) = (Compound_Form)(intern( "if"), ({
struct struct0x080663e8 *_sharp_pair_467;
_sharp_pair_467,
(_sharp_pair_467 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_467).car) = (Compound_Form)(intern( "@not"), ({
struct struct0x080663e8 *_sharp_pair_465;
_sharp_pair_465,
(_sharp_pair_465 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_465).car) = (is_in_Character_Set_condition)(peeked_char_form, char_set));
(((* _sharp_pair_465).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_465);
})
));
(((* _sharp_pair_467).cdr) = ({
struct struct0x080663e8 *_sharp_pair_466;
_sharp_pair_466,
(_sharp_pair_466 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_466).car) = (Compound_Form)(intern( "break"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_466).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_466);
})
);
((List__O__Form__C____type__type ) _sharp_pair_467);
})
));
(((* _sharp_pair_469).cdr) = ({
struct struct0x080663e8 *_sharp_pair_468;
_sharp_pair_468,
(_sharp_pair_468 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_468).car) = (grammar_expander_rec)(repeated_rule, next_rules));
(((* _sharp_pair_468).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_468);
})
);
((List__O__Form__C____type__type ) _sharp_pair_469);
})
);
((List__O__Form__C____type__type ) _sharp_pair_470);
})
));
(((* _sharp_pair_471).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_471);
})
);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "+")))?
(({
Form__type repeated_rule;
Character_Set__type char_set;
Form__type peeked_char_form;
Symbol__type peeked_char;
(repeated_rule = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head));
(char_set = (head_set)(repeated_rule, ((List__O__Form__C____type__type ) 0)));
(peeked_char = (gensym)(((String__type) &__string_40)));
(peeked_char_form = (Id_Form)(peeked_char));
(Compound_Form)(intern( "loop"), ({
struct struct0x080663e8 *_sharp_pair_481;
_sharp_pair_481,
(_sharp_pair_481 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_481).car) = (Compound_Form)(intern( "block"), ({
struct struct0x080663e8 *_sharp_pair_480;
_sharp_pair_480,
(_sharp_pair_480 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_480).car) = (grammar_expander_rec)(repeated_rule, next_rules));
(((* _sharp_pair_480).cdr) = ({
struct struct0x080663e8 *_sharp_pair_479;
_sharp_pair_479,
(_sharp_pair_479 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_479).car) = (Compound_Form)(intern( "="), ({
struct struct0x080663e8 *_sharp_pair_474;
_sharp_pair_474,
(_sharp_pair_474 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_474).car) = (Compound_Form)(intern( "let"), ({
struct struct0x080663e8 *_sharp_pair_472;
_sharp_pair_472,
(_sharp_pair_472 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_472).car) = peeked_char_form);
(((* _sharp_pair_472).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_472);
})
));
(((* _sharp_pair_474).cdr) = ({
struct struct0x080663e8 *_sharp_pair_473;
_sharp_pair_473,
(_sharp_pair_473 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_473).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_473).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_473);
})
);
((List__O__Form__C____type__type ) _sharp_pair_474);
})
));
(((* _sharp_pair_479).cdr) = ({
struct struct0x080663e8 *_sharp_pair_478;
_sharp_pair_478,
(_sharp_pair_478 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_478).car) = (Compound_Form)(intern( "if"), ({
struct struct0x080663e8 *_sharp_pair_477;
_sharp_pair_477,
(_sharp_pair_477 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_477).car) = (Compound_Form)(intern( "@not"), ({
struct struct0x080663e8 *_sharp_pair_475;
_sharp_pair_475,
(_sharp_pair_475 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_475).car) = (is_in_Character_Set_condition)(peeked_char_form, char_set));
(((* _sharp_pair_475).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_475);
})
));
(((* _sharp_pair_477).cdr) = ({
struct struct0x080663e8 *_sharp_pair_476;
_sharp_pair_476,
(_sharp_pair_476 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_476).car) = (Compound_Form)(intern( "break"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_476).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_476);
})
);
((List__O__Form__C____type__type ) _sharp_pair_477);
})
));
(((* _sharp_pair_478).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_478);
})
);
((List__O__Form__C____type__type ) _sharp_pair_479);
})
);
((List__O__Form__C____type__type ) _sharp_pair_480);
})
));
(((* _sharp_pair_481).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_481);
})
);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "?")))?
(({
Character_Set__type char_set;
Form__type peeked_char_form;
Symbol__type peeked_char;
Form__type maybe_rule;
(maybe_rule = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head));
(char_set = (head_set)(maybe_rule, ((List__O__Form__C____type__type ) 0)));
(peeked_char = (gensym)(((String__type) &__string_41)));
(peeked_char_form = (Id_Form)(peeked_char));
(Compound_Form)(intern( "block"), ({
struct struct0x080663e8 *_sharp_pair_488;
_sharp_pair_488,
(_sharp_pair_488 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_488).car) = (Compound_Form)(intern( "="), ({
struct struct0x080663e8 *_sharp_pair_484;
_sharp_pair_484,
(_sharp_pair_484 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_484).car) = (Compound_Form)(intern( "let"), ({
struct struct0x080663e8 *_sharp_pair_482;
_sharp_pair_482,
(_sharp_pair_482 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_482).car) = peeked_char_form);
(((* _sharp_pair_482).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_482);
})
));
(((* _sharp_pair_484).cdr) = ({
struct struct0x080663e8 *_sharp_pair_483;
_sharp_pair_483,
(_sharp_pair_483 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_483).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_483).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_483);
})
);
((List__O__Form__C____type__type ) _sharp_pair_484);
})
));
(((* _sharp_pair_488).cdr) = ({
struct struct0x080663e8 *_sharp_pair_487;
_sharp_pair_487,
(_sharp_pair_487 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_487).car) = (Compound_Form)(intern( "if"), ({
struct struct0x080663e8 *_sharp_pair_486;
_sharp_pair_486,
(_sharp_pair_486 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_486).car) = (is_in_Character_Set_condition)(peeked_char_form, char_set));
(((* _sharp_pair_486).cdr) = ({
struct struct0x080663e8 *_sharp_pair_485;
_sharp_pair_485,
(_sharp_pair_485 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_485).car) = (grammar_expander_rec)(maybe_rule, next_rules));
(((* _sharp_pair_485).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_485);
})
);
((List__O__Form__C____type__type ) _sharp_pair_486);
})
));
(((* _sharp_pair_487).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_487);
})
);
((List__O__Form__C____type__type ) _sharp_pair_488);
})
);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( ".")))?
(({
Symbol__type gram_name;
Symbol__type rule_name;
(gram_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head)))).value));
(rule_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail))).head)))).value));
(Compound_Form)(intern( "funcall"), ({
struct struct0x080663e8 *_sharp_pair_489;
_sharp_pair_489,
(_sharp_pair_489 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_489).car) = (Id_Form)((intern_string)((function_name_from_grammar_and_rule)(gram_name, rule_name))));
(((* _sharp_pair_489).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_489);
})
);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "@")))?
(({
Form__type grammar_form;
Symbol__type form_head;
Form__type form;
(form = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head));
({if( ((is_compound_form)(form) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_42)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x080663e8 *_sharp_pair_490;
_sharp_pair_490,
(_sharp_pair_490 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_490).car) = (Id_Form)(intern( "form")));
(((* _sharp_pair_490).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_490);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_43)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(form_head = ((* ((struct struct0x0805ee90 *) ((Compound_Form__type ) form))).head));
(grammar_form = (call_grammar_macro)(form_head, form));
(grammar_expander_rec)(grammar_form, next_rules);
})
):
(({
(print_form)(((Form__type ) cf));
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_44)),
(print_String)(((String__type) &__string_45)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;
(Id_Form)(intern( "imp"));
})
))))))))))))))))))));
})
):
((((is_id_form)(parse_form))?
(({
Symbol_Form__type id_form;
(id_form = ((Symbol_Form__type ) parse_form));
(((((* ((struct struct0x08059be8 *) id_form)).value) == intern( "_")))?
(({
(Compound_Form)(intern( "funcall"), ({
struct struct0x080663e8 *_sharp_pair_491;
_sharp_pair_491,
(_sharp_pair_491 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_491).car) = (Id_Form)(intern( "get_point_pos")));
(((* _sharp_pair_491).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_491);
})
);
})
):
((((((* ((struct struct0x08059be8 *) id_form)).value) == intern( ".")))?
(({
(Compound_Form)(intern( "read_char"), ((List__O__Form__C____type__type ) 0));
})
):
((Compound_Form)(intern( "funcall"), ({
struct struct0x080663e8 *_sharp_pair_492;
_sharp_pair_492,
(_sharp_pair_492 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_492).car) = (Id_Form)((intern_string)((function_name_from_grammar_and_rule)(grammar_name, ((* ((struct struct0x08059be8 *) id_form)).value)))));
(((* _sharp_pair_492).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_492);
})
)))));
})
):
((((is_string_form)(parse_form))?
(({
void **_sharp_make_list_ptr494;
List__O__Int__C____type__type cl;
List__O__Form__C____type__type form_list;
(cl = (string_to_int_list)(((* ((struct struct0x0805baa0 *) ((String_Form__type ) parse_form))).value)));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list493;
_sharp_make_list493,
_sharp_make_list_ptr494,
(_sharp_make_list_ptr494 = ((void *) (&_sharp_make_list493))),
({
({
List__O__Int__C____type__type _sharp_iterator496;
(_sharp_iterator496 = cl);
((void) 0);_sharp__sharp_loop497_begin500:((void) 0),
({
Int__type Int;
({if( (_sharp_iterator496 == ((List__O__Int__C____type__type ) 0)))
{
({goto _sharp__sharp_loop497_end498;});}})
;
(Int = ((* ((struct struct0x085adbb8 *) _sharp_iterator496)).car));
({
((* _sharp_make_list_ptr494) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr494))).car) = ((void *) (Compound_Form)(intern( "read_char"), ((List__O__Form__C____type__type ) 0)))),
(_sharp_make_list_ptr494 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr494))).cdr))),
((void) 0);
})
;
((void) 0);_sharp__sharp_loop497_continue499:((void) 0);
(_sharp_iterator496 = ((* ((struct struct0x085adbb8 *) _sharp_iterator496)).cdr));
})
,
({goto _sharp__sharp_loop497_begin500;}),
((void) 0);_sharp__sharp_loop497_end498:((void) 0);
})
;
((void) 0);
})
,
((* _sharp_make_list_ptr494) = ((void *) 0)),
_sharp_make_list493;
})
);
(Compound_Form)(intern( "seq"), form_list);
})
):
((((is_symbol_form)(parse_form))?
(({
Symbol__type symbol;
(symbol = ((* ((struct struct0x08059be8 *) ((Symbol_Form__type ) parse_form))).value));
(Compound_Form)(intern( "parse_symbol"), ({
struct struct0x080663e8 *_sharp_pair_501;
_sharp_pair_501,
(_sharp_pair_501 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_501).car) = (String_Form)((get_symbol_name)(symbol)));
(((* _sharp_pair_501).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_501);
})
);
})
):
(({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_46)),
(print_String)(((String__type) &__string_47)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;
(print_form)(parse_form);
(Id_Form)(intern( "imp2"));
})
))))))));
})
;}

Form__type  expand_grammar_rule(Form__type  rule)
{
return ({
(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0));
})
;}

List__O__Form__C____type__type  expand_grammar_list(List__O__Compound_Form__C____type__type  grammar_list)
{
return ({
void **_sharp_make_list_ptr522;
List__O__Form__C____type__type form_list;
(rules_hash = ((Hash__O__Symbol__c__Hash__O__Symbol__c__Form__C____C____type__type ) (make_hash_table)()));
(head_set_hash = ((Hash__O__Symbol__c__Hash__O__Symbol__c__Character_Set__C____C____type__type ) (make_hash_table)()));
({
List__O__Compound_Form__C____type__type _sharp_iterator510;
(_sharp_iterator510 = grammar_list);
((void) 0);_sharp__sharp_loop511_begin520:((void) 0),
({
Compound_Form__type grammar;
({if( (_sharp_iterator510 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop511_end512;});}})
;
(grammar = ((* ((struct struct0x081fd6f8 *) _sharp_iterator510)).car));
({
List__O__Compound_Form__C____type__type rule_list;
(grammar_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) grammar)).form_list))).tail))).head)))).value));
((Hash__O__Symbol__c__Form__C____type__type ) (puthash)(((void *) grammar_name), ((void *) ((Hash__O__Symbol__c__Form__C____type__type ) (make_hash_table)())), ((Hash_Table__type ) rules_hash)));
((Hash__O__Symbol__c__Character_Set__C____type__type ) (puthash)(((void *) grammar_name), ((void *) ((Hash__O__Symbol__c__Character_Set__C____type__type ) (make_hash_table)())), ((Hash_Table__type ) head_set_hash)));
(rule_list = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) grammar)).form_list))).tail))).tail)));
({
List__O__Compound_Form__C____type__type _sharp_iterator514;
(_sharp_iterator514 = rule_list);
((void) 0);_sharp__sharp_loop515_begin518:((void) 0),
({
Compound_Form__type rule;
({if( (_sharp_iterator514 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop515_end516;});}})
;
(rule = ((* ((struct struct0x081fd6f8 *) _sharp_iterator514)).car));
({
Symbol__type rule_name;
Form__type form;
(rule_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).head)))).value));
(form = ((Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).tail))).tail))).head)));
((Form__type ) (puthash)(((void *) rule_name), ((void *) form), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash))))));
(pre_define_function)((intern_string)((function_name_from_grammar_and_rule)(grammar_name, rule_name)), ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).tail))).head));
})
;
((void) 0);_sharp__sharp_loop515_continue517:((void) 0);
(_sharp_iterator514 = ((* ((struct struct0x081fd6f8 *) _sharp_iterator514)).cdr));
})
,
({goto _sharp__sharp_loop515_begin518;}),
((void) 0);_sharp__sharp_loop515_end516:((void) 0);
})
;
})
;
((void) 0);_sharp__sharp_loop511_continue519:((void) 0);
(_sharp_iterator510 = ((* ((struct struct0x081fd6f8 *) _sharp_iterator510)).cdr));
})
,
({goto _sharp__sharp_loop511_begin520;}),
((void) 0);_sharp__sharp_loop511_end512:((void) 0);
})
;
(form_list = ({
List__O__Form__C____type__type _sharp_make_list521;
_sharp_make_list521,
_sharp_make_list_ptr522,
(_sharp_make_list_ptr522 = ((void *) (&_sharp_make_list521))),
({
({
List__O__Compound_Form__C____type__type _sharp_iterator524;
(_sharp_iterator524 = grammar_list);
((void) 0);_sharp__sharp_loop525_begin543:((void) 0),
({
Compound_Form__type grammar;
({if( (_sharp_iterator524 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop525_end526;});}})
;
(grammar = ((* ((struct struct0x081fd6f8 *) _sharp_iterator524)).car));
({
struct struct0x0851b408 *_sharp_pointer_alloc527;
List__O__Compound_Form__C____type__type rule_list;
(grammar_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) grammar)).form_list))).tail))).head)))).value));
(dot_character_set = ((Character_Set__type ) ({
struct struct0x0851e1e0 *_sharp_pair_528;
_sharp_pair_528,
(_sharp_pair_528 = ((struct struct0x0851e1e0 *) (alloc_cons_cell)()));
(((* _sharp_pair_528).car) = ((Character_Range__type ) _sharp_pointer_alloc527,
(_sharp_pointer_alloc527 = ((struct struct0x0851b408 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc527) = ((struct struct0x0851b408 ){1, 255})),
((struct struct0x0851b408 *) _sharp_pointer_alloc527)));
(((* _sharp_pair_528).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_528);
})
));
(rule_list = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) grammar)).form_list))).tail))).tail)));
({
List__O__Compound_Form__C____type__type _sharp_iterator530;
(_sharp_iterator530 = rule_list);
((void) 0);_sharp__sharp_loop531_begin541:((void) 0),
({
Compound_Form__type rule;
({if( (_sharp_iterator530 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop531_end532;});}})
;
(rule = ((* ((struct struct0x081fd6f8 *) _sharp_iterator530)).car));
({
Form__type function_form;
Expanded_Form__type exp_function_body;
Form__type function_body;
Symbol__type function_name;
Symbol__type rule_name;
Form__type form;
Form__type lambda_form;
(rule_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).head)))).value));
(function_name = (intern_string)((function_name_from_grammar_and_rule)(grammar_name, rule_name)));
(form = ((Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).tail))).tail))).head)));
(id_used = ((Hash__O__Symbol__c__Type__C____type__type ) (make_hash_table)()));
(declare_block_begin)();
(function_body = (grammar_expander_rec)(form, ((List__O__Form__C____type__type ) 0)));
(exp_function_body = (declare_block_end)(({
struct struct0x080663e8 *_sharp_pair_533;
_sharp_pair_533,
(_sharp_pair_533 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_533).car) = function_body);
(((* _sharp_pair_533).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_533);
})
));
(lambda_form = (Compound_Form)(intern( "lambda"), ({
struct struct0x080663e8 *_sharp_pair_536;
_sharp_pair_536,
(_sharp_pair_536 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_536).car) = (((struct struct0x08064ef0 ) ((* ((struct struct0x08065108 *) ((Real_Type__type ) ((* ((struct struct0x0805f900 *) exp_function_body)).type)))).common_)).type_form));
(((* _sharp_pair_536).cdr) = ({
struct struct0x080663e8 *_sharp_pair_535;
_sharp_pair_535,
(_sharp_pair_535 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_535).car) = (Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_535).cdr) = ({
struct struct0x080663e8 *_sharp_pair_534;
_sharp_pair_534,
(_sharp_pair_534 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_534).car) = ((* ((struct struct0x0805f900 *) exp_function_body)).return_form));
(((* _sharp_pair_534).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_534);
})
);
((List__O__Form__C____type__type ) _sharp_pair_535);
})
);
((List__O__Form__C____type__type ) _sharp_pair_536);
})
));
(function_form = (Compound_Form)(intern( "define"), ({
struct struct0x080663e8 *_sharp_pair_539;
_sharp_pair_539,
(_sharp_pair_539 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_539).car) = (Id_Form)(intern( "function")));
(((* _sharp_pair_539).cdr) = ({
struct struct0x080663e8 *_sharp_pair_538;
_sharp_pair_538,
(_sharp_pair_538 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_538).car) = (Id_Form)(function_name));
(((* _sharp_pair_538).cdr) = ({
struct struct0x080663e8 *_sharp_pair_537;
_sharp_pair_537,
(_sharp_pair_537 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_537).car) = lambda_form);
(((* _sharp_pair_537).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_537);
})
);
((List__O__Form__C____type__type ) _sharp_pair_538);
})
);
((List__O__Form__C____type__type ) _sharp_pair_539);
})
));
((* _sharp_make_list_ptr522) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr522))).car) = ((void *) function_form)),
(_sharp_make_list_ptr522 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr522))).cdr))),
((void) 0);
})
;
((void) 0);_sharp__sharp_loop531_continue540:((void) 0);
(_sharp_iterator530 = ((* ((struct struct0x081fd6f8 *) _sharp_iterator530)).cdr));
})
,
({goto _sharp__sharp_loop531_begin541;}),
((void) 0);_sharp__sharp_loop531_end532:((void) 0);
})
;
})
;
((void) 0);_sharp__sharp_loop525_continue542:((void) 0);
(_sharp_iterator524 = ((* ((struct struct0x081fd6f8 *) _sharp_iterator524)).cdr));
})
,
({goto _sharp__sharp_loop525_begin543;}),
((void) 0);_sharp__sharp_loop525_end526:((void) 0);
})
;
((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr522) = ((void *) 0)),
_sharp_make_list521;
})
);
form_list;
})
;}

void  test(void)
{
return ({
((void) 0);
})
;}

Form__type  parse_sharp__sharp_expander_function(Compound_Form__type  form)
{
return ({
Form__type rule_id_form;
Form__type grammar_id_form;
Compound_Form__type cf2;
Form__type form2;
Symbol__type rule;
Symbol__type grammar;
(form2 = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) form)).form_list))).head));
({if( ((is_compound_form)(form2) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_48)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x080663e8 *_sharp_pair_502;
_sharp_pair_502,
(_sharp_pair_502 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_502).car) = (Id_Form)(intern( "form2")));
(((* _sharp_pair_502).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_502);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_49)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(cf2 = ((Compound_Form__type ) form2));
(print_form)(form2);
({if( ((((* ((struct struct0x0805ee90 *) cf2)).head) == intern( "[]")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_50)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x080663e8 *_sharp_pair_506;
_sharp_pair_506,
(_sharp_pair_506 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_506).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x080663e8 *_sharp_pair_504;
_sharp_pair_504,
(_sharp_pair_504 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_504).car) = (Id_Form)(intern( "cf2")));
(((* _sharp_pair_504).cdr) = ({
struct struct0x080663e8 *_sharp_pair_503;
_sharp_pair_503,
(_sharp_pair_503 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_503).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_503).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_503);
})
);
((List__O__Form__C____type__type ) _sharp_pair_504);
})
));
(((* _sharp_pair_506).cdr) = ({
struct struct0x080663e8 *_sharp_pair_505;
_sharp_pair_505,
(_sharp_pair_505 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_505).car) = (Symbol_Form)(intern( "[]")));
(((* _sharp_pair_505).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_505);
})
);
((List__O__Form__C____type__type ) _sharp_pair_506);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_51)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(grammar_id_form = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf2)).form_list))).head));
(rule_id_form = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf2)).form_list))).tail))).head));
({if( ((is_id_form)(grammar_id_form) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_52)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x080663e8 *_sharp_pair_507;
_sharp_pair_507,
(_sharp_pair_507 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_507).car) = (Id_Form)(intern( "grammar_id_form")));
(((* _sharp_pair_507).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_507);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_53)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(grammar = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) grammar_id_form))).value));
(rule = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) rule_id_form))).value));
(Compound_Form)(intern( "funcall"), ({
struct struct0x080663e8 *_sharp_pair_508;
_sharp_pair_508,
(_sharp_pair_508 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_508).car) = (Id_Form)((intern_string)((function_name_from_grammar_and_rule)(grammar, rule))));
(((* _sharp_pair_508).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_508);
})
);
})
;}

Form__type  grammar_expander_sharp__sharp_expander_function(Compound_Form__type  form_)
{
return ({
Symbol__type rule;
Form__type form;
(id_used = ((Hash__O__Symbol__c__Type__C____type__type ) (make_hash_table)()));
(rule = ((* ((struct struct0x08059be8 *) ((Symbol_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) form_)).form_list))).head)))).value));
({if( (((Form__type ) (gethash)(((void *) rule), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash)))))) == ((Form__type ) 0)))
{
({
(print_String)(((String__type) &__string_54)),
(print_Symbol)(rule),
(maybe_flush)();
(exit)(3);
})
;}})
;
(grammar_name = intern( "parse_grammar"));
(form = (grammar_expander_rec)(((Form__type ) (gethash)(((void *) rule), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash)))))), ((List__O__Form__C____type__type ) 0)));
form;
})
;}

void init_grammar_expander(void){
define_expander( intern( "parse"), parse_sharp__sharp_expander_function);
define_expander( intern( "grammar_expander"), grammar_expander_sharp__sharp_expander_function);
}

void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( "TEST result: %d", test_ptr());flush();}
