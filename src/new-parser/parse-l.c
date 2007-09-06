/* Automatically generated : do not edit!*/
#include "parse-l.inc"
Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type__type parse_top_level_hash;

Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type__type parse_macro_hash;

void  init__parse_l(void)
{
return ({
({(parse_macro_hash = ((Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type__type ) (make_hash_table)()));
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
(parse_top_level_hash = ((Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type__type ) (make_hash_table)()));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "function")), ((void *) (&_l__parse__Top_Level__function)), ((Hash_Table__type ) parse_top_level_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "global")), ((void *) (&_l__parse__Top_Level__global)), ((Hash_Table__type ) parse_top_level_hash)));
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
({({_sharp__sharp_loop494_begin496:;
({
({(read_char)();
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 61))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 59))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop494_end495;});}})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop494_begin496;});});
_sharp__sharp_loop494_end495:;});
(end = (get_point_pos)());
({(String_Form)((get_parsed_string_string)(((int) end - (int) start), ((int) start - (int) 1), end));});});
})
;}

List__O__Form__C____type__type  _l__parse__XML_Parser__Content_List(void)
{
return ({
Form__type cd;
List__O__Form__C____type__type cl;
Form__type form;
Form__type exp;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))?
(({({(read_char)();});
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((Bool__type ) 0))))))?
(({({(read_char)();});
({((List__O__Form__C____type__type ) 0);});})):
(({(form = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(exp = (_l__parse__Code__Sequence)());
({(read_char)();});
({(read_char)();});
({(Compound_Form)(intern( "$"), ({
struct struct0x0805e580 *_sharp_pair_497;
({_sharp_pair_497;
(_sharp_pair_497 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_497).car) = exp);
(((* _sharp_pair_497).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_497);
})
);});})):
((_l__parse__XML_Parser__Tagged_Compound)()));
})
);
(cl = (_l__parse__XML_Parser__Content_List)());
({({
struct struct0x0805e580 *_sharp_pair_498;
({_sharp_pair_498;
(_sharp_pair_498 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_498).car) = form);
(((* _sharp_pair_498).cdr) = cl);
((List__O__Form__C____type__type ) _sharp_pair_498);
})
;});})));
})
;})):
(({(cd = (_l__parse__XML_Parser__CharData)());
(cl = (_l__parse__XML_Parser__Content_List)());
({({
struct struct0x0805e580 *_sharp_pair_499;
({_sharp_pair_499;
(_sharp_pair_499 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_499).car) = cd);
(((* _sharp_pair_499).cdr) = cl);
((List__O__Form__C____type__type ) _sharp_pair_499);
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
List__O__Form__C____type__type cl;
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

Int__type  _l__parse__Top_Level__Star_Comment_End(void)
{
return ({
({({({_sharp__sharp_loop501_begin503:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 43))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 41))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop501_end502;});}})
;
(read_char)();
((void) 0);});
})
;
({goto _sharp__sharp_loop501_begin503;});});
_sharp__sharp_loop501_end502:;});
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
(({({({_sharp__sharp_loop504_begin506:;
({
({({(read_char)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop504_end505;});}})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop504_begin506;});});
_sharp__sharp_loop504_end505:;});
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((Bool__type ) 0))))))?
(({(read_char)();})):
((_l__parse__Top_Level__Star_Comment_End)()));
})
;})):
((_l__parse__Top_Level__Star_Comment_End)()));
})
;});
})
;}

Int__type  _l__parse__Top_Level__Comment(void)
{
return ({
({({(read_char)();});
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((Bool__type ) 0))))))?
(({({(read_char)();});
({({_sharp__sharp_loop508_begin510:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop508_end509;});}})
;
(read_char)();
((void) 0);});
})
;
({goto _sharp__sharp_loop508_begin510;});});
_sharp__sharp_loop508_end509:;});
({(read_char)();});})):
(({({(read_char)();});
(_l__parse__Top_Level__Star_Comment_End)();})));
})
;});
})
;}

void  _l__parse__Top_Level__Spacing(void)
{
return ({
({({_sharp__sharp_loop512_begin514:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop512_end513;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__Top_Level__Comment)()));
})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop512_begin514;});});
_sharp__sharp_loop512_end513:;});
})
;}

List__O__Form__C____type__type  _l__parse__Top_Level__All(void)
{
return ({
void **_sharp_make_list_ptr517;
Form__type form;
List__O__Form__C____type__type list;
({(_l__parse__Top_Level__Spacing)();
(list = ({
List__O__Form__C____type__type _sharp_make_list516;
({_sharp_make_list516;
_sharp_make_list_ptr517;
(_sharp_make_list_ptr517 = ((void *) (&_sharp_make_list516)));
({({_sharp__sharp_loop518_begin520:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop518_end519;});}})
;
({(form = (_l__parse__Top_Level__Top)());
(_l__parse__Top_Level__Spacing)();
({({((* _sharp_make_list_ptr517) = (alloc_cons_cell)());
(((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr517))).car) = ((void *) form));
(_sharp_make_list_ptr517 = (&((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr517))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop518_begin520;});});
_sharp__sharp_loop518_end519:;});
((* _sharp_make_list_ptr517) = ((void *) 0));
_sharp_make_list516;});
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
({(print_String)(((String__type) &__string_23));
(print_String)(((String__type) &__string_24));
(print_Symbol)(id);
(print_String)(((String__type) &__string_25));
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
void **_sharp_make_list_ptr523;
Form__type ret_type;
List__O__Form__C____type__type params;
Form__type body;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
Symbol__type name;
({(name = (_l__parse__Lexical__Id)());
(parse_symbol)(((String__type) &__string_26));
(params = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))
{
({(arg1 = (_l__parse__Type__Labeled_Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list522;
({_sharp_make_list522;
_sharp_make_list_ptr523;
(_sharp_make_list_ptr523 = ((void *) (&_sharp_make_list522)));
({({_sharp__sharp_loop524_begin526:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop524_end525;});}})
;
({(parse_symbol)(((String__type) &__string_27));
(arg = (_l__parse__Type__Labeled_Type)());
({({((* _sharp_make_list_ptr523) = (alloc_cons_cell)());
(((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr523))).car) = ((void *) arg));
(_sharp_make_list_ptr523 = (&((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr523))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop524_begin526;});});
_sharp__sharp_loop524_end525:;});
((* _sharp_make_list_ptr523) = ((void *) 0));
_sharp_make_list522;});
})
);
(arg_list = ({({
struct struct0x0805e580 *_sharp_pair_527;
({_sharp_pair_527;
(_sharp_pair_527 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_527).car) = arg1);
(((* _sharp_pair_527).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_527);
})
;}));});}})
;
((void) 0);});
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_28));
(parse_symbol)(((String__type) &__string_29));
(ret_type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_30));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_31));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805e580 *_sharp_pair_533;
({_sharp_pair_533;
(_sharp_pair_533 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_533).car) = (Id_Form)(fsymb));
(((* _sharp_pair_533).cdr) = ({
struct struct0x0805e580 *_sharp_pair_532;
({_sharp_pair_532;
(_sharp_pair_532 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_532).car) = (Id_Form)(name));
(((* _sharp_pair_532).cdr) = ({
struct struct0x0805e580 *_sharp_pair_531;
({_sharp_pair_531;
(_sharp_pair_531 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_531).car) = (Compound_Form)(intern( "lambda"), ({
struct struct0x0805e580 *_sharp_pair_530;
({_sharp_pair_530;
(_sharp_pair_530 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_530).car) = ret_type);
(((* _sharp_pair_530).cdr) = ({
struct struct0x0805e580 *_sharp_pair_529;
({_sharp_pair_529;
(_sharp_pair_529 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_529).car) = (Compound_Form)(intern( "tuple"), params));
(((* _sharp_pair_529).cdr) = ({
struct struct0x0805e580 *_sharp_pair_528;
({_sharp_pair_528;
(_sharp_pair_528 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_528).car) = body);
(((* _sharp_pair_528).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_528);
})
);
((List__O__Form__C____type__type ) _sharp_pair_529);
})
);
((List__O__Form__C____type__type ) _sharp_pair_530);
})
));
(((* _sharp_pair_531).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_531);
})
);
((List__O__Form__C____type__type ) _sharp_pair_532);
})
);
((List__O__Form__C____type__type ) _sharp_pair_533);
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
(parse_symbol)(((String__type) &__string_32));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805e580 *_sharp_pair_536;
({_sharp_pair_536;
(_sharp_pair_536 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_536).car) = (Id_Form)(fsymb));
(((* _sharp_pair_536).cdr) = ({
struct struct0x0805e580 *_sharp_pair_535;
({_sharp_pair_535;
(_sharp_pair_535 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_535).car) = (Id_Form)(name));
(((* _sharp_pair_535).cdr) = ({
struct struct0x0805e580 *_sharp_pair_534;
({_sharp_pair_534;
(_sharp_pair_534 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_534).car) = type);
(((* _sharp_pair_534).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_534);
})
);
((List__O__Form__C____type__type ) _sharp_pair_535);
})
);
((List__O__Form__C____type__type ) _sharp_pair_536);
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
(parse_symbol)(((String__type) &__string_33));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_34));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805e580 *_sharp_pair_539;
({_sharp_pair_539;
(_sharp_pair_539 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_539).car) = (Id_Form)(fsymb));
(((* _sharp_pair_539).cdr) = ({
struct struct0x0805e580 *_sharp_pair_538;
({_sharp_pair_538;
(_sharp_pair_538 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_538).car) = name);
(((* _sharp_pair_538).cdr) = ({
struct struct0x0805e580 *_sharp_pair_537;
({_sharp_pair_537;
(_sharp_pair_537 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_537).car) = exp);
(((* _sharp_pair_537).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_537);
})
);
((List__O__Form__C____type__type ) _sharp_pair_538);
})
);
((List__O__Form__C____type__type ) _sharp_pair_539);
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
(parse_symbol)(((String__type) &__string_35));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_36));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805e580 *_sharp_pair_542;
({_sharp_pair_542;
(_sharp_pair_542 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_542).car) = (Id_Form)(fsymb));
(((* _sharp_pair_542).cdr) = ({
struct struct0x0805e580 *_sharp_pair_541;
({_sharp_pair_541;
(_sharp_pair_541 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_541).car) = type_name);
(((* _sharp_pair_541).cdr) = ({
struct struct0x0805e580 *_sharp_pair_540;
({_sharp_pair_540;
(_sharp_pair_540 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_540).car) = type);
(((* _sharp_pair_540).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_540);
})
);
((List__O__Form__C____type__type ) _sharp_pair_541);
})
);
((List__O__Form__C____type__type ) _sharp_pair_542);
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
(parse_symbol)(((String__type) &__string_37));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_38));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805e580 *_sharp_pair_545;
({_sharp_pair_545;
(_sharp_pair_545 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_545).car) = (Id_Form)(fsymb));
(((* _sharp_pair_545).cdr) = ({
struct struct0x0805e580 *_sharp_pair_544;
({_sharp_pair_544;
(_sharp_pair_544 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_544).car) = type_name);
(((* _sharp_pair_544).cdr) = ({
struct struct0x0805e580 *_sharp_pair_543;
({_sharp_pair_543;
(_sharp_pair_543 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_543).car) = type);
(((* _sharp_pair_543).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_543);
})
);
((List__O__Form__C____type__type ) _sharp_pair_544);
})
);
((List__O__Form__C____type__type ) _sharp_pair_545);
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
(parse_symbol)(((String__type) &__string_39));
(param = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_40));
(parse_symbol)(((String__type) &__string_41));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_42));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805e580 *_sharp_pair_550;
({_sharp_pair_550;
(_sharp_pair_550 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_550).car) = (Id_Form)(fsymb));
(((* _sharp_pair_550).cdr) = ({
struct struct0x0805e580 *_sharp_pair_549;
({_sharp_pair_549;
(_sharp_pair_549 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_549).car) = name);
(((* _sharp_pair_549).cdr) = ({
struct struct0x0805e580 *_sharp_pair_548;
({_sharp_pair_548;
(_sharp_pair_548 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_548).car) = (Compound_Form)(intern( ":"), ({
struct struct0x0805e580 *_sharp_pair_547;
({_sharp_pair_547;
(_sharp_pair_547 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_547).car) = param);
(((* _sharp_pair_547).cdr) = ({
struct struct0x0805e580 *_sharp_pair_546;
({_sharp_pair_546;
(_sharp_pair_546 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_546).car) = body);
(((* _sharp_pair_546).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_546);
})
);
((List__O__Form__C____type__type ) _sharp_pair_547);
})
));
(((* _sharp_pair_548).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_548);
})
);
((List__O__Form__C____type__type ) _sharp_pair_549);
})
);
((List__O__Form__C____type__type ) _sharp_pair_550);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__macro(Symbol__type  fsymb)
{
return ({
void **_sharp_make_list_ptr557;
List__O__Form__C____type__type params;
Form__type body;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
Form__type name;
Form__type macro_name;
Form__type type;
({(macro_name = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_43));
(params = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))
{
({(arg1 = ({(name = (_l__parse__Lexical__Id_Form)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( ":"), ({
struct struct0x0805e580 *_sharp_pair_552;
({_sharp_pair_552;
(_sharp_pair_552 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_552).car) = name);
(((* _sharp_pair_552).cdr) = ({
struct struct0x0805e580 *_sharp_pair_551;
({_sharp_pair_551;
(_sharp_pair_551 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_551).car) = type);
(((* _sharp_pair_551).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_551);
})
);
((List__O__Form__C____type__type ) _sharp_pair_552);
})
);});})):
(({name;})));
})
;}));
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list556;
({_sharp_make_list556;
_sharp_make_list_ptr557;
(_sharp_make_list_ptr557 = ((void *) (&_sharp_make_list556)));
({({_sharp__sharp_loop558_begin560:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop558_end559;});}})
;
({(parse_symbol)(((String__type) &__string_44));
(arg = ({(name = (_l__parse__Lexical__Id_Form)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( ":"), ({
struct struct0x0805e580 *_sharp_pair_555;
({_sharp_pair_555;
(_sharp_pair_555 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_555).car) = name);
(((* _sharp_pair_555).cdr) = ({
struct struct0x0805e580 *_sharp_pair_554;
({_sharp_pair_554;
(_sharp_pair_554 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_554).car) = type);
(((* _sharp_pair_554).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_554);
})
);
((List__O__Form__C____type__type ) _sharp_pair_555);
})
);});})):
(({name;})));
})
;}));
({({((* _sharp_make_list_ptr557) = (alloc_cons_cell)());
(((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr557))).car) = ((void *) arg));
(_sharp_make_list_ptr557 = (&((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr557))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop558_begin560;});});
_sharp__sharp_loop558_end559:;});
((* _sharp_make_list_ptr557) = ((void *) 0));
_sharp_make_list556;});
})
);
(arg_list = ({({
struct struct0x0805e580 *_sharp_pair_561;
({_sharp_pair_561;
(_sharp_pair_561 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_561).car) = arg1);
(((* _sharp_pair_561).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_561);
})
;}));});}})
;
((void) 0);});
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_45));
(parse_symbol)(((String__type) &__string_46));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_47));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805e580 *_sharp_pair_565;
({_sharp_pair_565;
(_sharp_pair_565 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_565).car) = (Id_Form)(fsymb));
(((* _sharp_pair_565).cdr) = ({
struct struct0x0805e580 *_sharp_pair_564;
({_sharp_pair_564;
(_sharp_pair_564 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_564).car) = macro_name);
(((* _sharp_pair_564).cdr) = ({
struct struct0x0805e580 *_sharp_pair_563;
({_sharp_pair_563;
(_sharp_pair_563 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_563).car) = (Compound_Form)(intern( "tuple"), params));
(((* _sharp_pair_563).cdr) = ({
struct struct0x0805e580 *_sharp_pair_562;
({_sharp_pair_562;
(_sharp_pair_562 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_562).car) = body);
(((* _sharp_pair_562).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_562);
})
);
((List__O__Form__C____type__type ) _sharp_pair_563);
})
);
((List__O__Form__C____type__type ) _sharp_pair_564);
})
);
((List__O__Form__C____type__type ) _sharp_pair_565);
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
(({(parse_symbol)(((String__type) &__string_48));
(parse_symbol)(((String__type) &__string_49));
(name = (_l__parse__Lexical__Id_Form)());
({(read_char)();});
(parse_symbol)(((String__type) &__string_50));
(exp = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "label"), ({
struct struct0x0805e580 *_sharp_pair_568;
({_sharp_pair_568;
(_sharp_pair_568 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_568).car) = (Compound_Form)(intern( "left"), ({
struct struct0x0805e580 *_sharp_pair_566;
({_sharp_pair_566;
(_sharp_pair_566 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_566).car) = name);
(((* _sharp_pair_566).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_566);
})
));
(((* _sharp_pair_568).cdr) = ({
struct struct0x0805e580 *_sharp_pair_567;
({_sharp_pair_567;
(_sharp_pair_567 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_567).car) = exp);
(((* _sharp_pair_567).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_567);
})
);
((List__O__Form__C____type__type ) _sharp_pair_568);
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
(({(parse_symbol)(((String__type) &__string_51));
(att1 = (_l__parse__Top_Level__attribute_component)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_52));
(att2 = (_l__parse__Top_Level__attribute_component)());
(parse_symbol)(((String__type) &__string_53));
({(Compound_Form)(intern( "tuple"), ({
struct struct0x0805e580 *_sharp_pair_570;
({_sharp_pair_570;
(_sharp_pair_570 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_570).car) = att1);
(((* _sharp_pair_570).cdr) = ({
struct struct0x0805e580 *_sharp_pair_569;
({_sharp_pair_569;
(_sharp_pair_569 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_569).car) = att2);
(((* _sharp_pair_569).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_569);
})
);
((List__O__Form__C____type__type ) _sharp_pair_570);
})
);});})):
(({(parse_symbol)(((String__type) &__string_54));
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
(parse_symbol)(((String__type) &__string_55));
(expression = (_l__parse__Top_Level__attributes_components)());
(parse_symbol)(((String__type) &__string_56));
({(Compound_Form)(intern( "define"), ({
struct struct0x0805e580 *_sharp_pair_575;
({_sharp_pair_575;
(_sharp_pair_575 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_575).car) = (Id_Form)(fsymb));
(((* _sharp_pair_575).cdr) = ({
struct struct0x0805e580 *_sharp_pair_574;
({_sharp_pair_574;
(_sharp_pair_574 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_574).car) = type);
(((* _sharp_pair_574).cdr) = ({
struct struct0x0805e580 *_sharp_pair_573;
({_sharp_pair_573;
(_sharp_pair_573 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_573).car) = (Id_Form)(objname));
(((* _sharp_pair_573).cdr) = ({
struct struct0x0805e580 *_sharp_pair_572;
({_sharp_pair_572;
(_sharp_pair_572 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_572).car) = (Id_Form)(fieldname));
(((* _sharp_pair_572).cdr) = ({
struct struct0x0805e580 *_sharp_pair_571;
({_sharp_pair_571;
(_sharp_pair_571 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_571).car) = expression);
(((* _sharp_pair_571).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_571);
})
);
((List__O__Form__C____type__type ) _sharp_pair_572);
})
);
((List__O__Form__C____type__type ) _sharp_pair_573);
})
);
((List__O__Form__C____type__type ) _sharp_pair_574);
})
);
((List__O__Form__C____type__type ) _sharp_pair_575);
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
struct struct0x0805e580 *_sharp_pair_577;
({_sharp_pair_577;
(_sharp_pair_577 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_577).car) = (Id_Form)(fsymb));
(((* _sharp_pair_577).cdr) = ({
struct struct0x0805e580 *_sharp_pair_576;
({_sharp_pair_576;
(_sharp_pair_576 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_576).car) = any);
(((* _sharp_pair_576).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_576);
})
);
((List__O__Form__C____type__type ) _sharp_pair_577);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__include(Symbol__type  fsymb)
{
return ({
String__type filename;
({(filename = (_l__parse__Lexical__String)());
(parse_symbol)(((String__type) &__string_57));
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
List__O__Form__C____type__type typel;
Form__type id;
Form__type type;
({(id = (_l__parse__Lexical__Id_Form)());
(typel = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(type = (_l__parse__Type__Type)());
({({
struct struct0x0805e580 *_sharp_pair_578;
({_sharp_pair_578;
(_sharp_pair_578 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_578).car) = type);
(((* _sharp_pair_578).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_578);
})
;});})):
(({((List__O__Form__C____type__type ) 0);})));
})
);
({(Compound_Form)(intern( "let"), ({
struct struct0x0805e580 *_sharp_pair_579;
({_sharp_pair_579;
(_sharp_pair_579 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_579).car) = id);
(((* _sharp_pair_579).cdr) = typel);
((List__O__Form__C____type__type ) _sharp_pair_579);
})
);});});
})
;}

Form__type  _l__parse__Macro__if(Symbol__type  symb)
{
return ({
List__O__Form__C____type__type elsel;
Form__type cond;
Form__type exp2;
Form__type exp;
({(parse_symbol)(((String__type) &__string_58));
(cond = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_59));
(exp = (_l__parse__Code__Expression)());
(elsel = ({
((((((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 101))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 108))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 115))||(((Bool__type ) 0))))))&&(((((new_peek_char)(3) == 101))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_60));
(exp2 = (_l__parse__Code__Expression)());
({({
struct struct0x0805e580 *_sharp_pair_580;
({_sharp_pair_580;
(_sharp_pair_580 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_580).car) = exp2);
(((* _sharp_pair_580).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_580);
})
;});})):
(({((List__O__Form__C____type__type ) 0);})));
})
);
({(Compound_Form)(intern( "if"), ({
struct struct0x0805e580 *_sharp_pair_582;
({_sharp_pair_582;
(_sharp_pair_582 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_582).car) = cond);
(((* _sharp_pair_582).cdr) = ({
struct struct0x0805e580 *_sharp_pair_581;
({_sharp_pair_581;
(_sharp_pair_581 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_581).car) = exp);
(((* _sharp_pair_581).cdr) = elsel);
((List__O__Form__C____type__type ) _sharp_pair_581);
})
);
((List__O__Form__C____type__type ) _sharp_pair_582);
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
struct struct0x0805e580 *_sharp_pair_583;
({_sharp_pair_583;
(_sharp_pair_583 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_583).car) = exp);
(((* _sharp_pair_583).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_583);
})
);});});
})
;}

Form__type  _l__parse__Macro__while_like(Symbol__type  symb)
{
return ({
Form__type body;
Form__type cond;
({(parse_symbol)(((String__type) &__string_61));
(cond = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_62));
(body = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "while"), ({
struct struct0x0805e580 *_sharp_pair_585;
({_sharp_pair_585;
(_sharp_pair_585 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_585).car) = cond);
(((* _sharp_pair_585).cdr) = ({
struct struct0x0805e580 *_sharp_pair_584;
({_sharp_pair_584;
(_sharp_pair_584 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_584).car) = body);
(((* _sharp_pair_584).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_584);
})
);
((List__O__Form__C____type__type ) _sharp_pair_585);
})
);});});
})
;}

Form__type  _l__parse__Macro__break(Symbol__type  symb)
{
return ({
({(Compound_Form)(intern( "break"), ((List__O__Form__C____type__type ) 0));});
})
;}

Form__type  _l__parse__Macro__continue(Symbol__type  symb)
{
return ({
Form__type exp;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_63));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@seq"), ({
struct struct0x0805e580 *_sharp_pair_587;
({_sharp_pair_587;
(_sharp_pair_587 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_587).car) = (Compound_Form)(intern( "@set_continue"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_587).cdr) = ({
struct struct0x0805e580 *_sharp_pair_586;
({_sharp_pair_586;
(_sharp_pair_586 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_586).car) = exp);
(((* _sharp_pair_586).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_586);
})
);
((List__O__Form__C____type__type ) _sharp_pair_587);
})
);});})):
(({(Compound_Form)(intern( "continue"), ((List__O__Form__C____type__type ) 0));})));
})
;
})
;}

Form__type  _l__parse__Macro__foreach(Symbol__type  symb)
{
return ({
Form__type var;
Form__type body;
Form__type collect;
({(parse_symbol)(((String__type) &__string_64));
(var = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_65));
(collect = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_66));
(body = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "foreach"), ({
struct struct0x0805e580 *_sharp_pair_590;
({_sharp_pair_590;
(_sharp_pair_590 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_590).car) = var);
(((* _sharp_pair_590).cdr) = ({
struct struct0x0805e580 *_sharp_pair_589;
({_sharp_pair_589;
(_sharp_pair_589 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_589).car) = collect);
(((* _sharp_pair_589).cdr) = ({
struct struct0x0805e580 *_sharp_pair_588;
({_sharp_pair_588;
(_sharp_pair_588 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_588).car) = body);
(((* _sharp_pair_588).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_588);
})
);
((List__O__Form__C____type__type ) _sharp_pair_589);
})
);
((List__O__Form__C____type__type ) _sharp_pair_590);
})
);});});
})
;}

Form__type  _l__parse__Macro__cast(Symbol__type  symb)
{
return ({
Form__type exp;
Form__type type;
({(parse_symbol)(((String__type) &__string_67));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_68));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_69));
({(Compound_Form)(intern( "cast"), ({
struct struct0x0805e580 *_sharp_pair_592;
({_sharp_pair_592;
(_sharp_pair_592 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_592).car) = type);
(((* _sharp_pair_592).cdr) = ({
struct struct0x0805e580 *_sharp_pair_591;
({_sharp_pair_591;
(_sharp_pair_591 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_591).car) = exp);
(((* _sharp_pair_591).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_591);
})
);
((List__O__Form__C____type__type ) _sharp_pair_592);
})
);});});
})
;}

Form__type  _l__parse__Macro__Form(Symbol__type  symb)
{
return ({
Form__type exp;
({(parse_symbol)(((String__type) &__string_70));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_71));
({(Compound_Form)(intern( "Form"), ({
struct struct0x0805e580 *_sharp_pair_593;
({_sharp_pair_593;
(_sharp_pair_593 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_593).car) = exp);
(((* _sharp_pair_593).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_593);
})
);});});
})
;}

Form__type  _l__parse__Macro__XML(Symbol__type  fsymb)
{
return ({
Form__type form;
({(parse_symbol)(((String__type) &__string_72));
(form = (_l__parse__XML_Parser__Content)());
(parse_symbol)(((String__type) &__string_73));
({(Compound_Form)(intern( "XML"), ({
struct struct0x0805e580 *_sharp_pair_594;
({_sharp_pair_594;
(_sharp_pair_594 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_594).car) = form);
(((* _sharp_pair_594).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_594);
})
);});});
})
;}

Form__type  _l__parse__Type__Base_Type(void)
{
return ({
void **_sharp_make_list_ptr603;
void **_sharp_make_list_ptr597;
List__O__Form__C____type__type form_list2;
Form__type lab_type;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
Symbol__type id;
Form__type form;
List__O__Form__C____type__type form_list;
({(id = (_l__parse__Lexical__Id)());
(form = ({
((({(id == intern( "struct"));}))?
(({((void) 0);
(parse_symbol)(((String__type) &__string_74));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list596;
({_sharp_make_list596;
_sharp_make_list_ptr597;
(_sharp_make_list_ptr597 = ((void *) (&_sharp_make_list596)));
({({_sharp__sharp_loop598_begin600:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop598_end599;});}})
;
({(lab_type = (_l__parse__Type__Labeled_Type)());
(parse_symbol)(((String__type) &__string_75));
({({((* _sharp_make_list_ptr597) = (alloc_cons_cell)());
(((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr597))).car) = ((void *) lab_type));
(_sharp_make_list_ptr597 = (&((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr597))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop598_begin600;});});
_sharp__sharp_loop598_end599:;});
((* _sharp_make_list_ptr597) = ((void *) 0));
_sharp_make_list596;});
})
);
(parse_symbol)(((String__type) &__string_76));
({(Compound_Form)(intern( "struct"), form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_77));
(form_list2 = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list602;
({_sharp_make_list602;
_sharp_make_list_ptr603;
(_sharp_make_list_ptr603 = ((void *) (&_sharp_make_list602)));
({({_sharp__sharp_loop604_begin606:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop604_end605;});}})
;
({(parse_symbol)(((String__type) &__string_78));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr603) = (alloc_cons_cell)());
(((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr603))).car) = ((void *) arg));
(_sharp_make_list_ptr603 = (&((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr603))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop604_begin606;});});
_sharp__sharp_loop604_end605:;});
((* _sharp_make_list_ptr603) = ((void *) 0));
_sharp_make_list602;});
})
);
(arg_list = ({({
struct struct0x0805e580 *_sharp_pair_607;
({_sharp_pair_607;
(_sharp_pair_607 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_607).car) = arg1);
(((* _sharp_pair_607).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_607);
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
);
(_l__parse__Lexical__Spacing)();
({form;});});
})
;}

Form__type  _l__parse__Type__Tuple_Type(void)
{
return ({
void **_sharp_make_list_ptr610;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
List__O__Form__C____type__type form_list;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_79));
(form_list = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list609;
({_sharp_make_list609;
_sharp_make_list_ptr610;
(_sharp_make_list_ptr610 = ((void *) (&_sharp_make_list609)));
({({_sharp__sharp_loop611_begin613:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop611_end612;});}})
;
({(parse_symbol)(((String__type) &__string_80));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr610) = (alloc_cons_cell)());
(((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr610))).car) = ((void *) arg));
(_sharp_make_list_ptr610 = (&((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr610))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop611_begin613;});});
_sharp__sharp_loop611_end612:;});
((* _sharp_make_list_ptr610) = ((void *) 0));
_sharp_make_list609;});
})
);
(arg_list = ({({
struct struct0x0805e580 *_sharp_pair_614;
({_sharp_pair_614;
(_sharp_pair_614 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_614).car) = arg1);
(((* _sharp_pair_614).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_614);
})
;}));});}})
;
((void) 0);});
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_81));
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
({({_sharp__sharp_loop617_begin619:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop617_end618;});}})
;
({(parse_symbol)(((String__type) &__string_82));
(form = ({(Compound_Form)(intern( "*"), ({
struct struct0x0805e580 *_sharp_pair_616;
({_sharp_pair_616;
(_sharp_pair_616 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_616).car) = form);
(((* _sharp_pair_616).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_616);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop617_begin619;});});
_sharp__sharp_loop617_end618:;});
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
({(id = (parse_symbol)(((String__type) &__string_83)));
(form2 = (_l__parse__Type__Function_Type)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_621;
({_sharp_pair_621;
(_sharp_pair_621 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_621).car) = form);
(((* _sharp_pair_621).cdr) = ({
struct struct0x0805e580 *_sharp_pair_620;
({_sharp_pair_620;
(_sharp_pair_620 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_620).car) = form2);
(((* _sharp_pair_620).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_620);
})
);
((List__O__Form__C____type__type ) _sharp_pair_621);
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
(_l__parse__Type__Function_Type)();
})
;}

Form__type  _l__parse__Type__Labeled_Type(void)
{
return ({
Form__type idf;
Form__type type;
({(idf = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_84));
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( ":"), ({
struct struct0x0805e580 *_sharp_pair_623;
({_sharp_pair_623;
(_sharp_pair_623 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_623).car) = idf);
(((* _sharp_pair_623).cdr) = ({
struct struct0x0805e580 *_sharp_pair_622;
({_sharp_pair_622;
(_sharp_pair_622 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_622).car) = type);
(((* _sharp_pair_622).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_622);
})
);
((List__O__Form__C____type__type ) _sharp_pair_623);
})
);});});
})
;}

Form__type  _l__parse__Code__Primary(void)
{
return ({
List__O__Form__C____type__type expl;
Form__type (*funptr)(Symbol__type );
Symbol__type __rep_symb;
Form__type __rep_exp;
Symbol__type id;
Form__type form;
Form__type exp;
List__O__Form__C____type__type form_list;
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
(({(parse_symbol)(((String__type) &__string_85));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_86));
({(Compound_Form)(id, form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_87));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@label"), ({
struct struct0x0805e580 *_sharp_pair_625;
({_sharp_pair_625;
(_sharp_pair_625 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_625).car) = (Id_Form)(id));
(((* _sharp_pair_625).cdr) = ({
struct struct0x0805e580 *_sharp_pair_624;
({_sharp_pair_624;
(_sharp_pair_624 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_624).car) = exp);
(((* _sharp_pair_624).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_624);
})
);
((List__O__Form__C____type__type ) _sharp_pair_625);
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
((parse_symbol)(((String__type) &__string_88))):
((parse_symbol)(((String__type) &__string_89))));
})
);
(__rep_exp = (_l__parse__Code__Sequence)());
(parse_symbol)(((String__type) &__string_90));
({(Compound_Form)(__rep_symb, ({
struct struct0x0805e580 *_sharp_pair_626;
({_sharp_pair_626;
(_sharp_pair_626 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_626).car) = __rep_exp);
(((* _sharp_pair_626).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_626);
})
);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_91));
(expl = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_92));
({(((((expl == ((List__O__Form__C____type__type ) 0)))||((((* ((struct struct0x080548e8 *) expl)).tail) != ((List__O__Form__C____type__type ) 0)))))?
((Compound_Form)(intern( "tuple"), expl)):
(((* ((struct struct0x080548e8 *) expl)).head)));});})):
(({(parse_symbol)(((String__type) &__string_93));
(seq = (_l__parse__Code__Maybe_Empty_Sequence)());
(parse_symbol)(((String__type) &__string_94));
({(Compound_Form)(intern( "@block"), ({
struct struct0x0805e580 *_sharp_pair_627;
({_sharp_pair_627;
(_sharp_pair_627 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_627).car) = seq);
(((* _sharp_pair_627).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_627);
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
List__O__Form__C____type__type form_list;
({(form = (_l__parse__Code__Primary)());
({({_sharp__sharp_loop634_begin636:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((((new_peek_char)(0) == 46))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop634_end635;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_95));
(form2 = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_96));
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x0805e580 *_sharp_pair_630;
({_sharp_pair_630;
(_sharp_pair_630 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_630).car) = form);
(((* _sharp_pair_630).cdr) = ({
struct struct0x0805e580 *_sharp_pair_629;
({_sharp_pair_629;
(_sharp_pair_629 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_629).car) = form2);
(((* _sharp_pair_629).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_629);
})
);
((List__O__Form__C____type__type ) _sharp_pair_630);
})
);}));})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 46))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_97));
(id = (_l__parse__Lexical__Id)());
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x0805e580 *_sharp_pair_632;
({_sharp_pair_632;
(_sharp_pair_632 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_632).car) = form);
(((* _sharp_pair_632).cdr) = ({
struct struct0x0805e580 *_sharp_pair_631;
({_sharp_pair_631;
(_sharp_pair_631 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_631).car) = (Symbol_Form)(id));
(((* _sharp_pair_631).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_631);
})
);
((List__O__Form__C____type__type ) _sharp_pair_632);
})
);}));})):
(({(parse_symbol)(((String__type) &__string_98));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_99));
(form = ({(Compound_Form)(intern( "funcall"), ({
struct struct0x0805e580 *_sharp_pair_633;
({_sharp_pair_633;
(_sharp_pair_633 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_633).car) = form);
(((* _sharp_pair_633).cdr) = form_list);
((List__O__Form__C____type__type ) _sharp_pair_633);
})
);}));})));
})
));
})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop634_begin636;});});
_sharp__sharp_loop634_end635:;});
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
(({(parse_symbol)(((String__type) &__string_100));
({intern( "@unary_minus");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_101));
({intern( "@get_label");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_102));
({intern( "@ref");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_103));
({intern( "@deref");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 45))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_104));
({intern( "@pre_--");});})):
(({(parse_symbol)(((String__type) &__string_105));
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
struct struct0x0805e580 *_sharp_pair_637;
({_sharp_pair_637;
(_sharp_pair_637 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_637).car) = form);
(((* _sharp_pair_637).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_637);
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
({({_sharp__sharp_loop641_begin643:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop641_end642;});}})
;
({(id = (parse_symbol)(((String__type) &__string_106)));
(form2 = (_l__parse__Code__Unary_Operator)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_640;
({_sharp_pair_640;
(_sharp_pair_640 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_640).car) = form);
(((* _sharp_pair_640).cdr) = ({
struct struct0x0805e580 *_sharp_pair_639;
({_sharp_pair_639;
(_sharp_pair_639 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_639).car) = form2);
(((* _sharp_pair_639).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_639);
})
);
((List__O__Form__C____type__type ) _sharp_pair_640);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop641_begin643;});});
_sharp__sharp_loop641_end642:;});
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
({({_sharp__sharp_loop647_begin649:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop647_end648;});}})
;
({(id = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_107))):
((parse_symbol)(((String__type) &__string_108))));
})
);
(form2 = (_l__parse__Code__Multiplicative)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_646;
({_sharp_pair_646;
(_sharp_pair_646 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_646).car) = form);
(((* _sharp_pair_646).cdr) = ({
struct struct0x0805e580 *_sharp_pair_645;
({_sharp_pair_645;
(_sharp_pair_645 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_645).car) = form2);
(((* _sharp_pair_645).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_645);
})
);
((List__O__Form__C____type__type ) _sharp_pair_646);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop647_begin649;});});
_sharp__sharp_loop647_end648:;});
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
({({_sharp__sharp_loop653_begin655:;
({
({({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 62))||(((((new_peek_char)(1) == 60))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop653_end654;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_109))):
((parse_symbol)(((String__type) &__string_110))));
})
);
(form2 = (_l__parse__Code__Additive)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_652;
({_sharp_pair_652;
(_sharp_pair_652 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_652).car) = form);
(((* _sharp_pair_652).cdr) = ({
struct struct0x0805e580 *_sharp_pair_651;
({_sharp_pair_651;
(_sharp_pair_651 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_651).car) = form2);
(((* _sharp_pair_651).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_651);
})
);
((List__O__Form__C____type__type ) _sharp_pair_652);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop653_begin655;});});
_sharp__sharp_loop653_end654:;});
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
({({_sharp__sharp_loop659_begin661:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop659_end660;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_111))):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_112))):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_113))):
((parse_symbol)(((String__type) &__string_114))));
})
));
})
));
})
);
(form2 = (_l__parse__Code__Shift)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_658;
({_sharp_pair_658;
(_sharp_pair_658 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_658).car) = form);
(((* _sharp_pair_658).cdr) = ({
struct struct0x0805e580 *_sharp_pair_657;
({_sharp_pair_657;
(_sharp_pair_657 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_657).car) = form2);
(((* _sharp_pair_657).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_657);
})
);
((List__O__Form__C____type__type ) _sharp_pair_658);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop659_begin661;});});
_sharp__sharp_loop659_end660:;});
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
({({_sharp__sharp_loop665_begin667:;
({
({({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((((new_peek_char)(0) == 33))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 61))||(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop665_end666;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_115))):
((parse_symbol)(((String__type) &__string_116))));
})
);
(form2 = (_l__parse__Code__Relational)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_664;
({_sharp_pair_664;
(_sharp_pair_664 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_664).car) = form);
(((* _sharp_pair_664).cdr) = ({
struct struct0x0805e580 *_sharp_pair_663;
({_sharp_pair_663;
(_sharp_pair_663 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_663).car) = form2);
(((* _sharp_pair_663).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_663);
})
);
((List__O__Form__C____type__type ) _sharp_pair_664);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop665_begin667;});});
_sharp__sharp_loop665_end666:;});
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
({({_sharp__sharp_loop671_begin673:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop671_end672;});}})
;
({(id = (parse_symbol)(((String__type) &__string_117)));
(form2 = (_l__parse__Code__Equality)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_670;
({_sharp_pair_670;
(_sharp_pair_670 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_670).car) = form);
(((* _sharp_pair_670).cdr) = ({
struct struct0x0805e580 *_sharp_pair_669;
({_sharp_pair_669;
(_sharp_pair_669 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_669).car) = form2);
(((* _sharp_pair_669).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_669);
})
);
((List__O__Form__C____type__type ) _sharp_pair_670);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop671_begin673;});});
_sharp__sharp_loop671_end672:;});
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
({({_sharp__sharp_loop677_begin679:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 94))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop677_end678;});}})
;
({(id = (parse_symbol)(((String__type) &__string_118)));
(form2 = (_l__parse__Code__Bitwise_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_676;
({_sharp_pair_676;
(_sharp_pair_676 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_676).car) = form);
(((* _sharp_pair_676).cdr) = ({
struct struct0x0805e580 *_sharp_pair_675;
({_sharp_pair_675;
(_sharp_pair_675 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_675).car) = form2);
(((* _sharp_pair_675).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_675);
})
);
((List__O__Form__C____type__type ) _sharp_pair_676);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop677_begin679;});});
_sharp__sharp_loop677_end678:;});
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
({({_sharp__sharp_loop683_begin685:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop683_end684;});}})
;
({(id = (parse_symbol)(((String__type) &__string_119)));
(form2 = (_l__parse__Code__Bitwise_Xor)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_682;
({_sharp_pair_682;
(_sharp_pair_682 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_682).car) = form);
(((* _sharp_pair_682).cdr) = ({
struct struct0x0805e580 *_sharp_pair_681;
({_sharp_pair_681;
(_sharp_pair_681 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_681).car) = form2);
(((* _sharp_pair_681).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_681);
})
);
((List__O__Form__C____type__type ) _sharp_pair_682);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop683_begin685;});});
_sharp__sharp_loop683_end684:;});
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
({({_sharp__sharp_loop689_begin691:;
({
({({if( (!(((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 97))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 110))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 100))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop689_end690;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_120));
({intern( "@and");});}));
(form2 = (_l__parse__Code__Bitwise_Ior)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_688;
({_sharp_pair_688;
(_sharp_pair_688 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_688).car) = form);
(((* _sharp_pair_688).cdr) = ({
struct struct0x0805e580 *_sharp_pair_687;
({_sharp_pair_687;
(_sharp_pair_687 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_687).car) = form2);
(((* _sharp_pair_687).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_687);
})
);
((List__O__Form__C____type__type ) _sharp_pair_688);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop689_begin691;});});
_sharp__sharp_loop689_end690:;});
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
({({_sharp__sharp_loop695_begin697:;
({
({({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 111))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 114))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop695_end696;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_121));
({intern( "@or");});}));
(form2 = (_l__parse__Code__Logical_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_694;
({_sharp_pair_694;
(_sharp_pair_694 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_694).car) = form);
(((* _sharp_pair_694).cdr) = ({
struct struct0x0805e580 *_sharp_pair_693;
({_sharp_pair_693;
(_sharp_pair_693 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_693).car) = form2);
(((* _sharp_pair_693).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_693);
})
);
((List__O__Form__C____type__type ) _sharp_pair_694);
})
);}));});
((void) 0);});
})
;
({goto _sharp__sharp_loop695_begin697;});});
_sharp__sharp_loop695_end696:;});
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
({(id = (parse_symbol)(((String__type) &__string_122)));
(form2 = (_l__parse__Code__Assignment)());
(form = ({(Compound_Form)(id, ({
struct struct0x0805e580 *_sharp_pair_699;
({_sharp_pair_699;
(_sharp_pair_699 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_699).car) = form);
(((* _sharp_pair_699).cdr) = ({
struct struct0x0805e580 *_sharp_pair_698;
({_sharp_pair_698;
(_sharp_pair_698 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_698).car) = form2);
(((* _sharp_pair_698).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_698);
})
);
((List__O__Form__C____type__type ) _sharp_pair_699);
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
(({(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0));})));
})
;
})
;}

Form__type  _l__parse__Code__Maybe_Empty_Sequence(void)
{
return ({
void **_sharp_make_list_ptr701;
Form__type exp2;
List__O__Form__C____type__type exp_list;
Form__type tup;
Form__type exp;
({(tup = ({(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0));}));
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))?
(({(exp = (_l__parse__Code__Expression)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))?
(({(exp_list = ({
List__O__Form__C____type__type _sharp_make_list700;
({_sharp_make_list700;
_sharp_make_list_ptr701;
(_sharp_make_list_ptr701 = ((void *) (&_sharp_make_list700)));
({({_sharp__sharp_loop702_begin704:;
({
({({(parse_symbol)(((String__type) &__string_123));
(exp2 = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))?
((_l__parse__Code__Expression)()):
(({tup;})));
})
);
({({((* _sharp_make_list_ptr701) = (alloc_cons_cell)());
(((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr701))).car) = ((void *) exp2));
(_sharp_make_list_ptr701 = (&((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr701))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop702_end703;});}})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop702_begin704;});});
_sharp__sharp_loop702_end703:;});
((* _sharp_make_list_ptr701) = ((void *) 0));
_sharp_make_list700;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x0805e580 *_sharp_pair_705;
({_sharp_pair_705;
(_sharp_pair_705 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_705).car) = exp);
(((* _sharp_pair_705).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_705);
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
void **_sharp_make_list_ptr707;
Form__type exp2;
List__O__Form__C____type__type exp_list;
Form__type exp;
({(exp = (_l__parse__Code__Expression)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))?
(({(exp_list = ({
List__O__Form__C____type__type _sharp_make_list706;
({_sharp_make_list706;
_sharp_make_list_ptr707;
(_sharp_make_list_ptr707 = ((void *) (&_sharp_make_list706)));
({({_sharp__sharp_loop708_begin710:;
({
({({(parse_symbol)(((String__type) &__string_124));
(exp2 = (_l__parse__Code__Expression)());
({({((* _sharp_make_list_ptr707) = (alloc_cons_cell)());
(((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr707))).car) = ((void *) exp2));
(_sharp_make_list_ptr707 = (&((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr707))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop708_end709;});}})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop708_begin710;});});
_sharp__sharp_loop708_end709:;});
((* _sharp_make_list_ptr707) = ((void *) 0));
_sharp_make_list706;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x0805e580 *_sharp_pair_711;
({_sharp_pair_711;
(_sharp_pair_711 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_711).car) = exp);
(((* _sharp_pair_711).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_711);
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

List__O__Form__C____type__type  _l__parse__Code__Expression_List(void)
{
return ({
void **_sharp_make_list_ptr714;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))
{
({(arg1 = (_l__parse__Code__Non_Empty_Sequence)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list713;
({_sharp_make_list713;
_sharp_make_list_ptr714;
(_sharp_make_list_ptr714 = ((void *) (&_sharp_make_list713)));
({({_sharp__sharp_loop715_begin717:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop715_end716;});}})
;
({(parse_symbol)(((String__type) &__string_125));
(arg = (_l__parse__Code__Non_Empty_Sequence)());
({({((* _sharp_make_list_ptr714) = (alloc_cons_cell)());
(((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr714))).car) = ((void *) arg));
(_sharp_make_list_ptr714 = (&((* (* ((struct struct0x086db320 **) _sharp_make_list_ptr714))).cdr)));
((void) 0);});});});
((void) 0);});
})
;
({goto _sharp__sharp_loop715_begin717;});});
_sharp__sharp_loop715_end716:;});
((* _sharp_make_list_ptr714) = ((void *) 0));
_sharp_make_list713;});
})
);
(arg_list = ({({
struct struct0x0805e580 *_sharp_pair_718;
({_sharp_pair_718;
(_sharp_pair_718 = ((struct struct0x0805e580 *) (alloc_cons_cell)()));});
(((* _sharp_pair_718).car) = arg1);
(((* _sharp_pair_718).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_718);
})
;}));});}})
;
((void) 0);});
})
;
({arg_list;});});
})
;}

Int__type  _l__parse__Lexical__Comment(void)
{
return ({
({({(read_char)();
(read_char)();});
({({_sharp__sharp_loop720_begin722:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop720_end721;});}})
;
(read_char)();
((void) 0);});
})
;
({goto _sharp__sharp_loop720_begin722;});});
_sharp__sharp_loop720_end721:;});
({(read_char)();});});
})
;}

void  _l__parse__Lexical__Spacing(void)
{
return ({
({({_sharp__sharp_loop724_begin726:;
({
({({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop724_end725;});}})
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
({goto _sharp__sharp_loop724_begin726;});});
_sharp__sharp_loop724_end725:;});
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
({({_sharp__sharp_loop728_begin730:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop728_end729;});}})
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
({goto _sharp__sharp_loop728_begin730;});});
_sharp__sharp_loop728_end729:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Hexadecimal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop732_begin734:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 102))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop732_end733;});}})
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
({goto _sharp__sharp_loop732_begin734;});});
_sharp__sharp_loop732_end733:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Octal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop736_begin738:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 55))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop736_end737;});}})
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
({goto _sharp__sharp_loop736_begin738;});});
_sharp__sharp_loop736_end737:;});
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
({({_sharp__sharp_loop740_begin742:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop740_end741;});}})
;
(_l__parse__Lexical__Alpha_Num)();
((void) 0);});
})
;
({goto _sharp__sharp_loop740_begin742;});});
_sharp__sharp_loop740_end741:;});
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
Int__type i;
Int__type start;
Int__type end;
({(i = ({0;}));
(read_char)();
(start = (get_point_pos)());
({({_sharp__sharp_loop744_begin746:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop744_end745;});}})
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
({goto _sharp__sharp_loop744_begin746;});});
_sharp__sharp_loop744_end745:;});
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
Int__type i;
Int__type start;
Int__type end;
({(i = ({0;}));
(start = (get_point_pos)());
({({_sharp__sharp_loop748_begin753:;
({
({({(read_char)();
({({_sharp__sharp_loop750_begin752:;
({
({({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 35))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 33))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop750_end751;});}})
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
({goto _sharp__sharp_loop750_begin752;});});
_sharp__sharp_loop750_end751:;});
(end = (get_point_pos)());
(read_char)();
(_l__parse__Lexical__Spacing)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop748_end749;});}})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop748_begin753;});});
_sharp__sharp_loop748_end749:;});
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
