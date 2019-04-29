%{
// $Id: parser.y,v 1.22 2019-04-23 14:07:52-07 - - $
// Dummy parser for scanner project.
/*
 *  oc-compiler main.cpp
 *  CMPS 104A Assignment 1: StringSet generator
 *  Author: 
 *  Nikhil Punathil <npunathi@ucsc.edu> [SID:1584204]
 *  Nikhil Sheth <npsheth@ucsc.edu> [SID:1584204]
 *  Date: 2019.04.29
 */

#include <cassert>

#include "lyutils.h"
#include "astree.h"

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%token TOK_VOID TOK_INT TOK_STRING TOK_CHAR
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_NULLPTR TOK_ARRAY TOK_ARROW TOK_ALLOC TOK_PTR
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE TOK_NOT
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON
%token TOK_ROOT TOK_BLOCK TOK_CALL 

%start program

%%

program : program token | ;
token   : '(' | ')' | '[' | ']' | '{' | '}' | ';' | ','
        | '=' | '+' | '-' | '*' | '/' | '%' | TOK_NOT | TOK_PTR
        | TOK_ROOT TOK_VOID | TOK_INT | TOK_STRING | TOK_CHAR
        | TOK_IF | TOK_ELSE | TOK_WHILE | TOK_RETURN | TOK_STRUCT
        | TOK_NULLPTR | TOK_ARRAY | TOK_ARROW | TOK_ALLOC
        | TOK_EQ | TOK_NE | TOK_LT | TOK_LE | TOK_GT | TOK_GE
        | TOK_IDENT | TOK_INTCON | TOK_CHARCON | TOK_STRINGCON
        ;

%%


const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

