%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);

%}

%token KW_LET KW_CYCLIC KW_BIG_RATIONAL KW_COMPLEX KW_SYMMETRIC KW_ALTERNATING KW_DIHEDRAL KW_INV_MAT KW_BIGINT KW_MATRIX KW_POLYNOMIAL KW_VEC KW_BUF IDENT PRIMITIVE_DTYPE LIT_INT LIT_FLOAT LIT_STR LIT_CHAR

%start statements

%%
statements      : statement statements
                | epsilon
                ;

statement       : declaration ';'
/*
                : assignment
                : call_stmt
                : return_stmt
                : expression
                : if_else_conditional
                : switch_conditional
                : loop_stmt
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

declaration     : KW_LET var ':' PRIMITIVE_DTYPE
                | KW_LET var ':' KW_BUF '<' PRIMITIVE_DTYPE '>'
                | KW_LET var ':' IDENT
                | KW_LET var ':' group_data_type
                | KW_LET var ':' ring_data_type
                | KW_LET var ':' field_data_type
                | KW_LET var ':' space_data_type
                ;
/*
A               : '=' expression
                | epsilon
                ;
*/
epsilon         : ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
