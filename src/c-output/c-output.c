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
(((* ((struct struct0x08063990 *) rf)).form_type_) == 1811939328);
})
;}

Bool__type  is_expanded_form(Form__type  f)
{
return ({
(((* ((struct struct0x08063990 *) f)).form_type_) == (- (int) 536870912));
})
;}

Bool__type  is_id_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x08063990 *) rf)).form_type_) == (- (int) 1342177280));
})
;}

Bool__type  is_int_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x08063990 *) rf)).form_type_) == (- (int) -2147483648));
})
;}

Bool__type  is_symbol_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x08063990 *) rf)).form_type_) == (- (int) 1073741824));
})
;}

Bool__type  is_string_form(Form__type  f)
{
return ({
Form__type rf;
(rf = ((Form__type ) f));
(((* ((struct struct0x08063990 *) rf)).form_type_) == (- (int) 1610612736));
})
;}

Bool__type  is_struct_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) nt)).common_)).type_type) == 0);
})
;}

Bool__type  is_base_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) nt)).common_)).type_type) == 3);
})
;}

Bool__type  is_pointer_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) nt)).common_)).type_type) == 4);
})
;}

Bool__type  is_tuple_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) nt)).common_)).type_type) == 2);
})
;}

Bool__type  is_function_type(Type__type  t)
{
return ({
Real_Type__type nt;
(nt = ((Real_Type__type ) t));
((((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) nt)).common_)).type_type) == 1);
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
(((((* ((struct struct0x08063e58 *) bt)).origin_type) == ((Type__type ) 0)))?
(({
({if( ((is_id_form)((((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) bt))).common_)).type_form)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_145;
_sharp_pair_145,
(_sharp_pair_145 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_145).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_144;
_sharp_pair_144,
(_sharp_pair_144 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_144).car) = (Id_Form)(intern( "bt")));
(((* _sharp_pair_144).cdr) = ({
struct struct0x08096a90 *_sharp_pair_143;
_sharp_pair_143,
(_sharp_pair_143 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_143).car) = (Symbol_Form)(intern( "type_form")));
(((* _sharp_pair_143).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_143);
})
);
((List__O__Form__C____type__type ) _sharp_pair_144);
})
));
(((* _sharp_pair_145).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_145);
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
(print_Symbol)(((* ((struct struct0x0805fe70 *) ((Id_Form__type ) (((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) bt))).common_)).type_form)))).value)),
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
(c_output_type)((prepend_star)(name), (intern_type)(((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) ((Compound_Form__type ) (((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) t))).common_)).type_form)))).form_list))).head)));
})
):
((((is_tuple_type)(t))?
(({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) t))).common_)).type_form)));
(((((* ((struct struct0x08065108 *) tf)).form_list) == ((List__O__Form__C____type__type ) 0)))?
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "void "), "void "})),
(print_Symbol)(name),
(maybe_flush)();
})
):
(({
(print_form)((((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) t))).common_)).type_form));
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
(form_list = ((* ((struct struct0x08065108 *) ((Compound_Form__type ) (((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) t))).common_)).type_form)))).form_list));
(return_type = (intern_type)(((* ((struct struct0x08060190 *) form_list)).head)));
(c_output_type)(intern( ""), return_type);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(print_Symbol)(name),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"})),
(maybe_flush)();
(parameters = ((Compound_Form__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) form_list)).tail))).head)));
(((((* ((struct struct0x08065108 *) parameters)).form_list) == ((List__O__Form__C____type__type ) 0)))?
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(void)"), "(void)"})),
(maybe_flush)();
})
):
(({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(maybe_flush)();
(c_output_type)(intern( ""), (intern_type)(((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) parameters)).form_list))).head)));
({
List__O__Form__C____type__type _sharp_iterator147;
(_sharp_iterator147 = ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) parameters)).form_list))).tail));
((void) 0);_sharp__sharp_loop148_begin151:((void) 0),
({
Form__type parameter;
({if( (_sharp_iterator147 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop148_end149;});}})
;
(parameter = ((* ((struct struct0x08096a90 *) _sharp_iterator147)).car));
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(maybe_flush)();
(c_output_type)(intern( ""), (intern_type)(parameter));
})
;
((void) 0);_sharp__sharp_loop148_continue150:((void) 0);
(_sharp_iterator147 = ((* ((struct struct0x08096a90 *) _sharp_iterator147)).cdr));
})
,
({goto _sharp__sharp_loop148_begin151;}),
((void) 0);_sharp__sharp_loop148_end149:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"})),
(maybe_flush)();
})
));
})
):
(({
(print_form)((((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) t))).common_)).type_form));
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
({if( (((* ((struct struct0x08063e58 *) bt)).origin_type) == ((Type__type ) 0)))
{
({
({goto end;});
})
;}})
;
({if( ((Bool__type ) (gethash)(((void *) ((* ((struct struct0x08063e58 *) bt)).origin_type)), ((Hash_Table__type ) has_been_outputed))))
{
({
({goto next;});
})
;}})
;
(c_output_type_definition)(((* ((struct struct0x08063e58 *) bt)).origin_type));
((void) 0);next:((void) 0),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "typedef "), "typedef "})),
(maybe_flush)();
(c_output_type)((mangle_type_name)(t), ((* ((struct struct0x08063e58 *) bt)).origin_type));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "__type"), "__type"})),
(maybe_flush)();
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n"), ";\n"})),
(maybe_flush)();
})
):
((((is_struct_type)(t))?
(({
Form__type tf;
(tf = (((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) t))).common_)).type_form));
({
List__O__Form__C____type__type _sharp_iterator153;
(_sharp_iterator153 = ((* ((struct struct0x08065108 *) ((Compound_Form__type ) tf))).form_list));
((void) 0);_sharp__sharp_loop154_begin162:((void) 0),
({
Form__type label_form_;
({if( (_sharp_iterator153 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop154_end155;});}})
;
(label_form_ = ((* ((struct struct0x08096a90 *) _sharp_iterator153)).car));
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
struct struct0x08096a90 *_sharp_pair_156;
_sharp_pair_156,
(_sharp_pair_156 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_156).car) = (Id_Form)(intern( "label_form_")));
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
(label_form = ((Compound_Form__type ) label_form_));
({if( ((((* ((struct struct0x08065108 *) label_form)).head) == intern( "label")) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_160;
_sharp_pair_160,
(_sharp_pair_160 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_160).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_158;
_sharp_pair_158,
(_sharp_pair_158 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_158).car) = (Id_Form)(intern( "label_form")));
(((* _sharp_pair_158).cdr) = ({
struct struct0x08096a90 *_sharp_pair_157;
_sharp_pair_157,
(_sharp_pair_157 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_157).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_157).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_157);
})
);
((List__O__Form__C____type__type ) _sharp_pair_158);
})
));
(((* _sharp_pair_160).cdr) = ({
struct struct0x08096a90 *_sharp_pair_159;
_sharp_pair_159,
(_sharp_pair_159 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_159).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_159).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_159);
})
);
((List__O__Form__C____type__type ) _sharp_pair_160);
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
(subtf = ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) label_form)).form_list))).tail))).head));
(subtype = (intern_type)(subtf));
({if( ((Bool__type ) (gethash)(((void *) subtype), ((Hash_Table__type ) has_been_outputed))))
{
({goto _sharp__sharp_loop154_continue161;});}})
;
(c_output_type_definition)(subtype);
})
;
((void) 0);_sharp__sharp_loop154_continue161:((void) 0);
(_sharp_iterator153 = ((* ((struct struct0x08096a90 *) _sharp_iterator153)).cdr));
})
,
({goto _sharp__sharp_loop154_begin162;}),
((void) 0);_sharp__sharp_loop154_end155:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "struct struct"), "struct struct"})),
(print_Int_Hex)(((Int__type ) t)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " {\n"), " {\n"})),
(maybe_flush)();
({
List__O__Form__C____type__type _sharp_iterator164;
(_sharp_iterator164 = ((* ((struct struct0x08065108 *) ((Compound_Form__type ) tf))).form_list));
((void) 0);_sharp__sharp_loop165_begin173:((void) 0),
({
Form__type label_form_;
({if( (_sharp_iterator164 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop165_end166;});}})
;
(label_form_ = ((* ((struct struct0x08096a90 *) _sharp_iterator164)).car));
({
Symbol__type field_name;
Type__type subtype;
Form__type subtf;
Compound_Form__type label_form;
(label_form = ((Compound_Form__type ) label_form_));
({if( ((is_id_form)(((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) label_form)).form_list))).head)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_171;
_sharp_pair_171,
(_sharp_pair_171 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_171).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_170;
_sharp_pair_170,
(_sharp_pair_170 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_170).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_168;
_sharp_pair_168,
(_sharp_pair_168 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_168).car) = (Id_Form)(intern( "label_form")));
(((* _sharp_pair_168).cdr) = ({
struct struct0x08096a90 *_sharp_pair_167;
_sharp_pair_167,
(_sharp_pair_167 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_167).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_167).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_167);
})
);
((List__O__Form__C____type__type ) _sharp_pair_168);
})
));
(((* _sharp_pair_170).cdr) = ({
struct struct0x08096a90 *_sharp_pair_169;
_sharp_pair_169,
(_sharp_pair_169 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_169).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_169).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_169);
})
);
((List__O__Form__C____type__type ) _sharp_pair_170);
})
));
(((* _sharp_pair_171).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_171);
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
(field_name = ((* ((struct struct0x0805fe70 *) ((Id_Form__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) label_form)).form_list))).head)))).value));
(subtf = ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) label_form)).form_list))).tail))).head));
(subtype = (intern_type)(subtf));
(c_output_type)(field_name, subtype);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n"), ";\n"})),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop165_continue172:((void) 0);
(_sharp_iterator164 = ((* ((struct struct0x08096a90 *) _sharp_iterator164)).cdr));
})
,
({goto _sharp__sharp_loop165_begin173;}),
((void) 0);_sharp__sharp_loop165_end166:((void) 0);
})
;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "};\n"), "};\n"})),
(maybe_flush)();
})
):
((((is_pointer_type)(t))?
(({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) t))).common_)).type_form)));
({if( (is_compound_form)(((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) tf)).form_list))).head)))
{
({
Compound_Form__type ptf;
(ptf = ((Compound_Form__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) tf)).form_list))).head)));
({if( (((* ((struct struct0x08065108 *) ptf)).head) == intern( "struct")))
{
({goto end;});}})
;
})
;}})
;
(c_output_type_definition)((intern_type)(((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) tf)).form_list))).head)));
})
):
((((is_function_type)(t))?
(({
Type__type from_type;
Type__type to_type;
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) t))).common_)).type_form)));
(to_type = (intern_type)(((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) tf)).form_list))).head)));
(c_output_type_definition)(to_type);
(from_type = (intern_type)(((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) tf)).form_list))).tail))).head)));
(c_output_type_definition)(from_type);
})
):
(({if( (is_tuple_type)(t))
{
({
Compound_Form__type tf;
(tf = ((Compound_Form__type ) (((struct struct0x08094938 ) ((* ((struct struct0x08094bd0 *) ((Real_Type__type ) t))).common_)).type_form)));
({
List__O__Form__C____type__type _sharp_iterator175;
(_sharp_iterator175 = ((* ((struct struct0x08065108 *) tf)).form_list));
((void) 0);_sharp__sharp_loop176_begin179:((void) 0),
({
Form__type subform;
({if( (_sharp_iterator175 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop176_end177;});}})
;
(subform = ((* ((struct struct0x08096a90 *) _sharp_iterator175)).car));
({
Type__type type;
(type = (intern_type)(subform));
(c_output_type_definition)(type);
})
;
((void) 0);_sharp__sharp_loop176_continue178:((void) 0);
(_sharp_iterator175 = ((* ((struct struct0x08096a90 *) _sharp_iterator175)).cdr));
})
,
({goto _sharp__sharp_loop176_begin179;}),
((void) 0);_sharp__sharp_loop176_end177:((void) 0);
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
((void) 0);_sharp__sharp_loop180_begin184:((void) 0),
({
Bool__type _sharp_tuple183;
Type__type _sharp_tuple182;
Bool__type bool;
Type__type type;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop180_end181;});}})
;
(_sharp_tuple182 = ((Type__type ) Index_)),
(_sharp_tuple183 = ((Bool__type ) (* PValue_))),
(type = _sharp_tuple182),
(bool = _sharp_tuple183);
({
({if( bool)
{
({
(c_output_type_definition)(type);
})
;}})
;
((void) 0);
})
;
(PValue_ = (JudyLNext)((* ((void **) hash_)), ((void *) (&Index_)), 0));
})
,
({goto _sharp__sharp_loop180_begin184;}),
((void) 0);_sharp__sharp_loop180_end181:((void) 0);
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
(f = ((* ((struct struct0x080664c8 *) expf)).return_form));
(((is_compound_form)(f))?
(({
void (*fun)(Expanded_Compound_Form__type );
Compound_Form__type cf;
(cf = ((Compound_Form__type ) f));
(fun = ((void (*)(Expanded_Compound_Form__type )) (gethash)(((void *) ((* ((struct struct0x08065108 *) cf)).head)), ((Hash_Table__type ) c_output_hash))));
({if( (fun == ((void (*)(Expanded_Compound_Form__type )) 0)))
{
({
({
(current_output_descriptor = stdout_descriptor);
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "Panic : "), "Panic : "})),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "No output function defined for "), "No output function defined for "})),
(print_Symbol)(((* ((struct struct0x08065108 *) cf)).head)),
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
(print_Symbol)((convert_id)(((* ((struct struct0x0805fe70 *) id_form)).value)));
})
):
((((is_int_form)(f))?
(({
Int_Form__type int_form;
(int_form = ((Int_Form__type ) f));
(print_Int_Dec)(((* ((struct struct0x080642f0 *) int_form)).value));
})
):
((((is_symbol_form)(f))?
(({
Symbol_Form__type symbol_form;
(symbol_form = ((Symbol_Form__type ) f));
(print_Symbol)(intern( "intern( \"")),
(print_String)((convert_id_as_string)(((* ((struct struct0x0805fe70 *) symbol_form)).value))),
(print_Symbol)(intern( "\")"));
})
):
((((is_string_form)(f))?
(({
String__type string;
String_Form__type string_form;
(string_form = ((String_Form__type ) f));
(string = (convert_string)(((* ((struct struct0x08061558 *) string_form)).value)));
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
(print_Int_Dec)(((* ((struct struct0x08063990 *) ((Form__type ) f))).form_type_));
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
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " + (int) "), " + (int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_mul_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " * (int) "), " * (int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_sub_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " - (int) "), " - (int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_div_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " / (int) "), " / (int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_unary_minus_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(- (int) "), "(- (int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_ge_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " >= (int) "), " >= (int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_gt_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " > (int) "), " > (int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_le_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " <= (int) "), " <= (int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_lt_int(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((int) "), "((int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " < (int) "), " < (int) "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_different(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " != "), " != "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_equal(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " == "), " == "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_access_struct(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "."), "."}));
({if( ((is_symbol_form)(((* ((struct struct0x080664c8 *) ((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head))).return_form)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_193;
_sharp_pair_193,
(_sharp_pair_193 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_193).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_192;
_sharp_pair_192,
(_sharp_pair_192 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_192).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_190;
_sharp_pair_190,
(_sharp_pair_190 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_190).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_188;
_sharp_pair_188,
(_sharp_pair_188 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_188).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_186;
_sharp_pair_186,
(_sharp_pair_186 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_186).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_186).cdr) = ({
struct struct0x08096a90 *_sharp_pair_185;
_sharp_pair_185,
(_sharp_pair_185 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_185).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_185).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_185);
})
);
((List__O__Form__C____type__type ) _sharp_pair_186);
})
));
(((* _sharp_pair_188).cdr) = ({
struct struct0x08096a90 *_sharp_pair_187;
_sharp_pair_187,
(_sharp_pair_187 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_187).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_187).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_187);
})
);
((List__O__Form__C____type__type ) _sharp_pair_188);
})
));
(((* _sharp_pair_190).cdr) = ({
struct struct0x08096a90 *_sharp_pair_189;
_sharp_pair_189,
(_sharp_pair_189 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_189).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_189).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_189);
})
);
((List__O__Form__C____type__type ) _sharp_pair_190);
})
));
(((* _sharp_pair_192).cdr) = ({
struct struct0x08096a90 *_sharp_pair_191;
_sharp_pair_191,
(_sharp_pair_191 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_191).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_191).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_191);
})
);
((List__O__Form__C____type__type ) _sharp_pair_192);
})
));
(((* _sharp_pair_193).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_193);
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
(print_Symbol)(((* ((struct struct0x0805fe70 *) ((Symbol_Form__type ) ((* ((struct struct0x080664c8 *) ((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head))).return_form)))).value)),
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
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " = "), " = "}));
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head));
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
List__O__Expanded_Form__C____type__type _sharp_iterator195;
(_sharp_iterator195 = ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)));
((void) 0);_sharp__sharp_loop196_begin199:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator195 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop196_end197;});}})
;
(subform = ((* ((struct struct0x081eb830 *) _sharp_iterator195)).car));
({
(c_output_form)(subform),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";\n"), ";\n"}));
})
;
((void) 0);_sharp__sharp_loop196_continue198:((void) 0);
(_sharp_iterator195 = ((* ((struct struct0x081eb830 *) _sharp_iterator195)).cdr));
})
,
({goto _sharp__sharp_loop196_begin199;}),
((void) 0);_sharp__sharp_loop196_end197:((void) 0);
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
(c_output_type)(intern( ""), (intern_type)(((* ((struct struct0x080664c8 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head))).return_form)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ") "), ") "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;
})
;}

void  c_output_deref(Expanded_Compound_Form__type  cf)
{
return ({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(* "), "(* "})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;}

void  c_output_funcall(Expanded_Compound_Form__type  cf)
{
return ({
Expanded_Form__type function;
(function = ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head));
({if( (is_id_form)(((* ((struct struct0x080664c8 *) function)).return_form)))
{
({
((Bool__type ) (puthash)(((void *) ((* ((struct struct0x0805fe70 *) ((Id_Form__type ) ((* ((struct struct0x080664c8 *) function)).return_form)))).value)), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) globals_needed)));
})
;}})
;
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(c_output_form)(function),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")("), ")("}));
({if( (((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail) != ((List__O__Expanded_Form__C____type__type ) 0)))
{
({
(c_output_form)(((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head));
({
List__O__Expanded_Form__C____type__type _sharp_iterator201;
(_sharp_iterator201 = ((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).tail));
((void) 0);_sharp__sharp_loop202_begin205:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator201 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop202_end203;});}})
;
(subform = ((* ((struct struct0x081eb830 *) _sharp_iterator201)).car));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(c_output_form)(subform);
((void) 0);_sharp__sharp_loop202_continue204:((void) 0);
(_sharp_iterator201 = ((* ((struct struct0x081eb830 *) _sharp_iterator201)).cdr));
})
,
({goto _sharp__sharp_loop202_begin205;}),
((void) 0);_sharp__sharp_loop202_end203:((void) 0);
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
(condition = ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head));
(then = ((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head));
({
(((((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)))?
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
(elsef = ((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).tail))).head));
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
({if( ((((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_214;
_sharp_pair_214,
(_sharp_pair_214 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_214).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_209;
_sharp_pair_209,
(_sharp_pair_209 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_209).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_207;
_sharp_pair_207,
(_sharp_pair_207 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_207).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_207).cdr) = ({
struct struct0x08096a90 *_sharp_pair_206;
_sharp_pair_206,
(_sharp_pair_206 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_206).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_206).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_206);
})
);
((List__O__Form__C____type__type ) _sharp_pair_207);
})
));
(((* _sharp_pair_209).cdr) = ({
struct struct0x08096a90 *_sharp_pair_208;
_sharp_pair_208,
(_sharp_pair_208 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_208).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_208).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_208);
})
);
((List__O__Form__C____type__type ) _sharp_pair_209);
})
));
(((* _sharp_pair_214).cdr) = ({
struct struct0x08096a90 *_sharp_pair_213;
_sharp_pair_213,
(_sharp_pair_213 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_213).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_212;
_sharp_pair_212,
(_sharp_pair_212 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_212).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08096a90 *_sharp_pair_210;
_sharp_pair_210,
(_sharp_pair_210 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_210).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_210).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_210);
})
));
(((* _sharp_pair_212).cdr) = ({
struct struct0x08096a90 *_sharp_pair_211;
_sharp_pair_211,
(_sharp_pair_211 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_211).car) = (Int_Form)(0));
(((* _sharp_pair_211).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_211);
})
);
((List__O__Form__C____type__type ) _sharp_pair_212);
})
));
(((* _sharp_pair_213).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_213);
})
);
((List__O__Form__C____type__type ) _sharp_pair_214);
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
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_221;
_sharp_pair_221,
(_sharp_pair_221 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_221).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_220;
_sharp_pair_220,
(_sharp_pair_220 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_220).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_220).cdr) = ({
struct struct0x08096a90 *_sharp_pair_219;
_sharp_pair_219,
(_sharp_pair_219 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_219).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_218;
_sharp_pair_218,
(_sharp_pair_218 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_218).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_216;
_sharp_pair_216,
(_sharp_pair_216 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_216).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_216).cdr) = ({
struct struct0x08096a90 *_sharp_pair_215;
_sharp_pair_215,
(_sharp_pair_215 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_215).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_215).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_215);
})
);
((List__O__Form__C____type__type ) _sharp_pair_216);
})
));
(((* _sharp_pair_218).cdr) = ({
struct struct0x08096a90 *_sharp_pair_217;
_sharp_pair_217,
(_sharp_pair_217 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_217).car) = (Symbol_Form)(intern( "head")));
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
);
((List__O__Form__C____type__type ) _sharp_pair_220);
})
));
(((* _sharp_pair_221).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_221);
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
(label_form = ((Id_Form__type ) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "&&"), "&&"})),
(print_Symbol)((convert_id)(((* ((struct struct0x0805fe70 *) label_form)).value)));
})
;}

void  c_output_goto_constant(Expanded_Compound_Form__type  cf)
{
return ({
Id_Form__type id_form;
({if( ((((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_230;
_sharp_pair_230,
(_sharp_pair_230 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_230).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_225;
_sharp_pair_225,
(_sharp_pair_225 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_225).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_223;
_sharp_pair_223,
(_sharp_pair_223 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_223).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_223).cdr) = ({
struct struct0x08096a90 *_sharp_pair_222;
_sharp_pair_222,
(_sharp_pair_222 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_222).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_222).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_222);
})
);
((List__O__Form__C____type__type ) _sharp_pair_223);
})
));
(((* _sharp_pair_225).cdr) = ({
struct struct0x08096a90 *_sharp_pair_224;
_sharp_pair_224,
(_sharp_pair_224 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_224).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_224).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_224);
})
);
((List__O__Form__C____type__type ) _sharp_pair_225);
})
));
(((* _sharp_pair_230).cdr) = ({
struct struct0x08096a90 *_sharp_pair_229;
_sharp_pair_229,
(_sharp_pair_229 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_229).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_228;
_sharp_pair_228,
(_sharp_pair_228 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_228).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08096a90 *_sharp_pair_226;
_sharp_pair_226,
(_sharp_pair_226 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_226).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_226).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_226);
})
));
(((* _sharp_pair_228).cdr) = ({
struct struct0x08096a90 *_sharp_pair_227;
_sharp_pair_227,
(_sharp_pair_227 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_227).car) = (Int_Form)(0));
(((* _sharp_pair_227).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_227);
})
);
((List__O__Form__C____type__type ) _sharp_pair_228);
})
));
(((* _sharp_pair_229).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_229);
})
);
((List__O__Form__C____type__type ) _sharp_pair_230);
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
(id_form = ((Id_Form__type ) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)));
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
struct struct0x08096a90 *_sharp_pair_233;
_sharp_pair_233,
(_sharp_pair_233 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_233).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_232;
_sharp_pair_232,
(_sharp_pair_232 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_232).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_232).cdr) = ({
struct struct0x08096a90 *_sharp_pair_231;
_sharp_pair_231,
(_sharp_pair_231 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_231).car) = (Id_Form)(intern( "id_form")));
(((* _sharp_pair_231).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_231);
})
);
((List__O__Form__C____type__type ) _sharp_pair_232);
})
));
(((* _sharp_pair_233).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_233);
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
(print_Symbol)((convert_id)(((* ((struct struct0x0805fe70 *) id_form)).value))),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";})"), ";})"}));
})
;}

void  c_output_goto_variable(Expanded_Compound_Form__type  cf)
{
return ({
({if( ((((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_242;
_sharp_pair_242,
(_sharp_pair_242 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_242).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_237;
_sharp_pair_237,
(_sharp_pair_237 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_237).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_235;
_sharp_pair_235,
(_sharp_pair_235 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_235).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_235).cdr) = ({
struct struct0x08096a90 *_sharp_pair_234;
_sharp_pair_234,
(_sharp_pair_234 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_234).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_234).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_234);
})
);
((List__O__Form__C____type__type ) _sharp_pair_235);
})
));
(((* _sharp_pair_237).cdr) = ({
struct struct0x08096a90 *_sharp_pair_236;
_sharp_pair_236,
(_sharp_pair_236 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_236).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_236).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_236);
})
);
((List__O__Form__C____type__type ) _sharp_pair_237);
})
));
(((* _sharp_pair_242).cdr) = ({
struct struct0x08096a90 *_sharp_pair_241;
_sharp_pair_241,
(_sharp_pair_241 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_241).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_240;
_sharp_pair_240,
(_sharp_pair_240 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_240).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08096a90 *_sharp_pair_238;
_sharp_pair_238,
(_sharp_pair_238 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_238).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_238).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_238);
})
));
(((* _sharp_pair_240).cdr) = ({
struct struct0x08096a90 *_sharp_pair_239;
_sharp_pair_239,
(_sharp_pair_239 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_239).car) = (Int_Form)(0));
(((* _sharp_pair_239).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_239);
})
);
((List__O__Form__C____type__type ) _sharp_pair_240);
})
));
(((* _sharp_pair_241).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_241);
})
);
((List__O__Form__C____type__type ) _sharp_pair_242);
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
({if( ((is_compound_form)(((* ((struct struct0x080664c8 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head))).return_form)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_249;
_sharp_pair_249,
(_sharp_pair_249 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_249).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_248;
_sharp_pair_248,
(_sharp_pair_248 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_248).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_246;
_sharp_pair_246,
(_sharp_pair_246 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_246).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_244;
_sharp_pair_244,
(_sharp_pair_244 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_244).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_244).cdr) = ({
struct struct0x08096a90 *_sharp_pair_243;
_sharp_pair_243,
(_sharp_pair_243 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_243).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_243).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_243);
})
);
((List__O__Form__C____type__type ) _sharp_pair_244);
})
));
(((* _sharp_pair_246).cdr) = ({
struct struct0x08096a90 *_sharp_pair_245;
_sharp_pair_245,
(_sharp_pair_245 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_245).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_245).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_245);
})
);
((List__O__Form__C____type__type ) _sharp_pair_246);
})
));
(((* _sharp_pair_248).cdr) = ({
struct struct0x08096a90 *_sharp_pair_247;
_sharp_pair_247,
(_sharp_pair_247 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_247).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_247).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_247);
})
);
((List__O__Form__C____type__type ) _sharp_pair_248);
})
));
(((* _sharp_pair_249).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_249);
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
({if( ((((* ((struct struct0x08065108 *) ((Compound_Form__type ) ((* ((struct struct0x080664c8 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head))).return_form)))).head) == intern( "deref")) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_261;
_sharp_pair_261,
(_sharp_pair_261 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_261).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_259;
_sharp_pair_259,
(_sharp_pair_259 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_259).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_257;
_sharp_pair_257,
(_sharp_pair_257 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_257).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_257).cdr) = ({
struct struct0x08096a90 *_sharp_pair_256;
_sharp_pair_256,
(_sharp_pair_256 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_256).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_255;
_sharp_pair_255,
(_sharp_pair_255 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_255).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_253;
_sharp_pair_253,
(_sharp_pair_253 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_253).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_251;
_sharp_pair_251,
(_sharp_pair_251 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_251).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_251).cdr) = ({
struct struct0x08096a90 *_sharp_pair_250;
_sharp_pair_250,
(_sharp_pair_250 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_250).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_250).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_250);
})
);
((List__O__Form__C____type__type ) _sharp_pair_251);
})
));
(((* _sharp_pair_253).cdr) = ({
struct struct0x08096a90 *_sharp_pair_252;
_sharp_pair_252,
(_sharp_pair_252 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_252).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_252).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_252);
})
);
((List__O__Form__C____type__type ) _sharp_pair_253);
})
));
(((* _sharp_pair_255).cdr) = ({
struct struct0x08096a90 *_sharp_pair_254;
_sharp_pair_254,
(_sharp_pair_254 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_254).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_254).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_254);
})
);
((List__O__Form__C____type__type ) _sharp_pair_255);
})
));
(((* _sharp_pair_256).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_256);
})
);
((List__O__Form__C____type__type ) _sharp_pair_257);
})
));
(((* _sharp_pair_259).cdr) = ({
struct struct0x08096a90 *_sharp_pair_258;
_sharp_pair_258,
(_sharp_pair_258 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_258).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_258).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_258);
})
);
((List__O__Form__C____type__type ) _sharp_pair_259);
})
));
(((* _sharp_pair_261).cdr) = ({
struct struct0x08096a90 *_sharp_pair_260;
_sharp_pair_260,
(_sharp_pair_260 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_260).car) = (Symbol_Form)(intern( "deref")));
(((* _sharp_pair_260).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_260);
})
);
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
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "({goto *"), "({goto *"})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) ((Expanded_Compound_Form__type ) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)))).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ";})"), ";})"})),
(maybe_flush)();
})
;}

void  c_output_label(Expanded_Compound_Form__type  cf)
{
return ({
Id_Form__type label_form;
({if( ((((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail) == ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_270;
_sharp_pair_270,
(_sharp_pair_270 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_270).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_265;
_sharp_pair_265,
(_sharp_pair_265 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_265).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_263;
_sharp_pair_263,
(_sharp_pair_263 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_263).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_263).cdr) = ({
struct struct0x08096a90 *_sharp_pair_262;
_sharp_pair_262,
(_sharp_pair_262 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_262).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_262).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_262);
})
);
((List__O__Form__C____type__type ) _sharp_pair_263);
})
));
(((* _sharp_pair_265).cdr) = ({
struct struct0x08096a90 *_sharp_pair_264;
_sharp_pair_264,
(_sharp_pair_264 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_264).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_264).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_264);
})
);
((List__O__Form__C____type__type ) _sharp_pair_265);
})
));
(((* _sharp_pair_270).cdr) = ({
struct struct0x08096a90 *_sharp_pair_269;
_sharp_pair_269,
(_sharp_pair_269 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_269).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_268;
_sharp_pair_268,
(_sharp_pair_268 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_268).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08096a90 *_sharp_pair_266;
_sharp_pair_266,
(_sharp_pair_266 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_266).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_266).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_266);
})
));
(((* _sharp_pair_268).cdr) = ({
struct struct0x08096a90 *_sharp_pair_267;
_sharp_pair_267,
(_sharp_pair_267 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_267).car) = (Int_Form)(0));
(((* _sharp_pair_267).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_267);
})
);
((List__O__Form__C____type__type ) _sharp_pair_268);
})
));
(((* _sharp_pair_269).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_269);
})
);
((List__O__Form__C____type__type ) _sharp_pair_270);
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
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_277;
_sharp_pair_277,
(_sharp_pair_277 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_277).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_276;
_sharp_pair_276,
(_sharp_pair_276 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_276).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_276).cdr) = ({
struct struct0x08096a90 *_sharp_pair_275;
_sharp_pair_275,
(_sharp_pair_275 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_275).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_274;
_sharp_pair_274,
(_sharp_pair_274 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_274).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_272;
_sharp_pair_272,
(_sharp_pair_272 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_272).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_272).cdr) = ({
struct struct0x08096a90 *_sharp_pair_271;
_sharp_pair_271,
(_sharp_pair_271 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_271).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_271).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_271);
})
);
((List__O__Form__C____type__type ) _sharp_pair_272);
})
));
(((* _sharp_pair_274).cdr) = ({
struct struct0x08096a90 *_sharp_pair_273;
_sharp_pair_273,
(_sharp_pair_273 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_273).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_273).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_273);
})
);
((List__O__Form__C____type__type ) _sharp_pair_274);
})
));
(((* _sharp_pair_275).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_275);
})
);
((List__O__Form__C____type__type ) _sharp_pair_276);
})
));
(((* _sharp_pair_277).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_277);
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
(label_form = ((Id_Form__type ) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "((void) 0);"), "((void) 0);"})),
(print_Symbol)((convert_id)(((* ((struct struct0x0805fe70 *) label_form)).value))),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ":((void) 0)"), ":((void) 0)"}));
})
;}

void  c_output_let(Expanded_Compound_Form__type  cf)
{
return ({
({
({if( ((is_id_form)(((Form__type ) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head))) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_284;
_sharp_pair_284,
(_sharp_pair_284 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_284).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_283;
_sharp_pair_283,
(_sharp_pair_283 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_283).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_283).cdr) = ({
struct struct0x08096a90 *_sharp_pair_282;
_sharp_pair_282,
(_sharp_pair_282 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_282).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_281;
_sharp_pair_281,
(_sharp_pair_281 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_281).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_279;
_sharp_pair_279,
(_sharp_pair_279 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_279).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_279).cdr) = ({
struct struct0x08096a90 *_sharp_pair_278;
_sharp_pair_278,
(_sharp_pair_278 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_278).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_278).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_278);
})
);
((List__O__Form__C____type__type ) _sharp_pair_279);
})
));
(((* _sharp_pair_281).cdr) = ({
struct struct0x08096a90 *_sharp_pair_280;
_sharp_pair_280,
(_sharp_pair_280 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_280).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_280).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_280);
})
);
((List__O__Form__C____type__type ) _sharp_pair_281);
})
));
(((* _sharp_pair_282).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_282);
})
);
((List__O__Form__C____type__type ) _sharp_pair_283);
})
));
(((* _sharp_pair_284).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_284);
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
(c_output_type)((convert_id)(((* ((struct struct0x0805fe70 *) ((Id_Form__type ) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)))).value)), (intern_type)(((Form__type ) ((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail))).head))));
})
;
})
;}

void  c_output_ref(Expanded_Compound_Form__type  cf)
{
return ({
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "(&"), "(&"})),
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head)),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")"), ")"}));
})
;
})
;}

void  c_output_seq(Expanded_Compound_Form__type  cf)
{
return ({
({
({if( ((((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)) != ((List__O__Expanded_Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_291;
_sharp_pair_291,
(_sharp_pair_291 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_291).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_286;
_sharp_pair_286,
(_sharp_pair_286 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_286).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_286).cdr) = ({
struct struct0x08096a90 *_sharp_pair_285;
_sharp_pair_285,
(_sharp_pair_285 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_285).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_285).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_285);
})
);
((List__O__Form__C____type__type ) _sharp_pair_286);
})
));
(((* _sharp_pair_291).cdr) = ({
struct struct0x08096a90 *_sharp_pair_290;
_sharp_pair_290,
(_sharp_pair_290 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_290).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_289;
_sharp_pair_289,
(_sharp_pair_289 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_289).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08096a90 *_sharp_pair_287;
_sharp_pair_287,
(_sharp_pair_287 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_287).car) = (Id_Form)(intern( "Expanded_Form")));
(((* _sharp_pair_287).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_287);
})
));
(((* _sharp_pair_289).cdr) = ({
struct struct0x08096a90 *_sharp_pair_288;
_sharp_pair_288,
(_sharp_pair_288 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_288).car) = (Int_Form)(0));
(((* _sharp_pair_288).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_288);
})
);
((List__O__Form__C____type__type ) _sharp_pair_289);
})
));
(((* _sharp_pair_290).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_290);
})
);
((List__O__Form__C____type__type ) _sharp_pair_291);
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
(c_output_form)(((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head));
({
List__O__Expanded_Form__C____type__type _sharp_iterator293;
(_sharp_iterator293 = ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail));
((void) 0);_sharp__sharp_loop294_begin297:((void) 0),
({
Expanded_Form__type subform;
({if( (_sharp_iterator293 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop294_end295;});}})
;
(subform = ((* ((struct struct0x081eb830 *) _sharp_iterator293)).car));
({
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ",\n"), ",\n"})),
(c_output_form)(subform);
})
;
((void) 0);_sharp__sharp_loop294_continue296:((void) 0);
(_sharp_iterator293 = ((* ((struct struct0x081eb830 *) _sharp_iterator293)).cdr));
})
,
({goto _sharp__sharp_loop294_begin297;}),
((void) 0);_sharp__sharp_loop294_end295:((void) 0);
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
(c_output_type)(intern( ""), ((* ((struct struct0x080946c0 *) cf)).type));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "){"), "){"}));
({
Expanded_Form__type form_subform;
Expanded_Form__type subform_;
(subform_ = ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).head));
({if( ((is_compound_form)(((* ((struct struct0x080664c8 *) subform_)).return_form)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_300;
_sharp_pair_300,
(_sharp_pair_300 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_300).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_299;
_sharp_pair_299,
(_sharp_pair_299 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_299).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_299).cdr) = ({
struct struct0x08096a90 *_sharp_pair_298;
_sharp_pair_298,
(_sharp_pair_298 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_298).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_298).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_298);
})
);
((List__O__Form__C____type__type ) _sharp_pair_299);
})
));
(((* _sharp_pair_300).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_300);
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
({if( ((((* ((struct struct0x08065108 *) ((Compound_Form__type ) ((* ((struct struct0x080664c8 *) subform_)).return_form)))).head) == intern( "label")) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_308;
_sharp_pair_308,
(_sharp_pair_308 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_308).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_306;
_sharp_pair_306,
(_sharp_pair_306 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_306).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_304;
_sharp_pair_304,
(_sharp_pair_304 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_304).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_304).cdr) = ({
struct struct0x08096a90 *_sharp_pair_303;
_sharp_pair_303,
(_sharp_pair_303 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_303).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_302;
_sharp_pair_302,
(_sharp_pair_302 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_302).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_302).cdr) = ({
struct struct0x08096a90 *_sharp_pair_301;
_sharp_pair_301,
(_sharp_pair_301 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_301).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_301).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_301);
})
);
((List__O__Form__C____type__type ) _sharp_pair_302);
})
));
(((* _sharp_pair_303).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_303);
})
);
((List__O__Form__C____type__type ) _sharp_pair_304);
})
));
(((* _sharp_pair_306).cdr) = ({
struct struct0x08096a90 *_sharp_pair_305;
_sharp_pair_305,
(_sharp_pair_305 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_305).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_305).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_305);
})
);
((List__O__Form__C____type__type ) _sharp_pair_306);
})
));
(((* _sharp_pair_308).cdr) = ({
struct struct0x08096a90 *_sharp_pair_307;
_sharp_pair_307,
(_sharp_pair_307 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_307).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_307).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_307);
})
);
((List__O__Form__C____type__type ) _sharp_pair_308);
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
(form_subform = ((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) ((Expanded_Compound_Form__type ) subform_))).return_form_))).form_list)))).tail))).head));
(c_output_form)(form_subform);
})
;
({
List__O__Expanded_Form__C____type__type _sharp_iterator310;
(_sharp_iterator310 = ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)))).tail));
((void) 0);_sharp__sharp_loop311_begin325:((void) 0),
({
Expanded_Form__type subform_;
({if( (_sharp_iterator310 == ((List__O__Expanded_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop311_end312;});}})
;
(subform_ = ((* ((struct struct0x081eb830 *) _sharp_iterator310)).car));
({
Expanded_Form__type form_subform;
({if( ((is_compound_form)(((* ((struct struct0x080664c8 *) subform_)).return_form)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_315;
_sharp_pair_315,
(_sharp_pair_315 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_315).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_314;
_sharp_pair_314,
(_sharp_pair_314 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_314).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_314).cdr) = ({
struct struct0x08096a90 *_sharp_pair_313;
_sharp_pair_313,
(_sharp_pair_313 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_313).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_313).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_313);
})
);
((List__O__Form__C____type__type ) _sharp_pair_314);
})
));
(((* _sharp_pair_315).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_315);
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
({if( ((((* ((struct struct0x08065108 *) ((Compound_Form__type ) ((* ((struct struct0x080664c8 *) subform_)).return_form)))).head) == intern( "label")) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_323;
_sharp_pair_323,
(_sharp_pair_323 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_323).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_321;
_sharp_pair_321,
(_sharp_pair_321 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_321).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_319;
_sharp_pair_319,
(_sharp_pair_319 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_319).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_319).cdr) = ({
struct struct0x08096a90 *_sharp_pair_318;
_sharp_pair_318,
(_sharp_pair_318 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_318).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_317;
_sharp_pair_317,
(_sharp_pair_317 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_317).car) = (Id_Form)(intern( "subform_")));
(((* _sharp_pair_317).cdr) = ({
struct struct0x08096a90 *_sharp_pair_316;
_sharp_pair_316,
(_sharp_pair_316 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_316).car) = (Symbol_Form)(intern( "return_form")));
(((* _sharp_pair_316).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_316);
})
);
((List__O__Form__C____type__type ) _sharp_pair_317);
})
));
(((* _sharp_pair_318).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_318);
})
);
((List__O__Form__C____type__type ) _sharp_pair_319);
})
));
(((* _sharp_pair_321).cdr) = ({
struct struct0x08096a90 *_sharp_pair_320;
_sharp_pair_320,
(_sharp_pair_320 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_320).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_320).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_320);
})
);
((List__O__Form__C____type__type ) _sharp_pair_321);
})
));
(((* _sharp_pair_323).cdr) = ({
struct struct0x08096a90 *_sharp_pair_322;
_sharp_pair_322,
(_sharp_pair_322 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_322).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_322).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_322);
})
);
((List__O__Form__C____type__type ) _sharp_pair_323);
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
(form_subform = ((* ((struct struct0x081d1968 *) ((* ((struct struct0x081d1968 *) ((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) ((Expanded_Compound_Form__type ) subform_))).return_form_))).form_list)))).tail))).head));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(c_output_form)(form_subform);
})
;
((void) 0);_sharp__sharp_loop311_continue324:((void) 0);
(_sharp_iterator310 = ((* ((struct struct0x081eb830 *) _sharp_iterator310)).cdr));
})
,
({goto _sharp__sharp_loop311_begin325;}),
((void) 0);_sharp__sharp_loop311_end312:((void) 0);
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
(((((List__O__Expanded_Form__C____type__type ) ((* ((struct struct0x08065108 *) ((* ((struct struct0x080946c0 *) cf)).return_form_))).form_list)) == ((List__O__Expanded_Form__C____type__type ) 0)))?
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
struct struct0x08096a90 *_sharp_pair_326;
_sharp_pair_326,
(_sharp_pair_326 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_326).car) = (Id_Form)(intern( "l_")));
(((* _sharp_pair_326).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_326);
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
(l = ((* ((struct struct0x080664c8 *) ((Expanded_Form__type ) l_))).return_form));
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
struct struct0x08096a90 *_sharp_pair_327;
_sharp_pair_327,
(_sharp_pair_327 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_327).car) = (Id_Form)(intern( "l")));
(((* _sharp_pair_327).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_327);
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
({if( ((((* ((struct struct0x08065108 *) ((Compound_Form__type ) l))).head) == intern( "lambda")) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_333;
_sharp_pair_333,
(_sharp_pair_333 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_333).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_331;
_sharp_pair_331,
(_sharp_pair_331 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_331).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_329;
_sharp_pair_329,
(_sharp_pair_329 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_329).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_329).cdr) = ({
struct struct0x08096a90 *_sharp_pair_328;
_sharp_pair_328,
(_sharp_pair_328 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_328).car) = (Id_Form)(intern( "l")));
(((* _sharp_pair_328).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_328);
})
);
((List__O__Form__C____type__type ) _sharp_pair_329);
})
));
(((* _sharp_pair_331).cdr) = ({
struct struct0x08096a90 *_sharp_pair_330;
_sharp_pair_330,
(_sharp_pair_330 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_330).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_330).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_330);
})
);
((List__O__Form__C____type__type ) _sharp_pair_331);
})
));
(((* _sharp_pair_333).cdr) = ({
struct struct0x08096a90 *_sharp_pair_332;
_sharp_pair_332,
(_sharp_pair_332 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_332).car) = (Symbol_Form)(intern( "lambda")));
(((* _sharp_pair_332).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_332);
})
);
((List__O__Form__C____type__type ) _sharp_pair_333);
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
(form_list = ((List__O__Form__C____type__type ) ((* ((struct struct0x08065108 *) ((Compound_Form__type ) l))).form_list)));
(return_type = ((* ((struct struct0x08060190 *) form_list)).head));
(c_output_type)(intern( ""), (intern_type)(return_type));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " "), " "})),
(print_Symbol)(name),
(print_String)((&(struct { unsigned int len; char *content;}){strlen( "("), "("})),
(maybe_flush)();
(parameters_type = ((Compound_Form__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) form_list)).tail))).head)));
({if( ((((* ((struct struct0x08065108 *) parameters_type)).head) == intern( "tuple")) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_337;
_sharp_pair_337,
(_sharp_pair_337 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_337).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_335;
_sharp_pair_335,
(_sharp_pair_335 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_335).car) = (Id_Form)(intern( "parameters_type")));
(((* _sharp_pair_335).cdr) = ({
struct struct0x08096a90 *_sharp_pair_334;
_sharp_pair_334,
(_sharp_pair_334 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_334).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_334).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_334);
})
);
((List__O__Form__C____type__type ) _sharp_pair_335);
})
));
(((* _sharp_pair_337).cdr) = ({
struct struct0x08096a90 *_sharp_pair_336;
_sharp_pair_336,
(_sharp_pair_336 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_336).car) = (Symbol_Form)(intern( "tuple")));
(((* _sharp_pair_336).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_336);
})
);
((List__O__Form__C____type__type ) _sharp_pair_337);
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
(((((* ((struct struct0x08065108 *) parameters_type)).form_list) == ((List__O__Form__C____type__type ) 0)))?
((print_String)((&(struct { unsigned int len; char *content;}){strlen( "void"), "void"})),
(maybe_flush)()):
(({
Id_Form__type first_param_name;
Form__type first_param_type;
Compound_Form__type first_parameter;
(first_parameter = ((Compound_Form__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) parameters_type)).form_list))).head)));
({if( ((((* ((struct struct0x08065108 *) first_parameter)).head) == intern( "label")) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_341;
_sharp_pair_341,
(_sharp_pair_341 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_341).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_339;
_sharp_pair_339,
(_sharp_pair_339 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_339).car) = (Id_Form)(intern( "first_parameter")));
(((* _sharp_pair_339).cdr) = ({
struct struct0x08096a90 *_sharp_pair_338;
_sharp_pair_338,
(_sharp_pair_338 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_338).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_338).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_338);
})
);
((List__O__Form__C____type__type ) _sharp_pair_339);
})
));
(((* _sharp_pair_341).cdr) = ({
struct struct0x08096a90 *_sharp_pair_340;
_sharp_pair_340,
(_sharp_pair_340 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_340).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_340).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_340);
})
);
((List__O__Form__C____type__type ) _sharp_pair_341);
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
(first_param_name = ((Id_Form__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) first_parameter)).form_list))).head)));
(first_param_type = ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) first_parameter)).form_list))).tail))).head));
(c_output_type)(intern( ""), (intern_type)(((Form__type ) first_param_type)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " "), " "})),
(print_Symbol)(((* ((struct struct0x0805fe70 *) first_param_name)).value)),
(maybe_flush)();
({
List__O__Compound_Form__C____type__type _sharp_iterator343;
(_sharp_iterator343 = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) parameters_type)).form_list))).tail)));
((void) 0);_sharp__sharp_loop344_begin351:((void) 0),
({
Compound_Form__type parameter;
({if( (_sharp_iterator343 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop344_end345;});}})
;
(parameter = ((* ((struct struct0x0828d258 *) _sharp_iterator343)).car));
({
Id_Form__type param_name;
Form__type type;
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ", "), ", "})),
(maybe_flush)();
({if( ((((* ((struct struct0x08065108 *) first_parameter)).head) == intern( "label")) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_349;
_sharp_pair_349,
(_sharp_pair_349 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_349).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_347;
_sharp_pair_347,
(_sharp_pair_347 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_347).car) = (Id_Form)(intern( "first_parameter")));
(((* _sharp_pair_347).cdr) = ({
struct struct0x08096a90 *_sharp_pair_346;
_sharp_pair_346,
(_sharp_pair_346 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_346).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_346).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_346);
})
);
((List__O__Form__C____type__type ) _sharp_pair_347);
})
));
(((* _sharp_pair_349).cdr) = ({
struct struct0x08096a90 *_sharp_pair_348;
_sharp_pair_348,
(_sharp_pair_348 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_348).car) = (Symbol_Form)(intern( "label")));
(((* _sharp_pair_348).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_348);
})
);
((List__O__Form__C____type__type ) _sharp_pair_349);
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
(param_name = ((Id_Form__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) parameter)).form_list))).head)));
(type = ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08065108 *) parameter)).form_list))).tail))).head));
(c_output_type)(intern( ""), (intern_type)(((Form__type ) type)));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( " "), " "})),
(print_Symbol)(((* ((struct struct0x0805fe70 *) param_name)).value)),
(maybe_flush)();
})
;
((void) 0);_sharp__sharp_loop344_continue350:((void) 0);
(_sharp_iterator343 = ((* ((struct struct0x0828d258 *) _sharp_iterator343)).cdr));
})
,
({goto _sharp__sharp_loop344_begin351;}),
((void) 0);_sharp__sharp_loop344_end345:((void) 0);
})
;
})
));
(print_String)((&(struct { unsigned int len; char *content;}){strlen( ")\n{\nreturn "), ")\n{\nreturn "})),
(maybe_flush)();
(c_output_form)(((Expanded_Form__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) form_list)).tail))).tail))).head))),
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
struct struct0x08096a90 *_sharp_pair_354;
_sharp_pair_354,
(_sharp_pair_354 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_354).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08096a90 *_sharp_pair_353;
_sharp_pair_353,
(_sharp_pair_353 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_353).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_353).cdr) = ({
struct struct0x08096a90 *_sharp_pair_352;
_sharp_pair_352,
(_sharp_pair_352 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_352).car) = (Id_Form)(intern( "f")));
(((* _sharp_pair_352).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_352);
})
);
((List__O__Form__C____type__type ) _sharp_pair_353);
})
));
(((* _sharp_pair_354).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_354);
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
({if( ((((* ((struct struct0x08065108 *) f)).head) == intern( "define")) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_358;
_sharp_pair_358,
(_sharp_pair_358 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_358).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_356;
_sharp_pair_356,
(_sharp_pair_356 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_356).car) = (Id_Form)(intern( "f")));
(((* _sharp_pair_356).cdr) = ({
struct struct0x08096a90 *_sharp_pair_355;
_sharp_pair_355,
(_sharp_pair_355 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_355).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_355).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_355);
})
);
((List__O__Form__C____type__type ) _sharp_pair_356);
})
));
(((* _sharp_pair_358).cdr) = ({
struct struct0x08096a90 *_sharp_pair_357;
_sharp_pair_357,
(_sharp_pair_357 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_357).car) = (Symbol_Form)(intern( "define")));
(((* _sharp_pair_357).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_357);
})
);
((List__O__Form__C____type__type ) _sharp_pair_358);
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
(form_list = ((List__O__Form__C____type__type ) ((* ((struct struct0x08065108 *) ((Compound_Form__type ) f))).form_list)));
({if( ((is_id_form)(((* ((struct struct0x08060190 *) form_list)).head)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_361;
_sharp_pair_361,
(_sharp_pair_361 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_361).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_360;
_sharp_pair_360,
(_sharp_pair_360 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_360).car) = (Id_Form)(intern( "form_list")));
(((* _sharp_pair_360).cdr) = ({
struct struct0x08096a90 *_sharp_pair_359;
_sharp_pair_359,
(_sharp_pair_359 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_359).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_359).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_359);
})
);
((List__O__Form__C____type__type ) _sharp_pair_360);
})
));
(((* _sharp_pair_361).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_361);
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
(species = ((* ((struct struct0x0805fe70 *) ((Id_Form__type ) ((* ((struct struct0x08060190 *) form_list)).head)))).value));
({if( ((is_id_form)(((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) form_list)).tail))).head)) == ((Bool__type ) 0)))
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
struct struct0x08096a90 *_sharp_pair_366;
_sharp_pair_366,
(_sharp_pair_366 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_366).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_365;
_sharp_pair_365,
(_sharp_pair_365 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_365).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08096a90 *_sharp_pair_363;
_sharp_pair_363,
(_sharp_pair_363 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_363).car) = (Id_Form)(intern( "form_list")));
(((* _sharp_pair_363).cdr) = ({
struct struct0x08096a90 *_sharp_pair_362;
_sharp_pair_362,
(_sharp_pair_362 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_362).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_362).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_362);
})
);
((List__O__Form__C____type__type ) _sharp_pair_363);
})
));
(((* _sharp_pair_365).cdr) = ({
struct struct0x08096a90 *_sharp_pair_364;
_sharp_pair_364,
(_sharp_pair_364 = ((struct struct0x08096a90 *) (alloc_cons_cell)()));
(((* _sharp_pair_364).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_364).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_364);
})
);
((List__O__Form__C____type__type ) _sharp_pair_365);
})
));
(((* _sharp_pair_366).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_366);
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
(name = ((* ((struct struct0x0805fe70 *) ((Id_Form__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) form_list)).tail))).head)))).value));
(((species == intern( "function")))?
(({
(c_output_function_definition)(name, ((Form__type ) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) form_list)).tail))).tail))).head)));
})
):
((((species == intern( "type")))?
(({
((void) 0);
})
):
((((species == intern( "global")))?
(({
(c_output_global_definition)(name, ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) ((* ((struct struct0x08060190 *) form_list)).tail))).tail))).head));
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
List__O__Compound_Form__C____type__type _sharp_iterator368;
(_sharp_iterator368 = form_list);
((void) 0);_sharp__sharp_loop369_begin372:((void) 0),
({
Compound_Form__type f;
({if( (_sharp_iterator368 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop369_end370;});}})
;
(f = ((* ((struct struct0x0828d258 *) _sharp_iterator368)).car));
(c_output_definition)(f);
((void) 0);_sharp__sharp_loop369_continue371:((void) 0);
(_sharp_iterator368 = ((* ((struct struct0x0828d258 *) _sharp_iterator368)).cdr));
})
,
({goto _sharp__sharp_loop369_begin372;}),
((void) 0);_sharp__sharp_loop369_end370:((void) 0);
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
((void) 0);_sharp__sharp_loop373_begin377:((void) 0),
({
Bool__type _sharp_tuple376;
Symbol__type _sharp_tuple375;
Bool__type misc_;
Symbol__type symbol;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop373_end374;});}})
;
(_sharp_tuple375 = ((Symbol__type ) Index_)),
(_sharp_tuple376 = ((Bool__type ) (* PValue_))),
(symbol = _sharp_tuple375),
(misc_ = _sharp_tuple376);
({
Type__type t;
(t = (get_global_type)(symbol));
((Bool__type ) (puthash)(((void *) t), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) type_definition_needed)));
})
;
(PValue_ = (JudyLNext)((* ((void **) hash_)), ((void *) (&Index_)), 0));
})
,
({goto _sharp__sharp_loop373_begin377;}),
((void) 0);_sharp__sharp_loop373_end374:((void) 0);
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
((void) 0);_sharp__sharp_loop378_begin382:((void) 0),
({
Bool__type _sharp_tuple381;
Symbol__type _sharp_tuple380;
Bool__type misc_;
Symbol__type symbol;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop378_end379;});}})
;
(_sharp_tuple380 = ((Symbol__type ) Index_)),
(_sharp_tuple381 = ((Bool__type ) (* PValue_))),
(symbol = _sharp_tuple380),
(misc_ = _sharp_tuple381);
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
({goto _sharp__sharp_loop378_begin382;}),
((void) 0);_sharp__sharp_loop378_end379:((void) 0);
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
