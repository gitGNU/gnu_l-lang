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
({({_sharp__sharp_loop448_begin450:;
({
(read_char)();
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 61))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 59))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop448_end449;});}})
;
})
;
({goto _sharp__sharp_loop448_begin450;});});
_sharp__sharp_loop448_end449:;});
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
struct struct0x080b27c8 *_sharp_pair_451;
({_sharp_pair_451;
(_sharp_pair_451 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_451).car) = exp);
(((* _sharp_pair_451).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_451);
})
);});})):
((_l__parse__XML_Parser__Tagged_Compound)()));
})
);
(cl = (_l__parse__XML_Parser__Content_List)());
({({
struct struct0x080b27c8 *_sharp_pair_452;
({_sharp_pair_452;
(_sharp_pair_452 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_452).car) = form);
(((* _sharp_pair_452).cdr) = cl);
((List__O__Form__C____type__type ) _sharp_pair_452);
})
;});})));
})
;})):
(({(cd = (_l__parse__XML_Parser__CharData)());
(cl = (_l__parse__XML_Parser__Content_List)());
({({
struct struct0x080b27c8 *_sharp_pair_453;
({_sharp_pair_453;
(_sharp_pair_453 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_453).car) = cd);
(((* _sharp_pair_453).cdr) = cl);
((List__O__Form__C____type__type ) _sharp_pair_453);
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
({({({_sharp__sharp_loop455_begin457:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 43))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 41))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop455_end456;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop455_begin457;});});
_sharp__sharp_loop455_end456:;});
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
(({({({_sharp__sharp_loop458_begin460:;
({
({(read_char)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop458_end459;});}})
;
})
;
({goto _sharp__sharp_loop458_begin460;});});
_sharp__sharp_loop458_end459:;});
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
({({_sharp__sharp_loop462_begin464:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop462_end463;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop462_begin464;});});
_sharp__sharp_loop462_end463:;});
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
({({_sharp__sharp_loop466_begin468:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop466_end467;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__Top_Level__Comment)()));
})
;
})
;
({goto _sharp__sharp_loop466_begin468;});});
_sharp__sharp_loop466_end467:;});
})
;}

List__O__Form__C____type__type  _l__parse__Top_Level__All(void)
{
return ({
void **_sharp_make_list_ptr471;
Form__type form;
List__O__Form__C____type__type list;
({(_l__parse__Top_Level__Spacing)();
(list = ({
List__O__Form__C____type__type _sharp_make_list470;
({_sharp_make_list470;
_sharp_make_list_ptr471;
(_sharp_make_list_ptr471 = ((void *) (&_sharp_make_list470)));
({({_sharp__sharp_loop472_begin474:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop472_end473;});}})
;
({(form = (_l__parse__Top_Level__Top)());
(_l__parse__Top_Level__Spacing)();
({({((* _sharp_make_list_ptr471) = (alloc_cons_cell)());
(((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr471))).car) = ((void *) form));
(_sharp_make_list_ptr471 = (&((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr471))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop472_begin474;});});
_sharp__sharp_loop472_end473:;});
((* _sharp_make_list_ptr471) = ((void *) 0));
_sharp_make_list470;});
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
void **_sharp_make_list_ptr477;
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
List__O__Form__C____type__type _sharp_make_list476;
({_sharp_make_list476;
_sharp_make_list_ptr477;
(_sharp_make_list_ptr477 = ((void *) (&_sharp_make_list476)));
({({_sharp__sharp_loop478_begin480:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop478_end479;});}})
;
({(parse_symbol)(((String__type) &__string_27));
(arg = (_l__parse__Type__Labeled_Type)());
({({((* _sharp_make_list_ptr477) = (alloc_cons_cell)());
(((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr477))).car) = ((void *) arg));
(_sharp_make_list_ptr477 = (&((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr477))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop478_begin480;});});
_sharp__sharp_loop478_end479:;});
((* _sharp_make_list_ptr477) = ((void *) 0));
_sharp_make_list476;});
})
);
(arg_list = ({({
struct struct0x080b27c8 *_sharp_pair_481;
({_sharp_pair_481;
(_sharp_pair_481 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_481).car) = arg1);
(((* _sharp_pair_481).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_481);
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
struct struct0x080b27c8 *_sharp_pair_487;
({_sharp_pair_487;
(_sharp_pair_487 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_487).car) = (Id_Form)(fsymb));
(((* _sharp_pair_487).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_486;
({_sharp_pair_486;
(_sharp_pair_486 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_486).car) = (Id_Form)(name));
(((* _sharp_pair_486).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_485;
({_sharp_pair_485;
(_sharp_pair_485 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_485).car) = (Compound_Form)(intern( "lambda"), ({
struct struct0x080b27c8 *_sharp_pair_484;
({_sharp_pair_484;
(_sharp_pair_484 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_484).car) = ret_type);
(((* _sharp_pair_484).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_483;
({_sharp_pair_483;
(_sharp_pair_483 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_483).car) = (Compound_Form)(intern( "tuple"), params));
(((* _sharp_pair_483).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_482;
({_sharp_pair_482;
(_sharp_pair_482 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_482).car) = body);
(((* _sharp_pair_482).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_482);
})
);
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
);
((List__O__Form__C____type__type ) _sharp_pair_487);
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
struct struct0x080b27c8 *_sharp_pair_490;
({_sharp_pair_490;
(_sharp_pair_490 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_490).car) = (Id_Form)(fsymb));
(((* _sharp_pair_490).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_489;
({_sharp_pair_489;
(_sharp_pair_489 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_489).car) = (Id_Form)(name));
(((* _sharp_pair_489).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_488;
({_sharp_pair_488;
(_sharp_pair_488 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_488).car) = type);
(((* _sharp_pair_488).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_488);
})
);
((List__O__Form__C____type__type ) _sharp_pair_489);
})
);
((List__O__Form__C____type__type ) _sharp_pair_490);
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
struct struct0x080b27c8 *_sharp_pair_493;
({_sharp_pair_493;
(_sharp_pair_493 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_493).car) = (Id_Form)(fsymb));
(((* _sharp_pair_493).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_492;
({_sharp_pair_492;
(_sharp_pair_492 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_492).car) = type_name);
(((* _sharp_pair_492).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_491;
({_sharp_pair_491;
(_sharp_pair_491 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_491).car) = type);
(((* _sharp_pair_491).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_491);
})
);
((List__O__Form__C____type__type ) _sharp_pair_492);
})
);
((List__O__Form__C____type__type ) _sharp_pair_493);
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
struct struct0x080b27c8 *_sharp_pair_498;
({_sharp_pair_498;
(_sharp_pair_498 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_498).car) = (Id_Form)(fsymb));
(((* _sharp_pair_498).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_497;
({_sharp_pair_497;
(_sharp_pair_497 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_497).car) = name);
(((* _sharp_pair_497).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_496;
({_sharp_pair_496;
(_sharp_pair_496 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_496).car) = (Compound_Form)(intern( ":"), ({
struct struct0x080b27c8 *_sharp_pair_495;
({_sharp_pair_495;
(_sharp_pair_495 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_495).car) = param);
(((* _sharp_pair_495).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_494;
({_sharp_pair_494;
(_sharp_pair_494 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_494).car) = body);
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
);
((List__O__Form__C____type__type ) _sharp_pair_498);
})
);});});
})
;}

Form__type  _l__parse__Top_Level__macro(Symbol__type  fsymb)
{
return ({
void **_sharp_make_list_ptr505;
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
struct struct0x080b27c8 *_sharp_pair_500;
({_sharp_pair_500;
(_sharp_pair_500 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_500).car) = name);
(((* _sharp_pair_500).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_499;
({_sharp_pair_499;
(_sharp_pair_499 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_499).car) = type);
(((* _sharp_pair_499).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_499);
})
);
((List__O__Form__C____type__type ) _sharp_pair_500);
})
);});})):
(({name;})));
})
;}));
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list504;
({_sharp_make_list504;
_sharp_make_list_ptr505;
(_sharp_make_list_ptr505 = ((void *) (&_sharp_make_list504)));
({({_sharp__sharp_loop506_begin508:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop506_end507;});}})
;
({(parse_symbol)(((String__type) &__string_40));
(arg = ({(name = (_l__parse__Lexical__Id_Form)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( ":"), ({
struct struct0x080b27c8 *_sharp_pair_503;
({_sharp_pair_503;
(_sharp_pair_503 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_503).car) = name);
(((* _sharp_pair_503).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_502;
({_sharp_pair_502;
(_sharp_pair_502 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_502).car) = type);
(((* _sharp_pair_502).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_502);
})
);
((List__O__Form__C____type__type ) _sharp_pair_503);
})
);});})):
(({name;})));
})
;}));
({({((* _sharp_make_list_ptr505) = (alloc_cons_cell)());
(((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr505))).car) = ((void *) arg));
(_sharp_make_list_ptr505 = (&((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr505))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop506_begin508;});});
_sharp__sharp_loop506_end507:;});
((* _sharp_make_list_ptr505) = ((void *) 0));
_sharp_make_list504;});
})
);
(arg_list = ({({
struct struct0x080b27c8 *_sharp_pair_509;
({_sharp_pair_509;
(_sharp_pair_509 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_509).car) = arg1);
(((* _sharp_pair_509).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_509);
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
struct struct0x080b27c8 *_sharp_pair_513;
({_sharp_pair_513;
(_sharp_pair_513 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_513).car) = (Id_Form)(fsymb));
(((* _sharp_pair_513).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_512;
({_sharp_pair_512;
(_sharp_pair_512 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_512).car) = macro_name);
(((* _sharp_pair_512).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_511;
({_sharp_pair_511;
(_sharp_pair_511 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_511).car) = (Compound_Form)(intern( "tuple"), params));
(((* _sharp_pair_511).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_510;
({_sharp_pair_510;
(_sharp_pair_510 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_510).car) = body);
(((* _sharp_pair_510).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_510);
})
);
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

Form__type  _l__parse__Top_Level__attribute_component(void)
{
return ({
Form__type name;
Form__type exp;
({
((((((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 108))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 101))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 102))||(((Bool__type ) 0))))))&&(((((new_peek_char)(3) == 116))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_44));
(parse_symbol)(((String__type) &__string_45));
(name = (_l__parse__Lexical__Id_Form)());
({(read_char)();});
(parse_symbol)(((String__type) &__string_46));
(exp = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "label"), ({
struct struct0x080b27c8 *_sharp_pair_516;
({_sharp_pair_516;
(_sharp_pair_516 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_516).car) = (Compound_Form)(intern( "left"), ({
struct struct0x080b27c8 *_sharp_pair_514;
({_sharp_pair_514;
(_sharp_pair_514 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_514).car) = name);
(((* _sharp_pair_514).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_514);
})
));
(((* _sharp_pair_516).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_515;
({_sharp_pair_515;
(_sharp_pair_515 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_515).car) = exp);
(((* _sharp_pair_515).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_515);
})
);
((List__O__Form__C____type__type ) _sharp_pair_516);
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
struct struct0x080b27c8 *_sharp_pair_518;
({_sharp_pair_518;
(_sharp_pair_518 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_518).car) = att1);
(((* _sharp_pair_518).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_517;
({_sharp_pair_517;
(_sharp_pair_517 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_517).car) = att2);
(((* _sharp_pair_517).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_517);
})
);
((List__O__Form__C____type__type ) _sharp_pair_518);
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
struct struct0x080b27c8 *_sharp_pair_523;
({_sharp_pair_523;
(_sharp_pair_523 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_523).car) = (Id_Form)(fsymb));
(((* _sharp_pair_523).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_522;
({_sharp_pair_522;
(_sharp_pair_522 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_522).car) = type);
(((* _sharp_pair_522).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_521;
({_sharp_pair_521;
(_sharp_pair_521 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_521).car) = (Id_Form)(objname));
(((* _sharp_pair_521).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_520;
({_sharp_pair_520;
(_sharp_pair_520 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_520).car) = (Id_Form)(fieldname));
(((* _sharp_pair_520).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_519;
({_sharp_pair_519;
(_sharp_pair_519 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_519).car) = expression);
(((* _sharp_pair_519).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_519);
})
);
((List__O__Form__C____type__type ) _sharp_pair_520);
})
);
((List__O__Form__C____type__type ) _sharp_pair_521);
})
);
((List__O__Form__C____type__type ) _sharp_pair_522);
})
);
((List__O__Form__C____type__type ) _sharp_pair_523);
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
struct struct0x080b27c8 *_sharp_pair_525;
({_sharp_pair_525;
(_sharp_pair_525 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_525).car) = (Id_Form)(fsymb));
(((* _sharp_pair_525).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_524;
({_sharp_pair_524;
(_sharp_pair_524 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_524).car) = any);
(((* _sharp_pair_524).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_524);
})
);
((List__O__Form__C____type__type ) _sharp_pair_525);
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
struct struct0x080b27c8 *_sharp_pair_526;
({_sharp_pair_526;
(_sharp_pair_526 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_526).car) = type);
(((* _sharp_pair_526).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_526);
})
;});})):
(({((List__O__Form__C____type__type ) 0);})));
})
);
({(Compound_Form)(intern( "let"), ({
struct struct0x080b27c8 *_sharp_pair_527;
({_sharp_pair_527;
(_sharp_pair_527 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_527).car) = id);
(((* _sharp_pair_527).cdr) = typel);
((List__O__Form__C____type__type ) _sharp_pair_527);
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
struct struct0x080b27c8 *_sharp_pair_528;
({_sharp_pair_528;
(_sharp_pair_528 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_528).car) = exp2);
(((* _sharp_pair_528).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_528);
})
;});})):
(({((List__O__Form__C____type__type ) 0);})));
})
);
({(Compound_Form)(intern( "if"), ({
struct struct0x080b27c8 *_sharp_pair_530;
({_sharp_pair_530;
(_sharp_pair_530 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_530).car) = cond);
(((* _sharp_pair_530).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_529;
({_sharp_pair_529;
(_sharp_pair_529 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_529).car) = exp);
(((* _sharp_pair_529).cdr) = elsel);
((List__O__Form__C____type__type ) _sharp_pair_529);
})
);
((List__O__Form__C____type__type ) _sharp_pair_530);
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
struct struct0x080b27c8 *_sharp_pair_531;
({_sharp_pair_531;
(_sharp_pair_531 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_531).car) = exp);
(((* _sharp_pair_531).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_531);
})
);});});
})
;}

Form__type  _l__parse__Macro__while_like(Symbol__type  symb)
{
return ({
Form__type body;
Form__type cond;
({(parse_symbol)(((String__type) &__string_57));
(cond = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_58));
(body = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "while"), ({
struct struct0x080b27c8 *_sharp_pair_533;
({_sharp_pair_533;
(_sharp_pair_533 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_533).car) = cond);
(((* _sharp_pair_533).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_532;
({_sharp_pair_532;
(_sharp_pair_532 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_532).car) = body);
(((* _sharp_pair_532).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_532);
})
);
((List__O__Form__C____type__type ) _sharp_pair_533);
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
(({(parse_symbol)(((String__type) &__string_59));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@seq"), ({
struct struct0x080b27c8 *_sharp_pair_535;
({_sharp_pair_535;
(_sharp_pair_535 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_535).car) = (Compound_Form)(intern( "@set_continue"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_535).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_534;
({_sharp_pair_534;
(_sharp_pair_534 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_534).car) = exp);
(((* _sharp_pair_534).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_534);
})
);
((List__O__Form__C____type__type ) _sharp_pair_535);
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
({(parse_symbol)(((String__type) &__string_60));
(var = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_61));
(collect = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_62));
(body = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "foreach"), ({
struct struct0x080b27c8 *_sharp_pair_538;
({_sharp_pair_538;
(_sharp_pair_538 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_538).car) = var);
(((* _sharp_pair_538).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_537;
({_sharp_pair_537;
(_sharp_pair_537 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_537).car) = collect);
(((* _sharp_pair_537).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_536;
({_sharp_pair_536;
(_sharp_pair_536 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_536).car) = body);
(((* _sharp_pair_536).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_536);
})
);
((List__O__Form__C____type__type ) _sharp_pair_537);
})
);
((List__O__Form__C____type__type ) _sharp_pair_538);
})
);});});
})
;}

Form__type  _l__parse__Macro__cast(Symbol__type  symb)
{
return ({
Form__type exp;
Form__type type;
({(parse_symbol)(((String__type) &__string_63));
(type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_64));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_65));
({(Compound_Form)(intern( "cast"), ({
struct struct0x080b27c8 *_sharp_pair_540;
({_sharp_pair_540;
(_sharp_pair_540 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_540).car) = type);
(((* _sharp_pair_540).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_539;
({_sharp_pair_539;
(_sharp_pair_539 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_539).car) = exp);
(((* _sharp_pair_539).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_539);
})
);
((List__O__Form__C____type__type ) _sharp_pair_540);
})
);});});
})
;}

Form__type  _l__parse__Macro__Form(Symbol__type  symb)
{
return ({
Form__type exp;
({(parse_symbol)(((String__type) &__string_66));
(exp = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_67));
({(Compound_Form)(intern( "Form"), ({
struct struct0x080b27c8 *_sharp_pair_541;
({_sharp_pair_541;
(_sharp_pair_541 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_541).car) = exp);
(((* _sharp_pair_541).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_541);
})
);});});
})
;}

Form__type  _l__parse__Macro__XML(Symbol__type  fsymb)
{
return ({
Form__type form;
({(parse_symbol)(((String__type) &__string_68));
(form = (_l__parse__XML_Parser__Content)());
(parse_symbol)(((String__type) &__string_69));
({(Compound_Form)(intern( "XML"), ({
struct struct0x080b27c8 *_sharp_pair_542;
({_sharp_pair_542;
(_sharp_pair_542 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_542).car) = form);
(((* _sharp_pair_542).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_542);
})
);});});
})
;}

Form__type  _l__parse__Type__Base_Type(void)
{
return ({
void **_sharp_make_list_ptr551;
void **_sharp_make_list_ptr545;
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
(parse_symbol)(((String__type) &__string_70));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list544;
({_sharp_make_list544;
_sharp_make_list_ptr545;
(_sharp_make_list_ptr545 = ((void *) (&_sharp_make_list544)));
({({_sharp__sharp_loop546_begin548:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop546_end547;});}})
;
({(lab_type = (_l__parse__Type__Labeled_Type)());
(parse_symbol)(((String__type) &__string_71));
({({((* _sharp_make_list_ptr545) = (alloc_cons_cell)());
(((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr545))).car) = ((void *) lab_type));
(_sharp_make_list_ptr545 = (&((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr545))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop546_begin548;});});
_sharp__sharp_loop546_end547:;});
((* _sharp_make_list_ptr545) = ((void *) 0));
_sharp_make_list544;});
})
);
(parse_symbol)(((String__type) &__string_72));
({(Compound_Form)(intern( "struct"), form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_73));
(form_list2 = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list550;
({_sharp_make_list550;
_sharp_make_list_ptr551;
(_sharp_make_list_ptr551 = ((void *) (&_sharp_make_list550)));
({({_sharp__sharp_loop552_begin554:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop552_end553;});}})
;
({(parse_symbol)(((String__type) &__string_74));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr551) = (alloc_cons_cell)());
(((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr551))).car) = ((void *) arg));
(_sharp_make_list_ptr551 = (&((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr551))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop552_begin554;});});
_sharp__sharp_loop552_end553:;});
((* _sharp_make_list_ptr551) = ((void *) 0));
_sharp_make_list550;});
})
);
(arg_list = ({({
struct struct0x080b27c8 *_sharp_pair_555;
({_sharp_pair_555;
(_sharp_pair_555 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_555).car) = arg1);
(((* _sharp_pair_555).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_555);
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
void **_sharp_make_list_ptr558;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
List__O__Form__C____type__type form_list;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_75));
(form_list = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({(arg1 = (_l__parse__Type__Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list557;
({_sharp_make_list557;
_sharp_make_list_ptr558;
(_sharp_make_list_ptr558 = ((void *) (&_sharp_make_list557)));
({({_sharp__sharp_loop559_begin561:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop559_end560;});}})
;
({(parse_symbol)(((String__type) &__string_76));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr558) = (alloc_cons_cell)());
(((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr558))).car) = ((void *) arg));
(_sharp_make_list_ptr558 = (&((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr558))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop559_begin561;});});
_sharp__sharp_loop559_end560:;});
((* _sharp_make_list_ptr558) = ((void *) 0));
_sharp_make_list557;});
})
);
(arg_list = ({({
struct struct0x080b27c8 *_sharp_pair_562;
({_sharp_pair_562;
(_sharp_pair_562 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_562).car) = arg1);
(((* _sharp_pair_562).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_562);
})
;}));});}})
;
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_77));
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
({({_sharp__sharp_loop565_begin567:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop565_end566;});}})
;
({(parse_symbol)(((String__type) &__string_78));
(form = ({(Compound_Form)(intern( "*"), ({
struct struct0x080b27c8 *_sharp_pair_564;
({_sharp_pair_564;
(_sharp_pair_564 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_564).car) = form);
(((* _sharp_pair_564).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_564);
})
);}));});
})
;
({goto _sharp__sharp_loop565_begin567;});});
_sharp__sharp_loop565_end566:;});
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
({(id = (parse_symbol)(((String__type) &__string_79)));
(form2 = (_l__parse__Type__Function_Type)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_569;
({_sharp_pair_569;
(_sharp_pair_569 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_569).car) = form);
(((* _sharp_pair_569).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_568;
({_sharp_pair_568;
(_sharp_pair_568 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_568).car) = form2);
(((* _sharp_pair_568).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_568);
})
);
((List__O__Form__C____type__type ) _sharp_pair_569);
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
struct struct0x080b27c8 *_sharp_pair_571;
({_sharp_pair_571;
(_sharp_pair_571 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_571).car) = idf);
(((* _sharp_pair_571).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_570;
({_sharp_pair_570;
(_sharp_pair_570 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_570).car) = type);
(((* _sharp_pair_570).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_570);
})
);
((List__O__Form__C____type__type ) _sharp_pair_571);
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
(({(parse_symbol)(((String__type) &__string_80));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_81));
({(Compound_Form)(id, form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_82));
(exp = (_l__parse__Code__Maybe_Expression)());
({(Compound_Form)(intern( "@label"), ({
struct struct0x080b27c8 *_sharp_pair_573;
({_sharp_pair_573;
(_sharp_pair_573 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_573).car) = (Id_Form)(id));
(((* _sharp_pair_573).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_572;
({_sharp_pair_572;
(_sharp_pair_572 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_572).car) = exp);
(((* _sharp_pair_572).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_572);
})
);
((List__O__Form__C____type__type ) _sharp_pair_573);
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
((parse_symbol)(((String__type) &__string_83))):
((parse_symbol)(((String__type) &__string_84))));
})
);
(__rep_exp = (_l__parse__Code__Sequence)());
(parse_symbol)(((String__type) &__string_85));
({(Compound_Form)(__rep_symb, ({
struct struct0x080b27c8 *_sharp_pair_574;
({_sharp_pair_574;
(_sharp_pair_574 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_574).car) = __rep_exp);
(((* _sharp_pair_574).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_574);
})
);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_86));
(expl = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_87));
({(((((expl == ((List__O__Form__C____type__type ) 0)))||((((* ((struct struct0x0805f010 *) expl)).tail) != ((List__O__Form__C____type__type ) 0)))))?
((Compound_Form)(intern( "tuple"), expl)):
(((* ((struct struct0x0805f010 *) expl)).head)));});})):
(({(parse_symbol)(((String__type) &__string_88));
(seq = (_l__parse__Code__Maybe_Empty_Sequence)());
(parse_symbol)(((String__type) &__string_89));
({(Compound_Form)(intern( "@block"), ({
struct struct0x080b27c8 *_sharp_pair_575;
({_sharp_pair_575;
(_sharp_pair_575 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_575).car) = seq);
(((* _sharp_pair_575).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_575);
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
({({_sharp__sharp_loop582_begin584:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((((new_peek_char)(0) == 46))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop582_end583;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_90));
(form2 = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_91));
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x080b27c8 *_sharp_pair_578;
({_sharp_pair_578;
(_sharp_pair_578 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_578).car) = form);
(((* _sharp_pair_578).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_577;
({_sharp_pair_577;
(_sharp_pair_577 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_577).car) = form2);
(((* _sharp_pair_577).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_577);
})
);
((List__O__Form__C____type__type ) _sharp_pair_578);
})
);}));})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 46))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_92));
(id = (_l__parse__Lexical__Id)());
(form = ({(Compound_Form)(intern( "[]"), ({
struct struct0x080b27c8 *_sharp_pair_580;
({_sharp_pair_580;
(_sharp_pair_580 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_580).car) = form);
(((* _sharp_pair_580).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_579;
({_sharp_pair_579;
(_sharp_pair_579 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_579).car) = (Symbol_Form)(id));
(((* _sharp_pair_579).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_579);
})
);
((List__O__Form__C____type__type ) _sharp_pair_580);
})
);}));})):
(({(parse_symbol)(((String__type) &__string_93));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_94));
(form = ({(Compound_Form)(intern( "@funcall"), ({
struct struct0x080b27c8 *_sharp_pair_581;
({_sharp_pair_581;
(_sharp_pair_581 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_581).car) = form);
(((* _sharp_pair_581).cdr) = form_list);
((List__O__Form__C____type__type ) _sharp_pair_581);
})
);}));})));
})
));
})
;
})
;
({goto _sharp__sharp_loop582_begin584;});});
_sharp__sharp_loop582_end583:;});
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
(({(parse_symbol)(((String__type) &__string_95));
({intern( "@unary_minus");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_96));
({intern( "@get_label");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_97));
({intern( "@ref");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_98));
({intern( "@deref");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 45))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_99));
({intern( "@pre_--");});})):
(({(parse_symbol)(((String__type) &__string_100));
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
struct struct0x080b27c8 *_sharp_pair_585;
({_sharp_pair_585;
(_sharp_pair_585 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_585).car) = form);
(((* _sharp_pair_585).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_585);
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
({({_sharp__sharp_loop589_begin591:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop589_end590;});}})
;
({(id = (parse_symbol)(((String__type) &__string_101)));
(form2 = (_l__parse__Code__Unary_Operator)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_588;
({_sharp_pair_588;
(_sharp_pair_588 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_588).car) = form);
(((* _sharp_pair_588).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_587;
({_sharp_pair_587;
(_sharp_pair_587 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_587).car) = form2);
(((* _sharp_pair_587).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_587);
})
);
((List__O__Form__C____type__type ) _sharp_pair_588);
})
);}));});
})
;
({goto _sharp__sharp_loop589_begin591;});});
_sharp__sharp_loop589_end590:;});
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
({({_sharp__sharp_loop595_begin597:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop595_end596;});}})
;
({(id = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_102))):
((parse_symbol)(((String__type) &__string_103))));
})
);
(form2 = (_l__parse__Code__Multiplicative)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_594;
({_sharp_pair_594;
(_sharp_pair_594 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_594).car) = form);
(((* _sharp_pair_594).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_593;
({_sharp_pair_593;
(_sharp_pair_593 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_593).car) = form2);
(((* _sharp_pair_593).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_593);
})
);
((List__O__Form__C____type__type ) _sharp_pair_594);
})
);}));});
})
;
({goto _sharp__sharp_loop595_begin597;});});
_sharp__sharp_loop595_end596:;});
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
({({_sharp__sharp_loop601_begin603:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 62))||(((((new_peek_char)(1) == 60))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop601_end602;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_104))):
((parse_symbol)(((String__type) &__string_105))));
})
);
(form2 = (_l__parse__Code__Additive)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_600;
({_sharp_pair_600;
(_sharp_pair_600 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_600).car) = form);
(((* _sharp_pair_600).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_599;
({_sharp_pair_599;
(_sharp_pair_599 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_599).car) = form2);
(((* _sharp_pair_599).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_599);
})
);
((List__O__Form__C____type__type ) _sharp_pair_600);
})
);}));});
})
;
({goto _sharp__sharp_loop601_begin603;});});
_sharp__sharp_loop601_end602:;});
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
({({_sharp__sharp_loop607_begin609:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop607_end608;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_106))):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_107))):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_108))):
((parse_symbol)(((String__type) &__string_109))));
})
));
})
));
})
);
(form2 = (_l__parse__Code__Shift)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_606;
({_sharp_pair_606;
(_sharp_pair_606 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_606).car) = form);
(((* _sharp_pair_606).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_605;
({_sharp_pair_605;
(_sharp_pair_605 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Equality(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Relational)());
({({_sharp__sharp_loop613_begin615:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((((new_peek_char)(0) == 33))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 61))||(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop613_end614;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_110))):
((parse_symbol)(((String__type) &__string_111))));
})
);
(form2 = (_l__parse__Code__Relational)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_612;
({_sharp_pair_612;
(_sharp_pair_612 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_612).car) = form);
(((* _sharp_pair_612).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_611;
({_sharp_pair_611;
(_sharp_pair_611 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Bitwise_And(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Equality)());
({({_sharp__sharp_loop619_begin621:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop619_end620;});}})
;
({(id = (parse_symbol)(((String__type) &__string_112)));
(form2 = (_l__parse__Code__Equality)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_618;
({_sharp_pair_618;
(_sharp_pair_618 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_618).car) = form);
(((* _sharp_pair_618).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_617;
({_sharp_pair_617;
(_sharp_pair_617 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Bitwise_Xor(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Bitwise_And)());
({({_sharp__sharp_loop625_begin627:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 94))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop625_end626;});}})
;
({(id = (parse_symbol)(((String__type) &__string_113)));
(form2 = (_l__parse__Code__Bitwise_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_624;
({_sharp_pair_624;
(_sharp_pair_624 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_624).car) = form);
(((* _sharp_pair_624).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_623;
({_sharp_pair_623;
(_sharp_pair_623 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Bitwise_Ior(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Bitwise_Xor)());
({({_sharp__sharp_loop631_begin633:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop631_end632;});}})
;
({(id = (parse_symbol)(((String__type) &__string_114)));
(form2 = (_l__parse__Code__Bitwise_Xor)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_630;
({_sharp_pair_630;
(_sharp_pair_630 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_630).car) = form);
(((* _sharp_pair_630).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_629;
({_sharp_pair_629;
(_sharp_pair_629 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Logical_And(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Bitwise_Ior)());
({({_sharp__sharp_loop637_begin639:;
({
({if( (!(((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 97))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 110))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 100))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop637_end638;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_115));
({intern( "@and");});}));
(form2 = (_l__parse__Code__Bitwise_Ior)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_636;
({_sharp_pair_636;
(_sharp_pair_636 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_636).car) = form);
(((* _sharp_pair_636).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_635;
({_sharp_pair_635;
(_sharp_pair_635 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
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

Form__type  _l__parse__Code__Logical_Or(void)
{
return ({
Form__type form2;
Symbol__type id;
Form__type form;
({(form = (_l__parse__Code__Logical_And)());
({({_sharp__sharp_loop643_begin645:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 111))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 114))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop643_end644;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_116));
({intern( "@or");});}));
(form2 = (_l__parse__Code__Logical_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_642;
({_sharp_pair_642;
(_sharp_pair_642 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_642).car) = form);
(((* _sharp_pair_642).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_641;
({_sharp_pair_641;
(_sharp_pair_641 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
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
({(id = (parse_symbol)(((String__type) &__string_117)));
(form2 = (_l__parse__Code__Assignment)());
(form = ({(Compound_Form)(id, ({
struct struct0x080b27c8 *_sharp_pair_647;
({_sharp_pair_647;
(_sharp_pair_647 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_647).car) = form);
(((* _sharp_pair_647).cdr) = ({
struct struct0x080b27c8 *_sharp_pair_646;
({_sharp_pair_646;
(_sharp_pair_646 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_646).car) = form2);
(((* _sharp_pair_646).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_646);
})
);
((List__O__Form__C____type__type ) _sharp_pair_647);
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
void **_sharp_make_list_ptr649;
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
List__O__Form__C____type__type _sharp_make_list648;
({_sharp_make_list648;
_sharp_make_list_ptr649;
(_sharp_make_list_ptr649 = ((void *) (&_sharp_make_list648)));
({({_sharp__sharp_loop650_begin652:;
({
({(parse_symbol)(((String__type) &__string_118));
(exp2 = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))?
((_l__parse__Code__Expression)()):
(({tup;})));
})
);
({({((* _sharp_make_list_ptr649) = (alloc_cons_cell)());
(((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr649))).car) = ((void *) exp2));
(_sharp_make_list_ptr649 = (&((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr649))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop650_end651;});}})
;
})
;
({goto _sharp__sharp_loop650_begin652;});});
_sharp__sharp_loop650_end651:;});
((* _sharp_make_list_ptr649) = ((void *) 0));
_sharp_make_list648;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x080b27c8 *_sharp_pair_653;
({_sharp_pair_653;
(_sharp_pair_653 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_653).car) = exp);
(((* _sharp_pair_653).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_653);
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
void **_sharp_make_list_ptr655;
Form__type exp2;
List__O__Form__C____type__type exp_list;
Form__type exp;
({(exp = (_l__parse__Code__Expression)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))?
(({(exp_list = ({
List__O__Form__C____type__type _sharp_make_list654;
({_sharp_make_list654;
_sharp_make_list_ptr655;
(_sharp_make_list_ptr655 = ((void *) (&_sharp_make_list654)));
({({_sharp__sharp_loop656_begin658:;
({
({(parse_symbol)(((String__type) &__string_119));
(exp2 = (_l__parse__Code__Expression)());
({({((* _sharp_make_list_ptr655) = (alloc_cons_cell)());
(((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr655))).car) = ((void *) exp2));
(_sharp_make_list_ptr655 = (&((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr655))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop656_end657;});}})
;
})
;
({goto _sharp__sharp_loop656_begin658;});});
_sharp__sharp_loop656_end657:;});
((* _sharp_make_list_ptr655) = ((void *) 0));
_sharp_make_list654;});
})
);
({(Compound_Form)(intern( "@seq"), ({
struct struct0x080b27c8 *_sharp_pair_659;
({_sharp_pair_659;
(_sharp_pair_659 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_659).car) = exp);
(((* _sharp_pair_659).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_659);
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
void **_sharp_make_list_ptr662;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))))))))
{
({(arg1 = (_l__parse__Code__Non_Empty_Sequence)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list661;
({_sharp_make_list661;
_sharp_make_list_ptr662;
(_sharp_make_list_ptr662 = ((void *) (&_sharp_make_list661)));
({({_sharp__sharp_loop663_begin665:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop663_end664;});}})
;
({(parse_symbol)(((String__type) &__string_120));
(arg = (_l__parse__Code__Non_Empty_Sequence)());
({({((* _sharp_make_list_ptr662) = (alloc_cons_cell)());
(((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr662))).car) = ((void *) arg));
(_sharp_make_list_ptr662 = (&((* (* ((struct struct0x08642378 **) _sharp_make_list_ptr662))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop663_begin665;});});
_sharp__sharp_loop663_end664:;});
((* _sharp_make_list_ptr662) = ((void *) 0));
_sharp_make_list661;});
})
);
(arg_list = ({({
struct struct0x080b27c8 *_sharp_pair_666;
({_sharp_pair_666;
(_sharp_pair_666 = ((struct struct0x080b27c8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_666).car) = arg1);
(((* _sharp_pair_666).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_666);
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
({({_sharp__sharp_loop668_begin670:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop668_end669;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop668_begin670;});});
_sharp__sharp_loop668_end669:;});
({(read_char)();});});
})
;}

void  _l__parse__Lexical__Spacing(void)
{
return ({
({({_sharp__sharp_loop672_begin674:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop672_end673;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__Lexical__Comment)()));
})
;
})
;
({goto _sharp__sharp_loop672_begin674;});});
_sharp__sharp_loop672_end673:;});
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
({({_sharp__sharp_loop676_begin678:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop676_end677;});}})
;
({(d = (_l__parse__Lexical__Digit)());
({({
({(n = ((int) n * (int) 10));
(n = ((int) n + (int) d));});
})
;});});
})
;
({goto _sharp__sharp_loop676_begin678;});});
_sharp__sharp_loop676_end677:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Hexadecimal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop680_begin682:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 102))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop680_end681;});}})
;
({(d = (_l__parse__Lexical__Hexa_Digit)());
({({
({(n = ((int) n * (int) 16));
(n = ((int) n + (int) d));});
})
;});});
})
;
({goto _sharp__sharp_loop680_begin682;});});
_sharp__sharp_loop680_end681:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Octal_Number_End(void)
{
return ({
Int__type n;
Int__type d;
({(n = ({0;}));
({({_sharp__sharp_loop684_begin686:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 55))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop684_end685;});}})
;
({(d = (_l__parse__Lexical__Octal_Digit)());
({({
({(n = ((int) n * (int) 8));
(n = ((int) n + (int) d));});
})
;});});
})
;
({goto _sharp__sharp_loop684_begin686;});});
_sharp__sharp_loop684_end685:;});
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
({({_sharp__sharp_loop688_begin690:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop688_end689;});}})
;
(_l__parse__Lexical__Alpha_Num)();
})
;
({goto _sharp__sharp_loop688_begin690;});});
_sharp__sharp_loop688_end689:;});
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
({({_sharp__sharp_loop692_begin694:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop692_end693;});}})
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
({goto _sharp__sharp_loop692_begin694;});});
_sharp__sharp_loop692_end693:;});
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
({({_sharp__sharp_loop696_begin701:;
({
({(read_char)();
({({_sharp__sharp_loop698_begin700:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 35))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 33))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop698_end699;});}})
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
({goto _sharp__sharp_loop698_begin700;});});
_sharp__sharp_loop698_end699:;});
(end = (get_point_pos)());
(read_char)();
(_l__parse__Lexical__Spacing)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop696_end697;});}})
;
})
;
({goto _sharp__sharp_loop696_begin701;});});
_sharp__sharp_loop696_end697:;});
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
