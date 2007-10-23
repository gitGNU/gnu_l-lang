/* Automatically generated : do not edit!*/
#include "left_expand_l.inc"
Hash__O__Symbol__c__Left_Expander__C____type left_expander_hash;

void  define_left_expander(Symbol__type  symbol, Form__type (*expander)(Compound_Form__type , Expanded_Form__type ))
{
return ({
({((Form__type (*)(Compound_Form__type , Expanded_Form__type )) (puthash)(((void *) symbol), ((void *) expander), ((Hash_Table__type ) left_expander_hash)));
((void) 0);});
})
;}

void  init__left_expand(void)
{
return ({
({(left_expander_hash = ((Hash__O__Symbol__c__Left_Expander__C____type ) (make_hash_table)()));
((Form__type (*)(Compound_Form__type , Expanded_Form__type )) (puthash)(((void *) intern( "let")), ((void *) (&left_expand_let)), ((Hash_Table__type ) left_expander_hash)));
((Form__type (*)(Compound_Form__type , Expanded_Form__type )) (puthash)(((void *) intern( "@deref")), ((void *) (&left_expand_deref)), ((Hash_Table__type ) left_expander_hash)));
((Form__type (*)(Compound_Form__type , Expanded_Form__type )) (puthash)(((void *) intern( "deref")), ((void *) (&left_expand_deref)), ((Hash_Table__type ) left_expander_hash)));
((Form__type (*)(Compound_Form__type , Expanded_Form__type )) (puthash)(((void *) intern( "tuple")), ((void *) (&left_expand_deref)), ((Hash_Table__type ) left_expander_hash)));
((void) 0);});
})
;}

Form__type  left_expand(Form__type  assignee, Expanded_Form__type expression)
{
return ({
(((!((is_compound_form)(assignee))))?
(({
Expanded_Form__type expanded_assignee;
({(expanded_assignee = (expand)(assignee));
((Form__type ) (Expanded_Form)((Compound_Form)(intern( "="), ({
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
), ((* ((struct struct0x08055758 *) expanded_assignee)).type)));});
})
):
(({
Form__type (*lexpander)(Compound_Form__type , Expanded_Form__type );
Compound_Form__type gform;
Symbol__type head;
({(gform = ((Compound_Form__type ) assignee));
(head = ((* ((struct struct0x08054b28 *) gform)).head));
(lexpander = ((Form__type (*)(Compound_Form__type , Expanded_Form__type )) (gethash)(((void *) head), ((Hash_Table__type ) left_expander_hash))));
({if( (lexpander == ((Form__type (*)(Compound_Form__type , Expanded_Form__type )) 0)))
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

Form__type  left_expand_let(Compound_Form__type  cf, Expanded_Form__type expression)
{
return ((Form__type ) ({
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
(Expanded_Form)((Compound_Form)(intern( "="), ({
struct struct0x0805f9e0 *_sharp_pair_381;
({_sharp_pair_381;
(_sharp_pair_381 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_381).car) = ((Form__type ) exp_let));
(((* _sharp_pair_381).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_380;
({_sharp_pair_380;
(_sharp_pair_380 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_380).car) = new_expression);
(((* _sharp_pair_380).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_380);
})
);
((List__O__Form__C____type ) _sharp_pair_381);
})
), id_type);});
})
);}

Form__type  left_expand_deref(Compound_Form__type  cf, Expanded_Form__type expression)
{
return ((Form__type ) ({
Expanded_Form__type expanded_refed;
Form__type refed;
Expanded_Form__type exp_deref;
Type__type pointed_type;
Type__type type;
({(refed = ((* ((struct struct0x08054cf8 *) ((* ((struct struct0x08054b28 *) cf)).form_list))).head));
(expanded_refed = (expand)(refed));
(type = ((* ((struct struct0x08055758 *) expanded_refed)).type));
(pointed_type = ((* ((struct struct0x08590a98 *) ((Pointer_Type__type ) type))).pointed_type));
(exp_deref = (Expanded_Form)((Compound_Form)(intern( "deref"), ({
struct struct0x0805f9e0 *_sharp_pair_382;
({_sharp_pair_382;
(_sharp_pair_382 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_382).car) = ((Form__type ) expanded_refed));
(((* _sharp_pair_382).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_382);
})
), pointed_type));
(Expanded_Form)((Compound_Form)(intern( "="), ({
struct struct0x0805f9e0 *_sharp_pair_384;
({_sharp_pair_384;
(_sharp_pair_384 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_384).car) = ((Form__type ) exp_deref));
(((* _sharp_pair_384).cdr) = ({
struct struct0x0805f9e0 *_sharp_pair_383;
({_sharp_pair_383;
(_sharp_pair_383 = ((struct struct0x0805f9e0 *) (alloc_cons_cell)()));});
(((* _sharp_pair_383).car) = ((Form__type ) expression));
(((* _sharp_pair_383).cdr) = ((List__O__Form__C____type ) 0));
((List__O__Form__C____type ) _sharp_pair_383);
})
);
((List__O__Form__C____type ) _sharp_pair_384);
})
), pointed_type);});
})
);}

Form__type  left_expand_tuple(Compound_Form__type  cf, Expanded_Form__type expression)
{
return ({
({({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_3));
(print_String)(((String__type) &__string_4));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;
((Form__type ) 0);});
})
;}

void init_left_expand_l(void){
}
