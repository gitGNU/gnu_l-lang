/* Automatically generated : do not edit!*/
#include "grammar-expander.inc"
struct struct0x085f6590 semantic_condition_then;

Hash__O__Symbol__c__Type__C____type__type id_used;

Hash__O__Symbol__c__Form__C____type__type grammar_hash;

Hash__O__Symbol__c__Hash__O__Symbol__c__Form__C____C____type__type rules_hash;

Hash__O__Symbol__c__Hash__O__Symbol__c__List__O__Character_Set__C____C____C____type__type head_set_hash;

Symbol__type grammar_name;

String__type  function_name_from_grammar_and_rule(Symbol__type  grammar_name, Symbol__type  rule_name)
{
return ({
(concat)(((String__type) &__string_1), (concat)((get_symbol_name)((convert_id)(grammar_name)), (concat)(((String__type) &__string_2), (get_symbol_name)((convert_id)(rule_name)))));
})
;}

List__O__Character_Set__C____type__type  head_set(Form__type  parse_form, List__O__Form__C____type__type  next_rules)
{
return ({
List__O__Character_Set__C____type__type cs_list;
Character_Set__type cs;
({cs;
cs_list;
(((is_compound_form)(parse_form))?
(({
Compound_Form__type cf;
({(cf = ((Compound_Form__type ) parse_form));
(((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "[]")))?
(({
({(cs_list = ({
struct struct0x085ac238 *_sharp_pair_439;
({_sharp_pair_439;
(_sharp_pair_439 = ((struct struct0x085ac238 *) (alloc_cons_cell)()));});
(((* _sharp_pair_439).car) = (make_Character_Set)(((Form__type ) cf)));
(((* _sharp_pair_439).cdr) = ((List__O__Character_Set__C____type__type ) 0));
((List__O__Character_Set__C____type__type ) _sharp_pair_439);
})
);
((void) 0);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "[^]")))?
(({
({(cs_list = ({
struct struct0x085ac238 *_sharp_pair_440;
({_sharp_pair_440;
(_sharp_pair_440 = ((struct struct0x085ac238 *) (alloc_cons_cell)()));});
(((* _sharp_pair_440).car) = (make_inverse_Character_Set)(((Form__type ) cf)));
(((* _sharp_pair_440).cdr) = ((List__O__Character_Set__C____type__type ) 0));
((List__O__Character_Set__C____type__type ) _sharp_pair_440);
})
);
((void) 0);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( " ")))?
(({
({(cs_list = (head_set)(((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head), ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail)));
((void) 0);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( ":")))?
(({
({(cs_list = (head_set)(((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail))).head), next_rules));
((void) 0);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "|")))?
(({
List__O__Character_Set__C____type__type cs_;
({({if( ((((* ((struct struct0x0805eec0 *) cf)).form_list) != ((List__O__Form__C____type__type ) 0)) == ((Bool__type ) 0)))
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
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x08067cc8 *_sharp_pair_447;
({_sharp_pair_447;
(_sharp_pair_447 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_447).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_442;
({_sharp_pair_442;
(_sharp_pair_442 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_442).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_442).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_441;
({_sharp_pair_441;
(_sharp_pair_441 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_441).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_441).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_441);
})
);
((List__O__Form__C____type__type ) _sharp_pair_442);
})
));
(((* _sharp_pair_447).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_446;
({_sharp_pair_446;
(_sharp_pair_446 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_446).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_445;
({_sharp_pair_445;
(_sharp_pair_445 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_445).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067cc8 *_sharp_pair_443;
({_sharp_pair_443;
(_sharp_pair_443 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_443).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_443).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_443);
})
));
(((* _sharp_pair_445).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_444;
({_sharp_pair_444;
(_sharp_pair_444 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_444).car) = (Int_Form)(0));
(((* _sharp_pair_444).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_444);
})
);
((List__O__Form__C____type__type ) _sharp_pair_445);
})
));
(((* _sharp_pair_446).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_446);
})
);
((List__O__Form__C____type__type ) _sharp_pair_447);
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
(cs_ = (head_set)(((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head), next_rules));
({
List__O__Form__C____type__type _sharp_iterator449;
(_sharp_iterator449 = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail));
({({_sharp__sharp_loop450_begin453:;
({
Form__type rule;
({if( (_sharp_iterator449 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop450_end451;});}})
;
(rule = ((* ((struct struct0x08067cc8 *) _sharp_iterator449)).car));
({
({(cs_ = (union_Character_Set_List)((head_set)(rule, next_rules), cs_));
((void) 0);});
})
;
_sharp__sharp_loop450_continue452:;
(_sharp_iterator449 = ((* ((struct struct0x08067cc8 *) _sharp_iterator449)).cdr));
})
;
({goto _sharp__sharp_loop450_begin453;});});
_sharp__sharp_loop450_end451:;});
})
;
(cs_list = cs_);
((void) 0);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "*")))?
(({
List__O__Character_Set__C____type__type cs_;
({(cs_ = (union_Character_Set_List)((head_set)(((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head), ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail)), (head_set)(((* ((struct struct0x0805f070 *) next_rules)).head), ((* ((struct struct0x0805f070 *) next_rules)).tail))));
(cs_list = cs_);
((void) 0);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "+")))?
(({
({(cs_list = (head_set)(((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head), ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail)));
((void) 0);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "{}")))?
(({
({(((next_rules == ((List__O__Form__C____type__type ) 0)))?
(({
({(cs_list = ((List__O__Character_Set__C____type__type ) 0));
((void) 0);});
})
):
(({
({(cs_list = (head_set)(((* ((struct struct0x0805f070 *) next_rules)).head), ((* ((struct struct0x0805f070 *) next_rules)).tail)));
((void) 0);});
})
));
((void) 0);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( ".")))?
(({
Symbol__type save_grammar_name;
Symbol__type rule_name;
({(save_grammar_name = grammar_name);
(grammar_name = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head)))).value));
(rule_name = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail))).head)))).value));
({if( ((((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))) != ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) 0)) == ((Bool__type ) 0)))
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
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x08067cc8 *_sharp_pair_462;
({_sharp_pair_462;
(_sharp_pair_462 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_462).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_455;
({_sharp_pair_455;
(_sharp_pair_455 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_455).car) = (Id_Form)(intern( "head_set_hash")));
(((* _sharp_pair_455).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_454;
({_sharp_pair_454;
(_sharp_pair_454 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_454).car) = (Id_Form)(intern( "grammar_name")));
(((* _sharp_pair_454).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_454);
})
);
((List__O__Form__C____type__type ) _sharp_pair_455);
})
));
(((* _sharp_pair_462).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_461;
({_sharp_pair_461;
(_sharp_pair_461 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_461).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_460;
({_sharp_pair_460;
(_sharp_pair_460 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_460).car) = (Compound_Form)(intern( "Hash"), ({
struct struct0x08067cc8 *_sharp_pair_458;
({_sharp_pair_458;
(_sharp_pair_458 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_458).car) = (Id_Form)(intern( "Symbol")));
(((* _sharp_pair_458).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_457;
({_sharp_pair_457;
(_sharp_pair_457 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_457).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067cc8 *_sharp_pair_456;
({_sharp_pair_456;
(_sharp_pair_456 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_456).car) = (Id_Form)(intern( "Character_Set")));
(((* _sharp_pair_456).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_456);
})
));
(((* _sharp_pair_457).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_457);
})
);
((List__O__Form__C____type__type ) _sharp_pair_458);
})
));
(((* _sharp_pair_460).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_459;
({_sharp_pair_459;
(_sharp_pair_459 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_459).car) = (Int_Form)(0));
(((* _sharp_pair_459).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_459);
})
);
((List__O__Form__C____type__type ) _sharp_pair_460);
})
));
(((* _sharp_pair_461).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_461);
})
);
((List__O__Form__C____type__type ) _sharp_pair_462);
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
(cs_list = ((List__O__Character_Set__C____type__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash)))))));
({if( (cs_list == ((List__O__Character_Set__C____type__type ) 0)))
{
({
Form__type named_rule;
({((List__O__Character_Set__C____type__type ) (puthash)(((void *) rule_name), ((void *) ((List__O__Character_Set__C____type__type ) (- (int) 1))), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
(named_rule = ((Form__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash)))))));
({if( (named_rule == ((Form__type ) 0)))
{
({
({({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_7));
(print_String)(((String__type) &__string_8));
(print_Symbol)(rule_name);
(print_String)(((String__type) &__string_9));
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
(cs_list = (head_set)(named_rule, ((List__O__Form__C____type__type ) 0)));
({if( (cs_list == ((List__O__Character_Set__C____type__type ) (- (int) 1))))
{
({
({({(print_String)(((String__type) &__string_10));
(print_Symbol)(rule_name);
(print_String)(((String__type) &__string_11));
(maybe_flush)();});
(exit)(3);
((void) 0);});
})
;}})
;
((List__O__Character_Set__C____type__type ) (puthash)(((void *) rule_name), ((void *) cs_list), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
((void) 0);});
})
;}})
;
(grammar_name = save_grammar_name);
((void) 0);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "@")))?
(({
Form__type grammar_form;
Symbol__type form_head;
Form__type form;
({(form = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head));
({if( ((is_compound_form)(form) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_12));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08067cc8 *_sharp_pair_463;
({_sharp_pair_463;
(_sharp_pair_463 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_463).car) = (Id_Form)(intern( "form")));
(((* _sharp_pair_463).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_463);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_13));
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
(form_head = ((* ((struct struct0x0805eec0 *) ((Compound_Form__type ) form))).head));
(grammar_form = (call_grammar_macro)(form_head, form));
(cs_list = (head_set)(grammar_form, next_rules));
((void) 0);});
})
):
(({
({({(print_String)(((String__type) &__string_14));
(print_Symbol)(((* ((struct struct0x0805eec0 *) cf)).head));
(print_String)(((String__type) &__string_15));
(maybe_flush)();});
(print_form)(parse_form);
(exit)(3);
((void) 0);});
})
))))))))))))))))))));});
})
):
((((is_id_form)(parse_form))?
(({
Symbol__type rule_name;
({(rule_name = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) parse_form))).value));
(((rule_name == intern( "_")))?
(({
({({if( (next_rules == ((List__O__Form__C____type__type ) 0)))
{
({
({({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_16));
(print_String)(((String__type) &__string_17));
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
(cs_list = (head_set)(((* ((struct struct0x0805f070 *) next_rules)).head), ((* ((struct struct0x0805f070 *) next_rules)).tail)));
((void) 0);});
})
):
(({
({({if( ((((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))) != ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_18));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x08067cc8 *_sharp_pair_472;
({_sharp_pair_472;
(_sharp_pair_472 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_472).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_465;
({_sharp_pair_465;
(_sharp_pair_465 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_465).car) = (Id_Form)(intern( "head_set_hash")));
(((* _sharp_pair_465).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_464;
({_sharp_pair_464;
(_sharp_pair_464 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_464).car) = (Id_Form)(intern( "grammar_name")));
(((* _sharp_pair_464).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_464);
})
);
((List__O__Form__C____type__type ) _sharp_pair_465);
})
));
(((* _sharp_pair_472).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_471;
({_sharp_pair_471;
(_sharp_pair_471 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_471).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_470;
({_sharp_pair_470;
(_sharp_pair_470 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_470).car) = (Compound_Form)(intern( "Hash"), ({
struct struct0x08067cc8 *_sharp_pair_468;
({_sharp_pair_468;
(_sharp_pair_468 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_468).car) = (Id_Form)(intern( "Symbol")));
(((* _sharp_pair_468).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_467;
({_sharp_pair_467;
(_sharp_pair_467 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_467).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067cc8 *_sharp_pair_466;
({_sharp_pair_466;
(_sharp_pair_466 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_466).car) = (Id_Form)(intern( "Character_Set")));
(((* _sharp_pair_466).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_466);
})
));
(((* _sharp_pair_467).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_467);
})
);
((List__O__Form__C____type__type ) _sharp_pair_468);
})
));
(((* _sharp_pair_470).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_469;
({_sharp_pair_469;
(_sharp_pair_469 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_469).car) = (Int_Form)(0));
(((* _sharp_pair_469).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_469);
})
);
((List__O__Form__C____type__type ) _sharp_pair_470);
})
));
(((* _sharp_pair_471).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_471);
})
);
((List__O__Form__C____type__type ) _sharp_pair_472);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_19));
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
(cs_list = ((List__O__Character_Set__C____type__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash)))))));
({if( (cs_list == ((List__O__Character_Set__C____type__type ) 0)))
{
({
Form__type named_rule;
({((List__O__Character_Set__C____type__type ) (puthash)(((void *) rule_name), ((void *) ((List__O__Character_Set__C____type__type ) (- (int) 1))), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
(named_rule = ((Form__type ) (gethash)(((void *) rule_name), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash)))))));
({if( (named_rule == ((Form__type ) 0)))
{
({
({({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_20));
(print_String)(((String__type) &__string_21));
(print_Symbol)(rule_name);
(print_String)(((String__type) &__string_22));
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
(cs_list = (head_set)(named_rule, ((List__O__Form__C____type__type ) 0)));
({if( (cs_list == ((List__O__Character_Set__C____type__type ) (- (int) 1))))
{
({
({({(print_String)(((String__type) &__string_23));
(print_Symbol)(rule_name);
(print_String)(((String__type) &__string_24));
(maybe_flush)();});
(exit)(3);
((void) 0);});
})
;}})
;
((List__O__Character_Set__C____type__type ) (puthash)(((void *) rule_name), ((void *) cs_list), ((Hash_Table__type ) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) head_set_hash))))));
((void) 0);});
})
;}})
;
((void) 0);});
})
));});
})
):
((((is_string_form)(parse_form))?
(({
struct struct0x08580ad8 *_sharp_pointer_alloc473;
Int__type head;
({(head = (string_element)(((* ((struct struct0x0805baf8 *) ((String_Form__type ) parse_form))).value), 0));
(cs_list = ({
struct struct0x085ac238 *_sharp_pair_475;
({_sharp_pair_475;
(_sharp_pair_475 = ((struct struct0x085ac238 *) (alloc_cons_cell)()));});
(((* _sharp_pair_475).car) = ((Character_Set__type ) ({
struct struct0x08582e60 *_sharp_pair_474;
({_sharp_pair_474;
(_sharp_pair_474 = ((struct struct0x08582e60 *) (alloc_cons_cell)()));});
(((* _sharp_pair_474).car) = ((Character_Range__type ) ({_sharp_pointer_alloc473;
(_sharp_pointer_alloc473 = ((struct struct0x08580ad8 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc473) = ((struct struct0x08580ad8 ){head, head}));
((struct struct0x08580ad8 *) _sharp_pointer_alloc473);})));
(((* _sharp_pair_474).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_474);
})
));
(((* _sharp_pair_475).cdr) = ((List__O__Character_Set__C____type__type ) 0));
((List__O__Character_Set__C____type__type ) _sharp_pair_475);
})
);
((void) 0);
((void) 0);});
})
):
((((is_symbol_form)(parse_form))?
(({
void **_sharp_make_list_ptr477;
List__O__Int__C____type__type l;
({(l = (string_to_int_list)((get_symbol_name)(((* ((struct struct0x0805dc08 *) ((Symbol_Form__type ) parse_form))).value))));
(cs_list = ({
List__O__Character_Set__C____type__type _sharp_make_list476;
({_sharp_make_list476;
_sharp_make_list_ptr477;
(_sharp_make_list_ptr477 = ((void *) (&_sharp_make_list476)));
({
List__O__Int__C____type__type _sharp_iterator479;
(_sharp_iterator479 = l);
({({_sharp__sharp_loop480_begin485:;
({
Int__type head;
({if( (_sharp_iterator479 == ((List__O__Int__C____type__type ) 0)))
{
({goto _sharp__sharp_loop480_end481;});}})
;
(head = ((* ((struct struct0x08638d50 *) _sharp_iterator479)).car));
({
struct struct0x08580ad8 *_sharp_pointer_alloc482;
({({((* _sharp_make_list_ptr477) = (alloc_cons_cell)());
(((* (* ((struct struct0x08591358 **) _sharp_make_list_ptr477))).car) = ((void *) ((Character_Set__type ) ({
struct struct0x08582e60 *_sharp_pair_483;
({_sharp_pair_483;
(_sharp_pair_483 = ((struct struct0x08582e60 *) (alloc_cons_cell)()));});
(((* _sharp_pair_483).car) = ((Character_Range__type ) ({_sharp_pointer_alloc482;
(_sharp_pointer_alloc482 = ((struct struct0x08580ad8 *) (GC_alloc)(8)));
((* _sharp_pointer_alloc482) = ((struct struct0x08580ad8 ){head, head}));
((struct struct0x08580ad8 *) _sharp_pointer_alloc482);})));
(((* _sharp_pair_483).cdr) = ((List__O__Character_Range__C____type__type ) 0));
((List__O__Character_Range__C____type__type ) _sharp_pair_483);
})
)));
(_sharp_make_list_ptr477 = (&((* (* ((struct struct0x08591358 **) _sharp_make_list_ptr477))).cdr)));
((void) 0);});
((void) 0);});
})
;
_sharp__sharp_loop480_continue484:;
(_sharp_iterator479 = ((* ((struct struct0x08638d50 *) _sharp_iterator479)).cdr));
})
;
({goto _sharp__sharp_loop480_begin485;});});
_sharp__sharp_loop480_end481:;});
})
;
((* _sharp_make_list_ptr477) = ((void *) 0));
_sharp_make_list476;});
})
);
((void) 0);});
})
):
(({
({({(print_String)(((String__type) &__string_25));
(maybe_flush)();});
(print_form)(parse_form);
(exit)(3);
((void) 0);});
})
))))))));
cs_list;});
})
;}

Form__type  head_set_function(Form__type  parse_form)
{
return ({
Form__type cop_form;
Form__type ret_form;
({(ret_form = ((Form__type ) 0));
(cop_form = parse_form);
({({_sharp__sharp_loop486_begin488:;
({
({({if( ((((is_compound_form)(cop_form))&&((((* ((struct struct0x0805eec0 *) ((Compound_Form__type ) cop_form))).head) == intern( " ")))) == ((Bool__type ) 0)))
{
({goto _sharp__sharp_loop486_end487;});}})
;
(cop_form = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) ((Compound_Form__type ) cop_form))).form_list))).head));
((void) 0);});
})
;
({goto _sharp__sharp_loop486_begin488;});});
_sharp__sharp_loop486_end487:;});
({if( (is_compound_form)(cop_form))
{
({
Compound_Form__type cf;
({(cf = ((Compound_Form__type ) cop_form));
({if( (((* ((struct struct0x0805eec0 *) cf)).head) == intern( "&")))
{
({
({({if( ((((is_compound_form)(((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head)))&&((((* ((struct struct0x0805eec0 *) ((Compound_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head)))).head) == intern( "{}")))) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_26));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "@and"), ({
struct struct0x08067cc8 *_sharp_pair_505;
({_sharp_pair_505;
(_sharp_pair_505 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_505).car) = (Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08067cc8 *_sharp_pair_493;
({_sharp_pair_493;
(_sharp_pair_493 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_493).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_492;
({_sharp_pair_492;
(_sharp_pair_492 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_492).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_490;
({_sharp_pair_490;
(_sharp_pair_490 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_490).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_490).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_489;
({_sharp_pair_489;
(_sharp_pair_489 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_489).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_489).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_489);
})
);
((List__O__Form__C____type__type ) _sharp_pair_490);
})
));
(((* _sharp_pair_492).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_491;
({_sharp_pair_491;
(_sharp_pair_491 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_491).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_491).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_491);
})
);
((List__O__Form__C____type__type ) _sharp_pair_492);
})
));
(((* _sharp_pair_493).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_493);
})
));
(((* _sharp_pair_505).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_504;
({_sharp_pair_504;
(_sharp_pair_504 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_504).car) = (Compound_Form)(intern( "=="), ({
struct struct0x08067cc8 *_sharp_pair_503;
({_sharp_pair_503;
(_sharp_pair_503 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_503).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_501;
({_sharp_pair_501;
(_sharp_pair_501 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_501).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_499;
({_sharp_pair_499;
(_sharp_pair_499 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_499).car) = (Id_Form)(intern( "Compound_Form")));
(((* _sharp_pair_499).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_498;
({_sharp_pair_498;
(_sharp_pair_498 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_498).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_497;
({_sharp_pair_497;
(_sharp_pair_497 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_497).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_495;
({_sharp_pair_495;
(_sharp_pair_495 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_495).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_495).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_494;
({_sharp_pair_494;
(_sharp_pair_494 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_494).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_494).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_494);
})
);
((List__O__Form__C____type__type ) _sharp_pair_495);
})
));
(((* _sharp_pair_497).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_496;
({_sharp_pair_496;
(_sharp_pair_496 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_496).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_496).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_496);
})
);
((List__O__Form__C____type__type ) _sharp_pair_497);
})
));
(((* _sharp_pair_498).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_498);
})
);
((List__O__Form__C____type__type ) _sharp_pair_499);
})
));
(((* _sharp_pair_501).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_500;
({_sharp_pair_500;
(_sharp_pair_500 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_500).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_500).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_500);
})
);
((List__O__Form__C____type__type ) _sharp_pair_501);
})
));
(((* _sharp_pair_503).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_502;
({_sharp_pair_502;
(_sharp_pair_502 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_502).car) = (Symbol_Form)(intern( "{}")));
(((* _sharp_pair_502).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_502);
})
);
((List__O__Form__C____type__type ) _sharp_pair_503);
})
));
(((* _sharp_pair_504).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_504);
})
);
((List__O__Form__C____type__type ) _sharp_pair_505);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_27));
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
(ret_form = (grammar_expander_rec)(((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head), ((List__O__Form__C____type__type ) 0)));
((void) 0);});
})
;}})
;
((void) 0);});
})
;}})
;
({if( (ret_form == ((Form__type ) 0)))
{
({
List__O__Character_Set__C____type__type ret_set;
({(ret_set = (head_set)(parse_form, ((List__O__Form__C____type__type ) 0)));
(ret_form = (is_in_Character_Set_condition)(ret_set));
((void) 0);});
})
;}})
;
ret_form;});
})
;}

Form__type  grammar_expander_rec(Form__type  parse_form, List__O__Form__C____type__type  next_rules)
{
return ({
(((is_compound_form)(parse_form))?
(({
Compound_Form__type cf;
({(cf = ((Compound_Form__type ) parse_form));
(((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "[]")))||((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "[^]")))))?
(({
(Compound_Form)(intern( "read_char"), ((List__O__Form__C____type__type ) 0));
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( ":")))?
(({
Expanded_Form__type exp_right_form;
Form__type subrule;
Form__type left_form;
Symbol__type id;
Id_Form__type id_form;
Form__type right_form;
({(id_form = ((Id_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head)));
(id = ((* ((struct struct0x0805dc08 *) id_form)).value));
(left_form = ((Form__type ) id_form));
(subrule = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail))).head));
(right_form = (grammar_expander_rec)(subrule, next_rules));
({if( (((((is_compound_form)(subrule))&&((((* ((struct struct0x0805eec0 *) ((Compound_Form__type ) subrule))).head) == intern( "*")))))||((((* ((struct struct0x0805eec0 *) ((Compound_Form__type ) subrule))).head) == intern( "+")))))
{
({
({(right_form = (Compound_Form)(intern( "make_list"), ({
struct struct0x08067cc8 *_sharp_pair_506;
({_sharp_pair_506;
(_sharp_pair_506 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_506).car) = right_form);
(((* _sharp_pair_506).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_506);
})
));
((void) 0);});
})
;}})
;
(exp_right_form = (expand)(right_form));
({if( (((Type__type ) (gethash)(((void *) id), ((Hash_Table__type ) id_used))) == ((Type__type ) 0)))
{
({
({((Type__type ) (puthash)(((void *) id), ((void *) ((Type__type ) 1)), ((Hash_Table__type ) id_used)));
(expand)((Compound_Form)(intern( "let"), ({
struct struct0x08067cc8 *_sharp_pair_508;
({_sharp_pair_508;
(_sharp_pair_508 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_508).car) = ((Form__type ) id_form));
(((* _sharp_pair_508).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_507;
({_sharp_pair_507;
(_sharp_pair_507 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_507).car) = (((struct struct0x08066790 ) ((* ((struct struct0x08066990 *) ((Real_Type__type ) ((* ((struct struct0x0805f878 *) exp_right_form)).type)))).common_)).type_form));
(((* _sharp_pair_507).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_507);
})
);
((List__O__Form__C____type__type ) _sharp_pair_508);
})
));
((void) 0);});
})
;}})
;
(Compound_Form)(intern( "="), ({
struct struct0x08067cc8 *_sharp_pair_510;
({_sharp_pair_510;
(_sharp_pair_510 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_510).car) = left_form);
(((* _sharp_pair_510).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_509;
({_sharp_pair_509;
(_sharp_pair_509 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_509).car) = ((Form__type ) exp_right_form));
(((* _sharp_pair_509).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_509);
})
);
((List__O__Form__C____type__type ) _sharp_pair_510);
})
);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "{}")))?
(({
(Compound_Form)(intern( "seq"), ((* ((struct struct0x0805eec0 *) cf)).form_list));
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( " ")))?
(({
void **_sharp_make_list_ptr512;
List__O__Form__C____type__type fl;
({(fl = ({
List__O__Form__C____type__type _sharp_make_list511;
({_sharp_make_list511;
_sharp_make_list_ptr512;
(_sharp_make_list_ptr512 = ((void *) (&_sharp_make_list511)));
({
List__O__Form__C____type__type grammar_rule_it;
({(grammar_rule_it = ((* ((struct struct0x0805eec0 *) cf)).form_list));
({({_sharp__sharp_loop513_begin515:;
({
({({if( ((grammar_rule_it != ((List__O__Form__C____type__type ) 0)) == ((Bool__type ) 0)))
{
({goto _sharp__sharp_loop513_end514;});}})
;
({
List__O__Form__C____type__type grammar_tail;
Form__type grammar_rule;
({(grammar_rule = ((* ((struct struct0x0805f070 *) grammar_rule_it)).head));
(grammar_tail = ((* ((struct struct0x0805f070 *) grammar_rule_it)).tail));
({((* _sharp_make_list_ptr512) = (alloc_cons_cell)());
(((* (* ((struct struct0x08591358 **) _sharp_make_list_ptr512))).car) = ((void *) (grammar_expander_rec)(grammar_rule, grammar_tail)));
(_sharp_make_list_ptr512 = (&((* (* ((struct struct0x08591358 **) _sharp_make_list_ptr512))).cdr)));
((void) 0);});
(grammar_rule_it = grammar_tail);
((void) 0);});
})
;
((void) 0);});
})
;
({goto _sharp__sharp_loop513_begin515;});});
_sharp__sharp_loop513_end514:;});});
})
;
((* _sharp_make_list_ptr512) = ((void *) 0));
_sharp_make_list511;});
})
);
(Compound_Form)(intern( "seq"), fl);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "|")))?
(({
((((Bool__type ) 1))?
(({
Form__type cond_form;
Form__type maybe_rule;
({({if( ((((((((* ((struct struct0x0805eec0 *) cf)).form_list) != ((List__O__Form__C____type__type ) 0)))&&((((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail) != ((List__O__Form__C____type__type ) 0)))))&&((((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail))).tail) == ((List__O__Form__C____type__type ) 0)))) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_28));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "@and"), ({
struct struct0x08067cc8 *_sharp_pair_546;
({_sharp_pair_546;
(_sharp_pair_546 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_546).car) = (Compound_Form)(intern( "@and"), ({
struct struct0x08067cc8 *_sharp_pair_533;
({_sharp_pair_533;
(_sharp_pair_533 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_533).car) = (Compound_Form)(intern( "!="), ({
struct struct0x08067cc8 *_sharp_pair_522;
({_sharp_pair_522;
(_sharp_pair_522 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_522).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_517;
({_sharp_pair_517;
(_sharp_pair_517 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_517).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_517).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_516;
({_sharp_pair_516;
(_sharp_pair_516 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_516).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_516).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_516);
})
);
((List__O__Form__C____type__type ) _sharp_pair_517);
})
));
(((* _sharp_pair_522).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_521;
({_sharp_pair_521;
(_sharp_pair_521 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_521).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_520;
({_sharp_pair_520;
(_sharp_pair_520 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_520).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067cc8 *_sharp_pair_518;
({_sharp_pair_518;
(_sharp_pair_518 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_518).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_518).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_518);
})
));
(((* _sharp_pair_520).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_519;
({_sharp_pair_519;
(_sharp_pair_519 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_519).car) = (Int_Form)(0));
(((* _sharp_pair_519).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_519);
})
);
((List__O__Form__C____type__type ) _sharp_pair_520);
})
));
(((* _sharp_pair_521).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_521);
})
);
((List__O__Form__C____type__type ) _sharp_pair_522);
})
));
(((* _sharp_pair_533).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_532;
({_sharp_pair_532;
(_sharp_pair_532 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_532).car) = (Compound_Form)(intern( "!="), ({
struct struct0x08067cc8 *_sharp_pair_531;
({_sharp_pair_531;
(_sharp_pair_531 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_531).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_526;
({_sharp_pair_526;
(_sharp_pair_526 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_526).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_524;
({_sharp_pair_524;
(_sharp_pair_524 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_524).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_524).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_523;
({_sharp_pair_523;
(_sharp_pair_523 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_523).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_523).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_523);
})
);
((List__O__Form__C____type__type ) _sharp_pair_524);
})
));
(((* _sharp_pair_526).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_525;
({_sharp_pair_525;
(_sharp_pair_525 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_525).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_525).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_525);
})
);
((List__O__Form__C____type__type ) _sharp_pair_526);
})
));
(((* _sharp_pair_531).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_530;
({_sharp_pair_530;
(_sharp_pair_530 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_530).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_529;
({_sharp_pair_529;
(_sharp_pair_529 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_529).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067cc8 *_sharp_pair_527;
({_sharp_pair_527;
(_sharp_pair_527 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_527).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_527).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_527);
})
));
(((* _sharp_pair_529).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_528;
({_sharp_pair_528;
(_sharp_pair_528 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_528).car) = (Int_Form)(0));
(((* _sharp_pair_528).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_528);
})
);
((List__O__Form__C____type__type ) _sharp_pair_529);
})
));
(((* _sharp_pair_530).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_530);
})
);
((List__O__Form__C____type__type ) _sharp_pair_531);
})
));
(((* _sharp_pair_532).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_532);
})
);
((List__O__Form__C____type__type ) _sharp_pair_533);
})
));
(((* _sharp_pair_546).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_545;
({_sharp_pair_545;
(_sharp_pair_545 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_545).car) = (Compound_Form)(intern( "=="), ({
struct struct0x08067cc8 *_sharp_pair_544;
({_sharp_pair_544;
(_sharp_pair_544 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_544).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_539;
({_sharp_pair_539;
(_sharp_pair_539 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_539).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_537;
({_sharp_pair_537;
(_sharp_pair_537 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_537).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_535;
({_sharp_pair_535;
(_sharp_pair_535 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_535).car) = (Id_Form)(intern( "cf")));
(((* _sharp_pair_535).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_534;
({_sharp_pair_534;
(_sharp_pair_534 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_534).car) = (Symbol_Form)(intern( "form_list")));
(((* _sharp_pair_534).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_534);
})
);
((List__O__Form__C____type__type ) _sharp_pair_535);
})
));
(((* _sharp_pair_537).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_536;
({_sharp_pair_536;
(_sharp_pair_536 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_536).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_536).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_536);
})
);
((List__O__Form__C____type__type ) _sharp_pair_537);
})
));
(((* _sharp_pair_539).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_538;
({_sharp_pair_538;
(_sharp_pair_538 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_538).car) = (Symbol_Form)(intern( "tail")));
(((* _sharp_pair_538).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_538);
})
);
((List__O__Form__C____type__type ) _sharp_pair_539);
})
));
(((* _sharp_pair_544).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_543;
({_sharp_pair_543;
(_sharp_pair_543 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_543).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_542;
({_sharp_pair_542;
(_sharp_pair_542 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_542).car) = (Compound_Form)(intern( "List"), ({
struct struct0x08067cc8 *_sharp_pair_540;
({_sharp_pair_540;
(_sharp_pair_540 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_540).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_540).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_540);
})
));
(((* _sharp_pair_542).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_541;
({_sharp_pair_541;
(_sharp_pair_541 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_541).car) = (Int_Form)(0));
(((* _sharp_pair_541).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_541);
})
);
((List__O__Form__C____type__type ) _sharp_pair_542);
})
));
(((* _sharp_pair_543).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_543);
})
);
((List__O__Form__C____type__type ) _sharp_pair_544);
})
));
(((* _sharp_pair_545).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_545);
})
);
((List__O__Form__C____type__type ) _sharp_pair_546);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_29));
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
(maybe_rule = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head));
(cond_form = (head_set_function)(maybe_rule));
(Compound_Form)(intern( "@block"), ({
struct struct0x08067cc8 *_sharp_pair_550;
({_sharp_pair_550;
(_sharp_pair_550 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_550).car) = (Compound_Form)(intern( "if"), ({
struct struct0x08067cc8 *_sharp_pair_549;
({_sharp_pair_549;
(_sharp_pair_549 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_549).car) = cond_form);
(((* _sharp_pair_549).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_548;
({_sharp_pair_548;
(_sharp_pair_548 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_548).car) = (grammar_expander_rec)(maybe_rule, next_rules));
(((* _sharp_pair_548).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_547;
({_sharp_pair_547;
(_sharp_pair_547 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_547).car) = (grammar_expander_rec)(((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail))).head), next_rules));
(((* _sharp_pair_547).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_547);
})
);
((List__O__Form__C____type__type ) _sharp_pair_548);
})
);
((List__O__Form__C____type__type ) _sharp_pair_549);
})
));
(((* _sharp_pair_550).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_550);
})
);});
})
):
(({
Int__type number_rule_empty;
Form__type else_form;
Form__type *orig_else_form_ptr;
Form__type peeked_char_form;
Form__type ret_form;
Symbol__type peeked_char;
List__O__Form__C____type__type form_list;
({(peeked_char = (gensym)(((String__type) &__string_30)));
(peeked_char_form = (Id_Form)(peeked_char));
(orig_else_form_ptr = ((Form__type *) 0));
(else_form = (Compound_Form)(intern( "parse_error"), ((List__O__Form__C____type__type ) 0)));
(number_rule_empty = 0);
(form_list = ((* ((struct struct0x0805eec0 *) cf)).form_list));
({
List__O__Form__C____type__type _sharp_iterator552;
(_sharp_iterator552 = form_list);
({({_sharp__sharp_loop553_begin564:;
({
Form__type grammar_rule;
({if( (_sharp_iterator552 == ((List__O__Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop553_end554;});}})
;
(grammar_rule = ((* ((struct struct0x08067cc8 *) _sharp_iterator552)).car));
({
List__O__Character_Set__C____type__type char_set;
({(char_set = (head_set)(grammar_rule, ((List__O__Form__C____type__type ) 0)));
(((char_set == ((List__O__Character_Set__C____type__type ) 0)))?
(({
({(number_rule_empty = ((int) number_rule_empty + (int) 1));
({if( ((int) number_rule_empty > (int) 1))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_31));
(print_String)(((String__type) &__string_32));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;}})
;
({if( ((orig_else_form_ptr != ((Form__type *) 0)) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_33));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "!="), ({
struct struct0x08067cc8 *_sharp_pair_559;
({_sharp_pair_559;
(_sharp_pair_559 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_559).car) = (Id_Form)(intern( "orig_else_form_ptr")));
(((* _sharp_pair_559).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_558;
({_sharp_pair_558;
(_sharp_pair_558 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_558).car) = (Compound_Form)(intern( "cast"), ({
struct struct0x08067cc8 *_sharp_pair_557;
({_sharp_pair_557;
(_sharp_pair_557 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_557).car) = (Compound_Form)(intern( "*"), ({
struct struct0x08067cc8 *_sharp_pair_555;
({_sharp_pair_555;
(_sharp_pair_555 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_555).car) = (Id_Form)(intern( "Form")));
(((* _sharp_pair_555).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_555);
})
));
(((* _sharp_pair_557).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_556;
({_sharp_pair_556;
(_sharp_pair_556 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_556).car) = (Int_Form)(0));
(((* _sharp_pair_556).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_556);
})
);
((List__O__Form__C____type__type ) _sharp_pair_557);
})
));
(((* _sharp_pair_558).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_558);
})
);
((List__O__Form__C____type__type ) _sharp_pair_559);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_34));
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
((* orig_else_form_ptr) = (grammar_expander_rec)(grammar_rule, ((List__O__Form__C____type__type ) 0)));
((void) 0);});
})
):
(({
({(else_form = (Compound_Form)(intern( "if"), ({
struct struct0x08067cc8 *_sharp_pair_562;
({_sharp_pair_562;
(_sharp_pair_562 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_562).car) = (is_in_Character_Set_condition)(char_set));
(((* _sharp_pair_562).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_561;
({_sharp_pair_561;
(_sharp_pair_561 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_561).car) = (grammar_expander_rec)(grammar_rule, next_rules));
(((* _sharp_pair_561).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_560;
({_sharp_pair_560;
(_sharp_pair_560 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_560).car) = else_form);
(((* _sharp_pair_560).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_560);
})
);
((List__O__Form__C____type__type ) _sharp_pair_561);
})
);
((List__O__Form__C____type__type ) _sharp_pair_562);
})
));
({if( (orig_else_form_ptr == ((Form__type *) 0)))
{
({
Compound_Form__type cfe;
({(cfe = ((Compound_Form__type ) else_form));
(orig_else_form_ptr = (&((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cfe)).form_list))).tail))).tail))).head)));
((void) 0);});
})
;}})
;
((void) 0);});
})
));
((void) 0);});
})
;
_sharp__sharp_loop553_continue563:;
(_sharp_iterator552 = ((* ((struct struct0x08067cc8 *) _sharp_iterator552)).cdr));
})
;
({goto _sharp__sharp_loop553_begin564;});});
_sharp__sharp_loop553_end554:;});
})
;
(ret_form = (Compound_Form)(intern( "block"), ({
struct struct0x08067cc8 *_sharp_pair_569;
({_sharp_pair_569;
(_sharp_pair_569 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_569).car) = (Compound_Form)(intern( "="), ({
struct struct0x08067cc8 *_sharp_pair_567;
({_sharp_pair_567;
(_sharp_pair_567 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_567).car) = (Compound_Form)(intern( "let"), ({
struct struct0x08067cc8 *_sharp_pair_565;
({_sharp_pair_565;
(_sharp_pair_565 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_565).car) = peeked_char_form);
(((* _sharp_pair_565).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_565);
})
));
(((* _sharp_pair_567).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_566;
({_sharp_pair_566;
(_sharp_pair_566 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_566).car) = (Compound_Form)(intern( "peek_char"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_566).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_566);
})
);
((List__O__Form__C____type__type ) _sharp_pair_567);
})
));
(((* _sharp_pair_569).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_568;
({_sharp_pair_568;
(_sharp_pair_568 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_568).car) = else_form);
(((* _sharp_pair_568).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_568);
})
);
((List__O__Form__C____type__type ) _sharp_pair_569);
})
));
ret_form;});
})
));
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "*")))?
(({
Form__type repeated_rule;
Form__type peeked_char_form;
Form__type cond_form;
Symbol__type peeked_char;
({(repeated_rule = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head));
(cond_form = (head_set_function)(repeated_rule));
(peeked_char = (gensym)(((String__type) &__string_35)));
(peeked_char_form = (Id_Form)(peeked_char));
(Compound_Form)(intern( "loop"), ({
struct struct0x08067cc8 *_sharp_pair_577;
({_sharp_pair_577;
(_sharp_pair_577 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_577).car) = (Compound_Form)(intern( "@block"), ({
struct struct0x08067cc8 *_sharp_pair_576;
({_sharp_pair_576;
(_sharp_pair_576 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_576).car) = (Compound_Form)(intern( "@seq"), ({
struct struct0x08067cc8 *_sharp_pair_575;
({_sharp_pair_575;
(_sharp_pair_575 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_575).car) = (Compound_Form)(intern( "if"), ({
struct struct0x08067cc8 *_sharp_pair_572;
({_sharp_pair_572;
(_sharp_pair_572 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_572).car) = (Compound_Form)(intern( "not"), ({
struct struct0x08067cc8 *_sharp_pair_570;
({_sharp_pair_570;
(_sharp_pair_570 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_570).car) = cond_form);
(((* _sharp_pair_570).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_570);
})
));
(((* _sharp_pair_572).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_571;
({_sharp_pair_571;
(_sharp_pair_571 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_571).car) = (Compound_Form)(intern( "break"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_571).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_571);
})
);
((List__O__Form__C____type__type ) _sharp_pair_572);
})
));
(((* _sharp_pair_575).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_574;
({_sharp_pair_574;
(_sharp_pair_574 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_574).car) = (grammar_expander_rec)(repeated_rule, next_rules));
(((* _sharp_pair_574).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_573;
({_sharp_pair_573;
(_sharp_pair_573 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_573).car) = (Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_573).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_573);
})
);
((List__O__Form__C____type__type ) _sharp_pair_574);
})
);
((List__O__Form__C____type__type ) _sharp_pair_575);
})
));
(((* _sharp_pair_576).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_576);
})
));
(((* _sharp_pair_577).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_577);
})
);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "+")))?
(({
Form__type repeated_rule;
Form__type cond_form;
({(repeated_rule = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head));
(cond_form = (head_set_function)(repeated_rule));
(Compound_Form)(intern( "loop"), ({
struct struct0x08067cc8 *_sharp_pair_585;
({_sharp_pair_585;
(_sharp_pair_585 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_585).car) = (Compound_Form)(intern( "@block"), ({
struct struct0x08067cc8 *_sharp_pair_584;
({_sharp_pair_584;
(_sharp_pair_584 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_584).car) = (Compound_Form)(intern( "@seq"), ({
struct struct0x08067cc8 *_sharp_pair_583;
({_sharp_pair_583;
(_sharp_pair_583 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_583).car) = (grammar_expander_rec)(repeated_rule, next_rules));
(((* _sharp_pair_583).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_582;
({_sharp_pair_582;
(_sharp_pair_582 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_582).car) = (Compound_Form)(intern( "if"), ({
struct struct0x08067cc8 *_sharp_pair_580;
({_sharp_pair_580;
(_sharp_pair_580 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_580).car) = (Compound_Form)(intern( "not"), ({
struct struct0x08067cc8 *_sharp_pair_578;
({_sharp_pair_578;
(_sharp_pair_578 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_578).car) = cond_form);
(((* _sharp_pair_578).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_578);
})
));
(((* _sharp_pair_580).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_579;
({_sharp_pair_579;
(_sharp_pair_579 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_579).car) = (Compound_Form)(intern( "break"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_579).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_579);
})
);
((List__O__Form__C____type__type ) _sharp_pair_580);
})
));
(((* _sharp_pair_582).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_581;
({_sharp_pair_581;
(_sharp_pair_581 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_581).car) = (Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_581).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_581);
})
);
((List__O__Form__C____type__type ) _sharp_pair_582);
})
);
((List__O__Form__C____type__type ) _sharp_pair_583);
})
));
(((* _sharp_pair_584).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_584);
})
));
(((* _sharp_pair_585).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_585);
})
);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "?")))?
(({
Form__type cond_form;
Form__type maybe_rule;
({(maybe_rule = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head));
(cond_form = (head_set_function)(maybe_rule));
(Compound_Form)(intern( "@block"), ({
struct struct0x08067cc8 *_sharp_pair_590;
({_sharp_pair_590;
(_sharp_pair_590 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_590).car) = (Compound_Form)(intern( "@seq"), ({
struct struct0x08067cc8 *_sharp_pair_589;
({_sharp_pair_589;
(_sharp_pair_589 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_589).car) = (Compound_Form)(intern( "if"), ({
struct struct0x08067cc8 *_sharp_pair_587;
({_sharp_pair_587;
(_sharp_pair_587 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_587).car) = cond_form);
(((* _sharp_pair_587).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_586;
({_sharp_pair_586;
(_sharp_pair_586 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_586).car) = (grammar_expander_rec)(maybe_rule, next_rules));
(((* _sharp_pair_586).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_586);
})
);
((List__O__Form__C____type__type ) _sharp_pair_587);
})
));
(((* _sharp_pair_589).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_588;
({_sharp_pair_588;
(_sharp_pair_588 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_588).car) = (Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0)));
(((* _sharp_pair_588).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_588);
})
);
((List__O__Form__C____type__type ) _sharp_pair_589);
})
));
(((* _sharp_pair_590).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_590);
})
);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( ".")))?
(({
Symbol__type gram_name;
Symbol__type rule_name;
({(gram_name = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head)))).value));
(rule_name = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).tail))).head)))).value));
(Compound_Form)(intern( "funcall"), ({
struct struct0x08067cc8 *_sharp_pair_591;
({_sharp_pair_591;
(_sharp_pair_591 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_591).car) = (Id_Form)((intern_string)((function_name_from_grammar_and_rule)(gram_name, rule_name))));
(((* _sharp_pair_591).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_591);
})
);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "@")))?
(({
Form__type grammar_form;
Symbol__type form_head;
Form__type form;
({(form = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf)).form_list))).head));
({if( ((is_compound_form)(form) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_36));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08067cc8 *_sharp_pair_592;
({_sharp_pair_592;
(_sharp_pair_592 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_592).car) = (Id_Form)(intern( "form")));
(((* _sharp_pair_592).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_592);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_37));
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
(form_head = ((* ((struct struct0x0805eec0 *) ((Compound_Form__type ) form))).head));
(grammar_form = (call_grammar_macro)(form_head, form));
(grammar_expander_rec)(grammar_form, next_rules);});
})
):
((((((* ((struct struct0x0805eec0 *) cf)).head) == intern( "&")))?
(({
(Compound_Form)(intern( "tuple"), ((List__O__Form__C____type__type ) 0));
})
):
(({
({(print_form)(((Form__type ) cf));
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_38));
(print_String)(((String__type) &__string_39));
(print_Symbol)(((* ((struct struct0x0805eec0 *) cf)).head));
(print_String)(((String__type) &__string_40));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;
(Id_Form)(intern( "imp"));});
})
))))))))))))))))))))));});
})
):
((((is_id_form)(parse_form))?
(({
Symbol_Form__type id_form;
({(id_form = ((Symbol_Form__type ) parse_form));
(((((* ((struct struct0x0805dc08 *) id_form)).value) == intern( "_")))?
(({
(Compound_Form)(intern( "funcall"), ({
struct struct0x08067cc8 *_sharp_pair_593;
({_sharp_pair_593;
(_sharp_pair_593 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_593).car) = (Id_Form)(intern( "get_point_pos")));
(((* _sharp_pair_593).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_593);
})
);
})
):
((Compound_Form)(intern( "funcall"), ({
struct struct0x08067cc8 *_sharp_pair_594;
({_sharp_pair_594;
(_sharp_pair_594 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_594).car) = (Id_Form)((intern_string)((function_name_from_grammar_and_rule)(grammar_name, ((* ((struct struct0x0805dc08 *) id_form)).value)))));
(((* _sharp_pair_594).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_594);
})
)));});
})
):
((((is_string_form)(parse_form))?
(({
void **_sharp_make_list_ptr596;
List__O__Int__C____type__type cl;
List__O__Form__C____type__type form_list;
({(cl = (string_to_int_list)(((* ((struct struct0x0805baf8 *) ((String_Form__type ) parse_form))).value)));
(form_list = ({
List__O__Form__C____type__type _sharp_make_list595;
({_sharp_make_list595;
_sharp_make_list_ptr596;
(_sharp_make_list_ptr596 = ((void *) (&_sharp_make_list595)));
({
List__O__Int__C____type__type _sharp_iterator598;
(_sharp_iterator598 = cl);
({({_sharp__sharp_loop599_begin602:;
({
Int__type Int;
({if( (_sharp_iterator598 == ((List__O__Int__C____type__type ) 0)))
{
({goto _sharp__sharp_loop599_end600;});}})
;
(Int = ((* ((struct struct0x08638d50 *) _sharp_iterator598)).car));
({
({((* _sharp_make_list_ptr596) = (alloc_cons_cell)());
(((* (* ((struct struct0x08591358 **) _sharp_make_list_ptr596))).car) = ((void *) (Compound_Form)(intern( "read_char"), ((List__O__Form__C____type__type ) 0))));
(_sharp_make_list_ptr596 = (&((* (* ((struct struct0x08591358 **) _sharp_make_list_ptr596))).cdr)));
((void) 0);});
})
;
_sharp__sharp_loop599_continue601:;
(_sharp_iterator598 = ((* ((struct struct0x08638d50 *) _sharp_iterator598)).cdr));
})
;
({goto _sharp__sharp_loop599_begin602;});});
_sharp__sharp_loop599_end600:;});
})
;
((* _sharp_make_list_ptr596) = ((void *) 0));
_sharp_make_list595;});
})
);
(Compound_Form)(intern( "seq"), form_list);});
})
):
((((is_symbol_form)(parse_form))?
(({
Symbol__type symbol;
({(symbol = ((* ((struct struct0x0805dc08 *) ((Symbol_Form__type ) parse_form))).value));
(Compound_Form)(intern( "parse_symbol"), ({
struct struct0x08067cc8 *_sharp_pair_603;
({_sharp_pair_603;
(_sharp_pair_603 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_603).car) = (String_Form)((get_symbol_name)(symbol)));
(((* _sharp_pair_603).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_603);
})
);});
})
):
(({
({({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_41));
(print_String)(((String__type) &__string_42));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;
(print_form)(parse_form);
(Id_Form)(intern( "imp2"));});
})
))))))));
})
;}

List__O__Form__C____type__type  expand_grammar_list(List__O__Compound_Form__C____type__type  grammar_list)
{
return ({
void **_sharp_make_list_ptr625;
List__O__Form__C____type__type form_list;
({(rules_hash = ((Hash__O__Symbol__c__Hash__O__Symbol__c__Form__C____C____type__type ) (make_hash_table)()));
(head_set_hash = ((Hash__O__Symbol__c__Hash__O__Symbol__c__List__O__Character_Set__C____C____C____type__type ) (make_hash_table)()));
({
List__O__Compound_Form__C____type__type _sharp_iterator613;
(_sharp_iterator613 = grammar_list);
({({_sharp__sharp_loop614_begin623:;
({
Compound_Form__type grammar;
({if( (_sharp_iterator613 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop614_end615;});}})
;
(grammar = ((* ((struct struct0x0829e8e0 *) _sharp_iterator613)).car));
({
List__O__Compound_Form__C____type__type rule_list;
({(grammar_name = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) grammar)).form_list))).tail))).head)))).value));
((Hash__O__Symbol__c__Form__C____type__type ) (puthash)(((void *) grammar_name), ((void *) ((Hash__O__Symbol__c__Form__C____type__type ) (make_hash_table)())), ((Hash_Table__type ) rules_hash)));
((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (puthash)(((void *) grammar_name), ((void *) ((Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type ) (make_hash_table)())), ((Hash_Table__type ) head_set_hash)));
(rule_list = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) grammar)).form_list))).tail))).tail)));
({
List__O__Compound_Form__C____type__type _sharp_iterator617;
(_sharp_iterator617 = rule_list);
({({_sharp__sharp_loop618_begin621:;
({
Compound_Form__type rule;
({if( (_sharp_iterator617 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop618_end619;});}})
;
(rule = ((* ((struct struct0x0829e8e0 *) _sharp_iterator617)).car));
({
Symbol__type rule_name;
Form__type form;
({(rule_name = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) rule)).form_list))).head)))).value));
(form = ((Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) rule)).form_list))).tail))).tail))).tail))).head)));
((Form__type ) (puthash)(((void *) rule_name), ((void *) form), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash))))));
(pre_define_function)((intern_string)((function_name_from_grammar_and_rule)(grammar_name, rule_name)), ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) rule)).form_list))).tail))).head));
((void) 0);});
})
;
_sharp__sharp_loop618_continue620:;
(_sharp_iterator617 = ((* ((struct struct0x0829e8e0 *) _sharp_iterator617)).cdr));
})
;
({goto _sharp__sharp_loop618_begin621;});});
_sharp__sharp_loop618_end619:;});
})
;
((void) 0);});
})
;
_sharp__sharp_loop614_continue622:;
(_sharp_iterator613 = ((* ((struct struct0x0829e8e0 *) _sharp_iterator613)).cdr));
})
;
({goto _sharp__sharp_loop614_begin623;});});
_sharp__sharp_loop614_end615:;});
})
;
(form_list = ({
List__O__Form__C____type__type _sharp_make_list624;
({_sharp_make_list624;
_sharp_make_list_ptr625;
(_sharp_make_list_ptr625 = ((void *) (&_sharp_make_list624)));
({
List__O__Compound_Form__C____type__type _sharp_iterator627;
(_sharp_iterator627 = grammar_list);
({({_sharp__sharp_loop628_begin641:;
({
Compound_Form__type grammar;
({if( (_sharp_iterator627 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop628_end629;});}})
;
(grammar = ((* ((struct struct0x0829e8e0 *) _sharp_iterator627)).car));
({
List__O__Compound_Form__C____type__type rule_list;
({(grammar_name = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) grammar)).form_list))).tail))).head)))).value));
(rule_list = ((List__O__Compound_Form__C____type__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) grammar)).form_list))).tail))).tail)));
({
List__O__Compound_Form__C____type__type _sharp_iterator631;
(_sharp_iterator631 = rule_list);
({({_sharp__sharp_loop632_begin639:;
({
Compound_Form__type rule;
({if( (_sharp_iterator631 == ((List__O__Compound_Form__C____type__type ) 0)))
{
({goto _sharp__sharp_loop632_end633;});}})
;
(rule = ((* ((struct struct0x0829e8e0 *) _sharp_iterator631)).car));
({
Form__type function_form;
Expanded_Form__type exp_function_body;
Form__type function_body;
Compound_Form__type params;
Symbol__type function_name;
Symbol__type rule_name;
Form__type form;
Form__type return_type_form;
Expanded_Form__type lambda_form;
({(rule_name = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) rule)).form_list))).head)))).value));
(function_name = (intern_string)((function_name_from_grammar_and_rule)(grammar_name, rule_name)));
(return_type_form = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) rule)).form_list))).tail))).head));
(params = ((Compound_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) rule)).form_list))).tail))).tail))).head)));
(form = ((Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) rule)).form_list))).tail))).tail))).tail))).head)));
(id_used = ((Hash__O__Symbol__c__Type__C____type__type ) (make_hash_table)()));
(declare_function_begin)(params, return_type_form);
(declare_block_begin)();
(function_body = (grammar_expander_rec)(form, ((List__O__Form__C____type__type ) 0)));
(exp_function_body = (declare_block_end)(({
struct struct0x08067cc8 *_sharp_pair_634;
({_sharp_pair_634;
(_sharp_pair_634 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_634).car) = function_body);
(((* _sharp_pair_634).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_634);
})
));
(lambda_form = (declare_function_end)(exp_function_body));
(function_form = (Compound_Form)(intern( "define"), ({
struct struct0x08067cc8 *_sharp_pair_637;
({_sharp_pair_637;
(_sharp_pair_637 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_637).car) = (Id_Form)(intern( "function")));
(((* _sharp_pair_637).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_636;
({_sharp_pair_636;
(_sharp_pair_636 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_636).car) = (Id_Form)(function_name));
(((* _sharp_pair_636).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_635;
({_sharp_pair_635;
(_sharp_pair_635 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_635).car) = ((* ((struct struct0x0805f878 *) lambda_form)).return_form));
(((* _sharp_pair_635).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_635);
})
);
((List__O__Form__C____type__type ) _sharp_pair_636);
})
);
((List__O__Form__C____type__type ) _sharp_pair_637);
})
));
({((* _sharp_make_list_ptr625) = (alloc_cons_cell)());
(((* (* ((struct struct0x08591358 **) _sharp_make_list_ptr625))).car) = ((void *) function_form));
(_sharp_make_list_ptr625 = (&((* (* ((struct struct0x08591358 **) _sharp_make_list_ptr625))).cdr)));
((void) 0);});
((void) 0);});
})
;
_sharp__sharp_loop632_continue638:;
(_sharp_iterator631 = ((* ((struct struct0x0829e8e0 *) _sharp_iterator631)).cdr));
})
;
({goto _sharp__sharp_loop632_begin639;});});
_sharp__sharp_loop632_end633:;});
})
;
((void) 0);});
})
;
_sharp__sharp_loop628_continue640:;
(_sharp_iterator627 = ((* ((struct struct0x0829e8e0 *) _sharp_iterator627)).cdr));
})
;
({goto _sharp__sharp_loop628_begin641;});});
_sharp__sharp_loop628_end629:;});
})
;
((* _sharp_make_list_ptr625) = ((void *) 0));
_sharp_make_list624;});
})
);
form_list;});
})
;}

void  test(void)
{
return ({
({((void) 0);
((void) 0);});
})
;}

Form__type  get_parse_function_sharp__sharp_expander_function(Compound_Form__type  form)
{
return ({
Symbol__type rule;
Form__type grammar_id_form;
Compound_Form__type cf2;
Form__type form2;
Form__type rule_id_form;
Symbol__type grammar;
({(form2 = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) form)).form_list))).head));
({if( ((is_compound_form)(form2) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_43));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_compound_form"), ({
struct struct0x08067cc8 *_sharp_pair_604;
({_sharp_pair_604;
(_sharp_pair_604 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_604).car) = (Id_Form)(intern( "form2")));
(((* _sharp_pair_604).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_604);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_44));
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
(cf2 = ((Compound_Form__type ) form2));
(print_form)(form2);
({if( ((((* ((struct struct0x0805eec0 *) cf2)).head) == intern( "[]")) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_45));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "=="), ({
struct struct0x08067cc8 *_sharp_pair_608;
({_sharp_pair_608;
(_sharp_pair_608 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_608).car) = (Compound_Form)(intern( "[]"), ({
struct struct0x08067cc8 *_sharp_pair_606;
({_sharp_pair_606;
(_sharp_pair_606 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_606).car) = (Id_Form)(intern( "cf2")));
(((* _sharp_pair_606).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_605;
({_sharp_pair_605;
(_sharp_pair_605 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_605).car) = (Symbol_Form)(intern( "head")));
(((* _sharp_pair_605).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_605);
})
);
((List__O__Form__C____type__type ) _sharp_pair_606);
})
));
(((* _sharp_pair_608).cdr) = ({
struct struct0x08067cc8 *_sharp_pair_607;
({_sharp_pair_607;
(_sharp_pair_607 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_607).car) = (Symbol_Form)(intern( "[]")));
(((* _sharp_pair_607).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_607);
})
);
((List__O__Form__C____type__type ) _sharp_pair_608);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_46));
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
(grammar_id_form = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf2)).form_list))).head));
(rule_id_form = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) cf2)).form_list))).tail))).head));
({if( ((is_id_form)(grammar_id_form) == ((Bool__type ) 0)))
{
({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_47));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(print_form)((Compound_Form)(intern( "is_id_form"), ({
struct struct0x08067cc8 *_sharp_pair_609;
({_sharp_pair_609;
(_sharp_pair_609 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_609).car) = (Id_Form)(intern( "grammar_id_form")));
(((* _sharp_pair_609).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_609);
})
));
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_48));
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
(grammar = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) grammar_id_form))).value));
(rule = ((* ((struct struct0x0805dc08 *) ((Id_Form__type ) rule_id_form))).value));
(Id_Form)((intern_string)((function_name_from_grammar_and_rule)(grammar, rule)));});
})
;}

Form__type  parse_sharp__sharp_expander_function(Compound_Form__type  form)
{
return ({
(Compound_Form)(intern( "funcall"), ({
struct struct0x08067cc8 *_sharp_pair_611;
({_sharp_pair_611;
(_sharp_pair_611 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_611).car) = (Compound_Form)(intern( "get_parse_function"), ({
struct struct0x08067cc8 *_sharp_pair_610;
({_sharp_pair_610;
(_sharp_pair_610 = ((struct struct0x08067cc8 *) (alloc_cons_cell)()));});
(((* _sharp_pair_610).car) = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) form)).form_list))).head));
(((* _sharp_pair_610).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_610);
})
));
(((* _sharp_pair_611).cdr) = ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) form)).form_list))).tail));
((List__O__Form__C____type__type ) _sharp_pair_611);
})
);
})
;}

Form__type  grammar_expander_sharp__sharp_expander_function(Compound_Form__type  form_)
{
return ({
Symbol__type rule;
Form__type form;
({(id_used = ((Hash__O__Symbol__c__Type__C____type__type ) (make_hash_table)()));
(rule = ((* ((struct struct0x0805dc08 *) ((Symbol_Form__type ) ((* ((struct struct0x0805f070 *) ((* ((struct struct0x0805eec0 *) form_)).form_list))).head)))).value));
({if( (((Form__type ) (gethash)(((void *) rule), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash)))))) == ((Form__type ) 0)))
{
({
({({(print_String)(((String__type) &__string_49));
(print_Symbol)(rule);
(maybe_flush)();});
(exit)(3);
((void) 0);});
})
;}})
;
(grammar_name = intern( "parse_grammar"));
(form = (grammar_expander_rec)(((Form__type ) (gethash)(((void *) rule), ((Hash_Table__type ) ((Hash__O__Symbol__c__Form__C____type__type ) (gethash)(((void *) grammar_name), ((Hash_Table__type ) rules_hash)))))), ((List__O__Form__C____type__type ) 0)));
form;});
})
;}

void init_grammar_expander(void){
define_expander( intern( "get_parse_function"), get_parse_function_sharp__sharp_expander_function);
define_expander( intern( "parse"), parse_sharp__sharp_expander_function);
define_expander( intern( "grammar_expander"), grammar_expander_sharp__sharp_expander_function);
}

void main() { init(); int (*test_ptr)( void); test_ptr = test; printf( "TEST result: %d", test_ptr());flush();}
