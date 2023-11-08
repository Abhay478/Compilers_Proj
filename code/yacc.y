/* %language "C++" */
%{
    #include "semantic.hpp"
    extern int yylex();
    void yyerror(const char* s);
    FILE * token_stream;
    // flags
    int in_func = 0;
    int in_loop = 0;
    int in_cond = 0;
    int tdef = 0;

    using namespace std;

    extern Type * int_float_check(Type * t1, Type * t2);
    extern Type * forge_check(Type * t1, Type * t2);
    extern Type * mult_type_check_arithmetic(Type *t1, Type *t2);
    extern Type * div_type_check_arithmetic(Type *t1, Type *t2);
    extern Type * modulus_relational_type_check_arithmetic(Type *t1, Type *t2);
    extern Type * add_sub_type_check_arithmetic(Type *t1, Type *t2);
    extern Type * and_or_type_check(Type *t1, Type *t2);
    extern VarTypes convert_constType_to_varType(CType t);
%}
%code requires {
    // #include "semantic.h"
    #include "semantic.hpp"
}
%union {
    std::string * ident;
    int lit_int;
    float lit_float;
    std::string * lit_str;
    char lit_char;
    PDT prim_type;
    struct {
        void * val;
        CType type;
    } cons;
    Type * type;
    Archetypes archetype; 
    struct {
        Archetypes archetype;
        Type * type;
    } claim_stub_type;

    std::deque<Var *> * var_list;
    Var * var;
    // std::string * eh;
    std::deque<std::string> * ident_list_type;
    std::deque<Type *> * type_list;
    int count;
    FunctionSymbolTableEntry * func;
    GenericInner * targ;
    std::deque<GenericInner *> * targ_list;
}

// keywords
%token KW_CLAIM KW_IS KW_GROUP KW_RING KW_FIELD KW_SPACE KW_LET KW_RETURN KW_IF KW_ELSE KW_WHILE KW_FOR KW_IN KW_SWITCH KW_CASE KW_DEFAULT KW_BREAK KW_CONTINUE KW_FN KW_FORGE KW_AS KW_STRUCT KW_ENUM KW_WITH

// Types
%token <ident> IDENT 
%token <prim_type> PRIMITIVE_DTYPE 
%token <lit_int> LIT_INT 
%token <lit_float> LIT_FLOAT 
%token <lit_str> LIT_STR 
%token <lit_char> LIT_CHAR 

%token rel_op KW_TRUE KW_FALSE ASSIGN_OP

%token INCR DECR ARROW VARIANT SLICE AND OR // Two character operators.

%left '.'
%left '[' '('
%left INCR DECR
%right '!' // Also unary minus, ref, and deref - see `expression` definition.
%left KW_AS 
%left '@'
%left '*' '/' '%' 
%left '+' '-' 
%left rel_op '>' '<'
%left KW_IN
%left AND
%left OR

%type <cons> constant

%type <lit_int> identity_rule

%type <type> expression
%type <type> loop_cond
%type <type> type
%type <type> array_decl
%type <type> cart
%type <type> cart_value
%type <type> array_access
%type <type> call
%type <type> unary_operation
%type <type_list> type_list
%type <type_list> expr_list
%type <type_list> cart_value_list
%type <type_list> sc_blocks

%type <archetype> archetype

%type <claim_stub_type> claim_stub

%type <var> type_var
%type <var> decl_item
%type <var_list> attr_list
%type <var_list> decl_list
%type <var_list> declaration
%type <var_list> type_var_list
%type <var_list> param_list

%type <ident_list_type> ident_list
%type <ident_list_type> variant_list

%type <count> array_index

%type <func> fh_stub

%type <targ> type_arg
%type <targ_list> type_args

%start P

%%
P               : declarations // globals
                | P function
                | P struct
                | P forge
                | P enum
                | P archetype_claim
                ;

declarations    : declaration ';' declarations
                | epsilon
                ;

body            : '{' statements '}'
                ;

statements      : statement statements
                | epsilon
                ;

statement       : declaration ';'
                | assignment ';'
                | unary_operation ';'
                | call ';' // check if exists.
                | return_stmt {if(!in_func) yyerror("Returning outside function.");}';' 
                | conditional
                | switch_case
                | loop_stmt
                | KW_BREAK ';' {if(!in_loop) yyerror("break statement outside of loop");}
                | KW_CONTINUE ';' {if(!in_loop) yyerror("continue statement outside of loop");}
                | ';'
                ;

generic         : IDENT '<' type_args '>' // someone write a list of allowed generics.
                ;

type_args       : type_args ',' type_arg {
                    $$ = $1;
                    $$->push_back($3);
                }
                | type_arg {
                    deque<GenericInner *> arr(1, $1);
                    $$ = &arr;
                }
                | epsilon { 
                    deque<GenericInner *> arr(0, NULL);
                    $$ = &arr;
                }
                ;

type_arg        : type {
                    $$ = new GenericInner((void *)$1, 0);
                }
                | LIT_INT {
                    $$ = new GenericInner((void *)$1, 1);
                }
                ;

declaration     : KW_LET decl_list {
                    $$ = $2;
                }
                ;

decl_list       : decl_item {
                    deque<Var *> arr(1, $1);
                    $$ = &arr;
                }
                | decl_item ',' decl_list {
                    $$ = $3;
                    $$->push_front($1);
                }
                ;

decl_item       : type_var {
                    $$ = $1;
                    // That's it, right?
                }
                | type_var '=' expression {
                    if(typecmp($1->type, $3)) {
                        yyerror("Type mismatch in declaration.");
                    }

                    $$ = $1;
                }// check whether lval and rval have same type.
                ;

type            : PRIMITIVE_DTYPE {
                    Type * t = new Type(); 
                    t->push_type(get_vt($1), 0, 0, NULL);
                    $$ = t;

                }
                | '[' type ']' {
                    Type * t = new Type();
                    t->head = $2->head;
                    t->push_type(BUF, 0, 1, NULL);
                    $$ = t;
                }
                | IDENT {
                    // struct lookup
                    StructSymbolTableEntry * entry = struct_st.lookup(*$1);
                    if(!entry) {
                        // enum lookup
                        EnumSymbolTableEntry * entry = enum_st.lookup(*$1);
                        if(!entry) yyerror("No such type.");
                        else {
                            Type * t = new Type();
                            t->push_type(ENUM, 0, 1, new AuxESTE(entry)); // aux is the symbol table entry.
                            $$ = t;
                        }
                    }
                    else {
                        Type * t = new Type();

                        t->push_type(STRUCT, 0, 1, new AuxSSTE(entry)); // aux is the symbol table entry.
                        $$ = t;
                    }
                }
                | generic 
                | '&' type {
                    Type * t = new Type();
                    t->head = $2->head; // Reference to this.
                    t->push_type(REF, 0, 1, NULL); // Push the reference.
                    $$ = t;
                }
                | cart 
                ; 

assign_op       : ASSIGN_OP
                | '='
                ;

assignment      : expression assign_op expression // first expression must be an lvalue
                ;

constant        : LIT_CHAR {$$.val = (void *)$1; $$.type = CT_CHAR;}
                | LIT_FLOAT {$$.val = (void *)*(int *)(float *)&$1; $$.type = CT_FLOAT;}
                | LIT_INT {$$.val = (void *)$1; $$.type = CT_INT;}
                | LIT_STR {$$.val = (void *)$1; $$.type = CT_STR;}
                | KW_TRUE {$$.val = (void *)1; $$.type = CT_BOOL;}
                | KW_FALSE {$$.val = (void *)0; $$.type = CT_BOOL;}
                | IDENT VARIANT IDENT  {
                    $$.val = 0;
                    EnumSymbolTableEntry * entry = enum_st.lookup(*$1);
                    if(!entry) yyerror("Enum not found in symbol table.");
                    else {
                        for(auto i: entry->fields) {
                            if(i == *$3) {
                                Variant * var = new Variant(*$1, *$3, entry);
                                $$.val = var;
                                $$.type = CT_VAR; 
                                break;
                            }
                        }
                        if(!$$.val) yyerror("Variant not found in enum.");
                    }
                } 
                ;

expression      : '(' expression ')' {
                    $$ = $2;
                }
                | array_access
                | '!' expression {
                    Type *t = $2;
                    if(t->core() != BOOL){
                        yyerror("Can only negate bool expression!");
                    }
                    $$ = $2;
                }
                | '-' expression                %prec '!'  // Unary minus has precedence of '!', not subtraction.
                {
                    ClaimSymbolTableEntry *cste = claim_st.lookup($2, GROUP);
                    if(!cste){
                        yyerror("unary minus requires Group");
                    }
                    $$ = $2;
                }
                | '*' expression                %prec '!'  // Dereference has precedence of '!', not multiplication.   
                {
                    if($2->core() != REF){
                        yyerror("Must be reference");
                    }
                    $$ = $2->pop_type();
                }
                | '&' expression                %prec '!'  // Address-of has precedence of '!', bitwise operators do not exist.
                {
                    $$ = new Type();
                    $$->head = $2->head;
                    $$->push_type(REF, 0, 0, NULL);
                }
                | expression '.' IDENT // struct access, lookup in table
                {
                    if($1->core() != STRUCT){
                        yyerror("Must be struct");
                    }
                    else{
                        StructSymbolTableEntry * sste = ((AuxSSTE *)$1->head->aux)->sste;
                        Var *v = sste->fieldLookup(*($3));
                        if(!v){
                            yyerror("Field of struct doesn't exist");
                        }
                        $$ = v->type;
                    }
                }
                | expression '.' LIT_INT 
                {
                    if($1->core() != CART) {
                        yyerror("Tuple access on non-tuple type.");
                    } 
                    else 
                    {
                        if($3 < 0 || $3 >= $1->head->size) {
                            yyerror("Tuple access out of bounds.");
                        } else {
                            deque<InnerType *> c = ((AuxCART *)$1->head->aux)->cart;
                            $$ = new Type();
                            $$->head = c[$3];
                        }
                    }
                }         
                | expression KW_AS '(' type ')' {
                    FunctionSymbolTableEntry * fste = forge_st.lookup($1, $4);
                    if(!fste || typecmp($4, fste->return_type)){
                        yyerror("No forge found");
                    }
                    else{
                        $$ = fste->return_type;
                    }
                }
                | expression '@' expression // claim space 
                {
                    ClaimSymbolTableEntry * cste1 = claim_st.lookup($1, SPACE);
                    ClaimSymbolTableEntry * cste2 = claim_st.lookup($3, SPACE);
                    if(!cste1 || !cste2){
                        yyerror("Must be a space");
                    } else {
                        // check if same type
                        if(typecmp($1, $3)){
                            FunctionSymbolTableEntry * fste = forge_st.lookup($1, $3);
                            if(!fste){
                                yyerror("Type mismatch");
                            }
                            else{
                                Type * temp = fste->return_type;
                                $$ = temp->pop_type(); 
                                /***
                                 * IMPORTANT
                                 * In Type *, if the head claims SPACE, the field it is a space over will be in the next pointer.
                                 * Hence the pop_type() call.
                                 * In a ClaimSymbolTableEntry, this is not so - there is a separate field.
                                */
                            }
                        }
                        else{
                            $$ = cste1->over; // Aforementioned separate field.
                        }
                    }
                }
                | expression '*' expression // int, float, forgeable, claim group, ring
                {
                    $$ = mult_type_check_arithmetic($1, $3);
                }
                | expression '/' expression // int, float, forgeable, claim group, ring, field
                {
                    $$ = div_type_check_arithmetic($1, $3);

                }
                | expression '%' expression // int, float
                {
                    $$ = modulus_relational_type_check_arithmetic($1, $3);
                }
                | expression '+' expression // int, float, forgeable, claim group
                {
                    $$ = add_sub_type_check_arithmetic($1, $3);
                }
                | expression '-' expression // int, float, forgeable, claim group
                {
                    $$ = add_sub_type_check_arithmetic($1, $3);
                }
                | expression '>' expression // int, float
                {
                    $$ = modulus_relational_type_check_arithmetic($1, $3);
                }
                | expression '<' expression // int, float
                {
                    $$ = modulus_relational_type_check_arithmetic($1, $3);
                }
                | expression rel_op expression // int, float
                {
                    $$ = modulus_relational_type_check_arithmetic($1, $3);
                }
                | expression KW_IN expression // second buf over first.
                | expression AND expression // bool
                {
                    $$ = and_or_type_check($1, $3);
                }
                | expression OR expression // bool
                {
                    $$ = and_or_type_check($1, $3);
                }
                | IDENT // lookup in global VarST
                | constant 
                {
                    $$ = new Type();
                    VarTypes vt = convert_constType_to_varType($1.type);

                    if(vt == ENUM) {
                        $$->push_type(vt, 0, 0, new AuxESTE(((Variant *)$1.val)->este));
                    }
                    else $$->push_type(vt, 0, 0, NULL);
                }
                | unary_operation 
                | call 
                | array_decl // array value
                | cart_value // tuple value
                ; // semantic check: check if lvalue

cart_value      : '(' expression ',' cart_value_list ')' {
                    Type * t = new Type();
                    deque<InnerType *> arr($4->size() + 1, NULL);
                    arr[0] = $2->head;
                    for(int i = 1; i <= $4->size(); i++) {
                        arr[i] = (*$4)[i]->head;
                    }
                    t->push_type(CART, 0, arr.size(), new AuxCART(arr));
                    $$ = t;
                }
                ;

cart_value_list : expression ',' cart_value_list {
                    $$ = $3;
                    $$->push_front($1);
                }
                | expression {
                    deque<Type *> arr(1, $1);
                    $$ = &arr; // TODO: Check if this works.
                }
                | epsilon { 
                    deque<Type *> arr(0, NULL);
                    $$ = &arr;
                }
                ;

return_stmt     : KW_RETURN expression // Check if compatible with current function return type.
                | KW_RETURN
                ;

call            : IDENT '(' expr_list ')' {
                    FunctionSymbolTableEntry * entry = func_st.lookup(*$1);
                    if(!entry) {
                        yyerror("Function not found in symbol table."); 
                        $$ = new Type();
                    }
                    else {
                        // TODO: Check if the types are compatible.
                        for(int i = 0; i < $3->size(); i++) {
                            // Might be a better way than directly accessing the vector?
                            if(typecmp((*$3)[i], entry->params->entries[i]->type)) {
                                yyerror("Function call parameter type mismatch.");
                                break;
                            }
                        }
                        $$ = entry->return_type;
                    }
                }
                | expression '.' IDENT '(' expr_list ')' {
                    if($1->core() != STRUCT) {
                        yyerror("Method call on non-struct type.");
                    } else {
                        FunctionSymbolTableEntry * meth = ((AuxSSTE *)$1->head->aux)->sste->methods->lookup(*$3);
                        if(!meth) yyerror("Method not found in symbol table.");
                        else {
                            for(int i = 0; i < $3->size(); i++) {
                            // Might be a better way than directly accessing the vector?
                            if(typecmp((*$5)[i], meth->params->entries[i]->type)) {
                                yyerror("Function call parameter type mismatch.");
                                break;
                            }
                        }
                            $$ = meth->return_type;
                        }
                    }
                }// member functions 
                ;

expr_list       : expression ',' expr_list {
                    $$ = $3;
                    $$->push_front($1); 
                }
                | expression {
                    deque<Type *> arr(1, $1);
                    $$ = &arr;
                }
                | epsilon {
                    deque<Type *> arr(0, NULL);
                    $$ = &arr;
                }
                ;

unary_op        : INCR
                | DECR
                ;

unary_operation : expression unary_op {
                    if($1->core() != INT) {
                        yyerror("Unary operation on non-int type.");
                        $$ = new Type();
                    }
                    else {
                        $$ = $1;
                    }
                }
                ;

array_access    : expression array_index {
                    if($1->core() != BUF) {
                        if(!claim_st.lookup($1, SPACE))
                            yyerror("Array access on non-array type.");
                    }
                    else {
                        // Keep track of dimensions and stuff.
                        InnerType * current = $1->head;
                        int n = current->size;
                        while($1->core() == BUF || claim_st.lookup($1, SPACE)) {
                            n += current->size;
                            if($2 > n) yyerror("Array access out of bounds.");
                            else if($2 == n) {
                                $$ = new Type();
                                $$->head = current;
                                break;
                            }
                            current = current->next;
                        }
                    }
                }
                ;

array_decl      : '[' expr_list ']' {
                    // All expressions should have the same type
                    Type * t = (*$2)[0];
                    for(int i = 1; i < $2->size(); i++) {
                        if(typecmp(t, (*$2)[i])) {
                            yyerror("Array elements must have the same type.");
                            break;
                        }
                    }

                    $$ = new Type();
                    $$->head = t->head;
                    $$->push_type(BUF, 0, 1, NULL);
                }
                | '[' expression ';' expression ']' {
                    if($4->core() != INT) {
                        yyerror("Array size must be an integer.");
                    }
                    $$ = new Type();
                    $$->head = $2->head;
                    $$->push_type(BUF, 0, 1, NULL);
                }
                ;

array_index     : '[' expression ',' expr_list ']' // Access using commas, like a[1, 2] instead of a[1][2]. More mathy, more convenient.
                {
                    if($2->core() != INT) {
                        yyerror("Array index must be an integer.");
                    }
                    for(auto i: (*$4)) {
                        if(i->core() != INT) {
                            yyerror("Array index must be an integer.");
                            break;
                        }
                    }
                    $$ = $4->size() + 1;
                }
                | '[' expression ']' {
                    if($2->core() != INT) {
                        yyerror("Array index must be an integer.");
                    }
                    $$ = 1;
                }
                | '[' expression SLICE expression ']' // subarray access 
                {
                    if($2->core() != INT || $4->core() != INT) {
                        yyerror("Slice operands must be integers.");
                    }
                    $$ = 1;
                }
                ;

conditional     : KW_IF '(' expression {
                    if($3->core() != BOOL) yyerror("predicate must be boolean");
                } ')' {in_cond = 1;} if_body 
                ;

if_body         : body {in_cond = 0;}
                | body KW_ELSE conditional
                | body KW_ELSE body {in_cond = 0;}
                ;

loop_stmt       : KW_WHILE '(' loop_cond ')' {in_loop = 0;} body {in_loop = 0;}
                | KW_FOR '(' assignment ';' loop_cond ';' loop_mut ')' {in_loop = 0;} body {in_loop = 0;}
                | KW_FOR '(' declaration ';' loop_cond ';' loop_mut ')' {in_loop = 0;} body {in_loop = 0;}
                | KW_FOR IDENT KW_IN expression {
                    if($4->core() != BUF) {
                        if(!claim_st.lookup($4, SPACE))
                            yyerror("Looping over non-array type.");
                    }
                } {in_loop = 0;} body {in_loop = 0;}
                ;

loop_cond       : expression {
                    if($1->core() != BOOL) 
                        yyerror("Loop condition has to be boolean.");

                    $$ = $1;
                }
                ;

loop_mut        : unary_operation
                | assignment
                | epsilon
                ;

switch_case     : KW_SWITCH '(' expression ')' '{' sc_blocks KW_DEFAULT ':' statements '}'
                | KW_SWITCH '(' expression ')' '{' sc_blocks '}'
                ;

sc_blocks       : sc_blocks KW_CASE expression ':' statements {
                    $$ = $1;
                    $$->push_back($3);
                }
                | epsilon {
                    // $$ = new deque<Type *>();
                    deque<Type *> arr(0, NULL);
                    $$ = &arr;
                }
                ; // NOTE: Does not cascade

claim_stub      : KW_CLAIM IDENT KW_IS archetype {
                    $$.type = (Type *)(void *)-1;
                    StructSymbolTableEntry * entry = struct_st.lookup(*$2);
                    if(!entry) {
                        EnumSymbolTableEntry * entry = enum_st.lookup(*$2);
                        if(!entry) yyerror("No such type.");
                        else {
                            Type * t = new Type();
                            t->push_type(ENUM, 0, 1, new AuxESTE(entry));
                            ClaimSymbolTableEntry * claim = claim_st.lookup(t, $4);
                            if(!claim) $$.type = t; // Can copy Type, as InnerType is malloc'd.
                        }
                    } 
                    else {
                        Type * t = new Type();
                        t->push_type(STRUCT, 0, 1, new AuxSSTE(entry));
                        ClaimSymbolTableEntry * claim = claim_st.lookup(t, $4);
                        if(!claim) $$.type = t;
                    }

                    $$.archetype = $4;
                    
                }
                ; 

archetype_claim : claim_stub '{' type_def {
                    if($1.archetype != SPACE) yyerror("Cannot add inner types for flat archetypes."); 
                    else {
                        if(!tdef) yyerror("No inner types defined.");
                        else {
                            tdef = 0;
                        }
                    }
                } rule_list '}' {
                    if($1.type == (Type *)(void *)-1) {
                        yyerror("Claim unsuccesful.");
                    }
                    else {
                        ClaimSymbolTableEntry * claim = new ClaimSymbolTableEntry($1.type, $1.archetype);
                        claim_st.insert(claim);
                    }
                }
                | claim_stub KW_WITH '(' ident_list ')' ';' {
                    if($1.type == (Type *)(void *)-1) {
                        yyerror("Claim unsuccesful.");
                    }
                    else {
                        FunctionSymbolTableEntry * entry1 = func_st.lookup((*$4)[0]);
                        FunctionSymbolTableEntry * entry2 = func_st.lookup((*$4)[1]);
                        if(!entry1 || !entry2) yyerror("Function not found in symbol table.");
                        else {
                            if(typecmp(entry1->return_type, get_param_type(entry2)) || typecmp(entry2->return_type, get_param_type(entry1))) {
                                yyerror("Functions are not inverses.");
                            }
                            else {
                                ClaimSymbolTableEntry * claim = new ClaimSymbolTableEntry($1.type, $1.archetype);
                                claim_st.insert(claim);
                            }
                        }
                    }
                }
                ;

archetype       : KW_GROUP {$$ = GROUP;}
                | KW_RING {$$ = RING;}
                | KW_FIELD {$$ = FIELD;}
                | KW_SPACE {$$ = SPACE;}
                ;

type_def        : KW_FIELD '=' type ';' {
                    if(!claim_st.lookup($3, FIELD)) yyerror("Type is not a field.");
                    tdef = 1;
                }
                | epsilon
                ;

rule_list       : rule_list rule
                | rule
                ;

rule            : additive_rule
                | mult_rule
                | identity_rule
                | negation_rule
                | inverse_rule
                ;

additive_rule   : '(' IDENT '=' IDENT '+' IDENT ')' ARROW body 
                ;

mult_rule       : '(' IDENT '=' IDENT '*' IDENT ')' ARROW body
                ;

identity_rule   : '(' IDENT '=' LIT_INT ')' ARROW body {$$ = $4;}// LIT_INT should be 0 or 1, depending on the archetype
                ; // We don't need the type of IDENT in semantic, we copy-paste into final code.

negation_rule   : '(' IDENT '=' '-' IDENT ')' ARROW body
                ;

inverse_rule    : '(' IDENT '=' LIT_INT '/' IDENT ')' ARROW body {if($4 != 1) yyerror("Inverse rule must be 1/x");}
                ; // LIT_INT must be 1

function        : {in_func = 1;}function_header{in_func = 0;} body 
                ;

fh_stub         : KW_FN IDENT '(' param_list ')' {
                    FunctionSymbolTableEntry * entry = func_st.lookup(*$2);
                    if(entry) yyerror("Function already exists in symbol table.");
                    else {
                        VarSymbolTable * params = new VarSymbolTable();
                        for(auto i: *$4) {
                            params->insert(i->make_entry());
                        }

                        FunctionSymbolTableEntry * entry = new FunctionSymbolTableEntry(*$2, params, NULL);
                        $$ = entry;
                    }
                }
function_header :  fh_stub ':' type {
                    $1->return_type = $3;
                    func_st.insert($1);
                }
                | fh_stub {
                    func_st.insert($1);
                }// return type is void
                ;

type_var_list   : type_var ',' type_var_list {
                    $$ = $3;
                    $$->push_front($1);
                }
                | type_var {
                    deque<Var *> arr(1, $1);
                    $$ = &arr;

                }
                | epsilon { 
                   deque<Var *> arr(0, new Var());
                   $$ = &arr;
                }
                ;

param_list      : type_var_list 
                ;

type_var        : IDENT ':' type {
                    $$ = new Var(*$1, $3, 0, 0);
                }
                ;

struct          : KW_STRUCT IDENT '{' attr_list '}' {
                    StructSymbolTableEntry * entry = new StructSymbolTableEntry(*$2, *$4);
                    struct_st.insert(entry);
                }
                ;

attr_list       : type_var_list
                ;

enum            : KW_ENUM IDENT '{' variant_list '}' {
                    EnumSymbolTableEntry * entry = new EnumSymbolTableEntry(*$2, *$4);
                    enum_st.insert(entry);
                }
                ;

ident_list      : ident_list ',' IDENT {
                    $$ = $1;
                    $$->push_front(*$3);
                }
                | IDENT {
                    deque<string> arr(1, *$1);
                    $$ = &arr;
                }
                | epsilon { 
                    deque<string> arr(0, string());
                    $$ = &arr;
                }
                ;

variant_list    : ident_list
                ;

forge           : KW_FORGE '(' param_list ')' KW_AS '(' type ')' body {
                    VarSymbolTable * params = new VarSymbolTable();
                    for(auto i: *$3) {
                        params->insert(i->make_entry());
                    }

                    FunctionSymbolTableEntry * entry = new FunctionSymbolTableEntry(NULL, params, $7);
                    forge_st.insert(entry);
                }
                ;

cart            : '(' type ',' ')' {
                    Type * t = new Type();
                    deque<InnerType *> arr(1, $2->head);
                    t->push_type(CART, 0, 1, new AuxCART(arr));
                    $$ = t;
                }
                | '(' type ',' type_list ')' {
                    Type * t = new Type();
                    deque<InnerType *> arr($4->size() + 1, NULL);
                    arr[0] = $2->head;
                    for(int i = 1; i <= $4->size(); i++) {
                        arr[i] = (*$4)[i - 1]->head;
                    }
                    t->push_type(CART, 0, arr.size(), new AuxCART(arr));
                    $$ = t;
                }
                ;

type_list       : type_list ',' type {
                    $$ = $1;
                    $$->push_front($3);
                }
                | type {
                    deque<Type *> arr(1, $1);   
                    $$ = &arr;
                }
                ;

epsilon         : ;

%%

int main() {
    token_stream = fopen("code/seq_tokens.txt", "w");
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
