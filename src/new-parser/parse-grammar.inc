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

typedef struct struct0x0805ee90 *Compound_Form__type;
typedef struct struct0x08059110 *List__O__pointer__O__Void__C____C____type__type;
struct struct0x08059110 {
void *head;
List__O__pointer__O__Void__C____C____type__type tail;
};
typedef struct struct0x0805d790 *Form__type;
typedef void *Output_Descriptor__type;
struct struct0x0805d790 {
Int__type form_type_;
};
typedef struct struct0x0805e110 *Int_Form__type;
struct struct0x0805e110 {
Int__type form_type_;
Int__type value;
};
typedef struct struct0x0805f088 *List__O__Form__C____type__type;
struct struct0x0805ee90 {
Int__type form_type_;
Symbol__type head;
Int__type garbage_;
List__O__Form__C____type__type form_list;
};
struct struct0x0805f088 {
Form__type head;
List__O__Form__C____type__type tail;
};
typedef struct struct0x0805d730 *Exit__type;
struct struct0x08067248 {
Form__type car;
List__O__Form__C____type__type cdr;
};
typedef struct struct0x08525170 *Character_Range__type;
struct struct0x08525170 {
Int__type min;
Int__type max;
};
typedef struct struct0x08525500 *List__O__Character_Range__C____type__type;
struct struct0x08525500 {
Character_Range__type head;
List__O__Character_Range__C____type__type tail;
};
typedef List__O__Character_Range__C____type__type Character_Set__type;
typedef struct struct0x08525c88 *List__O__Character_Set__C____type__type;
struct struct0x08525c88 {
Character_Set__type head;
List__O__Character_Set__C____type__type tail;
};
struct struct0x08528220 {
Character_Range__type car;
List__O__Character_Range__C____type__type cdr;
};
struct struct0x085364e8 {
void *car;
void *cdr;
};
struct struct0x08550ad8 {
Character_Set__type car;
List__O__Character_Set__C____type__type cdr;
};
Bool__type (is_compound_form)(Form__type );
Form__type (Symbol_Form)(Symbol__type );
Form__type (String_Form)(String__type );
void (exit)(Int__type );
void *(GC_alloc)(Int__type );
void (print_Int_Dec)(Int__type );
void *(alloc_cons_cell)(void);
List__O__pointer__O__Void__C____C____type__type (append)(List__O__pointer__O__Void__C____C____type__type , List__O__pointer__O__Void__C____C____type__type );
void (print_String)(String__type );
void (flush)(void);
void (maybe_flush)(void);
Form__type (_l__parse__parse_grammar__Expression)(void);
Form__type (Int_Form)(Int__type );
Form__type (Id_Form)(Symbol__type );
Form__type (Compound_Form)(Symbol__type , List__O__Form__C____type__type );
Int__type (print_form)(Form__type );
Bool__type (is_int_form)(Form__type );
Symbol__type (intern_string)(String__type );
void (set_parser_support_to)(String__type );
Int__type (new_peek_char)(Int__type );
Int__type (read_char)(void);
Symbol__type (parse_symbol)(String__type );
Int__type (character_from_symbol)(Symbol__type );
Int__type (get_point_pos)(void);
String__type (substring)(Int__type , Int__type );
Form__type (_l__parse__parse_grammar__Type)(void);
Character_Set__type (sort_Character_Set)(List__O__Character_Range__C____type__type );
Character_Set__type (make_Character_Set)(Form__type );
Character_Set__type (get_inverse_Character_Set)(Character_Set__type );
Character_Set__type (union_Character_Set)(Character_Set__type , Character_Set__type );
Int__type (_l__parse__parse_grammar__Comment)(void);
void (_l__parse__parse_grammar__Spacing)(void);
Int__type (_l__parse__parse_grammar__Alpha_Num)(void);
Int__type (_l__parse__parse_grammar__Alpha)(void);
Symbol__type (_l__parse__parse_grammar__Identifier)(void);
Int__type (_l__parse__parse_grammar__Escaped_Character)(void);
Form__type (_l__parse__parse_grammar__Callable_Rule_or_Binding)(void);
Int__type (_l__parse__parse_grammar__Maybe_Escaped_Character)(void);
Int__type (_l__parse__parse_grammar__Maybe_Escaped_Character_Character_Range)(void);
Form__type (_l__parse__parse_grammar__String)(void);
Form__type (_l__parse__parse_grammar__Symbol)(void);
Form__type (_l__parse__parse_grammar__Character_Range)(void);
Form__type (_l__parse__parse_grammar__Character_Set)(void);
Form__type (_l__parse__parse_grammar__Primary)(void);
Form__type (_l__parse__parse_grammar__Semantic_Action)(void);
Form__type (_l__parse__parse_grammar__Semantic_Predicate)(void);
Form__type (_l__parse__parse_grammar__Rule_Macro)(void);
Form__type (_l__parse__parse_grammar__Replacement)(void);
Form__type (_l__parse__parse_grammar__Postfix)(void);
Form__type (_l__parse__parse_grammar__Sequence)(void);
Form__type (_l__parse__parse_grammar__Alternative)(void);
Form__type (_l__parse__parse_grammar__Rule)(void);
Form__type (_l__parse__parse_grammar__Grammar_Rule)(void);
Form__type (_l__parse__parse_grammar__Grammar)(void);
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
static struct { unsigned int length; char *content; } __string_10 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_11 = { 15, "Bad min or max\n"};
static struct { unsigned int length; char *content; } __string_12 = { 12, "Parse error\n"};
static struct { unsigned int length; char *content; } __string_13 = { 57, "rule Spacing<i:Int,j:Symbol>:Character = [ \n	]* [^a-b]  ;"};
static struct { unsigned int length; char *content; } __string_14 = { 115, "grammar parse_grammar = { rule truc<i:Int>:Int = toto.tata 'ouf'?; rule test:toto = @Separator(',', truc) ')' a to;"};
static struct { unsigned int length; char *content; } __string_15 = { 51, "rule toto<a:Int>:Form = tata:truc taff @toto< truc>"};
static struct { unsigned int length; char *content; } __string_16 = { 1, "?"};
static struct { unsigned int length; char *content; } __string_17 = { 1, "*"};
static struct { unsigned int length; char *content; } __string_18 = { 1, "+"};
static struct { unsigned int length; char *content; } __string_19 = { 1, ","};
static struct { unsigned int length; char *content; } __string_20 = { 1, ","};
static struct { unsigned int length; char *content; } __string_21 = { 1, "="};
static struct { unsigned int length; char *content; } __string_22 = { 1, ";"};
