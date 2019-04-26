/* $Id: lexer.l,v 1.9 2019-04-18 13:33:21-07 - - $ */

%{

#include "lyutils.h"

#define YY_USER_ACTION  { lexer::advance(); }

%}

%option 8bit
%option debug
%option nobackup
%option nodefault
%option noinput
%option nounput
%option noyywrap
%option warn
/*%option verbose*/

LETTER          [A-Za-z_]
DIGIT           [0-9]
MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)
NUMBER          ({MANTISSA}{EXPONENT}?)
NOTNUMBER       ({MANTISSA}[Ee][+-]?)
IDENT           ({LETTER}({LETTER}|{DIGIT})*)

%%

"#".*           { lexer::include(); }
[ \t]+          { }
\n              { lexer::newline(); }

">="             { return lexer::token (TOK_GE); }
"<="             { return lexer::token (TOK_LE); }
"="             { return lexer::token ('='); }
">"             { return lexer::token (TOK_GT); }
"<"             { return lexer::token (TOK_LT); }
"+"             { return lexer::token ('+'); }
"-"             { return lexer::token ('-'); }
"*"             { return lexer::token ('*'); }
"/"             { return lexer::token ('/'); }
"^"             { return lexer::token ('^'); }
"("             { return lexer::token ('('); }
")"             { return lexer::token (')'); }
"{"             { return lexer::token ('{'); }
"}"             { return lexer::token ('}'); }
";"             { return lexer::token (';'); }
"not"           { return lexer::token (TOK_NOT); }
"int"           { return lexer::token (TOK_INTCON); }
"char"          { return lexer::token (TOK_CHARCON); }
"while"         { return lexer::token (TOK_WHILE); }
"void"          { return lexer::token (TOK_VOID); }
"return"        { return lexer::token (TOK_RETURN); }

{NUMBER}        { return lexer::token (TOK_INT); }
{IDENT}         { return lexer::token (TOK_IDENT); }

{NOTNUMBER}     { return lexer::badtoken (TOK_INT); }
.               { lexer::badchar (*yytext); }

%%

