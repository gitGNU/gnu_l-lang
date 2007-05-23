/* Automatically generated : do not edit!*/
#include "parse-grammar.inc"
Int__type  _l__parse__parse_grammar__Comment(void)
{
return ({
(read_char)(),
(read_char)(),
((void) 0);_sharp__sharp_loop405_begin407:((void) 0),
({
Int__type _sharp_peeked_char_star404;
(_sharp_peeked_char_star404 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star404 >= (int) 11))&&(((int) _sharp_peeked_char_star404 <= (int) 255))))||(((((((int) _sharp_peeked_char_star404 >= (int) 0))&&(((int) _sharp_peeked_char_star404 <= (int) 9))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop405_end406;});}})
;
(read_char)();
})
,
({goto _sharp__sharp_loop405_begin407;}),
((void) 0);_sharp__sharp_loop405_end406:((void) 0),
(read_char)();
})
;}

void  _l__parse__parse_grammar__Spacing(void)
{
return ({
((void) 0);_sharp__sharp_loop410_begin412:((void) 0),
({
Int__type _sharp_peeked_char_star408;
(_sharp_peeked_char_star408 = (peek_char)());
({if( (!((((_sharp_peeked_char_star408 == 47))||((((_sharp_peeked_char_star408 == 32))||((((_sharp_peeked_char_star408 == 10))||((((_sharp_peeked_char_star408 == 9))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop410_end411;});}})
;
({
Int__type _sharp_peeked_char_alt409;
(_sharp_peeked_char_alt409 = (peek_char)());
(((((_sharp_peeked_char_alt409 == 47))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Comment)()):
((((((_sharp_peeked_char_alt409 == 32))||((((_sharp_peeked_char_alt409 == 10))||((((_sharp_peeked_char_alt409 == 9))||(((Bool__type ) 0))))))))?
((read_char)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop410_begin412;}),
((void) 0);_sharp__sharp_loop410_end411:((void) 0);
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
((void) 0);_sharp__sharp_loop414_begin416:((void) 0),
({
Int__type _sharp_peeked_char_star413;
(_sharp_peeked_char_star413 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star413 >= (int) 97))&&(((int) _sharp_peeked_char_star413 <= (int) 122))))||((((_sharp_peeked_char_star413 == 95))||(((((((int) _sharp_peeked_char_star413 >= (int) 65))&&(((int) _sharp_peeked_char_star413 <= (int) 90))))||(((((((int) _sharp_peeked_char_star413 >= (int) 48))&&(((int) _sharp_peeked_char_star413 <= (int) 57))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop414_end415;});}})
;
(_l__parse__parse_grammar__Alpha_Num)();
})
,
({goto _sharp__sharp_loop414_begin416;}),
((void) 0);_sharp__sharp_loop414_end415:((void) 0),
(end = (get_point_pos)()),
(intern_string)((substring)(start, end));
})
;}

Int__type  _l__parse__parse_grammar__Escaped_Character(void)
{
return ({
(read_char)(),
({
Int__type _sharp_peeked_char_alt417;
(_sharp_peeked_char_alt417 = (peek_char)());
((((((((int) _sharp_peeked_char_alt417 >= (int) 117))&&(((int) _sharp_peeked_char_alt417 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt417 >= (int) 111))&&(((int) _sharp_peeked_char_alt417 <= (int) 115))))||(((((((int) _sharp_peeked_char_alt417 >= (int) 0))&&(((int) _sharp_peeked_char_alt417 <= (int) 109))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt417 == 116))||((((_sharp_peeked_char_alt417 == 110))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt418;
(_sharp_peeked_char_alt418 = (peek_char)());
(((((_sharp_peeked_char_alt418 == 116))||(((Bool__type ) 0))))?
((read_char)(),
9):
((((((_sharp_peeked_char_alt418 == 110))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_alt419;
(_sharp_peeked_char_alt419 = (peek_char)());
((((((((int) _sharp_peeked_char_alt419 >= (int) 93))&&(((int) _sharp_peeked_char_alt419 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt419 >= (int) 0))&&(((int) _sharp_peeked_char_alt419 <= (int) 91))))||(((Bool__type ) 0))))))?
((read_char)()):
((((((_sharp_peeked_char_alt419 == 92))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_alt420;
(_sharp_peeked_char_alt420 = (peek_char)());
((((((((int) _sharp_peeked_char_alt420 >= (int) 94))&&(((int) _sharp_peeked_char_alt420 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt420 >= (int) 93))&&(((int) _sharp_peeked_char_alt420 <= (int) 92))))||(((((((int) _sharp_peeked_char_alt420 >= (int) 0))&&(((int) _sharp_peeked_char_alt420 <= (int) 91))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt420 == 92))||(((Bool__type ) 0))))?
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
((void) 0);_sharp__sharp_loop423_begin425:((void) 0),
({
Int__type _sharp_peeked_char_star421;
(_sharp_peeked_char_star421 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star421 >= (int) 93))&&(((int) _sharp_peeked_char_star421 <= (int) 255))))||((((_sharp_peeked_char_star421 == 92))||(((((((int) _sharp_peeked_char_star421 >= (int) 35))&&(((int) _sharp_peeked_char_star421 <= (int) 91))))||(((((((int) _sharp_peeked_char_star421 >= (int) 0))&&(((int) _sharp_peeked_char_star421 <= (int) 33))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop423_end424;});}})
;
({
Int__type _sharp_peeked_char_alt422;
(_sharp_peeked_char_alt422 = (peek_char)());
((((((((int) _sharp_peeked_char_alt422 >= (int) 93))&&(((int) _sharp_peeked_char_alt422 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt422 >= (int) 35))&&(((int) _sharp_peeked_char_alt422 <= (int) 91))))||(((((((int) _sharp_peeked_char_alt422 >= (int) 0))&&(((int) _sharp_peeked_char_alt422 <= (int) 33))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt422 == 92))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop423_begin425;}),
((void) 0);_sharp__sharp_loop423_end424:((void) 0),
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
((void) 0);_sharp__sharp_loop428_begin430:((void) 0),
({
Int__type _sharp_peeked_char_star426;
(_sharp_peeked_char_star426 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star426 >= (int) 93))&&(((int) _sharp_peeked_char_star426 <= (int) 255))))||((((_sharp_peeked_char_star426 == 92))||(((((((int) _sharp_peeked_char_star426 >= (int) 40))&&(((int) _sharp_peeked_char_star426 <= (int) 91))))||(((((((int) _sharp_peeked_char_star426 >= (int) 0))&&(((int) _sharp_peeked_char_star426 <= (int) 38))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop428_end429;});}})
;
({
Int__type _sharp_peeked_char_alt427;
(_sharp_peeked_char_alt427 = (peek_char)());
((((((((int) _sharp_peeked_char_alt427 >= (int) 93))&&(((int) _sharp_peeked_char_alt427 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt427 >= (int) 40))&&(((int) _sharp_peeked_char_alt427 <= (int) 91))))||(((((((int) _sharp_peeked_char_alt427 >= (int) 0))&&(((int) _sharp_peeked_char_alt427 <= (int) 38))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt427 == 92))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Escaped_Character)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop428_begin430;}),
((void) 0);_sharp__sharp_loop428_end429:((void) 0),
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
Int__type _sharp_peeked_char_maybe431;
(_sharp_peeked_char_maybe431 = (peek_char)());
({if( (((_sharp_peeked_char_maybe431 == 45))||(((Bool__type ) 0))))
{
(read_char)(),
(max = (_l__parse__parse_grammar__Maybe_Escaped_Character)());}})
;
})
,
(((min == max))?
((Int_Form)(min)):
((Compound_Form)(intern( "-"), ({
struct struct0x080663e8 *_sharp_pair_433;
_sharp_pair_433,
(_sharp_pair_433 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_433).car) = (Int_Form)(min));
(((* _sharp_pair_433).cdr) = ({
struct struct0x080663e8 *_sharp_pair_432;
_sharp_pair_432,
(_sharp_pair_432 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_432).car) = (Int_Form)(max));
(((* _sharp_pair_432).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_432);
})
);
((List__O__Form__C____type__type ) _sharp_pair_433);
})
)));
})
;}

Form__type  _l__parse__parse_grammar__Character_Set(void)
{
return ({
void **_sharp_make_list_ptr437;
Symbol__type char_selector;
Form__type cr;
List__O__Form__C____type__type cr_list;
(char_selector = intern( "[]")),
(read_char)(),
({
Int__type _sharp_peeked_char_maybe434;
(_sharp_peeked_char_maybe434 = (peek_char)());
({if( (((_sharp_peeked_char_maybe434 == 94))||(((Bool__type ) 0))))
{
(read_char)(),
(char_selector = intern( "[^]"));}})
;
})
,
(cr_list = ({
List__O__Form__C____type__type _sharp_make_list436;
_sharp_make_list436,
_sharp_make_list_ptr437,
(_sharp_make_list_ptr437 = ((void *) (&_sharp_make_list436))),
((void) 0);_sharp__sharp_loop438_begin440:((void) 0),
({
Int__type _sharp_peeked_char_star435;
(_sharp_peeked_char_star435 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star435 >= (int) 94))&&(((int) _sharp_peeked_char_star435 <= (int) 255))))||(((((((int) _sharp_peeked_char_star435 >= (int) 93))&&(((int) _sharp_peeked_char_star435 <= (int) 92))))||((((_sharp_peeked_char_star435 == 92))||(((((((int) _sharp_peeked_char_star435 >= (int) 0))&&(((int) _sharp_peeked_char_star435 <= (int) 91))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop438_end439;});}})
;
(cr = (_l__parse__parse_grammar__Character_Range)()),
((* _sharp_make_list_ptr437) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0851c278 **) _sharp_make_list_ptr437))).car) = ((void *) cr)),
(_sharp_make_list_ptr437 = (&((* (* ((struct struct0x0851c278 **) _sharp_make_list_ptr437))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop438_begin440;}),
((void) 0);_sharp__sharp_loop438_end439:((void) 0),
((* _sharp_make_list_ptr437) = ((void *) 0)),
_sharp_make_list436;
})
),
(read_char)(),
(Compound_Form)(char_selector, cr_list);
})
;}

Form__type  _l__parse__parse_grammar__Callable_Rule_or_Binding(void)
{
return ({
Symbol__type id;
Form__type form;
(id = (_l__parse__parse_grammar__Identifier)()),
(form = (Id_Form)(id)),
({
Int__type _sharp_peeked_char_maybe441;
(_sharp_peeked_char_maybe441 = (peek_char)());
({if( (((_sharp_peeked_char_maybe441 == 58))||((((_sharp_peeked_char_maybe441 == 46))||(((Bool__type ) 0))))))
{
({
Int__type _sharp_peeked_char_alt442;
(_sharp_peeked_char_alt442 = (peek_char)());
(((((_sharp_peeked_char_alt442 == 58))||(((Bool__type ) 0))))?
((read_char)(),
(form = (_l__parse__parse_grammar__Postfix)()),
(form = (Compound_Form)(intern( "<>"), ({
struct struct0x080663e8 *_sharp_pair_446;
_sharp_pair_446,
(_sharp_pair_446 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_446).car) = (Id_Form)(id));
(((* _sharp_pair_446).cdr) = ({
struct struct0x080663e8 *_sharp_pair_445;
_sharp_pair_445,
(_sharp_pair_445 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_445).car) = form);
(((* _sharp_pair_445).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_445);
})
);
((List__O__Form__C____type__type ) _sharp_pair_446);
})
))):
((((((_sharp_peeked_char_alt442 == 46))||(((Bool__type ) 0))))?
((read_char)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(form = (Compound_Form)(intern( "."), ({
struct struct0x080663e8 *_sharp_pair_444;
_sharp_pair_444,
(_sharp_pair_444 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_444).car) = form);
(((* _sharp_pair_444).cdr) = ({
struct struct0x080663e8 *_sharp_pair_443;
_sharp_pair_443,
(_sharp_pair_443 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_443).car) = (Id_Form)(id));
(((* _sharp_pair_443).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_443);
})
);
((List__O__Form__C____type__type ) _sharp_pair_444);
})
))):
((parse_error)()))));
})
;}})
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
struct struct0x080663e8 *_sharp_pair_447;
_sharp_pair_447,
(_sharp_pair_447 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_447).car) = exp);
(((* _sharp_pair_447).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_447);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Rule_Macro(void)
{
return ({
void **_sharp_make_list_ptr451;
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
Int__type _sharp_peeked_char_alt448;
(_sharp_peeked_char_alt448 = (peek_char)());
(((((_sharp_peeked_char_alt448 == 123))||(((((((int) _sharp_peeked_char_alt448 >= (int) 97))&&(((int) _sharp_peeked_char_alt448 <= (int) 122))))||((((_sharp_peeked_char_alt448 == 95))||((((_sharp_peeked_char_alt448 == 91))||(((((((int) _sharp_peeked_char_alt448 >= (int) 65))&&(((int) _sharp_peeked_char_alt448 <= (int) 90))))||((((_sharp_peeked_char_alt448 == 64))||((((_sharp_peeked_char_alt448 == 40))||((((_sharp_peeked_char_alt448 == 39))||((((_sharp_peeked_char_alt448 == 36))||((((_sharp_peeked_char_alt448 == 34))||(((Bool__type ) 0))))))))))))))))))))))?
((arg1 = (_l__parse__parse_grammar__Rule)()),
(_l__parse__parse_grammar__Spacing)(),
(rest_list = ({
List__O__Form__C____type__type _sharp_make_list450;
_sharp_make_list450,
_sharp_make_list_ptr451,
(_sharp_make_list_ptr451 = ((void *) (&_sharp_make_list450))),
((void) 0);_sharp__sharp_loop452_begin454:((void) 0),
({
Int__type _sharp_peeked_char_star449;
(_sharp_peeked_char_star449 = (peek_char)());
({if( (!((((_sharp_peeked_char_star449 == 44))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop452_end453;});}})
;
(parse_symbol)(((String__type) &__string_14)),
(arg = (_l__parse__parse_grammar__Rule)()),
((* _sharp_make_list_ptr451) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0851c278 **) _sharp_make_list_ptr451))).car) = ((void *) arg)),
(_sharp_make_list_ptr451 = (&((* (* ((struct struct0x0851c278 **) _sharp_make_list_ptr451))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop452_begin454;}),
((void) 0);_sharp__sharp_loop452_end453:((void) 0),
((* _sharp_make_list_ptr451) = ((void *) 0)),
_sharp_make_list450;
})
),
(read_char)(),
({
struct struct0x080663e8 *_sharp_pair_455;
_sharp_pair_455,
(_sharp_pair_455 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_455).car) = arg1);
(((* _sharp_pair_455).cdr) = rest_list);
((List__O__Form__C____type__type ) _sharp_pair_455);
})
):
((((((_sharp_peeked_char_alt448 == 41))||(((Bool__type ) 0))))?
((read_char)(),
((List__O__Form__C____type__type ) 0)):
((parse_error)()))));
})
),
(Compound_Form)(intern( "@"), ({
struct struct0x080663e8 *_sharp_pair_456;
_sharp_pair_456,
(_sharp_pair_456 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_456).car) = (Compound_Form)(id, form_list));
(((* _sharp_pair_456).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_456);
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
struct struct0x080663e8 *_sharp_pair_457;
_sharp_pair_457,
(_sharp_pair_457 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_457).car) = exp);
(((* _sharp_pair_457).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_457);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Primary(void)
{
return ({
Form__type r;
({
Int__type _sharp_peeked_char_alt458;
(_sharp_peeked_char_alt458 = (peek_char)());
(((((_sharp_peeked_char_alt458 == 40))||(((Bool__type ) 0))))?
((read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(r = (_l__parse__parse_grammar__Rule)()),
(read_char)(),
r):
((((((_sharp_peeked_char_alt458 == 123))||(((((((int) _sharp_peeked_char_alt458 >= (int) 97))&&(((int) _sharp_peeked_char_alt458 <= (int) 122))))||((((_sharp_peeked_char_alt458 == 95))||((((_sharp_peeked_char_alt458 == 91))||(((((((int) _sharp_peeked_char_alt458 >= (int) 65))&&(((int) _sharp_peeked_char_alt458 <= (int) 90))))||((((_sharp_peeked_char_alt458 == 64))||((((_sharp_peeked_char_alt458 == 39))||((((_sharp_peeked_char_alt458 == 36))||((((_sharp_peeked_char_alt458 == 34))||(((Bool__type ) 0))))))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt459;
(_sharp_peeked_char_alt459 = (peek_char)());
(((((_sharp_peeked_char_alt459 == 36))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Replacement)()):
((((((_sharp_peeked_char_alt459 == 123))||(((((((int) _sharp_peeked_char_alt459 >= (int) 97))&&(((int) _sharp_peeked_char_alt459 <= (int) 122))))||((((_sharp_peeked_char_alt459 == 95))||((((_sharp_peeked_char_alt459 == 91))||(((((((int) _sharp_peeked_char_alt459 >= (int) 65))&&(((int) _sharp_peeked_char_alt459 <= (int) 90))))||((((_sharp_peeked_char_alt459 == 64))||((((_sharp_peeked_char_alt459 == 39))||((((_sharp_peeked_char_alt459 == 34))||(((Bool__type ) 0))))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt460;
(_sharp_peeked_char_alt460 = (peek_char)());
(((((_sharp_peeked_char_alt460 == 64))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Rule_Macro)()):
((((((_sharp_peeked_char_alt460 == 123))||(((((((int) _sharp_peeked_char_alt460 >= (int) 97))&&(((int) _sharp_peeked_char_alt460 <= (int) 122))))||((((_sharp_peeked_char_alt460 == 95))||((((_sharp_peeked_char_alt460 == 91))||(((((((int) _sharp_peeked_char_alt460 >= (int) 65))&&(((int) _sharp_peeked_char_alt460 <= (int) 90))))||((((_sharp_peeked_char_alt460 == 39))||((((_sharp_peeked_char_alt460 == 34))||(((Bool__type ) 0))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt461;
(_sharp_peeked_char_alt461 = (peek_char)());
(((((_sharp_peeked_char_alt461 == 123))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Semantic_Action)()):
(((((((((int) _sharp_peeked_char_alt461 >= (int) 97))&&(((int) _sharp_peeked_char_alt461 <= (int) 122))))||((((_sharp_peeked_char_alt461 == 95))||((((_sharp_peeked_char_alt461 == 91))||(((((((int) _sharp_peeked_char_alt461 >= (int) 65))&&(((int) _sharp_peeked_char_alt461 <= (int) 90))))||((((_sharp_peeked_char_alt461 == 39))||((((_sharp_peeked_char_alt461 == 34))||(((Bool__type ) 0))))))))))))))?
(({
Int__type _sharp_peeked_char_alt462;
(_sharp_peeked_char_alt462 = (peek_char)());
((((((((int) _sharp_peeked_char_alt462 >= (int) 97))&&(((int) _sharp_peeked_char_alt462 <= (int) 122))))||((((_sharp_peeked_char_alt462 == 95))||(((((((int) _sharp_peeked_char_alt462 >= (int) 65))&&(((int) _sharp_peeked_char_alt462 <= (int) 90))))||(((Bool__type ) 0))))))))?
((_l__parse__parse_grammar__Callable_Rule_or_Binding)()):
((((((_sharp_peeked_char_alt462 == 91))||((((_sharp_peeked_char_alt462 == 39))||((((_sharp_peeked_char_alt462 == 34))||(((Bool__type ) 0))))))))?
(({
Int__type _sharp_peeked_char_alt463;
(_sharp_peeked_char_alt463 = (peek_char)());
(((((_sharp_peeked_char_alt463 == 91))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Character_Set)()):
((((((_sharp_peeked_char_alt463 == 39))||((((_sharp_peeked_char_alt463 == 34))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt464;
(_sharp_peeked_char_alt464 = (peek_char)());
(((((_sharp_peeked_char_alt464 == 39))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Symbol)()):
((((((_sharp_peeked_char_alt464 == 34))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_maybe465;
(_sharp_peeked_char_maybe465 = (peek_char)());
({if( (((_sharp_peeked_char_maybe465 == 63))||((((_sharp_peeked_char_maybe465 == 43))||((((_sharp_peeked_char_maybe465 == 42))||(((Bool__type ) 0))))))))
{
(op = ({
Int__type _sharp_peeked_char_alt466;
(_sharp_peeked_char_alt466 = (peek_char)());
(((((_sharp_peeked_char_alt466 == 43))||(((Bool__type ) 0))))?
((parse_symbol)(((String__type) &__string_15))):
((((((_sharp_peeked_char_alt466 == 63))||((((_sharp_peeked_char_alt466 == 42))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt467;
(_sharp_peeked_char_alt467 = (peek_char)());
(((((_sharp_peeked_char_alt467 == 42))||(((Bool__type ) 0))))?
((parse_symbol)(((String__type) &__string_16))):
((((((_sharp_peeked_char_alt467 == 63))||(((Bool__type ) 0))))?
((parse_symbol)(((String__type) &__string_17))):
((parse_error)()))));
})
):
((parse_error)()))));
})
),
(form = (Compound_Form)(op, ({
struct struct0x080663e8 *_sharp_pair_468;
_sharp_pair_468,
(_sharp_pair_468 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_468).car) = form);
(((* _sharp_pair_468).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_468);
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
void **_sharp_make_list_ptr471;
Form__type post;
List__O__Form__C____type__type post_list;
(post_list = ({
List__O__Form__C____type__type _sharp_make_list470;
_sharp_make_list470,
_sharp_make_list_ptr471,
(_sharp_make_list_ptr471 = ((void *) (&_sharp_make_list470))),
((void) 0);_sharp__sharp_loop472_begin474:((void) 0),
({
Int__type _sharp_peeked_char_star469;
(post = (_l__parse__parse_grammar__Postfix)()),
(_l__parse__parse_grammar__Spacing)(),
((* _sharp_make_list_ptr471) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0851c278 **) _sharp_make_list_ptr471))).car) = ((void *) post)),
(_sharp_make_list_ptr471 = (&((* (* ((struct struct0x0851c278 **) _sharp_make_list_ptr471))).cdr))),
((void) 0);
(_sharp_peeked_char_star469 = (peek_char)());
({if( (!((((_sharp_peeked_char_star469 == 123))||(((((((int) _sharp_peeked_char_star469 >= (int) 97))&&(((int) _sharp_peeked_char_star469 <= (int) 122))))||((((_sharp_peeked_char_star469 == 95))||((((_sharp_peeked_char_star469 == 91))||(((((((int) _sharp_peeked_char_star469 >= (int) 65))&&(((int) _sharp_peeked_char_star469 <= (int) 90))))||((((_sharp_peeked_char_star469 == 64))||((((_sharp_peeked_char_star469 == 40))||((((_sharp_peeked_char_star469 == 39))||((((_sharp_peeked_char_star469 == 36))||((((_sharp_peeked_char_star469 == 34))||(((Bool__type ) 0))))))))))))))))))))))))
{
({goto _sharp__sharp_loop472_end473;});}})
;
})
,
({goto _sharp__sharp_loop472_begin474;}),
((void) 0);_sharp__sharp_loop472_end473:((void) 0),
((* _sharp_make_list_ptr471) = ((void *) 0)),
_sharp_make_list470;
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
((void) 0);_sharp__sharp_loop478_begin480:((void) 0),
({
Int__type _sharp_peeked_char_star475;
(_sharp_peeked_char_star475 = (peek_char)());
({if( (!((((_sharp_peeked_char_star475 == 124))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop478_end479;});}})
;
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(sec = (_l__parse__parse_grammar__Sequence)()),
(prim = (Compound_Form)(intern( "|"), ({
struct struct0x080663e8 *_sharp_pair_477;
_sharp_pair_477,
(_sharp_pair_477 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_477).car) = prim);
(((* _sharp_pair_477).cdr) = ({
struct struct0x080663e8 *_sharp_pair_476;
_sharp_pair_476,
(_sharp_pair_476 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_476).car) = sec);
(((* _sharp_pair_476).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_476);
})
);
((List__O__Form__C____type__type ) _sharp_pair_477);
})
));
})
,
({goto _sharp__sharp_loop478_begin480;}),
((void) 0);_sharp__sharp_loop478_end479:((void) 0),
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
struct struct0x080663e8 *_sharp_pair_483;
_sharp_pair_483,
(_sharp_pair_483 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_483).car) = (Id_Form)(id));
(((* _sharp_pair_483).cdr) = ({
struct struct0x080663e8 *_sharp_pair_482;
_sharp_pair_482,
(_sharp_pair_482 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_482).car) = ret_type);
(((* _sharp_pair_482).cdr) = ({
struct struct0x080663e8 *_sharp_pair_481;
_sharp_pair_481,
(_sharp_pair_481 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_481).car) = r);
(((* _sharp_pair_481).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_481);
})
);
((List__O__Form__C____type__type ) _sharp_pair_482);
})
);
((List__O__Form__C____type__type ) _sharp_pair_483);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Grammar(void)
{
return ({
void **_sharp_make_list_ptr486;
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
List__O__Form__C____type__type _sharp_make_list485;
_sharp_make_list485,
_sharp_make_list_ptr486,
(_sharp_make_list_ptr486 = ((void *) (&_sharp_make_list485))),
((void) 0);_sharp__sharp_loop487_begin489:((void) 0),
({
Int__type _sharp_peeked_char_star484;
(_sharp_peeked_char_star484 = (peek_char)());
({if( (!((((_sharp_peeked_char_star484 == 114))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop487_end488;});}})
;
(gr = (_l__parse__parse_grammar__Grammar_Rule)()),
((* _sharp_make_list_ptr486) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0851c278 **) _sharp_make_list_ptr486))).car) = ((void *) gr)),
(_sharp_make_list_ptr486 = (&((* (* ((struct struct0x0851c278 **) _sharp_make_list_ptr486))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop487_begin489;}),
((void) 0);_sharp__sharp_loop487_end488:((void) 0),
((* _sharp_make_list_ptr486) = ((void *) 0)),
_sharp_make_list485;
})
),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(Compound_Form)(intern( "define"), ({
struct struct0x080663e8 *_sharp_pair_491;
_sharp_pair_491,
(_sharp_pair_491 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_491).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_491).cdr) = ({
struct struct0x080663e8 *_sharp_pair_490;
_sharp_pair_490,
(_sharp_pair_490 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_490).car) = (Id_Form)(id));
(((* _sharp_pair_490).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_490);
})
);
((List__O__Form__C____type__type ) _sharp_pair_491);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Grammar_Macro(void)
{
return ({
void **_sharp_make_list_ptr495;
Symbol__type arg;
List__O__Form__C____type__type rest_list;
Symbol__type arg1;
Symbol__type id;
Form__type rule;
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
Int__type _sharp_peeked_char_alt492;
(_sharp_peeked_char_alt492 = (peek_char)());
((((((((int) _sharp_peeked_char_alt492 >= (int) 97))&&(((int) _sharp_peeked_char_alt492 <= (int) 122))))||((((_sharp_peeked_char_alt492 == 95))||(((((((int) _sharp_peeked_char_alt492 >= (int) 65))&&(((int) _sharp_peeked_char_alt492 <= (int) 90))))||(((Bool__type ) 0))))))))?
((arg1 = (_l__parse__parse_grammar__Identifier)()),
(_l__parse__parse_grammar__Spacing)(),
(rest_list = ({
List__O__Form__C____type__type _sharp_make_list494;
_sharp_make_list494,
_sharp_make_list_ptr495,
(_sharp_make_list_ptr495 = ((void *) (&_sharp_make_list494))),
((void) 0);_sharp__sharp_loop496_begin498:((void) 0),
({
Int__type _sharp_peeked_char_star493;
(_sharp_peeked_char_star493 = (peek_char)());
({if( (!((((_sharp_peeked_char_star493 == 44))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop496_end497;});}})
;
(parse_symbol)(((String__type) &__string_18)),
(arg = (_l__parse__parse_grammar__Identifier)()),
((* _sharp_make_list_ptr495) = (alloc_cons_cell)()),
(((* (* ((struct struct0x0851c278 **) _sharp_make_list_ptr495))).car) = ((void *) (Id_Form)(arg))),
(_sharp_make_list_ptr495 = (&((* (* ((struct struct0x0851c278 **) _sharp_make_list_ptr495))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop496_begin498;}),
((void) 0);_sharp__sharp_loop496_end497:((void) 0),
((* _sharp_make_list_ptr495) = ((void *) 0)),
_sharp_make_list494;
})
),
(read_char)(),
({
struct struct0x080663e8 *_sharp_pair_499;
_sharp_pair_499,
(_sharp_pair_499 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_499).car) = (Id_Form)(arg1));
(((* _sharp_pair_499).cdr) = rest_list);
((List__O__Form__C____type__type ) _sharp_pair_499);
})
):
((((((_sharp_peeked_char_alt492 == 41))||(((Bool__type ) 0))))?
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
struct struct0x080663e8 *_sharp_pair_503;
_sharp_pair_503,
(_sharp_pair_503 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_503).car) = (Id_Form)(intern( "grammar_macro")));
(((* _sharp_pair_503).cdr) = ({
struct struct0x080663e8 *_sharp_pair_502;
_sharp_pair_502,
(_sharp_pair_502 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_502).car) = (Id_Form)(id));
(((* _sharp_pair_502).cdr) = ({
struct struct0x080663e8 *_sharp_pair_501;
_sharp_pair_501,
(_sharp_pair_501 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_501).car) = (Compound_Form)(intern( "tuple"), form_list));
(((* _sharp_pair_501).cdr) = ({
struct struct0x080663e8 *_sharp_pair_500;
_sharp_pair_500,
(_sharp_pair_500 = ((struct struct0x080663e8 *) (alloc_cons_cell)()));
(((* _sharp_pair_500).car) = rule);
(((* _sharp_pair_500).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_500);
})
);
((List__O__Form__C____type__type ) _sharp_pair_501);
})
);
((List__O__Form__C____type__type ) _sharp_pair_502);
})
);
((List__O__Form__C____type__type ) _sharp_pair_503);
})
);
})
;}
