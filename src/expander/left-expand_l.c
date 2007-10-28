/* Automatically generated : do not edit!*/
#include "left_expand_l.inc"
Hash__O__Symbol__c__Left_Expander__C____type left_expander_hash;

void  define_left_expander(Symbol__type  symbol, Pattern_Return__type (*expander)(Compound_Form__type , Expanded_Form__type ))
{
return ({
({((Pattern_Return__type (*)(Compound_Form__type , Expanded_Form__type )) (puthash)(((void *) symbol), ((void *) expander), ((Hash_Table__type ) left_expander_hash)));
((void) 0);});
})
;}

void  init__left_expand(void)
{
return ({
({(left_expander_hash = ((Hash__O__Symbol__c__Left_Expander__C____type ) (make_hash_table)()));
((Pattern_Return__type (*)(Compound_Form__type , Expanded_Form__type )) (puthash)(((void *) intern( "let")), ((void *) (&left_expand_let)), ((Hash_Table__type ) left_expander_hash)));
((Pattern_Return__type (*)(Compound_Form__type , Expanded_Form__type )) (puthash)(((void *) intern( "@deref")), ((void *) (&left_expand_deref)), ((Hash_Table__type ) left_expander_hash)));
((Pattern_Return__type (*)(Compound_Form__type , Expanded_Form__type )) (puthash)(((void *) intern( "deref")), ((void *) (&left_expand_deref)), ((Hash_Table__type ) left_expander_hash)));
((Pattern_Return__type (*)(Compound_Form__type , Expanded_Form__type )) (puthash)(((void *) intern( "tuple")), ((void *) (&left_expand_tuple)), ((Hash_Table__type ) left_expander_hash)));
((void) 0);});
})
;}

Form__type  left_expand(Form__type  assignee, Expanded_Form__type expression)
{
return ({
Pattern_Return__type pr;
({(pr = (left_expand_rec)(assignee, expression));
((* ((struct struct0x085b70a8 *) pr)).extraction);});
})
;}

Pattern_Return__type  left_expand_rec(Form__type  assignee, Expanded_Form__type expression)
{
return ({
(((!((is_compound_form)(assignee))))?
(({
struct struct0x085b70a8 *_sharp_pointer_alloc380;
Expanded_Form__type expanded_assignee;
({(expanded_assignee = (expand)(assignee));
((Pattern_Return__type ) ({_sharp_pointer_alloc380;
(_sharp_pointer_alloc380 = ((struct struct0x085b70a8 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc380) = ((struct struct0x085b70a8 ){(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type ) 0)), ((Form__type ) (Expanded_Form)((Compound_Form)(intern( "="), ({
struct struct0x0805f9e0 *_sharp_pair_379;
({_sharp_pair_379;
(_sharp_pair_379 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_379).car) = ((Form__type ) expanded_assignee));
(((* _sharp_pair_379).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_378;
({_sharp_pair_378;
(_sharp_pair_378 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_378).car) = ((Form__type ) (coerced_form)(expression, ((* ((struct struct0x08055758 *) expanded_assignee)).type))));
(((* _sharp_pair_378).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_378);
})
);
((List__O__Form__C____type ) _sharp_pair_379);
})
), ((* ((struct struct0x08055758 *) expanded_assignee)).type)))}));
((struct struct0x085b70a8 *) _sharp_pointer_alloc380);}));});
})
):
(({
Pattern_Return__type (*lexpander)(Compound_Form__type , Expanded_Form__type );
Compound_Form__type gform;
Symbol__type head;
({(gform = ((Compound_Form__type ) assignee));
(head = ((* ((struct struct0x08054b28 *) gform)).head));
(lexpander = ((Pattern_Return__type (*)(Compound_Form__type , Expanded_Form__type )) (gethash)(((void *) head), ((Hash_Table__type ) left_expander_hash))));
({if( (lexpander == ((Pattern_Return__type (*)(Compound_Form__type , Expanded_Form__type )) 0)))
{
({
({({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_1));
(print_String)(((String__type) &__string_2));
(print_Symbol)(head);
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;
((void) 0);});
})
;}})
;
((* lexpander))(gform, expression);});
})
));
})
;}

Pattern_Return__type  left_expand_let(Compound_Form__type  cf, Expanded_Form__type expression)
{
return ({
struct struct0x085b70a8 *_sharp_pointer_alloc383;
Expanded_Form__type exp_let;
Symbol__type new_symbol;
Form__type new_expression;
Type__type id_type;
Id_Form__type id_form;
({(id_form = ((Id_Form__type ) ((* ((struct struct0x08054cf8 *) ((* ((struct struct0x08054b28 *) cf)).form_list))).head)));
id_type;
new_expression;
(((((* ((struct struct0x08054cf8 *) ((* ((struct struct0x08054b28 *) cf)).form_list))).tail) != ((List__O__Form__C____type ) 0)))?
(({
Form__type type_form;
({(type_form = ((* ((struct struct0x08054cf8 *) ((* ((struct struct0x08054cf8 *) ((* ((struct struct0x08054b28 *) cf)).form_list))).tail))).head));
(id_type = (intern_type)(type_form));
(new_expression = ((Form__type ) (coerced_form)(expression, id_type)));
((void) 0);});
})
):
(({
({(new_expression = ((Form__type ) expression));
(id_type = ((* ((struct struct0x08055758 *) expression)).type));
((void) 0);});
})
));
(new_symbol = (insert_local_variable)(((* ((struct struct0x08053210 *) id_form)).value), id_type));
(exp_let = (Expanded_Form)((Id_Form)(new_symbol), id_type));
((Pattern_Return__type ) ({_sharp_pointer_alloc383;
(_sharp_pointer_alloc383 = ((struct struct0x085b70a8 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc383) = ((struct struct0x085b70a8 ){(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type ) 0)), ((Form__type ) (Expanded_Form)((Compound_Form)(intern( "="), ({
struct struct0x0805f9e0 *_sharp_pair_382;
({_sharp_pair_382;
(_sharp_pair_382 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_382).car) = ((Form__type ) exp_let));
(((* _sharp_pair_382).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_381;
({_sharp_pair_381;
(_sharp_pair_381 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_381).car) = new_expression);
(((* _sharp_pair_381).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_381);
})
);
((List__O__Form__C____type ) _sharp_pair_382);
})
), id_type))}));
((struct struct0x085b70a8 *) _sharp_pointer_alloc383);}));});
})
;}

Pattern_Return__type  left_expand_deref(Compound_Form__type  cf, Expanded_Form__type expression)
{
return ({
struct struct0x085b70a8 *_sharp_pointer_alloc387;
Expanded_Form__type expanded_refed;
Form__type refed;
Expanded_Form__type exp_deref;
Type__type pointed_type;
Type__type type;
({(refed = ((* ((struct struct0x08054cf8 *) ((* ((struct struct0x08054b28 *) cf)).form_list))).head));
(expanded_refed = (expand)(refed));
(type = ((* ((struct struct0x08055758 *) expanded_refed)).type));
(pointed_type = ((* ((struct struct0x085a2668 *) ((Pointer_Type__type ) type))).pointed_type));
(exp_deref = (Expanded_Form)((Compound_Form)(intern( "deref"), ({
struct struct0x0805f9e0 *_sharp_pair_384;
({_sharp_pair_384;
(_sharp_pair_384 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_384).car) = ((Form__type ) expanded_refed));
(((* _sharp_pair_384).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_384);
})
), pointed_type));
((Pattern_Return__type ) ({_sharp_pointer_alloc387;
(_sharp_pointer_alloc387 = ((struct struct0x085b70a8 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc387) = ((struct struct0x085b70a8 ){(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type ) 0)), ((Form__type ) (Expanded_Form)((Compound_Form)(intern( "="), ({
struct struct0x0805f9e0 *_sharp_pair_386;
({_sharp_pair_386;
(_sharp_pair_386 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_386).car) = ((Form__type ) exp_deref));
(((* _sharp_pair_386).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_385;
({_sharp_pair_385;
(_sharp_pair_385 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_385).car) = ((Form__type ) expression));
(((* _sharp_pair_385).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_385);
})
);
((List__O__Form__C____type ) _sharp_pair_386);
})
), pointed_type))}));
((struct struct0x085b70a8 *) _sharp_pointer_alloc387);}));});
})
;}

Pattern_Return__type  left_expand_tuple(Compound_Form__type  cf, Expanded_Form__type expression)
{
return ({
struct struct0x085b70a8 *_sharp_pointer_alloc423;
List__O__Form__C____type second_assign_list;
List__O__Symbol__C____type cur_id;
List__O__Expanded_Form__C____type assign_form_list;
List__O__Symbol__C____type id_list;
Form__type return_form;
({id_list;
assign_form_list;
({
List__O__Expanded_Form__C____type *assign_form_list_ptr;
Compound_Form__type gform;
List__O__Symbol__C____type *id_list_ptr;
({(id_list_ptr = (&id_list));
(assign_form_list_ptr = (&assign_form_list));
(gform = ((Compound_Form__type ) ((* ((struct struct0x08055758 *) expression)).return_form)));
({if( ((is_compound_form)(((Form__type ) gform)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_3));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x0805f9e0 *_sharp_pair_388;
({_sharp_pair_388;
(_sharp_pair_388 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_388).car) = (Id_Form)(intern( "gform")));
(((* _sharp_pair_388).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_388);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_4));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
({if( ((((* ((struct struct0x08054b28 *) gform)).head) == intern( "tuple")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_5));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0805f9e0 *_sharp_pair_392;
({_sharp_pair_392;
(_sharp_pair_392 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_392).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x0805f9e0 *_sharp_pair_390;
({_sharp_pair_390;
(_sharp_pair_390 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_390).car) = (Id_Form)(intern( "gform")));
(((* _sharp_pair_390).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_389;
({_sharp_pair_389;
(_sharp_pair_389 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_389).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_389).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_389);
})
);
((List__O__Form__C____type ) _sharp_pair_390);
})
));
(((* _sharp_pair_392).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_391;
({_sharp_pair_391;
(_sharp_pair_391 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_391).car) = (Symbol_Form)(intern( "tuple")));
(((* _sharp_pair_391).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_391);
})
);
((List__O__Form__C____type ) _sharp_pair_392);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_6));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
({
List__O__Form__C____type _sharp_iterator394;
(_sharp_iterator394 = ((* ((struct struct0x08054b28 *) gform)).form_list));
({({_sharp__sharp_loop395_begin403:;
({
Form__type subexpr;
({if( (_sharp_iterator394 == ((List__O__Form__C____type ) 0)))
{
({goto _sharp__sharp_loop395_end396;});}})
;
(subexpr = ((* ((struct struct0x0805f9e0 *) _sharp_iterator394)).car));
({
Form__type copy_form;
Symbol__type tuple_copy;
({(tuple_copy = (gensym)(((String__type) &__string_7)));
((* id_list_ptr) = ({
struct struct0x085d8d60 *_sharp_pair_397;
({_sharp_pair_397;
(_sharp_pair_397 = ((struct struct0x085d8d60 *) (alloc_cons_cell)()));});
(((* _sharp_pair_397).car) = tuple_copy);
(((* _sharp_pair_397).cdr) = ((List__O__Symbol__C____type ) 0));
((List__O__Symbol__C____type ) _sharp_pair_397);
})
);
(id_list_ptr = (&((* ((struct struct0x085d0028 *) (* id_list_ptr))).tail)));
(copy_form = (Compound_Form)(intern( "="), ({
struct struct0x0805f9e0 *_sharp_pair_400;
({_sharp_pair_400;
(_sharp_pair_400 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_400).car) = (Compound_Form)(intern( "let"), ({
struct struct0x0805f9e0 *_sharp_pair_398;
({_sharp_pair_398;
(_sharp_pair_398 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_398).car) = (Id_Form)(tuple_copy));
(((* _sharp_pair_398).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_398);
})
));
(((* _sharp_pair_400).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_399;
({_sharp_pair_399;
(_sharp_pair_399 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_399).car) = subexpr);
(((* _sharp_pair_399).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_399);
})
);
((List__O__Form__C____type ) _sharp_pair_400);
})
));
((* assign_form_list_ptr) = ({
struct struct0x08218c30 *_sharp_pair_401;
({_sharp_pair_401;
(_sharp_pair_401 = ((struct struct0x08218c30 *) (alloc_cons_cell)()));});
(((* _sharp_pair_401).car) = (expand)(copy_form));
(((* _sharp_pair_401).cdr) = ((List__O__Expanded_Form__C____type ) 0));
((List__O__Expanded_Form__C____type ) _sharp_pair_401);
})
);
(assign_form_list_ptr = (&((* ((struct struct0x081f9ae0 *) (* assign_form_list_ptr))).tail)));
((void) 0);});
})
;
_sharp__sharp_loop395_continue402:;
(_sharp_iterator394 = ((* ((struct struct0x0805f9e0 *) _sharp_iterator394)).cdr));
})
;
({goto _sharp__sharp_loop395_begin403;});});
_sharp__sharp_loop395_end396:;});
})
;
((* assign_form_list_ptr) = ((List__O__Expanded_Form__C____type ) 0));
((* id_list_ptr) = ((List__O__Symbol__C____type ) 0));
((void) 0);});
})
;
(cur_id = id_list);
second_assign_list;
({
List__O__Form__C____type *second_assign_list_ptr;
({(second_assign_list_ptr = (&second_assign_list));
({
List__O__Form__C____type _sharp_iterator405;
(_sharp_iterator405 = ((* ((struct struct0x08054b28 *) cf)).form_list));
({({_sharp__sharp_loop406_begin415:;
({
Form__type cur_form;
({if( (_sharp_iterator405 == ((List__O__Form__C____type ) 0)))
{
({goto _sharp__sharp_loop406_end407;});}})
;
(cur_form = ((* ((struct struct0x0805f9e0 *) _sharp_iterator405)).car));
({
Symbol__type id;
({({if( ((cur_id != ((List__O__Symbol__C____type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_8));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x0805f9e0 *_sharp_pair_412;
({_sharp_pair_412;
(_sharp_pair_412 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_412).car) = (Id_Form)(intern( "cur_id")));
(((* _sharp_pair_412).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_411;
({_sharp_pair_411;
(_sharp_pair_411 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_411).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0805f9e0 *_sharp_pair_410;
({_sharp_pair_410;
(_sharp_pair_410 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_410).car) = (Compound_Form)(intern( "List"), ({
struct struct0x0805f9e0 *_sharp_pair_408;
({_sharp_pair_408;
(_sharp_pair_408 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_408).car) = (Id_Form)(intern( "Symbol")));
(((* _sharp_pair_408).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_408);
})
));
(((* _sharp_pair_410).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_409;
({_sharp_pair_409;
(_sharp_pair_409 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_409).car) = (Int_Form)(0));
(((* _sharp_pair_409).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_409);
})
);
((List__O__Form__C____type ) _sharp_pair_410);
})
));
(((* _sharp_pair_411).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_411);
})
);
((List__O__Form__C____type ) _sharp_pair_412);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_9));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(id = ((* ((struct struct0x085d0028 *) cur_id)).head));
((* second_assign_list_ptr) = ({
struct struct0x0805f9e0 *_sharp_pair_413;
({_sharp_pair_413;
(_sharp_pair_413 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_413).car) = (left_expand)(cur_form, (expand)((Id_Form)(id))));
(((* _sharp_pair_413).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_413);
})
);
(second_assign_list_ptr = (&((* ((struct struct0x08054cf8 *) (* second_assign_list_ptr))).tail)));
(cur_id = ((* ((struct struct0x085d0028 *) cur_id)).tail));
((void) 0);});
})
;
_sharp__sharp_loop406_continue414:;
(_sharp_iterator405 = ((* ((struct struct0x0805f9e0 *) _sharp_iterator405)).cdr));
})
;
({goto _sharp__sharp_loop406_begin415;});});
_sharp__sharp_loop406_end407:;});
})
;
((* second_assign_list_ptr) = ((List__O__Form__C____type ) 0));
((void) 0);});
})
;
({if( ((cur_id == ((List__O__Symbol__C____type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_10));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x0805f9e0 *_sharp_pair_420;
({_sharp_pair_420;
(_sharp_pair_420 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_420).car) = (Id_Form)(intern( "cur_id")));
(((* _sharp_pair_420).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_419;
({_sharp_pair_419;
(_sharp_pair_419 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_419).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x0805f9e0 *_sharp_pair_418;
({_sharp_pair_418;
(_sharp_pair_418 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_418).car) = (Compound_Form)(intern( "List"), ({
struct struct0x0805f9e0 *_sharp_pair_416;
({_sharp_pair_416;
(_sharp_pair_416 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_416).car) = (Id_Form)(intern( "Symbol")));
(((* _sharp_pair_416).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_416);
})
));
(((* _sharp_pair_418).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_417;
({_sharp_pair_417;
(_sharp_pair_417 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_417).car) = (Int_Form)(0));
(((* _sharp_pair_417).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_417);
})
);
((List__O__Form__C____type ) _sharp_pair_418);
})
));
(((* _sharp_pair_419).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_419);
})
);
((List__O__Form__C____type ) _sharp_pair_420);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_11));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(2);
})
;}})
;
(return_form = (Compound_Form)(intern( "seq"), ({
struct struct0x0805f9e0 *_sharp_pair_422;
({_sharp_pair_422;
(_sharp_pair_422 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_422).car) = (Compound_Form)(intern( "seq"), ((List__O__Form__C____type ) assign_form_list)));
(((* _sharp_pair_422).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_421;
({_sharp_pair_421;
(_sharp_pair_421 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_421).car) = (Compound_Form)(intern( "seq"), second_assign_list));
(((* _sharp_pair_421).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_421);
})
);
((List__O__Form__C____type ) _sharp_pair_422);
})
));
((Pattern_Return__type ) ({_sharp_pointer_alloc423;
(_sharp_pointer_alloc423 = ((struct struct0x085b70a8 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc423) = ((struct struct0x085b70a8 ){(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type ) 0)), ((Form__type ) (expand)(return_form))}));
((struct struct0x085b70a8 *) _sharp_pointer_alloc423);}));});
})
;}
