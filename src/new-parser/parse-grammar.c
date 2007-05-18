/* Automatically generated : do not edit!*/
#include "parse-grammar.inc"
Int__type  _l__parse__parse_grammar__Comment(void)
{
return ({
(read_char)(),
(read_char)(),
((void) 0);_sharp__sharp_loop581_begin583:((void) 0),
({
Int__type _sharp_peeked_char_star580;
(_sharp_peeked_char_star580 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star580 >= (int) 11))&&(((int) _sharp_peeked_char_star580 <= (int) 255))))||(((((((int) _sharp_peeked_char_star580 >= (int) 0))&&(((int) _sharp_peeked_char_star580 <= (int) 9))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop581_end582;});}})
;
(read_char)();
})
,
({goto _sharp__sharp_loop581_begin583;}),
((void) 0);_sharp__sharp_loop581_end582:((void) 0),
(read_char)(),
(read_char)();
})
;}

void  _l__parse__parse_grammar__Spacing(void)
{
return ({
((void) 0);_sharp__sharp_loop586_begin588:((void) 0),
({
Int__type _sharp_peeked_char_star584;
(_sharp_peeked_char_star584 = (peek_char)());
({if( (!((((_sharp_peeked_char_star584 == 32))||((((_sharp_peeked_char_star584 == 10))||((((_sharp_peeked_char_star584 == 9))||((((_sharp_peeked_char_star584 == 47))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop586_end587;});}})
;
({
Int__type _sharp_peeked_char_alt585;
(_sharp_peeked_char_alt585 = (peek_char)());
(((((_sharp_peeked_char_alt585 == 47))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Comment)()):
((((((_sharp_peeked_char_alt585 == 32))||((((_sharp_peeked_char_alt585 == 10))||((((_sharp_peeked_char_alt585 == 9))||(((Bool__type ) 0))))))))?
((read_char)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop586_begin588;}),
((void) 0);_sharp__sharp_loop586_end587:((void) 0);
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
((void) 0);_sharp__sharp_loop590_begin592:((void) 0),
({
Int__type _sharp_peeked_char_star589;
(_sharp_peeked_char_star589 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star589 >= (int) 97))&&(((int) _sharp_peeked_char_star589 <= (int) 122))))||((((_sharp_peeked_char_star589 == 95))||(((((((int) _sharp_peeked_char_star589 >= (int) 65))&&(((int) _sharp_peeked_char_star589 <= (int) 90))))||(((((((int) _sharp_peeked_char_star589 >= (int) 48))&&(((int) _sharp_peeked_char_star589 <= (int) 57))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop590_end591;});}})
;
(_l__parse__parse_grammar__Alpha_Num)();
})
,
({goto _sharp__sharp_loop590_begin592;}),
((void) 0);_sharp__sharp_loop590_end591:((void) 0),
(end = (get_point_pos)()),
(intern_string)((substring)(start, end));
})
;}

Int__type  _l__parse__parse_grammar__Escaped_Character(void)
{
return ({
(read_char)(),
({
Int__type _sharp_peeked_char_alt593;
(_sharp_peeked_char_alt593 = (peek_char)());
((((((((int) _sharp_peeked_char_alt593 >= (int) 117))&&(((int) _sharp_peeked_char_alt593 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt593 >= (int) 111))&&(((int) _sharp_peeked_char_alt593 <= (int) 115))))||(((((((int) _sharp_peeked_char_alt593 >= (int) 0))&&(((int) _sharp_peeked_char_alt593 <= (int) 109))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt593 == 110))||((((_sharp_peeked_char_alt593 == 116))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt594;
(_sharp_peeked_char_alt594 = (peek_char)());
(((((_sharp_peeked_char_alt594 == 116))||(((Bool__type ) 0))))?
((read_char)(),
9):
((((((_sharp_peeked_char_alt594 == 110))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_alt595;
(_sharp_peeked_char_alt595 = (peek_char)());
((((((((int) _sharp_peeked_char_alt595 >= (int) 93))&&(((int) _sharp_peeked_char_alt595 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt595 >= (int) 0))&&(((int) _sharp_peeked_char_alt595 <= (int) 91))))||(((Bool__type ) 0))))))?
((read_char)()):
((((((_sharp_peeked_char_alt595 == 92))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_alt596;
(_sharp_peeked_char_alt596 = (peek_char)());
((((((((int) _sharp_peeked_char_alt596 >= (int) 94))&&(((int) _sharp_peeked_char_alt596 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt596 >= (int) 93))&&(((int) _sharp_peeked_char_alt596 <= (int) 92))))||(((((((int) _sharp_peeked_char_alt596 >= (int) 0))&&(((int) _sharp_peeked_char_alt596 <= (int) 91))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt596 == 92))||(((Bool__type ) 0))))?
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
((void) 0);_sharp__sharp_loop599_begin601:((void) 0),
({
Int__type _sharp_peeked_char_star597;
(_sharp_peeked_char_star597 = (peek_char)());
({if( (!((((_sharp_peeked_char_star597 == 92))||(((((((int) _sharp_peeked_char_star597 >= (int) 93))&&(((int) _sharp_peeked_char_star597 <= (int) 255))))||(((((((int) _sharp_peeked_char_star597 >= (int) 35))&&(((int) _sharp_peeked_char_star597 <= (int) 91))))||(((((((int) _sharp_peeked_char_star597 >= (int) 0))&&(((int) _sharp_peeked_char_star597 <= (int) 33))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop599_end600;});}})
;
({
Int__type _sharp_peeked_char_alt598;
(_sharp_peeked_char_alt598 = (peek_char)());
((((((((int) _sharp_peeked_char_alt598 >= (int) 93))&&(((int) _sharp_peeked_char_alt598 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt598 >= (int) 35))&&(((int) _sharp_peeked_char_alt598 <= (int) 91))))||(((((((int) _sharp_peeked_char_alt598 >= (int) 0))&&(((int) _sharp_peeked_char_alt598 <= (int) 33))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt598 == 92))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop599_begin601;}),
((void) 0);_sharp__sharp_loop599_end600:((void) 0),
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
Int__type _sharp_peeked_char_maybe602;
(_sharp_peeked_char_maybe602 = (peek_char)());
({if( (((_sharp_peeked_char_maybe602 == 45))||(((Bool__type ) 0))))
{
(read_char)(),
(max = (_l__parse__parse_grammar__Maybe_Escaped_Character)());}})
;
})
,
(((min == max))?
((Int_Form)(min)):
((Compound_Form)(intern( "-"), ({
struct struct0x08066050 *_sharp_pair_604;
_sharp_pair_604,
(_sharp_pair_604 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_604).car) = (Int_Form)(min));
(((* _sharp_pair_604).cdr) = ({
struct struct0x08066050 *_sharp_pair_603;
_sharp_pair_603,
(_sharp_pair_603 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_603).car) = (Int_Form)(max));
(((* _sharp_pair_603).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_603);
})
);
((List__O__Form__C____type__type ) _sharp_pair_604);
})
)));
})
;}

Form__type  _l__parse__parse_grammar__Character_Set(void)
{
return ({
void **_sharp_make_list_ptr608;
Symbol__type char_selector;
List__O__Form__C____type__type cr_list;
Form__type cr;
(char_selector = intern( "[]")),
(read_char)(),
({
Int__type _sharp_peeked_char_maybe605;
(_sharp_peeked_char_maybe605 = (peek_char)());
({if( (((_sharp_peeked_char_maybe605 == 94))||(((Bool__type ) 0))))
{
(read_char)(),
(char_selector = intern( "[^]"));}})
;
})
,
(cr_list = ({
List__O__Form__C____type__type _sharp_make_list607;
_sharp_make_list607,
_sharp_make_list_ptr608,
(_sharp_make_list_ptr608 = ((void *) (&_sharp_make_list607))),
((void) 0);_sharp__sharp_loop609_begin611:((void) 0),
({
Int__type _sharp_peeked_char_star606;
(_sharp_peeked_char_star606 = (peek_char)());
({if( (!((((_sharp_peeked_char_star606 == 92))||(((((((int) _sharp_peeked_char_star606 >= (int) 94))&&(((int) _sharp_peeked_char_star606 <= (int) 255))))||(((((((int) _sharp_peeked_char_star606 >= (int) 93))&&(((int) _sharp_peeked_char_star606 <= (int) 92))))||(((((((int) _sharp_peeked_char_star606 >= (int) 0))&&(((int) _sharp_peeked_char_star606 <= (int) 91))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop609_end610;});}})
;
(cr = (_l__parse__parse_grammar__Character_Range)()),
((* _sharp_make_list_ptr608) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08525e00 **) _sharp_make_list_ptr608))).car) = ((void *) cr)),
(_sharp_make_list_ptr608 = (&((* (* ((struct struct0x08525e00 **) _sharp_make_list_ptr608))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop609_begin611;}),
((void) 0);_sharp__sharp_loop609_end610:((void) 0),
((* _sharp_make_list_ptr608) = ((void *) 0)),
_sharp_make_list607;
})
),
(read_char)(),
(Compound_Form)(char_selector, cr_list);
})
;}

Form__type  _l__parse__parse_grammar__Callable_Rule(void)
{
return ({
Symbol__type id;
(id = (_l__parse__parse_grammar__Identifier)()),
(Id_Form)(id);
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
struct struct0x08066050 *_sharp_pair_612;
_sharp_pair_612,
(_sharp_pair_612 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_612).car) = exp);
(((* _sharp_pair_612).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_612);
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
struct struct0x08066050 *_sharp_pair_614;
_sharp_pair_614,
(_sharp_pair_614 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_614).car) = (Id_Form)(id));
(((* _sharp_pair_614).cdr) = ({
struct struct0x08066050 *_sharp_pair_613;
_sharp_pair_613,
(_sharp_pair_613 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_613).car) = form);
(((* _sharp_pair_613).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_613);
})
);
((List__O__Form__C____type__type ) _sharp_pair_614);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Primary(void)
{
return ({
Form__type r;
({
Int__type _sharp_peeked_char_alt615;
(_sharp_peeked_char_alt615 = (peek_char)());
(((((_sharp_peeked_char_alt615 == 40))||(((Bool__type ) 0))))?
((read_char)(),
(r = (_l__parse__parse_grammar__Rule)()),
(read_char)(),
r):
((((((_sharp_peeked_char_alt615 == 34))||((((_sharp_peeked_char_alt615 == 91))||(((((((int) _sharp_peeked_char_alt615 >= (int) 97))&&(((int) _sharp_peeked_char_alt615 <= (int) 122))))||((((_sharp_peeked_char_alt615 == 95))||(((((((int) _sharp_peeked_char_alt615 >= (int) 65))&&(((int) _sharp_peeked_char_alt615 <= (int) 90))))||((((_sharp_peeked_char_alt615 == 60))||((((_sharp_peeked_char_alt615 == 123))||(((Bool__type ) 0))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt616;
(_sharp_peeked_char_alt616 = (peek_char)());
(((((_sharp_peeked_char_alt616 == 123))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Semantic_Action)()):
((((((_sharp_peeked_char_alt616 == 34))||((((_sharp_peeked_char_alt616 == 91))||(((((((int) _sharp_peeked_char_alt616 >= (int) 97))&&(((int) _sharp_peeked_char_alt616 <= (int) 122))))||((((_sharp_peeked_char_alt616 == 95))||(((((((int) _sharp_peeked_char_alt616 >= (int) 65))&&(((int) _sharp_peeked_char_alt616 <= (int) 90))))||((((_sharp_peeked_char_alt616 == 60))||(((Bool__type ) 0))))))))))))))?
(({
Int__type _sharp_peeked_char_alt617;
(_sharp_peeked_char_alt617 = (peek_char)());
(((((_sharp_peeked_char_alt617 == 60))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Grouping)()):
((((((_sharp_peeked_char_alt617 == 34))||((((_sharp_peeked_char_alt617 == 91))||(((((((int) _sharp_peeked_char_alt617 >= (int) 97))&&(((int) _sharp_peeked_char_alt617 <= (int) 122))))||((((_sharp_peeked_char_alt617 == 95))||(((((((int) _sharp_peeked_char_alt617 >= (int) 65))&&(((int) _sharp_peeked_char_alt617 <= (int) 90))))||(((Bool__type ) 0))))))))))))?
(({
Int__type _sharp_peeked_char_alt618;
(_sharp_peeked_char_alt618 = (peek_char)());
((((((((int) _sharp_peeked_char_alt618 >= (int) 97))&&(((int) _sharp_peeked_char_alt618 <= (int) 122))))||((((_sharp_peeked_char_alt618 == 95))||(((((((int) _sharp_peeked_char_alt618 >= (int) 65))&&(((int) _sharp_peeked_char_alt618 <= (int) 90))))||(((Bool__type ) 0))))))))?
((_l__parse__parse_grammar__Callable_Rule)()):
((((((_sharp_peeked_char_alt618 == 34))||((((_sharp_peeked_char_alt618 == 91))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt619;
(_sharp_peeked_char_alt619 = (peek_char)());
(((((_sharp_peeked_char_alt619 == 91))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Character_Set)()):
((((((_sharp_peeked_char_alt619 == 34))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_maybe620;
(_sharp_peeked_char_maybe620 = (peek_char)());
({if( (((_sharp_peeked_char_maybe620 == 63))||((((_sharp_peeked_char_maybe620 == 42))||((((_sharp_peeked_char_maybe620 == 43))||(((Bool__type ) 0))))))))
{
(start = (get_point_pos)()),
({
Int__type _sharp_peeked_char_alt621;
(_sharp_peeked_char_alt621 = (peek_char)());
(((((_sharp_peeked_char_alt621 == 43))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt621 == 63))||((((_sharp_peeked_char_alt621 == 42))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt622;
(_sharp_peeked_char_alt622 = (peek_char)());
(((((_sharp_peeked_char_alt622 == 42))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt622 == 63))||(((Bool__type ) 0))))?
((read_char)()):
((parse_error)()))));
})
):
((parse_error)()))));
})
,
(end = (get_point_pos)()),
(form = (Compound_Form)((intern_string)((substring)(start, end)), ({
struct struct0x08066050 *_sharp_pair_623;
_sharp_pair_623,
(_sharp_pair_623 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_623).car) = form);
(((* _sharp_pair_623).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_623);
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
void **_sharp_make_list_ptr626;
Form__type post;
List__O__Form__C____type__type post_list;
(_l__parse__parse_grammar__Spacing)(),
(post_list = ({
List__O__Form__C____type__type _sharp_make_list625;
_sharp_make_list625,
_sharp_make_list_ptr626,
(_sharp_make_list_ptr626 = ((void *) (&_sharp_make_list625))),
((void) 0);_sharp__sharp_loop627_begin629:((void) 0),
({
Int__type _sharp_peeked_char_star624;
(_sharp_peeked_char_star624 = (peek_char)());
({if( (!((((_sharp_peeked_char_star624 == 34))||((((_sharp_peeked_char_star624 == 91))||(((((((int) _sharp_peeked_char_star624 >= (int) 97))&&(((int) _sharp_peeked_char_star624 <= (int) 122))))||((((_sharp_peeked_char_star624 == 95))||(((((((int) _sharp_peeked_char_star624 >= (int) 65))&&(((int) _sharp_peeked_char_star624 <= (int) 90))))||((((_sharp_peeked_char_star624 == 60))||((((_sharp_peeked_char_star624 == 123))||((((_sharp_peeked_char_star624 == 40))||(((Bool__type ) 0))))))))))))))))))))
{
({goto _sharp__sharp_loop627_end628;});}})
;
(post = (_l__parse__parse_grammar__Postfix)()),
(_l__parse__parse_grammar__Spacing)(),
((* _sharp_make_list_ptr626) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08525e00 **) _sharp_make_list_ptr626))).car) = ((void *) post)),
(_sharp_make_list_ptr626 = (&((* (* ((struct struct0x08525e00 **) _sharp_make_list_ptr626))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop627_begin629;}),
((void) 0);_sharp__sharp_loop627_end628:((void) 0),
((* _sharp_make_list_ptr626) = ((void *) 0)),
_sharp_make_list625;
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
((void) 0);_sharp__sharp_loop633_begin635:((void) 0),
({
Int__type _sharp_peeked_char_star630;
(_sharp_peeked_char_star630 = (peek_char)());
({if( (!((((_sharp_peeked_char_star630 == 124))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop633_end634;});}})
;
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(sec = (_l__parse__parse_grammar__Sequence)()),
(prim = (Compound_Form)(intern( "|"), ({
struct struct0x08066050 *_sharp_pair_632;
_sharp_pair_632,
(_sharp_pair_632 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_632).car) = prim);
(((* _sharp_pair_632).cdr) = ({
struct struct0x08066050 *_sharp_pair_631;
_sharp_pair_631,
(_sharp_pair_631 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_631).car) = sec);
(((* _sharp_pair_631).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_631);
})
);
((List__O__Form__C____type__type ) _sharp_pair_632);
})
));
})
,
({goto _sharp__sharp_loop633_begin635;}),
((void) 0);_sharp__sharp_loop633_end634:((void) 0),
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
struct struct0x08066050 *_sharp_pair_638;
_sharp_pair_638,
(_sharp_pair_638 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_638).car) = (Id_Form)(id));
(((* _sharp_pair_638).cdr) = ({
struct struct0x08066050 *_sharp_pair_637;
_sharp_pair_637,
(_sharp_pair_637 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_637).car) = ret_type);
(((* _sharp_pair_637).cdr) = ({
struct struct0x08066050 *_sharp_pair_636;
_sharp_pair_636,
(_sharp_pair_636 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_636).car) = r);
(((* _sharp_pair_636).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_636);
})
);
((List__O__Form__C____type__type ) _sharp_pair_637);
})
);
((List__O__Form__C____type__type ) _sharp_pair_638);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Grammar(void)
{
return ({
void **_sharp_make_list_ptr641;
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
List__O__Form__C____type__type _sharp_make_list640;
_sharp_make_list640,
_sharp_make_list_ptr641,
(_sharp_make_list_ptr641 = ((void *) (&_sharp_make_list640))),
((void) 0);_sharp__sharp_loop642_begin644:((void) 0),
({
Int__type _sharp_peeked_char_star639;
(_sharp_peeked_char_star639 = (peek_char)());
({if( (!((((_sharp_peeked_char_star639 == 114))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop642_end643;});}})
;
(gr = (_l__parse__parse_grammar__Grammar_Rule)()),
((* _sharp_make_list_ptr641) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08525e00 **) _sharp_make_list_ptr641))).car) = ((void *) gr)),
(_sharp_make_list_ptr641 = (&((* (* ((struct struct0x08525e00 **) _sharp_make_list_ptr641))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop642_begin644;}),
((void) 0);_sharp__sharp_loop642_end643:((void) 0),
((* _sharp_make_list_ptr641) = ((void *) 0)),
_sharp_make_list640;
})
),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(Compound_Form)(intern( "define"), ({
struct struct0x08066050 *_sharp_pair_646;
_sharp_pair_646,
(_sharp_pair_646 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_646).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_646).cdr) = ({
struct struct0x08066050 *_sharp_pair_645;
_sharp_pair_645,
(_sharp_pair_645 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_645).car) = (Id_Form)(id));
(((* _sharp_pair_645).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_645);
})
);
((List__O__Form__C____type__type ) _sharp_pair_646);
})
);
})
;}
