/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ROOT = 258,
    IDENT = 259,
    NUMBER = 260,
    TYPE_ID = 261,
    FUNCTION = 262,
    TOK_PARAM = 263,
    TOK_PROTOTYPE = 264,
    BLOCK = 265,
    TOK_NULLPTR = 266,
    TOK_INDEX = 267,
    CALL = 268,
    ENDIF = 269,
    TOK_IFELSE = 270,
    TOK_GE = 271,
    TOK_LE = 272,
    TOK_EQ = 273,
    TOK_NE = 274,
    TOK_GT = 275,
    TOK_LT = 276,
    TOK_IF = 277,
    TOK_ELSE = 278,
    TOK_STRUCT = 279,
    TOK_ARRAY = 280,
    TOK_NOT = 281,
    TOK_ALLOC = 282,
    TOK_PTR = 283,
    TOK_ARROW = 284,
    TOK_WHILE = 285,
    TOK_VOID = 286,
    TOK_RETURN = 287,
    TOK_INT = 288,
    TOK_CHAR = 289,
    TOK_STRING = 290,
    TOK_CHARCON = 291,
    TOK_STRINGCON = 292,
    TOK_INTCON = 293,
    TOK_IDENT = 294,
    POS = 295,
    NEG = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
