%option yylineno
%{
    #include "y.tab.h"
%}
dig [0-9]
num (-?{dig}+)
real (-?{dig}+\.{dig}+)
id [[:alpha:]_][[:alnum:]_]*
str_c \"([^"]|(\\\"))*\"
char_c \'\\?([^']|(\\'))\'

rel_op (>|<|==|!=|<=|>=)
log_op (&&|"||"|!)
spl [\(\)\{\}\[\]]
arith_op (\+|\-|\*|\/|\%)
aug_op {arith_op}=
acc_op (\.|::)
punct [,;:]
misc_ops (@|"=>"|=|&|"|")

uint (u8|u16|u32|u64)
sint (i8|i16|i32|i64)

pdt ({uint}|{sint}|float|bool|char)

op ({rel_op}|{log_op}|{arith_op}|{aug_op}|{acc_op}|{misc_ops})

%%

{char_c} {return LIT_CHAR;}
{str_c} {return LIT_STR;}
{num} {return LIT_INT;}
{real}
"//.*\n" {}
"/\*.*\*/" {}

"&&" {return LOGICAL_AND;}
"||" {return LOGICAL_OR;}
"!" {return LOGICAL_NOT;}
{arith_op} {return yytext[0];}

">" {return yytext[0];}
"<" {return yytext[0];}
">=" {return GTEQ;}
"<=" {return LTEQ;}
"==" {return EQ;}
"!=" {return NEQ;}

let {return KW_LET;}
return {return KW_RETURN;}
if {return KW_IF;}
else {return KW_ELSE;}
for {return KW_FOR;}
while {return KW_WHILE;}
switch {return KW_SWITCH;}
case {return KW_CASE;}
default { return KW_DEFAULT;}
break {return KW_BREAK;}
continue {return KW_CONTINUE;}

Cyclic {return KW_CYCLIC;}
BigRational {return KW_BIG_RATIONAL;}
Complex {return KW_COMPLEX;}
Symmetric {return KW_SYMMETRIC;}
Alternating {return KW_ALTERNATING;}
Dihedral {return KW_DIHEDRAL;}
InvMat {return KW_INV_MAT;}
BigInt {return KW_BIGINT;}
Matrix {return KW_MATRIX;}
Polynomial {return KW_POLYNOMIAL;}
Vec {return KW_VEC;}
Buf {return KW_BUF;}

{pdt} {return PRIMITIVE_DTYPE;} 

{op} {return yytext[0];} /* operators */

{punct} {return yytext[0];}
{spl} {return yytext[0];} /* punctuation and special characters */


{id} {return IDENT;} /* we need to change YYSTYPE to return ID.name. This after making sure lexer and parser work correctly. */

" " ;
\n ;

. {printf("Error: Unrecognised token"); exit(1);}

%%
int yywrap(){}
