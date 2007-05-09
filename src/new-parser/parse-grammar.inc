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
typedef struct struct0x0805d7a0 *Form__type;
typedef void *Output_Descriptor__type;
struct struct0x0805d7a0 {
Int__type form_type_;
};
typedef struct struct0x0805e120 *Int_Form__type;
struct struct0x0805e120 {
Int__type form_type_;
Int__type value;
};
typedef struct struct0x0805f098 *List__O__Form__C____type__type;
struct struct0x0805eea0 {
Int__type form_type_;
Symbol__type head;
Int__type garbage_;
List__O__Form__C____type__type form_list;
};
struct struct0x0805f098 {
Form__type head;
List__O__Form__C____type__type tail;
};
struct struct0x08065f90 {
Form__type car;
List__O__Form__C____type__type cdr;
};
typedef struct struct0x08513380 *Character_Range__type;
struct struct0x08513380 {
Int__type min;
Int__type max;
};
typedef struct struct0x08513710 *List__O__Character_Range__C____type__type;
struct struct0x08513710 {
Character_Range__type head;
List__O__Character_Range__C____type__type tail;
};
typedef List__O__Character_Range__C____type__type Character_Set__type;
typedef struct struct0x085139f0 *Exit__type;
struct struct0x085139f0 {
Int__type dummy;
};
struct struct0x08515dc8 {
Character_Range__type car;
List__O__Character_Range__C____type__type cdr;
};
struct struct0x08524078 {
void *car;
void *cdr;
};
Bool__type (is_compound_form)(Form__type );
Form__type (String_Form)(String__type );
void (exit)(Int__type );
void *(GC_alloc)(Int__type );
void (print_Int_Dec)(Int__type );
void *(alloc_cons_cell)(void);
void (print_String)(String__type );
void (flush)(void);
void (maybe_flush)(void);
Form__type (Int_Form)(Int__type );
Form__type (Id_Form)(Symbol__type );
Form__type (Compound_Form)(Symbol__type , List__O__Form__C____type__type );
Int__type (print_form)(Form__type );
Bool__type (is_int_form)(Form__type );
Symbol__type (intern_string)(String__type );
Int__type (character_from_symbol)(Symbol__type );
void (set_parser_support_to)(String__type );
Int__type (peek_char)(void);
Int__type (read_char)(void);
Int__type (get_point_pos)(void);
String__type (substring)(Int__type , Int__type );
Form__type (parse_Expression)(void);
Form__type (parse_Type)(void);
String__type (get_test_string)(void);
Character_Set__type (sort_Character_Set)(List__O__Character_Range__C____type__type );
Character_Set__type (make_Character_Set)(Form__type );
Character_Set__type (get_inverse_Character_Set)(Character_Set__type );
Exit__type (parse_error)(void);
Form__type (parse_Grammar_Rule)(void);
Form__type (parse_Grammar)(void);
Int__type (parse_Comment)(void);
void (parse_Spacing)(void);
Form__type (parse_String)(void);
Form__type (parse_Character_Range)(void);
Int__type (parse_Alpha_Num)(void);
Int__type (parse_Alpha)(void);
Symbol__type (parse_Identifier)(void);
Int__type (parse_Escaped_Character)(void);
Int__type (parse_Maybe_Escaped_Character)(void);
Form__type (parse_Callable_Rule)(void);
Int__type (parse_Maybe_Escaped_Character_Character_Range)(void);
Form__type (parse_Primary)(void);
Form__type (parse_Character_Set)(void);
Form__type (parse_Sequence)(void);
Form__type (parse_Postfix)(void);
Form__type (parse_Semantic_Action)(void);
Form__type (parse_Grouping)(void);
Form__type (parse_Alternative)(void);
Form__type (parse_Rule)(void);
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
static struct { unsigned int length; char *content; } __string_11 = { 33, "rule Spacing:Character = [ \n	]* ;"};
