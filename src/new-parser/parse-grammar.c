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
({if( (!((((_sharp_peeked_char_star408 == 32))||((((_sharp_peeked_char_star408 == 10))||((((_sharp_peeked_char_star408 == 9))||((((_sharp_peeked_char_star408 == 47))||(((Bool__type ) 0))))))))))))
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
((((((_sharp_peeked_char_alt417 == 110))||((((_sharp_peeked_char_alt417 == 116))||(((Bool__type ) 0))))))?
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
({if( (!((((_sharp_peeked_char_star421 == 92))||(((((((int) _sharp_peeked_char_star421 >= (int) 93))&&(((int) _sharp_peeked_char_star421 <= (int) 255))))||(((((((int) _sharp_peeked_char_star421 >= (int) 35))&&(((int) _sharp_peeked_char_star421 <= (int) 91))))||(((((((int) _sharp_peeked_char_star421 >= (int) 0))&&(((int) _sharp_peeked_char_star421 <= (int) 33))))||(((Bool__type ) 0))))))))))))
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
({if( (!((((_sharp_peeked_char_star426 == 92))||(((((((int) _sharp_peeked_char_star426 >= (int) 93))&&(((int) _sharp_peeked_char_star426 <= (int) 255))))||(((((((int) _sharp_peeked_char_star426 >= (int) 40))&&(((int) _sharp_peeked_char_star426 <= (int) 91))))||(((((((int) _sharp_peeked_char_star426 >= (int) 0))&&(((int) _sharp_peeked_char_star426 <= (int) 38))))||(((Bool__type ) 0))))))))))))
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
struct struct0x08066050 *_sharp_pair_433;
_sharp_pair_433,
(_sharp_pair_433 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_433).car) = (Int_Form)(min));
(((* _sharp_pair_433).cdr) = ({
struct struct0x08066050 *_sharp_pair_432;
_sharp_pair_432,
(_sharp_pair_432 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
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
List__O__Form__C____type__type cr_list;
Form__type cr;
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
({if( (!((((_sharp_peeked_char_star435 == 92))||(((((((int) _sharp_peeked_char_star435 >= (int) 94))&&(((int) _sharp_peeked_char_star435 <= (int) 255))))||(((((((int) _sharp_peeked_char_star435 >= (int) 93))&&(((int) _sharp_peeked_char_star435 <= (int) 92))))||(((((((int) _sharp_peeked_char_star435 >= (int) 0))&&(((int) _sharp_peeked_char_star435 <= (int) 91))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop438_end439;});}})
;
(cr = (_l__parse__parse_grammar__Character_Range)()),
((* _sharp_make_list_ptr437) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08519de0 **) _sharp_make_list_ptr437))).car) = ((void *) cr)),
(_sharp_make_list_ptr437 = (&((* (* ((struct struct0x08519de0 **) _sharp_make_list_ptr437))).cdr))),
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

Form__type  _l__parse__parse_grammar__Callable_Rule(void)
{
return ({
Symbol__type id;
Form__type form;
(id = (_l__parse__parse_grammar__Identifier)()),
(form = (Id_Form)(id)),
({
Int__type _sharp_peeked_char_maybe441;
(_sharp_peeked_char_maybe441 = (peek_char)());
({if( (((_sharp_peeked_char_maybe441 == 46))||(((Bool__type ) 0))))
{
(read_char)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(form = (Compound_Form)(intern( "."), ({
struct struct0x08066050 *_sharp_pair_443;
_sharp_pair_443,
(_sharp_pair_443 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_443).car) = form);
(((* _sharp_pair_443).cdr) = ({
struct struct0x08066050 *_sharp_pair_442;
_sharp_pair_442,
(_sharp_pair_442 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_442).car) = (Id_Form)(id));
(((* _sharp_pair_442).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_442);
})
);
((List__O__Form__C____type__type ) _sharp_pair_443);
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
struct struct0x08066050 *_sharp_pair_444;
_sharp_pair_444,
(_sharp_pair_444 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_444).car) = exp);
(((* _sharp_pair_444).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_444);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Grouping(void)
{
return ({
Symbol__type id;
Form__type form;
(read_char)(),
(id = (_l__parse__parse_grammar__Identifier)()),
(read_char)(),
(form = (_l__parse__parse_grammar__Rule)()),
(read_char)(),
(Compound_Form)(intern( "<>"), ({
struct struct0x08066050 *_sharp_pair_446;
_sharp_pair_446,
(_sharp_pair_446 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_446).car) = (Id_Form)(id));
(((* _sharp_pair_446).cdr) = ({
struct struct0x08066050 *_sharp_pair_445;
_sharp_pair_445,
(_sharp_pair_445 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_445).car) = form);
(((* _sharp_pair_445).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_445);
})
);
((List__O__Form__C____type__type ) _sharp_pair_446);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Rule_Macro(void)
{
return ({
Form__type exp;
(read_char)(),
(exp = (_l__parse__parse_grammar__Expression)()),
(Compound_Form)(intern( "@"), ({
struct struct0x08066050 *_sharp_pair_447;
_sharp_pair_447,
(_sharp_pair_447 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_447).car) = exp);
(((* _sharp_pair_447).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_447);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Primary(void)
{
return ({
Form__type r;
({
Int__type _sharp_peeked_char_alt448;
(_sharp_peeked_char_alt448 = (peek_char)());
(((((_sharp_peeked_char_alt448 == 40))||(((Bool__type ) 0))))?
((read_char)(),
(r = (_l__parse__parse_grammar__Rule)()),
(read_char)(),
r):
((((((_sharp_peeked_char_alt448 == 34))||((((_sharp_peeked_char_alt448 == 39))||((((_sharp_peeked_char_alt448 == 91))||(((((((int) _sharp_peeked_char_alt448 >= (int) 97))&&(((int) _sharp_peeked_char_alt448 <= (int) 122))))||((((_sharp_peeked_char_alt448 == 95))||(((((((int) _sharp_peeked_char_alt448 >= (int) 65))&&(((int) _sharp_peeked_char_alt448 <= (int) 90))))||((((_sharp_peeked_char_alt448 == 60))||((((_sharp_peeked_char_alt448 == 123))||((((_sharp_peeked_char_alt448 == 64))||(((Bool__type ) 0))))))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt449;
(_sharp_peeked_char_alt449 = (peek_char)());
(((((_sharp_peeked_char_alt449 == 64))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Rule_Macro)()):
((((((_sharp_peeked_char_alt449 == 34))||((((_sharp_peeked_char_alt449 == 39))||((((_sharp_peeked_char_alt449 == 91))||(((((((int) _sharp_peeked_char_alt449 >= (int) 97))&&(((int) _sharp_peeked_char_alt449 <= (int) 122))))||((((_sharp_peeked_char_alt449 == 95))||(((((((int) _sharp_peeked_char_alt449 >= (int) 65))&&(((int) _sharp_peeked_char_alt449 <= (int) 90))))||((((_sharp_peeked_char_alt449 == 60))||((((_sharp_peeked_char_alt449 == 123))||(((Bool__type ) 0))))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt450;
(_sharp_peeked_char_alt450 = (peek_char)());
(((((_sharp_peeked_char_alt450 == 123))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Semantic_Action)()):
((((((_sharp_peeked_char_alt450 == 34))||((((_sharp_peeked_char_alt450 == 39))||((((_sharp_peeked_char_alt450 == 91))||(((((((int) _sharp_peeked_char_alt450 >= (int) 97))&&(((int) _sharp_peeked_char_alt450 <= (int) 122))))||((((_sharp_peeked_char_alt450 == 95))||(((((((int) _sharp_peeked_char_alt450 >= (int) 65))&&(((int) _sharp_peeked_char_alt450 <= (int) 90))))||((((_sharp_peeked_char_alt450 == 60))||(((Bool__type ) 0))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt451;
(_sharp_peeked_char_alt451 = (peek_char)());
(((((_sharp_peeked_char_alt451 == 60))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Grouping)()):
((((((_sharp_peeked_char_alt451 == 34))||((((_sharp_peeked_char_alt451 == 39))||((((_sharp_peeked_char_alt451 == 91))||(((((((int) _sharp_peeked_char_alt451 >= (int) 97))&&(((int) _sharp_peeked_char_alt451 <= (int) 122))))||((((_sharp_peeked_char_alt451 == 95))||(((((((int) _sharp_peeked_char_alt451 >= (int) 65))&&(((int) _sharp_peeked_char_alt451 <= (int) 90))))||(((Bool__type ) 0))))))))))))))?
(({
Int__type _sharp_peeked_char_alt452;
(_sharp_peeked_char_alt452 = (peek_char)());
((((((((int) _sharp_peeked_char_alt452 >= (int) 97))&&(((int) _sharp_peeked_char_alt452 <= (int) 122))))||((((_sharp_peeked_char_alt452 == 95))||(((((((int) _sharp_peeked_char_alt452 >= (int) 65))&&(((int) _sharp_peeked_char_alt452 <= (int) 90))))||(((Bool__type ) 0))))))))?
((_l__parse__parse_grammar__Callable_Rule)()):
((((((_sharp_peeked_char_alt452 == 34))||((((_sharp_peeked_char_alt452 == 39))||((((_sharp_peeked_char_alt452 == 91))||(((Bool__type ) 0))))))))?
(({
Int__type _sharp_peeked_char_alt453;
(_sharp_peeked_char_alt453 = (peek_char)());
(((((_sharp_peeked_char_alt453 == 91))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Character_Set)()):
((((((_sharp_peeked_char_alt453 == 34))||((((_sharp_peeked_char_alt453 == 39))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt454;
(_sharp_peeked_char_alt454 = (peek_char)());
(((((_sharp_peeked_char_alt454 == 39))||(((Bool__type ) 0))))?
((_l__parse__parse_grammar__Symbol)()):
((((((_sharp_peeked_char_alt454 == 34))||(((Bool__type ) 0))))?
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
Int__type start;
Form__type form;
Int__type end;
(form = (_l__parse__parse_grammar__Primary)()),
({
Int__type _sharp_peeked_char_maybe455;
(_sharp_peeked_char_maybe455 = (peek_char)());
({if( (((_sharp_peeked_char_maybe455 == 63))||((((_sharp_peeked_char_maybe455 == 42))||((((_sharp_peeked_char_maybe455 == 43))||(((Bool__type ) 0))))))))
{
(start = (get_point_pos)()),
({
Int__type _sharp_peeked_char_alt456;
(_sharp_peeked_char_alt456 = (peek_char)());
(((((_sharp_peeked_char_alt456 == 43))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt456 == 63))||((((_sharp_peeked_char_alt456 == 42))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt457;
(_sharp_peeked_char_alt457 = (peek_char)());
(((((_sharp_peeked_char_alt457 == 42))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt457 == 63))||(((Bool__type ) 0))))?
((read_char)()):
((parse_error)()))));
})
):
((parse_error)()))));
})
,
(end = (get_point_pos)()),
(form = (Compound_Form)((intern_string)((substring)(start, end)), ({
struct struct0x08066050 *_sharp_pair_458;
_sharp_pair_458,
(_sharp_pair_458 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_458).car) = form);
(((* _sharp_pair_458).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_458);
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
void **_sharp_make_list_ptr461;
Form__type post;
List__O__Form__C____type__type post_list;
(_l__parse__parse_grammar__Spacing)(),
(post_list = ({
List__O__Form__C____type__type _sharp_make_list460;
_sharp_make_list460,
_sharp_make_list_ptr461,
(_sharp_make_list_ptr461 = ((void *) (&_sharp_make_list460))),
((void) 0);_sharp__sharp_loop462_begin464:((void) 0),
({
Int__type _sharp_peeked_char_star459;
(_sharp_peeked_char_star459 = (peek_char)());
({if( (!((((_sharp_peeked_char_star459 == 34))||((((_sharp_peeked_char_star459 == 39))||((((_sharp_peeked_char_star459 == 91))||(((((((int) _sharp_peeked_char_star459 >= (int) 97))&&(((int) _sharp_peeked_char_star459 <= (int) 122))))||((((_sharp_peeked_char_star459 == 95))||(((((((int) _sharp_peeked_char_star459 >= (int) 65))&&(((int) _sharp_peeked_char_star459 <= (int) 90))))||((((_sharp_peeked_char_star459 == 60))||((((_sharp_peeked_char_star459 == 123))||((((_sharp_peeked_char_star459 == 64))||((((_sharp_peeked_char_star459 == 40))||(((Bool__type ) 0))))))))))))))))))))))))
{
({goto _sharp__sharp_loop462_end463;});}})
;
(post = (_l__parse__parse_grammar__Postfix)()),
(_l__parse__parse_grammar__Spacing)(),
((* _sharp_make_list_ptr461) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08519de0 **) _sharp_make_list_ptr461))).car) = ((void *) post)),
(_sharp_make_list_ptr461 = (&((* (* ((struct struct0x08519de0 **) _sharp_make_list_ptr461))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop462_begin464;}),
((void) 0);_sharp__sharp_loop462_end463:((void) 0),
((* _sharp_make_list_ptr461) = ((void *) 0)),
_sharp_make_list460;
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
((void) 0);_sharp__sharp_loop468_begin470:((void) 0),
({
Int__type _sharp_peeked_char_star465;
(_sharp_peeked_char_star465 = (peek_char)());
({if( (!((((_sharp_peeked_char_star465 == 124))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop468_end469;});}})
;
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(sec = (_l__parse__parse_grammar__Sequence)()),
(prim = (Compound_Form)(intern( "|"), ({
struct struct0x08066050 *_sharp_pair_467;
_sharp_pair_467,
(_sharp_pair_467 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_467).car) = prim);
(((* _sharp_pair_467).cdr) = ({
struct struct0x08066050 *_sharp_pair_466;
_sharp_pair_466,
(_sharp_pair_466 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_466).car) = sec);
(((* _sharp_pair_466).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_466);
})
);
((List__O__Form__C____type__type ) _sharp_pair_467);
})
));
})
,
({goto _sharp__sharp_loop468_begin470;}),
((void) 0);_sharp__sharp_loop468_end469:((void) 0),
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
struct struct0x08066050 *_sharp_pair_473;
_sharp_pair_473,
(_sharp_pair_473 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_473).car) = (Id_Form)(id));
(((* _sharp_pair_473).cdr) = ({
struct struct0x08066050 *_sharp_pair_472;
_sharp_pair_472,
(_sharp_pair_472 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_472).car) = ret_type);
(((* _sharp_pair_472).cdr) = ({
struct struct0x08066050 *_sharp_pair_471;
_sharp_pair_471,
(_sharp_pair_471 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_471).car) = r);
(((* _sharp_pair_471).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_471);
})
);
((List__O__Form__C____type__type ) _sharp_pair_472);
})
);
((List__O__Form__C____type__type ) _sharp_pair_473);
})
);
})
;}

Form__type  _l__parse__parse_grammar__Grammar(void)
{
return ({
void **_sharp_make_list_ptr476;
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
List__O__Form__C____type__type _sharp_make_list475;
_sharp_make_list475,
_sharp_make_list_ptr476,
(_sharp_make_list_ptr476 = ((void *) (&_sharp_make_list475))),
((void) 0);_sharp__sharp_loop477_begin479:((void) 0),
({
Int__type _sharp_peeked_char_star474;
(_sharp_peeked_char_star474 = (peek_char)());
({if( (!((((_sharp_peeked_char_star474 == 114))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop477_end478;});}})
;
(gr = (_l__parse__parse_grammar__Grammar_Rule)()),
((* _sharp_make_list_ptr476) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08519de0 **) _sharp_make_list_ptr476))).car) = ((void *) gr)),
(_sharp_make_list_ptr476 = (&((* (* ((struct struct0x08519de0 **) _sharp_make_list_ptr476))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop477_begin479;}),
((void) 0);_sharp__sharp_loop477_end478:((void) 0),
((* _sharp_make_list_ptr476) = ((void *) 0)),
_sharp_make_list475;
})
),
(read_char)(),
(_l__parse__parse_grammar__Spacing)(),
(read_char)(),
(Compound_Form)(intern( "define"), ({
struct struct0x08066050 *_sharp_pair_481;
_sharp_pair_481,
(_sharp_pair_481 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_481).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_481).cdr) = ({
struct struct0x08066050 *_sharp_pair_480;
_sharp_pair_480,
(_sharp_pair_480 = ((struct struct0x08066050 *) (alloc_cons_cell)()));
(((* _sharp_pair_480).car) = (Id_Form)(id));
(((* _sharp_pair_480).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_480);
})
);
((List__O__Form__C____type__type ) _sharp_pair_481);
})
);
})
;}
