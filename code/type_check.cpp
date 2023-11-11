#include "semantic.hpp"
extern int yyerror(const char * s);

bool is_int_or_float(VarTypes t) {
    return t == INT || t == FLOAT;
}

// Check if both types are either int or float.
// If so, return float if either is float, else int (C++ rules).
Expr * int_float_check(Expr * t1, Expr * t2) {
    if (!t1 || !t2) return NULL;
    VarTypes t1_ = t1->core();
    VarTypes t2_ = t2->core();

    if (!is_int_or_float(t1_) || !is_int_or_float(t2_)) return NULL;

    Type * t = t1_ == FLOAT ? t1 : t2;

    return new Expr(t, false);
}

// Result of multiplying two types
// If both are int or float, return float if either is float, else int (C++ rules).
// If both are equal, must claim ring
// First could be a space over the second, then return the second
Expr *mult_type_check_arithmetic(Expr *t1, Expr *t2) {
    if (!t1 || !t2) return NULL;

    Type * t = int_float_check(t1, t2);
    if (t) return new Expr(t, false);

    if (typecmp(t1, t2) == 0) {
        if (!claim_st.lookup(t1, RING)) {
            yyerror("Multipying two equal types requires a ring claim");
        }
        return new Expr(t1, false);
    }

    auto claim = claim_st.lookup(t1, SPACE);
    if (claim && typecmp(claim->over, t2) == 0) {
        return new Expr(t2, false);
    } else {
        yyerror("Multiplying two unequal types requires an appropriate space claim");
        return NULL;
    }
}

// Result of dividing two types
// If both are int or float, return float if either is float, else int (C++ rules).
// If both are equal, must claim field
// First could be a space over the second, then second must be a field
Expr *div_type_check_arithmetic(Expr *t1, Expr *t2) {
    if (!t1 || !t2) return NULL;

    Type * t = int_float_check(t1, t2);
    if(t) return new Expr(t, false);

    if (typecmp(t1, t2) == 0) {
        if (!claim_st.lookup(t1, FIELD)) {
            yyerror("Division requires a field claim");
        }
        return new Expr(t1, false);
    }

    auto claim = claim_st.lookup(t1, SPACE);
    if (claim && typecmp(claim->over, t2) == 0) {
        return new Expr(t2, false);
    } else {
        yyerror("Dividing two unequal types requires an appropriate space claim");
        return NULL;
    }
}

// both types must be int
Expr *modulus_type_check_arithmetic(Expr *t1, Expr *t2) {
    if (!t1 || !t2) return NULL;

    if (t1->core() != INT || t2->core() != INT) {
        yyerror("Modulus requires both operands to be int types");
        return NULL;
    }

    return new Expr(t1, false);
}

// both types must be int or float
Expr *cmp_op_type_check_arithmetic(Expr *t1, Expr *t2) {
    if (!t1 || !t2) return NULL;
    VarTypes t1_ = t1->core();
    VarTypes t2_ = t2->core();

    if (!is_int_or_float(t1_) || !is_int_or_float(t2_)) {
        yyerror("Relational operator requires both operands to be int or float types");
        return NULL;
    }

    Type *t = new Type();
    t->push_type(BOOL, 0, 0, NULL);
    return new Expr(t, false);
}

// both types must be int or float
// OR same type
Expr *eq_op_type_check_arithmetic(Expr *t1, Expr *t2) {
    if (!t1 || !t2) return NULL;

    Expr *t = int_float_check(t1, t2);
    if (t) {
        delete t;
        Type *t = new Type();
        t->push_type(BOOL, 0, 0, NULL);
        return new Expr(t, false);
    }

    if (typecmp(t1, t2) == 0) {
        Type *t = new Type();
        t->push_type(BOOL, 0, 0, NULL);
        return new Expr(t, false);
    }

    yyerror("Equality operator requires both operands to be the same type");
    return NULL;
}

// both types must be int or float
// or both types must be equal and claimed as a group
Expr *add_sub_type_check_arithmetic(Expr *t1, Expr *t2) {
    if (!t1 || !t2) return NULL;

    Type * t = int_float_check(t1, t2);
    if(t) return new Expr(t, false);

    if (typecmp(t1, t2) != 0) {
        yyerror("Cannot add or subtract two unequal types");
        return NULL;
    }

    if (!claim_st.lookup(t1, GROUP)) {
        yyerror("Adding or subtracting requires a group claim");
    }
    return new Expr(t1, false);
}

// both types must be bool
Expr *and_or_type_check(Expr *t1, Expr *t2) {
    if (!t1 || !t2) return NULL;
    if(t1->core() != BOOL || t2->core() != BOOL){
        yyerror("&& and || require both operands to be boolean types");
        return NULL;
    }
    Type *t = new Type();
    t->push_type(BOOL, 0, 0, NULL);
    return new Expr(t, false);
}

// t2 must be a BUF over t1
Expr *in_type_check(Expr *t1, Expr *t2) {
    if (!t1 || !t2) return NULL;
    if (t2->core() != BUF) {
        yyerror(GREEN_ESCAPE "in" RESET_ESCAPE " requires the second operand to be a BUF");
        return NULL;
    }
    if (typecmp(t1->head, t2->head->next) != 0) {
        yyerror(GREEN_ESCAPE "in" RESET_ESCAPE " requires the second operand to be a Buf over the first");
        return NULL;
    }
    Type *t = new Type();
    t->push_type(BOOL, 0, 0, NULL);
    return new Expr(t, false);
}

VarTypes convert_constType_to_varType(CType t) {
    if(t == CT_INT) return INT;
    else if(t == CT_FLOAT) return FLOAT;
    else if(t == CT_CHAR) return CHAR;
    else if(t == CT_BOOL) return BOOL;
    else if(t == CT_STR) return STR;
    else if(t == CT_VAR) return ENUM;
    else return INT;
}
