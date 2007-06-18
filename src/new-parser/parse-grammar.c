/* Automatically generated : do not edit!*/
#include "parse-grammar.inc"
Int__type  _l__parse__parse_grammar__Comment(void)
{
return ({
({({(read_char)();
(read_char)();});
({({_sharp__sharp_loop795_begin797:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop795_end796;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop795_begin797;});});
_sharp__sharp_loop795_end796:;});
({(read_char)();});});
})
;}

void  _l__parse__parse_grammar__Spacing(void)
{
return ({
({({_sharp__sharp_loop799_begin801:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop799_end800;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__parse_grammar__Comment)()));
})
;
})
;
({goto _sharp__sharp_loop799_begin801;});});
_sharp__sharp_loop799_end800:;});
})
;}

Int__type  _l__parse__parse_grammar__Alpha(void)
{
return ({
(read_char)();
})
;}

Int__type  _l__parse__parse_grammar__Alpha_Num(void)
{
return ({
(read_char)();
})
;}

Symbol__type  _l__parse__parse_grammar__Identifier(void)
{
return ({
Int__type start;
Int__type end;
({(start = (get_point_pos)());
(_l__parse__parse_grammar__Alpha)();
({({_sharp__sharp_loop803_begin805:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop803_end804;});}})
;
(_l__parse__parse_grammar__Alpha_Num)();
})
;
({goto _sharp__sharp_loop803_begin805;});});
_sharp__sharp_loop803_end804:;});
(end = (get_point_pos)());
({(intern_string)((substring)(start, end));});});
})
;}

Int__type  _l__parse__parse_grammar__Escaped_Character(void)
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

Int__type  _l__parse__parse_grammar__Maybe_Escaped_Character(void)
{
return ({
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 92))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((read_char)()));
})
;
})
;}

Int__type  _l__parse__parse_grammar__Maybe_Escaped_Character_Character_Range(void)
{
return ({
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 92))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((read_char)()));
})
;
})
;}

Form__type  _l__parse__parse_grammar__String(void)
{
return ({
Int__type start;
Int__type end;
({(read_char)();
(start = (get_point_pos)());
({({_sharp__sharp_loop807_begin809:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 35))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 33))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop807_end808;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 92))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((read_char)()));
})
;
})
;
({goto _sharp__sharp_loop807_begin809;});});
_sharp__sharp_loop807_end808:;});
(end = (get_point_pos)());
(read_char)();
({(String_Form)((substring)(start, end));});});
})
;}

Form__type  _l__parse__parse_grammar__Symbol(void)
{
return ({
Int__type start;
Int__type end;
({(read_char)();
(start = (get_point_pos)());
({({_sharp__sharp_loop811_begin813:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop811_end812;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 92))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((read_char)()));
})
;
})
;
({goto _sharp__sharp_loop811_begin813;});});
_sharp__sharp_loop811_end812:;});
(end = (get_point_pos)());
(read_char)();
({(Symbol_Form)((intern_string)((substring)(start, end)));});});
})
;}

Form__type  _l__parse__parse_grammar__Character_Range(void)
{
return ({
Int__type max;
Int__type min;
({(min = (_l__parse__parse_grammar__Maybe_Escaped_Character_Character_Range)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 45))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(max = (_l__parse__parse_grammar__Maybe_Escaped_Character)());
({(Compound_Form)(intern( "-"), ({
struct struct0x08067248 *_sharp_pair_815;
({_sharp_pair_815;
(_sharp_pair_815 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_815).car) = (Int_Form)(min));
(((* _sharp_pair_815).cdr) = ({
struct struct0x08067248 *_sharp_pair_814;
({_sharp_pair_814;
(_sharp_pair_814 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_814).car) = (Int_Form)(max));
(((* _sharp_pair_814).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_814);
})
);
((List__O__Form__C____type__type ) _sharp_pair_815);
})
);});})):
(({(Int_Form)(min);})));
})
;});
})
;}

Form__type  _l__parse__parse_grammar__Character_Set(void)
{
return ({
void **_sharp_make_list_ptr818;
Symbol__type char_selector;
Form__type cr;
List__O__Form__C____type__type cr_list;
({({(read_char)();});
(char_selector = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 94))||(((Bool__type ) 0))))))?
(({({(read_char)();});
({intern( "[^]");});})):
(({intern( "[]");})));
})
);
(cr_list = ({
List__O__Form__C____type__type _sharp_make_list817;
({_sharp_make_list817;
_sharp_make_list_ptr818;
(_sharp_make_list_ptr818 = ((void *) (&_sharp_make_list817)));
({({_sharp__sharp_loop819_begin821:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 94))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 92))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop819_end820;});}})
;
({(cr = (_l__parse__parse_grammar__Character_Range)());
({({((* _sharp_make_list_ptr818) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr818))).car) = ((void *) cr));
(_sharp_make_list_ptr818 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr818))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop819_begin821;});});
_sharp__sharp_loop819_end820:;});
((* _sharp_make_list_ptr818) = ((void *) 0));
_sharp_make_list817;});
})
);
({(read_char)();});
({(Compound_Form)(char_selector, cr_list);});});
})
;}

Form__type  _l__parse__parse_grammar__Callable_Rule_or_Binding(void)
{
return ({
Symbol__type id2;
Symbol__type id;
Form__type form2;
Form__type form;
({(id = (_l__parse__parse_grammar__Identifier)());
(form = ({(Id_Form)(id);}));
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 46))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(id2 = (_l__parse__parse_grammar__Identifier)());
({(Compound_Form)(intern( "."), ({
struct struct0x08067248 *_sharp_pair_823;
({_sharp_pair_823;
(_sharp_pair_823 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_823).car) = form);
(((* _sharp_pair_823).cdr) = ({
struct struct0x08067248 *_sharp_pair_822;
({_sharp_pair_822;
(_sharp_pair_822 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_822).car) = (Id_Form)(id2));
(((* _sharp_pair_822).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_822);
})
);
((List__O__Form__C____type__type ) _sharp_pair_823);
})
);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(form2 = (_l__parse__parse_grammar__Postfix)());
({(Compound_Form)(intern( ":"), ({
struct struct0x08067248 *_sharp_pair_825;
({_sharp_pair_825;
(_sharp_pair_825 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_825).car) = form);
(((* _sharp_pair_825).cdr) = ({
struct struct0x08067248 *_sharp_pair_824;
({_sharp_pair_824;
(_sharp_pair_824 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_824).car) = form2);
(((* _sharp_pair_824).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_824);
})
);
((List__O__Form__C____type__type ) _sharp_pair_825);
})
);});})):
(({form;})));
})
));
})
;});
})
;}

Form__type  _l__parse__parse_grammar__Semantic_Action(void)
{
return ({
Form__type exp;
({({(read_char)();});
(exp = (_l__parse__parse_grammar__Expression)());
({(read_char)();});
({(Compound_Form)(intern( "{}"), ({
struct struct0x08067248 *_sharp_pair_826;
({_sharp_pair_826;
(_sharp_pair_826 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_826).car) = exp);
(((* _sharp_pair_826).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_826);
})
);});});
})
;}

Form__type  _l__parse__parse_grammar__Semantic_Predicate(void)
{
return ({
Form__type form;
({({(read_char)();});
(form = (_l__parse__parse_grammar__Primary)());
({(Compound_Form)(intern( "&"), ({
struct struct0x08067248 *_sharp_pair_827;
({_sharp_pair_827;
(_sharp_pair_827 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_827).car) = form);
(((* _sharp_pair_827).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_827);
})
);});});
})
;}

Form__type  _l__parse__parse_grammar__Rule_Macro(void)
{
return ({
void **_sharp_make_list_ptr830;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
Symbol__type id;
List__O__Form__C____type__type form_list;
({({(read_char)();});
(id = (_l__parse__parse_grammar__Identifier)());
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
(form_list = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((new_peek_char)(0) == 91))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 64))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))
{
({(arg1 = (_l__parse__parse_grammar__Rule)());
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list829;
({_sharp_make_list829;
_sharp_make_list_ptr830;
(_sharp_make_list_ptr830 = ((void *) (&_sharp_make_list829)));
({({_sharp__sharp_loop831_begin833:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop831_end832;});}})
;
({({({(read_char)();});
(_l__parse__parse_grammar__Spacing)();});
(arg = (_l__parse__parse_grammar__Rule)());
({({((* _sharp_make_list_ptr830) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr830))).car) = ((void *) arg));
(_sharp_make_list_ptr830 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr830))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop831_begin833;});});
_sharp__sharp_loop831_end832:;});
((* _sharp_make_list_ptr830) = ((void *) 0));
_sharp_make_list829;});
})
);
(arg_list = ({({
struct struct0x08067248 *_sharp_pair_834;
({_sharp_pair_834;
(_sharp_pair_834 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_834).car) = arg1);
(((* _sharp_pair_834).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_834);
})
;}));});}})
;
})
;
({arg_list;});}));
({(read_char)();});
({(Compound_Form)(intern( "@"), ({
struct struct0x08067248 *_sharp_pair_835;
({_sharp_pair_835;
(_sharp_pair_835 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_835).car) = (Compound_Form)(id, form_list));
(((* _sharp_pair_835).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_835);
})
);});});
})
;}

Form__type  _l__parse__parse_grammar__Replacement(void)
{
return ({
Form__type exp;
({({(read_char)();});
(exp = (_l__parse__parse_grammar__Expression)());
({(read_char)();});
({(Compound_Form)(intern( "$"), ({
struct struct0x08067248 *_sharp_pair_836;
({_sharp_pair_836;
(_sharp_pair_836 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_836).car) = exp);
(((* _sharp_pair_836).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_836);
})
);});});
})
;}

Form__type  _l__parse__parse_grammar__Primary(void)
{
return ({
Form__type r;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__String)()):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 39))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Symbol)()):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 91))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Character_Set)()):
(({
((((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))?
((_l__parse__parse_grammar__Callable_Rule_or_Binding)()):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Semantic_Action)()):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 38))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Semantic_Predicate)()):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 64))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Rule_Macro)()):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 36))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Replacement)()):
(({({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
(r = (_l__parse__parse_grammar__Rule)());
({(read_char)();});
({r;});})));
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
));
})
));
})
;
})
;}

Form__type  _l__parse__parse_grammar__Postfix(void)
{
return ({
Symbol__type op;
Form__type form;
({(form = (_l__parse__parse_grammar__Primary)());
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 63))||(((((new_peek_char)(0) == 43))||(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))))))?
(({(op = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 63))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_16))):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_17))):
((parse_symbol)(((String__type) &__string_18))));
})
));
})
);
({(Compound_Form)(op, ({
struct struct0x08067248 *_sharp_pair_837;
({_sharp_pair_837;
(_sharp_pair_837 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_837).car) = form);
(((* _sharp_pair_837).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_837);
})
);});})):
(({form;})));
})
;});
})
;}

Form__type  _l__parse__parse_grammar__Sequence(void)
{
return ({
void **_sharp_make_list_ptr839;
Form__type post;
List__O__Form__C____type__type post_list;
({(post_list = ({
List__O__Form__C____type__type _sharp_make_list838;
({_sharp_make_list838;
_sharp_make_list_ptr839;
(_sharp_make_list_ptr839 = ((void *) (&_sharp_make_list838)));
({({_sharp__sharp_loop840_begin842:;
({
({(post = (_l__parse__parse_grammar__Postfix)());
(_l__parse__parse_grammar__Spacing)();
({({((* _sharp_make_list_ptr839) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr839))).car) = ((void *) post));
(_sharp_make_list_ptr839 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr839))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((new_peek_char)(0) == 91))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 64))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))
{
({goto _sharp__sharp_loop840_end841;});}})
;
})
;
({goto _sharp__sharp_loop840_begin842;});});
_sharp__sharp_loop840_end841:;});
((* _sharp_make_list_ptr839) = ((void *) 0));
_sharp_make_list838;});
})
);
({(((((* ((struct struct0x0805f088 *) post_list)).tail) == ((List__O__Form__C____type__type ) 0)))?
(((* ((struct struct0x0805f088 *) post_list)).head)):
((Compound_Form)(intern( " "), post_list)));});});
})
;}

Form__type  _l__parse__parse_grammar__Alternative(void)
{
return ({
Symbol__type id;
Form__type form2;
Form__type form;
({(form = (_l__parse__parse_grammar__Sequence)());
({
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))
{
({(id = ({({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
({intern( "|");});}));
(form2 = (_l__parse__parse_grammar__Alternative)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067248 *_sharp_pair_844;
({_sharp_pair_844;
(_sharp_pair_844 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_844).car) = form);
(((* _sharp_pair_844).cdr) = ({
struct struct0x08067248 *_sharp_pair_843;
({_sharp_pair_843;
(_sharp_pair_843 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_843).car) = form2);
(((* _sharp_pair_843).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_843);
})
);
((List__O__Form__C____type__type ) _sharp_pair_844);
})
);}));});}})
;
})
;
({form;});});
})
;}

Form__type  _l__parse__parse_grammar__Rule(void)
{
return ({
(_l__parse__parse_grammar__Alternative)();
})
;}

Form__type  _l__parse__parse_grammar__Grammar_Rule(void)
{
return ({
void **_sharp_make_list_ptr851;
Form__type ret_type;
Symbol__type param;
Form__type r;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
Symbol__type id;
List__O__Form__C____type__type form_list;
Form__type type;
({({(read_char)();
(read_char)();
(read_char)();
(read_char)();});
(_l__parse__parse_grammar__Spacing)();
(id = (_l__parse__parse_grammar__Identifier)());
(form_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 60))||(((Bool__type ) 0))))))
{
({({(read_char)();});
(form_list = ({(arg_list = ({((List__O__Form__C____type__type ) 0);}));
({
({if( ((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((Bool__type ) 0))))))))))
{
({(arg1 = ({(param = (_l__parse__parse_grammar__Identifier)());
({(read_char)();});
(type = (_l__parse__parse_grammar__Type)());
({(Compound_Form)(intern( "label"), ({
struct struct0x08067248 *_sharp_pair_846;
({_sharp_pair_846;
(_sharp_pair_846 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_846).car) = (Id_Form)(param));
(((* _sharp_pair_846).cdr) = ({
struct struct0x08067248 *_sharp_pair_845;
({_sharp_pair_845;
(_sharp_pair_845 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_845).car) = type);
(((* _sharp_pair_845).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_845);
})
);
((List__O__Form__C____type__type ) _sharp_pair_846);
})
);});}));
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list850;
({_sharp_make_list850;
_sharp_make_list_ptr851;
(_sharp_make_list_ptr851 = ((void *) (&_sharp_make_list850)));
({({_sharp__sharp_loop852_begin854:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop852_end853;});}})
;
({(parse_symbol)(((String__type) &__string_19));
(arg = ({(param = (_l__parse__parse_grammar__Identifier)());
({(read_char)();});
(type = (_l__parse__parse_grammar__Type)());
({(Compound_Form)(intern( "label"), ({
struct struct0x08067248 *_sharp_pair_849;
({_sharp_pair_849;
(_sharp_pair_849 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_849).car) = (Id_Form)(param));
(((* _sharp_pair_849).cdr) = ({
struct struct0x08067248 *_sharp_pair_848;
({_sharp_pair_848;
(_sharp_pair_848 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_848).car) = type);
(((* _sharp_pair_848).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_848);
})
);
((List__O__Form__C____type__type ) _sharp_pair_849);
})
);});}));
({({((* _sharp_make_list_ptr851) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr851))).car) = ((void *) arg));
(_sharp_make_list_ptr851 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr851))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop852_begin854;});});
_sharp__sharp_loop852_end853:;});
((* _sharp_make_list_ptr851) = ((void *) 0));
_sharp_make_list850;});
})
);
(arg_list = ({({
struct struct0x08067248 *_sharp_pair_855;
({_sharp_pair_855;
(_sharp_pair_855 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_855).car) = arg1);
(((* _sharp_pair_855).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_855);
})
;}));});}})
;
})
;
({arg_list;});}));
({(read_char)();});});}})
;
})
;
({(read_char)();});
(ret_type = (_l__parse__parse_grammar__Type)());
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
(r = (_l__parse__parse_grammar__Rule)());
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
({(Compound_Form)(intern( "rule"), ({
struct struct0x08067248 *_sharp_pair_859;
({_sharp_pair_859;
(_sharp_pair_859 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_859).car) = (Id_Form)(id));
(((* _sharp_pair_859).cdr) = ({
struct struct0x08067248 *_sharp_pair_858;
({_sharp_pair_858;
(_sharp_pair_858 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_858).car) = ret_type);
(((* _sharp_pair_858).cdr) = ({
struct struct0x08067248 *_sharp_pair_857;
({_sharp_pair_857;
(_sharp_pair_857 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_857).car) = (Compound_Form)(intern( "tuple"), form_list));
(((* _sharp_pair_857).cdr) = ({
struct struct0x08067248 *_sharp_pair_856;
({_sharp_pair_856;
(_sharp_pair_856 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_856).car) = r);
(((* _sharp_pair_856).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_856);
})
);
((List__O__Form__C____type__type ) _sharp_pair_857);
})
);
((List__O__Form__C____type__type ) _sharp_pair_858);
})
);
((List__O__Form__C____type__type ) _sharp_pair_859);
})
);});});
})
;}

Form__type  _l__parse__parse_grammar__Grammar(void)
{
return ({
void **_sharp_make_list_ptr862;
Form__type gr;
List__O__Form__C____type__type gr_list;
Symbol__type id;
({({(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();});
(_l__parse__parse_grammar__Spacing)();
(id = (_l__parse__parse_grammar__Identifier)());
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
(gr_list = ({
List__O__Form__C____type__type _sharp_make_list861;
({_sharp_make_list861;
_sharp_make_list_ptr862;
(_sharp_make_list_ptr862 = ((void *) (&_sharp_make_list861)));
({({_sharp__sharp_loop863_begin865:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 114))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop863_end864;});}})
;
({(gr = (_l__parse__parse_grammar__Grammar_Rule)());
({({((* _sharp_make_list_ptr862) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr862))).car) = ((void *) gr));
(_sharp_make_list_ptr862 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr862))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop863_begin865;});});
_sharp__sharp_loop863_end864:;});
((* _sharp_make_list_ptr862) = ((void *) 0));
_sharp_make_list861;});
})
);
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
({(Compound_Form)(intern( "define"), ({
struct struct0x08067248 *_sharp_pair_867;
({_sharp_pair_867;
(_sharp_pair_867 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_867).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_867).cdr) = ({
struct struct0x08067248 *_sharp_pair_866;
({_sharp_pair_866;
(_sharp_pair_866 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_866).car) = (Id_Form)(id));
(((* _sharp_pair_866).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_866);
})
);
((List__O__Form__C____type__type ) _sharp_pair_867);
})
);});});
})
;}

Form__type  _l__parse__parse_grammar__Grammar_Macro(void)
{
return ({
void **_sharp_make_list_ptr870;
List__O__Form__C____type__type rest_list;
Symbol__type arg;
Symbol__type arg1;
Symbol__type id;
Form__type rule;
List__O__Form__C____type__type form_list;
({({(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();});
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
(id = (_l__parse__parse_grammar__Identifier)());
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
(form_list = ({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 62))||(((Bool__type ) 0))))))?
(({({(read_char)();});
({((List__O__Form__C____type__type ) 0);});})):
(({(arg1 = (_l__parse__parse_grammar__Identifier)());
(_l__parse__parse_grammar__Spacing)();
(rest_list = ({
List__O__Form__C____type__type _sharp_make_list869;
({_sharp_make_list869;
_sharp_make_list_ptr870;
(_sharp_make_list_ptr870 = ((void *) (&_sharp_make_list869)));
({({_sharp__sharp_loop871_begin873:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop871_end872;});}})
;
({(parse_symbol)(((String__type) &__string_20));
(arg = (_l__parse__parse_grammar__Identifier)());
({({((* _sharp_make_list_ptr870) = (alloc_cons_cell)());
(((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr870))).car) = ((void *) (Id_Form)(arg)));
(_sharp_make_list_ptr870 = (&((* (* ((struct struct0x085364e8 **) _sharp_make_list_ptr870))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop871_begin873;});});
_sharp__sharp_loop871_end872:;});
((* _sharp_make_list_ptr870) = ((void *) 0));
_sharp_make_list869;});
})
);
({(read_char)();});
({({
struct struct0x08067248 *_sharp_pair_874;
({_sharp_pair_874;
(_sharp_pair_874 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_874).car) = (Id_Form)(arg1));
(((* _sharp_pair_874).cdr) = rest_list);
((List__O__Form__C____type__type ) _sharp_pair_874);
})
;});})));
})
);
(_l__parse__parse_grammar__Spacing)();
(parse_symbol)(((String__type) &__string_21));
(rule = (_l__parse__parse_grammar__Rule)());
(parse_symbol)(((String__type) &__string_22));
({(Compound_Form)(intern( "define"), ({
struct struct0x08067248 *_sharp_pair_878;
({_sharp_pair_878;
(_sharp_pair_878 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_878).car) = (Id_Form)(intern( "grammar_macro")));
(((* _sharp_pair_878).cdr) = ({
struct struct0x08067248 *_sharp_pair_877;
({_sharp_pair_877;
(_sharp_pair_877 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_877).car) = (Id_Form)(id));
(((* _sharp_pair_877).cdr) = ({
struct struct0x08067248 *_sharp_pair_876;
({_sharp_pair_876;
(_sharp_pair_876 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_876).car) = (Compound_Form)(intern( "tuple"), form_list));
(((* _sharp_pair_876).cdr) = ({
struct struct0x08067248 *_sharp_pair_875;
({_sharp_pair_875;
(_sharp_pair_875 = ((struct struct0x08067248 *) (alloc_cons_cell)()));});
(((* _sharp_pair_875).car) = rule);
(((* _sharp_pair_875).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_875);
})
);
((List__O__Form__C____type__type ) _sharp_pair_876);
})
);
((List__O__Form__C____type__type ) _sharp_pair_877);
})
);
((List__O__Form__C____type__type ) _sharp_pair_878);
})
);});});
})
;}
