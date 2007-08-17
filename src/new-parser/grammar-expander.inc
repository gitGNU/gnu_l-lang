typedef int Int__type;
typedef int Bool__type;
typedef void *Type__type;
typedef void* Label__type;
typedef void Void__type;
typedef struct {} * Symbol__type;

typedef struct {unsigned int len; char *content;} * String__type;

Symbol__type intern( const char * string);
Void__type print_Int_Dec( int i);
Void__type print_String( String__type s);
void maybe_flush( void);
String__type make_heap_string( char *s);

typedef struct struct0x08058c78 *List__O__Int__C____type__type;
typedef struct struct0x0805eec0 *Compound_Form__type;
struct struct0x08058c78 {
Int__type head;
List__O__Int__C____type__type tail;
};
typedef struct struct0x0805d798 *Form__type;
typedef void *Hash_Table__type;
typedef void *Output_Descriptor__type;
struct struct0x0805baf8 {
Int__type form_type_;
String__type value;
};
struct struct0x0805d798 {
Int__type form_type_;
};
typedef struct struct0x0805dc08 *Id_Form__type;
struct struct0x0805dc08 {
Int__type form_type_;
Symbol__type value;
};
typedef struct struct0x0805f878 *Expanded_Form__type;
typedef struct struct0x0805f070 *List__O__Form__C____type__type;
typedef struct struct0x0805dc08 *Symbol_Form__type;
typedef struct struct0x0805baf8 *String_Form__type;
struct struct0x0805eec0 {
Int__type form_type_;
Symbol__type head;
Int__type garbage_;
List__O__Form__C____type__type form_list;
};
struct struct0x0805f070 {
Form__type head;
List__O__Form__C____type__type tail;
};
struct struct0x0805f878 {
Int__type form_type_;
Form__type original_form;
Form__type return_form;
Type__type type;
};
typedef struct struct0x080619a8 *List__O__Compound_Form__C____type__type;
struct struct0x080619a8 {
Compound_Form__type head;
List__O__Compound_Form__C____type__type tail;
};
typedef struct struct0x08066990 *Real_Type__type;
struct struct0x08066790 {
Int__type type_type;
Form__type type_form;
Int__type size;
Int__type alignment;
};
typedef struct struct0x08066790 Common_To_All_Type__type;
struct struct0x08066990 {
Common_To_All_Type__type common_;
};
struct struct0x08067cc8 {
Form__type car;
List__O__Form__C____type__type cdr;
};
struct struct0x0829e8e0 {
Compound_Form__type car;
List__O__Compound_Form__C____type__type cdr;
};
typedef struct struct0x08580ad8 *Character_Range__type;
struct struct0x08580ad8 {
Int__type min;
Int__type max;
};
typedef struct struct0x08580e88 *List__O__Character_Range__C____type__type;
struct struct0x08580e88 {
Character_Range__type head;
List__O__Character_Range__C____type__type tail;
};
typedef List__O__Character_Range__C____type__type Character_Set__type;
typedef struct struct0x08581748 *List__O__Character_Set__C____type__type;
struct struct0x08581748 {
Character_Set__type head;
List__O__Character_Set__C____type__type tail;
};
struct struct0x08582e60 {
Character_Range__type car;
List__O__Character_Range__C____type__type cdr;
};
struct struct0x08591358 {
void *car;
void *cdr;
};
struct struct0x085ac238 {
Character_Set__type car;
List__O__Character_Set__C____type__type cdr;
};
struct struct0x085f6590 {
Form__type condition;
List__O__Form__C____type__type then;
};
typedef Hash_Table__type Hash__O__Symbol__c__Hash__O__Symbol__c__Form__C____C____type__type;
typedef Hash_Table__type Hash__O__Symbol__c__Form__C____type__type;
typedef Hash_Table__type Hash__O__Symbol__c__Hash__O__Symbol__c__List__O__Character_Set__C____C____C____type__type;
typedef Hash_Table__type Hash__O__Symbol__c__List__O__Character_Set__C____C____type__type;
typedef Hash_Table__type Hash__O__Symbol__c__Type__C____type__type;
struct struct0x08638d50 {
Int__type car;
List__O__Int__C____type__type cdr;
};
Bool__type (is_compound_form)(Form__type );
Form__type (Symbol_Form)(Symbol__type );
Form__type (String_Form)(String__type );
void (exit)(Int__type );
void *(GC_alloc)(Int__type );
void (print_Symbol)(Symbol__type );
void *(alloc_cons_cell)(void);
List__O__Int__C____type__type (string_to_int_list)(String__type );
Hash_Table__type (make_hash_table)(void);
void (print_String)(String__type );
void (flush)(void);
void (maybe_flush)(void);
Form__type (Int_Form)(Int__type );
void *(gethash)(void *, Hash_Table__type );
void *(puthash)(void *, void *, Hash_Table__type );
Form__type (Id_Form)(Symbol__type );
void (declare_block_begin)(void);
Form__type (Compound_Form)(Symbol__type , List__O__Form__C____type__type );
Int__type (print_form)(Form__type );
Bool__type (is_symbol_form)(Form__type );
Bool__type (is_id_form)(Form__type );
Bool__type (is_string_form)(Form__type );
Expanded_Form__type (expand)(Form__type );
Symbol__type (gensym)(String__type );
Symbol__type (convert_id)(Symbol__type );
Symbol__type (intern_string)(String__type );
Form__type (call_grammar_macro)(Symbol__type , Form__type );
String__type (concat)(String__type , String__type );
String__type (get_symbol_name)(Symbol__type );
Int__type (string_element)(String__type , Int__type );
void (pre_define_function)(Symbol__type , Form__type );
Form__type (grammar_expander_rec)(Form__type , List__O__Form__C____type__type );
void (declare_function_begin)(Compound_Form__type , Form__type );
Expanded_Form__type (declare_block_end)(List__O__Form__C____type__type );
Expanded_Form__type (declare_function_end)(Expanded_Form__type );
Character_Set__type (make_Character_Set)(Form__type );
Character_Set__type (make_inverse_Character_Set)(Form__type );
List__O__Character_Set__C____type__type (union_Character_Set_List)(List__O__Character_Set__C____type__type , List__O__Character_Set__C____type__type );
Form__type (is_in_Character_Set_condition)(List__O__Character_Set__C____type__type );
String__type (function_name_from_grammar_and_rule)(Symbol__type , Symbol__type );
List__O__Character_Set__C____type__type (head_set)(Form__type , List__O__Form__C____type__type );
Form__type (head_set_function)(Form__type );
Output_Descriptor__type current_output_descriptor;
Output_Descriptor__type stdout_output_descriptor;
Output_Descriptor__type stderr_output_descriptor;
static struct { unsigned int length; char *content; } __string_1 = { 11, "_l__parse__"};
static struct { unsigned int length; char *content; } __string_2 = { 2, "__"};
static struct { unsigned int length; char *content; } __string_3 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_4 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_5 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_6 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_7 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_8 = { 53, "Trying to calculate the head set of an unknown rule: "};
static struct { unsigned int length; char *content; } __string_9 = { 1, "\n"};
static struct { unsigned int length; char *content; } __string_10 = { 34, "Error: infinite recursion in rule "};
static struct { unsigned int length; char *content; } __string_11 = { 1, "\n"};
static struct { unsigned int length; char *content; } __string_12 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_13 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_14 = { 16, "Unimplemented :|"};
static struct { unsigned int length; char *content; } __string_15 = { 2, "|\n"};
static struct { unsigned int length; char *content; } __string_16 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_17 = { 11, "Error in _\n"};
static struct { unsigned int length; char *content; } __string_18 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_19 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_20 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_21 = { 53, "Trying to calculate the head set of an unknown rule: "};
static struct { unsigned int length; char *content; } __string_22 = { 1, "\n"};
static struct { unsigned int length; char *content; } __string_23 = { 34, "Error: infinite recursion in rule "};
static struct { unsigned int length; char *content; } __string_24 = { 1, "\n"};
static struct { unsigned int length; char *content; } __string_25 = { 12, "Not handled\n"};
static struct { unsigned int length; char *content; } __string_26 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_27 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_28 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_29 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_30 = { 15, "peeked_char_alt"};
static struct { unsigned int length; char *content; } __string_31 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_32 = { 47, "An alternative must have at most one empty rule"};
static struct { unsigned int length; char *content; } __string_33 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_34 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_35 = { 16, "peeked_char_star"};
static struct { unsigned int length; char *content; } __string_36 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_37 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_38 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_39 = { 13, "unknown head:"};
static struct { unsigned int length; char *content; } __string_40 = { 1, "\n"};
static struct { unsigned int length; char *content; } __string_41 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_42 = { 13, "FORM PROBLEM\n"};
static struct { unsigned int length; char *content; } __string_43 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_44 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_45 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_46 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_47 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_48 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_49 = { 13, "Unknown rule\n"};
