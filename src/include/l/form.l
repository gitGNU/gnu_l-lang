//type Form = struct { form_type_: Int;} *;
//
//type Id_Form = struct { form_type_: Int;
//                        value : Symbol;} *;
//
//type Int_Form = struct { form_type_: Int;
//                         value : Int;} *;
//
//type Symbol_Form = struct { form_type_: Int;
//                            value : Symbol;} *;
//
//type String_Form = struct { form_type_: Int;
//                            value : String;} *;
//
//type Compound_Form = struct {
//                       form_type_: Int;
//                       head: Symbol;
//                       garbage_:Int;
//                       form_list: List< Form>; } *;
//
//type Expanded_Form = struct { form_type_: Int;
//                              original_form : Form;
//                              return_form: Form;
//                              type: Type ;} *;
//

subtype Expanded_Form < Form;
subtype Compound_Form < Form;


//type Form = {
//  type Id_Form: struct{ value: Symbol;};
//  type Int_Form: struct{ value: Int;};
//  type Symbol_Form: struct{ value: Symbol;};
//  type String_Form: struct{ value: String;};
//  type Compound_Form: struct{ head: Symbol;
//                              form_list: List<Form>; };
//  type Expanded_Form: struct{ original_form: Form;
//                              return_form: Form;
//                              type: Type; };
//} *;

//macro Compound_Form = creator( Compound_Form, 
