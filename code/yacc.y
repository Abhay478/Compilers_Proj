%require "3.6"
%{
    #include <stdint.h>
    #include "../code/semantic.hpp"
    extern int yylex();
    void yyerror(const char* s);
    FILE * token_stream;
    FILE * output_stream;
    FILE * struct_stream;
    // flags
    int in_loop = 0; // loop depth counter, for break and continue
    int in_cond = 0; // flag, for if-else
    int in_forg = 0; // flag, for forge
    int in_rule = 0; // flag, for rule
    int forge_count = 0;  // For generating unique names for forges.
    Type * current_func = NULL;
    Scope * current_scope = NULL;
    Struct * method_of = NULL;
    Claim * current_claim = NULL;

    using namespace std;

    extern int yylineno;

    int indent = 0;
    void generate(string &s);
    void generate(const char *);
    void generateln(string &s);
    void generateln(const char *);

    Var * out;
    Scope * forge_scope = NULL;
    Scope * rule_scope = NULL;

%}
%code requires {
    #include "../code/semantic.hpp"
}
%union {
    std::string * repr;
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
    std::vector<Type *> * type_list;
    std::vector<CType> * sc_type_list;
    Expr * expr;
    std::vector<Expr *> * exp_list;
    Archetypes archetype; 
    Claim * claim_stub_type;
    VarSymbolTable * var_table;
    Var * var;
    std::vector<std::string> * ident_list_type;
    int count;
    struct {
        Function * entry; 
        std::string * repr;
    } func;
    GenericInner * targ;
    std::vector<GenericInner *> * targ_list;
    bool bl;
    struct {
        bool is_slice;
        union {
            std::string * repr;
            struct {
                std::string * start;
                std::string * end;
            } slice;
        };
    } acc;
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
%type <cons> case

%type <op> assign_op
%type <expr> expression
%type <expr> cart_value
%type <expr> array_decl
%type <expr> array_access
%type <expr> call
%type <expr> unary_operation
%type <expr> loop_cond
%type <expr> assignment


%type <exp_list> expr_list_
%type <exp_list> cart_value_list
%type <exp_list> cart_value_list_
%type <exp_list> opt_expr_list
%type <repr> type_var_list
%type <repr> type_var_list_
%type <repr> param_list
%type <repr> attr_list


%type <type> type
%type <type> cart
%type <type> generic
%type <type> type_def
%type <type_list> type_list
%type <sc_type_list> sc_blocks


%type <archetype> archetype

%type <claim_stub_type> claim_stub

%type <var> type_var
%type <var_table> end_table

%type <ident_list_type> ident_list
%type <ident_list_type> variant_list

%type <acc> array_index

%type <func> fh_stub

%type <targ> type_arg
%type <targ_list> type_args

%type <bl> unary_op

%start program

%%
program         :  start_table P end_table

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
                    // tree growth
                    Scope * new_scope = new Scope();
                    new_scope->parent = current_scope;
                    current_scope = new_scope;
                }
                ;

end_table       : epsilon {
                    // tree ascent
                    $$ = current_scope->vars;
                    current_scope = current_scope->parent;
                }

start_block     : '{' {
                    // indentation hack
                    generateln("{");
                    indent++;
                }

end_block       : '}' {
                    // indentation hack
                    indent--;
                    generateln("}");
                }

body            : start_block  {
                    // autogen declaration of out variable
                    if(current_scope == forge_scope || current_scope == rule_scope) {
                        string s = out->type->repr_cpp() + " " + out->repr_cpp() + ";";
                        generateln(s);
                    }
                } start_table statements end_table {
                    // autogen return statement
                    if(current_scope == forge_scope || current_scope == rule_scope) {
                        string s = "return " + out->repr_cpp() + ";";
                        generateln(s);
                    }
                } end_block
                ;

statements      : statement statements
                | epsilon
                ;

statement       : declaration ';'
                | assignment ';' { 
                    $1->repr += ';';
                    generateln($1->repr);
                }
                | unary_operation ';' {
                    $1->repr += ';';
                    generateln($1->repr);
                }
                | call ';' {
                    $1->repr += ';';
                    generateln($1->repr);
                }
                | return_stmt ';'
                | conditional
                | switch_case
                | loop_stmt // TODO: test loops
                | KW_BREAK ';' {
                    if (!in_loop)
                        yyerror("break statement outside of loop");
                    else generateln("break;");
                }
                | KW_CONTINUE ';' {
                    if (!in_loop)
                        yyerror("continue statement outside of loop");
                    else generateln("continue;");
                }
                | ';'
                ;

generic         : IDENT '<' type_args '>' {
                    Generic * gste = gen_st.lookup(*$1);
                    if(!gste) { // exists?
                        string err = "Generic type " GREEN_ESCAPE + *$1 + RESET_ESCAPE " not found.";
                        yyerror(err.c_str());
                        break;
                    }
                    if(!$3) { // ??
                        yyerror("Unknown compile error (allocation failed?)");
                        $$ = NULL;
                        break;
                    }
                    if(gste->types.size() != $3->size()) { // Cmp
                        yyerror("Generic type has wrong number of parameters.");
                        break;
                    }


                    // alloc
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

decl_list       : decl_item {generateln(";");}
                | decl_item {generateln(";");} ',' decl_list 
                ;

decl_item       : type_var {
                    if(!$1) {
                        break;
                    }

                    string repr_cpp = $1->type->repr_cpp() + " " + $1->repr_cpp();
                    generate(repr_cpp);
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

                    string repr_cpp = $1->type->repr_cpp() + " " + $1->repr_cpp() + " = " + $3->repr;
                    generate(repr_cpp);
                }
                ;

type_var        : IDENT ':' type {
                    auto newvar = new Var(*$1, $3);
                    if (current_scope->insert(newvar)) {
                        string err = "Variable " + *$1 + " already defined.";
                        yyerror(err.c_str());
                        $$ = NULL;
                    } else {
                        $$ = newvar;
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
                    $$->repr = $1->repr + " " + *$2 + " " + $3->repr;
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
                    if($$) $$->repr = "(" + $2->repr + ")";
                }
                | array_access // TODO: Test for multiple dimensions
                | '!' expression {
                    if (!$2) {
                        $$ = NULL;
                        break;
                    }
                    if($2->core() != BOOL){
                        yyerror("Can only negate bool expression!");
                    }
                    $$ = new Expr($2, false); // need new one coz different is_lvalue??
                    $$->repr = "!" + $2->repr;
                }
                | '-' expression                %prec '!'  // Unary minus has precedence of '!', not subtraction.
                {
                    if (!$2) {
                        $$ = NULL;
                        break;
                    }
                    $$ = new Expr($2, false);
                    $$->repr = "-" + $2->repr;
                    if($2->core() == INT || $2->core() == FLOAT) {
                        break;
                    }
                    Claim * cste = claim_st.lookup($2, GROUP);
                    if(!cste){
                        yyerror("unary minus requires Group");
                    }
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
                    $$->repr = "*" + $2->repr;
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
                    $$->repr = "&" + $2->repr;
                }
                | expression '.' IDENT { // TODO: Test.
                    if(!$1) {
                        $$ = NULL;
                        break;
                    }
                    InnerType * it = $1->head;
                    string refs = "";
                    while(it->core_type == REF) {
                        it = it->next;
                        refs += "*";
                    }
                    Type * t = new Type();
                    if (!t) {
                        $$ = NULL;
                        break;
                    }
                    t->head = it;
                    if (t->core() != STRUCT){
                        yyerror("Field access on non-struct type.");
                        $$ = NULL;
                    } else {
                        Struct * sste = t->head->sste;
                        Var *v = sste->fieldLookup(*($3));
                        if(!v){
                            yyerror("Field of struct doesn't exist");
                        }
                        $$ = new Expr(v->type, $1->is_lvalue);
                        $$->repr = "(" + refs + "(" + $1->repr + "))" + "." + *$3;
                    }
                } // struct access, lookup in table
                | expression '.' LIT_INT  // TODO: Test.
                {
                    if(!$1) {
                        $$ = NULL;
                        break;
                    }
                    InnerType * it = $1->head;
                    string refs = "";
                    while(it->core_type == REF) {
                        it = it->next;
                        refs += "*";
                    }
                    Type * t = new Type();
                    if (!t) {
                        $$ = NULL;
                        break;
                    }
                    t->head = it;
                    if(t->core() != CART) {
                        yyerror("Tuple access on non-tuple type.");
                    } 
                    else 
                    {
                        if($3 < 0 || $3 >= $1->head->size) {
                            yyerror("Tuple access out of bounds.");
                            break;
                        } else {
                            auto c = t->head->cart;
                            Type * inner = new Type();
                            inner->head = (*c)[$3]->head;
                            $$ = new Expr(inner, $1->is_lvalue);
                            $$->repr = "std::get<" + to_string($3) + ">(" + refs + "(" + $1->repr + "))";
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
                        // break;
                    }
                    else{
                        Type * t = fste->return_type;
                        $$ = new Expr(t, false);
                        $$->repr = fste->name + "(" + $1->repr + ")";
                    }
                }
                | expression '@' expression // claim space 
                {
                    if (!$1 || !$3) {
                        $$ = NULL;
                        break;
                    }
                    if($1->core() == GEN && $1->head->gste->name == "Vec") {
                        if(typecmp($1, $3)) {
                            yyerror("Type mismatch in vector dot product.");
                            break;
                        }
                        $$ = new Expr((*$1->head->types)[0]->type, false);
                    }
                }
                | expression '*' expression    { $$ = mult_type_check_arithmetic($1, $3); if($$) $$->repr = $1->repr + " * " + $3->repr; }
                | expression '/' expression    { $$ = div_type_check_arithmetic($1, $3); if($$) $$->repr = $1->repr + " * " + $3->repr + ".inv()"; }
                | expression '%' expression    { $$ = modulus_type_check_arithmetic($1, $3); if($$) $$->repr = $1->repr + " % " + $3->repr;}
                | expression '+' expression    { $$ = add_sub_type_check_arithmetic($1, $3); if($$) $$->repr = $1->repr + " + " + $3->repr;}
                | expression '-' expression    { $$ = add_sub_type_check_arithmetic($1, $3); if($$) $$->repr = $1->repr + " + -(" + $3->repr + ")";}
                | expression '>' expression    { $$ = cmp_op_type_check_arithmetic($1, $3); if($$) $$->repr = $1->repr + " > " + $3->repr;}
                | expression '<' expression    { $$ = cmp_op_type_check_arithmetic($1, $3); if($$) $$->repr = $1->repr + " < " + $3->repr;}
                | expression CMP_OP expression { $$ = cmp_op_type_check_arithmetic($1, $3); if($$) $$->repr = $1->repr + " " + *$2 + " " + $3->repr;}
                | expression EQ_OP expression  { $$ = eq_op_type_check_arithmetic($1, $3); if($$) $$->repr = $1->repr + " " + *$2 + " " + $3->repr;}
                | expression KW_IN expression  { 
                    $$ = in_type_check($1, $3); 
                    if($$) $$->repr = "(std::find(" + $3->repr + ".begin(), " + $3->repr + ".end(), " + $1->repr + ") != " + $3->repr + ".end())";
                }
                | expression AND expression    { $$ = and_or_type_check($1, $3); if($$) $$->repr = $1->repr + " && " + $3->repr;}
                | expression OR expression     { $$ = and_or_type_check($1, $3); if($$) $$->repr = $1->repr + " || " + $3->repr;}
                | IDENT {
                    Var * vste = current_scope->lookup(*$1);
                    if(!vste) {
                        string err = "Variable " GREEN_ESCAPE + *$1 + RESET_ESCAPE " not found in current scope.";
                        yyerror(err.c_str());
                        $$ = NULL;
                        break;
                    }

                    $$ = new Expr(vste->type, true);
                    $$->repr = vste->repr_cpp();
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
                    switch($1.type) {
                        case CT_CHAR:
                            $$->repr = string(1, $1.lit_char);
                            break;
                        case CT_FLOAT:
                            $$->repr = to_string($1.lit_float);
                            break;
                        case CT_INT:
                            $$->repr = to_string($1.lit_int);
                            break;
                        case CT_STR:
                            $$->repr = *$1.lit_str;
                            break;
                        case CT_BOOL:
                            $$->repr = $1.bl ? "true" : "false";
                            break;
                        case CT_VAR:
                            $$->repr = $1.var->tag + "::" + $1.var->val; // CPP does not have ::
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
                        $$->repr = "this";
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
                    $$->repr = "{";
                    for(int i = 0; i < $2->size(); i++) {
                        if(i) $$->repr += ", ";
                        $$->repr += (*$2)[i]->repr;
                    }
                    $$->repr += "}";
                }
                ;

OPT_COMMA       : ','
                | epsilon
                ;

cart_value_list : expression ',' {
                    vector<Expr *> *arr = new vector<Expr *>();
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
                    vector<Expr *> *arr = new vector<Expr *>();
                    arr->push_back($1);
                    arr->push_back($3);
                    $$ = arr;
                }
                ;

return_stmt     : KW_RETURN expression {
                    if(in_forg || in_rule) {
                        yyerror("Cannot return expression from forges or rules.");
                        break;
                    }
                    if(!current_func) {
                        yyerror("Returning outside function.");
                    } else if(current_func->core() == VOID) {
                        yyerror("Returning value from void function.");
                    }
                    else if(typecmp(current_func, $2)) {
                        yyerror("Type mismatch in return.");
                    }

                    string gen = "return " + $2->repr + ";";
                    generateln(gen);
                } // Check if compatible with current function return type.
                | KW_RETURN {
                    if(in_forg || in_rule) {
                        string s = "return " + out->repr_cpp() + ";";
                        generateln(s);
                        break;
                    }
                    if(!current_func) {
                        yyerror("Returning outside function.");
                    } else if(current_func->core() != VOID) {
                        yyerror("Returning void from non-void function.");
                    }
                    generateln("return;");
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
                    if (entry->params->entries.size() != $3->size()) { // TODO: Test for providing args to a function that shouldn't take them.
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
                    $$->repr = "f_" + *$1 + "(";
                    for(int i = 0; i < $3->size(); i++) {
                        if(i) $$->repr += ", ";
                        $$->repr += (*$3)[i]->repr;
                    }
                    $$->repr += ")";
                }
                | expression '.' IDENT '(' opt_expr_list ')' {
                    if(!$1) {
                        $$ = NULL;
                        break;
                    }
                    InnerType * it = $1->head;
                    string refs = "";
                    while(it->core_type == REF) {
                        it = it->next;
                        refs += "*";
                    }
                    Type * t = new Type();
                    if (!t) {
                        $$ = NULL;
                        break;
                    }
                    t->head = it;
                    if(t->core() != STRUCT) {
                        yyerror("Method call on non-struct type.");
                        $$ = NULL;
                        break;
                    }

                    auto sste = t->head->sste;
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
                    $$->repr = "(" + refs + "(" + $1->repr + "))" + ".m_" + *$3 + "(";
                    for(int i = 0; i < $5->size(); i++) {
                        if(i) $$->repr += ", ";
                        $$->repr += (*$5)[i]->repr;
                    }
                    $$->repr += ")";
                } // member functions 
                ;

opt_expr_list   : expr_list_
                | epsilon {
                    vector<Expr *> *arr = new vector<Expr *>();
                    $$ = arr;
                }
                ;

expr_list_      : expr_list_ ',' expression {
                    $$ = $1;
                    $$->push_back($3); 
                }
                | expression {
                    vector<Expr *> *arr = new vector<Expr *>(1, $1);
                    $$ = arr;
                }
                ;

unary_op        : INCR {$$ = true;}
                | DECR {$$ = false;}
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
                    $$->repr = $1->repr + ($2 ? "++" : "--");
                }
                ;

array_access    : expression array_index {
                    if (!$1) {
                        $$ = NULL;
                        break;
                    }
                    if($1->core() == BUF) {
                        // TODO: Vec/Mat/InvMat
                        // TODO: Test for slices.
                        
                        if(!$2.is_slice) {
                            $$ = new Expr($1->pop_type(), $1->is_lvalue);
                            $$->repr = $1->repr + *$2.repr;
                        }
                        else {
                            $$ = new Expr($1->pop_type(), $1->is_lvalue);
                            $$->repr = "slice(" + $1->repr + ", " + *$2.slice.start + ", " + *$2.slice.end + ")";
                        }
                    }
                    else if ($1->core() == STR) {
                        if(!$2.is_slice) {
                            $$ = new Expr($1->pop_type(), $1->is_lvalue);
                            $$->repr = $1->repr + *$2.repr;
                        }
                        else {
                            $$ = new Expr($1->pop_type(), $1->is_lvalue);
                            $$->repr = "slice_str(" + $1->repr + ", " + *$2.slice.start + ", " + *$2.slice.end + ")";
                        }
                    } 
                    else {
                        yyerror("Array access on non-array type.");
                        $$ = NULL;
                        break;
                    }
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
                        $$->repr = "{";
                        for(int i = 0; i < $2->size(); i++) {
                            if(i) $$->repr += ", ";
                            $$->repr += (*$2)[i]->repr;
                        }
                        $$->repr += "}";
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

array_index     : '[' expression ']' {
                    if($2->core() != INT) {
                        yyerror("Array index must be an integer.");
                        break;
                    }
                    $$.is_slice = false;
                    $$.repr = new string("[" + $2->repr + "]");

                }
                | '[' expression SLICE expression ']' // subarray access 
                {
                    if(!$2 || !$4) {
                        break;
                    }
                    if($2->core() != INT || $4->core() != INT) {
                        yyerror("Slice operands must be integers.");
                    }
                    $$.is_slice = true;
                    $$.slice.start = &$2->repr;
                    $$.slice.end = &$4->repr;
                }
                ;

conditional     : KW_IF '(' expression ')' {
                    if(!$3) {
                        break;
                    }
                    if($3->core() != BOOL) yyerror("predicate must be boolean");

                    string gen = "if (" + $3->repr + ") ";
                    generate(gen);
                    in_cond = 1;
                } if_body 
                ;

if_body         : body {in_cond = 0;}
                | body KW_ELSE { generate("else "); } conditional
                | body KW_ELSE { generate("else "); } body {in_cond = 0;}
                ;

loop_stmt       : KW_WHILE '(' loop_cond ')' {
                    in_loop++;
                    if(!$3) {
                        break;
                    }
                    string gen = "while (" + $3->repr + ")";
                    generateln(gen);
                } body {in_loop--;}
                | KW_FOR '(' {generate("for (");} 
                    assignment {generate($4->repr);} ';' {generate("; ");} 
                    loop_cond {generate($8->repr);} ';' {generate("; ");} 
                    loop_mut ')' {in_loop++; generate(") ");} 
                    body {in_loop--;}
                | KW_FOR '(' {generate("for (");} 
                    start_table KW_LET decl_item {generate("; ");} ';' 
                    loop_cond {generate($9->repr);} ';' {generate("; ");} 
                    loop_mut ')' {in_loop++; generate(") ");} 
                    body {in_loop--;} end_table
                | KW_FOR {generate("for auto ");} start_table IDENT {generate(*$4);} KW_IN {generate(" in ");} expression {
                    if($8->core() != BUF){
                        yyerror("Looping over non-buf type.");
                        break;
                    }
                    Type * t = $8->pop_type();
                    current_scope->insert(new Var(*$4, t));

                    generate($8->repr);

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

loop_mut        : unary_operation {generate($1->repr);}
                | assignment {generate($1->repr);}
                | epsilon {generate(" ");}
                ;

switch_case     : KW_SWITCH '(' {generate("switch( ");} expression {
                    if(!$4) break;
                    generate($4->repr);
                    // expression type must be int char or enum
                    int type = $4->core();
                    if(!(type == INT || type == FLOAT || type == ENUM)){
                        yyerror("Switch argument can have integers, characters or enum variants only.");
                    }
                } ')' {generate(" )");} start_block sc_blocks sc_default end_block {
                    if(!$4) {break;}
                    int exp_type = $4->core();
                    for(CType i: *$9) {
                        if((i != CT_INT && exp_type == INT) || (i != CT_CHAR && exp_type == CHAR) || (i != CT_VAR && exp_type == ENUM)) {
                            yyerror("Case type mismatch.");
                            break;
                        }
                    }
                }
                // DO NOT move the header into a separate non-terminal. Weird segfaults.
                ;
sc_default      : KW_DEFAULT ARROW {generate("default: ");} body {generateln("break;");}
                | epsilon
                ;
case            : KW_CASE constant ARROW {
                    string gen = "case ";
                    if($2.type == CT_INT){
                        gen += to_string($2.lit_int);
                    }
                    else if($2.type == CT_CHAR){
                        gen += $2.lit_char;
                    }
                    else if($2.type == CT_VAR){
                        gen += $2.var->tag + "::" + $2.var->val;
                    }
                    else{
                        yyerror("Case argument can only be an integer, character or Enum variant.");
                        break;
                    }
                    gen += ": ";
                    generate(gen);
                } body {$$ = $2; generateln("break;");}
                ;

sc_blocks       : sc_blocks case {
                    $$ = $1;
                    $$->push_back($2.type);
                }
                | case {
                    $$ = new vector<CType>(1, $1.type); 
                }
                ; // NOTE: Does not cascade

claim_stub      : KW_CLAIM IDENT KW_IS archetype {
                    Struct * entry = struct_st.lookup(*$2);
                    if(!entry) {
                        Enum * entry = enum_st.lookup(*$2);
                        if(!entry) {
                            yyerror("No such type.");
                            $$ = NULL;
                            break;
                        }
                        int cl = entry->add_claim($4);
                        if(cl == 1) {
                            yyerror("Claim already exists.");
                            $$ = NULL;
                            break;
                        } else if (cl == -1) {
                            yyerror("Claim dependencies missing.");
                            $$ = NULL;
                            break;
                        }

                        Type * t = new Type();
                        t->push_type(ENUM, 0, 1, new Aux(entry));
                        Claim * claim = claim_st.lookup(t, $4);
                        if(!claim) {
                            $$ = new Claim(t, $4); // Can copy Type, as InnerType is malloc'd.
                        } else {
                            $$ = NULL;
                        }
                    } 
                    else {
                        if(entry->add_claim($4)) {
                            yyerror("Claim already exists.");
                            $$ = NULL;
                            break;
                        }
                        Type * t = new Type();
                        t->push_type(STRUCT, 0, 1, new Aux(entry));
                        Claim * claim = claim_st.lookup(t, $4);
                        if(!claim) {$$ = new Claim(t, $4);}
                        else {$$ = NULL;}
                    }   
                }
                ; 

archetype_claim : claim_stub '{' type_def {
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
                } rule_list '}' {
                    current_claim = NULL;
                }
                | claim_stub KW_WITH '(' ident_list ')' ';' {
                    if(!$1) {
                        yyerror("Claim unsuccesful.");
                    }
                    else {
                        Function * entry1 = func_st.lookup((*$4)[0]); // This returns what we're claiming
                        Function * entry2 = func_st.lookup((*$4)[1]); // This returns what's already claimed, accepts what we're claaiming

                        if(!entry1 || !entry2) {
                            yyerror("Function not found in symbol table.");
                            break;
                        }
                        if(typecmp(entry1->return_type, get_param_type(entry2)) || typecmp(entry2->return_type, get_param_type(entry1))) {
                            yyerror("Function types do not match (should be inverses)");
                            break;
                        }
                        if (typecmp(get_param_type(entry2), $1->type)) {
                            yyerror("Function type does not match claim type.");
                            break;
                        }
                        Type *other = entry2->return_type;
                        // check if other claims claim_stub->archetype
                        if(!claim_st.lookup(other, $1->archetype)) {
                            yyerror("Type being claimed via function does not claim archetype.");
                            break;
                        }
                        current_claim = $1;
                        claim_st.insert($1);

                        switch($1->archetype) {
                            case GROUP: {
                                auto v1 = add_gen("_sum", "_op1", "_op2");
                                generateln("{"); indent++;
                                string s = v1[0]->repr_cpp() + " = " + entry1->repr_cpp() + "(" + entry2->repr_cpp() + "(" + v1[1]->repr_cpp() + ") + " + entry2->repr_cpp() + "(" + v1[2]->repr_cpp() + "));";
                                generateln(s);
                                s = "return " + v1[0]->repr_cpp() + ";";
                                generateln(s);
                                indent--;
                                generateln("}");

                                auto v2 = neg_gen("_neg", "_op");
                                generateln("{"); indent++;
                                s = v2[0]->repr_cpp() + " = " + entry2->repr_cpp() + "(-" + entry1->repr_cpp() + "(" + v2[1]->repr_cpp() + "));";   
                                generateln(s);
                                s = "return " + v2[0]->repr_cpp() + ";";
                                generateln(s);
                                indent--;
                                generateln("}");

                                auto v3 = id_gen("_id", 0);
                                generateln("{"); indent++;
                                s = v3->repr_cpp() + " = " + entry1->repr_cpp() + "(0)" + ";";
                                generateln(s);
                                s = "return " + v3->repr_cpp() + ";";
                                generateln(s);
                                indent--;
                                generateln("}");

                                break;
                            }
                            case RING: {
                                auto v4 = mult_gen("_prod", "_op1", "_op2");
                                generateln("{"); indent++;
                                string s = v4[0]->repr_cpp() + " = " + entry1->repr_cpp() + "(" + entry2->repr_cpp() + "(" + v4[1]->repr_cpp() + ") * " + entry2->repr_cpp() + "(" + v4[2]->repr_cpp() + "));";
                                generateln(s);
                                s = "return " + v4[0]->repr_cpp() + ";";
                                generateln(s);
                                indent--;
                                generateln("}");

                                auto v5 = id_gen("_id", 1);
                                generateln("{"); indent++;
                                s = v5->repr_cpp() + " = " + entry1->repr_cpp() + "(1)" + ";";
                                generateln(s);
                                s = "return " + v5->repr_cpp() + ";";
                                generateln(s);
                                indent--;
                                generateln("}");

                                break;
                            }
                            case FIELD: {
                                auto v6 = inv_gen("_inv", "_op");
                                generateln("{"); indent++;
                                string s = v6[0]->repr_cpp() + " = " + entry1->repr_cpp() + "(" + entry2->return_type->repr_cpp() + "::inv(" + entry2->repr_cpp() + "(" + v6[1]->repr_cpp() + ")));";
                                generateln(s);
                                s = "return " + v6[0]->repr_cpp() + ";";
                                generateln(s);
                                indent--;
                                generateln("}");

                                break;
                            }
                            case SPACE: {
                                auto v7 = mult_gen("_prod", "_op1", "_op2");
                                generateln("{"); indent++;
                                string s = v7[0]->repr_cpp() + " = " + entry1->repr_cpp() + "(" + entry2->repr_cpp() + "(" + v7[1]->repr_cpp() + ") * " + entry2->repr_cpp() + "(" + v7[2]->repr_cpp() + "));";
                                generateln(s);
                                s = "return " + v7[0]->repr_cpp() + ";";
                                generateln(s);
                                indent--;
                                generateln("}");
                                break;
                            }
                            default:
                                break;
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

tbl_rule        : start_table {in_rule=1;} rule {in_rule=0;} end_table
                ;

rule            : additive_rule 
                | mult_rule
                | identity_rule
                | negation_rule
                | inverse_rule
                ;

additive_rule   : '(' IDENT '=' IDENT '+' IDENT ')' {
                    if(add_gen(*$2, *$4, *$6).empty()) {
                        yyerror("Additive rule must be in a group.");
                    }
                } ARROW body {
                    rule_scope = NULL;
                    generateln("");
                    out = NULL;
                }
                ;

mult_rule       : '(' IDENT '=' IDENT '*' IDENT ')' {
                    if(mult_gen(*$2, *$4, *$6).empty()) {
                        yyerror("Multiplicative rule must be in a ring or space.");
                    }
                    
                } ARROW body {
                    rule_scope = NULL;
                    generateln("");
                    out = NULL;
                }
                ;

identity_rule   : '(' IDENT '=' LIT_INT ')' {
                    if(id_gen(*$2, $4)) break;
                    switch(current_claim->archetype) {
                        case GROUP:
                            yyerror("Identity must be 0.");
                            printf("%d\n", $4);
                            break;
                        case RING:
                            yyerror("Identity must be 1.");
                            break;
                        case FIELD: case SPACE:
                            yyerror("Identity rule must be in a group or ring.");
                            break;
                        default:
                            break;
                    }

                } ARROW body {
                    rule_scope = NULL;
                    generateln("");
                    out = NULL;
                }
                ; // We don't need the type of IDENT in semantic, we copy-paste into final code.

negation_rule   : '(' IDENT '=' '-' IDENT ')' {
                    if(neg_gen(*$2, *$5).empty()) {
                        yyerror("Negation rule must be in a group.");
                    }
                } ARROW body {
                    rule_scope = NULL;
                    generateln("");
                    out = NULL;
                }
                ;

inverse_rule    : '(' IDENT '=' LIT_INT '/' IDENT ')' {
                    if(inv_gen(*$2, *$6).empty()) {
                        yyerror("Inverse rule must be in a field.");
                    }
                } ARROW body {
                    rule_scope = NULL;
                    generateln("");
                }
                ; // LIT_INT must be 1

function        : start_table function_header body end_table {method_of = NULL; current_func = NULL; generateln("");}
                ;

fh_stub         : KW_FN IDENT '(' param_list ')' {
                    Function * entry = func_st.lookup(*$2);
                    if(entry) yyerror("Function already exists in symbol table.");
                    else {
                        VarSymbolTable * params = current_scope->vars;

                        Function * entry = new Function(*$2, params, NULL);
                        $$.entry = entry;
                        $$.repr = new string((*$2 != "main" ? "f_" : "") + *$2 + "(" + ($4 ? *$4 : "") + ") ");
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

                        $$.entry = fste;
                        $$.repr = new string(*$2 + "::m_" + *$4 + "(" + *$6 + ") ");
                    }
                }
                ;

function_header :  fh_stub ':' type {
                    if($1.entry) {
                        $1.entry->return_type = $3;
                        func_st.insert($1.entry);
                        string header = $3->repr_cpp() + " " + *($1.repr);
                        generate(header);
                        // We ain't putting this stuff 
                    }
                    current_func = $3;
                }
                | fh_stub {
                    if($1.entry) {
                        func_st.insert($1.entry);
                        string header = "void " + *($1.repr);
                        generate(header);
                    }
                    current_func = new Type();
                    current_func->push_type(VOID, 0, 0, NULL);
                }
                ;

type_var_list   : type_var_list_
                | epsilon {$$ = NULL;}
                ;

type_var_list_ : type_var_list_ ',' type_var {
                    $$ = $1;
                    *$$ += "; " + $3->type->repr_cpp() + " " + $3->repr_cpp();
                }
                | type_var {
                    $$ = new string($1->type->repr_cpp() + " " + $1->repr_cpp());
                }
                ;            

param_list      : type_var_list {
                    $$ = $1;
                    if(!$$) break;
                    replace($$->begin(), $$->end(), ';', ',');
                    // generateln(*$$);
                }
                ;

struct          : KW_STRUCT IDENT '{' start_table attr_list end_table '}' {
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

attr_list       : type_var_list {
                    $$ = $1;
                    if($$) {
                        *$$ += ";"; 
                        // generateln(*$$);
                    }
                }
                ;

enum            : KW_ENUM IDENT '{' variant_list '}' {
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

forge           : start_table KW_FORGE '(' type_var ')' KW_AS start_table '(' type_var ')' {
                    if (!$9) {
                        yyerror("Forge must have a return type.");
                        break;
                    }
                    VarSymbolTable * params = current_scope->parent->vars;
                    Function * entry = new Function("forge_" + to_string(forge_count), params, $9->type);
                    forge_st.insert(entry);
                    in_forg = 1;

                    string header = $9->type->repr_cpp() + " forge_" + to_string(forge_count) + "(" + $4->type->repr_cpp() + " " + $4->repr_cpp() + ") ";
                    generate(header);

                    forge_count++;
                    out = $9;
                    forge_scope = current_scope;

                } body end_table end_table {in_forg = 0; out = NULL; forge_scope = NULL; generateln("");}
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

int main() {
    token_stream = fopen("code/seq_tokens.txt", "w");
    output_stream = fopen("a.cpp", "w");
    struct_stream = fopen("a.hpp", "w");
    init_symbol_tables();

    // headers
    generateln_h("#include<bits/stdc++.h>");
    generateln_h("#include \"std/forges.hpp\"");
    generateln_h("using namespace std;\n");
    generateln("#include \"a.hpp\"\n");

    yyparse();

    generate_structs();
    generate_enums();

    fclose(token_stream);
    fclose(output_stream);
    fclose(struct_stream);

    if (error) {
        // if error, generated files are useless, so remove them
        // but for now, keeping them for debugging
        // TODO: uncomment this once complete
        // remove("a.cpp");
        // remove("a.hpp");
    }
    return error;
}

extern int yylineno;

void yyerror(const char* s) {
    const char *m = GREEN_ESCAPE "Error" RESET_ESCAPE " on line %3d: %s\n";
    fprintf(stderr, m, yylineno, s);
    error = true;
}
