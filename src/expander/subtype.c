/* Automatically generated : do not edit!*/
#include "subtype.inc"
Hash__O__Type__c__Hash__O__Type__c__Bool__C____C____type__type subtype_hash;

Hash__O__Type__c__Hash__O__Type__c__Bool__C____C____type__type direct_subtype_hash;

Hash__O__Type__c__Hash__O__Type__c__Bool__C____C____type__type supertype_hash;

Hash__O__Type__c__Hash__O__Type__c__Bool__C____C____type__type direct_supertype_hash;

void  init__subtype(void)
{
return ({
({(direct_supertype_hash = ((Hash__O__Type__c__Hash__O__Type__c__Bool__C____C____type__type ) (make_hash_table)()));
(supertype_hash = ((Hash__O__Type__c__Hash__O__Type__c__Bool__C____C____type__type ) (make_hash_table)()));
(direct_subtype_hash = ((Hash__O__Type__c__Hash__O__Type__c__Bool__C____C____type__type ) (make_hash_table)()));
(subtype_hash = ((Hash__O__Type__c__Hash__O__Type__c__Bool__C____C____type__type ) (make_hash_table)()));
((void) 0);});
})
;}

void  define_subtype_relationship(Type__type  sub, Type__type  super)
{
return ({
Hash__O__Type__c__Bool__C____type__type hashsup;
Hash__O__Type__c__Bool__C____type__type hashsub;
({hashsub;
hashsup;
({if( ((hashsub = ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) sub), ((Hash_Table__type ) direct_supertype_hash)))) == ((Hash__O__Type__c__Bool__C____type__type ) 0)))
{
({
({(hashsub = ((Hash__O__Type__c__Bool__C____type__type ) (puthash)(((void *) sub), ((void *) ((Hash__O__Type__c__Bool__C____type__type ) (make_hash_table)())), ((Hash_Table__type ) direct_supertype_hash))));
((void) 0);});
})
;}})
;
((Bool__type ) (puthash)(((void *) super), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) hashsub)));
({if( ((hashsup = ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) super), ((Hash_Table__type ) direct_supertype_hash)))) == ((Hash__O__Type__c__Bool__C____type__type ) 0)))
{
({
({(hashsup = ((Hash__O__Type__c__Bool__C____type__type ) (puthash)(((void *) super), ((void *) ((Hash__O__Type__c__Bool__C____type__type ) (make_hash_table)())), ((Hash_Table__type ) direct_supertype_hash))));
((void) 0);});
})
;}})
;
((Bool__type ) (puthash)(((void *) sub), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) hashsup)));
({if( ((hashsup = ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) super), ((Hash_Table__type ) supertype_hash)))) == ((Hash__O__Type__c__Bool__C____type__type ) 0)))
{
({
({((Hash__O__Type__c__Bool__C____type__type ) (puthash)(((void *) super), ((void *) ((Hash__O__Type__c__Bool__C____type__type ) (make_hash_table)())), ((Hash_Table__type ) subtype_hash)));
(hashsup = ((Hash__O__Type__c__Bool__C____type__type ) (puthash)(((void *) super), ((void *) ((Hash__O__Type__c__Bool__C____type__type ) (make_hash_table)())), ((Hash_Table__type ) supertype_hash))));
((Bool__type ) (puthash)(((void *) super), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) super), ((Hash_Table__type ) supertype_hash))))));
((Bool__type ) (puthash)(((void *) super), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) super), ((Hash_Table__type ) subtype_hash))))));
((void) 0);});
})
;}})
;
({if( ((hashsub = ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) sub), ((Hash_Table__type ) subtype_hash)))) == ((Hash__O__Type__c__Bool__C____type__type ) 0)))
{
({
({((Hash__O__Type__c__Bool__C____type__type ) (puthash)(((void *) sub), ((void *) ((Hash__O__Type__c__Bool__C____type__type ) (make_hash_table)())), ((Hash_Table__type ) supertype_hash)));
(hashsub = ((Hash__O__Type__c__Bool__C____type__type ) (puthash)(((void *) sub), ((void *) ((Hash__O__Type__c__Bool__C____type__type ) (make_hash_table)())), ((Hash_Table__type ) subtype_hash))));
((Bool__type ) (puthash)(((void *) sub), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) sub), ((Hash_Table__type ) supertype_hash))))));
((Bool__type ) (puthash)(((void *) sub), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) sub), ((Hash_Table__type ) subtype_hash))))));
((void) 0);});
})
;}})
;
({
void **PValue_;
Hash__O__Type__c__Bool__C____type__type hash_;
Int__type Index_;
(Index_ = 0);
(hash_ = hashsub);
PValue_;
(PValue_ = (JudyLFirst)((* ((void **) hash_)), ((void *) (&Index_)), 0));
({({_sharp__sharp_loop379_begin389:;
({
Bool__type _sharp_tuple382;
Type__type _sharp_tuple381;
Bool__type useless_bool1;
Type__type subtype;
({if( (PValue_ == ((void **) 0)))
{
({goto _sharp__sharp_loop379_end380;});}})
;
({({(_sharp_tuple381 = ((Type__type ) Index_));
(_sharp_tuple382 = ((Bool__type ) (* PValue_)));});
({(subtype = _sharp_tuple381);
(useless_bool1 = _sharp_tuple382);});});
({
({({
void **PValue__sharp_u_sharp_0;
Hash__O__Type__c__Bool__C____type__type hash__sharp_u_sharp_0;
Int__type Index__sharp_u_sharp_0;
(Index__sharp_u_sharp_0 = 0);
(hash__sharp_u_sharp_0 = hashsup);
PValue_;
(PValue__sharp_u_sharp_0 = (JudyLFirst)((* ((void **) hash__sharp_u_sharp_0)), ((void *) (&Index__sharp_u_sharp_0)), 0));
({({_sharp__sharp_loop384_begin388:;
({
Bool__type _sharp_tuple387;
Type__type _sharp_tuple386;
Bool__type useless_bool2;
Type__type supertype;
({if( (PValue__sharp_u_sharp_0 == ((void **) 0)))
{
({goto _sharp__sharp_loop384_end385;});}})
;
({({(_sharp_tuple386 = ((Type__type ) Index__sharp_u_sharp_0));
(_sharp_tuple387 = ((Bool__type ) (* PValue__sharp_u_sharp_0)));});
({(supertype = _sharp_tuple386);
(useless_bool2 = _sharp_tuple387);});});
({
({((Bool__type ) (puthash)(((void *) supertype), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) subtype), ((Hash_Table__type ) supertype_hash))))));
((Bool__type ) (puthash)(((void *) subtype), ((void *) ((Bool__type ) 1)), ((Hash_Table__type ) ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) supertype), ((Hash_Table__type ) subtype_hash))))));
((void) 0);});
})
;
(PValue__sharp_u_sharp_0 = (JudyLNext)((* ((void **) hash__sharp_u_sharp_0)), ((void *) (&Index__sharp_u_sharp_0)), 0));
})
;
({goto _sharp__sharp_loop384_begin388;});});
_sharp__sharp_loop384_end385:;});
})
;
((void) 0);});
})
;
(PValue_ = (JudyLNext)((* ((void **) hash_)), ((void *) (&Index_)), 0));
})
;
({goto _sharp__sharp_loop379_begin389;});});
_sharp__sharp_loop379_end380:;});
})
;
((void) 0);});
})
;}

Bool__type  is_direct_subtype(Type__type  sub, Type__type  super)
{
return ({
Hash__O__Type__c__Bool__C____type__type hashsub;
({hashsub;
((((hashsub = ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) sub), ((Hash_Table__type ) direct_supertype_hash)))) == ((Hash__O__Type__c__Bool__C____type__type ) 0)))?
(({
((Bool__type ) 0);
})
):
(((Bool__type ) (gethash)(((void *) super), ((Hash_Table__type ) hashsub)))));});
})
;}

Bool__type  is_subtype(Type__type  sub, Type__type  super)
{
return ({
Hash__O__Type__c__Bool__C____type__type hashsub;
({hashsub;
((((hashsub = ((Hash__O__Type__c__Bool__C____type__type ) (gethash)(((void *) sub), ((Hash_Table__type ) supertype_hash)))) == ((Hash__O__Type__c__Bool__C____type__type ) 0)))?
(({
((Bool__type ) 0);
})
):
(((Bool__type ) (gethash)(((void *) super), ((Hash_Table__type ) hashsub)))));});
})
;}

Expanded_Form__type  coerced_form(Expanded_Form__type  form, Type__type  into)
{
return ({
Type__type sub;
({(sub = ((* ((struct struct0x080553a0 *) form)).type));
(((sub == into))?
(({
form;
})
):
((((is_subtype)(sub, into))?
(({
(expand)((Compound_Form)(intern( "cast"), ({
struct struct0x0805ec58 *_sharp_pair_391;
({_sharp_pair_391;
(_sharp_pair_391 = ((struct struct0x0805ec58 *) (alloc_cons_cell)()));});
(((* _sharp_pair_391).car) = (((struct struct0x0805d4a8 ) ((* ((struct struct0x0805d690 *) ((Real_Type__type ) into))).common_)).type_form));
(((* _sharp_pair_391).cdr) = ({
struct struct0x0805ec58 *_sharp_pair_390;
({_sharp_pair_390;
(_sharp_pair_390 = ((struct struct0x0805ec58 *) (alloc_cons_cell)()));});
(((* _sharp_pair_390).car) = ((Form__type ) form));
(((* _sharp_pair_390).cdr) = ((List__O__Form__C____type__type ) 0));
((List__O__Form__C____type__type ) _sharp_pair_390);
})
);
((List__O__Form__C____type__type ) _sharp_pair_391);
})
));
})
):
(((Exit__type ) ({({
({
Output_Descriptor__type save_od_;
(save_od_ = current_output_descriptor);
(current_output_descriptor = stderr_output_descriptor);
({(print_String)(((String__type) &__string_1));
(print_String)(((String__type) &__string_2));
(maybe_flush)();});
(flush)();
(current_output_descriptor = save_od_);
((void) 0);
})
;
(exit)(3);
})
;
0;}))))));});
})
;}

Type__type  Type(Int__type  i)
{
return ((Type__type ) i);}

Bool__type  test(void)
{
return ({
({(init__subtype)();
(define_subtype_relationship)((Type)(3), (Type)(4));
(define_subtype_relationship)((Type)(2), (Type)(3));
(is_subtype)((Type)(2), (Type)(4));});
})
;}
