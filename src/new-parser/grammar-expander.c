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
void **_sharp_make_list_ptr437;
List__O__Character_Range__C____type__type new_list;
Compound_Form__type form;
(form = ((Compound_Form__type ) form_));
(new_list = ({
List__O__Character_Range__C____type__type _sharp_make_list436;
_sharp_make_list436,
_sharp_make_list_ptr437,
(_sharp_make_list_ptr437 = ((void *) (&_sharp_make_list436))),
({
({
List__O__Form__C____type__type _sharp_iterator439;
(_sharp_iterator439 = ((* ((struct struct0x0805ef40 *) form)).form_list));
((void) 0);_sharp__sharp_loop440_begin454:((void) 0),
({
Form__type subform;
({if( (_sharp_iterator439 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop440_end441;});}})
;
(subform = ((* ((struct struct0x080937a0 *) _sharp_iterator439)).car));
({
(((is_compound_form)(subform))?
(({
struct struct0x08559c10 *_sharp_pointer_alloc448;
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
struct struct0x080937a0 *_sharp_pair_444;
_sharp_pair_444,
(_sharp_pair_444 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_444).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080937a0 *_sharp_pair_443;
_sharp_pair_443,
(_sharp_pair_443 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_443).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_443).cdr) = ({
struct struct0x080937a0 *_sharp_pair_442;
_sharp_pair_442,
(_sharp_pair_442 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_442).car) = (Id_Form)(intern( "min_form")));
(((* _sharp_pair_442).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_442);
})
);
((List__O__Form__C____type__type ) _sharp_pair_443);
})
));
(((* _sharp_pair_444).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_444);
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
struct struct0x080937a0 *_sharp_pair_447;
_sharp_pair_447,
(_sharp_pair_447 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_447).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080937a0 *_sharp_pair_446;
_sharp_pair_446,
(_sharp_pair_446 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_446).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_446).cdr) = ({
struct struct0x080937a0 *_sharp_pair_445;
_sharp_pair_445,
(_sharp_pair_445 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_445).car) = (Id_Form)(intern( "max_form")));
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
((* _sharp_make_list_ptr437) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr437))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc448,
(_sharp_pointer_alloc448 = ((struct struct0x08559c10 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc448) = ((struct struct0x08559c10 ){((* ((struct struct0x0805e1c0 *) min_form)).value), ((* ((struct struct0x0805e1c0 *) max_form)).value)})),
((struct struct0x08559c10 *) _sharp_pointer_alloc448)))),
(_sharp_make_list_ptr437 = (&((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr437))).cdr))),
((void) 0);
})
):
(({
struct struct0x08559c10 *_sharp_pointer_alloc452;
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
struct struct0x080937a0 *_sharp_pair_451;
_sharp_pair_451,
(_sharp_pair_451 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_451).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080937a0 *_sharp_pair_450;
_sharp_pair_450,
(_sharp_pair_450 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_450).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_450).cdr) = ({
struct struct0x080937a0 *_sharp_pair_449;
_sharp_pair_449,
(_sharp_pair_449 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_449).car) = (Id_Form)(intern( "symbol_form")));
(((* _sharp_pair_449).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_449);
})
);
((List__O__Form__C____type__type ) _sharp_pair_450);
})
));
(((* _sharp_pair_451).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_451);
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
((* _sharp_make_list_ptr437) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr437))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc452,
(_sharp_pointer_alloc452 = ((struct struct0x08559c10 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc452) = ((struct struct0x08559c10 ){((* ((struct struct0x0805e1c0 *) symbol_form)).value), ((* ((struct struct0x0805e1c0 *) symbol_form)).value)})),
((struct struct0x08559c10 *) _sharp_pointer_alloc452)))),
(_sharp_make_list_ptr437 = (&((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr437))).cdr))),
((void) 0);
})
));
})
;
((void) 0);_sharp__sharp_loop440_continue453:((void) 0);
(_sharp_iterator439 = ((* ((struct struct0x080937a0 *) _sharp_iterator439)).cdr));
})
,
({goto _sharp__sharp_loop440_begin454;}),
((void) 0);_sharp__sharp_loop440_end441:((void) 0);
})
;
((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr437) = ((void *) 0)),
_sharp_make_list436;
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
struct struct0x08559c10 *_sharp_pointer_alloc455;
((Character_Set__type ) ({
struct struct0x0858fcb8 *_sharp_pair_456;
_sharp_pair_456,
(_sharp_pair_456 = ((struct struct0x0858fcb8 *) (alloc_cons_cell)()));
(((* _sharp_pair_456).car) = ((Character_Range__type ) _sharp_pointer_alloc455,
(_sharp_pointer_alloc455 = ((struct struct0x08559c10 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc455) = ((struct struct0x08559c10 ){1, 255})),
((struct struct0x08559c10 *) _sharp_pointer_alloc455)));
(((* _sharp_pair_456).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_456);
})
);
})
):
(({
void **_sharp_make_list_ptr458;
List__O__Character_Range__C____type__type inverse;
Character_Range__type first;
List__O__Character_Range__C____type__type csl;
(csl = ((List__O__Character_Range__C____type__type ) cs));
(first = ((* ((struct struct0x08559f08 *) csl)).head));
(inverse = ({
List__O__Character_Range__C____type__type _sharp_make_list457;
_sharp_make_list457,
_sharp_make_list_ptr458,
(_sharp_make_list_ptr458 = ((void *) (&_sharp_make_list457))),
({
Int__type prec;
({if( (((* ((struct struct0x08559c10 *) first)).min) != 0))
{
({
struct struct0x08559c10 *_sharp_pointer_alloc459;
((* _sharp_make_list_ptr458) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr458))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc459,
(_sharp_pointer_alloc459 = ((struct struct0x08559c10 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc459) = ((struct struct0x08559c10 ){0, ((int) ((* ((struct struct0x08559c10 *) first)).min) - (int) 1)})),
((struct struct0x08559c10 *) _sharp_pointer_alloc459)))),
(_sharp_make_list_ptr458 = (&((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr458))).cdr))),
((void) 0);
})
;}})
;
(prec = ((int) ((* ((struct struct0x08559c10 *) first)).max) + (int) 1));
({
List__O__Character_Range__C____type__type _sharp_iterator461;
(_sharp_iterator461 = ((* ((struct struct0x08559f08 *) csl)).tail));
((void) 0);_sharp__sharp_loop462_begin466:((void) 0),
({
Character_Range__type cr;
({if( (_sharp_iterator461 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop462_end463;});}})
;
(cr = ((* ((struct struct0x0858fcb8 *) _sharp_iterator461)).car));
({
struct struct0x08559c10 *_sharp_pointer_alloc464;
((* _sharp_make_list_ptr458) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr458))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc464,
(_sharp_pointer_alloc464 = ((struct struct0x08559c10 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc464) = ((struct struct0x08559c10 ){prec, ((int) ((* ((struct struct0x08559c10 *) cr)).min) - (int) 1)})),
((struct struct0x08559c10 *) _sharp_pointer_alloc464)))),
(_sharp_make_list_ptr458 = (&((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr458))).cdr))),
((void) 0);
(prec = ((int) ((* ((struct struct0x08559c10 *) cr)).max) + (int) 1));
})
;
((void) 0);_sharp__sharp_loop462_continue465:((void) 0);
(_sharp_iterator461 = ((* ((struct struct0x0858fcb8 *) _sharp_iterator461)).cdr));
})
,
({goto _sharp__sharp_loop462_begin466;}),
((void) 0);_sharp__sharp_loop462_end463:((void) 0);
})
;
({if( ((int) prec < (int) 256))
{
({
struct struct0x08559c10 *_sharp_pointer_alloc467;
((* _sharp_make_list_ptr458) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr458))).car) = ((void *) ((Character_Range__type ) _sharp_pointer_alloc467,
(_sharp_pointer_alloc467 = ((struct struct0x08559c10 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc467) = ((struct struct0x08559c10 ){prec, 255})),
((struct struct0x08559c10 *) _sharp_pointer_alloc467)))),
(_sharp_make_list_ptr458 = (&((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr458))).cdr))),
((void) 0);
})
;}})
;
((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr458) = ((void *) 0)),
_sharp_make_list457;
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
List__O__Character_Range__C____type__type _sharp_iterator469;
(_sharp_iterator469 = cl);
((void) 0);_sharp__sharp_loop470_begin473:((void) 0),
({
Character_Range__type cr;
({if( (_sharp_iterator469 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop470_end471;});}})
;
(cr = ((* ((struct struct0x0858fcb8 *) _sharp_iterator469)).car));
({
(print_String)(((String__type) &__string_7)),
(print_Int_Dec)(((* ((struct struct0x08559c10 *) cr)).min)),
(print_String)(((String__type) &__string_8)),
(print_Int_Dec)(((* ((struct struct0x08559c10 *) cr)).max)),
(print_String)(((String__type) &__string_9)),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop470_continue472:((void) 0);
(_sharp_iterator469 = ((* ((struct struct0x0858fcb8 *) _sharp_iterator469)).cdr));
})
,
({goto _sharp__sharp_loop470_begin473;}),
((void) 0);_sharp__sharp_loop470_end471:((void) 0);
})
;
})
;}

Form__type  is_in_Character_Set_condition(Form__type  id_form, Character_Set__type  cs)
{
return ({
Form__type final_cond;
(final_cond = (Compound_Form)(intern( "cast"), ({
struct struct0x080937a0 *_sharp_pair_475;
_sharp_pair_475,
(_sharp_pair_475 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_475).car) = (Id_Form)(intern( "Bool")));
(((* _sharp_pair_475).cdr) = ({
struct struct0x080937a0 *_sharp_pair_474;
_sharp_pair_474,
(_sharp_pair_474 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_474).car) = (Int_Form)(0));
(((* _sharp_pair_474).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_474);
})
);
((List__O__Form__C____type__type ) _sharp_pair_475);
})
));
({
List__O__Character_Range__C____type__type _sharp_iterator477;
(_sharp_iterator477 = ((List__O__Character_Range__C____type__type ) cs));
((void) 0);_sharp__sharp_loop478_begin491:((void) 0),
({
Character_Range__type cr;
({if( (_sharp_iterator477 == ((List__O__Character_Range__C____type__type ) 0)))
{
({goto _sharp__sharp_loop478_end479;});}})
;
(cr = ((* ((struct struct0x0858fcb8 *) _sharp_iterator477)).car));
({
Form__type cond;
(cond = (((((* ((struct struct0x08559c10 *) cr)).min) == ((* ((struct struct0x08559c10 *) cr)).max)))?
(({
(Compound_Form)(intern( "=="), ({
struct struct0x080937a0 *_sharp_pair_481;
_sharp_pair_481,
(_sharp_pair_481 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_481).car) = id_form);
(((* _sharp_pair_481).cdr) = ({
struct struct0x080937a0 *_sharp_pair_480;
_sharp_pair_480,
(_sharp_pair_480 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_480).car) = (Int_Form)(((* ((struct struct0x08559c10 *) cr)).min)));
(((* _sharp_pair_480).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_480);
})
);
((List__O__Form__C____type__type ) _sharp_pair_481);
})
);
})
):
(({
(Compound_Form)(intern( "@and"), ({
struct struct0x080937a0 *_sharp_pair_487;
_sharp_pair_487,
(_sharp_pair_487 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_487).car) = (Compound_Form)(intern( ">="), ({
struct struct0x080937a0 *_sharp_pair_483;
_sharp_pair_483,
(_sharp_pair_483 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_483).car) = id_form);
(((* _sharp_pair_483).cdr) = ({
struct struct0x080937a0 *_sharp_pair_482;
_sharp_pair_482,
(_sharp_pair_482 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_482).car) = (Int_Form)(((* ((struct struct0x08559c10 *) cr)).min)));
(((* _sharp_pair_482).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_482);
})
);
((List__O__Form__C____type__type ) _sharp_pair_483);
})
));
(((* _sharp_pair_487).cdr) = ({
struct struct0x080937a0 *_sharp_pair_486;
_sharp_pair_486,
(_sharp_pair_486 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_486).car) = (Compound_Form)(intern( "<="), ({
struct struct0x080937a0 *_sharp_pair_485;
_sharp_pair_485,
(_sharp_pair_485 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_485).car) = id_form);
(((* _sharp_pair_485).cdr) = ({
struct struct0x080937a0 *_sharp_pair_484;
_sharp_pair_484,
(_sharp_pair_484 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_484).car) = (Int_Form)(((* ((struct struct0x08559c10 *) cr)).max)));
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
);
})
)));
(final_cond = (Compound_Form)(intern( "@or"), ({
struct struct0x080937a0 *_sharp_pair_489;
_sharp_pair_489,
(_sharp_pair_489 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_489).car) = cond);
(((* _sharp_pair_489).cdr) = ({
struct struct0x080937a0 *_sharp_pair_488;
_sharp_pair_488,
(_sharp_pair_488 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_488).car) = final_cond);
(((* _sharp_pair_488).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_488);
})
);
((List__O__Form__C____type__type ) _sharp_pair_489);
})
));
})
;
((void) 0);_sharp__sharp_loop478_continue490:((void) 0);
(_sharp_iterator477 = ((* ((struct struct0x0858fcb8 *) _sharp_iterator477)).cdr));
})
,
({goto _sharp__sharp_loop478_begin491;}),
((void) 0);_sharp__sharp_loop478_end479:((void) 0);
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
struct struct0x080937a0 *_sharp_pair_498;
_sharp_pair_498,
(_sharp_pair_498 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_498).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x080937a0 *_sharp_pair_493;
_sharp_pair_493,
(_sharp_pair_493 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_493).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_493).cdr) = ({
struct struct0x080937a0 *_sharp_pair_492;
_sharp_pair_492,
(_sharp_pair_492 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_492).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_492).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_492);
})
);
((List__O__Form__C____type__type ) _sharp_pair_493);
})
));
(((* _sharp_pair_498).cdr) = ({
struct struct0x080937a0 *_sharp_pair_497;
_sharp_pair_497,
(_sharp_pair_497 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_497).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x080937a0 *_sharp_pair_496;
_sharp_pair_496,
(_sharp_pair_496 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_496).car) = (Compound_Form)(intern( "List"), ({
struct struct0x080937a0 *_sharp_pair_494;
_sharp_pair_494,
(_sharp_pair_494 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_494).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_494).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_494);
})
));
(((* _sharp_pair_496).cdr) = ({
struct struct0x080937a0 *_sharp_pair_495;
_sharp_pair_495,
(_sharp_pair_495 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_495).car) = (Int_Form)(0));
(((* _sharp_pair_495).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_495);
})
);
((List__O__Form__C____type__type ) _sharp_pair_496);
})
));
(((* _sharp_pair_497).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_497);
})
);
((List__O__Form__C____type__type ) _sharp_pair_498);
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
List__O__Form__C____type__type _sharp_iterator500;
(_sharp_iterator500 = ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) cf)).form_list))).tail));
((void) 0);_sharp__sharp_loop501_begin504:((void) 0),
({
Form__type rule;
({if( (_sharp_iterator500 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop501_end502;});}})
;
(rule = ((* ((struct struct0x080937a0 *) _sharp_iterator500)).car));
({
(cs_ = (append)(((List__O__pointer__O__Void__C____C____type__type ) (head_set)(rule, next_rules)), cs_));
})
;
((void) 0);_sharp__sharp_loop501_continue503:((void) 0);
(_sharp_iterator500 = ((* ((struct struct0x080937a0 *) _sharp_iterator500)).cdr));
})
,
({goto _sharp__sharp_loop501_begin504;}),
((void) 0);_sharp__sharp_loop501_end502:((void) 0);
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
struct struct0x08559c10 *_sharp_pointer_alloc505;
Int__type head;
(head = (string_element)(((* ((struct struct0x0805bb08 *) ((String_Form__type ) parse_form))).value), 0));
(cs = ((Character_Set__type ) ({
struct struct0x0858fcb8 *_sharp_pair_506;
_sharp_pair_506,
(_sharp_pair_506 = ((struct struct0x0858fcb8 *) (alloc_cons_cell)()));
(((* _sharp_pair_506).car) = ((Character_Range__type ) _sharp_pointer_alloc505,
(_sharp_pointer_alloc505 = ((struct struct0x08559c10 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc505) = ((struct struct0x08559c10 ){head, head})),
((struct struct0x08559c10 *) _sharp_pointer_alloc505)));
(((* _sharp_pair_506).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_506);
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
Form__type subrule;
Form__type left_form;
Symbol__type id;
Expanded_Form__type exp_right_form;
Id_Form__type id_form;
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
struct struct0x080937a0 *_sharp_pair_507;
_sharp_pair_507,
(_sharp_pair_507 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_507).car) = right_form);
(((* _sharp_pair_507).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_507);
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
struct struct0x080937a0 *_sharp_pair_509;
_sharp_pair_509,
(_sharp_pair_509 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_509).car) = ((Form__type ) id_form));
(((* _sharp_pair_509).cdr) = ({
struct struct0x080937a0 *_sharp_pair_508;
_sharp_pair_508,
(_sharp_pair_508 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_508).car) = (((struct struct0x080920b0 ) ((* ((struct struct0x08092360 *) ((Real_Type__type ) ((* ((struct struct0x0805f9b0 *) exp_right_form)).type)))).common_)).type_form));
(((* _sharp_pair_508).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_508);
})
);
((List__O__Form__C____type__type ) _sharp_pair_509);
})
));
})
;}})
;
(Compound_Form)(intern( "="), ({
struct struct0x080937a0 *_sharp_pair_511;
_sharp_pair_511,
(_sharp_pair_511 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_511).car) = left_form);
(((* _sharp_pair_511).cdr) = ({
struct struct0x080937a0 *_sharp_pair_510;
_sharp_pair_510,
(_sharp_pair_510 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_510).car) = ((Form__type ) exp_right_form));
(((* _sharp_pair_510).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_510);
})
);
((List__O__Form__C____type__type ) _sharp_pair_511);
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
void **_sharp_make_list_ptr513;
List__O__Form__C____type__type fl;
(fl = ({
List__O__Form__C____type__type _sharp_make_list512;
_sharp_make_list512,
_sharp_make_list_ptr513,
(_sharp_make_list_ptr513 = ((void *) (&_sharp_make_list512))),
({
List__O__Form__C____type__type grammar_rule_it;
(grammar_rule_it = ((* ((struct struct0x0805ef40 *) cf)).form_list));
((void) 0);_sharp__sharp_loop514_begin516:((void) 0),
({if( (!((grammar_rule_it != ((List__O__Form__C____type__type ) 0)))))
{
({goto _sharp__sharp_loop514_end515;});}})
,
({
List__O__Form__C____type__type grammar_tail;
Form__type grammar_rule;
(grammar_rule = ((* ((struct struct0x0805f138 *) grammar_rule_it)).head));
(grammar_tail = ((* ((struct struct0x0805f138 *) grammar_rule_it)).tail));
((* _sharp_make_list_ptr513) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr513))).car) = ((void *) (grammar_expander_rec)(grammar_rule, grammar_tail))),
(_sharp_make_list_ptr513 = (&((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr513))).cdr))),
((void) 0);
(grammar_rule_it = grammar_tail);
})
,
({goto _sharp__sharp_loop514_begin516;}),
((void) 0);_sharp__sharp_loop514_end515:((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr513) = ((void *) 0)),
_sharp_make_list512;
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
List__O__Form__C____type__type _sharp_iterator518;
(_sharp_iterator518 = ((* ((struct struct0x0805ef40 *) cf)).form_list));
((void) 0);_sharp__sharp_loop519_begin525:((void) 0),
({
Form__type grammar_rule;
({if( (_sharp_iterator518 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop519_end520;});}})
;
(grammar_rule = ((* ((struct struct0x080937a0 *) _sharp_iterator518)).car));
({
Character_Set__type char_set;
(char_set = (head_set)(grammar_rule, next_rules));
(else_form = (Compound_Form)(intern( "if"), ({
struct struct0x080937a0 *_sharp_pair_523;
_sharp_pair_523,
(_sharp_pair_523 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_523).car) = (is_in_Character_Set_condition)(peeked_char_form, char_set));
(((* _sharp_pair_523).cdr) = ({
struct struct0x080937a0 *_sharp_pair_522;
_sharp_pair_522,
(_sharp_pair_522 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_522).car) = (grammar_expander_rec)(grammar_rule, next_rules));
(((* _sharp_pair_522).cdr) = ({
struct struct0x080937a0 *_sharp_pair_521;
_sharp_pair_521,
(_sharp_pair_521 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_521).car) = else_form);
(((* _sharp_pair_521).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_521);
})
);
((List__O__Form__C____type__type ) _sharp_pair_522);
})
);
((List__O__Form__C____type__type ) _sharp_pair_523);
})
));
})
;
((void) 0);_sharp__sharp_loop519_continue524:((void) 0);
(_sharp_iterator518 = ((* ((struct struct0x080937a0 *) _sharp_iterator518)).cdr));
})
,
({goto _sharp__sharp_loop519_begin525;}),
((void) 0);_sharp__sharp_loop519_end520:((void) 0);
})
;
(Compound_Form)(intern( "block"), ({
struct struct0x080937a0 *_sharp_pair_530;
_sharp_pair_530,
(_sharp_pair_530 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_530).car) = (Compound_Form)(intern( "="), ({
struct struct0x080937a0 *_sharp_pair_528;
_sharp_pair_528,
(_sharp_pair_528 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_528).car) = (Compound_Form)(intern( "let"), ({
struct struct0x080937a0 *_sharp_pair_526;
_sharp_pair_526,
(_sharp_pair_526 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_526).car) = peeked_char_form);
(((* _sharp_pair_526).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_526);
})
));
(((* _sharp_pair_528).cdr) = ({
struct struct0x080937a0 *_sharp_pair_527;
_sharp_pair_527,
(_sharp_pair_527 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_527).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_527).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_527);
})
);
((List__O__Form__C____type__type ) _sharp_pair_528);
})
));
(((* _sharp_pair_530).cdr) = ({
struct struct0x080937a0 *_sharp_pair_529;
_sharp_pair_529,
(_sharp_pair_529 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_529).car) = else_form);
(((* _sharp_pair_529).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_529);
})
);
((List__O__Form__C____type__type ) _sharp_pair_530);
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
struct struct0x080937a0 *_sharp_pair_540;
_sharp_pair_540,
(_sharp_pair_540 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_540).car) = (Compound_Form)(intern( "block"), ({
struct struct0x080937a0 *_sharp_pair_539;
_sharp_pair_539,
(_sharp_pair_539 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_539).car) = (Compound_Form)(intern( "="), ({
struct struct0x080937a0 *_sharp_pair_533;
_sharp_pair_533,
(_sharp_pair_533 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_533).car) = (Compound_Form)(intern( "let"), ({
struct struct0x080937a0 *_sharp_pair_531;
_sharp_pair_531,
(_sharp_pair_531 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_531).car) = peeked_char_form);
(((* _sharp_pair_531).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_531);
})
));
(((* _sharp_pair_533).cdr) = ({
struct struct0x080937a0 *_sharp_pair_532;
_sharp_pair_532,
(_sharp_pair_532 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_532).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_532).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_532);
})
);
((List__O__Form__C____type__type ) _sharp_pair_533);
})
));
(((* _sharp_pair_539).cdr) = ({
struct struct0x080937a0 *_sharp_pair_538;
_sharp_pair_538,
(_sharp_pair_538 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_538).car) = (Compound_Form)(intern( "if"), ({
struct struct0x080937a0 *_sharp_pair_536;
_sharp_pair_536,
(_sharp_pair_536 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_536).car) = (Compound_Form)(intern( "@not"), ({
struct struct0x080937a0 *_sharp_pair_534;
_sharp_pair_534,
(_sharp_pair_534 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_534).car) = (is_in_Character_Set_condition)(peeked_char_form, char_set));
(((* _sharp_pair_534).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_534);
})
));
(((* _sharp_pair_536).cdr) = ({
struct struct0x080937a0 *_sharp_pair_535;
_sharp_pair_535,
(_sharp_pair_535 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_535).car) = (Compound_Form)(intern( "break"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_535).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_535);
})
);
((List__O__Form__C____type__type ) _sharp_pair_536);
})
));
(((* _sharp_pair_538).cdr) = ({
struct struct0x080937a0 *_sharp_pair_537;
_sharp_pair_537,
(_sharp_pair_537 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_537).car) = (grammar_expander_rec)(repeated_rule, next_rules));
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
(((* _sharp_pair_540).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_540);
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
struct struct0x080937a0 *_sharp_pair_547;
_sharp_pair_547,
(_sharp_pair_547 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_547).car) = (Compound_Form)(intern( "="), ({
struct struct0x080937a0 *_sharp_pair_543;
_sharp_pair_543,
(_sharp_pair_543 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_543).car) = (Compound_Form)(intern( "let"), ({
struct struct0x080937a0 *_sharp_pair_541;
_sharp_pair_541,
(_sharp_pair_541 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_541).car) = peeked_char_form);
(((* _sharp_pair_541).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_541);
})
));
(((* _sharp_pair_543).cdr) = ({
struct struct0x080937a0 *_sharp_pair_542;
_sharp_pair_542,
(_sharp_pair_542 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_542).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_542).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_542);
})
);
((List__O__Form__C____type__type ) _sharp_pair_543);
})
));
(((* _sharp_pair_547).cdr) = ({
struct struct0x080937a0 *_sharp_pair_546;
_sharp_pair_546,
(_sharp_pair_546 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_546).car) = (Compound_Form)(intern( "if"), ({
struct struct0x080937a0 *_sharp_pair_545;
_sharp_pair_545,
(_sharp_pair_545 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_545).car) = (is_in_Character_Set_condition)(peeked_char_form, char_set));
(((* _sharp_pair_545).cdr) = ({
struct struct0x080937a0 *_sharp_pair_544;
_sharp_pair_544,
(_sharp_pair_544 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_544).car) = (grammar_expander_rec)(maybe_rule, next_rules));
(((* _sharp_pair_544).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_544);
})
);
((List__O__Form__C____type__type ) _sharp_pair_545);
})
));
(((* _sharp_pair_546).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_546);
})
);
((List__O__Form__C____type__type ) _sharp_pair_547);
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
struct struct0x080937a0 *_sharp_pair_548;
_sharp_pair_548,
(_sharp_pair_548 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_548).car) = (Id_Form)(intern( "get_point_pos")));
(((* _sharp_pair_548).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_548);
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
struct struct0x080937a0 *_sharp_pair_549;
_sharp_pair_549,
(_sharp_pair_549 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_549).car) = (Id_Form)((intern_string)((concat)(((String__type) &__string_25), (get_symbol_name)(((* ((struct struct0x08059c28 *) id_form)).value))))));
(((* _sharp_pair_549).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_549);
})
)))));
})
):
((((is_string_form)(parse_form))?
(({
void **_sharp_make_list_ptr551;
List__O__Int__C____type__type cl;
List__O__Form__C____type__type form_list;
(cl = (string_to_int_list)(((* ((struct struct0x0805bb08 *) ((String_Form__type ) parse_form))).value)));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list550;
_sharp_make_list550,
_sharp_make_list_ptr551,
(_sharp_make_list_ptr551 = ((void *) (&_sharp_make_list550))),
({
({
List__O__Int__C____type__type _sharp_iterator553;
(_sharp_iterator553 = cl);
((void) 0);_sharp__sharp_loop554_begin557:((void) 0),
({
Int__type Int;
({if( (_sharp_iterator553 == ((List__O__Int__C____type__type ) 0)))
{
({goto _sharp__sharp_loop554_end555;});}})
;
(Int = ((* ((struct struct0x084fdee0 *) _sharp_iterator553)).car));
({
((* _sharp_make_list_ptr551) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr551))).car) = ((void *) (Compound_Form)(intern( "read_char"), ((List__O__Form__C____type__type ) 0)))),
(_sharp_make_list_ptr551 = (&((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr551))).cdr))),
((void) 0);
})
;
((void) 0);_sharp__sharp_loop554_continue556:((void) 0);
(_sharp_iterator553 = ((* ((struct struct0x084fdee0 *) _sharp_iterator553)).cdr));
})
,
({goto _sharp__sharp_loop554_begin557;}),
((void) 0);_sharp__sharp_loop554_end555:((void) 0);
})
;
((void) 0);
})
,
((* _sharp_make_list_ptr551) = ((void *) 0)),
_sharp_make_list550;
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
void **_sharp_make_list_ptr567;
struct struct0x08559c10 *_sharp_pointer_alloc558;
List__O__Compound_Form__C____type__type rule_list;
Symbol__type grammar_name;
List__O__Form__C____type__type form_list;
Compound_Form__type grammar;
(grammar = ((Compound_Form__type ) grammar_));
(grammar_name = ((* ((struct struct0x08059c28 *) ((Id_Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) grammar)).form_list))).tail))).tail))).head)))).value));
(rule_list = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) grammar)).form_list))).tail))).tail))).tail)));
(dot_character_set = ((Character_Set__type ) ({
struct struct0x0858fcb8 *_sharp_pair_559;
_sharp_pair_559,
(_sharp_pair_559 = ((struct struct0x0858fcb8 *) (alloc_cons_cell)()));
(((* _sharp_pair_559).car) = ((Character_Range__type ) _sharp_pointer_alloc558,
(_sharp_pointer_alloc558 = ((struct struct0x08559c10 *) (GC_alloc)(8))),
((* _sharp_pointer_alloc558) = ((struct struct0x08559c10 ){1, 255})),
((struct struct0x08559c10 *) _sharp_pointer_alloc558)));
(((* _sharp_pair_559).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_559);
})
));
(rules_hash = ((Hash__O__Symbol__c__Form__C____type__type ) (make_hash_table)()));
(head_set_hash = ((Hash__O__Symbol__c__Character_Set__C____type__type ) (make_hash_table)()));
({
List__O__Compound_Form__C____type__type _sharp_iterator561;
(_sharp_iterator561 = rule_list);
((void) 0);_sharp__sharp_loop562_begin565:((void) 0),
({
Compound_Form__type rule;
({if( (_sharp_iterator561 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop562_end563;});}})
;
(rule = ((* ((struct struct0x081d4a08 *) _sharp_iterator561)).car));
({
Symbol__type rule_name;
Form__type form;
(rule_name = ((* ((struct struct0x08059c28 *) ((Id_Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) rule)).form_list))).head)))).value));
(form = ((Form__type ) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805f138 *) ((* ((struct struct0x0805ef40 *) rule)).form_list))).tail))).head)));
((Form__type ) (puthash)(((void *) rule_name), ((void *) form), ((Hash_Table__type ) rules_hash)));
})
;
((void) 0);_sharp__sharp_loop562_continue564:((void) 0);
(_sharp_iterator561 = ((* ((struct struct0x081d4a08 *) _sharp_iterator561)).cdr));
})
,
({goto _sharp__sharp_loop562_begin565;}),
((void) 0);_sharp__sharp_loop562_end563:((void) 0);
})
;
(form_list = ({
List__O__Form__C____type__type _sharp_make_list566;
_sharp_make_list566,
_sharp_make_list_ptr567,
(_sharp_make_list_ptr567 = ((void *) (&_sharp_make_list566))),
({
({
List__O__Compound_Form__C____type__type _sharp_iterator569;
(_sharp_iterator569 = rule_list);
((void) 0);_sharp__sharp_loop570_begin580:((void) 0),
({
Compound_Form__type rule;
({if( (_sharp_iterator569 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop570_end571;});}})
;
(rule = ((* ((struct struct0x081d4a08 *) _sharp_iterator569)).car));
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
(function_body = (grammar_expander_rec)(form, ((List__O__Form__C____type__type ) 0)));
(exp_function_body = (expand)((Compound_Form)(intern( "block"), ({
struct struct0x080937a0 *_sharp_pair_572;
_sharp_pair_572,
(_sharp_pair_572 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_572).car) = function_body);
(((* _sharp_pair_572).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_572);
})
)));
(lambda_form = (Compound_Form)(intern( "lambda"), ({
struct struct0x080937a0 *_sharp_pair_575;
_sharp_pair_575,
(_sharp_pair_575 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_575).car) = (((struct struct0x080920b0 ) ((* ((struct struct0x08092360 *) ((Real_Type__type ) ((* ((struct struct0x0805f9b0 *) exp_function_body)).type)))).common_)).type_form));
(((* _sharp_pair_575).cdr) = ({
struct struct0x080937a0 *_sharp_pair_574;
_sharp_pair_574,
(_sharp_pair_574 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_574).car) = (Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_574).cdr) = ({
struct struct0x080937a0 *_sharp_pair_573;
_sharp_pair_573,
(_sharp_pair_573 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_573).car) = ((* ((struct struct0x0805f9b0 *) exp_function_body)).return_form));
(((* _sharp_pair_573).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_573);
})
);
((List__O__Form__C____type__type ) _sharp_pair_574);
})
);
((List__O__Form__C____type__type ) _sharp_pair_575);
})
));
(function_form = (Compound_Form)(intern( "define"), ({
struct struct0x080937a0 *_sharp_pair_578;
_sharp_pair_578,
(_sharp_pair_578 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_578).car) = (Id_Form)(intern( "function")));
(((* _sharp_pair_578).cdr) = ({
struct struct0x080937a0 *_sharp_pair_577;
_sharp_pair_577,
(_sharp_pair_577 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_577).car) = (Id_Form)(function_name));
(((* _sharp_pair_577).cdr) = ({
struct struct0x080937a0 *_sharp_pair_576;
_sharp_pair_576,
(_sharp_pair_576 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_576).car) = lambda_form);
(((* _sharp_pair_576).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_576);
})
);
((List__O__Form__C____type__type ) _sharp_pair_577);
})
);
((List__O__Form__C____type__type ) _sharp_pair_578);
})
));
((* _sharp_make_list_ptr567) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr567))).car) = ((void *) function_form)),
(_sharp_make_list_ptr567 = (&((* (* ((struct struct0x08501c98 **) _sharp_make_list_ptr567))).cdr))),
((void) 0);
})
;
((void) 0);_sharp__sharp_loop570_continue579:((void) 0);
(_sharp_iterator569 = ((* ((struct struct0x081d4a08 *) _sharp_iterator569)).cdr));
})
,
({goto _sharp__sharp_loop570_begin580;}),
((void) 0);_sharp__sharp_loop570_end571:((void) 0);
})
;
((void) 0);
((void) 0);
})
,
((* _sharp_make_list_ptr567) = ((void *) 0)),
_sharp_make_list566;
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
struct struct0x080937a0 *_sharp_pair_589;
_sharp_pair_589,
(_sharp_pair_589 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_589).car) = (Id_Form)(intern( "rule")));
(((* _sharp_pair_589).cdr) = ({
struct struct0x080937a0 *_sharp_pair_588;
_sharp_pair_588,
(_sharp_pair_588 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_588).car) = (Id_Form)(intern( "Comment")));
(((* _sharp_pair_588).cdr) = ({
struct struct0x080937a0 *_sharp_pair_587;
_sharp_pair_587,
(_sharp_pair_587 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_587).car) = (Compound_Form)(intern( " "), ({
struct struct0x080937a0 *_sharp_pair_586;
_sharp_pair_586,
(_sharp_pair_586 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_586).car) = (String_Form)(((String__type) &__string_28)));
(((* _sharp_pair_586).cdr) = ({
struct struct0x080937a0 *_sharp_pair_585;
_sharp_pair_585,
(_sharp_pair_585 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_585).car) = (Compound_Form)(intern( "*"), ({
struct struct0x080937a0 *_sharp_pair_582;
_sharp_pair_582,
(_sharp_pair_582 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_582).car) = (Compound_Form)(intern( "[^]"), ({
struct struct0x080937a0 *_sharp_pair_581;
_sharp_pair_581,
(_sharp_pair_581 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_581).car) = (Int_Form)(10));
(((* _sharp_pair_581).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_581);
})
));
(((* _sharp_pair_582).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_582);
})
));
(((* _sharp_pair_585).cdr) = ({
struct struct0x080937a0 *_sharp_pair_584;
_sharp_pair_584,
(_sharp_pair_584 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_584).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x080937a0 *_sharp_pair_583;
_sharp_pair_583,
(_sharp_pair_583 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_583).car) = (Int_Form)(10));
(((* _sharp_pair_583).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_583);
})
));
(((* _sharp_pair_584).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_584);
})
);
((List__O__Form__C____type__type ) _sharp_pair_585);
})
);
((List__O__Form__C____type__type ) _sharp_pair_586);
})
));
(((* _sharp_pair_587).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_587);
})
);
((List__O__Form__C____type__type ) _sharp_pair_588);
})
);
((List__O__Form__C____type__type ) _sharp_pair_589);
})
));
(grammar = (Compound_Form)(intern( "define"), ({
struct struct0x080937a0 *_sharp_pair_592;
_sharp_pair_592,
(_sharp_pair_592 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_592).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_592).cdr) = ({
struct struct0x080937a0 *_sharp_pair_591;
_sharp_pair_591,
(_sharp_pair_591 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_591).car) = (Id_Form)(intern( "test_grammar")));
(((* _sharp_pair_591).cdr) = ({
struct struct0x080937a0 *_sharp_pair_590;
_sharp_pair_590,
(_sharp_pair_590 = ((struct struct0x080937a0 *) (alloc_cons_cell)()));
(((* _sharp_pair_590).car) = rule);
(((* _sharp_pair_590).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_590);
})
);
((List__O__Form__C____type__type ) _sharp_pair_591);
})
);
((List__O__Form__C____type__type ) _sharp_pair_592);
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
