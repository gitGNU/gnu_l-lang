/* Automatically generated : do not edit!*/
#include "parse-l.inc"
Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type__type parse_top_level_hash;

Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type__type parse_macro_hash;

void  init__parse_l(void)
{
return ({
(parse_macro_hash = ((Hash__O__Symbol__c__pointer__O__function__O__Symbol__c__Form__C____C____C____type__type ) (make_hash_table)()));
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
((void) 0);
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
struct struct0x08067088 *_sharp_pair_471;
({_sharp_pair_471;
(_sharp_pair_471 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
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
struct struct0x08067088 *_sharp_pair_472;
({_sharp_pair_472;
(_sharp_pair_472 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
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
struct struct0x08067088 *_sharp_pair_473;
({_sharp_pair_473;
(_sharp_pair_473 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
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

List__O__Form__C____type__type  _l__parse__Top_Level__All(void)
{
return ({
void **_sharp_make_list_ptr476;
Form__type form;
List__O__Form__C____type__type list;
({(list = ({
List__O__Form__C____type__type _sharp_make_list475;
({_sharp_make_list475;
_sharp_make_list_ptr476;
(_sharp_make_list_ptr476 = ((void *) (&_sharp_make_list475)));
({({_sharp__sharp_loop477_begin479:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop477_end478;});}})
;
({(form = (_l__parse__Top_Level__Top)());
({({((* _sharp_make_list_ptr476) = (alloc_cons_cell)());
(((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr476))).car) = ((void *) form));
(_sharp_make_list_ptr476 = (&((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr476))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop477_begin479;});});
_sharp__sharp_loop477_end478:;});
((* _sharp_make_list_ptr476) = ((void *) 0));
_sharp_make_list475;});
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
({(print_String)(((String__type) &__string_15));
(print_String)(((String__type) &__string_16));
(print_Symbol)(id);
(print_String)(((String__type) &__string_17));
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
void **_sharp_make_list_ptr482;
Form__type ret_type;
List__O__Form__C____type__type params;
Form__type body;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
Symbol__type name;
({(name = (_l__parse__Lexical__Id)());
(parse_symbol)(((String__type) &__string_18));
(params = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))
{
({(arg1 = (_l__parse__Type__Labeled_Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list481;
({_sharp_make_list481;
_sharp_make_list_ptr482;
(_sharp_make_list_ptr482 = ((void *) (&_sharp_make_list481)));
({({_sharp__sharp_loop483_begin485:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop483_end484;});}})
;
({(parse_symbol)(((String__type) &__string_19));
(arg = (_l__parse__Type__Labeled_Type)());
({({((* _sharp_make_list_ptr482) = (alloc_cons_cell)());
(((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr482))).car) = ((void *) arg));
(_sharp_make_list_ptr482 = (&((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr482))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop483_begin485;});});
_sharp__sharp_loop483_end484:;});
((* _sharp_make_list_ptr482) = ((void *) 0));
_sharp_make_list481;});
})
);
(arg_list = ({({
struct struct0x08067088 *_sharp_pair_486;
({_sharp_pair_486;
(_sharp_pair_486 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_486).car) = arg1);
(((* _sharp_pair_486).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_486);
})
;}));});}})
;
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_20));
(parse_symbol)(((String__type) &__string_21));
(ret_type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_22));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_23));
({(Compound_Form)(intern( "define"), ({
struct struct0x08067088 *_sharp_pair_492;
({_sharp_pair_492;
(_sharp_pair_492 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_492).car) = (Id_Form)(fsymb));
(((* _sharp_pair_492).cdr) = ({
struct struct0x08067088 *_sharp_pair_491;
({_sharp_pair_491;
(_sharp_pair_491 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_491).car) = (Id_Form)(name));
(((* _sharp_pair_491).cdr) = ({
struct struct0x08067088 *_sharp_pair_490;
({_sharp_pair_490;
(_sharp_pair_490 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_490).car) = (Compound_Form)(intern( "lambda"), ({
struct struct0x08067088 *_sharp_pair_489;
({_sharp_pair_489;
(_sharp_pair_489 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_489).car) = ret_type);
(((* _sharp_pair_489).cdr) = ({
struct struct0x08067088 *_sharp_pair_488;
({_sharp_pair_488;
(_sharp_pair_488 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_488).car) = (Compound_Form)(intern( "tuple"), params));
(((* _sharp_pair_488).cdr) = ({
struct struct0x08067088 *_sharp_pair_487;
({_sharp_pair_487;
(_sharp_pair_487 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_487).car) = body);
(((* _sharp_pair_487).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_487);
})
);
((List__O__Form__C____type__type ) _sharp_pair_488);
})
);
((List__O__Form__C____type__type ) _sharp_pair_489);
})
));
(((* _sharp_pair_490).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_490);
})
);
((List__O__Form__C____type__type ) _sharp_pair_491);
})
);
((List__O__Form__C____type__type ) _sharp_pair_492);
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
(parse_symbol)(((String__type) &__string_24));
({(Compound_Form)(intern( "define"), ({
struct struct0x08067088 *_sharp_pair_495;
({_sharp_pair_495;
(_sharp_pair_495 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_495).car) = (Id_Form)(fsymb));
(((* _sharp_pair_495).cdr) = ({
struct struct0x08067088 *_sharp_pair_494;
({_sharp_pair_494;
(_sharp_pair_494 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_494).car) = (Id_Form)(name));
(((* _sharp_pair_494).cdr) = ({
struct struct0x08067088 *_sharp_pair_493;
({_sharp_pair_493;
(_sharp_pair_493 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_493).car) = type);
(((* _sharp_pair_493).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_493);
})
);
((List__O__Form__C____type__type ) _sharp_pair_494);
})
);
((List__O__Form__C____type__type ) _sharp_pair_495);
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
(parse_symbol)(((String__type) &__string_25));
(param = (_l__parse__Lexical__Id_Form)());
(parse_symbol)(((String__type) &__string_26));
(parse_symbol)(((String__type) &__string_27));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_28));
({(Compound_Form)(intern( "define"), ({
struct struct0x08067088 *_sharp_pair_500;
({_sharp_pair_500;
(_sharp_pair_500 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_500).car) = (Id_Form)(fsymb));
(((* _sharp_pair_500).cdr) = ({
struct struct0x08067088 *_sharp_pair_499;
({_sharp_pair_499;
(_sharp_pair_499 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_499).car) = name);
(((* _sharp_pair_499).cdr) = ({
struct struct0x08067088 *_sharp_pair_498;
({_sharp_pair_498;
(_sharp_pair_498 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_498).car) = (Compound_Form)(intern( ":"), ({
struct struct0x08067088 *_sharp_pair_497;
({_sharp_pair_497;
(_sharp_pair_497 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_497).car) = param);
(((* _sharp_pair_497).cdr) = ({
struct struct0x08067088 *_sharp_pair_496;
({_sharp_pair_496;
(_sharp_pair_496 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_496).car) = body);
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
);
((List__O__Form__C____type__type ) _sharp_pair_500);
})
);});});
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
struct struct0x08067088 *_sharp_pair_501;
({_sharp_pair_501;
(_sharp_pair_501 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_501).car) = type);
(((* _sharp_pair_501).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_501);
})
;});})):
(({((List__O__Form__C____type__type ) 0);})));
})
);
({(Compound_Form)(intern( "let"), ({
struct struct0x08067088 *_sharp_pair_502;
({_sharp_pair_502;
(_sharp_pair_502 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_502).car) = id);
(((* _sharp_pair_502).cdr) = typel);
((List__O__Form__C____type__type ) _sharp_pair_502);
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
({(parse_symbol)(((String__type) &__string_29));
(cond = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_30));
(exp = (_l__parse__Code__Expression)());
(elsel = ({
((((((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 101))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 108))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 115))||(((Bool__type ) 0))))))&&(((((new_peek_char)(3) == 101))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_31));
(exp2 = (_l__parse__Code__Expression)());
({({
struct struct0x08067088 *_sharp_pair_503;
({_sharp_pair_503;
(_sharp_pair_503 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_503).car) = exp2);
(((* _sharp_pair_503).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_503);
})
;});})):
(({((List__O__Form__C____type__type ) 0);})));
})
);
({(Compound_Form)(intern( "if"), ({
struct struct0x08067088 *_sharp_pair_505;
({_sharp_pair_505;
(_sharp_pair_505 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_505).car) = cond);
(((* _sharp_pair_505).cdr) = ({
struct struct0x08067088 *_sharp_pair_504;
({_sharp_pair_504;
(_sharp_pair_504 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_504).car) = exp);
(((* _sharp_pair_504).cdr) = elsel);
((List__O__Form__C____type__type ) _sharp_pair_504);
})
);
((List__O__Form__C____type__type ) _sharp_pair_505);
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
struct struct0x08067088 *_sharp_pair_506;
({_sharp_pair_506;
(_sharp_pair_506 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_506).car) = exp);
(((* _sharp_pair_506).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_506);
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
(({(parse_symbol)(((String__type) &__string_32));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@seq"), ({
struct struct0x08067088 *_sharp_pair_508;
({_sharp_pair_508;
(_sharp_pair_508 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_508).car) = (Compound_Form)(intern( "@set_continue"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_508).cdr) = ({
struct struct0x08067088 *_sharp_pair_507;
({_sharp_pair_507;
(_sharp_pair_507 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_507).car) = exp);
(((* _sharp_pair_507).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_507);
})
);
((List__O__Form__C____type__type ) _sharp_pair_508);
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
({(parse_symbol)(((String__type) &__string_33));
(var = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_34));
(collect = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_35));
(body = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "foreach"), ({
struct struct0x08067088 *_sharp_pair_511;
({_sharp_pair_511;
(_sharp_pair_511 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_511).car) = var);
(((* _sharp_pair_511).cdr) = ({
struct struct0x08067088 *_sharp_pair_510;
({_sharp_pair_510;
(_sharp_pair_510 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_510).car) = collect);
(((* _sharp_pair_510).cdr) = ({
struct struct0x08067088 *_sharp_pair_509;
({_sharp_pair_509;
(_sharp_pair_509 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_509).car) = body);
(((* _sharp_pair_509).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_509);
})
);
((List__O__Form__C____type__type ) _sharp_pair_510);
})
);
((List__O__Form__C____type__type ) _sharp_pair_511);
})
);});});
})
;}

Form__type  _l__parse__Macro__cast(Symbol__type  symb)
{
return ({
Form__type exp;
Form__type type;
({(parse_symbol)(((String__type) &__string_36));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_37));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_38));
({(Compound_Form)(intern( "cast"), ({
struct struct0x08067088 *_sharp_pair_513;
({_sharp_pair_513;
(_sharp_pair_513 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_513).car) = type);
(((* _sharp_pair_513).cdr) = ({
struct struct0x08067088 *_sharp_pair_512;
({_sharp_pair_512;
(_sharp_pair_512 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_512).car) = exp);
(((* _sharp_pair_512).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_512);
})
);
((List__O__Form__C____type__type ) _sharp_pair_513);
})
);});});
})
;}

Form__type  _l__parse__Macro__Form(Symbol__type  symb)
{
return ({
Form__type exp;
({(parse_symbol)(((String__type) &__string_39));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_40));
({(Compound_Form)(intern( "Form"), ({
struct struct0x08067088 *_sharp_pair_514;
({_sharp_pair_514;
(_sharp_pair_514 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_514).car) = exp);
(((* _sharp_pair_514).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_514);
})
);});});
})
;}

Form__type  _l__parse__Macro__XML(Symbol__type  fsymb)
{
return ({
Form__type form;
({(parse_symbol)(((String__type) &__string_41));
(form = (_l__parse__XML_Parser__Content)());
(parse_symbol)(((String__type) &__string_42));
({(Compound_Form)(intern( "XML"), ({
struct struct0x08067088 *_sharp_pair_515;
({_sharp_pair_515;
(_sharp_pair_515 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_515).car) = form);
(((* _sharp_pair_515).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_515);
})
);});});
})
;}

Form__type  _l__parse__Type__Base_Type(void)
{
return ({
void **_sharp_make_list_ptr524;
void **_sharp_make_list_ptr518;
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
(parse_symbol)(((String__type) &__string_43));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list517;
({_sharp_make_list517;
_sharp_make_list_ptr518;
(_sharp_make_list_ptr518 = ((void *) (&_sharp_make_list517)));
({({_sharp__sharp_loop519_begin521:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop519_end520;});}})
;
({(lab_type = (_l__parse__Type__Labeled_Type)());
(parse_symbol)(((String__type) &__string_44));
({({((* _sharp_make_list_ptr518) = (alloc_cons_cell)());
(((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr518))).car) = ((void *) lab_type));
(_sharp_make_list_ptr518 = (&((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr518))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop519_begin521;});});
_sharp__sharp_loop519_end520:;});
((* _sharp_make_list_ptr518) = ((void *) 0));
_sharp_make_list517;});
})
);
(parse_symbol)(((String__type) &__string_45));
({(Compound_Form)(intern( "struct"), form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_46));
(form_list2 = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list523;
({_sharp_make_list523;
_sharp_make_list_ptr524;
(_sharp_make_list_ptr524 = ((void *) (&_sharp_make_list523)));
({({_sharp__sharp_loop525_begin527:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop525_end526;});}})
;
({(parse_symbol)(((String__type) &__string_47));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr524) = (alloc_cons_cell)());
(((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr524))).car) = ((void *) arg));
(_sharp_make_list_ptr524 = (&((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr524))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop525_begin527;});});
_sharp__sharp_loop525_end526:;});
((* _sharp_make_list_ptr524) = ((void *) 0));
_sharp_make_list523;});
})
);
(arg_list = ({({
struct struct0x08067088 *_sharp_pair_528;
({_sharp_pair_528;
(_sharp_pair_528 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_528).car) = arg1);
(((* _sharp_pair_528).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_528);
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
void **_sharp_make_list_ptr531;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
List__O__Form__C____type__type form_list;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_48));
(form_list = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list530;
({_sharp_make_list530;
_sharp_make_list_ptr531;
(_sharp_make_list_ptr531 = ((void *) (&_sharp_make_list530)));
({({_sharp__sharp_loop532_begin534:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop532_end533;});}})
;
({(parse_symbol)(((String__type) &__string_49));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr531) = (alloc_cons_cell)());
(((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr531))).car) = ((void *) arg));
(_sharp_make_list_ptr531 = (&((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr531))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop532_begin534;});});
_sharp__sharp_loop532_end533:;});
((* _sharp_make_list_ptr531) = ((void *) 0));
_sharp_make_list530;});
})
);
(arg_list = ({({
struct struct0x08067088 *_sharp_pair_535;
({_sharp_pair_535;
(_sharp_pair_535 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_535).car) = arg1);
(((* _sharp_pair_535).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_535);
})
;}));});}})
;
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_50));
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
({({_sharp__sharp_loop538_begin540:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop538_end539;});}})
;
({(parse_symbol)(((String__type) &__string_51));
(form = ({(Compound_Form)(intern( "*"), ({
struct struct0x08067088 *_sharp_pair_537;
({_sharp_pair_537;
(_sharp_pair_537 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_537).car) = form);
(((* _sharp_pair_537).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_537);
})
);}));});
})
;
({goto _sharp__sharp_loop538_begin540;});});
_sharp__sharp_loop538_end539:;});
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
({(id = (parse_symbol)(((String__type) &__string_52)));
(form2 = (_l__parse__Type__Function_Type)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_542;
({_sharp_pair_542;
(_sharp_pair_542 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_542).car) = form);
(((* _sharp_pair_542).cdr) = ({
struct struct0x08067088 *_sharp_pair_541;
({_sharp_pair_541;
(_sharp_pair_541 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_541).car) = form2);
(((* _sharp_pair_541).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_541);
})
);
((List__O__Form__C____type__type ) _sharp_pair_542);
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
struct struct0x08067088 *_sharp_pair_544;
({_sharp_pair_544;
(_sharp_pair_544 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_544).car) = idf);
(((* _sharp_pair_544).cdr) = ({
struct struct0x08067088 *_sharp_pair_543;
({_sharp_pair_543;
(_sharp_pair_543 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_543).car) = type);
(((* _sharp_pair_543).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_543);
})
);
((List__O__Form__C____type__type ) _sharp_pair_544);
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
(({(parse_symbol)(((String__type) &__string_53));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_54));
({(Compound_Form)(id, form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_55));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@label"), ({
struct struct0x08067088 *_sharp_pair_546;
({_sharp_pair_546;
(_sharp_pair_546 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_546).car) = (Id_Form)(id));
(((* _sharp_pair_546).cdr) = ({
struct struct0x08067088 *_sharp_pair_545;
({_sharp_pair_545;
(_sharp_pair_545 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_545).car) = exp);
(((* _sharp_pair_545).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_545);
})
);
((List__O__Form__C____type__type ) _sharp_pair_546);
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
((parse_symbol)(((String__type) &__string_56))):
((parse_symbol)(((String__type) &__string_57))));
})
);
(__rep_exp = (_l__parse__Code__Sequence)());
(parse_symbol)(((String__type) &__string_58));
({(Compound_Form)(__rep_symb, ({
struct struct0x08067088 *_sharp_pair_547;
({_sharp_pair_547;
(_sharp_pair_547 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_547).car) = __rep_exp);
(((* _sharp_pair_547).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_547);
})
);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_59));
(expl = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_60));
({(((((expl == ((List__O__Form__C____type__type ) 0)))||((((* ((struct struct0x0805efe8 *) expl)).tail) != ((List__O__Form__C____type__type ) 0)))))?
((Compound_Form)(intern( "tuple"), expl)):
(((* ((struct struct0x0805efe8 *) expl)).head)));});})):
(({(parse_symbol)(((String__type) &__string_61));
(seq = (_l__parse__Code__Maybe_Empty_Sequence)());
(parse_symbol)(((String__type) &__string_62));
({(Compound_Form)(intern( "@block"), ({
struct struct0x08067088 *_sharp_pair_548;
({_sharp_pair_548;
(_sharp_pair_548 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_548).car) = seq);
(((* _sharp_pair_548).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_548);
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
({({_sharp__sharp_loop555_begin557:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((((new_peek_char)(0) == 46))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop555_end556;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_63));
(form2 = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_64));
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x08067088 *_sharp_pair_551;
({_sharp_pair_551;
(_sharp_pair_551 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_551).car) = form);
(((* _sharp_pair_551).cdr) = ({
struct struct0x08067088 *_sharp_pair_550;
({_sharp_pair_550;
(_sharp_pair_550 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_550).car) = form2);
(((* _sharp_pair_550).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_550);
})
);
((List__O__Form__C____type__type ) _sharp_pair_551);
})
);}));})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 46))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_65));
(id = (_l__parse__Lexical__Id)());
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x08067088 *_sharp_pair_553;
({_sharp_pair_553;
(_sharp_pair_553 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_553).car) = form);
(((* _sharp_pair_553).cdr) = ({
struct struct0x08067088 *_sharp_pair_552;
({_sharp_pair_552;
(_sharp_pair_552 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_552).car) = (Symbol_Form)(id));
(((* _sharp_pair_552).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_552);
})
);
((List__O__Form__C____type__type ) _sharp_pair_553);
})
);}));})):
(({(parse_symbol)(((String__type) &__string_66));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_67));
(form = ({(Compound_Form)(intern( "@funcall"), ({
struct struct0x08067088 *_sharp_pair_554;
({_sharp_pair_554;
(_sharp_pair_554 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_554).car) = form);
(((* _sharp_pair_554).cdr) = form_list);
((List__O__Form__C____type__type ) _sharp_pair_554);
})
);}));})));
})
));
})
;
})
;
({goto _sharp__sharp_loop555_begin557;});});
_sharp__sharp_loop555_end556:;});
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
(({(parse_symbol)(((String__type) &__string_68));
({intern( "@unary_minus");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_69));
({intern( "@get_label");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_70));
({intern( "@ref");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_71));
({intern( "@deref");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 45))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_72));
({intern( "@pre_--");});})):
(({(parse_symbol)(((String__type) &__string_73));
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
struct struct0x08067088 *_sharp_pair_558;
({_sharp_pair_558;
(_sharp_pair_558 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_558).car) = form);
(((* _sharp_pair_558).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_558);
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
({({_sharp__sharp_loop562_begin564:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop562_end563;});}})
;
({(id = (parse_symbol)(((String__type) &__string_74)));
(form2 = (_l__parse__Code__Unary_Operator)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_561;
({_sharp_pair_561;
(_sharp_pair_561 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_561).car) = form);
(((* _sharp_pair_561).cdr) = ({
struct struct0x08067088 *_sharp_pair_560;
({_sharp_pair_560;
(_sharp_pair_560 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_560).car) = form2);
(((* _sharp_pair_560).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_560);
})
);
((List__O__Form__C____type__type ) _sharp_pair_561);
})
);}));});
})
;
({goto _sharp__sharp_loop562_begin564;});});
_sharp__sharp_loop562_end563:;});
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
({({_sharp__sharp_loop568_begin570:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop568_end569;});}})
;
({(id = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_75))):
((parse_symbol)(((String__type) &__string_76))));
})
);
(form2 = (_l__parse__Code__Multiplicative)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_567;
({_sharp_pair_567;
(_sharp_pair_567 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_567).car) = form);
(((* _sharp_pair_567).cdr) = ({
struct struct0x08067088 *_sharp_pair_566;
({_sharp_pair_566;
(_sharp_pair_566 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_566).car) = form2);
(((* _sharp_pair_566).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_566);
})
);
((List__O__Form__C____type__type ) _sharp_pair_567);
})
);}));});
})
;
({goto _sharp__sharp_loop568_begin570;});});
_sharp__sharp_loop568_end569:;});
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
({({_sharp__sharp_loop574_begin576:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 62))||(((((new_peek_char)(1) == 60))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop574_end575;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_77))):
((parse_symbol)(((String__type) &__string_78))));
})
);
(form2 = (_l__parse__Code__Additive)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_573;
({_sharp_pair_573;
(_sharp_pair_573 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_573).car) = form);
(((* _sharp_pair_573).cdr) = ({
struct struct0x08067088 *_sharp_pair_572;
({_sharp_pair_572;
(_sharp_pair_572 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_572).car) = form2);
(((* _sharp_pair_572).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_572);
})
);
((List__O__Form__C____type__type ) _sharp_pair_573);
})
);}));});
})
;
({goto _sharp__sharp_loop574_begin576;});});
_sharp__sharp_loop574_end575:;});
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
({({_sharp__sharp_loop580_begin582:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop580_end581;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_79))):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_80))):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_81))):
((parse_symbol)(((String__type) &__string_82))));
})
));
})
));
})
);
(form2 = (_l__parse__Code__Shift)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_579;
({_sharp_pair_579;
(_sharp_pair_579 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_579).car) = form);
(((* _sharp_pair_579).cdr) = ({
struct struct0x08067088 *_sharp_pair_578;
({_sharp_pair_578;
(_sharp_pair_578 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_578).car) = form2);
(((* _sharp_pair_578).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_578);
})
);
((List__O__Form__C____type__type ) _sharp_pair_579);
})
);}));});
})
;
({goto _sharp__sharp_loop580_begin582;});});
_sharp__sharp_loop580_end581:;});
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
({({_sharp__sharp_loop586_begin588:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((((new_peek_char)(0) == 33))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 61))||(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop586_end587;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_83))):
((parse_symbol)(((String__type) &__string_84))));
})
);
(form2 = (_l__parse__Code__Relational)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_585;
({_sharp_pair_585;
(_sharp_pair_585 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_585).car) = form);
(((* _sharp_pair_585).cdr) = ({
struct struct0x08067088 *_sharp_pair_584;
({_sharp_pair_584;
(_sharp_pair_584 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_584).car) = form2);
(((* _sharp_pair_584).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_584);
})
);
((List__O__Form__C____type__type ) _sharp_pair_585);
})
);}));});
})
;
({goto _sharp__sharp_loop586_begin588;});});
_sharp__sharp_loop586_end587:;});
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
({({_sharp__sharp_loop592_begin594:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop592_end593;});}})
;
({(id = (parse_symbol)(((String__type) &__string_85)));
(form2 = (_l__parse__Code__Equality)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_591;
({_sharp_pair_591;
(_sharp_pair_591 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_591).car) = form);
(((* _sharp_pair_591).cdr) = ({
struct struct0x08067088 *_sharp_pair_590;
({_sharp_pair_590;
(_sharp_pair_590 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_590).car) = form2);
(((* _sharp_pair_590).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_590);
})
);
((List__O__Form__C____type__type ) _sharp_pair_591);
})
);}));});
})
;
({goto _sharp__sharp_loop592_begin594;});});
_sharp__sharp_loop592_end593:;});
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
({({_sharp__sharp_loop598_begin600:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 94))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop598_end599;});}})
;
({(id = (parse_symbol)(((String__type) &__string_86)));
(form2 = (_l__parse__Code__Bitwise_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_597;
({_sharp_pair_597;
(_sharp_pair_597 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_597).car) = form);
(((* _sharp_pair_597).cdr) = ({
struct struct0x08067088 *_sharp_pair_596;
({_sharp_pair_596;
(_sharp_pair_596 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_596).car) = form2);
(((* _sharp_pair_596).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_596);
})
);
((List__O__Form__C____type__type ) _sharp_pair_597);
})
);}));});
})
;
({goto _sharp__sharp_loop598_begin600;});});
_sharp__sharp_loop598_end599:;});
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
({({_sharp__sharp_loop604_begin606:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop604_end605;});}})
;
({(id = (parse_symbol)(((String__type) &__string_87)));
(form2 = (_l__parse__Code__Bitwise_Xor)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_603;
({_sharp_pair_603;
(_sharp_pair_603 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_603).car) = form);
(((* _sharp_pair_603).cdr) = ({
struct struct0x08067088 *_sharp_pair_602;
({_sharp_pair_602;
(_sharp_pair_602 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_602).car) = form2);
(((* _sharp_pair_602).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_602);
})
);
((List__O__Form__C____type__type ) _sharp_pair_603);
})
);}));});
})
;
({goto _sharp__sharp_loop604_begin606;});});
_sharp__sharp_loop604_end605:;});
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
({({_sharp__sharp_loop610_begin612:;
({
({if( (!(((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 97))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 110))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 100))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop610_end611;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_88));
({intern( "@and");});}));
(form2 = (_l__parse__Code__Bitwise_Ior)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_609;
({_sharp_pair_609;
(_sharp_pair_609 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_609).car) = form);
(((* _sharp_pair_609).cdr) = ({
struct struct0x08067088 *_sharp_pair_608;
({_sharp_pair_608;
(_sharp_pair_608 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_608).car) = form2);
(((* _sharp_pair_608).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_608);
})
);
((List__O__Form__C____type__type ) _sharp_pair_609);
})
);}));});
})
;
({goto _sharp__sharp_loop610_begin612;});});
_sharp__sharp_loop610_end611:;});
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
({({_sharp__sharp_loop616_begin618:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 111))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 114))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop616_end617;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_89));
({intern( "@or");});}));
(form2 = (_l__parse__Code__Logical_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_615;
({_sharp_pair_615;
(_sharp_pair_615 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_615).car) = form);
(((* _sharp_pair_615).cdr) = ({
struct struct0x08067088 *_sharp_pair_614;
({_sharp_pair_614;
(_sharp_pair_614 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_614).car) = form2);
(((* _sharp_pair_614).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_614);
})
);
((List__O__Form__C____type__type ) _sharp_pair_615);
})
);}));});
})
;
({goto _sharp__sharp_loop616_begin618;});});
_sharp__sharp_loop616_end617:;});
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
({(id = (parse_symbol)(((String__type) &__string_90)));
(form2 = (_l__parse__Code__Assignment)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067088 *_sharp_pair_620;
({_sharp_pair_620;
(_sharp_pair_620 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_620).car) = form);
(((* _sharp_pair_620).cdr) = ({
struct struct0x08067088 *_sharp_pair_619;
({_sharp_pair_619;
(_sharp_pair_619 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_619).car) = form2);
(((* _sharp_pair_619).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_619);
})
);
((List__O__Form__C____type__type ) _sharp_pair_620);
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
void **_sharp_make_list_ptr622;
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
List__O__Form__C____type__type _sharp_make_list621;
({_sharp_make_list621;
_sharp_make_list_ptr622;
(_sharp_make_list_ptr622 = ((void *) (&_sharp_make_list621)));
({({_sharp__sharp_loop623_begin625:;
({
({(parse_symbol)(((String__type) &__string_91));
(exp2 = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))?
((_l__parse__Code__Expression)()):
(({tup;})));
})
);
({({((* _sharp_make_list_ptr622) = (alloc_cons_cell)());
(((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr622))).car) = ((void *) exp2));
(_sharp_make_list_ptr622 = (&((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr622))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop623_end624;});}})
;
})
;
({goto _sharp__sharp_loop623_begin625;});});
_sharp__sharp_loop623_end624:;});
((* _sharp_make_list_ptr622) = ((void *) 0));
_sharp_make_list621;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x08067088 *_sharp_pair_626;
({_sharp_pair_626;
(_sharp_pair_626 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_626).car) = exp);
(((* _sharp_pair_626).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_626);
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
void **_sharp_make_list_ptr628;
Form__type exp2;
List__O__Form__C____type__type exp_list;
Form__type exp;
({(exp = (_l__parse__Code__Expression)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))?
(({(exp_list = ({
List__O__Form__C____type__type _sharp_make_list627;
({_sharp_make_list627;
_sharp_make_list_ptr628;
(_sharp_make_list_ptr628 = ((void *) (&_sharp_make_list627)));
({({_sharp__sharp_loop629_begin631:;
({
({(parse_symbol)(((String__type) &__string_92));
(exp2 = (_l__parse__Code__Expression)());
({({((* _sharp_make_list_ptr628) = (alloc_cons_cell)());
(((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr628))).car) = ((void *) exp2));
(_sharp_make_list_ptr628 = (&((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr628))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop629_end630;});}})
;
})
;
({goto _sharp__sharp_loop629_begin631;});});
_sharp__sharp_loop629_end630:;});
((* _sharp_make_list_ptr628) = ((void *) 0));
_sharp_make_list627;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x08067088 *_sharp_pair_632;
({_sharp_pair_632;
(_sharp_pair_632 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_632).car) = exp);
(((* _sharp_pair_632).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_632);
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
void **_sharp_make_list_ptr635;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))
{
({(arg1 = (_l__parse__Code__Non_Empty_Sequence)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list634;
({_sharp_make_list634;
_sharp_make_list_ptr635;
(_sharp_make_list_ptr635 = ((void *) (&_sharp_make_list634)));
({({_sharp__sharp_loop636_begin638:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop636_end637;});}})
;
({(parse_symbol)(((String__type) &__string_93));
(arg = (_l__parse__Code__Non_Empty_Sequence)());
({({((* _sharp_make_list_ptr635) = (alloc_cons_cell)());
(((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr635))).car) = ((void *) arg));
(_sharp_make_list_ptr635 = (&((* (* ((struct struct0x0862b8d8 **) _sharp_make_list_ptr635))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop636_begin638;});});
_sharp__sharp_loop636_end637:;});
((* _sharp_make_list_ptr635) = ((void *) 0));
_sharp_make_list634;});
})
);
(arg_list = ({({
struct struct0x08067088 *_sharp_pair_639;
({_sharp_pair_639;
(_sharp_pair_639 = ((struct struct0x08067088 *) (alloc_cons_cell)()));});
(((* _sharp_pair_639).car) = arg1);
(((* _sharp_pair_639).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_639);
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
({({_sharp__sharp_loop641_begin643:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop641_end642;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop641_begin643;});});
_sharp__sharp_loop641_end642:;});
({(read_char)();});});
})
;}

void  _l__parse__Lexical__Spacing(void)
{
return ({
({({_sharp__sharp_loop645_begin647:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop645_end646;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__Lexical__Comment)()));
})
;
})
;
({goto _sharp__sharp_loop645_begin647;});});
_sharp__sharp_loop645_end646:;});
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
({({_sharp__sharp_loop649_begin651:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop649_end650;});}})
;
({(d = (_l__parse__Lexical__Digit)());
({({
({(n = ((int) n * (int) 10));
(n = ((int) n + (int) d));});
})
;});});
})
;
({goto _sharp__sharp_loop649_begin651;});});
_sharp__sharp_loop649_end650:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Hexadecimal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop653_begin655:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 102))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop653_end654;});}})
;
({(d = (_l__parse__Lexical__Hexa_Digit)());
({({
({(n = ((int) n * (int) 16));
(n = ((int) n + (int) d));});
})
;});});
})
;
({goto _sharp__sharp_loop653_begin655;});});
_sharp__sharp_loop653_end654:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Octal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop657_begin659:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 55))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop657_end658;});}})
;
({(d = (_l__parse__Lexical__Octal_Digit)());
({({
({(n = ((int) n * (int) 8));
(n = ((int) n + (int) d));});
})
;});});
})
;
({goto _sharp__sharp_loop657_begin659;});});
_sharp__sharp_loop657_end658:;});
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
({({_sharp__sharp_loop661_begin663:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop661_end662;});}})
;
(_l__parse__Lexical__Alpha_Num)();
})
;
({goto _sharp__sharp_loop661_begin663;});});
_sharp__sharp_loop661_end662:;});
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
({({_sharp__sharp_loop665_begin667:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop665_end666;});}})
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
({goto _sharp__sharp_loop665_begin667;});});
_sharp__sharp_loop665_end666:;});
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
({({_sharp__sharp_loop669_begin674:;
({
({(read_char)();
({({_sharp__sharp_loop671_begin673:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 35))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 33))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop671_end672;});}})
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
({goto _sharp__sharp_loop671_begin673;});});
_sharp__sharp_loop671_end672:;});
(end = (get_point_pos)());
(read_char)();
(_l__parse__Lexical__Spacing)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop669_end670;});}})
;
})
;
({goto _sharp__sharp_loop669_begin674;});});
_sharp__sharp_loop669_end670:;});
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
