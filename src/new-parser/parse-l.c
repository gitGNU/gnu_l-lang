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
((void) 0);});
})
;}

Form__type  _l__parse__XML_Parser__CharData(void)
{
return ({
Int__type start;
Int__type end;
({(start = (get_point_pos)());
({({_sharp__sharp_loop468_begin470:;
({
(read_char)();
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 61))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 59))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop468_end469;});}})
;
})
;
({goto _sharp__sharp_loop468_begin470;});});
_sharp__sharp_loop468_end469:;});
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
struct struct0x080674e0 *_sharp_pair_471;
({_sharp_pair_471;
(_sharp_pair_471 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_471).car) = exp);
(((* _sharp_pair_471).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_471);
})
);});})):
((_l__parse__XML_Parser__Tagged_Compound)()));
})
);
(cl = (_l__parse__XML_Parser__Content_List)());
({({
struct struct0x080674e0 *_sharp_pair_472;
({_sharp_pair_472;
(_sharp_pair_472 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_472).car) = form);
(((* _sharp_pair_472).cdr) = cl);
((List__O__Form__C____type__type ) _sharp_pair_472);
})
;});})));
})
;})):
(({(cd = (_l__parse__XML_Parser__CharData)());
(cl = (_l__parse__XML_Parser__Content_List)());
({({
struct struct0x080674e0 *_sharp_pair_473;
({_sharp_pair_473;
(_sharp_pair_473 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_473).car) = cd);
(((* _sharp_pair_473).cdr) = cl);
((List__O__Form__C____type__type ) _sharp_pair_473);
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
({({({_sharp__sharp_loop475_begin477:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 43))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 41))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop475_end476;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop475_begin477;});});
_sharp__sharp_loop475_end476:;});
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
(({({({_sharp__sharp_loop478_begin480:;
({
({(read_char)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop478_end479;});}})
;
})
;
({goto _sharp__sharp_loop478_begin480;});});
_sharp__sharp_loop478_end479:;});
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
({({_sharp__sharp_loop482_begin484:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop482_end483;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop482_begin484;});});
_sharp__sharp_loop482_end483:;});
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
({({_sharp__sharp_loop486_begin488:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop486_end487;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__Top_Level__Comment)()));
})
;
})
;
({goto _sharp__sharp_loop486_begin488;});});
_sharp__sharp_loop486_end487:;});
})
;}

List__O__Form__C____type__type  _l__parse__Top_Level__All(void)
{
return ({
void **_sharp_make_list_ptr491;
Form__type form;
List__O__Form__C____type__type list;
({(_l__parse__Top_Level__Spacing)();
(list = ({
List__O__Form__C____type__type _sharp_make_list490;
({_sharp_make_list490;
_sharp_make_list_ptr491;
(_sharp_make_list_ptr491 = ((void *) (&_sharp_make_list490)));
({({_sharp__sharp_loop492_begin494:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop492_end493;});}})
;
({(form = (_l__parse__Top_Level__Top)());
(_l__parse__Top_Level__Spacing)();
({({((* _sharp_make_list_ptr491) = (alloc_cons_cell)());
(((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr491))).car) = ((void *) form));
(_sharp_make_list_ptr491 = (&((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr491))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop492_begin494;});});
_sharp__sharp_loop492_end493:;});
((* _sharp_make_list_ptr491) = ((void *) 0));
_sharp_make_list490;});
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
void **_sharp_make_list_ptr497;
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
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))
{
({(arg1 = (_l__parse__Type__Labeled_Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list496;
({_sharp_make_list496;
_sharp_make_list_ptr497;
(_sharp_make_list_ptr497 = ((void *) (&_sharp_make_list496)));
({({_sharp__sharp_loop498_begin500:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop498_end499;});}})
;
({(parse_symbol)(((String__type) &__string_27));
(arg = (_l__parse__Type__Labeled_Type)());
({({((* _sharp_make_list_ptr497) = (alloc_cons_cell)());
(((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr497))).car) = ((void *) arg));
(_sharp_make_list_ptr497 = (&((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr497))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop498_begin500;});});
_sharp__sharp_loop498_end499:;});
((* _sharp_make_list_ptr497) = ((void *) 0));
_sharp_make_list496;});
})
);
(arg_list = ({({
struct struct0x080674e0 *_sharp_pair_501;
({_sharp_pair_501;
(_sharp_pair_501 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_501).car) = arg1);
(((* _sharp_pair_501).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_501);
})
;}));});}})
;
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
struct struct0x080674e0 *_sharp_pair_507;
({_sharp_pair_507;
(_sharp_pair_507 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_507).car) = (Id_Form)(fsymb));
(((* _sharp_pair_507).cdr) = ({
struct struct0x080674e0 *_sharp_pair_506;
({_sharp_pair_506;
(_sharp_pair_506 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_506).car) = (Id_Form)(name));
(((* _sharp_pair_506).cdr) = ({
struct struct0x080674e0 *_sharp_pair_505;
({_sharp_pair_505;
(_sharp_pair_505 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_505).car) = (Compound_Form)(intern( "lambda"), ({
struct struct0x080674e0 *_sharp_pair_504;
({_sharp_pair_504;
(_sharp_pair_504 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_504).car) = ret_type);
(((* _sharp_pair_504).cdr) = ({
struct struct0x080674e0 *_sharp_pair_503;
({_sharp_pair_503;
(_sharp_pair_503 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_503).car) = (Compound_Form)(intern( "tuple"), params));
(((* _sharp_pair_503).cdr) = ({
struct struct0x080674e0 *_sharp_pair_502;
({_sharp_pair_502;
(_sharp_pair_502 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_502).car) = body);
(((* _sharp_pair_502).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_502);
})
);
((List__O__Form__C____type__type ) _sharp_pair_503);
})
);
((List__O__Form__C____type__type ) _sharp_pair_504);
})
));
(((* _sharp_pair_505).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_505);
})
);
((List__O__Form__C____type__type ) _sharp_pair_506);
})
);
((List__O__Form__C____type__type ) _sharp_pair_507);
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
struct struct0x080674e0 *_sharp_pair_510;
({_sharp_pair_510;
(_sharp_pair_510 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_510).car) = (Id_Form)(fsymb));
(((* _sharp_pair_510).cdr) = ({
struct struct0x080674e0 *_sharp_pair_509;
({_sharp_pair_509;
(_sharp_pair_509 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_509).car) = (Id_Form)(name));
(((* _sharp_pair_509).cdr) = ({
struct struct0x080674e0 *_sharp_pair_508;
({_sharp_pair_508;
(_sharp_pair_508 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_508).car) = type);
(((* _sharp_pair_508).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_508);
})
);
((List__O__Form__C____type__type ) _sharp_pair_509);
})
);
((List__O__Form__C____type__type ) _sharp_pair_510);
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
(parse_symbol)(((String__type) &__string_33));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_34));
({(Compound_Form)(intern( "define"), ({
struct struct0x080674e0 *_sharp_pair_513;
({_sharp_pair_513;
(_sharp_pair_513 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_513).car) = (Id_Form)(fsymb));
(((* _sharp_pair_513).cdr) = ({
struct struct0x080674e0 *_sharp_pair_512;
({_sharp_pair_512;
(_sharp_pair_512 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_512).car) = type_name);
(((* _sharp_pair_512).cdr) = ({
struct struct0x080674e0 *_sharp_pair_511;
({_sharp_pair_511;
(_sharp_pair_511 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_511).car) = type);
(((* _sharp_pair_511).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_511);
})
);
((List__O__Form__C____type__type ) _sharp_pair_512);
})
);
((List__O__Form__C____type__type ) _sharp_pair_513);
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
(parse_symbol)(((String__type) &__string_35));
(param = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_36));
(parse_symbol)(((String__type) &__string_37));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_38));
({(Compound_Form)(intern( "define"), ({
struct struct0x080674e0 *_sharp_pair_518;
({_sharp_pair_518;
(_sharp_pair_518 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_518).car) = (Id_Form)(fsymb));
(((* _sharp_pair_518).cdr) = ({
struct struct0x080674e0 *_sharp_pair_517;
({_sharp_pair_517;
(_sharp_pair_517 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_517).car) = name);
(((* _sharp_pair_517).cdr) = ({
struct struct0x080674e0 *_sharp_pair_516;
({_sharp_pair_516;
(_sharp_pair_516 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_516).car) = (Compound_Form)(intern( ":"), ({
struct struct0x080674e0 *_sharp_pair_515;
({_sharp_pair_515;
(_sharp_pair_515 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_515).car) = param);
(((* _sharp_pair_515).cdr) = ({
struct struct0x080674e0 *_sharp_pair_514;
({_sharp_pair_514;
(_sharp_pair_514 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_514).car) = body);
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
);
((List__O__Form__C____type__type ) _sharp_pair_517);
})
);
((List__O__Form__C____type__type ) _sharp_pair_518);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__macro(Symbol__type  fsymb)
{
return ({
void **_sharp_make_list_ptr525;
List__O__Form__C____type__type params;
Form__type body;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
Form__type name;
Form__type type;
Form__type macro_name;
({(macro_name = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_39));
(params = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))
{
({(arg1 = ({(name = (_l__parse__Lexical__Id_Form)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( ":"), ({
struct struct0x080674e0 *_sharp_pair_520;
({_sharp_pair_520;
(_sharp_pair_520 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_520).car) = name);
(((* _sharp_pair_520).cdr) = ({
struct struct0x080674e0 *_sharp_pair_519;
({_sharp_pair_519;
(_sharp_pair_519 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_519).car) = type);
(((* _sharp_pair_519).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_519);
})
);
((List__O__Form__C____type__type ) _sharp_pair_520);
})
);});})):
(({name;})));
})
;}));
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list524;
({_sharp_make_list524;
_sharp_make_list_ptr525;
(_sharp_make_list_ptr525 = ((void *) (&_sharp_make_list524)));
({({_sharp__sharp_loop526_begin528:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop526_end527;});}})
;
({(parse_symbol)(((String__type) &__string_40));
(arg = ({(name = (_l__parse__Lexical__Id_Form)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( ":"), ({
struct struct0x080674e0 *_sharp_pair_523;
({_sharp_pair_523;
(_sharp_pair_523 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_523).car) = name);
(((* _sharp_pair_523).cdr) = ({
struct struct0x080674e0 *_sharp_pair_522;
({_sharp_pair_522;
(_sharp_pair_522 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_522).car) = type);
(((* _sharp_pair_522).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_522);
})
);
((List__O__Form__C____type__type ) _sharp_pair_523);
})
);});})):
(({name;})));
})
;}));
({({((* _sharp_make_list_ptr525) = (alloc_cons_cell)());
(((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr525))).car) = ((void *) arg));
(_sharp_make_list_ptr525 = (&((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr525))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop526_begin528;});});
_sharp__sharp_loop526_end527:;});
((* _sharp_make_list_ptr525) = ((void *) 0));
_sharp_make_list524;});
})
);
(arg_list = ({({
struct struct0x080674e0 *_sharp_pair_529;
({_sharp_pair_529;
(_sharp_pair_529 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_529).car) = arg1);
(((* _sharp_pair_529).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_529);
})
;}));});}})
;
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_41));
(parse_symbol)(((String__type) &__string_42));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_43));
({(Compound_Form)(intern( "define"), ({
struct struct0x080674e0 *_sharp_pair_533;
({_sharp_pair_533;
(_sharp_pair_533 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_533).car) = (Id_Form)(fsymb));
(((* _sharp_pair_533).cdr) = ({
struct struct0x080674e0 *_sharp_pair_532;
({_sharp_pair_532;
(_sharp_pair_532 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_532).car) = macro_name);
(((* _sharp_pair_532).cdr) = ({
struct struct0x080674e0 *_sharp_pair_531;
({_sharp_pair_531;
(_sharp_pair_531 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_531).car) = (Compound_Form)(intern( "tuple"), params));
(((* _sharp_pair_531).cdr) = ({
struct struct0x080674e0 *_sharp_pair_530;
({_sharp_pair_530;
(_sharp_pair_530 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_530).car) = body);
(((* _sharp_pair_530).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_530);
})
);
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

Form__type  _l__parse__Top_Level__attribute_component(void)
{
return ({
Form__type exp;
Form__type name;
({
((((((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 108))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 101))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 102))||(((Bool__type ) 0))))))&&(((((new_peek_char)(3) == 116))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_44));
(parse_symbol)(((String__type) &__string_45));
(name = (_l__parse__Lexical__Id_Form)());
({(read_char)();});
(parse_symbol)(((String__type) &__string_46));
(exp = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "label"), ({
struct struct0x080674e0 *_sharp_pair_536;
({_sharp_pair_536;
(_sharp_pair_536 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_536).car) = (Compound_Form)(intern( "left"), ({
struct struct0x080674e0 *_sharp_pair_534;
({_sharp_pair_534;
(_sharp_pair_534 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_534).car) = name);
(((* _sharp_pair_534).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_534);
})
));
(((* _sharp_pair_536).cdr) = ({
struct struct0x080674e0 *_sharp_pair_535;
({_sharp_pair_535;
(_sharp_pair_535 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_535).car) = exp);
(((* _sharp_pair_535).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_535);
})
);
((List__O__Form__C____type__type ) _sharp_pair_536);
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
(({(parse_symbol)(((String__type) &__string_47));
(att1 = (_l__parse__Top_Level__attribute_component)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_48));
(att2 = (_l__parse__Top_Level__attribute_component)());
(parse_symbol)(((String__type) &__string_49));
({(Compound_Form)(intern( "tuple"), ({
struct struct0x080674e0 *_sharp_pair_538;
({_sharp_pair_538;
(_sharp_pair_538 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_538).car) = att1);
(((* _sharp_pair_538).cdr) = ({
struct struct0x080674e0 *_sharp_pair_537;
({_sharp_pair_537;
(_sharp_pair_537 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_537).car) = att2);
(((* _sharp_pair_537).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_537);
})
);
((List__O__Form__C____type__type ) _sharp_pair_538);
})
);});})):
(({(parse_symbol)(((String__type) &__string_50));
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
(parse_symbol)(((String__type) &__string_51));
(expression = (_l__parse__Top_Level__attributes_components)());
(parse_symbol)(((String__type) &__string_52));
({(Compound_Form)(intern( "define"), ({
struct struct0x080674e0 *_sharp_pair_543;
({_sharp_pair_543;
(_sharp_pair_543 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_543).car) = (Id_Form)(fsymb));
(((* _sharp_pair_543).cdr) = ({
struct struct0x080674e0 *_sharp_pair_542;
({_sharp_pair_542;
(_sharp_pair_542 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_542).car) = type);
(((* _sharp_pair_542).cdr) = ({
struct struct0x080674e0 *_sharp_pair_541;
({_sharp_pair_541;
(_sharp_pair_541 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_541).car) = (Id_Form)(objname));
(((* _sharp_pair_541).cdr) = ({
struct struct0x080674e0 *_sharp_pair_540;
({_sharp_pair_540;
(_sharp_pair_540 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_540).car) = (Id_Form)(fieldname));
(((* _sharp_pair_540).cdr) = ({
struct struct0x080674e0 *_sharp_pair_539;
({_sharp_pair_539;
(_sharp_pair_539 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_539).car) = expression);
(((* _sharp_pair_539).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_539);
})
);
((List__O__Form__C____type__type ) _sharp_pair_540);
})
);
((List__O__Form__C____type__type ) _sharp_pair_541);
})
);
((List__O__Form__C____type__type ) _sharp_pair_542);
})
);
((List__O__Form__C____type__type ) _sharp_pair_543);
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
struct struct0x080674e0 *_sharp_pair_545;
({_sharp_pair_545;
(_sharp_pair_545 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_545).car) = (Id_Form)(fsymb));
(((* _sharp_pair_545).cdr) = ({
struct struct0x080674e0 *_sharp_pair_544;
({_sharp_pair_544;
(_sharp_pair_544 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_544).car) = any);
(((* _sharp_pair_544).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_544);
})
);
((List__O__Form__C____type__type ) _sharp_pair_545);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__include(Symbol__type  fsymb)
{
return ({
String__type filename;
({(filename = (_l__parse__Lexical__String)());
(parse_symbol)(((String__type) &__string_53));
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
struct struct0x080674e0 *_sharp_pair_546;
({_sharp_pair_546;
(_sharp_pair_546 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_546).car) = type);
(((* _sharp_pair_546).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_546);
})
;});})):
(({((List__O__Form__C____type__type ) 0);})));
})
);
({(Compound_Form)(intern( "let"), ({
struct struct0x080674e0 *_sharp_pair_547;
({_sharp_pair_547;
(_sharp_pair_547 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_547).car) = id);
(((* _sharp_pair_547).cdr) = typel);
((List__O__Form__C____type__type ) _sharp_pair_547);
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
({(parse_symbol)(((String__type) &__string_54));
(cond = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_55));
(exp = (_l__parse__Code__Expression)());
(elsel = ({
((((((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 101))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 108))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 115))||(((Bool__type ) 0))))))&&(((((new_peek_char)(3) == 101))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_56));
(exp2 = (_l__parse__Code__Expression)());
({({
struct struct0x080674e0 *_sharp_pair_548;
({_sharp_pair_548;
(_sharp_pair_548 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_548).car) = exp2);
(((* _sharp_pair_548).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_548);
})
;});})):
(({((List__O__Form__C____type__type ) 0);})));
})
);
({(Compound_Form)(intern( "if"), ({
struct struct0x080674e0 *_sharp_pair_550;
({_sharp_pair_550;
(_sharp_pair_550 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_550).car) = cond);
(((* _sharp_pair_550).cdr) = ({
struct struct0x080674e0 *_sharp_pair_549;
({_sharp_pair_549;
(_sharp_pair_549 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_549).car) = exp);
(((* _sharp_pair_549).cdr) = elsel);
((List__O__Form__C____type__type ) _sharp_pair_549);
})
);
((List__O__Form__C____type__type ) _sharp_pair_550);
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
struct struct0x080674e0 *_sharp_pair_551;
({_sharp_pair_551;
(_sharp_pair_551 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_551).car) = exp);
(((* _sharp_pair_551).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_551);
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
(({(parse_symbol)(((String__type) &__string_57));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@seq"), ({
struct struct0x080674e0 *_sharp_pair_553;
({_sharp_pair_553;
(_sharp_pair_553 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_553).car) = (Compound_Form)(intern( "@set_continue"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_553).cdr) = ({
struct struct0x080674e0 *_sharp_pair_552;
({_sharp_pair_552;
(_sharp_pair_552 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_552).car) = exp);
(((* _sharp_pair_552).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_552);
})
);
((List__O__Form__C____type__type ) _sharp_pair_553);
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
Form__type body;
Form__type var;
Form__type collect;
({(parse_symbol)(((String__type) &__string_58));
(var = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_59));
(collect = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_60));
(body = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "foreach"), ({
struct struct0x080674e0 *_sharp_pair_556;
({_sharp_pair_556;
(_sharp_pair_556 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_556).car) = var);
(((* _sharp_pair_556).cdr) = ({
struct struct0x080674e0 *_sharp_pair_555;
({_sharp_pair_555;
(_sharp_pair_555 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_555).car) = collect);
(((* _sharp_pair_555).cdr) = ({
struct struct0x080674e0 *_sharp_pair_554;
({_sharp_pair_554;
(_sharp_pair_554 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_554).car) = body);
(((* _sharp_pair_554).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_554);
})
);
((List__O__Form__C____type__type ) _sharp_pair_555);
})
);
((List__O__Form__C____type__type ) _sharp_pair_556);
})
);});});
})
;}

Form__type  _l__parse__Macro__cast(Symbol__type  symb)
{
return ({
Form__type exp;
Form__type type;
({(parse_symbol)(((String__type) &__string_61));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_62));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_63));
({(Compound_Form)(intern( "cast"), ({
struct struct0x080674e0 *_sharp_pair_558;
({_sharp_pair_558;
(_sharp_pair_558 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_558).car) = type);
(((* _sharp_pair_558).cdr) = ({
struct struct0x080674e0 *_sharp_pair_557;
({_sharp_pair_557;
(_sharp_pair_557 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_557).car) = exp);
(((* _sharp_pair_557).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_557);
})
);
((List__O__Form__C____type__type ) _sharp_pair_558);
})
);});});
})
;}

Form__type  _l__parse__Macro__Form(Symbol__type  symb)
{
return ({
Form__type exp;
({(parse_symbol)(((String__type) &__string_64));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_65));
({(Compound_Form)(intern( "Form"), ({
struct struct0x080674e0 *_sharp_pair_559;
({_sharp_pair_559;
(_sharp_pair_559 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_559).car) = exp);
(((* _sharp_pair_559).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_559);
})
);});});
})
;}

Form__type  _l__parse__Macro__XML(Symbol__type  fsymb)
{
return ({
Form__type form;
({(parse_symbol)(((String__type) &__string_66));
(form = (_l__parse__XML_Parser__Content)());
(parse_symbol)(((String__type) &__string_67));
({(Compound_Form)(intern( "XML"), ({
struct struct0x080674e0 *_sharp_pair_560;
({_sharp_pair_560;
(_sharp_pair_560 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_560).car) = form);
(((* _sharp_pair_560).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_560);
})
);});});
})
;}

Form__type  _l__parse__Type__Base_Type(void)
{
return ({
void **_sharp_make_list_ptr569;
void **_sharp_make_list_ptr563;
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
(parse_symbol)(((String__type) &__string_68));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list562;
({_sharp_make_list562;
_sharp_make_list_ptr563;
(_sharp_make_list_ptr563 = ((void *) (&_sharp_make_list562)));
({({_sharp__sharp_loop564_begin566:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop564_end565;});}})
;
({(lab_type = (_l__parse__Type__Labeled_Type)());
(parse_symbol)(((String__type) &__string_69));
({({((* _sharp_make_list_ptr563) = (alloc_cons_cell)());
(((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr563))).car) = ((void *) lab_type));
(_sharp_make_list_ptr563 = (&((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr563))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop564_begin566;});});
_sharp__sharp_loop564_end565:;});
((* _sharp_make_list_ptr563) = ((void *) 0));
_sharp_make_list562;});
})
);
(parse_symbol)(((String__type) &__string_70));
({(Compound_Form)(intern( "struct"), form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_71));
(form_list2 = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list568;
({_sharp_make_list568;
_sharp_make_list_ptr569;
(_sharp_make_list_ptr569 = ((void *) (&_sharp_make_list568)));
({({_sharp__sharp_loop570_begin572:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop570_end571;});}})
;
({(parse_symbol)(((String__type) &__string_72));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr569) = (alloc_cons_cell)());
(((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr569))).car) = ((void *) arg));
(_sharp_make_list_ptr569 = (&((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr569))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop570_begin572;});});
_sharp__sharp_loop570_end571:;});
((* _sharp_make_list_ptr569) = ((void *) 0));
_sharp_make_list568;});
})
);
(arg_list = ({({
struct struct0x080674e0 *_sharp_pair_573;
({_sharp_pair_573;
(_sharp_pair_573 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_573).car) = arg1);
(((* _sharp_pair_573).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_573);
})
;}));});}})
;
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
void **_sharp_make_list_ptr576;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
List__O__Form__C____type__type form_list;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_73));
(form_list = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list575;
({_sharp_make_list575;
_sharp_make_list_ptr576;
(_sharp_make_list_ptr576 = ((void *) (&_sharp_make_list575)));
({({_sharp__sharp_loop577_begin579:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop577_end578;});}})
;
({(parse_symbol)(((String__type) &__string_74));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr576) = (alloc_cons_cell)());
(((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr576))).car) = ((void *) arg));
(_sharp_make_list_ptr576 = (&((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr576))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop577_begin579;});});
_sharp__sharp_loop577_end578:;});
((* _sharp_make_list_ptr576) = ((void *) 0));
_sharp_make_list575;});
})
);
(arg_list = ({({
struct struct0x080674e0 *_sharp_pair_580;
({_sharp_pair_580;
(_sharp_pair_580 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_580).car) = arg1);
(((* _sharp_pair_580).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_580);
})
;}));});}})
;
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_75));
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
({({_sharp__sharp_loop583_begin585:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop583_end584;});}})
;
({(parse_symbol)(((String__type) &__string_76));
(form = ({(Compound_Form)(intern( "*"), ({
struct struct0x080674e0 *_sharp_pair_582;
({_sharp_pair_582;
(_sharp_pair_582 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_582).car) = form);
(((* _sharp_pair_582).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_582);
})
);}));});
})
;
({goto _sharp__sharp_loop583_begin585;});});
_sharp__sharp_loop583_end584:;});
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
({if( ((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 62))||(((Bool__type ) 0))))))
{
({(id = (parse_symbol)(((String__type) &__string_77)));
(form2 = (_l__parse__Type__Function_Type)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_587;
({_sharp_pair_587;
(_sharp_pair_587 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_587).car) = form);
(((* _sharp_pair_587).cdr) = ({
struct struct0x080674e0 *_sharp_pair_586;
({_sharp_pair_586;
(_sharp_pair_586 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_586).car) = form2);
(((* _sharp_pair_586).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_586);
})
);
((List__O__Form__C____type__type ) _sharp_pair_587);
})
);}));});}})
;
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
({(read_char)();});
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( ":"), ({
struct struct0x080674e0 *_sharp_pair_589;
({_sharp_pair_589;
(_sharp_pair_589 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_589).car) = idf);
(((* _sharp_pair_589).cdr) = ({
struct struct0x080674e0 *_sharp_pair_588;
({_sharp_pair_588;
(_sharp_pair_588 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_588).car) = type);
(((* _sharp_pair_588).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_588);
})
);
((List__O__Form__C____type__type ) _sharp_pair_589);
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
Form__type seq;
List__O__Form__C____type__type form_list;
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
(({(parse_symbol)(((String__type) &__string_78));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_79));
({(Compound_Form)(id, form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_80));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@label"), ({
struct struct0x080674e0 *_sharp_pair_591;
({_sharp_pair_591;
(_sharp_pair_591 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_591).car) = (Id_Form)(id));
(((* _sharp_pair_591).cdr) = ({
struct struct0x080674e0 *_sharp_pair_590;
({_sharp_pair_590;
(_sharp_pair_590 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_590).car) = exp);
(((* _sharp_pair_590).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_590);
})
);
((List__O__Form__C____type__type ) _sharp_pair_591);
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
((parse_symbol)(((String__type) &__string_81))):
((parse_symbol)(((String__type) &__string_82))));
})
);
(__rep_exp = (_l__parse__Code__Sequence)());
(parse_symbol)(((String__type) &__string_83));
({(Compound_Form)(__rep_symb, ({
struct struct0x080674e0 *_sharp_pair_592;
({_sharp_pair_592;
(_sharp_pair_592 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_592).car) = __rep_exp);
(((* _sharp_pair_592).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_592);
})
);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_84));
(expl = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_85));
({(((((expl == ((List__O__Form__C____type__type ) 0)))||((((* ((struct struct0x0805f0d0 *) expl)).tail) != ((List__O__Form__C____type__type ) 0)))))?
((Compound_Form)(intern( "tuple"), expl)):
(((* ((struct struct0x0805f0d0 *) expl)).head)));});})):
(({(parse_symbol)(((String__type) &__string_86));
(seq = (_l__parse__Code__Maybe_Empty_Sequence)());
(parse_symbol)(((String__type) &__string_87));
({(Compound_Form)(intern( "@block"), ({
struct struct0x080674e0 *_sharp_pair_593;
({_sharp_pair_593;
(_sharp_pair_593 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_593).car) = seq);
(((* _sharp_pair_593).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_593);
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
({({_sharp__sharp_loop600_begin602:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((((new_peek_char)(0) == 46))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop600_end601;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_88));
(form2 = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_89));
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x080674e0 *_sharp_pair_596;
({_sharp_pair_596;
(_sharp_pair_596 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_596).car) = form);
(((* _sharp_pair_596).cdr) = ({
struct struct0x080674e0 *_sharp_pair_595;
({_sharp_pair_595;
(_sharp_pair_595 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_595).car) = form2);
(((* _sharp_pair_595).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_595);
})
);
((List__O__Form__C____type__type ) _sharp_pair_596);
})
);}));})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 46))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_90));
(id = (_l__parse__Lexical__Id)());
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x080674e0 *_sharp_pair_598;
({_sharp_pair_598;
(_sharp_pair_598 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_598).car) = form);
(((* _sharp_pair_598).cdr) = ({
struct struct0x080674e0 *_sharp_pair_597;
({_sharp_pair_597;
(_sharp_pair_597 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_597).car) = (Symbol_Form)(id));
(((* _sharp_pair_597).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_597);
})
);
((List__O__Form__C____type__type ) _sharp_pair_598);
})
);}));})):
(({(parse_symbol)(((String__type) &__string_91));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_92));
(form = ({(Compound_Form)(intern( "@funcall"), ({
struct struct0x080674e0 *_sharp_pair_599;
({_sharp_pair_599;
(_sharp_pair_599 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_599).car) = form);
(((* _sharp_pair_599).cdr) = form_list);
((List__O__Form__C____type__type ) _sharp_pair_599);
})
);}));})));
})
));
})
;
})
;
({goto _sharp__sharp_loop600_begin602;});});
_sharp__sharp_loop600_end601:;});
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
(({(parse_symbol)(((String__type) &__string_93));
({intern( "@unary_minus");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_94));
({intern( "@get_label");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_95));
({intern( "@ref");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_96));
({intern( "@deref");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 45))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_97));
({intern( "@pre_--");});})):
(({(parse_symbol)(((String__type) &__string_98));
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
struct struct0x080674e0 *_sharp_pair_603;
({_sharp_pair_603;
(_sharp_pair_603 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_603).car) = form);
(((* _sharp_pair_603).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_603);
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
({({_sharp__sharp_loop607_begin609:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop607_end608;});}})
;
({(id = (parse_symbol)(((String__type) &__string_99)));
(form2 = (_l__parse__Code__Unary_Operator)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_606;
({_sharp_pair_606;
(_sharp_pair_606 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_606).car) = form);
(((* _sharp_pair_606).cdr) = ({
struct struct0x080674e0 *_sharp_pair_605;
({_sharp_pair_605;
(_sharp_pair_605 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_605).car) = form2);
(((* _sharp_pair_605).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_605);
})
);
((List__O__Form__C____type__type ) _sharp_pair_606);
})
);}));});
})
;
({goto _sharp__sharp_loop607_begin609;});});
_sharp__sharp_loop607_end608:;});
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
({({_sharp__sharp_loop613_begin615:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop613_end614;});}})
;
({(id = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_100))):
((parse_symbol)(((String__type) &__string_101))));
})
);
(form2 = (_l__parse__Code__Multiplicative)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_612;
({_sharp_pair_612;
(_sharp_pair_612 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_612).car) = form);
(((* _sharp_pair_612).cdr) = ({
struct struct0x080674e0 *_sharp_pair_611;
({_sharp_pair_611;
(_sharp_pair_611 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_611).car) = form2);
(((* _sharp_pair_611).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_611);
})
);
((List__O__Form__C____type__type ) _sharp_pair_612);
})
);}));});
})
;
({goto _sharp__sharp_loop613_begin615;});});
_sharp__sharp_loop613_end614:;});
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
({({_sharp__sharp_loop619_begin621:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 62))||(((((new_peek_char)(1) == 60))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop619_end620;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_102))):
((parse_symbol)(((String__type) &__string_103))));
})
);
(form2 = (_l__parse__Code__Additive)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_618;
({_sharp_pair_618;
(_sharp_pair_618 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_618).car) = form);
(((* _sharp_pair_618).cdr) = ({
struct struct0x080674e0 *_sharp_pair_617;
({_sharp_pair_617;
(_sharp_pair_617 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_617).car) = form2);
(((* _sharp_pair_617).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_617);
})
);
((List__O__Form__C____type__type ) _sharp_pair_618);
})
);}));});
})
;
({goto _sharp__sharp_loop619_begin621;});});
_sharp__sharp_loop619_end620:;});
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
({({_sharp__sharp_loop625_begin627:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop625_end626;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_104))):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_105))):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_106))):
((parse_symbol)(((String__type) &__string_107))));
})
));
})
));
})
);
(form2 = (_l__parse__Code__Shift)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_624;
({_sharp_pair_624;
(_sharp_pair_624 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_624).car) = form);
(((* _sharp_pair_624).cdr) = ({
struct struct0x080674e0 *_sharp_pair_623;
({_sharp_pair_623;
(_sharp_pair_623 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_623).car) = form2);
(((* _sharp_pair_623).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_623);
})
);
((List__O__Form__C____type__type ) _sharp_pair_624);
})
);}));});
})
;
({goto _sharp__sharp_loop625_begin627;});});
_sharp__sharp_loop625_end626:;});
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
({({_sharp__sharp_loop631_begin633:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((((new_peek_char)(0) == 33))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 61))||(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop631_end632;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_108))):
((parse_symbol)(((String__type) &__string_109))));
})
);
(form2 = (_l__parse__Code__Relational)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_630;
({_sharp_pair_630;
(_sharp_pair_630 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_630).car) = form);
(((* _sharp_pair_630).cdr) = ({
struct struct0x080674e0 *_sharp_pair_629;
({_sharp_pair_629;
(_sharp_pair_629 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_629).car) = form2);
(((* _sharp_pair_629).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_629);
})
);
((List__O__Form__C____type__type ) _sharp_pair_630);
})
);}));});
})
;
({goto _sharp__sharp_loop631_begin633;});});
_sharp__sharp_loop631_end632:;});
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
({({_sharp__sharp_loop637_begin639:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop637_end638;});}})
;
({(id = (parse_symbol)(((String__type) &__string_110)));
(form2 = (_l__parse__Code__Equality)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_636;
({_sharp_pair_636;
(_sharp_pair_636 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_636).car) = form);
(((* _sharp_pair_636).cdr) = ({
struct struct0x080674e0 *_sharp_pair_635;
({_sharp_pair_635;
(_sharp_pair_635 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_635).car) = form2);
(((* _sharp_pair_635).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_635);
})
);
((List__O__Form__C____type__type ) _sharp_pair_636);
})
);}));});
})
;
({goto _sharp__sharp_loop637_begin639;});});
_sharp__sharp_loop637_end638:;});
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
({({_sharp__sharp_loop643_begin645:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 94))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop643_end644;});}})
;
({(id = (parse_symbol)(((String__type) &__string_111)));
(form2 = (_l__parse__Code__Bitwise_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_642;
({_sharp_pair_642;
(_sharp_pair_642 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_642).car) = form);
(((* _sharp_pair_642).cdr) = ({
struct struct0x080674e0 *_sharp_pair_641;
({_sharp_pair_641;
(_sharp_pair_641 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_641).car) = form2);
(((* _sharp_pair_641).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_641);
})
);
((List__O__Form__C____type__type ) _sharp_pair_642);
})
);}));});
})
;
({goto _sharp__sharp_loop643_begin645;});});
_sharp__sharp_loop643_end644:;});
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
({({_sharp__sharp_loop649_begin651:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop649_end650;});}})
;
({(id = (parse_symbol)(((String__type) &__string_112)));
(form2 = (_l__parse__Code__Bitwise_Xor)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_648;
({_sharp_pair_648;
(_sharp_pair_648 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_648).car) = form);
(((* _sharp_pair_648).cdr) = ({
struct struct0x080674e0 *_sharp_pair_647;
({_sharp_pair_647;
(_sharp_pair_647 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_647).car) = form2);
(((* _sharp_pair_647).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_647);
})
);
((List__O__Form__C____type__type ) _sharp_pair_648);
})
);}));});
})
;
({goto _sharp__sharp_loop649_begin651;});});
_sharp__sharp_loop649_end650:;});
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
({({_sharp__sharp_loop655_begin657:;
({
({if( (!(((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 97))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 110))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 100))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop655_end656;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_113));
({intern( "@and");});}));
(form2 = (_l__parse__Code__Bitwise_Ior)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_654;
({_sharp_pair_654;
(_sharp_pair_654 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_654).car) = form);
(((* _sharp_pair_654).cdr) = ({
struct struct0x080674e0 *_sharp_pair_653;
({_sharp_pair_653;
(_sharp_pair_653 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_653).car) = form2);
(((* _sharp_pair_653).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_653);
})
);
((List__O__Form__C____type__type ) _sharp_pair_654);
})
);}));});
})
;
({goto _sharp__sharp_loop655_begin657;});});
_sharp__sharp_loop655_end656:;});
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
({({_sharp__sharp_loop661_begin663:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 111))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 114))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop661_end662;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_114));
({intern( "@or");});}));
(form2 = (_l__parse__Code__Logical_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_660;
({_sharp_pair_660;
(_sharp_pair_660 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_660).car) = form);
(((* _sharp_pair_660).cdr) = ({
struct struct0x080674e0 *_sharp_pair_659;
({_sharp_pair_659;
(_sharp_pair_659 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_659).car) = form2);
(((* _sharp_pair_659).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_659);
})
);
((List__O__Form__C____type__type ) _sharp_pair_660);
})
);}));});
})
;
({goto _sharp__sharp_loop661_begin663;});});
_sharp__sharp_loop661_end662:;});
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
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((Bool__type ) 0))))))
{
({(id = (parse_symbol)(((String__type) &__string_115)));
(form2 = (_l__parse__Code__Assignment)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674e0 *_sharp_pair_665;
({_sharp_pair_665;
(_sharp_pair_665 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_665).car) = form);
(((* _sharp_pair_665).cdr) = ({
struct struct0x080674e0 *_sharp_pair_664;
({_sharp_pair_664;
(_sharp_pair_664 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_664).car) = form2);
(((* _sharp_pair_664).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_664);
})
);
((List__O__Form__C____type__type ) _sharp_pair_665);
})
);}));});}})
;
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
void **_sharp_make_list_ptr667;
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
List__O__Form__C____type__type _sharp_make_list666;
({_sharp_make_list666;
_sharp_make_list_ptr667;
(_sharp_make_list_ptr667 = ((void *) (&_sharp_make_list666)));
({({_sharp__sharp_loop668_begin670:;
({
({(parse_symbol)(((String__type) &__string_116));
(exp2 = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))?
((_l__parse__Code__Expression)()):
(({tup;})));
})
);
({({((* _sharp_make_list_ptr667) = (alloc_cons_cell)());
(((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr667))).car) = ((void *) exp2));
(_sharp_make_list_ptr667 = (&((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr667))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop668_end669;});}})
;
})
;
({goto _sharp__sharp_loop668_begin670;});});
_sharp__sharp_loop668_end669:;});
((* _sharp_make_list_ptr667) = ((void *) 0));
_sharp_make_list666;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x080674e0 *_sharp_pair_671;
({_sharp_pair_671;
(_sharp_pair_671 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_671).car) = exp);
(((* _sharp_pair_671).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_671);
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
void **_sharp_make_list_ptr673;
Form__type exp2;
List__O__Form__C____type__type exp_list;
Form__type exp;
({(exp = (_l__parse__Code__Expression)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))?
(({(exp_list = ({
List__O__Form__C____type__type _sharp_make_list672;
({_sharp_make_list672;
_sharp_make_list_ptr673;
(_sharp_make_list_ptr673 = ((void *) (&_sharp_make_list672)));
({({_sharp__sharp_loop674_begin676:;
({
({(parse_symbol)(((String__type) &__string_117));
(exp2 = (_l__parse__Code__Expression)());
({({((* _sharp_make_list_ptr673) = (alloc_cons_cell)());
(((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr673))).car) = ((void *) exp2));
(_sharp_make_list_ptr673 = (&((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr673))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop674_end675;});}})
;
})
;
({goto _sharp__sharp_loop674_begin676;});});
_sharp__sharp_loop674_end675:;});
((* _sharp_make_list_ptr673) = ((void *) 0));
_sharp_make_list672;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x080674e0 *_sharp_pair_677;
({_sharp_pair_677;
(_sharp_pair_677 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_677).car) = exp);
(((* _sharp_pair_677).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_677);
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
void **_sharp_make_list_ptr680;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))
{
({(arg1 = (_l__parse__Code__Non_Empty_Sequence)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list679;
({_sharp_make_list679;
_sharp_make_list_ptr680;
(_sharp_make_list_ptr680 = ((void *) (&_sharp_make_list679)));
({({_sharp__sharp_loop681_begin683:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop681_end682;});}})
;
({(parse_symbol)(((String__type) &__string_118));
(arg = (_l__parse__Code__Non_Empty_Sequence)());
({({((* _sharp_make_list_ptr680) = (alloc_cons_cell)());
(((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr680))).car) = ((void *) arg));
(_sharp_make_list_ptr680 = (&((* (* ((struct struct0x08643b88 **) _sharp_make_list_ptr680))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop681_begin683;});});
_sharp__sharp_loop681_end682:;});
((* _sharp_make_list_ptr680) = ((void *) 0));
_sharp_make_list679;});
})
);
(arg_list = ({({
struct struct0x080674e0 *_sharp_pair_684;
({_sharp_pair_684;
(_sharp_pair_684 = ((struct struct0x080674e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_684).car) = arg1);
(((* _sharp_pair_684).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_684);
})
;}));});}})
;
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
({({_sharp__sharp_loop686_begin688:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop686_end687;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop686_begin688;});});
_sharp__sharp_loop686_end687:;});
({(read_char)();});});
})
;}

void  _l__parse__Lexical__Spacing(void)
{
return ({
({({_sharp__sharp_loop690_begin692:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop690_end691;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__Lexical__Comment)()));
})
;
})
;
({goto _sharp__sharp_loop690_begin692;});});
_sharp__sharp_loop690_end691:;});
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
({({_sharp__sharp_loop694_begin696:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop694_end695;});}})
;
({(d = (_l__parse__Lexical__Digit)());
({({
({(n = ((int) n * (int) 10));
(n = ((int) n + (int) d));});
})
;});});
})
;
({goto _sharp__sharp_loop694_begin696;});});
_sharp__sharp_loop694_end695:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Hexadecimal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop698_begin700:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 102))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop698_end699;});}})
;
({(d = (_l__parse__Lexical__Hexa_Digit)());
({({
({(n = ((int) n * (int) 16));
(n = ((int) n + (int) d));});
})
;});});
})
;
({goto _sharp__sharp_loop698_begin700;});});
_sharp__sharp_loop698_end699:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Octal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop702_begin704:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 55))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop702_end703;});}})
;
({(d = (_l__parse__Lexical__Octal_Digit)());
({({
({(n = ((int) n * (int) 8));
(n = ((int) n + (int) d));});
})
;});});
})
;
({goto _sharp__sharp_loop702_begin704;});});
_sharp__sharp_loop702_end703:;});
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
({({_sharp__sharp_loop706_begin708:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop706_end707;});}})
;
(_l__parse__Lexical__Alpha_Num)();
})
;
({goto _sharp__sharp_loop706_begin708;});});
_sharp__sharp_loop706_end707:;});
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
({({_sharp__sharp_loop710_begin712:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop710_end711;});}})
;
({({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))?
((read_char)()):
(({(read_char)();
(read_char)();})));
})
;
(i = ({((int) i + (int) 1);}));});
})
;
({goto _sharp__sharp_loop710_begin712;});});
_sharp__sharp_loop710_end711:;});
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
({({_sharp__sharp_loop714_begin719:;
({
({(read_char)();
({({_sharp__sharp_loop716_begin718:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 35))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 33))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop716_end717;});}})
;
({({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 35))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 33))))||(((Bool__type ) 0))))))))))?
((read_char)()):
(({(read_char)();
(read_char)();})));
})
;
(i = ({((int) i + (int) 1);}));});
})
;
({goto _sharp__sharp_loop716_begin718;});});
_sharp__sharp_loop716_end717:;});
(end = (get_point_pos)());
(read_char)();
(_l__parse__Lexical__Spacing)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop714_end715;});}})
;
})
;
({goto _sharp__sharp_loop714_begin719;});});
_sharp__sharp_loop714_end715:;});
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
