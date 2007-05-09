/* Automatically generated : do not edit!*/
#include "parse-grammar.inc"

Int__type  parse_Comment(void)
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
(read_char)(),
(read_char)();
})
;}

void  parse_Spacing(void)
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
((parse_Comment)()):
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
((void) 0);_sharp__sharp_loop414_begin416:((void) 0),
({
Int__type _sharp_peeked_char_star413;
(_sharp_peeked_char_star413 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star413 >= (int) 97))&&(((int) _sharp_peeked_char_star413 <= (int) 122))))||((((_sharp_peeked_char_star413 == 95))||(((((((int) _sharp_peeked_char_star413 >= (int) 65))&&(((int) _sharp_peeked_char_star413 <= (int) 90))))||(((((((int) _sharp_peeked_char_star413 >= (int) 48))&&(((int) _sharp_peeked_char_star413 <= (int) 57))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop414_end415;});}})
;
(parse_Alpha_Num)();
})
,
({goto _sharp__sharp_loop414_begin416;}),
((void) 0);_sharp__sharp_loop414_end415:((void) 0),
(end = (get_point_pos)()),
(intern_string)((substring)(start, end));
})
;}

Int__type  parse_Escaped_Character(void)
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

Int__type  parse_Maybe_Escaped_Character(void)
{
return ({
({
Int__type _sharp_peeked_char_alt419;
(_sharp_peeked_char_alt419 = (peek_char)());
((((((((int) _sharp_peeked_char_alt419 >= (int) 93))&&(((int) _sharp_peeked_char_alt419 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt419 >= (int) 0))&&(((int) _sharp_peeked_char_alt419 <= (int) 91))))||(((Bool__type ) 0))))))?
((read_char)()):
((((((_sharp_peeked_char_alt419 == 92))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_alt420;
(_sharp_peeked_char_alt420 = (peek_char)());
((((((((int) _sharp_peeked_char_alt420 >= (int) 94))&&(((int) _sharp_peeked_char_alt420 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt420 >= (int) 93))&&(((int) _sharp_peeked_char_alt420 <= (int) 92))))||(((((((int) _sharp_peeked_char_alt420 >= (int) 0))&&(((int) _sharp_peeked_char_alt420 <= (int) 91))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt420 == 92))||(((Bool__type ) 0))))?
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
((parse_Escaped_Character)()):
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

Form__type  parse_Character_Range(void)
{
return ({
Int__type max;
Int__type min;
(max = (min = (parse_Maybe_Escaped_Character_Character_Range)())),
({
Int__type _sharp_peeked_char_maybe426;
(_sharp_peeked_char_maybe426 = (peek_char)());
({if( (((_sharp_peeked_char_maybe426 == 45))||(((Bool__type ) 0))))
{
(read_char)(),
(max = (parse_Maybe_Escaped_Character)());}})
;
})
,
(((min == max))?
((Int_Form)(min)):
((Compound_Form)(intern( "-"), ({
struct struct0x08065f90 *_sharp_pair_428;
_sharp_pair_428,
(_sharp_pair_428 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_428).car) = (Int_Form)(min));
(((* _sharp_pair_428).cdr) = ({
struct struct0x08065f90 *_sharp_pair_427;
_sharp_pair_427,
(_sharp_pair_427 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_427).car) = (Int_Form)(max));
(((* _sharp_pair_427).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_427);
})
);
((List__O__Form__C____type__type ) _sharp_pair_428);
})
)));
})
;}

Form__type  parse_Character_Set(void)
{
return ({
void **_sharp_make_list_ptr432;
Symbol__type char_selector;
List__O__Form__C____type__type cr_list;
Form__type cr;
(char_selector = intern( "[]")),
(read_char)(),
({
Int__type _sharp_peeked_char_maybe429;
(_sharp_peeked_char_maybe429 = (peek_char)());
({if( (((_sharp_peeked_char_maybe429 == 94))||(((Bool__type ) 0))))
{
(read_char)(),
(char_selector = intern( "[^]"));}})
;
})
,
(cr_list = ({
List__O__Form__C____type__type _sharp_make_list431;
_sharp_make_list431,
_sharp_make_list_ptr432,
(_sharp_make_list_ptr432 = ((void *) (&_sharp_make_list431))),
((void) 0);_sharp__sharp_loop433_begin435:((void) 0),
({
Int__type _sharp_peeked_char_star430;
(_sharp_peeked_char_star430 = (peek_char)());
({if( (!((((_sharp_peeked_char_star430 == 92))||(((((((int) _sharp_peeked_char_star430 >= (int) 94))&&(((int) _sharp_peeked_char_star430 <= (int) 255))))||(((((((int) _sharp_peeked_char_star430 >= (int) 93))&&(((int) _sharp_peeked_char_star430 <= (int) 92))))||(((((((int) _sharp_peeked_char_star430 >= (int) 0))&&(((int) _sharp_peeked_char_star430 <= (int) 91))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop433_end434;});}})
;
(cr = (parse_Character_Range)()),
((* _sharp_make_list_ptr432) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08518ba8 **) _sharp_make_list_ptr432))).car) = ((void *) cr)),
(_sharp_make_list_ptr432 = (&((* (* ((struct struct0x08518ba8 **) _sharp_make_list_ptr432))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop433_begin435;}),
((void) 0);_sharp__sharp_loop433_end434:((void) 0),
((* _sharp_make_list_ptr432) = ((void *) 0)),
_sharp_make_list431;
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
struct struct0x08065f90 *_sharp_pair_436;
_sharp_pair_436,
(_sharp_pair_436 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_436).car) = exp);
(((* _sharp_pair_436).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_436);
})
);
})
;}

Form__type  parse_Grouping(void)
{
return ({
Symbol__type id;
Form__type form;
(read_char)(),
(id = (parse_Identifier)()),
(read_char)(),
(form = (parse_Rule)()),
(read_char)(),
(Compound_Form)(intern( "<>"), ({
struct struct0x08065f90 *_sharp_pair_438;
_sharp_pair_438,
(_sharp_pair_438 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_438).car) = (Id_Form)(id));
(((* _sharp_pair_438).cdr) = ({
struct struct0x08065f90 *_sharp_pair_437;
_sharp_pair_437,
(_sharp_pair_437 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_437).car) = form);
(((* _sharp_pair_437).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_437);
})
);
((List__O__Form__C____type__type ) _sharp_pair_438);
})
);
})
;}

Form__type  parse_Primary(void)
{
return ({
Form__type r;
({
Int__type _sharp_peeked_char_alt439;
(_sharp_peeked_char_alt439 = (peek_char)());
(((((_sharp_peeked_char_alt439 == 40))||(((Bool__type ) 0))))?
((read_char)(),
(r = (parse_Rule)()),
(read_char)(),
r):
((((((_sharp_peeked_char_alt439 == 34))||((((_sharp_peeked_char_alt439 == 91))||(((((((int) _sharp_peeked_char_alt439 >= (int) 97))&&(((int) _sharp_peeked_char_alt439 <= (int) 122))))||((((_sharp_peeked_char_alt439 == 95))||(((((((int) _sharp_peeked_char_alt439 >= (int) 65))&&(((int) _sharp_peeked_char_alt439 <= (int) 90))))||((((_sharp_peeked_char_alt439 == 60))||((((_sharp_peeked_char_alt439 == 123))||(((Bool__type ) 0))))))))))))))))?
(({
Int__type _sharp_peeked_char_alt440;
(_sharp_peeked_char_alt440 = (peek_char)());
(((((_sharp_peeked_char_alt440 == 123))||(((Bool__type ) 0))))?
((parse_Semantic_Action)()):
((((((_sharp_peeked_char_alt440 == 34))||((((_sharp_peeked_char_alt440 == 91))||(((((((int) _sharp_peeked_char_alt440 >= (int) 97))&&(((int) _sharp_peeked_char_alt440 <= (int) 122))))||((((_sharp_peeked_char_alt440 == 95))||(((((((int) _sharp_peeked_char_alt440 >= (int) 65))&&(((int) _sharp_peeked_char_alt440 <= (int) 90))))||((((_sharp_peeked_char_alt440 == 60))||(((Bool__type ) 0))))))))))))))?
(({
Int__type _sharp_peeked_char_alt441;
(_sharp_peeked_char_alt441 = (peek_char)());
(((((_sharp_peeked_char_alt441 == 60))||(((Bool__type ) 0))))?
((parse_Grouping)()):
((((((_sharp_peeked_char_alt441 == 34))||((((_sharp_peeked_char_alt441 == 91))||(((((((int) _sharp_peeked_char_alt441 >= (int) 97))&&(((int) _sharp_peeked_char_alt441 <= (int) 122))))||((((_sharp_peeked_char_alt441 == 95))||(((((((int) _sharp_peeked_char_alt441 >= (int) 65))&&(((int) _sharp_peeked_char_alt441 <= (int) 90))))||(((Bool__type ) 0))))))))))))?
(({
Int__type _sharp_peeked_char_alt442;
(_sharp_peeked_char_alt442 = (peek_char)());
((((((((int) _sharp_peeked_char_alt442 >= (int) 97))&&(((int) _sharp_peeked_char_alt442 <= (int) 122))))||((((_sharp_peeked_char_alt442 == 95))||(((((((int) _sharp_peeked_char_alt442 >= (int) 65))&&(((int) _sharp_peeked_char_alt442 <= (int) 90))))||(((Bool__type ) 0))))))))?
((parse_Callable_Rule)()):
((((((_sharp_peeked_char_alt442 == 34))||((((_sharp_peeked_char_alt442 == 91))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt443;
(_sharp_peeked_char_alt443 = (peek_char)());
(((((_sharp_peeked_char_alt443 == 91))||(((Bool__type ) 0))))?
((parse_Character_Set)()):
((((((_sharp_peeked_char_alt443 == 34))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_maybe444;
(_sharp_peeked_char_maybe444 = (peek_char)());
({if( (((_sharp_peeked_char_maybe444 == 63))||((((_sharp_peeked_char_maybe444 == 42))||((((_sharp_peeked_char_maybe444 == 43))||(((Bool__type ) 0))))))))
{
(start = (get_point_pos)()),
({
Int__type _sharp_peeked_char_alt445;
(_sharp_peeked_char_alt445 = (peek_char)());
(((((_sharp_peeked_char_alt445 == 43))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt445 == 63))||((((_sharp_peeked_char_alt445 == 42))||(((Bool__type ) 0))))))?
(({
Int__type _sharp_peeked_char_alt446;
(_sharp_peeked_char_alt446 = (peek_char)());
(((((_sharp_peeked_char_alt446 == 42))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt446 == 63))||(((Bool__type ) 0))))?
((read_char)()):
((parse_error)()))));
})
):
((parse_error)()))));
})
,
(end = (get_point_pos)()),
(form = (Compound_Form)((intern_string)((substring)(start, end)), ({
struct struct0x08065f90 *_sharp_pair_447;
_sharp_pair_447,
(_sharp_pair_447 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_447).car) = form);
(((* _sharp_pair_447).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_447);
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
void **_sharp_make_list_ptr450;
Form__type post;
List__O__Form__C____type__type post_list;
(parse_Spacing)(),
(post_list = ({
List__O__Form__C____type__type _sharp_make_list449;
_sharp_make_list449,
_sharp_make_list_ptr450,
(_sharp_make_list_ptr450 = ((void *) (&_sharp_make_list449))),
((void) 0);_sharp__sharp_loop451_begin453:((void) 0),
({
Int__type _sharp_peeked_char_star448;
(_sharp_peeked_char_star448 = (peek_char)());
({if( (!((((_sharp_peeked_char_star448 == 34))||((((_sharp_peeked_char_star448 == 91))||(((((((int) _sharp_peeked_char_star448 >= (int) 97))&&(((int) _sharp_peeked_char_star448 <= (int) 122))))||((((_sharp_peeked_char_star448 == 95))||(((((((int) _sharp_peeked_char_star448 >= (int) 65))&&(((int) _sharp_peeked_char_star448 <= (int) 90))))||((((_sharp_peeked_char_star448 == 60))||((((_sharp_peeked_char_star448 == 123))||((((_sharp_peeked_char_star448 == 40))||(((Bool__type ) 0))))))))))))))))))))
{
({goto _sharp__sharp_loop451_end452;});}})
;
(post = (parse_Postfix)()),
(parse_Spacing)(),
((* _sharp_make_list_ptr450) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08518ba8 **) _sharp_make_list_ptr450))).car) = ((void *) post)),
(_sharp_make_list_ptr450 = (&((* (* ((struct struct0x08518ba8 **) _sharp_make_list_ptr450))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop451_begin453;}),
((void) 0);_sharp__sharp_loop451_end452:((void) 0),
((* _sharp_make_list_ptr450) = ((void *) 0)),
_sharp_make_list449;
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
((void) 0);_sharp__sharp_loop457_begin459:((void) 0),
({
Int__type _sharp_peeked_char_star454;
(_sharp_peeked_char_star454 = (peek_char)());
({if( (!((((_sharp_peeked_char_star454 == 124))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop457_end458;});}})
;
(read_char)(),
(parse_Spacing)(),
(sec = (parse_Sequence)()),
(prim = (Compound_Form)(intern( "|"), ({
struct struct0x08065f90 *_sharp_pair_456;
_sharp_pair_456,
(_sharp_pair_456 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_456).car) = prim);
(((* _sharp_pair_456).cdr) = ({
struct struct0x08065f90 *_sharp_pair_455;
_sharp_pair_455,
(_sharp_pair_455 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_455).car) = sec);
(((* _sharp_pair_455).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_455);
})
);
((List__O__Form__C____type__type ) _sharp_pair_456);
})
));
})
,
({goto _sharp__sharp_loop457_begin459;}),
((void) 0);_sharp__sharp_loop457_end458:((void) 0),
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
struct struct0x08065f90 *_sharp_pair_462;
_sharp_pair_462,
(_sharp_pair_462 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_462).car) = (Id_Form)(id));
(((* _sharp_pair_462).cdr) = ({
struct struct0x08065f90 *_sharp_pair_461;
_sharp_pair_461,
(_sharp_pair_461 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_461).car) = ret_type);
(((* _sharp_pair_461).cdr) = ({
struct struct0x08065f90 *_sharp_pair_460;
_sharp_pair_460,
(_sharp_pair_460 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_460).car) = r);
(((* _sharp_pair_460).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_460);
})
);
((List__O__Form__C____type__type ) _sharp_pair_461);
})
);
((List__O__Form__C____type__type ) _sharp_pair_462);
})
);
})
;}

Form__type  parse_Grammar(void)
{
return ({
void **_sharp_make_list_ptr465;
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
List__O__Form__C____type__type _sharp_make_list464;
_sharp_make_list464,
_sharp_make_list_ptr465,
(_sharp_make_list_ptr465 = ((void *) (&_sharp_make_list464))),
((void) 0);_sharp__sharp_loop466_begin468:((void) 0),
({
Int__type _sharp_peeked_char_star463;
(_sharp_peeked_char_star463 = (peek_char)());
({if( (!((((_sharp_peeked_char_star463 == 114))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop466_end467;});}})
;
(gr = (parse_Grammar_Rule)()),
((* _sharp_make_list_ptr465) = (alloc_cons_cell)()),
(((* (* ((struct struct0x08518ba8 **) _sharp_make_list_ptr465))).car) = ((void *) gr)),
(_sharp_make_list_ptr465 = (&((* (* ((struct struct0x08518ba8 **) _sharp_make_list_ptr465))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop466_begin468;}),
((void) 0);_sharp__sharp_loop466_end467:((void) 0),
((* _sharp_make_list_ptr465) = ((void *) 0)),
_sharp_make_list464;
})
),
(read_char)(),
(parse_Spacing)(),
(read_char)(),
(Compound_Form)(intern( "define"), ({
struct struct0x08065f90 *_sharp_pair_470;
_sharp_pair_470,
(_sharp_pair_470 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_470).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_470).cdr) = ({
struct struct0x08065f90 *_sharp_pair_469;
_sharp_pair_469,
(_sharp_pair_469 = ((struct struct0x08065f90 *) (alloc_cons_cell)()));
(((* _sharp_pair_469).car) = (Id_Form)(id));
(((* _sharp_pair_469).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_469);
})
);
((List__O__Form__C____type__type ) _sharp_pair_470);
})
);
})
;}

void init_parse_grammar(void){
}

