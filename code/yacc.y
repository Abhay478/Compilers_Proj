%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);

%}

// keywords
%token KW_CLAIM KW_IS KW_GROUP KW_RING KW_FIELD KW_SPACE KW_LET KW_RETURN KW_IF KW_ELSE KW_WHILE KW_FOR KW_IN KW_SWITCH KW_CASE KW_DEFAULT KW_BREAK KW_CONTINUE KW_FN KW_FORGE KW_AS KW_STRUCT KW_ENUM KW_WITH

// other
%token IDENT PRIMITIVE_DTYPE LIT_INT LIT_FLOAT LIT_STR LIT_CHAR rel_op KW_TRUE KW_FALSE ASSIGN_OP
%token INCR DECR ARROW VARIANT SLICE AND OR // Two character operators.

%left '['
%left INCR DECR
%left '.'
%right '!' // Also unary minus, ref, and deref - see `expression` definition.
%left KW_AS 
%left '@'
%left '*' '/' '%' 
%left '+' '-' 
%left rel_op '>' '<'
%left KW_IN
%left AND
%left OR

%start P

%%
P               : declarations // globals
                | P function
                | P struct
                | P forge
                | P enum
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
                | call ';'
                | return_stmt ';' 
                | conditional
                | switch_case
                | loop_stmt
                /* | PRINT '(' pass_param_list ')' ';' */
                | KW_BREAK ';'
                | KW_CONTINUE ';' 
                | archetype_claim              
                ;

// TODO: use these instead
generic         : IDENT '<' type_args '>'
                ;

type_args       : type_arg ',' type_args
                | type_arg
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

type            : PRIMITIVE_DTYPE
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

constant        : LIT_CHAR
                | LIT_FLOAT
                | LIT_INT
                | LIT_STR
                | KW_TRUE
                | KW_FALSE
                | IDENT VARIANT IDENT // Enum variant
                ;

expression      : '(' expression ')'
                | array_access
                | '!' expression
                | '-' expression                %prec '!'  // Unary minus has precedence of '!', not subtraction.
                | '*' expression                %prec '!'  // Dereference has precedence of '!', not multiplication.   
                | '&' expression                %prec '!'  // Address-of has precedence of '!', bitwise operators do not exist.
                | expression '.' IDENT
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

cart_value      : '(' expression ',' ')'
                | '(' expression ',' cart_value_list ')'
                ;

cart_value_list : expression ',' cart_value_list
                | expression
                ;

return_stmt     : KW_RETURN expression 
                ;

call            : IDENT '(' expr_list ')' 
                ;

expr_list       : expression ',' expr_list
                | epsilon
                ;

unary_operation : expression INCR
                | expression DECR
                ;

array_access    : expression array_index
                ;

array_decl      : '[' expr_list ']'
                ;

array_index     : '[' expression ',' expr_list ']' // Access using commas, like a[1, 2] instead of a[1][2]. More mathy, more convenient.
                | '[' expression SLICE expression ']' // subarray access
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
                | assignment
                | epsilon
                ;

switch_case     : KW_SWITCH '(' expression ')' '{' sc_blocks KW_DEFAULT ':' statements '}'
                | KW_SWITCH '(' expression ')' '{' sc_blocks '}'
                ;

sc_blocks       : KW_CASE constant ':' statements sc_blocks
                | epsilon
                ; // NOTE: Does not cascade

archetype_claim : KW_CLAIM IDENT KW_IS archetype '{' type_def rule_list '}' ';'
                | KW_CLAIM IDENT KW_IS archetype KW_WITH '(' ident_list ')' ';'
                ;

archetype       : KW_GROUP
                | KW_RING
                | KW_FIELD
                | KW_SPACE
                ;

type_def        : archetype '=' type ';'
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

identity_rule   : '(' IDENT '=' LIT_INT ')' ARROW body // LIT_INT should be 0 or 1, depending on the archetype
                ;

negation_rule   : '(' IDENT '=' '-' IDENT ')' ARROW body
                ;

inverse_rule    : '(' IDENT '=' LIT_INT '/' IDENT ')' ARROW body // LIT_INT must be 1
                ;

function        : function_header body 
                ;

function_header : KW_FN IDENT '(' param_list ')' ':' type
                ;

type_var_list   : type_var_list ',' type_var
                | type_var
                ;

param_list      : type_var_list
                ;

type_var        : IDENT ':' type
                ;

struct          : KW_STRUCT IDENT '{' attr_list '}'
                ;

attr_list       : type_var_list
                ;

enum            : KW_ENUM IDENT '{' variant_list '}'
                ;

ident_list      : ident_list ',' IDENT
                | IDENT
                ;
variant_list    : ident_list
                ;

forge           : KW_FORGE '(' param_list ')' KW_AS type body
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
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
