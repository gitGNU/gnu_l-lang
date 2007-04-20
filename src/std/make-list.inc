typedef int Int__type;
typedef int Bool__type;
typedef void *Type__type;
typedef void* Label__type;
typedef void Void__type;
typedef struct {} * Symbol__type;

typedef struct {unsigned int len; char *content;} * String__type;
typedef void * Output_Descriptor__type;

Symbol__type intern( const char * string);
Void__type print_Int_Dec( int i);
Void__type print_String( String__type s);
void maybe_flush( void);
String__type make_heap_string( char *s);

typedef struct struct0x080588a0 *List__O__Int__C____type__type;
struct struct0x080588a0 {
Int__type head;
List__O__Int__C____type__type tail;
};
typedef struct struct0x08058f88 *List_Maker_Element__type;
typedef struct struct0x08058f58 *List__O__List_Maker_Element__C____type__type;
struct struct0x08058f58 {
List_Maker_Element__type head;
List__O__List_Maker_Element__C____type__type tail;
};
struct struct0x08058f88 {
Symbol__type ptr_name;
Type__type type_listed;
};
typedef struct struct0x0805d338 *Form__type;
typedef struct struct0x0805ebc0 *List__O__Form__C____type__type;
struct struct0x0805d338 {
Int__type form_type_;
};
typedef struct struct0x0805e9c8 *Compound_Form__type;
struct struct0x0805e9c8 {
Int__type form_type_;
Symbol__type head;
Int__type garbage_;
List__O__Form__C____type__type form_list;
};
typedef struct struct0x0805f438 *Expanded_Form__type;
struct struct0x0805ebc0 {
Form__type head;
List__O__Form__C____type__type tail;
};
struct struct0x0805f438 {
Int__type form_type_;
Form__type original_form;
Form__type return_form;
Type__type type;
};
struct struct0x0808ce28 {
Int__type type_type;
Form__type type_form;
Int__type size;
Int__type alignment;
};
typedef struct struct0x0808d0b0 *Real_Type__type;
typedef struct struct0x0808ce28 Common_To_All_Type__type;
struct struct0x0808d0b0 {
Common_To_All_Type__type common_;
};
struct struct0x0808e910 {
Form__type car;
List__O__Form__C____type__type cdr;
};
struct struct0x08470068 {
List_Maker_Element__type car;
List__O__List_Maker_Element__C____type__type cdr;
};
struct struct0x084fdcd0 {
Int__type car;
List__O__Int__C____type__type cdr;
};
struct struct0x085019f8 {
void *car;
void *cdr;
};
typedef struct struct0x08506bf0 *List__O__Symbol__C____type__type;
struct struct0x08506bf0 {
Symbol__type head;
List__O__Symbol__C____type__type tail;
};
struct struct0x08507c28 {
Symbol__type car;
List__O__Symbol__C____type__type cdr;
};
Form__type (Symbol_Form)(Symbol__type );
void (print_Int_Dec)(Int__type );
void (exit)(Int__type );
void *(GC_alloc)(Int__type );
void (print_Symbol)(Symbol__type );
void *(alloc_cons_cell)(void);
void (print_String)(String__type );
void (maybe_flush)(void);
Form__type (Int_Form)(Int__type );
Form__type (Id_Form)(Symbol__type );
Form__type (Compound_Form)(Symbol__type , List__O__Form__C____type__type );
Expanded_Form__type (expand)(Form__type );
Symbol__type (gensym)(String__type );
Output_Descriptor__type current_output_descriptor;
Output_Descriptor__type stdout_descriptor;
