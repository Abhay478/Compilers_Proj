%option yylineno
%{
    #include "y.tab.h"
%}
dig [0-9]
num (-?dig+)
real (-?dig+)(\.dig+)?
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

%%

if {return IF;}
else {return ELSE;}
for {return FOR;}
while {return WHILE;}
fn {return FN;}
let {return LET;}
return {return RETURN;}
claim {return CLAIM;}
"ring morph" {return RMORPH;}
"group morph" {return GMORPH;}
forge {return FORGE;}
is {return IS;}
struct {return STRUCT;}
enum {return ENUM;}
true {return TRUE;}
false {return FALSE;}
void {return VOID;}

id {return ID;} // we need to change YYSTYPE to return ID.name. This after making sure lexer and parser work correctly.

{acc_op} {return yytext;} // Access operators
{rel_op} {return yytext;} // relational operators
{aug_op} {return yytext;} // augmented operators
{arith_op} {return yytext;} // arithmetic operators
{log_op} {return yytext;} // logical operators
{misc_ops} {return yytext;} // Miscellaneous: absolute value idea, we forgot to put in specs ig. Also, references.

{spl} {return spl;} // special characters
{punct} {return yytext;} // punctuation


{char_c} {return char_c;}
{str_c} {return str_c;}
{num} {return num;}

{uint} {return uint;}
{sint} {return sint;}
Group {return GROUP;}
Ring {return RING;}
Field {return FIELD;}
Space {return SPACE;}


%%

