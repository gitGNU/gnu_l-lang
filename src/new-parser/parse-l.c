/* Automatically generated : do not edit!*/
#include "parse-l.inc"
Hash__O__Symbol__c__pointer__O__function__O__Form__c__tuple__O__Symbol__C____C____C____C____type__type parse_top_level_hash;

Hash__O__Symbol__c__pointer__O__function__O__Form__c__tuple__O__Symbol__C____C____C____C____type__type parse_macro_hash;

void  init__parse_l(void)
{
return ({
(parse_macro_hash = ((Hash__O__Symbol__c__pointer__O__function__O__Form__c__tuple__O__Symbol__C____C____C____C____type__type ) (make_hash_table)()));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "let")), ((void *) (&_l__parse__Macro__let)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "if")), ((void *) (&_l__parse__Macro__if)), ((Hash_Table__type ) parse_macro_hash)));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "loop")), ((void *) (&_l__parse__Macro__loop)), ((Hash_Table__type ) parse_macro_hash)));
(parse_top_level_hash = ((Hash__O__Symbol__c__pointer__O__function__O__Form__c__tuple__O__Symbol__C____C____C____C____type__type ) (make_hash_table)()));
((Form__type (*)(Symbol__type )) (puthash)(((void *) intern( "function")), ((void *) (&_l__parse__Top_Level__function)), ((Hash_Table__type ) parse_top_level_hash)));
((void) 0);
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
({(print_String)(((String__type) &__string_11));
(print_String)(((String__type) &__string_12));
(print_Symbol)(id);
(print_String)(((String__type) &__string_13));
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
void **_sharp_make_list_ptr431;
Form__type body;
Form__type ret_type;
List__O__Form__C____type__type params;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
Symbol__type name;
({(name = (_l__parse__Lexical__Id)());
(parse_symbol)(((String__type) &__string_14));
(params = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))
{
({(arg1 = (_l__parse__Type__Labeled_Type)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list430;
({_sharp_make_list430;
_sharp_make_list_ptr431;
(_sharp_make_list_ptr431 = ((void *) (&_sharp_make_list430)));
({({_sharp__sharp_loop432_begin434:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop432_end433;});}})
;
({(parse_symbol)(((String__type) &__string_15));
(arg = (_l__parse__Type__Labeled_Type)());
({({((* _sharp_make_list_ptr431) = (alloc_cons_cell)());
(((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr431))).car) = ((void *) arg));
(_sharp_make_list_ptr431 = (&((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr431))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop432_begin434;});});
_sharp__sharp_loop432_end433:;});
((* _sharp_make_list_ptr431) = ((void *) 0));
_sharp_make_list430;});
})
);
(arg_list = ({({
struct struct0x08067248 *_sharp_pair_435;
({_sharp_pair_435;
(_sharp_pair_435 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_435).car) = arg1);
(((* _sharp_pair_435).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_435);
})
;}));});}})
;
})
;
({arg_list;});}));
(parse_symbol)(((String__type) &__string_16));
(parse_symbol)(((String__type) &__string_17));
(ret_type = (_l__parse__Type__Type)());
(parse_symbol)(((String__type) &__string_18));
(body = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_19));
({(Compound_Form)(intern( "define"), ({
struct struct0x08067248 *_sharp_pair_443;
({_sharp_pair_443;
(_sharp_pair_443 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_443).car) = (Id_Form)(fsymb));
(((* _sharp_pair_443).cdr) = ({
struct struct0x08067248 *_sharp_pair_442;
({_sharp_pair_442;
(_sharp_pair_442 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_442).car) = (Compound_Form)(intern( ":"), ({
struct struct0x08067248 *_sharp_pair_441;
({_sharp_pair_441;
(_sharp_pair_441 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_441).car) = (Id_Form)(name));
(((* _sharp_pair_441).cdr) = ({
struct struct0x08067248 *_sharp_pair_440;
({_sharp_pair_440;
(_sharp_pair_440 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_440).car) = (Compound_Form)(intern( "lambda"), ({
struct struct0x08067248 *_sharp_pair_439;
({_sharp_pair_439;
(_sharp_pair_439 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_439).car) = (Compound_Form)(intern( "->"), ({
struct struct0x08067248 *_sharp_pair_437;
({_sharp_pair_437;
(_sharp_pair_437 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_437).car) = (Compound_Form)(intern( "@tuple"), params));
(((* _sharp_pair_437).cdr) = ({
struct struct0x08067248 *_sharp_pair_436;
({_sharp_pair_436;
(_sharp_pair_436 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_436).car) = ret_type);
(((* _sharp_pair_436).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_436);
})
);
((List__O__Form__C____type__type ) _sharp_pair_437);
})
));
(((* _sharp_pair_439).cdr) = ({
struct struct0x08067248 *_sharp_pair_438;
({_sharp_pair_438;
(_sharp_pair_438 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_438).car) = body);
(((* _sharp_pair_438).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_438);
})
);
((List__O__Form__C____type__type ) _sharp_pair_439);
})
));
(((* _sharp_pair_440).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_440);
})
);
((List__O__Form__C____type__type ) _sharp_pair_441);
})
));
(((* _sharp_pair_442).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_442);
})
);
((List__O__Form__C____type__type ) _sharp_pair_443);
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
struct struct0x08067248 *_sharp_pair_445;
({_sharp_pair_445;
(_sharp_pair_445 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_445).car) = (Id_Form)(fsymb));
(((* _sharp_pair_445).cdr) = ({
struct struct0x08067248 *_sharp_pair_444;
({_sharp_pair_444;
(_sharp_pair_444 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_444).car) = ltype);
(((* _sharp_pair_444).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_444);
})
);
((List__O__Form__C____type__type ) _sharp_pair_445);
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
(typel = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))
{
({({(read_char)();});
(type = (_l__parse__Type__Type)());
(typel = ({({
struct struct0x08067248 *_sharp_pair_446;
({_sharp_pair_446;
(_sharp_pair_446 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_446).car) = type);
(((* _sharp_pair_446).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_446);
})
;}));});}})
;
})
;
({(Compound_Form)(intern( "let"), ({
struct struct0x08067248 *_sharp_pair_447;
({_sharp_pair_447;
(_sharp_pair_447 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_447).car) = id);
(((* _sharp_pair_447).cdr) = typel);
((List__O__Form__C____type__type ) _sharp_pair_447);
})
);});});
})
;}

Form__type  _l__parse__Macro__if(Symbol__type  symb)
{
return ({
Form__type exp2;
Form__type cond;
Form__type exp;
({(parse_symbol)(((String__type) &__string_20));
(cond = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_21));
(exp = (_l__parse__Code__Expression)());
(exp2 = ({
((((((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 101))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 108))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 115))||(((Bool__type ) 0))))))&&(((((new_peek_char)(3) == 101))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_22));
(_l__parse__Code__Expression)();})):
(({(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0));})));
})
);
({(Compound_Form)(intern( "if"), ({
struct struct0x08067248 *_sharp_pair_450;
({_sharp_pair_450;
(_sharp_pair_450 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_450).car) = cond);
(((* _sharp_pair_450).cdr) = ({
struct struct0x08067248 *_sharp_pair_449;
({_sharp_pair_449;
(_sharp_pair_449 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_449).car) = exp);
(((* _sharp_pair_449).cdr) = ({
struct struct0x08067248 *_sharp_pair_448;
({_sharp_pair_448;
(_sharp_pair_448 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_448).car) = exp2);
(((* _sharp_pair_448).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_448);
})
);
((List__O__Form__C____type__type ) _sharp_pair_449);
})
);
((List__O__Form__C____type__type ) _sharp_pair_450);
})
);});});
})
;}

Form__type  _l__parse__Macro__loop(Symbol__type  symb)
{
return ({
Form__type exp;
({(exp = (_l__parse__Code__Expression)());
({(Compound_Form)(symb, ({
struct struct0x08067248 *_sharp_pair_451;
({_sharp_pair_451;
(_sharp_pair_451 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_451).car) = exp);
(((* _sharp_pair_451).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_451);
})
);});});
})
;}

Form__type  _l__parse__Type__Base_Type(void)
{
return ({
void **_sharp_make_list_ptr460;
void **_sharp_make_list_ptr454;
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
(parse_symbol)(((String__type) &__string_23));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list453;
({_sharp_make_list453;
_sharp_make_list_ptr454;
(_sharp_make_list_ptr454 = ((void *) (&_sharp_make_list453)));
({({_sharp__sharp_loop455_begin457:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop455_end456;});}})
;
({(lab_type = (_l__parse__Type__Labeled_Type)());
(parse_symbol)(((String__type) &__string_24));
({({((* _sharp_make_list_ptr454) = (alloc_cons_cell)());
(((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr454))).car) = ((void *) lab_type));
(_sharp_make_list_ptr454 = (&((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr454))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop455_begin457;});});
_sharp__sharp_loop455_end456:;});
((* _sharp_make_list_ptr454) = ((void *) 0));
_sharp_make_list453;});
})
);
(parse_symbol)(((String__type) &__string_25));
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
List__O__Form__C____type__type _sharp_make_list459;
({_sharp_make_list459;
_sharp_make_list_ptr460;
(_sharp_make_list_ptr460 = ((void *) (&_sharp_make_list459)));
({({_sharp__sharp_loop461_begin463:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop461_end462;});}})
;
({(parse_symbol)(((String__type) &__string_26));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr460) = (alloc_cons_cell)());
(((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr460))).car) = ((void *) arg));
(_sharp_make_list_ptr460 = (&((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr460))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop461_begin463;});});
_sharp__sharp_loop461_end462:;});
((* _sharp_make_list_ptr460) = ((void *) 0));
_sharp_make_list459;});
})
);
(arg_list = ({({
struct struct0x08067248 *_sharp_pair_464;
({_sharp_pair_464;
(_sharp_pair_464 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_464).car) = arg1);
(((* _sharp_pair_464).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_464);
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
void **_sharp_make_list_ptr467;
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
List__O__Form__C____type__type _sharp_make_list466;
({_sharp_make_list466;
_sharp_make_list_ptr467;
(_sharp_make_list_ptr467 = ((void *) (&_sharp_make_list466)));
({({_sharp__sharp_loop468_begin470:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop468_end469;});}})
;
({(parse_symbol)(((String__type) &__string_27));
(arg = (_l__parse__Type__Type)());
({({((* _sharp_make_list_ptr467) = (alloc_cons_cell)());
(((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr467))).car) = ((void *) arg));
(_sharp_make_list_ptr467 = (&((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr467))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop468_begin470;});});
_sharp__sharp_loop468_end469:;});
((* _sharp_make_list_ptr467) = ((void *) 0));
_sharp_make_list466;});
})
);
(arg_list = ({({
struct struct0x08067248 *_sharp_pair_471;
({_sharp_pair_471;
(_sharp_pair_471 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_471).car) = arg1);
(((* _sharp_pair_471).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_471);
})
;}));});}})
;
})
;
({arg_list;});}));
({(read_char)();});
({(Compound_Form)(intern( "@tuple"), form_list);});})):
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
({({_sharp__sharp_loop474_begin476:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop474_end475;});}})
;
({(parse_symbol)(((String__type) &__string_28));
(form = ({(Compound_Form)(intern( "*"), ({
struct struct0x08067248 *_sharp_pair_473;
({_sharp_pair_473;
(_sharp_pair_473 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_473).car) = form);
(((* _sharp_pair_473).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_473);
})
);}));});
})
;
({goto _sharp__sharp_loop474_begin476;});});
_sharp__sharp_loop474_end475:;});
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
({(id = (parse_symbol)(((String__type) &__string_29)));
(form2 = (_l__parse__Type__Function_Type)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_478;
({_sharp_pair_478;
(_sharp_pair_478 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_478).car) = form);
(((* _sharp_pair_478).cdr) = ({
struct struct0x08067248 *_sharp_pair_477;
({_sharp_pair_477;
(_sharp_pair_477 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_477).car) = form2);
(((* _sharp_pair_477).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_477);
})
);
((List__O__Form__C____type__type ) _sharp_pair_478);
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
struct struct0x08067248 *_sharp_pair_480;
({_sharp_pair_480;
(_sharp_pair_480 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_480).car) = idf);
(((* _sharp_pair_480).cdr) = ({
struct struct0x08067248 *_sharp_pair_479;
({_sharp_pair_479;
(_sharp_pair_479 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_479).car) = type);
(((* _sharp_pair_479).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_479);
})
);
((List__O__Form__C____type__type ) _sharp_pair_480);
})
);});});
})
;}

Form__type  _l__parse__Code__Primary(void)
{
return ({
List__O__Form__C____type__type expl;
Form__type (*funptr)(Symbol__type );
Symbol__type id;
Form__type form;
Form__type exp;
List__O__Form__C____type__type form_list;
List__O__Form__C____type__type seq;
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
(({(parse_symbol)(((String__type) &__string_30));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_31));
({(Compound_Form)(id, form_list);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_32));
(exp = (_l__parse__Code__Expression)());
({(Compound_Form)(intern( "@label"), ({
struct struct0x08067248 *_sharp_pair_482;
({_sharp_pair_482;
(_sharp_pair_482 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_482).car) = (Id_Form)(id));
(((* _sharp_pair_482).cdr) = ({
struct struct0x08067248 *_sharp_pair_481;
({_sharp_pair_481;
(_sharp_pair_481 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_481).car) = exp);
(((* _sharp_pair_481).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_481);
})
);
((List__O__Form__C____type__type ) _sharp_pair_482);
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
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_33));
(expl = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_34));
({(((((expl == ((List__O__Form__C____type__type ) 0)))||((((* ((struct struct0x0805f088 *) expl)).tail) != ((List__O__Form__C____type__type ) 0)))))?
((Compound_Form)(intern( "@tuple"), expl)):
(((* ((struct struct0x0805f088 *) expl)).head)));});})):
(({(parse_symbol)(((String__type) &__string_35));
(seq = (_l__parse__Code__Sequence_List)());
(parse_symbol)(((String__type) &__string_36));
({(Compound_Form)(intern( "@block"), seq);});})));
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
({
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((((new_peek_char)(0) == 46))||(((((new_peek_char)(0) == 40))||(((Bool__type ) 0))))))))))
{
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_37));
(form2 = (_l__parse__Code__Expression)());
(parse_symbol)(((String__type) &__string_38));
(form = ({(Compound_Form)(intern( "@access"), ({
struct struct0x08067248 *_sharp_pair_484;
({_sharp_pair_484;
(_sharp_pair_484 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_484).car) = form);
(((* _sharp_pair_484).cdr) = ({
struct struct0x08067248 *_sharp_pair_483;
({_sharp_pair_483;
(_sharp_pair_483 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_483).car) = form2);
(((* _sharp_pair_483).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_483);
})
);
((List__O__Form__C____type__type ) _sharp_pair_484);
})
);}));})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 46))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_39));
(id = (_l__parse__Lexical__Id)());
(form = ({(Compound_Form)(intern( "@access"), ({
struct struct0x08067248 *_sharp_pair_486;
({_sharp_pair_486;
(_sharp_pair_486 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_486).car) = form);
(((* _sharp_pair_486).cdr) = ({
struct struct0x08067248 *_sharp_pair_485;
({_sharp_pair_485;
(_sharp_pair_485 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_485).car) = (Symbol_Form)(id));
(((* _sharp_pair_485).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_485);
})
);
((List__O__Form__C____type__type ) _sharp_pair_486);
})
);}));})):
(({(parse_symbol)(((String__type) &__string_40));
(form_list = (_l__parse__Code__Expression_List)());
(parse_symbol)(((String__type) &__string_41));
(form = ({(Compound_Form)(intern( "@funcall"), ({
struct struct0x08067248 *_sharp_pair_487;
({_sharp_pair_487;
(_sharp_pair_487 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_487).car) = form);
(((* _sharp_pair_487).cdr) = form_list);
((List__O__Form__C____type__type ) _sharp_pair_487);
})
);}));})));
})
));
})
;}})
;
})
;
({form;});});
})
;}

Form__type  _l__parse__Code__Unary_Operator(void)
{
return ({
Symbol__type op;
Form__type form;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))))))))))?
(({(op = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_42));
({intern( "@unary_minus");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_43));
({intern( "@ref");});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_44));
({intern( "@deref");});})):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 45))||(((Bool__type ) 0))))))?
(({(parse_symbol)(((String__type) &__string_45));
({intern( "@pre_--");});})):
(({(parse_symbol)(((String__type) &__string_46));
({intern( "@pre_++");});})));
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
struct struct0x08067248 *_sharp_pair_488;
({_sharp_pair_488;
(_sharp_pair_488 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_488).car) = form);
(((* _sharp_pair_488).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_488);
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
({({_sharp__sharp_loop492_begin494:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop492_end493;});}})
;
({(id = (parse_symbol)(((String__type) &__string_47)));
(form2 = (_l__parse__Code__Unary_Operator)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_491;
({_sharp_pair_491;
(_sharp_pair_491 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_491).car) = form);
(((* _sharp_pair_491).cdr) = ({
struct struct0x08067248 *_sharp_pair_490;
({_sharp_pair_490;
(_sharp_pair_490 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_490).car) = form2);
(((* _sharp_pair_490).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_490);
})
);
((List__O__Form__C____type__type ) _sharp_pair_491);
})
);}));});
})
;
({goto _sharp__sharp_loop492_begin494;});});
_sharp__sharp_loop492_end493:;});
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
({({_sharp__sharp_loop498_begin500:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop498_end499;});}})
;
({(id = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 43))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_48))):
((parse_symbol)(((String__type) &__string_49))));
})
);
(form2 = (_l__parse__Code__Multiplicative)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_497;
({_sharp_pair_497;
(_sharp_pair_497 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_497).car) = form);
(((* _sharp_pair_497).cdr) = ({
struct struct0x08067248 *_sharp_pair_496;
({_sharp_pair_496;
(_sharp_pair_496 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_496).car) = form2);
(((* _sharp_pair_496).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_496);
})
);
((List__O__Form__C____type__type ) _sharp_pair_497);
})
);}));});
})
;
({goto _sharp__sharp_loop498_begin500;});});
_sharp__sharp_loop498_end499:;});
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
({({_sharp__sharp_loop504_begin506:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))&&(((((new_peek_char)(1) == 62))||(((((new_peek_char)(1) == 60))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop504_end505;});}})
;
({(id = ({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_50))):
((parse_symbol)(((String__type) &__string_51))));
})
);
(form2 = (_l__parse__Code__Additive)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_503;
({_sharp_pair_503;
(_sharp_pair_503 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_503).car) = form);
(((* _sharp_pair_503).cdr) = ({
struct struct0x08067248 *_sharp_pair_502;
({_sharp_pair_502;
(_sharp_pair_502 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_502).car) = form2);
(((* _sharp_pair_502).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_502);
})
);
((List__O__Form__C____type__type ) _sharp_pair_503);
})
);}));});
})
;
({goto _sharp__sharp_loop504_begin506;});});
_sharp__sharp_loop504_end505:;});
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
({({_sharp__sharp_loop510_begin512:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 62))||(((((new_peek_char)(0) == 60))||(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop510_end511;});}})
;
({(id = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_52))):
(({
((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_53))):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_54))):
((parse_symbol)(((String__type) &__string_55))));
})
));
})
));
})
);
(form2 = (_l__parse__Code__Shift)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_509;
({_sharp_pair_509;
(_sharp_pair_509 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_509).car) = form);
(((* _sharp_pair_509).cdr) = ({
struct struct0x08067248 *_sharp_pair_508;
({_sharp_pair_508;
(_sharp_pair_508 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_508).car) = form2);
(((* _sharp_pair_508).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_508);
})
);
((List__O__Form__C____type__type ) _sharp_pair_509);
})
);}));});
})
;
({goto _sharp__sharp_loop510_begin512;});});
_sharp__sharp_loop510_end511:;});
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
({({_sharp__sharp_loop516_begin518:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 61))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 61))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop516_end517;});}})
;
({(id = (parse_symbol)(((String__type) &__string_56)));
(form2 = (_l__parse__Code__Relational)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_515;
({_sharp_pair_515;
(_sharp_pair_515 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_515).car) = form);
(((* _sharp_pair_515).cdr) = ({
struct struct0x08067248 *_sharp_pair_514;
({_sharp_pair_514;
(_sharp_pair_514 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_514).car) = form2);
(((* _sharp_pair_514).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_514);
})
);
((List__O__Form__C____type__type ) _sharp_pair_515);
})
);}));});
})
;
({goto _sharp__sharp_loop516_begin518;});});
_sharp__sharp_loop516_end517:;});
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
({({_sharp__sharp_loop522_begin524:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop522_end523;});}})
;
({(id = (parse_symbol)(((String__type) &__string_57)));
(form2 = (_l__parse__Code__Equality)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_521;
({_sharp_pair_521;
(_sharp_pair_521 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_521).car) = form);
(((* _sharp_pair_521).cdr) = ({
struct struct0x08067248 *_sharp_pair_520;
({_sharp_pair_520;
(_sharp_pair_520 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_520).car) = form2);
(((* _sharp_pair_520).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_520);
})
);
((List__O__Form__C____type__type ) _sharp_pair_521);
})
);}));});
})
;
({goto _sharp__sharp_loop522_begin524;});});
_sharp__sharp_loop522_end523:;});
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
({({_sharp__sharp_loop528_begin530:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 94))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop528_end529;});}})
;
({(id = (parse_symbol)(((String__type) &__string_58)));
(form2 = (_l__parse__Code__Bitwise_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_527;
({_sharp_pair_527;
(_sharp_pair_527 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_527).car) = form);
(((* _sharp_pair_527).cdr) = ({
struct struct0x08067248 *_sharp_pair_526;
({_sharp_pair_526;
(_sharp_pair_526 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_526).car) = form2);
(((* _sharp_pair_526).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_526);
})
);
((List__O__Form__C____type__type ) _sharp_pair_527);
})
);}));});
})
;
({goto _sharp__sharp_loop528_begin530;});});
_sharp__sharp_loop528_end529:;});
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
({({_sharp__sharp_loop534_begin536:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop534_end535;});}})
;
({(id = (parse_symbol)(((String__type) &__string_59)));
(form2 = (_l__parse__Code__Bitwise_Xor)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_533;
({_sharp_pair_533;
(_sharp_pair_533 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_533).car) = form);
(((* _sharp_pair_533).cdr) = ({
struct struct0x08067248 *_sharp_pair_532;
({_sharp_pair_532;
(_sharp_pair_532 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_532).car) = form2);
(((* _sharp_pair_532).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_532);
})
);
((List__O__Form__C____type__type ) _sharp_pair_533);
})
);}));});
})
;
({goto _sharp__sharp_loop534_begin536;});});
_sharp__sharp_loop534_end535:;});
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
({({_sharp__sharp_loop540_begin542:;
({
({if( (!(((((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 97))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 110))||(((Bool__type ) 0))))))&&(((((new_peek_char)(2) == 100))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop540_end541;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_60));
({intern( "@and");});}));
(form2 = (_l__parse__Code__Bitwise_Ior)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_539;
({_sharp_pair_539;
(_sharp_pair_539 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_539).car) = form);
(((* _sharp_pair_539).cdr) = ({
struct struct0x08067248 *_sharp_pair_538;
({_sharp_pair_538;
(_sharp_pair_538 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_538).car) = form2);
(((* _sharp_pair_538).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_538);
})
);
((List__O__Form__C____type__type ) _sharp_pair_539);
})
);}));});
})
;
({goto _sharp__sharp_loop540_begin542;});});
_sharp__sharp_loop540_end541:;});
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
({({_sharp__sharp_loop546_begin548:;
({
({if( (!(((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 111))||(((Bool__type ) 0))))))&&(((((new_peek_char)(1) == 114))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop546_end547;});}})
;
({(id = ({(parse_symbol)(((String__type) &__string_61));
({intern( "@or");});}));
(form2 = (_l__parse__Code__Logical_And)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_545;
({_sharp_pair_545;
(_sharp_pair_545 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_545).car) = form);
(((* _sharp_pair_545).cdr) = ({
struct struct0x08067248 *_sharp_pair_544;
({_sharp_pair_544;
(_sharp_pair_544 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_544).car) = form2);
(((* _sharp_pair_544).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_544);
})
);
((List__O__Form__C____type__type ) _sharp_pair_545);
})
);}));});
})
;
({goto _sharp__sharp_loop546_begin548;});});
_sharp__sharp_loop546_end547:;});
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
({(id = (parse_symbol)(((String__type) &__string_62)));
(form2 = (_l__parse__Code__Assignment)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_550;
({_sharp_pair_550;
(_sharp_pair_550 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_550).car) = form);
(((* _sharp_pair_550).cdr) = ({
struct struct0x08067248 *_sharp_pair_549;
({_sharp_pair_549;
(_sharp_pair_549 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_549).car) = form2);
(((* _sharp_pair_549).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_549);
})
);
((List__O__Form__C____type__type ) _sharp_pair_550);
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

List__O__Form__C____type__type  _l__parse__Code__Sequence_List(void)
{
return ({
void **_sharp_make_list_ptr553;
Form__type e;
List__O__Form__C____type__type exp_list;
Form__type tup;
Form__type exp;
({(tup = ({(Compound_Form)(intern( "@tuple"), ((List__O__Form__C____type__type ) 0));}));
(exp = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))?
((_l__parse__Code__Expression)()):
(({tup;})));
})
);
(exp_list = ({
List__O__Form__C____type__type _sharp_make_list552;
({_sharp_make_list552;
_sharp_make_list_ptr553;
(_sharp_make_list_ptr553 = ((void *) (&_sharp_make_list552)));
({({_sharp__sharp_loop554_begin556:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 59))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop554_end555;});}})
;
({(parse_symbol)(((String__type) &__string_63));
(e = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((((new_peek_char)(0) == 48))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 45))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))))))?
((_l__parse__Code__Expression)()):
(({tup;})));
})
);
({({((* _sharp_make_list_ptr553) = (alloc_cons_cell)());
(((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr553))).car) = ((void *) e));
(_sharp_make_list_ptr553 = (&((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr553))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop554_begin556;});});
_sharp__sharp_loop554_end555:;});
((* _sharp_make_list_ptr553) = ((void *) 0));
_sharp_make_list552;});
})
);
({({
struct struct0x08067248 *_sharp_pair_557;
({_sharp_pair_557;
(_sharp_pair_557 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_557).car) = exp);
(((* _sharp_pair_557).cdr) = exp_list);
((List__O__Form__C____type__type ) _sharp_pair_557);
})
;});});
})
;}

Form__type  _l__parse__Code__Sequence(void)
{
return ({
List__O__Form__C____type__type sl;
({(sl = (_l__parse__Code__Sequence_List)());
({(((((* ((struct struct0x0805f088 *) sl)).tail) != ((List__O__Form__C____type__type ) 0)))?
((Compound_Form)(intern( "@seq"), sl)):
(((* ((struct struct0x0805f088 *) sl)).head)));});});
})
;}

List__O__Form__C____type__type  _l__parse__Code__Expression_List(void)
{
return ({
void **_sharp_make_list_ptr560;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((Bool__type ) 1))
{
({(arg1 = (_l__parse__Code__Sequence)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list559;
({_sharp_make_list559;
_sharp_make_list_ptr560;
(_sharp_make_list_ptr560 = ((void *) (&_sharp_make_list559)));
({({_sharp__sharp_loop561_begin563:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop561_end562;});}})
;
({(parse_symbol)(((String__type) &__string_64));
(arg = (_l__parse__Code__Sequence)());
({({((* _sharp_make_list_ptr560) = (alloc_cons_cell)());
(((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr560))).car) = ((void *) arg));
(_sharp_make_list_ptr560 = (&((* (* ((struct struct0x085cc0f8 **) _sharp_make_list_ptr560))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop561_begin563;});});
_sharp__sharp_loop561_end562:;});
((* _sharp_make_list_ptr560) = ((void *) 0));
_sharp_make_list559;});
})
);
(arg_list = ({({
struct struct0x08067248 *_sharp_pair_564;
({_sharp_pair_564;
(_sharp_pair_564 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_564).car) = arg1);
(((* _sharp_pair_564).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_564);
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
({({_sharp__sharp_loop566_begin568:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop566_end567;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop566_begin568;});});
_sharp__sharp_loop566_end567:;});
({(read_char)();});});
})
;}

void  _l__parse__Lexical__Spacing(void)
{
return ({
({({_sharp__sharp_loop570_begin572:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop570_end571;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__Lexical__Comment)()));
})
;
})
;
({goto _sharp__sharp_loop570_begin572;});});
_sharp__sharp_loop570_end571:;});
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

Int__type  _l__parse__Lexical__Hexa_Digit(void)
{
return ({
Int__type d;
({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))?
((_l__parse__Lexical__Digit)()):
(({(d = (read_char)());
({((int) d - (int) 97);});})));
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
({({_sharp__sharp_loop574_begin576:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop574_end575;});}})
;
({(d = (_l__parse__Lexical__Digit)());
({({
(n = ((int) n * (int) 10));
(n = ((int) n + (int) d));
})
;});});
})
;
({goto _sharp__sharp_loop574_begin576;});});
_sharp__sharp_loop574_end575:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Hexadecimal_Number(void)
{
return ({
Int__type n;
Int__type d;
({({(read_char)();
(read_char)();});
(n = ({0;}));
({({_sharp__sharp_loop578_begin580:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 102))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop578_end579;});}})
;
({(d = (_l__parse__Lexical__Hexa_Digit)());
({({
(n = ((int) n * (int) 16));
(n = ((int) n + (int) d));
})
;});});
})
;
({goto _sharp__sharp_loop578_begin580;});});
_sharp__sharp_loop578_end579:;});
({n;});});
})
;}

Int__type  _l__parse__Lexical__Number(void)
{
return ({
({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 49))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))?
((_l__parse__Lexical__Decimal_Number)()):
((_l__parse__Lexical__Hexadecimal_Number)()));
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
({({_sharp__sharp_loop582_begin584:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop582_end583;});}})
;
(_l__parse__Lexical__Alpha_Num)();
})
;
({goto _sharp__sharp_loop582_begin584;});});
_sharp__sharp_loop582_end583:;});
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
({({_sharp__sharp_loop586_begin588:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop586_end587;});}})
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
({goto _sharp__sharp_loop586_begin588;});});
_sharp__sharp_loop586_end587:;});
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
({({_sharp__sharp_loop590_begin595:;
({
({(read_char)();
({({_sharp__sharp_loop592_begin594:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop592_end593;});}})
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
({goto _sharp__sharp_loop592_begin594;});});
_sharp__sharp_loop592_end593:;});
(end = (get_point_pos)());
(read_char)();
(_l__parse__Lexical__Spacing)();});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop590_end591;});}})
;
})
;
({goto _sharp__sharp_loop590_begin595;});});
_sharp__sharp_loop590_end591:;});
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
