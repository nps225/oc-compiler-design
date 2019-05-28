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

%right TOK_IF TOK_ELSE
%right  '='
%left   TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left   '+' '-'
%left   '*' '/' '%'
%right  '^'
%right  POS NEG TOK_NOT

%start  program


%%

program : stmtseq               { $$ = $1 = nullptr; }
        ;

stmtseq : stmtseq expr ';'      { destroy ($3); $$ = $1->adopt ($2); }
        | stmtseq error ';'     { destroy ($3); $$ = $1; }
        | stmtseq ';'           { destroy ($2); $$ = $1; }
        |                       { $$ = parser::root; }
        ;

vardecl : TOK_IDENT '=' expr    { $$ = $1; }

expr    : '(' expr ')'          { destroy ($1, $3); $$ = $2; }
        | binop                 { $$ = $1; }
        | unop                  { $$ = $1; }
        ;

binop   : expr '=' expr         { $$ = $2->adopt ($1, $3); }
        | expr '+' expr         { $$ = $2->adopt ($1, $3); }
        | expr '-' expr         { $$ = $2->adopt ($1, $3); }
        | expr '*' expr         { $$ = $2->adopt ($1, $3); }
        | expr '/' expr         { $$ = $2->adopt ($1, $3); }
        | expr '^' expr         { $$ = $2->adopt ($1, $3); }
        | expr '%' expr         { $$ = $2->adopt ($1, $3); }
        | expr TOK_EQ expr         { $$ = $2->adopt ($1, $3); }
        | expr TOK_NE expr         { $$ = $2->adopt ($1, $3); }
        | expr TOK_LT expr         { $$ = $2->adopt ($1, $3); }
        | expr TOK_LE expr         { $$ = $2->adopt ($1, $3); }
        | expr TOK_GT expr         { $$ = $2->adopt ($1, $3); }
        | expr TOK_GE expr         { $$ = $2->adopt ($1, $3); }
        ;

unop    : '+' expr %prec POS    { $$ = $1->adopt_sym ($2, POS); }
        | '-' expr %prec NEG    { $$ = $1->adopt_sym ($2, NEG); }
        | TOK_NOT expr %prec POS    { $$ = $1->adopt_sym ($2, POS); }

%%

const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

