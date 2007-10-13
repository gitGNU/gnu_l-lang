/* Automatically generated : do not edit!*/
#include "parse-grammar.inc"

Int__type  _l__parse__parse_grammar__Comment(void)
{
return ({
({({(read_char)();
(read_char)();});
({({_sharp__sharp_loop553_begin555:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 11))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 9))))||(((Bool__type ) 0))))))))))
{
({goto _sharp__sharp_loop553_end554;});}})
;
(read_char)();
})
;
({goto _sharp__sharp_loop553_begin555;});});
_sharp__sharp_loop553_end554:;});
({(read_char)();});});
})
;}

void  _l__parse__parse_grammar__Spacing(void)
{
return ({
({({_sharp__sharp_loop557_begin559:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 47))||(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop557_end558;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 32))||(((((new_peek_char)(0) == 10))||(((((new_peek_char)(0) == 9))||(((Bool__type ) 0))))))))))?
((read_char)()):
((_l__parse__parse_grammar__Comment)()));
})
;
})
;
({goto _sharp__sharp_loop557_begin559;});});
_sharp__sharp_loop557_end558:;});
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
({({_sharp__sharp_loop561_begin563:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((((int) (new_peek_char)(0) >= (int) 48))&&(((int) (new_peek_char)(0) <= (int) 57))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop561_end562;});}})
;
(_l__parse__parse_grammar__Alpha_Num)();
})
;
({goto _sharp__sharp_loop561_begin563;});});
_sharp__sharp_loop561_end562:;});
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
({({_sharp__sharp_loop565_begin567:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 35))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 33))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop565_end566;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 92))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((read_char)()));
})
;
})
;
({goto _sharp__sharp_loop565_begin567;});});
_sharp__sharp_loop565_end566:;});
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
({({_sharp__sharp_loop569_begin571:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 40))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 38))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop569_end570;});}})
;
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 92))||(((Bool__type ) 0))))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((read_char)()));
})
;
})
;
({goto _sharp__sharp_loop569_begin571;});});
_sharp__sharp_loop569_end570:;});
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
struct struct0x08067530 *_sharp_pair_573;
({_sharp_pair_573;
(_sharp_pair_573 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_573).car) = (Int_Form)(min));
(((* _sharp_pair_573).cdr) = ({
struct struct0x08067530 *_sharp_pair_572;
({_sharp_pair_572;
(_sharp_pair_572 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_572).car) = (Int_Form)(max));
(((* _sharp_pair_572).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_572);
})
);
((List__O__Form__C____type__type ) _sharp_pair_573);
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
void **_sharp_make_list_ptr576;
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
List__O__Form__C____type__type _sharp_make_list575;
({_sharp_make_list575;
_sharp_make_list_ptr576;
(_sharp_make_list_ptr576 = ((void *) (&_sharp_make_list575)));
({({_sharp__sharp_loop577_begin579:;
({
({if( (!(((((Bool__type ) 1))&&(((((((int) (new_peek_char)(0) >= (int) 94))&&(((int) (new_peek_char)(0) <= (int) 255))))||(((((((int) (new_peek_char)(0) >= (int) 93))&&(((int) (new_peek_char)(0) <= (int) 92))))||(((((new_peek_char)(0) == 92))||(((((((int) (new_peek_char)(0) >= (int) 0))&&(((int) (new_peek_char)(0) <= (int) 91))))||(((Bool__type ) 0))))))))))))))
{
({goto _sharp__sharp_loop577_end578;});}})
;
({(cr = (_l__parse__parse_grammar__Character_Range)());
({({((* _sharp_make_list_ptr576) = (alloc_cons_cell)());
(((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr576))).car) = ((void *) cr));
(_sharp_make_list_ptr576 = (&((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr576))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop577_begin579;});});
_sharp__sharp_loop577_end578:;});
((* _sharp_make_list_ptr576) = ((void *) 0));
_sharp_make_list575;});
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
Form__type form2;
Form__type form;
Symbol__type id;
({(id = (_l__parse__parse_grammar__Identifier)());
(form = ({(Id_Form)(id);}));
({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 46))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(id2 = (_l__parse__parse_grammar__Identifier)());
({(Compound_Form)(intern( "."), ({
struct struct0x08067530 *_sharp_pair_581;
({_sharp_pair_581;
(_sharp_pair_581 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_581).car) = form);
(((* _sharp_pair_581).cdr) = ({
struct struct0x08067530 *_sharp_pair_580;
({_sharp_pair_580;
(_sharp_pair_580 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_580).car) = (Id_Form)(id2));
(((* _sharp_pair_580).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_580);
})
);
((List__O__Form__C____type__type ) _sharp_pair_581);
})
);});})):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 58))||(((Bool__type ) 0))))))?
(({({(read_char)();});
(form2 = (_l__parse__parse_grammar__Postfix)());
({(Compound_Form)(intern( ":"), ({
struct struct0x08067530 *_sharp_pair_583;
({_sharp_pair_583;
(_sharp_pair_583 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_583).car) = form);
(((* _sharp_pair_583).cdr) = ({
struct struct0x08067530 *_sharp_pair_582;
({_sharp_pair_582;
(_sharp_pair_582 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_582).car) = form2);
(((* _sharp_pair_582).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_582);
})
);
((List__O__Form__C____type__type ) _sharp_pair_583);
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
(_l__parse__parse_grammar__Spacing)();
(exp = (_l__parse__Code__Sequence)());
({(read_char)();});
({(Compound_Form)(intern( "{}"), ({
struct struct0x08067530 *_sharp_pair_584;
({_sharp_pair_584;
(_sharp_pair_584 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_584).car) = exp);
(((* _sharp_pair_584).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_584);
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
struct struct0x08067530 *_sharp_pair_585;
({_sharp_pair_585;
(_sharp_pair_585 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_585).car) = form);
(((* _sharp_pair_585).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_585);
})
);});});
})
;}

Form__type  _l__parse__parse_grammar__Rule_Macro(void)
{
return ({
void **_sharp_make_list_ptr588;
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
List__O__Form__C____type__type _sharp_make_list587;
({_sharp_make_list587;
_sharp_make_list_ptr588;
(_sharp_make_list_ptr588 = ((void *) (&_sharp_make_list587)));
({({_sharp__sharp_loop589_begin591:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop589_end590;});}})
;
({({({(read_char)();});
(_l__parse__parse_grammar__Spacing)();});
(arg = (_l__parse__parse_grammar__Rule)());
({({((* _sharp_make_list_ptr588) = (alloc_cons_cell)());
(((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr588))).car) = ((void *) arg));
(_sharp_make_list_ptr588 = (&((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr588))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop589_begin591;});});
_sharp__sharp_loop589_end590:;});
((* _sharp_make_list_ptr588) = ((void *) 0));
_sharp_make_list587;});
})
);
(arg_list = ({({
struct struct0x08067530 *_sharp_pair_592;
({_sharp_pair_592;
(_sharp_pair_592 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_592).car) = arg1);
(((* _sharp_pair_592).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_592);
})
;}));});}})
;
})
;
({arg_list;});}));
({(read_char)();});
({(Compound_Form)(intern( "@"), ({
struct struct0x08067530 *_sharp_pair_593;
({_sharp_pair_593;
(_sharp_pair_593 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_593).car) = (Compound_Form)(id, form_list));
(((* _sharp_pair_593).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_593);
})
);});});
})
;}

Form__type  _l__parse__parse_grammar__Replacement(void)
{
return ({
Form__type exp;
({({(read_char)();});
(exp = (_l__parse__Code__Sequence)());
({(read_char)();});
({(Compound_Form)(intern( "$"), ({
struct struct0x08067530 *_sharp_pair_594;
({_sharp_pair_594;
(_sharp_pair_594 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_594).car) = exp);
(((* _sharp_pair_594).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_594);
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
((parse_symbol)(((String__type) &__string_5))):
(({
((((((Bool__type ) 1))&&(((((new_peek_char)(0) == 42))||(((Bool__type ) 0))))))?
((parse_symbol)(((String__type) &__string_6))):
((parse_symbol)(((String__type) &__string_7))));
})
));
})
);
({(Compound_Form)(op, ({
struct struct0x08067530 *_sharp_pair_595;
({_sharp_pair_595;
(_sharp_pair_595 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_595).car) = form);
(((* _sharp_pair_595).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_595);
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
void **_sharp_make_list_ptr597;
Form__type post;
List__O__Form__C____type__type post_list;
({(post_list = ({
List__O__Form__C____type__type _sharp_make_list596;
({_sharp_make_list596;
_sharp_make_list_ptr597;
(_sharp_make_list_ptr597 = ((void *) (&_sharp_make_list596)));
({({_sharp__sharp_loop598_begin600:;
({
({(post = (_l__parse__parse_grammar__Postfix)());
(_l__parse__parse_grammar__Spacing)();
({({((* _sharp_make_list_ptr597) = (alloc_cons_cell)());
(((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr597))).car) = ((void *) post));
(_sharp_make_list_ptr597 = (&((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr597))).cdr)));
((void) 0);});});});
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 123))||(((((((int) (new_peek_char)(0) >= (int) 97))&&(((int) (new_peek_char)(0) <= (int) 122))))||(((((new_peek_char)(0) == 95))||(((((new_peek_char)(0) == 91))||(((((((int) (new_peek_char)(0) >= (int) 65))&&(((int) (new_peek_char)(0) <= (int) 90))))||(((((new_peek_char)(0) == 64))||(((((new_peek_char)(0) == 40))||(((((new_peek_char)(0) == 39))||(((((new_peek_char)(0) == 38))||(((((new_peek_char)(0) == 36))||(((((new_peek_char)(0) == 34))||(((Bool__type ) 0))))))))))))))))))))))))))))
{
({goto _sharp__sharp_loop598_end599;});}})
;
})
;
({goto _sharp__sharp_loop598_begin600;});});
_sharp__sharp_loop598_end599:;});
((* _sharp_make_list_ptr597) = ((void *) 0));
_sharp_make_list596;});
})
);
({(((((* ((struct struct0x0805f0d0 *) post_list)).tail) == ((List__O__Form__C____type__type ) 0)))?
(((* ((struct struct0x0805f0d0 *) post_list)).head)):
((Compound_Form)(intern( " "), post_list)));});});
})
;}

Form__type  _l__parse__parse_grammar__Alternative(void)
{
return ({
Form__type form2;
Form__type form;
Symbol__type id;
({(form = (_l__parse__parse_grammar__Sequence)());
({
({if( ((((Bool__type ) 1))&&(((((new_peek_char)(0) == 124))||(((Bool__type ) 0))))))
{
({(id = ({({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
({intern( "|");});}));
(form2 = (_l__parse__parse_grammar__Alternative)());
(form = ({(Compound_Form)(id, ({
struct struct0x08067530 *_sharp_pair_602;
({_sharp_pair_602;
(_sharp_pair_602 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_602).car) = form);
(((* _sharp_pair_602).cdr) = ({
struct struct0x08067530 *_sharp_pair_601;
({_sharp_pair_601;
(_sharp_pair_601 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_601).car) = form2);
(((* _sharp_pair_601).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_601);
})
);
((List__O__Form__C____type__type ) _sharp_pair_602);
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
void **_sharp_make_list_ptr609;
Form__type ret_type;
Symbol__type param;
Form__type r;
Form__type arg;
Form__type arg1;
List__O__Form__C____type__type arg_list;
Symbol__type id;
Form__type type;
List__O__Form__C____type__type form_list;
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
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( "label"), ({
struct struct0x08067530 *_sharp_pair_604;
({_sharp_pair_604;
(_sharp_pair_604 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_604).car) = (Id_Form)(param));
(((* _sharp_pair_604).cdr) = ({
struct struct0x08067530 *_sharp_pair_603;
({_sharp_pair_603;
(_sharp_pair_603 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_603).car) = type);
(((* _sharp_pair_603).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_603);
})
);
((List__O__Form__C____type__type ) _sharp_pair_604);
})
);});}));
(arg_list = ({
List__O__Form__C____type__type _sharp_make_list608;
({_sharp_make_list608;
_sharp_make_list_ptr609;
(_sharp_make_list_ptr609 = ((void *) (&_sharp_make_list608)));
({({_sharp__sharp_loop610_begin612:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop610_end611;});}})
;
({(parse_symbol)(((String__type) &__string_8));
(arg = ({(param = (_l__parse__parse_grammar__Identifier)());
({(read_char)();});
(type = (_l__parse__Type__Type)());
({(Compound_Form)(intern( "label"), ({
struct struct0x08067530 *_sharp_pair_607;
({_sharp_pair_607;
(_sharp_pair_607 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_607).car) = (Id_Form)(param));
(((* _sharp_pair_607).cdr) = ({
struct struct0x08067530 *_sharp_pair_606;
({_sharp_pair_606;
(_sharp_pair_606 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_606).car) = type);
(((* _sharp_pair_606).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_606);
})
);
((List__O__Form__C____type__type ) _sharp_pair_607);
})
);});}));
({({((* _sharp_make_list_ptr609) = (alloc_cons_cell)());
(((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr609))).car) = ((void *) arg));
(_sharp_make_list_ptr609 = (&((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr609))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop610_begin612;});});
_sharp__sharp_loop610_end611:;});
((* _sharp_make_list_ptr609) = ((void *) 0));
_sharp_make_list608;});
})
);
(arg_list = ({({
struct struct0x08067530 *_sharp_pair_613;
({_sharp_pair_613;
(_sharp_pair_613 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_613).car) = arg1);
(((* _sharp_pair_613).cdr) = arg_list);
((List__O__Form__C____type__type ) _sharp_pair_613);
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
(ret_type = (_l__parse__Type__Type)());
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
(r = (_l__parse__parse_grammar__Rule)());
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
({(Compound_Form)(intern( "rule"), ({
struct struct0x08067530 *_sharp_pair_617;
({_sharp_pair_617;
(_sharp_pair_617 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_617).car) = (Id_Form)(id));
(((* _sharp_pair_617).cdr) = ({
struct struct0x08067530 *_sharp_pair_616;
({_sharp_pair_616;
(_sharp_pair_616 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_616).car) = ret_type);
(((* _sharp_pair_616).cdr) = ({
struct struct0x08067530 *_sharp_pair_615;
({_sharp_pair_615;
(_sharp_pair_615 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_615).car) = (Compound_Form)(intern( "tuple"), form_list));
(((* _sharp_pair_615).cdr) = ({
struct struct0x08067530 *_sharp_pair_614;
({_sharp_pair_614;
(_sharp_pair_614 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_614).car) = r);
(((* _sharp_pair_614).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_614);
})
);
((List__O__Form__C____type__type ) _sharp_pair_615);
})
);
((List__O__Form__C____type__type ) _sharp_pair_616);
})
);
((List__O__Form__C____type__type ) _sharp_pair_617);
})
);});});
})
;}

Form__type  _l__parse__parse_grammar__Grammar(void)
{
return ({
({({(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();
(read_char)();});
(_l__parse__parse_grammar__Spacing)();
(_l__parse__parse_grammar__Grammar_End)();});
})
;}

Form__type  _l__parse__parse_grammar__Grammar_End(void)
{
return ({
void **_sharp_make_list_ptr620;
Form__type gr;
List__O__Form__C____type__type gr_list;
Symbol__type id;
({(id = (_l__parse__parse_grammar__Identifier)());
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
(gr_list = ({
List__O__Form__C____type__type _sharp_make_list619;
({_sharp_make_list619;
_sharp_make_list_ptr620;
(_sharp_make_list_ptr620 = ((void *) (&_sharp_make_list619)));
({({_sharp__sharp_loop621_begin623:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 114))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop621_end622;});}})
;
({(gr = (_l__parse__parse_grammar__Grammar_Rule)());
({({((* _sharp_make_list_ptr620) = (alloc_cons_cell)());
(((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr620))).car) = ((void *) gr));
(_sharp_make_list_ptr620 = (&((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr620))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop621_begin623;});});
_sharp__sharp_loop621_end622:;});
((* _sharp_make_list_ptr620) = ((void *) 0));
_sharp_make_list619;});
})
);
({(read_char)();});
(_l__parse__parse_grammar__Spacing)();
({(read_char)();});
 (_l__parse__parse_grammar__Spacing)();
({(Compound_Form)(intern( "define"), ({
struct struct0x08067530 *_sharp_pair_625;
({_sharp_pair_625;
(_sharp_pair_625 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_625).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_625).cdr) = ({
struct struct0x08067530 *_sharp_pair_624;
({_sharp_pair_624;
(_sharp_pair_624 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_624).car) = (Id_Form)(id));
(((* _sharp_pair_624).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_624);
})
);
((List__O__Form__C____type__type ) _sharp_pair_625);
})
);});});
})
;}

Form__type  _l__parse__parse_grammar__Grammar_Macro(void)
{
return ({
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
(_l__parse__parse_grammar__Grammar_Macro_End)();});
})
;}

Form__type  _l__parse__parse_grammar__Grammar_Macro_End(void)
{
return ({
void **_sharp_make_list_ptr628;
List__O__Form__C____type__type rest_list;
Symbol__type arg;
Symbol__type arg1;
Form__type rule;
Symbol__type id;
List__O__Form__C____type__type form_list;
({({(read_char)();});
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
List__O__Form__C____type__type _sharp_make_list627;
({_sharp_make_list627;
_sharp_make_list_ptr628;
(_sharp_make_list_ptr628 = ((void *) (&_sharp_make_list627)));
({({_sharp__sharp_loop629_begin631:;
({
({if( (!(((((Bool__type ) 1))&&(((((new_peek_char)(0) == 44))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop629_end630;});}})
;
({(parse_symbol)(((String__type) &__string_9));
(arg = (_l__parse__parse_grammar__Identifier)());
({({((* _sharp_make_list_ptr628) = (alloc_cons_cell)());
(((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr628))).car) = ((void *) (Id_Form)(arg)));
(_sharp_make_list_ptr628 = (&((* (* ((struct struct0x085549c8 **) _sharp_make_list_ptr628))).cdr)));
((void) 0);});});});
})
;
({goto _sharp__sharp_loop629_begin631;});});
_sharp__sharp_loop629_end630:;});
((* _sharp_make_list_ptr628) = ((void *) 0));
_sharp_make_list627;});
})
);
({(read_char)();});
({({
struct struct0x08067530 *_sharp_pair_632;
({_sharp_pair_632;
(_sharp_pair_632 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_632).car) = (Id_Form)(arg1));
(((* _sharp_pair_632).cdr) = rest_list);
((List__O__Form__C____type__type ) _sharp_pair_632);
})
;});})));
})
);
(_l__parse__parse_grammar__Spacing)();
(parse_symbol)(((String__type) &__string_10));
(rule = (_l__parse__parse_grammar__Rule)());
(parse_symbol)(((String__type) &__string_11));
({(Compound_Form)(intern( "define"), ({
struct struct0x08067530 *_sharp_pair_636;
({_sharp_pair_636;
(_sharp_pair_636 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_636).car) = (Id_Form)(intern( "grammar_macro")));
(((* _sharp_pair_636).cdr) = ({
struct struct0x08067530 *_sharp_pair_635;
({_sharp_pair_635;
(_sharp_pair_635 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_635).car) = (Id_Form)(id));
(((* _sharp_pair_635).cdr) = ({
struct struct0x08067530 *_sharp_pair_634;
({_sharp_pair_634;
(_sharp_pair_634 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_634).car) = (Compound_Form)(intern( "tuple"), form_list));
(((* _sharp_pair_634).cdr) = ({
struct struct0x08067530 *_sharp_pair_633;
({_sharp_pair_633;
(_sharp_pair_633 = ((struct struct0x08067530 *) (alloc_cons_cell)()));});
(((* _sharp_pair_633).car) = rule);
(((* _sharp_pair_633).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_633);
})
);
((List__O__Form__C____type__type ) _sharp_pair_634);
})
);
((List__O__Form__C____type__type ) _sharp_pair_635);
})
);
((List__O__Form__C____type__type ) _sharp_pair_636);
})
);});});
})
;}
