%option yylineno
%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.hpp"
    //#define seq_token(a) fprintf(token_stream, "%s: %s\n", (a), yytext)
    extern FILE * token_stream;

    void seq_token(const char * type) {
        fprintf(token_stream, "%d %s: %s\n", yylineno, type, yytext);
        fflush(token_stream);
    }
%}
dig [0-9]
num (-?{dig}+)
real -?{dig}+\.{dig}+
id [[:alpha:]_][[:alnum:]_]*
str_c \"([^"]|(\\\"))*\"
char_c \'([^\\']|\\.)\'

cmp_op (<=|>=)
eq_op (==|!=)
spl [\(\)\{\}\[\]]
arith_op (\+|\-|\*|\/|\%)
assign_op {arith_op}=
punct [,;:]
misc_ops (@|=|&)

uint (u8|u16|u32|u64)
sint (i8|i16|i32|i64)

pdt ({uint}|{sint}|float|bool|char|str)

op (>|<|!|{arith_op}|\.|{misc_ops})

short_comment \/\/.*
long_comment_inner [^*]|\**[^/]
long_comment \/\*({long_comment_inner})*\*\/
comment {short_comment}|{long_comment}
ws [\r\n\t ]

%%

{char_c} { 
        seq_token("literal"); 
        yylval.lit_char = yytext[1]; 
        return LIT_CHAR; 
    }
{str_c} {
        seq_token("literal"); 
        yylval.lit_str = new std::string(yytext);
        return LIT_STR; 
    }
{num} { 
        seq_token("literal"); 
        yylval.lit_int = atoi(yytext);
        return LIT_INT; 
    }
{real} { 
        seq_token("literal"); 
        yylval.lit_float = atof(yytext);
        return LIT_FLOAT; 
    }

if          { seq_token("reserved keyword"); return KW_IF; }
else        { seq_token("reserved keyword"); return KW_ELSE; }
for         { seq_token("reserved keyword"); return KW_FOR; }
while       { seq_token("reserved keyword"); return KW_WHILE; }
fn          { seq_token("reserved keyword"); return KW_FN; }
this        { seq_token("reserved keyword"); return KW_THIS; }
let         { seq_token("reserved keyword"); return KW_LET; }
return      { seq_token("reserved keyword"); return KW_RETURN; }
claim       { seq_token("reserved keyword"); return KW_CLAIM; }
forge       { seq_token("reserved keyword"); return KW_FORGE; }
as          { seq_token("reserved keyword"); return KW_AS; }
is          { seq_token("reserved keyword"); return KW_IS; }
with        { seq_token("reserved keyword"); return KW_WITH; }
struct      { seq_token("reserved keyword"); return KW_STRUCT; }
enum        { seq_token("reserved keyword"); return KW_ENUM; }
true        { seq_token("reserved keyword"); return KW_TRUE; }
false       { seq_token("reserved keyword"); return KW_FALSE; }
break       { seq_token("reserved keyword"); return KW_BREAK; }
continue    { seq_token("reserved keyword"); return KW_CONTINUE; }
default     { seq_token("reserved keyword"); return KW_DEFAULT; }
switch      { seq_token("reserved keyword"); return KW_SWITCH; }
case        { seq_token("reserved keyword"); return KW_CASE; }
in          { seq_token("reserved keyword"); return KW_IN; }
Ring        { seq_token("reserved keyword"); return KW_RING; }
Group       { seq_token("reserved keyword"); return KW_GROUP; }
Field       { seq_token("reserved keyword"); return KW_FIELD; }
Space       { seq_token("reserved keyword"); return KW_SPACE; }

{pdt} { 
        seq_token("data type"); 
        yylval.prim_type = get_pdt(yytext);
        return PRIMITIVE_DTYPE; 
    }

"++"        { seq_token("operator"); return INCR; }
"--"        { seq_token("operator"); return DECR; }
"=>"        { seq_token("operator"); return ARROW; }
"::"        { seq_token("operator"); return VARIANT; }
".."        { seq_token("operator"); return SLICE; }
"&&"        { seq_token("operator"); return AND; }
"||"        { seq_token("operator"); return OR; }

{op}        { seq_token("operator"); return yytext[0]; } /* single character operators */

{cmp_op}    {
    seq_token("operator");
    yylval.op = new std::string(yytext);
    return CMP_OP;
}
{eq_op}     {
    seq_token("operator");
    yylval.op = new std::string(yytext);
    return EQ_OP;
}
{assign_op} {
    seq_token("operator");
    return ASSIGN_OP;
}

{spl}       { seq_token("special characters"); return yytext[0];} /* special characters */
{punct}     { seq_token("punctuation"); return yytext[0];} /* punctuation */

{id} { 
        seq_token("ID"); 
        yylval.ident = new std::string(strdup(yytext));
        return IDENT;
    } /* we need to change YYSTYPE to return ID.name. This after making sure lexer and parser work correctly. */

{ws} {}
{comment} {}

%%

