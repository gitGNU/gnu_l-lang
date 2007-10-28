/* Automatically generated : do not edit!*/
#include "parse-l.inc"
Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type parse_top_level_hash;

Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type parse_macro_hash;

void  init__parse_l(void)
{
return ({
({(parse_macro_hash = ((Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type ) (make_hash_table)()));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "let")), ((void *) (&_l__parse__Macro__let)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "cast")), ((void *) (&_l__parse__Macro__cast)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "if")), ((void *) (&_l__parse__Macro__if)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "loop")), ((void *) (&_l__parse__Macro__loop_like)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "while")), ((void *) (&_l__parse__Macro__while_like)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "make_list")), ((void *) (&_l__parse__Macro__loop_like)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "buffered")), ((void *) (&_l__parse__Macro__loop_like)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "unbuffered")), ((void *) (&_l__parse__Macro__loop_like)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "foreach")), ((void *) (&_l__parse__Macro__foreach)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "Form")), ((void *) (&_l__parse__Macro__Form)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "XML")), ((void *) (&_l__parse__Macro__XML)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "break")), ((void *) (&_l__parse__Macro__break)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "continue")), ((void *) (&_l__parse__Macro__continue)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "match")), ((void *) (&_l__parse__Macro__match)), ((Hash_Table__type ) parse_macro_hash)));
(parse_top_level_hash = ((Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type ) (make_hash_table)()));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "function")), ((void *) (&_l__parse__Top_Level__function)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "global")), ((void *) (&_l__parse__Top_Level__global)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "variable")), ((void *) (&_l__parse__Top_Level__global)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "expander")), ((void *) (&_l__parse__Top_Level__expander)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "type")), ((void *) (&_l__parse__Top_Level__type)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "type_alias")), ((void *) (&_l__parse__Top_Level__type)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "macro")), ((void *) (&_l__parse__Top_Level__macro)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "include")), ((void *) (&_l__parse__Top_Level__include)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "grammar")), ((void *) (&_l__parse__Top_Level__grammar)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "grammar_macro")), ((void *) (&_l__parse__Top_Level__grammar_macro)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "attribute")), ((void *) (&_l__parse__Top_Level__attribute)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "compile_time")), ((void *) (&_l__parse__Top_Level__compile_time)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "subtype")), ((void *) (&_l__parse__Top_Level__subtype)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "constant")), ((void *) (&_l__parse__Top_Level__constant)), ((Hash_Table__type ) parse_top_level_hash)));
((void) 0);});
})
;}

Form__type  _l__parse__XML_Parser__CharData(void)
{
return ({
Int__type start;
Int__type end;
({(start = (get_point_pos)());
({({_sharp__sharp_loop501_begin503:;
({
({(read_char)();
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 61))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 59))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop501_end502;});}})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop501_begin503;});});
_sharp__sharp_loop501_end502:;});
(end = (get_point_pos)());
({(String_Form)((get_parsed_string_string)(((int) end - (int) start), ((int) start - (int) 1), end));});});
})
;}

List__O__Form__C____type  _l__parse__XML_Parser__Content_List(void)
{
return ({
Form__type cd;
List__O__Form__C____type cl;
Form__type form;
Form__type exp;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))?
(({({(read_char)();});
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((Bool__type ) 0))))))?
(({({(read_char)();});
({((List__O__Form__C____type ) 0);});})):
(({(form = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(exp = (_l__parse__Code__Sequence)());
({(read_char)();});
({(read_char)();});
({(Compound_Form)(intern( "$"), ({
struct struct0x0805f9e0 *_sharp_pair_504;
({_sharp_pair_504;
(_sharp_pair_504 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_504).car) = exp);
(((* _sharp_pair_504).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_504);
})
);});})):
((_l__parse__XML_Parser__Tagged_Compound)()));
})
);
(cl = (_l__parse__XML_Parser__Content_List)());
({({
struct struct0x0805f9e0 *_sharp_pair_505;
({_sharp_pair_505;
(_sharp_pair_505 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_505).car) = form);
(((* _sharp_pair_505).cdr) = cl);
((List__O__Form__C____type ) _sharp_pair_505);
})
;});})));
})
;})):
(({(cd = (_l__parse__XML_Parser__CharData)());
(cl = (_l__parse__XML_Parser__Content_List)());
({({
struct struct0x0805f9e0 *_sharp_pair_506;
({_sharp_pair_506;
(_sharp_pair_506 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_506).car) = cd);
(((* _sharp_pair_506).cdr) = cl);
((List__O__Form__C____type ) _sharp_pair_506);
})
;});})));
})
;
})
;}

Form__type  _l__parse__XML_Parser__Tagged_Compound(void)
{
return ({
Symbol__type id2;
List__O__Form__C____type cl;
Symbol__type id;
({(id = (_l__parse__Lexical__Id)());
({(read_char)();});
(cl = (_l__parse__XML_Parser__Content_List)());
(id2 = (_l__parse__Lexical__Id)());
({(read_char)();});
({(Compound_Form)(id, cl);});});
})
;}

Form__type  _l__parse__XML_Parser__Content(void)
{
return ({
({({(read_char)();});
(_l__parse__XML_Parser__Tagged_Compound)();});
})
;}

List__O__Form__C____type  _l__parse__Top_Level__All(void)
{
return ({
void **_sharp_make_list_ptr509;
Form__type form;
List__O__Form__C____type list;
({(_l__parse__Lexical__Spacing)();
(list = ({
List__O__Form__C____type _sharp_make_list508;
({_sharp_make_list508;
_sharp_make_list_ptr509;
(_sharp_make_list_ptr509 = ((void *) (&_sharp_make_list508)));
({({_sharp__sharp_loop510_begin512:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop510_end511;});}})
;
({(form = (_l__parse__Top_Level__Top)());
({({((* _sharp_make_list_ptr509) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr509))).car) = ((void *) form));
(_sharp_make_list_ptr509 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr509))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop510_begin512;});});
_sharp__sharp_loop510_end511:;});
((* _sharp_make_list_ptr509) = ((void *) 0));
_sharp_make_list508;});
})
);
({list;});});
})
;}

Form__type  _l__parse__Top_Level__Top(void)
{
return ({
Symbol__type id;
({(id = (_l__parse__Lexical__Id)());
({({
Form__type (*funptr)(Symbol__type );
({(funptr = ((Form__type (*)(Symbol__type )) (gethash)(((void *) id), ((Hash_Table__type ) parse_top_level_hash))));
({if( (funptr == ((Form__type (*)(Symbol__type )) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_24));
(print_String)(((String__type) &__string_25));
(print_Symbol)(id);
(print_String)(((String__type) &__string_26));
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
((* funptr))(id);});
})
;});});
})
;}

Form__type  _l__parse__Top_Level__function(Symbol__type  fsymb)
{
return ({
void **_sharp_make_list_ptr515;
Form__type ret_type;
List__O__Form__C____type params;
Form__type body;
Form__type arg;
Form__type arg1;
List__O__Form__C____type arg_list;
Symbol__type name;
({(name = (_l__parse__Lexical__Id)());
(parse_symbol)(((String__type) &__string_27));
(params = ({(arg_list = ({((List__O__Form__C____type ) 0);}));
({
({({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))
{
({(arg1 = (_l__parse__Type__Labeled_Type)());
(arg_list = ({
List__O__Form__C____type _sharp_make_list514;
({_sharp_make_list514;
_sharp_make_list_ptr515;
(_sharp_make_list_ptr515 = ((void *) (&_sharp_make_list514)));
({({_sharp__sharp_loop516_begin518:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop516_end517;});}})
;
({(parse_symbol)(((String__type) &__string_28));
(arg = (_l__parse__Type__Labeled_Type)());
({({((* _sharp_make_list_ptr515) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr515))).car) = ((void *) arg));
(_sharp_make_list_ptr515 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr515))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop516_begin518;});});
_sharp__sharp_loop516_end517:;});
((* _sharp_make_list_ptr515) = ((void *) 0));
_sharp_make_list514;});
})
);
(arg_list = ({({
struct struct0x0805f9e0 *_sharp_pair_519;
({_sharp_pair_519;
(_sharp_pair_519 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_519).car) = arg1);
(((* _sharp_pair_519).cdr) = arg_list);
((List__O__Form__C____type ) _sharp_pair_519);
})
;}));});}})
;
((void) 0);});
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_29));
(parse_symbol)(((String__type) &__string_30));
(ret_type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_31));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_32));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805f9e0 *_sharp_pair_525;
({_sharp_pair_525;
(_sharp_pair_525 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_525).car) = (Id_Form)(fsymb));
(((* _sharp_pair_525).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_524;
({_sharp_pair_524;
(_sharp_pair_524 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_524).car) = (Id_Form)(name));
(((* _sharp_pair_524).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_523;
({_sharp_pair_523;
(_sharp_pair_523 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_523).car) = (Compound_Form)(intern( "lambda"), ({
struct struct0x0805f9e0 *_sharp_pair_522;
({_sharp_pair_522;
(_sharp_pair_522 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_522).car) = ret_type);
(((* _sharp_pair_522).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_521;
({_sharp_pair_521;
(_sharp_pair_521 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_521).car) = (Compound_Form)(intern( "tuple"), params));
(((* _sharp_pair_521).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_520;
({_sharp_pair_520;
(_sharp_pair_520 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_520).car) = body);
(((* _sharp_pair_520).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_520);
})
);
((List__O__Form__C____type ) _sharp_pair_521);
})
);
((List__O__Form__C____type ) _sharp_pair_522);
})
));
(((* _sharp_pair_523).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_523);
})
);
((List__O__Form__C____type ) _sharp_pair_524);
})
);
((List__O__Form__C____type ) _sharp_pair_525);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__global(Symbol__type  fsymb)
{
return ({
Symbol__type name;
Form__type type;
({(name = (_l__parse__Lexical__Id)());
({(read_char)();});
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_33));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805f9e0 *_sharp_pair_528;
({_sharp_pair_528;
(_sharp_pair_528 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_528).car) = (Id_Form)(fsymb));
(((* _sharp_pair_528).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_527;
({_sharp_pair_527;
(_sharp_pair_527 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_527).car) = (Id_Form)(name));
(((* _sharp_pair_527).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_526;
({_sharp_pair_526;
(_sharp_pair_526 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_526).car) = type);
(((* _sharp_pair_526).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_526);
})
);
((List__O__Form__C____type ) _sharp_pair_527);
})
);
((List__O__Form__C____type ) _sharp_pair_528);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__constant(Symbol__type  fsymb)
{
return ({
Form__type exp;
Form__type name;
({(name = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_34));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_35));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805f9e0 *_sharp_pair_531;
({_sharp_pair_531;
(_sharp_pair_531 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_531).car) = (Id_Form)(fsymb));
(((* _sharp_pair_531).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_530;
({_sharp_pair_530;
(_sharp_pair_530 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_530).car) = name);
(((* _sharp_pair_530).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_529;
({_sharp_pair_529;
(_sharp_pair_529 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_529).car) = exp);
(((* _sharp_pair_529).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_529);
})
);
((List__O__Form__C____type ) _sharp_pair_530);
})
);
((List__O__Form__C____type ) _sharp_pair_531);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__type(Symbol__type  fsymb)
{
return ({
Form__type type_name;
Form__type type;
({(type_name = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_36));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_37));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805f9e0 *_sharp_pair_534;
({_sharp_pair_534;
(_sharp_pair_534 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_534).car) = (Id_Form)(fsymb));
(((* _sharp_pair_534).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_533;
({_sharp_pair_533;
(_sharp_pair_533 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_533).car) = type_name);
(((* _sharp_pair_533).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_532;
({_sharp_pair_532;
(_sharp_pair_532 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_532).car) = type);
(((* _sharp_pair_532).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_532);
})
);
((List__O__Form__C____type ) _sharp_pair_533);
})
);
((List__O__Form__C____type ) _sharp_pair_534);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__subtype(Symbol__type  fsymb)
{
return ({
Form__type type_name;
Form__type type;
({(type_name = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_38));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_39));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805f9e0 *_sharp_pair_537;
({_sharp_pair_537;
(_sharp_pair_537 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_537).car) = (Id_Form)(fsymb));
(((* _sharp_pair_537).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_536;
({_sharp_pair_536;
(_sharp_pair_536 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_536).car) = type_name);
(((* _sharp_pair_536).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_535;
({_sharp_pair_535;
(_sharp_pair_535 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_535).car) = type);
(((* _sharp_pair_535).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_535);
})
);
((List__O__Form__C____type ) _sharp_pair_536);
})
);
((List__O__Form__C____type ) _sharp_pair_537);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__expander(Symbol__type  fsymb)
{
return ({
Form__type param;
Form__type body;
Form__type name;
({(name = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_40));
(param = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_41));
(parse_symbol)(((String__type) &__string_42));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_43));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805f9e0 *_sharp_pair_542;
({_sharp_pair_542;
(_sharp_pair_542 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_542).car) = (Id_Form)(fsymb));
(((* _sharp_pair_542).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_541;
({_sharp_pair_541;
(_sharp_pair_541 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_541).car) = name);
(((* _sharp_pair_541).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_540;
({_sharp_pair_540;
(_sharp_pair_540 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_540).car) = (Compound_Form)(intern( ":"), ({
struct struct0x0805f9e0 *_sharp_pair_539;
({_sharp_pair_539;
(_sharp_pair_539 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_539).car) = param);
(((* _sharp_pair_539).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_538;
({_sharp_pair_538;
(_sharp_pair_538 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_538).car) = body);
(((* _sharp_pair_538).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_538);
})
);
((List__O__Form__C____type ) _sharp_pair_539);
})
));
(((* _sharp_pair_540).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_540);
})
);
((List__O__Form__C____type ) _sharp_pair_541);
})
);
((List__O__Form__C____type ) _sharp_pair_542);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__macro(Symbol__type  fsymb)
{
return ({
void **_sharp_make_list_ptr549;
List__O__Form__C____type params;
Form__type body;
Form__type arg;
Form__type arg1;
List__O__Form__C____type arg_list;
Form__type name;
Form__type macro_name;
Form__type type;
({(macro_name = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_44));
(params = ({(arg_list = ({((List__O__Form__C____type ) 0);}));
({
({({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))
{
({(arg1 = ({(name = (_l__parse__Lexical__Id_Form)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( ":"), ({
struct struct0x0805f9e0 *_sharp_pair_544;
({_sharp_pair_544;
(_sharp_pair_544 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_544).car) = name);
(((* _sharp_pair_544).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_543;
({_sharp_pair_543;
(_sharp_pair_543 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_543).car) = type);
(((* _sharp_pair_543).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_543);
})
);
((List__O__Form__C____type ) _sharp_pair_544);
})
);});})):
(({name;})));
})
;}));
(arg_list = ({
List__O__Form__C____type _sharp_make_list548;
({_sharp_make_list548;
_sharp_make_list_ptr549;
(_sharp_make_list_ptr549 = ((void *) (&_sharp_make_list548)));
({({_sharp__sharp_loop550_begin552:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop550_end551;});}})
;
({(parse_symbol)(((String__type) &__string_45));
(arg = ({(name = (_l__parse__Lexical__Id_Form)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( ":"), ({
struct struct0x0805f9e0 *_sharp_pair_547;
({_sharp_pair_547;
(_sharp_pair_547 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_547).car) = name);
(((* _sharp_pair_547).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_546;
({_sharp_pair_546;
(_sharp_pair_546 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_546).car) = type);
(((* _sharp_pair_546).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_546);
})
);
((List__O__Form__C____type ) _sharp_pair_547);
})
);});})):
(({name;})));
})
;}));
({({((* _sharp_make_list_ptr549) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr549))).car) = ((void *) arg));
(_sharp_make_list_ptr549 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr549))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop550_begin552;});});
_sharp__sharp_loop550_end551:;});
((* _sharp_make_list_ptr549) = ((void *) 0));
_sharp_make_list548;});
})
);
(arg_list = ({({
struct struct0x0805f9e0 *_sharp_pair_553;
({_sharp_pair_553;
(_sharp_pair_553 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_553).car) = arg1);
(((* _sharp_pair_553).cdr) = arg_list);
((List__O__Form__C____type ) _sharp_pair_553);
})
;}));});}})
;
((void) 0);});
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_46));
(parse_symbol)(((String__type) &__string_47));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_48));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805f9e0 *_sharp_pair_557;
({_sharp_pair_557;
(_sharp_pair_557 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_557).car) = (Id_Form)(fsymb));
(((* _sharp_pair_557).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_556;
({_sharp_pair_556;
(_sharp_pair_556 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_556).car) = macro_name);
(((* _sharp_pair_556).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_555;
({_sharp_pair_555;
(_sharp_pair_555 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_555).car) = (Compound_Form)(intern( "tuple"), params));
(((* _sharp_pair_555).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_554;
({_sharp_pair_554;
(_sharp_pair_554 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_554).car) = body);
(((* _sharp_pair_554).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_554);
})
);
((List__O__Form__C____type ) _sharp_pair_555);
})
);
((List__O__Form__C____type ) _sharp_pair_556);
})
);
((List__O__Form__C____type ) _sharp_pair_557);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__attribute_component(void)
{
return ({
Form__type exp;
Form__type name;
({
((((((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 108))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 101))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 102))||(((Bool__type ) 0))))))&&(((((new_peek_char)(3) == 116))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_49));
(parse_symbol)(((String__type) &__string_50));
(name = (_l__parse__Lexical__Id_Form)());
({(read_char)();});
(parse_symbol)(((String__type) &__string_51));
(exp = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "label"), ({
struct struct0x0805f9e0 *_sharp_pair_560;
({_sharp_pair_560;
(_sharp_pair_560 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_560).car) = (Compound_Form)(intern( "left"), ({
struct struct0x0805f9e0 *_sharp_pair_558;
({_sharp_pair_558;
(_sharp_pair_558 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_558).car) = name);
(((* _sharp_pair_558).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_558);
})
));
(((* _sharp_pair_560).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_559;
({_sharp_pair_559;
(_sharp_pair_559 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_559).car) = exp);
(((* _sharp_pair_559).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_559);
})
);
((List__O__Form__C____type ) _sharp_pair_560);
})
);});})):
((_l__parse__Code__Expression)()));
})
;
})
;}

Form__type  _l__parse__Top_Level__attributes_components(void)
{
return ({
Form__type att2;
Form__type att1;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_52));
(att1 = (_l__parse__Top_Level__attribute_component)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_53));
(att2 = (_l__parse__Top_Level__attribute_component)());
(parse_symbol)(((String__type) &__string_54));
({(Compound_Form)(intern( "tuple"), ({
struct struct0x0805f9e0 *_sharp_pair_562;
({_sharp_pair_562;
(_sharp_pair_562 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_562).car) = att1);
(((* _sharp_pair_562).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_561;
({_sharp_pair_561;
(_sharp_pair_561 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_561).car) = att2);
(((* _sharp_pair_561).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_561);
})
);
((List__O__Form__C____type ) _sharp_pair_562);
})
);});})):
(({(parse_symbol)(((String__type) &__string_55));
({att1;});})));
})
;})):
((_l__parse__Top_Level__attribute_component)()));
})
;
})
;}

Form__type  _l__parse__Top_Level__attribute(Symbol__type  fsymb)
{
return ({
Form__type expression;
Symbol__type objname;
Symbol__type fieldname;
Form__type type;
({(type = (_l__parse__Type__Type)());
(objname = (_l__parse__Lexical__Id)());
({(read_char)();});
(fieldname = (_l__parse__Lexical__Id)());
(parse_symbol)(((String__type) &__string_56));
(expression = (_l__parse__Top_Level__attributes_components)());
(parse_symbol)(((String__type) &__string_57));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805f9e0 *_sharp_pair_567;
({_sharp_pair_567;
(_sharp_pair_567 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_567).car) = (Id_Form)(fsymb));
(((* _sharp_pair_567).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_566;
({_sharp_pair_566;
(_sharp_pair_566 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_566).car) = type);
(((* _sharp_pair_566).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_565;
({_sharp_pair_565;
(_sharp_pair_565 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_565).car) = (Id_Form)(objname));
(((* _sharp_pair_565).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_564;
({_sharp_pair_564;
(_sharp_pair_564 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_564).car) = (Id_Form)(fieldname));
(((* _sharp_pair_564).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_563;
({_sharp_pair_563;
(_sharp_pair_563 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_563).car) = expression);
(((* _sharp_pair_563).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_563);
})
);
((List__O__Form__C____type ) _sharp_pair_564);
})
);
((List__O__Form__C____type ) _sharp_pair_565);
})
);
((List__O__Form__C____type ) _sharp_pair_566);
})
);
((List__O__Form__C____type ) _sharp_pair_567);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__compile_time(Symbol__type  fsymb)
{
return ({
Form__type any;
({(any = (_l__parse__Top_Level__Top)());
({(Compound_Form)(intern( "define"), ({
struct struct0x0805f9e0 *_sharp_pair_569;
({_sharp_pair_569;
(_sharp_pair_569 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_569).car) = (Id_Form)(fsymb));
(((* _sharp_pair_569).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_568;
({_sharp_pair_568;
(_sharp_pair_568 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_568).car) = any);
(((* _sharp_pair_568).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_568);
})
);
((List__O__Form__C____type ) _sharp_pair_569);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__include(Symbol__type  fsymb)
{
return ({
String__type filename;
({(filename = (_l__parse__Lexical__String)());
(parse_symbol)(((String__type) &__string_58));
({(parse_include_filename)(filename);});});
})
;}

Form__type  _l__parse__Top_Level__grammar_macro(Symbol__type  fsymb)
{
return ({
(_l__parse__parse_grammar__Grammar_Macro_End)();
})
;}

Form__type  _l__parse__Top_Level__grammar(Symbol__type  fsymb)
{
return ({
(_l__parse__parse_grammar__Grammar_End)();
})
;}

Form__type  _l__parse__Macro__let(Symbol__type  symb)
{
return ({
List__O__Form__C____type typel;
Symbol__type __rep_symb;
Form__type __rep_exp;
Form__type id;
Form__type type;
({(id = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))))?
(({(__rep_symb = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 64))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_59))):
((parse_symbol)(((String__type) &__string_60))));
})
);
(__rep_exp = (_l__parse__Code__Sequence)());
(parse_symbol)(((String__type) &__string_61));
({(Compound_Form)(__rep_symb, ({
struct struct0x0805f9e0 *_sharp_pair_570;
({_sharp_pair_570;
(_sharp_pair_570 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_570).car) = __rep_exp);
(((* _sharp_pair_570).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_570);
})
);});})):
((_l__parse__Lexical__Id_Form)()));
})
);
(typel = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(type = (_l__parse__Type__Type)());
({({
struct struct0x0805f9e0 *_sharp_pair_571;
({_sharp_pair_571;
(_sharp_pair_571 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_571).car) = type);
(((* _sharp_pair_571).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_571);
})
;});})):
(({((List__O__Form__C____type ) 0);})));
})
);
({(Compound_Form)(intern( "let"), ({
struct struct0x0805f9e0 *_sharp_pair_572;
({_sharp_pair_572;
(_sharp_pair_572 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_572).car) = id);
(((* _sharp_pair_572).cdr) = typel);
((List__O__Form__C____type ) _sharp_pair_572);
})
);});});
})
;}

Form__type  _l__parse__Macro__if(Symbol__type  symb)
{
return ({
List__O__Form__C____type elsel;
Form__type cond;
Form__type exp2;
Form__type exp;
({(parse_symbol)(((String__type) &__string_62));
(cond = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_63));
(exp = (_l__parse__Code__Expression)());
(elsel = ({
((((((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 101))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 108))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 115))||(((Bool__type ) 0))))))&&(((((new_peek_char)(3) == 101))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_64));
(exp2 = (_l__parse__Code__Expression)());
({({
struct struct0x0805f9e0 *_sharp_pair_573;
({_sharp_pair_573;
(_sharp_pair_573 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_573).car) = exp2);
(((* _sharp_pair_573).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_573);
})
;});})):
(({((List__O__Form__C____type ) 0);})));
})
);
({(Compound_Form)(intern( "if"), ({
struct struct0x0805f9e0 *_sharp_pair_575;
({_sharp_pair_575;
(_sharp_pair_575 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_575).car) = cond);
(((* _sharp_pair_575).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_574;
({_sharp_pair_574;
(_sharp_pair_574 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_574).car) = exp);
(((* _sharp_pair_574).cdr) = elsel);
((List__O__Form__C____type ) _sharp_pair_574);
})
);
((List__O__Form__C____type ) _sharp_pair_575);
})
);});});
})
;}

Form__type  _l__parse__Macro__loop_like(Symbol__type  symb)
{
return ({
Form__type exp;
({(exp = (_l__parse__Code__Expression)());
({(Compound_Form)(symb, ({
struct struct0x0805f9e0 *_sharp_pair_576;
({_sharp_pair_576;
(_sharp_pair_576 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_576).car) = exp);
(((* _sharp_pair_576).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_576);
})
);});});
})
;}

Form__type  _l__parse__Macro__while_like(Symbol__type  symb)
{
return ({
Form__type body;
Form__type cond;
({(parse_symbol)(((String__type) &__string_65));
(cond = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_66));
(body = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "while"), ({
struct struct0x0805f9e0 *_sharp_pair_578;
({_sharp_pair_578;
(_sharp_pair_578 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_578).car) = cond);
(((* _sharp_pair_578).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_577;
({_sharp_pair_577;
(_sharp_pair_577 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_577).car) = body);
(((* _sharp_pair_577).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_577);
})
);
((List__O__Form__C____type ) _sharp_pair_578);
})
);});});
})
;}

Form__type  _l__parse__Macro__break(Symbol__type  symb)
{
return ({
({(Compound_Form)(intern( "break"), ((List__O__Form__C____type ) 0));});
})
;}

Form__type  _l__parse__Macro__continue(Symbol__type  symb)
{
return ({
Form__type exp;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_67));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@seq"), ({
struct struct0x0805f9e0 *_sharp_pair_580;
({_sharp_pair_580;
(_sharp_pair_580 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_580).car) = (Compound_Form)(intern( "@set_continue"), ((List__O__Form__C____type ) 0)));
(((* _sharp_pair_580).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_579;
({_sharp_pair_579;
(_sharp_pair_579 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_579).car) = exp);
(((* _sharp_pair_579).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_579);
})
);
((List__O__Form__C____type ) _sharp_pair_580);
})
);});})):
(({(Compound_Form)(intern( "continue"), ((List__O__Form__C____type ) 0));})));
})
;
})
;}

Form__type  _l__parse__Macro__foreach(Symbol__type  symb)
{
return ({
Form__type collect;
Form__type var;
Form__type body;
({(parse_symbol)(((String__type) &__string_68));
(var = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_69));
(collect = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_70));
(body = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "foreach"), ({
struct struct0x0805f9e0 *_sharp_pair_583;
({_sharp_pair_583;
(_sharp_pair_583 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_583).car) = var);
(((* _sharp_pair_583).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_582;
({_sharp_pair_582;
(_sharp_pair_582 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_582).car) = collect);
(((* _sharp_pair_582).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_581;
({_sharp_pair_581;
(_sharp_pair_581 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_581).car) = body);
(((* _sharp_pair_581).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_581);
})
);
((List__O__Form__C____type ) _sharp_pair_582);
})
);
((List__O__Form__C____type ) _sharp_pair_583);
})
);});});
})
;}

Form__type  _l__parse__Macro__cast(Symbol__type  symb)
{
return ({
Form__type exp;
Form__type type;
({(parse_symbol)(((String__type) &__string_71));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_72));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_73));
({(Compound_Form)(intern( "cast"), ({
struct struct0x0805f9e0 *_sharp_pair_585;
({_sharp_pair_585;
(_sharp_pair_585 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_585).car) = type);
(((* _sharp_pair_585).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_584;
({_sharp_pair_584;
(_sharp_pair_584 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_584).car) = exp);
(((* _sharp_pair_584).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_584);
})
);
((List__O__Form__C____type ) _sharp_pair_585);
})
);});});
})
;}

Form__type  _l__parse__Macro__match(Symbol__type  symb)
{
return ({
void **_sharp_make_list_ptr588;
Form__type action;
List__O__Form__C____type rule_list;
Symbol__type id;
Form__type exp;
List__O__Form__C____type form_list;
Form__type label;
({(parse_symbol)(((String__type) &__string_74));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_75));
(parse_symbol)(((String__type) &__string_76));
(rule_list = ({
List__O__Form__C____type _sharp_make_list587;
({_sharp_make_list587;
_sharp_make_list_ptr588;
(_sharp_make_list_ptr588 = ((void *) (&_sharp_make_list587)));
({({_sharp__sharp_loop589_begin593:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop589_end590;});}})
;
({(label = ({(id = (_l__parse__Lexical__Id)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_77));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_78));
({(Compound_Form)(id, form_list);});})):
(({(Id_Form)(id);})));
})
;}));
(parse_symbol)(((String__type) &__string_79));
(action = (_l__parse__Code__Expression_Ior_Semicolon)());
({({((* _sharp_make_list_ptr588) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr588))).car) = ((void *) (Compound_Form)(intern( ":"), ({
struct struct0x0805f9e0 *_sharp_pair_592;
({_sharp_pair_592;
(_sharp_pair_592 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_592).car) = label);
(((* _sharp_pair_592).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_591;
({_sharp_pair_591;
(_sharp_pair_591 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_591).car) = action);
(((* _sharp_pair_591).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_591);
})
);
((List__O__Form__C____type ) _sharp_pair_592);
})
)));
(_sharp_make_list_ptr588 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr588))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop589_begin593;});});
_sharp__sharp_loop589_end590:;});
((* _sharp_make_list_ptr588) = ((void *) 0));
_sharp_make_list587;});
})
);
(parse_symbol)(((String__type) &__string_80));
({(Compound_Form)(symb, ({
struct struct0x0805f9e0 *_sharp_pair_594;
({_sharp_pair_594;
(_sharp_pair_594 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_594).car) = exp);
(((* _sharp_pair_594).cdr) = rule_list);
((List__O__Form__C____type ) _sharp_pair_594);
})
);});});
})
;}

Form__type  _l__parse__Macro__Form(Symbol__type  symb)
{
return ({
Form__type exp;
({(parse_symbol)(((String__type) &__string_81));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_82));
({(Compound_Form)(intern( "Form"), ({
struct struct0x0805f9e0 *_sharp_pair_595;
({_sharp_pair_595;
(_sharp_pair_595 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_595).car) = exp);
(((* _sharp_pair_595).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_595);
})
);});});
})
;}

Form__type  _l__parse__Macro__XML(Symbol__type  fsymb)
{
return ({
Form__type form;
({(parse_symbol)(((String__type) &__string_83));
(form = (_l__parse__XML_Parser__Content)());
(parse_symbol)(((String__type) &__string_84));
({(Compound_Form)(intern( "XML"), ({
struct struct0x0805f9e0 *_sharp_pair_596;
({_sharp_pair_596;
(_sharp_pair_596 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_596).car) = form);
(((* _sharp_pair_596).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_596);
})
);});});
})
;}

Form__type  _l__parse__Type__Base_Type(void)
{
return ({
void **_sharp_make_list_ptr611;
void **_sharp_make_list_ptr605;
void **_sharp_make_list_ptr599;
List__O__Form__C____type form_list2;
Form__type lab_type;
Form__type arg;
Form__type arg1;
List__O__Form__C____type arg_list;
Symbol__type id;
Form__type form;
List__O__Form__C____type form_list;
({(id = (_l__parse__Lexical__Id)());
(form = ({
((({(id == intern( "struct"));}))?
(({((void) 0);
(parse_symbol)(((String__type) &__string_85));
(form_list = ({
List__O__Form__C____type _sharp_make_list598;
({_sharp_make_list598;
_sharp_make_list_ptr599;
(_sharp_make_list_ptr599 = ((void *) (&_sharp_make_list598)));
({({_sharp__sharp_loop600_begin602:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop600_end601;});}})
;
({(lab_type = (_l__parse__Type__Labeled_Type)());
(parse_symbol)(((String__type) &__string_86));
({({((* _sharp_make_list_ptr599) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr599))).car) = ((void *) lab_type));
(_sharp_make_list_ptr599 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr599))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop600_begin602;});});
_sharp__sharp_loop600_end601:;});
((* _sharp_make_list_ptr599) = ((void *) 0));
_sharp_make_list598;});
})
);
(parse_symbol)(((String__type) &__string_87));
({(Compound_Form)(intern( "struct"), form_list);});})):
(({
((({(id == intern( "sum"));}))?
(({((void) 0);
(parse_symbol)(((String__type) &__string_88));
(form_list = ({
List__O__Form__C____type _sharp_make_list604;
({_sharp_make_list604;
_sharp_make_list_ptr605;
(_sharp_make_list_ptr605 = ((void *) (&_sharp_make_list604)));
({({_sharp__sharp_loop606_begin608:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop606_end607;});}})
;
({(lab_type = (_l__parse__Type__Labeled_Type)());
(parse_symbol)(((String__type) &__string_89));
({({((* _sharp_make_list_ptr605) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr605))).car) = ((void *) lab_type));
(_sharp_make_list_ptr605 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr605))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop606_begin608;});});
_sharp__sharp_loop606_end607:;});
((* _sharp_make_list_ptr605) = ((void *) 0));
_sharp_make_list604;});
})
);
(parse_symbol)(((String__type) &__string_90));
({(Compound_Form)(intern( "sum"), form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_91));
(form_list2 = ({(arg_list = ({((List__O__Form__C____type ) 0);}));
({
({({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type _sharp_make_list610;
({_sharp_make_list610;
_sharp_make_list_ptr611;
(_sharp_make_list_ptr611 = ((void *) (&_sharp_make_list610)));
({({_sharp__sharp_loop612_begin614:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop612_end613;});}})
;
({(parse_symbol)(((String__type) &__string_92));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr611) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr611))).car) = ((void *) arg));
(_sharp_make_list_ptr611 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr611))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop612_begin614;});});
_sharp__sharp_loop612_end613:;});
((* _sharp_make_list_ptr611) = ((void *) 0));
_sharp_make_list610;});
})
);
(arg_list = ({({
struct struct0x0805f9e0 *_sharp_pair_615;
({_sharp_pair_615;
(_sharp_pair_615 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_615).car) = arg1);
(((* _sharp_pair_615).cdr) = arg_list);
((List__O__Form__C____type ) _sharp_pair_615);
})
;}));});}})
;
((void) 0);});
})
;
({arg_list;});}));
({(read_char)();});
({(Compound_Form)(id, form_list2);});})):
(({(Id_Form)(id);})));
})
));
})
));
})
);
(_l__parse__Lexical__Spacing)();
({form;});});
})
;}

Form__type  _l__parse__Type__Tuple_Type(void)
{
return ({
void **_sharp_make_list_ptr618;
Form__type arg;
Form__type arg1;
List__O__Form__C____type arg_list;
List__O__Form__C____type form_list;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_93));
(form_list = ({(arg_list = ({((List__O__Form__C____type ) 0);}));
({
({({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type _sharp_make_list617;
({_sharp_make_list617;
_sharp_make_list_ptr618;
(_sharp_make_list_ptr618 = ((void *) (&_sharp_make_list617)));
({({_sharp__sharp_loop619_begin621:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop619_end620;});}})
;
({(parse_symbol)(((String__type) &__string_94));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr618) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr618))).car) = ((void *) arg));
(_sharp_make_list_ptr618 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr618))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop619_begin621;});});
_sharp__sharp_loop619_end620:;});
((* _sharp_make_list_ptr618) = ((void *) 0));
_sharp_make_list617;});
})
);
(arg_list = ({({
struct struct0x0805f9e0 *_sharp_pair_622;
({_sharp_pair_622;
(_sharp_pair_622 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_622).car) = arg1);
(((* _sharp_pair_622).cdr) = arg_list);
((List__O__Form__C____type ) _sharp_pair_622);
})
;}));});}})
;
((void) 0);});
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_95));
({(Compound_Form)(intern( "tuple"), form_list);});})):
((_l__parse__Type__Base_Type)()));
})
;
})
;}

Form__type  _l__parse__Type__Indirection_Type(void)
{
return ({
Form__type form;
({(form = (_l__parse__Type__Tuple_Type)());
({({_sharp__sharp_loop625_begin627:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop625_end626;});}})
;
({(parse_symbol)(((String__type) &__string_96));
(form = ({(Compound_Form)(intern( "*"), ({
struct struct0x0805f9e0 *_sharp_pair_624;
({_sharp_pair_624;
(_sharp_pair_624 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_624).car) = form);
(((* _sharp_pair_624).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_624);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop625_begin627;});});
_sharp__sharp_loop625_end626:;});
({form;});});
})
;}

Form__type  _l__parse__Type__Function_Type(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Type__Indirection_Type)());
({
({({if( ((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 62))||(((Bool__type ) 0))))))
{
({(id = (parse_symbol)(((String__type) &__string_97)));
(form2 = (_l__parse__Type__Function_Type)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_629;
({_sharp_pair_629;
(_sharp_pair_629 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_629).car) = form);
(((* _sharp_pair_629).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_628;
({_sharp_pair_628;
(_sharp_pair_628 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_628).car) = form2);
(((* _sharp_pair_628).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_628);
})
);
((List__O__Form__C____type ) _sharp_pair_629);
})
);}));});}})
;
((void) 0);});
})
;
({form;});});
})
;}

Form__type  _l__parse__Type__Type(void)
{
return ({
Symbol__type __rep_symb;
Form__type __rep_exp;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))))?
(({(__rep_symb = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 64))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_98))):
((parse_symbol)(((String__type) &__string_99))));
})
);
(__rep_exp = (_l__parse__Code__Sequence)());
(parse_symbol)(((String__type) &__string_100));
({(Compound_Form)(__rep_symb, ({
struct struct0x0805f9e0 *_sharp_pair_630;
({_sharp_pair_630;
(_sharp_pair_630 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_630).car) = __rep_exp);
(((* _sharp_pair_630).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_630);
})
);});})):
((_l__parse__Type__Function_Type)()));
})
;
})
;}

Form__type  _l__parse__Type__Labeled_Type(void)
{
return ({
Form__type idf;
Form__type type;
({(idf = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_101));
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( ":"), ({
struct struct0x0805f9e0 *_sharp_pair_632;
({_sharp_pair_632;
(_sharp_pair_632 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_632).car) = idf);
(((* _sharp_pair_632).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_631;
({_sharp_pair_631;
(_sharp_pair_631 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_631).car) = type);
(((* _sharp_pair_631).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_631);
})
);
((List__O__Form__C____type ) _sharp_pair_632);
})
);});});
})
;}

Form__type  _l__parse__Code__Primary(void)
{
return ({
List__O__Form__C____type expl;
Symbol__type __rep_symb;
Form__type __rep_exp;
Symbol__type id;
Form__type form;
Form__type (*funptr)(Symbol__type );
Form__type exp;
List__O__Form__C____type form_list;
Form__type seq;
(form = ({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))?
(({(id = (_l__parse__Lexical__Id)());
(funptr = ({((Form__type (*)(Symbol__type )) (gethash)(((void *) id), ((Hash_Table__type ) parse_macro_hash)));}));
({
((({(funptr != ((Form__type (*)(Symbol__type )) 0));}))?
(({((void) 0);
({((* funptr))(id);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_102));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_103));
({(Compound_Form)(id, form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_104));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@label"), ({
struct struct0x0805f9e0 *_sharp_pair_634;
({_sharp_pair_634;
(_sharp_pair_634 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_634).car) = (Id_Form)(id));
(((* _sharp_pair_634).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_633;
({_sharp_pair_633;
(_sharp_pair_633 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_633).car) = exp);
(((* _sharp_pair_633).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_633);
})
);
((List__O__Form__C____type ) _sharp_pair_634);
})
);});})):
(({(Id_Form)(id);})));
})
));
})
));
})
;})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))?
((_l__parse__Lexical__String_Form)()):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 39))||(((Bool__type ) 0))))))?
((_l__parse__Lexical__Symbol_Form)()):
(({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((Bool__type ) 0))))))))?
((_l__parse__Lexical__Number_Form)()):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))))?
(({(__rep_symb = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 64))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_105))):
((parse_symbol)(((String__type) &__string_106))));
})
);
(__rep_exp = (_l__parse__Code__Sequence)());
(parse_symbol)(((String__type) &__string_107));
({(Compound_Form)(__rep_symb, ({
struct struct0x0805f9e0 *_sharp_pair_635;
({_sharp_pair_635;
(_sharp_pair_635 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_635).car) = __rep_exp);
(((* _sharp_pair_635).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_635);
})
);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_108));
(expl = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_109));
({(((((expl == ((List__O__Form__C____type ) 0)))||((((* ((struct struct0x08054cf8 *) expl)).tail) != ((List__O__Form__C____type ) 0)))))?
((Compound_Form)(intern( "tuple"), expl)):
(((* ((struct struct0x08054cf8 *) expl)).head)));});})):
(({(parse_symbol)(((String__type) &__string_110));
(seq = (_l__parse__Code__Maybe_Empty_Sequence)());
(parse_symbol)(((String__type) &__string_111));
({(Compound_Form)(intern( "@block"), ({
struct struct0x0805f9e0 *_sharp_pair_636;
({_sharp_pair_636;
(_sharp_pair_636 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_636).car) = seq);
(((* _sharp_pair_636).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_636);
})
);});})));
})
));
})
));
})
));
})
));
})
));
})
);
})
;}

Form__type  _l__parse__Code__Postfix(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
List__O__Form__C____type form_list;
({(form = (_l__parse__Code__Primary)());
({({_sharp__sharp_loop643_begin645:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((((new_peek_char)(0) == 46))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop643_end644;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_112));
(form2 = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_113));
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x0805f9e0 *_sharp_pair_639;
({_sharp_pair_639;
(_sharp_pair_639 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_639).car) = form);
(((* _sharp_pair_639).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_638;
({_sharp_pair_638;
(_sharp_pair_638 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_638).car) = form2);
(((* _sharp_pair_638).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_638);
})
);
((List__O__Form__C____type ) _sharp_pair_639);
})
);}));})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 46))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_114));
(id = (_l__parse__Lexical__Id)());
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x0805f9e0 *_sharp_pair_641;
({_sharp_pair_641;
(_sharp_pair_641 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_641).car) = form);
(((* _sharp_pair_641).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_640;
({_sharp_pair_640;
(_sharp_pair_640 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_640).car) = (Symbol_Form)(id));
(((* _sharp_pair_640).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_640);
})
);
((List__O__Form__C____type ) _sharp_pair_641);
})
);}));})):
(({(parse_symbol)(((String__type) &__string_115));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_116));
(form = ({(Compound_Form)(intern( "funcall"), ({
struct struct0x0805f9e0 *_sharp_pair_642;
({_sharp_pair_642;
(_sharp_pair_642 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_642).car) = form);
(((* _sharp_pair_642).cdr) = form_list);
((List__O__Form__C____type ) _sharp_pair_642);
})
);}));})));
})
));
})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop643_begin645;});});
_sharp__sharp_loop643_end644:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Unary_Operator(void)
{
return ({
Symbol__type op;
Form__type form;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))))))))))))?
(({(op = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_117));
({intern( "@unary_minus");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_118));
({intern( "@get_label");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_119));
({intern( "@ref");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_120));
({intern( "@deref");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 45))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_121));
({intern( "@pre_--");});})):
(({(parse_symbol)(((String__type) &__string_122));
({intern( "@pre_++");});})));
})
));
})
));
})
));
})
));
})
);
(form = (_l__parse__Code__Unary_Operator)());
({(Compound_Form)(op, ({
struct struct0x0805f9e0 *_sharp_pair_646;
({_sharp_pair_646;
(_sharp_pair_646 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_646).car) = form);
(((* _sharp_pair_646).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_646);
})
);});})):
((form = (_l__parse__Code__Postfix)())));
})
;
})
;}

Form__type  _l__parse__Code__Multiplicative(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Unary_Operator)());
({({_sharp__sharp_loop650_begin652:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop650_end651;});}})
;
({(id = (parse_symbol)(((String__type) &__string_123)));
(form2 = (_l__parse__Code__Unary_Operator)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_649;
({_sharp_pair_649;
(_sharp_pair_649 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_649).car) = form);
(((* _sharp_pair_649).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_648;
({_sharp_pair_648;
(_sharp_pair_648 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_648).car) = form2);
(((* _sharp_pair_648).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_648);
})
);
((List__O__Form__C____type ) _sharp_pair_649);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop650_begin652;});});
_sharp__sharp_loop650_end651:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Additive(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Multiplicative)());
({({_sharp__sharp_loop656_begin658:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop656_end657;});}})
;
({(id = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_124))):
((parse_symbol)(((String__type) &__string_125))));
})
);
(form2 = (_l__parse__Code__Multiplicative)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_655;
({_sharp_pair_655;
(_sharp_pair_655 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_655).car) = form);
(((* _sharp_pair_655).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_654;
({_sharp_pair_654;
(_sharp_pair_654 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_654).car) = form2);
(((* _sharp_pair_654).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_654);
})
);
((List__O__Form__C____type ) _sharp_pair_655);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop656_begin658;});});
_sharp__sharp_loop656_end657:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Shift(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Additive)());
({({_sharp__sharp_loop662_begin664:;
({
({({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 62))||(((((new_peek_char)(1) == 60))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop662_end663;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_126))):
((parse_symbol)(((String__type) &__string_127))));
})
);
(form2 = (_l__parse__Code__Additive)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_661;
({_sharp_pair_661;
(_sharp_pair_661 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_661).car) = form);
(((* _sharp_pair_661).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_660;
({_sharp_pair_660;
(_sharp_pair_660 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_660).car) = form2);
(((* _sharp_pair_660).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_660);
})
);
((List__O__Form__C____type ) _sharp_pair_661);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop662_begin664;});});
_sharp__sharp_loop662_end663:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Relational(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Shift)());
({({_sharp__sharp_loop668_begin670:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop668_end669;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_128))):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_129))):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_130))):
((parse_symbol)(((String__type) &__string_131))));
})
));
})
));
})
);
(form2 = (_l__parse__Code__Shift)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_667;
({_sharp_pair_667;
(_sharp_pair_667 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_667).car) = form);
(((* _sharp_pair_667).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_666;
({_sharp_pair_666;
(_sharp_pair_666 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_666).car) = form2);
(((* _sharp_pair_666).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_666);
})
);
((List__O__Form__C____type ) _sharp_pair_667);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop668_begin670;});});
_sharp__sharp_loop668_end669:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Equality(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Relational)());
({({_sharp__sharp_loop674_begin676:;
({
({({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((((new_peek_char)(0) == 33))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 61))||(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop674_end675;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_132))):
((parse_symbol)(((String__type) &__string_133))));
})
);
(form2 = (_l__parse__Code__Relational)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_673;
({_sharp_pair_673;
(_sharp_pair_673 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_673).car) = form);
(((* _sharp_pair_673).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_672;
({_sharp_pair_672;
(_sharp_pair_672 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_672).car) = form2);
(((* _sharp_pair_672).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_672);
})
);
((List__O__Form__C____type ) _sharp_pair_673);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop674_begin676;});});
_sharp__sharp_loop674_end675:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Bitwise_And(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Equality)());
({({_sharp__sharp_loop680_begin682:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop680_end681;});}})
;
({(id = (parse_symbol)(((String__type) &__string_134)));
(form2 = (_l__parse__Code__Equality)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_679;
({_sharp_pair_679;
(_sharp_pair_679 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_679).car) = form);
(((* _sharp_pair_679).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_678;
({_sharp_pair_678;
(_sharp_pair_678 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_678).car) = form2);
(((* _sharp_pair_678).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_678);
})
);
((List__O__Form__C____type ) _sharp_pair_679);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop680_begin682;});});
_sharp__sharp_loop680_end681:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Bitwise_Xor(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Bitwise_And)());
({({_sharp__sharp_loop686_begin688:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 94))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop686_end687;});}})
;
({(id = (parse_symbol)(((String__type) &__string_135)));
(form2 = (_l__parse__Code__Bitwise_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_685;
({_sharp_pair_685;
(_sharp_pair_685 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_685).car) = form);
(((* _sharp_pair_685).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_684;
({_sharp_pair_684;
(_sharp_pair_684 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_684).car) = form2);
(((* _sharp_pair_684).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_684);
})
);
((List__O__Form__C____type ) _sharp_pair_685);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop686_begin688;});});
_sharp__sharp_loop686_end687:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Bitwise_Ior(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Bitwise_Xor)());
({({_sharp__sharp_loop692_begin694:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop692_end693;});}})
;
({(id = (parse_symbol)(((String__type) &__string_136)));
(form2 = (_l__parse__Code__Bitwise_Xor)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_691;
({_sharp_pair_691;
(_sharp_pair_691 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_691).car) = form);
(((* _sharp_pair_691).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_690;
({_sharp_pair_690;
(_sharp_pair_690 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_690).car) = form2);
(((* _sharp_pair_690).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_690);
})
);
((List__O__Form__C____type ) _sharp_pair_691);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop692_begin694;});});
_sharp__sharp_loop692_end693:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Logical_And(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Bitwise_Ior)());
({({_sharp__sharp_loop698_begin700:;
({
({({if( (!(((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 97))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 110))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 100))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop698_end699;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_137));
({intern( "@and");});}));
(form2 = (_l__parse__Code__Bitwise_Ior)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_697;
({_sharp_pair_697;
(_sharp_pair_697 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_697).car) = form);
(((* _sharp_pair_697).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_696;
({_sharp_pair_696;
(_sharp_pair_696 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_696).car) = form2);
(((* _sharp_pair_696).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_696);
})
);
((List__O__Form__C____type ) _sharp_pair_697);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop698_begin700;});});
_sharp__sharp_loop698_end699:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Logical_Or(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Logical_And)());
({({_sharp__sharp_loop704_begin706:;
({
({({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 111))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 114))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop704_end705;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_138));
({intern( "@or");});}));
(form2 = (_l__parse__Code__Logical_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_703;
({_sharp_pair_703;
(_sharp_pair_703 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_703).car) = form);
(((* _sharp_pair_703).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_702;
({_sharp_pair_702;
(_sharp_pair_702 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_702).car) = form2);
(((* _sharp_pair_702).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_702);
})
);
((List__O__Form__C____type ) _sharp_pair_703);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop704_begin706;});});
_sharp__sharp_loop704_end705:;});
({form;});});
})
;}

Form__type  _l__parse__Code__Assignment(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Logical_Or)());
({
({({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((Bool__type ) 0))))))
{
({(id = (parse_symbol)(((String__type) &__string_139)));
(form2 = (_l__parse__Code__Assignment)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805f9e0 *_sharp_pair_708;
({_sharp_pair_708;
(_sharp_pair_708 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_708).car) = form);
(((* _sharp_pair_708).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_707;
({_sharp_pair_707;
(_sharp_pair_707 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_707).car) = form2);
(((* _sharp_pair_707).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_707);
})
);
((List__O__Form__C____type ) _sharp_pair_708);
})
);}));});}})
;
((void) 0);});
})
;
({form;});});
})
;}

Form__type  _l__parse__Code__Expression(void)
{
return ({
(_l__parse__Code__Assignment)();
})
;}

Form__type  _l__parse__Code__Maybe_Expression(void)
{
return ({
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))?
((_l__parse__Code__Expression)()):
(({(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type ) 0));})));
})
;
})
;}

Form__type  _l__parse__Code__Expression_Ior_Semicolon(void)
{
return ({
Form__type exp;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))?
(({(exp = (_l__parse__Code__Expression)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_140));
({(Compound_Form)(intern( "@seq"), ({
struct struct0x0805f9e0 *_sharp_pair_710;
({_sharp_pair_710;
(_sharp_pair_710 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_710).car) = exp);
(((* _sharp_pair_710).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_709;
({_sharp_pair_709;
(_sharp_pair_709 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_709).car) = (Compound_Form)(intern( "tuple"), ((List__O__Form__C____type ) 0)));
(((* _sharp_pair_709).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_709);
})
);
((List__O__Form__C____type ) _sharp_pair_710);
})
);});})):
(({exp;})));
})
;})):
(({(parse_symbol)(((String__type) &__string_141));
({(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type ) 0));});})));
})
;
})
;}

Form__type  _l__parse__Code__Maybe_Empty_Sequence(void)
{
return ({
void **_sharp_make_list_ptr712;
Form__type exp2;
List__O__Form__C____type exp_list;
Form__type tup;
Form__type exp;
({(tup = ({(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type ) 0));}));
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))?
(({(exp = (_l__parse__Code__Expression)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))?
(({(exp_list = ({
List__O__Form__C____type _sharp_make_list711;
({_sharp_make_list711;
_sharp_make_list_ptr712;
(_sharp_make_list_ptr712 = ((void *) (&_sharp_make_list711)));
({({_sharp__sharp_loop713_begin715:;
({
({({(parse_symbol)(((String__type) &__string_142));
(exp2 = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))?
((_l__parse__Code__Expression)()):
(({tup;})));
})
);
({({((* _sharp_make_list_ptr712) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr712))).car) = ((void *) exp2));
(_sharp_make_list_ptr712 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr712))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop713_end714;});}})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop713_begin715;});});
_sharp__sharp_loop713_end714:;});
((* _sharp_make_list_ptr712) = ((void *) 0));
_sharp_make_list711;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x0805f9e0 *_sharp_pair_716;
({_sharp_pair_716;
(_sharp_pair_716 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_716).car) = exp);
(((* _sharp_pair_716).cdr) = exp_list);
((List__O__Form__C____type ) _sharp_pair_716);
})
);});})):
(({exp;})));
})
;})):
(({tup;})));
})
;});
})
;}

Form__type  _l__parse__Code__Non_Empty_Sequence(void)
{
return ({
void **_sharp_make_list_ptr718;
Form__type exp2;
List__O__Form__C____type exp_list;
Form__type exp;
({(exp = (_l__parse__Code__Expression)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))?
(({(exp_list = ({
List__O__Form__C____type _sharp_make_list717;
({_sharp_make_list717;
_sharp_make_list_ptr718;
(_sharp_make_list_ptr718 = ((void *) (&_sharp_make_list717)));
({({_sharp__sharp_loop719_begin721:;
({
({({(parse_symbol)(((String__type) &__string_143));
(exp2 = (_l__parse__Code__Expression)());
({({((* _sharp_make_list_ptr718) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr718))).car) = ((void *) exp2));
(_sharp_make_list_ptr718 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr718))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop719_end720;});}})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop719_begin721;});});
_sharp__sharp_loop719_end720:;});
((* _sharp_make_list_ptr718) = ((void *) 0));
_sharp_make_list717;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x0805f9e0 *_sharp_pair_722;
({_sharp_pair_722;
(_sharp_pair_722 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_722).car) = exp);
(((* _sharp_pair_722).cdr) = exp_list);
((List__O__Form__C____type ) _sharp_pair_722);
})
);});})):
(({exp;})));
})
;});
})
;}

Form__type  _l__parse__Code__Sequence(void)
{
return ({
(_l__parse__Code__Non_Empty_Sequence)();
})
;}

List__O__Form__C____type  _l__parse__Code__Expression_List(void)
{
return ({
void **_sharp_make_list_ptr725;
Form__type arg;
Form__type arg1;
List__O__Form__C____type arg_list;
({(arg_list = ({((List__O__Form__C____type ) 0);}));
({
({({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))
{
({(arg1 = (_l__parse__Code__Non_Empty_Sequence)());
(arg_list = ({
List__O__Form__C____type _sharp_make_list724;
({_sharp_make_list724;
_sharp_make_list_ptr725;
(_sharp_make_list_ptr725 = ((void *) (&_sharp_make_list724)));
({({_sharp__sharp_loop726_begin728:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop726_end727;});}})
;
({(parse_symbol)(((String__type) &__string_144));
(arg = (_l__parse__Code__Non_Empty_Sequence)());
({({((* _sharp_make_list_ptr725) = (alloc_cons_cell)());
(((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr725))).car) = ((void *) arg));
(_sharp_make_list_ptr725 = (&((* (* ((struct struct0x086f2e10 **) _sharp_make_list_ptr725))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop726_begin728;});});
_sharp__sharp_loop726_end727:;});
((* _sharp_make_list_ptr725) = ((void *) 0));
_sharp_make_list724;});
})
);
(arg_list = ({({
struct struct0x0805f9e0 *_sharp_pair_729;
({_sharp_pair_729;
(_sharp_pair_729 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_729).car) = arg1);
(((* _sharp_pair_729).cdr) = arg_list);
((List__O__Form__C____type ) _sharp_pair_729);
})
;}));});}})
;
((void) 0);});
})
;
({arg_list;});});
})
;}

Int__type  _l__parse__Lexical__Star_Comment_End(void)
{
return ({
({({({_sharp__sharp_loop731_begin733:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 43))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 41))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop731_end732;});}})
;
(read_char)();
((void) 0);});
})
;
({goto _sharp__sharp_loop731_begin733;});});
_sharp__sharp_loop731_end732:;});
({({({_sharp__sharp_loop734_begin736:;
({
({({(read_char)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop734_end735;});}})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop734_begin736;});});
_sharp__sharp_loop734_end735:;});
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((Bool__type ) 0))))))?
(({(read_char)();})):
((_l__parse__Lexical__Star_Comment_End)()));
})
;});});
})
;}

Int__type  _l__parse__Lexical__Comment(void)
{
return ({
({({(read_char)();});
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((Bool__type ) 0))))))?
(({({(read_char)();});
({({_sharp__sharp_loop738_begin740:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop738_end739;});}})
;
(read_char)();
((void) 0);});
})
;
({goto _sharp__sharp_loop738_begin740;});});
_sharp__sharp_loop738_end739:;});
({(read_char)();});})):
(({({(read_char)();});
(_l__parse__Lexical__Star_Comment_End)();})));
})
;});
})
;}

void  _l__parse__Lexical__Spacing(void)
{
return ({
({({_sharp__sharp_loop742_begin744:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop742_end743;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__Lexical__Comment)()));
})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop742_begin744;});});
_sharp__sharp_loop742_end743:;});
})
;}

Int__type  _l__parse__Lexical__Alpha(void)
{
return ({
(read_char)();
})
;}

Int__type  _l__parse__Lexical__Alpha_Num(void)
{
return ({
(read_char)();
})
;}

Int__type  _l__parse__Lexical__Digit(void)
{
return ({
Int__type d;
({(d = (read_char)());
({((int) d - (int) 48);});});
})
;}

Int__type  _l__parse__Lexical__Octal_Digit(void)
{
return ({
Int__type d;
({(d = (read_char)());
({((int) d - (int) 48);});});
})
;}

Int__type  _l__parse__Lexical__Hexa_Digit(void)
{
return ({
Int__type d;
({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))?
((_l__parse__Lexical__Digit)()):
(({(d = (read_char)());
({((int) ((int) d - (int) 97) + (int) 10);});})));
})
;
})
;}

Int__type  _l__parse__Lexical__Decimal_Number(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({(d = (read_char)());
({((int) d - (int) 48);});}));
({({_sharp__sharp_loop746_begin748:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop746_end747;});}})
;
({(d = (_l__parse__Lexical__Digit)());
({({
({(n = ((int) n * (int) 10));
(n = ((int) n + (int) d));});
})
;});});
((void) 0);});
})
;
({goto _sharp__sharp_loop746_begin748;});});
_sharp__sharp_loop746_end747:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Hexadecimal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop750_begin752:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 102))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop750_end751;});}})
;
({(d = (_l__parse__Lexical__Hexa_Digit)());
({({
({(n = ((int) n * (int) 16));
(n = ((int) n + (int) d));});
})
;});});
((void) 0);});
})
;
({goto _sharp__sharp_loop750_begin752;});});
_sharp__sharp_loop750_end751:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Octal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop754_begin756:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 55))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop754_end755;});}})
;
({(d = (_l__parse__Lexical__Octal_Digit)());
({({
({(n = ((int) n * (int) 8));
(n = ((int) n + (int) d));});
})
;});});
((void) 0);});
})
;
({goto _sharp__sharp_loop754_begin756;});});
_sharp__sharp_loop754_end755:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Number(void)
{
return ({
({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))?
((_l__parse__Lexical__Decimal_Number)()):
(({({(read_char)();});
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 120))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(_l__parse__Lexical__Hexadecimal_Number_End)();})):
((_l__parse__Lexical__Octal_Number_End)()));
})
;})));
})
;
})
;}

Form__type  _l__parse__Lexical__Number_Form(void)
{
return ({
Int__type n;
({(n = (_l__parse__Lexical__Number)());
(_l__parse__Lexical__Spacing)();
({(Int_Form)(n);});});
})
;}

Symbol__type  _l__parse__Lexical__Id(void)
{
return ({
Int__type start;
Int__type end;
({(start = (get_point_pos)());
(_l__parse__Lexical__Alpha)();
({({_sharp__sharp_loop758_begin760:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop758_end759;});}})
;
(_l__parse__Lexical__Alpha_Num)();
((void) 0);});
})
;
({goto _sharp__sharp_loop758_begin760;});});
_sharp__sharp_loop758_end759:;});
(end = (get_point_pos)());
(_l__parse__Lexical__Spacing)();
({(intern_string)((substring)(start, end));});});
})
;}

Form__type  _l__parse__Lexical__Id_Form(void)
{
return ({
Symbol__type id;
({(id = (_l__parse__Lexical__Id)());
({(Id_Form)(id);});});
})
;}

Int__type  _l__parse__Lexical__Escaped_Character(void)
{
return ({
({(read_char)();
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 110))||(((Bool__type ) 0))))))?
(({({(read_char)();});
({10;});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 116))||(((Bool__type ) 0))))))?
(({({(read_char)();});
({9;});})):
((read_char)()));
})
));
})
;});
})
;}

Symbol__type  _l__parse__Lexical__Symbol(void)
{
return ({
Int__type start;
Int__type end;
Int__type i;
({(i = ({0;}));
(read_char)();
(start = (get_point_pos)());
({({_sharp__sharp_loop762_begin764:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop762_end763;});}})
;
({({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))?
((read_char)()):
(({(read_char)();
(read_char)();})));
})
;
(i = ({((int) i + (int) 1);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop762_begin764;});});
_sharp__sharp_loop762_end763:;});
(end = (get_point_pos)());
(read_char)();
(_l__parse__Lexical__Spacing)();
({(intern_string)((get_parsed_string_symbol)(i, start, end));});});
})
;}

Form__type  _l__parse__Lexical__Symbol_Form(void)
{
return ({
Symbol__type s;
({(s = (_l__parse__Lexical__Symbol)());
({(Symbol_Form)(s);});});
})
;}

String__type  _l__parse__Lexical__String(void)
{
return ({
Int__type start;
Int__type end;
Int__type i;
({(i = ({0;}));
(start = (get_point_pos)());
({({_sharp__sharp_loop766_begin771:;
({
({({(read_char)();
({({_sharp__sharp_loop768_begin770:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 35))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 33))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop768_end769;});}})
;
({({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 35))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 33))))||(((Bool__type ) 0))))))))))?
((read_char)()):
(({(read_char)();
(read_char)();})));
})
;
(i = ({((int) i + (int) 1);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop768_begin770;});});
_sharp__sharp_loop768_end769:;});
(end = (get_point_pos)());
(read_char)();
(_l__parse__Lexical__Spacing)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop766_end767;});}})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop766_begin771;});});
_sharp__sharp_loop766_end767:;});
({(get_parsed_string_string)(i, start, end);});});
})
;}

Form__type  _l__parse__Lexical__String_Form(void)
{
return ({
String__type s;
({(s = (_l__parse__Lexical__String)());
({(String_Form)(s);});});
})
;}

Form__type  _l__parse__Lexical__Any(void)
{
return ({
({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))?
((_l__parse__Lexical__Id_Form)()):
(({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((Bool__type ) 0))))))))?
((_l__parse__Lexical__Number_Form)()):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 39))||(((Bool__type ) 0))))))?
((_l__parse__Lexical__Symbol_Form)()):
((_l__parse__Lexical__String_Form)()));
})
));
})
));
})
;
})
;}
