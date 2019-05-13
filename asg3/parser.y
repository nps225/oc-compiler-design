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
%token  BLOCK TOK_NULLPTR TOK_INDEX CALL ENDIF TOK_IFELSE
%token  TOK_GE TOK_LE TOK_EQ TOK_NE TOK_GT TOK_LT
%token  TOK_IF TOK_ELSE TOK_STRUCT TOK_ARRAY TOK_NOT
%token  TOK_ALLOC TOK_PTR TOK_ARROW TOK_WHILE TOK_VOID
%token  TOK_RETURN TOK_INT TOK_CHAR TOK_STRING
%token  TOK_CHARCON TOK_STRINGCON TOK_INTCON TOK_IDENT

%right TOK_IFELSE TOK_IF TOK_ELSE
%right  '='
%left   TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left   '+' '-'
%left   '*' '/' '%'
%right  '^'
%right  POS NEG TOK_NOT
%left   TOK_ARROW '['
%nonassoc '('

%precedence TOK_NULLPTR TOK_WHILE


%start  start

%%

start : program               { $$ = $1 = nullptr; }
      ;

program : program struct        { $$ = $1->adopt($2); }
        | program vardecl       { $$ = $1->adopt($2); }
        | program function      { $$ = $1->adopt($2); }
        | program error ';'     { destroy ($3); $$ = $1; }
        | program error '}'     { destroy ($3); $$ = $1; }
        | program ';'           { destroy ($2); $$ = $1; }
        | %empty                { $$ = parser::root; }
        ;


struct : TOK_STRUCT TOK_IDENT blockS
       {
         // destroy($4);
         $$ = $1->adopt($2,$3);
       }


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

while: TOK_WHILE '(' express ')' select
       {
         destroy($2,$4);
         $$ = $1->adopt($3,$5);
       }
       ;

select: state
        {
           $$ = $1;
        }
      ;

// ifelse: TOK_IF '(' express ')' select TOK_ELSE select
//         {
//            destroy($2,$4);
//            destroy($6);
//            $$ = $1->adopt($3,$5);
//            $$ = $$->adopt($7);
//         }
//         | TOK_ELSE select 

ifelse: TOK_IF '(' express ')' select TOK_ELSE select
      {
         destroy($2,$4);
         destroy($6);
         $$ = $1->adopt($3,$5);
         $$ = $$->adopt($7);
      }
      | TOK_IF '(' express ')' select 
      {
         destroy($2,$4);
         $$ = $1->adopt($3,$5);
      }
      
//old version of my if else handling -> produced
//dangling else
// ifelse: TOK_IF '(' express ')' select else
//        {
//          destroy($2,$4);
//          $$ = $1-> adopt($3,$5);
//          $$ = $$->adopt($6);
//        }
//        |TOK_ELSE select
//        {
//           destroy($1);
//           $$ = $$->adopt($2);  
//        }
       
//        ;

// else: TOK_ELSE state 
//       {
//          destroy($1);
//          $$ = $2;
//       }
//       | %empty %prec TOK_IF

return : TOK_RETURN ';'
        {
           destroy($2);
           $$ = $1;
        }
        | TOK_RETURN express ';'
        {
           destroy($3);
           $$ = $1->adopt($2);
        }
        ;

alloc: TOK_ALLOC TOK_LT TOK_STRING TOK_GT '(' ')'
       {
         destroy($2,$4);
         destroy($5,$6);
         $$ = $1->adopt($3);
       }
       | TOK_ALLOC TOK_LT TOK_STRING TOK_GT '(' express ')'
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


blockS: blockBodyS '}' ';'
               {
                  destroy($2,$3  );
                  $$ = $1;
               }
      // | blockBody '}' ';' {destroy($2,$3); $$ = $1;}
      ;


blockBodyS: multiState 
             { 
               // destroy($1); 
               // $$ = new astree(BLOCK,$1->lloc,"{"); 
               $$ = $1;
             }
         | '{'
            {
                $$ = new astree(BLOCK,$1->lloc,"{"); 
            }
         ;


block: blockBody '}'
               {
                  destroy($2);
                  $$ = $1;
               }
      ;


blockBody: multiState 
             { 
               $$ = $1;
             }
         | '{'
            {
                $$ = new astree(BLOCK,$1->lloc,"{"); 
            }
         ;

multiState: '{' state 
           {
              $$ = $1->symChange($1,BLOCK);
              $$ = $$ ->adopt($2);
           }
           | multiState state
           {
              $$ = $1->symChange($1,BLOCK);
              $1 = $1->adopt($2);
           }

state:   vardecl
         {
            $$ = $1;
         }
         |block
         {
            $$ = $1;
         }
         |while
         {
            $$ = $1;
         }
         | ifelse
         {
            $$ = $1;
         }
         | return 
         {
            $$ = $1;
         }
         | express ';'
         {
            destroy($2);
            $$=$1;
         }
         | ';'
         {
             $$ = new astree(BLOCK,$1->lloc,"{");
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


express: binop
         {
            $$ = $1;
         }
         |unop 
         {
            $$ = $1;
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

binop: express '=' express
        {
           $$ = $2->adopt($1,$3);
        }
      | express TOK_EQ express
        {
           $$ = $2->adopt($1,$3);
        }
      | express TOK_NE express
        {
           $$ = $2->adopt($1,$3);
        }
      | express TOK_GT express
        {
           $$ = $2->adopt($1,$3);
        }
      | express TOK_GE express
        {
           $$ = $2->adopt($1,$3);
        }
      | express TOK_LT express
        {
           $$ = $2->adopt($1,$3);
        }
      | express TOK_LE express
        {
           $$ = $2->adopt($1,$3);
        }
      | express '+' express
        {
           $$ = $2->adopt($1,$3);
        }
      | express '-' express
        {
           $$ = $2->adopt($1,$3);
        }
      | express '*' express
        {
           $$ = $2->adopt($1,$3);
        }
      | express '/' express
        {
           $$ = $2->adopt($1,$3);
        }
      | express '%' express
        {
           $$ = $2->adopt($1,$3);
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
    | TOK_NOT express %prec NEG    
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
         | express TOK_ARROW TOK_IDENT
               {
                  //get clarification for if we need to swap $1 & $3
                  $$ = $2->adopt($1,$3);
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
        | TOK_PTR TOK_LT TOK_STRUCT TOK_IDENT TOK_GT
        {
           destroy($2,$5);
           destroy($3);
           $$ = $1->adopt($4);
        }
        ;

constant: TOK_INTCON                { $$ = $1; }
        | TOK_STRINGCON              { $$ = $1; }
        | TOK_CHARCON                { $$ = $1; }
        | TOK_NULLPTR                { $$ = $1; }
        ;

%%

const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}