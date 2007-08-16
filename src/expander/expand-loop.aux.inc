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

typedef struct struct0x0805ee20 *Compound_Form__type;
typedef struct struct0x0805d708 *Form__type;
typedef void *Output_Descriptor__type;
struct struct0x0805d708 {
Int__type form_type_;
};
typedef struct struct0x0805efd0 *List__O__Form__C____type__type;
struct struct0x0805ee20 {
Int__type form_type_;
Symbol__type head;
Int__type garbage_;
List__O__Form__C____type__type form_list;
};
struct struct0x0805efd0 {
Form__type head;
List__O__Form__C____type__type tail;
};
typedef struct struct0x0805f7d8 *Expanded_Form__type;
struct struct0x080b27b8 {
Form__type car;
List__O__Form__C____type__type cdr;
};
void *(alloc_cons_cell)(void);
Form__type (Int_Form)(Int__type );
Form__type (Id_Form)(Symbol__type );
Form__type (Compound_Form)(Symbol__type , List__O__Form__C____type__type );
Expanded_Form__type (expand)(Form__type );
Output_Descriptor__type current_output_descriptor;
Output_Descriptor__type stdout_output_descriptor;
Output_Descriptor__type stderr_output_descriptor;
