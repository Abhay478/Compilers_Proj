%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);

%}

%token KW_CLAIM KW_IS KW_GROUP KW_RING KW_FIELD KW_SPACE KW_PRINT KW_LET KW_RETURN KW_IF KW_ELSE KW_WHILE KW_FOR KW_IN KW_SWITCH KW_CASE KW_DEFAULT KW_BREAK KW_CONTINUE KW_CYCLIC KW_BIG_RATIONAL KW_COMPLEX KW_SYMMETRIC KW_ALTERNATING KW_DIHEDRAL KW_INV_MAT KW_BIGINT KW_MATRIX KW_POLYNOMIAL KW_VEC KW_BUF IDENT PRIMITIVE_DTYPE LIT_INT LIT_FLOAT LIT_STR LIT_CHAR LOGICAL_AND LOGICAL_OR LOGICAL_NOT EQ NEQ GT LT GTEQ LTEQ KW_TRUE KW_FALSE

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
                | KW_PRINT '(' print_param_list ')' ';'
                | KW_BREAK ';'
                | KW_CONTINUE ';' 
                | archetype_claim              
                ;

print_param_list : LIT_STR
                 | LIT_STR ',' print_param_list
                 | expression
                 | expression ',' print_param_list
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
                | ',' var ':' KW_BUF '<' PRIMITIVE_DTYPE '>' A
                | ',' var ':' PRIMITIVE_DTYPE A
                | ',' var ':' IDENT A
                | ',' var ':' group_data_type A
                | ',' var ':' ring_data_type A
                | ',' var ':' field_data_type A
                | ',' var ':' space_data_type A
                ;
                ;

assignment      : var '=' expression
                | array_access '=' expression
                ;

expression      : arithmetic_expr
                | logical_expr
                //| call_stmt
                //| var
                //| constant
                //| unary_operation
                //| array_access
                | array_decl
                | var '@' var
                ;

arithmetic_expr : arithmetic_expr '+' term {printf("Rule: arithmetic_expr : arithmetic_expr \'+\' term\n");}
                | arithmetic_expr '-' term {printf("Rule: arithmetic_expr : arithmetic_expr \'-\' term\n");}
                | term {printf("Rule: arithmetic_expr : term\n");}
                //| '(' arithmetic_expr ')'
                ;

term            : term '*' factor {printf("Rule: term : term \'*\' factor\n");}
                | term '/' factor {printf("Rule: term : term \'/\' factor\n");}
                | term '%' factor {printf("Rule: term : term \'\%\' factor\n");}
                | factor {printf("Rule: term : factor\n");}
                ;

factor          : var {printf("Rule: factor : var\n");}
                | '(' arithmetic_expr ')' {printf("Rule: factor : \'(\' arithmetic_expr \')\'\n");}
                | '-' factor 
                | constant {printf("Rule: factor : constant\n");}
                | call_stmt {printf("Rule: factor : call_stmt\n");}
                | array_access {printf("Rule: factor : array_access\n");}
                | unary_operation {printf("Rule: factor : unary_operation\n");}
                ;

constant        : LIT_CHAR
                | LIT_FLOAT
                | LIT_INT
                | LIT_STR
                ;

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

unary_operation : var '+' '+' 
                | var '-' '-'
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

if_else_conditional : KW_IF '(' logical_expr ')' D 
                    ;

D                   : '{' statements '}' 
                    | '{' statements '}' KW_ELSE if_else_conditional
                    | '{' statements '}' KW_ELSE '{' statements '}'
                    /*| statement
                    | statement KW_ELSE if_else_conditional
                    | statement KW_ELSE '{' statements '}'
                    | statement KW_ELSE statement
                    */;

loop_stmt           : KW_WHILE '(' logical_expr ')' '{' statements '}'
                    | KW_FOR '(' assignment ';' logical_expr ';' V ')' '{' statements '}'
                    | KW_FOR '(' declaration ';' logical_expr ';' V ')' '{' statements '}'
                    | KW_FOR IDENT KW_IN IDENT '{' statements '}'
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

group_closure_rule  : '(' IDENT '=' IDENT '+' IDENT ')' '=' '>' '{' statements '}' {printf("Group_closure_rule\n");}
                    ;

ring_closure_rule   : '(' IDENT '=' IDENT '*' IDENT ')' '=' '>' '{' statements '}'
                    ;

identity_rule       : '(' IDENT '=' LIT_INT ')' '=' '>' '{' statements '}'
                    ;

group_inverse_rule  : '(' IDENT '=' '-' IDENT ')' '=' '>' '{' statements '}'
                    ;

field_inverse_rule  : '(' IDENT '=' '~' IDENT ')' '=' '>' '{' statements '}'
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
