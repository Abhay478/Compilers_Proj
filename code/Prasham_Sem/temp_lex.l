%option yylineno
%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.hpp"
    #define seq_token(a) fprintf(token_stream, "%s: %s\n", (a), yytext)
    extern FILE * token_stream;

    typedef yy::parser::token_kind_type tt;
%}
dig [0-9]
num (-?{dig}+)
real -?{dig}+\.{dig}+
id [[:alpha:]_][[:alnum:]_]*
str_c \"([^"]|(\\\"))*\"
char_c \'([^\\']|\\.)\'

rel_op (==|!=|<=|>=)
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
        return tt::LIT_CHAR; 
    }
{str_c} {
        seq_token("literal"); 
        yylval.lit_str = new std::string(strndup(yytext+1, strlen(yytext)-2));
        return tt::LIT_STR; 
    }
{num} { 
        seq_token("literal"); 
        yylval.lit_int = atoi(yytext);
        return tt::LIT_INT; 
    }
{real} { 
        seq_token("literal"); 
        yylval.lit_float = atof(yytext);
        return tt::LIT_FLOAT; 
    }

if          { seq_token("reserved keyword"); return tt::KW_IF; }
else        { seq_token("reserved keyword"); return tt::KW_ELSE; }
for         { seq_token("reserved keyword"); return tt::KW_FOR; }
while       { seq_token("reserved keyword"); return tt::KW_WHILE; }
fn          { seq_token("reserved keyword"); return tt::KW_FN; }
let         { seq_token("reserved keyword"); return tt::KW_LET; }
return      { seq_token("reserved keyword"); return tt::KW_RETURN; }
claim       { seq_token("reserved keyword"); return tt::KW_CLAIM; }
forge       { seq_token("reserved keyword"); return tt::KW_FORGE; }
as          { seq_token("reserved keyword"); return tt::KW_AS; }
is          { seq_token("reserved keyword"); return tt::KW_IS; }
struct      { seq_token("reserved keyword"); return tt::KW_STRUCT; }
enum        { seq_token("reserved keyword"); return tt::KW_ENUM; }
true        { seq_token("reserved keyword"); return tt::KW_TRUE; }
false       { seq_token("reserved keyword"); return tt::KW_FALSE; }
break       { seq_token("reserved keyword"); return tt::KW_BREAK; }
continue    { seq_token("reserved keyword"); return tt::KW_CONTINUE; }
default     { seq_token("reserved keyword"); return tt::KW_DEFAULT; }
switch      { seq_token("reserved keyword"); return tt::KW_SWITCH; }
case        { seq_token("reserved keyword"); return tt::KW_CASE; }
in          { seq_token("reserved keyword"); return tt::KW_IN; }
Ring        { seq_token("reserved keyword"); return tt::KW_RING; }
Group       { seq_token("reserved keyword"); return tt::KW_GROUP; }
Field       { seq_token("reserved keyword"); return tt::KW_FIELD; }
Space       { seq_token("reserved keyword"); return tt::KW_SPACE; }

{pdt} { 
        seq_token("data type"); 
        yylval.prim_type = get_pdt(yytext);
        return tt::PRIMITIVE_DTYPE; 
    }

"++"        { seq_token("operator"); return tt::INCR; }
"--"        { seq_token("operator"); return tt::DECR; }
"=>"        { seq_token("operator"); return tt::ARROW; }
"::"        { seq_token("operator"); return tt::VARIANT; }
".."        { seq_token("operator"); return tt::SLICE; }
{rel_op}    { seq_token("operator"); return tt::rel_op; }
"&&"        { seq_token("operator"); return tt::AND; }
"||"        { seq_token("operator"); return tt::OR; }

{op}        { seq_token("operator"); return yytext[0]; } /* single character operators */

{assign_op} { seq_token("operator"); return tt::ASSIGN_OP; } /* assignment operators */

{spl}       { seq_token("special characters"); return yytext[0];} /* special characters */
{punct}     { seq_token("punctuation"); return yytext[0];} /* punctuation */

{id} { 
        seq_token("ID"); 
        yylval.ident = new std::string(strdup(yytext));
        return tt::IDENT;
    } /* we need to change YYSTYPE to return ID.name. This after making sure lexer and parser work correctly. */

{ws} {}
{comment} {}

%%

