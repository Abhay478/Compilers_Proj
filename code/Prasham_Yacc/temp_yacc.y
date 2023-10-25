%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);

%}

%token KW_LET KW_RETURN KW_CYCLIC KW_BIG_RATIONAL KW_COMPLEX KW_SYMMETRIC KW_ALTERNATING KW_DIHEDRAL KW_INV_MAT KW_BIGINT KW_MATRIX KW_POLYNOMIAL KW_VEC KW_BUF IDENT PRIMITIVE_DTYPE LIT_INT LIT_FLOAT LIT_STR LIT_CHAR LOGICAL_AND LOGICAL_OR LOGICAL_NOT EQ NEQ GT LT GTEQ LTEQ KW_TRUE KW_FALSE

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
                | var
                | constant
                | unary_operation
                | array_access
                | array_decl
                ;

arithmetic_expr : arithmetic_expr C
                | term
                //| '(' arithmetic_expr ')'
                ;

C               : '+' term
                | '-' term
                ;

term            : term D
                | factor
                ;

D               : '*' factor
                | '/' factor
                | '%' factor
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
                | unary_operation
                | var
                | constant
                | call_stmt
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

call_stmt       : IDENT '(' pass_param_list ')' 
                | IDENT '(' ')'
                ;

pass_param_list : expression ',' pass_param_list
                | expression
                ;

unary_operation : var '+' '+'
                | var '-' '-'
                ;

array_access    : IDENT C
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

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
