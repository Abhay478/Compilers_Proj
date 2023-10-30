%option yylineno
%{
    #include "y.tab.h"
%}
dig [0-9]
num (-?{dig}+)
real -?{dig}+\.{dig}+
id [[:alpha:]_][[:alnum:]_]*
str_c \"([^"]|(\\\"))*\"
char_c \'\\?([^']|(\\'))\'

rel_op (==|!=|<=|>=)
spl [\(\)\{\}\[\]]
arith_op (\+|\-|\*|\/|\%)
assign_op {arith_op}=
punct [,;:]
misc_ops (@|=|&)

uint (u8|u16|u32|u64)
sint (i8|i16|i32|i64)

pdt ({uint}|{sint}|float|bool|char|str)

op ('>'|'<'|'!'|{arith_op}|\.|{misc_ops})

%%

{char_c} {return LIT_CHAR;}
{str_c} {return LIT_STR;}
{num} {return LIT_INT;}

"//.*\n" {}
"/\*.*\*/" {}

if {return KW_IF;}
else {return KW_ELSE;}
for {return KW_FOR;}
while {return KW_WHILE;}
fn {return KW_FN;}
let {return KW_LET;}
return {return KW_RETURN;}
claim {return KW_CLAIM;}
forge {return KW_FORGE;}
as {return KW_AS;}
is {return KW_IS;}
struct {return KW_STRUCT;}
enum {return KW_ENUM;}
true {return KW_TRUE;}
false {return KW_FALSE;}
break {return KW_BREAK;}
continue {return KW_CONTINUE;}
default {return KW_DEFAULT;}
switch {return KW_SWITCH;}
case {return KW_CASE;}
in {return KW_IN;}
Ring {return KW_RING;}
Group {return KW_GROUP;}
Field {return KW_FIELD;}
Space {return KW_SPACE;}

"++" {return INCR;}
"--" {return DECR;}
"=>" {return ARROW;}
"::" {return VARIANT;}
".." {return SLICE;}
{rel_op} {return rel_op;}
"&&" {return AND;}
"||" {return OR;}

{pdt} {return PRIMITIVE_DTYPE;} 

{op} {return yytext[0];} /* single character operators */

{assign_op} {return ASSIGN_OP;} /* assignment operators */

{spl}|{punct} {return yytext[0];} /* punctuation and special characters */


{real} {return LIT_FLOAT;}

{id} {return IDENT;} /* we need to change YYSTYPE to return ID.name. This after making sure lexer and parser work correctly. */


%%

