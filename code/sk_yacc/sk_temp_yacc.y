%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);

%}

%token KW_LET KW_RETURN KW_CYCLIC KW_ENUM KW_STRUCT KW_BIG_RATIONAL KW_FN KW_COMPLEX KW_SYMMETRIC KW_ALTERNATING KW_DIHEDRAL KW_INV_MAT KW_BIGINT KW_MATRIX KW_POLYNOMIAL KW_VEC KW_BUF IDENT PRIMITIVE_DTYPE LIT_INT LIT_FLOAT LIT_STR LIT_CHAR LOGICAL_AND LOGICAL_OR LOGICAL_NOT EQ NEQ GT LT GTEQ LTEQ KW_TRUE KW_FALSE

%start statements

%%
statements      : statement statements
                | epsilon
                ;

statement       : declaration ';'
                | assignment ';'
                | call_stmt ';'
                | return_stmt ';' 
                /*| if_else_conditional
                | switch_conditional
                | loop_stmt
                */
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

declaration     : KW_LET var ':' PRIMITIVE_DTYPE A
                | KW_LET var ':' KW_BUF '<' PRIMITIVE_DTYPE '>' A
                | KW_LET var ':' IDENT A
                | KW_LET var ':' group_data_type A
                | KW_LET var ':' ring_data_type A
                | KW_LET var ':' field_data_type A
                | KW_LET var ':' space_data_type A
                ;

A               : '=' expression
                | epsilon
                ;

assignment      : var '=' expression
                ;

expression      : arithmetic_expr
                //| logical_expr
                | call_stmt
                //| var
                //| constant
                //| unary_operation
                | array_access
                | array_decl
                ;

arithmetic_expr : arithmetic_expr '+' term
                | arithmetic_expr '-' term
                | term
                //| '(' arithmetic_expr ')'
                ;

term            : term '*' factor
                | term '/' factor
                | term '%' factor
                | factor
                ;

factor          : var
                | '(' arithmetic_expr ')'
                | '-' factor
                | constant
                ;

constant        : LIT_CHAR
                | LIT_FLOAT
                | LIT_INT
                | LIT_STR
                ;
/*
logical_expr    : B logical_op logical_expr 
                | B
                | LOGICAL_NOT logical_expr
                ;

B               : arithmetic_expr
                //| unary_operation
                //| call_stmt
                | '(' logical_expr ')'
                | KW_TRUE
                | KW_FALSE
                ;

logical_op      : '>' 
                | '<'
                | GTEQ
                | LTEQ
                | EQ
                | NEQ
                | LOGICAL_AND
                | LOGICAL_OR
                ;
*/
return_stmt     : KW_RETURN expression 
                ;

call_stmt       : var '(' pass_param_list ')' 
                | var '(' ')'
                ;

pass_param_list : expression ',' pass_param_list
                | expression
                ;
/*
unary_operation : '+' '+' var
                | '-' '-' var
                ;
*/
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

epsilon         : ;

function        : function_header '{' function_body '}' 
                ;

function_header : KW_FN IDENT '(' parameter_list ')' ':' PRIMITIVE_DTYPE
                ;

function_body   : statements
                ;

parameter_list  : parameter
                | parameter_list ',' parameter 
                ;

parameter       : IDENT ':' data_type
                ;
            
data_type       : PRIMITIVE_DTYPE
                | KW_BUF '<' PRIMITIVE_DTYPE '>' 
                | group_data_type
                | ring_data_type
                | field_data_type
                | space_data_type
                | struct
                ;
/*
struct          : struct_header '{' struct_body '}'
                ;

struct_header   : KW_STRUCT IDENT 
                ;

struct_body     : declaration
                ;
*/

enums           : enum_header '{' enum_body '}'
                ;

enum_header     : KW_ENUM IDENT
                ;
    
enum_body       : variant_list
                ;

variant_list    : variant
                | variant_list ',' variant 
                ;

variant         : IDENT;

/* enum_var        : KW_LET IDENT ':' IDENT '=' I */


%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
