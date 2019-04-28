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
OCTAL           [0-7]
HEX             [0-9a-fA-F]
DECIMAL         (^[^0]{DIGIT}*)
OCTALNUM        (0{OCTAL}*)
HEXNUM          ((0x|0X){HEX}*)        
MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)
STRING          (\"([^\\"\n]|\\[\\’"0nt])*\")
CHAR            ('([^\\'\n]|\\[\\'"0nt])')
NUM             ({HEXNUM}|{DECIMAL}|{OCTALNUM})
NUMBER          ({MANTISSA}{EXPONENT}?)
NOTNUMBER       ({MANTISSA}[Ee][+-]?)
IDENT           ({LETTER}({LETTER}|{DIGIT})*)
BADSTRING       (\"([^"])*\"|\")
BADCHAR         ('([^'])*'|')
BADIDENT        ({DIGIT}{IDENT})

%%

"#".*           { lexer::include(); }
[ \t]+          { }
\n              { lexer::newline(); }

">="             { return lexer::token (TOK_GE); }
"<="             { return lexer::token (TOK_LE); }
"="             { return lexer::token ('='); }
"=="             { return lexer::token (TOK_EQ); }
">"             { return lexer::token (TOK_GT); }
"<"             { return lexer::token (TOK_LT); }
","             { return lexer::token (','); }
"+"             { return lexer::token ('+'); }
"-"             { return lexer::token ('-'); }
"*"             { return lexer::token ('*'); }
"/"             { return lexer::token ('/'); }
"%"             { return lexer::token ('%'); }
"^"             { return lexer::token ('^'); }
"("             { return lexer::token ('('); }
")"             { return lexer::token (')'); }
"{"             { return lexer::token ('{'); }
"}"             { return lexer::token ('}'); }
"["             { return lexer::token ('['); }
"]"             { return lexer::token (']'); }
";"             { return lexer::token (';'); }
"if"           { return lexer::token (TOK_IF); }
"else"           { return lexer::token (TOK_ELSE); }
"struct"           { return lexer::token (TOK_STRUCT); }
"array"           { return lexer::token (TOK_ARRAY); }
"not"           { return lexer::token (TOK_NOT); }
"alloc"           { return lexer::token (TOK_ALLOC); }
"ptr"           { return lexer::token (TOK_PTR); }
"->"           { return lexer::token (TOK_ARROW); }
"while"         { return lexer::token (TOK_WHILE); }
"void"          { return lexer::token (TOK_VOID); }
"return"        { return lexer::token (TOK_RETURN); }
"int"           { return lexer::token (TOK_INT); }
"char"          { return lexer::token (TOK_CHAR); }
"string"        { return lexer::token (TOK_STRING); }

{CHAR}          { return lexer::token (TOK_CHARCON); }
{STRING}        { return lexer::token (TOK_STRINGCON); }
{NUMBER}           { return lexer::token (TOK_INTCON); }
{IDENT}         { return lexer::token (TOK_IDENT); }

{NOTNUMBER}     { return lexer::badtoken (TOK_INT); }
{BADSTRING}               { yyerror("bad string"); }
{BADCHAR}               { yyerror("bad char"); }
{BADIDENT}               { yyerror("bad identifier"); }
.               { lexer::badchar (*yytext); }

%%

