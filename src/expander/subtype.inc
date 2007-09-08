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

typedef struct struct0x080528a0 *Form__type;
typedef void *Hash_Table__type;
typedef void *Output_Descriptor__type;
struct struct0x080528a0 {
Int__type form_type_;
};
typedef struct struct0x080553a0 *Expanded_Form__type;
typedef struct struct0x08054940 *List__O__Form__C____type__type;
struct struct0x08054940 {
Form__type head;
List__O__Form__C____type__type tail;
};
struct struct0x080553a0 {
Int__type form_type_;
Form__type original_form;
Form__type return_form;
Type__type type;
};
typedef struct struct0x08052860 *Exit__type;
struct struct0x0805d4a8 {
Int__type type_type;
Form__type type_form;
Int__type size;
Int__type alignment;
};
typedef struct struct0x0805d690 *Real_Type__type;
typedef struct struct0x0805d4a8 Common_To_All_Type__type;
struct struct0x0805d690 {
Common_To_All_Type__type common_;
};
struct struct0x0805ec58 {
Form__type car;
List__O__Form__C____type__type cdr;
};
typedef Hash_Table__type Hash__O__Type__c__Bool__C____type__type;
typedef Hash_Table__type Hash__O__Type__c__Hash__O__Type__c__Bool__C____C____type__type;
Type__type (Type)(Int__type );
void (exit)(Int__type );
void *(alloc_cons_cell)(void);
Hash_Table__type (make_hash_table)(void);
void (print_String)(String__type );
void (flush)(void);
void (maybe_flush)(void);
void *(gethash)(void *, Hash_Table__type );
void *(puthash)(void *, void *, Hash_Table__type );
void **(JudyLNext)(void *, void *, Int__type );
void **(JudyLFirst)(void *, void *, Int__type );
Form__type (Compound_Form)(Symbol__type , List__O__Form__C____type__type );
Expanded_Form__type (expand)(Form__type );
void (init__subtype)(void);
void (define_subtype_relationship)(Type__type , Type__type );
Bool__type (is_subtype)(Type__type , Type__type );
Output_Descriptor__type current_output_descriptor;
Output_Descriptor__type stdout_output_descriptor;
Output_Descriptor__type stderr_output_descriptor;
static struct { unsigned int length; char *content; } __string_1 = { 8, "Panic : "};
static struct { unsigned int length; char *content; } __string_2 = { 47, "Error: cannot coerce form XXX to into type XXX\n"};
