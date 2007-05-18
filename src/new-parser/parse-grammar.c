/* Automatically generated : do not edit!*/
#include "parse-grammar.inc"
Int__type  _l__parse__parse_grammar__Comment(void)
{
return ({
(read_char)(),
(read_char)(),
((void) 0);_sharp__sharp_loop589_begin591:((void) 0),
({
Int__type _sharp_peeked_char_star588;
(_sharp_peeked_char_star588 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star588 >= (int) 11))&&(((int) _sharp_peeked_char_star588 <= (int) 255))))||(((((((int) _sharp_peeked_char_star588 >= (int) 0))&&(((int) _sharp_peeked_char_star588 <= (int) 9))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop589_end590;});}})
;
(read_char)();
})
,
({goto _sharp__sharp_loop589_begin591;}),
((void) 0);_sharp__sharp_loop589_end590:((void) 0),
(read_char)(),
(read_char)();
})
;}

void  _l__parse__parse_grammar__Spacing(void)
{
return ({
((void) 0);_sharp__sharp_loop594_begin596:((void) 0),
({
Int__type _sharp_peeked_char_star592;
(_sharp_peeked_char_star592 = (peek_char)());
({if( (!((((_sharp_peeked_char_star592 == 32))||((((_sharp_peeked_char_star592 == 10))||((((_sharp_peeked_char_star592 == 9))||((((_sharp_peeked_char_star592 == 47))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop594_end595;});}})
;
({
Int__type _sharp_peeked_char_alt593;
(_sharp_peeked_char_alt593 = (peek_char)());
(((((_sharp_peeked_char_alt593 == 47))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Comment)()):
((((((_sharp_peeked_char_alt593 == 32))||((((_sharp_peeked_char_alt593 == 10))||((((_sharp_peeked_char_alt593 == 9))||(((Bool__type ) 0))))))))?
((read_char)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop594_begin596;}),
((void) 0);_sharp__sharp_loop594_end595:((void) 0);
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
((void) 0);_sharp__sharp_loop598_begin600:((void) 0),
({
Int__type _sharp_peeked_char_star597;
(_sharp_peeked_char_star597 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star597 >= (int) 97))&&(((int) _sharp_peeked_char_star597 <= (int) 122))))||((((_sharp_peeked_char_star597 == 95))||(((((((int) _sharp_peeked_char_star597 >= (int) 65))&&(((int) _sharp_peeked_char_star597 <= (int) 90))))||(((((((int) _sharp_peeked_char_star597 >= (int) 48))&&(((int) _sharp_peeked_char_star597 <= (int) 57))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop598_end599;});}})
;
(_l__parse__parse_grammar__Alpha_Num)();
})
,
({goto _sharp__sharp_loop598_begin600;}),
((void) 0);_sharp__sharp_loop598_end599:((void) 0),
(end = (get_point_pos)()),
(intern_string)((substring)(start, end));
})
;}

Int__type  _l__parse__parse_grammar__Escaped_Character(void)
{
return ({
(read_char)(),
({
Int__type _sharp_peeked_char_alt601;
(_sharp_peeked_char_alt601 = (peek_char)());
((((((((int) _sharp_peeked_char_alt601 >= (int) 117))&&(((int) _sharp_peeked_char_alt601 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt601 >= (int) 111))&&(((int) _sharp_peeked_char_alt601 <= (int) 115))))||(((((((int) _sharp_peeked_char_alt601 >= (int) 0))&&(((int) _sharp_peeked_char_alt601 <= (int) 109))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt601 == 110))||((((_sharp_peeked_char_alt601 == 116))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt602;
(_sharp_peeked_char_alt602 = (peek_char)());
(((((_sharp_peeked_char_alt602 == 116))||(((Bool__type ) 0))))?
((read_char)(),
9):
((((((_sharp_peeked_char_alt602 == 110))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_alt603;
(_sharp_peeked_char_alt603 = (peek_char)());
((((((((int) _sharp_peeked_char_alt603 >= (int) 93))&&(((int) _sharp_peeked_char_alt603 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt603 >= (int) 0))&&(((int) _sharp_peeked_char_alt603 <= (int) 91))))||(((Bool__type ) 0))))))?
((read_char)()):
((((((_sharp_peeked_char_alt603 == 92))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_alt604;
(_sharp_peeked_char_alt604 = (peek_char)());
((((((((int) _sharp_peeked_char_alt604 >= (int) 94))&&(((int) _sharp_peeked_char_alt604 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt604 >= (int) 93))&&(((int) _sharp_peeked_char_alt604 <= (int) 92))))||(((((((int) _sharp_peeked_char_alt604 >= (int) 0))&&(((int) _sharp_peeked_char_alt604 <= (int) 91))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt604 == 92))||(((Bool__type ) 0))))?
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
((void) 0);_sharp__sharp_loop607_begin609:((void) 0),
({
Int__type _sharp_peeked_char_star605;
(_sharp_peeked_char_star605 = (peek_char)());
({if( (!((((_sharp_peeked_char_star605 == 92))||(((((((int) _sharp_peeked_char_star605 >= (int) 93))&&(((int) _sharp_peeked_char_star605 <= (int) 255))))||(((((((int) _sharp_peeked_char_star605 >= (int) 35))&&(((int) _sharp_peeked_char_star605 <= (int) 91))))||(((((((int) _sharp_peeked_char_star605 >= (int) 0))&&(((int) _sharp_peeked_char_star605 <= (int) 33))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop607_end608;});}})
;
({
Int__type _sharp_peeked_char_alt606;
(_sharp_peeked_char_alt606 = (peek_char)());
((((((((int) _sharp_peeked_char_alt606 >= (int) 93))&&(((int) _sharp_peeked_char_alt606 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt606 >= (int) 35))&&(((int) _sharp_peeked_char_alt606 <= (int) 91))))||(((((((int) _sharp_peeked_char_alt606 >= (int) 0))&&(((int) _sharp_peeked_char_alt606 <= (int) 33))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt606 == 92))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop607_begin609;}),
((void) 0);_sharp__sharp_loop607_end608:((void) 0),
(end = (get_point_pos)()),
(read_char)(),
(String_Form)((substring)(start, end));
})
;}

Form__type  _l__parse__parse_grammar__Character_Range(void)
{
return ({
Int__type max;
Int__type min;
(max = (min = (_l__parse__parse_grammar__Maybe_Escaped_Character_Character_Range)())),
({
Int__type _sharp_peeked_char_maybe610;
(_sharp_peeked_char_maybe610 = (peek_char)());
({if( (((_sharp_peeked_char_maybe610 == 45))||(((Bool__type ) 0))))
{
(read_char)(),
(max = (_l__parse__parse_grammar__Maybe_Escaped_Character)());}})
;
})
,
(((min == max))?
((Int_Form)(min)):
((Compound_Form)(intern( "-"), ({
struct struct0x08066050 *_sharp_pair_612;
_sharp_pair_612,
(_sharp_pair_612 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_612).car) = (Int_Form)(min));
(((* _sharp_pair_612).cdr) = ({
struct struct0x08066050 *_sharp_pair_611;
_sharp_pair_611,
(_sharp_pair_611 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_611).car) = (Int_Form)(max));
(((* _sharp_pair_611).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_611);
})
);
((List__O__Form__C____type__type ) _sharp_pair_612);
})
)));
})
;}

Form__type  _l__parse__parse_grammar__Character_Set(void)
{
return ({
void **_sharp_make_list_ptr616;
Symbol__type char_selector;
List__O__Form__C____type__type cr_list;
Form__type cr;
(char_selector = intern( "[]")),
(read_char)(),
({
Int__type _sharp_peeked_char_maybe613;
(_sharp_peeked_char_maybe613 = (peek_char)());
({if( (((_sharp_peeked_char_maybe613 == 94))||(((Bool__type ) 0))))
{
(read_char)(),
(char_selector = intern( "[^]"));}})
;
})
,
(cr_list = ({
List__O__Form__C____type__type _sharp_make_list615;
_sharp_make_list615,
_sharp_make_list_ptr616,
(_sharp_make_list_ptr616 = ((void *) (&_sharp_make_list615))),
((void) 0);_sharp__sharp_loop617_begin619:((void) 0),
({
Int__type _sharp_peeked_char_star614;
(_sharp_peeked_char_star614 = (peek_char)());
({if( (!((((_sharp_peeked_char_star614 == 92))||(((((((int) _sharp_peeked_char_star614 >= (int) 94))&&(((int) _sharp_peeked_char_star614 <= (int) 255))))||(((((((int) _sharp_peeked_char_star614 >= (int) 93))&&(((int) _sharp_peeked_char_star614 <= (int) 92))))||(((((((int) _sharp_peeked_char_star614 >= (int) 0))&&(((int) _sharp_peeked_char_star614 <= (int) 91))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop617_end618;});}})
;
(cr = (_l__parse__parse_grammar__Character_Range)()),
((* _sharp_make_list_ptr616) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08526d78 **) _sharp_make_list_ptr616))).car) = ((void *) cr)),
(_sharp_make_list_ptr616 = (&((* (* ((struct struct0x08526d78 **) _sharp_make_list_ptr616))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop617_begin619;}),
((void) 0);_sharp__sharp_loop617_end618:((void) 0),
((* _sharp_make_list_ptr616) = ((void *) 0)),
_sharp_make_list615;
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
Int__type _sharp_peeked_char_maybe620;
(_sharp_peeked_char_maybe620 = (peek_char)());
({if( (((_sharp_peeked_char_maybe620 == 46))||(((Bool__type ) 0))))
{
(read_char)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(form = (Compound_Form)(intern( "."), ({
struct struct0x08066050 *_sharp_pair_622;
_sharp_pair_622,
(_sharp_pair_622 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_622).car) = form);
(((* _sharp_pair_622).cdr) = ({
struct struct0x08066050 *_sharp_pair_621;
_sharp_pair_621,
(_sharp_pair_621 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_621).car) = (Id_Form)(id));
(((* _sharp_pair_621).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_621);
})
);
((List__O__Form__C____type__type ) _sharp_pair_622);
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
struct struct0x08066050 *_sharp_pair_623;
_sharp_pair_623,
(_sharp_pair_623 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_623).car) = exp);
(((* _sharp_pair_623).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_623);
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
struct struct0x08066050 *_sharp_pair_625;
_sharp_pair_625,
(_sharp_pair_625 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_625).car) = (Id_Form)(id));
(((* _sharp_pair_625).cdr) = ({
struct struct0x08066050 *_sharp_pair_624;
_sharp_pair_624,
(_sharp_pair_624 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_624).car) = form);
(((* _sharp_pair_624).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_624);
})
);
((List__O__Form__C____type__type ) _sharp_pair_625);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Primary(void)
{
return ({
Form__type r;
({
Int__type _sharp_peeked_char_alt626;
(_sharp_peeked_char_alt626 = (peek_char)());
(((((_sharp_peeked_char_alt626 == 40))||(((Bool__type ) 0))))?
((read_char)(),
(r = (_l__parse__parse_grammar__Rule)()),
(read_char)(),
r):
((((((_sharp_peeked_char_alt626 == 34))||((((_sharp_peeked_char_alt626 == 91))||(((((((int) _sharp_peeked_char_alt626 >= (int) 97))&&(((int) _sharp_peeked_char_alt626 <= (int) 122))))||((((_sharp_peeked_char_alt626 == 95))||(((((((int) _sharp_peeked_char_alt626 >= (int) 65))&&(((int) _sharp_peeked_char_alt626 <= (int) 90))))||((((_sharp_peeked_char_alt626 == 60))||((((_sharp_peeked_char_alt626 == 123))||(((Bool__type ) 0))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt627;
(_sharp_peeked_char_alt627 = (peek_char)());
(((((_sharp_peeked_char_alt627 == 123))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Semantic_Action)()):
((((((_sharp_peeked_char_alt627 == 34))||((((_sharp_peeked_char_alt627 == 91))||(((((((int) _sharp_peeked_char_alt627 >= (int) 97))&&(((int) _sharp_peeked_char_alt627 <= (int) 122))))||((((_sharp_peeked_char_alt627 == 95))||(((((((int) _sharp_peeked_char_alt627 >= (int) 65))&&(((int) _sharp_peeked_char_alt627 <= (int) 90))))||((((_sharp_peeked_char_alt627 == 60))||(((Bool__type ) 0))))))))))))))?
(({
Int__type _sharp_peeked_char_alt628;
(_sharp_peeked_char_alt628 = (peek_char)());
(((((_sharp_peeked_char_alt628 == 60))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Grouping)()):
((((((_sharp_peeked_char_alt628 == 34))||((((_sharp_peeked_char_alt628 == 91))||(((((((int) _sharp_peeked_char_alt628 >= (int) 97))&&(((int) _sharp_peeked_char_alt628 <= (int) 122))))||((((_sharp_peeked_char_alt628 == 95))||(((((((int) _sharp_peeked_char_alt628 >= (int) 65))&&(((int) _sharp_peeked_char_alt628 <= (int) 90))))||(((Bool__type ) 0))))))))))))?
(({
Int__type _sharp_peeked_char_alt629;
(_sharp_peeked_char_alt629 = (peek_char)());
((((((((int) _sharp_peeked_char_alt629 >= (int) 97))&&(((int) _sharp_peeked_char_alt629 <= (int) 122))))||((((_sharp_peeked_char_alt629 == 95))||(((((((int) _sharp_peeked_char_alt629 >= (int) 65))&&(((int) _sharp_peeked_char_alt629 <= (int) 90))))||(((Bool__type ) 0))))))))?
((_l__parse__parse_grammar__Callable_Rule)()):
((((((_sharp_peeked_char_alt629 == 34))||((((_sharp_peeked_char_alt629 == 91))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt630;
(_sharp_peeked_char_alt630 = (peek_char)());
(((((_sharp_peeked_char_alt630 == 91))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Character_Set)()):
((((((_sharp_peeked_char_alt630 == 34))||(((Bool__type ) 0))))?
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
;
})
;}

Form__type  _l__parse__parse_grammar__Postfix(void)
{
return ({
Int__type start;
Form__type form;
Int__type end;
(form = (_l__parse__parse_grammar__Primary)()),
({
Int__type _sharp_peeked_char_maybe631;
(_sharp_peeked_char_maybe631 = (peek_char)());
({if( (((_sharp_peeked_char_maybe631 == 63))||((((_sharp_peeked_char_maybe631 == 42))||((((_sharp_peeked_char_maybe631 == 43))||(((Bool__type ) 0))))))))
{
(start = (get_point_pos)()),
({
Int__type _sharp_peeked_char_alt632;
(_sharp_peeked_char_alt632 = (peek_char)());
(((((_sharp_peeked_char_alt632 == 43))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt632 == 63))||((((_sharp_peeked_char_alt632 == 42))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt633;
(_sharp_peeked_char_alt633 = (peek_char)());
(((((_sharp_peeked_char_alt633 == 42))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt633 == 63))||(((Bool__type ) 0))))?
((read_char)()):
((parse_error)()))));
})
):
((parse_error)()))));
})
,
(end = (get_point_pos)()),
(form = (Compound_Form)((intern_string)((substring)(start, end)), ({
struct struct0x08066050 *_sharp_pair_634;
_sharp_pair_634,
(_sharp_pair_634 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_634).car) = form);
(((* _sharp_pair_634).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_634);
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
void **_sharp_make_list_ptr637;
Form__type post;
List__O__Form__C____type__type post_list;
(_l__parse__parse_grammar__Spacing)(),
(post_list = ({
List__O__Form__C____type__type _sharp_make_list636;
_sharp_make_list636,
_sharp_make_list_ptr637,
(_sharp_make_list_ptr637 = ((void *) (&_sharp_make_list636))),
((void) 0);_sharp__sharp_loop638_begin640:((void) 0),
({
Int__type _sharp_peeked_char_star635;
(_sharp_peeked_char_star635 = (peek_char)());
({if( (!((((_sharp_peeked_char_star635 == 34))||((((_sharp_peeked_char_star635 == 91))||(((((((int) _sharp_peeked_char_star635 >= (int) 97))&&(((int) _sharp_peeked_char_star635 <= (int) 122))))||((((_sharp_peeked_char_star635 == 95))||(((((((int) _sharp_peeked_char_star635 >= (int) 65))&&(((int) _sharp_peeked_char_star635 <= (int) 90))))||((((_sharp_peeked_char_star635 == 60))||((((_sharp_peeked_char_star635 == 123))||((((_sharp_peeked_char_star635 == 40))||(((Bool__type ) 0))))))))))))))))))))
{
({goto _sharp__sharp_loop638_end639;});}})
;
(post = (_l__parse__parse_grammar__Postfix)()),
(_l__parse__parse_grammar__Spacing)(),
((* _sharp_make_list_ptr637) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08526d78 **) _sharp_make_list_ptr637))).car) = ((void *) post)),
(_sharp_make_list_ptr637 = (&((* (* ((struct struct0x08526d78 **) _sharp_make_list_ptr637))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop638_begin640;}),
((void) 0);_sharp__sharp_loop638_end639:((void) 0),
((* _sharp_make_list_ptr637) = ((void *) 0)),
_sharp_make_list636;
})
),
(((((* ((struct struct0x0805f098 *) post_list)).tail) == ((List__O__Form__C____type__type ) 0)))?
(((* ((struct struct0x0805f098 *) post_list)).head)):
((Compound_Form)(intern( " "), post_list)));
})
;}

Form__type  _l__parse__parse_grammar__Alternative(void)
{
return ({
Form__type sec;
Form__type prim;
(prim = (_l__parse__parse_grammar__Sequence)()),
((void) 0);_sharp__sharp_loop644_begin646:((void) 0),
({
Int__type _sharp_peeked_char_star641;
(_sharp_peeked_char_star641 = (peek_char)());
({if( (!((((_sharp_peeked_char_star641 == 124))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop644_end645;});}})
;
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(sec = (_l__parse__parse_grammar__Sequence)()),
(prim = (Compound_Form)(intern( "|"), ({
struct struct0x08066050 *_sharp_pair_643;
_sharp_pair_643,
(_sharp_pair_643 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_643).car) = prim);
(((* _sharp_pair_643).cdr) = ({
struct struct0x08066050 *_sharp_pair_642;
_sharp_pair_642,
(_sharp_pair_642 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_642).car) = sec);
(((* _sharp_pair_642).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_642);
})
);
((List__O__Form__C____type__type ) _sharp_pair_643);
})
));
})
,
({goto _sharp__sharp_loop644_begin646;}),
((void) 0);_sharp__sharp_loop644_end645:((void) 0),
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
struct struct0x08066050 *_sharp_pair_649;
_sharp_pair_649,
(_sharp_pair_649 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_649).car) = (Id_Form)(id));
(((* _sharp_pair_649).cdr) = ({
struct struct0x08066050 *_sharp_pair_648;
_sharp_pair_648,
(_sharp_pair_648 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_648).car) = ret_type);
(((* _sharp_pair_648).cdr) = ({
struct struct0x08066050 *_sharp_pair_647;
_sharp_pair_647,
(_sharp_pair_647 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_647).car) = r);
(((* _sharp_pair_647).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_647);
})
);
((List__O__Form__C____type__type ) _sharp_pair_648);
})
);
((List__O__Form__C____type__type ) _sharp_pair_649);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Grammar(void)
{
return ({
void **_sharp_make_list_ptr652;
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
List__O__Form__C____type__type _sharp_make_list651;
_sharp_make_list651,
_sharp_make_list_ptr652,
(_sharp_make_list_ptr652 = ((void *) (&_sharp_make_list651))),
((void) 0);_sharp__sharp_loop653_begin655:((void) 0),
({
Int__type _sharp_peeked_char_star650;
(_sharp_peeked_char_star650 = (peek_char)());
({if( (!((((_sharp_peeked_char_star650 == 114))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop653_end654;});}})
;
(gr = (_l__parse__parse_grammar__Grammar_Rule)()),
((* _sharp_make_list_ptr652) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08526d78 **) _sharp_make_list_ptr652))).car) = ((void *) gr)),
(_sharp_make_list_ptr652 = (&((* (* ((struct struct0x08526d78 **) _sharp_make_list_ptr652))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop653_begin655;}),
((void) 0);_sharp__sharp_loop653_end654:((void) 0),
((* _sharp_make_list_ptr652) = ((void *) 0)),
_sharp_make_list651;
})
),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(Compound_Form)(intern( "define"), ({
struct struct0x08066050 *_sharp_pair_657;
_sharp_pair_657,
(_sharp_pair_657 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_657).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_657).cdr) = ({
struct struct0x08066050 *_sharp_pair_656;
_sharp_pair_656,
(_sharp_pair_656 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_656).car) = (Id_Form)(id));
(((* _sharp_pair_656).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_656);
})
);
((List__O__Form__C____type__type ) _sharp_pair_657);
})
);
})
;}
