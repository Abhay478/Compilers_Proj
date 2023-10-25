%{
	#include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    int yylex();
    FILE *token_stream;
    FILE *parsed_output;
    extern FILE* yyin;
    extern int yylineno;
	void yyerror(const char *s);
    int return_count = 0;
    int error_flag = 0;
    int line_no = 0;
    int file_no = 0;
%}

%token DECLARE DATA_TYPE VOID ID EXPR NUMBER STRING_CONSTANT RETURN ADD MUL SUB DIV POSTINCR POSTDECR CALL ARROW_OPERATOR THIS IN_CASE_THAT DO OTHERWISE LT LEQ GT GEQ EQ NE NEG LOOP WHILE FOR AND OR LOCAL GLOBAL CLASS TRUE FALSE

%start start_program

%%
start_program           : class_declaration start_program
                        | method start_program
                        | epsilon
                        | error '\n' { error_flag = 1; yyerrok; }
                        ;

class_declaration       : CLASS ID '[' NUMBER ']' {fprintf(parsed_output, " : class definition ");} '{' class_body '}' 
                        | CLASS ID {fprintf(parsed_output, " : class definition ");} '{' class_body '}'
                        ;

class_body              : declaration {fprintf(parsed_output, " : declaration statement ");} class_body
                        | method class_body
                        | epsilon
                        ;

method                  : scope return_type ID R {fprintf(parsed_output, " : function definition ");} '{' statements '}' {if(return_count == 0) { printf("Error in \"public_test_%d.clike\" at line %d: function has no return statement!\n", file_no, line_no); exit(1);} else return_count = 0;}
                        ;

return_type             : DATA_TYPE
                        | VOID
                        ;

scope                   : GLOBAL
                        | LOCAL
                        ;

R                       : '[' NUMBER ']' '(' decl_param_list ')'
                        | '(' ')'
                        ;

decl_param_list         : DATA_TYPE ID ',' decl_param_list
                        | DATA_TYPE ID
                        | VOID ID ',' decl_param_list
                        | VOID ID
                        ;

statements              : statement statements
                        | '{' statements '}' statements
                        | epsilon
                        ;

return_stmt             : RETURN predicate {return_count++;} ';'
                        | RETURN VOID {return_count++;} ';'
                        ;

statement               : declaration {fprintf(parsed_output, " : declaration statement ");}
                        | expression {fprintf(parsed_output, " : expression statement ");}
                        | call_stmt_standalone
                        | conditional_stmt
                        | loop_stmt
                        | return_stmt {fprintf(parsed_output, " : return statement ");}
                        | unary_op_standalone ';' {fprintf(parsed_output, " : call statement ");}
                        | error '\n' { error_flag = 1; yyerrok; }
                        ;

declaration             : DECLARE DATA_TYPE A ';'
                        | DECLARE ID A ';'
                        ;

A                       : ID ',' A 
                        | ID
                        ;

expression              : EXPR ID '=' RHS_expr ';'
                        | EXPR ID '=' call_stmt ';'
                        | EXPR ID '=' TRUE ';'
                        | EXPR ID '=' FALSE ';'
                        ;

RHS_expr                : ID
                        | constant
                        | binary_op
                        | unary_op_rhs
                        ;

constant                : NUMBER
                        | STRING_CONSTANT
                        ;

binary_op               : operator '(' temp ',' temp ')' 
                        ;

temp                    : binary_op
                        | NUMBER
                        | ID
                        | unary_op_rhs
                        | call_stmt
                        | TRUE
                        | FALSE
                        ;

operator                : ADD
                        | MUL
                        | DIV
                        | SUB
                        ;

unary_op_standalone     : POSTINCR '(' ID ')'
                        | POSTDECR '(' ID ')'
                        ;

unary_op_rhs            : POSTINCR '(' Y2 ')' 
                        | POSTDECR '(' Y2 ')' 
                        ;

Y2                      : NUMBER
                        | ID
                        | binary_op
                        | call_stmt
                        | unary_op_rhs
                        ;

call_stmt_standalone    : CALL ID ARROW_OPERATOR ID Z ';' {fprintf(parsed_output, " : call statement with object ");}
                        | CALL THIS ARROW_OPERATOR ID Z ';'{fprintf(parsed_output, " : call statement with object ");}
                        | CALL ID Z ';' {fprintf(parsed_output, " : call statement ");}
                        ;
call_stmt               : CALL ID ARROW_OPERATOR ID Z 
                        | CALL THIS ARROW_OPERATOR ID Z 
                        | CALL ID Z 
                        ;

Z                       : '[' NUMBER ']' '(' pass_param_list ')'
                        | '(' ')'
                        ;

pass_param_list         : RHS_expr ',' pass_param_list
                        | RHS_expr
                        | call_stmt
                        | TRUE
                        | FALSE
                        ;


conditional_stmt        : IN_CASE_THAT '(' predicate ')' {fprintf(parsed_output, " : conditional statement ");} DO '{' statements '}' H 
                        ;

H                       : OTHERWISE {fprintf(parsed_output, " : conditional statement ");} '{' statements '}'
                        | epsilon
                        ;

predicate               : U logical_op predicate 
                        | U
                        | NEG predicate
                        ;

U                       : binary_op
                        | unary_op_rhs
                        | ID
                        | constant
                        | call_stmt
                        | '(' predicate ')'
                        | TRUE
                        | FALSE
                        ;

logical_op              : LT 
                        | GT
                        | GEQ
                        | LEQ
                        | EQ
                        | NE
                        | NEG
                        | AND
                        | OR
                        ;

loop_stmt               : LOOP WHILE '(' predicate ')' {fprintf(parsed_output, " : loop statement ");} DO '{' statements '}'
                        | FOR '(' expression predicate ';' V ')' {fprintf(parsed_output, " : loop statement ");} '{' statements '}'
                        ;

V                       : unary_op_rhs
                        | epsilon
                        ;

epsilon                 : ;

%%

int main() {
    
    // set the value of n = no. of test cases here:
    int n = 3;
    for(int i = 1; i <= n; i++){
        line_no = 0;
        file_no = i;
        char parsed_file[100];
        char input_file[100];
        char token_file[100];
        sprintf(parsed_file, "pt_parser_%d.parsed", i);
        sprintf(input_file, "public_test_%d.clike", i);
        sprintf(token_file, "pt_seq_tokens_%d.txt", i);
        parsed_output = fopen(parsed_file, "w");
        token_stream = fopen(token_file, "w");
        yyin = fopen(input_file, "r");
        fprintf(token_stream, "Name: Prasham Walvekar\nID: CS21BTECH11047\n\n");
        yyparse();
    }
}

void yyerror(const char* msg) {
    //fprintf(parsed_output, " : invalid statement\n");
    error_flag = 1;
}
                        