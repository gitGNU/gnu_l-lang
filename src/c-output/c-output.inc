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

struct struct0x0805fe70 {
Int__type form_type_;
Symbol__type value;
};
typedef struct struct0x08063990 *Form__type;
typedef struct struct0x08060190 *List__O__Form__C____type__type;
struct struct0x08060190 {
Form__type head;
List__O__Form__C____type__type tail;
};
typedef void *Hash_Table__type;
typedef Hash_Table__type Hash__O__Symbol__c__pointer__O__function__O__Void__c__tuple__O__Expanded_Compound_Form__C____C____C____C____type__type;
typedef void *Output_Descriptor__type;
struct struct0x08061558 {
Int__type form_type_;
String__type value;
};
typedef struct struct0x0805fe70 *Symbol_Form__type;
struct struct0x08063990 {
Int__type form_type_;
};
typedef struct struct0x080642f0 *Int_Form__type;
typedef struct struct0x0805fe70 *Id_Form__type;
struct struct0x08094938 {
Int__type type_type;
Form__type type_form;
Int__type size;
Int__type alignment;
};
typedef struct struct0x08094938 Common_To_All_Type__type;
struct struct0x08063e58 {
Common_To_All_Type__type common_;
Int__type misc_data_;
Type__type origin_type;
};
struct struct0x080642f0 {
Int__type form_type_;
Int__type value;
};
typedef struct struct0x08061558 *String_Form__type;
typedef struct struct0x08065108 *Compound_Form__type;
struct struct0x08065108 {
Int__type form_type_;
Symbol__type head;
Int__type garbage_;
List__O__Form__C____type__type form_list;
};
typedef struct struct0x08067120 *List__O__Compound_Form__C____type__type;
typedef struct struct0x080664c8 *Expanded_Form__type;
struct struct0x080664c8 {
Int__type form_type_;
Form__type original_form;
Form__type return_form;
Type__type type;
};
struct struct0x08067120 {
Compound_Form__type head;
List__O__Compound_Form__C____type__type tail;
};
typedef struct struct0x080946c0 *Expanded_Compound_Form__type;
struct struct0x080946c0 {
Int__type useless_form_type_;
Int__type useless2;
Compound_Form__type return_form_;
Type__type type;
};
typedef struct struct0x08094bd0 *Real_Type__type;
typedef struct struct0x08063e58 *Base_Type__type;
struct struct0x08094bd0 {
Common_To_All_Type__type common_;
};
struct struct0x08096a90 {
Form__type car;
List__O__Form__C____type__type cdr;
};
typedef Hash_Table__type Hash__O__Type__c__Bool__C____type__type;
typedef Hash_Table__type Hash__O__Symbol__c__Bool__C____type__type;
typedef struct struct0x081d1968 *List__O__Expanded_Form__C____type__type;
struct struct0x081d1968 {
Expanded_Form__type head;
List__O__Expanded_Form__C____type__type tail;
};
struct struct0x081eb830 {
Expanded_Form__type car;
List__O__Expanded_Form__C____type__type cdr;
};
struct struct0x0828d258 {
Compound_Form__type car;
List__O__Compound_Form__C____type__type cdr;
};
Form__type (Symbol_Form)(Symbol__type );
void (print_Int_Dec)(Int__type );
void (exit)(Int__type );
void (print_Int_Hex)(Int__type );
void (print_Symbol)(Symbol__type );
void *(alloc_cons_cell)(void);
void **(JudyLNext)(void *, void *, Int__type );
void **(JudyLFirst)(void *, void *, Int__type );
Output_Descriptor__type (make_output_descriptor_write_file)(String__type );
void (print_String)(String__type );
void (flush)(void);
void (maybe_flush)(void);
Hash_Table__type (make_hash_table)(void);
void *(gethash)(void *, Hash_Table__type );
void *(puthash)(void *, void *, Hash_Table__type );
Form__type (Id_Form)(Symbol__type );
Form__type (Int_Form)(Int__type );
Form__type (Compound_Form)(Symbol__type , List__O__Form__C____type__type );
Int__type (print_form)(Form__type );
List__O__Compound_Form__C____type__type (expanded_form_list_from_file_name)(String__type );
Symbol__type (convert_id)(Symbol__type );
String__type (convert_id_as_string)(Symbol__type );
String__type (convert_string)(String__type );
String__type (file_name_non_directory)(String__type );
Type__type (intern_type)(Form__type );
Symbol__type (mangle_type_name)(Type__type );
Symbol__type (prepend_star)(Symbol__type );
Type__type (get_global_type)(Symbol__type );
Bool__type (is_compound_form)(Form__type );
Bool__type (is_expanded_form)(Form__type );
Bool__type (is_int_form)(Form__type );
Bool__type (is_id_form)(Form__type );
Bool__type (is_symbol_form)(Form__type );
Bool__type (is_string_form)(Form__type );
Bool__type (is_struct_type)(Type__type );
Bool__type (is_base_type)(Type__type );
Bool__type (is_pointer_type)(Type__type );
Bool__type (is_tuple_type)(Type__type );
Bool__type (is_function_type)(Type__type );
void (c_output_type)(Symbol__type , Type__type );
void (c_output_type_definition)(Type__type );
void (output_all_type_definitions)(void);
void (reinit_types)(void);
void (init_output_type)(void);
void (c_output_form)(Expanded_Form__type );
void (init_c_output)(void);
void (c_output_function_definition)(Symbol__type , Form__type );
void (c_output_global_definition)(Symbol__type , Form__type );
void (c_output_definition)(Compound_Form__type );
void (doit)(String__type , String__type , String__type );
Output_Descriptor__type current_output_descriptor;
Output_Descriptor__type stdout_descriptor;
