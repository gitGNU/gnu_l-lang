/* parse-grammar.c - 
   Copyright (C) 2007 Matthieu Lemerre <racin@free.fr>

   This file is part of the L programming language.

   The L programming language is free software; you can redistribute it 
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.
   
   The L programming language is distributed in the hope that it will be 
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty 
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
   GNU Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public License
   along with the L programming language; see the file COPYING.  If not,
   write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
   Boston, MA  02110-1301  USA.  */

#include "parse-grammar.inc"

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

Int__type  parse_Comment(void)
{
return ({
(read_char)(),
(read_char)(),
((void) 0);_sharp__sharp_loop836_begin838:((void) 0),
({
Int__type _sharp_peeked_char_star835;
(_sharp_peeked_char_star835 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star835 >= (int) 11))&&(((int) _sharp_peeked_char_star835 <= (int) 255))))||(((((((int) _sharp_peeked_char_star835 >= (int) 0))&&(((int) _sharp_peeked_char_star835 <= (int) 9))))||(((Bool__type ) 0))))))))
{
({goto _sharp__sharp_loop836_end837;});}})
;
(read_char)();
})
,
({goto _sharp__sharp_loop836_begin838;}),
((void) 0);_sharp__sharp_loop836_end837:((void) 0),
(read_char)();
})
;}

void  parse_Spacing(void)
{
return ({
((void) 0);_sharp__sharp_loop841_begin843:((void) 0),
({
Int__type _sharp_peeked_char_star839;
(_sharp_peeked_char_star839 = (peek_char)());
({if( (!((((_sharp_peeked_char_star839 == 9))||((((_sharp_peeked_char_star839 == 10))||((((_sharp_peeked_char_star839 == 32))||((((_sharp_peeked_char_star839 == 47))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop841_end842;});}})
;
({
Int__type _sharp_peeked_char_alt840;
(_sharp_peeked_char_alt840 = (peek_char)());
(((((_sharp_peeked_char_alt840 == 47))||(((Bool__type ) 0))))?
((parse_Comment)()):
((((((_sharp_peeked_char_alt840 == 9))||((((_sharp_peeked_char_alt840 == 10))||((((_sharp_peeked_char_alt840 == 32))||(((Bool__type ) 0))))))))?
((read_char)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop841_begin843;}),
((void) 0);_sharp__sharp_loop841_end842:((void) 0);
})
;}

Symbol__type  parse_Identifier(void)
{
return ({
Int__type start;
Int__type end;
(start = (get_point_pos)()),
(parse_Alpha)(),
((void) 0);_sharp__sharp_loop845_begin847:((void) 0),
({
Int__type _sharp_peeked_char_star844;
(_sharp_peeked_char_star844 = (peek_char)());
({if( (!(((((((int) _sharp_peeked_char_star844 >= (int) 48))&&(((int) _sharp_peeked_char_star844 <= (int) 57))))||((((_sharp_peeked_char_star844 == 95))||(((((((int) _sharp_peeked_char_star844 >= (int) 65))&&(((int) _sharp_peeked_char_star844 <= (int) 90))))||(((((((int) _sharp_peeked_char_star844 >= (int) 97))&&(((int) _sharp_peeked_char_star844 <= (int) 122))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop845_end846;});}})
;
(parse_Alpha_Num)();
})
,
({goto _sharp__sharp_loop845_begin847;}),
((void) 0);_sharp__sharp_loop845_end846:((void) 0),
(end = (get_point_pos)()),
(intern_string)((substring)(start, end));
})
;}

Int__type  parse_Escaped_Character(void)
{
return ({
(read_char)(),
({
Int__type _sharp_peeked_char_alt848;
(_sharp_peeked_char_alt848 = (peek_char)());
((((((((int) _sharp_peeked_char_alt848 >= (int) 117))&&(((int) _sharp_peeked_char_alt848 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt848 >= (int) 111))&&(((int) _sharp_peeked_char_alt848 <= (int) 115))))||(((((((int) _sharp_peeked_char_alt848 >= (int) 0))&&(((int) _sharp_peeked_char_alt848 <= (int) 109))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt848 == 116))||(((Bool__type ) 0))))?
((read_char)(),
9):
((((((_sharp_peeked_char_alt848 == 110))||(((Bool__type ) 0))))?
((read_char)(),
10):
((parse_error)()))))));
})
;
})
;}

Int__type  parse_Maybe_Escaped_Character(void)
{
return ({
({
Int__type _sharp_peeked_char_alt849;
(_sharp_peeked_char_alt849 = (peek_char)());
((((((((int) _sharp_peeked_char_alt849 >= (int) 93))&&(((int) _sharp_peeked_char_alt849 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt849 >= (int) 0))&&(((int) _sharp_peeked_char_alt849 <= (int) 91))))||(((Bool__type ) 0))))))?
((read_char)()):
((((((_sharp_peeked_char_alt849 == 92))||(((Bool__type ) 0))))?
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
Int__type _sharp_peeked_char_alt850;
(_sharp_peeked_char_alt850 = (peek_char)());
((((((((int) _sharp_peeked_char_alt850 >= (int) 94))&&(((int) _sharp_peeked_char_alt850 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt850 >= (int) 93))&&(((int) _sharp_peeked_char_alt850 <= (int) 92))))||(((((((int) _sharp_peeked_char_alt850 >= (int) 0))&&(((int) _sharp_peeked_char_alt850 <= (int) 91))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt850 == 92))||(((Bool__type ) 0))))?
((parse_Escaped_Character)()):
((parse_error)()))));
})
;
})
;}

Form__type  parse_Character_Range(void)
{
return ({
Int__type max;
Int__type min;
(min = (max = (parse_Maybe_Escaped_Character_Character_Range)())),
({
Int__type _sharp_peeked_char_maybe851;
(_sharp_peeked_char_maybe851 = (peek_char)());
({if( (((_sharp_peeked_char_maybe851 == 45))||(((Bool__type ) 0))))
{
(read_char)(),
(max = (parse_Maybe_Escaped_Character)());}})
;
})
,
(((min == max))?
((Int_Form)(min)):
((Compound_Form)(intern( "-"), ({
struct struct0x080933f8 *_sharp_pair_853;
_sharp_pair_853,
(_sharp_pair_853 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_853).car) = (Int_Form)(min));
(((* _sharp_pair_853).cdr) = ({
struct struct0x080933f8 *_sharp_pair_852;
_sharp_pair_852,
(_sharp_pair_852 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_852).car) = (Int_Form)(max));
(((* _sharp_pair_852).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_852);
})
);
((List__O__Form__C____type__type ) _sharp_pair_853);
})
)));
})
;}

Form__type  parse_Character_Set(void)
{
return ({
void **_sharp_make_list_ptr857;
List__O__Form__C____type__type cr_list;
Symbol__type char_selector;
Form__type cr;
(char_selector = intern( "[]")),
(read_char)(),
({
Int__type _sharp_peeked_char_maybe854;
(_sharp_peeked_char_maybe854 = (peek_char)());
({if( (((_sharp_peeked_char_maybe854 == 94))||(((Bool__type ) 0))))
{
(read_char)(),
(char_selector = intern( "[^]"));}})
;
})
,
(cr_list = ({
List__O__Form__C____type__type _sharp_make_list856;
_sharp_make_list856,
_sharp_make_list_ptr857,
(_sharp_make_list_ptr857 = ((void *) (&_sharp_make_list856))),
((void) 0);_sharp__sharp_loop858_begin860:((void) 0),
({
Int__type _sharp_peeked_char_star855;
(_sharp_peeked_char_star855 = (peek_char)());
({if( (!((((_sharp_peeked_char_star855 == 92))||(((((((int) _sharp_peeked_char_star855 >= (int) 94))&&(((int) _sharp_peeked_char_star855 <= (int) 255))))||(((((((int) _sharp_peeked_char_star855 >= (int) 93))&&(((int) _sharp_peeked_char_star855 <= (int) 92))))||(((((((int) _sharp_peeked_char_star855 >= (int) 0))&&(((int) _sharp_peeked_char_star855 <= (int) 91))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop858_end859;});}})
;
(cr = (parse_Character_Range)()),
((* _sharp_make_list_ptr857) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084f28c0 **) _sharp_make_list_ptr857))).car) = ((void *) cr)),
(_sharp_make_list_ptr857 = (&((* (* ((struct struct0x084f28c0 **) _sharp_make_list_ptr857))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop858_begin860;}),
((void) 0);_sharp__sharp_loop858_end859:((void) 0),
((* _sharp_make_list_ptr857) = ((void *) 0)),
_sharp_make_list856;
})
),
(read_char)(),
(Compound_Form)(char_selector, cr_list);
})
;}

Form__type  parse_String(void)
{
return ({
Int__type start;
Int__type end;
(read_char)(),
(start = (get_point_pos)()),
((void) 0);_sharp__sharp_loop863_begin865:((void) 0),
({
Int__type _sharp_peeked_char_star861;
(_sharp_peeked_char_star861 = (peek_char)());
({if( (!((((_sharp_peeked_char_star861 == 92))||(((((((int) _sharp_peeked_char_star861 >= (int) 93))&&(((int) _sharp_peeked_char_star861 <= (int) 255))))||(((((((int) _sharp_peeked_char_star861 >= (int) 35))&&(((int) _sharp_peeked_char_star861 <= (int) 91))))||(((((((int) _sharp_peeked_char_star861 >= (int) 0))&&(((int) _sharp_peeked_char_star861 <= (int) 33))))||(((Bool__type ) 0))))))))))))
{
({goto _sharp__sharp_loop863_end864;});}})
;
({
Int__type _sharp_peeked_char_alt862;
(_sharp_peeked_char_alt862 = (peek_char)());
((((((((int) _sharp_peeked_char_alt862 >= (int) 93))&&(((int) _sharp_peeked_char_alt862 <= (int) 255))))||(((((((int) _sharp_peeked_char_alt862 >= (int) 35))&&(((int) _sharp_peeked_char_alt862 <= (int) 91))))||(((((((int) _sharp_peeked_char_alt862 >= (int) 0))&&(((int) _sharp_peeked_char_alt862 <= (int) 33))))||(((Bool__type ) 0))))))))?
((read_char)()):
((((((_sharp_peeked_char_alt862 == 92))||(((Bool__type ) 0))))?
((parse_Escaped_Character)()):
((parse_error)()))));
})
;
})
,
({goto _sharp__sharp_loop863_begin865;}),
((void) 0);_sharp__sharp_loop863_end864:((void) 0),
(end = (get_point_pos)()),
(read_char)(),
(String_Form)((substring)(start, end));
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
struct struct0x080933f8 *_sharp_pair_866;
_sharp_pair_866,
(_sharp_pair_866 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_866).car) = exp);
(((* _sharp_pair_866).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_866);
})
);
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
struct struct0x080933f8 *_sharp_pair_868;
_sharp_pair_868,
(_sharp_pair_868 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_868).car) = (Id_Form)(id));
(((* _sharp_pair_868).cdr) = ({
struct struct0x080933f8 *_sharp_pair_867;
_sharp_pair_867,
(_sharp_pair_867 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_867).car) = form);
(((* _sharp_pair_867).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_867);
})
);
((List__O__Form__C____type__type ) _sharp_pair_868);
})
);
})
;}

Form__type  parse_Primary(void)
{
return ({
Form__type r;
({
Int__type _sharp_peeked_char_alt869;
(_sharp_peeked_char_alt869 = (peek_char)());
(((((_sharp_peeked_char_alt869 == 40))||(((Bool__type ) 0))))?
((read_char)(),
(r = (parse_Rule)()),
(read_char)(),
r):
((((((_sharp_peeked_char_alt869 == 60))||(((Bool__type ) 0))))?
((parse_Grouping)()):
((((((_sharp_peeked_char_alt869 == 123))||(((Bool__type ) 0))))?
((parse_Semantic_Action)()):
((((((_sharp_peeked_char_alt869 == 95))||(((((((int) _sharp_peeked_char_alt869 >= (int) 65))&&(((int) _sharp_peeked_char_alt869 <= (int) 90))))||(((((((int) _sharp_peeked_char_alt869 >= (int) 97))&&(((int) _sharp_peeked_char_alt869 <= (int) 122))))||(((Bool__type ) 0))))))))?
((parse_Callable_Rule)()):
((((((_sharp_peeked_char_alt869 == 39))||((((_sharp_peeked_char_alt869 == 34))||(((Bool__type ) 0))))))?
((parse_String)()):
((((((_sharp_peeked_char_alt869 == 91))||(((Bool__type ) 0))))?
((parse_Character_Set)()):
((parse_error)()))))))))))));
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
Int__type _sharp_peeked_char_maybe870;
(_sharp_peeked_char_maybe870 = (peek_char)());
({if( (((_sharp_peeked_char_maybe870 == 63))||((((_sharp_peeked_char_maybe870 == 42))||((((_sharp_peeked_char_maybe870 == 43))||(((Bool__type ) 0))))))))
{
(start = (get_point_pos)()),
({
Int__type _sharp_peeked_char_alt871;
(_sharp_peeked_char_alt871 = (peek_char)());
(((((_sharp_peeked_char_alt871 == 43))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt871 == 42))||(((Bool__type ) 0))))?
((read_char)()):
((((((_sharp_peeked_char_alt871 == 63))||(((Bool__type ) 0))))?
((read_char)()):
((parse_error)()))))));
})
,
(end = (get_point_pos)()),
(form = (Compound_Form)((intern_string)((substring)(start, end)), ({
struct struct0x080933f8 *_sharp_pair_872;
_sharp_pair_872,
(_sharp_pair_872 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_872).car) = form);
(((* _sharp_pair_872).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_872);
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
void **_sharp_make_list_ptr875;
Form__type post;
List__O__Form__C____type__type post_list;
(parse_Spacing)(),
(post_list = ({
List__O__Form__C____type__type _sharp_make_list874;
_sharp_make_list874,
_sharp_make_list_ptr875,
(_sharp_make_list_ptr875 = ((void *) (&_sharp_make_list874))),
((void) 0);_sharp__sharp_loop876_begin878:((void) 0),
({
Int__type _sharp_peeked_char_star873;
(_sharp_peeked_char_star873 = (peek_char)());
({if( (!((((_sharp_peeked_char_star873 == 91))||((((_sharp_peeked_char_star873 == 39))||((((_sharp_peeked_char_star873 == 34))||((((_sharp_peeked_char_star873 == 95))||(((((((int) _sharp_peeked_char_star873 >= (int) 65))&&(((int) _sharp_peeked_char_star873 <= (int) 90))))||(((((((int) _sharp_peeked_char_star873 >= (int) 97))&&(((int) _sharp_peeked_char_star873 <= (int) 122))))||((((_sharp_peeked_char_star873 == 123))||((((_sharp_peeked_char_star873 == 60))||((((_sharp_peeked_char_star873 == 40))||(((Bool__type ) 0))))))))))))))))))))))
{
({goto _sharp__sharp_loop876_end877;});}})
;
(post = (parse_Postfix)()),
(parse_Spacing)(),
((* _sharp_make_list_ptr875) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084f28c0 **) _sharp_make_list_ptr875))).car) = ((void *) post)),
(_sharp_make_list_ptr875 = (&((* (* ((struct struct0x084f28c0 **) _sharp_make_list_ptr875))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop876_begin878;}),
((void) 0);_sharp__sharp_loop876_end877:((void) 0),
((* _sharp_make_list_ptr875) = ((void *) 0)),
_sharp_make_list874;
})
),
(Compound_Form)(intern( " "), post_list);
})
;}

Form__type  parse_Alternative(void)
{
return ({
Form__type sec;
Form__type prim;
(prim = (parse_Sequence)()),
((void) 0);_sharp__sharp_loop882_begin884:((void) 0),
({
Int__type _sharp_peeked_char_star879;
(_sharp_peeked_char_star879 = (peek_char)());
({if( (!((((_sharp_peeked_char_star879 == 124))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop882_end883;});}})
;
(read_char)(),
(parse_Spacing)(),
(sec = (parse_Sequence)()),
(prim = (Compound_Form)(intern( "|"), ({
struct struct0x080933f8 *_sharp_pair_881;
_sharp_pair_881,
(_sharp_pair_881 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_881).car) = prim);
(((* _sharp_pair_881).cdr) = ({
struct struct0x080933f8 *_sharp_pair_880;
_sharp_pair_880,
(_sharp_pair_880 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_880).car) = sec);
(((* _sharp_pair_880).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_880);
})
);
((List__O__Form__C____type__type ) _sharp_pair_881);
})
));
})
,
({goto _sharp__sharp_loop882_begin884;}),
((void) 0);_sharp__sharp_loop882_end883:((void) 0),
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
Form__type r;
Symbol__type id;
(read_char)(),
(read_char)(),
(read_char)(),
(read_char)(),
(parse_Spacing)(),
(id = (parse_Identifier)()),
(parse_Spacing)(),
(read_char)(),
(parse_Spacing)(),
(r = (parse_Rule)()),
(parse_Spacing)(),
(read_char)(),
(parse_Spacing)(),
(Compound_Form)(intern( "rule"), ({
struct struct0x080933f8 *_sharp_pair_886;
_sharp_pair_886,
(_sharp_pair_886 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_886).car) = (Id_Form)(id));
(((* _sharp_pair_886).cdr) = ({
struct struct0x080933f8 *_sharp_pair_885;
_sharp_pair_885,
(_sharp_pair_885 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_885).car) = r);
(((* _sharp_pair_885).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_885);
})
);
((List__O__Form__C____type__type ) _sharp_pair_886);
})
);
})
;}

Form__type  parse_Grammar(void)
{
return ({
void **_sharp_make_list_ptr889;
Form__type gr;
List__O__Form__C____type__type gr_list;
Symbol__type id;
(parse_Spacing)(),
(id = (parse_Identifier)()),
(parse_Spacing)(),
(read_char)(),
(parse_Spacing)(),
(read_char)(),
(parse_Spacing)(),
(gr_list = ({
List__O__Form__C____type__type _sharp_make_list888;
_sharp_make_list888,
_sharp_make_list_ptr889,
(_sharp_make_list_ptr889 = ((void *) (&_sharp_make_list888))),
((void) 0);_sharp__sharp_loop890_begin892:((void) 0),
({
Int__type _sharp_peeked_char_star887;
(_sharp_peeked_char_star887 = (peek_char)());
({if( (!((((_sharp_peeked_char_star887 == 114))||(((Bool__type ) 0))))))
{
({goto _sharp__sharp_loop890_end891;});}})
;
(gr = (parse_Grammar_Rule)()),
((* _sharp_make_list_ptr889) = (alloc_cons_cell)()),
(((* (* ((struct struct0x084f28c0 **) _sharp_make_list_ptr889))).car) = ((void *) gr)),
(_sharp_make_list_ptr889 = (&((* (* ((struct struct0x084f28c0 **) _sharp_make_list_ptr889))).cdr))),
((void) 0);
})
,
({goto _sharp__sharp_loop890_begin892;}),
((void) 0);_sharp__sharp_loop890_end891:((void) 0),
((* _sharp_make_list_ptr889) = ((void *) 0)),
_sharp_make_list888;
})
),
(read_char)(),
(parse_Spacing)(),
(read_char)(),
(parse_Spacing)(),
(Compound_Form)(intern( "define"), ({
struct struct0x080933f8 *_sharp_pair_894;
_sharp_pair_894,
(_sharp_pair_894 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_894).car) = (Id_Form)(intern( "grammar")));
(((* _sharp_pair_894).cdr) = ({
struct struct0x080933f8 *_sharp_pair_893;
_sharp_pair_893,
(_sharp_pair_893 = ((struct struct0x080933f8 *) (alloc_cons_cell)()));
(((* _sharp_pair_893).car) = (Id_Form)(id));
(((* _sharp_pair_893).cdr) = gr_list);
((List__O__Form__C____type__type ) _sharp_pair_893);
})
);
((List__O__Form__C____type__type ) _sharp_pair_894);
})
);
})
;}
