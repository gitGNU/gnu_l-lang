/* Automatically generated : do not edit!*/
#include "parse-l.inc"
Hash__O__Symbol__c__pointer__O__function__O__Form__c__tuple__O__Symbol__C____C____C____C____type__type parse_top_level_hash;

Hash__O__Symbol__c__pointer__O__function__O__Form__c__tuple__O__Symbol__C____C____C____C____type__type parse_macro_hash;

void  init__parse_l(void)
{
return ({
(parse_macro_hash = ((Hash__O__Symbol__c__pointer__O__function__O__Form__c__tuple__O__Symbol__C____C____C____C____type__type ) (make_hash_table)()));
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
(parse_top_level_hash = ((Hash__O__Symbol__c__pointer__O__function__O__Form__c__tuple__O__Symbol__C____C____C____C____type__type ) (make_hash_table)()));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "function")), ((void *) (&_l__parse__Top_Level__function)), ((Hash_Table__type ) parse_top_level_hash)));
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
struct struct0x080674c8 *_sharp_pair_471;
({_sharp_pair_471;
(_sharp_pair_471 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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
struct struct0x080674c8 *_sharp_pair_472;
({_sharp_pair_472;
(_sharp_pair_472 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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
struct struct0x080674c8 *_sharp_pair_473;
({_sharp_pair_473;
(_sharp_pair_473 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Top_Level__Top(void)
{
return ({
Symbol__type id;
({(id = (_l__parse__Lexical__Id)());
({({
Form__type (*funptr)(Symbol__type );
(funptr = ((Form__type (*)(Symbol__type )) (gethash)(((void *) id), ((Hash_Table__type ) parse_top_level_hash))));
({if( (funptr == ((Form__type (*)(Symbol__type )) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_13));
(print_String)(((String__type) &__string_14));
(print_Symbol)(id);
(print_String)(((String__type) &__string_15));
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
((* funptr))(id);
})
;});});
})
;}

Form__type  _l__parse__Top_Level__function(Symbol__type  fsymb)
{
return ({
void **_sharp_make_list_ptr476;
Form__type ret_type;
List__O__Form__C____type__type params;
Form__type body;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
Symbol__type name;
({(name = (_l__parse__Lexical__Id)());
(parse_symbol)(((String__type) &__string_16));
(params = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))
{
({(arg1 = (_l__parse__Type__Labeled_Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list475;
({_sharp_make_list475;
_sharp_make_list_ptr476;
(_sharp_make_list_ptr476 = ((void *) (&_sharp_make_list475)));
({({_sharp__sharp_loop477_begin479:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop477_end478;});}})
;
({(parse_symbol)(((String__type) &__string_17));
(arg = (_l__parse__Type__Labeled_Type)());
({({((* _sharp_make_list_ptr476) = (alloc_cons_cell)());
(((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr476))).car) = ((void *) arg));
(_sharp_make_list_ptr476 = (&((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr476))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop477_begin479;});});
_sharp__sharp_loop477_end478:;});
((* _sharp_make_list_ptr476) = ((void *) 0));
_sharp_make_list475;});
})
);
(arg_list = ({({
struct struct0x080674c8 *_sharp_pair_480;
({_sharp_pair_480;
(_sharp_pair_480 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_480).car) = arg1);
(((* _sharp_pair_480).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_480);
})
;}));});}})
;
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_18));
(parse_symbol)(((String__type) &__string_19));
(ret_type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_20));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_21));
({(Compound_Form)(intern( "define"), ({
struct struct0x080674c8 *_sharp_pair_486;
({_sharp_pair_486;
(_sharp_pair_486 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_486).car) = (Id_Form)(fsymb));
(((* _sharp_pair_486).cdr) = ({
struct struct0x080674c8 *_sharp_pair_485;
({_sharp_pair_485;
(_sharp_pair_485 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_485).car) = (Id_Form)(name));
(((* _sharp_pair_485).cdr) = ({
struct struct0x080674c8 *_sharp_pair_484;
({_sharp_pair_484;
(_sharp_pair_484 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_484).car) = (Compound_Form)(intern( "lambda"), ({
struct struct0x080674c8 *_sharp_pair_483;
({_sharp_pair_483;
(_sharp_pair_483 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_483).car) = ret_type);
(((* _sharp_pair_483).cdr) = ({
struct struct0x080674c8 *_sharp_pair_482;
({_sharp_pair_482;
(_sharp_pair_482 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_482).car) = (Compound_Form)(intern( "tuple"), params));
(((* _sharp_pair_482).cdr) = ({
struct struct0x080674c8 *_sharp_pair_481;
({_sharp_pair_481;
(_sharp_pair_481 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_481).car) = body);
(((* _sharp_pair_481).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_481);
})
);
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
);
((List__O__Form__C____type__type ) _sharp_pair_486);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__global(Symbol__type  fsymb)
{
return ({
Form__type ltype;
({(ltype = (_l__parse__Type__Labeled_Type)());
({(Compound_Form)(intern( "define"), ({
struct struct0x080674c8 *_sharp_pair_488;
({_sharp_pair_488;
(_sharp_pair_488 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_488).car) = (Id_Form)(fsymb));
(((* _sharp_pair_488).cdr) = ({
struct struct0x080674c8 *_sharp_pair_487;
({_sharp_pair_487;
(_sharp_pair_487 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_487).car) = ltype);
(((* _sharp_pair_487).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_487);
})
);
((List__O__Form__C____type__type ) _sharp_pair_488);
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
struct struct0x080674c8 *_sharp_pair_489;
({_sharp_pair_489;
(_sharp_pair_489 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_489).car) = type);
(((* _sharp_pair_489).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_489);
})
;});})):
(({((List__O__Form__C____type__type ) 0);})));
})
);
({(Compound_Form)(intern( "let"), ({
struct struct0x080674c8 *_sharp_pair_490;
({_sharp_pair_490;
(_sharp_pair_490 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_490).car) = id);
(((* _sharp_pair_490).cdr) = typel);
((List__O__Form__C____type__type ) _sharp_pair_490);
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
({(parse_symbol)(((String__type) &__string_22));
(cond = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_23));
(exp = (_l__parse__Code__Expression)());
(elsel = ({
((((((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 101))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 108))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 115))||(((Bool__type ) 0))))))&&(((((new_peek_char)(3) == 101))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_24));
(exp2 = (_l__parse__Code__Expression)());
({({
struct struct0x080674c8 *_sharp_pair_491;
({_sharp_pair_491;
(_sharp_pair_491 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_491).car) = exp2);
(((* _sharp_pair_491).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_491);
})
;});})):
(({((List__O__Form__C____type__type ) 0);})));
})
);
({(Compound_Form)(intern( "if"), ({
struct struct0x080674c8 *_sharp_pair_493;
({_sharp_pair_493;
(_sharp_pair_493 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_493).car) = cond);
(((* _sharp_pair_493).cdr) = ({
struct struct0x080674c8 *_sharp_pair_492;
({_sharp_pair_492;
(_sharp_pair_492 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_492).car) = exp);
(((* _sharp_pair_492).cdr) = elsel);
((List__O__Form__C____type__type ) _sharp_pair_492);
})
);
((List__O__Form__C____type__type ) _sharp_pair_493);
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
struct struct0x080674c8 *_sharp_pair_494;
({_sharp_pair_494;
(_sharp_pair_494 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_494).car) = exp);
(((* _sharp_pair_494).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_494);
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
(({(parse_symbol)(((String__type) &__string_25));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@seq"), ({
struct struct0x080674c8 *_sharp_pair_496;
({_sharp_pair_496;
(_sharp_pair_496 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_496).car) = (Compound_Form)(intern( "@set_continue"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_496).cdr) = ({
struct struct0x080674c8 *_sharp_pair_495;
({_sharp_pair_495;
(_sharp_pair_495 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_495).car) = exp);
(((* _sharp_pair_495).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_495);
})
);
((List__O__Form__C____type__type ) _sharp_pair_496);
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
({(parse_symbol)(((String__type) &__string_26));
(var = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_27));
(collect = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_28));
(body = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "foreach"), ({
struct struct0x080674c8 *_sharp_pair_499;
({_sharp_pair_499;
(_sharp_pair_499 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_499).car) = var);
(((* _sharp_pair_499).cdr) = ({
struct struct0x080674c8 *_sharp_pair_498;
({_sharp_pair_498;
(_sharp_pair_498 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_498).car) = collect);
(((* _sharp_pair_498).cdr) = ({
struct struct0x080674c8 *_sharp_pair_497;
({_sharp_pair_497;
(_sharp_pair_497 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_497).car) = body);
(((* _sharp_pair_497).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_497);
})
);
((List__O__Form__C____type__type ) _sharp_pair_498);
})
);
((List__O__Form__C____type__type ) _sharp_pair_499);
})
);});});
})
;}

Form__type  _l__parse__Macro__cast(Symbol__type  symb)
{
return ({
Form__type exp;
Form__type type;
({(parse_symbol)(((String__type) &__string_29));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_30));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_31));
({(Compound_Form)(intern( "cast"), ({
struct struct0x080674c8 *_sharp_pair_501;
({_sharp_pair_501;
(_sharp_pair_501 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_501).car) = type);
(((* _sharp_pair_501).cdr) = ({
struct struct0x080674c8 *_sharp_pair_500;
({_sharp_pair_500;
(_sharp_pair_500 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_500).car) = exp);
(((* _sharp_pair_500).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_500);
})
);
((List__O__Form__C____type__type ) _sharp_pair_501);
})
);});});
})
;}

Form__type  _l__parse__Macro__Form(Symbol__type  symb)
{
return ({
Form__type exp;
({(parse_symbol)(((String__type) &__string_32));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_33));
({(Compound_Form)(intern( "Form"), ({
struct struct0x080674c8 *_sharp_pair_502;
({_sharp_pair_502;
(_sharp_pair_502 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_502).car) = exp);
(((* _sharp_pair_502).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_502);
})
);});});
})
;}

Form__type  _l__parse__Macro__XML(Symbol__type  fsymb)
{
return ({
Form__type form;
({(parse_symbol)(((String__type) &__string_34));
(form = (_l__parse__XML_Parser__Content)());
(parse_symbol)(((String__type) &__string_35));
({(Compound_Form)(intern( "XML"), ({
struct struct0x080674c8 *_sharp_pair_503;
({_sharp_pair_503;
(_sharp_pair_503 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_503).car) = form);
(((* _sharp_pair_503).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_503);
})
);});});
})
;}

Form__type  _l__parse__Type__Base_Type(void)
{
return ({
void **_sharp_make_list_ptr512;
void **_sharp_make_list_ptr506;
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
(parse_symbol)(((String__type) &__string_36));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list505;
({_sharp_make_list505;
_sharp_make_list_ptr506;
(_sharp_make_list_ptr506 = ((void *) (&_sharp_make_list505)));
({({_sharp__sharp_loop507_begin509:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop507_end508;});}})
;
({(lab_type = (_l__parse__Type__Labeled_Type)());
(parse_symbol)(((String__type) &__string_37));
({({((* _sharp_make_list_ptr506) = (alloc_cons_cell)());
(((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr506))).car) = ((void *) lab_type));
(_sharp_make_list_ptr506 = (&((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr506))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop507_begin509;});});
_sharp__sharp_loop507_end508:;});
((* _sharp_make_list_ptr506) = ((void *) 0));
_sharp_make_list505;});
})
);
(parse_symbol)(((String__type) &__string_38));
({(Compound_Form)(intern( "struct"), form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(form_list2 = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list511;
({_sharp_make_list511;
_sharp_make_list_ptr512;
(_sharp_make_list_ptr512 = ((void *) (&_sharp_make_list511)));
({({_sharp__sharp_loop513_begin515:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop513_end514;});}})
;
({(parse_symbol)(((String__type) &__string_39));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr512) = (alloc_cons_cell)());
(((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr512))).car) = ((void *) arg));
(_sharp_make_list_ptr512 = (&((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr512))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop513_begin515;});});
_sharp__sharp_loop513_end514:;});
((* _sharp_make_list_ptr512) = ((void *) 0));
_sharp_make_list511;});
})
);
(arg_list = ({({
struct struct0x080674c8 *_sharp_pair_516;
({_sharp_pair_516;
(_sharp_pair_516 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_516).car) = arg1);
(((* _sharp_pair_516).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_516);
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
void **_sharp_make_list_ptr519;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
List__O__Form__C____type__type form_list;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(form_list = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list518;
({_sharp_make_list518;
_sharp_make_list_ptr519;
(_sharp_make_list_ptr519 = ((void *) (&_sharp_make_list518)));
({({_sharp__sharp_loop520_begin522:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop520_end521;});}})
;
({(parse_symbol)(((String__type) &__string_40));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr519) = (alloc_cons_cell)());
(((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr519))).car) = ((void *) arg));
(_sharp_make_list_ptr519 = (&((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr519))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop520_begin522;});});
_sharp__sharp_loop520_end521:;});
((* _sharp_make_list_ptr519) = ((void *) 0));
_sharp_make_list518;});
})
);
(arg_list = ({({
struct struct0x080674c8 *_sharp_pair_523;
({_sharp_pair_523;
(_sharp_pair_523 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_523).car) = arg1);
(((* _sharp_pair_523).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_523);
})
;}));});}})
;
})
;
({arg_list;});}));
({(read_char)();});
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
({({_sharp__sharp_loop526_begin528:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop526_end527;});}})
;
({(parse_symbol)(((String__type) &__string_41));
(form = ({(Compound_Form)(intern( "*"), ({
struct struct0x080674c8 *_sharp_pair_525;
({_sharp_pair_525;
(_sharp_pair_525 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_525).car) = form);
(((* _sharp_pair_525).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_525);
})
);}));});
})
;
({goto _sharp__sharp_loop526_begin528;});});
_sharp__sharp_loop526_end527:;});
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
({(id = (parse_symbol)(((String__type) &__string_42)));
(form2 = (_l__parse__Type__Function_Type)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_530;
({_sharp_pair_530;
(_sharp_pair_530 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_530).car) = form);
(((* _sharp_pair_530).cdr) = ({
struct struct0x080674c8 *_sharp_pair_529;
({_sharp_pair_529;
(_sharp_pair_529 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_529).car) = form2);
(((* _sharp_pair_529).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_529);
})
);
((List__O__Form__C____type__type ) _sharp_pair_530);
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
struct struct0x080674c8 *_sharp_pair_532;
({_sharp_pair_532;
(_sharp_pair_532 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_532).car) = idf);
(((* _sharp_pair_532).cdr) = ({
struct struct0x080674c8 *_sharp_pair_531;
({_sharp_pair_531;
(_sharp_pair_531 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_531).car) = type);
(((* _sharp_pair_531).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_531);
})
);
((List__O__Form__C____type__type ) _sharp_pair_532);
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
(({(parse_symbol)(((String__type) &__string_43));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_44));
({(Compound_Form)(id, form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_45));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@label"), ({
struct struct0x080674c8 *_sharp_pair_534;
({_sharp_pair_534;
(_sharp_pair_534 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_534).car) = (Id_Form)(id));
(((* _sharp_pair_534).cdr) = ({
struct struct0x080674c8 *_sharp_pair_533;
({_sharp_pair_533;
(_sharp_pair_533 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_533).car) = exp);
(((* _sharp_pair_533).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_533);
})
);
((List__O__Form__C____type__type ) _sharp_pair_534);
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
((parse_symbol)(((String__type) &__string_46))):
((parse_symbol)(((String__type) &__string_47))));
})
);
(__rep_exp = (_l__parse__Code__Sequence)());
(parse_symbol)(((String__type) &__string_48));
({(Compound_Form)(__rep_symb, ({
struct struct0x080674c8 *_sharp_pair_535;
({_sharp_pair_535;
(_sharp_pair_535 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_535).car) = __rep_exp);
(((* _sharp_pair_535).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_535);
})
);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_49));
(expl = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_50));
({(((((expl == ((List__O__Form__C____type__type ) 0)))||((((* ((struct struct0x0805f240 *) expl)).tail) != ((List__O__Form__C____type__type ) 0)))))?
((Compound_Form)(intern( "tuple"), expl)):
(((* ((struct struct0x0805f240 *) expl)).head)));});})):
(({(parse_symbol)(((String__type) &__string_51));
(seq = (_l__parse__Code__Maybe_Empty_Sequence)());
(parse_symbol)(((String__type) &__string_52));
({(Compound_Form)(intern( "@block"), ({
struct struct0x080674c8 *_sharp_pair_536;
({_sharp_pair_536;
(_sharp_pair_536 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_536).car) = seq);
(((* _sharp_pair_536).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_536);
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
({({_sharp__sharp_loop543_begin545:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((((new_peek_char)(0) == 46))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop543_end544;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_53));
(form2 = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_54));
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x080674c8 *_sharp_pair_539;
({_sharp_pair_539;
(_sharp_pair_539 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_539).car) = form);
(((* _sharp_pair_539).cdr) = ({
struct struct0x080674c8 *_sharp_pair_538;
({_sharp_pair_538;
(_sharp_pair_538 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_538).car) = form2);
(((* _sharp_pair_538).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_538);
})
);
((List__O__Form__C____type__type ) _sharp_pair_539);
})
);}));})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 46))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_55));
(id = (_l__parse__Lexical__Id)());
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x080674c8 *_sharp_pair_541;
({_sharp_pair_541;
(_sharp_pair_541 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_541).car) = form);
(((* _sharp_pair_541).cdr) = ({
struct struct0x080674c8 *_sharp_pair_540;
({_sharp_pair_540;
(_sharp_pair_540 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_540).car) = (Symbol_Form)(id));
(((* _sharp_pair_540).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_540);
})
);
((List__O__Form__C____type__type ) _sharp_pair_541);
})
);}));})):
(({(parse_symbol)(((String__type) &__string_56));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_57));
(form = ({(Compound_Form)(intern( "@funcall"), ({
struct struct0x080674c8 *_sharp_pair_542;
({_sharp_pair_542;
(_sharp_pair_542 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_542).car) = form);
(((* _sharp_pair_542).cdr) = form_list);
((List__O__Form__C____type__type ) _sharp_pair_542);
})
);}));})));
})
));
})
;
})
;
({goto _sharp__sharp_loop543_begin545;});});
_sharp__sharp_loop543_end544:;});
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
(({(parse_symbol)(((String__type) &__string_58));
({intern( "@unary_minus");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_59));
({intern( "@get_label");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_60));
({intern( "@ref");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_61));
({intern( "@deref");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 45))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_62));
({intern( "@pre_--");});})):
(({(parse_symbol)(((String__type) &__string_63));
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
struct struct0x080674c8 *_sharp_pair_546;
({_sharp_pair_546;
(_sharp_pair_546 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_546).car) = form);
(((* _sharp_pair_546).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_546);
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
({({_sharp__sharp_loop550_begin552:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop550_end551;});}})
;
({(id = (parse_symbol)(((String__type) &__string_64)));
(form2 = (_l__parse__Code__Unary_Operator)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_549;
({_sharp_pair_549;
(_sharp_pair_549 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_549).car) = form);
(((* _sharp_pair_549).cdr) = ({
struct struct0x080674c8 *_sharp_pair_548;
({_sharp_pair_548;
(_sharp_pair_548 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_548).car) = form2);
(((* _sharp_pair_548).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_548);
})
);
((List__O__Form__C____type__type ) _sharp_pair_549);
})
);}));});
})
;
({goto _sharp__sharp_loop550_begin552;});});
_sharp__sharp_loop550_end551:;});
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
({({_sharp__sharp_loop556_begin558:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop556_end557;});}})
;
({(id = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_65))):
((parse_symbol)(((String__type) &__string_66))));
})
);
(form2 = (_l__parse__Code__Multiplicative)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_555;
({_sharp_pair_555;
(_sharp_pair_555 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_555).car) = form);
(((* _sharp_pair_555).cdr) = ({
struct struct0x080674c8 *_sharp_pair_554;
({_sharp_pair_554;
(_sharp_pair_554 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_554).car) = form2);
(((* _sharp_pair_554).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_554);
})
);
((List__O__Form__C____type__type ) _sharp_pair_555);
})
);}));});
})
;
({goto _sharp__sharp_loop556_begin558;});});
_sharp__sharp_loop556_end557:;});
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
({({_sharp__sharp_loop562_begin564:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 62))||(((((new_peek_char)(1) == 60))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop562_end563;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_67))):
((parse_symbol)(((String__type) &__string_68))));
})
);
(form2 = (_l__parse__Code__Additive)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_561;
({_sharp_pair_561;
(_sharp_pair_561 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_561).car) = form);
(((* _sharp_pair_561).cdr) = ({
struct struct0x080674c8 *_sharp_pair_560;
({_sharp_pair_560;
(_sharp_pair_560 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Relational(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Shift)());
({({_sharp__sharp_loop568_begin570:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop568_end569;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_69))):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_70))):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_71))):
((parse_symbol)(((String__type) &__string_72))));
})
));
})
));
})
);
(form2 = (_l__parse__Code__Shift)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_567;
({_sharp_pair_567;
(_sharp_pair_567 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_567).car) = form);
(((* _sharp_pair_567).cdr) = ({
struct struct0x080674c8 *_sharp_pair_566;
({_sharp_pair_566;
(_sharp_pair_566 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Equality(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Relational)());
({({_sharp__sharp_loop574_begin576:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((((new_peek_char)(0) == 33))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 61))||(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop574_end575;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_73))):
((parse_symbol)(((String__type) &__string_74))));
})
);
(form2 = (_l__parse__Code__Relational)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_573;
({_sharp_pair_573;
(_sharp_pair_573 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_573).car) = form);
(((* _sharp_pair_573).cdr) = ({
struct struct0x080674c8 *_sharp_pair_572;
({_sharp_pair_572;
(_sharp_pair_572 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Bitwise_And(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Equality)());
({({_sharp__sharp_loop580_begin582:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop580_end581;});}})
;
({(id = (parse_symbol)(((String__type) &__string_75)));
(form2 = (_l__parse__Code__Equality)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_579;
({_sharp_pair_579;
(_sharp_pair_579 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_579).car) = form);
(((* _sharp_pair_579).cdr) = ({
struct struct0x080674c8 *_sharp_pair_578;
({_sharp_pair_578;
(_sharp_pair_578 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Bitwise_Xor(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Bitwise_And)());
({({_sharp__sharp_loop586_begin588:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 94))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop586_end587;});}})
;
({(id = (parse_symbol)(((String__type) &__string_76)));
(form2 = (_l__parse__Code__Bitwise_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_585;
({_sharp_pair_585;
(_sharp_pair_585 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_585).car) = form);
(((* _sharp_pair_585).cdr) = ({
struct struct0x080674c8 *_sharp_pair_584;
({_sharp_pair_584;
(_sharp_pair_584 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Bitwise_Ior(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Bitwise_Xor)());
({({_sharp__sharp_loop592_begin594:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop592_end593;});}})
;
({(id = (parse_symbol)(((String__type) &__string_77)));
(form2 = (_l__parse__Code__Bitwise_Xor)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_591;
({_sharp_pair_591;
(_sharp_pair_591 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_591).car) = form);
(((* _sharp_pair_591).cdr) = ({
struct struct0x080674c8 *_sharp_pair_590;
({_sharp_pair_590;
(_sharp_pair_590 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Logical_And(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Bitwise_Ior)());
({({_sharp__sharp_loop598_begin600:;
({
({if( (!(((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 97))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 110))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 100))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop598_end599;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_78));
({intern( "@and");});}));
(form2 = (_l__parse__Code__Bitwise_Ior)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_597;
({_sharp_pair_597;
(_sharp_pair_597 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_597).car) = form);
(((* _sharp_pair_597).cdr) = ({
struct struct0x080674c8 *_sharp_pair_596;
({_sharp_pair_596;
(_sharp_pair_596 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Logical_Or(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Logical_And)());
({({_sharp__sharp_loop604_begin606:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 111))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 114))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop604_end605;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_79));
({intern( "@or");});}));
(form2 = (_l__parse__Code__Logical_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_603;
({_sharp_pair_603;
(_sharp_pair_603 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_603).car) = form);
(((* _sharp_pair_603).cdr) = ({
struct struct0x080674c8 *_sharp_pair_602;
({_sharp_pair_602;
(_sharp_pair_602 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
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
({(id = (parse_symbol)(((String__type) &__string_80)));
(form2 = (_l__parse__Code__Assignment)());
(form = ({(Compound_Form)(id, ({
struct struct0x080674c8 *_sharp_pair_608;
({_sharp_pair_608;
(_sharp_pair_608 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_608).car) = form);
(((* _sharp_pair_608).cdr) = ({
struct struct0x080674c8 *_sharp_pair_607;
({_sharp_pair_607;
(_sharp_pair_607 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_607).car) = form2);
(((* _sharp_pair_607).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_607);
})
);
((List__O__Form__C____type__type ) _sharp_pair_608);
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
void **_sharp_make_list_ptr610;
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
List__O__Form__C____type__type _sharp_make_list609;
({_sharp_make_list609;
_sharp_make_list_ptr610;
(_sharp_make_list_ptr610 = ((void *) (&_sharp_make_list609)));
({({_sharp__sharp_loop611_begin613:;
({
({(parse_symbol)(((String__type) &__string_81));
(exp2 = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))?
((_l__parse__Code__Expression)()):
(({tup;})));
})
);
({({((* _sharp_make_list_ptr610) = (alloc_cons_cell)());
(((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr610))).car) = ((void *) exp2));
(_sharp_make_list_ptr610 = (&((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr610))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop611_end612;});}})
;
})
;
({goto _sharp__sharp_loop611_begin613;});});
_sharp__sharp_loop611_end612:;});
((* _sharp_make_list_ptr610) = ((void *) 0));
_sharp_make_list609;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x080674c8 *_sharp_pair_614;
({_sharp_pair_614;
(_sharp_pair_614 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_614).car) = exp);
(((* _sharp_pair_614).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_614);
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
void **_sharp_make_list_ptr616;
Form__type exp2;
List__O__Form__C____type__type exp_list;
Form__type exp;
({(exp = (_l__parse__Code__Expression)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))?
(({(exp_list = ({
List__O__Form__C____type__type _sharp_make_list615;
({_sharp_make_list615;
_sharp_make_list_ptr616;
(_sharp_make_list_ptr616 = ((void *) (&_sharp_make_list615)));
({({_sharp__sharp_loop617_begin619:;
({
({(parse_symbol)(((String__type) &__string_82));
(exp2 = (_l__parse__Code__Expression)());
({({((* _sharp_make_list_ptr616) = (alloc_cons_cell)());
(((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr616))).car) = ((void *) exp2));
(_sharp_make_list_ptr616 = (&((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr616))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop617_end618;});}})
;
})
;
({goto _sharp__sharp_loop617_begin619;});});
_sharp__sharp_loop617_end618:;});
((* _sharp_make_list_ptr616) = ((void *) 0));
_sharp_make_list615;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x080674c8 *_sharp_pair_620;
({_sharp_pair_620;
(_sharp_pair_620 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_620).car) = exp);
(((* _sharp_pair_620).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_620);
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
void **_sharp_make_list_ptr623;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))
{
({(arg1 = (_l__parse__Code__Non_Empty_Sequence)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list622;
({_sharp_make_list622;
_sharp_make_list_ptr623;
(_sharp_make_list_ptr623 = ((void *) (&_sharp_make_list622)));
({({_sharp__sharp_loop624_begin626:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop624_end625;});}})
;
({(parse_symbol)(((String__type) &__string_83));
(arg = (_l__parse__Code__Non_Empty_Sequence)());
({({((* _sharp_make_list_ptr623) = (alloc_cons_cell)());
(((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr623))).car) = ((void *) arg));
(_sharp_make_list_ptr623 = (&((* (* ((struct struct0x08626f10 **) _sharp_make_list_ptr623))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop624_begin626;});});
_sharp__sharp_loop624_end625:;});
((* _sharp_make_list_ptr623) = ((void *) 0));
_sharp_make_list622;});
})
);
(arg_list = ({({
struct struct0x080674c8 *_sharp_pair_627;
({_sharp_pair_627;
(_sharp_pair_627 = ((struct struct0x080674c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_627).car) = arg1);
(((* _sharp_pair_627).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_627);
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
({({_sharp__sharp_loop629_begin631:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop629_end630;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop629_begin631;});});
_sharp__sharp_loop629_end630:;});
({(read_char)();});});
})
;}

void  _l__parse__Lexical__Spacing(void)
{
return ({
({({_sharp__sharp_loop633_begin635:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop633_end634;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__Lexical__Comment)()));
})
;
})
;
({goto _sharp__sharp_loop633_begin635;});});
_sharp__sharp_loop633_end634:;});
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
({({_sharp__sharp_loop637_begin639:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop637_end638;});}})
;
({(d = (_l__parse__Lexical__Digit)());
({({
(n = ((int) n * (int) 10));
(n = ((int) n + (int) d));
})
;});});
})
;
({goto _sharp__sharp_loop637_begin639;});});
_sharp__sharp_loop637_end638:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Hexadecimal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop641_begin643:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 102))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop641_end642;});}})
;
({(d = (_l__parse__Lexical__Hexa_Digit)());
({({
(n = ((int) n * (int) 16));
(n = ((int) n + (int) d));
})
;});});
})
;
({goto _sharp__sharp_loop641_begin643;});});
_sharp__sharp_loop641_end642:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Octal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop645_begin647:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 55))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop645_end646;});}})
;
({(d = (_l__parse__Lexical__Octal_Digit)());
({({
(n = ((int) n * (int) 8));
(n = ((int) n + (int) d));
})
;});});
})
;
({goto _sharp__sharp_loop645_begin647;});});
_sharp__sharp_loop645_end646:;});
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
({({_sharp__sharp_loop649_begin651:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop649_end650;});}})
;
(_l__parse__Lexical__Alpha_Num)();
})
;
({goto _sharp__sharp_loop649_begin651;});});
_sharp__sharp_loop649_end650:;});
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
({({_sharp__sharp_loop653_begin655:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop653_end654;});}})
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
({goto _sharp__sharp_loop653_begin655;});});
_sharp__sharp_loop653_end654:;});
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
({({_sharp__sharp_loop657_begin662:;
({
({(read_char)();
({({_sharp__sharp_loop659_begin661:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 35))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 33))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop659_end660;});}})
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
({goto _sharp__sharp_loop659_begin661;});});
_sharp__sharp_loop659_end660:;});
(end = (get_point_pos)());
(read_char)();
(_l__parse__Lexical__Spacing)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop657_end658;});}})
;
})
;
({goto _sharp__sharp_loop657_begin662;});});
_sharp__sharp_loop657_end658:;});
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
