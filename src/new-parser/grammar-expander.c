/* Automatically generated : do not edit!*/
#include "grammar-expander.inc"
struct struct0x08525290 semantic_condition_then;

Hash__O__Symbol__c__Type__C____type__type id_used;

Hash__O__Symbol__c__Form__C____type__type grammar_hash;

Hash__O__Symbol__c__Hash__O__Symbol__c__Form__C____C____type__type rules_hash;

Hash__O__Symbol__c__Hash__O__Symbol__c__List__O__Character_Set__C____C____C____type__type head_set_hash;

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
({({_sharp__sharp_loop339_begin347:;
({
Character_Range__type cr;
({if( (_sharp_iterator338 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop339_end340;});}})
;
(cr = ((* ((struct struct0x08528220 *) _sharp_iterator338)).car));
({
List__O__Character_Range__C____type__type *new_cr_list_ptr;
(new_cr_list_ptr = (&new_cr_list));
({({_sharp__sharp_loop341_begin345:;
({
List__O__Character_Range__C____type__type next_cr;
({if( ((* new_cr_list_ptr) == ((List__O__Character_Range__C____type__type ) 0)))
{
({
((* new_cr_list_ptr) = ({
struct struct0x08528220 *_sharp_pair_343;
({_sharp_pair_343;
(_sharp_pair_343 = ((struct struct0x08528220 *) (alloc_cons_cell)()));});
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
({if( ((int) ((* ((struct struct0x08525170 *) cr)).max) < (int) ((* ((struct struct0x08525170 *) ((* ((struct struct0x08525500 *) next_cr)).head))).min)))
{
({
List__O__Character_Range__C____type__type pair;
(pair = ({
struct struct0x08528220 *_sharp_pair_344;
({_sharp_pair_344;
(_sharp_pair_344 = ((struct struct0x08528220 *) (alloc_cons_cell)()));});
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
(new_cr_list_ptr = (&((* ((struct struct0x08525500 *) (* new_cr_list_ptr))).tail)));
})
;
({goto _sharp__sharp_loop341_begin345;});});
_sharp__sharp_loop341_end342:;});
})
;
_sharp__sharp_loop339_continue346:;
(_sharp_iterator338 = ((* ((struct struct0x08528220 *) _sharp_iterator338)).cdr));
})
;
({goto _sharp__sharp_loop339_begin347;});});
_sharp__sharp_loop339_end340:;});
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
({_sharp_make_list348;
_sharp_make_list_ptr349;
(_sharp_make_list_ptr349 = ((void *) (&_sharp_make_list348)));
({
({
List__O__Form__C____type__type _sharp_iterator351;
(_sharp_iterator351 = ((* ((struct struct0x0805ee90 *) form)).form_list));
({({_sharp__sharp_loop352_begin366:;
({
Form__type subform;
({if( (_sharp_iterator351 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop352_end353;});}})
;
(subform = ((* ((struct struct0x08067248 *) _sharp_iterator351)).car));
({
(((is_compound_form)(subform))?
(({
struct struct0x08525170 *_sharp_pointer_alloc360;
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
({(print_String)(((String__type) &__string_1));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_int_form"), ({
struct struct0x08067248 *_sharp_pair_356;
({_sharp_pair_356;
(_sharp_pair_356 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_356).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_355;
({_sharp_pair_355;
(_sharp_pair_355 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_355).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_355).cdr) = ({
struct struct0x08067248 *_sharp_pair_354;
({_sharp_pair_354;
(_sharp_pair_354 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
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
struct struct0x08067248 *_sharp_pair_359;
({_sharp_pair_359;
(_sharp_pair_359 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_359).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_358;
({_sharp_pair_358;
(_sharp_pair_358 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_358).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_358).cdr) = ({
struct struct0x08067248 *_sharp_pair_357;
({_sharp_pair_357;
(_sharp_pair_357 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
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
({((* _sharp_make_list_ptr349) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr349))).car) = ((void *) ((Character_Range__type ) ({_sharp_pointer_alloc360;
(_sharp_pointer_alloc360 = ((struct struct0x08525170 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc360) = ((struct struct0x08525170 ){((* ((struct struct0x0805e110 *) min_form)).value), ((* ((struct struct0x0805e110 *) max_form)).value)}));
((struct struct0x08525170 *) _sharp_pointer_alloc360);}))));
(_sharp_make_list_ptr349 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr349))).cdr)));
((void) 0);});
})
):
(({
struct struct0x08525170 *_sharp_pointer_alloc364;
Int_Form__type symbol_form;
(symbol_form = ((Int_Form__type ) subform));
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
struct struct0x08067248 *_sharp_pair_363;
({_sharp_pair_363;
(_sharp_pair_363 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_363).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_362;
({_sharp_pair_362;
(_sharp_pair_362 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_362).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_362).cdr) = ({
struct struct0x08067248 *_sharp_pair_361;
({_sharp_pair_361;
(_sharp_pair_361 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
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
({((* _sharp_make_list_ptr349) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr349))).car) = ((void *) ((Character_Range__type ) ({_sharp_pointer_alloc364;
(_sharp_pointer_alloc364 = ((struct struct0x08525170 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc364) = ((struct struct0x08525170 ){((* ((struct struct0x0805e110 *) symbol_form)).value), ((* ((struct struct0x0805e110 *) symbol_form)).value)}));
((struct struct0x08525170 *) _sharp_pointer_alloc364);}))));
(_sharp_make_list_ptr349 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr349))).cdr)));
((void) 0);});
})
));
})
;
_sharp__sharp_loop352_continue365:;
(_sharp_iterator351 = ((* ((struct struct0x08067248 *) _sharp_iterator351)).cdr));
})
;
({goto _sharp__sharp_loop352_begin366;});});
_sharp__sharp_loop352_end353:;});
})
;
((void) 0);
((void) 0);
})
;
((* _sharp_make_list_ptr349) = ((void *) 0));
_sharp_make_list348;});
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
struct struct0x08525170 *_sharp_pointer_alloc367;
((Character_Set__type ) ({
struct struct0x08528220 *_sharp_pair_368;
({_sharp_pair_368;
(_sharp_pair_368 = ((struct struct0x08528220 *) (alloc_cons_cell)()));});
(((* _sharp_pair_368).car) = ((Character_Range__type ) ({_sharp_pointer_alloc367;
(_sharp_pointer_alloc367 = ((struct struct0x08525170 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc367) = ((struct struct0x08525170 ){1, 255}));
((struct struct0x08525170 *) _sharp_pointer_alloc367);})));
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
(first = ((* ((struct struct0x08525500 *) csl)).head));
(inverse = ({
List__O__Character_Range__C____type__type _sharp_make_list369;
({_sharp_make_list369;
_sharp_make_list_ptr370;
(_sharp_make_list_ptr370 = ((void *) (&_sharp_make_list369)));
({
Int__type prec;
({if( (((* ((struct struct0x08525170 *) first)).min) != 0))
{
({
struct struct0x08525170 *_sharp_pointer_alloc371;
({((* _sharp_make_list_ptr370) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr370))).car) = ((void *) ((Character_Range__type ) ({_sharp_pointer_alloc371;
(_sharp_pointer_alloc371 = ((struct struct0x08525170 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc371) = ((struct struct0x08525170 ){0, ((int) ((* ((struct struct0x08525170 *) first)).min) - (int) 1)}));
((struct struct0x08525170 *) _sharp_pointer_alloc371);}))));
(_sharp_make_list_ptr370 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr370))).cdr)));
((void) 0);});
})
;}})
;
(prec = ((int) ((* ((struct struct0x08525170 *) first)).max) + (int) 1));
({
List__O__Character_Range__C____type__type _sharp_iterator373;
(_sharp_iterator373 = ((* ((struct struct0x08525500 *) csl)).tail));
({({_sharp__sharp_loop374_begin378:;
({
Character_Range__type cr;
({if( (_sharp_iterator373 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop374_end375;});}})
;
(cr = ((* ((struct struct0x08528220 *) _sharp_iterator373)).car));
({
struct struct0x08525170 *_sharp_pointer_alloc376;
({((* _sharp_make_list_ptr370) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr370))).car) = ((void *) ((Character_Range__type ) ({_sharp_pointer_alloc376;
(_sharp_pointer_alloc376 = ((struct struct0x08525170 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc376) = ((struct struct0x08525170 ){prec, ((int) ((* ((struct struct0x08525170 *) cr)).min) - (int) 1)}));
((struct struct0x08525170 *) _sharp_pointer_alloc376);}))));
(_sharp_make_list_ptr370 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr370))).cdr)));
((void) 0);});
(prec = ((int) ((* ((struct struct0x08525170 *) cr)).max) + (int) 1));
})
;
_sharp__sharp_loop374_continue377:;
(_sharp_iterator373 = ((* ((struct struct0x08528220 *) _sharp_iterator373)).cdr));
})
;
({goto _sharp__sharp_loop374_begin378;});});
_sharp__sharp_loop374_end375:;});
})
;
({if( ((int) prec < (int) 256))
{
({
struct struct0x08525170 *_sharp_pointer_alloc379;
({((* _sharp_make_list_ptr370) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr370))).car) = ((void *) ((Character_Range__type ) ({_sharp_pointer_alloc379;
(_sharp_pointer_alloc379 = ((struct struct0x08525170 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc379) = ((struct struct0x08525170 ){prec, 255}));
((struct struct0x08525170 *) _sharp_pointer_alloc379);}))));
(_sharp_make_list_ptr370 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr370))).cdr)));
((void) 0);});
})
;}})
;
((void) 0);
((void) 0);
})
;
((* _sharp_make_list_ptr370) = ((void *) 0));
_sharp_make_list369;});
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
({({_sharp__sharp_loop382_begin385:;
({
Character_Range__type cr;
({if( (_sharp_iterator381 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop382_end383;});}})
;
(cr = ((* ((struct struct0x08528220 *) _sharp_iterator381)).car));
({
({(print_String)(((String__type) &__string_7));
(print_Int_Dec)(((* ((struct struct0x08525170 *) cr)).min));
(print_String)(((String__type) &__string_8));
(print_Int_Dec)(((* ((struct struct0x08525170 *) cr)).max));
(print_String)(((String__type) &__string_9));
(maybe_flush)();});
({if( ((((int) ((* ((struct struct0x08525170 *) cr)).min) > (int) 255))||(((int) ((* ((struct struct0x08525170 *) cr)).max) > (int) 255))))
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
})
;
_sharp__sharp_loop382_continue384:;
(_sharp_iterator381 = ((* ((struct struct0x08528220 *) _sharp_iterator381)).cdr));
})
;
({goto _sharp__sharp_loop382_begin385;});});
_sharp__sharp_loop382_end383:;});
})
;
})
;}

Character_Set__type  union_Character_Set(Character_Set__type  cs1_, Character_Set__type  cs2_)
{
return ({
List__O__Character_Range__C____type__type cs1;
List__O__Character_Range__C____type__type cs2;
(cs1 = ((List__O__Character_Range__C____type__type ) cs1_));
(cs2 = ((List__O__Character_Range__C____type__type ) cs2_));
(sort_Character_Set)(((List__O__Character_Range__C____type__type ) (append)(((List__O__pointer__O__Void__C____C____type__type ) cs1), ((List__O__pointer__O__Void__C____C____type__type ) cs2))));
})
;}

List__O__Character_Set__C____type__type  union_Character_Set_List(List__O__Character_Set__C____type__type  csl1, List__O__Character_Set__C____type__type  csl2)
{
return ({
void **_sharp_make_list_ptr387;
List__O__Character_Set__C____type__type l2;
List__O__Character_Set__C____type__type l1;
List__O__Character_Set__C____type__type new_list;
(l1 = csl1);
(l2 = csl2);
(new_list = ({
List__O__Character_Set__C____type__type _sharp_make_list386;
({_sharp_make_list386;
_sharp_make_list_ptr387;
(_sharp_make_list_ptr387 = ((void *) (&_sharp_make_list386)));
({
({_sharp__sharp_loop388_continue390:;
({({_sharp__sharp_loop388_begin391:;
({
(((l1 != ((List__O__Character_Set__C____type__type ) 0)))?
(({
({if( (l2 != ((List__O__Character_Set__C____type__type ) 0)))
{
({
({((* _sharp_make_list_ptr387) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr387))).car) = ((void *) (union_Character_Set)(((* ((struct struct0x08525c88 *) l1)).head), ((* ((struct struct0x08525c88 *) l2)).head))));
(_sharp_make_list_ptr387 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr387))).cdr)));
((void) 0);});
(l2 = ((* ((struct struct0x08525c88 *) l2)).tail));
(l1 = ((* ((struct struct0x08525c88 *) l1)).tail));
({goto _sharp__sharp_loop388_continue390;});
})
;}})
;
({goto _sharp__sharp_loop388_end389;});
})
):
(({if( (l2 != ((List__O__Character_Set__C____type__type ) 0)))
{
({
({goto _sharp__sharp_loop388_end389;});
})
;}})
));
({goto _sharp__sharp_loop388_end389;});
})
;
({goto _sharp__sharp_loop388_begin391;});});
_sharp__sharp_loop388_end389:;});});
((void) 0);
((void) 0);
})
;
((* _sharp_make_list_ptr387) = ((void *) 0));
_sharp_make_list386;});
})
);
})
;}

Form__type  is_in_Character_Set_condition(List__O__Character_Set__C____type__type  cs_list)
{
return ({
Int__type i;
Form__type final_final_cond;
Form__type final_cond;
final_cond;
(final_final_cond = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_393;
({_sharp_pair_393;
(_sharp_pair_393 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_393).car) = (Id_Form)(intern( "Bool")));
(((* _sharp_pair_393).cdr) = ({
struct struct0x08067248 *_sharp_pair_392;
({_sharp_pair_392;
(_sharp_pair_392 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_392).car) = (Int_Form)(1));
(((* _sharp_pair_392).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_392);
})
);
((List__O__Form__C____type__type ) _sharp_pair_393);
})
));
(i = 0);
({
List__O__Character_Set__C____type__type _sharp_iterator395;
(_sharp_iterator395 = cs_list);
({({_sharp__sharp_loop396_begin420:;
({
Character_Set__type cs;
({if( (_sharp_iterator395 == ((List__O__Character_Set__C____type__type ) 0)))
{
({goto _sharp__sharp_loop396_end397;});}})
;
(cs = ((* ((struct struct0x08550ad8 *) _sharp_iterator395)).car));
({
Form__type get_form;
(get_form = (Compound_Form)(intern( "new_peek_char"), ({
struct struct0x08067248 *_sharp_pair_398;
({_sharp_pair_398;
(_sharp_pair_398 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_398).car) = (Int_Form)(i));
(((* _sharp_pair_398).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_398);
})
));
(i = ((int) i + (int) 1));
(final_cond = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_400;
({_sharp_pair_400;
(_sharp_pair_400 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_400).car) = (Id_Form)(intern( "Bool")));
(((* _sharp_pair_400).cdr) = ({
struct struct0x08067248 *_sharp_pair_399;
({_sharp_pair_399;
(_sharp_pair_399 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_399).car) = (Int_Form)(0));
(((* _sharp_pair_399).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_399);
})
);
((List__O__Form__C____type__type ) _sharp_pair_400);
})
));
({
List__O__Character_Range__C____type__type _sharp_iterator402;
(_sharp_iterator402 = ((List__O__Character_Range__C____type__type ) cs));
({({_sharp__sharp_loop403_begin416:;
({
Character_Range__type cr;
({if( (_sharp_iterator402 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop403_end404;});}})
;
(cr = ((* ((struct struct0x08528220 *) _sharp_iterator402)).car));
({
Form__type cond;
(cond = (((((* ((struct struct0x08525170 *) cr)).min) == ((* ((struct struct0x08525170 *) cr)).max)))?
(({
(Compound_Form)(intern( "=="), ({
struct struct0x08067248 *_sharp_pair_406;
({_sharp_pair_406;
(_sharp_pair_406 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_406).car) = get_form);
(((* _sharp_pair_406).cdr) = ({
struct struct0x08067248 *_sharp_pair_405;
({_sharp_pair_405;
(_sharp_pair_405 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_405).car) = (Int_Form)(((* ((struct struct0x08525170 *) cr)).min)));
(((* _sharp_pair_405).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_405);
})
);
((List__O__Form__C____type__type ) _sharp_pair_406);
})
);
})
):
(({
(Compound_Form)(intern( "@and"), ({
struct struct0x08067248 *_sharp_pair_412;
({_sharp_pair_412;
(_sharp_pair_412 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_412).car) = (Compound_Form)(intern( ">="), ({
struct struct0x08067248 *_sharp_pair_408;
({_sharp_pair_408;
(_sharp_pair_408 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_408).car) = get_form);
(((* _sharp_pair_408).cdr) = ({
struct struct0x08067248 *_sharp_pair_407;
({_sharp_pair_407;
(_sharp_pair_407 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_407).car) = (Int_Form)(((* ((struct struct0x08525170 *) cr)).min)));
(((* _sharp_pair_407).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_407);
})
);
((List__O__Form__C____type__type ) _sharp_pair_408);
})
));
(((* _sharp_pair_412).cdr) = ({
struct struct0x08067248 *_sharp_pair_411;
({_sharp_pair_411;
(_sharp_pair_411 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_411).car) = (Compound_Form)(intern( "<="), ({
struct struct0x08067248 *_sharp_pair_410;
({_sharp_pair_410;
(_sharp_pair_410 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_410).car) = get_form);
(((* _sharp_pair_410).cdr) = ({
struct struct0x08067248 *_sharp_pair_409;
({_sharp_pair_409;
(_sharp_pair_409 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_409).car) = (Int_Form)(((* ((struct struct0x08525170 *) cr)).max)));
(((* _sharp_pair_409).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_409);
})
);
((List__O__Form__C____type__type ) _sharp_pair_410);
})
));
(((* _sharp_pair_411).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_411);
})
);
((List__O__Form__C____type__type ) _sharp_pair_412);
})
);
})
)));
(final_cond = (Compound_Form)(intern( "@or"), ({
struct struct0x08067248 *_sharp_pair_414;
({_sharp_pair_414;
(_sharp_pair_414 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_414).car) = cond);
(((* _sharp_pair_414).cdr) = ({
struct struct0x08067248 *_sharp_pair_413;
({_sharp_pair_413;
(_sharp_pair_413 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_413).car) = final_cond);
(((* _sharp_pair_413).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_413);
})
);
((List__O__Form__C____type__type ) _sharp_pair_414);
})
));
})
;
_sharp__sharp_loop403_continue415:;
(_sharp_iterator402 = ((* ((struct struct0x08528220 *) _sharp_iterator402)).cdr));
})
;
({goto _sharp__sharp_loop403_begin416;});});
_sharp__sharp_loop403_end404:;});
})
;
(final_final_cond = (Compound_Form)(intern( "@and"), ({
struct struct0x08067248 *_sharp_pair_418;
({_sharp_pair_418;
(_sharp_pair_418 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_418).car) = final_final_cond);
(((* _sharp_pair_418).cdr) = ({
struct struct0x08067248 *_sharp_pair_417;
({_sharp_pair_417;
(_sharp_pair_417 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_417).car) = final_cond);
(((* _sharp_pair_417).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_417);
})
);
((List__O__Form__C____type__type ) _sharp_pair_418);
})
));
})
;
_sharp__sharp_loop396_continue419:;
(_sharp_iterator395 = ((* ((struct struct0x08550ad8 *) _sharp_iterator395)).cdr));
})
;
({goto _sharp__sharp_loop396_begin420;});});
_sharp__sharp_loop396_end397:;});
})
;
final_final_cond;
})
;}

String__type  function_name_from_grammar_and_rule(Symbol__type  grammar_name, Symbol__type  rule_name)
{
return ({
(concat)(((String__type) &__string_12), (concat)((get_symbol_name)((convert_id)(grammar_name)), (concat)(((String__type) &__string_13), (get_symbol_name)((convert_id)(rule_name)))));
})
;}

List__O__Character_Set__C____type__type  head_set(Form__type  parse_form, List__O__Form__C____type__type  next_rules)
{
return ({
List__O__Character_Set__C____type__type cs_list;
Character_Set__type cs;
cs;
cs_list;
(((is_compound_form)(parse_form))?
(({
Compound_Form__type cf;
(cf = ((Compound_Form__type ) parse_form));
(((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "[]")))?
(({
(cs_list = ({
struct struct0x08550ad8 *_sharp_pair_421;
({_sharp_pair_421;
(_sharp_pair_421 = ((struct struct0x08550ad8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_421).car) = (make_Character_Set)(((Form__type ) cf)));
(((* _sharp_pair_421).cdr) = ((List__O__Character_Set__C____type__type ) 0));
((List__O__Character_Set__C____type__type ) _sharp_pair_421);
})
);
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "[^]")))?
(({
(cs_list = ({
struct struct0x08550ad8 *_sharp_pair_422;
({_sharp_pair_422;
(_sharp_pair_422 = ((struct struct0x08550ad8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_422).car) = (make_inverse_Character_Set)(((Form__type ) cf)));
(((* _sharp_pair_422).cdr) = ((List__O__Character_Set__C____type__type ) 0));
((List__O__Character_Set__C____type__type ) _sharp_pair_422);
})
);
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( " ")))?
(({
(cs_list = (head_set)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head), ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail)));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( ":")))?
(({
(cs_list = (head_set)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail))).head), next_rules));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "|")))?
(({
List__O__Character_Set__C____type__type cs_;
({if( ((((* ((struct struct0x0805ee90 *) cf)).form_list) != ((List__O__Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_14));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x08067248 *_sharp_pair_429;
({_sharp_pair_429;
(_sharp_pair_429 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_429).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_424;
({_sharp_pair_424;
(_sharp_pair_424 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_424).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_424).cdr) = ({
struct struct0x08067248 *_sharp_pair_423;
({_sharp_pair_423;
(_sharp_pair_423 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_423).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_423).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_423);
})
);
((List__O__Form__C____type__type ) _sharp_pair_424);
})
));
(((* _sharp_pair_429).cdr) = ({
struct struct0x08067248 *_sharp_pair_428;
({_sharp_pair_428;
(_sharp_pair_428 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_428).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_427;
({_sharp_pair_427;
(_sharp_pair_427 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_427).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067248 *_sharp_pair_425;
({_sharp_pair_425;
(_sharp_pair_425 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_425).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_425).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_425);
})
));
(((* _sharp_pair_427).cdr) = ({
struct struct0x08067248 *_sharp_pair_426;
({_sharp_pair_426;
(_sharp_pair_426 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_426).car) = (Int_Form)(0));
(((* _sharp_pair_426).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_426);
})
);
((List__O__Form__C____type__type ) _sharp_pair_427);
})
));
(((* _sharp_pair_428).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_428);
})
);
((List__O__Form__C____type__type ) _sharp_pair_429);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_15));
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
(cs_ = (head_set)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head), next_rules));
({
List__O__Form__C____type__type _sharp_iterator431;
(_sharp_iterator431 = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail));
({({_sharp__sharp_loop432_begin435:;
({
Form__type rule;
({if( (_sharp_iterator431 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop432_end433;});}})
;
(rule = ((* ((struct struct0x08067248 *) _sharp_iterator431)).car));
({
(cs_ = (union_Character_Set_List)((head_set)(rule, next_rules), cs_));
})
;
_sharp__sharp_loop432_continue434:;
(_sharp_iterator431 = ((* ((struct struct0x08067248 *) _sharp_iterator431)).cdr));
})
;
({goto _sharp__sharp_loop432_begin435;});});
_sharp__sharp_loop432_end433:;});
})
;
(cs_list = cs_);
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "*")))?
(({
List__O__Character_Set__C____type__type cs_;
(cs_ = (union_Character_Set_List)((head_set)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head), ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail)), (head_set)(((* ((struct struct0x0805f088 *) next_rules)).head), ((* ((struct struct0x0805f088 *) next_rules)).tail))));
(cs_list = cs_);
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "+")))?
(({
(cs_list = (head_set)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head), ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail)));
((void) 0);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "{}")))?
(({
(((next_rules == ((List__O__Form__C____type__type ) 0)))?
(({
(cs_list = ((List__O__Character_Set__C____type__type ) 0));
})
):
((cs_list = (head_set)(((* ((struct struct0x0805f088 *) next_rules)).head), ((* ((struct struct0x0805f088 *) next_rules)).tail)))));
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
({if( ((((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))) != ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_16));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x08067248 *_sharp_pair_444;
({_sharp_pair_444;
(_sharp_pair_444 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_444).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_437;
({_sharp_pair_437;
(_sharp_pair_437 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_437).car) = (Id_Form)(intern( "head_set_hash")));
(((* _sharp_pair_437).cdr) = ({
struct struct0x08067248 *_sharp_pair_436;
({_sharp_pair_436;
(_sharp_pair_436 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_436).car) = (Id_Form)(intern( "grammar_name")));
(((* _sharp_pair_436).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_436);
})
);
((List__O__Form__C____type__type ) _sharp_pair_437);
})
));
(((* _sharp_pair_444).cdr) = ({
struct struct0x08067248 *_sharp_pair_443;
({_sharp_pair_443;
(_sharp_pair_443 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_443).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_442;
({_sharp_pair_442;
(_sharp_pair_442 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_442).car) = (Compound_Form)(intern( "Hash"), ({
struct struct0x08067248 *_sharp_pair_440;
({_sharp_pair_440;
(_sharp_pair_440 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_440).car) = (Id_Form)(intern( "Symbol")));
(((* _sharp_pair_440).cdr) = ({
struct struct0x08067248 *_sharp_pair_439;
({_sharp_pair_439;
(_sharp_pair_439 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_439).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067248 *_sharp_pair_438;
({_sharp_pair_438;
(_sharp_pair_438 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_438).car) = (Id_Form)(intern( "Character_Set")));
(((* _sharp_pair_438).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_438);
})
));
(((* _sharp_pair_439).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_439);
})
);
((List__O__Form__C____type__type ) _sharp_pair_440);
})
));
(((* _sharp_pair_442).cdr) = ({
struct struct0x08067248 *_sharp_pair_441;
({_sharp_pair_441;
(_sharp_pair_441 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_441).car) = (Int_Form)(0));
(((* _sharp_pair_441).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_441);
})
);
((List__O__Form__C____type__type ) _sharp_pair_442);
})
));
(((* _sharp_pair_443).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_443);
})
);
((List__O__Form__C____type__type ) _sharp_pair_444);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_17));
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
(cs_list = ((List__O__Character_Set__C____type__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash)))))));
({if( (cs_list == ((List__O__Character_Set__C____type__type ) 0)))
{
({
Form__type named_rule;
((List__O__Character_Set__C____type__type ) (puthash)(((void *) rule_name), ((void *) ((List__O__Character_Set__C____type__type ) (- (int) 1))), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
(named_rule = ((Form__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash)))))));
({if( (named_rule == ((Form__type ) 0)))
{
({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_18));
(print_String)(((String__type) &__string_19));
(print_Symbol)(rule_name);
(print_String)(((String__type) &__string_20));
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
(cs_list = (head_set)(named_rule, ((List__O__Form__C____type__type ) 0)));
({if( (cs_list == ((List__O__Character_Set__C____type__type ) (- (int) 1))))
{
({
({(print_String)(((String__type) &__string_21));
(print_Symbol)(rule_name);
(print_String)(((String__type) &__string_22));
(maybe_flush)();});
(exit)(3);
})
;}})
;
((List__O__Character_Set__C____type__type ) (puthash)(((void *) rule_name), ((void *) cs_list), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
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
({(print_String)(((String__type) &__string_23));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08067248 *_sharp_pair_445;
({_sharp_pair_445;
(_sharp_pair_445 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_445).car) = (Id_Form)(intern( "form")));
(((* _sharp_pair_445).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_445);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_24));
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
(form_head = ((* ((struct struct0x0805ee90 *) ((Compound_Form__type ) form))).head));
(grammar_form = (call_grammar_macro)(form_head, form));
(cs_list = (head_set)(grammar_form, next_rules));
((void) 0);
})
):
(({
({(print_String)(((String__type) &__string_25));
(print_Symbol)(((* ((struct struct0x0805ee90 *) cf)).head));
(print_String)(((String__type) &__string_26));
(maybe_flush)();});
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
({(print_String)(((String__type) &__string_27));
(print_String)(((String__type) &__string_28));
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
(cs_list = (head_set)(((* ((struct struct0x0805f088 *) next_rules)).head), ((* ((struct struct0x0805f088 *) next_rules)).tail)));
((void) 0);
})
):
(({
({if( ((((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))) != ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_29));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x08067248 *_sharp_pair_454;
({_sharp_pair_454;
(_sharp_pair_454 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_454).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_447;
({_sharp_pair_447;
(_sharp_pair_447 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_447).car) = (Id_Form)(intern( "head_set_hash")));
(((* _sharp_pair_447).cdr) = ({
struct struct0x08067248 *_sharp_pair_446;
({_sharp_pair_446;
(_sharp_pair_446 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_446).car) = (Id_Form)(intern( "grammar_name")));
(((* _sharp_pair_446).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_446);
})
);
((List__O__Form__C____type__type ) _sharp_pair_447);
})
));
(((* _sharp_pair_454).cdr) = ({
struct struct0x08067248 *_sharp_pair_453;
({_sharp_pair_453;
(_sharp_pair_453 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_453).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_452;
({_sharp_pair_452;
(_sharp_pair_452 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_452).car) = (Compound_Form)(intern( "Hash"), ({
struct struct0x08067248 *_sharp_pair_450;
({_sharp_pair_450;
(_sharp_pair_450 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_450).car) = (Id_Form)(intern( "Symbol")));
(((* _sharp_pair_450).cdr) = ({
struct struct0x08067248 *_sharp_pair_449;
({_sharp_pair_449;
(_sharp_pair_449 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_449).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067248 *_sharp_pair_448;
({_sharp_pair_448;
(_sharp_pair_448 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_448).car) = (Id_Form)(intern( "Character_Set")));
(((* _sharp_pair_448).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_448);
})
));
(((* _sharp_pair_449).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_449);
})
);
((List__O__Form__C____type__type ) _sharp_pair_450);
})
));
(((* _sharp_pair_452).cdr) = ({
struct struct0x08067248 *_sharp_pair_451;
({_sharp_pair_451;
(_sharp_pair_451 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_451).car) = (Int_Form)(0));
(((* _sharp_pair_451).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_451);
})
);
((List__O__Form__C____type__type ) _sharp_pair_452);
})
));
(((* _sharp_pair_453).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_453);
})
);
((List__O__Form__C____type__type ) _sharp_pair_454);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_30));
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
(cs_list = ((List__O__Character_Set__C____type__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash)))))));
({if( (cs_list == ((List__O__Character_Set__C____type__type ) 0)))
{
({
Form__type named_rule;
((List__O__Character_Set__C____type__type ) (puthash)(((void *) rule_name), ((void *) ((List__O__Character_Set__C____type__type ) (- (int) 1))), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
(named_rule = ((Form__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash)))))));
({if( (named_rule == ((Form__type ) 0)))
{
({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_31));
(print_String)(((String__type) &__string_32));
(print_Symbol)(rule_name);
(print_String)(((String__type) &__string_33));
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
(cs_list = (head_set)(named_rule, ((List__O__Form__C____type__type ) 0)));
({if( (cs_list == ((List__O__Character_Set__C____type__type ) (- (int) 1))))
{
({
({(print_String)(((String__type) &__string_34));
(print_Symbol)(rule_name);
(print_String)(((String__type) &__string_35));
(maybe_flush)();});
(exit)(3);
})
;}})
;
((List__O__Character_Set__C____type__type ) (puthash)(((void *) rule_name), ((void *) cs_list), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
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
struct struct0x08525170 *_sharp_pointer_alloc455;
Int__type head;
(head = (string_element)(((* ((struct struct0x0805baa0 *) ((String_Form__type ) parse_form))).value), 0));
(cs_list = ({
struct struct0x08550ad8 *_sharp_pair_457;
({_sharp_pair_457;
(_sharp_pair_457 = ((struct struct0x08550ad8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_457).car) = ((Character_Set__type ) ({
struct struct0x08528220 *_sharp_pair_456;
({_sharp_pair_456;
(_sharp_pair_456 = ((struct struct0x08528220 *) (alloc_cons_cell)()));});
(((* _sharp_pair_456).car) = ((Character_Range__type ) ({_sharp_pointer_alloc455;
(_sharp_pointer_alloc455 = ((struct struct0x08525170 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc455) = ((struct struct0x08525170 ){head, head}));
((struct struct0x08525170 *) _sharp_pointer_alloc455);})));
(((* _sharp_pair_456).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_456);
})
));
(((* _sharp_pair_457).cdr) = ((List__O__Character_Set__C____type__type ) 0));
((List__O__Character_Set__C____type__type ) _sharp_pair_457);
})
);
((void) 0);
})
):
((((is_symbol_form)(parse_form))?
(({
void **_sharp_make_list_ptr459;
List__O__Int__C____type__type l;
(l = (string_to_int_list)((get_symbol_name)(((* ((struct struct0x08059be8 *) ((Symbol_Form__type ) parse_form))).value))));
(cs_list = ({
List__O__Character_Set__C____type__type _sharp_make_list458;
({_sharp_make_list458;
_sharp_make_list_ptr459;
(_sharp_make_list_ptr459 = ((void *) (&_sharp_make_list458)));
({
({
List__O__Int__C____type__type _sharp_iterator461;
(_sharp_iterator461 = l);
({({_sharp__sharp_loop462_begin467:;
({
Int__type head;
({if( (_sharp_iterator461 == ((List__O__Int__C____type__type ) 0)))
{
({goto _sharp__sharp_loop462_end463;});}})
;
(head = ((* ((struct struct0x085902f8 *) _sharp_iterator461)).car));
({
struct struct0x08525170 *_sharp_pointer_alloc464;
({((* _sharp_make_list_ptr459) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr459))).car) = ((void *) ((Character_Set__type ) ({
struct struct0x08528220 *_sharp_pair_465;
({_sharp_pair_465;
(_sharp_pair_465 = ((struct struct0x08528220 *) (alloc_cons_cell)()));});
(((* _sharp_pair_465).car) = ((Character_Range__type ) ({_sharp_pointer_alloc464;
(_sharp_pointer_alloc464 = ((struct struct0x08525170 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc464) = ((struct struct0x08525170 ){head, head}));
((struct struct0x08525170 *) _sharp_pointer_alloc464);})));
(((* _sharp_pair_465).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_465);
})
)));
(_sharp_make_list_ptr459 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr459))).cdr)));
((void) 0);});
})
;
_sharp__sharp_loop462_continue466:;
(_sharp_iterator461 = ((* ((struct struct0x085902f8 *) _sharp_iterator461)).cdr));
})
;
({goto _sharp__sharp_loop462_begin467;});});
_sharp__sharp_loop462_end463:;});
})
;
((void) 0);
((void) 0);
})
;
((* _sharp_make_list_ptr459) = ((void *) 0));
_sharp_make_list458;});
})
);
((void) 0);
})
):
(({
({(print_String)(((String__type) &__string_36));
(maybe_flush)();});
(print_form)(parse_form);
(exit)(3);
})
))))))));
cs_list;
})
;}

Form__type  head_set_function(Form__type  parse_form)
{
return ({
Form__type cop_form;
Form__type ret_form;
(ret_form = ((Form__type ) 0));
(cop_form = parse_form);
({({_sharp__sharp_loop468_begin470:;
({({if( (!((((is_compound_form)(cop_form))&&((((* ((struct struct0x0805ee90 *) ((Compound_Form__type ) cop_form))).head) == intern( " ")))))))
{
({goto _sharp__sharp_loop468_end469;});}})
;
(cop_form = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) ((Compound_Form__type ) cop_form))).form_list))).head));});
({goto _sharp__sharp_loop468_begin470;});});
_sharp__sharp_loop468_end469:;});
({if( (is_compound_form)(cop_form))
{
({
Compound_Form__type cf;
(cf = ((Compound_Form__type ) cop_form));
({if( (((* ((struct struct0x0805ee90 *) cf)).head) == intern( "&")))
{
({
({if( ((((is_compound_form)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head)))&&((((* ((struct struct0x0805ee90 *) ((Compound_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head)))).head) == intern( "{}")))) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_37));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "@and"), ({
struct struct0x08067248 *_sharp_pair_487;
({_sharp_pair_487;
(_sharp_pair_487 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_487).car) = (Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08067248 *_sharp_pair_475;
({_sharp_pair_475;
(_sharp_pair_475 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_475).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_474;
({_sharp_pair_474;
(_sharp_pair_474 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_474).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_472;
({_sharp_pair_472;
(_sharp_pair_472 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_472).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_472).cdr) = ({
struct struct0x08067248 *_sharp_pair_471;
({_sharp_pair_471;
(_sharp_pair_471 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_471).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_471).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_471);
})
);
((List__O__Form__C____type__type ) _sharp_pair_472);
})
));
(((* _sharp_pair_474).cdr) = ({
struct struct0x08067248 *_sharp_pair_473;
({_sharp_pair_473;
(_sharp_pair_473 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_473).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_473).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_473);
})
);
((List__O__Form__C____type__type ) _sharp_pair_474);
})
));
(((* _sharp_pair_475).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_475);
})
));
(((* _sharp_pair_487).cdr) = ({
struct struct0x08067248 *_sharp_pair_486;
({_sharp_pair_486;
(_sharp_pair_486 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_486).car) = (Compound_Form)(intern( "=="), ({
struct struct0x08067248 *_sharp_pair_485;
({_sharp_pair_485;
(_sharp_pair_485 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_485).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_483;
({_sharp_pair_483;
(_sharp_pair_483 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_483).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_481;
({_sharp_pair_481;
(_sharp_pair_481 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_481).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_481).cdr) = ({
struct struct0x08067248 *_sharp_pair_480;
({_sharp_pair_480;
(_sharp_pair_480 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_480).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_479;
({_sharp_pair_479;
(_sharp_pair_479 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_479).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_477;
({_sharp_pair_477;
(_sharp_pair_477 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_477).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_477).cdr) = ({
struct struct0x08067248 *_sharp_pair_476;
({_sharp_pair_476;
(_sharp_pair_476 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_476).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_476).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_476);
})
);
((List__O__Form__C____type__type ) _sharp_pair_477);
})
));
(((* _sharp_pair_479).cdr) = ({
struct struct0x08067248 *_sharp_pair_478;
({_sharp_pair_478;
(_sharp_pair_478 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_478).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_478).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_478);
})
);
((List__O__Form__C____type__type ) _sharp_pair_479);
})
));
(((* _sharp_pair_480).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_480);
})
);
((List__O__Form__C____type__type ) _sharp_pair_481);
})
));
(((* _sharp_pair_483).cdr) = ({
struct struct0x08067248 *_sharp_pair_482;
({_sharp_pair_482;
(_sharp_pair_482 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_482).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_482).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_482);
})
);
((List__O__Form__C____type__type ) _sharp_pair_483);
})
));
(((* _sharp_pair_485).cdr) = ({
struct struct0x08067248 *_sharp_pair_484;
({_sharp_pair_484;
(_sharp_pair_484 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_484).car) = (Symbol_Form)(intern( "{}")));
(((* _sharp_pair_484).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_484);
})
);
((List__O__Form__C____type__type ) _sharp_pair_485);
})
));
(((* _sharp_pair_486).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_486);
})
);
((List__O__Form__C____type__type ) _sharp_pair_487);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_38));
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
(ret_form = (grammar_expander_rec)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head), ((List__O__Form__C____type__type ) 0)));
})
;}})
;
})
;}})
;
({if( (ret_form == ((Form__type ) 0)))
{
({
List__O__Character_Set__C____type__type ret_set;
(ret_set = (head_set)(parse_form, ((List__O__Form__C____type__type ) 0)));
(ret_form = (is_in_Character_Set_condition)(ret_set));
})
;}})
;
ret_form;
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
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( ":")))?
(({
Expanded_Form__type exp_right_form;
Form__type subrule;
Form__type left_form;
Symbol__type id;
Id_Form__type id_form;
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
struct struct0x08067248 *_sharp_pair_488;
({_sharp_pair_488;
(_sharp_pair_488 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_488).car) = right_form);
(((* _sharp_pair_488).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_488);
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
struct struct0x08067248 *_sharp_pair_490;
({_sharp_pair_490;
(_sharp_pair_490 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_490).car) = ((Form__type ) id_form));
(((* _sharp_pair_490).cdr) = ({
struct struct0x08067248 *_sharp_pair_489;
({_sharp_pair_489;
(_sharp_pair_489 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_489).car) = (((struct struct0x08065bc8 ) ((* ((struct struct0x0805dbc8 *) ((Real_Type__type ) ((* ((struct struct0x0805f900 *) exp_right_form)).type)))).common_)).type_form));
(((* _sharp_pair_489).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_489);
})
);
((List__O__Form__C____type__type ) _sharp_pair_490);
})
));
})
;}})
;
(Compound_Form)(intern( "="), ({
struct struct0x08067248 *_sharp_pair_492;
({_sharp_pair_492;
(_sharp_pair_492 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_492).car) = left_form);
(((* _sharp_pair_492).cdr) = ({
struct struct0x08067248 *_sharp_pair_491;
({_sharp_pair_491;
(_sharp_pair_491 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_491).car) = ((Form__type ) exp_right_form));
(((* _sharp_pair_491).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_491);
})
);
((List__O__Form__C____type__type ) _sharp_pair_492);
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
void **_sharp_make_list_ptr494;
List__O__Form__C____type__type fl;
(fl = ({
List__O__Form__C____type__type _sharp_make_list493;
({_sharp_make_list493;
_sharp_make_list_ptr494;
(_sharp_make_list_ptr494 = ((void *) (&_sharp_make_list493)));
({
List__O__Form__C____type__type grammar_rule_it;
(grammar_rule_it = ((* ((struct struct0x0805ee90 *) cf)).form_list));
({({_sharp__sharp_loop495_begin497:;
({({if( (!((grammar_rule_it != ((List__O__Form__C____type__type ) 0)))))
{
({goto _sharp__sharp_loop495_end496;});}})
;
({
List__O__Form__C____type__type grammar_tail;
Form__type grammar_rule;
(grammar_rule = ((* ((struct struct0x0805f088 *) grammar_rule_it)).head));
(grammar_tail = ((* ((struct struct0x0805f088 *) grammar_rule_it)).tail));
({((* _sharp_make_list_ptr494) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr494))).car) = ((void *) (grammar_expander_rec)(grammar_rule, grammar_tail)));
(_sharp_make_list_ptr494 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr494))).cdr)));
((void) 0);});
(grammar_rule_it = grammar_tail);
})
;});
({goto _sharp__sharp_loop495_begin497;});});
_sharp__sharp_loop495_end496:;});
((void) 0);
})
;
((* _sharp_make_list_ptr494) = ((void *) 0));
_sharp_make_list493;});
})
);
(Compound_Form)(intern( "seq"), fl);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "|")))?
(({
((((Bool__type ) 1))?
(({
Form__type cond_form;
Form__type maybe_rule;
({if( ((((((((* ((struct struct0x0805ee90 *) cf)).form_list) != ((List__O__Form__C____type__type ) 0)))&&((((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail) != ((List__O__Form__C____type__type ) 0)))))&&((((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail))).tail) == ((List__O__Form__C____type__type ) 0)))) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_39));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "@and"), ({
struct struct0x08067248 *_sharp_pair_528;
({_sharp_pair_528;
(_sharp_pair_528 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_528).car) = (Compound_Form)(intern( "@and"), ({
struct struct0x08067248 *_sharp_pair_515;
({_sharp_pair_515;
(_sharp_pair_515 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_515).car) = (Compound_Form)(intern( "!="), ({
struct struct0x08067248 *_sharp_pair_504;
({_sharp_pair_504;
(_sharp_pair_504 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_504).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_499;
({_sharp_pair_499;
(_sharp_pair_499 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_499).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_499).cdr) = ({
struct struct0x08067248 *_sharp_pair_498;
({_sharp_pair_498;
(_sharp_pair_498 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_498).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_498).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_498);
})
);
((List__O__Form__C____type__type ) _sharp_pair_499);
})
));
(((* _sharp_pair_504).cdr) = ({
struct struct0x08067248 *_sharp_pair_503;
({_sharp_pair_503;
(_sharp_pair_503 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_503).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_502;
({_sharp_pair_502;
(_sharp_pair_502 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_502).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067248 *_sharp_pair_500;
({_sharp_pair_500;
(_sharp_pair_500 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_500).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_500).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_500);
})
));
(((* _sharp_pair_502).cdr) = ({
struct struct0x08067248 *_sharp_pair_501;
({_sharp_pair_501;
(_sharp_pair_501 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_501).car) = (Int_Form)(0));
(((* _sharp_pair_501).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_501);
})
);
((List__O__Form__C____type__type ) _sharp_pair_502);
})
));
(((* _sharp_pair_503).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_503);
})
);
((List__O__Form__C____type__type ) _sharp_pair_504);
})
));
(((* _sharp_pair_515).cdr) = ({
struct struct0x08067248 *_sharp_pair_514;
({_sharp_pair_514;
(_sharp_pair_514 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_514).car) = (Compound_Form)(intern( "!="), ({
struct struct0x08067248 *_sharp_pair_513;
({_sharp_pair_513;
(_sharp_pair_513 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_513).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_508;
({_sharp_pair_508;
(_sharp_pair_508 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_508).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_506;
({_sharp_pair_506;
(_sharp_pair_506 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_506).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_506).cdr) = ({
struct struct0x08067248 *_sharp_pair_505;
({_sharp_pair_505;
(_sharp_pair_505 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_505).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_505).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_505);
})
);
((List__O__Form__C____type__type ) _sharp_pair_506);
})
));
(((* _sharp_pair_508).cdr) = ({
struct struct0x08067248 *_sharp_pair_507;
({_sharp_pair_507;
(_sharp_pair_507 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_507).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_507).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_507);
})
);
((List__O__Form__C____type__type ) _sharp_pair_508);
})
));
(((* _sharp_pair_513).cdr) = ({
struct struct0x08067248 *_sharp_pair_512;
({_sharp_pair_512;
(_sharp_pair_512 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_512).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_511;
({_sharp_pair_511;
(_sharp_pair_511 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_511).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067248 *_sharp_pair_509;
({_sharp_pair_509;
(_sharp_pair_509 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_509).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_509).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_509);
})
));
(((* _sharp_pair_511).cdr) = ({
struct struct0x08067248 *_sharp_pair_510;
({_sharp_pair_510;
(_sharp_pair_510 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_510).car) = (Int_Form)(0));
(((* _sharp_pair_510).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_510);
})
);
((List__O__Form__C____type__type ) _sharp_pair_511);
})
));
(((* _sharp_pair_512).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_512);
})
);
((List__O__Form__C____type__type ) _sharp_pair_513);
})
));
(((* _sharp_pair_514).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_514);
})
);
((List__O__Form__C____type__type ) _sharp_pair_515);
})
));
(((* _sharp_pair_528).cdr) = ({
struct struct0x08067248 *_sharp_pair_527;
({_sharp_pair_527;
(_sharp_pair_527 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_527).car) = (Compound_Form)(intern( "=="), ({
struct struct0x08067248 *_sharp_pair_526;
({_sharp_pair_526;
(_sharp_pair_526 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_526).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_521;
({_sharp_pair_521;
(_sharp_pair_521 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_521).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_519;
({_sharp_pair_519;
(_sharp_pair_519 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_519).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_517;
({_sharp_pair_517;
(_sharp_pair_517 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_517).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_517).cdr) = ({
struct struct0x08067248 *_sharp_pair_516;
({_sharp_pair_516;
(_sharp_pair_516 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_516).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_516).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_516);
})
);
((List__O__Form__C____type__type ) _sharp_pair_517);
})
));
(((* _sharp_pair_519).cdr) = ({
struct struct0x08067248 *_sharp_pair_518;
({_sharp_pair_518;
(_sharp_pair_518 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_518).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_518).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_518);
})
);
((List__O__Form__C____type__type ) _sharp_pair_519);
})
));
(((* _sharp_pair_521).cdr) = ({
struct struct0x08067248 *_sharp_pair_520;
({_sharp_pair_520;
(_sharp_pair_520 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_520).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_520).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_520);
})
);
((List__O__Form__C____type__type ) _sharp_pair_521);
})
));
(((* _sharp_pair_526).cdr) = ({
struct struct0x08067248 *_sharp_pair_525;
({_sharp_pair_525;
(_sharp_pair_525 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_525).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_524;
({_sharp_pair_524;
(_sharp_pair_524 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_524).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067248 *_sharp_pair_522;
({_sharp_pair_522;
(_sharp_pair_522 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_522).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_522).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_522);
})
));
(((* _sharp_pair_524).cdr) = ({
struct struct0x08067248 *_sharp_pair_523;
({_sharp_pair_523;
(_sharp_pair_523 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_523).car) = (Int_Form)(0));
(((* _sharp_pair_523).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_523);
})
);
((List__O__Form__C____type__type ) _sharp_pair_524);
})
));
(((* _sharp_pair_525).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_525);
})
);
((List__O__Form__C____type__type ) _sharp_pair_526);
})
));
(((* _sharp_pair_527).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_527);
})
);
((List__O__Form__C____type__type ) _sharp_pair_528);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_40));
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
(maybe_rule = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head));
(cond_form = (head_set_function)(maybe_rule));
(Compound_Form)(intern( "block"), ({
struct struct0x08067248 *_sharp_pair_532;
({_sharp_pair_532;
(_sharp_pair_532 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_532).car) = (Compound_Form)(intern( "if"), ({
struct struct0x08067248 *_sharp_pair_531;
({_sharp_pair_531;
(_sharp_pair_531 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_531).car) = cond_form);
(((* _sharp_pair_531).cdr) = ({
struct struct0x08067248 *_sharp_pair_530;
({_sharp_pair_530;
(_sharp_pair_530 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_530).car) = (grammar_expander_rec)(maybe_rule, next_rules));
(((* _sharp_pair_530).cdr) = ({
struct struct0x08067248 *_sharp_pair_529;
({_sharp_pair_529;
(_sharp_pair_529 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_529).car) = (grammar_expander_rec)(((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).tail))).head), next_rules));
(((* _sharp_pair_529).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_529);
})
);
((List__O__Form__C____type__type ) _sharp_pair_530);
})
);
((List__O__Form__C____type__type ) _sharp_pair_531);
})
));
(((* _sharp_pair_532).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_532);
})
);
})
):
(({
Int__type number_rule_empty;
Form__type else_form;
Form__type *orig_else_form_ptr;
Form__type peeked_char_form;
Form__type ret_form;
Symbol__type peeked_char;
List__O__Form__C____type__type form_list;
(peeked_char = (gensym)(((String__type) &__string_41)));
(peeked_char_form = (Id_Form)(peeked_char));
(orig_else_form_ptr = ((Form__type *) 0));
(else_form = (Compound_Form)(intern( "parse_error"), ((List__O__Form__C____type__type ) 0)));
(number_rule_empty = 0);
(form_list = ((* ((struct struct0x0805ee90 *) cf)).form_list));
({
List__O__Form__C____type__type _sharp_iterator534;
(_sharp_iterator534 = form_list);
({({_sharp__sharp_loop535_begin546:;
({
Form__type grammar_rule;
({if( (_sharp_iterator534 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop535_end536;});}})
;
(grammar_rule = ((* ((struct struct0x08067248 *) _sharp_iterator534)).car));
({
List__O__Character_Set__C____type__type char_set;
(char_set = (head_set)(grammar_rule, ((List__O__Form__C____type__type ) 0)));
(((char_set == ((List__O__Character_Set__C____type__type ) 0)))?
(({
(number_rule_empty = ((int) number_rule_empty + (int) 1));
({if( ((int) number_rule_empty > (int) 1))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_42));
(print_String)(((String__type) &__string_43));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;}})
;
({if( ((orig_else_form_ptr != ((Form__type *) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_44));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x08067248 *_sharp_pair_541;
({_sharp_pair_541;
(_sharp_pair_541 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_541).car) = (Id_Form)(intern( "orig_else_form_ptr")));
(((* _sharp_pair_541).cdr) = ({
struct struct0x08067248 *_sharp_pair_540;
({_sharp_pair_540;
(_sharp_pair_540 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_540).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067248 *_sharp_pair_539;
({_sharp_pair_539;
(_sharp_pair_539 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_539).car) = (Compound_Form)(intern( "pointer"), ({
struct struct0x08067248 *_sharp_pair_537;
({_sharp_pair_537;
(_sharp_pair_537 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_537).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_537).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_537);
})
));
(((* _sharp_pair_539).cdr) = ({
struct struct0x08067248 *_sharp_pair_538;
({_sharp_pair_538;
(_sharp_pair_538 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_538).car) = (Int_Form)(0));
(((* _sharp_pair_538).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_538);
})
);
((List__O__Form__C____type__type ) _sharp_pair_539);
})
));
(((* _sharp_pair_540).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_540);
})
);
((List__O__Form__C____type__type ) _sharp_pair_541);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_45));
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
((* orig_else_form_ptr) = (grammar_expander_rec)(grammar_rule, ((List__O__Form__C____type__type ) 0)));
((void) 0);
})
):
(({
(else_form = (Compound_Form)(intern( "if"), ({
struct struct0x08067248 *_sharp_pair_544;
({_sharp_pair_544;
(_sharp_pair_544 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_544).car) = (is_in_Character_Set_condition)(char_set));
(((* _sharp_pair_544).cdr) = ({
struct struct0x08067248 *_sharp_pair_543;
({_sharp_pair_543;
(_sharp_pair_543 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_543).car) = (grammar_expander_rec)(grammar_rule, next_rules));
(((* _sharp_pair_543).cdr) = ({
struct struct0x08067248 *_sharp_pair_542;
({_sharp_pair_542;
(_sharp_pair_542 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_542).car) = else_form);
(((* _sharp_pair_542).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_542);
})
);
((List__O__Form__C____type__type ) _sharp_pair_543);
})
);
((List__O__Form__C____type__type ) _sharp_pair_544);
})
));
({if( (orig_else_form_ptr == ((Form__type *) 0)))
{
({
Compound_Form__type cfe;
(cfe = ((Compound_Form__type ) else_form));
(orig_else_form_ptr = (&((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cfe)).form_list))).tail))).tail))).head)));
((void) 0);
})
;}})
;
((void) 0);
})
));
})
;
_sharp__sharp_loop535_continue545:;
(_sharp_iterator534 = ((* ((struct struct0x08067248 *) _sharp_iterator534)).cdr));
})
;
({goto _sharp__sharp_loop535_begin546;});});
_sharp__sharp_loop535_end536:;});
})
;
(ret_form = (Compound_Form)(intern( "block"), ({
struct struct0x08067248 *_sharp_pair_551;
({_sharp_pair_551;
(_sharp_pair_551 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_551).car) = (Compound_Form)(intern( "="), ({
struct struct0x08067248 *_sharp_pair_549;
({_sharp_pair_549;
(_sharp_pair_549 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_549).car) = (Compound_Form)(intern( "let"), ({
struct struct0x08067248 *_sharp_pair_547;
({_sharp_pair_547;
(_sharp_pair_547 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_547).car) = peeked_char_form);
(((* _sharp_pair_547).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_547);
})
));
(((* _sharp_pair_549).cdr) = ({
struct struct0x08067248 *_sharp_pair_548;
({_sharp_pair_548;
(_sharp_pair_548 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_548).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_548).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_548);
})
);
((List__O__Form__C____type__type ) _sharp_pair_549);
})
));
(((* _sharp_pair_551).cdr) = ({
struct struct0x08067248 *_sharp_pair_550;
({_sharp_pair_550;
(_sharp_pair_550 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_550).car) = else_form);
(((* _sharp_pair_550).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_550);
})
);
((List__O__Form__C____type__type ) _sharp_pair_551);
})
));
ret_form;
})
));
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "*")))?
(({
Form__type repeated_rule;
Form__type peeked_char_form;
Form__type cond_form;
Symbol__type peeked_char;
(repeated_rule = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head));
(cond_form = (head_set_function)(repeated_rule));
(peeked_char = (gensym)(((String__type) &__string_46)));
(peeked_char_form = (Id_Form)(peeked_char));
(Compound_Form)(intern( "loop"), ({
struct struct0x08067248 *_sharp_pair_557;
({_sharp_pair_557;
(_sharp_pair_557 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_557).car) = (Compound_Form)(intern( "block"), ({
struct struct0x08067248 *_sharp_pair_556;
({_sharp_pair_556;
(_sharp_pair_556 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_556).car) = (Compound_Form)(intern( "if"), ({
struct struct0x08067248 *_sharp_pair_554;
({_sharp_pair_554;
(_sharp_pair_554 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_554).car) = (Compound_Form)(intern( "@not"), ({
struct struct0x08067248 *_sharp_pair_552;
({_sharp_pair_552;
(_sharp_pair_552 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_552).car) = cond_form);
(((* _sharp_pair_552).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_552);
})
));
(((* _sharp_pair_554).cdr) = ({
struct struct0x08067248 *_sharp_pair_553;
({_sharp_pair_553;
(_sharp_pair_553 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_553).car) = (Compound_Form)(intern( "break"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_553).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_553);
})
);
((List__O__Form__C____type__type ) _sharp_pair_554);
})
));
(((* _sharp_pair_556).cdr) = ({
struct struct0x08067248 *_sharp_pair_555;
({_sharp_pair_555;
(_sharp_pair_555 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_555).car) = (grammar_expander_rec)(repeated_rule, next_rules));
(((* _sharp_pair_555).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_555);
})
);
((List__O__Form__C____type__type ) _sharp_pair_556);
})
));
(((* _sharp_pair_557).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_557);
})
);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "+")))?
(({
Form__type repeated_rule;
Form__type cond_form;
(repeated_rule = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head));
(cond_form = (head_set_function)(repeated_rule));
(Compound_Form)(intern( "loop"), ({
struct struct0x08067248 *_sharp_pair_563;
({_sharp_pair_563;
(_sharp_pair_563 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_563).car) = (Compound_Form)(intern( "block"), ({
struct struct0x08067248 *_sharp_pair_562;
({_sharp_pair_562;
(_sharp_pair_562 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_562).car) = (grammar_expander_rec)(repeated_rule, next_rules));
(((* _sharp_pair_562).cdr) = ({
struct struct0x08067248 *_sharp_pair_561;
({_sharp_pair_561;
(_sharp_pair_561 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_561).car) = (Compound_Form)(intern( "if"), ({
struct struct0x08067248 *_sharp_pair_560;
({_sharp_pair_560;
(_sharp_pair_560 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_560).car) = (Compound_Form)(intern( "@not"), ({
struct struct0x08067248 *_sharp_pair_558;
({_sharp_pair_558;
(_sharp_pair_558 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_558).car) = cond_form);
(((* _sharp_pair_558).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_558);
})
));
(((* _sharp_pair_560).cdr) = ({
struct struct0x08067248 *_sharp_pair_559;
({_sharp_pair_559;
(_sharp_pair_559 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_559).car) = (Compound_Form)(intern( "break"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_559).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_559);
})
);
((List__O__Form__C____type__type ) _sharp_pair_560);
})
));
(((* _sharp_pair_561).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_561);
})
);
((List__O__Form__C____type__type ) _sharp_pair_562);
})
));
(((* _sharp_pair_563).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_563);
})
);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "?")))?
(({
Form__type cond_form;
Form__type maybe_rule;
(maybe_rule = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf)).form_list))).head));
(cond_form = (head_set_function)(maybe_rule));
(Compound_Form)(intern( "block"), ({
struct struct0x08067248 *_sharp_pair_566;
({_sharp_pair_566;
(_sharp_pair_566 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_566).car) = (Compound_Form)(intern( "if"), ({
struct struct0x08067248 *_sharp_pair_565;
({_sharp_pair_565;
(_sharp_pair_565 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_565).car) = cond_form);
(((* _sharp_pair_565).cdr) = ({
struct struct0x08067248 *_sharp_pair_564;
({_sharp_pair_564;
(_sharp_pair_564 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_564).car) = (grammar_expander_rec)(maybe_rule, next_rules));
(((* _sharp_pair_564).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_564);
})
);
((List__O__Form__C____type__type ) _sharp_pair_565);
})
));
(((* _sharp_pair_566).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_566);
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
struct struct0x08067248 *_sharp_pair_567;
({_sharp_pair_567;
(_sharp_pair_567 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_567).car) = (Id_Form)((intern_string)((function_name_from_grammar_and_rule)(gram_name, rule_name))));
(((* _sharp_pair_567).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_567);
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
({(print_String)(((String__type) &__string_47));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08067248 *_sharp_pair_568;
({_sharp_pair_568;
(_sharp_pair_568 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_568).car) = (Id_Form)(intern( "form")));
(((* _sharp_pair_568).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_568);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_48));
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
(form_head = ((* ((struct struct0x0805ee90 *) ((Compound_Form__type ) form))).head));
(grammar_form = (call_grammar_macro)(form_head, form));
(grammar_expander_rec)(grammar_form, next_rules);
})
):
((((((* ((struct struct0x0805ee90 *) cf)).head) == intern( "&")))?
(({
(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0));
})
):
(({
(print_form)(((Form__type ) cf));
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_49));
(print_String)(((String__type) &__string_50));
(print_Symbol)(((* ((struct struct0x0805ee90 *) cf)).head));
(print_String)(((String__type) &__string_51));
(maybe_flush)();});
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
))))))))))))))))))))));
})
):
((((is_id_form)(parse_form))?
(({
Symbol_Form__type id_form;
(id_form = ((Symbol_Form__type ) parse_form));
(((((* ((struct struct0x08059be8 *) id_form)).value) == intern( "_")))?
(({
(Compound_Form)(intern( "funcall"), ({
struct struct0x08067248 *_sharp_pair_569;
({_sharp_pair_569;
(_sharp_pair_569 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_569).car) = (Id_Form)(intern( "get_point_pos")));
(((* _sharp_pair_569).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_569);
})
);
})
):
((Compound_Form)(intern( "funcall"), ({
struct struct0x08067248 *_sharp_pair_570;
({_sharp_pair_570;
(_sharp_pair_570 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_570).car) = (Id_Form)((intern_string)((function_name_from_grammar_and_rule)(grammar_name, ((* ((struct struct0x08059be8 *) id_form)).value)))));
(((* _sharp_pair_570).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_570);
})
)));
})
):
((((is_string_form)(parse_form))?
(({
void **_sharp_make_list_ptr572;
List__O__Int__C____type__type cl;
List__O__Form__C____type__type form_list;
(cl = (string_to_int_list)(((* ((struct struct0x0805baa0 *) ((String_Form__type ) parse_form))).value)));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list571;
({_sharp_make_list571;
_sharp_make_list_ptr572;
(_sharp_make_list_ptr572 = ((void *) (&_sharp_make_list571)));
({
({
List__O__Int__C____type__type _sharp_iterator574;
(_sharp_iterator574 = cl);
({({_sharp__sharp_loop575_begin578:;
({
Int__type Int;
({if( (_sharp_iterator574 == ((List__O__Int__C____type__type ) 0)))
{
({goto _sharp__sharp_loop575_end576;});}})
;
(Int = ((* ((struct struct0x085902f8 *) _sharp_iterator574)).car));
({
({((* _sharp_make_list_ptr572) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr572))).car) = ((void *) (Compound_Form)(intern( "read_char"), ((List__O__Form__C____type__type ) 0))));
(_sharp_make_list_ptr572 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr572))).cdr)));
((void) 0);});
})
;
_sharp__sharp_loop575_continue577:;
(_sharp_iterator574 = ((* ((struct struct0x085902f8 *) _sharp_iterator574)).cdr));
})
;
({goto _sharp__sharp_loop575_begin578;});});
_sharp__sharp_loop575_end576:;});
})
;
((void) 0);
})
;
((* _sharp_make_list_ptr572) = ((void *) 0));
_sharp_make_list571;});
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
struct struct0x08067248 *_sharp_pair_579;
({_sharp_pair_579;
(_sharp_pair_579 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_579).car) = (String_Form)((get_symbol_name)(symbol)));
(((* _sharp_pair_579).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_579);
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
({(print_String)(((String__type) &__string_52));
(print_String)(((String__type) &__string_53));
(maybe_flush)();});
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
void **_sharp_make_list_ptr601;
List__O__Form__C____type__type form_list;
(rules_hash = ((Hash__O__Symbol__c__Hash__O__Symbol__c__Form__C____C____type__type ) (make_hash_table)()));
(head_set_hash = ((Hash__O__Symbol__c__Hash__O__Symbol__c__List__O__Character_Set__C____C____C____type__type ) (make_hash_table)()));
({
List__O__Compound_Form__C____type__type _sharp_iterator589;
(_sharp_iterator589 = grammar_list);
({({_sharp__sharp_loop590_begin599:;
({
Compound_Form__type grammar;
({if( (_sharp_iterator589 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop590_end591;});}})
;
(grammar = ((* ((struct struct0x081fec90 *) _sharp_iterator589)).car));
({
List__O__Compound_Form__C____type__type rule_list;
(grammar_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) grammar)).form_list))).tail))).head)))).value));
((Hash__O__Symbol__c__Form__C____type__type ) (puthash)(((void *) grammar_name), ((void *) ((Hash__O__Symbol__c__Form__C____type__type ) (make_hash_table)())), ((Hash_Table__type ) rules_hash)));
((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (puthash)(((void *) grammar_name), ((void *) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (make_hash_table)())), ((Hash_Table__type ) head_set_hash)));
(rule_list = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) grammar)).form_list))).tail))).tail)));
({
List__O__Compound_Form__C____type__type _sharp_iterator593;
(_sharp_iterator593 = rule_list);
({({_sharp__sharp_loop594_begin597:;
({
Compound_Form__type rule;
({if( (_sharp_iterator593 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop594_end595;});}})
;
(rule = ((* ((struct struct0x081fec90 *) _sharp_iterator593)).car));
({
Symbol__type rule_name;
Form__type form;
(rule_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).head)))).value));
(form = ((Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).tail))).tail))).tail))).head)));
((Form__type ) (puthash)(((void *) rule_name), ((void *) form), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash))))));
(pre_define_function)((intern_string)((function_name_from_grammar_and_rule)(grammar_name, rule_name)), ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).tail))).head));
})
;
_sharp__sharp_loop594_continue596:;
(_sharp_iterator593 = ((* ((struct struct0x081fec90 *) _sharp_iterator593)).cdr));
})
;
({goto _sharp__sharp_loop594_begin597;});});
_sharp__sharp_loop594_end595:;});
})
;
})
;
_sharp__sharp_loop590_continue598:;
(_sharp_iterator589 = ((* ((struct struct0x081fec90 *) _sharp_iterator589)).cdr));
})
;
({goto _sharp__sharp_loop590_begin599;});});
_sharp__sharp_loop590_end591:;});
})
;
(form_list = ({
List__O__Form__C____type__type _sharp_make_list600;
({_sharp_make_list600;
_sharp_make_list_ptr601;
(_sharp_make_list_ptr601 = ((void *) (&_sharp_make_list600)));
({
({
List__O__Compound_Form__C____type__type _sharp_iterator603;
(_sharp_iterator603 = grammar_list);
({({_sharp__sharp_loop604_begin617:;
({
Compound_Form__type grammar;
({if( (_sharp_iterator603 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop604_end605;});}})
;
(grammar = ((* ((struct struct0x081fec90 *) _sharp_iterator603)).car));
({
List__O__Compound_Form__C____type__type rule_list;
(grammar_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) grammar)).form_list))).tail))).head)))).value));
(rule_list = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) grammar)).form_list))).tail))).tail)));
({
List__O__Compound_Form__C____type__type _sharp_iterator607;
(_sharp_iterator607 = rule_list);
({({_sharp__sharp_loop608_begin615:;
({
Compound_Form__type rule;
({if( (_sharp_iterator607 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop608_end609;});}})
;
(rule = ((* ((struct struct0x081fec90 *) _sharp_iterator607)).car));
({
Form__type function_form;
Expanded_Form__type exp_function_body;
Form__type function_body;
Compound_Form__type params;
Symbol__type function_name;
Symbol__type rule_name;
Form__type form;
Form__type return_type_form;
Expanded_Form__type lambda_form;
(rule_name = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).head)))).value));
(function_name = (intern_string)((function_name_from_grammar_and_rule)(grammar_name, rule_name)));
(return_type_form = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).tail))).head));
(params = ((Compound_Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).tail))).tail))).head)));
(form = ((Form__type ) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) rule)).form_list))).tail))).tail))).tail))).head)));
(id_used = ((Hash__O__Symbol__c__Type__C____type__type ) (make_hash_table)()));
(declare_function_begin)(params, return_type_form);
(declare_block_begin)();
(function_body = (grammar_expander_rec)(form, ((List__O__Form__C____type__type ) 0)));
(exp_function_body = (declare_block_end)(({
struct struct0x08067248 *_sharp_pair_610;
({_sharp_pair_610;
(_sharp_pair_610 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_610).car) = function_body);
(((* _sharp_pair_610).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_610);
})
));
(lambda_form = (declare_function_end)(exp_function_body));
(function_form = (Compound_Form)(intern( "define"), ({
struct struct0x08067248 *_sharp_pair_613;
({_sharp_pair_613;
(_sharp_pair_613 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_613).car) = (Id_Form)(intern( "function")));
(((* _sharp_pair_613).cdr) = ({
struct struct0x08067248 *_sharp_pair_612;
({_sharp_pair_612;
(_sharp_pair_612 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_612).car) = (Id_Form)(function_name));
(((* _sharp_pair_612).cdr) = ({
struct struct0x08067248 *_sharp_pair_611;
({_sharp_pair_611;
(_sharp_pair_611 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_611).car) = ((* ((struct struct0x0805f900 *) lambda_form)).return_form));
(((* _sharp_pair_611).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_611);
})
);
((List__O__Form__C____type__type ) _sharp_pair_612);
})
);
((List__O__Form__C____type__type ) _sharp_pair_613);
})
));
({((* _sharp_make_list_ptr601) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr601))).car) = ((void *) function_form));
(_sharp_make_list_ptr601 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr601))).cdr)));
((void) 0);});
})
;
_sharp__sharp_loop608_continue614:;
(_sharp_iterator607 = ((* ((struct struct0x081fec90 *) _sharp_iterator607)).cdr));
})
;
({goto _sharp__sharp_loop608_begin615;});});
_sharp__sharp_loop608_end609:;});
})
;
})
;
_sharp__sharp_loop604_continue616:;
(_sharp_iterator603 = ((* ((struct struct0x081fec90 *) _sharp_iterator603)).cdr));
})
;
({goto _sharp__sharp_loop604_begin617;});});
_sharp__sharp_loop604_end605:;});
})
;
((void) 0);
((void) 0);
})
;
((* _sharp_make_list_ptr601) = ((void *) 0));
_sharp_make_list600;});
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

Form__type  get_parse_function_sharp__sharp_expander_function(Compound_Form__type  form)
{
return ({
Symbol__type rule;
Form__type grammar_id_form;
Compound_Form__type cf2;
Form__type form2;
Form__type rule_id_form;
Symbol__type grammar;
(form2 = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) form)).form_list))).head));
({if( ((is_compound_form)(form2) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_54));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08067248 *_sharp_pair_580;
({_sharp_pair_580;
(_sharp_pair_580 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_580).car) = (Id_Form)(intern( "form2")));
(((* _sharp_pair_580).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_580);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_55));
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
(cf2 = ((Compound_Form__type ) form2));
(print_form)(form2);
({if( ((((* ((struct struct0x0805ee90 *) cf2)).head) == intern( "[]")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_56));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08067248 *_sharp_pair_584;
({_sharp_pair_584;
(_sharp_pair_584 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_584).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067248 *_sharp_pair_582;
({_sharp_pair_582;
(_sharp_pair_582 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_582).car) = (Id_Form)(intern( "cf2")));
(((* _sharp_pair_582).cdr) = ({
struct struct0x08067248 *_sharp_pair_581;
({_sharp_pair_581;
(_sharp_pair_581 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_581).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_581).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_581);
})
);
((List__O__Form__C____type__type ) _sharp_pair_582);
})
));
(((* _sharp_pair_584).cdr) = ({
struct struct0x08067248 *_sharp_pair_583;
({_sharp_pair_583;
(_sharp_pair_583 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_583).car) = (Symbol_Form)(intern( "[]")));
(((* _sharp_pair_583).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_583);
})
);
((List__O__Form__C____type__type ) _sharp_pair_584);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_57));
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
(grammar_id_form = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf2)).form_list))).head));
(rule_id_form = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) cf2)).form_list))).tail))).head));
({if( ((is_id_form)(grammar_id_form) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_58));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08067248 *_sharp_pair_585;
({_sharp_pair_585;
(_sharp_pair_585 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_585).car) = (Id_Form)(intern( "grammar_id_form")));
(((* _sharp_pair_585).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_585);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_59));
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
(grammar = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) grammar_id_form))).value));
(rule = ((* ((struct struct0x08059be8 *) ((Id_Form__type ) rule_id_form))).value));
(Id_Form)((intern_string)((function_name_from_grammar_and_rule)(grammar, rule)));
})
;}

Form__type  parse_sharp__sharp_expander_function(Compound_Form__type  form)
{
return ({
(Compound_Form)(intern( "funcall"), ({
struct struct0x08067248 *_sharp_pair_587;
({_sharp_pair_587;
(_sharp_pair_587 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_587).car) = (Compound_Form)(intern( "get_parse_function"), ({
struct struct0x08067248 *_sharp_pair_586;
({_sharp_pair_586;
(_sharp_pair_586 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_586).car) = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) form)).form_list))).head));
(((* _sharp_pair_586).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_586);
})
));
(((* _sharp_pair_587).cdr) = ((* ((struct struct0x0805f088 *) ((* ((struct struct0x0805ee90 *) form)).form_list))).tail));
((List__O__Form__C____type__type ) _sharp_pair_587);
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
({(print_String)(((String__type) &__string_60));
(print_Symbol)(rule);
(maybe_flush)();});
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
define_expander( intern( "get_parse_function"), get_parse_function_sharp__sharp_expander_function);
define_expander( intern( "parse"), parse_sharp__sharp_expander_function);
define_expander( intern( "grammar_expander"), grammar_expander_sharp__sharp_expander_function);
}

void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( "TEST result: %d", test_ptr());flush();}
