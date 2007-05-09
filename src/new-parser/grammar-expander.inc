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

typedef struct struct0x0805eea0 *Compound_Form__type;
typedef struct struct0x08058a80 *List__O__Int__C____type__type;
struct struct0x08058a80 {
Int__type head;
List__O__Int__C____type__type tail;
};
typedef struct struct0x080590d8 *List__O__pointer__O__Void__C____C____type__type;
struct struct0x080590d8 {
void *head;
List__O__pointer__O__Void__C____C____type__type tail;
};
typedef struct struct0x0805d7a0 *Form__type;
struct struct0x08059b98 {
Int__type form_type_;
Symbol__type value;
};
typedef void *Hash_Table__type;
typedef struct struct0x08064af8 *Real_Type__type;
typedef void *Output_Descriptor__type;
struct struct0x0805bab0 {
Int__type form_type_;
String__type value;
};
struct struct0x0805d7a0 {
Int__type form_type_;
};
typedef struct struct0x0805e120 *Int_Form__type;
typedef struct struct0x08059b98 *Id_Form__type;
struct struct0x0805e120 {
Int__type form_type_;
Int__type value;
};
typedef struct struct0x08059b98 *Symbol_Form__type;
typedef struct struct0x0805bab0 *String_Form__type;
typedef struct struct0x0805f098 *List__O__Form__C____type__type;
struct struct0x0805eea0 {
Int__type form_type_;
Symbol__type head;
Int__type garbage_;
List__O__Form__C____type__type form_list;
};
typedef struct struct0x0805f910 *Expanded_Form__type;
struct struct0x0805f098 {
Form__type head;
List__O__Form__C____type__type tail;
};
struct struct0x0805f910 {
Int__type form_type_;
Form__type original_form;
Form__type return_form;
Type__type type;
};
typedef struct struct0x08061890 *List__O__Compound_Form__C____type__type;
struct struct0x08061890 {
Compound_Form__type head;
List__O__Compound_Form__C____type__type tail;
};
struct struct0x080648f8 {
Int__type type_type;
Form__type type_form;
Int__type size;
Int__type alignment;
};
typedef struct struct0x080648f8 Common_To_All_Type__type;
struct struct0x08064af8 {
Common_To_All_Type__type common_;
};
struct struct0x08065e18 {
Form__type car;
List__O__Form__C____type__type cdr;
};
typedef struct struct0x085136a8 *List__O__Character_Range__C____type__type;
typedef List__O__Character_Range__C____type__type Character_Set__type;
struct struct0x081fcf48 {
Compound_Form__type car;
List__O__Compound_Form__C____type__type cdr;
};
typedef struct struct0x08513318 *Character_Range__type;
struct struct0x08513318 {
Int__type min;
Int__type max;
};
struct struct0x085136a8 {
Character_Range__type head;
List__O__Character_Range__C____type__type tail;
};
typedef Hash_Table__type Hash__O__Symbol__c__Type__C____type__type;
typedef struct struct0x08513988 *Exit__type;
struct struct0x08513988 {
Int__type dummy;
};
typedef Hash_Table__type Hash__O__Symbol__c__Character_Set__C____type__type;
typedef Hash_Table__type Hash__O__Symbol__c__Form__C____type__type;
struct struct0x08515d60 {
Character_Range__type car;
List__O__Character_Range__C____type__type cdr;
};
struct struct0x08524010 {
void *car;
void *cdr;
};
struct struct0x0857b328 {
Int__type car;
List__O__Int__C____type__type cdr;
};
Bool__type (is_compound_form)(Form__type );
Form__type (Symbol_Form)(Symbol__type );
Form__type (String_Form)(String__type );
void (exit)(Int__type );
void *(GC_alloc)(Int__type );
void (print_Int_Dec)(Int__type );
void (print_Symbol)(Symbol__type );
void *(alloc_cons_cell)(void);
List__O__pointer__O__Void__C____C____type__type (append)(List__O__pointer__O__Void__C____C____type__type , List__O__pointer__O__Void__C____C____type__type );
List__O__Int__C____type__type (string_to_int_list)(String__type );
Hash_Table__type (make_hash_table)(void);
void (pre_define_function)(Symbol__type , Form__type );
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
Bool__type (is_int_form)(Form__type );
Bool__type (is_id_form)(Form__type );
Bool__type (is_string_form)(Form__type );
Expanded_Form__type (expand)(Form__type );
Symbol__type (gensym)(String__type );
Symbol__type (intern_string)(String__type );
Int__type (character_from_symbol)(Symbol__type );
String__type (concat)(String__type , String__type );
String__type (get_symbol_name)(Symbol__type );
Int__type (string_element)(String__type , Int__type );
Expanded_Form__type (declare_block_end)(List__O__Form__C____type__type );
Character_Set__type (sort_Character_Set)(List__O__Character_Range__C____type__type );
Character_Set__type (make_Character_Set)(Form__type );
Character_Set__type (get_inverse_Character_Set)(Character_Set__type );
Character_Set__type (make_inverse_Character_Set)(Form__type );
Form__type (is_in_Character_Set_condition)(Form__type , Character_Set__type );
Character_Set__type (head_set)(Form__type , List__O__Form__C____type__type );
Form__type (grammar_expander_rec)(Form__type , List__O__Form__C____type__type );
List__O__Form__C____type__type (grammar_produce_function_definitions)(Form__type );
Output_Descriptor__type current_output_descriptor;
Output_Descriptor__type stdout_output_descriptor;
Output_Descriptor__type stderr_output_descriptor;
static struct { unsigned int length; char *content; } __string_1 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_2 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_3 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_4 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_5 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_6 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_7 = { 4, "min:"};
static struct { unsigned int length; char *content; } __string_8 = { 6, ", max:"};
static struct { unsigned int length; char *content; } __string_9 = { 1, "\n"};
static struct { unsigned int length; char *content; } __string_10 = { 12, "Parse error\n"};
static struct { unsigned int length; char *content; } __string_11 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_12 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_13 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_14 = { 12, "Error in {}\n"};
static struct { unsigned int length; char *content; } __string_15 = { 16, "Unimplemented :|"};
static struct { unsigned int length; char *content; } __string_16 = { 2, "|\n"};
static struct { unsigned int length; char *content; } __string_17 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_18 = { 11, "Error in _\n"};
static struct { unsigned int length; char *content; } __string_19 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_20 = { 53, "Trying to calculate the head set of an unknown rule: "};
static struct { unsigned int length; char *content; } __string_21 = { 1, "\n"};
static struct { unsigned int length; char *content; } __string_22 = { 34, "Error: infinite recursion in rule "};
static struct { unsigned int length; char *content; } __string_23 = { 1, "\n"};
static struct { unsigned int length; char *content; } __string_24 = { 12, "Not handled\n"};
static struct { unsigned int length; char *content; } __string_25 = { 15, "peeked_char_alt"};
static struct { unsigned int length; char *content; } __string_26 = { 16, "peeked_char_star"};
static struct { unsigned int length; char *content; } __string_27 = { 17, "peeked_char_maybe"};
static struct { unsigned int length; char *content; } __string_28 = { 6, "parse_"};
static struct { unsigned int length; char *content; } __string_29 = { 13, "FORM PROBLEM\n"};
static struct { unsigned int length; char *content; } __string_30 = { 6, "parse_"};
static struct { unsigned int length; char *content; } __string_31 = { 2, "//"};
static struct { unsigned int length; char *content; } __string_32 = { 13, "Unknown rule\n"};
