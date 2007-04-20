/* Automatically generated : do not edit!*/
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
(((* ((struct struct0x080642f0 *) rf)).form_type_) == 1811939328);
})
;}

Bool__type  is_expanded_form(Form__type  f)
{
return ({
(((* ((struct struct0x080642f0 *) f)).form_type_) == (- (int) 536870912));
})
;}

Bool__type  is_id_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x080642f0 *) rf)).form_type_) == (- (int) 1342177280));
})
;}

Bool__type  is_int_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x080642f0 *) rf)).form_type_) == (- (int) -2147483648));
})
;}

Bool__type  is_symbol_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x080642f0 *) rf)).form_type_) == (- (int) 1073741824));
})
;}

Bool__type  is_string_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x080642f0 *) rf)).form_type_) == (- (int) 1610612736));
})
;}

Bool__type  is_struct_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) nt)).common_)).type_type) == 0);
})
;}

Bool__type  is_base_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) nt)).common_)).type_type) == 3);
})
;}

Bool__type  is_pointer_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) nt)).common_)).type_type) == 4);
})
;}

Bool__type  is_tuple_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) nt)).common_)).type_type) == 2);
})
;}

Bool__type  is_function_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) nt)).common_)).type_type) == 1);
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
(((((* ((struct struct0x08064740 *) bt)).origin_type) == ((Type__type ) 0)))?
(({
({if( ((is_id_form)((((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) bt))).common_)).type_form)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_79;
_sharp_pair_79,
(_sharp_pair_79 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_79).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_78;
_sharp_pair_78,
(_sharp_pair_78 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_78).car) = (Id_Form)(intern( "bt")));
(((* _sharp_pair_78).cdr) = ({
struct struct0x08095f28 *_sharp_pair_77;
_sharp_pair_77,
(_sharp_pair_77 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_77).car) = (Symbol_Form)(intern( "type_form")));
(((* _sharp_pair_77).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_77);
})
);
((List__O__Form__C____type__type ) _sharp_pair_78);
})
));
(((* _sharp_pair_79).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_79);
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
(print_Symbol)(((* ((struct struct0x080608f0 *) ((Id_Form__type ) (((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) bt))).common_)).type_form)))).value)),
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
(c_output_type)((prepend_star)(name), (intern_type)(((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) ((Compound_Form__type ) (((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) t))).common_)).type_form)))).form_list))).head)));
})
):
((((is_tuple_type)(t))?
(({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) t))).common_)).type_form)));
(((((* ((struct struct0x080659b0 *) tf)).form_list) == ((List__O__Form__C____type__type ) 0)))?
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "void "), "void "})),
(print_Symbol)(name),
(maybe_flush)();
})
):
(({
(print_form)((((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) t))).common_)).type_form));
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
(form_list = ((* ((struct struct0x080659b0 *) ((Compound_Form__type ) (((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) t))).common_)).type_form)))).form_list));
(return_type = (intern_type)(((* ((struct struct0x08065ba8 *) form_list)).head)));
(c_output_type)(intern( ""), return_type);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(print_Symbol)(name),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"})),
(maybe_flush)();
(parameters = ((Compound_Form__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) form_list)).tail))).head)));
(((((* ((struct struct0x080659b0 *) parameters)).form_list) == ((List__O__Form__C____type__type ) 0)))?
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(void)"), "(void)"})),
(maybe_flush)();
})
):
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(maybe_flush)();
(c_output_type)(intern( ""), (intern_type)(((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) parameters)).form_list))).head)));
({
List__O__Form__C____type__type _sharp_iterator81;
(_sharp_iterator81 = ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) parameters)).form_list))).tail));
((void) 0);_sharp__sharp_loop82_begin85:((void) 0),
({
Form__type parameter;
({if( (_sharp_iterator81 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop82_end83;});}})
;
(parameter = ((* ((struct struct0x08095f28 *) _sharp_iterator81)).car));
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(maybe_flush)();
(c_output_type)(intern( ""), (intern_type)(parameter));
})
;
((void) 0);_sharp__sharp_loop82_continue84:((void) 0);
(_sharp_iterator81 = ((* ((struct struct0x08095f28 *) _sharp_iterator81)).cdr));
})
,
({goto _sharp__sharp_loop82_begin85;}),
((void) 0);_sharp__sharp_loop82_end83:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"})),
(maybe_flush)();
})
));
})
):
(({
(print_form)((((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) t))).common_)).type_form));
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
({if( (((* ((struct struct0x08064740 *) bt)).origin_type) == ((Type__type ) 0)))
{
({
({goto end;});
})
;}})
;
({if( ((Bool__type ) (gethash)(((void *) ((* ((struct struct0x08064740 *) bt)).origin_type)), ((Hash_Table__type ) has_been_outputed))))
{
({
({goto next;});
})
;}})
;
(c_output_type_definition)(((* ((struct struct0x08064740 *) bt)).origin_type));
((void) 0);next:((void) 0),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "typedef "), "typedef "})),
(maybe_flush)();
(c_output_type)((mangle_type_name)(t), ((* ((struct struct0x08064740 *) bt)).origin_type));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "__type"), "__type"})),
(maybe_flush)();
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n"), ";\n"})),
(maybe_flush)();
})
):
((((is_struct_type)(t))?
(({
Form__type tf;
(tf = (((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) t))).common_)).type_form));
({
List__O__Form__C____type__type _sharp_iterator87;
(_sharp_iterator87 = ((* ((struct struct0x080659b0 *) ((Compound_Form__type ) tf))).form_list));
((void) 0);_sharp__sharp_loop88_begin96:((void) 0),
({
Form__type label_form_;
({if( (_sharp_iterator87 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop88_end89;});}})
;
(label_form_ = ((* ((struct struct0x08095f28 *) _sharp_iterator87)).car));
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
struct struct0x08095f28 *_sharp_pair_90;
_sharp_pair_90,
(_sharp_pair_90 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_90).car) = (Id_Form)(intern( "label_form_")));
(((* _sharp_pair_90).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_90);
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
({if( ((((* ((struct struct0x080659b0 *) label_form)).head) == intern( "label")) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_94;
_sharp_pair_94,
(_sharp_pair_94 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_94).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_92;
_sharp_pair_92,
(_sharp_pair_92 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_92).car) = (Id_Form)(intern( "label_form")));
(((* _sharp_pair_92).cdr) = ({
struct struct0x08095f28 *_sharp_pair_91;
_sharp_pair_91,
(_sharp_pair_91 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_91).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_91).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_91);
})
);
((List__O__Form__C____type__type ) _sharp_pair_92);
})
));
(((* _sharp_pair_94).cdr) = ({
struct struct0x08095f28 *_sharp_pair_93;
_sharp_pair_93,
(_sharp_pair_93 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_93).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_93).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_93);
})
);
((List__O__Form__C____type__type ) _sharp_pair_94);
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
(subtf = ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) label_form)).form_list))).tail))).head));
(subtype = (intern_type)(subtf));
({if( ((Bool__type ) (gethash)(((void *) subtype), ((Hash_Table__type ) has_been_outputed))))
{
({goto _sharp__sharp_loop88_continue95;});}})
;
(c_output_type_definition)(subtype);
})
;
((void) 0);_sharp__sharp_loop88_continue95:((void) 0);
(_sharp_iterator87 = ((* ((struct struct0x08095f28 *) _sharp_iterator87)).cdr));
})
,
({goto _sharp__sharp_loop88_begin96;}),
((void) 0);_sharp__sharp_loop88_end89:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "struct struct"), "struct struct"})),
(print_Int_Hex)(((Int__type ) t)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " {\n"), " {\n"})),
(maybe_flush)();
({
List__O__Form__C____type__type _sharp_iterator98;
(_sharp_iterator98 = ((* ((struct struct0x080659b0 *) ((Compound_Form__type ) tf))).form_list));
((void) 0);_sharp__sharp_loop99_begin107:((void) 0),
({
Form__type label_form_;
({if( (_sharp_iterator98 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop99_end100;});}})
;
(label_form_ = ((* ((struct struct0x08095f28 *) _sharp_iterator98)).car));
({
Symbol__type field_name;
Type__type subtype;
Form__type subtf;
Compound_Form__type label_form;
(label_form = ((Compound_Form__type ) label_form_));
({if( ((is_id_form)(((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) label_form)).form_list))).head)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_105;
_sharp_pair_105,
(_sharp_pair_105 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_105).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_104;
_sharp_pair_104,
(_sharp_pair_104 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_104).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_102;
_sharp_pair_102,
(_sharp_pair_102 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_102).car) = (Id_Form)(intern( "label_form")));
(((* _sharp_pair_102).cdr) = ({
struct struct0x08095f28 *_sharp_pair_101;
_sharp_pair_101,
(_sharp_pair_101 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_101).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_101).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_101);
})
);
((List__O__Form__C____type__type ) _sharp_pair_102);
})
));
(((* _sharp_pair_104).cdr) = ({
struct struct0x08095f28 *_sharp_pair_103;
_sharp_pair_103,
(_sharp_pair_103 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_103).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_103).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_103);
})
);
((List__O__Form__C____type__type ) _sharp_pair_104);
})
));
(((* _sharp_pair_105).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_105);
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
(field_name = ((* ((struct struct0x080608f0 *) ((Id_Form__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) label_form)).form_list))).head)))).value));
(subtf = ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) label_form)).form_list))).tail))).head));
(subtype = (intern_type)(subtf));
(c_output_type)(field_name, subtype);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n"), ";\n"})),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop99_continue106:((void) 0);
(_sharp_iterator98 = ((* ((struct struct0x08095f28 *) _sharp_iterator98)).cdr));
})
,
({goto _sharp__sharp_loop99_begin107;}),
((void) 0);_sharp__sharp_loop99_end100:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "};\n"), "};\n"})),
(maybe_flush)();
})
):
((((is_pointer_type)(t))?
(({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) t))).common_)).type_form)));
({if( (is_compound_form)(((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) tf)).form_list))).head)))
{
({
Compound_Form__type ptf;
(ptf = ((Compound_Form__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) tf)).form_list))).head)));
({if( (((* ((struct struct0x080659b0 *) ptf)).head) == intern( "struct")))
{
({goto end;});}})
;
})
;}})
;
(c_output_type_definition)((intern_type)(((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) tf)).form_list))).head)));
})
):
((((is_function_type)(t))?
(({
Type__type from_type;
Type__type to_type;
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) t))).common_)).type_form)));
(to_type = (intern_type)(((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) tf)).form_list))).head)));
(c_output_type_definition)(to_type);
(from_type = (intern_type)(((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) tf)).form_list))).tail))).head)));
(c_output_type_definition)(from_type);
})
):
(({if( (is_tuple_type)(t))
{
({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x080943c8 ) ((* ((struct struct0x08094660 *) ((Real_Type__type ) t))).common_)).type_form)));
({
List__O__Form__C____type__type _sharp_iterator109;
(_sharp_iterator109 = ((* ((struct struct0x080659b0 *) tf)).form_list));
((void) 0);_sharp__sharp_loop110_begin113:((void) 0),
({
Form__type subform;
({if( (_sharp_iterator109 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop110_end111;});}})
;
(subform = ((* ((struct struct0x08095f28 *) _sharp_iterator109)).car));
({
Type__type type;
(type = (intern_type)(subform));
(c_output_type_definition)(type);
})
;
((void) 0);_sharp__sharp_loop110_continue112:((void) 0);
(_sharp_iterator109 = ((* ((struct struct0x08095f28 *) _sharp_iterator109)).cdr));
})
,
({goto _sharp__sharp_loop110_begin113;}),
((void) 0);_sharp__sharp_loop110_end111:((void) 0);
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
((void) 0);_sharp__sharp_loop115_begin119:((void) 0),
({
Bool__type _sharp_tuple118;
Type__type _sharp_tuple117;
Bool__type bool;
Type__type type;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop115_end116;});}})
;
(_sharp_tuple117 = ((Type__type ) Index_)),
(_sharp_tuple118 = ((Bool__type ) (* PValue_))),
(type = _sharp_tuple117),
(bool = _sharp_tuple118);
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
({goto _sharp__sharp_loop115_begin119;}),
((void) 0);_sharp__sharp_loop115_end116:((void) 0);
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
(f = ((* ((struct struct0x08066420 *) expf)).return_form));
(((is_compound_form)(f))?
(({
void (*fun)(Expanded_Compound_Form__type );
Compound_Form__type cf;
(cf = ((Compound_Form__type ) f));
(fun = ((void (*)(Expanded_Compound_Form__type )) (gethash)(((void *) ((* ((struct struct0x080659b0 *) cf)).head)), ((Hash_Table__type ) c_output_hash))));
({if( (fun == ((void (*)(Expanded_Compound_Form__type )) 0)))
{
({
({
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Panic : "), "Panic : "})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "No output function defined for "), "No output function defined for "})),
(print_Symbol)(((* ((struct struct0x080659b0 *) cf)).head)),
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
(print_Symbol)((convert_id)(((* ((struct struct0x080608f0 *) id_form)).value)));
})
):
((((is_int_form)(f))?
(({
Int_Form__type int_form;
(int_form = ((Int_Form__type ) f));
(print_Int_Dec)(((* ((struct struct0x08064c40 *) int_form)).value));
})
):
((((is_symbol_form)(f))?
(({
Symbol_Form__type symbol_form;
(symbol_form = ((Symbol_Form__type ) f));
(print_Symbol)(intern( "intern( \"")),
(print_String)((convert_id_as_string)(((* ((struct struct0x080608f0 *) symbol_form)).value))),
(print_Symbol)(intern( "\")"));
})
):
((((is_string_form)(f))?
(({
String__type string;
String_Form__type string_form;
(string_form = ((String_Form__type ) f));
(string = (convert_string)(((* ((struct struct0x08061ea0 *) string_form)).value)));
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
(print_Int_Dec)(((* ((struct struct0x080642f0 *) ((Form__type ) f))).form_type_));
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
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " + (int) "), " + (int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_mul_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " * (int) "), " * (int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_sub_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " - (int) "), " - (int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_div_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " / (int) "), " / (int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_unary_minus_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(- (int) "), "(- (int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_ge_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " >= (int) "), " >= (int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_gt_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " > (int) "), " > (int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_le_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " <= (int) "), " <= (int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_lt_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " < (int) "), " < (int) "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_different(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " != "), " != "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_equal(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " == "), " == "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_access_struct(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "."), "."}));
({if( ((is_symbol_form)(((* ((struct struct0x08066420 *) ((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head))).return_form)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_128;
_sharp_pair_128,
(_sharp_pair_128 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_128).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_127;
_sharp_pair_127,
(_sharp_pair_127 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_127).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_125;
_sharp_pair_125,
(_sharp_pair_125 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_125).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_123;
_sharp_pair_123,
(_sharp_pair_123 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_123).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_121;
_sharp_pair_121,
(_sharp_pair_121 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_121).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_121).cdr) = ({
struct struct0x08095f28 *_sharp_pair_120;
_sharp_pair_120,
(_sharp_pair_120 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_120).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_120).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_120);
})
);
((List__O__Form__C____type__type ) _sharp_pair_121);
})
));
(((* _sharp_pair_123).cdr) = ({
struct struct0x08095f28 *_sharp_pair_122;
_sharp_pair_122,
(_sharp_pair_122 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_122).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_122).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_122);
})
);
((List__O__Form__C____type__type ) _sharp_pair_123);
})
));
(((* _sharp_pair_125).cdr) = ({
struct struct0x08095f28 *_sharp_pair_124;
_sharp_pair_124,
(_sharp_pair_124 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_124).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_124).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_124);
})
);
((List__O__Form__C____type__type ) _sharp_pair_125);
})
));
(((* _sharp_pair_127).cdr) = ({
struct struct0x08095f28 *_sharp_pair_126;
_sharp_pair_126,
(_sharp_pair_126 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_126).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_126).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_126);
})
);
((List__O__Form__C____type__type ) _sharp_pair_127);
})
));
(((* _sharp_pair_128).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_128);
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
(print_Symbol)(((* ((struct struct0x080608f0 *) ((Symbol_Form__type ) ((* ((struct struct0x08066420 *) ((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head))).return_form)))).value)),
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
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " = "), " = "}));
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head));
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
List__O__Expanded_Form__C____type__type _sharp_iterator130;
(_sharp_iterator130 = ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)));
((void) 0);_sharp__sharp_loop131_begin134:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator130 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop131_end132;});}})
;
(subform = ((* ((struct struct0x0816e620 *) _sharp_iterator130)).car));
({
(c_output_form)(subform),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n"), ";\n"}));
})
;
((void) 0);_sharp__sharp_loop131_continue133:((void) 0);
(_sharp_iterator130 = ((* ((struct struct0x0816e620 *) _sharp_iterator130)).cdr));
})
,
({goto _sharp__sharp_loop131_begin134;}),
((void) 0);_sharp__sharp_loop131_end132:((void) 0);
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
(c_output_type)(intern( ""), (intern_type)(((* ((struct struct0x08066420 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head))).return_form)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ") "), ") "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;
})
;}

void  c_output_deref(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(* "), "(* "})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_funcall(Expanded_Compound_Form__type  cf)
{
return ({
Expanded_Form__type function;
(function = ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head));
({if( (is_id_form)(((* ((struct struct0x08066420 *) function)).return_form)))
{
({
((Bool__type ) (puthash)(((void *) ((* ((struct struct0x080608f0 *) ((Id_Form__type ) ((* ((struct struct0x08066420 *) function)).return_form)))).value)), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) globals_needed)));
})
;}})
;
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(function),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")("), ")("}));
({if( (((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail) != ((List__O__Expanded_Form__C____type__type ) 0)))
{
({
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head));
({
List__O__Expanded_Form__C____type__type _sharp_iterator136;
(_sharp_iterator136 = ((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).tail));
((void) 0);_sharp__sharp_loop137_begin140:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator136 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop137_end138;});}})
;
(subform = ((* ((struct struct0x0816e620 *) _sharp_iterator136)).car));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(c_output_form)(subform);
((void) 0);_sharp__sharp_loop137_continue139:((void) 0);
(_sharp_iterator136 = ((* ((struct struct0x0816e620 *) _sharp_iterator136)).cdr));
})
,
({goto _sharp__sharp_loop137_begin140;}),
((void) 0);_sharp__sharp_loop137_end138:((void) 0);
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
(condition = ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head));
(then = ((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head));
({
(((((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)))?
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
(elsef = ((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).tail))).head));
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
({if( ((((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_149;
_sharp_pair_149,
(_sharp_pair_149 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_149).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_144;
_sharp_pair_144,
(_sharp_pair_144 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_144).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_142;
_sharp_pair_142,
(_sharp_pair_142 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_142).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_142).cdr) = ({
struct struct0x08095f28 *_sharp_pair_141;
_sharp_pair_141,
(_sharp_pair_141 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_141).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_141).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_141);
})
);
((List__O__Form__C____type__type ) _sharp_pair_142);
})
));
(((* _sharp_pair_144).cdr) = ({
struct struct0x08095f28 *_sharp_pair_143;
_sharp_pair_143,
(_sharp_pair_143 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_143).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_143).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_143);
})
);
((List__O__Form__C____type__type ) _sharp_pair_144);
})
));
(((* _sharp_pair_149).cdr) = ({
struct struct0x08095f28 *_sharp_pair_148;
_sharp_pair_148,
(_sharp_pair_148 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_148).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_147;
_sharp_pair_147,
(_sharp_pair_147 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_147).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08095f28 *_sharp_pair_145;
_sharp_pair_145,
(_sharp_pair_145 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_145).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_145).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_145);
})
));
(((* _sharp_pair_147).cdr) = ({
struct struct0x08095f28 *_sharp_pair_146;
_sharp_pair_146,
(_sharp_pair_146 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_146).car) = (Int_Form)(0));
(((* _sharp_pair_146).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_146);
})
);
((List__O__Form__C____type__type ) _sharp_pair_147);
})
));
(((* _sharp_pair_148).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_148);
})
);
((List__O__Form__C____type__type ) _sharp_pair_149);
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
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_156;
_sharp_pair_156,
(_sharp_pair_156 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_156).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_155;
_sharp_pair_155,
(_sharp_pair_155 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_155).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_155).cdr) = ({
struct struct0x08095f28 *_sharp_pair_154;
_sharp_pair_154,
(_sharp_pair_154 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_154).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_153;
_sharp_pair_153,
(_sharp_pair_153 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_153).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_151;
_sharp_pair_151,
(_sharp_pair_151 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_151).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_151).cdr) = ({
struct struct0x08095f28 *_sharp_pair_150;
_sharp_pair_150,
(_sharp_pair_150 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_150).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_150).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_150);
})
);
((List__O__Form__C____type__type ) _sharp_pair_151);
})
));
(((* _sharp_pair_153).cdr) = ({
struct struct0x08095f28 *_sharp_pair_152;
_sharp_pair_152,
(_sharp_pair_152 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_152).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_152).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_152);
})
);
((List__O__Form__C____type__type ) _sharp_pair_153);
})
));
(((* _sharp_pair_154).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_154);
})
);
((List__O__Form__C____type__type ) _sharp_pair_155);
})
));
(((* _sharp_pair_156).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_156);
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
(label_form = ((Id_Form__type ) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "&&"), "&&"})),
(print_Symbol)((convert_id)(((* ((struct struct0x080608f0 *) label_form)).value)));
})
;}

void  c_output_goto_constant(Expanded_Compound_Form__type  cf)
{
return ({
Id_Form__type id_form;
({if( ((((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_165;
_sharp_pair_165,
(_sharp_pair_165 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_165).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_160;
_sharp_pair_160,
(_sharp_pair_160 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_160).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_158;
_sharp_pair_158,
(_sharp_pair_158 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_158).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_158).cdr) = ({
struct struct0x08095f28 *_sharp_pair_157;
_sharp_pair_157,
(_sharp_pair_157 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_157).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_157).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_157);
})
);
((List__O__Form__C____type__type ) _sharp_pair_158);
})
));
(((* _sharp_pair_160).cdr) = ({
struct struct0x08095f28 *_sharp_pair_159;
_sharp_pair_159,
(_sharp_pair_159 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_159).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_159).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_159);
})
);
((List__O__Form__C____type__type ) _sharp_pair_160);
})
));
(((* _sharp_pair_165).cdr) = ({
struct struct0x08095f28 *_sharp_pair_164;
_sharp_pair_164,
(_sharp_pair_164 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_164).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_163;
_sharp_pair_163,
(_sharp_pair_163 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_163).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08095f28 *_sharp_pair_161;
_sharp_pair_161,
(_sharp_pair_161 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_161).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_161).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_161);
})
));
(((* _sharp_pair_163).cdr) = ({
struct struct0x08095f28 *_sharp_pair_162;
_sharp_pair_162,
(_sharp_pair_162 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_162).car) = (Int_Form)(0));
(((* _sharp_pair_162).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_162);
})
);
((List__O__Form__C____type__type ) _sharp_pair_163);
})
));
(((* _sharp_pair_164).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_164);
})
);
((List__O__Form__C____type__type ) _sharp_pair_165);
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
(id_form = ((Id_Form__type ) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)));
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
struct struct0x08095f28 *_sharp_pair_168;
_sharp_pair_168,
(_sharp_pair_168 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_168).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_167;
_sharp_pair_167,
(_sharp_pair_167 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_167).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_167).cdr) = ({
struct struct0x08095f28 *_sharp_pair_166;
_sharp_pair_166,
(_sharp_pair_166 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_166).car) = (Id_Form)(intern( "id_form")));
(((* _sharp_pair_166).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_166);
})
);
((List__O__Form__C____type__type ) _sharp_pair_167);
})
));
(((* _sharp_pair_168).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_168);
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
(print_Symbol)((convert_id)(((* ((struct struct0x080608f0 *) id_form)).value))),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";})"), ";})"}));
})
;}

void  c_output_goto_variable(Expanded_Compound_Form__type  cf)
{
return ({
({if( ((((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_177;
_sharp_pair_177,
(_sharp_pair_177 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_177).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_172;
_sharp_pair_172,
(_sharp_pair_172 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_172).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_170;
_sharp_pair_170,
(_sharp_pair_170 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_170).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_170).cdr) = ({
struct struct0x08095f28 *_sharp_pair_169;
_sharp_pair_169,
(_sharp_pair_169 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_169).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_169).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_169);
})
);
((List__O__Form__C____type__type ) _sharp_pair_170);
})
));
(((* _sharp_pair_172).cdr) = ({
struct struct0x08095f28 *_sharp_pair_171;
_sharp_pair_171,
(_sharp_pair_171 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_171).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_171).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_171);
})
);
((List__O__Form__C____type__type ) _sharp_pair_172);
})
));
(((* _sharp_pair_177).cdr) = ({
struct struct0x08095f28 *_sharp_pair_176;
_sharp_pair_176,
(_sharp_pair_176 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_176).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_175;
_sharp_pair_175,
(_sharp_pair_175 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_175).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08095f28 *_sharp_pair_173;
_sharp_pair_173,
(_sharp_pair_173 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_173).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_173).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_173);
})
));
(((* _sharp_pair_175).cdr) = ({
struct struct0x08095f28 *_sharp_pair_174;
_sharp_pair_174,
(_sharp_pair_174 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_174).car) = (Int_Form)(0));
(((* _sharp_pair_174).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_174);
})
);
((List__O__Form__C____type__type ) _sharp_pair_175);
})
));
(((* _sharp_pair_176).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_176);
})
);
((List__O__Form__C____type__type ) _sharp_pair_177);
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
({if( ((is_compound_form)(((* ((struct struct0x08066420 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head))).return_form)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_184;
_sharp_pair_184,
(_sharp_pair_184 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_184).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_183;
_sharp_pair_183,
(_sharp_pair_183 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_183).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_181;
_sharp_pair_181,
(_sharp_pair_181 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_181).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_179;
_sharp_pair_179,
(_sharp_pair_179 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_179).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_179).cdr) = ({
struct struct0x08095f28 *_sharp_pair_178;
_sharp_pair_178,
(_sharp_pair_178 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_178).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_178).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_178);
})
);
((List__O__Form__C____type__type ) _sharp_pair_179);
})
));
(((* _sharp_pair_181).cdr) = ({
struct struct0x08095f28 *_sharp_pair_180;
_sharp_pair_180,
(_sharp_pair_180 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_180).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_180).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_180);
})
);
((List__O__Form__C____type__type ) _sharp_pair_181);
})
));
(((* _sharp_pair_183).cdr) = ({
struct struct0x08095f28 *_sharp_pair_182;
_sharp_pair_182,
(_sharp_pair_182 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_182).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_182).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_182);
})
);
((List__O__Form__C____type__type ) _sharp_pair_183);
})
));
(((* _sharp_pair_184).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_184);
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
({if( ((((* ((struct struct0x080659b0 *) ((Compound_Form__type ) ((* ((struct struct0x08066420 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head))).return_form)))).head) == intern( "deref")) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_196;
_sharp_pair_196,
(_sharp_pair_196 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_196).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_194;
_sharp_pair_194,
(_sharp_pair_194 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_194).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_192;
_sharp_pair_192,
(_sharp_pair_192 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_192).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_192).cdr) = ({
struct struct0x08095f28 *_sharp_pair_191;
_sharp_pair_191,
(_sharp_pair_191 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_191).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_190;
_sharp_pair_190,
(_sharp_pair_190 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_190).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_188;
_sharp_pair_188,
(_sharp_pair_188 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_188).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_186;
_sharp_pair_186,
(_sharp_pair_186 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_186).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_186).cdr) = ({
struct struct0x08095f28 *_sharp_pair_185;
_sharp_pair_185,
(_sharp_pair_185 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_185).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_185).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_185);
})
);
((List__O__Form__C____type__type ) _sharp_pair_186);
})
));
(((* _sharp_pair_188).cdr) = ({
struct struct0x08095f28 *_sharp_pair_187;
_sharp_pair_187,
(_sharp_pair_187 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_187).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_187).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_187);
})
);
((List__O__Form__C____type__type ) _sharp_pair_188);
})
));
(((* _sharp_pair_190).cdr) = ({
struct struct0x08095f28 *_sharp_pair_189;
_sharp_pair_189,
(_sharp_pair_189 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_189).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_189).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_189);
})
);
((List__O__Form__C____type__type ) _sharp_pair_190);
})
));
(((* _sharp_pair_191).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_191);
})
);
((List__O__Form__C____type__type ) _sharp_pair_192);
})
));
(((* _sharp_pair_194).cdr) = ({
struct struct0x08095f28 *_sharp_pair_193;
_sharp_pair_193,
(_sharp_pair_193 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_193).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_193).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_193);
})
);
((List__O__Form__C____type__type ) _sharp_pair_194);
})
));
(((* _sharp_pair_196).cdr) = ({
struct struct0x08095f28 *_sharp_pair_195;
_sharp_pair_195,
(_sharp_pair_195 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_195).car) = (Symbol_Form)(intern( "deref")));
(((* _sharp_pair_195).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_195);
})
);
((List__O__Form__C____type__type ) _sharp_pair_196);
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
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) ((Expanded_Compound_Form__type ) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)))).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";})"), ";})"})),
(maybe_flush)();
})
;}

void  c_output_label(Expanded_Compound_Form__type  cf)
{
return ({
Id_Form__type label_form;
({if( ((((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_205;
_sharp_pair_205,
(_sharp_pair_205 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_205).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_200;
_sharp_pair_200,
(_sharp_pair_200 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_200).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_198;
_sharp_pair_198,
(_sharp_pair_198 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_198).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_198).cdr) = ({
struct struct0x08095f28 *_sharp_pair_197;
_sharp_pair_197,
(_sharp_pair_197 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_197).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_197).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_197);
})
);
((List__O__Form__C____type__type ) _sharp_pair_198);
})
));
(((* _sharp_pair_200).cdr) = ({
struct struct0x08095f28 *_sharp_pair_199;
_sharp_pair_199,
(_sharp_pair_199 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_199).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_199).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_199);
})
);
((List__O__Form__C____type__type ) _sharp_pair_200);
})
));
(((* _sharp_pair_205).cdr) = ({
struct struct0x08095f28 *_sharp_pair_204;
_sharp_pair_204,
(_sharp_pair_204 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_204).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_203;
_sharp_pair_203,
(_sharp_pair_203 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_203).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08095f28 *_sharp_pair_201;
_sharp_pair_201,
(_sharp_pair_201 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_201).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_201).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_201);
})
));
(((* _sharp_pair_203).cdr) = ({
struct struct0x08095f28 *_sharp_pair_202;
_sharp_pair_202,
(_sharp_pair_202 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_202).car) = (Int_Form)(0));
(((* _sharp_pair_202).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_202);
})
);
((List__O__Form__C____type__type ) _sharp_pair_203);
})
));
(((* _sharp_pair_204).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_204);
})
);
((List__O__Form__C____type__type ) _sharp_pair_205);
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
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_212;
_sharp_pair_212,
(_sharp_pair_212 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_212).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_211;
_sharp_pair_211,
(_sharp_pair_211 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_211).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_211).cdr) = ({
struct struct0x08095f28 *_sharp_pair_210;
_sharp_pair_210,
(_sharp_pair_210 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_210).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_209;
_sharp_pair_209,
(_sharp_pair_209 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_209).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_207;
_sharp_pair_207,
(_sharp_pair_207 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_207).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_207).cdr) = ({
struct struct0x08095f28 *_sharp_pair_206;
_sharp_pair_206,
(_sharp_pair_206 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_206).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_206).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_206);
})
);
((List__O__Form__C____type__type ) _sharp_pair_207);
})
));
(((* _sharp_pair_209).cdr) = ({
struct struct0x08095f28 *_sharp_pair_208;
_sharp_pair_208,
(_sharp_pair_208 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_208).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_208).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_208);
})
);
((List__O__Form__C____type__type ) _sharp_pair_209);
})
));
(((* _sharp_pair_210).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_210);
})
);
((List__O__Form__C____type__type ) _sharp_pair_211);
})
));
(((* _sharp_pair_212).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_212);
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
(label_form = ((Id_Form__type ) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((void) 0);"), "((void) 0);"})),
(print_Symbol)((convert_id)(((* ((struct struct0x080608f0 *) label_form)).value))),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ":((void) 0)"), ":((void) 0)"}));
})
;}

void  c_output_let(Expanded_Compound_Form__type  cf)
{
return ({
({
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_219;
_sharp_pair_219,
(_sharp_pair_219 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_219).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_218;
_sharp_pair_218,
(_sharp_pair_218 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_218).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_218).cdr) = ({
struct struct0x08095f28 *_sharp_pair_217;
_sharp_pair_217,
(_sharp_pair_217 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_217).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_216;
_sharp_pair_216,
(_sharp_pair_216 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_216).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_214;
_sharp_pair_214,
(_sharp_pair_214 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_214).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_214).cdr) = ({
struct struct0x08095f28 *_sharp_pair_213;
_sharp_pair_213,
(_sharp_pair_213 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_213).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_213).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_213);
})
);
((List__O__Form__C____type__type ) _sharp_pair_214);
})
));
(((* _sharp_pair_216).cdr) = ({
struct struct0x08095f28 *_sharp_pair_215;
_sharp_pair_215,
(_sharp_pair_215 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_215).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_215).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_215);
})
);
((List__O__Form__C____type__type ) _sharp_pair_216);
})
));
(((* _sharp_pair_217).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_217);
})
);
((List__O__Form__C____type__type ) _sharp_pair_218);
})
));
(((* _sharp_pair_219).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_219);
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
(c_output_type)((convert_id)(((* ((struct struct0x080608f0 *) ((Id_Form__type ) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)))).value)), (intern_type)(((Form__type ) ((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail))).head))));
})
;
})
;}

void  c_output_ref(Expanded_Compound_Form__type  cf)
{
return ({
({
Expanded_Form__type subform;
(subform = ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head));
({if( (is_compound_form)(((* ((struct struct0x08066420 *) subform)).return_form)))
{
({
Expanded_Compound_Form__type csubform;
(csubform = ((Expanded_Compound_Form__type ) subform));
({if( (((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) csubform)).return_form_))).head) == intern( "cast")))
{
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(("), "(("}));
(c_output_type)(intern( ""), (intern_type)(((* ((struct struct0x08066420 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) csubform)).return_form_))).form_list)))).head))).return_form)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ") "), ") "}));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(&"), "(&"})),
(c_output_form)(((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) csubform)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
({goto end;});
})
;}})
;
})
;}})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(&"), "(&"})),
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
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
({if( ((((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)) != ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_226;
_sharp_pair_226,
(_sharp_pair_226 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_226).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_221;
_sharp_pair_221,
(_sharp_pair_221 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_221).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_221).cdr) = ({
struct struct0x08095f28 *_sharp_pair_220;
_sharp_pair_220,
(_sharp_pair_220 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_220).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_220).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_220);
})
);
((List__O__Form__C____type__type ) _sharp_pair_221);
})
));
(((* _sharp_pair_226).cdr) = ({
struct struct0x08095f28 *_sharp_pair_225;
_sharp_pair_225,
(_sharp_pair_225 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_225).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_224;
_sharp_pair_224,
(_sharp_pair_224 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_224).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08095f28 *_sharp_pair_222;
_sharp_pair_222,
(_sharp_pair_222 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_222).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_222).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_222);
})
));
(((* _sharp_pair_224).cdr) = ({
struct struct0x08095f28 *_sharp_pair_223;
_sharp_pair_223,
(_sharp_pair_223 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_223).car) = (Int_Form)(0));
(((* _sharp_pair_223).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_223);
})
);
((List__O__Form__C____type__type ) _sharp_pair_224);
})
));
(((* _sharp_pair_225).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_225);
})
);
((List__O__Form__C____type__type ) _sharp_pair_226);
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
(c_output_form)(((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head));
({
List__O__Expanded_Form__C____type__type _sharp_iterator228;
(_sharp_iterator228 = ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail));
((void) 0);_sharp__sharp_loop229_begin232:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator228 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop229_end230;});}})
;
(subform = ((* ((struct struct0x0816e620 *) _sharp_iterator228)).car));
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ",\n"), ",\n"})),
(c_output_form)(subform);
})
;
((void) 0);_sharp__sharp_loop229_continue231:((void) 0);
(_sharp_iterator228 = ((* ((struct struct0x0816e620 *) _sharp_iterator228)).cdr));
})
,
({goto _sharp__sharp_loop229_begin232;}),
((void) 0);_sharp__sharp_loop229_end230:((void) 0);
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
(c_output_type)(intern( ""), ((* ((struct struct0x08094140 *) cf)).type));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "){"), "){"}));
({
Expanded_Form__type form_subform;
Expanded_Form__type subform_;
(subform_ = ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).head));
({if( ((is_compound_form)(((* ((struct struct0x08066420 *) subform_)).return_form)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_235;
_sharp_pair_235,
(_sharp_pair_235 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_235).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_234;
_sharp_pair_234,
(_sharp_pair_234 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_234).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_234).cdr) = ({
struct struct0x08095f28 *_sharp_pair_233;
_sharp_pair_233,
(_sharp_pair_233 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_233).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_233).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_233);
})
);
((List__O__Form__C____type__type ) _sharp_pair_234);
})
));
(((* _sharp_pair_235).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_235);
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
({if( ((((* ((struct struct0x080659b0 *) ((Compound_Form__type ) ((* ((struct struct0x08066420 *) subform_)).return_form)))).head) == intern( "label")) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_243;
_sharp_pair_243,
(_sharp_pair_243 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_243).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_241;
_sharp_pair_241,
(_sharp_pair_241 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_241).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_239;
_sharp_pair_239,
(_sharp_pair_239 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_239).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_239).cdr) = ({
struct struct0x08095f28 *_sharp_pair_238;
_sharp_pair_238,
(_sharp_pair_238 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_238).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_237;
_sharp_pair_237,
(_sharp_pair_237 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_237).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_237).cdr) = ({
struct struct0x08095f28 *_sharp_pair_236;
_sharp_pair_236,
(_sharp_pair_236 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_236).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_236).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_236);
})
);
((List__O__Form__C____type__type ) _sharp_pair_237);
})
));
(((* _sharp_pair_238).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_238);
})
);
((List__O__Form__C____type__type ) _sharp_pair_239);
})
));
(((* _sharp_pair_241).cdr) = ({
struct struct0x08095f28 *_sharp_pair_240;
_sharp_pair_240,
(_sharp_pair_240 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_240).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_240).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_240);
})
);
((List__O__Form__C____type__type ) _sharp_pair_241);
})
));
(((* _sharp_pair_243).cdr) = ({
struct struct0x08095f28 *_sharp_pair_242;
_sharp_pair_242,
(_sharp_pair_242 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_242).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_242).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_242);
})
);
((List__O__Form__C____type__type ) _sharp_pair_243);
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
(form_subform = ((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) ((Expanded_Compound_Form__type ) subform_))).return_form_))).form_list)))).tail))).head));
(c_output_form)(form_subform);
})
;
({
List__O__Expanded_Form__C____type__type _sharp_iterator245;
(_sharp_iterator245 = ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)))).tail));
((void) 0);_sharp__sharp_loop246_begin260:((void) 0),
({
Expanded_Form__type subform_;
({if( (_sharp_iterator245 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop246_end247;});}})
;
(subform_ = ((* ((struct struct0x0816e620 *) _sharp_iterator245)).car));
({
Expanded_Form__type form_subform;
({if( ((is_compound_form)(((* ((struct struct0x08066420 *) subform_)).return_form)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_250;
_sharp_pair_250,
(_sharp_pair_250 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_250).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_249;
_sharp_pair_249,
(_sharp_pair_249 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_249).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_249).cdr) = ({
struct struct0x08095f28 *_sharp_pair_248;
_sharp_pair_248,
(_sharp_pair_248 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_248).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_248).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_248);
})
);
((List__O__Form__C____type__type ) _sharp_pair_249);
})
));
(((* _sharp_pair_250).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_250);
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
({if( ((((* ((struct struct0x080659b0 *) ((Compound_Form__type ) ((* ((struct struct0x08066420 *) subform_)).return_form)))).head) == intern( "label")) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_258;
_sharp_pair_258,
(_sharp_pair_258 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_258).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_256;
_sharp_pair_256,
(_sharp_pair_256 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_256).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_254;
_sharp_pair_254,
(_sharp_pair_254 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_254).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_254).cdr) = ({
struct struct0x08095f28 *_sharp_pair_253;
_sharp_pair_253,
(_sharp_pair_253 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_253).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_252;
_sharp_pair_252,
(_sharp_pair_252 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_252).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_252).cdr) = ({
struct struct0x08095f28 *_sharp_pair_251;
_sharp_pair_251,
(_sharp_pair_251 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_251).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_251).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_251);
})
);
((List__O__Form__C____type__type ) _sharp_pair_252);
})
));
(((* _sharp_pair_253).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_253);
})
);
((List__O__Form__C____type__type ) _sharp_pair_254);
})
));
(((* _sharp_pair_256).cdr) = ({
struct struct0x08095f28 *_sharp_pair_255;
_sharp_pair_255,
(_sharp_pair_255 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_255).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_255).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_255);
})
);
((List__O__Form__C____type__type ) _sharp_pair_256);
})
));
(((* _sharp_pair_258).cdr) = ({
struct struct0x08095f28 *_sharp_pair_257;
_sharp_pair_257,
(_sharp_pair_257 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_257).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_257).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_257);
})
);
((List__O__Form__C____type__type ) _sharp_pair_258);
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
(form_subform = ((* ((struct struct0x08154668 *) ((* ((struct struct0x08154668 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) ((Expanded_Compound_Form__type ) subform_))).return_form_))).form_list)))).tail))).head));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(c_output_form)(form_subform);
})
;
((void) 0);_sharp__sharp_loop246_continue259:((void) 0);
(_sharp_iterator245 = ((* ((struct struct0x0816e620 *) _sharp_iterator245)).cdr));
})
,
({goto _sharp__sharp_loop246_begin260;}),
((void) 0);_sharp__sharp_loop246_end247:((void) 0);
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
(((((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((* ((struct struct0x08094140 *) cf)).return_form_))).form_list)) == ((List__O__Expanded_Form__C____type__type ) 0)))?
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
struct struct0x08095f28 *_sharp_pair_261;
_sharp_pair_261,
(_sharp_pair_261 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_261).car) = (Id_Form)(intern( "l_")));
(((* _sharp_pair_261).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_261);
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
(l = ((* ((struct struct0x08066420 *) ((Expanded_Form__type ) l_))).return_form));
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
struct struct0x08095f28 *_sharp_pair_262;
_sharp_pair_262,
(_sharp_pair_262 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_262).car) = (Id_Form)(intern( "l")));
(((* _sharp_pair_262).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_262);
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
({if( ((((* ((struct struct0x080659b0 *) ((Compound_Form__type ) l))).head) == intern( "lambda")) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_268;
_sharp_pair_268,
(_sharp_pair_268 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_268).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_266;
_sharp_pair_266,
(_sharp_pair_266 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_266).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_264;
_sharp_pair_264,
(_sharp_pair_264 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_264).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_264).cdr) = ({
struct struct0x08095f28 *_sharp_pair_263;
_sharp_pair_263,
(_sharp_pair_263 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_263).car) = (Id_Form)(intern( "l")));
(((* _sharp_pair_263).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_263);
})
);
((List__O__Form__C____type__type ) _sharp_pair_264);
})
));
(((* _sharp_pair_266).cdr) = ({
struct struct0x08095f28 *_sharp_pair_265;
_sharp_pair_265,
(_sharp_pair_265 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_265).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_265).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_265);
})
);
((List__O__Form__C____type__type ) _sharp_pair_266);
})
));
(((* _sharp_pair_268).cdr) = ({
struct struct0x08095f28 *_sharp_pair_267;
_sharp_pair_267,
(_sharp_pair_267 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_267).car) = (Symbol_Form)(intern( "lambda")));
(((* _sharp_pair_267).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_267);
})
);
((List__O__Form__C____type__type ) _sharp_pair_268);
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
(form_list = ((List__O__Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((Compound_Form__type ) l))).form_list)));
(return_type = ((* ((struct struct0x08065ba8 *) form_list)).head));
(c_output_type)(intern( ""), (intern_type)(return_type));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " "), " "})),
(print_Symbol)((convert_id)(name)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(maybe_flush)();
(parameters_type = ((Compound_Form__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) form_list)).tail))).head)));
({if( ((((* ((struct struct0x080659b0 *) parameters_type)).head) == intern( "tuple")) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_272;
_sharp_pair_272,
(_sharp_pair_272 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_272).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_270;
_sharp_pair_270,
(_sharp_pair_270 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_270).car) = (Id_Form)(intern( "parameters_type")));
(((* _sharp_pair_270).cdr) = ({
struct struct0x08095f28 *_sharp_pair_269;
_sharp_pair_269,
(_sharp_pair_269 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_269).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_269).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_269);
})
);
((List__O__Form__C____type__type ) _sharp_pair_270);
})
));
(((* _sharp_pair_272).cdr) = ({
struct struct0x08095f28 *_sharp_pair_271;
_sharp_pair_271,
(_sharp_pair_271 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_271).car) = (Symbol_Form)(intern( "tuple")));
(((* _sharp_pair_271).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_271);
})
);
((List__O__Form__C____type__type ) _sharp_pair_272);
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
(((((* ((struct struct0x080659b0 *) parameters_type)).form_list) == ((List__O__Form__C____type__type ) 0)))?
((print_String)((&(struct { unsigned int len; char *content;}){strlen( "void"), "void"})),
(maybe_flush)()):
(({
Id_Form__type first_param_name;
Form__type first_param_type;
Compound_Form__type first_parameter;
(first_parameter = ((Compound_Form__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) parameters_type)).form_list))).head)));
({if( ((((* ((struct struct0x080659b0 *) first_parameter)).head) == intern( "label")) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_276;
_sharp_pair_276,
(_sharp_pair_276 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_276).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_274;
_sharp_pair_274,
(_sharp_pair_274 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_274).car) = (Id_Form)(intern( "first_parameter")));
(((* _sharp_pair_274).cdr) = ({
struct struct0x08095f28 *_sharp_pair_273;
_sharp_pair_273,
(_sharp_pair_273 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_273).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_273).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_273);
})
);
((List__O__Form__C____type__type ) _sharp_pair_274);
})
));
(((* _sharp_pair_276).cdr) = ({
struct struct0x08095f28 *_sharp_pair_275;
_sharp_pair_275,
(_sharp_pair_275 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_275).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_275).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_275);
})
);
((List__O__Form__C____type__type ) _sharp_pair_276);
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
(first_param_name = ((Id_Form__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) first_parameter)).form_list))).head)));
(first_param_type = ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) first_parameter)).form_list))).tail))).head));
(c_output_type)(intern( ""), (intern_type)(((Form__type ) first_param_type)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " "), " "})),
(print_Symbol)((convert_id)(((* ((struct struct0x080608f0 *) first_param_name)).value))),
(maybe_flush)();
({
List__O__Compound_Form__C____type__type _sharp_iterator278;
(_sharp_iterator278 = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) parameters_type)).form_list))).tail)));
((void) 0);_sharp__sharp_loop279_begin286:((void) 0),
({
Compound_Form__type parameter;
({if( (_sharp_iterator278 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop279_end280;});}})
;
(parameter = ((* ((struct struct0x08212a10 *) _sharp_iterator278)).car));
({
Id_Form__type param_name;
Form__type type;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(maybe_flush)();
({if( ((((* ((struct struct0x080659b0 *) first_parameter)).head) == intern( "label")) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_284;
_sharp_pair_284,
(_sharp_pair_284 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_284).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_282;
_sharp_pair_282,
(_sharp_pair_282 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_282).car) = (Id_Form)(intern( "first_parameter")));
(((* _sharp_pair_282).cdr) = ({
struct struct0x08095f28 *_sharp_pair_281;
_sharp_pair_281,
(_sharp_pair_281 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_281).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_281).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_281);
})
);
((List__O__Form__C____type__type ) _sharp_pair_282);
})
));
(((* _sharp_pair_284).cdr) = ({
struct struct0x08095f28 *_sharp_pair_283;
_sharp_pair_283,
(_sharp_pair_283 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_283).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_283).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_283);
})
);
((List__O__Form__C____type__type ) _sharp_pair_284);
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
(param_name = ((Id_Form__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) parameter)).form_list))).head)));
(type = ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) parameter)).form_list))).tail))).head));
(c_output_type)(intern( ""), (intern_type)(((Form__type ) type)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " "), " "})),
(print_Symbol)((convert_id)(((* ((struct struct0x080608f0 *) param_name)).value))),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop279_continue285:((void) 0);
(_sharp_iterator278 = ((* ((struct struct0x08212a10 *) _sharp_iterator278)).cdr));
})
,
({goto _sharp__sharp_loop279_begin286;}),
((void) 0);_sharp__sharp_loop279_end280:((void) 0);
})
;
})
));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")\n{\nreturn "), ")\n{\nreturn "})),
(maybe_flush)();
(c_output_form)(((Expanded_Form__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) form_list)).tail))).tail))).head))),
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
struct struct0x08095f28 *_sharp_pair_289;
_sharp_pair_289,
(_sharp_pair_289 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_289).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_288;
_sharp_pair_288,
(_sharp_pair_288 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_288).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_288).cdr) = ({
struct struct0x08095f28 *_sharp_pair_287;
_sharp_pair_287,
(_sharp_pair_287 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_287).car) = (Id_Form)(intern( "f")));
(((* _sharp_pair_287).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_287);
})
);
((List__O__Form__C____type__type ) _sharp_pair_288);
})
));
(((* _sharp_pair_289).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_289);
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
({if( ((((* ((struct struct0x080659b0 *) f)).head) == intern( "define")) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_293;
_sharp_pair_293,
(_sharp_pair_293 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_293).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_291;
_sharp_pair_291,
(_sharp_pair_291 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_291).car) = (Id_Form)(intern( "f")));
(((* _sharp_pair_291).cdr) = ({
struct struct0x08095f28 *_sharp_pair_290;
_sharp_pair_290,
(_sharp_pair_290 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_290).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_290).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_290);
})
);
((List__O__Form__C____type__type ) _sharp_pair_291);
})
));
(((* _sharp_pair_293).cdr) = ({
struct struct0x08095f28 *_sharp_pair_292;
_sharp_pair_292,
(_sharp_pair_292 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_292).car) = (Symbol_Form)(intern( "define")));
(((* _sharp_pair_292).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_292);
})
);
((List__O__Form__C____type__type ) _sharp_pair_293);
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
(form_list = ((List__O__Form__C____type__type ) ((* ((struct struct0x080659b0 *) ((Compound_Form__type ) f))).form_list)));
({if( ((is_id_form)(((* ((struct struct0x08065ba8 *) form_list)).head)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_296;
_sharp_pair_296,
(_sharp_pair_296 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_296).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_295;
_sharp_pair_295,
(_sharp_pair_295 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_295).car) = (Id_Form)(intern( "form_list")));
(((* _sharp_pair_295).cdr) = ({
struct struct0x08095f28 *_sharp_pair_294;
_sharp_pair_294,
(_sharp_pair_294 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_294).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_294).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_294);
})
);
((List__O__Form__C____type__type ) _sharp_pair_295);
})
));
(((* _sharp_pair_296).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_296);
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
(species = ((* ((struct struct0x080608f0 *) ((Id_Form__type ) ((* ((struct struct0x08065ba8 *) form_list)).head)))).value));
({if( ((is_id_form)(((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) form_list)).tail))).head)) == ((Bool__type ) 0)))
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
struct struct0x08095f28 *_sharp_pair_301;
_sharp_pair_301,
(_sharp_pair_301 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_301).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_300;
_sharp_pair_300,
(_sharp_pair_300 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_300).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08095f28 *_sharp_pair_298;
_sharp_pair_298,
(_sharp_pair_298 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_298).car) = (Id_Form)(intern( "form_list")));
(((* _sharp_pair_298).cdr) = ({
struct struct0x08095f28 *_sharp_pair_297;
_sharp_pair_297,
(_sharp_pair_297 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_297).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_297).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_297);
})
);
((List__O__Form__C____type__type ) _sharp_pair_298);
})
));
(((* _sharp_pair_300).cdr) = ({
struct struct0x08095f28 *_sharp_pair_299;
_sharp_pair_299,
(_sharp_pair_299 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_299).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_299).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_299);
})
);
((List__O__Form__C____type__type ) _sharp_pair_300);
})
));
(((* _sharp_pair_301).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_301);
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
(name = ((* ((struct struct0x080608f0 *) ((Id_Form__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) form_list)).tail))).head)))).value));
(((species == intern( "function")))?
(({
(c_output_function_definition)(name, ((Form__type ) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) form_list)).tail))).tail))).head)));
})
):
((((species == intern( "type")))?
(({
((void) 0);
})
):
((((species == intern( "global")))?
(({
(c_output_global_definition)(name, ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) form_list)).tail))).tail))).head));
((void) 0);
})
):
((((species == intern( "expander")))?
(({
Form__type funform;
(funform = ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) f)).form_list))).tail))).tail))).head));
(c_output_definition)(((Compound_Form__type ) funform));
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
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "/* Automatically generated : do not edit!*/\n"), "/* Automatically generated : do not edit!*/\n"})),
(maybe_flush)();
(print_Symbol)(intern( "#include \"")),
(print_String)((file_name_non_directory)(out_inc_file)),
(print_Symbol)(intern( "\"")),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "\n"), "\n"})),
(maybe_flush)();
({
List__O__Compound_Form__C____type__type _sharp_iterator303;
(_sharp_iterator303 = form_list);
((void) 0);_sharp__sharp_loop304_begin307:((void) 0),
({
Compound_Form__type f;
({if( (_sharp_iterator303 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop304_end305;});}})
;
(f = ((* ((struct struct0x08212a10 *) _sharp_iterator303)).car));
(c_output_definition)(f);
((void) 0);_sharp__sharp_loop304_continue306:((void) 0);
(_sharp_iterator303 = ((* ((struct struct0x08212a10 *) _sharp_iterator303)).cdr));
})
,
({goto _sharp__sharp_loop304_begin307;}),
((void) 0);_sharp__sharp_loop304_end305:((void) 0);
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
((void) 0);_sharp__sharp_loop309_begin313:((void) 0),
({
Bool__type _sharp_tuple312;
Symbol__type _sharp_tuple311;
Bool__type misc_;
Symbol__type symbol;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop309_end310;});}})
;
(_sharp_tuple311 = ((Symbol__type ) Index_)),
(_sharp_tuple312 = ((Bool__type ) (* PValue_))),
(symbol = _sharp_tuple311),
(misc_ = _sharp_tuple312);
({
Type__type t;
(t = (get_global_type)(symbol));
((Bool__type ) (puthash)(((void *) t), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) type_definition_needed)));
})
;
(PValue_ = (JudyLNext)((* ((void **) hash_)), ((void *) (&Index_)), 0));
})
,
({goto _sharp__sharp_loop309_begin313;}),
((void) 0);_sharp__sharp_loop309_end310:((void) 0);
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
((void) 0);_sharp__sharp_loop315_begin319:((void) 0),
({
Bool__type _sharp_tuple318;
Symbol__type _sharp_tuple317;
Bool__type misc_;
Symbol__type symbol;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop315_end316;});}})
;
(_sharp_tuple317 = ((Symbol__type ) Index_)),
(_sharp_tuple318 = ((Bool__type ) (* PValue_))),
(symbol = _sharp_tuple317),
(misc_ = _sharp_tuple318);
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
({goto _sharp__sharp_loop315_begin319;}),
((void) 0);_sharp__sharp_loop315_end316:((void) 0);
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
(doit)((&(struct { unsigned int len; char *content;}){strlen( "test.l"), "test.l"}), (&(struct { unsigned int len; char *content;}){strlen( "test.c"), "test.c"}), (&(struct { unsigned int len; char *content;}){strlen( "test.inc"), "test.inc"}));
})
;}

Form__type  print_error_sharp__sharp_expander_function(Compound_Form__type  form)
{
return ({
(Compound_Form)(intern( "block"), ({
struct struct0x08095f28 *_sharp_pair_11;
_sharp_pair_11,
(_sharp_pair_11 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_11).car) = (Compound_Form)(intern( "="), ({
struct struct0x08095f28 *_sharp_pair_2;
_sharp_pair_2,
(_sharp_pair_2 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_2).car) = (Compound_Form)(intern( "let"), ({
struct struct0x08095f28 *_sharp_pair_0;
_sharp_pair_0,
(_sharp_pair_0 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_0).car) = (Id_Form)(intern( "save_od_")));
(((* _sharp_pair_0).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_0);
})
));
(((* _sharp_pair_2).cdr) = ({
struct struct0x08095f28 *_sharp_pair_1;
_sharp_pair_1,
(_sharp_pair_1 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_1).car) = (Id_Form)(intern( "current_output_descriptor")));
(((* _sharp_pair_1).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_1);
})
);
((List__O__Form__C____type__type ) _sharp_pair_2);
})
));
(((* _sharp_pair_11).cdr) = ({
struct struct0x08095f28 *_sharp_pair_10;
_sharp_pair_10,
(_sharp_pair_10 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_10).car) = (Compound_Form)(intern( "="), ({
struct struct0x08095f28 *_sharp_pair_4;
_sharp_pair_4,
(_sharp_pair_4 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_4).car) = (Id_Form)(intern( "current_output_descriptor")));
(((* _sharp_pair_4).cdr) = ({
struct struct0x08095f28 *_sharp_pair_3;
_sharp_pair_3,
(_sharp_pair_3 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_3).car) = (Id_Form)(intern( "stdout_descriptor")));
(((* _sharp_pair_3).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_3);
})
);
((List__O__Form__C____type__type ) _sharp_pair_4);
})
));
(((* _sharp_pair_10).cdr) = ({
struct struct0x08095f28 *_sharp_pair_9;
_sharp_pair_9,
(_sharp_pair_9 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_9).car) = (Compound_Form)(intern( "print"), ((* ((struct struct0x080659b0 *) form)).form_list)));
(((* _sharp_pair_9).cdr) = ({
struct struct0x08095f28 *_sharp_pair_8;
_sharp_pair_8,
(_sharp_pair_8 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_8).car) = (Compound_Form)(intern( "flush"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_8).cdr) = ({
struct struct0x08095f28 *_sharp_pair_7;
_sharp_pair_7,
(_sharp_pair_7 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_7).car) = (Compound_Form)(intern( "="), ({
struct struct0x08095f28 *_sharp_pair_6;
_sharp_pair_6,
(_sharp_pair_6 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_6).car) = (Id_Form)(intern( "current_output_descriptor")));
(((* _sharp_pair_6).cdr) = ({
struct struct0x08095f28 *_sharp_pair_5;
_sharp_pair_5,
(_sharp_pair_5 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_5).car) = (Id_Form)(intern( "save_od_")));
(((* _sharp_pair_5).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_5);
})
);
((List__O__Form__C____type__type ) _sharp_pair_6);
})
));
(((* _sharp_pair_7).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_7);
})
);
((List__O__Form__C____type__type ) _sharp_pair_8);
})
);
((List__O__Form__C____type__type ) _sharp_pair_9);
})
);
((List__O__Form__C____type__type ) _sharp_pair_10);
})
);
((List__O__Form__C____type__type ) _sharp_pair_11);
})
);
})
;}

Form__type  panic_sharp__sharp_expander_function(Compound_Form__type  form)
{
return ({
(Compound_Form)(intern( "block"), ({
struct struct0x08095f28 *_sharp_pair_19;
_sharp_pair_19,
(_sharp_pair_19 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_19).car) = (Compound_Form)(intern( "="), ({
struct struct0x08095f28 *_sharp_pair_13;
_sharp_pair_13,
(_sharp_pair_13 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_13).car) = (Id_Form)(intern( "current_output_descriptor")));
(((* _sharp_pair_13).cdr) = ({
struct struct0x08095f28 *_sharp_pair_12;
_sharp_pair_12,
(_sharp_pair_12 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_12).car) = (Id_Form)(intern( "stdout_descriptor")));
(((* _sharp_pair_12).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_12);
})
);
((List__O__Form__C____type__type ) _sharp_pair_13);
})
));
(((* _sharp_pair_19).cdr) = ({
struct struct0x08095f28 *_sharp_pair_18;
_sharp_pair_18,
(_sharp_pair_18 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_18).car) = (Compound_Form)(intern( "print"), ({
struct struct0x08095f28 *_sharp_pair_14;
_sharp_pair_14,
(_sharp_pair_14 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_14).car) = (String_Form)((&(struct { unsigned int len; char *content;}){strlen( "Panic : "), "Panic : "})));
(((* _sharp_pair_14).cdr) = ((* ((struct struct0x080659b0 *) form)).form_list));
((List__O__Form__C____type__type ) _sharp_pair_14);
})
));
(((* _sharp_pair_18).cdr) = ({
struct struct0x08095f28 *_sharp_pair_17;
_sharp_pair_17,
(_sharp_pair_17 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_17).car) = (Compound_Form)(intern( "flush"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_17).cdr) = ({
struct struct0x08095f28 *_sharp_pair_16;
_sharp_pair_16,
(_sharp_pair_16 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_16).car) = (Compound_Form)(intern( "exit"), ({
struct struct0x08095f28 *_sharp_pair_15;
_sharp_pair_15,
(_sharp_pair_15 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_15).car) = (Int_Form)(3));
(((* _sharp_pair_15).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_15);
})
));
(((* _sharp_pair_16).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_16);
})
);
((List__O__Form__C____type__type ) _sharp_pair_17);
})
);
((List__O__Form__C____type__type ) _sharp_pair_18);
})
);
((List__O__Form__C____type__type ) _sharp_pair_19);
})
);
})
;}

Form__type  assert_sharp__sharp_expander_function(Compound_Form__type  _sharp_form20)
{
return ({
Form__type condition;
(condition = ((* ((struct struct0x08065ba8 *) ((* ((struct struct0x080659b0 *) _sharp_form20)).form_list))).head));
(Compound_Form)(intern( "if"), ({
struct struct0x08095f28 *_sharp_pair_35;
_sharp_pair_35,
(_sharp_pair_35 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_35).car) = (Compound_Form)(intern( "=="), ({
struct struct0x08095f28 *_sharp_pair_24;
_sharp_pair_24,
(_sharp_pair_24 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_24).car) = condition);
(((* _sharp_pair_24).cdr) = ({
struct struct0x08095f28 *_sharp_pair_23;
_sharp_pair_23,
(_sharp_pair_23 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_23).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08095f28 *_sharp_pair_22;
_sharp_pair_22,
(_sharp_pair_22 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_22).car) = (Id_Form)(intern( "Bool")));
(((* _sharp_pair_22).cdr) = ({
struct struct0x08095f28 *_sharp_pair_21;
_sharp_pair_21,
(_sharp_pair_21 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_21).car) = (Int_Form)(0));
(((* _sharp_pair_21).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_21);
})
);
((List__O__Form__C____type__type ) _sharp_pair_22);
})
));
(((* _sharp_pair_23).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_23);
})
);
((List__O__Form__C____type__type ) _sharp_pair_24);
})
));
(((* _sharp_pair_35).cdr) = ({
struct struct0x08095f28 *_sharp_pair_34;
_sharp_pair_34,
(_sharp_pair_34 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_34).car) = (Compound_Form)(intern( "block"), ({
struct struct0x08095f28 *_sharp_pair_33;
_sharp_pair_33,
(_sharp_pair_33 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_33).car) = (Compound_Form)(intern( "print_error"), ({
struct struct0x08095f28 *_sharp_pair_25;
_sharp_pair_25,
(_sharp_pair_25 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_25).car) = (String_Form)((&(struct { unsigned int len; char *content;}){strlen( "Assertion "), "Assertion "})));
(((* _sharp_pair_25).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_25);
})
));
(((* _sharp_pair_33).cdr) = ({
struct struct0x08095f28 *_sharp_pair_32;
_sharp_pair_32,
(_sharp_pair_32 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_32).car) = (Compound_Form)(intern( "print_form"), ({
struct struct0x08095f28 *_sharp_pair_27;
_sharp_pair_27,
(_sharp_pair_27 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_27).car) = (Compound_Form)(intern( "Form"), ({
struct struct0x08095f28 *_sharp_pair_26;
_sharp_pair_26,
(_sharp_pair_26 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_26).car) = condition);
(((* _sharp_pair_26).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_26);
})
));
(((* _sharp_pair_27).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_27);
})
));
(((* _sharp_pair_32).cdr) = ({
struct struct0x08095f28 *_sharp_pair_31;
_sharp_pair_31,
(_sharp_pair_31 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_31).car) = (Compound_Form)(intern( "print_error"), ({
struct struct0x08095f28 *_sharp_pair_28;
_sharp_pair_28,
(_sharp_pair_28 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_28).car) = (String_Form)((&(struct { unsigned int len; char *content;}){strlen( " failed\n"), " failed\n"})));
(((* _sharp_pair_28).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_28);
})
));
(((* _sharp_pair_31).cdr) = ({
struct struct0x08095f28 *_sharp_pair_30;
_sharp_pair_30,
(_sharp_pair_30 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_30).car) = (Compound_Form)(intern( "exit"), ({
struct struct0x08095f28 *_sharp_pair_29;
_sharp_pair_29,
(_sharp_pair_29 = ((struct struct0x08095f28 *) (alloc_cons_cell)()));
(((* _sharp_pair_29).car) = (Int_Form)(3));
(((* _sharp_pair_29).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_29);
})
));
(((* _sharp_pair_30).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_30);
})
);
((List__O__Form__C____type__type ) _sharp_pair_31);
})
);
((List__O__Form__C____type__type ) _sharp_pair_32);
})
);
((List__O__Form__C____type__type ) _sharp_pair_33);
})
));
(((* _sharp_pair_34).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_34);
})
);
((List__O__Form__C____type__type ) _sharp_pair_35);
})
);
})
;}

void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( "TEST result: %d", test_ptr());flush();}
