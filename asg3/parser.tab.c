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


#line 77 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 170 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   521

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
      50,    53,    43,    41,    54,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    56,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    52,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    55,    56,    57,    58,    59,    60,    61,
      65,    72,    79,    85,    93,   102,   108,   117,   124,   129,
     138,   144,   152,   158,   165,   172,   187,   194,   199,   228,
     233,   240,   246,   252,   260,   268,   276,   288,   297,   303,
     310,   318,   322,   328,   333,   339,   343,   347,   351,   355,
     359,   364,   380,   384,   388,   392,   396,   402,   406,   412,
     416,   420,   424,   428,   432,   436,   440,   444,   448,   452,
     456,   462,   466,   470,   477,   481,   487,   494,   495,   502,
     503,   504,   505,   506,   514,   515,   516,   517
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ROOT", "IDENT", "NUMBER", "TYPE_ID",
  "FUNCTION", "TOK_PARAM", "TOK_PROTOTYPE", "BLOCK", "TOK_NULLPTR",
  "TOK_INDEX", "CALL", "ENDIF", "TOK_IFELSE", "TOK_GE", "TOK_LE", "TOK_EQ",
  "TOK_NE", "TOK_GT", "TOK_LT", "TOK_IF", "TOK_ELSE", "TOK_STRUCT",
  "TOK_ARRAY", "TOK_NOT", "TOK_ALLOC", "TOK_PTR", "TOK_ARROW", "TOK_WHILE",
  "TOK_VOID", "TOK_RETURN", "TOK_INT", "TOK_CHAR", "TOK_STRING",
  "TOK_CHARCON", "TOK_STRINGCON", "TOK_INTCON", "TOK_IDENT", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "POS", "NEG", "'['", "'('", "';'",
  "'}'", "')'", "','", "'{'", "']'", "$accept", "start", "program",
  "struct", "function", "vardecl", "identif", "param", "callParam", "call",
  "while", "select", "ifelse", "return", "alloc", "blockS", "blockBodyS",
  "block", "blockBody", "multiState", "state", "express", "binop", "unop",
  "var", "type", "type_id", "constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      61,    43,    45,    42,    47,    37,    94,   295,   296,    91,
      40,    59,   125,    41,    44,   123,    93
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -136,    10,     3,  -136,   -26,   -22,    -1,    12,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,   -11,     7,  -136,  -136,
    -136,    -7,   176,    34,   234,    24,   -27,    57,  -136,    29,
      57,    56,    58,   -32,  -136,    63,     2,    90,   202,  -136,
    -136,    36,    57,   202,    82,    55,   195,  -136,  -136,  -136,
      59,   202,   202,   202,  -136,    57,  -136,    47,  -136,  -136,
    -136,  -136,  -136,  -136,    54,    57,  -136,   402,  -136,  -136,
    -136,    71,  -136,    60,  -136,  -136,    96,  -136,  -136,  -136,
    -136,  -136,  -136,   419,   202,  -136,  -136,   -17,    26,   202,
    -136,   455,    93,   -17,   -17,   237,  -136,   202,  -136,   202,
     202,   202,   202,   202,   202,    74,   202,   202,   202,   202,
     202,   202,   202,  -136,   -27,  -136,  -136,  -136,   254,    87,
     107,   113,   292,  -136,  -136,   472,  -136,   472,     0,     0,
       0,     0,     0,     0,  -136,   472,   271,   271,   -17,   -17,
     -17,   174,    57,   116,    90,    89,    57,  -136,   118,    94,
     125,   111,  -136,    57,   129,   131,  -136,   309,  -136,  -136,
     347,   104,  -136,  -136,   147,  -136,   364,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     0,     1,     0,     0,     0,     0,    82,    79,
      81,    80,     8,     3,     5,     4,     0,     0,    77,     6,
       7,     0,     0,     0,     0,     0,    17,    39,    10,     0,
      38,     0,     0,     0,    18,     0,     0,     0,     0,    15,
      87,     0,     0,     0,     0,     0,     0,    86,    85,    84,
      74,     0,     0,     0,    51,    42,    45,     0,    55,    47,
      48,    49,    54,    46,     0,    41,    43,     0,    52,    53,
      57,     0,    58,     0,    44,    78,     0,    11,    13,    17,
      12,    14,    19,     0,     0,    28,    25,    73,     0,     0,
      29,     0,     0,    71,    72,     0,    23,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    37,    83,    16,     0,     0,
       0,     0,     0,    30,    22,    20,    56,    21,    63,    65,
      60,    61,    62,    64,    76,    59,    66,    67,    68,    69,
      70,     0,     0,     0,     0,     0,     0,    75,    27,     0,
       0,     0,    24,     0,     0,     0,    31,     0,    26,    34,
       0,     0,    32,    33,     0,    35,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,  -136,   155,   -16,  -136,  -136,  -136,
    -136,  -135,  -136,  -136,  -136,  -136,  -136,    23,  -136,   138,
     -25,   -37,  -136,  -136,  -136,    -2,   140,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    13,    14,    56,    16,    25,    57,    58,
      59,    85,    60,    61,    62,    28,    29,    63,    64,    65,
      86,    67,    68,    69,    70,    71,    18,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    83,    66,    -2,     4,    74,    87,   148,    34,    91,
       3,   152,   105,    38,    93,    94,    95,    21,   158,    77,
      22,    82,    35,    55,    39,    19,    20,     5,     6,   105,
      66,     7,   112,    23,     8,    35,     9,    10,    11,    24,
      74,   107,   108,   109,   110,   111,    26,   118,    27,   112,
     119,   120,   122,    80,    12,   125,    78,    55,    32,    81,
     127,   121,   128,   129,   130,   131,   132,   133,    40,   135,
     136,   137,   138,   139,   140,   141,    75,    36,    37,    41,
      42,    73,     6,    43,    44,     7,    84,    45,     8,    46,
       9,    10,    11,    47,    48,    49,    50,    76,    51,    52,
      96,    97,    79,    88,    40,    89,    98,    53,    54,    92,
     114,   115,    55,   134,   157,     6,   116,   160,     7,    43,
      44,     8,    40,     9,    10,    11,   143,   166,   144,    47,
      48,    49,    50,   145,    51,    52,   149,    43,    44,   151,
      40,   153,   150,    53,   154,   155,   124,    47,    48,    49,
      50,   161,    51,    52,   164,    43,    44,    15,    40,    30,
       0,    53,    31,     0,   156,    47,    48,    49,    50,     0,
      51,    52,     0,    43,    44,     0,     0,     0,     0,    53,
       0,     0,   159,    47,    48,    49,    50,     0,    51,    52,
      99,   100,   101,   102,   103,   104,     0,    53,     0,     0,
     165,     0,     0,   105,     7,     0,    40,     8,     0,     9,
      10,    11,     0,    40,   106,   107,   108,   109,   110,   111,
       0,    43,    44,   112,     0,     0,     0,     0,    43,    44,
     147,    47,    48,    49,    50,     0,    51,    52,    47,    48,
      49,    50,     0,    51,    52,    53,    90,     0,     0,     0,
       0,     0,    53,    99,   100,   101,   102,   103,   104,     6,
       0,     0,     7,     0,     0,     8,   105,     9,    10,    11,
      99,   100,   101,   102,   103,   104,     0,   106,   107,   108,
     109,   110,   111,   105,     0,     0,   112,    33,     0,     0,
     126,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     105,     0,     0,   112,     0,     0,     0,   142,    99,   100,
     101,   102,   103,   104,   109,   110,   111,     0,     0,     0,
     112,   105,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   106,   107,   108,   109,   110,   111,   105,     0,
       0,   112,     0,     0,     0,   146,     0,     0,     0,   106,
     107,   108,   109,   110,   111,     0,     0,     0,   112,     0,
       0,     0,   162,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,   106,   107,   108,
     109,   110,   111,   105,     0,     0,   112,     0,     0,     0,
     163,     0,     0,     0,   106,   107,   108,   109,   110,   111,
       0,     0,     0,   112,     0,     0,     0,   167,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   106,   107,   108,   109,   110,   111,   105,     0,
       0,   112,     0,   113,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,     0,     0,     0,   112,     0,
     117,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     0,   106,   107,   108,   109,   110,
     111,   105,     0,     0,   112,     0,   123,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,     0,     0,
       0,   112
};

static const yytype_int16 yycheck[] =
{
       2,    38,    27,     0,     1,    30,    43,   142,    24,    46,
       0,   146,    29,    40,    51,    52,    53,    39,   153,    51,
      21,    37,    24,    55,    51,    51,    52,    24,    25,    29,
      55,    28,    49,    21,    31,    37,    33,    34,    35,    50,
      65,    41,    42,    43,    44,    45,    39,    84,    55,    49,
      24,    25,    89,    51,    51,    92,    33,    55,    24,    36,
      97,    35,    99,   100,   101,   102,   103,   104,    11,   106,
     107,   108,   109,   110,   111,   112,    20,    53,    54,    22,
      23,    52,    25,    26,    27,    28,    50,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    39,    41,    42,
      53,    54,    39,    21,    11,    50,    52,    50,    51,    50,
      39,    51,    55,    39,   151,    25,    20,   154,    28,    26,
      27,    31,    11,    33,    34,    35,    39,   164,    21,    36,
      37,    38,    39,    20,    41,    42,    20,    26,    27,    50,
      11,    23,   144,    50,    50,    20,    53,    36,    37,    38,
      39,    20,    41,    42,    50,    26,    27,     2,    11,    21,
      -1,    50,    22,    -1,    53,    36,    37,    38,    39,    -1,
      41,    42,    -1,    26,    27,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    53,    36,    37,    38,    39,    -1,    41,    42,
      16,    17,    18,    19,    20,    21,    -1,    50,    -1,    -1,
      53,    -1,    -1,    29,    28,    -1,    11,    31,    -1,    33,
      34,    35,    -1,    11,    40,    41,    42,    43,    44,    45,
      -1,    26,    27,    49,    -1,    -1,    -1,    -1,    26,    27,
      56,    36,    37,    38,    39,    -1,    41,    42,    36,    37,
      38,    39,    -1,    41,    42,    50,    51,    -1,    -1,    -1,
      -1,    -1,    50,    16,    17,    18,    19,    20,    21,    25,
      -1,    -1,    28,    -1,    -1,    31,    29,    33,    34,    35,
      16,    17,    18,    19,    20,    21,    -1,    40,    41,    42,
      43,    44,    45,    29,    -1,    -1,    49,    53,    -1,    -1,
      53,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      29,    -1,    -1,    49,    -1,    -1,    -1,    53,    16,    17,
      18,    19,    20,    21,    43,    44,    45,    -1,    -1,    -1,
      49,    29,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    40,    41,    42,    43,    44,    45,    29,    -1,
      -1,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    53,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    21,    -1,    40,    41,    42,
      43,    44,    45,    29,    -1,    -1,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    53,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,    40,    41,    42,    43,    44,    45,    29,    -1,
      -1,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      51,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    -1,    40,    41,    42,    43,    44,
      45,    29,    -1,    -1,    49,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    59,     0,     1,    24,    25,    28,    31,    33,
      34,    35,    51,    60,    61,    62,    63,    82,    83,    51,
      52,    39,    21,    21,    50,    64,    39,    55,    72,    73,
      76,    83,    24,    53,    63,    82,    53,    54,    40,    51,
      11,    22,    23,    26,    27,    30,    32,    36,    37,    38,
      39,    41,    42,    50,    51,    55,    62,    65,    66,    67,
      69,    70,    71,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    84,    52,    77,    20,    39,    51,    74,    39,
      51,    74,    63,    78,    50,    68,    77,    78,    21,    50,
      51,    78,    50,    78,    78,    78,    53,    54,    52,    16,
      17,    18,    19,    20,    21,    29,    40,    41,    42,    43,
      44,    45,    49,    51,    39,    51,    20,    51,    78,    24,
      25,    35,    78,    51,    53,    78,    53,    78,    78,    78,
      78,    78,    78,    78,    39,    78,    78,    78,    78,    78,
      78,    78,    53,    39,    21,    20,    53,    56,    68,    20,
      82,    50,    68,    23,    50,    20,    53,    78,    68,    53,
      78,    20,    53,    53,    50,    53,    78,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    59,    59,    59,    59,
      60,    61,    61,    61,    61,    62,    62,    63,    64,    64,
      65,    65,    66,    66,    67,    68,    69,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    72,    73,    73,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    81,    81,    81,    82,    82,    83,
      83,    83,    83,    83,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     2,     0,
       3,     4,     4,     4,     4,     3,     5,     2,     2,     3,
       3,     3,     3,     2,     5,     1,     7,     5,     2,     2,
       3,     6,     7,     8,     7,     9,    10,     3,     1,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     1,     4,     3,     1,     4,     1,
       1,     1,     1,     5,     1,     1,     1,     1
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
#line 847 "parser.tab.c" /* yacc.c:684  */
        break;

    case 4: /* IDENT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 853 "parser.tab.c" /* yacc.c:684  */
        break;

    case 5: /* NUMBER  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 859 "parser.tab.c" /* yacc.c:684  */
        break;

    case 6: /* TYPE_ID  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 865 "parser.tab.c" /* yacc.c:684  */
        break;

    case 7: /* FUNCTION  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 871 "parser.tab.c" /* yacc.c:684  */
        break;

    case 8: /* TOK_PARAM  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 877 "parser.tab.c" /* yacc.c:684  */
        break;

    case 9: /* TOK_PROTOTYPE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 883 "parser.tab.c" /* yacc.c:684  */
        break;

    case 10: /* BLOCK  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 889 "parser.tab.c" /* yacc.c:684  */
        break;

    case 11: /* TOK_NULLPTR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 895 "parser.tab.c" /* yacc.c:684  */
        break;

    case 12: /* TOK_INDEX  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 901 "parser.tab.c" /* yacc.c:684  */
        break;

    case 13: /* CALL  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 907 "parser.tab.c" /* yacc.c:684  */
        break;

    case 14: /* ENDIF  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 913 "parser.tab.c" /* yacc.c:684  */
        break;

    case 15: /* TOK_IFELSE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 919 "parser.tab.c" /* yacc.c:684  */
        break;

    case 16: /* TOK_GE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 925 "parser.tab.c" /* yacc.c:684  */
        break;

    case 17: /* TOK_LE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 931 "parser.tab.c" /* yacc.c:684  */
        break;

    case 18: /* TOK_EQ  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 937 "parser.tab.c" /* yacc.c:684  */
        break;

    case 19: /* TOK_NE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 943 "parser.tab.c" /* yacc.c:684  */
        break;

    case 20: /* TOK_GT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 949 "parser.tab.c" /* yacc.c:684  */
        break;

    case 21: /* TOK_LT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 955 "parser.tab.c" /* yacc.c:684  */
        break;

    case 22: /* TOK_IF  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 961 "parser.tab.c" /* yacc.c:684  */
        break;

    case 23: /* TOK_ELSE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 967 "parser.tab.c" /* yacc.c:684  */
        break;

    case 24: /* TOK_STRUCT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 973 "parser.tab.c" /* yacc.c:684  */
        break;

    case 25: /* TOK_ARRAY  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 979 "parser.tab.c" /* yacc.c:684  */
        break;

    case 26: /* TOK_NOT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 985 "parser.tab.c" /* yacc.c:684  */
        break;

    case 27: /* TOK_ALLOC  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 991 "parser.tab.c" /* yacc.c:684  */
        break;

    case 28: /* TOK_PTR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 997 "parser.tab.c" /* yacc.c:684  */
        break;

    case 29: /* TOK_ARROW  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1003 "parser.tab.c" /* yacc.c:684  */
        break;

    case 30: /* TOK_WHILE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1009 "parser.tab.c" /* yacc.c:684  */
        break;

    case 31: /* TOK_VOID  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1015 "parser.tab.c" /* yacc.c:684  */
        break;

    case 32: /* TOK_RETURN  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1021 "parser.tab.c" /* yacc.c:684  */
        break;

    case 33: /* TOK_INT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1027 "parser.tab.c" /* yacc.c:684  */
        break;

    case 34: /* TOK_CHAR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1033 "parser.tab.c" /* yacc.c:684  */
        break;

    case 35: /* TOK_STRING  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1039 "parser.tab.c" /* yacc.c:684  */
        break;

    case 36: /* TOK_CHARCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1045 "parser.tab.c" /* yacc.c:684  */
        break;

    case 37: /* TOK_STRINGCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1051 "parser.tab.c" /* yacc.c:684  */
        break;

    case 38: /* TOK_INTCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1057 "parser.tab.c" /* yacc.c:684  */
        break;

    case 39: /* TOK_IDENT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1063 "parser.tab.c" /* yacc.c:684  */
        break;

    case 40: /* '='  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1069 "parser.tab.c" /* yacc.c:684  */
        break;

    case 41: /* '+'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1075 "parser.tab.c" /* yacc.c:684  */
        break;

    case 42: /* '-'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1081 "parser.tab.c" /* yacc.c:684  */
        break;

    case 43: /* '*'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1087 "parser.tab.c" /* yacc.c:684  */
        break;

    case 44: /* '/'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1093 "parser.tab.c" /* yacc.c:684  */
        break;

    case 45: /* '%'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1099 "parser.tab.c" /* yacc.c:684  */
        break;

    case 46: /* '^'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1105 "parser.tab.c" /* yacc.c:684  */
        break;

    case 47: /* POS  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1111 "parser.tab.c" /* yacc.c:684  */
        break;

    case 48: /* NEG  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1117 "parser.tab.c" /* yacc.c:684  */
        break;

    case 49: /* '['  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1123 "parser.tab.c" /* yacc.c:684  */
        break;

    case 50: /* '('  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1129 "parser.tab.c" /* yacc.c:684  */
        break;

    case 51: /* ';'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1135 "parser.tab.c" /* yacc.c:684  */
        break;

    case 52: /* '}'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1141 "parser.tab.c" /* yacc.c:684  */
        break;

    case 53: /* ')'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1147 "parser.tab.c" /* yacc.c:684  */
        break;

    case 54: /* ','  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1153 "parser.tab.c" /* yacc.c:684  */
        break;

    case 55: /* '{'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1159 "parser.tab.c" /* yacc.c:684  */
        break;

    case 56: /* ']'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1165 "parser.tab.c" /* yacc.c:684  */
        break;

    case 58: /* start  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1171 "parser.tab.c" /* yacc.c:684  */
        break;

    case 59: /* program  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1177 "parser.tab.c" /* yacc.c:684  */
        break;

    case 60: /* struct  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1183 "parser.tab.c" /* yacc.c:684  */
        break;

    case 61: /* function  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1189 "parser.tab.c" /* yacc.c:684  */
        break;

    case 62: /* vardecl  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1195 "parser.tab.c" /* yacc.c:684  */
        break;

    case 63: /* identif  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1201 "parser.tab.c" /* yacc.c:684  */
        break;

    case 64: /* param  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1207 "parser.tab.c" /* yacc.c:684  */
        break;

    case 65: /* callParam  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1213 "parser.tab.c" /* yacc.c:684  */
        break;

    case 66: /* call  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1219 "parser.tab.c" /* yacc.c:684  */
        break;

    case 67: /* while  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1225 "parser.tab.c" /* yacc.c:684  */
        break;

    case 68: /* select  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1231 "parser.tab.c" /* yacc.c:684  */
        break;

    case 69: /* ifelse  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1237 "parser.tab.c" /* yacc.c:684  */
        break;

    case 70: /* return  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1243 "parser.tab.c" /* yacc.c:684  */
        break;

    case 71: /* alloc  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1249 "parser.tab.c" /* yacc.c:684  */
        break;

    case 72: /* blockS  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1255 "parser.tab.c" /* yacc.c:684  */
        break;

    case 73: /* blockBodyS  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1261 "parser.tab.c" /* yacc.c:684  */
        break;

    case 74: /* block  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1267 "parser.tab.c" /* yacc.c:684  */
        break;

    case 75: /* blockBody  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1273 "parser.tab.c" /* yacc.c:684  */
        break;

    case 76: /* multiState  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1279 "parser.tab.c" /* yacc.c:684  */
        break;

    case 77: /* state  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1285 "parser.tab.c" /* yacc.c:684  */
        break;

    case 78: /* express  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1291 "parser.tab.c" /* yacc.c:684  */
        break;

    case 79: /* binop  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1297 "parser.tab.c" /* yacc.c:684  */
        break;

    case 80: /* unop  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1303 "parser.tab.c" /* yacc.c:684  */
        break;

    case 81: /* var  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1309 "parser.tab.c" /* yacc.c:684  */
        break;

    case 82: /* type  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1315 "parser.tab.c" /* yacc.c:684  */
        break;

    case 83: /* type_id  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1321 "parser.tab.c" /* yacc.c:684  */
        break;

    case 84: /* constant  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1327 "parser.tab.c" /* yacc.c:684  */
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
#line 1673 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 4: /* IDENT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1679 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 5: /* NUMBER  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1685 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 6: /* TYPE_ID  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1691 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 7: /* FUNCTION  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1697 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 8: /* TOK_PARAM  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1703 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 9: /* TOK_PROTOTYPE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1709 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 10: /* BLOCK  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1715 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 11: /* TOK_NULLPTR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1721 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 12: /* TOK_INDEX  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1727 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 13: /* CALL  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1733 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 14: /* ENDIF  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1739 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 15: /* TOK_IFELSE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1745 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 16: /* TOK_GE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1751 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 17: /* TOK_LE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1757 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 18: /* TOK_EQ  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1763 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 19: /* TOK_NE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1769 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 20: /* TOK_GT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1775 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 21: /* TOK_LT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1781 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 22: /* TOK_IF  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1787 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 23: /* TOK_ELSE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1793 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 24: /* TOK_STRUCT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1799 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 25: /* TOK_ARRAY  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1805 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 26: /* TOK_NOT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1811 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 27: /* TOK_ALLOC  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1817 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 28: /* TOK_PTR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1823 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 29: /* TOK_ARROW  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1829 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 30: /* TOK_WHILE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1835 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 31: /* TOK_VOID  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1841 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 32: /* TOK_RETURN  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1847 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 33: /* TOK_INT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1853 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 34: /* TOK_CHAR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1859 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 35: /* TOK_STRING  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1865 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 36: /* TOK_CHARCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1871 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 37: /* TOK_STRINGCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1877 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 38: /* TOK_INTCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1883 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 39: /* TOK_IDENT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1889 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 40: /* '='  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1895 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 41: /* '+'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1901 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 42: /* '-'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1907 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 43: /* '*'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1913 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 44: /* '/'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1919 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 45: /* '%'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1925 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 46: /* '^'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1931 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 47: /* POS  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1937 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 48: /* NEG  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1943 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 49: /* '['  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1949 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 50: /* '('  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1955 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 51: /* ';'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1961 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 52: /* '}'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1967 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 53: /* ')'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1973 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* ','  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1979 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* '{'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1985 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 56: /* ']'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1991 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 58: /* start  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1997 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 59: /* program  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2003 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 60: /* struct  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2009 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 61: /* function  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2015 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 62: /* vardecl  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2021 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 63: /* identif  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2027 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 64: /* param  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2033 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 65: /* callParam  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2039 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 66: /* call  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2045 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 67: /* while  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2051 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 68: /* select  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2057 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 69: /* ifelse  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2063 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 70: /* return  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2069 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 71: /* alloc  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2075 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 72: /* blockS  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2081 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 73: /* blockBodyS  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2087 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 74: /* block  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2093 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 75: /* blockBody  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2099 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 76: /* multiState  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2105 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 77: /* state  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2111 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 78: /* express  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2117 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 79: /* binop  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2123 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 80: /* unop  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2129 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 81: /* var  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2135 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 82: /* type  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2141 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 83: /* type_id  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2147 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 84: /* constant  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2153 "parser.tab.c" /* yacc.c:1257  */
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

#line 2243 "parser.tab.c" /* yacc.c:1429  */
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
#line 52 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) = nullptr; }
#line 2425 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2431 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2437 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2443 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]); }
#line 2449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]); }
#line 2455 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 60 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2461 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval) = parser::root; }
#line 2467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "parser.y" /* yacc.c:1646  */
    {
         // destroy($4);
         (yyval) = (yyvsp[-2])->adopt((yyvsp[-1]),(yyvsp[0]));
       }
#line 2476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 73 "parser.y" /* yacc.c:1646  */
    {  
                  destroy ( (yyvsp[-1]), (yyvsp[0])) ; 
                  (yyvsp[-2]) = (yyvsp[-2])->symChange((yyvsp[-2]),TOK_PARAM);
                  (yyval) = new astree(FUNCTION, (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
               }
#line 2487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 80 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]),(yyvsp[0]));
                  (yyval) = new astree(FUNCTION, (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
               }
#line 2497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 86 "parser.y" /* yacc.c:1646  */
    {
                 destroy((yyvsp[-1]));
                 (yyvsp[-2]) = (yyvsp[-2])->symChange((yyvsp[-2]),TOK_PARAM);
                 (yyval) = new astree(FUNCTION,(yyvsp[-3])->lloc,"");
                 (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
                 (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2509 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 94 "parser.y" /* yacc.c:1646  */
    {
                 destroy((yyvsp[-1]));
                 (yyval) = new astree(FUNCTION,(yyvsp[-3])->lloc,"");
                 (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
                 (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 103 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = new astree(TYPE_ID,(yyvsp[-2])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-2]),(yyvsp[-1]));
               }
#line 2530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 109 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-2]),(yyvsp[0]));
                  (yyval) = new astree(TYPE_ID,(yyvsp[-4])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-4]),(yyvsp[-3]));
                  (yyval) = (yyval)->adopt((yyvsp[-1]));
               }
#line 2541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = new astree(TYPE_ID, (yyvsp[-1])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-1]),(yyvsp[0]));
               }
#line 2550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 125 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = new astree(TOK_PARAM, (yyvsp[-1])->lloc, "(");
                  (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]));
                  // $$ = new astree(TOK_PARAM, $1->lloc, "(");
                  (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));
               }
#line 2569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 139 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),CALL);
                  (yyval) = (yyval)->adopt((yyvsp[-2]),(yyvsp[0])); 
                  
               }
#line 2579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 145 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]));
                  (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));
               }
#line 2588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 153 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[0]));
         (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),CALL);
         (yyval) = (yyval)->adopt((yyvsp[-2]));
      }
#line 2598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 159 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[0]));
         (yyval) = (yyvsp[-1]);
      }
#line 2607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-3]),(yyvsp[-1]));
         (yyval) = (yyvsp[-4])->adopt((yyvsp[-2]),(yyvsp[0]));
       }
#line 2616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 173 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 188 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-5]),(yyvsp[-3]));
         destroy((yyvsp[-1]));
         (yyval) = (yyvsp[-6])->adopt((yyvsp[-4]),(yyvsp[-2]));
         (yyval) = (yyval)->adopt((yyvsp[0]));
      }
#line 2635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 195 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-3]),(yyvsp[-1]));
         (yyval) = (yyvsp[-4])->adopt((yyvsp[-2]),(yyvsp[0]));
      }
#line 2644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 200 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-1]));
         (yyval) = (yyval)->adopt((yyvsp[0]));
      }
#line 2653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 229 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[0]));
           (yyval) = (yyvsp[-1]);
        }
#line 2662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 234 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[0]));
           (yyval) = (yyvsp[-2])->adopt((yyvsp[-1]));
        }
#line 2671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 241 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-4]),(yyvsp[-2]));
         destroy((yyvsp[-1]),(yyvsp[0]));
         (yyval) = (yyvsp[-5])->adopt((yyvsp[-3]));
       }
#line 2681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 247 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-5]),(yyvsp[-3]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyval) = (yyvsp[-6])->adopt((yyvsp[-4]),(yyvsp[-1]));
       }
#line 2691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 254 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-6]),(yyvsp[-5]));
         destroy((yyvsp[-2]));
         destroy((yyvsp[-3]),(yyvsp[0]));
         (yyval) = (yyvsp[-7])->adopt((yyvsp[-4]),(yyvsp[-1]));
       }
#line 2702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 262 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-5]),(yyvsp[-4]));
         destroy((yyvsp[-1]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyval) = (yyvsp[-6])->adopt((yyvsp[-3]));
       }
#line 2713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 270 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-7]),(yyvsp[-5]));
         destroy((yyvsp[-3]),(yyvsp[-2]));
         destroy((yyvsp[-1]),(yyvsp[0]));
         (yyval) = (yyvsp[-8])->adopt((yyvsp[-6]),(yyvsp[-4]));
       }
#line 2724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 278 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-8]),(yyvsp[-6]));
         destroy((yyvsp[-4]),(yyvsp[-3]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyvsp[-9]) = (yyvsp[-9])->adopt((yyvsp[-7]),(yyvsp[-5]));
         (yyval) = (yyvsp[-9])->adopt((yyvsp[-1]));
       }
#line 2736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 289 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]),(yyvsp[0])  );
                  (yyval) = (yyvsp[-2]);
               }
#line 2745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 298 "parser.y" /* yacc.c:1646  */
    { 
               // destroy($1); 
               // $$ = new astree(BLOCK,$1->lloc,"{"); 
               (yyval) = (yyvsp[0]);
             }
#line 2755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 304 "parser.y" /* yacc.c:1646  */
    {
                (yyval) = new astree(BLOCK,(yyvsp[0])->lloc,"{"); 
            }
#line 2763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 311 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = (yyvsp[-1]);
               }
#line 2772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 319 "parser.y" /* yacc.c:1646  */
    { 
               (yyval) = (yyvsp[0]);
             }
#line 2780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 323 "parser.y" /* yacc.c:1646  */
    {
                (yyval) = new astree(BLOCK,(yyvsp[0])->lloc,"{"); 
            }
#line 2788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 329 "parser.y" /* yacc.c:1646  */
    {
              (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),BLOCK);
              (yyval) = (yyval) ->adopt((yyvsp[0]));
           }
#line 2797 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 334 "parser.y" /* yacc.c:1646  */
    {
              (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),BLOCK);
              (yyvsp[-1]) = (yyvsp[-1])->adopt((yyvsp[0]));
           }
#line 2806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 340 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 344 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2822 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 348 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2830 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 352 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 356 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2846 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 360 "parser.y" /* yacc.c:1646  */
    {
            destroy((yyvsp[0]));
            (yyval)=(yyvsp[-1]);
         }
#line 2855 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 365 "parser.y" /* yacc.c:1646  */
    {
             (yyval) = new astree(BLOCK,(yyvsp[0])->lloc,"{");
         }
#line 2863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 381 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2871 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 385 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2879 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 389 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 393 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2895 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 397 "parser.y" /* yacc.c:1646  */
    {
            destroy((yyvsp[0]));
            (yyval) = new astree(TOK_PARAM,(yyvsp[-2])->lloc,"(");
            (yyval) = (yyval)->adopt((yyvsp[-1]));
         }
#line 2905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 403 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2913 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 407 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2921 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 413 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 417 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 421 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 425 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 429 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2961 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 433 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2969 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 437 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2977 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 441 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 445 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2993 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 449 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 3001 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 453 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 3009 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 457 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 3017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 463 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), POS); 
         }
#line 3025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 467 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), NEG); 
         }
#line 3033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 471 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), NEG); 
         }
#line 3041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 478 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = (yyvsp[0]);
               }
#line 3049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 482 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = new astree(TOK_INDEX,(yyvsp[-2])->lloc,"[");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-1]));
               }
#line 3059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 488 "parser.y" /* yacc.c:1646  */
    {
                  //get clarification for if we need to swap $1 & $3
                  (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
               }
#line 3068 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 494 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3074 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 496 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[-2]),(yyvsp[0]));
           (yyval) = (yyvsp[-3])->adopt((yyvsp[-1]));
        }
#line 3083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 502 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 503 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3095 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 504 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3101 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 505 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3107 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 507 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[-3]),(yyvsp[0]));
           destroy((yyvsp[-2]));
           (yyval) = (yyvsp[-4])->adopt((yyvsp[-1]));
        }
#line 3117 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 514 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3123 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 515 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3129 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 516 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3135 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 517 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3141 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 3145 "parser.tab.c" /* yacc.c:1646  */
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
#line 520 "parser.y" /* yacc.c:1906  */


const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}
