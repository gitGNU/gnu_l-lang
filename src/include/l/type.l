type Common_To_All_Type = struct { type_type:Int;
                         type_form:Form;
                         size:Int;
                         alignment:Int;
                       };

type Real_Type = struct { common_:Common_To_All_Type; }* ;

type Base_Type = struct { common_:Common_To_All_Type;
                          misc_data_:Int;
                          origin_type:Type; } *;

type Pointer_Type = struct { common_:Common_To_All_Type;
                             pointed_type:Type; } *;     

// Only Type should be exposed; but we also need Base_Type's original type.
attribute Type t.type_form = cast( Real_Type, t).common_.type_form;
