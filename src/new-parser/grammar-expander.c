/* Automatically generated : do not edit!*/
#include "grammar-expander.inc"
Hash__O__Symbol__c__Type__C____type__type id_used;

Hash__O__Symbol__c__Form__C____type__type grammar_hash;

Character_Set__type dot_character_set;

Hash__O__Symbol__c__Form__C____type__type rules_hash;

Hash__O__Symbol__c__Character_Set__C____type__type head_set_hash;

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

Character_Set__type  make_Character_Set(Form__type  form_)
{
return ({
void **_sharp_make_list_ptr338;
List__O__Character_Range__C____type__type new_list;
Compound_Form__type form;
(form = ((Compound_Form__type ) form_));
(new_list = ({
List__O__Character_Range__C____type__type _sharp_make_list337;
_sharp_make_list337,
_sharp_make_list_ptr338,
(_sharp_make_list_ptr338 = ((void *) (&_sharp_make_list337))),
({
({
List__O__Form__C____type__type _sharp_iterator340;
(_sharp_iterator340 = ((* ((struct struct0x0805ef40 *) form)).form_list));
((void) 0);_sharp__sharp_loop341_begin355:((void) 0),
({
Form__type subform;
({if( (_sharp_iterator340 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop341_end342;});}})
;
(subform = ((* ((struct struct0x08065ce0 *) _sharp_iterator340)).car));
({
(((is_compound_form)(subform))?
(({
struct struct0x084d4998 *_sharp_pointer_alloc349;
Int_Form__type max_form;
Int_Form__type min_form;
Compound_Form__type cf;
(cf = ((Compound_Form__type ) subform));
(min_form = ((Int_Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).head)));
(max_form = ((Int_Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).tail))).head)));
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
struct struct0x08065ce0 *_sharp_pair_345;
_sharp_pair_345,
(_sharp_pair_345 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_345).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08065ce0 *_sharp_pair_344;
_sharp_pair_344,
(_sharp_pair_344 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_344).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_344).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_343;
_sharp_pair_343,
(_sharp_pair_343 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_343).car) = (Id_Form)(intern( "min_form")));
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
struct struct0x08065ce0 *_sharp_pair_348;
_sharp_pair_348,
(_sharp_pair_348 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_348).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08065ce0 *_sharp_pair_347;
_sharp_pair_347,
(_sharp_pair_347 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_347).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_347).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_346;
_sharp_pair_346,
(_sharp_pair_346 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_346).car) = (Id_Form)(intern( "max_form")));
(((* _sharp_pair_346).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_346);
})
);
((List__O__Form__C____type__type ) _sharp_pair_347);
})
));
(((* _sharp_pair_348).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_348);
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
((* _sharp_make_list_ptr338) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr338))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc349,
(_sharp_pointer_alloc349 = ((struct struct0x084d4998 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc349) = ((struct struct0x084d4998 ){((* ((struct struct0x0805e1c0 *) min_form)).value), ((* ((struct struct0x0805e1c0 *) max_form)).value)})),
((struct struct0x084d4998 *) _sharp_pointer_alloc349)))),
(_sharp_make_list_ptr338 = (&((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr338))).cdr))),
((void) 0);
})
):
(({
struct struct0x084d4998 *_sharp_pointer_alloc353;
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
struct struct0x08065ce0 *_sharp_pair_352;
_sharp_pair_352,
(_sharp_pair_352 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_352).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08065ce0 *_sharp_pair_351;
_sharp_pair_351,
(_sharp_pair_351 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_351).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_351).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_350;
_sharp_pair_350,
(_sharp_pair_350 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_350).car) = (Id_Form)(intern( "symbol_form")));
(((* _sharp_pair_350).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_350);
})
);
((List__O__Form__C____type__type ) _sharp_pair_351);
})
));
(((* _sharp_pair_352).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_352);
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
((* _sharp_make_list_ptr338) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr338))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc353,
(_sharp_pointer_alloc353 = ((struct struct0x084d4998 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc353) = ((struct struct0x084d4998 ){((* ((struct struct0x0805e1c0 *) symbol_form)).value), ((* ((struct struct0x0805e1c0 *) symbol_form)).value)})),
((struct struct0x084d4998 *) _sharp_pointer_alloc353)))),
(_sharp_make_list_ptr338 = (&((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr338))).cdr))),
((void) 0);
})
));
})
;
((void) 0);_sharp__sharp_loop341_continue354:((void) 0);
(_sharp_iterator340 = ((* ((struct struct0x08065ce0 *) _sharp_iterator340)).cdr));
})
,
({goto _sharp__sharp_loop341_begin355;}),
((void) 0);_sharp__sharp_loop341_end342:((void) 0);
})
;
((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr338) = ((void *) 0)),
_sharp_make_list337;
})
);
((Character_Set__type ) new_list);
})
;}

Character_Set__type  get_inverse_Character_Set(Character_Set__type  cs)
{
return ({
(((cs == ((Character_Set__type ) 0)))?
(({
struct struct0x084d4998 *_sharp_pointer_alloc356;
((Character_Set__type ) ({
struct struct0x084e8aa8 *_sharp_pair_357;
_sharp_pair_357,
(_sharp_pair_357 = ((struct struct0x084e8aa8 *) (alloc_cons_cell)()));
(((* _sharp_pair_357).car) = ((Character_Range__type ) _sharp_pointer_alloc356,
(_sharp_pointer_alloc356 = ((struct struct0x084d4998 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc356) = ((struct struct0x084d4998 ){1, 255})),
((struct struct0x084d4998 *) _sharp_pointer_alloc356)));
(((* _sharp_pair_357).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_357);
})
);
})
):
(({
void **_sharp_make_list_ptr359;
List__O__Character_Range__C____type__type inverse;
Character_Range__type first;
List__O__Character_Range__C____type__type csl;
(csl = ((List__O__Character_Range__C____type__type ) cs));
(first = ((* ((struct struct0x084d4d28 *) csl)).head));
(inverse = ({
List__O__Character_Range__C____type__type _sharp_make_list358;
_sharp_make_list358,
_sharp_make_list_ptr359,
(_sharp_make_list_ptr359 = ((void *) (&_sharp_make_list358))),
({
Int__type prec;
({if( (((* ((struct struct0x084d4998 *) first)).min) != 0))
{
({
struct struct0x084d4998 *_sharp_pointer_alloc360;
((* _sharp_make_list_ptr359) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr359))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc360,
(_sharp_pointer_alloc360 = ((struct struct0x084d4998 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc360) = ((struct struct0x084d4998 ){0, ((int) ((* ((struct struct0x084d4998 *) first)).min) - (int) 1)})),
((struct struct0x084d4998 *) _sharp_pointer_alloc360)))),
(_sharp_make_list_ptr359 = (&((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr359))).cdr))),
((void) 0);
})
;}})
;
(prec = ((int) ((* ((struct struct0x084d4998 *) first)).max) + (int) 1));
({
List__O__Character_Range__C____type__type _sharp_iterator362;
(_sharp_iterator362 = ((* ((struct struct0x084d4d28 *) csl)).tail));
((void) 0);_sharp__sharp_loop363_begin367:((void) 0),
({
Character_Range__type cr;
({if( (_sharp_iterator362 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop363_end364;});}})
;
(cr = ((* ((struct struct0x084e8aa8 *) _sharp_iterator362)).car));
({
struct struct0x084d4998 *_sharp_pointer_alloc365;
((* _sharp_make_list_ptr359) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr359))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc365,
(_sharp_pointer_alloc365 = ((struct struct0x084d4998 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc365) = ((struct struct0x084d4998 ){prec, ((int) ((* ((struct struct0x084d4998 *) cr)).min) - (int) 1)})),
((struct struct0x084d4998 *) _sharp_pointer_alloc365)))),
(_sharp_make_list_ptr359 = (&((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr359))).cdr))),
((void) 0);
(prec = ((int) ((* ((struct struct0x084d4998 *) cr)).max) + (int) 1));
})
;
((void) 0);_sharp__sharp_loop363_continue366:((void) 0);
(_sharp_iterator362 = ((* ((struct struct0x084e8aa8 *) _sharp_iterator362)).cdr));
})
,
({goto _sharp__sharp_loop363_begin367;}),
((void) 0);_sharp__sharp_loop363_end364:((void) 0);
})
;
({if( ((int) prec < (int) 256))
{
({
struct struct0x084d4998 *_sharp_pointer_alloc368;
((* _sharp_make_list_ptr359) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr359))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc368,
(_sharp_pointer_alloc368 = ((struct struct0x084d4998 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc368) = ((struct struct0x084d4998 ){prec, 255})),
((struct struct0x084d4998 *) _sharp_pointer_alloc368)))),
(_sharp_make_list_ptr359 = (&((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr359))).cdr))),
((void) 0);
})
;}})
;
((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr359) = ((void *) 0)),
_sharp_make_list358;
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
List__O__Character_Range__C____type__type _sharp_iterator370;
(_sharp_iterator370 = cl);
((void) 0);_sharp__sharp_loop371_begin374:((void) 0),
({
Character_Range__type cr;
({if( (_sharp_iterator370 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop371_end372;});}})
;
(cr = ((* ((struct struct0x084e8aa8 *) _sharp_iterator370)).car));
({
(print_String)(((String__type) &__string_7)),
(print_Int_Dec)(((* ((struct struct0x084d4998 *) cr)).min)),
(print_String)(((String__type) &__string_8)),
(print_Int_Dec)(((* ((struct struct0x084d4998 *) cr)).max)),
(print_String)(((String__type) &__string_9)),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop371_continue373:((void) 0);
(_sharp_iterator370 = ((* ((struct struct0x084e8aa8 *) _sharp_iterator370)).cdr));
})
,
({goto _sharp__sharp_loop371_begin374;}),
((void) 0);_sharp__sharp_loop371_end372:((void) 0);
})
;
})
;}

Form__type  is_in_Character_Set_condition(Form__type  id_form, Character_Set__type  cs)
{
return ({
Form__type final_cond;
(final_cond = (Compound_Form)(intern( "cast"), ({
struct struct0x08065ce0 *_sharp_pair_376;
_sharp_pair_376,
(_sharp_pair_376 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_376).car) = (Id_Form)(intern( "Bool")));
(((* _sharp_pair_376).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_375;
_sharp_pair_375,
(_sharp_pair_375 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_375).car) = (Int_Form)(0));
(((* _sharp_pair_375).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_375);
})
);
((List__O__Form__C____type__type ) _sharp_pair_376);
})
));
({
List__O__Character_Range__C____type__type _sharp_iterator378;
(_sharp_iterator378 = ((List__O__Character_Range__C____type__type ) cs));
((void) 0);_sharp__sharp_loop379_begin392:((void) 0),
({
Character_Range__type cr;
({if( (_sharp_iterator378 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop379_end380;});}})
;
(cr = ((* ((struct struct0x084e8aa8 *) _sharp_iterator378)).car));
({
Form__type cond;
(cond = (((((* ((struct struct0x084d4998 *) cr)).min) == ((* ((struct struct0x084d4998 *) cr)).max)))?
(({
(Compound_Form)(intern( "=="), ({
struct struct0x08065ce0 *_sharp_pair_382;
_sharp_pair_382,
(_sharp_pair_382 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_382).car) = id_form);
(((* _sharp_pair_382).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_381;
_sharp_pair_381,
(_sharp_pair_381 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_381).car) = (Int_Form)(((* ((struct struct0x084d4998 *) cr)).min)));
(((* _sharp_pair_381).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_381);
})
);
((List__O__Form__C____type__type ) _sharp_pair_382);
})
);
})
):
(({
(Compound_Form)(intern( "@and"), ({
struct struct0x08065ce0 *_sharp_pair_388;
_sharp_pair_388,
(_sharp_pair_388 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_388).car) = (Compound_Form)(intern( ">="), ({
struct struct0x08065ce0 *_sharp_pair_384;
_sharp_pair_384,
(_sharp_pair_384 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_384).car) = id_form);
(((* _sharp_pair_384).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_383;
_sharp_pair_383,
(_sharp_pair_383 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_383).car) = (Int_Form)(((* ((struct struct0x084d4998 *) cr)).min)));
(((* _sharp_pair_383).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_383);
})
);
((List__O__Form__C____type__type ) _sharp_pair_384);
})
));
(((* _sharp_pair_388).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_387;
_sharp_pair_387,
(_sharp_pair_387 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_387).car) = (Compound_Form)(intern( "<="), ({
struct struct0x08065ce0 *_sharp_pair_386;
_sharp_pair_386,
(_sharp_pair_386 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_386).car) = id_form);
(((* _sharp_pair_386).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_385;
_sharp_pair_385,
(_sharp_pair_385 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_385).car) = (Int_Form)(((* ((struct struct0x084d4998 *) cr)).max)));
(((* _sharp_pair_385).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_385);
})
);
((List__O__Form__C____type__type ) _sharp_pair_386);
})
));
(((* _sharp_pair_387).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_387);
})
);
((List__O__Form__C____type__type ) _sharp_pair_388);
})
);
})
)));
(final_cond = (Compound_Form)(intern( "@or"), ({
struct struct0x08065ce0 *_sharp_pair_390;
_sharp_pair_390,
(_sharp_pair_390 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_390).car) = cond);
(((* _sharp_pair_390).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_389;
_sharp_pair_389,
(_sharp_pair_389 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_389).car) = final_cond);
(((* _sharp_pair_389).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_389);
})
);
((List__O__Form__C____type__type ) _sharp_pair_390);
})
));
})
;
((void) 0);_sharp__sharp_loop379_continue391:((void) 0);
(_sharp_iterator378 = ((* ((struct struct0x084e8aa8 *) _sharp_iterator378)).cdr));
})
,
({goto _sharp__sharp_loop379_begin392;}),
((void) 0);_sharp__sharp_loop379_end380:((void) 0);
})
;
final_cond;
})
;}

Exit__type  parse_error(void)
{
return ({
(print_String)(((String__type) &__string_10)),
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
(((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "[]")))?
(({
(cs = (make_Character_Set)(((Form__type ) cf)));
((void) 0);
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "[^]")))?
(({
(cs = (make_inverse_Character_Set)(((Form__type ) cf)));
((void) 0);
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( " ")))?
(({
(cs = (head_set)(((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).head), ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).tail)));
((void) 0);
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "<>")))?
(({
(cs = (head_set)(((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).tail))).head), next_rules));
((void) 0);
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "|")))?
(({
List__O__pointer__O__Void__C____C____type__type cs_;
({if( ((((* ((struct struct0x0805ef40 *) cf)).form_list) != ((List__O__Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_11)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x08065ce0 *_sharp_pair_399;
_sharp_pair_399,
(_sharp_pair_399 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_399).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08065ce0 *_sharp_pair_394;
_sharp_pair_394,
(_sharp_pair_394 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_394).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_394).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_393;
_sharp_pair_393,
(_sharp_pair_393 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_393).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_393).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_393);
})
);
((List__O__Form__C____type__type ) _sharp_pair_394);
})
));
(((* _sharp_pair_399).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_398;
_sharp_pair_398,
(_sharp_pair_398 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_398).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08065ce0 *_sharp_pair_397;
_sharp_pair_397,
(_sharp_pair_397 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_397).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08065ce0 *_sharp_pair_395;
_sharp_pair_395,
(_sharp_pair_395 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_395).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_395).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_395);
})
));
(((* _sharp_pair_397).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_396;
_sharp_pair_396,
(_sharp_pair_396 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_396).car) = (Int_Form)(0));
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
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_12)),
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
(cs_ = ((List__O__pointer__O__Void__C____C____type__type ) (head_set)(((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).head), next_rules)));
({
List__O__Form__C____type__type _sharp_iterator401;
(_sharp_iterator401 = ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).tail));
((void) 0);_sharp__sharp_loop402_begin405:((void) 0),
({
Form__type rule;
({if( (_sharp_iterator401 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop402_end403;});}})
;
(rule = ((* ((struct struct0x08065ce0 *) _sharp_iterator401)).car));
({
(cs_ = (append)(((List__O__pointer__O__Void__C____C____type__type ) (head_set)(rule, next_rules)), cs_));
})
;
((void) 0);_sharp__sharp_loop402_continue404:((void) 0);
(_sharp_iterator401 = ((* ((struct struct0x08065ce0 *) _sharp_iterator401)).cdr));
})
,
({goto _sharp__sharp_loop402_begin405;}),
((void) 0);_sharp__sharp_loop402_end403:((void) 0);
})
;
(cs = ((Character_Set__type ) cs_));
((void) 0);
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "{}")))?
(({
({if( (next_rules == ((List__O__Form__C____type__type ) 0)))
{
({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_13)),
(print_String)(((String__type) &__string_14)),
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
(cs = (head_set)(((* ((struct struct0x0805f138 *) next_rules)).head), ((* ((struct struct0x0805f138 *) next_rules)).tail)));
((void) 0);
})
):
(({
(print_String)(((String__type) &__string_15)),
(print_Symbol)(((* ((struct struct0x0805ef40 *) cf)).head)),
(print_String)(((String__type) &__string_16)),
(maybe_flush)();
(print_form)(parse_form);
(exit)(3);
})
))))))))))));
})
):
((((is_id_form)(parse_form))?
(({
Symbol__type rule_name;
(rule_name = ((* ((struct struct0x08059c28 *) ((Id_Form__type ) parse_form))).value));
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
(print_String)(((String__type) &__string_17)),
(print_String)(((String__type) &__string_18)),
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
(cs = (head_set)(((* ((struct struct0x0805f138 *) next_rules)).head), ((* ((struct struct0x0805f138 *) next_rules)).tail)));
((void) 0);
})
):
(({
(cs = ((Character_Set__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) head_set_hash))));
({if( (cs == ((Character_Set__type ) 0)))
{
({
((Character_Set__type ) (puthash)(((void *) rule_name), ((void *) ((Character_Set__type ) (- (int) 1))), ((Hash_Table__type ) head_set_hash)));
(cs = (head_set)(((Form__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) rules_hash))), ((List__O__Form__C____type__type ) 0)));
({if( (cs == ((Character_Set__type ) (- (int) 1))))
{
({
(print_String)(((String__type) &__string_19)),
(print_Symbol)(rule_name),
(print_String)(((String__type) &__string_20)),
(maybe_flush)();
(exit)(3);
})
;}})
;
((Character_Set__type ) (puthash)(((void *) rule_name), ((void *) cs), ((Hash_Table__type ) head_set_hash)));
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
struct struct0x084d4998 *_sharp_pointer_alloc406;
Int__type head;
(head = (string_element)(((* ((struct struct0x0805bb08 *) ((String_Form__type ) parse_form))).value), 0));
(cs = ((Character_Set__type ) ({
struct struct0x084e8aa8 *_sharp_pair_407;
_sharp_pair_407,
(_sharp_pair_407 = ((struct struct0x084e8aa8 *) (alloc_cons_cell)()));
(((* _sharp_pair_407).car) = ((Character_Range__type ) _sharp_pointer_alloc406,
(_sharp_pointer_alloc406 = ((struct struct0x084d4998 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc406) = ((struct struct0x084d4998 ){head, head})),
((struct struct0x084d4998 *) _sharp_pointer_alloc406)));
(((* _sharp_pair_407).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_407);
})
));
((void) 0);
})
):
(({
(print_String)(((String__type) &__string_21)),
(maybe_flush)();
(print_form)(parse_form);
(exit)(3);
})
))))));
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
(((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "[]")))||((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "[^]")))))?
(({
(Compound_Form)(intern( "read_char"), ((List__O__Form__C____type__type ) 0));
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "<>")))?
(({
Expanded_Form__type exp_right_form;
Form__type subrule;
Form__type left_form;
Id_Form__type id_form;
Symbol__type id;
Form__type right_form;
(id_form = ((Id_Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).head)));
(id = ((* ((struct struct0x08059c28 *) id_form)).value));
(left_form = ((Form__type ) id_form));
(subrule = ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).tail))).head));
(right_form = (grammar_expander_rec)(subrule, next_rules));
({if( (((is_compound_form)(subrule))&&((((((* ((struct struct0x0805ef40 *) ((Compound_Form__type ) subrule))).head) == intern( "*")))||((((* ((struct struct0x0805ef40 *) ((Compound_Form__type ) subrule))).head) == intern( "+")))))))
{
({
(right_form = (Compound_Form)(intern( "make_list"), ({
struct struct0x08065ce0 *_sharp_pair_408;
_sharp_pair_408,
(_sharp_pair_408 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_408).car) = right_form);
(((* _sharp_pair_408).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_408);
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
struct struct0x08065ce0 *_sharp_pair_410;
_sharp_pair_410,
(_sharp_pair_410 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_410).car) = ((Form__type ) id_form));
(((* _sharp_pair_410).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_409;
_sharp_pair_409,
(_sharp_pair_409 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_409).car) = (((struct struct0x080647d0 ) ((* ((struct struct0x080649d0 *) ((Real_Type__type ) ((* ((struct struct0x0805f9b0 *) exp_right_form)).type)))).common_)).type_form));
(((* _sharp_pair_409).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_409);
})
);
((List__O__Form__C____type__type ) _sharp_pair_410);
})
));
})
;}})
;
(Compound_Form)(intern( "="), ({
struct struct0x08065ce0 *_sharp_pair_412;
_sharp_pair_412,
(_sharp_pair_412 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_412).car) = left_form);
(((* _sharp_pair_412).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_411;
_sharp_pair_411,
(_sharp_pair_411 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_411).car) = ((Form__type ) exp_right_form));
(((* _sharp_pair_411).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_411);
})
);
((List__O__Form__C____type__type ) _sharp_pair_412);
})
);
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "{}")))?
(({
(Compound_Form)(intern( "seq"), ((* ((struct struct0x0805ef40 *) cf)).form_list));
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( " ")))?
(({
void **_sharp_make_list_ptr414;
List__O__Form__C____type__type fl;
(fl = ({
List__O__Form__C____type__type _sharp_make_list413;
_sharp_make_list413,
_sharp_make_list_ptr414,
(_sharp_make_list_ptr414 = ((void *) (&_sharp_make_list413))),
({
List__O__Form__C____type__type grammar_rule_it;
(grammar_rule_it = ((* ((struct struct0x0805ef40 *) cf)).form_list));
((void) 0);_sharp__sharp_loop415_begin417:((void) 0),
({if( (!((grammar_rule_it != ((List__O__Form__C____type__type ) 0)))))
{
({goto _sharp__sharp_loop415_end416;});}})
,
({
List__O__Form__C____type__type grammar_tail;
Form__type grammar_rule;
(grammar_rule = ((* ((struct struct0x0805f138 *) grammar_rule_it)).head));
(grammar_tail = ((* ((struct struct0x0805f138 *) grammar_rule_it)).tail));
((* _sharp_make_list_ptr414) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr414))).car) = ((void *) (grammar_expander_rec)(grammar_rule, grammar_tail))),
(_sharp_make_list_ptr414 = (&((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr414))).cdr))),
((void) 0);
(grammar_rule_it = grammar_tail);
})
,
({goto _sharp__sharp_loop415_begin417;}),
((void) 0);_sharp__sharp_loop415_end416:((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr414) = ((void *) 0)),
_sharp_make_list413;
})
);
(Compound_Form)(intern( "seq"), fl);
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "|")))?
(({
Form__type else_form;
Form__type peeked_char_form;
Symbol__type peeked_char;
(peeked_char = (gensym)(((String__type) &__string_22)));
(peeked_char_form = (Id_Form)(peeked_char));
(else_form = (Compound_Form)(intern( "parse_error"), ((List__O__Form__C____type__type ) 0)));
({
List__O__Form__C____type__type _sharp_iterator419;
(_sharp_iterator419 = ((* ((struct struct0x0805ef40 *) cf)).form_list));
((void) 0);_sharp__sharp_loop420_begin426:((void) 0),
({
Form__type grammar_rule;
({if( (_sharp_iterator419 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop420_end421;});}})
;
(grammar_rule = ((* ((struct struct0x08065ce0 *) _sharp_iterator419)).car));
({
Character_Set__type char_set;
(char_set = (head_set)(grammar_rule, next_rules));
(else_form = (Compound_Form)(intern( "if"), ({
struct struct0x08065ce0 *_sharp_pair_424;
_sharp_pair_424,
(_sharp_pair_424 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_424).car) = (is_in_Character_Set_condition)(peeked_char_form, char_set));
(((* _sharp_pair_424).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_423;
_sharp_pair_423,
(_sharp_pair_423 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_423).car) = (grammar_expander_rec)(grammar_rule, next_rules));
(((* _sharp_pair_423).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_422;
_sharp_pair_422,
(_sharp_pair_422 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_422).car) = else_form);
(((* _sharp_pair_422).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_422);
})
);
((List__O__Form__C____type__type ) _sharp_pair_423);
})
);
((List__O__Form__C____type__type ) _sharp_pair_424);
})
));
})
;
((void) 0);_sharp__sharp_loop420_continue425:((void) 0);
(_sharp_iterator419 = ((* ((struct struct0x08065ce0 *) _sharp_iterator419)).cdr));
})
,
({goto _sharp__sharp_loop420_begin426;}),
((void) 0);_sharp__sharp_loop420_end421:((void) 0);
})
;
(Compound_Form)(intern( "block"), ({
struct struct0x08065ce0 *_sharp_pair_431;
_sharp_pair_431,
(_sharp_pair_431 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_431).car) = (Compound_Form)(intern( "="), ({
struct struct0x08065ce0 *_sharp_pair_429;
_sharp_pair_429,
(_sharp_pair_429 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_429).car) = (Compound_Form)(intern( "let"), ({
struct struct0x08065ce0 *_sharp_pair_427;
_sharp_pair_427,
(_sharp_pair_427 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_427).car) = peeked_char_form);
(((* _sharp_pair_427).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_427);
})
));
(((* _sharp_pair_429).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_428;
_sharp_pair_428,
(_sharp_pair_428 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_428).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_428).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_428);
})
);
((List__O__Form__C____type__type ) _sharp_pair_429);
})
));
(((* _sharp_pair_431).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_430;
_sharp_pair_430,
(_sharp_pair_430 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_430).car) = else_form);
(((* _sharp_pair_430).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_430);
})
);
((List__O__Form__C____type__type ) _sharp_pair_431);
})
);
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "*")))?
(({
Form__type repeated_rule;
Character_Set__type char_set;
Form__type peeked_char_form;
Symbol__type peeked_char;
(repeated_rule = ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).head));
(char_set = (head_set)(repeated_rule, ((List__O__Form__C____type__type ) 0)));
(peeked_char = (gensym)(((String__type) &__string_23)));
(peeked_char_form = (Id_Form)(peeked_char));
(Compound_Form)(intern( "loop"), ({
struct struct0x08065ce0 *_sharp_pair_441;
_sharp_pair_441,
(_sharp_pair_441 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_441).car) = (Compound_Form)(intern( "block"), ({
struct struct0x08065ce0 *_sharp_pair_440;
_sharp_pair_440,
(_sharp_pair_440 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_440).car) = (Compound_Form)(intern( "="), ({
struct struct0x08065ce0 *_sharp_pair_434;
_sharp_pair_434,
(_sharp_pair_434 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_434).car) = (Compound_Form)(intern( "let"), ({
struct struct0x08065ce0 *_sharp_pair_432;
_sharp_pair_432,
(_sharp_pair_432 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_432).car) = peeked_char_form);
(((* _sharp_pair_432).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_432);
})
));
(((* _sharp_pair_434).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_433;
_sharp_pair_433,
(_sharp_pair_433 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_433).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_433).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_433);
})
);
((List__O__Form__C____type__type ) _sharp_pair_434);
})
));
(((* _sharp_pair_440).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_439;
_sharp_pair_439,
(_sharp_pair_439 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_439).car) = (Compound_Form)(intern( "if"), ({
struct struct0x08065ce0 *_sharp_pair_437;
_sharp_pair_437,
(_sharp_pair_437 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_437).car) = (Compound_Form)(intern( "@not"), ({
struct struct0x08065ce0 *_sharp_pair_435;
_sharp_pair_435,
(_sharp_pair_435 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_435).car) = (is_in_Character_Set_condition)(peeked_char_form, char_set));
(((* _sharp_pair_435).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_435);
})
));
(((* _sharp_pair_437).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_436;
_sharp_pair_436,
(_sharp_pair_436 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_436).car) = (Compound_Form)(intern( "break"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_436).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_436);
})
);
((List__O__Form__C____type__type ) _sharp_pair_437);
})
));
(((* _sharp_pair_439).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_438;
_sharp_pair_438,
(_sharp_pair_438 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_438).car) = (grammar_expander_rec)(repeated_rule, next_rules));
(((* _sharp_pair_438).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_438);
})
);
((List__O__Form__C____type__type ) _sharp_pair_439);
})
);
((List__O__Form__C____type__type ) _sharp_pair_440);
})
));
(((* _sharp_pair_441).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_441);
})
);
})
):
((((((* ((struct struct0x0805ef40 *) cf)).head) == intern( "?")))?
(({
Character_Set__type char_set;
Form__type peeked_char_form;
Symbol__type peeked_char;
Form__type maybe_rule;
(maybe_rule = ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).head));
(char_set = (head_set)(maybe_rule, ((List__O__Form__C____type__type ) 0)));
(peeked_char = (gensym)(((String__type) &__string_24)));
(peeked_char_form = (Id_Form)(peeked_char));
(Compound_Form)(intern( "block"), ({
struct struct0x08065ce0 *_sharp_pair_448;
_sharp_pair_448,
(_sharp_pair_448 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_448).car) = (Compound_Form)(intern( "="), ({
struct struct0x08065ce0 *_sharp_pair_444;
_sharp_pair_444,
(_sharp_pair_444 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_444).car) = (Compound_Form)(intern( "let"), ({
struct struct0x08065ce0 *_sharp_pair_442;
_sharp_pair_442,
(_sharp_pair_442 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_442).car) = peeked_char_form);
(((* _sharp_pair_442).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_442);
})
));
(((* _sharp_pair_444).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_443;
_sharp_pair_443,
(_sharp_pair_443 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_443).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_443).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_443);
})
);
((List__O__Form__C____type__type ) _sharp_pair_444);
})
));
(((* _sharp_pair_448).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_447;
_sharp_pair_447,
(_sharp_pair_447 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_447).car) = (Compound_Form)(intern( "if"), ({
struct struct0x08065ce0 *_sharp_pair_446;
_sharp_pair_446,
(_sharp_pair_446 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_446).car) = (is_in_Character_Set_condition)(peeked_char_form, char_set));
(((* _sharp_pair_446).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_445;
_sharp_pair_445,
(_sharp_pair_445 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_445).car) = (grammar_expander_rec)(maybe_rule, next_rules));
(((* _sharp_pair_445).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_445);
})
);
((List__O__Form__C____type__type ) _sharp_pair_446);
})
));
(((* _sharp_pair_447).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_447);
})
);
((List__O__Form__C____type__type ) _sharp_pair_448);
})
);
})
):
(({
(Id_Form)(intern( "imp"));
})
))))))))))))));
})
):
((((is_id_form)(parse_form))?
(({
Symbol_Form__type id_form;
(id_form = ((Symbol_Form__type ) parse_form));
(((((* ((struct struct0x08059c28 *) id_form)).value) == intern( "_")))?
(({
(Compound_Form)(intern( "funcall"), ({
struct struct0x08065ce0 *_sharp_pair_449;
_sharp_pair_449,
(_sharp_pair_449 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_449).car) = (Id_Form)(intern( "get_point_pos")));
(((* _sharp_pair_449).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_449);
})
);
})
):
((((((* ((struct struct0x08059c28 *) id_form)).value) == intern( ".")))?
(({
(Compound_Form)(intern( "read_char"), ((List__O__Form__C____type__type ) 0));
})
):
((Compound_Form)(intern( "funcall"), ({
struct struct0x08065ce0 *_sharp_pair_450;
_sharp_pair_450,
(_sharp_pair_450 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_450).car) = (Id_Form)((intern_string)((concat)(((String__type) &__string_25), (get_symbol_name)(((* ((struct struct0x08059c28 *) id_form)).value))))));
(((* _sharp_pair_450).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_450);
})
)))));
})
):
((((is_string_form)(parse_form))?
(({
void **_sharp_make_list_ptr452;
List__O__Int__C____type__type cl;
List__O__Form__C____type__type form_list;
(cl = (string_to_int_list)(((* ((struct struct0x0805bb08 *) ((String_Form__type ) parse_form))).value)));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list451;
_sharp_make_list451,
_sharp_make_list_ptr452,
(_sharp_make_list_ptr452 = ((void *) (&_sharp_make_list451))),
({
({
List__O__Int__C____type__type _sharp_iterator454;
(_sharp_iterator454 = cl);
((void) 0);_sharp__sharp_loop455_begin458:((void) 0),
({
Int__type Int;
({if( (_sharp_iterator454 == ((List__O__Int__C____type__type ) 0)))
{
({goto _sharp__sharp_loop455_end456;});}})
;
(Int = ((* ((struct struct0x08536ff8 *) _sharp_iterator454)).car));
({
((* _sharp_make_list_ptr452) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr452))).car) = ((void *) (Compound_Form)(intern( "read_char"), ((List__O__Form__C____type__type ) 0)))),
(_sharp_make_list_ptr452 = (&((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr452))).cdr))),
((void) 0);
})
;
((void) 0);_sharp__sharp_loop455_continue457:((void) 0);
(_sharp_iterator454 = ((* ((struct struct0x08536ff8 *) _sharp_iterator454)).cdr));
})
,
({goto _sharp__sharp_loop455_begin458;}),
((void) 0);_sharp__sharp_loop455_end456:((void) 0);
})
;
((void) 0);
})
,
((* _sharp_make_list_ptr452) = ((void *) 0)),
_sharp_make_list451;
})
);
(Compound_Form)(intern( "seq"), form_list);
})
):
(({
(print_String)(((String__type) &__string_26)),
(maybe_flush)();
(print_form)(parse_form);
(Id_Form)(intern( "imp2"));
})
))))));
})
;}

Form__type  expand_grammar_rule(Form__type  rule)
{
return ({
(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0));
})
;}

List__O__Form__C____type__type  grammar_produce_function_definitions(Form__type  grammar_)
{
return ({
void **_sharp_make_list_ptr468;
struct struct0x084d4998 *_sharp_pointer_alloc459;
List__O__Compound_Form__C____type__type rule_list;
Symbol__type grammar_name;
List__O__Form__C____type__type form_list;
Compound_Form__type grammar;
(grammar = ((Compound_Form__type ) grammar_));
(grammar_name = ((* ((struct struct0x08059c28 *) ((Id_Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) grammar)).form_list))).tail))).tail))).head)))).value));
(rule_list = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) grammar)).form_list))).tail))).tail))).tail)));
(dot_character_set = ((Character_Set__type ) ({
struct struct0x084e8aa8 *_sharp_pair_460;
_sharp_pair_460,
(_sharp_pair_460 = ((struct struct0x084e8aa8 *) (alloc_cons_cell)()));
(((* _sharp_pair_460).car) = ((Character_Range__type ) _sharp_pointer_alloc459,
(_sharp_pointer_alloc459 = ((struct struct0x084d4998 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc459) = ((struct struct0x084d4998 ){1, 255})),
((struct struct0x084d4998 *) _sharp_pointer_alloc459)));
(((* _sharp_pair_460).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_460);
})
));
(rules_hash = ((Hash__O__Symbol__c__Form__C____type__type ) (make_hash_table)()));
(head_set_hash = ((Hash__O__Symbol__c__Character_Set__C____type__type ) (make_hash_table)()));
({
List__O__Compound_Form__C____type__type _sharp_iterator462;
(_sharp_iterator462 = rule_list);
((void) 0);_sharp__sharp_loop463_begin466:((void) 0),
({
Compound_Form__type rule;
({if( (_sharp_iterator462 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop463_end464;});}})
;
(rule = ((* ((struct struct0x081f7e28 *) _sharp_iterator462)).car));
({
Symbol__type rule_name;
Form__type form;
(rule_name = ((* ((struct struct0x08059c28 *) ((Id_Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) rule)).form_list))).head)))).value));
(form = ((Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) rule)).form_list))).tail))).head)));
((Form__type ) (puthash)(((void *) rule_name), ((void *) form), ((Hash_Table__type ) rules_hash)));
})
;
((void) 0);_sharp__sharp_loop463_continue465:((void) 0);
(_sharp_iterator462 = ((* ((struct struct0x081f7e28 *) _sharp_iterator462)).cdr));
})
,
({goto _sharp__sharp_loop463_begin466;}),
((void) 0);_sharp__sharp_loop463_end464:((void) 0);
})
;
(form_list = ({
List__O__Form__C____type__type _sharp_make_list467;
_sharp_make_list467,
_sharp_make_list_ptr468,
(_sharp_make_list_ptr468 = ((void *) (&_sharp_make_list467))),
({
({
List__O__Compound_Form__C____type__type _sharp_iterator470;
(_sharp_iterator470 = rule_list);
((void) 0);_sharp__sharp_loop471_begin481:((void) 0),
({
Compound_Form__type rule;
({if( (_sharp_iterator470 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop471_end472;});}})
;
(rule = ((* ((struct struct0x081f7e28 *) _sharp_iterator470)).car));
({
Form__type function_form;
Expanded_Form__type exp_function_body;
Form__type function_body;
Symbol__type rule_name;
Form__type form;
Symbol__type function_name;
Form__type lambda_form;
(rule_name = ((* ((struct struct0x08059c28 *) ((Id_Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) rule)).form_list))).head)))).value));
(function_name = (intern_string)((concat)(((String__type) &__string_27), (get_symbol_name)(rule_name))));
(form = ((Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) rule)).form_list))).tail))).head)));
(id_used = ((Hash__O__Symbol__c__Type__C____type__type ) (make_hash_table)()));
(declare_block_begin)();
(function_body = (grammar_expander_rec)(form, ((List__O__Form__C____type__type ) 0)));
(exp_function_body = (declare_block_end)(({
struct struct0x08065ce0 *_sharp_pair_473;
_sharp_pair_473,
(_sharp_pair_473 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_473).car) = function_body);
(((* _sharp_pair_473).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_473);
})
));
(lambda_form = (Compound_Form)(intern( "lambda"), ({
struct struct0x08065ce0 *_sharp_pair_476;
_sharp_pair_476,
(_sharp_pair_476 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_476).car) = (((struct struct0x080647d0 ) ((* ((struct struct0x080649d0 *) ((Real_Type__type ) ((* ((struct struct0x0805f9b0 *) exp_function_body)).type)))).common_)).type_form));
(((* _sharp_pair_476).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_475;
_sharp_pair_475,
(_sharp_pair_475 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_475).car) = (Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_475).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_474;
_sharp_pair_474,
(_sharp_pair_474 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_474).car) = ((* ((struct struct0x0805f9b0 *) exp_function_body)).return_form));
(((* _sharp_pair_474).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_474);
})
);
((List__O__Form__C____type__type ) _sharp_pair_475);
})
);
((List__O__Form__C____type__type ) _sharp_pair_476);
})
));
(function_form = (Compound_Form)(intern( "define"), ({
struct struct0x08065ce0 *_sharp_pair_479;
_sharp_pair_479,
(_sharp_pair_479 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_479).car) = (Id_Form)(intern( "function")));
(((* _sharp_pair_479).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_478;
_sharp_pair_478,
(_sharp_pair_478 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_478).car) = (Id_Form)(function_name));
(((* _sharp_pair_478).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_477;
_sharp_pair_477,
(_sharp_pair_477 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_477).car) = lambda_form);
(((* _sharp_pair_477).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_477);
})
);
((List__O__Form__C____type__type ) _sharp_pair_478);
})
);
((List__O__Form__C____type__type ) _sharp_pair_479);
})
));
((* _sharp_make_list_ptr468) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr468))).car) = ((void *) function_form)),
(_sharp_make_list_ptr468 = (&((* (* ((struct struct0x084e0768 **) _sharp_make_list_ptr468))).cdr))),
((void) 0);
})
;
((void) 0);_sharp__sharp_loop471_continue480:((void) 0);
(_sharp_iterator470 = ((* ((struct struct0x081f7e28 *) _sharp_iterator470)).cdr));
})
,
({goto _sharp__sharp_loop471_begin481;}),
((void) 0);_sharp__sharp_loop471_end472:((void) 0);
})
;
((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr468) = ((void *) 0)),
_sharp_make_list467;
})
);
form_list;
})
;}

void  test(void)
{
return ({
Form__type rule;
Form__type grammar;
(rule = (Compound_Form)(intern( "define"), ({
struct struct0x08065ce0 *_sharp_pair_490;
_sharp_pair_490,
(_sharp_pair_490 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_490).car) = (Id_Form)(intern( "rule")));
(((* _sharp_pair_490).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_489;
_sharp_pair_489,
(_sharp_pair_489 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_489).car) = (Id_Form)(intern( "Comment")));
(((* _sharp_pair_489).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_488;
_sharp_pair_488,
(_sharp_pair_488 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_488).car) = (Compound_Form)(intern( " "), ({
struct struct0x08065ce0 *_sharp_pair_487;
_sharp_pair_487,
(_sharp_pair_487 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_487).car) = (String_Form)(((String__type) &__string_28)));
(((* _sharp_pair_487).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_486;
_sharp_pair_486,
(_sharp_pair_486 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_486).car) = (Compound_Form)(intern( "*"), ({
struct struct0x08065ce0 *_sharp_pair_483;
_sharp_pair_483,
(_sharp_pair_483 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_483).car) = (Compound_Form)(intern( "[^]"), ({
struct struct0x08065ce0 *_sharp_pair_482;
_sharp_pair_482,
(_sharp_pair_482 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_482).car) = (Int_Form)(10));
(((* _sharp_pair_482).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_482);
})
));
(((* _sharp_pair_483).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_483);
})
));
(((* _sharp_pair_486).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_485;
_sharp_pair_485,
(_sharp_pair_485 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_485).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08065ce0 *_sharp_pair_484;
_sharp_pair_484,
(_sharp_pair_484 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_484).car) = (Int_Form)(10));
(((* _sharp_pair_484).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_484);
})
));
(((* _sharp_pair_485).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_485);
})
);
((List__O__Form__C____type__type ) _sharp_pair_486);
})
);
((List__O__Form__C____type__type ) _sharp_pair_487);
})
));
(((* _sharp_pair_488).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_488);
})
);
((List__O__Form__C____type__type ) _sharp_pair_489);
})
);
((List__O__Form__C____type__type ) _sharp_pair_490);
})
));
(grammar = (Compound_Form)(intern( "define"), ({
struct struct0x08065ce0 *_sharp_pair_493;
_sharp_pair_493,
(_sharp_pair_493 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_493).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_493).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_492;
_sharp_pair_492,
(_sharp_pair_492 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_492).car) = (Id_Form)(intern( "test_grammar")));
(((* _sharp_pair_492).cdr) = ({
struct struct0x08065ce0 *_sharp_pair_491;
_sharp_pair_491,
(_sharp_pair_491 = ((struct struct0x08065ce0 *) (alloc_cons_cell)()));
(((* _sharp_pair_491).car) = rule);
(((* _sharp_pair_491).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_491);
})
);
((List__O__Form__C____type__type ) _sharp_pair_492);
})
);
((List__O__Form__C____type__type ) _sharp_pair_493);
})
));
(grammar_produce_function_definitions)(grammar);
((void) 0);
})
;}

Form__type  grammar_expander_sharp__sharp_expander_function(Compound_Form__type  form_)
{
return ({
Symbol__type rule;
Form__type form;
(id_used = ((Hash__O__Symbol__c__Type__C____type__type ) (make_hash_table)()));
(rule = ((* ((struct struct0x08059c28 *) ((Symbol_Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) form_)).form_list))).head)))).value));
({if( (((Form__type ) (gethash)(((void *) rule), ((Hash_Table__type ) rules_hash))) == ((Form__type ) 0)))
{
({
(print_String)(((String__type) &__string_29)),
(print_Symbol)(rule),
(maybe_flush)();
(exit)(3);
})
;}})
;
(form = (grammar_expander_rec)(((Form__type ) (gethash)(((void *) rule), ((Hash_Table__type ) rules_hash))), ((List__O__Form__C____type__type ) 0)));
form;
})
;}

void init_grammar_expander(void){
define_expander( intern( "grammar_expander"), grammar_expander_sharp__sharp_expander_function);
}

void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( "TEST result: %d", test_ptr());flush();}
