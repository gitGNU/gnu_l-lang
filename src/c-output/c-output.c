#include "c-output.inc"
Hash__O__Type__c__Bool__C____type__type has_been_outputed;

Hash__O__Type__c__Bool__C____type__type type_definition_needed;

Output_Descriptor__type inc_file_descriptor;

Output_Descriptor__type output_file_descriptor;

Output_Descriptor__type stdout_descriptor;

Hash__O__Symbol__c__Bool__C____type__type globals_needed;

Hash__O__Symbol__c__pointer__O__function__O__Void__c__tuple__O__Expanded_Compound_Form__C____C____C____C____type__type c_output_hash;

Bool__type  is_compound_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x0805c940 *) rf)).form_type_) == 1811939328);
})
;}

Bool__type  is_expanded_form(Form__type  f)
{
return ({
(((* ((struct struct0x0805c940 *) f)).form_type_) == (- (int) 536870912));
})
;}

Bool__type  is_id_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x0805c940 *) rf)).form_type_) == (- (int) 1342177280));
})
;}

Bool__type  is_int_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x0805c940 *) rf)).form_type_) == (- (int) -2147483648));
})
;}

Bool__type  is_symbol_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x0805c940 *) rf)).form_type_) == (- (int) 1073741824));
})
;}

Bool__type  is_string_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x0805c940 *) rf)).form_type_) == (- (int) 1610612736));
})
;}

Bool__type  is_struct_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) nt)).common_)).type_type) == 0);
})
;}

Bool__type  is_base_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) nt)).common_)).type_type) == 3);
})
;}

Bool__type  is_pointer_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) nt)).common_)).type_type) == 4);
})
;}

Bool__type  is_tuple_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) nt)).common_)).type_type) == 2);
})
;}

Bool__type  is_function_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) nt)).common_)).type_type) == 1);
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
(((((* ((struct struct0x0805cdd8 *) bt)).origin_type) == ((Type__type ) 0)))?
(({
({if( ((is_id_form)((((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) bt))).common_)).type_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x0808c540 *_sharp_pair_399;
_sharp_pair_399,
(_sharp_pair_399 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_399).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_398;
_sharp_pair_398,
(_sharp_pair_398 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_398).car) = (Id_Form)(intern( "bt")));
(((* _sharp_pair_398).cdr) = ({
struct struct0x0808c540 *_sharp_pair_397;
_sharp_pair_397,
(_sharp_pair_397 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_397).car) = (Symbol_Form)(intern( "type_form")));
(((* _sharp_pair_397).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_397);
})
);
((List__O__Form__C____type__type ) _sharp_pair_398);
})
));
(((* _sharp_pair_399).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_399);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(print_Symbol)(((* ((struct struct0x08058df0 *) ((Id_Form__type ) (((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) bt))).common_)).type_form)))).value)),
(maybe_flush)();
})
):
((print_Symbol)((mangle_type_name)(t)),
(maybe_flush)()));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "__type "), "__type "})),
(print_Symbol)(name),
(maybe_flush)();
})
):
((((is_struct_type)(t))?
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "struct struct"), "struct struct"})),
(print_Int_Hex)(((Int__type ) t)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " "), " "})),
(print_Symbol)(name),
(maybe_flush)();
})
):
((((is_pointer_type)(t))?
(({
(c_output_type)((prepend_star)(name), (intern_type)(((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) ((Compound_Form__type ) (((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) t))).common_)).type_form)))).form_list))).head)));
})
):
((((is_tuple_type)(t))?
(({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) t))).common_)).type_form)));
(((((* ((struct struct0x0805e130 *) tf)).form_list) == ((List__O__Form__C____type__type ) 0)))?
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "void "), "void "})),
(print_Symbol)(name),
(maybe_flush)();
})
):
(({
(print_form)((((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) t))).common_)).type_form));
({
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Panic : "), "Panic : "})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Non void tuples not implemented\n"), "Non void tuples not implemented\n"})),
(maybe_flush)();
(flush)();
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
(form_list = ((* ((struct struct0x0805e130 *) ((Compound_Form__type ) (((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) t))).common_)).type_form)))).form_list));
(return_type = (intern_type)(((* ((struct struct0x08059148 *) form_list)).head)));
(c_output_type)(intern( ""), return_type);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(print_Symbol)(name),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"})),
(maybe_flush)();
(parameters = ((Compound_Form__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) form_list)).tail))).head)));
(((((* ((struct struct0x0805e130 *) parameters)).form_list) == ((List__O__Form__C____type__type ) 0)))?
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(void)"), "(void)"})),
(maybe_flush)();
})
):
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(maybe_flush)();
(c_output_type)(intern( ""), (intern_type)(((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) parameters)).form_list))).head)));
({
List__O__Form__C____type__type _sharp_iterator401;
(_sharp_iterator401 = ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) parameters)).form_list))).tail));
((void) 0);_sharp__sharp_loop402_begin405:((void) 0),
({
Form__type parameter;
({if( (_sharp_iterator401 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop402_end403;});}})
;
(parameter = ((* ((struct struct0x0808c540 *) _sharp_iterator401)).car));
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(maybe_flush)();
(c_output_type)(intern( ""), (intern_type)(parameter));
})
;
((void) 0);_sharp__sharp_loop402_continue404:((void) 0);
(_sharp_iterator401 = ((* ((struct struct0x0808c540 *) _sharp_iterator401)).cdr));
})
,
({goto _sharp__sharp_loop402_begin405;}),
((void) 0);_sharp__sharp_loop402_end403:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"})),
(maybe_flush)();
})
));
})
):
(({
(print_form)((((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) t))).common_)).type_form));
({
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Panic : "), "Panic : "})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Unimplemented\n"), "Unimplemented\n"})),
(maybe_flush)();
(flush)();
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
({if( (((* ((struct struct0x0805cdd8 *) bt)).origin_type) == ((Type__type ) 0)))
{
({
({goto end;});
})
;}})
;
({if( ((Bool__type ) (gethash)(((void *) ((* ((struct struct0x0805cdd8 *) bt)).origin_type)), ((Hash_Table__type ) has_been_outputed))))
{
({
({goto next;});
})
;}})
;
(c_output_type_definition)(((* ((struct struct0x0805cdd8 *) bt)).origin_type));
((void) 0);next:((void) 0),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "typedef "), "typedef "})),
(maybe_flush)();
(c_output_type)((mangle_type_name)(t), ((* ((struct struct0x0805cdd8 *) bt)).origin_type));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "__type"), "__type"})),
(maybe_flush)();
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n"), ";\n"})),
(maybe_flush)();
})
):
((((is_struct_type)(t))?
(({
Form__type tf;
(tf = (((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) t))).common_)).type_form));
({
List__O__Form__C____type__type _sharp_iterator407;
(_sharp_iterator407 = ((* ((struct struct0x0805e130 *) ((Compound_Form__type ) tf))).form_list));
((void) 0);_sharp__sharp_loop408_begin416:((void) 0),
({
Form__type label_form_;
({if( (_sharp_iterator407 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop408_end409;});}})
;
(label_form_ = ((* ((struct struct0x0808c540 *) _sharp_iterator407)).car));
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
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x0808c540 *_sharp_pair_410;
_sharp_pair_410,
(_sharp_pair_410 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_410).car) = (Id_Form)(intern( "label_form_")));
(((* _sharp_pair_410).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_410);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(label_form = ((Compound_Form__type ) label_form_));
({if( ((((* ((struct struct0x0805e130 *) label_form)).head) == intern( "label")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_414;
_sharp_pair_414,
(_sharp_pair_414 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_414).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_412;
_sharp_pair_412,
(_sharp_pair_412 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_412).car) = (Id_Form)(intern( "label_form")));
(((* _sharp_pair_412).cdr) = ({
struct struct0x0808c540 *_sharp_pair_411;
_sharp_pair_411,
(_sharp_pair_411 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_411).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_411).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_411);
})
);
((List__O__Form__C____type__type ) _sharp_pair_412);
})
));
(((* _sharp_pair_414).cdr) = ({
struct struct0x0808c540 *_sharp_pair_413;
_sharp_pair_413,
(_sharp_pair_413 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_413).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_413).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_413);
})
);
((List__O__Form__C____type__type ) _sharp_pair_414);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(subtf = ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) label_form)).form_list))).tail))).head));
(subtype = (intern_type)(subtf));
({if( ((Bool__type ) (gethash)(((void *) subtype), ((Hash_Table__type ) has_been_outputed))))
{
({goto _sharp__sharp_loop408_continue415;});}})
;
(c_output_type_definition)(subtype);
})
;
((void) 0);_sharp__sharp_loop408_continue415:((void) 0);
(_sharp_iterator407 = ((* ((struct struct0x0808c540 *) _sharp_iterator407)).cdr));
})
,
({goto _sharp__sharp_loop408_begin416;}),
((void) 0);_sharp__sharp_loop408_end409:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "struct struct"), "struct struct"})),
(print_Int_Hex)(((Int__type ) t)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " {\n"), " {\n"})),
(maybe_flush)();
({
List__O__Form__C____type__type _sharp_iterator418;
(_sharp_iterator418 = ((* ((struct struct0x0805e130 *) ((Compound_Form__type ) tf))).form_list));
((void) 0);_sharp__sharp_loop419_begin427:((void) 0),
({
Form__type label_form_;
({if( (_sharp_iterator418 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop419_end420;});}})
;
(label_form_ = ((* ((struct struct0x0808c540 *) _sharp_iterator418)).car));
({
Symbol__type field_name;
Type__type subtype;
Form__type subtf;
Compound_Form__type label_form;
(label_form = ((Compound_Form__type ) label_form_));
({if( ((is_id_form)(((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) label_form)).form_list))).head)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x0808c540 *_sharp_pair_425;
_sharp_pair_425,
(_sharp_pair_425 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_425).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_424;
_sharp_pair_424,
(_sharp_pair_424 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_424).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_422;
_sharp_pair_422,
(_sharp_pair_422 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_422).car) = (Id_Form)(intern( "label_form")));
(((* _sharp_pair_422).cdr) = ({
struct struct0x0808c540 *_sharp_pair_421;
_sharp_pair_421,
(_sharp_pair_421 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_421).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_421).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_421);
})
);
((List__O__Form__C____type__type ) _sharp_pair_422);
})
));
(((* _sharp_pair_424).cdr) = ({
struct struct0x0808c540 *_sharp_pair_423;
_sharp_pair_423,
(_sharp_pair_423 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_423).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_423).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_423);
})
);
((List__O__Form__C____type__type ) _sharp_pair_424);
})
));
(((* _sharp_pair_425).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_425);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(field_name = ((* ((struct struct0x08058df0 *) ((Id_Form__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) label_form)).form_list))).head)))).value));
(subtf = ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) label_form)).form_list))).tail))).head));
(subtype = (intern_type)(subtf));
(c_output_type)(field_name, subtype);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n"), ";\n"})),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop419_continue426:((void) 0);
(_sharp_iterator418 = ((* ((struct struct0x0808c540 *) _sharp_iterator418)).cdr));
})
,
({goto _sharp__sharp_loop419_begin427;}),
((void) 0);_sharp__sharp_loop419_end420:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "};\n"), "};\n"})),
(maybe_flush)();
})
):
((((is_pointer_type)(t))?
(({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) t))).common_)).type_form)));
({if( (is_compound_form)(((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) tf)).form_list))).head)))
{
({
Compound_Form__type ptf;
(ptf = ((Compound_Form__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) tf)).form_list))).head)));
({if( (((* ((struct struct0x0805e130 *) ptf)).head) == intern( "struct")))
{
({goto end;});}})
;
})
;}})
;
(c_output_type_definition)((intern_type)(((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) tf)).form_list))).head)));
})
):
((((is_function_type)(t))?
(({
Type__type from_type;
Type__type to_type;
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) t))).common_)).type_form)));
(to_type = (intern_type)(((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) tf)).form_list))).head)));
(c_output_type_definition)(to_type);
(from_type = (intern_type)(((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) tf)).form_list))).tail))).head)));
(c_output_type_definition)(from_type);
})
):
(({if( (is_tuple_type)(t))
{
({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x0808ab48 ) ((* ((struct struct0x0808add0 *) ((Real_Type__type ) t))).common_)).type_form)));
({
List__O__Form__C____type__type _sharp_iterator429;
(_sharp_iterator429 = ((* ((struct struct0x0805e130 *) tf)).form_list));
((void) 0);_sharp__sharp_loop430_begin433:((void) 0),
({
Form__type subform;
({if( (_sharp_iterator429 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop430_end431;});}})
;
(subform = ((* ((struct struct0x0808c540 *) _sharp_iterator429)).car));
({
Type__type type;
(type = (intern_type)(subform));
(c_output_type_definition)(type);
})
;
((void) 0);_sharp__sharp_loop430_continue432:((void) 0);
(_sharp_iterator429 = ((* ((struct struct0x0808c540 *) _sharp_iterator429)).cdr));
})
,
({goto _sharp__sharp_loop430_begin433;}),
((void) 0);_sharp__sharp_loop430_end431:((void) 0);
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
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "typedef int Int__type;\n"), "typedef int Int__type;\n"})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "typedef int Bool__type;\n"), "typedef int Bool__type;\n"})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "typedef void *Type__type;\n"), "typedef void *Type__type;\n"})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "typedef void* Label__type;\n"), "typedef void* Label__type;\n"})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "typedef void Void__type;\n"), "typedef void Void__type;\n"})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "typedef struct {} * Symbol__type;\n\n"), "typedef struct {} * Symbol__type;\n\n"})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "typedef struct {unsigned int len; char *content;} * String__type;\n\n"), "typedef struct {unsigned int len; char *content;} * String__type;\n\n"})),
(maybe_flush)();
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Symbol__type intern( const char * string);\n"), "Symbol__type intern( const char * string);\n"})),
(maybe_flush)();
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Void__type print_Int_Dec( int i);\n"), "Void__type print_Int_Dec( int i);\n"})),
(maybe_flush)();
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Void__type print_String( String__type s);\n"), "Void__type print_String( String__type s);\n"})),
(maybe_flush)();
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "void maybe_flush( void);\n"), "void maybe_flush( void);\n"})),
(maybe_flush)();
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "String__type make_heap_string( char *s);\n"), "String__type make_heap_string( char *s);\n"})),
(maybe_flush)();
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "\n"), "\n"})),
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
((void) 0);_sharp__sharp_loop435_begin439:((void) 0),
({
Bool__type _sharp_tuple438;
Type__type _sharp_tuple437;
Bool__type bool;
Type__type type;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop435_end436;});}})
;
(_sharp_tuple437 = ((Type__type ) Index_)),
(_sharp_tuple438 = ((Bool__type ) (* PValue_))),
(type = _sharp_tuple437),
(bool = _sharp_tuple438);
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
({goto _sharp__sharp_loop435_begin439;}),
((void) 0);_sharp__sharp_loop435_end436:((void) 0);
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
(f = ((* ((struct struct0x0805f528 *) expf)).return_form));
(((is_compound_form)(f))?
(({
void (*fun)(Expanded_Compound_Form__type );
Compound_Form__type cf;
(cf = ((Compound_Form__type ) f));
(fun = ((void (*)(Expanded_Compound_Form__type )) (gethash)(((void *) ((* ((struct struct0x0805e130 *) cf)).head)), ((Hash_Table__type ) c_output_hash))));
({if( (fun == ((void (*)(Expanded_Compound_Form__type )) 0)))
{
({
({
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Panic : "), "Panic : "})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "No output function defined for "), "No output function defined for "})),
(print_Symbol)(((* ((struct struct0x0805e130 *) cf)).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "\n"), "\n"}));
(flush)();
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
(print_Symbol)((convert_id)(((* ((struct struct0x08058df0 *) id_form)).value)));
})
):
((((is_int_form)(f))?
(({
Int_Form__type int_form;
(int_form = ((Int_Form__type ) f));
(print_Int_Dec)(((* ((struct struct0x0805d298 *) int_form)).value));
})
):
((((is_symbol_form)(f))?
(({
Symbol_Form__type symbol_form;
(symbol_form = ((Symbol_Form__type ) f));
(print_Symbol)(intern( "intern( \"")),
(print_String)((convert_id_as_string)(((* ((struct struct0x08058df0 *) symbol_form)).value))),
(print_Symbol)(intern( "\")"));
})
):
((((is_string_form)(f))?
(({
String__type string;
String_Form__type string_form;
(string_form = ((String_Form__type ) f));
(string = (convert_string)(((* ((struct struct0x0805a538 *) string_form)).value)));
(print_Symbol)(intern( "(&(struct { unsigned int len; char *content;}){strlen( \"")),
(print_String)(string),
(print_Symbol)(intern( "\"), \"")),
(print_String)(string),
(print_Symbol)(intern( "\"})"));
})
):
(({
({
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Panic : "), "Panic : "})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "f.form_type_="), "f.form_type_="})),
(print_Int_Dec)(((* ((struct struct0x0805c940 *) ((Form__type ) f))).form_type_));
(flush)();
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
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " + (int) "), " + (int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_mul_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " * (int) "), " * (int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_sub_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " - (int) "), " - (int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_div_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " / (int) "), " / (int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_unary_minus_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(- (int) "), "(- (int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_ge_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " >= (int) "), " >= (int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_gt_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " > (int) "), " > (int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_le_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " <= (int) "), " <= (int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_lt_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " < (int) "), " < (int) "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_different(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " != "), " != "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_equal(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " == "), " == "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_access_struct(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "."), "."}));
({if( ((is_symbol_form)(((* ((struct struct0x0805f528 *) ((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head))).return_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_symbol_form"), ({
struct struct0x0808c540 *_sharp_pair_448;
_sharp_pair_448,
(_sharp_pair_448 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_448).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_447;
_sharp_pair_447,
(_sharp_pair_447 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_447).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_445;
_sharp_pair_445,
(_sharp_pair_445 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_445).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_443;
_sharp_pair_443,
(_sharp_pair_443 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_443).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_441;
_sharp_pair_441,
(_sharp_pair_441 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_441).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_441).cdr) = ({
struct struct0x0808c540 *_sharp_pair_440;
_sharp_pair_440,
(_sharp_pair_440 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_440).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_440).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_440);
})
);
((List__O__Form__C____type__type ) _sharp_pair_441);
})
));
(((* _sharp_pair_443).cdr) = ({
struct struct0x0808c540 *_sharp_pair_442;
_sharp_pair_442,
(_sharp_pair_442 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_442).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_442).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_442);
})
);
((List__O__Form__C____type__type ) _sharp_pair_443);
})
));
(((* _sharp_pair_445).cdr) = ({
struct struct0x0808c540 *_sharp_pair_444;
_sharp_pair_444,
(_sharp_pair_444 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_444).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_444).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_444);
})
);
((List__O__Form__C____type__type ) _sharp_pair_445);
})
));
(((* _sharp_pair_447).cdr) = ({
struct struct0x0808c540 *_sharp_pair_446;
_sharp_pair_446,
(_sharp_pair_446 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_446).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_446).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_446);
})
);
((List__O__Form__C____type__type ) _sharp_pair_447);
})
));
(((* _sharp_pair_448).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_448);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(print_Symbol)(((* ((struct struct0x08058df0 *) ((Symbol_Form__type ) ((* ((struct struct0x0805f528 *) ((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head))).return_form)))).value)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;
})
;}

void  c_output_assign(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("}));
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " = "), " = "}));
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;
})
;}

void  c_output_block(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "({\n"), "({\n"}));
({
List__O__Expanded_Form__C____type__type _sharp_iterator450;
(_sharp_iterator450 = ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)));
((void) 0);_sharp__sharp_loop451_begin454:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator450 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop451_end452;});}})
;
(subform = ((* ((struct struct0x08164af8 *) _sharp_iterator450)).car));
({
(c_output_form)(subform),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n"), ";\n"}));
})
;
((void) 0);_sharp__sharp_loop451_continue453:((void) 0);
(_sharp_iterator450 = ((* ((struct struct0x08164af8 *) _sharp_iterator450)).cdr));
})
,
({goto _sharp__sharp_loop451_begin454;}),
((void) 0);_sharp__sharp_loop451_end452:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "})\n"), "})\n"}));
})
;
})
;}

void  c_output_cast(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(("), "(("}));
(c_output_type)(intern( ""), (intern_type)(((* ((struct struct0x0805f528 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head))).return_form)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ") "), ") "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;
})
;}

void  c_output_deref(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(* "), "(* "})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_funcall(Expanded_Compound_Form__type  cf)
{
return ({
Expanded_Form__type function;
(function = ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head));
({if( (is_id_form)(((* ((struct struct0x0805f528 *) function)).return_form)))
{
({
((Bool__type ) (puthash)(((void *) ((* ((struct struct0x08058df0 *) ((Id_Form__type ) ((* ((struct struct0x0805f528 *) function)).return_form)))).value)), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) globals_needed)));
})
;}})
;
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(function),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")("), ")("}));
({if( (((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail) != ((List__O__Expanded_Form__C____type__type ) 0)))
{
({
(c_output_form)(((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head));
({
List__O__Expanded_Form__C____type__type _sharp_iterator456;
(_sharp_iterator456 = ((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).tail));
((void) 0);_sharp__sharp_loop457_begin460:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator456 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop457_end458;});}})
;
(subform = ((* ((struct struct0x08164af8 *) _sharp_iterator456)).car));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(c_output_form)(subform);
((void) 0);_sharp__sharp_loop457_continue459:((void) 0);
(_sharp_iterator456 = ((* ((struct struct0x08164af8 *) _sharp_iterator456)).cdr));
})
,
({goto _sharp__sharp_loop457_begin460;}),
((void) 0);_sharp__sharp_loop457_end458:((void) 0);
})
;
})
;}})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;
})
;}

void  c_output_if(Expanded_Compound_Form__type  cf)
{
return ({
Expanded_Form__type then;
Expanded_Form__type condition;
(condition = ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head));
(then = ((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head));
({
(((((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)))?
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "({if( "), "({if( "})),
(c_output_form)(condition),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")\n{\n"), ")\n{\n"})),
(c_output_form)(then),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";}})\n"), ";}})\n"}));
})
):
(({
Expanded_Form__type elsef;
(elsef = ((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).tail))).head));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(("), "(("})),
(c_output_form)(condition),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")?\n("), ")?\n("})),
(c_output_form)(then),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "):\n("), "):\n("})),
(c_output_form)(elsef),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "))"), "))"}));
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
({if( ((((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_469;
_sharp_pair_469,
(_sharp_pair_469 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_469).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_464;
_sharp_pair_464,
(_sharp_pair_464 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_464).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_462;
_sharp_pair_462,
(_sharp_pair_462 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_462).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_462).cdr) = ({
struct struct0x0808c540 *_sharp_pair_461;
_sharp_pair_461,
(_sharp_pair_461 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_461).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_461).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_461);
})
);
((List__O__Form__C____type__type ) _sharp_pair_462);
})
));
(((* _sharp_pair_464).cdr) = ({
struct struct0x0808c540 *_sharp_pair_463;
_sharp_pair_463,
(_sharp_pair_463 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_463).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_463).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_463);
})
);
((List__O__Form__C____type__type ) _sharp_pair_464);
})
));
(((* _sharp_pair_469).cdr) = ({
struct struct0x0808c540 *_sharp_pair_468;
_sharp_pair_468,
(_sharp_pair_468 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_468).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_467;
_sharp_pair_467,
(_sharp_pair_467 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_467).car) = (Compound_Form)(intern( "List"), ({
struct struct0x0808c540 *_sharp_pair_465;
_sharp_pair_465,
(_sharp_pair_465 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_465).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_465).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_465);
})
));
(((* _sharp_pair_467).cdr) = ({
struct struct0x0808c540 *_sharp_pair_466;
_sharp_pair_466,
(_sharp_pair_466 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_466).car) = (Int_Form)(0));
(((* _sharp_pair_466).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_466);
})
);
((List__O__Form__C____type__type ) _sharp_pair_467);
})
));
(((* _sharp_pair_468).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_468);
})
);
((List__O__Form__C____type__type ) _sharp_pair_469);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x0808c540 *_sharp_pair_476;
_sharp_pair_476,
(_sharp_pair_476 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_476).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_475;
_sharp_pair_475,
(_sharp_pair_475 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_475).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_475).cdr) = ({
struct struct0x0808c540 *_sharp_pair_474;
_sharp_pair_474,
(_sharp_pair_474 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_474).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_473;
_sharp_pair_473,
(_sharp_pair_473 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_473).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_471;
_sharp_pair_471,
(_sharp_pair_471 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_471).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_471).cdr) = ({
struct struct0x0808c540 *_sharp_pair_470;
_sharp_pair_470,
(_sharp_pair_470 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_470).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_470).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_470);
})
);
((List__O__Form__C____type__type ) _sharp_pair_471);
})
));
(((* _sharp_pair_473).cdr) = ({
struct struct0x0808c540 *_sharp_pair_472;
_sharp_pair_472,
(_sharp_pair_472 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_472).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_472).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_472);
})
);
((List__O__Form__C____type__type ) _sharp_pair_473);
})
));
(((* _sharp_pair_474).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_474);
})
);
((List__O__Form__C____type__type ) _sharp_pair_475);
})
));
(((* _sharp_pair_476).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_476);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(label_form = ((Id_Form__type ) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "&&"), "&&"})),
(print_Symbol)((convert_id)(((* ((struct struct0x08058df0 *) label_form)).value)));
})
;}

void  c_output_goto_constant(Expanded_Compound_Form__type  cf)
{
return ({
Id_Form__type id_form;
({if( ((((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_485;
_sharp_pair_485,
(_sharp_pair_485 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_485).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_480;
_sharp_pair_480,
(_sharp_pair_480 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_480).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_478;
_sharp_pair_478,
(_sharp_pair_478 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_478).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_478).cdr) = ({
struct struct0x0808c540 *_sharp_pair_477;
_sharp_pair_477,
(_sharp_pair_477 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_477).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_477).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_477);
})
);
((List__O__Form__C____type__type ) _sharp_pair_478);
})
));
(((* _sharp_pair_480).cdr) = ({
struct struct0x0808c540 *_sharp_pair_479;
_sharp_pair_479,
(_sharp_pair_479 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_479).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_479).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_479);
})
);
((List__O__Form__C____type__type ) _sharp_pair_480);
})
));
(((* _sharp_pair_485).cdr) = ({
struct struct0x0808c540 *_sharp_pair_484;
_sharp_pair_484,
(_sharp_pair_484 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_484).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_483;
_sharp_pair_483,
(_sharp_pair_483 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_483).car) = (Compound_Form)(intern( "List"), ({
struct struct0x0808c540 *_sharp_pair_481;
_sharp_pair_481,
(_sharp_pair_481 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_481).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_481).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_481);
})
));
(((* _sharp_pair_483).cdr) = ({
struct struct0x0808c540 *_sharp_pair_482;
_sharp_pair_482,
(_sharp_pair_482 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_482).car) = (Int_Form)(0));
(((* _sharp_pair_482).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_482);
})
);
((List__O__Form__C____type__type ) _sharp_pair_483);
})
));
(((* _sharp_pair_484).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_484);
})
);
((List__O__Form__C____type__type ) _sharp_pair_485);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(id_form = ((Id_Form__type ) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)));
({if( ((is_id_form)(((Form__type ) id_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x0808c540 *_sharp_pair_488;
_sharp_pair_488,
(_sharp_pair_488 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_488).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_487;
_sharp_pair_487,
(_sharp_pair_487 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_487).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_487).cdr) = ({
struct struct0x0808c540 *_sharp_pair_486;
_sharp_pair_486,
(_sharp_pair_486 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_486).car) = (Id_Form)(intern( "id_form")));
(((* _sharp_pair_486).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_486);
})
);
((List__O__Form__C____type__type ) _sharp_pair_487);
})
));
(((* _sharp_pair_488).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_488);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "({goto "), "({goto "})),
(print_Symbol)((convert_id)(((* ((struct struct0x08058df0 *) id_form)).value))),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";})"), ";})"}));
})
;}

void  c_output_goto_variable(Expanded_Compound_Form__type  cf)
{
return ({
({if( ((((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_497;
_sharp_pair_497,
(_sharp_pair_497 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_497).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_492;
_sharp_pair_492,
(_sharp_pair_492 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_492).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_490;
_sharp_pair_490,
(_sharp_pair_490 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_490).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_490).cdr) = ({
struct struct0x0808c540 *_sharp_pair_489;
_sharp_pair_489,
(_sharp_pair_489 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_489).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_489).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_489);
})
);
((List__O__Form__C____type__type ) _sharp_pair_490);
})
));
(((* _sharp_pair_492).cdr) = ({
struct struct0x0808c540 *_sharp_pair_491;
_sharp_pair_491,
(_sharp_pair_491 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_491).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_491).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_491);
})
);
((List__O__Form__C____type__type ) _sharp_pair_492);
})
));
(((* _sharp_pair_497).cdr) = ({
struct struct0x0808c540 *_sharp_pair_496;
_sharp_pair_496,
(_sharp_pair_496 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_496).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_495;
_sharp_pair_495,
(_sharp_pair_495 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_495).car) = (Compound_Form)(intern( "List"), ({
struct struct0x0808c540 *_sharp_pair_493;
_sharp_pair_493,
(_sharp_pair_493 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_493).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_493).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_493);
})
));
(((* _sharp_pair_495).cdr) = ({
struct struct0x0808c540 *_sharp_pair_494;
_sharp_pair_494,
(_sharp_pair_494 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_494).car) = (Int_Form)(0));
(((* _sharp_pair_494).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_494);
})
);
((List__O__Form__C____type__type ) _sharp_pair_495);
})
));
(((* _sharp_pair_496).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_496);
})
);
((List__O__Form__C____type__type ) _sharp_pair_497);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
({if( ((is_compound_form)(((* ((struct struct0x0805f528 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head))).return_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x0808c540 *_sharp_pair_504;
_sharp_pair_504,
(_sharp_pair_504 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_504).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_503;
_sharp_pair_503,
(_sharp_pair_503 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_503).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_501;
_sharp_pair_501,
(_sharp_pair_501 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_501).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_499;
_sharp_pair_499,
(_sharp_pair_499 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_499).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_499).cdr) = ({
struct struct0x0808c540 *_sharp_pair_498;
_sharp_pair_498,
(_sharp_pair_498 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_498).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_498).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_498);
})
);
((List__O__Form__C____type__type ) _sharp_pair_499);
})
));
(((* _sharp_pair_501).cdr) = ({
struct struct0x0808c540 *_sharp_pair_500;
_sharp_pair_500,
(_sharp_pair_500 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_500).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_500).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_500);
})
);
((List__O__Form__C____type__type ) _sharp_pair_501);
})
));
(((* _sharp_pair_503).cdr) = ({
struct struct0x0808c540 *_sharp_pair_502;
_sharp_pair_502,
(_sharp_pair_502 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_502).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_502).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_502);
})
);
((List__O__Form__C____type__type ) _sharp_pair_503);
})
));
(((* _sharp_pair_504).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_504);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
({if( ((((* ((struct struct0x0805e130 *) ((Compound_Form__type ) ((* ((struct struct0x0805f528 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head))).return_form)))).head) == intern( "deref")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_516;
_sharp_pair_516,
(_sharp_pair_516 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_516).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_514;
_sharp_pair_514,
(_sharp_pair_514 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_514).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_512;
_sharp_pair_512,
(_sharp_pair_512 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_512).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_512).cdr) = ({
struct struct0x0808c540 *_sharp_pair_511;
_sharp_pair_511,
(_sharp_pair_511 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_511).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_510;
_sharp_pair_510,
(_sharp_pair_510 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_510).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_508;
_sharp_pair_508,
(_sharp_pair_508 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_508).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_506;
_sharp_pair_506,
(_sharp_pair_506 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_506).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_506).cdr) = ({
struct struct0x0808c540 *_sharp_pair_505;
_sharp_pair_505,
(_sharp_pair_505 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_505).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_505).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_505);
})
);
((List__O__Form__C____type__type ) _sharp_pair_506);
})
));
(((* _sharp_pair_508).cdr) = ({
struct struct0x0808c540 *_sharp_pair_507;
_sharp_pair_507,
(_sharp_pair_507 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_507).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_507).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_507);
})
);
((List__O__Form__C____type__type ) _sharp_pair_508);
})
));
(((* _sharp_pair_510).cdr) = ({
struct struct0x0808c540 *_sharp_pair_509;
_sharp_pair_509,
(_sharp_pair_509 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_509).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_509).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_509);
})
);
((List__O__Form__C____type__type ) _sharp_pair_510);
})
));
(((* _sharp_pair_511).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_511);
})
);
((List__O__Form__C____type__type ) _sharp_pair_512);
})
));
(((* _sharp_pair_514).cdr) = ({
struct struct0x0808c540 *_sharp_pair_513;
_sharp_pair_513,
(_sharp_pair_513 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_513).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_513).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_513);
})
);
((List__O__Form__C____type__type ) _sharp_pair_514);
})
));
(((* _sharp_pair_516).cdr) = ({
struct struct0x0808c540 *_sharp_pair_515;
_sharp_pair_515,
(_sharp_pair_515 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_515).car) = (Symbol_Form)(intern( "deref")));
(((* _sharp_pair_515).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_515);
})
);
((List__O__Form__C____type__type ) _sharp_pair_516);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "({goto *"), "({goto *"})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) ((Expanded_Compound_Form__type ) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)))).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";})"), ";})"})),
(maybe_flush)();
})
;}

void  c_output_label(Expanded_Compound_Form__type  cf)
{
return ({
Id_Form__type label_form;
({if( ((((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_525;
_sharp_pair_525,
(_sharp_pair_525 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_525).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_520;
_sharp_pair_520,
(_sharp_pair_520 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_520).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_518;
_sharp_pair_518,
(_sharp_pair_518 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_518).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_518).cdr) = ({
struct struct0x0808c540 *_sharp_pair_517;
_sharp_pair_517,
(_sharp_pair_517 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_517).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_517).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_517);
})
);
((List__O__Form__C____type__type ) _sharp_pair_518);
})
));
(((* _sharp_pair_520).cdr) = ({
struct struct0x0808c540 *_sharp_pair_519;
_sharp_pair_519,
(_sharp_pair_519 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_519).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_519).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_519);
})
);
((List__O__Form__C____type__type ) _sharp_pair_520);
})
));
(((* _sharp_pair_525).cdr) = ({
struct struct0x0808c540 *_sharp_pair_524;
_sharp_pair_524,
(_sharp_pair_524 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_524).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_523;
_sharp_pair_523,
(_sharp_pair_523 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_523).car) = (Compound_Form)(intern( "List"), ({
struct struct0x0808c540 *_sharp_pair_521;
_sharp_pair_521,
(_sharp_pair_521 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_521).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_521).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_521);
})
));
(((* _sharp_pair_523).cdr) = ({
struct struct0x0808c540 *_sharp_pair_522;
_sharp_pair_522,
(_sharp_pair_522 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_522).car) = (Int_Form)(0));
(((* _sharp_pair_522).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_522);
})
);
((List__O__Form__C____type__type ) _sharp_pair_523);
})
));
(((* _sharp_pair_524).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_524);
})
);
((List__O__Form__C____type__type ) _sharp_pair_525);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x0808c540 *_sharp_pair_532;
_sharp_pair_532,
(_sharp_pair_532 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_532).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_531;
_sharp_pair_531,
(_sharp_pair_531 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_531).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_531).cdr) = ({
struct struct0x0808c540 *_sharp_pair_530;
_sharp_pair_530,
(_sharp_pair_530 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_530).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_529;
_sharp_pair_529,
(_sharp_pair_529 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_529).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_527;
_sharp_pair_527,
(_sharp_pair_527 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_527).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_527).cdr) = ({
struct struct0x0808c540 *_sharp_pair_526;
_sharp_pair_526,
(_sharp_pair_526 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_526).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_526).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_526);
})
);
((List__O__Form__C____type__type ) _sharp_pair_527);
})
));
(((* _sharp_pair_529).cdr) = ({
struct struct0x0808c540 *_sharp_pair_528;
_sharp_pair_528,
(_sharp_pair_528 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_528).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_528).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_528);
})
);
((List__O__Form__C____type__type ) _sharp_pair_529);
})
));
(((* _sharp_pair_530).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_530);
})
);
((List__O__Form__C____type__type ) _sharp_pair_531);
})
));
(((* _sharp_pair_532).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_532);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(label_form = ((Id_Form__type ) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((void) 0);"), "((void) 0);"})),
(print_Symbol)((convert_id)(((* ((struct struct0x08058df0 *) label_form)).value))),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ":((void) 0)"), ":((void) 0)"}));
})
;}

void  c_output_let(Expanded_Compound_Form__type  cf)
{
return ({
({
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x0808c540 *_sharp_pair_539;
_sharp_pair_539,
(_sharp_pair_539 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_539).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_538;
_sharp_pair_538,
(_sharp_pair_538 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_538).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_538).cdr) = ({
struct struct0x0808c540 *_sharp_pair_537;
_sharp_pair_537,
(_sharp_pair_537 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_537).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_536;
_sharp_pair_536,
(_sharp_pair_536 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_536).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_534;
_sharp_pair_534,
(_sharp_pair_534 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_534).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_534).cdr) = ({
struct struct0x0808c540 *_sharp_pair_533;
_sharp_pair_533,
(_sharp_pair_533 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_533).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_533).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_533);
})
);
((List__O__Form__C____type__type ) _sharp_pair_534);
})
));
(((* _sharp_pair_536).cdr) = ({
struct struct0x0808c540 *_sharp_pair_535;
_sharp_pair_535,
(_sharp_pair_535 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_535).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_535).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_535);
})
);
((List__O__Form__C____type__type ) _sharp_pair_536);
})
));
(((* _sharp_pair_537).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_537);
})
);
((List__O__Form__C____type__type ) _sharp_pair_538);
})
));
(((* _sharp_pair_539).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_539);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(c_output_type)((convert_id)(((* ((struct struct0x08058df0 *) ((Id_Form__type ) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)))).value)), (intern_type)(((Form__type ) ((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail))).head))));
})
;
})
;}

void  c_output_ref(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(&"), "(&"})),
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;
})
;}

void  c_output_seq(Expanded_Compound_Form__type  cf)
{
return ({
({
({if( ((((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)) != ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x0808c540 *_sharp_pair_546;
_sharp_pair_546,
(_sharp_pair_546 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_546).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_541;
_sharp_pair_541,
(_sharp_pair_541 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_541).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_541).cdr) = ({
struct struct0x0808c540 *_sharp_pair_540;
_sharp_pair_540,
(_sharp_pair_540 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_540).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_540).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_540);
})
);
((List__O__Form__C____type__type ) _sharp_pair_541);
})
));
(((* _sharp_pair_546).cdr) = ({
struct struct0x0808c540 *_sharp_pair_545;
_sharp_pair_545,
(_sharp_pair_545 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_545).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_544;
_sharp_pair_544,
(_sharp_pair_544 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_544).car) = (Compound_Form)(intern( "List"), ({
struct struct0x0808c540 *_sharp_pair_542;
_sharp_pair_542,
(_sharp_pair_542 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_542).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_542).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_542);
})
));
(((* _sharp_pair_544).cdr) = ({
struct struct0x0808c540 *_sharp_pair_543;
_sharp_pair_543,
(_sharp_pair_543 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_543).car) = (Int_Form)(0));
(((* _sharp_pair_543).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_543);
})
);
((List__O__Form__C____type__type ) _sharp_pair_544);
})
));
(((* _sharp_pair_545).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_545);
})
);
((List__O__Form__C____type__type ) _sharp_pair_546);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(c_output_form)(((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head));
({
List__O__Expanded_Form__C____type__type _sharp_iterator548;
(_sharp_iterator548 = ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail));
((void) 0);_sharp__sharp_loop549_begin552:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator548 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop549_end550;});}})
;
(subform = ((* ((struct struct0x08164af8 *) _sharp_iterator548)).car));
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ",\n"), ",\n"})),
(c_output_form)(subform);
})
;
((void) 0);_sharp__sharp_loop549_continue551:((void) 0);
(_sharp_iterator548 = ((* ((struct struct0x08164af8 *) _sharp_iterator548)).cdr));
})
,
({goto _sharp__sharp_loop549_begin552;}),
((void) 0);_sharp__sharp_loop549_end550:((void) 0);
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
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(("), "(("}));
(c_output_type)(intern( ""), ((* ((struct struct0x0808a8b8 *) cf)).type));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "){"), "){"}));
({
Expanded_Form__type form_subform;
Expanded_Form__type subform_;
(subform_ = ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).head));
({if( ((is_compound_form)(((* ((struct struct0x0805f528 *) subform_)).return_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x0808c540 *_sharp_pair_555;
_sharp_pair_555,
(_sharp_pair_555 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_555).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_554;
_sharp_pair_554,
(_sharp_pair_554 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_554).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_554).cdr) = ({
struct struct0x0808c540 *_sharp_pair_553;
_sharp_pair_553,
(_sharp_pair_553 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_553).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_553).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_553);
})
);
((List__O__Form__C____type__type ) _sharp_pair_554);
})
));
(((* _sharp_pair_555).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_555);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
({if( ((((* ((struct struct0x0805e130 *) ((Compound_Form__type ) ((* ((struct struct0x0805f528 *) subform_)).return_form)))).head) == intern( "label")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_563;
_sharp_pair_563,
(_sharp_pair_563 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_563).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_561;
_sharp_pair_561,
(_sharp_pair_561 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_561).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_559;
_sharp_pair_559,
(_sharp_pair_559 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_559).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_559).cdr) = ({
struct struct0x0808c540 *_sharp_pair_558;
_sharp_pair_558,
(_sharp_pair_558 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_558).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_557;
_sharp_pair_557,
(_sharp_pair_557 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_557).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_557).cdr) = ({
struct struct0x0808c540 *_sharp_pair_556;
_sharp_pair_556,
(_sharp_pair_556 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_556).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_556).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_556);
})
);
((List__O__Form__C____type__type ) _sharp_pair_557);
})
));
(((* _sharp_pair_558).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_558);
})
);
((List__O__Form__C____type__type ) _sharp_pair_559);
})
));
(((* _sharp_pair_561).cdr) = ({
struct struct0x0808c540 *_sharp_pair_560;
_sharp_pair_560,
(_sharp_pair_560 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_560).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_560).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_560);
})
);
((List__O__Form__C____type__type ) _sharp_pair_561);
})
));
(((* _sharp_pair_563).cdr) = ({
struct struct0x0808c540 *_sharp_pair_562;
_sharp_pair_562,
(_sharp_pair_562 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_562).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_562).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_562);
})
);
((List__O__Form__C____type__type ) _sharp_pair_563);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(form_subform = ((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) ((Expanded_Compound_Form__type ) subform_))).return_form_))).form_list)))).tail))).head));
(c_output_form)(form_subform);
})
;
({
List__O__Expanded_Form__C____type__type _sharp_iterator565;
(_sharp_iterator565 = ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)))).tail));
((void) 0);_sharp__sharp_loop566_begin580:((void) 0),
({
Expanded_Form__type subform_;
({if( (_sharp_iterator565 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop566_end567;});}})
;
(subform_ = ((* ((struct struct0x08164af8 *) _sharp_iterator565)).car));
({
Expanded_Form__type form_subform;
({if( ((is_compound_form)(((* ((struct struct0x0805f528 *) subform_)).return_form)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x0808c540 *_sharp_pair_570;
_sharp_pair_570,
(_sharp_pair_570 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_570).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_569;
_sharp_pair_569,
(_sharp_pair_569 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_569).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_569).cdr) = ({
struct struct0x0808c540 *_sharp_pair_568;
_sharp_pair_568,
(_sharp_pair_568 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_568).car) = (Symbol_Form)(intern( "return_form")));
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
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
({if( ((((* ((struct struct0x0805e130 *) ((Compound_Form__type ) ((* ((struct struct0x0805f528 *) subform_)).return_form)))).head) == intern( "label")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_578;
_sharp_pair_578,
(_sharp_pair_578 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_578).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_576;
_sharp_pair_576,
(_sharp_pair_576 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_576).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_574;
_sharp_pair_574,
(_sharp_pair_574 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_574).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_574).cdr) = ({
struct struct0x0808c540 *_sharp_pair_573;
_sharp_pair_573,
(_sharp_pair_573 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_573).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_572;
_sharp_pair_572,
(_sharp_pair_572 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_572).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_572).cdr) = ({
struct struct0x0808c540 *_sharp_pair_571;
_sharp_pair_571,
(_sharp_pair_571 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_571).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_571).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_571);
})
);
((List__O__Form__C____type__type ) _sharp_pair_572);
})
));
(((* _sharp_pair_573).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_573);
})
);
((List__O__Form__C____type__type ) _sharp_pair_574);
})
));
(((* _sharp_pair_576).cdr) = ({
struct struct0x0808c540 *_sharp_pair_575;
_sharp_pair_575,
(_sharp_pair_575 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_575).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_575).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_575);
})
);
((List__O__Form__C____type__type ) _sharp_pair_576);
})
));
(((* _sharp_pair_578).cdr) = ({
struct struct0x0808c540 *_sharp_pair_577;
_sharp_pair_577,
(_sharp_pair_577 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_577).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_577).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_577);
})
);
((List__O__Form__C____type__type ) _sharp_pair_578);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"}));
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(form_subform = ((* ((struct struct0x0814abd8 *) ((* ((struct struct0x0814abd8 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) ((Expanded_Compound_Form__type ) subform_))).return_form_))).form_list)))).tail))).head));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(c_output_form)(form_subform);
})
;
((void) 0);_sharp__sharp_loop566_continue579:((void) 0);
(_sharp_iterator565 = ((* ((struct struct0x08164af8 *) _sharp_iterator565)).cdr));
})
,
({goto _sharp__sharp_loop566_begin580;}),
((void) 0);_sharp__sharp_loop566_end567:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "})"), "})"}));
})
;
})
;}

void  c_output_tuple(Expanded_Compound_Form__type  cf)
{
return ({
(((((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((* ((struct struct0x0808a8b8 *) cf)).return_form_))).form_list)) == ((List__O__Expanded_Form__C____type__type ) 0)))?
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((void) 0)"), "((void) 0)"})),
(maybe_flush)();
})
):
(({
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Panic : "), "Panic : "})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Unimplemented\n"), "Unimplemented\n"})),
(maybe_flush)();
(flush)();
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
({if( ((is_expanded_form)(l_) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_expanded_form"), ({
struct struct0x0808c540 *_sharp_pair_581;
_sharp_pair_581,
(_sharp_pair_581 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_581).car) = (Id_Form)(intern( "l_")));
(((* _sharp_pair_581).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_581);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(l = ((* ((struct struct0x0805f528 *) ((Expanded_Form__type ) l_))).return_form));
({if( ((is_compound_form)(l) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x0808c540 *_sharp_pair_582;
_sharp_pair_582,
(_sharp_pair_582 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_582).car) = (Id_Form)(intern( "l")));
(((* _sharp_pair_582).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_582);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
({if( ((((* ((struct struct0x0805e130 *) ((Compound_Form__type ) l))).head) == intern( "lambda")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_588;
_sharp_pair_588,
(_sharp_pair_588 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_588).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_586;
_sharp_pair_586,
(_sharp_pair_586 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_586).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_584;
_sharp_pair_584,
(_sharp_pair_584 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_584).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_584).cdr) = ({
struct struct0x0808c540 *_sharp_pair_583;
_sharp_pair_583,
(_sharp_pair_583 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_583).car) = (Id_Form)(intern( "l")));
(((* _sharp_pair_583).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_583);
})
);
((List__O__Form__C____type__type ) _sharp_pair_584);
})
));
(((* _sharp_pair_586).cdr) = ({
struct struct0x0808c540 *_sharp_pair_585;
_sharp_pair_585,
(_sharp_pair_585 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_585).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_585).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_585);
})
);
((List__O__Form__C____type__type ) _sharp_pair_586);
})
));
(((* _sharp_pair_588).cdr) = ({
struct struct0x0808c540 *_sharp_pair_587;
_sharp_pair_587,
(_sharp_pair_587 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_587).car) = (Symbol_Form)(intern( "lambda")));
(((* _sharp_pair_587).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_587);
})
);
((List__O__Form__C____type__type ) _sharp_pair_588);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(form_list = ((List__O__Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((Compound_Form__type ) l))).form_list)));
(return_type = ((* ((struct struct0x08059148 *) form_list)).head));
(c_output_type)(intern( ""), (intern_type)(return_type));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " "), " "})),
(print_Symbol)(name),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(maybe_flush)();
(parameters_type = ((Compound_Form__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) form_list)).tail))).head)));
({if( ((((* ((struct struct0x0805e130 *) parameters_type)).head) == intern( "tuple")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_592;
_sharp_pair_592,
(_sharp_pair_592 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_592).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_590;
_sharp_pair_590,
(_sharp_pair_590 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_590).car) = (Id_Form)(intern( "parameters_type")));
(((* _sharp_pair_590).cdr) = ({
struct struct0x0808c540 *_sharp_pair_589;
_sharp_pair_589,
(_sharp_pair_589 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_589).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_589).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_589);
})
);
((List__O__Form__C____type__type ) _sharp_pair_590);
})
));
(((* _sharp_pair_592).cdr) = ({
struct struct0x0808c540 *_sharp_pair_591;
_sharp_pair_591,
(_sharp_pair_591 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_591).car) = (Symbol_Form)(intern( "tuple")));
(((* _sharp_pair_591).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_591);
})
);
((List__O__Form__C____type__type ) _sharp_pair_592);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(((((* ((struct struct0x0805e130 *) parameters_type)).form_list) == ((List__O__Form__C____type__type ) 0)))?
((print_String)((&(struct { unsigned int len; char *content;}){strlen( "void"), "void"})),
(maybe_flush)()):
(({
Id_Form__type first_param_name;
Form__type first_param_type;
Compound_Form__type first_parameter;
(first_parameter = ((Compound_Form__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) parameters_type)).form_list))).head)));
({if( ((((* ((struct struct0x0805e130 *) first_parameter)).head) == intern( "label")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_596;
_sharp_pair_596,
(_sharp_pair_596 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_596).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_594;
_sharp_pair_594,
(_sharp_pair_594 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_594).car) = (Id_Form)(intern( "first_parameter")));
(((* _sharp_pair_594).cdr) = ({
struct struct0x0808c540 *_sharp_pair_593;
_sharp_pair_593,
(_sharp_pair_593 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_593).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_593).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_593);
})
);
((List__O__Form__C____type__type ) _sharp_pair_594);
})
));
(((* _sharp_pair_596).cdr) = ({
struct struct0x0808c540 *_sharp_pair_595;
_sharp_pair_595,
(_sharp_pair_595 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_595).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_595).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_595);
})
);
((List__O__Form__C____type__type ) _sharp_pair_596);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(first_param_name = ((Id_Form__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) first_parameter)).form_list))).head)));
(first_param_type = ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) first_parameter)).form_list))).tail))).head));
(c_output_type)(intern( ""), (intern_type)(((Form__type ) first_param_type)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " "), " "})),
(print_Symbol)(((* ((struct struct0x08058df0 *) first_param_name)).value)),
(maybe_flush)();
({
List__O__Compound_Form__C____type__type _sharp_iterator598;
(_sharp_iterator598 = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) parameters_type)).form_list))).tail)));
((void) 0);_sharp__sharp_loop599_begin606:((void) 0),
({
Compound_Form__type parameter;
({if( (_sharp_iterator598 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop599_end600;});}})
;
(parameter = ((* ((struct struct0x082064f8 *) _sharp_iterator598)).car));
({
Id_Form__type param_name;
Form__type type;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(maybe_flush)();
({if( ((((* ((struct struct0x0805e130 *) first_parameter)).head) == intern( "label")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_604;
_sharp_pair_604,
(_sharp_pair_604 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_604).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_602;
_sharp_pair_602,
(_sharp_pair_602 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_602).car) = (Id_Form)(intern( "first_parameter")));
(((* _sharp_pair_602).cdr) = ({
struct struct0x0808c540 *_sharp_pair_601;
_sharp_pair_601,
(_sharp_pair_601 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_601).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_601).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_601);
})
);
((List__O__Form__C____type__type ) _sharp_pair_602);
})
));
(((* _sharp_pair_604).cdr) = ({
struct struct0x0808c540 *_sharp_pair_603;
_sharp_pair_603,
(_sharp_pair_603 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_603).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_603).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_603);
})
);
((List__O__Form__C____type__type ) _sharp_pair_604);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(param_name = ((Id_Form__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) parameter)).form_list))).head)));
(type = ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) ((* ((struct struct0x0805e130 *) parameter)).form_list))).tail))).head));
(c_output_type)(intern( ""), (intern_type)(((Form__type ) type)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " "), " "})),
(print_Symbol)(((* ((struct struct0x08058df0 *) param_name)).value)),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop599_continue605:((void) 0);
(_sharp_iterator598 = ((* ((struct struct0x082064f8 *) _sharp_iterator598)).cdr));
})
,
({goto _sharp__sharp_loop599_begin606;}),
((void) 0);_sharp__sharp_loop599_end600:((void) 0);
})
;
})
));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")\n{\nreturn "), ")\n{\nreturn "})),
(maybe_flush)();
(c_output_form)(((Expanded_Form__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) form_list)).tail))).tail))).head))),
(maybe_flush)();
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";}\n\n"), ";}\n\n"})),
(maybe_flush)();
})
;}

void  c_output_global_definition(Symbol__type  name, Form__type  form_type)
{
return ({
(c_output_type)(name, (intern_type)(form_type));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n\n"), ";\n\n"})),
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
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x0808c540 *_sharp_pair_609;
_sharp_pair_609,
(_sharp_pair_609 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_609).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0808c540 *_sharp_pair_608;
_sharp_pair_608,
(_sharp_pair_608 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_608).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_608).cdr) = ({
struct struct0x0808c540 *_sharp_pair_607;
_sharp_pair_607,
(_sharp_pair_607 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_607).car) = (Id_Form)(intern( "f")));
(((* _sharp_pair_607).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_607);
})
);
((List__O__Form__C____type__type ) _sharp_pair_608);
})
));
(((* _sharp_pair_609).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_609);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
({if( ((((* ((struct struct0x0805e130 *) f)).head) == intern( "define")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0808c540 *_sharp_pair_613;
_sharp_pair_613,
(_sharp_pair_613 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_613).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_611;
_sharp_pair_611,
(_sharp_pair_611 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_611).car) = (Id_Form)(intern( "f")));
(((* _sharp_pair_611).cdr) = ({
struct struct0x0808c540 *_sharp_pair_610;
_sharp_pair_610,
(_sharp_pair_610 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_610).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_610).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_610);
})
);
((List__O__Form__C____type__type ) _sharp_pair_611);
})
));
(((* _sharp_pair_613).cdr) = ({
struct struct0x0808c540 *_sharp_pair_612;
_sharp_pair_612,
(_sharp_pair_612 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_612).car) = (Symbol_Form)(intern( "define")));
(((* _sharp_pair_612).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_612);
})
);
((List__O__Form__C____type__type ) _sharp_pair_613);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(form_list = ((List__O__Form__C____type__type ) ((* ((struct struct0x0805e130 *) ((Compound_Form__type ) f))).form_list)));
({if( ((is_id_form)(((* ((struct struct0x08059148 *) form_list)).head)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x0808c540 *_sharp_pair_616;
_sharp_pair_616,
(_sharp_pair_616 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_616).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_615;
_sharp_pair_615,
(_sharp_pair_615 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_615).car) = (Id_Form)(intern( "form_list")));
(((* _sharp_pair_615).cdr) = ({
struct struct0x0808c540 *_sharp_pair_614;
_sharp_pair_614,
(_sharp_pair_614 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_614).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_614).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_614);
})
);
((List__O__Form__C____type__type ) _sharp_pair_615);
})
));
(((* _sharp_pair_616).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_616);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(species = ((* ((struct struct0x08058df0 *) ((Id_Form__type ) ((* ((struct struct0x08059148 *) form_list)).head)))).value));
({if( ((is_id_form)(((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) form_list)).tail))).head)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x0808c540 *_sharp_pair_621;
_sharp_pair_621,
(_sharp_pair_621 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_621).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_620;
_sharp_pair_620,
(_sharp_pair_620 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_620).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0808c540 *_sharp_pair_618;
_sharp_pair_618,
(_sharp_pair_618 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_618).car) = (Id_Form)(intern( "form_list")));
(((* _sharp_pair_618).cdr) = ({
struct struct0x0808c540 *_sharp_pair_617;
_sharp_pair_617,
(_sharp_pair_617 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_617).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_617).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_617);
})
);
((List__O__Form__C____type__type ) _sharp_pair_618);
})
));
(((* _sharp_pair_620).cdr) = ({
struct struct0x0808c540 *_sharp_pair_619;
_sharp_pair_619,
(_sharp_pair_619 = ((struct struct0x0808c540 *) (alloc_cons_cell)()));
(((* _sharp_pair_619).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_619).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_619);
})
);
((List__O__Form__C____type__type ) _sharp_pair_620);
})
));
(((* _sharp_pair_621).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_621);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
(exit)(3);
})
;}})
;
(name = ((* ((struct struct0x08058df0 *) ((Id_Form__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) form_list)).tail))).head)))).value));
(((species == intern( "function")))?
(({
(c_output_function_definition)(name, ((Form__type ) ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) form_list)).tail))).tail))).head)));
})
):
((((species == intern( "type")))?
(({
((void) 0);
})
):
((((species == intern( "global")))?
(({
(c_output_global_definition)(name, ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) ((* ((struct struct0x08059148 *) form_list)).tail))).tail))).head));
((void) 0);
})
):
((((species == intern( "expander")))?
(({
((void) 0);
})
):
((((species == intern( "attribute")))?
(({
((void) 0);
})
):
(({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Species '"), "Species '"})),
(print_Symbol)(species),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "'\n"), "'\n"})),
(maybe_flush)();
(flush)();
(current_output_descriptor = save_od_);
})
;
({
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Panic : "), "Panic : "})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Not implemented\n"), "Not implemented\n"})),
(maybe_flush)();
(flush)();
(exit)(3);
})
;
})
))))))))));
})
;}

void  doit(String__type  l_file, String__type  out_c_file, String__type  out_inc_file)
{
return ({
List__O__Compound_Form__C____type__type form_list;
(globals_needed = ((Hash__O__Symbol__c__Bool__C____type__type ) (make_hash_table)()));
(reinit_types)();
(stdout_descriptor = current_output_descriptor);
(output_file_descriptor = (make_output_descriptor_write_file)(out_c_file));
(inc_file_descriptor = (make_output_descriptor_write_file)(out_inc_file));
(form_list = (expanded_form_list_from_file_name)(l_file));
(current_output_descriptor = output_file_descriptor);
(print_Symbol)(intern( "#include \"")),
(print_String)((file_name_non_directory)(out_inc_file)),
(print_Symbol)(intern( "\"")),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "\n"), "\n"})),
(maybe_flush)();
({
List__O__Compound_Form__C____type__type _sharp_iterator623;
(_sharp_iterator623 = form_list);
((void) 0);_sharp__sharp_loop624_begin627:((void) 0),
({
Compound_Form__type f;
({if( (_sharp_iterator623 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop624_end625;});}})
;
(f = ((* ((struct struct0x082064f8 *) _sharp_iterator623)).car));
(c_output_definition)(f);
((void) 0);_sharp__sharp_loop624_continue626:((void) 0);
(_sharp_iterator623 = ((* ((struct struct0x082064f8 *) _sharp_iterator623)).cdr));
})
,
({goto _sharp__sharp_loop624_begin627;}),
((void) 0);_sharp__sharp_loop624_end625:((void) 0);
})
;
(print_Symbol)(intern( "void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( \"TEST result: %d\", test_ptr());flush();}")),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "\n"), "\n"})),
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
((void) 0);_sharp__sharp_loop629_begin633:((void) 0),
({
Bool__type _sharp_tuple632;
Symbol__type _sharp_tuple631;
Bool__type misc_;
Symbol__type symbol;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop629_end630;});}})
;
(_sharp_tuple631 = ((Symbol__type ) Index_)),
(_sharp_tuple632 = ((Bool__type ) (* PValue_))),
(symbol = _sharp_tuple631),
(misc_ = _sharp_tuple632);
({
Type__type t;
(t = (get_global_type)(symbol));
((Bool__type ) (puthash)(((void *) t), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) type_definition_needed)));
})
;
(PValue_ = (JudyLNext)((* ((void **) hash_)), ((void *) (&Index_)), 0));
})
,
({goto _sharp__sharp_loop629_begin633;}),
((void) 0);_sharp__sharp_loop629_end630:((void) 0);
})
;
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
((void) 0);_sharp__sharp_loop635_begin639:((void) 0),
({
Bool__type _sharp_tuple638;
Symbol__type _sharp_tuple637;
Bool__type misc_;
Symbol__type symbol;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop635_end636;});}})
;
(_sharp_tuple637 = ((Symbol__type ) Index_)),
(_sharp_tuple638 = ((Bool__type ) (* PValue_))),
(symbol = _sharp_tuple637),
(misc_ = _sharp_tuple638);
({
Type__type t;
(t = (get_global_type)(symbol));
(c_output_type)(symbol, t);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n"), ";\n"})),
(maybe_flush)();
})
;
(PValue_ = (JudyLNext)((* ((void **) hash_)), ((void *) (&Index_)), 0));
})
,
({goto _sharp__sharp_loop635_begin639;}),
((void) 0);_sharp__sharp_loop635_end636:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Output_Descriptor__type current_output_descriptor;\n"), "Output_Descriptor__type current_output_descriptor;\n"})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Output_Descriptor__type stdout_descriptor;\n"), "Output_Descriptor__type stdout_descriptor;\n"})),
(maybe_flush)();
(flush)();
})
;}

void  test(void)
{
return ({
(stdout_descriptor = current_output_descriptor);
(init_c_output)();
(doit)((&(struct { unsigned int len; char *content;}){strlen( "c-output/c-output.l"), "c-output/c-output.l"}), (&(struct { unsigned int len; char *content;}){strlen( "c-output/c-output.c"), "c-output/c-output.c"}), (&(struct { unsigned int len; char *content;}){strlen( "c-output/c-output.inc"), "c-output/c-output.inc"}));
})
;}

void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( "TEST result: %d", test_ptr());flush();}
