/* Automatically generated : do not edit!*/
#include "parse-grammar.inc"
Int__type  _l__parse__parse_grammar__Comment(void)
{
return ({
(read_char)(),
(read_char)(),
((void) 0);_sharp__sharp_loop612_begin614:((void) 0),
({
Int__type _sharp_peeked_char_star611;
(_sharp_peeked_char_star611 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star611 >= (int) 11))&&(((int) _sharp_peeked_char_star611 <= (int) 255))))||(((((((int) _sharp_peeked_char_star611 >= (int) 0))&&(((int) _sharp_peeked_char_star611 <= (int) 9))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop612_end613;});}})
;
(read_char)();
})
,
({goto _sharp__sharp_loop612_begin614;}),
((void) 0);_sharp__sharp_loop612_end613:((void) 0),
(read_char)();
})
;}

void  _l__parse__parse_grammar__Spacing(void)
{
return ({
((void) 0);_sharp__sharp_loop617_begin619:((void) 0),
({
Int__type _sharp_peeked_char_star615;
(_sharp_peeked_char_star615 = (peek_char)());
({if( (!((((_sharp_peeked_char_star615 == 47))||((((_sharp_peeked_char_star615 == 32))||((((_sharp_peeked_char_star615 == 10))||((((_sharp_peeked_char_star615 == 9))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop617_end618;});}})
;
({
Int__type _sharp_peeked_char_alt616;
(_sharp_peeked_char_alt616 = (peek_char)());
(((((_sharp_peeked_char_alt616 == 47))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Comment)()):
((((((_sharp_peeked_char_alt616 == 32))||((((_sharp_peeked_char_alt616 == 10))||((((_sharp_peeked_char_alt616 == 9))||(((Bool__type ) 0))))))))?
((read_char)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop617_begin619;}),
((void) 0);_sharp__sharp_loop617_end618:((void) 0);
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
(start = (get_point_pos)()),
(_l__parse__parse_grammar__Alpha)(),
((void) 0);_sharp__sharp_loop621_begin623:((void) 0),
({
Int__type _sharp_peeked_char_star620;
(_sharp_peeked_char_star620 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star620 >= (int) 97))&&(((int) _sharp_peeked_char_star620 <= (int) 122))))||((((_sharp_peeked_char_star620 == 95))||(((((((int) _sharp_peeked_char_star620 >= (int) 65))&&(((int) _sharp_peeked_char_star620 <= (int) 90))))||(((((((int) _sharp_peeked_char_star620 >= (int) 48))&&(((int) _sharp_peeked_char_star620 <= (int) 57))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop621_end622;});}})
;
(_l__parse__parse_grammar__Alpha_Num)();
})
,
({goto _sharp__sharp_loop621_begin623;}),
((void) 0);_sharp__sharp_loop621_end622:((void) 0),
(end = (get_point_pos)()),
(intern_string)((substring)(start, end));
})
;}

Int__type  _l__parse__parse_grammar__Escaped_Character(void)
{
return ({
(read_char)(),
({
Int__type _sharp_peeked_char_alt624;
(_sharp_peeked_char_alt624 = (peek_char)());
((((((((int) _sharp_peeked_char_alt624 >= (int) 117))&&(((int) _sharp_peeked_char_alt624 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt624 >= (int) 111))&&(((int) _sharp_peeked_char_alt624 <= (int) 115))))||(((((((int) _sharp_peeked_char_alt624 >= (int) 0))&&(((int) _sharp_peeked_char_alt624 <= (int) 109))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt624 == 116))||((((_sharp_peeked_char_alt624 == 110))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt625;
(_sharp_peeked_char_alt625 = (peek_char)());
(((((_sharp_peeked_char_alt625 == 116))||(((Bool__type ) 0))))?
((read_char)(),
9):
((((((_sharp_peeked_char_alt625 == 110))||(((Bool__type ) 0))))?
((read_char)(),
10):
((parse_error)()))));
})
):
((parse_error)()))));
})
;
})
;}

Int__type  _l__parse__parse_grammar__Maybe_Escaped_Character(void)
{
return ({
({
Int__type _sharp_peeked_char_alt626;
(_sharp_peeked_char_alt626 = (peek_char)());
((((((((int) _sharp_peeked_char_alt626 >= (int) 93))&&(((int) _sharp_peeked_char_alt626 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt626 >= (int) 0))&&(((int) _sharp_peeked_char_alt626 <= (int) 91))))||(((Bool__type ) 0))))))?
((read_char)()):
((((((_sharp_peeked_char_alt626 == 92))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((parse_error)()))));
})
;
})
;}

Int__type  _l__parse__parse_grammar__Maybe_Escaped_Character_Character_Range(void)
{
return ({
({
Int__type _sharp_peeked_char_alt627;
(_sharp_peeked_char_alt627 = (peek_char)());
((((((((int) _sharp_peeked_char_alt627 >= (int) 94))&&(((int) _sharp_peeked_char_alt627 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt627 >= (int) 93))&&(((int) _sharp_peeked_char_alt627 <= (int) 92))))||(((((((int) _sharp_peeked_char_alt627 >= (int) 0))&&(((int) _sharp_peeked_char_alt627 <= (int) 91))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt627 == 92))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((parse_error)()))));
})
;
})
;}

Form__type  _l__parse__parse_grammar__String(void)
{
return ({
Int__type start;
Int__type end;
(read_char)(),
(start = (get_point_pos)()),
((void) 0);_sharp__sharp_loop630_begin632:((void) 0),
({
Int__type _sharp_peeked_char_star628;
(_sharp_peeked_char_star628 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star628 >= (int) 93))&&(((int) _sharp_peeked_char_star628 <= (int) 255))))||((((_sharp_peeked_char_star628 == 92))||(((((((int) _sharp_peeked_char_star628 >= (int) 35))&&(((int) _sharp_peeked_char_star628 <= (int) 91))))||(((((((int) _sharp_peeked_char_star628 >= (int) 0))&&(((int) _sharp_peeked_char_star628 <= (int) 33))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop630_end631;});}})
;
({
Int__type _sharp_peeked_char_alt629;
(_sharp_peeked_char_alt629 = (peek_char)());
((((((((int) _sharp_peeked_char_alt629 >= (int) 93))&&(((int) _sharp_peeked_char_alt629 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt629 >= (int) 35))&&(((int) _sharp_peeked_char_alt629 <= (int) 91))))||(((((((int) _sharp_peeked_char_alt629 >= (int) 0))&&(((int) _sharp_peeked_char_alt629 <= (int) 33))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt629 == 92))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop630_begin632;}),
((void) 0);_sharp__sharp_loop630_end631:((void) 0),
(end = (get_point_pos)()),
(read_char)(),
(String_Form)((substring)(start, end));
})
;}

Form__type  _l__parse__parse_grammar__Symbol(void)
{
return ({
Int__type start;
Int__type end;
(read_char)(),
(start = (get_point_pos)()),
((void) 0);_sharp__sharp_loop635_begin637:((void) 0),
({
Int__type _sharp_peeked_char_star633;
(_sharp_peeked_char_star633 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star633 >= (int) 93))&&(((int) _sharp_peeked_char_star633 <= (int) 255))))||((((_sharp_peeked_char_star633 == 92))||(((((((int) _sharp_peeked_char_star633 >= (int) 40))&&(((int) _sharp_peeked_char_star633 <= (int) 91))))||(((((((int) _sharp_peeked_char_star633 >= (int) 0))&&(((int) _sharp_peeked_char_star633 <= (int) 38))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop635_end636;});}})
;
({
Int__type _sharp_peeked_char_alt634;
(_sharp_peeked_char_alt634 = (peek_char)());
((((((((int) _sharp_peeked_char_alt634 >= (int) 93))&&(((int) _sharp_peeked_char_alt634 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt634 >= (int) 40))&&(((int) _sharp_peeked_char_alt634 <= (int) 91))))||(((((((int) _sharp_peeked_char_alt634 >= (int) 0))&&(((int) _sharp_peeked_char_alt634 <= (int) 38))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt634 == 92))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop635_begin637;}),
((void) 0);_sharp__sharp_loop635_end636:((void) 0),
(end = (get_point_pos)()),
(read_char)(),
(Symbol_Form)((intern_string)((substring)(start, end)));
})
;}

Form__type  _l__parse__parse_grammar__Character_Range(void)
{
return ({
Int__type max;
Int__type min;
(max = (min = (_l__parse__parse_grammar__Maybe_Escaped_Character_Character_Range)())),
({
Int__type _sharp_peeked_char_maybe638;
(_sharp_peeked_char_maybe638 = (peek_char)());
({if( (((_sharp_peeked_char_maybe638 == 45))||(((Bool__type ) 0))))
{
(read_char)(),
(max = (_l__parse__parse_grammar__Maybe_Escaped_Character)());}})
;
})
,
(((min == max))?
((Int_Form)(min)):
((Compound_Form)(intern( "-"), ({
struct struct0x080663e8 *_sharp_pair_640;
_sharp_pair_640,
(_sharp_pair_640 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_640).car) = (Int_Form)(min));
(((* _sharp_pair_640).cdr) = ({
struct struct0x080663e8 *_sharp_pair_639;
_sharp_pair_639,
(_sharp_pair_639 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_639).car) = (Int_Form)(max));
(((* _sharp_pair_639).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_639);
})
);
((List__O__Form__C____type__type ) _sharp_pair_640);
})
)));
})
;}

Form__type  _l__parse__parse_grammar__Character_Set(void)
{
return ({
void **_sharp_make_list_ptr644;
Symbol__type char_selector;
Form__type cr;
List__O__Form__C____type__type cr_list;
(char_selector = intern( "[]")),
(read_char)(),
({
Int__type _sharp_peeked_char_maybe641;
(_sharp_peeked_char_maybe641 = (peek_char)());
({if( (((_sharp_peeked_char_maybe641 == 94))||(((Bool__type ) 0))))
{
(read_char)(),
(char_selector = intern( "[^]"));}})
;
})
,
(cr_list = ({
List__O__Form__C____type__type _sharp_make_list643;
_sharp_make_list643,
_sharp_make_list_ptr644,
(_sharp_make_list_ptr644 = ((void *) (&_sharp_make_list643))),
((void) 0);_sharp__sharp_loop645_begin647:((void) 0),
({
Int__type _sharp_peeked_char_star642;
(_sharp_peeked_char_star642 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star642 >= (int) 94))&&(((int) _sharp_peeked_char_star642 <= (int) 255))))||(((((((int) _sharp_peeked_char_star642 >= (int) 93))&&(((int) _sharp_peeked_char_star642 <= (int) 92))))||((((_sharp_peeked_char_star642 == 92))||(((((((int) _sharp_peeked_char_star642 >= (int) 0))&&(((int) _sharp_peeked_char_star642 <= (int) 91))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop645_end646;});}})
;
(cr = (_l__parse__parse_grammar__Character_Range)()),
((* _sharp_make_list_ptr644) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr644))).car) = ((void *) cr)),
(_sharp_make_list_ptr644 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr644))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop645_begin647;}),
((void) 0);_sharp__sharp_loop645_end646:((void) 0),
((* _sharp_make_list_ptr644) = ((void *) 0)),
_sharp_make_list643;
})
),
(read_char)(),
(Compound_Form)(char_selector, cr_list);
})
;}

Form__type  _l__parse__parse_grammar__Callable_Rule(void)
{
return ({
Form__type form;
Symbol__type id;
(id = (_l__parse__parse_grammar__Identifier)()),
(form = (Id_Form)(id)),
({
Int__type _sharp_peeked_char_maybe648;
(_sharp_peeked_char_maybe648 = (peek_char)());
({if( (((_sharp_peeked_char_maybe648 == 46))||(((Bool__type ) 0))))
{
(read_char)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(form = (Compound_Form)(intern( "."), ({
struct struct0x080663e8 *_sharp_pair_650;
_sharp_pair_650,
(_sharp_pair_650 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_650).car) = form);
(((* _sharp_pair_650).cdr) = ({
struct struct0x080663e8 *_sharp_pair_649;
_sharp_pair_649,
(_sharp_pair_649 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_649).car) = (Id_Form)(id));
(((* _sharp_pair_649).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_649);
})
);
((List__O__Form__C____type__type ) _sharp_pair_650);
})
));}})
;
})
,
form;
})
;}

Form__type  _l__parse__parse_grammar__Semantic_Action(void)
{
return ({
Form__type exp;
(read_char)(),
(exp = (_l__parse__parse_grammar__Expression)()),
(read_char)(),
(Compound_Form)(intern( "{}"), ({
struct struct0x080663e8 *_sharp_pair_651;
_sharp_pair_651,
(_sharp_pair_651 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_651).car) = exp);
(((* _sharp_pair_651).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_651);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Grouping(void)
{
return ({
Form__type form;
Symbol__type id;
(read_char)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(read_char)(),
(form = (_l__parse__parse_grammar__Rule)()),
(read_char)(),
(Compound_Form)(intern( "<>"), ({
struct struct0x080663e8 *_sharp_pair_653;
_sharp_pair_653,
(_sharp_pair_653 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_653).car) = (Id_Form)(id));
(((* _sharp_pair_653).cdr) = ({
struct struct0x080663e8 *_sharp_pair_652;
_sharp_pair_652,
(_sharp_pair_652 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_652).car) = form);
(((* _sharp_pair_652).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_652);
})
);
((List__O__Form__C____type__type ) _sharp_pair_653);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Rule_Macro(void)
{
return ({
void **_sharp_make_list_ptr657;
Form__type arg;
List__O__Form__C____type__type rest_list;
Form__type arg1;
Symbol__type id;
List__O__Form__C____type__type form_list;
(read_char)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(form_list = ({
Int__type _sharp_peeked_char_alt654;
(_sharp_peeked_char_alt654 = (peek_char)());
(((((_sharp_peeked_char_alt654 == 123))||(((((((int) _sharp_peeked_char_alt654 >= (int) 97))&&(((int) _sharp_peeked_char_alt654 <= (int) 122))))||((((_sharp_peeked_char_alt654 == 95))||((((_sharp_peeked_char_alt654 == 91))||(((((((int) _sharp_peeked_char_alt654 >= (int) 65))&&(((int) _sharp_peeked_char_alt654 <= (int) 90))))||((((_sharp_peeked_char_alt654 == 64))||((((_sharp_peeked_char_alt654 == 60))||((((_sharp_peeked_char_alt654 == 40))||((((_sharp_peeked_char_alt654 == 39))||((((_sharp_peeked_char_alt654 == 36))||((((_sharp_peeked_char_alt654 == 34))||(((Bool__type ) 0))))))))))))))))))))))))?
((arg1 = (_l__parse__parse_grammar__Rule)()),
(_l__parse__parse_grammar__Spacing)(),
(rest_list = ({
List__O__Form__C____type__type _sharp_make_list656;
_sharp_make_list656,
_sharp_make_list_ptr657,
(_sharp_make_list_ptr657 = ((void *) (&_sharp_make_list656))),
((void) 0);_sharp__sharp_loop658_begin660:((void) 0),
({
Int__type _sharp_peeked_char_star655;
(_sharp_peeked_char_star655 = (peek_char)());
({if( (!((((_sharp_peeked_char_star655 == 44))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop658_end659;});}})
;
(parse_symbol)(((String__type) &__string_14)),
(arg = (_l__parse__parse_grammar__Rule)()),
((* _sharp_make_list_ptr657) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr657))).car) = ((void *) arg)),
(_sharp_make_list_ptr657 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr657))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop658_begin660;}),
((void) 0);_sharp__sharp_loop658_end659:((void) 0),
((* _sharp_make_list_ptr657) = ((void *) 0)),
_sharp_make_list656;
})
),
(read_char)(),
({
struct struct0x080663e8 *_sharp_pair_661;
_sharp_pair_661,
(_sharp_pair_661 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_661).car) = arg1);
(((* _sharp_pair_661).cdr) = rest_list);
((List__O__Form__C____type__type ) _sharp_pair_661);
})
):
((((((_sharp_peeked_char_alt654 == 41))||(((Bool__type ) 0))))?
((read_char)(),
((List__O__Form__C____type__type ) 0)):
((parse_error)()))));
})
),
(Compound_Form)(intern( "@"), ({
struct struct0x080663e8 *_sharp_pair_662;
_sharp_pair_662,
(_sharp_pair_662 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_662).car) = (Compound_Form)(id, form_list));
(((* _sharp_pair_662).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_662);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Replacement(void)
{
return ({
Form__type exp;
(read_char)(),
(exp = (_l__parse__parse_grammar__Expression)()),
(read_char)(),
(Compound_Form)(intern( "$"), ({
struct struct0x080663e8 *_sharp_pair_663;
_sharp_pair_663,
(_sharp_pair_663 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_663).car) = exp);
(((* _sharp_pair_663).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_663);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Primary(void)
{
return ({
Form__type r;
({
Int__type _sharp_peeked_char_alt664;
(_sharp_peeked_char_alt664 = (peek_char)());
(((((_sharp_peeked_char_alt664 == 40))||(((Bool__type ) 0))))?
((read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(r = (_l__parse__parse_grammar__Rule)()),
(read_char)(),
r):
((((((_sharp_peeked_char_alt664 == 123))||(((((((int) _sharp_peeked_char_alt664 >= (int) 97))&&(((int) _sharp_peeked_char_alt664 <= (int) 122))))||((((_sharp_peeked_char_alt664 == 95))||((((_sharp_peeked_char_alt664 == 91))||(((((((int) _sharp_peeked_char_alt664 >= (int) 65))&&(((int) _sharp_peeked_char_alt664 <= (int) 90))))||((((_sharp_peeked_char_alt664 == 64))||((((_sharp_peeked_char_alt664 == 60))||((((_sharp_peeked_char_alt664 == 39))||((((_sharp_peeked_char_alt664 == 36))||((((_sharp_peeked_char_alt664 == 34))||(((Bool__type ) 0))))))))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt665;
(_sharp_peeked_char_alt665 = (peek_char)());
(((((_sharp_peeked_char_alt665 == 36))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Replacement)()):
((((((_sharp_peeked_char_alt665 == 123))||(((((((int) _sharp_peeked_char_alt665 >= (int) 97))&&(((int) _sharp_peeked_char_alt665 <= (int) 122))))||((((_sharp_peeked_char_alt665 == 95))||((((_sharp_peeked_char_alt665 == 91))||(((((((int) _sharp_peeked_char_alt665 >= (int) 65))&&(((int) _sharp_peeked_char_alt665 <= (int) 90))))||((((_sharp_peeked_char_alt665 == 64))||((((_sharp_peeked_char_alt665 == 60))||((((_sharp_peeked_char_alt665 == 39))||((((_sharp_peeked_char_alt665 == 34))||(((Bool__type ) 0))))))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt666;
(_sharp_peeked_char_alt666 = (peek_char)());
(((((_sharp_peeked_char_alt666 == 64))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Rule_Macro)()):
((((((_sharp_peeked_char_alt666 == 123))||(((((((int) _sharp_peeked_char_alt666 >= (int) 97))&&(((int) _sharp_peeked_char_alt666 <= (int) 122))))||((((_sharp_peeked_char_alt666 == 95))||((((_sharp_peeked_char_alt666 == 91))||(((((((int) _sharp_peeked_char_alt666 >= (int) 65))&&(((int) _sharp_peeked_char_alt666 <= (int) 90))))||((((_sharp_peeked_char_alt666 == 60))||((((_sharp_peeked_char_alt666 == 39))||((((_sharp_peeked_char_alt666 == 34))||(((Bool__type ) 0))))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt667;
(_sharp_peeked_char_alt667 = (peek_char)());
(((((_sharp_peeked_char_alt667 == 123))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Semantic_Action)()):
(((((((((int) _sharp_peeked_char_alt667 >= (int) 97))&&(((int) _sharp_peeked_char_alt667 <= (int) 122))))||((((_sharp_peeked_char_alt667 == 95))||((((_sharp_peeked_char_alt667 == 91))||(((((((int) _sharp_peeked_char_alt667 >= (int) 65))&&(((int) _sharp_peeked_char_alt667 <= (int) 90))))||((((_sharp_peeked_char_alt667 == 60))||((((_sharp_peeked_char_alt667 == 39))||((((_sharp_peeked_char_alt667 == 34))||(((Bool__type ) 0))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt668;
(_sharp_peeked_char_alt668 = (peek_char)());
(((((_sharp_peeked_char_alt668 == 60))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Grouping)()):
(((((((((int) _sharp_peeked_char_alt668 >= (int) 97))&&(((int) _sharp_peeked_char_alt668 <= (int) 122))))||((((_sharp_peeked_char_alt668 == 95))||((((_sharp_peeked_char_alt668 == 91))||(((((((int) _sharp_peeked_char_alt668 >= (int) 65))&&(((int) _sharp_peeked_char_alt668 <= (int) 90))))||((((_sharp_peeked_char_alt668 == 39))||((((_sharp_peeked_char_alt668 == 34))||(((Bool__type ) 0))))))))))))))?
(({
Int__type _sharp_peeked_char_alt669;
(_sharp_peeked_char_alt669 = (peek_char)());
((((((((int) _sharp_peeked_char_alt669 >= (int) 97))&&(((int) _sharp_peeked_char_alt669 <= (int) 122))))||((((_sharp_peeked_char_alt669 == 95))||(((((((int) _sharp_peeked_char_alt669 >= (int) 65))&&(((int) _sharp_peeked_char_alt669 <= (int) 90))))||(((Bool__type ) 0))))))))?
((_l__parse__parse_grammar__Callable_Rule)()):
((((((_sharp_peeked_char_alt669 == 91))||((((_sharp_peeked_char_alt669 == 39))||((((_sharp_peeked_char_alt669 == 34))||(((Bool__type ) 0))))))))?
(({
Int__type _sharp_peeked_char_alt670;
(_sharp_peeked_char_alt670 = (peek_char)());
(((((_sharp_peeked_char_alt670 == 91))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Character_Set)()):
((((((_sharp_peeked_char_alt670 == 39))||((((_sharp_peeked_char_alt670 == 34))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt671;
(_sharp_peeked_char_alt671 = (peek_char)());
(((((_sharp_peeked_char_alt671 == 39))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Symbol)()):
((((((_sharp_peeked_char_alt671 == 34))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__String)()):
((parse_error)()))));
})
):
((parse_error)()))));
})
):
((parse_error)()))));
})
):
((parse_error)()))));
})
):
((parse_error)()))));
})
):
((parse_error)()))));
})
):
((parse_error)()))));
})
):
((parse_error)()))));
})
;
})
;}

Form__type  _l__parse__parse_grammar__Postfix(void)
{
return ({
Symbol__type op;
Form__type form;
(form = (_l__parse__parse_grammar__Primary)()),
({
Int__type _sharp_peeked_char_maybe672;
(_sharp_peeked_char_maybe672 = (peek_char)());
({if( (((_sharp_peeked_char_maybe672 == 63))||((((_sharp_peeked_char_maybe672 == 43))||((((_sharp_peeked_char_maybe672 == 42))||(((Bool__type ) 0))))))))
{
(op = ({
Int__type _sharp_peeked_char_alt673;
(_sharp_peeked_char_alt673 = (peek_char)());
(((((_sharp_peeked_char_alt673 == 43))||(((Bool__type ) 0))))?
((parse_symbol)(((String__type) &__string_15))):
((((((_sharp_peeked_char_alt673 == 63))||((((_sharp_peeked_char_alt673 == 42))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt674;
(_sharp_peeked_char_alt674 = (peek_char)());
(((((_sharp_peeked_char_alt674 == 42))||(((Bool__type ) 0))))?
((parse_symbol)(((String__type) &__string_16))):
((((((_sharp_peeked_char_alt674 == 63))||(((Bool__type ) 0))))?
((parse_symbol)(((String__type) &__string_17))):
((parse_error)()))));
})
):
((parse_error)()))));
})
),
(form = (Compound_Form)(op, ({
struct struct0x080663e8 *_sharp_pair_675;
_sharp_pair_675,
(_sharp_pair_675 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_675).car) = form);
(((* _sharp_pair_675).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_675);
})
));}})
;
})
,
form;
})
;}

Form__type  _l__parse__parse_grammar__Sequence(void)
{
return ({
void **_sharp_make_list_ptr678;
Form__type post;
List__O__Form__C____type__type post_list;
(post_list = ({
List__O__Form__C____type__type _sharp_make_list677;
_sharp_make_list677,
_sharp_make_list_ptr678,
(_sharp_make_list_ptr678 = ((void *) (&_sharp_make_list677))),
((void) 0);_sharp__sharp_loop679_begin681:((void) 0),
({
Int__type _sharp_peeked_char_star676;
(post = (_l__parse__parse_grammar__Postfix)()),
(_l__parse__parse_grammar__Spacing)(),
((* _sharp_make_list_ptr678) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr678))).car) = ((void *) post)),
(_sharp_make_list_ptr678 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr678))).cdr))),
((void) 0);
(_sharp_peeked_char_star676 = (peek_char)());
({if( (!((((_sharp_peeked_char_star676 == 123))||(((((((int) _sharp_peeked_char_star676 >= (int) 97))&&(((int) _sharp_peeked_char_star676 <= (int) 122))))||((((_sharp_peeked_char_star676 == 95))||((((_sharp_peeked_char_star676 == 91))||(((((((int) _sharp_peeked_char_star676 >= (int) 65))&&(((int) _sharp_peeked_char_star676 <= (int) 90))))||((((_sharp_peeked_char_star676 == 64))||((((_sharp_peeked_char_star676 == 60))||((((_sharp_peeked_char_star676 == 40))||((((_sharp_peeked_char_star676 == 39))||((((_sharp_peeked_char_star676 == 36))||((((_sharp_peeked_char_star676 == 34))||(((Bool__type ) 0))))))))))))))))))))))))))
{
({goto _sharp__sharp_loop679_end680;});}})
;
})
,
({goto _sharp__sharp_loop679_begin681;}),
((void) 0);_sharp__sharp_loop679_end680:((void) 0),
((* _sharp_make_list_ptr678) = ((void *) 0)),
_sharp_make_list677;
})
),
(((((* ((struct struct0x0805f088 *) post_list)).tail) == ((List__O__Form__C____type__type ) 0)))?
(((* ((struct struct0x0805f088 *) post_list)).head)):
((Compound_Form)(intern( " "), post_list)));
})
;}

Form__type  _l__parse__parse_grammar__Alternative(void)
{
return ({
Form__type sec;
Form__type prim;
(prim = (_l__parse__parse_grammar__Sequence)()),
((void) 0);_sharp__sharp_loop685_begin687:((void) 0),
({
Int__type _sharp_peeked_char_star682;
(_sharp_peeked_char_star682 = (peek_char)());
({if( (!((((_sharp_peeked_char_star682 == 124))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop685_end686;});}})
;
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(sec = (_l__parse__parse_grammar__Sequence)()),
(prim = (Compound_Form)(intern( "|"), ({
struct struct0x080663e8 *_sharp_pair_684;
_sharp_pair_684,
(_sharp_pair_684 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_684).car) = prim);
(((* _sharp_pair_684).cdr) = ({
struct struct0x080663e8 *_sharp_pair_683;
_sharp_pair_683,
(_sharp_pair_683 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_683).car) = sec);
(((* _sharp_pair_683).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_683);
})
);
((List__O__Form__C____type__type ) _sharp_pair_684);
})
));
})
,
({goto _sharp__sharp_loop685_begin687;}),
((void) 0);_sharp__sharp_loop685_end686:((void) 0),
prim;
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
Form__type ret_type;
Form__type r;
Symbol__type id;
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(read_char)(),
(ret_type = (_l__parse__parse_grammar__Type)()),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(r = (_l__parse__parse_grammar__Rule)()),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(Compound_Form)(intern( "rule"), ({
struct struct0x080663e8 *_sharp_pair_690;
_sharp_pair_690,
(_sharp_pair_690 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_690).car) = (Id_Form)(id));
(((* _sharp_pair_690).cdr) = ({
struct struct0x080663e8 *_sharp_pair_689;
_sharp_pair_689,
(_sharp_pair_689 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_689).car) = ret_type);
(((* _sharp_pair_689).cdr) = ({
struct struct0x080663e8 *_sharp_pair_688;
_sharp_pair_688,
(_sharp_pair_688 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_688).car) = r);
(((* _sharp_pair_688).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_688);
})
);
((List__O__Form__C____type__type ) _sharp_pair_689);
})
);
((List__O__Form__C____type__type ) _sharp_pair_690);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Grammar(void)
{
return ({
void **_sharp_make_list_ptr693;
Form__type gr;
List__O__Form__C____type__type gr_list;
Symbol__type id;
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(gr_list = ({
List__O__Form__C____type__type _sharp_make_list692;
_sharp_make_list692,
_sharp_make_list_ptr693,
(_sharp_make_list_ptr693 = ((void *) (&_sharp_make_list692))),
((void) 0);_sharp__sharp_loop694_begin696:((void) 0),
({
Int__type _sharp_peeked_char_star691;
(_sharp_peeked_char_star691 = (peek_char)());
({if( (!((((_sharp_peeked_char_star691 == 114))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop694_end695;});}})
;
(gr = (_l__parse__parse_grammar__Grammar_Rule)()),
((* _sharp_make_list_ptr693) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr693))).car) = ((void *) gr)),
(_sharp_make_list_ptr693 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr693))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop694_begin696;}),
((void) 0);_sharp__sharp_loop694_end695:((void) 0),
((* _sharp_make_list_ptr693) = ((void *) 0)),
_sharp_make_list692;
})
),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(Compound_Form)(intern( "define"), ({
struct struct0x080663e8 *_sharp_pair_698;
_sharp_pair_698,
(_sharp_pair_698 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_698).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_698).cdr) = ({
struct struct0x080663e8 *_sharp_pair_697;
_sharp_pair_697,
(_sharp_pair_697 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_697).car) = (Id_Form)(id));
(((* _sharp_pair_697).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_697);
})
);
((List__O__Form__C____type__type ) _sharp_pair_698);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Grammar_Macro(void)
{
return ({
void **_sharp_make_list_ptr702;
Symbol__type arg;
List__O__Form__C____type__type rest_list;
Symbol__type arg1;
Form__type rule;
Symbol__type id;
List__O__Form__C____type__type form_list;
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(form_list = ({
Int__type _sharp_peeked_char_alt699;
(_sharp_peeked_char_alt699 = (peek_char)());
((((((((int) _sharp_peeked_char_alt699 >= (int) 97))&&(((int) _sharp_peeked_char_alt699 <= (int) 122))))||((((_sharp_peeked_char_alt699 == 95))||(((((((int) _sharp_peeked_char_alt699 >= (int) 65))&&(((int) _sharp_peeked_char_alt699 <= (int) 90))))||(((Bool__type ) 0))))))))?
((arg1 = (_l__parse__parse_grammar__Identifier)()),
(_l__parse__parse_grammar__Spacing)(),
(rest_list = ({
List__O__Form__C____type__type _sharp_make_list701;
_sharp_make_list701,
_sharp_make_list_ptr702,
(_sharp_make_list_ptr702 = ((void *) (&_sharp_make_list701))),
((void) 0);_sharp__sharp_loop703_begin705:((void) 0),
({
Int__type _sharp_peeked_char_star700;
(_sharp_peeked_char_star700 = (peek_char)());
({if( (!((((_sharp_peeked_char_star700 == 44))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop703_end704;});}})
;
(parse_symbol)(((String__type) &__string_18)),
(arg = (_l__parse__parse_grammar__Identifier)()),
((* _sharp_make_list_ptr702) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr702))).car) = ((void *) (Id_Form)(arg))),
(_sharp_make_list_ptr702 = (&((* (* ((struct struct0x0852c460 **) _sharp_make_list_ptr702))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop703_begin705;}),
((void) 0);_sharp__sharp_loop703_end704:((void) 0),
((* _sharp_make_list_ptr702) = ((void *) 0)),
_sharp_make_list701;
})
),
(read_char)(),
({
struct struct0x080663e8 *_sharp_pair_706;
_sharp_pair_706,
(_sharp_pair_706 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_706).car) = (Id_Form)(arg1));
(((* _sharp_pair_706).cdr) = rest_list);
((List__O__Form__C____type__type ) _sharp_pair_706);
})
):
((((((_sharp_peeked_char_alt699 == 41))||(((Bool__type ) 0))))?
((read_char)(),
((List__O__Form__C____type__type ) 0)):
((parse_error)()))));
})
),
(_l__parse__parse_grammar__Spacing)(),
(parse_symbol)(((String__type) &__string_19)),
(rule = (_l__parse__parse_grammar__Rule)()),
(parse_symbol)(((String__type) &__string_20)),
(Compound_Form)(intern( "define"), ({
struct struct0x080663e8 *_sharp_pair_710;
_sharp_pair_710,
(_sharp_pair_710 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_710).car) = (Id_Form)(intern( "grammar_macro")));
(((* _sharp_pair_710).cdr) = ({
struct struct0x080663e8 *_sharp_pair_709;
_sharp_pair_709,
(_sharp_pair_709 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_709).car) = (Id_Form)(id));
(((* _sharp_pair_709).cdr) = ({
struct struct0x080663e8 *_sharp_pair_708;
_sharp_pair_708,
(_sharp_pair_708 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_708).car) = (Compound_Form)(intern( "tuple"), form_list));
(((* _sharp_pair_708).cdr) = ({
struct struct0x080663e8 *_sharp_pair_707;
_sharp_pair_707,
(_sharp_pair_707 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_707).car) = rule);
(((* _sharp_pair_707).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_707);
})
);
((List__O__Form__C____type__type ) _sharp_pair_708);
})
);
((List__O__Form__C____type__type ) _sharp_pair_709);
})
);
((List__O__Form__C____type__type ) _sharp_pair_710);
})
);
})
;}
