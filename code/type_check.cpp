#include "semantic.hpp"
extern int yyerror(const char * s);

Type * int_float_check(Type * t1, Type * t2) {
    Type * t = new Type();
    if(t1->core() == INT && t2->core() == INT){
        t->push_type(INT, 0, 0, NULL);
        return t;
    }
    else if(t1->core() == FLOAT && (t2->core() == INT || t2->core() == FLOAT) || (t2->core() == FLOAT && (t1->core() == INT || t1->core() == FLOAT))){
        t->push_type(FLOAT, 0, 0, NULL);
        return t;
    }
    else return NULL;
}

Type * forge_check(Type * t1, Type * t2) {
    if(!typecmp(t1, t2)){
        return t1;
    }
    Function *fste = forge_st.lookup(t1, t2);
    Type * t = new Type();
    if(!fste){
        yyerror("Type mismatch");
        return NULL;
    }
    else{
        t = fste->return_type;
        return t;
    }
}

Type *mult_type_check_arithmetic(Type *t1, Type *t2){
    Type * t = int_float_check(t1, t2);
    if(t) return t;
    else{
        if(!claim_st.lookup(t1, RING) || !claim_st.lookup(t1, RING)){
            yyerror("multiplication requires expression to be a Ring");
        }
        else{
            return forge_check(t1, t2);
        }
    }
}

Type *div_type_check_arithmetic(Type *t1, Type *t2){
    Type * t = int_float_check(t1, t2);
    if(t) return t;
    else{
        if(!claim_st.lookup(t1, FIELD) || !claim_st.lookup(t2, FIELD)){
            yyerror("division requires expression to be a Group, Ring and Field");
        }
        else{
            return forge_check(t1, t2);
        }
    }
}

Type *modulus_relational_type_check_arithmetic(Type *t1, Type *t2){
    Type * t = int_float_check(t1, t2);
    if(t) return t;
    else{
        yyerror("Modulus/relational_op requires expression to be an int or float type only");
    }
}

Type *add_sub_type_check_arithmetic(Type *t1, Type *t2){
    Type * t = int_float_check(t1, t2);
    if(t) return t;
    else{
        if(!claim_st.lookup(t1, GROUP) || !claim_st.lookup(t2, GROUP)){
            yyerror("Group must be claimed.");
        }
        else{
            return forge_check(t1, t2);
        }
    }

}

Type *and_or_type_check(Type *t1, Type *t2){
    Type *t = new Type();
    if(t1->head->core_type != BOOL || t2->head->core_type != BOOL){
        yyerror("Expression not bool");
    }
    else{
        t->push_type(BOOL, 0, 0, NULL);
        return t;
    }
}

VarTypes convert_constType_to_varType(CType t){
    if(t == CT_INT) return INT;
    else if(t == CT_FLOAT) return FLOAT;
    else if(t == CT_CHAR) return CHAR;
    else if(t == CT_BOOL) return BOOL;
    else if(t == CT_STR) return STR;
    else if(t == CT_VAR) return ENUM;
    else return INT;
}


