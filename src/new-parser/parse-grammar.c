/* Automatically generated : do not edit!*/
#include "parse-grammar.inc"
Int__type  _l__parse__parse_grammar__Comment(void)
{
return ({
(read_char)(),
(read_char)(),
((void) 0);_sharp__sharp_loop597_begin599:((void) 0),
({
Int__type _sharp_peeked_char_star596;
(_sharp_peeked_char_star596 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star596 >= (int) 11))&&(((int) _sharp_peeked_char_star596 <= (int) 255))))||(((((((int) _sharp_peeked_char_star596 >= (int) 0))&&(((int) _sharp_peeked_char_star596 <= (int) 9))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop597_end598;});}})
;
(read_char)();
})
,
({goto _sharp__sharp_loop597_begin599;}),
((void) 0);_sharp__sharp_loop597_end598:((void) 0),
(read_char)();
})
;}

void  _l__parse__parse_grammar__Spacing(void)
{
return ({
((void) 0);_sharp__sharp_loop602_begin604:((void) 0),
({
Int__type _sharp_peeked_char_star600;
(_sharp_peeked_char_star600 = (peek_char)());
({if( (!((((_sharp_peeked_char_star600 == 32))||((((_sharp_peeked_char_star600 == 10))||((((_sharp_peeked_char_star600 == 9))||((((_sharp_peeked_char_star600 == 47))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop602_end603;});}})
;
({
Int__type _sharp_peeked_char_alt601;
(_sharp_peeked_char_alt601 = (peek_char)());
(((((_sharp_peeked_char_alt601 == 47))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Comment)()):
((((((_sharp_peeked_char_alt601 == 32))||((((_sharp_peeked_char_alt601 == 10))||((((_sharp_peeked_char_alt601 == 9))||(((Bool__type ) 0))))))))?
((read_char)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop602_begin604;}),
((void) 0);_sharp__sharp_loop602_end603:((void) 0);
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
((void) 0);_sharp__sharp_loop606_begin608:((void) 0),
({
Int__type _sharp_peeked_char_star605;
(_sharp_peeked_char_star605 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star605 >= (int) 97))&&(((int) _sharp_peeked_char_star605 <= (int) 122))))||((((_sharp_peeked_char_star605 == 95))||(((((((int) _sharp_peeked_char_star605 >= (int) 65))&&(((int) _sharp_peeked_char_star605 <= (int) 90))))||(((((((int) _sharp_peeked_char_star605 >= (int) 48))&&(((int) _sharp_peeked_char_star605 <= (int) 57))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop606_end607;});}})
;
(_l__parse__parse_grammar__Alpha_Num)();
})
,
({goto _sharp__sharp_loop606_begin608;}),
((void) 0);_sharp__sharp_loop606_end607:((void) 0),
(end = (get_point_pos)()),
(intern_string)((substring)(start, end));
})
;}

Int__type  _l__parse__parse_grammar__Escaped_Character(void)
{
return ({
(read_char)(),
({
Int__type _sharp_peeked_char_alt609;
(_sharp_peeked_char_alt609 = (peek_char)());
((((((((int) _sharp_peeked_char_alt609 >= (int) 117))&&(((int) _sharp_peeked_char_alt609 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt609 >= (int) 111))&&(((int) _sharp_peeked_char_alt609 <= (int) 115))))||(((((((int) _sharp_peeked_char_alt609 >= (int) 0))&&(((int) _sharp_peeked_char_alt609 <= (int) 109))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt609 == 110))||((((_sharp_peeked_char_alt609 == 116))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt610;
(_sharp_peeked_char_alt610 = (peek_char)());
(((((_sharp_peeked_char_alt610 == 116))||(((Bool__type ) 0))))?
((read_char)(),
9):
((((((_sharp_peeked_char_alt610 == 110))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_alt611;
(_sharp_peeked_char_alt611 = (peek_char)());
((((((((int) _sharp_peeked_char_alt611 >= (int) 93))&&(((int) _sharp_peeked_char_alt611 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt611 >= (int) 0))&&(((int) _sharp_peeked_char_alt611 <= (int) 91))))||(((Bool__type ) 0))))))?
((read_char)()):
((((((_sharp_peeked_char_alt611 == 92))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_alt612;
(_sharp_peeked_char_alt612 = (peek_char)());
((((((((int) _sharp_peeked_char_alt612 >= (int) 94))&&(((int) _sharp_peeked_char_alt612 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt612 >= (int) 93))&&(((int) _sharp_peeked_char_alt612 <= (int) 92))))||(((((((int) _sharp_peeked_char_alt612 >= (int) 0))&&(((int) _sharp_peeked_char_alt612 <= (int) 91))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt612 == 92))||(((Bool__type ) 0))))?
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
((void) 0);_sharp__sharp_loop615_begin617:((void) 0),
({
Int__type _sharp_peeked_char_star613;
(_sharp_peeked_char_star613 = (peek_char)());
({if( (!((((_sharp_peeked_char_star613 == 92))||(((((((int) _sharp_peeked_char_star613 >= (int) 93))&&(((int) _sharp_peeked_char_star613 <= (int) 255))))||(((((((int) _sharp_peeked_char_star613 >= (int) 35))&&(((int) _sharp_peeked_char_star613 <= (int) 91))))||(((((((int) _sharp_peeked_char_star613 >= (int) 0))&&(((int) _sharp_peeked_char_star613 <= (int) 33))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop615_end616;});}})
;
({
Int__type _sharp_peeked_char_alt614;
(_sharp_peeked_char_alt614 = (peek_char)());
((((((((int) _sharp_peeked_char_alt614 >= (int) 93))&&(((int) _sharp_peeked_char_alt614 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt614 >= (int) 35))&&(((int) _sharp_peeked_char_alt614 <= (int) 91))))||(((((((int) _sharp_peeked_char_alt614 >= (int) 0))&&(((int) _sharp_peeked_char_alt614 <= (int) 33))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt614 == 92))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop615_begin617;}),
((void) 0);_sharp__sharp_loop615_end616:((void) 0),
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
Int__type _sharp_peeked_char_maybe618;
(_sharp_peeked_char_maybe618 = (peek_char)());
({if( (((_sharp_peeked_char_maybe618 == 45))||(((Bool__type ) 0))))
{
(read_char)(),
(max = (_l__parse__parse_grammar__Maybe_Escaped_Character)());}})
;
})
,
(((min == max))?
((Int_Form)(min)):
((Compound_Form)(intern( "-"), ({
struct struct0x08066050 *_sharp_pair_620;
_sharp_pair_620,
(_sharp_pair_620 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_620).car) = (Int_Form)(min));
(((* _sharp_pair_620).cdr) = ({
struct struct0x08066050 *_sharp_pair_619;
_sharp_pair_619,
(_sharp_pair_619 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_619).car) = (Int_Form)(max));
(((* _sharp_pair_619).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_619);
})
);
((List__O__Form__C____type__type ) _sharp_pair_620);
})
)));
})
;}

Form__type  _l__parse__parse_grammar__Character_Set(void)
{
return ({
void **_sharp_make_list_ptr624;
Symbol__type char_selector;
List__O__Form__C____type__type cr_list;
Form__type cr;
(char_selector = intern( "[]")),
(read_char)(),
({
Int__type _sharp_peeked_char_maybe621;
(_sharp_peeked_char_maybe621 = (peek_char)());
({if( (((_sharp_peeked_char_maybe621 == 94))||(((Bool__type ) 0))))
{
(read_char)(),
(char_selector = intern( "[^]"));}})
;
})
,
(cr_list = ({
List__O__Form__C____type__type _sharp_make_list623;
_sharp_make_list623,
_sharp_make_list_ptr624,
(_sharp_make_list_ptr624 = ((void *) (&_sharp_make_list623))),
((void) 0);_sharp__sharp_loop625_begin627:((void) 0),
({
Int__type _sharp_peeked_char_star622;
(_sharp_peeked_char_star622 = (peek_char)());
({if( (!((((_sharp_peeked_char_star622 == 92))||(((((((int) _sharp_peeked_char_star622 >= (int) 94))&&(((int) _sharp_peeked_char_star622 <= (int) 255))))||(((((((int) _sharp_peeked_char_star622 >= (int) 93))&&(((int) _sharp_peeked_char_star622 <= (int) 92))))||(((((((int) _sharp_peeked_char_star622 >= (int) 0))&&(((int) _sharp_peeked_char_star622 <= (int) 91))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop625_end626;});}})
;
(cr = (_l__parse__parse_grammar__Character_Range)()),
((* _sharp_make_list_ptr624) = (alloc_cons_cell)()),
(((* (* ((struct struct0x085285e8 **) _sharp_make_list_ptr624))).car) = ((void *) cr)),
(_sharp_make_list_ptr624 = (&((* (* ((struct struct0x085285e8 **) _sharp_make_list_ptr624))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop625_begin627;}),
((void) 0);_sharp__sharp_loop625_end626:((void) 0),
((* _sharp_make_list_ptr624) = ((void *) 0)),
_sharp_make_list623;
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
Int__type _sharp_peeked_char_maybe628;
(_sharp_peeked_char_maybe628 = (peek_char)());
({if( (((_sharp_peeked_char_maybe628 == 46))||(((Bool__type ) 0))))
{
(read_char)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(form = (Compound_Form)(intern( "."), ({
struct struct0x08066050 *_sharp_pair_630;
_sharp_pair_630,
(_sharp_pair_630 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_630).car) = form);
(((* _sharp_pair_630).cdr) = ({
struct struct0x08066050 *_sharp_pair_629;
_sharp_pair_629,
(_sharp_pair_629 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_629).car) = (Id_Form)(id));
(((* _sharp_pair_629).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_629);
})
);
((List__O__Form__C____type__type ) _sharp_pair_630);
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
struct struct0x08066050 *_sharp_pair_631;
_sharp_pair_631,
(_sharp_pair_631 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_631).car) = exp);
(((* _sharp_pair_631).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_631);
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
struct struct0x08066050 *_sharp_pair_633;
_sharp_pair_633,
(_sharp_pair_633 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_633).car) = (Id_Form)(id));
(((* _sharp_pair_633).cdr) = ({
struct struct0x08066050 *_sharp_pair_632;
_sharp_pair_632,
(_sharp_pair_632 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_632).car) = form);
(((* _sharp_pair_632).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_632);
})
);
((List__O__Form__C____type__type ) _sharp_pair_633);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Primary(void)
{
return ({
Form__type r;
({
Int__type _sharp_peeked_char_alt634;
(_sharp_peeked_char_alt634 = (peek_char)());
(((((_sharp_peeked_char_alt634 == 40))||(((Bool__type ) 0))))?
((read_char)(),
(r = (_l__parse__parse_grammar__Rule)()),
(read_char)(),
r):
((((((_sharp_peeked_char_alt634 == 34))||((((_sharp_peeked_char_alt634 == 91))||(((((((int) _sharp_peeked_char_alt634 >= (int) 97))&&(((int) _sharp_peeked_char_alt634 <= (int) 122))))||((((_sharp_peeked_char_alt634 == 95))||(((((((int) _sharp_peeked_char_alt634 >= (int) 65))&&(((int) _sharp_peeked_char_alt634 <= (int) 90))))||((((_sharp_peeked_char_alt634 == 60))||((((_sharp_peeked_char_alt634 == 123))||(((Bool__type ) 0))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt635;
(_sharp_peeked_char_alt635 = (peek_char)());
(((((_sharp_peeked_char_alt635 == 123))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Semantic_Action)()):
((((((_sharp_peeked_char_alt635 == 34))||((((_sharp_peeked_char_alt635 == 91))||(((((((int) _sharp_peeked_char_alt635 >= (int) 97))&&(((int) _sharp_peeked_char_alt635 <= (int) 122))))||((((_sharp_peeked_char_alt635 == 95))||(((((((int) _sharp_peeked_char_alt635 >= (int) 65))&&(((int) _sharp_peeked_char_alt635 <= (int) 90))))||((((_sharp_peeked_char_alt635 == 60))||(((Bool__type ) 0))))))))))))))?
(({
Int__type _sharp_peeked_char_alt636;
(_sharp_peeked_char_alt636 = (peek_char)());
(((((_sharp_peeked_char_alt636 == 60))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Grouping)()):
((((((_sharp_peeked_char_alt636 == 34))||((((_sharp_peeked_char_alt636 == 91))||(((((((int) _sharp_peeked_char_alt636 >= (int) 97))&&(((int) _sharp_peeked_char_alt636 <= (int) 122))))||((((_sharp_peeked_char_alt636 == 95))||(((((((int) _sharp_peeked_char_alt636 >= (int) 65))&&(((int) _sharp_peeked_char_alt636 <= (int) 90))))||(((Bool__type ) 0))))))))))))?
(({
Int__type _sharp_peeked_char_alt637;
(_sharp_peeked_char_alt637 = (peek_char)());
((((((((int) _sharp_peeked_char_alt637 >= (int) 97))&&(((int) _sharp_peeked_char_alt637 <= (int) 122))))||((((_sharp_peeked_char_alt637 == 95))||(((((((int) _sharp_peeked_char_alt637 >= (int) 65))&&(((int) _sharp_peeked_char_alt637 <= (int) 90))))||(((Bool__type ) 0))))))))?
((_l__parse__parse_grammar__Callable_Rule)()):
((((((_sharp_peeked_char_alt637 == 34))||((((_sharp_peeked_char_alt637 == 91))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt638;
(_sharp_peeked_char_alt638 = (peek_char)());
(((((_sharp_peeked_char_alt638 == 91))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Character_Set)()):
((((((_sharp_peeked_char_alt638 == 34))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_maybe639;
(_sharp_peeked_char_maybe639 = (peek_char)());
({if( (((_sharp_peeked_char_maybe639 == 63))||((((_sharp_peeked_char_maybe639 == 42))||((((_sharp_peeked_char_maybe639 == 43))||(((Bool__type ) 0))))))))
{
(start = (get_point_pos)()),
({
Int__type _sharp_peeked_char_alt640;
(_sharp_peeked_char_alt640 = (peek_char)());
(((((_sharp_peeked_char_alt640 == 43))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt640 == 63))||((((_sharp_peeked_char_alt640 == 42))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt641;
(_sharp_peeked_char_alt641 = (peek_char)());
(((((_sharp_peeked_char_alt641 == 42))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt641 == 63))||(((Bool__type ) 0))))?
((read_char)()):
((parse_error)()))));
})
):
((parse_error)()))));
})
,
(end = (get_point_pos)()),
(form = (Compound_Form)((intern_string)((substring)(start, end)), ({
struct struct0x08066050 *_sharp_pair_642;
_sharp_pair_642,
(_sharp_pair_642 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_642).car) = form);
(((* _sharp_pair_642).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_642);
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
void **_sharp_make_list_ptr645;
Form__type post;
List__O__Form__C____type__type post_list;
(_l__parse__parse_grammar__Spacing)(),
(post_list = ({
List__O__Form__C____type__type _sharp_make_list644;
_sharp_make_list644,
_sharp_make_list_ptr645,
(_sharp_make_list_ptr645 = ((void *) (&_sharp_make_list644))),
((void) 0);_sharp__sharp_loop646_begin648:((void) 0),
({
Int__type _sharp_peeked_char_star643;
(_sharp_peeked_char_star643 = (peek_char)());
({if( (!((((_sharp_peeked_char_star643 == 34))||((((_sharp_peeked_char_star643 == 91))||(((((((int) _sharp_peeked_char_star643 >= (int) 97))&&(((int) _sharp_peeked_char_star643 <= (int) 122))))||((((_sharp_peeked_char_star643 == 95))||(((((((int) _sharp_peeked_char_star643 >= (int) 65))&&(((int) _sharp_peeked_char_star643 <= (int) 90))))||((((_sharp_peeked_char_star643 == 60))||((((_sharp_peeked_char_star643 == 123))||((((_sharp_peeked_char_star643 == 40))||(((Bool__type ) 0))))))))))))))))))))
{
({goto _sharp__sharp_loop646_end647;});}})
;
(post = (_l__parse__parse_grammar__Postfix)()),
(_l__parse__parse_grammar__Spacing)(),
((* _sharp_make_list_ptr645) = (alloc_cons_cell)()),
(((* (* ((struct struct0x085285e8 **) _sharp_make_list_ptr645))).car) = ((void *) post)),
(_sharp_make_list_ptr645 = (&((* (* ((struct struct0x085285e8 **) _sharp_make_list_ptr645))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop646_begin648;}),
((void) 0);_sharp__sharp_loop646_end647:((void) 0),
((* _sharp_make_list_ptr645) = ((void *) 0)),
_sharp_make_list644;
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
((void) 0);_sharp__sharp_loop652_begin654:((void) 0),
({
Int__type _sharp_peeked_char_star649;
(_sharp_peeked_char_star649 = (peek_char)());
({if( (!((((_sharp_peeked_char_star649 == 124))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop652_end653;});}})
;
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(sec = (_l__parse__parse_grammar__Sequence)()),
(prim = (Compound_Form)(intern( "|"), ({
struct struct0x08066050 *_sharp_pair_651;
_sharp_pair_651,
(_sharp_pair_651 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_651).car) = prim);
(((* _sharp_pair_651).cdr) = ({
struct struct0x08066050 *_sharp_pair_650;
_sharp_pair_650,
(_sharp_pair_650 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_650).car) = sec);
(((* _sharp_pair_650).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_650);
})
);
((List__O__Form__C____type__type ) _sharp_pair_651);
})
));
})
,
({goto _sharp__sharp_loop652_begin654;}),
((void) 0);_sharp__sharp_loop652_end653:((void) 0),
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
struct struct0x08066050 *_sharp_pair_657;
_sharp_pair_657,
(_sharp_pair_657 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_657).car) = (Id_Form)(id));
(((* _sharp_pair_657).cdr) = ({
struct struct0x08066050 *_sharp_pair_656;
_sharp_pair_656,
(_sharp_pair_656 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_656).car) = ret_type);
(((* _sharp_pair_656).cdr) = ({
struct struct0x08066050 *_sharp_pair_655;
_sharp_pair_655,
(_sharp_pair_655 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_655).car) = r);
(((* _sharp_pair_655).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_655);
})
);
((List__O__Form__C____type__type ) _sharp_pair_656);
})
);
((List__O__Form__C____type__type ) _sharp_pair_657);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Grammar(void)
{
return ({
void **_sharp_make_list_ptr660;
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
List__O__Form__C____type__type _sharp_make_list659;
_sharp_make_list659,
_sharp_make_list_ptr660,
(_sharp_make_list_ptr660 = ((void *) (&_sharp_make_list659))),
((void) 0);_sharp__sharp_loop661_begin663:((void) 0),
({
Int__type _sharp_peeked_char_star658;
(_sharp_peeked_char_star658 = (peek_char)());
({if( (!((((_sharp_peeked_char_star658 == 114))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop661_end662;});}})
;
(gr = (_l__parse__parse_grammar__Grammar_Rule)()),
((* _sharp_make_list_ptr660) = (alloc_cons_cell)()),
(((* (* ((struct struct0x085285e8 **) _sharp_make_list_ptr660))).car) = ((void *) gr)),
(_sharp_make_list_ptr660 = (&((* (* ((struct struct0x085285e8 **) _sharp_make_list_ptr660))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop661_begin663;}),
((void) 0);_sharp__sharp_loop661_end662:((void) 0),
((* _sharp_make_list_ptr660) = ((void *) 0)),
_sharp_make_list659;
})
),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(Compound_Form)(intern( "define"), ({
struct struct0x08066050 *_sharp_pair_665;
_sharp_pair_665,
(_sharp_pair_665 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_665).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_665).cdr) = ({
struct struct0x08066050 *_sharp_pair_664;
_sharp_pair_664,
(_sharp_pair_664 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_664).car) = (Id_Form)(id));
(((* _sharp_pair_664).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_664);
})
);
((List__O__Form__C____type__type ) _sharp_pair_665);
})
);
})
;}
