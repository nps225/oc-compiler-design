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
   parser::root = new astree (ROOT, {0, 0, 0}, "");
}

%token  ROOT IDENT NUMBER TYPE_ID FUNCTION TOK_PARAM TOK_PROTOTYPE
%token  BLOCK
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

%start  start

%%

start : program               { $$ = $1 = nullptr; }
      ;

program : program function      { $$ = $1->adopt($2); }
        | program error ';'     { destroy ($3); $$ = $1; }
        | program ';'           { destroy ($2); $$ = $1; }
        |                       { $$ = parser::root; }
        ;

function : identif '(' ')' ';' 
               {  
                  destroy ( $3, $4) ; 
                  $2 = $2->symChange($2,TOK_PARAM);
                  $$ = new astree(FUNCTION, $1->lloc, "");
                  $$ = $$->adopt($1,$2);
               }
         | identif param ')' ';' 
               {
                  destroy($3,$4);
                  $$ = new astree(FUNCTION, $1->lloc, "");
                  $$ = $$->adopt($1,$2);
               }
         | identif '(' ')' block
               {
                 destroy($3);
                 $2 = $2->symChange($2,TOK_PARAM);
                 $$ = new astree(FUNCTION,$1->lloc,"");
                 $$ = $$->adopt($1,$2);
                 $$ = $$->adopt($4);
               }
	| identif param ')' block
               {
                 destroy($3);
                 $$ = new astree(FUNCTION,$1->lloc,"");
                 $$ = $$->adopt($1,$2);
                 $$ = $$->adopt($4);
               }
         ;

identif : type_id TOK_IDENT     
               {
                  $$ = new astree(TYPE_ID, $1->lloc,"");
                  $$ = $$->adopt($1,$2);
               }
         ;

param : '(' identif 
               {
                  $$ = new astree(TOK_PARAM, $1->lloc, "");
                  $$ = $$->adopt($2);
               }
      | '(' identif ',' identif
               {
                  destroy($3);
                  $$ = new astree(TOK_PARAM, $1->lloc, "");
                  $$ = $$->adopt($2,$4);
               }
      ;



block: '{' 
               {
                  $$ = new astree(BLOCK,$1->lloc,"{");
               }
     | '{' statement
              {
                 $$ = new astree(BLOCK,$1->lloc,"{");
                 $$=$$->adopt($2);
              }
     ;

statement: expr 
             {
                $$ = $1;
             }
         ;

type_id : TOK_INT                { $$ = $1; }
        | TOK_STRING             { $$ = $1; }
        | TOK_CHAR               { $$ = $1; }
        | TOK_VOID               { $$ = $1; }
        | TOK_IDENT              { $$ = $1; }
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
        | TOK_IDENT             { $$ = $1; }
        | NUMBER                { $$ = $1; }
        ;

%%

const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}
