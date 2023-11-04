%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);
FILE * token_stream;

// flags
int in_func = 0;
int in_loop = 0;
int in_cond = 0;
#include "semantic.h"
%}
%code requires {
    #include "semantic.h"
}
%union {
    char * ident;
    int lit_int;
    float lit_float;
    char * lit_str;
    char lit_char;
    PDT prim_type;
    struct {
        void * val;
        CType type;
    } cons;
    Type expr; // Not a pointer because maybe overlap stack nodes? No one will ever pop the stack, so safe.
    Archetype archetype; 
    struct {
        Archetype archetype;
        Type type;
    } claim_stub_type;
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
%type <lit_int> identity_rule // is it 0 or 1? Check inside claim body.
%type <expr> expression
%type <archetype> archetype
%type <claim_stub_type> claim_stub
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
                | call ';'
                | return_stmt ';' 
                | conditional
                | switch_case
                | loop_stmt
                | KW_BREAK ';' {if(!in_loop) yyerror("break statement outside of loop");}
                | KW_CONTINUE ';' {if(!in_loop) yyerror("continue statement outside of loop");}
                | ';'
                ;

generic         : IDENT '<' type_args '>' // someone write a list of allowed generics.
                ;

type_args       : type_arg ',' type_args
                | type_arg
                | epsilon
                ;

type_arg        : type
                | LIT_INT
                ;

declaration     : KW_LET decl_list
                ;

decl_list       : decl_item
                | decl_item ',' decl_list
                ;

decl_item       : type_var
                | type_var '=' expression
                ;

type            : PRIMITIVE_DTYPE {}
                | '[' type ']' 
                | IDENT
                | generic
                | '&' type
                | cart
                ; 

assign_op       : ASSIGN_OP
                | '='
                ;

assignment      : expression assign_op expression // expression must be an lvalue
                ;

constant        : LIT_CHAR {$$.val = (void *)$1; $$.type = CT_CHAR;}
                | LIT_FLOAT {$$.val = (void *)*(int *)(float *)&$1; $$.type = CT_FLOAT;}
                | LIT_INT {$$.val = (void *)$1; $$.type = CT_INT;}
                | LIT_STR {$$.val = (void *)$1; $$.type = CT_STR;}
                | KW_TRUE {$$.val = (void *)1; $$.type = CT_BOOL;}
                | KW_FALSE {$$.val = (void *)0; $$.type = CT_BOOL;}
                | IDENT VARIANT IDENT  {
                    $$.val = 0;
                    EnumSymbolTableEntry * entry = est_lookup(&enum_st, $1);
                    if(!entry) yyerror("Enum not found in symbol table.");
                    else {
                        for(int i = 0; i < entry->numFields; i++) {
                            if(!strcmp(entry->fields[i], $3)) {
                                $$.val = (Variant *)malloc(sizeof(Variant));
                                ((Variant *)$$.val)->tag = strdup($1);
                                ((Variant *)$$.val)->val = strdup($3);
                                ((Variant *)$$.val)->este = entry;
                                $$.type = CT_VAR; 
                                break;
                            }
                        }
                        if(!$$.val) yyerror("Variant not found in enum.");
                    }
                } // Enum variant: needs a symbol table lookup. Added it.
                ;

expression      : '(' expression ')'
                | array_access
                | '!' expression
                | '-' expression                %prec '!'  // Unary minus has precedence of '!', not subtraction.
                | '*' expression                %prec '!'  // Dereference has precedence of '!', not multiplication.   
                | '&' expression                %prec '!'  // Address-of has precedence of '!', bitwise operators do not exist.
                | expression '.' IDENT
                | expression '.' LIT_INT {
                    if($1.head->core_type != CART) {
                        yyerror("Tuple access on non-tuple type.");
                    } else {
                        if($3 < 0 || $3 >= $1.head->size) {
                            yyerror("Tuple access out of bounds.");
                        } else {
                            // TODO: That struct Type construction.
                        }
                    }

                    $$ = make_type();
                }               // tuple access 
                | expression KW_AS '(' type ')'
                | expression '@' expression
                | expression '*' expression
                | expression '/' expression
                | expression '%' expression
                | expression '+' expression
                | expression '-' expression
                | expression '>' expression
                | expression '<' expression
                | expression rel_op expression
                | expression KW_IN expression
                | expression AND expression 
                | expression OR expression
                | IDENT | constant | unary_operation | call 
                | array_decl // array value
                | cart_value // tuple value
                ; // semantic check: check if lvalue

cart_value      : '(' expression ',' cart_value_list ')'
                ;

cart_value_list : expression ',' cart_value_list
                | expression
                | epsilon
                ;

return_stmt     : KW_RETURN expression 
                | KW_RETURN
                ;

call            : IDENT '(' expr_list ')' {
                    FunctionSymbolTableEntry * entry = fst_lookup(&func_st, $1);
                    if(!entry) yyerror("Function not found in symbol table.");
                    else {
                        // TODO: Check if the types are compatible.
                    }
                }
                | expression '.' IDENT '(' expr_list ')'
                /* | expression '.' LIT_INT '(' expr_list ')' */
                ;

expr_list       : expression ',' expr_list // TODO: get the list of types. Need no more information.
                | expression
                | epsilon
                ;

unary_operation : expression INCR
                | expression DECR
                ;

array_access    : expression array_index
                ;

array_decl      : '[' expr_list ']'
                | '[' expression ';' expression ']'
                ;

array_index     : '[' expression ',' expr_list ']' // Access using commas, like a[1, 2] instead of a[1][2]. More mathy, more convenient.
                | '[' expression ']'
                | '[' expression SLICE expression ']' // subarray access
                ;

conditional     : KW_IF '(' expression ')' {in_cond = 1;} if_body 
                ;

if_body         : body {in_cond = 0;}
                | body KW_ELSE conditional
                | body KW_ELSE body {in_cond = 0;}
                ;

loop_stmt       : KW_WHILE '(' expression ')' {in_loop = 0;} body {in_loop = 0;}
                | KW_FOR '(' assignment ';' expression ';' loop_mut ')' {in_loop = 0;} body {in_loop = 0;}
                | KW_FOR '(' declaration ';' expression ';' loop_mut ')' {in_loop = 0;} body {in_loop = 0;}
                | KW_FOR IDENT KW_IN IDENT {in_loop = 0;} body {in_loop = 0;}
                ;

loop_mut        : unary_operation
                | assignment
                | epsilon
                ;

switch_case     : KW_SWITCH '(' expression ')' '{' sc_blocks KW_DEFAULT ':' statements '}'
                | KW_SWITCH '(' expression ')' '{' sc_blocks '}'
                ;

sc_blocks       : KW_CASE constant ':' statements sc_blocks
                | epsilon
                ; // NOTE: Does not cascade

claim_stub      : KW_CLAIM IDENT KW_IS archetype {
                    $$.type = (Type)(void *)-1;
                    StructSymbolTableEntry * entry = sst_lookup(&struct_st, $2);
                    if(!entry) {
                        EnumSymbolTableEntry * entry = est_lookup(&struct_st, $2);
                        if(!entry) yyerror("No such type.");
                        else {
                            Type t = make_type();
                            push_type(&t, ENUM, 0, 1, entry);
                            ClaimSymbolTableEntry * claim = cst_lookup(&claim_st, t, $4);
                            if(!claim) $$.type = t; // Can copy Type, as InnerType is malloc'd.
                        }
                    } 
                    else {
                        $$.which = 0;
                        Type t = make_type();
                        push_type(&t, STRUCT, 0, 1, entry);
                        ClaimSymbolTableEntry * claim = cst_lookup(&claim_st, t, $4);
                        if(!claim) $$.type = t;
                    }

                    $$.archetype = $4;
                    
                }
                ; // Avoids redundant code.

archetype_claim : claim_stub '{' type_def {
                    if($1.archetype != SPACE) yyerror("Cannot add inner types for flat archetypes."); 
                } rule_list '}' {
                    if($1.type == (Type)(void *)-1)) {
                        yyerror("Claim unsuccesful.");
                    }
                    else {
                        ClaimSymbolTableEntry * claim = make_claim_ste($1.type, $1.archetype);
                        cst_insert(&claim_st, claim);
                    }
                }
                // PROBLEM: We need the ?SymbolTableEntry again to insert into claim_st. Another lookup is bad, moving the midrule to the end is unsavoury 
                // (error reported at the wrong place), and I know of no way to transport that entry pointer barring globals, which are, again, unsavoury. 
                // SOLUTION: Returning the pointer from claim_stub. Yay.
                | claim_stub KW_WITH '(' ident_list ')' ';'
                ;

archetype       : KW_GROUP {$$ = GROUP;}
                | KW_RING {$$ = RING;}
                | KW_FIELD {$$ = FIELD;}
                | KW_SPACE {$$ = SPACE;}
                ;

type_def        : archetype {
                    if($1 != FIELD) yyerror("Faulty inner type.");
                } '=' type ';' {}
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

function        : function_header body 
                ;

function_header : KW_FN IDENT '(' param_list ')' ':' type
                | KW_FN IDENT '(' param_list ')' // return type is void
                ;

type_var_list   : type_var ',' type_var_list
                | type_var
                | epsilon
                ;

param_list      : type_var_list
                ;

type_var        : IDENT ':' type {
                    
                }
                ;

struct          : KW_STRUCT IDENT '{' attr_list '}'
                ;

attr_list       : type_var_list
                ;

enum            : KW_ENUM IDENT '{' variant_list '}'
                ;

ident_list      : ident_list ',' IDENT
                | IDENT
                | epsilon
                ;

variant_list    : ident_list
                ;

forge           : KW_FORGE '(' param_list ')' KW_AS '(' type ')' body
                ;

cart            : '(' type ',' ')'
                | '(' type ',' type_list ')'
                ;

type_list       : type_list ',' type
                | type
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
