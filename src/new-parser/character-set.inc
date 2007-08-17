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

typedef struct struct0x0805eec0 *Compound_Form__type;
typedef struct struct0x08059208 *List__O__pointer__O__Void__C____C____type__type;
typedef struct struct0x0805d798 *Form__type;
struct struct0x08059208 {
void *head;
List__O__pointer__O__Void__C____C____type__type tail;
};
struct struct0x08059d10 {
Int__type form_type_;
Int__type value;
};
typedef void *Output_Descriptor__type;
struct struct0x0805d798 {
Int__type form_type_;
};
typedef struct struct0x08059d10 *Int_Form__type;
typedef struct struct0x0805f070 *List__O__Form__C____type__type;
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
struct struct0x08067cc8 {
Form__type car;
List__O__Form__C____type__type cdr;
};
typedef struct struct0x08552a38 *Character_Range__type;
struct struct0x08552a38 {
Int__type min;
Int__type max;
};
typedef struct struct0x08552da8 *List__O__Character_Range__C____type__type;
struct struct0x08552da8 {
Character_Range__type head;
List__O__Character_Range__C____type__type tail;
};
typedef List__O__Character_Range__C____type__type Character_Set__type;
typedef struct struct0x08553628 *List__O__Character_Set__C____type__type;
struct struct0x08553628 {
Character_Set__type head;
List__O__Character_Set__C____type__type tail;
};
struct struct0x08554d10 {
Character_Range__type car;
List__O__Character_Range__C____type__type cdr;
};
struct struct0x08563308 {
void *car;
void *cdr;
};
struct struct0x0857e0e0 {
Character_Set__type car;
List__O__Character_Set__C____type__type cdr;
};
Bool__type (is_compound_form)(Form__type );
void (exit)(Int__type );
void *(GC_alloc)(Int__type );
void (print_Int_Dec)(Int__type );
void *(alloc_cons_cell)(void);
List__O__pointer__O__Void__C____C____type__type (append)(List__O__pointer__O__Void__C____C____type__type , List__O__pointer__O__Void__C____C____type__type );
void (print_String)(String__type );
void (flush)(void);
void (maybe_flush)(void);
Form__type (Int_Form)(Int__type );
Form__type (Id_Form)(Symbol__type );
Form__type (Compound_Form)(Symbol__type , List__O__Form__C____type__type );
Int__type (print_form)(Form__type );
Bool__type (is_int_form)(Form__type );
Int__type (character_from_symbol)(Symbol__type );
Character_Set__type (sort_Character_Set)(List__O__Character_Range__C____type__type );
Character_Set__type (make_Character_Set)(Form__type );
Character_Set__type (get_inverse_Character_Set)(Character_Set__type );
Character_Set__type (union_Character_Set)(Character_Set__type , Character_Set__type );
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
