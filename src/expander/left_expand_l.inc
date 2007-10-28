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

typedef struct struct0x08052c28 *Form__type;
typedef void *Hash_Table__type;
typedef void *Output_Descriptor__type;
struct struct0x08052c28 {
Int__type form_type_;
};
typedef struct struct0x08053210 *Id_Form__type;
struct struct0x08053210 {
Int__type form_type_;
Symbol__type value;
};
typedef struct struct0x08055758 *Expanded_Form__type;
typedef struct struct0x08054b28 *Compound_Form__type;
typedef struct struct0x08054cf8 *List__O__Form__C____type;
struct struct0x08054b28 {
Int__type form_type_;
Symbol__type head;
Int__type garbage_;
List__O__Form__C____type form_list;
};
struct struct0x08054cf8 {
Form__type head;
List__O__Form__C____type tail;
};
struct struct0x08055758 {
Int__type form_type_;
Form__type original_form;
Form__type return_form;
Type__type type;
};
struct struct0x0805f9e0 {
Form__type car;
List__O__Form__C____type cdr;
};
typedef struct struct0x081f9ae0 *List__O__Expanded_Form__C____type;
struct struct0x081f9ae0 {
Expanded_Form__type head;
List__O__Expanded_Form__C____type tail;
};
struct struct0x08218c30 {
Expanded_Form__type car;
List__O__Expanded_Form__C____type cdr;
};
typedef struct struct0x085a2408 *Pointer_Type__type;
struct struct0x0805e088 {
Int__type type_type;
Form__type type_form;
Int__type size;
Int__type alignment;
};
typedef struct struct0x0805e088 Common_To_All_Type__type;
struct struct0x085a2408 {
Common_To_All_Type__type common_;
Type__type pointed_type;
};
typedef struct struct0x085b6e48 *Pattern_Return__type;
struct struct0x085b6e48 {
Form__type verification;
Form__type extraction;
};
typedef Hash_Table__type Hash__O__Symbol__c__Left_Expander__C____type;
typedef struct struct0x085cfdc8 *List__O__Symbol__C____type;
struct struct0x085cfdc8 {
Symbol__type head;
List__O__Symbol__C____type tail;
};
struct struct0x085d8b08 {
Symbol__type car;
List__O__Symbol__C____type cdr;
};
Bool__type (is_compound_form)(Form__type );
Form__type (Symbol_Form)(Symbol__type );
void *(GC_alloc)(Int__type );
Symbol__type (insert_local_variable)(Symbol__type , Type__type );
void (exit)(Int__type );
void (print_Symbol)(Symbol__type );
void *(alloc_cons_cell)(void);
Hash_Table__type (make_hash_table)(void);
void (print_String)(String__type );
void (flush)(void);
void (maybe_flush)(void);
Form__type (Int_Form)(Int__type );
void *(gethash)(void *, Hash_Table__type );
void *(puthash)(void *, void *, Hash_Table__type );
Form__type (Id_Form)(Symbol__type );
Expanded_Form__type (Expanded_Form)(Form__type , Type__type );
Form__type (Compound_Form)(Symbol__type , List__O__Form__C____type );
Int__type (print_form)(Form__type );
Type__type (intern_type)(Form__type );
Expanded_Form__type (expand)(Form__type );
Expanded_Form__type (coerced_form)(Expanded_Form__type , Type__type );
Symbol__type (gensym)(String__type );
Pattern_Return__type (left_expand_deref)(Compound_Form__type , Expanded_Form__type );
Pattern_Return__type (left_expand_let)(Compound_Form__type , Expanded_Form__type );
Pattern_Return__type (left_expand_tuple)(Compound_Form__type , Expanded_Form__type );
Form__type (left_expand)(Form__type , Expanded_Form__type );
Pattern_Return__type (left_expand_rec)(Form__type , Expanded_Form__type );
Output_Descriptor__type current_output_descriptor;
Output_Descriptor__type stdout_output_descriptor;
Output_Descriptor__type stderr_output_descriptor;
static struct { unsigned int length; char *content; } __string_1 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_2 = { 36, "Error: no left expander defined for "};
static struct { unsigned int length; char *content; } __string_3 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_4 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_5 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_6 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_7 = { 5, "tuple"};
static struct { unsigned int length; char *content; } __string_8 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_9 = { 8, " failed\n"};
static struct { unsigned int length; char *content; } __string_10 = { 10, "Assertion "};
static struct { unsigned int length; char *content; } __string_11 = { 8, " failed\n"};
