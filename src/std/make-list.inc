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

typedef struct struct0x08058a98 *List__O__Int__C____type__type;
struct struct0x08058a98 {
Int__type head;
List__O__Int__C____type__type tail;
};
typedef struct struct0x08059180 *List_Maker_Element__type;
struct struct0x08059180 {
Symbol__type ptr_name;
Type__type type_listed;
};
typedef struct struct0x0805eba0 *List__O__Form__C____type__type;
typedef void *Output_Descriptor__type;
typedef struct struct0x0805d238 *Form__type;
struct struct0x0805d238 {
Int__type form_type_;
};
typedef struct struct0x0805e968 *Compound_Form__type;
struct struct0x0805e968 {
Int__type form_type_;
Symbol__type head;
Int__type garbage_;
List__O__Form__C____type__type form_list;
};
typedef struct struct0x0805f3a0 *Expanded_Form__type;
struct struct0x0805eba0 {
Form__type head;
List__O__Form__C____type__type tail;
};
struct struct0x0805f3a0 {
Int__type form_type_;
Form__type original_form;
Form__type return_form;
Type__type type;
};
struct struct0x080911a0 {
Int__type type_type;
Form__type type_form;
Int__type size;
Int__type alignment;
};
typedef struct struct0x08091410 *Real_Type__type;
typedef struct struct0x080911a0 Common_To_All_Type__type;
struct struct0x08091410 {
Common_To_All_Type__type common_;
};
struct struct0x08092850 {
Form__type car;
List__O__Form__C____type__type cdr;
};
typedef struct struct0x0849c1e8 *List__O__List_Maker_Element__C____type__type;
struct struct0x0849c1e8 {
List_Maker_Element__type head;
List__O__List_Maker_Element__C____type__type tail;
};
struct struct0x0849dc30 {
List_Maker_Element__type car;
List__O__List_Maker_Element__C____type__type cdr;
};
struct struct0x084f8dd8 {
Int__type car;
List__O__Int__C____type__type cdr;
};
struct struct0x085317c0 {
void *car;
void *cdr;
};
typedef struct struct0x08536af8 *List__O__Symbol__C____type__type;
struct struct0x08536af8 {
Symbol__type head;
List__O__Symbol__C____type__type tail;
};
struct struct0x08537ac0 {
Symbol__type car;
List__O__Symbol__C____type__type cdr;
};
Form__type (Symbol_Form)(Symbol__type );
void (exit)(Int__type );
void *(GC_alloc)(Int__type );
void (print_Int_Dec)(Int__type );
void (print_Symbol)(Symbol__type );
void *(alloc_cons_cell)(void);
void (print_String)(String__type );
void (maybe_flush)(void);
Form__type (Id_Form)(Symbol__type );
Form__type (Int_Form)(Int__type );
Form__type (Compound_Form)(Symbol__type , List__O__Form__C____type__type );
Expanded_Form__type (expand)(Form__type );
Symbol__type (gensym)(String__type );
Output_Descriptor__type current_output_descriptor;
Output_Descriptor__type stdout_output_descriptor;
Output_Descriptor__type stderr_output_descriptor;
static struct { unsigned int length; char *content; } __string_1 = { 9, "Element: "};
static struct { unsigned int length; char *content; } __string_2 = { 1, "\n"};
static struct { unsigned int length; char *content; } __string_3 = { 8, "-------\n"};
static struct { unsigned int length; char *content; } __string_4 = { 9, "Element: "};
static struct { unsigned int length; char *content; } __string_5 = { 1, "\n"};
static struct { unsigned int length; char *content; } __string_6 = { 9, "make_list"};
static struct { unsigned int length; char *content; } __string_7 = { 13, "make_list_ptr"};
static struct { unsigned int length; char *content; } __string_8 = { 58, "Error: make_list must contain at least one call to make()\n"};
static struct { unsigned int length; char *content; } __string_9 = { 56, "Error: Trying to make an element outside of a make_list\n"};
static struct { unsigned int length; char *content; } __string_10 = { 52, "Type mismatch: trying to make an heterogeneous list\n"};
