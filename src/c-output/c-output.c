/* Automatically generated : do not edit!*/
#include "c-output.inc"
Hash__O__Type__c__Bool__C____type__type has_been_outputed;

Hash__O__Type__c__Bool__C____type__type type_definition_needed;

Output_Descriptor__type inc_file_descriptor;

Output_Descriptor__type output_file_descriptor;

Output_Descriptor__type stdout_descriptor;

Int__type string_counter;

Hash__O__Int__c__String__C____type__type strings_needed;

Hash__O__Symbol__c__Bool__C____type__type globals_needed;

Hash__O__Symbol__c__pointer__O__function__O__Void__c__tuple__O__Expanded_Compound_Form__C____C____C____C____type__type c_output_hash;

Bool__type  is_compound_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x0805d238 *) rf)).form_type_) == 1811939328);
})
;}

Bool__type  is_expanded_form(Form__type  f)
{
return ({
(((* ((struct struct0x0805d238 *) f)).form_type_) == (- (int) 536870912));
})
;}

Bool__type  is_id_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x0805d238 *) rf)).form_type_) == (- (int) 1342177280));
})
;}

Bool__type  is_int_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x0805d238 *) rf)).form_type_) == (- (int) -2147483648));
})
;}

Bool__type  is_symbol_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x0805d238 *) rf)).form_type_) == (- (int) 1073741824));
})
;}

Bool__type  is_string_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x0805d238 *) rf)).form_type_) == (- (int) 1610612736));
})
;}

Bool__type  is_struct_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) nt)).common_)).type_type) == 0);
})
;}

Bool__type  is_base_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) nt)).common_)).type_type) == 3);
})
;}

Bool__type  is_pointer_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) nt)).common_)).type_type) == 4);
})
;}

Bool__type  is_tuple_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) nt)).common_)).type_type) == 2);
})
;}

Bool__type  is_function_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) nt)).common_)).type_type) == 1);
})
;}

void  c_output_type(Symbol__type  name, Type__type  t)
{
return ({
((Bool__type ) (puthash)(((void *) t), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) type_definition_needed)));
(((is_base_type)(t))?
(({
Base_Type__type bt;
(bt = ((Base_Type__type ) t));
(((((* ((struct struct0x0805d700 *) bt)).origin_type) == ((Type__type ) 0)))?
(({
({if( ((is_id_form)((((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) bt))).common_)).type_form)) == ((Bool__type ) 0)))
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
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08092c38 *_sharp_pair_360;
_sharp_pair_360,
(_sharp_pair_360 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_360).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_359;
_sharp_pair_359,
(_sharp_pair_359 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_359).car) = (Id_Form)(intern( "bt")));
(((* _sharp_pair_359).cdr) = ({
struct struct0x08092c38 *_sharp_pair_358;
_sharp_pair_358,
(_sharp_pair_358 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_358).car) = (Symbol_Form)(intern( "type_form")));
(((* _sharp_pair_358).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_358);
})
);
((List__O__Form__C____type__type ) _sharp_pair_359);
})
));
(((* _sharp_pair_360).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_360);
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
(print_Symbol)(((* ((struct struct0x080595b0 *) ((Id_Form__type ) (((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) bt))).common_)).type_form)))).value)),
(maybe_flush)();
})
):
((print_Symbol)((mangle_type_name)(t)),
(maybe_flush)()));
(print_String)(((String__type) &__string_3)),
(print_Symbol)(name),
(maybe_flush)();
})
):
((((is_struct_type)(t))?
(({
(print_String)(((String__type) &__string_4)),
(print_Int_Hex)(((Int__type ) t)),
(print_String)(((String__type) &__string_5)),
(print_Symbol)(name),
(maybe_flush)();
})
):
((((is_pointer_type)(t))?
(({
(c_output_type)((prepend_star)(name), (intern_type)(((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) ((Compound_Form__type ) (((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) t))).common_)).type_form)))).form_list))).head)));
})
):
((((is_tuple_type)(t))?
(({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) t))).common_)).type_form)));
(((((* ((struct struct0x0805e968 *) tf)).form_list) == ((List__O__Form__C____type__type ) 0)))?
(({
(print_String)(((String__type) &__string_6)),
(print_Symbol)(name),
(maybe_flush)();
})
):
(({
(print_form)((((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) t))).common_)).type_form));
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_7)),
(print_String)(((String__type) &__string_8)),
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
));
})
):
((((is_function_type)(t))?
(({
Compound_Form__type parameters;
Type__type return_type;
List__O__Form__C____type__type form_list;
(form_list = ((* ((struct struct0x0805e968 *) ((Compound_Form__type ) (((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) t))).common_)).type_form)))).form_list));
(return_type = (intern_type)(((* ((struct struct0x0805eba0 *) form_list)).head)));
(c_output_type)(intern( ""), return_type);
(print_String)(((String__type) &__string_9)),
(print_Symbol)(name),
(print_String)(((String__type) &__string_10)),
(maybe_flush)();
(parameters = ((Compound_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) form_list)).tail))).head)));
(((((* ((struct struct0x0805e968 *) parameters)).form_list) == ((List__O__Form__C____type__type ) 0)))?
(({
(print_String)(((String__type) &__string_11)),
(maybe_flush)();
})
):
(({
(print_String)(((String__type) &__string_12)),
(maybe_flush)();
(c_output_type)(intern( ""), (intern_type)(((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) parameters)).form_list))).head)));
({
List__O__Form__C____type__type _sharp_iterator362;
(_sharp_iterator362 = ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) parameters)).form_list))).tail));
((void) 0);_sharp__sharp_loop363_begin366:((void) 0),
({
Form__type parameter;
({if( (_sharp_iterator362 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop363_end364;});}})
;
(parameter = ((* ((struct struct0x08092c38 *) _sharp_iterator362)).car));
({
(print_String)(((String__type) &__string_13)),
(maybe_flush)();
(c_output_type)(intern( ""), (intern_type)(parameter));
})
;
((void) 0);_sharp__sharp_loop363_continue365:((void) 0);
(_sharp_iterator362 = ((* ((struct struct0x08092c38 *) _sharp_iterator362)).cdr));
})
,
({goto _sharp__sharp_loop363_begin366;}),
((void) 0);_sharp__sharp_loop363_end364:((void) 0);
})
;
(print_String)(((String__type) &__string_14)),
(maybe_flush)();
})
));
})
):
(({
(print_form)((((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) t))).common_)).type_form));
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
))))))))));
})
;}

void  c_output_type_definition(Type__type  t)
{
return ({
({if( (((Bool__type ) (gethash)(((void *) t), ((Hash_Table__type ) has_been_outputed))) == ((Bool__type ) 0)))
{
({
((Bool__type ) (puthash)(((void *) t), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) has_been_outputed)));
(((is_base_type)(t))?
(({
Base_Type__type bt;
(bt = ((Base_Type__type ) t));
({if( (((* ((struct struct0x0805d700 *) bt)).origin_type) == ((Type__type ) 0)))
{
({
({goto end;});
})
;}})
;
({if( ((Bool__type ) (gethash)(((void *) ((* ((struct struct0x0805d700 *) bt)).origin_type)), ((Hash_Table__type ) has_been_outputed))))
{
({
({goto next;});
})
;}})
;
(c_output_type_definition)(((* ((struct struct0x0805d700 *) bt)).origin_type));
((void) 0);next:((void) 0),
(print_String)(((String__type) &__string_17)),
(maybe_flush)();
(c_output_type)((mangle_type_name)(t), ((* ((struct struct0x0805d700 *) bt)).origin_type));
(print_String)(((String__type) &__string_18)),
(maybe_flush)();
(print_String)(((String__type) &__string_19)),
(maybe_flush)();
})
):
((((is_struct_type)(t))?
(({
Form__type tf;
(tf = (((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) t))).common_)).type_form));
({
List__O__Form__C____type__type _sharp_iterator368;
(_sharp_iterator368 = ((* ((struct struct0x0805e968 *) ((Compound_Form__type ) tf))).form_list));
((void) 0);_sharp__sharp_loop369_begin377:((void) 0),
({
Form__type label_form_;
({if( (_sharp_iterator368 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop369_end370;});}})
;
(label_form_ = ((* ((struct struct0x08092c38 *) _sharp_iterator368)).car));
({
Type__type subtype;
Form__type subtf;
Compound_Form__type label_form;
({if( ((is_compound_form)(label_form_) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_20)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08092c38 *_sharp_pair_371;
_sharp_pair_371,
(_sharp_pair_371 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_371).car) = (Id_Form)(intern( "label_form_")));
(((* _sharp_pair_371).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_371);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_21)),
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
(label_form = ((Compound_Form__type ) label_form_));
({if( ((((* ((struct struct0x0805e968 *) label_form)).head) == intern( "label")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_22)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_375;
_sharp_pair_375,
(_sharp_pair_375 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_375).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_373;
_sharp_pair_373,
(_sharp_pair_373 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_373).car) = (Id_Form)(intern( "label_form")));
(((* _sharp_pair_373).cdr) = ({
struct struct0x08092c38 *_sharp_pair_372;
_sharp_pair_372,
(_sharp_pair_372 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_372).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_372).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_372);
})
);
((List__O__Form__C____type__type ) _sharp_pair_373);
})
));
(((* _sharp_pair_375).cdr) = ({
struct struct0x08092c38 *_sharp_pair_374;
_sharp_pair_374,
(_sharp_pair_374 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_374).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_374).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_374);
})
);
((List__O__Form__C____type__type ) _sharp_pair_375);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_23)),
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
(subtf = ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) label_form)).form_list))).tail))).head));
(subtype = (intern_type)(subtf));
({if( ((Bool__type ) (gethash)(((void *) subtype), ((Hash_Table__type ) has_been_outputed))))
{
({goto _sharp__sharp_loop369_continue376;});}})
;
(c_output_type_definition)(subtype);
})
;
((void) 0);_sharp__sharp_loop369_continue376:((void) 0);
(_sharp_iterator368 = ((* ((struct struct0x08092c38 *) _sharp_iterator368)).cdr));
})
,
({goto _sharp__sharp_loop369_begin377;}),
((void) 0);_sharp__sharp_loop369_end370:((void) 0);
})
;
(print_String)(((String__type) &__string_24)),
(print_Int_Hex)(((Int__type ) t)),
(print_String)(((String__type) &__string_25)),
(maybe_flush)();
({
List__O__Form__C____type__type _sharp_iterator379;
(_sharp_iterator379 = ((* ((struct struct0x0805e968 *) ((Compound_Form__type ) tf))).form_list));
((void) 0);_sharp__sharp_loop380_begin388:((void) 0),
({
Form__type label_form_;
({if( (_sharp_iterator379 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop380_end381;});}})
;
(label_form_ = ((* ((struct struct0x08092c38 *) _sharp_iterator379)).car));
({
Symbol__type field_name;
Type__type subtype;
Form__type subtf;
Compound_Form__type label_form;
(label_form = ((Compound_Form__type ) label_form_));
({if( ((is_id_form)(((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) label_form)).form_list))).head)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_26)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08092c38 *_sharp_pair_386;
_sharp_pair_386,
(_sharp_pair_386 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_386).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_385;
_sharp_pair_385,
(_sharp_pair_385 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_385).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_383;
_sharp_pair_383,
(_sharp_pair_383 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_383).car) = (Id_Form)(intern( "label_form")));
(((* _sharp_pair_383).cdr) = ({
struct struct0x08092c38 *_sharp_pair_382;
_sharp_pair_382,
(_sharp_pair_382 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_382).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_382).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_382);
})
);
((List__O__Form__C____type__type ) _sharp_pair_383);
})
));
(((* _sharp_pair_385).cdr) = ({
struct struct0x08092c38 *_sharp_pair_384;
_sharp_pair_384,
(_sharp_pair_384 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_384).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_384).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_384);
})
);
((List__O__Form__C____type__type ) _sharp_pair_385);
})
));
(((* _sharp_pair_386).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_386);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_27)),
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
(field_name = ((* ((struct struct0x080595b0 *) ((Id_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) label_form)).form_list))).head)))).value));
(subtf = ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) label_form)).form_list))).tail))).head));
(subtype = (intern_type)(subtf));
(c_output_type)(field_name, subtype);
(print_String)(((String__type) &__string_28)),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop380_continue387:((void) 0);
(_sharp_iterator379 = ((* ((struct struct0x08092c38 *) _sharp_iterator379)).cdr));
})
,
({goto _sharp__sharp_loop380_begin388;}),
((void) 0);_sharp__sharp_loop380_end381:((void) 0);
})
;
(print_String)(((String__type) &__string_29)),
(maybe_flush)();
})
):
((((is_pointer_type)(t))?
(({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) t))).common_)).type_form)));
({if( (is_compound_form)(((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) tf)).form_list))).head)))
{
({
Compound_Form__type ptf;
(ptf = ((Compound_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) tf)).form_list))).head)));
({if( (((* ((struct struct0x0805e968 *) ptf)).head) == intern( "struct")))
{
({goto end;});}})
;
})
;}})
;
(c_output_type_definition)((intern_type)(((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) tf)).form_list))).head)));
})
):
((((is_function_type)(t))?
(({
Type__type from_type;
Type__type to_type;
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) t))).common_)).type_form)));
(to_type = (intern_type)(((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) tf)).form_list))).head)));
(c_output_type_definition)(to_type);
(from_type = (intern_type)(((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) tf)).form_list))).tail))).head)));
(c_output_type_definition)(from_type);
})
):
(({if( (is_tuple_type)(t))
{
({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x08091560 ) ((* ((struct struct0x080917d0 *) ((Real_Type__type ) t))).common_)).type_form)));
({
List__O__Form__C____type__type _sharp_iterator390;
(_sharp_iterator390 = ((* ((struct struct0x0805e968 *) tf)).form_list));
((void) 0);_sharp__sharp_loop391_begin394:((void) 0),
({
Form__type subform;
({if( (_sharp_iterator390 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop391_end392;});}})
;
(subform = ((* ((struct struct0x08092c38 *) _sharp_iterator390)).car));
({
Type__type type;
(type = (intern_type)(subform));
(c_output_type_definition)(type);
})
;
((void) 0);_sharp__sharp_loop391_continue393:((void) 0);
(_sharp_iterator390 = ((* ((struct struct0x08092c38 *) _sharp_iterator390)).cdr));
})
,
({goto _sharp__sharp_loop391_begin394;}),
((void) 0);_sharp__sharp_loop391_end392:((void) 0);
})
;
})
;}})
))))))));
})
;}})
;
((void) 0);end:((void) 0),
((void) 0);
})
;}

void  output_all_type_definitions(void)
{
return ({
Output_Descriptor__type save_descriptor;
(save_descriptor = current_output_descriptor);
(current_output_descriptor = inc_file_descriptor);
(print_String)(((String__type) &__string_30)),
(print_String)(((String__type) &__string_31)),
(print_String)(((String__type) &__string_32)),
(print_String)(((String__type) &__string_33)),
(print_String)(((String__type) &__string_34)),
(print_String)(((String__type) &__string_35)),
(print_String)(((String__type) &__string_36)),
(maybe_flush)();
(print_String)(((String__type) &__string_37)),
(maybe_flush)();
(print_String)(((String__type) &__string_38)),
(maybe_flush)();
(print_String)(((String__type) &__string_39)),
(maybe_flush)();
(print_String)(((String__type) &__string_40)),
(maybe_flush)();
(print_String)(((String__type) &__string_41)),
(maybe_flush)();
(print_String)(((String__type) &__string_42)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_descriptor);
((void) 0);
({
void **PValue_;
Hash__O__Type__c__Bool__C____type__type hash_;
Int__type Index_;
(Index_ = 0);
(hash_ = type_definition_needed);
PValue_;
(PValue_ = (JudyLFirst)((* ((void **) hash_)), ((void *) (&Index_)), 0));
((void) 0);_sharp__sharp_loop396_begin400:((void) 0),
({
Bool__type _sharp_tuple399;
Type__type _sharp_tuple398;
Bool__type bool;
Type__type type;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop396_end397;});}})
;
(_sharp_tuple398 = ((Type__type ) Index_)),
(_sharp_tuple399 = ((Bool__type ) (* PValue_))),
(type = _sharp_tuple398),
(bool = _sharp_tuple399);
({
({if( bool)
{
({
(c_output_type_definition)(type);
})
;}})
;
})
;
(PValue_ = (JudyLNext)((* ((void **) hash_)), ((void *) (&Index_)), 0));
})
,
({goto _sharp__sharp_loop396_begin400;}),
((void) 0);_sharp__sharp_loop396_end397:((void) 0);
})
;
})
;}

void  reinit_types(void)
{
return ({
(type_definition_needed = ((Hash__O__Type__c__Bool__C____type__type ) (make_hash_table)()));
(has_been_outputed = ((Hash__O__Type__c__Bool__C____type__type ) (make_hash_table)()));
((void) 0);
})
;}

void  init_output_type(void)
{
return ({
((void) 0);
})
;}

void  c_output_form(Expanded_Form__type  expf)
{
return ({
({
Form__type f;
(f = ((* ((struct struct0x0805f3a0 *) expf)).return_form));
(((is_compound_form)(f))?
(({
void (*fun)(Expanded_Compound_Form__type );
Compound_Form__type cf;
(cf = ((Compound_Form__type ) f));
(fun = ((void (*)(Expanded_Compound_Form__type )) (gethash)(((void *) ((* ((struct struct0x0805e968 *) cf)).head)), ((Hash_Table__type ) c_output_hash))));
({if( (fun == ((void (*)(Expanded_Compound_Form__type )) 0)))
{
({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_43)),
(print_String)(((String__type) &__string_44)),
(print_Symbol)(((* ((struct struct0x0805e968 *) cf)).head)),
(print_String)(((String__type) &__string_45));
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
((* fun))(((Expanded_Compound_Form__type ) expf));
})
):
(({
(((is_id_form)(f))?
(({
Id_Form__type id_form;
(id_form = ((Id_Form__type ) f));
(print_Symbol)((convert_id)(((* ((struct struct0x080595b0 *) id_form)).value)));
})
):
((((is_int_form)(f))?
(({
Int_Form__type int_form;
(int_form = ((Int_Form__type ) f));
(print_Int_Dec)(((* ((struct struct0x0805db68 *) int_form)).value));
})
):
((((is_symbol_form)(f))?
(({
Symbol_Form__type symbol_form;
(symbol_form = ((Symbol_Form__type ) f));
(print_Symbol)(intern( "intern( \"")),
(print_String)((convert_id_as_string)(((* ((struct struct0x080595b0 *) symbol_form)).value))),
(print_Symbol)(intern( "\")"));
})
):
((((is_string_form)(f))?
(({
String_Form__type string_form;
(string_form = ((String_Form__type ) f));
(string_counter = ((int) string_counter + (int) 1));
((String__type ) (puthash)(((void *) string_counter), ((void *) ((* ((struct struct0x0805ae18 *) string_form)).value)), ((Hash_Table__type ) strings_needed)));
(print_String)(((String__type) &__string_46)),
(print_Int_Dec)(string_counter),
(print_String)(((String__type) &__string_47));
})
):
(({
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_48)),
(print_String)(((String__type) &__string_49)),
(print_Int_Dec)(((* ((struct struct0x0805d238 *) ((Form__type ) f))).form_type_));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;
})
))))))));
})
));
})
;
})
;}

void  c_output_add_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_50)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_51)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_52));
})
;}

void  c_output_mul_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_53)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_54)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_55));
})
;}

void  c_output_sub_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_56)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_57)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_58));
})
;}

void  c_output_div_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_59)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_60)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_61));
})
;}

void  c_output_unary_minus_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_62)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_63));
})
;}

void  c_output_ge_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_64)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_65)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_66));
})
;}

void  c_output_gt_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_67)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_68)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_69));
})
;}

void  c_output_le_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_70)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_71)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_72));
})
;}

void  c_output_lt_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_73)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_74)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_75));
})
;}

void  c_output_different(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_76)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_77)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_78));
})
;}

void  c_output_equal(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_79)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_80)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_81));
})
;}

void  c_output_logical_or(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_82)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_83)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_84));
})
;}

void  c_output_logical_and(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_85)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_86)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_87));
})
;}

void  c_output_logical_not(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_88)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_89));
})
;}

void  c_output_access_struct(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)(((String__type) &__string_90)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_91));
({if( ((is_symbol_form)(((* ((struct struct0x0805f3a0 *) ((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head))).return_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_92));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_symbol_form"), ({
struct struct0x08092c38 *_sharp_pair_409;
_sharp_pair_409,
(_sharp_pair_409 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_409).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_408;
_sharp_pair_408,
(_sharp_pair_408 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_408).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_406;
_sharp_pair_406,
(_sharp_pair_406 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_406).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_404;
_sharp_pair_404,
(_sharp_pair_404 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_404).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_402;
_sharp_pair_402,
(_sharp_pair_402 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_402).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_402).cdr) = ({
struct struct0x08092c38 *_sharp_pair_401;
_sharp_pair_401,
(_sharp_pair_401 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_401).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_401).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_401);
})
);
((List__O__Form__C____type__type ) _sharp_pair_402);
})
));
(((* _sharp_pair_404).cdr) = ({
struct struct0x08092c38 *_sharp_pair_403;
_sharp_pair_403,
(_sharp_pair_403 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_403).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_403).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_403);
})
);
((List__O__Form__C____type__type ) _sharp_pair_404);
})
));
(((* _sharp_pair_406).cdr) = ({
struct struct0x08092c38 *_sharp_pair_405;
_sharp_pair_405,
(_sharp_pair_405 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_405).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_405).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_405);
})
);
((List__O__Form__C____type__type ) _sharp_pair_406);
})
));
(((* _sharp_pair_408).cdr) = ({
struct struct0x08092c38 *_sharp_pair_407;
_sharp_pair_407,
(_sharp_pair_407 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_407).car) = (Symbol_Form)(intern( "return_form")));
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
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_93));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(print_Symbol)(((* ((struct struct0x080595b0 *) ((Symbol_Form__type ) ((* ((struct struct0x0805f3a0 *) ((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head))).return_form)))).value)),
(print_String)(((String__type) &__string_94));
})
;
})
;}

void  c_output_assign(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)(((String__type) &__string_95));
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head));
(print_String)(((String__type) &__string_96));
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head));
(print_String)(((String__type) &__string_97));
})
;
})
;}

void  c_output_block(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)(((String__type) &__string_98));
({
List__O__Expanded_Form__C____type__type _sharp_iterator411;
(_sharp_iterator411 = ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)));
((void) 0);_sharp__sharp_loop412_begin415:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator411 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop412_end413;});}})
;
(subform = ((* ((struct struct0x0812d010 *) _sharp_iterator411)).car));
({
(c_output_form)(subform),
(print_String)(((String__type) &__string_99));
})
;
((void) 0);_sharp__sharp_loop412_continue414:((void) 0);
(_sharp_iterator411 = ((* ((struct struct0x0812d010 *) _sharp_iterator411)).cdr));
})
,
({goto _sharp__sharp_loop412_begin415;}),
((void) 0);_sharp__sharp_loop412_end413:((void) 0);
})
;
(print_String)(((String__type) &__string_100));
})
;
})
;}

void  c_output_cast(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)(((String__type) &__string_101));
(c_output_type)(intern( ""), (intern_type)(((* ((struct struct0x0805f3a0 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head))).return_form)));
(print_String)(((String__type) &__string_102)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_103));
})
;
})
;}

void  c_output_deref(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)(((String__type) &__string_104)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_105));
})
;}

void  c_output_funcall(Expanded_Compound_Form__type  cf)
{
return ({
Expanded_Form__type function;
(function = ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head));
({if( (is_id_form)(((* ((struct struct0x0805f3a0 *) function)).return_form)))
{
({
((Bool__type ) (puthash)(((void *) ((* ((struct struct0x080595b0 *) ((Id_Form__type ) ((* ((struct struct0x0805f3a0 *) function)).return_form)))).value)), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) globals_needed)));
})
;}})
;
({
(print_String)(((String__type) &__string_106)),
(c_output_form)(function),
(print_String)(((String__type) &__string_107));
({if( (((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail) != ((List__O__Expanded_Form__C____type__type ) 0)))
{
({
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head));
({
List__O__Expanded_Form__C____type__type _sharp_iterator417;
(_sharp_iterator417 = ((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).tail));
((void) 0);_sharp__sharp_loop418_begin421:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator417 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop418_end419;});}})
;
(subform = ((* ((struct struct0x0812d010 *) _sharp_iterator417)).car));
(print_String)(((String__type) &__string_108)),
(c_output_form)(subform);
((void) 0);_sharp__sharp_loop418_continue420:((void) 0);
(_sharp_iterator417 = ((* ((struct struct0x0812d010 *) _sharp_iterator417)).cdr));
})
,
({goto _sharp__sharp_loop418_begin421;}),
((void) 0);_sharp__sharp_loop418_end419:((void) 0);
})
;
})
;}})
;
(print_String)(((String__type) &__string_109));
})
;
})
;}

void  c_output_if(Expanded_Compound_Form__type  cf)
{
return ({
Expanded_Form__type then;
Expanded_Form__type condition;
(condition = ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head));
(then = ((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head));
({
(((((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)))?
(({
(print_String)(((String__type) &__string_110)),
(c_output_form)(condition),
(print_String)(((String__type) &__string_111)),
(c_output_form)(then),
(print_String)(((String__type) &__string_112));
})
):
(({
Expanded_Form__type elsef;
(elsef = ((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).tail))).head));
(print_String)(((String__type) &__string_113)),
(c_output_form)(condition),
(print_String)(((String__type) &__string_114)),
(c_output_form)(then),
(print_String)(((String__type) &__string_115)),
(c_output_form)(elsef),
(print_String)(((String__type) &__string_116));
})
));
})
;
})
;}

void  c_output_get_label(Expanded_Compound_Form__type  cf)
{
return ({
Id_Form__type label_form;
({if( ((((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_117)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_430;
_sharp_pair_430,
(_sharp_pair_430 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_430).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_425;
_sharp_pair_425,
(_sharp_pair_425 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_425).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_423;
_sharp_pair_423,
(_sharp_pair_423 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_423).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_423).cdr) = ({
struct struct0x08092c38 *_sharp_pair_422;
_sharp_pair_422,
(_sharp_pair_422 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_422).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_422).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_422);
})
);
((List__O__Form__C____type__type ) _sharp_pair_423);
})
));
(((* _sharp_pair_425).cdr) = ({
struct struct0x08092c38 *_sharp_pair_424;
_sharp_pair_424,
(_sharp_pair_424 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_424).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_424).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_424);
})
);
((List__O__Form__C____type__type ) _sharp_pair_425);
})
));
(((* _sharp_pair_430).cdr) = ({
struct struct0x08092c38 *_sharp_pair_429;
_sharp_pair_429,
(_sharp_pair_429 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_429).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_428;
_sharp_pair_428,
(_sharp_pair_428 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_428).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08092c38 *_sharp_pair_426;
_sharp_pair_426,
(_sharp_pair_426 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_426).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_426).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_426);
})
));
(((* _sharp_pair_428).cdr) = ({
struct struct0x08092c38 *_sharp_pair_427;
_sharp_pair_427,
(_sharp_pair_427 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_427).car) = (Int_Form)(0));
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
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_118)),
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
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_119)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08092c38 *_sharp_pair_437;
_sharp_pair_437,
(_sharp_pair_437 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_437).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_436;
_sharp_pair_436,
(_sharp_pair_436 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_436).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_436).cdr) = ({
struct struct0x08092c38 *_sharp_pair_435;
_sharp_pair_435,
(_sharp_pair_435 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_435).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_434;
_sharp_pair_434,
(_sharp_pair_434 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_434).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_432;
_sharp_pair_432,
(_sharp_pair_432 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_432).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_432).cdr) = ({
struct struct0x08092c38 *_sharp_pair_431;
_sharp_pair_431,
(_sharp_pair_431 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_431).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_431).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_431);
})
);
((List__O__Form__C____type__type ) _sharp_pair_432);
})
));
(((* _sharp_pair_434).cdr) = ({
struct struct0x08092c38 *_sharp_pair_433;
_sharp_pair_433,
(_sharp_pair_433 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_433).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_433).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_433);
})
);
((List__O__Form__C____type__type ) _sharp_pair_434);
})
));
(((* _sharp_pair_435).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_435);
})
);
((List__O__Form__C____type__type ) _sharp_pair_436);
})
));
(((* _sharp_pair_437).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_437);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_120)),
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
(label_form = ((Id_Form__type ) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)));
(print_String)(((String__type) &__string_121)),
(print_Symbol)((convert_id)(((* ((struct struct0x080595b0 *) label_form)).value)));
})
;}

void  c_output_goto_constant(Expanded_Compound_Form__type  cf)
{
return ({
Id_Form__type id_form;
({if( ((((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_122)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_446;
_sharp_pair_446,
(_sharp_pair_446 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_446).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_441;
_sharp_pair_441,
(_sharp_pair_441 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_441).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_439;
_sharp_pair_439,
(_sharp_pair_439 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_439).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_439).cdr) = ({
struct struct0x08092c38 *_sharp_pair_438;
_sharp_pair_438,
(_sharp_pair_438 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_438).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_438).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_438);
})
);
((List__O__Form__C____type__type ) _sharp_pair_439);
})
));
(((* _sharp_pair_441).cdr) = ({
struct struct0x08092c38 *_sharp_pair_440;
_sharp_pair_440,
(_sharp_pair_440 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_440).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_440).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_440);
})
);
((List__O__Form__C____type__type ) _sharp_pair_441);
})
));
(((* _sharp_pair_446).cdr) = ({
struct struct0x08092c38 *_sharp_pair_445;
_sharp_pair_445,
(_sharp_pair_445 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_445).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_444;
_sharp_pair_444,
(_sharp_pair_444 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_444).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08092c38 *_sharp_pair_442;
_sharp_pair_442,
(_sharp_pair_442 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_442).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_442).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_442);
})
));
(((* _sharp_pair_444).cdr) = ({
struct struct0x08092c38 *_sharp_pair_443;
_sharp_pair_443,
(_sharp_pair_443 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_443).car) = (Int_Form)(0));
(((* _sharp_pair_443).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_443);
})
);
((List__O__Form__C____type__type ) _sharp_pair_444);
})
));
(((* _sharp_pair_445).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_445);
})
);
((List__O__Form__C____type__type ) _sharp_pair_446);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_123)),
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
(id_form = ((Id_Form__type ) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)));
({if( ((is_id_form)(((Form__type ) id_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_124)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08092c38 *_sharp_pair_449;
_sharp_pair_449,
(_sharp_pair_449 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_449).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_448;
_sharp_pair_448,
(_sharp_pair_448 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_448).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_448).cdr) = ({
struct struct0x08092c38 *_sharp_pair_447;
_sharp_pair_447,
(_sharp_pair_447 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_447).car) = (Id_Form)(intern( "id_form")));
(((* _sharp_pair_447).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_447);
})
);
((List__O__Form__C____type__type ) _sharp_pair_448);
})
));
(((* _sharp_pair_449).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_449);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_125)),
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
(print_String)(((String__type) &__string_126)),
(print_Symbol)((convert_id)(((* ((struct struct0x080595b0 *) id_form)).value))),
(print_String)(((String__type) &__string_127));
})
;}

void  c_output_goto_variable(Expanded_Compound_Form__type  cf)
{
return ({
({if( ((((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_128)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_458;
_sharp_pair_458,
(_sharp_pair_458 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_458).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_453;
_sharp_pair_453,
(_sharp_pair_453 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_453).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_451;
_sharp_pair_451,
(_sharp_pair_451 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_451).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_451).cdr) = ({
struct struct0x08092c38 *_sharp_pair_450;
_sharp_pair_450,
(_sharp_pair_450 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_450).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_450).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_450);
})
);
((List__O__Form__C____type__type ) _sharp_pair_451);
})
));
(((* _sharp_pair_453).cdr) = ({
struct struct0x08092c38 *_sharp_pair_452;
_sharp_pair_452,
(_sharp_pair_452 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_452).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_452).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_452);
})
);
((List__O__Form__C____type__type ) _sharp_pair_453);
})
));
(((* _sharp_pair_458).cdr) = ({
struct struct0x08092c38 *_sharp_pair_457;
_sharp_pair_457,
(_sharp_pair_457 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_457).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_456;
_sharp_pair_456,
(_sharp_pair_456 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_456).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08092c38 *_sharp_pair_454;
_sharp_pair_454,
(_sharp_pair_454 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_454).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_454).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_454);
})
));
(((* _sharp_pair_456).cdr) = ({
struct struct0x08092c38 *_sharp_pair_455;
_sharp_pair_455,
(_sharp_pair_455 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_455).car) = (Int_Form)(0));
(((* _sharp_pair_455).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_455);
})
);
((List__O__Form__C____type__type ) _sharp_pair_456);
})
));
(((* _sharp_pair_457).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_457);
})
);
((List__O__Form__C____type__type ) _sharp_pair_458);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_129)),
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
({if( ((is_compound_form)(((* ((struct struct0x0805f3a0 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head))).return_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_130)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08092c38 *_sharp_pair_465;
_sharp_pair_465,
(_sharp_pair_465 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_465).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_464;
_sharp_pair_464,
(_sharp_pair_464 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_464).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_462;
_sharp_pair_462,
(_sharp_pair_462 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_462).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_460;
_sharp_pair_460,
(_sharp_pair_460 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_460).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_460).cdr) = ({
struct struct0x08092c38 *_sharp_pair_459;
_sharp_pair_459,
(_sharp_pair_459 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_459).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_459).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_459);
})
);
((List__O__Form__C____type__type ) _sharp_pair_460);
})
));
(((* _sharp_pair_462).cdr) = ({
struct struct0x08092c38 *_sharp_pair_461;
_sharp_pair_461,
(_sharp_pair_461 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_461).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_461).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_461);
})
);
((List__O__Form__C____type__type ) _sharp_pair_462);
})
));
(((* _sharp_pair_464).cdr) = ({
struct struct0x08092c38 *_sharp_pair_463;
_sharp_pair_463,
(_sharp_pair_463 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_463).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_463).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_463);
})
);
((List__O__Form__C____type__type ) _sharp_pair_464);
})
));
(((* _sharp_pair_465).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_465);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_131)),
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
({if( ((((* ((struct struct0x0805e968 *) ((Compound_Form__type ) ((* ((struct struct0x0805f3a0 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head))).return_form)))).head) == intern( "deref")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_132)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_477;
_sharp_pair_477,
(_sharp_pair_477 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_477).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_475;
_sharp_pair_475,
(_sharp_pair_475 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_475).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_473;
_sharp_pair_473,
(_sharp_pair_473 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_473).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_473).cdr) = ({
struct struct0x08092c38 *_sharp_pair_472;
_sharp_pair_472,
(_sharp_pair_472 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_472).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_471;
_sharp_pair_471,
(_sharp_pair_471 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_471).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_469;
_sharp_pair_469,
(_sharp_pair_469 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_469).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_467;
_sharp_pair_467,
(_sharp_pair_467 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_467).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_467).cdr) = ({
struct struct0x08092c38 *_sharp_pair_466;
_sharp_pair_466,
(_sharp_pair_466 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_466).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_466).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_466);
})
);
((List__O__Form__C____type__type ) _sharp_pair_467);
})
));
(((* _sharp_pair_469).cdr) = ({
struct struct0x08092c38 *_sharp_pair_468;
_sharp_pair_468,
(_sharp_pair_468 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_468).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_468).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_468);
})
);
((List__O__Form__C____type__type ) _sharp_pair_469);
})
));
(((* _sharp_pair_471).cdr) = ({
struct struct0x08092c38 *_sharp_pair_470;
_sharp_pair_470,
(_sharp_pair_470 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_470).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_470).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_470);
})
);
((List__O__Form__C____type__type ) _sharp_pair_471);
})
));
(((* _sharp_pair_472).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_472);
})
);
((List__O__Form__C____type__type ) _sharp_pair_473);
})
));
(((* _sharp_pair_475).cdr) = ({
struct struct0x08092c38 *_sharp_pair_474;
_sharp_pair_474,
(_sharp_pair_474 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_474).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_474).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_474);
})
);
((List__O__Form__C____type__type ) _sharp_pair_475);
})
));
(((* _sharp_pair_477).cdr) = ({
struct struct0x08092c38 *_sharp_pair_476;
_sharp_pair_476,
(_sharp_pair_476 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_476).car) = (Symbol_Form)(intern( "deref")));
(((* _sharp_pair_476).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_476);
})
);
((List__O__Form__C____type__type ) _sharp_pair_477);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_133)),
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
(print_String)(((String__type) &__string_134)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) ((Expanded_Compound_Form__type ) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)))).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_135)),
(maybe_flush)();
})
;}

void  c_output_label(Expanded_Compound_Form__type  cf)
{
return ({
Id_Form__type label_form;
({if( ((((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_136)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_486;
_sharp_pair_486,
(_sharp_pair_486 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_486).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_481;
_sharp_pair_481,
(_sharp_pair_481 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_481).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_479;
_sharp_pair_479,
(_sharp_pair_479 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_479).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_479).cdr) = ({
struct struct0x08092c38 *_sharp_pair_478;
_sharp_pair_478,
(_sharp_pair_478 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_478).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_478).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_478);
})
);
((List__O__Form__C____type__type ) _sharp_pair_479);
})
));
(((* _sharp_pair_481).cdr) = ({
struct struct0x08092c38 *_sharp_pair_480;
_sharp_pair_480,
(_sharp_pair_480 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_480).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_480).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_480);
})
);
((List__O__Form__C____type__type ) _sharp_pair_481);
})
));
(((* _sharp_pair_486).cdr) = ({
struct struct0x08092c38 *_sharp_pair_485;
_sharp_pair_485,
(_sharp_pair_485 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_485).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_484;
_sharp_pair_484,
(_sharp_pair_484 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_484).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08092c38 *_sharp_pair_482;
_sharp_pair_482,
(_sharp_pair_482 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_482).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_482).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_482);
})
));
(((* _sharp_pair_484).cdr) = ({
struct struct0x08092c38 *_sharp_pair_483;
_sharp_pair_483,
(_sharp_pair_483 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_483).car) = (Int_Form)(0));
(((* _sharp_pair_483).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_483);
})
);
((List__O__Form__C____type__type ) _sharp_pair_484);
})
));
(((* _sharp_pair_485).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_485);
})
);
((List__O__Form__C____type__type ) _sharp_pair_486);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_137)),
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
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_138)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08092c38 *_sharp_pair_493;
_sharp_pair_493,
(_sharp_pair_493 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_493).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_492;
_sharp_pair_492,
(_sharp_pair_492 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_492).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_492).cdr) = ({
struct struct0x08092c38 *_sharp_pair_491;
_sharp_pair_491,
(_sharp_pair_491 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_491).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_490;
_sharp_pair_490,
(_sharp_pair_490 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_490).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_488;
_sharp_pair_488,
(_sharp_pair_488 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_488).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_488).cdr) = ({
struct struct0x08092c38 *_sharp_pair_487;
_sharp_pair_487,
(_sharp_pair_487 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_487).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_487).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_487);
})
);
((List__O__Form__C____type__type ) _sharp_pair_488);
})
));
(((* _sharp_pair_490).cdr) = ({
struct struct0x08092c38 *_sharp_pair_489;
_sharp_pair_489,
(_sharp_pair_489 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_489).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_489).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_489);
})
);
((List__O__Form__C____type__type ) _sharp_pair_490);
})
));
(((* _sharp_pair_491).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_491);
})
);
((List__O__Form__C____type__type ) _sharp_pair_492);
})
));
(((* _sharp_pair_493).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_493);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_139)),
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
(label_form = ((Id_Form__type ) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)));
(print_String)(((String__type) &__string_140)),
(print_Symbol)((convert_id)(((* ((struct struct0x080595b0 *) label_form)).value))),
(print_String)(((String__type) &__string_141));
})
;}

void  c_output_let(Expanded_Compound_Form__type  cf)
{
return ({
({
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_142));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08092c38 *_sharp_pair_500;
_sharp_pair_500,
(_sharp_pair_500 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_500).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_499;
_sharp_pair_499,
(_sharp_pair_499 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_499).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_499).cdr) = ({
struct struct0x08092c38 *_sharp_pair_498;
_sharp_pair_498,
(_sharp_pair_498 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_498).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_497;
_sharp_pair_497,
(_sharp_pair_497 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_497).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_495;
_sharp_pair_495,
(_sharp_pair_495 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_495).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_495).cdr) = ({
struct struct0x08092c38 *_sharp_pair_494;
_sharp_pair_494,
(_sharp_pair_494 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_494).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_494).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_494);
})
);
((List__O__Form__C____type__type ) _sharp_pair_495);
})
));
(((* _sharp_pair_497).cdr) = ({
struct struct0x08092c38 *_sharp_pair_496;
_sharp_pair_496,
(_sharp_pair_496 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_496).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_496).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_496);
})
);
((List__O__Form__C____type__type ) _sharp_pair_497);
})
));
(((* _sharp_pair_498).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_498);
})
);
((List__O__Form__C____type__type ) _sharp_pair_499);
})
));
(((* _sharp_pair_500).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_500);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_143));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(c_output_type)((convert_id)(((* ((struct struct0x080595b0 *) ((Id_Form__type ) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)))).value)), (intern_type)(((Form__type ) ((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail))).head))));
})
;
})
;}

void  c_output_ref(Expanded_Compound_Form__type  cf)
{
return ({
({
Expanded_Form__type subform;
(subform = ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head));
({if( (is_compound_form)(((* ((struct struct0x0805f3a0 *) subform)).return_form)))
{
({
Expanded_Compound_Form__type csubform;
(csubform = ((Expanded_Compound_Form__type ) subform));
({if( (((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) csubform)).return_form_))).head) == intern( "cast")))
{
({
(print_String)(((String__type) &__string_144));
(c_output_type)(intern( ""), (intern_type)(((* ((struct struct0x0805f3a0 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) csubform)).return_form_))).form_list)))).head))).return_form)));
(print_String)(((String__type) &__string_145));
(print_String)(((String__type) &__string_146)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) csubform)).return_form_))).form_list)))).tail))).head)),
(print_String)(((String__type) &__string_147));
(print_String)(((String__type) &__string_148));
({goto end;});
})
;}})
;
})
;}})
;
(print_String)(((String__type) &__string_149)),
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head)),
(print_String)(((String__type) &__string_150));
})
;
((void) 0);end:((void) 0),
((void) 0);
})
;}

void  c_output_seq(Expanded_Compound_Form__type  cf)
{
return ({
({
({if( ((((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)) != ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_151));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x08092c38 *_sharp_pair_507;
_sharp_pair_507,
(_sharp_pair_507 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_507).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_502;
_sharp_pair_502,
(_sharp_pair_502 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_502).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_502).cdr) = ({
struct struct0x08092c38 *_sharp_pair_501;
_sharp_pair_501,
(_sharp_pair_501 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_501).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_501).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_501);
})
);
((List__O__Form__C____type__type ) _sharp_pair_502);
})
));
(((* _sharp_pair_507).cdr) = ({
struct struct0x08092c38 *_sharp_pair_506;
_sharp_pair_506,
(_sharp_pair_506 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_506).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_505;
_sharp_pair_505,
(_sharp_pair_505 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_505).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08092c38 *_sharp_pair_503;
_sharp_pair_503,
(_sharp_pair_503 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_503).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_503).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_503);
})
));
(((* _sharp_pair_505).cdr) = ({
struct struct0x08092c38 *_sharp_pair_504;
_sharp_pair_504,
(_sharp_pair_504 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_504).car) = (Int_Form)(0));
(((* _sharp_pair_504).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_504);
})
);
((List__O__Form__C____type__type ) _sharp_pair_505);
})
));
(((* _sharp_pair_506).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_506);
})
);
((List__O__Form__C____type__type ) _sharp_pair_507);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_152));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(c_output_form)(((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head));
({
List__O__Expanded_Form__C____type__type _sharp_iterator509;
(_sharp_iterator509 = ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail));
((void) 0);_sharp__sharp_loop510_begin513:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator509 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop510_end511;});}})
;
(subform = ((* ((struct struct0x0812d010 *) _sharp_iterator509)).car));
({
(print_String)(((String__type) &__string_153)),
(c_output_form)(subform);
})
;
((void) 0);_sharp__sharp_loop510_continue512:((void) 0);
(_sharp_iterator509 = ((* ((struct struct0x0812d010 *) _sharp_iterator509)).cdr));
})
,
({goto _sharp__sharp_loop510_begin513;}),
((void) 0);_sharp__sharp_loop510_end511:((void) 0);
})
;
})
;
})
;}

void  c_output_struct(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)(((String__type) &__string_154));
(c_output_type)(intern( ""), ((* ((struct struct0x08091300 *) cf)).type));
(print_String)(((String__type) &__string_155));
({
Expanded_Form__type form_subform;
Expanded_Form__type subform_;
(subform_ = ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).head));
({if( ((is_compound_form)(((* ((struct struct0x0805f3a0 *) subform_)).return_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_156));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08092c38 *_sharp_pair_516;
_sharp_pair_516,
(_sharp_pair_516 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_516).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_515;
_sharp_pair_515,
(_sharp_pair_515 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_515).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_515).cdr) = ({
struct struct0x08092c38 *_sharp_pair_514;
_sharp_pair_514,
(_sharp_pair_514 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_514).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_514).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_514);
})
);
((List__O__Form__C____type__type ) _sharp_pair_515);
})
));
(((* _sharp_pair_516).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_516);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_157));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
({if( ((((* ((struct struct0x0805e968 *) ((Compound_Form__type ) ((* ((struct struct0x0805f3a0 *) subform_)).return_form)))).head) == intern( "label")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_158));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_524;
_sharp_pair_524,
(_sharp_pair_524 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_524).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_522;
_sharp_pair_522,
(_sharp_pair_522 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_522).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_520;
_sharp_pair_520,
(_sharp_pair_520 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_520).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_520).cdr) = ({
struct struct0x08092c38 *_sharp_pair_519;
_sharp_pair_519,
(_sharp_pair_519 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_519).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_518;
_sharp_pair_518,
(_sharp_pair_518 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_518).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_518).cdr) = ({
struct struct0x08092c38 *_sharp_pair_517;
_sharp_pair_517,
(_sharp_pair_517 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_517).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_517).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_517);
})
);
((List__O__Form__C____type__type ) _sharp_pair_518);
})
));
(((* _sharp_pair_519).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_519);
})
);
((List__O__Form__C____type__type ) _sharp_pair_520);
})
));
(((* _sharp_pair_522).cdr) = ({
struct struct0x08092c38 *_sharp_pair_521;
_sharp_pair_521,
(_sharp_pair_521 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_521).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_521).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_521);
})
);
((List__O__Form__C____type__type ) _sharp_pair_522);
})
));
(((* _sharp_pair_524).cdr) = ({
struct struct0x08092c38 *_sharp_pair_523;
_sharp_pair_523,
(_sharp_pair_523 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_523).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_523).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_523);
})
);
((List__O__Form__C____type__type ) _sharp_pair_524);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_159));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(form_subform = ((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) ((Expanded_Compound_Form__type ) subform_))).return_form_))).form_list)))).tail))).head));
(c_output_form)(form_subform);
})
;
({
List__O__Expanded_Form__C____type__type _sharp_iterator526;
(_sharp_iterator526 = ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)))).tail));
((void) 0);_sharp__sharp_loop527_begin541:((void) 0),
({
Expanded_Form__type subform_;
({if( (_sharp_iterator526 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop527_end528;});}})
;
(subform_ = ((* ((struct struct0x0812d010 *) _sharp_iterator526)).car));
({
Expanded_Form__type form_subform;
({if( ((is_compound_form)(((* ((struct struct0x0805f3a0 *) subform_)).return_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_160));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08092c38 *_sharp_pair_531;
_sharp_pair_531,
(_sharp_pair_531 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_531).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_530;
_sharp_pair_530,
(_sharp_pair_530 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_530).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_530).cdr) = ({
struct struct0x08092c38 *_sharp_pair_529;
_sharp_pair_529,
(_sharp_pair_529 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_529).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_529).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_529);
})
);
((List__O__Form__C____type__type ) _sharp_pair_530);
})
));
(((* _sharp_pair_531).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_531);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_161));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
({if( ((((* ((struct struct0x0805e968 *) ((Compound_Form__type ) ((* ((struct struct0x0805f3a0 *) subform_)).return_form)))).head) == intern( "label")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_162));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_539;
_sharp_pair_539,
(_sharp_pair_539 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_539).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_537;
_sharp_pair_537,
(_sharp_pair_537 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_537).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_535;
_sharp_pair_535,
(_sharp_pair_535 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_535).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_535).cdr) = ({
struct struct0x08092c38 *_sharp_pair_534;
_sharp_pair_534,
(_sharp_pair_534 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_534).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_533;
_sharp_pair_533,
(_sharp_pair_533 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_533).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_533).cdr) = ({
struct struct0x08092c38 *_sharp_pair_532;
_sharp_pair_532,
(_sharp_pair_532 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_532).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_532).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_532);
})
);
((List__O__Form__C____type__type ) _sharp_pair_533);
})
));
(((* _sharp_pair_534).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_534);
})
);
((List__O__Form__C____type__type ) _sharp_pair_535);
})
));
(((* _sharp_pair_537).cdr) = ({
struct struct0x08092c38 *_sharp_pair_536;
_sharp_pair_536,
(_sharp_pair_536 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_536).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_536).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_536);
})
);
((List__O__Form__C____type__type ) _sharp_pair_537);
})
));
(((* _sharp_pair_539).cdr) = ({
struct struct0x08092c38 *_sharp_pair_538;
_sharp_pair_538,
(_sharp_pair_538 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_538).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_538).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_538);
})
);
((List__O__Form__C____type__type ) _sharp_pair_539);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_163));
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(form_subform = ((* ((struct struct0x0810fb48 *) ((* ((struct struct0x0810fb48 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) ((Expanded_Compound_Form__type ) subform_))).return_form_))).form_list)))).tail))).head));
(print_String)(((String__type) &__string_164)),
(c_output_form)(form_subform);
})
;
((void) 0);_sharp__sharp_loop527_continue540:((void) 0);
(_sharp_iterator526 = ((* ((struct struct0x0812d010 *) _sharp_iterator526)).cdr));
})
,
({goto _sharp__sharp_loop527_begin541;}),
((void) 0);_sharp__sharp_loop527_end528:((void) 0);
})
;
(print_String)(((String__type) &__string_165));
})
;
})
;}

void  c_output_tuple(Expanded_Compound_Form__type  cf)
{
return ({
(((((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((* ((struct struct0x08091300 *) cf)).return_form_))).form_list)) == ((List__O__Expanded_Form__C____type__type ) 0)))?
(({
(print_String)(((String__type) &__string_166)),
(maybe_flush)();
})
):
(({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_167)),
(print_String)(((String__type) &__string_168)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
));
})
;}

void  init_c_output(void)
{
return ({
(c_output_hash = ((Hash__O__Symbol__c__pointer__O__function__O__Void__c__tuple__O__Expanded_Compound_Form__C____C____C____C____type__type ) (make_hash_table)()));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "+_Int")), ((void *) (&c_output_add_int)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "*_Int")), ((void *) (&c_output_mul_int)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "-_Int")), ((void *) (&c_output_sub_int)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "/_Int")), ((void *) (&c_output_div_int)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "unary_minus_Int")), ((void *) (&c_output_unary_minus_int)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( ">=_Int")), ((void *) (&c_output_ge_int)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( ">_Int")), ((void *) (&c_output_gt_int)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "<=_Int")), ((void *) (&c_output_le_int)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "<_Int")), ((void *) (&c_output_lt_int)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "==")), ((void *) (&c_output_equal)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "!=")), ((void *) (&c_output_different)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "@logical_or")), ((void *) (&c_output_logical_or)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "@logical_and")), ((void *) (&c_output_logical_and)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "@not")), ((void *) (&c_output_logical_not)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "=")), ((void *) (&c_output_assign)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "[]_Struct")), ((void *) (&c_output_access_struct)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "block")), ((void *) (&c_output_block)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "cast")), ((void *) (&c_output_cast)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "deref")), ((void *) (&c_output_deref)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "funcall")), ((void *) (&c_output_funcall)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "if")), ((void *) (&c_output_if)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "@get_label")), ((void *) (&c_output_get_label)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "@goto_constant")), ((void *) (&c_output_goto_constant)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "@goto_variable")), ((void *) (&c_output_goto_variable)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "label")), ((void *) (&c_output_label)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "let")), ((void *) (&c_output_let)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "ref")), ((void *) (&c_output_ref)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "seq")), ((void *) (&c_output_seq)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "struct")), ((void *) (&c_output_struct)), ((Hash_Table__type ) c_output_hash)));
((void (*)(Expanded_Compound_Form__type )) (puthash)(((void *) intern( "tuple")), ((void *) (&c_output_tuple)), ((Hash_Table__type ) c_output_hash)));
(init_output_type)();
})
;}

void  c_output_function_definition(Symbol__type  name, Form__type  l_)
{
return ({
Compound_Form__type parameters_type;
Form__type l;
Form__type return_type;
List__O__Form__C____type__type form_list;
({if( (name == intern( "parse_Unsigned_Number")))
{
(print_form)(l_);}})
;
({if( ((is_expanded_form)(l_) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_169)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_expanded_form"), ({
struct struct0x08092c38 *_sharp_pair_542;
_sharp_pair_542,
(_sharp_pair_542 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_542).car) = (Id_Form)(intern( "l_")));
(((* _sharp_pair_542).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_542);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_170)),
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
(l = ((* ((struct struct0x0805f3a0 *) ((Expanded_Form__type ) l_))).return_form));
({if( ((is_compound_form)(l) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_171)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08092c38 *_sharp_pair_543;
_sharp_pair_543,
(_sharp_pair_543 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_543).car) = (Id_Form)(intern( "l")));
(((* _sharp_pair_543).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_543);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_172)),
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
({if( ((((* ((struct struct0x0805e968 *) ((Compound_Form__type ) l))).head) == intern( "lambda")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_173)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_549;
_sharp_pair_549,
(_sharp_pair_549 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_549).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_547;
_sharp_pair_547,
(_sharp_pair_547 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_547).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_545;
_sharp_pair_545,
(_sharp_pair_545 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_545).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_545).cdr) = ({
struct struct0x08092c38 *_sharp_pair_544;
_sharp_pair_544,
(_sharp_pair_544 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_544).car) = (Id_Form)(intern( "l")));
(((* _sharp_pair_544).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_544);
})
);
((List__O__Form__C____type__type ) _sharp_pair_545);
})
));
(((* _sharp_pair_547).cdr) = ({
struct struct0x08092c38 *_sharp_pair_546;
_sharp_pair_546,
(_sharp_pair_546 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_546).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_546).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_546);
})
);
((List__O__Form__C____type__type ) _sharp_pair_547);
})
));
(((* _sharp_pair_549).cdr) = ({
struct struct0x08092c38 *_sharp_pair_548;
_sharp_pair_548,
(_sharp_pair_548 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_548).car) = (Symbol_Form)(intern( "lambda")));
(((* _sharp_pair_548).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_548);
})
);
((List__O__Form__C____type__type ) _sharp_pair_549);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_174)),
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
(form_list = ((List__O__Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((Compound_Form__type ) l))).form_list)));
(return_type = ((* ((struct struct0x0805eba0 *) form_list)).head));
(c_output_type)(intern( ""), (intern_type)(return_type));
(print_String)(((String__type) &__string_175)),
(print_Symbol)((convert_id)(name)),
(print_String)(((String__type) &__string_176)),
(maybe_flush)();
(parameters_type = ((Compound_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) form_list)).tail))).head)));
({if( ((((* ((struct struct0x0805e968 *) parameters_type)).head) == intern( "tuple")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_177)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_553;
_sharp_pair_553,
(_sharp_pair_553 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_553).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_551;
_sharp_pair_551,
(_sharp_pair_551 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_551).car) = (Id_Form)(intern( "parameters_type")));
(((* _sharp_pair_551).cdr) = ({
struct struct0x08092c38 *_sharp_pair_550;
_sharp_pair_550,
(_sharp_pair_550 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_550).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_550).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_550);
})
);
((List__O__Form__C____type__type ) _sharp_pair_551);
})
));
(((* _sharp_pair_553).cdr) = ({
struct struct0x08092c38 *_sharp_pair_552;
_sharp_pair_552,
(_sharp_pair_552 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_552).car) = (Symbol_Form)(intern( "tuple")));
(((* _sharp_pair_552).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_552);
})
);
((List__O__Form__C____type__type ) _sharp_pair_553);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_178)),
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
(((((* ((struct struct0x0805e968 *) parameters_type)).form_list) == ((List__O__Form__C____type__type ) 0)))?
((print_String)(((String__type) &__string_179)),
(maybe_flush)()):
(({
Id_Form__type first_param_name;
Form__type first_param_type;
Compound_Form__type first_parameter;
(first_parameter = ((Compound_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) parameters_type)).form_list))).head)));
({if( ((((* ((struct struct0x0805e968 *) first_parameter)).head) == intern( "label")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_180)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_557;
_sharp_pair_557,
(_sharp_pair_557 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_557).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_555;
_sharp_pair_555,
(_sharp_pair_555 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_555).car) = (Id_Form)(intern( "first_parameter")));
(((* _sharp_pair_555).cdr) = ({
struct struct0x08092c38 *_sharp_pair_554;
_sharp_pair_554,
(_sharp_pair_554 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_554).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_554).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_554);
})
);
((List__O__Form__C____type__type ) _sharp_pair_555);
})
));
(((* _sharp_pair_557).cdr) = ({
struct struct0x08092c38 *_sharp_pair_556;
_sharp_pair_556,
(_sharp_pair_556 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_556).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_556).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_556);
})
);
((List__O__Form__C____type__type ) _sharp_pair_557);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_181)),
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
(first_param_name = ((Id_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) first_parameter)).form_list))).head)));
(first_param_type = ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) first_parameter)).form_list))).tail))).head));
(c_output_type)(intern( ""), (intern_type)(((Form__type ) first_param_type)));
(print_String)(((String__type) &__string_182)),
(print_Symbol)((convert_id)(((* ((struct struct0x080595b0 *) first_param_name)).value))),
(maybe_flush)();
({
List__O__Compound_Form__C____type__type _sharp_iterator559;
(_sharp_iterator559 = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) parameters_type)).form_list))).tail)));
((void) 0);_sharp__sharp_loop560_begin567:((void) 0),
({
Compound_Form__type parameter;
({if( (_sharp_iterator559 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop560_end561;});}})
;
(parameter = ((* ((struct struct0x081d3e38 *) _sharp_iterator559)).car));
({
Id_Form__type param_name;
Form__type type;
(print_String)(((String__type) &__string_183)),
(maybe_flush)();
({if( ((((* ((struct struct0x0805e968 *) first_parameter)).head) == intern( "label")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_184)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_565;
_sharp_pair_565,
(_sharp_pair_565 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_565).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_563;
_sharp_pair_563,
(_sharp_pair_563 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_563).car) = (Id_Form)(intern( "first_parameter")));
(((* _sharp_pair_563).cdr) = ({
struct struct0x08092c38 *_sharp_pair_562;
_sharp_pair_562,
(_sharp_pair_562 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_562).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_562).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_562);
})
);
((List__O__Form__C____type__type ) _sharp_pair_563);
})
));
(((* _sharp_pair_565).cdr) = ({
struct struct0x08092c38 *_sharp_pair_564;
_sharp_pair_564,
(_sharp_pair_564 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_564).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_564).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_564);
})
);
((List__O__Form__C____type__type ) _sharp_pair_565);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_185)),
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
(param_name = ((Id_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) parameter)).form_list))).head)));
(type = ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) parameter)).form_list))).tail))).head));
(c_output_type)(intern( ""), (intern_type)(((Form__type ) type)));
(print_String)(((String__type) &__string_186)),
(print_Symbol)((convert_id)(((* ((struct struct0x080595b0 *) param_name)).value))),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop560_continue566:((void) 0);
(_sharp_iterator559 = ((* ((struct struct0x081d3e38 *) _sharp_iterator559)).cdr));
})
,
({goto _sharp__sharp_loop560_begin567;}),
((void) 0);_sharp__sharp_loop560_end561:((void) 0);
})
;
})
));
(print_String)(((String__type) &__string_187)),
(maybe_flush)();
(c_output_form)(((Expanded_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) form_list)).tail))).tail))).head))),
(maybe_flush)();
(print_String)(((String__type) &__string_188)),
(maybe_flush)();
})
;}

void  c_output_global_definition(Symbol__type  name, Form__type  form_type)
{
return ({
(c_output_type)(name, (intern_type)(form_type));
(print_String)(((String__type) &__string_189)),
(maybe_flush)();
})
;}

void  c_output_definition(Compound_Form__type  f)
{
return ({
Symbol__type species;
Symbol__type name;
List__O__Form__C____type__type form_list;
({if( ((is_compound_form)(((Form__type ) f)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_190)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08092c38 *_sharp_pair_570;
_sharp_pair_570,
(_sharp_pair_570 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_570).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_569;
_sharp_pair_569,
(_sharp_pair_569 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_569).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_569).cdr) = ({
struct struct0x08092c38 *_sharp_pair_568;
_sharp_pair_568,
(_sharp_pair_568 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_568).car) = (Id_Form)(intern( "f")));
(((* _sharp_pair_568).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_568);
})
);
((List__O__Form__C____type__type ) _sharp_pair_569);
})
));
(((* _sharp_pair_570).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_570);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_191)),
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
({if( ((((* ((struct struct0x0805e968 *) f)).head) == intern( "define")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_192)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_574;
_sharp_pair_574,
(_sharp_pair_574 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_574).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_572;
_sharp_pair_572,
(_sharp_pair_572 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_572).car) = (Id_Form)(intern( "f")));
(((* _sharp_pair_572).cdr) = ({
struct struct0x08092c38 *_sharp_pair_571;
_sharp_pair_571,
(_sharp_pair_571 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_571).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_571).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_571);
})
);
((List__O__Form__C____type__type ) _sharp_pair_572);
})
));
(((* _sharp_pair_574).cdr) = ({
struct struct0x08092c38 *_sharp_pair_573;
_sharp_pair_573,
(_sharp_pair_573 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_573).car) = (Symbol_Form)(intern( "define")));
(((* _sharp_pair_573).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_573);
})
);
((List__O__Form__C____type__type ) _sharp_pair_574);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_193)),
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
(form_list = ((List__O__Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((Compound_Form__type ) f))).form_list)));
({if( ((is_id_form)(((* ((struct struct0x0805eba0 *) form_list)).head)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_194)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08092c38 *_sharp_pair_577;
_sharp_pair_577,
(_sharp_pair_577 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_577).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_576;
_sharp_pair_576,
(_sharp_pair_576 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_576).car) = (Id_Form)(intern( "form_list")));
(((* _sharp_pair_576).cdr) = ({
struct struct0x08092c38 *_sharp_pair_575;
_sharp_pair_575,
(_sharp_pair_575 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_575).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_575).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_575);
})
);
((List__O__Form__C____type__type ) _sharp_pair_576);
})
));
(((* _sharp_pair_577).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_577);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_195)),
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
(species = ((* ((struct struct0x080595b0 *) ((Id_Form__type ) ((* ((struct struct0x0805eba0 *) form_list)).head)))).value));
({if( ((is_id_form)(((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) form_list)).tail))).head)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_196)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08092c38 *_sharp_pair_582;
_sharp_pair_582,
(_sharp_pair_582 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_582).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_581;
_sharp_pair_581,
(_sharp_pair_581 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_581).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_579;
_sharp_pair_579,
(_sharp_pair_579 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_579).car) = (Id_Form)(intern( "form_list")));
(((* _sharp_pair_579).cdr) = ({
struct struct0x08092c38 *_sharp_pair_578;
_sharp_pair_578,
(_sharp_pair_578 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_578).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_578).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_578);
})
);
((List__O__Form__C____type__type ) _sharp_pair_579);
})
));
(((* _sharp_pair_581).cdr) = ({
struct struct0x08092c38 *_sharp_pair_580;
_sharp_pair_580,
(_sharp_pair_580 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_580).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_580).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_580);
})
);
((List__O__Form__C____type__type ) _sharp_pair_581);
})
));
(((* _sharp_pair_582).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_582);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_197)),
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
(name = ((* ((struct struct0x080595b0 *) ((Id_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) form_list)).tail))).head)))).value));
(((species == intern( "function")))?
(({
(c_output_function_definition)(name, ((Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) form_list)).tail))).tail))).head)));
})
):
((((species == intern( "type")))?
(({
((void) 0);
})
):
((((species == intern( "global")))?
(({
(c_output_global_definition)(name, ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) form_list)).tail))).tail))).head));
((void) 0);
})
):
((((species == intern( "expander")))?
(({
Form__type funform;
(funform = ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) f)).form_list))).tail))).tail))).head));
(c_output_definition)(((Compound_Form__type ) funform));
((void) 0);
})
):
((((species == intern( "attribute")))?
(({
((void) 0);
})
):
((((species == intern( "compile_time")))?
(({
({
List__O__Form__C____type__type _sharp_iterator584;
(_sharp_iterator584 = ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) form_list)).tail))).tail));
((void) 0);_sharp__sharp_loop585_begin588:((void) 0),
({
Form__type definition;
({if( (_sharp_iterator584 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop585_end586;});}})
;
(definition = ((* ((struct struct0x08092c38 *) _sharp_iterator584)).car));
({
(c_output_definition)(((Compound_Form__type ) definition));
})
;
((void) 0);_sharp__sharp_loop585_continue587:((void) 0);
(_sharp_iterator584 = ((* ((struct struct0x08092c38 *) _sharp_iterator584)).cdr));
})
,
({goto _sharp__sharp_loop585_begin588;}),
((void) 0);_sharp__sharp_loop585_end586:((void) 0);
})
;
})
):
(({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_198)),
(print_Symbol)(species),
(print_String)(((String__type) &__string_199)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_200)),
(print_String)(((String__type) &__string_201)),
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
))))))))))));
})
;}

void  c_output_init_definition(Compound_Form__type  f)
{
return ({
Symbol__type species;
Id_Form__type name_form;
List__O__Form__C____type__type form_list;
({if( ((is_compound_form)(((Form__type ) f)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_202)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08092c38 *_sharp_pair_591;
_sharp_pair_591,
(_sharp_pair_591 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_591).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08092c38 *_sharp_pair_590;
_sharp_pair_590,
(_sharp_pair_590 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_590).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_590).cdr) = ({
struct struct0x08092c38 *_sharp_pair_589;
_sharp_pair_589,
(_sharp_pair_589 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_589).car) = (Id_Form)(intern( "f")));
(((* _sharp_pair_589).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_589);
})
);
((List__O__Form__C____type__type ) _sharp_pair_590);
})
));
(((* _sharp_pair_591).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_591);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_203)),
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
({if( ((((* ((struct struct0x0805e968 *) f)).head) == intern( "define")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_204)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08092c38 *_sharp_pair_595;
_sharp_pair_595,
(_sharp_pair_595 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_595).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_593;
_sharp_pair_593,
(_sharp_pair_593 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_593).car) = (Id_Form)(intern( "f")));
(((* _sharp_pair_593).cdr) = ({
struct struct0x08092c38 *_sharp_pair_592;
_sharp_pair_592,
(_sharp_pair_592 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_592).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_592).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_592);
})
);
((List__O__Form__C____type__type ) _sharp_pair_593);
})
));
(((* _sharp_pair_595).cdr) = ({
struct struct0x08092c38 *_sharp_pair_594;
_sharp_pair_594,
(_sharp_pair_594 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_594).car) = (Symbol_Form)(intern( "define")));
(((* _sharp_pair_594).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_594);
})
);
((List__O__Form__C____type__type ) _sharp_pair_595);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_205)),
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
(form_list = ((List__O__Form__C____type__type ) ((* ((struct struct0x0805e968 *) ((Compound_Form__type ) f))).form_list)));
({if( ((is_id_form)(((* ((struct struct0x0805eba0 *) form_list)).head)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_206)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08092c38 *_sharp_pair_598;
_sharp_pair_598,
(_sharp_pair_598 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_598).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_597;
_sharp_pair_597,
(_sharp_pair_597 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_597).car) = (Id_Form)(intern( "form_list")));
(((* _sharp_pair_597).cdr) = ({
struct struct0x08092c38 *_sharp_pair_596;
_sharp_pair_596,
(_sharp_pair_596 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_596).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_596).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_596);
})
);
((List__O__Form__C____type__type ) _sharp_pair_597);
})
));
(((* _sharp_pair_598).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_598);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_207)),
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
(species = ((* ((struct struct0x080595b0 *) ((Id_Form__type ) ((* ((struct struct0x0805eba0 *) form_list)).head)))).value));
({if( ((is_id_form)(((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) form_list)).tail))).head)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_208)),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08092c38 *_sharp_pair_603;
_sharp_pair_603,
(_sharp_pair_603 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_603).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_602;
_sharp_pair_602,
(_sharp_pair_602 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_602).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08092c38 *_sharp_pair_600;
_sharp_pair_600,
(_sharp_pair_600 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_600).car) = (Id_Form)(intern( "form_list")));
(((* _sharp_pair_600).cdr) = ({
struct struct0x08092c38 *_sharp_pair_599;
_sharp_pair_599,
(_sharp_pair_599 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_599).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_599).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_599);
})
);
((List__O__Form__C____type__type ) _sharp_pair_600);
})
));
(((* _sharp_pair_602).cdr) = ({
struct struct0x08092c38 *_sharp_pair_601;
_sharp_pair_601,
(_sharp_pair_601 = ((struct struct0x08092c38 *) (alloc_cons_cell)()));
(((* _sharp_pair_601).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_601).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_601);
})
);
((List__O__Form__C____type__type ) _sharp_pair_602);
})
));
(((* _sharp_pair_603).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_603);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
(print_String)(((String__type) &__string_209)),
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
(name_form = ((Id_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) form_list)).tail))).head)));
({if( (species == intern( "expander")))
{
({
Symbol__type funname;
Form__type funform;
(funform = ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) f)).form_list))).tail))).tail))).head));
(funname = ((* ((struct struct0x080595b0 *) ((Id_Form__type ) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805eba0 *) ((* ((struct struct0x0805e968 *) ((Compound_Form__type ) funform))).form_list))).tail))).head)))).value));
(print_String)(((String__type) &__string_210)),
(maybe_flush)();
(print_Symbol)(intern( "intern( \"")),
(print_String)((convert_id_as_string)(((* ((struct struct0x080595b0 *) name_form)).value))),
(print_Symbol)(intern( "\")")),
(maybe_flush)();
(print_String)(((String__type) &__string_211)),
(print_Symbol)((convert_id)(funname)),
(print_String)(((String__type) &__string_212)),
(maybe_flush)();
})
;}})
;
})
;}

void  doit(String__type  l_file, String__type  out_c_file, String__type  out_inc_file)
{
return ({
List__O__Compound_Form__C____type__type form_list;
(string_counter = 0);
(strings_needed = ((Hash__O__Int__c__String__C____type__type ) (make_hash_table)()));
(globals_needed = ((Hash__O__Symbol__c__Bool__C____type__type ) (make_hash_table)()));
(reinit_types)();
(stdout_descriptor = current_output_descriptor);
(output_file_descriptor = (make_output_descriptor_write_file)(out_c_file));
(inc_file_descriptor = (make_output_descriptor_write_file)(out_inc_file));
(form_list = (expanded_form_list_from_file_name)(l_file));
(current_output_descriptor = output_file_descriptor);
(print_String)(((String__type) &__string_213)),
(maybe_flush)();
(print_Symbol)(intern( "#include \"")),
(print_String)((file_name_non_directory)(out_inc_file)),
(print_Symbol)(intern( "\"")),
(print_String)(((String__type) &__string_214)),
(maybe_flush)();
({
List__O__Compound_Form__C____type__type _sharp_iterator605;
(_sharp_iterator605 = form_list);
((void) 0);_sharp__sharp_loop606_begin609:((void) 0),
({
Compound_Form__type f;
({if( (_sharp_iterator605 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop606_end607;});}})
;
(f = ((* ((struct struct0x081d3e38 *) _sharp_iterator605)).car));
(c_output_definition)(f);
((void) 0);_sharp__sharp_loop606_continue608:((void) 0);
(_sharp_iterator605 = ((* ((struct struct0x081d3e38 *) _sharp_iterator605)).cdr));
})
,
({goto _sharp__sharp_loop606_begin609;}),
((void) 0);_sharp__sharp_loop606_end607:((void) 0);
})
;
(print_String)(((String__type) &__string_215)),
(print_String)((file_name_non_extension)((file_name_non_directory)(out_inc_file))),
(print_String)(((String__type) &__string_216)),
(maybe_flush)();
({
List__O__Compound_Form__C____type__type _sharp_iterator611;
(_sharp_iterator611 = form_list);
((void) 0);_sharp__sharp_loop612_begin615:((void) 0),
({
Compound_Form__type f;
({if( (_sharp_iterator611 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop612_end613;});}})
;
(f = ((* ((struct struct0x081d3e38 *) _sharp_iterator611)).car));
(c_output_init_definition)(f);
((void) 0);_sharp__sharp_loop612_continue614:((void) 0);
(_sharp_iterator611 = ((* ((struct struct0x081d3e38 *) _sharp_iterator611)).cdr));
})
,
({goto _sharp__sharp_loop612_begin615;}),
((void) 0);_sharp__sharp_loop612_end613:((void) 0);
})
;
(print_String)(((String__type) &__string_217)),
(maybe_flush)();
(print_Symbol)(intern( "void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( \"TEST result: %d\", test_ptr());flush();}")),
(print_String)(((String__type) &__string_218)),
(maybe_flush)();
(flush)();
({
void **PValue_;
Hash__O__Symbol__c__Bool__C____type__type hash_;
Int__type Index_;
(Index_ = 0);
(hash_ = globals_needed);
PValue_;
(PValue_ = (JudyLFirst)((* ((void **) hash_)), ((void *) (&Index_)), 0));
((void) 0);_sharp__sharp_loop617_begin621:((void) 0),
({
Bool__type _sharp_tuple620;
Symbol__type _sharp_tuple619;
Bool__type misc_;
Symbol__type symbol;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop617_end618;});}})
;
(_sharp_tuple619 = ((Symbol__type ) Index_)),
(_sharp_tuple620 = ((Bool__type ) (* PValue_))),
(symbol = _sharp_tuple619),
(misc_ = _sharp_tuple620);
({
Type__type t;
(t = (get_global_type)(symbol));
((Bool__type ) (puthash)(((void *) t), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) type_definition_needed)));
})
;
(PValue_ = (JudyLNext)((* ((void **) hash_)), ((void *) (&Index_)), 0));
})
,
({goto _sharp__sharp_loop617_begin621;}),
((void) 0);_sharp__sharp_loop617_end618:((void) 0);
})
;
((Bool__type ) (puthash)(((void *) (intern_type)((Id_Form)(intern( "Output_Descriptor")))), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) type_definition_needed)));
(current_output_descriptor = inc_file_descriptor);
(output_all_type_definitions)();
({
void **PValue_;
Hash__O__Symbol__c__Bool__C____type__type hash_;
Int__type Index_;
(Index_ = 0);
(hash_ = globals_needed);
PValue_;
(PValue_ = (JudyLFirst)((* ((void **) hash_)), ((void *) (&Index_)), 0));
((void) 0);_sharp__sharp_loop623_begin627:((void) 0),
({
Bool__type _sharp_tuple626;
Symbol__type _sharp_tuple625;
Bool__type misc_;
Symbol__type symbol;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop623_end624;});}})
;
(_sharp_tuple625 = ((Symbol__type ) Index_)),
(_sharp_tuple626 = ((Bool__type ) (* PValue_))),
(symbol = _sharp_tuple625),
(misc_ = _sharp_tuple626);
({
Type__type t;
(t = (get_global_type)(symbol));
(c_output_type)(symbol, t);
(print_String)(((String__type) &__string_219)),
(maybe_flush)();
})
;
(PValue_ = (JudyLNext)((* ((void **) hash_)), ((void *) (&Index_)), 0));
})
,
({goto _sharp__sharp_loop623_begin627;}),
((void) 0);_sharp__sharp_loop623_end624:((void) 0);
})
;
(print_String)(((String__type) &__string_220)),
(print_String)(((String__type) &__string_221)),
(print_String)(((String__type) &__string_222)),
(maybe_flush)();
({
void **PValue_;
Hash__O__Int__c__String__C____type__type hash_;
Int__type Index_;
(Index_ = 0);
(hash_ = strings_needed);
PValue_;
(PValue_ = (JudyLFirst)((* ((void **) hash_)), ((void *) (&Index_)), 0));
((void) 0);_sharp__sharp_loop629_begin633:((void) 0),
({
String__type _sharp_tuple632;
Int__type _sharp_tuple631;
String__type string;
Int__type count;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop629_end630;});}})
;
(_sharp_tuple631 = ((Int__type ) Index_)),
(_sharp_tuple632 = ((String__type ) (* PValue_))),
(count = _sharp_tuple631),
(string = _sharp_tuple632);
({
(print_String)(((String__type) &__string_223)),
(print_String)(((String__type) &__string_224)),
(print_Int_Dec)(count),
(print_String)(((String__type) &__string_225)),
(print_Int_Dec)((get_string_length)(string)),
(print_Symbol)(intern( ", \"")),
(print_String)((convert_string)(string)),
(print_Symbol)(intern( "\"")),
(print_String)(((String__type) &__string_226)),
(maybe_flush)();
})
;
(PValue_ = (JudyLNext)((* ((void **) hash_)), ((void *) (&Index_)), 0));
})
,
({goto _sharp__sharp_loop629_begin633;}),
((void) 0);_sharp__sharp_loop629_end630:((void) 0);
})
;
(flush)();
})
;}

void  test(void)
{
return ({
(stdout_descriptor = current_output_descriptor);
(init_c_output)();
(doit)(((String__type) &__string_227), ((String__type) &__string_228), ((String__type) &__string_229));
})
;}

void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( "TEST result: %d", test_ptr());flush();}
