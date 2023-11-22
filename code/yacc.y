%require "3.6"
%{
    #include <stdint.h>
    #include "../code/semantic.hpp"
    extern int yylex();
    void yyerror(const char* s);
    FILE * token_stream;
    FILE * output_stream;
    // flags
    Type * current_func = NULL;
    int in_loop = 0;
    int in_cond = 0;
    int in_forg = 0;
    Scope * current_scope = NULL;
    Struct * method_of = NULL;
    Claim * current_claim = NULL;

    using namespace std;

    extern int yylineno;

    int indent = 0;
    void gen_line(string &s);
    void gen_line(const char *);

%}
%code requires {
    #include "../code/semantic.hpp"
}
%union {
    std::string * ident;
    int lit_int;
    double lit_float;
    std::string * lit_str;
    std::string * op;
    char lit_char;
    PDT prim_type;
    struct {
        union {
            int lit_int;
            double lit_float;
            std::string * lit_str;
            char lit_char;
            bool bl;
            Variant * var;
        };
        CType type;
    } cons;
    Type * type;
    Expr * expr;
    Archetypes archetype; 
    Claim * claim_stub_type;
    VarSymbolTable * var_table;
    Var * var;
    std::vector<std::string> * ident_list_type;
    std::vector<Type *> * type_list;
    int count;
    Function * func;
    GenericInner * targ;
    std::vector<GenericInner *> * targ_list;
}

// keywords
%token KW_CLAIM KW_IS KW_GROUP KW_RING KW_FIELD KW_SPACE KW_LET KW_RETURN KW_IF KW_ELSE KW_WHILE KW_FOR KW_IN KW_SWITCH KW_CASE KW_DEFAULT KW_BREAK KW_CONTINUE KW_FN KW_FORGE KW_AS KW_STRUCT KW_ENUM KW_WITH KW_THIS

// Types
%token <ident> IDENT 
%token <prim_type> PRIMITIVE_DTYPE 
%token <lit_int> LIT_INT 
%token <lit_float> LIT_FLOAT 
%token <lit_str> LIT_STR 
%token <lit_char> LIT_CHAR 

%token <op> CMP_OP
%token <op> EQ_OP
%token <op> ASSIGN_OP
%token KW_TRUE KW_FALSE

%token INCR DECR ARROW VARIANT SLICE AND OR // Two character operators.

%left OR
%left AND
%left KW_IN
%left CMP_OP '>' '<'
%left EQ_OP
%left '+' '-' 
%left '*' '/' '%' 
%left '@'
%left KW_AS 
%right '!' // Also unary minus, ref, and deref - see `expression` definition.
%left INCR DECR
%left '[' '('
%left '.'

%type <cons> constant

%type <op> assign_op
%type <expr> expression
%type <expr> cart_value
%type <expr> array_decl
%type <expr> array_access
%type <expr> call
%type <expr> unary_operation
%type <expr> loop_cond

%type <type> type
%type <type> cart
%type <type> generic
%type <type> type_def
%type <type_list> type_list
%type <type_list> opt_expr_list
%type <type_list> expr_list
%type <type_list> expr_list_
%type <type_list> cart_value_list
%type <type_list> cart_value_list_
%type <type_list> sc_blocks

%type <archetype> archetype

%type <claim_stub_type> claim_stub

%type <var> type_var
%type <var_table> end_table

%type <ident_list_type> ident_list
%type <ident_list_type> variant_list

%type <count> array_index

%type <func> fh_stub

%type <targ> type_arg
%type <targ_list> type_args

%start program

%%
program         : start_table P end_table

P               : epsilon
                | P declaration ';'
                | P ';'
                | P function
                | P struct
                | P forge
                | P enum
                | P archetype_claim
                ;

start_table     : epsilon {
                    Scope * new_scope = new Scope();
                    new_scope->parent = current_scope;
                    current_scope = new_scope;
                }
                ;

end_table       : epsilon {
                    $$ = current_scope->vars;
                    current_scope = current_scope->parent;
                }

start_block     : '{' {
                    gen_line("{");
                    indent++;
                }

end_block       : '}' {
                    indent--;
                    gen_line("}");
                }

body            : start_block start_table statements end_table end_block
                ;

statements      : statement statements
                | epsilon
                ;

statement       : declaration ';'
                | assignment ';'
                | unary_operation ';'
                | call ';' // check if exists.
                | return_stmt ';' 
                | conditional
                | switch_case
                | loop_stmt
                | KW_BREAK ';' {if(!in_loop) yyerror("break statement outside of loop");}
                | KW_CONTINUE ';' {if(!in_loop) yyerror("continue statement outside of loop");}
                | ';'
                ;

generic         : IDENT '<' type_args '>' {
                    Generic * gste = gen_st.lookup(*$1);
                    if(!gste) {
                        string err = "Generic type " GREEN_ESCAPE + *$1 + RESET_ESCAPE " not found.";
                        yyerror(err.c_str());
                        break;
                    }
                    if(!$3) {
                        yyerror("Unknown compile error (allocation failed?)");
                        $$ = NULL;
                        break;
                    }
                    if(gste->types.size() != $3->size()) {
                        yyerror("Generic type has wrong number of parameters.");
                        break;
                    }
                    auto arr = new vector<GenericInner *>();
                    bool err = false;
                    for(int i = 0; i < $3->size(); i++) {
                        GenericInner * t = (*$3)[i];
                        if (gste->types[i].is_int) {
                            if (!t->is_int) {
                                yyerror("Expected integer generic parameter, found type.");
                                err = true;
                                break;
                            }
                            arr->push_back(new GenericInner(t->lit_int));
                        } else {
                            if (t->is_int) {
                                yyerror("Expected type generic parameter, found integer.");
                                err = true;
                                break;
                            }

                            Archetypes a = gste->types[i].archetype;
                            Type * t1 = (*$3)[i]->type;
                            if (!claim_st.lookup(t1, a)) {
                                yyerror("Type does not claim archetype.");
                                err = true;
                                break;
                            }
                            arr->push_back(new GenericInner(t->type));
                        }
                    }
                    if (err) {
                        $$ = NULL;
                        break;
                    }

                    $$ = new Type();
                    /**
                     * New rule: Only the last entry of a generic will be considered for the stack.
                     * That way, generic over one type only, and position also defined.
                     * We do not need to check this, because we will be hardcoding all the generics.
                    */
                    $$->push_type(GEN, 0, 0, new Aux(gste, arr)); 
                }
                ;

type_args       : type_args ',' type_arg {
                    $$ = $1;
                    $$->push_back($3);
                }
                | type_arg {
                    vector<GenericInner *> *arr = new vector<GenericInner *>(1, $1);
                    $$ = arr;
                }
                | epsilon { 
                    vector<GenericInner *> *arr = new vector<GenericInner *>;
                    $$ = arr;
                }
                ;

type_arg        : type {
                    $$ = new GenericInner($1);
                }
                | LIT_INT {
                    $$ = new GenericInner($1);
                }
                ;

declaration     : KW_LET decl_list
                ;

decl_list       : decl_item
                | decl_item ',' decl_list 
                ;

decl_item       : type_var {
                    if(!$1) {
                        break;
                    }

                    string repr_cpp = $1->type->repr_cpp() + " " + $1->name + ";";
                    gen_line(repr_cpp);
                }
                | type_var '=' expression {
                    if(!$1) {
                        break;
                    }
                    if (!current_scope->parent) {
                        yyerror("Cannot assign to global variable. (use main)");
                        break;
                    } else if (typecmp($1->type, $3)) {
                        yyerror("Type mismatch in declaration.");
                        break;
                    }

                    // TODO: expr.repr
                    string repr_cpp = $1->type->repr_cpp() + " " + $1->name + " = " + $3->repr_cpp() + ";";
                    gen_line(repr_cpp);
                }
                ;

type_var        : IDENT ':' type {
                    auto out = new Var(*$1, $3);
                    if (current_scope->insert(out)) {
                        string err = "Variable " + *$1 + " already defined.";
                        yyerror(err.c_str());
                        $$ = NULL;
                    } else {
                        $$ = out;
                    }
                }
                ;

type            : PRIMITIVE_DTYPE {
                    Type * t = new Type(); 
                    t->push_type(get_vt($1), 0, 0, NULL);
                    t->head->pdt = $1;
                    $$ = t;

                }
                | '[' type ']' {
                    Type * t = new Type();
                    if($2) {
                        t->head = $2->head;
                    }
                    // Even if inner type is invalid, buffer is propagated. There may be further type errors independent of the inner type.
                    t->push_type(BUF, 0, 1, NULL);
                    $$ = t;
                }
                | IDENT {
                    // struct lookup
                    Struct * entry = struct_st.lookup(*$1);
                    if(!entry) {
                        // enum lookup
                        Enum * entry = enum_st.lookup(*$1);
                        if(!entry) yyerror("No such type.");
                        else {
                            Type * t = new Type();
                            t->push_type(ENUM, 0, 1, new Aux(entry)); // aux is the symbol table entry.
                            $$ = t;
                        }
                    }
                    else {
                        Type * t = new Type();

                        t->push_type(STRUCT, 0, 1, new Aux(entry)); // aux is the symbol table entry.
                        $$ = t;
                    }
                }
                | generic 
                | '&' type {
                    if(!$2) {
                        $$ = NULL;
                        break;
                    }
                    Type * t = new Type();
                    t->head = $2->head; // Reference to this.
                    t->push_type(REF, 0, 1, NULL); // Push the reference.
                    $$ = t;
                }
                | cart 
                ; 

assign_op       : ASSIGN_OP { $$ = $1; }
                | '=' { $$ = new string("="); }
                ;

assignment      : expression assign_op expression  {
                    if (!$1 || !$3) {
                        break;
                    } else if (!$1->is_lvalue) {
                        yyerror("Cannot assign to non-lvalue.");
                        break;
                    } else if (typecmp($1, $3)) {
                        yyerror("Type mismatch in assignment.");
                        break;
                    }

                    // TODO: expr.repr
                    string repr_cpp = $1->repr_cpp() + " " + *$2 + " " + $3->repr_cpp() + ";";
                    gen_line(repr_cpp);
                }
                ;

constant        : LIT_CHAR {$$.lit_char = $1; $$.type = CT_CHAR;}
                | LIT_FLOAT {$$.lit_float = $1; $$.type = CT_FLOAT;}
                | LIT_INT {$$.lit_int = $1; $$.type = CT_INT;}
                | LIT_STR {$$.lit_str = $1; $$.type = CT_STR;}
                | KW_TRUE {$$.bl = true; $$.type = CT_BOOL;}
                | KW_FALSE {$$.bl = false; $$.type = CT_BOOL;}
                | IDENT VARIANT IDENT  {
                    $$.var = NULL;
                    Enum * entry = enum_st.lookup(*$1);
                    if(!entry) yyerror("Enum not found in symbol table.");
                    else {
                        for(auto i: entry->fields) {
                            if(i == *$3) {
                                $$.var = new Variant(*$1, *$3, entry);
                                $$.type = CT_VAR; 
                                break;
                            }
                        }
                        if(!$$.var) yyerror("Variant not found in enum.");
                    }
                } 
                ;

expression      : '(' expression ')' {
                    $$ = $2;
                    $$->repr_cpp = "(" + $$->repr_cpp + ")";
                }
                | array_access
                | '!' expression {
                    if (!$2) {
                        $$ = NULL;
                        break;
                    }
                    if($2->core() != BOOL){
                        yyerror("Can only negate bool expression!");
                    }
                    $$ = new Expr($2, false); // need new one coz different is_lvalue??
                    $$->repr_cpp = "!" + $$->repr_cpp;
                }
                | '-' expression                %prec '!'  // Unary minus has precedence of '!', not subtraction.
                {
                    if (!$2) {
                        $$ = NULL;
                        break;
                    }
                    if($2->core() == INT || $2->core() == FLOAT) {
                        $$ = new Expr($2, false);
                        break;
                    }
                    Claim * cste = claim_st.lookup($2, GROUP);
                    if(!cste){
                        yyerror("unary minus requires Group");
                    }
                    $$ = new Expr($2, false);
                    $$->repr_cpp = "-" + $$->repr_cpp;
                }
                | '*' expression                %prec '!'  // Dereference has precedence of '!', not multiplication.   
                {
                    if (!$2) {
                        $$ = NULL;
                        break;
                    }
                    if ($2->core() != REF){
                        yyerror("Dereference of non-reference type.");
                    }
                    Type * t = $2->pop_type();
                    $$ = new Expr(t, true);
                    $$->repr_cpp = "*" + $$->repr_cpp;
                }
                | '&' expression                %prec '!'  // Address-of has precedence of '!', bitwise operators do not exist.
                {
                    if (!$2) {
                        $$ = NULL;
                        break;
                    }
                    // We could just not do this?
                    Type * t = new Type();
                    t->head = $2->head;
                    t->push_type(REF, 0, 0, NULL);
                    $$ = new Expr(t, false);
                    $$->repr_cpp = "&" + $$->repr_cpp;
                }
                | expression '.' IDENT // struct access, lookup in table
                {
                    if (!$1) {
                        $$ = NULL;
                        break;
                    }
                    if ($1->core() != STRUCT){
                        yyerror("Field access on non-struct type.");
                        $$ = NULL;
                    } else {
                        Struct * sste = $1->head->sste;
                        Var *v = sste->fieldLookup(*($3));
                        if(!v){
                            yyerror("Field of struct doesn't exist");
                        }
                        $$ = new Expr(v->type, $1->is_lvalue);
                        $$->repr_cpp = $1->repr_cpp + "." + *$3;
                    }
                }
                | expression '.' LIT_INT 
                {
                    if (!$1) {
                        $$ = NULL;
                        break;
                    }
                    if($1->core() != CART) {
                        yyerror("Tuple access on non-tuple type.");
                    } 
                    else 
                    {
                        if($3 < 0 || $3 >= $1->head->size) {
                            yyerror("Tuple access out of bounds.");
                            break;
                        } else {
                            auto c = $1->head->cart;
                            Type * t = new Type();
                            t->head = (*c)[$3]->head;
                            $$ = new Expr(t, $1->is_lvalue);
                            $$->repr_cpp = $1->repr_cpp + "." + to_string($3);
                        }
                    }
                }         
                | expression KW_AS '(' type ')' {
                    if (!$1) {
                        $$ = NULL;
                        break;
                    }
                    Function * fste = forge_st.lookup($1, $4);
                    if(!fste){
                        yyerror("No forge found");
                    }
                    else{
                        Type * t = fste->return_type;
                        $$ = new Expr(t, false);
                        $$->repr_cpp = fste->name + "(" + $1->repr_cpp + ")";
                    }
                }
                // TODO: Don't even ask.
                | expression '@' expression // claim space 
                {
                    if (!$1 || !$3) {
                        $$ = NULL;
                        break;
                    }
                    Claim * cste1 = claim_st.lookup($1, SPACE);
                    Claim * cste2 = claim_st.lookup($3, SPACE);
                    if(!cste1 || !cste2){
                        yyerror("Both operands to " RED_ESCAPE "@" RESET_ESCAPE " must be spaces.");
                    } else {
                        if(!typecmp($1, $3)) {
                            // same type, don't need to check for forge
                            Type * t = cste1->over;
                            $$ = new Expr(t, false);
                            break;
                        }

                        // both types are different, check for forge between innards.
                        auto f1 = $1->pop_type();
                        auto f2 = $3->pop_type(); 
                        Function * temp = forge_st.lookup(f1, f2);
                        Function * fste = temp ? temp : forge_st.lookup(f2, f1);
                        if(!fste){
                            yyerror("Use of " RED_ESCAPE "@" RESET_ESCAPE " over incompatible spaces.");
                        }
                        else{
                            Type * temp = fste->return_type;
                            Type * t = temp->pop_type(); 
                            $$ = new Expr(t, false);
                            /***
                             * IMPORTANT
                             * In Type *, if the head claims SPACE, the field it is a space over will be in the next pointer.
                             * Hence the pop_type() call.
                             * In a Claim, this is not so - there is a separate field.
                            */
                        }
                    }
                }
                | expression '*' expression    { $$ = mult_type_check_arithmetic($1, $3); $$->repr_cpp = $1->repr_cpp + " * " + $3->repr_cpp; }
                | expression '/' expression    { $$ = div_type_check_arithmetic($1, $3); $$->repr_cpp = $1->repr_cpp + " / " + $3->repr_cpp; }
                | expression '%' expression    { $$ = modulus_type_check_arithmetic($1, $3); $$->repr_cpp = $1->repr_cpp + " % " + $3->repr_cpp;}
                | expression '+' expression    { $$ = add_sub_type_check_arithmetic($1, $3); $$->repr_cpp = $1->repr_cpp + " + " + $3->repr_cpp;}
                | expression '-' expression    { $$ = add_sub_type_check_arithmetic($1, $3); $$->repr_cpp = $1->repr_cpp + " - " + $3->repr_cpp;}
                | expression '>' expression    { $$ = cmp_op_type_check_arithmetic($1, $3); $$->repr_cpp = $1->repr_cpp + " > " + $3->repr_cpp;}
                | expression '<' expression    { $$ = cmp_op_type_check_arithmetic($1, $3); $$->repr_cpp = $1->repr_cpp + " < " + $3->repr_cpp;}
                // TODO: these three
                | expression CMP_OP expression { $$ = cmp_op_type_check_arithmetic($1, $3); }
                | expression EQ_OP expression  { $$ = eq_op_type_check_arithmetic($1, $3); }
                | expression KW_IN expression  { $$ = in_type_check($1, $3); }

                | expression AND expression    { $$ = and_or_type_check($1, $3); $$->repr_cpp = $1->repr_cpp + " && " + $3->repr_cpp;}
                | expression OR expression     { $$ = and_or_type_check($1, $3); $$->repr_cpp = $1->repr_cpp + " || " + $3->repr_cpp;}
                | IDENT {
                    Var * vste = current_scope->lookup(*$1);
                    if(!vste) {
                        string err = "Variable " GREEN_ESCAPE + *$1 + RESET_ESCAPE " not found in current scope.";
                        yyerror(err.c_str());
                        $$ = NULL;
                        break;
                    }

                    $$ = new Expr(vste->type, true);
                    $$->repr_cpp = *$1;
                }
                | constant {
                    auto t = new Type();
                    VarTypes vt = convert_constType_to_varType($1.type);

                    if(vt == ENUM) {
                        t->push_type(vt, 0, 0, new Aux($1.var->este));
                    } else {
                        t->push_type(vt, 0, 0, NULL);
                    }
                    $$ = new Expr(t, false);
                    switch($1->type) {
                        case CT_CHAR:
                            $$->repr_cpp = "'" + string(1, $1->lit_char) + "'";
                            break;
                        case CT_FLOAT:
                            $$->repr_cpp = to_string($1->lit_float);
                            break;
                        case CT_INT:
                            $$->repr_cpp = to_string($1->lit_int);
                            break;
                        case CT_STR:
                            $$->repr_cpp = "\"" + *$1->lit_str + "\"";
                            break;
                        case CT_BOOL:
                            $$->repr_cpp = $1->bl ? "true" : "false";
                            break;
                        case CT_VAR:
                            $$->repr_cpp = $1->var->name; // CPP does not have ::
                            break;
                        default:
                            yyerror("Unknown constant type.");
                    }
                }
                | KW_THIS {
                    if(method_of) {
                        auto t = new Type();
                        t->push_type(STRUCT, 0, 0, new Aux(method_of));
                        $$ = new Expr(t, true);
                        $$->repr_cpp = "this";
                    } else {
                        yyerror(GREEN_ESCAPE "this" RESET_ESCAPE " can only be used in a struct method.");
                        $$ = NULL;
                    }
                }
                | unary_operation 
                | call 
                | array_decl // array value
                | cart_value // tuple value
                ; // semantic check: check if lvalue

cart_value      : '(' cart_value_list ')' {
                    Type * t = new Type();
                    auto arr = new vector<Type *>($2->size());
                    for(int i = 0; i < $2->size(); i++) {
                        (*arr)[i] = (*$2)[i];
                    }
                    t->push_type(CART, 0, arr->size(), new Aux(arr));
                    $$ = new Expr(t, false);
                    $$->repr_cpp = "{";
                    for(int i = 0; i < $2->size(); i++) {
                        if(i) $$->repr_cpp += ", ";
                        $$->repr_cpp += (*$2)[i]->repr_cpp;
                    }
                    $$->repr_cpp += "}";
                }
                ;

OPT_COMMA       : ','
                | epsilon
                ;

cart_value_list : expression ',' {
                    vector<Type *> *arr = new vector<Type *>();
                    arr->push_back($1);
                    $$ = arr;
                }
                | cart_value_list_ OPT_COMMA {
                    $$ = $1;
                }
                ;

cart_value_list_: cart_value_list_ ',' expression {
                    $$ = $1;
                    $$->push_back($3);
                }
                | expression ',' expression {
                    vector<Type *> *arr = new vector<Type *>();
                    arr->push_back($1);
                    arr->push_back($3);
                    $$ = arr;
                }
                ;

return_stmt     : KW_RETURN expression {
                    if(!current_func) {
                        yyerror("Returning outside function.");
                    } else if(!current_func->head) {
                        yyerror("Returning value from void function.");
                    }
                    else if(typecmp(current_func, $2)) {
                        yyerror("Type mismatch in return.");
                    }
                } // Check if compatible with current function return type.
                | KW_RETURN {
                    if(in_forg) {
                        break;
                    }
                    if(!current_func) {
                        yyerror("Returning outside function.");
                    } else if(current_func->head) {
                        yyerror("Returning void from non-void function.");
                    }
                }
                ;

call            : IDENT '(' opt_expr_list ')' {
                    Function * entry = func_st.lookup(*$1);
                    if(!entry) {
                        string err = "Function " GREEN_ESCAPE + *$1 + RESET_ESCAPE " not declared";
                        yyerror(err.c_str()); 
                        $$ = NULL;
                        break;
                    }
                    $$ = new Expr(entry->return_type, false);
                    if (entry->params->entries.size() != $3->size()) {
                        string err = "Expected " + to_string(entry->params->entries.size()) + " parameters, got " + to_string($3->size()) + ".";
                        yyerror(err.c_str());
                        break;
                    }
                    for(int i = 0; i < $3->size(); i++) {
                        if(typecmp((*$3)[i], entry->params->entries[i]->type)) {
                            string err = "Type mismatch on parameter " + to_string(i) + " of call to " + *$1 + ".";
                            yyerror(err.c_str());
                            break;
                        }
                    }
                    $$->repr_cpp = *$1 + "(";
                    for(int i = 0; i < $3->size(); i++) {
                        if(i) $$->repr_cpp += ", ";
                        $$->repr_cpp += (*$3)[i]->repr_cpp;
                    }
                    $$->repr_cpp += ")";
                }
                | expression '.' IDENT '(' opt_expr_list ')' {
                    if (!$1) {
                        $$ = NULL;
                        break;
                    }
                    if($1->core() != STRUCT) {
                        yyerror("Method call on non-struct type.");
                        $$ = NULL;
                        break;
                    }

                    auto sste = $1->head->sste;
                    Function * meth = sste->methods->lookup(*$3);
                    if(!meth) {
                        string err = "Method " GREEN_ESCAPE + *$3 + RESET_ESCAPE
                                     " not found on struct " GREEN_ESCAPE + sste->name + RESET_ESCAPE ".";
                        yyerror(err.c_str());
                        $$ = NULL;
                        break;
                    }
                    $$ = new Expr(meth->return_type, false);
                    for(int i = 0; i < $3->size(); i++) {
                        // Might be a better way than directly accessing the vector?
                        if(typecmp((*$5)[i], meth->params->entries[i]->type)) {
                            string err = "Type mismatch on parameter " + to_string(i) + " of call to " + *$3 + ".";
                            yyerror(err.c_str());
                            break;
                        }
                    }
                }// member functions 
                ;

opt_expr_list   : expr_list_
                | epsilon {
                    vector<Type *> *arr = new vector<Type *>();
                    $$ = arr;
                }
                ;

expr_list       : expr_list_ ','
                | expr_list_
                ;

expr_list_      : expr_list_ ',' expression {
                    $$ = $1;
                    $$->push_back($3); 
                }
                | expression {
                    vector<Type *> *arr = new vector<Type *>(1, $1);
                    $$ = arr;
                }
                ;

unary_op        : INCR
                | DECR
                ;

unary_operation : expression unary_op {
                    if (!$1) {
                        $$ = NULL;
                        break;
                    }
                    if (!$1->is_lvalue) {
                        yyerror("Unary operation on non-lvalue.");
                    } else if($1->core() != INT) {
                        yyerror("Unary operation on non-int type.");
                    }
                    $$ = new Expr($1, false);
                    $$->repr_cpp = $1->repr_cpp + ($2 == INCR ? "++" : "--");
                }
                ;

array_access    : expression array_index {
                    if (!$1) {
                        $$ = NULL;
                        break;
                    }
                    if($1->core() != BUF) {
                        // TODO: Vec/Mat/InvMat
                        yyerror("Array access on non-array type.");
                        $$ = NULL;
                        break;
                    }
                    if ($2 > 1) {
                        yyerror("Buf index must contain exactly one dimension.\n" BLUE_ESCAPE
                                "    Note" RESET_ESCAPE ": For `a: [[T]]`, use a[i][j] syntax.");
                        $$ = NULL;
                        break;
                    }
                    $$ = new Expr($1->pop_type(), $1->is_lvalue);
                    $$->repr_cpp = $1->repr_cpp + "[" + $2->repr_cpp + "]";
                }
                ;

array_decl      : '[' opt_expr_list ']' {
                    // All expressions should have the same type
                    Type * t = (*$2)[0];
                    for(int i = 1; i < $2->size(); i++) {
                        if(typecmp(t, (*$2)[i])) {
                            yyerror("Array elements must have the same type.");
                            $$ = NULL;
                            goto array_decl_break;
                        }
                    }
                    {
                        auto in = new Type();
                        in->head = t->head;
                        in->push_type(BUF, 0, 1, NULL);
                        $$ = new Expr(in, false);
                        $$->repr_cpp = "{";
                        for(int i = 0; i < $2->size(); i++) {
                            if(i) $$->repr_cpp += ", ";
                            $$->repr_cpp += (*$2)[i]->repr_cpp;
                        }
                        $$->repr_cpp += "}";
                    }
                array_decl_break:
                    break;
                }
                | '[' expression ';' expression ']' {
                    if(!$4 || !$2) {
                        $$ = NULL;
                        break;
                    }
                    if($4->core() != INT) {
                        yyerror("Array size must be an integer.");
                    }
                    auto t = new Type();
                    t->head = $2->head;
                    t->push_type(BUF, 0, 1, NULL);
                    $$ = new Expr(t, false);
                }
                ;

array_index     : '[' expr_list ']' // Access using commas, like a[1, 2] instead of a[1][2]. More mathy, more convenient.
                {
                    $$ = $2->size();
                    for(auto i: (*$2)) {
                        if(i->core() != INT) {
                            yyerror("Array index must be an integer.");
                            break;
                        }
                    }
                }
                | '[' expression SLICE expression ']' // subarray access 
                {
                    if(!$2 || !$4) {
                        $$ = 0;
                        break;
                    }
                    if($2->core() != INT || $4->core() != INT) {
                        yyerror("Slice operands must be integers.");
                    }
                    $$ = 1;
                }
                ;

conditional     : KW_IF '(' expression {
                    if(!$3) {
                        break;
                    }
                    if($3->core() != BOOL) yyerror("predicate must be boolean");
                } ')' {in_cond = 1;} if_body 
                ;

if_body         : body {in_cond = 0;}
                | body KW_ELSE conditional
                | body KW_ELSE body {in_cond = 0;}
                ;

loop_stmt       : KW_WHILE '(' loop_cond ')' {in_loop++;} body {in_loop--;}
                | KW_FOR '(' assignment ';' loop_cond ';' loop_mut ')' {in_loop++;} body {in_loop--;}
                | KW_FOR '(' start_table declaration ';' loop_cond ';' loop_mut ')' {in_loop++;} body {in_loop--;} end_table
                | KW_FOR start_table IDENT KW_IN expression {
                    if($5->core() != BUF){
                        yyerror("Looping over non-buf type.");
                        break;
                    }
                    Type * t = $5->pop_type();
                    current_scope->insert(new Var(*$3, t));

                } {in_loop++;} body {in_loop--;} end_table
                ;

loop_cond       : expression {
                    if(!$1) {
                        break;
                    }
                    if($1->core() != BOOL) 
                        yyerror("Loop condition has to be boolean.");

                    $$ = $1;
                }
                ;

loop_mut        : unary_operation
                | assignment
                | epsilon
                ;

switch_case     : KW_SWITCH '(' expression ')' start_block sc_blocks sc_default end_block {
                    if(!$3) break;
                    for(auto i: *$6) {
                        if(typecmp($3, i)) {
                            yyerror("Case type mismatch.");
                            break;
                        }
                    }
                }
                ;
sc_default      : KW_DEFAULT ARROW body
                | epsilon
                ;

sc_blocks       : sc_blocks KW_CASE expression ARROW body {
                    $$ = $1;
                    if(!$3) {
                        break;
                    }
                    $$->push_back($3);
                }
                | epsilon {
                    // $$ = new vector<Type *>();
                    vector<Type *> *arr = new vector<Type *>(0, NULL);
                    $$ = arr;
                }
                ; // NOTE: Does not cascade

claim_stub      : KW_CLAIM IDENT KW_IS archetype {
                    Struct * entry = struct_st.lookup(*$2);
                    if(!entry) {
                        Enum * entry = enum_st.lookup(*$2);
                        if(!entry) yyerror("No such type.");
                        else {
                            Type * t = new Type();
                            t->push_type(ENUM, 0, 1, new Aux(entry));
                            Claim * claim = claim_st.lookup(t, $4);
                            if(!claim) {$$ = new Claim(t, $4);} // Can copy Type, as InnerType is malloc'd.
                        }
                    } 
                    else {
                        Type * t = new Type();
                        t->push_type(STRUCT, 0, 1, new Aux(entry));
                        Claim * claim = claim_st.lookup(t, $4);
                        if(!claim) {$$ = new Claim(t, $4);}
                    }
                    
                }
                ; 

archetype_claim : claim_stub start_block type_def {
                    if(!$1) {
                        yyerror("Claim unsuccesful.");
                    }
                    else {
                        // We do not need a copy constructor. current_claim is malloc'd in claim_stub.
                        current_claim = $1;
                        if ($3 && $1->archetype != SPACE) {
                            yyerror("Cannot add inner types for flat archetypes.");
                        } else if (!$3 && $1->archetype == SPACE) {
                            yyerror("No inner types defined.");
                        } else if ($3 && $1->archetype == SPACE) {
                            current_claim->over = $3;
                        }

                        claim_st.insert(current_claim);
                    }
                } rule_list end_block {
                    current_claim = NULL;
                }
                | claim_stub KW_WITH '(' ident_list ')' ';' {
                    if(!$1) {
                        yyerror("Claim unsuccesful.");
                    }
                    else {
                        Function * entry1 = func_st.lookup((*$4)[0]);
                        Function * entry2 = func_st.lookup((*$4)[1]);
                        if(!entry1 || !entry2) yyerror("Function not found in symbol table.");
                        else {
                            if(typecmp(entry1->return_type, get_param_type(entry2)) || typecmp(entry2->return_type, get_param_type(entry1))) {
                                yyerror("Function types do not match (should be inverses)");
                                break;
                            }
                            if (typecmp(get_param_type(entry1), $1->type)) {
                                yyerror("Function type does not match claim type.");
                                break;
                            }
                            Type *other = entry2->return_type;
                            // check if other claims claim_stub->archetype
                            if(!claim_st.lookup(other, $1->archetype)) {
                                yyerror("Type being claimed via function does not claim archetype.");
                                break;
                            }
                            claim_st.insert($1);
                        }
                    }

                    current_claim = NULL;
                }
                ;

archetype       : KW_GROUP {$$ = GROUP;}
                | KW_RING {$$ = RING;}
                | KW_FIELD {$$ = FIELD;}
                | KW_SPACE {$$ = SPACE;}
                ;

type_def        : KW_FIELD '=' type ';' {
                    if(!claim_st.lookup($3, FIELD)) yyerror("Type is not a field.");
                    $$ = $3;
                }
                | epsilon {$$ = NULL;}
                ;

rule_list       : rule_list tbl_rule
                | tbl_rule
                ;

tbl_rule        : start_table rule end_table
                ;

rule            : additive_rule
                | mult_rule
                | identity_rule
                | negation_rule
                | inverse_rule
                ;

additive_rule   : '(' IDENT '=' IDENT '+' IDENT ')' {
                    if(current_claim->archetype != GROUP) {
                        yyerror("Additive rule must be in a group.");
                        break;
                    }
                    current_scope->insert(new Var(*$2, current_claim->type));
                    current_scope->insert(new Var(*$4, current_claim->type));
                    current_scope->insert(new Var(*$6, current_claim->type));
                } ARROW body
                ;

mult_rule       : '(' IDENT '=' IDENT '*' IDENT ')' {
                    if(current_claim->archetype == RING) {
                        current_scope->insert(new Var(*$2, current_claim->type));
                        current_scope->insert(new Var(*$4, current_claim->type));
                        current_scope->insert(new Var(*$6, current_claim->type));
                    } else if(current_claim->archetype == SPACE) {
                        Type * t = current_claim->type->pop_type();
                        current_scope->insert(new Var(*$2, current_claim->type));
                        current_scope->insert(new Var(*$4, t));
                        current_scope->insert(new Var(*$6, current_claim->type));
                    } else {
                        yyerror("Multiplicative rule must be in a ring or space.");
                    }
                    
                } ARROW body
                ;

identity_rule   : '(' IDENT '=' LIT_INT ')' {
                    current_scope->insert(new Var(*$2, current_claim->type));
                } ARROW body {
                    if(current_claim->archetype == GROUP) {
                        if($4 != 0) yyerror("Identity rule must be 0.");
                    }
                    else if(current_claim->archetype == RING) {
                        if($4 != 1) yyerror("Identity rule must be 1.");
                    }
                    else {
                        yyerror("Cannot have identity rule in field or space.");
                    }   
                }
                ; // We don't need the type of IDENT in semantic, we copy-paste into final code.

negation_rule   : '(' IDENT '=' '-' IDENT ')' {
                    if(current_claim->archetype != GROUP) {
                        yyerror("Negation rule must be in a group.");
                        break;
                    }
                    current_scope->insert(new Var(*$2, current_claim->type));
                    current_scope->insert(new Var(*$5, current_claim->type));
                } ARROW body
                ;

inverse_rule    : '(' IDENT '=' LIT_INT '/' IDENT ')' {
                    if(current_claim->archetype != FIELD) {
                        yyerror("Inverse rule must be in a field.");
                        break;
                    }
                    current_scope->insert(new Var(*$2, current_claim->type));
                    current_scope->insert(new Var(*$6, current_claim->type));
                } ARROW body {if($4 != 1) yyerror("Inverse rule must be 1/x");}
                ; // LIT_INT must be 1

function        : start_table function_header body end_table {method_of = NULL; current_func = NULL;}
                ;

fh_stub         : KW_FN IDENT '(' param_list ')' {
                    Function * entry = func_st.lookup(*$2);
                    if(entry) yyerror("Function already exists in symbol table.");
                    else {
                        VarSymbolTable * params = current_scope->vars;

                        Function * entry = new Function(*$2, params, NULL);
                        $$ = entry;
                    }
                }

                | KW_FN IDENT '.' IDENT '(' param_list ')' {
                    Struct * sste = struct_st.lookup(*$2);
                    if(!sste) yyerror("Struct not found.");
                    else {
                        VarSymbolTable * params = current_scope->vars;
                        method_of = sste;
                        Function * fste = new Function(*$4, params, NULL);
                        sste->methods->insert(fste);

                        $$ = fste;
                    }
                }
                ;

function_header :  fh_stub ':' type {
                    if($1) {
                        $1->return_type = $3;
                        func_st.insert($1);
                    }
                    current_func = $3;
                }
                | fh_stub {
                    if($1) func_st.insert($1);
                    current_func = new Type();
                    current_func->push_type(VOID, 0, 0, NULL);
                }
                ;

type_var_list   : type_var ',' type_var_list 
                | type_var 
                | epsilon 
                ;

param_list      : type_var_list 
                ;

struct          : KW_STRUCT IDENT start_block start_table attr_list end_table end_block {
                    Struct *sste = struct_st.lookup(*$2);
                    if(sste) {
                        yyerror("Existing struct with same name");
                        break;
                    }
                    Enum * este = enum_st.lookup(*$2);
                    if(este) {
                        yyerror("Existing enum with same name");
                        break;
                    }
                    Struct * entry = new Struct(*$2, $6->entries);
                    struct_st.insert(entry);
                }
                ;

attr_list       : type_var_list
                ;

enum            : KW_ENUM IDENT start_block variant_list end_block {
                    // if preexisting struct or enum, error
                    Struct *sste = struct_st.lookup(*$2);
                    if(sste) {
                        yyerror("Existing struct with same name");
                        break;
                    }
                    Enum * este = enum_st.lookup(*$2);
                    if(este) {
                        yyerror("Existing enum with same name");
                        break;
                    }
                    Enum * entry = new Enum(*$2, *$4);
                    enum_st.insert(entry);
                }
                ;

ident_list      : ident_list ',' IDENT {
                    $$ = $1;
                    $$->push_back(*$3);
                }
                | IDENT {
                    vector<string> *arr = new vector<string>(1, *$1);
                    $$ = arr;
                }
                | epsilon { 
                    vector<string> *arr = new vector<string>(0, string());
                    $$ = arr;
                }
                ;

variant_list    : ident_list
                ;

forge           : start_table KW_FORGE '(' param_list ')' KW_AS start_table '(' type_var ')' {
                    if (!$9) {
                        yyerror("Forge must have a return type.");
                        break;
                    }
                    VarSymbolTable * params = current_scope->parent->vars;
                    Function * entry = new Function("", params, $9->type);
                    forge_st.insert(entry);
                    in_forg = 1;
                } body end_table end_table {in_forg = 0;}
                ;

cart            : '(' type ',' ')' {
                    if(!$2) {
                        $$ = NULL;
                        break;
                    }
                    Type * t = new Type();
                    auto arr = new vector<Type *>(1, $2);
                    t->push_type(CART, 0, 1, new Aux(arr));
                    $$ = t;
                }
                | '(' type ',' type_list ')' {
                    if(!$2 || !$4) {
                        $$ = NULL;
                        break;
                    }
                    Type * t = new Type();
                    // vector<InnerType *> arr($4->size() + 1, NULL);
                    auto arr = new vector<Type *> ($4->size() + 1, NULL);
                    (*arr)[0] = $2;
                    for(int i = 1; i <= $4->size(); i++) {
                        (*arr)[i] = (*$4)[i - 1];
                    }
                    t->push_type(CART, 0, arr->size(), new Aux(arr));
                    $$ = t;
                }
                ;

type_list       : type_list ',' type {
                    $$ = $1;
                    $$->push_back($3);
                }
                | type {
                    vector<Type *> *arr = new vector<Type *>(1, $1);   
                    $$ = arr;
                }
                ;

epsilon         : ;

%%

bool error = false;

void gen_line(const char *s) {
    for (int i = 0; i < indent; i++) {
        fprintf(output_stream, "    ");
    }
    fprintf(output_stream, "%s\n", s);
}

void gen_line(string &s) {
    gen_line(s.c_str());
}

int main() {
    token_stream = fopen("code/seq_tokens.txt", "w");
    output_stream = fopen("a.cpp", "w");
    init_symbol_tables();
    yyparse();
    fclose(token_stream);
    fclose(output_stream);
    if (error) {
        // from stdio.h
        remove("a.cpp");
    }
    return error;
}

extern int yylineno;

void yyerror(const char* s) {
    const char *m = GREEN_ESCAPE "Error" RESET_ESCAPE " on line %3d: %s\n";
    fprintf(stderr, m, yylineno, s);
    error = true;
}
