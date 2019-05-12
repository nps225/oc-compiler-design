/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "parser.y" /* yacc.c:339  */


#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "lyutils.h"


#line 77 "yyparse.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
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
    TOK_GE = 270,
    TOK_LE = 271,
    TOK_EQ = 272,
    TOK_NE = 273,
    TOK_GT = 274,
    TOK_LT = 275,
    TOK_IF = 276,
    TOK_ELSE = 277,
    TOK_STRUCT = 278,
    TOK_ARRAY = 279,
    TOK_NOT = 280,
    TOK_ALLOC = 281,
    TOK_PTR = 282,
    TOK_ARROW = 283,
    TOK_WHILE = 284,
    TOK_VOID = 285,
    TOK_RETURN = 286,
    TOK_INT = 287,
    TOK_CHAR = 288,
    TOK_STRING = 289,
    TOK_CHARCON = 290,
    TOK_STRINGCON = 291,
    TOK_INTCON = 292,
    TOK_IDENT = 293,
    POS = 294,
    NEG = 295
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

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 169 "yyparse.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      51,    52,    42,    40,    53,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    51,    52,    53,    54,    55,    56,    60,
      66,    73,    80,    86,    94,   103,   109,   118,   125,   130,
     139,   145,   153,   159,   166,   173,   184,   196,   205,   210,
     217,   223,   229,   237,   245,   253,   265,   270,   271,   277,
     283,   288,   295,   299,   303,   307,   311,   315,   332,   336,
     340,   344,   348,   354,   358,   364,   368,   372,   376,   380,
     384,   388,   392,   396,   400,   404,   408,   414,   418,   422,
     429,   433,   439,   446,   447,   454,   455,   456,   457,   458,
     466,   467,   468,   469
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ROOT", "IDENT", "NUMBER", "TYPE_ID",
  "FUNCTION", "TOK_PARAM", "TOK_PROTOTYPE", "BLOCK", "TOK_NULLPTR",
  "TOK_INDEX", "CALL", "ENDIF", "TOK_GE", "TOK_LE", "TOK_EQ", "TOK_NE",
  "TOK_GT", "TOK_LT", "TOK_IF", "TOK_ELSE", "TOK_STRUCT", "TOK_ARRAY",
  "TOK_NOT", "TOK_ALLOC", "TOK_PTR", "TOK_ARROW", "TOK_WHILE", "TOK_VOID",
  "TOK_RETURN", "TOK_INT", "TOK_CHAR", "TOK_STRING", "TOK_CHARCON",
  "TOK_STRINGCON", "TOK_INTCON", "TOK_IDENT", "'='", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'^'", "POS", "NEG", "';'", "'{'", "'}'", "'('", "')'",
  "','", "'['", "']'", "$accept", "start", "program", "struct", "function",
  "vardecl", "identif", "param", "callParam", "call", "while", "select",
  "ifelse", "return", "alloc", "block", "blockBody", "state", "express",
  "binop", "unop", "var", "type", "type_id", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    61,
      43,    45,    42,    47,    37,    94,   294,   295,    59,   123,
     125,    40,    41,    44,    91,    93
};
# endif

#define YYPACT_NINF -122

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-122)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -122,     5,     3,  -122,   -38,   -14,    12,    18,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,    -3,    21,  -122,  -122,
       7,    13,    39,    61,     8,   -17,  -122,   129,  -122,   160,
      22,    32,    27,  -122,    51,    29,   112,   258,  -122,  -122,
      -1,   191,   258,    72,    16,   230,  -122,  -122,  -122,    45,
     258,   258,   191,    54,   258,  -122,    47,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,   272,  -122,  -122,    68,  -122,    59,
    -122,  -122,    90,  -122,  -122,  -122,  -122,  -122,  -122,   312,
     258,  -122,  -122,   -26,   -11,   258,  -122,   329,    28,   -26,
     -26,  -122,   369,  -122,   258,  -122,  -122,  -122,  -122,  -122,
    -122,    73,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   258,
     258,   -17,  -122,  -122,  -122,   375,    80,   101,    91,   415,
    -122,  -122,   507,  -122,   507,  -122,   218,   507,   191,   105,
     112,    74,   191,  -122,  -122,    75,   108,    46,  -122,    79,
     110,  -122,   421,  -122,   461,    92,  -122,  -122,    97,  -122,
     467,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,     0,     0,     0,    78,    75,
      77,    76,     7,     3,     5,     4,     0,     0,    73,     6,
       0,     0,     0,     0,     0,    17,    38,     0,    10,     0,
       0,     0,     0,    18,     0,     0,     0,     0,    15,    83,
       0,     0,     0,     0,     0,     0,    82,    81,    80,    70,
       0,     0,    41,     0,     0,    42,     0,    51,    44,    45,
      46,    50,    43,    39,     0,    49,    53,     0,    54,    36,
      40,    74,     0,    11,    13,    17,    12,    14,    19,     0,
       0,    27,    25,    69,     0,     0,    28,     0,     0,    67,
      68,     9,     0,    23,     0,    59,    61,    56,    57,    58,
      60,     0,    55,    62,    63,    64,    65,    66,    47,     0,
       0,     0,    37,    79,    16,     0,     0,     0,     0,     0,
      29,    22,    20,    52,    21,    72,     0,    48,     0,     0,
       0,     0,     0,    71,    26,     0,     0,     0,    24,     0,
       0,    30,     0,    33,     0,     0,    31,    32,     0,    34,
       0,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,  -122,   139,    -7,  -122,  -122,  -122,
    -122,  -121,  -122,  -122,  -122,   -12,  -122,   -10,   -36,  -122,
    -122,  -122,    -2,   126,  -122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    13,    14,    55,    16,    24,    56,    57,
      58,    81,    59,    60,    61,    62,    29,    82,    64,   110,
      65,    66,    67,    18,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    79,   101,    -2,     4,     3,    83,   134,    28,    87,
      19,   138,   116,   117,    89,    90,    33,    63,    92,    70,
      74,    34,    37,    77,    20,   118,     5,     6,   109,    78,
       7,    38,    21,     8,    34,     9,    10,    11,    22,    39,
       7,    71,    63,     8,   115,     9,    10,    11,    23,   119,
      80,    12,   122,    42,    43,    26,    27,    39,   124,    25,
      35,    36,    31,    46,    47,    48,    49,    85,    50,    51,
      72,    42,    43,   126,   127,    73,    52,    76,    52,    54,
     121,    46,    47,    48,    49,     6,    50,    51,     7,    75,
      39,     8,    84,     9,    10,    11,    88,    54,   141,    93,
      94,   142,    91,   144,    42,    43,   111,   112,    39,   113,
     131,   125,   150,    32,    46,    47,    48,    49,   129,    50,
      51,   130,    42,    43,   135,   137,   139,   140,   136,   145,
      54,   143,    46,    47,    48,    49,     6,    50,    51,     7,
      39,    15,     8,   148,     9,    10,    11,    30,    54,   149,
      40,    41,     0,     6,    42,    43,     7,     0,    44,     8,
      45,     9,    10,    11,    46,    47,    48,    49,     0,    50,
      51,    39,     0,     0,     0,     0,     0,    26,    52,    53,
      54,    40,    41,     0,     6,    42,    43,     7,     0,    44,
       8,    45,     9,    10,    11,    46,    47,    48,    49,     0,
      50,    51,    39,     0,     0,     0,     0,     0,    26,    52,
      69,    54,    40,    41,     0,     6,    42,    43,     7,     0,
      44,     8,    45,     9,    10,    11,    46,    47,    48,    49,
       0,    50,    51,    95,    96,    97,    98,    99,   100,    26,
      52,    39,    54,     0,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,   102,   103,   104,
     105,   106,   107,     0,     0,    46,    47,    48,    49,    39,
      50,    51,   109,   133,     0,     0,     0,     0,    86,     0,
       0,    54,     0,    42,    43,     0,     0,    95,    96,    97,
      98,    99,   100,    46,    47,    48,    49,     0,    50,    51,
     101,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,   102,   103,   104,   105,   106,   107,     0,     0,     0,
     108,     0,     0,     0,     0,     0,   109,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,     0,    95,    96,    97,    98,    99,   100,
       0,   102,   103,   104,   105,   106,   107,   101,     0,     0,
     114,     0,     0,     0,     0,     0,   109,     0,   102,   103,
     104,   105,   106,   107,     0,     0,     0,   120,     0,     0,
       0,     0,     0,   109,    95,    96,    97,    98,    99,   100,
      95,    96,    97,    98,    99,   100,     0,   101,     0,     0,
       0,     0,     0,   101,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   102,   103,   104,   105,   106,   107,
       0,   123,     0,   109,     0,     0,     0,   128,     0,   109,
      95,    96,    97,    98,    99,   100,    95,    96,    97,    98,
      99,   100,     0,   101,     0,     0,     0,     0,     0,   101,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     102,   103,   104,   105,   106,   107,     0,   132,     0,   109,
       0,     0,     0,   146,     0,   109,    95,    96,    97,    98,
      99,   100,    95,    96,    97,    98,    99,   100,     0,   101,
       0,     0,     0,     0,     0,   101,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   102,   103,   104,   105,
     106,   107,     0,   147,     0,   109,     0,     0,     0,   151,
       0,   109,    95,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109
};

static const yytype_int16 yycheck[] =
{
       2,    37,    28,     0,     1,     0,    42,   128,    20,    45,
      48,   132,    23,    24,    50,    51,    23,    27,    54,    29,
      32,    23,    39,    35,    38,    36,    23,    24,    54,    36,
      27,    48,    20,    30,    36,    32,    33,    34,    20,    11,
      27,    19,    52,    30,    80,    32,    33,    34,    51,    85,
      51,    48,    88,    25,    26,    48,    49,    11,    94,    38,
      52,    53,    23,    35,    36,    37,    38,    51,    40,    41,
      38,    25,    26,   109,   110,    48,    49,    48,    49,    51,
      52,    35,    36,    37,    38,    24,    40,    41,    27,    38,
      11,    30,    20,    32,    33,    34,    51,    51,    52,    52,
      53,   137,    48,   139,    25,    26,    38,    48,    11,    19,
      19,    38,   148,    52,    35,    36,    37,    38,    38,    40,
      41,    20,    25,    26,    19,    51,    51,    19,   130,    19,
      51,    52,    35,    36,    37,    38,    24,    40,    41,    27,
      11,     2,    30,    51,    32,    33,    34,    21,    51,    52,
      21,    22,    -1,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    11,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    21,    22,    -1,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    11,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    21,    22,    -1,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    15,    16,    17,    18,    19,    20,    48,
      49,    11,    51,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    39,    40,    41,
      42,    43,    44,    -1,    -1,    35,    36,    37,    38,    11,
      40,    41,    54,    55,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    25,    26,    -1,    -1,    15,    16,    17,
      18,    19,    20,    35,    36,    37,    38,    -1,    40,    41,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    54,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    39,    40,    41,    42,    43,    44,    28,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    54,    -1,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    54,    15,    16,    17,    18,    19,    20,
      15,    16,    17,    18,    19,    20,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    39,    40,    41,    42,    43,    44,
      -1,    52,    -1,    54,    -1,    -1,    -1,    52,    -1,    54,
      15,    16,    17,    18,    19,    20,    15,    16,    17,    18,
      19,    20,    -1,    28,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      39,    40,    41,    42,    43,    44,    -1,    52,    -1,    54,
      -1,    -1,    -1,    52,    -1,    54,    15,    16,    17,    18,
      19,    20,    15,    16,    17,    18,    19,    20,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    39,    40,    41,    42,
      43,    44,    -1,    52,    -1,    54,    -1,    -1,    -1,    52,
      -1,    54,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,     0,     1,    23,    24,    27,    30,    32,
      33,    34,    48,    59,    60,    61,    62,    78,    79,    48,
      38,    20,    20,    51,    63,    38,    48,    49,    71,    72,
      79,    23,    52,    62,    78,    52,    53,    39,    48,    11,
      21,    22,    25,    26,    29,    31,    35,    36,    37,    38,
      40,    41,    49,    50,    51,    61,    64,    65,    66,    68,
      69,    70,    71,    73,    74,    76,    77,    78,    80,    50,
      73,    19,    38,    48,    71,    38,    48,    71,    62,    74,
      51,    67,    73,    74,    20,    51,    48,    74,    51,    74,
      74,    48,    74,    52,    53,    15,    16,    17,    18,    19,
      20,    28,    39,    40,    41,    42,    43,    44,    48,    54,
      75,    38,    48,    19,    48,    74,    23,    24,    36,    74,
      48,    52,    74,    52,    74,    38,    74,    74,    52,    38,
      20,    19,    52,    55,    67,    19,    78,    51,    67,    51,
      19,    52,    74,    52,    74,    19,    52,    52,    51,    52,
      74,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    58,    58,    58,    59,
      59,    60,    60,    60,    60,    61,    61,    62,    63,    63,
      64,    64,    65,    65,    66,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    71,    71,    71,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    78,    78,    79,    79,    79,    79,    79,
      80,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     2,     0,     5,
       3,     4,     4,     4,     4,     3,     5,     2,     2,     3,
       3,     3,     3,     2,     5,     1,     5,     2,     2,     3,
       6,     7,     8,     7,     9,    10,     2,     3,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     4,     3,     1,     4,     1,     1,     1,     1,     5,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
          case 3: /* ROOT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 850 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 4: /* IDENT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 856 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 5: /* NUMBER  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 862 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 6: /* TYPE_ID  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 868 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 7: /* FUNCTION  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 874 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 8: /* TOK_PARAM  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 880 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 9: /* TOK_PROTOTYPE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 886 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 10: /* BLOCK  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 892 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 11: /* TOK_NULLPTR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 898 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 12: /* TOK_INDEX  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 904 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 13: /* CALL  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 910 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 14: /* ENDIF  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 916 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 15: /* TOK_GE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 922 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 16: /* TOK_LE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 928 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 17: /* TOK_EQ  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 934 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 18: /* TOK_NE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 940 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 19: /* TOK_GT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 946 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 20: /* TOK_LT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 952 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 21: /* TOK_IF  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 958 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 22: /* TOK_ELSE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 964 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 23: /* TOK_STRUCT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 970 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 24: /* TOK_ARRAY  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 976 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 25: /* TOK_NOT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 982 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 26: /* TOK_ALLOC  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 988 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 27: /* TOK_PTR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 994 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 28: /* TOK_ARROW  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1000 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 29: /* TOK_WHILE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1006 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 30: /* TOK_VOID  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1012 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 31: /* TOK_RETURN  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1018 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 32: /* TOK_INT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1024 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 33: /* TOK_CHAR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1030 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 34: /* TOK_STRING  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1036 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 35: /* TOK_CHARCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1042 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 36: /* TOK_STRINGCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1048 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 37: /* TOK_INTCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1054 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 38: /* TOK_IDENT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1060 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 39: /* '='  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1066 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 40: /* '+'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1072 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 41: /* '-'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1078 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 42: /* '*'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1084 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 43: /* '/'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1090 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 44: /* '%'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1096 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 45: /* '^'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1102 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 46: /* POS  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1108 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 47: /* NEG  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1114 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 48: /* ';'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1120 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 49: /* '{'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1126 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 50: /* '}'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1132 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 51: /* '('  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1138 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 52: /* ')'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1144 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 53: /* ','  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1150 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 54: /* '['  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1156 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 55: /* ']'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1162 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 57: /* start  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1168 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 58: /* program  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1174 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 59: /* struct  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1180 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 60: /* function  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1186 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 61: /* vardecl  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1192 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 62: /* identif  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1198 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 63: /* param  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1204 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 64: /* callParam  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1210 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 65: /* call  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1216 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 66: /* while  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1222 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 67: /* select  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1228 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 68: /* ifelse  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1234 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 69: /* return  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1240 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 70: /* alloc  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1246 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 71: /* block  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1252 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 72: /* blockBody  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1258 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 73: /* state  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1264 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 74: /* express  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1270 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 75: /* binop  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1276 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 76: /* unop  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1282 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 77: /* var  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1288 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 78: /* type  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1294 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 79: /* type_id  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1300 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 80: /* constant  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1306 "yyparse.cpp" /* yacc.c:684  */
        break;


      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* ROOT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1652 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 4: /* IDENT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1658 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 5: /* NUMBER  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1664 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 6: /* TYPE_ID  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1670 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 7: /* FUNCTION  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1676 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 8: /* TOK_PARAM  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1682 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 9: /* TOK_PROTOTYPE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1688 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 10: /* BLOCK  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1694 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 11: /* TOK_NULLPTR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1700 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 12: /* TOK_INDEX  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1706 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 13: /* CALL  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1712 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 14: /* ENDIF  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1718 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 15: /* TOK_GE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1724 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 16: /* TOK_LE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1730 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 17: /* TOK_EQ  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1736 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 18: /* TOK_NE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1742 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 19: /* TOK_GT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1748 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 20: /* TOK_LT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1754 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 21: /* TOK_IF  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1760 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 22: /* TOK_ELSE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1766 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 23: /* TOK_STRUCT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1772 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 24: /* TOK_ARRAY  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1778 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 25: /* TOK_NOT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1784 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 26: /* TOK_ALLOC  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1790 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 27: /* TOK_PTR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1796 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 28: /* TOK_ARROW  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1802 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 29: /* TOK_WHILE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1808 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 30: /* TOK_VOID  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1814 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 31: /* TOK_RETURN  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1820 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 32: /* TOK_INT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1826 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 33: /* TOK_CHAR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1832 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 34: /* TOK_STRING  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1838 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 35: /* TOK_CHARCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1844 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 36: /* TOK_STRINGCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1850 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 37: /* TOK_INTCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1856 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 38: /* TOK_IDENT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1862 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 39: /* '='  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1868 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 40: /* '+'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1874 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 41: /* '-'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1880 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 42: /* '*'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1886 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 43: /* '/'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1892 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 44: /* '%'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1898 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 45: /* '^'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1904 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 46: /* POS  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1910 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 47: /* NEG  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1916 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 48: /* ';'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1922 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 49: /* '{'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1928 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 50: /* '}'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1934 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 51: /* '('  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1940 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 52: /* ')'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1946 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 53: /* ','  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1952 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 54: /* '['  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1958 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 55: /* ']'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1964 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 57: /* start  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1970 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 58: /* program  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1976 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 59: /* struct  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1982 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 60: /* function  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1988 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 61: /* vardecl  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1994 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 62: /* identif  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2000 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 63: /* param  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2006 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 64: /* callParam  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2012 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 65: /* call  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2018 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 66: /* while  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2024 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 67: /* select  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2030 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 68: /* ifelse  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2036 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 69: /* return  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2042 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 70: /* alloc  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2048 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 71: /* block  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2054 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 72: /* blockBody  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2060 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 73: /* state  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2066 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 74: /* express  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2072 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 75: /* binop  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2078 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 76: /* unop  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2084 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 77: /* var  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2090 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 78: /* type  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2096 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 79: /* type_id  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2102 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 80: /* constant  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2108 "yyparse.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 23 "parser.y" /* yacc.c:1429  */
{
   parser::root = new astree (ROOT, {0, 0, 0}, "");
}

#line 2198 "yyparse.cpp" /* yacc.c:1429  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 48 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) = nullptr; }
#line 2380 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2386 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 52 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2392 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 53 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2398 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 54 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]); }
#line 2404 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 55 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2410 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 56 "parser.y" /* yacc.c:1646  */
    { (yyval) = parser::root; }
#line 2416 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-1]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyval) = (yyvsp[-4])->adopt((yyvsp[-3]));
       }
#line 2426 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 67 "parser.y" /* yacc.c:1646  */
    {
         // destroy($4);
         (yyval) = (yyvsp[-2])->adopt((yyvsp[-1]),(yyvsp[0]));
       }
#line 2435 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 74 "parser.y" /* yacc.c:1646  */
    {  
                  destroy ( (yyvsp[-1]), (yyvsp[0])) ; 
                  (yyvsp[-2]) = (yyvsp[-2])->symChange((yyvsp[-2]),TOK_PARAM);
                  (yyval) = new astree(FUNCTION, (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
               }
#line 2446 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]),(yyvsp[0]));
                  (yyval) = new astree(FUNCTION, (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
               }
#line 2456 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 87 "parser.y" /* yacc.c:1646  */
    {
                 destroy((yyvsp[-1]));
                 (yyvsp[-2]) = (yyvsp[-2])->symChange((yyvsp[-2]),TOK_PARAM);
                 (yyval) = new astree(FUNCTION,(yyvsp[-3])->lloc,"");
                 (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
                 (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2468 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 95 "parser.y" /* yacc.c:1646  */
    {
                 destroy((yyvsp[-1]));
                 (yyval) = new astree(FUNCTION,(yyvsp[-3])->lloc,"");
                 (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
                 (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2479 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 104 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = new astree(TYPE_ID,(yyvsp[-2])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-2]),(yyvsp[-1]));
               }
#line 2489 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 110 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-2]),(yyvsp[0]));
                  (yyval) = new astree(TYPE_ID,(yyvsp[-4])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-4]),(yyvsp[-3]));
                  (yyval) = (yyval)->adopt((yyvsp[-1]));
               }
#line 2500 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 119 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = new astree(TYPE_ID, (yyvsp[-1])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-1]),(yyvsp[0]));
               }
#line 2509 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 126 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = new astree(TOK_PARAM, (yyvsp[-1])->lloc, "(");
                  (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2518 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 131 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]));
                  // $$ = new astree(TOK_PARAM, $1->lloc, "(");
                  (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));
               }
#line 2528 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 140 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),CALL);
                  (yyval) = (yyval)->adopt((yyvsp[-2]),(yyvsp[0])); 
                  
               }
#line 2538 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]));
                  (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));
               }
#line 2547 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 154 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[0]));
         (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),CALL);
         (yyval) = (yyval)->adopt((yyvsp[-2]));
      }
#line 2557 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 160 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[0]));
         (yyval) = (yyvsp[-1]);
      }
#line 2566 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 167 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-3]),(yyvsp[-1]));
         (yyval) = (yyvsp[-4])->adopt((yyvsp[-2]),(yyvsp[0]));
       }
#line 2575 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 174 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2583 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 185 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-3]),(yyvsp[-1]));
         (yyval) = (yyvsp[-4])-> adopt((yyvsp[-2]),(yyvsp[0]));
       }
#line 2592 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 197 "parser.y" /* yacc.c:1646  */
    {
          destroy((yyvsp[-1]));
          (yyval) = (yyval)->adopt((yyvsp[0]));
         //  $$ = $->adopt($6);   
       }
#line 2602 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 206 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[0]));
           (yyval) = (yyvsp[-1]);
        }
#line 2611 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 211 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[0]));
           (yyval) = (yyvsp[-2])->adopt((yyvsp[-1]));
        }
#line 2620 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 218 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-4]),(yyvsp[-2]));
         destroy((yyvsp[-1]),(yyvsp[0]));
         (yyval) = (yyvsp[-5])->adopt((yyvsp[-3]));
       }
#line 2630 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 224 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-5]),(yyvsp[-3]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyval) = (yyvsp[-6])->adopt((yyvsp[-4]),(yyvsp[-1]));
       }
#line 2640 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 231 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-6]),(yyvsp[-5]));
         destroy((yyvsp[-2]));
         destroy((yyvsp[-3]),(yyvsp[0]));
         (yyval) = (yyvsp[-7])->adopt((yyvsp[-4]),(yyvsp[-1]));
       }
#line 2651 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 239 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-5]),(yyvsp[-4]));
         destroy((yyvsp[-1]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyval) = (yyvsp[-6])->adopt((yyvsp[-3]));
       }
#line 2662 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 247 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-7]),(yyvsp[-5]));
         destroy((yyvsp[-3]),(yyvsp[-2]));
         destroy((yyvsp[-1]),(yyvsp[0]));
         (yyval) = (yyvsp[-8])->adopt((yyvsp[-6]),(yyvsp[-4]));
       }
#line 2673 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 255 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-8]),(yyvsp[-6]));
         destroy((yyvsp[-4]),(yyvsp[-3]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyvsp[-9]) = (yyvsp[-9])->adopt((yyvsp[-7]),(yyvsp[-5]));
         (yyval) = (yyvsp[-9])->adopt((yyvsp[-1]));
       }
#line 2685 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 266 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = (yyvsp[-1]);
               }
#line 2694 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 270 "parser.y" /* yacc.c:1646  */
    {destroy((yyvsp[-1]),(yyvsp[0])); (yyval) = (yyvsp[-2]);}
#line 2700 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 271 "parser.y" /* yacc.c:1646  */
    {
         (yyval) = new astree(BLOCK,(yyvsp[0])->lloc,"{");
      }
#line 2708 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 278 "parser.y" /* yacc.c:1646  */
    { 
               // destroy($1); 
               (yyval) = new astree(BLOCK,(yyvsp[-1])->lloc,"{"); 
               (yyval) = (yyval)->adopt((yyvsp[0]));
             }
#line 2718 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 284 "parser.y" /* yacc.c:1646  */
    {
               (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),BLOCK);
               (yyvsp[-1]) = (yyvsp[-1])->adopt((yyvsp[0]));
            }
#line 2727 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 289 "parser.y" /* yacc.c:1646  */
    {
               (yyval) = (yyvsp[0])->symChange((yyvsp[0]),BLOCK);
            }
#line 2735 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 296 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2743 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 300 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2751 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 304 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2759 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 308 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2767 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 312 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2775 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 316 "parser.y" /* yacc.c:1646  */
    {
            destroy((yyvsp[0]));
            (yyval)=(yyvsp[-1]);
         }
#line 2784 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 333 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); 
         }
#line 2792 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 337 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2800 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 341 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2808 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 345 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2816 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 349 "parser.y" /* yacc.c:1646  */
    {
            destroy((yyvsp[0]));
            (yyval) = new astree(TOK_PARAM,(yyvsp[-2])->lloc,"(");
            (yyval) = (yyval)->adopt((yyvsp[-1]));
         }
#line 2826 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 355 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2834 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 359 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2842 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 365 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2850 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 369 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2858 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 373 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2866 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 377 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2874 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 381 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2882 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 385 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2890 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 389 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2898 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 393 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2906 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 397 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2914 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 401 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2922 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 405 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2930 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 409 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2938 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 415 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), POS); 
         }
#line 2946 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 419 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), NEG); 
         }
#line 2954 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 423 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), NEG); 
         }
#line 2962 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 430 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = (yyvsp[0]);
               }
#line 2970 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 434 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = new astree(TOK_INDEX,(yyvsp[-2])->lloc,"[");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-1]));
               }
#line 2980 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 440 "parser.y" /* yacc.c:1646  */
    {
                  //get clarification for if we need to swap $1 & $3
                  (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
               }
#line 2989 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 446 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2995 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 448 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[-2]),(yyvsp[0]));
           (yyval) = (yyvsp[-3])->adopt((yyvsp[-1]));
        }
#line 3004 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 454 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3010 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 455 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3016 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 456 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3022 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 457 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3028 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 459 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[-3]),(yyvsp[0]));
           destroy((yyvsp[-2]));
           (yyval) = (yyvsp[-4])->adopt((yyvsp[-1]));
        }
#line 3038 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 466 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3044 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 467 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3050 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 468 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3056 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 469 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3062 "yyparse.cpp" /* yacc.c:1646  */
    break;


#line 3066 "yyparse.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 472 "parser.y" /* yacc.c:1906  */


const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}
