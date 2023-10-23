%option yylineno
%{
    #include "y.tab.h"
%}
dig [0-9]
num (-?{dig}+)
real (-?{dig}+)(\.{dig}+)?
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

%%

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

{id} {return IDENT;} // we need to change YYSTYPE to return ID.name. This after making sure lexer and parser work correctly.

{acc_op} {return yytext;} // Access operators
{rel_op} {return yytext;} // relational operators
{aug_op} {return yytext;} // augmented operators
{arith_op} {return yytext;} // arithmetic operators
{log_op} {return yytext;} // logical operators
{misc_ops} {return yytext;} // Miscellaneous: absolute value idea, we forgot to put in specs ig. Also, references.

{spl} {return spl;} // special characters
{punct} {return yytext;} // punctuation


{char_c} {return LIT_CHAR;}
{str_c} {return LIT_STR;}
{num} {return LIT_INT;}
{real} {return LIT_FL;}

{pdt} {return PRIMITIVE_DTYPE;} 
Group {return GROUP;}
Ring {return RING;}
Field {return FIELD;}
Space {return SPACE;}


%%

