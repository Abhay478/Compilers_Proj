%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);

%}

%token KW_CLAIM KW_IS KW_GROUP KW_RING KW_FIELD KW_SPACE KW_PRINT KW_LET KW_RETURN KW_IF KW_ELSE KW_WHILE KW_FOR KW_IN KW_SWITCH KW_CASE KW_DEFAULT KW_BREAK KW_CONTINUE KW_FN KW_MORPH KW_FORGE KW_STRUCT KW_ENUM 
%token KW_CYCLIC KW_BIG_RATIONAL KW_COMPLEX KW_SYMMETRIC KW_ALTERNATING KW_DIHEDRAL KW_INV_MAT KW_BIGINT KW_MATRIX KW_POLYNOMIAL KW_VEC KW_BUF 
%token IDENT PRIMITIVE_DTYPE LIT_INT LIT_FLOAT LIT_STR LIT_CHAR log_op rel_op KW_TRUE KW_FALSE
%token GROUP RING FIELD SPACE
%token INCR DECR ARROW VARIANT
%left log_op rel_op '>' '<'
%left '+' '-' '*' '/' '%' '@'
%right '!'
%start statements

%%
statements      : statement statements
                | epsilon
                ;

statement       : declaration ';'
                | assignment ';'
                | call_stmt_standalone
                | return_stmt ';' 
                | if_else_conditional
                | switch_case
                | loop_stmt
                | KW_PRINT '(' pass_param_list ')' ';'
                | KW_BREAK ';'
                | KW_CONTINUE ';' 
                | archetype_claim              
                ;

body            : '{' statements '}'
                ;
              
var             : IDENT
                | IDENT '.' IDENT
                ;

field_data_type : // KW_CYCLIC '<' LIT_INT '>'
                | KW_BIG_RATIONAL
                | KW_COMPLEX
                ;

group_data_type : KW_CYCLIC '<' LIT_INT '>'
                | KW_SYMMETRIC '<' LIT_INT '>'
                | KW_ALTERNATING '<' LIT_INT '>'
                | KW_DIHEDRAL '<' LIT_INT '>'
                | KW_INV_MAT '<' LIT_INT ',' IDENT '>'
                ;

ring_data_type  : KW_BIGINT
                | KW_MATRIX '<' LIT_INT ',' IDENT '>'
                | KW_POLYNOMIAL '<' IDENT '>'
                ;

space_data_type : KW_VEC '<' IDENT '>'
                | KW_VEC '<' PRIMITIVE_DTYPE '>'
                ;

declaration     : KW_LET decl_tail
                ;

decl_tail       : typ_var decl_cntd

type            : PRIMITIVE_DTYPE
                | KW_BUF '<' PRIMITIVE_DTYPE '>'
                | IDENT
                | group_data_type
                | ring_data_type
                | field_data_type
                | space_data_type
                ; 

decl_cntd       : '=' expression
                | ',' decl_tail
                | epsilon
                ;

assignment      : var '=' expression
                | array_access '=' expression
                ;

constant        : LIT_CHAR
                | LIT_FLOAT
                | LIT_INT
                | LIT_STR
                ;

expression      : expression '+' expression
                | expression '-' expression
                | expression '*' expression
                | expression '/' expression
                | expression '%' expression
                | '(' expression ')'
                | expression log_op expression 
                | '!' expression
                | expression rel_op expression
                | expression '>' expression
                | expression '<' expression
                | var | constant | unary_operation | array_access | call_stmt 
                | KW_TRUE | KW_FALSE
                | expression '@' expression
                //| call_stmt
                //| var
                //| constant
                //| unary_operation
                //| array_access
                | array_decl
                /* | var '@' var */
                ;
/* predicate       : logical_expr
                | relational_expr
                ; */

/* arithmetic_expr : arithmetic_expr '+' term {}
                | arithmetic_expr '-' term {}
                | term {}
                //| '(' arithmetic_expr ')'
                ;

term            : term '*' factor {}
                | term '/' factor {}
                | term '%' factor {}
                | factor {}
                ;

factor          : var {}
                | '(' arithmetic_expr ')' {}
                | '-' factor 
                | constant {}
                | call_stmt {}
                | array_access {}
                | unary_operation {} 
                 ; */

/* 
arithmetic_expr : arithmetic_expr '+' arithmetic_expr
                | arithmetic_expr '-' arithmetic_expr
                | arithmetic_expr '*' arithmetic_expr
                | arithmetic_expr '/' arithmetic_expr
                | arithmetic_expr '%' arithmetic_expr
                | '(' arithmetic_expr ')'
                | var | constant | unary_operation | array_access | call_stmt | var '@' var
                ; */


/* logical_expr    : B logical_op logical_expr 
                | B
                | LOGICAL_NOT logical_expr
                ;

B               : arithmetic_expr
                //| unary_operation
                //| call_stmt
                | '(' logical_expr ')'
                | KW_TRUE
                | KW_FALSE
                ; */
/* 
logical_expr    : logical_expr log_op logical_expr 
                | '!' logical_expr
                | '(' logical_expr ')'
                | KW_TRUE
                | KW_FALSE
                ; */

/* relational_expr : relational_expr rel_op relational_expr
                | relational_expr '>' relational_expr
                | relational_expr '<' relational_expr
                | arithmetic_expr
                ; */

/* logical_op      : '>' 
                | '<'
                | GTEQ
                | LTEQ
                | EQ
                | NEQ
                | LOGICAL_AND
                | LOGICAL_OR
                ; */

return_stmt     : KW_RETURN expression 
                ;

call_stmt_standalone    : var '(' pass_param_list ')' ';'
                        | var '(' ')' ';'
                        ;

call_stmt       : var '(' pass_param_list ')' 
                | var '(' ')'
                ;

pass_param_list : expression ',' pass_param_list
                | expression
                ;

unary_operation : var INCR
                | var DECR
                ;

array_access    : var C
                ;

C               : '[' LIT_INT ']' C
                | '[' LIT_INT ']'
                ;

array_decl      : '[' array_list ']'
                ;

array_list      : constant ',' array_list
                | constant
                ;

if_else_conditional : KW_IF '(' expression ')' if_body
                    ;

if_body             : body 
                    | body KW_ELSE if_else_conditional
                    | body KW_ELSE body
                    /*| statement
                    | statement KW_ELSE if_else_conditional
                    | statement KW_ELSE body
                    | statement KW_ELSE statement
                    */;

loop_stmt           : KW_WHILE '(' expression ')' body
                    | KW_FOR '(' assignment ';' expression ';' V ')' body
                    | KW_FOR '(' declaration ';' expression ';' V ')' body
                    | KW_FOR IDENT KW_IN IDENT body
                    ;

V                   : unary_operation
                    | epsilon
                    ;

switch_case         : KW_SWITCH '(' expression ')' '{' switch_case_blocks KW_DEFAULT ':' statements '}'
                    | KW_SWITCH '(' expression ')' '{' switch_case_blocks '}'
                    ;

switch_case_blocks  : KW_CASE LIT_CHAR ':' statements switch_case_blocks
                    | KW_CASE LIT_INT ':' statements switch_case_blocks
                    | KW_CASE LIT_FLOAT ':' statements switch_case_blocks
                    | epsilon
                    ;

archetype_claim     : KW_CLAIM IDENT KW_IS KW_GROUP '{' group_closure_rule identity_rule group_inverse_rule '}' ';' {printf("Group claim rule\n");}
                    | KW_CLAIM IDENT KW_IS KW_RING '{' ring_closure_rule identity_rule '}' ';'
                    | KW_CLAIM IDENT KW_IS KW_FIELD '{' field_inverse_rule '}' ';'
                    | KW_CLAIM IDENT KW_IS KW_SPACE '{' KW_FIELD '=' '(' IDENT ')' ';' group_closure_rule group_inverse_rule identity_rule ring_closure_rule'}' ';'
                    ;

group_closure_rule  : '(' IDENT '=' IDENT '+' IDENT ')' ARROW body {printf("Group_closure_rule\n");}
                    ;

ring_closure_rule   : '(' IDENT '=' IDENT '*' IDENT ')' ARROW body
                    ;

identity_rule       : '(' IDENT '=' LIT_INT ')' ARROW body
                    ;

group_inverse_rule  : '(' IDENT '=' '-' IDENT ')' ARROW body
                    ;

field_inverse_rule  : '(' IDENT '=' '~' IDENT ')' ARROW body
                    ;


/*  */


function        : function_header '{' function_body '}' 
                ;

function_header : KW_FN IDENT '(' parameter_list ')' ':' type
                ;

function_body   : statements
                ;

parameter_list  : typ_var
                | parameter_list ',' typ_var 
                ;

typ_var         : var ':' type
                ;

struct          : KW_STRUCT IDENT '{' attr_list '}'
                ;
attr_list       : IDENT
                | typ_var ',' IDENT 
                ;
enums           : KW_ENUM IDENT '{' variant_list '}'
                ;
variant_list    : IDENT
                | variant_list ',' IDENT 
                ;
                
epsilon         : ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
