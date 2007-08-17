
/* Type-related definitions.  */
type Common_To_All_Type = struct { type_type:Int;
                                   type_form:Form;
                                   size:Int;
                                   alignment:Int;
                                 };
type Real_Type = struct { common_:Common_To_All_Type; }* ;
attribute Type t.type_form = cast( Real_Type, t).common_.type_form;

/* Symbol-related definitions.  */
attribute Symbol s.name = get_symbol_name( s);
