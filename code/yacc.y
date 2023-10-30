%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);

%}

%token KW_CLAIM KW_IS KW_GROUP KW_RING KW_FIELD KW_SPACE KW_PRINT KW_LET KW_RETURN KW_IF KW_ELSE KW_WHILE KW_FOR KW_IN KW_SWITCH KW_CASE KW_DEFAULT KW_BREAK KW_CONTINUE KW_FN KW_MORPH KW_FORGE KW_STRUCT KW_ENUM 
%token KW_CYCLIC KW_BIG_RATIONAL KW_COMPLEX KW_SYMMETRIC KW_ALTERNATING KW_DIHEDRAL KW_INV_MAT KW_BIGINT KW_MATRIX KW_POLYNOMIAL KW_VEC KW_BUF 
%token IDENT PRIMITIVE_DTYPE LIT_INT LIT_FLOAT LIT_STR LIT_CHAR log_op rel_op KW_TRUE KW_FALSE
%token GROUP RING FIELD SPACE
%token INCR DECR ARROW VARIANT SLICE // Two character operators.
%left log_op 
%left rel_op '>' '<'
%right '!'
%left '+' '-' 
%left '*' '/' '%' 
%left '@'
%right '.'
%start P

%%
P               : statements
                | P function
                | P struct
                | P forge
                | P enum
                ;
statements      : statement statements
                | epsilon
                ;

statement       : declaration ';'
                | assignment ';'
                | call_stmt
                | return_stmt ';' 
                | conditional
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
                | var '.' IDENT // Nested structs
                | IDENT VARIANT IDENT // No nested enums
                ;

field_data_type : KW_BIG_RATIONAL
                | KW_COMPLEX
                ;

group_data_type : KW_CYCLIC '<' LIT_INT '>'
                | KW_SYMMETRIC '<' LIT_INT '>'
                | KW_ALTERNATING '<' LIT_INT '>'
                | KW_DIHEDRAL '<' LIT_INT '>'
                | KW_INV_MAT '<' LIT_INT ',' type '>' // Second generic should be a field.
                ;

ring_data_type  : KW_BIGINT
                | KW_MATRIX '<' LIT_INT ',' type '>' // Second generic should be a field.
                | KW_POLYNOMIAL '<' type '>' // Second generic should be a field.
                ;

space_data_type : KW_VEC '<' type '>'
                /* | KW_VEC '<' PRIMITIVE_DTYPE '>' ALREADY IN TYPE */
                ;

declaration     : KW_LET decl_tail
                ;

decl_tail       : typ_var decl_cntd
                ;

type            : PRIMITIVE_DTYPE
                | KW_BUF '<' PRIMITIVE_DTYPE '>'
                | IDENT
                | group_data_type
                | ring_data_type
                | field_data_type
                | space_data_type
                | '&' type
                | cart
                ; 

decl_cntd       : '=' RHS
                | ',' decl_tail
                | epsilon
                ;

RHS             : expression
                | '&' RHS
                | '*' RHS
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
                | var | constant | unary_operation | array_access | call 
                | KW_TRUE | KW_FALSE
                | expression '@' expression
                | array_decl
                ;

return_stmt     : KW_RETURN expression 
                ;

call_stmt       : type '(' pass_param_list ')' ';'
                | type '(' ')' ';'
                ;

call            : type '(' pass_param_list ')' 
                | type '(' ')'
                ;

pass_param_list : expression ',' pass_param_list
                | expression
                ;

unary_operation : var INCR
                | var DECR
                ;

array_access    : var array_decl
                ;

array_decl      : '[' array_list ']' // Access using commas, like a[1, 2] instead of a[1][2]. More mathy, more convenient.
                | '['expression SLICE expression ']' // 
                ;

array_list      : constant ',' array_list
                | constant
                ;

conditional     : KW_IF '(' expression ')' if_body
                ;

if_body         : body 
                | body KW_ELSE conditional
                | body KW_ELSE body
                ;

loop_stmt       : KW_WHILE '(' expression ')' body
                | KW_FOR '(' assignment ';' expression ';' loop_mut ')' body
                | KW_FOR '(' declaration ';' expression ';' loop_mut ')' body
                | KW_FOR IDENT KW_IN IDENT body
                ;

loop_mut        : unary_operation
                | epsilon
                ;

switch_case     : KW_SWITCH '(' expression ')' '{' sc_blocks KW_DEFAULT ':' statements '}'
                | KW_SWITCH '(' expression ')' '{' sc_blocks '}'
                ;

sc_blocks       : KW_CASE LIT_CHAR ':' statements sc_blocks
                | KW_CASE LIT_INT ':' statements sc_blocks
                | KW_CASE LIT_FLOAT ':' statements sc_blocks
                | epsilon
                ;

archetype_claim : KW_CLAIM IDENT KW_IS KW_GROUP '{' additive_rule identity_rule negation_rule '}' ';' {printf("Group claim rule\n");}
                | KW_CLAIM IDENT KW_IS KW_RING '{' mult_rule identity_rule '}' ';'
                | KW_CLAIM IDENT KW_IS KW_FIELD '{' inverse_rule '}' ';'
                | KW_CLAIM IDENT KW_IS KW_SPACE '{' KW_FIELD '=' '(' type ')' ';' additive_rule negation_rule identity_rule mult_rule'}' ';'
                ;

additive_rule   : '(' IDENT '=' IDENT '+' IDENT ')' ARROW body {printf("Group_closure_rule\n");}
                ;

mult_rule       : '(' IDENT '=' IDENT '*' IDENT ')' ARROW body
                ;

identity_rule   : '(' IDENT '=' LIT_INT ')' ARROW body
                ;

negation_rule   : '(' IDENT '=' '-' IDENT ')' ARROW body
                ;

inverse_rule    : '(' IDENT '=' '~' IDENT ')' ARROW body
                ;

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
enum            : KW_ENUM IDENT '{' variant_list '}'
                ;
variant_list    : IDENT
                | variant_list ',' IDENT 
                ;
forge           : KW_FORGE type '(' parameter_list   '{' statements '}'
                ;
cart            : '(' typ_list ')'
                ;
typ_list        : typ_list ',' type
                | type
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
