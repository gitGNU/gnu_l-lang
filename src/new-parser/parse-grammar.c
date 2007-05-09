/* Automatically generated : do not edit!*/
#include "parse-grammar.inc"

Int__type  parse_Comment(void)
{
return ({
(read_char)(),
(read_char)(),
((void) 0);_sharp__sharp_loop573_begin575:((void) 0),
({
Int__type _sharp_peeked_char_star572;
(_sharp_peeked_char_star572 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star572 >= (int) 11))&&(((int) _sharp_peeked_char_star572 <= (int) 255))))||(((((((int) _sharp_peeked_char_star572 >= (int) 0))&&(((int) _sharp_peeked_char_star572 <= (int) 9))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop573_end574;});}})
;
(read_char)();
})
,
({goto _sharp__sharp_loop573_begin575;}),
((void) 0);_sharp__sharp_loop573_end574:((void) 0),
(read_char)(),
(read_char)();
})
;}

void  parse_Spacing(void)
{
return ({
((void) 0);_sharp__sharp_loop578_begin580:((void) 0),
({
Int__type _sharp_peeked_char_star576;
(_sharp_peeked_char_star576 = (peek_char)());
({if( (!((((_sharp_peeked_char_star576 == 32))||((((_sharp_peeked_char_star576 == 10))||((((_sharp_peeked_char_star576 == 9))||((((_sharp_peeked_char_star576 == 47))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop578_end579;});}})
;
({
Int__type _sharp_peeked_char_alt577;
(_sharp_peeked_char_alt577 = (peek_char)());
(((((_sharp_peeked_char_alt577 == 47))||(((Bool__type ) 0))))?
((parse_Comment)()):
((((((_sharp_peeked_char_alt577 == 32))||((((_sharp_peeked_char_alt577 == 10))||((((_sharp_peeked_char_alt577 == 9))||(((Bool__type ) 0))))))))?
((read_char)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop578_begin580;}),
((void) 0);_sharp__sharp_loop578_end579:((void) 0);
})
;}

Int__type  parse_Alpha(void)
{
return ({
(read_char)();
})
;}

Int__type  parse_Alpha_Num(void)
{
return ({
(read_char)();
})
;}

Symbol__type  parse_Identifier(void)
{
return ({
Int__type start;
Int__type end;
(start = (get_point_pos)()),
(parse_Alpha)(),
((void) 0);_sharp__sharp_loop582_begin584:((void) 0),
({
Int__type _sharp_peeked_char_star581;
(_sharp_peeked_char_star581 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star581 >= (int) 97))&&(((int) _sharp_peeked_char_star581 <= (int) 122))))||((((_sharp_peeked_char_star581 == 95))||(((((((int) _sharp_peeked_char_star581 >= (int) 65))&&(((int) _sharp_peeked_char_star581 <= (int) 90))))||(((((((int) _sharp_peeked_char_star581 >= (int) 48))&&(((int) _sharp_peeked_char_star581 <= (int) 57))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop582_end583;});}})
;
(parse_Alpha_Num)();
})
,
({goto _sharp__sharp_loop582_begin584;}),
((void) 0);_sharp__sharp_loop582_end583:((void) 0),
(end = (get_point_pos)()),
(intern_string)((substring)(start, end));
})
;}

Int__type  parse_Escaped_Character(void)
{
return ({
(read_char)(),
({
Int__type _sharp_peeked_char_alt585;
(_sharp_peeked_char_alt585 = (peek_char)());
((((((((int) _sharp_peeked_char_alt585 >= (int) 117))&&(((int) _sharp_peeked_char_alt585 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt585 >= (int) 111))&&(((int) _sharp_peeked_char_alt585 <= (int) 115))))||(((((((int) _sharp_peeked_char_alt585 >= (int) 0))&&(((int) _sharp_peeked_char_alt585 <= (int) 109))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt585 == 110))||((((_sharp_peeked_char_alt585 == 116))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt586;
(_sharp_peeked_char_alt586 = (peek_char)());
(((((_sharp_peeked_char_alt586 == 116))||(((Bool__type ) 0))))?
((read_char)(),
9):
((((((_sharp_peeked_char_alt586 == 110))||(((Bool__type ) 0))))?
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

Int__type  parse_Maybe_Escaped_Character(void)
{
return ({
({
Int__type _sharp_peeked_char_alt587;
(_sharp_peeked_char_alt587 = (peek_char)());
((((((((int) _sharp_peeked_char_alt587 >= (int) 93))&&(((int) _sharp_peeked_char_alt587 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt587 >= (int) 0))&&(((int) _sharp_peeked_char_alt587 <= (int) 91))))||(((Bool__type ) 0))))))?
((read_char)()):
((((((_sharp_peeked_char_alt587 == 92))||(((Bool__type ) 0))))?
((parse_Escaped_Character)()):
((parse_error)()))));
})
;
})
;}

Int__type  parse_Maybe_Escaped_Character_Character_Range(void)
{
return ({
({
Int__type _sharp_peeked_char_alt588;
(_sharp_peeked_char_alt588 = (peek_char)());
((((((((int) _sharp_peeked_char_alt588 >= (int) 94))&&(((int) _sharp_peeked_char_alt588 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt588 >= (int) 93))&&(((int) _sharp_peeked_char_alt588 <= (int) 92))))||(((((((int) _sharp_peeked_char_alt588 >= (int) 0))&&(((int) _sharp_peeked_char_alt588 <= (int) 91))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt588 == 92))||(((Bool__type ) 0))))?
((parse_Escaped_Character)()):
((parse_error)()))));
})
;
})
;}

Form__type  parse_String(void)
{
return ({
Int__type start;
Int__type end;
(read_char)(),
(start = (get_point_pos)()),
((void) 0);_sharp__sharp_loop591_begin593:((void) 0),
({
Int__type _sharp_peeked_char_star589;
(_sharp_peeked_char_star589 = (peek_char)());
({if( (!((((_sharp_peeked_char_star589 == 92))||(((((((int) _sharp_peeked_char_star589 >= (int) 93))&&(((int) _sharp_peeked_char_star589 <= (int) 255))))||(((((((int) _sharp_peeked_char_star589 >= (int) 35))&&(((int) _sharp_peeked_char_star589 <= (int) 91))))||(((((((int) _sharp_peeked_char_star589 >= (int) 0))&&(((int) _sharp_peeked_char_star589 <= (int) 33))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop591_end592;});}})
;
({
Int__type _sharp_peeked_char_alt590;
(_sharp_peeked_char_alt590 = (peek_char)());
((((((((int) _sharp_peeked_char_alt590 >= (int) 93))&&(((int) _sharp_peeked_char_alt590 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt590 >= (int) 35))&&(((int) _sharp_peeked_char_alt590 <= (int) 91))))||(((((((int) _sharp_peeked_char_alt590 >= (int) 0))&&(((int) _sharp_peeked_char_alt590 <= (int) 33))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt590 == 92))||(((Bool__type ) 0))))?
((parse_Escaped_Character)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop591_begin593;}),
((void) 0);_sharp__sharp_loop591_end592:((void) 0),
(end = (get_point_pos)()),
(read_char)(),
(String_Form)((substring)(start, end));
})
;}

Form__type  parse_Character_Range(void)
{
return ({
Int__type max;
Int__type min;
(max = (min = (parse_Maybe_Escaped_Character_Character_Range)())),
({
Int__type _sharp_peeked_char_maybe594;
(_sharp_peeked_char_maybe594 = (peek_char)());
({if( (((_sharp_peeked_char_maybe594 == 45))||(((Bool__type ) 0))))
{
(read_char)(),
(max = (parse_Maybe_Escaped_Character)());}})
;
})
,
(((min == max))?
((Int_Form)(min)):
((Compound_Form)(intern( "-"), ({
struct struct0x08065f90 *_sharp_pair_596;
_sharp_pair_596,
(_sharp_pair_596 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_596).car) = (Int_Form)(min));
(((* _sharp_pair_596).cdr) = ({
struct struct0x08065f90 *_sharp_pair_595;
_sharp_pair_595,
(_sharp_pair_595 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_595).car) = (Int_Form)(max));
(((* _sharp_pair_595).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_595);
})
);
((List__O__Form__C____type__type ) _sharp_pair_596);
})
)));
})
;}

Form__type  parse_Character_Set(void)
{
return ({
void **_sharp_make_list_ptr600;
Symbol__type char_selector;
List__O__Form__C____type__type cr_list;
Form__type cr;
(char_selector = intern( "[]")),
(read_char)(),
({
Int__type _sharp_peeked_char_maybe597;
(_sharp_peeked_char_maybe597 = (peek_char)());
({if( (((_sharp_peeked_char_maybe597 == 94))||(((Bool__type ) 0))))
{
(read_char)(),
(char_selector = intern( "[^]"));}})
;
})
,
(cr_list = ({
List__O__Form__C____type__type _sharp_make_list599;
_sharp_make_list599,
_sharp_make_list_ptr600,
(_sharp_make_list_ptr600 = ((void *) (&_sharp_make_list599))),
((void) 0);_sharp__sharp_loop601_begin603:((void) 0),
({
Int__type _sharp_peeked_char_star598;
(_sharp_peeked_char_star598 = (peek_char)());
({if( (!((((_sharp_peeked_char_star598 == 92))||(((((((int) _sharp_peeked_char_star598 >= (int) 94))&&(((int) _sharp_peeked_char_star598 <= (int) 255))))||(((((((int) _sharp_peeked_char_star598 >= (int) 93))&&(((int) _sharp_peeked_char_star598 <= (int) 92))))||(((((((int) _sharp_peeked_char_star598 >= (int) 0))&&(((int) _sharp_peeked_char_star598 <= (int) 91))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop601_end602;});}})
;
(cr = (parse_Character_Range)()),
((* _sharp_make_list_ptr600) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08524078 **) _sharp_make_list_ptr600))).car) = ((void *) cr)),
(_sharp_make_list_ptr600 = (&((* (* ((struct struct0x08524078 **) _sharp_make_list_ptr600))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop601_begin603;}),
((void) 0);_sharp__sharp_loop601_end602:((void) 0),
((* _sharp_make_list_ptr600) = ((void *) 0)),
_sharp_make_list599;
})
),
(read_char)(),
(Compound_Form)(char_selector, cr_list);
})
;}

Form__type  parse_Callable_Rule(void)
{
return ({
Symbol__type id;
(id = (parse_Identifier)()),
(Id_Form)(id);
})
;}

Form__type  parse_Semantic_Action(void)
{
return ({
Form__type exp;
(read_char)(),
(exp = (parse_Expression)()),
(read_char)(),
(Compound_Form)(intern( "{}"), ({
struct struct0x08065f90 *_sharp_pair_604;
_sharp_pair_604,
(_sharp_pair_604 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_604).car) = exp);
(((* _sharp_pair_604).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_604);
})
);
})
;}

Form__type  parse_Grouping(void)
{
return ({
Form__type form;
Symbol__type id;
(read_char)(),
(id = (parse_Identifier)()),
(read_char)(),
(form = (parse_Rule)()),
(read_char)(),
(Compound_Form)(intern( "<>"), ({
struct struct0x08065f90 *_sharp_pair_606;
_sharp_pair_606,
(_sharp_pair_606 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_606).car) = (Id_Form)(id));
(((* _sharp_pair_606).cdr) = ({
struct struct0x08065f90 *_sharp_pair_605;
_sharp_pair_605,
(_sharp_pair_605 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_605).car) = form);
(((* _sharp_pair_605).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_605);
})
);
((List__O__Form__C____type__type ) _sharp_pair_606);
})
);
})
;}

Form__type  parse_Primary(void)
{
return ({
Form__type r;
({
Int__type _sharp_peeked_char_alt607;
(_sharp_peeked_char_alt607 = (peek_char)());
(((((_sharp_peeked_char_alt607 == 40))||(((Bool__type ) 0))))?
((read_char)(),
(r = (parse_Rule)()),
(read_char)(),
r):
((((((_sharp_peeked_char_alt607 == 34))||((((_sharp_peeked_char_alt607 == 91))||(((((((int) _sharp_peeked_char_alt607 >= (int) 97))&&(((int) _sharp_peeked_char_alt607 <= (int) 122))))||((((_sharp_peeked_char_alt607 == 95))||(((((((int) _sharp_peeked_char_alt607 >= (int) 65))&&(((int) _sharp_peeked_char_alt607 <= (int) 90))))||((((_sharp_peeked_char_alt607 == 60))||((((_sharp_peeked_char_alt607 == 123))||(((Bool__type ) 0))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt608;
(_sharp_peeked_char_alt608 = (peek_char)());
(((((_sharp_peeked_char_alt608 == 123))||(((Bool__type ) 0))))?
((parse_Semantic_Action)()):
((((((_sharp_peeked_char_alt608 == 34))||((((_sharp_peeked_char_alt608 == 91))||(((((((int) _sharp_peeked_char_alt608 >= (int) 97))&&(((int) _sharp_peeked_char_alt608 <= (int) 122))))||((((_sharp_peeked_char_alt608 == 95))||(((((((int) _sharp_peeked_char_alt608 >= (int) 65))&&(((int) _sharp_peeked_char_alt608 <= (int) 90))))||((((_sharp_peeked_char_alt608 == 60))||(((Bool__type ) 0))))))))))))))?
(({
Int__type _sharp_peeked_char_alt609;
(_sharp_peeked_char_alt609 = (peek_char)());
(((((_sharp_peeked_char_alt609 == 60))||(((Bool__type ) 0))))?
((parse_Grouping)()):
((((((_sharp_peeked_char_alt609 == 34))||((((_sharp_peeked_char_alt609 == 91))||(((((((int) _sharp_peeked_char_alt609 >= (int) 97))&&(((int) _sharp_peeked_char_alt609 <= (int) 122))))||((((_sharp_peeked_char_alt609 == 95))||(((((((int) _sharp_peeked_char_alt609 >= (int) 65))&&(((int) _sharp_peeked_char_alt609 <= (int) 90))))||(((Bool__type ) 0))))))))))))?
(({
Int__type _sharp_peeked_char_alt610;
(_sharp_peeked_char_alt610 = (peek_char)());
((((((((int) _sharp_peeked_char_alt610 >= (int) 97))&&(((int) _sharp_peeked_char_alt610 <= (int) 122))))||((((_sharp_peeked_char_alt610 == 95))||(((((((int) _sharp_peeked_char_alt610 >= (int) 65))&&(((int) _sharp_peeked_char_alt610 <= (int) 90))))||(((Bool__type ) 0))))))))?
((parse_Callable_Rule)()):
((((((_sharp_peeked_char_alt610 == 34))||((((_sharp_peeked_char_alt610 == 91))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt611;
(_sharp_peeked_char_alt611 = (peek_char)());
(((((_sharp_peeked_char_alt611 == 91))||(((Bool__type ) 0))))?
((parse_Character_Set)()):
((((((_sharp_peeked_char_alt611 == 34))||(((Bool__type ) 0))))?
((parse_String)()):
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

Form__type  parse_Postfix(void)
{
return ({
Int__type start;
Form__type form;
Int__type end;
(form = (parse_Primary)()),
({
Int__type _sharp_peeked_char_maybe612;
(_sharp_peeked_char_maybe612 = (peek_char)());
({if( (((_sharp_peeked_char_maybe612 == 63))||((((_sharp_peeked_char_maybe612 == 42))||((((_sharp_peeked_char_maybe612 == 43))||(((Bool__type ) 0))))))))
{
(start = (get_point_pos)()),
({
Int__type _sharp_peeked_char_alt613;
(_sharp_peeked_char_alt613 = (peek_char)());
(((((_sharp_peeked_char_alt613 == 43))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt613 == 63))||((((_sharp_peeked_char_alt613 == 42))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt614;
(_sharp_peeked_char_alt614 = (peek_char)());
(((((_sharp_peeked_char_alt614 == 42))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt614 == 63))||(((Bool__type ) 0))))?
((read_char)()):
((parse_error)()))));
})
):
((parse_error)()))));
})
,
(end = (get_point_pos)()),
(form = (Compound_Form)((intern_string)((substring)(start, end)), ({
struct struct0x08065f90 *_sharp_pair_615;
_sharp_pair_615,
(_sharp_pair_615 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_615).car) = form);
(((* _sharp_pair_615).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_615);
})
));}})
;
})
,
form;
})
;}

Form__type  parse_Sequence(void)
{
return ({
void **_sharp_make_list_ptr618;
Form__type post;
List__O__Form__C____type__type post_list;
(parse_Spacing)(),
(post_list = ({
List__O__Form__C____type__type _sharp_make_list617;
_sharp_make_list617,
_sharp_make_list_ptr618,
(_sharp_make_list_ptr618 = ((void *) (&_sharp_make_list617))),
((void) 0);_sharp__sharp_loop619_begin621:((void) 0),
({
Int__type _sharp_peeked_char_star616;
(_sharp_peeked_char_star616 = (peek_char)());
({if( (!((((_sharp_peeked_char_star616 == 34))||((((_sharp_peeked_char_star616 == 91))||(((((((int) _sharp_peeked_char_star616 >= (int) 97))&&(((int) _sharp_peeked_char_star616 <= (int) 122))))||((((_sharp_peeked_char_star616 == 95))||(((((((int) _sharp_peeked_char_star616 >= (int) 65))&&(((int) _sharp_peeked_char_star616 <= (int) 90))))||((((_sharp_peeked_char_star616 == 60))||((((_sharp_peeked_char_star616 == 123))||((((_sharp_peeked_char_star616 == 40))||(((Bool__type ) 0))))))))))))))))))))
{
({goto _sharp__sharp_loop619_end620;});}})
;
(post = (parse_Postfix)()),
(parse_Spacing)(),
((* _sharp_make_list_ptr618) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08524078 **) _sharp_make_list_ptr618))).car) = ((void *) post)),
(_sharp_make_list_ptr618 = (&((* (* ((struct struct0x08524078 **) _sharp_make_list_ptr618))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop619_begin621;}),
((void) 0);_sharp__sharp_loop619_end620:((void) 0),
((* _sharp_make_list_ptr618) = ((void *) 0)),
_sharp_make_list617;
})
),
(((((* ((struct struct0x0805f098 *) post_list)).tail) == ((List__O__Form__C____type__type ) 0)))?
(((* ((struct struct0x0805f098 *) post_list)).head)):
((Compound_Form)(intern( " "), post_list)));
})
;}

Form__type  parse_Alternative(void)
{
return ({
Form__type sec;
Form__type prim;
(prim = (parse_Sequence)()),
((void) 0);_sharp__sharp_loop625_begin627:((void) 0),
({
Int__type _sharp_peeked_char_star622;
(_sharp_peeked_char_star622 = (peek_char)());
({if( (!((((_sharp_peeked_char_star622 == 124))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop625_end626;});}})
;
(read_char)(),
(parse_Spacing)(),
(sec = (parse_Sequence)()),
(prim = (Compound_Form)(intern( "|"), ({
struct struct0x08065f90 *_sharp_pair_624;
_sharp_pair_624,
(_sharp_pair_624 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_624).car) = prim);
(((* _sharp_pair_624).cdr) = ({
struct struct0x08065f90 *_sharp_pair_623;
_sharp_pair_623,
(_sharp_pair_623 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_623).car) = sec);
(((* _sharp_pair_623).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_623);
})
);
((List__O__Form__C____type__type ) _sharp_pair_624);
})
));
})
,
({goto _sharp__sharp_loop625_begin627;}),
((void) 0);_sharp__sharp_loop625_end626:((void) 0),
prim;
})
;}

Form__type  parse_Rule(void)
{
return ({
(parse_Alternative)();
})
;}

Form__type  parse_Grammar_Rule(void)
{
return ({
Form__type ret_type;
Form__type r;
Symbol__type id;
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(parse_Spacing)(),
(id = (parse_Identifier)()),
(read_char)(),
(ret_type = (parse_Type)()),
(parse_Spacing)(),
(read_char)(),
(parse_Spacing)(),
(r = (parse_Rule)()),
(parse_Spacing)(),
(read_char)(),
(parse_Spacing)(),
(Compound_Form)(intern( "rule"), ({
struct struct0x08065f90 *_sharp_pair_630;
_sharp_pair_630,
(_sharp_pair_630 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_630).car) = (Id_Form)(id));
(((* _sharp_pair_630).cdr) = ({
struct struct0x08065f90 *_sharp_pair_629;
_sharp_pair_629,
(_sharp_pair_629 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_629).car) = ret_type);
(((* _sharp_pair_629).cdr) = ({
struct struct0x08065f90 *_sharp_pair_628;
_sharp_pair_628,
(_sharp_pair_628 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_628).car) = r);
(((* _sharp_pair_628).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_628);
})
);
((List__O__Form__C____type__type ) _sharp_pair_629);
})
);
((List__O__Form__C____type__type ) _sharp_pair_630);
})
);
})
;}

Form__type  parse_Grammar(void)
{
return ({
void **_sharp_make_list_ptr633;
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
(parse_Spacing)(),
(id = (parse_Identifier)()),
(parse_Spacing)(),
(read_char)(),
(parse_Spacing)(),
(read_char)(),
(parse_Spacing)(),
(gr_list = ({
List__O__Form__C____type__type _sharp_make_list632;
_sharp_make_list632,
_sharp_make_list_ptr633,
(_sharp_make_list_ptr633 = ((void *) (&_sharp_make_list632))),
((void) 0);_sharp__sharp_loop634_begin636:((void) 0),
({
Int__type _sharp_peeked_char_star631;
(_sharp_peeked_char_star631 = (peek_char)());
({if( (!((((_sharp_peeked_char_star631 == 114))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop634_end635;});}})
;
(gr = (parse_Grammar_Rule)()),
((* _sharp_make_list_ptr633) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08524078 **) _sharp_make_list_ptr633))).car) = ((void *) gr)),
(_sharp_make_list_ptr633 = (&((* (* ((struct struct0x08524078 **) _sharp_make_list_ptr633))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop634_begin636;}),
((void) 0);_sharp__sharp_loop634_end635:((void) 0),
((* _sharp_make_list_ptr633) = ((void *) 0)),
_sharp_make_list632;
})
),
(read_char)(),
(parse_Spacing)(),
(read_char)(),
(Compound_Form)(intern( "define"), ({
struct struct0x08065f90 *_sharp_pair_638;
_sharp_pair_638,
(_sharp_pair_638 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_638).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_638).cdr) = ({
struct struct0x08065f90 *_sharp_pair_637;
_sharp_pair_637,
(_sharp_pair_637 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_637).car) = (Id_Form)(id));
(((* _sharp_pair_637).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_637);
})
);
((List__O__Form__C____type__type ) _sharp_pair_638);
})
);
})
;}
