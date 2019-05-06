// $Id: parser.y,v 1.14 2016-10-06 16:26:41-07 - - $

%{

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "lyutils.h"

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%destructor { destroy ($$); } <>
%printer { astree::dump (yyoutput, $$); } <>

%initial-action {
   parser::root = new astree (ROOT, {0, 0, 0}, "<<ROOT>>");
}

%token  ROOT IDENT NUMBER
%token  TOK_GE TOK_LE TOK_EQ TOK_NE TOK_GT TOK_LT
%token  TOK_IF TOK_ELSE TOK_STRUCT TOK_ARRAY TOK_NOT
%token  TOK_ALLOC TOK_PTR TOK_ARROW TOK_WHILE TOK_VOID
%token  TOK_RETURN TOK_INT TOK_CHAR TOK_STRING
%token  TOK_CHARCON TOK_STRINGCON TOK_INTCON TOK_IDENT

%right  '='
%left   '+' '-'
%left   '*' '/'
%right  '^'
%right  POS NEG

%start  program


%%

program : stmtseq               { $$ = $1 = nullptr; }
        ;

stmtseq : stmtseq expr ';'      { destroy ($3); $$ = $1->adopt ($2); }
        | stmtseq error ';'     { destroy ($3); $$ = $1; }
        | stmtseq ';'           { destroy ($2); $$ = $1; }
        |                       { $$ = parser::root; }
        ;

expr    : expr '=' expr         { $$ = $2->adopt ($1, $3); }
        | expr '+' expr         { $$ = $2->adopt ($1, $3); }
        | expr '-' expr         { $$ = $2->adopt ($1, $3); }
        | expr '*' expr         { $$ = $2->adopt ($1, $3); }
        | expr '/' expr         { $$ = $2->adopt ($1, $3); }
        | expr '^' expr         { $$ = $2->adopt ($1, $3); }
        | '+' expr %prec POS    { $$ = $1->adopt_sym ($2, POS); }
        | '-' expr %prec NEG    { $$ = $1->adopt_sym ($2, NEG); }
        | '(' expr ')'          { destroy ($1, $3); $$ = $2; }
        | IDENT                 { $$ = $1; }
        | NUMBER                { $$ = $1; }
        ;

%%

const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

