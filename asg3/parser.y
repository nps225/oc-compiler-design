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
%token  BLOCK TOK_NULLPTR TOK_INDEX CALL
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

program : program state         { $$ = $1->adopt($2); }
        | program vardecl       { $$ = $1->adopt($2); }
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

vardecl : type TOK_IDENT ';'
               {
                  destroy($3);
                  $$ = new astree(TYPE_ID,$1->lloc,"");
                  $$ = $$->adopt($1,$2);
               }
         | type TOK_IDENT '=' express ';'
               {
                  destroy($3,$5);
                  $$ = new astree(TYPE_ID,$1->lloc,"");
                  $$ = $$->adopt($1,$2);
                  $$ = $$->adopt($4);
               }
         ;

identif : type TOK_IDENT     
               {
                  $$ = new astree(TYPE_ID, $1->lloc,"");
                  $$ = $$->adopt($1,$2);
               }
         ;

param : '(' identif 
               {
                  $$ = new astree(TOK_PARAM, $1->lloc, "(");
                  $$ = $$->adopt($2);
               }
      | param ',' identif
               {
                  destroy($2);
                  // $$ = new astree(TOK_PARAM, $1->lloc, "(");
                  $$ = $1->adopt($3);
               }
      ;


callParam : TOK_IDENT '(' express
               {
                  $$ = $2->symChange($2,CALL);
                  $$ = $$->adopt($1,$3); 
                  
               }
            | callParam ',' express
               {
                  destroy($2);
                  $$ = $1->adopt($3);
               }
             
      ;

call: TOK_IDENT '(' ')'
      {
         destroy($3);
         $$ = $2->symChange($2,CALL);
         $$ = $$->adopt($1);
      }
      | callParam ')'
      {
         destroy($2);
         $$ = $1;
      }
      ;

while: TOK_WHILE '(' express ')' block
       {
         destroy($2,$4);
         $$ = $1->adopt($3,$5);
       }
       ;

ifelse: TOK_IF '(' express ')' block
       {
         destroy($2,$4);
         $$ = $1-> adopt($3,$5);
       }
       | TOK_IF '(' express ')' block TOK_ELSE block
       {
          destroy($2,$4);
          destroy($6);
          $1 = $1->adopt($3,$5);
          $1 = $1->adopt($7);          
       }
       ;

alloc: TOK_ALLOC TOK_LT TOK_STRINGCON TOK_GT '(' ')'
       {
         destroy($2,$4);
         destroy($5,$6);
         $$ = $1->adopt($3);
       }
       | TOK_ALLOC TOK_LT TOK_STRINGCON TOK_GT '(' express ')'
       {
         destroy($2,$4);
         destroy($5,$7);
         $$ = $1->adopt($3,$6);
       }
       | TOK_ALLOC TOK_LT TOK_STRUCT TOK_IDENT
         TOK_GT '(' express ')'
       {
         destroy($2,$3);
         destroy($6);
         destroy($5,$8);
         $$ = $1->adopt($4,$7);
       }
       | TOK_ALLOC TOK_LT TOK_STRUCT TOK_IDENT
         TOK_GT '(' ')'
       {
         destroy($2,$3);
         destroy($6);
         destroy($5,$7);
         $$ = $1->adopt($4);
       }
       | TOK_ALLOC TOK_LT TOK_ARRAY TOK_LT
         type TOK_GT TOK_GT '(' ')'
       {
         destroy($2,$4);
         destroy($6,$7);
         destroy($8,$9);
         $$ = $1->adopt($3,$5);
       }
       | TOK_ALLOC TOK_LT TOK_ARRAY TOK_LT
         type TOK_GT TOK_GT '(' express ')'
       {
         destroy($2,$4);
         destroy($6,$7);
         destroy($8,$10);
         $1 = $1->adopt($3,$5);
         $$ = $1->adopt($9);
       }
       ;


block: blockBody '}'
               {
                  destroy($2);
                  $$ = $1;
               }
      ;


blockBody: '{' statement 
             { 
               // destroy($1); 
               $$ = new astree(BLOCK,$1->lloc,"{"); 
               $$ = $$->adopt($2);
             }
         |  blockBody statement
            {
               $$ = $1->symChange($1,BLOCK);
               $1 = $1->adopt($2);
            }
         |  '{'
            {
               $$ = $1->symChange($1,BLOCK);
            }
         ;

statement: expr ';'
            {
               destroy($2);
               $$=$1;
            }
         ;

state:   while
         {
            $$ = $1;
         }
         | ifelse
         {
            $$ = $1;
         }
         | express ';'
         {
            destroy($2);
            $$=$1;
         }
         ;

// old code that may need later
//          | statement expr ';'
//             {
//                destroy($3);
//                $$ = new astree(TOK_PARAM,$1->lloc,"");
//                $$ = $$->adopt($1,$2);
//             }
//          ;


express: express binop express
         {
            $$ = $2->adopt ($1, $3); 
         }
         | alloc
         {
            $$ = $1;
         }
         |call 
         {
            $$ = $1;
         }
         | '(' express ')'
         {
            destroy($3);
            $$ = new astree(TOK_PARAM,$1->lloc,"(");
            $$ = $$->adopt($2);
         }
         | var
         {
            $$ = $1;
         }
         | constant 
         {
            $$ = $1;
         }
         ;

binop: '=' 
        {
           $$ = $1;
        }
      | TOK_EQ
        {
           $$ = $1;
        }
      | TOK_NE
        {
           $$ = $1;
        }
      | TOK_GT
        {
           $$ = $1;
        }
      | TOK_GE
        {
           $$ = $1;
        }
      | TOK_LT
        {
           $$ = $1;
        }
      | TOK_LE
        {
           $$ = $1;
        }
      | '+'
        {
           $$ = $1;
        }
      | '-'
        {
           $$ = $1;
        }
      | '*'
        {
           $$ = $1;
        }
      | '/' 
        {
           $$ = $1;
        }
      | '%' 
        {
           $$ = $1;
        }
      ;

unop: '+' express %prec POS    
         {
            $$ = $1->adopt_sym ($2, POS); 
         }
    | '-' express %prec NEG    
         {
           $$ = $1->adopt_sym ($2, NEG); 
         }
     ;


var     : TOK_IDENT 
               {
                  $$ = $1;
               }
         | express '[' express ']'
               {
                  destroy($4);
                  $$ = new astree(TOK_INDEX,$2->lloc,"[");
                  $$ = $$->adopt($1,$3);
               }
         ;

type    : type_id                { $$ = $1; }
        | TOK_ARRAY TOK_LT type_id TOK_GT 
        {
           destroy($2,$4);
           $$ = $1->adopt($3);
        }
        ;

type_id : TOK_INT                { $$ = $1; }
        | TOK_STRING             { $$ = $1; }
        | TOK_CHAR               { $$ = $1; }
        | TOK_VOID               { $$ = $1; }
        ;

constant: TOK_INTCON                { $$ = $1; }
        | TOK_STRINGCON              { $$ = $1; }
        | TOK_CHARCON                { $$ = $1; }
        | TOK_NULLPTR                { $$ = $1; }
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
        | constant              { $$ = $1; }
        | NUMBER                { $$ = $1; }
        ;

%%

const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}
