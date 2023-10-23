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
ring {return KW_RING;}
group {return KW_GROUP;}
morph {return KW_MORPH;}
forge {return KW_FORGE;}
is {return KW_IS;}
struct {return KW_STRUCT;}
enum {return KW_ENUM;}
true {return KW_TRUE;}
false {return KW_FALSE;}

{pdt} {return PRIMITIVE_DTYPE;} 
Group {return GROUP;}
Ring {return RING;}
Field {return FIELD;}
Space {return SPACE;}

{op} {return yytext;} /* operators */

{spl}|{punct} {return yytext;} /* punctuation and special characters */


{real} {return LIT_FL;}

{id} {return IDENT;} /* we need to change YYSTYPE to return ID.name. This after making sure lexer and parser work correctly. */


%%

