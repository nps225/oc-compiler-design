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
    TOK_GE = 269,
    TOK_LE = 270,
    TOK_EQ = 271,
    TOK_NE = 272,
    TOK_GT = 273,
    TOK_LT = 274,
    TOK_IF = 275,
    TOK_ELSE = 276,
    TOK_STRUCT = 277,
    TOK_ARRAY = 278,
    TOK_NOT = 279,
    TOK_ALLOC = 280,
    TOK_PTR = 281,
    TOK_ARROW = 282,
    TOK_WHILE = 283,
    TOK_VOID = 284,
    TOK_RETURN = 285,
    TOK_INT = 286,
    TOK_CHAR = 287,
    TOK_STRING = 288,
    TOK_CHARCON = 289,
    TOK_STRINGCON = 290,
    TOK_INTCON = 291,
    TOK_IDENT = 292,
    POS = 293,
    NEG = 294
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

#line 168 "yyparse.cpp" /* yacc.c:358  */

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
#define YYLAST   532

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    43,     2,     2,
      50,    51,    41,    39,    52,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      35,    36,    37,    45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    50,    51,    52,    53,    54,    55,    59,
      65,    83,    90,    96,   104,   113,   119,   128,   135,   140,
     149,   155,   163,   169,   176,   183,   188,   198,   203,   210,
     216,   222,   230,   238,   246,   258,   266,   272,   277,   284,
     288,   292,   296,   300,   304,   321,   325,   329,   333,   337,
     343,   347,   353,   357,   361,   365,   369,   373,   377,   381,
     385,   389,   393,   397,   403,   407,   414,   418,   424,   431,
     432,   439,   440,   441,   442,   443,   451,   452,   453,   454
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ROOT", "IDENT", "NUMBER", "TYPE_ID",
  "FUNCTION", "TOK_PARAM", "TOK_PROTOTYPE", "BLOCK", "TOK_NULLPTR",
  "TOK_INDEX", "CALL", "TOK_GE", "TOK_LE", "TOK_EQ", "TOK_NE", "TOK_GT",
  "TOK_LT", "TOK_IF", "TOK_ELSE", "TOK_STRUCT", "TOK_ARRAY", "TOK_NOT",
  "TOK_ALLOC", "TOK_PTR", "TOK_ARROW", "TOK_WHILE", "TOK_VOID",
  "TOK_RETURN", "TOK_INT", "TOK_CHAR", "TOK_STRING", "TOK_CHARCON",
  "TOK_STRINGCON", "TOK_INTCON", "TOK_IDENT", "'='", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'^'", "POS", "NEG", "';'", "'{'", "'}'", "'('", "')'",
  "','", "'['", "']'", "$accept", "start", "program", "struct", "function",
  "vardecl", "identif", "param", "callParam", "call", "while", "ifelse",
  "return", "alloc", "block", "blockBody", "state", "express", "binop",
  "unop", "var", "type", "type_id", "constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    61,    43,
      45,    42,    47,    37,    94,   293,   294,    59,   123,   125,
      40,    41,    44,    91,    93
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,    11,     3,   -35,   -31,   -17,    18,    26,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,     4,    -7,   -35,   -35,
       8,    43,    35,   284,   -28,   -29,   141,    13,   172,    40,
      31,   -20,   -35,    42,     0,   497,   482,   -35,   -35,    30,
      62,    36,   465,   -35,   -35,   -35,    39,   482,   482,   203,
      14,   482,   -35,     1,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   230,   -35,   -35,    53,   -35,   -35,   -35,   -35,   -35,
      73,   -35,   -35,   -35,   -35,   -35,   -35,   247,   482,   -16,
     482,   -35,   287,    48,   -22,   -22,   -35,   304,   -35,   482,
     -35,   -35,   -35,   -35,   -35,   -35,    56,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   482,   482,   -29,   -35,   -35,   334,
      57,    76,    78,   351,   -35,   -35,   445,   -35,   445,   -35,
      24,   445,    54,    83,   497,    55,    54,   -35,    87,    59,
      86,    81,   -35,    54,   100,    94,   -35,   381,   -35,   -35,
     398,    63,   -35,   -35,   108,   -35,   428,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,     0,     0,     0,    74,    71,
      73,    72,     7,     3,     5,     4,     0,     0,    69,     6,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,    15,    79,     0,
       0,     0,     0,    78,    77,    76,    66,     0,     0,    38,
       0,     0,    39,     0,    48,    41,    42,    43,    47,    40,
      36,     0,    46,    50,     0,    51,    10,    35,    37,    70,
       0,    11,    13,    17,    12,    14,    19,     0,     0,     0,
       0,    27,     0,     0,    64,    65,     9,     0,    23,     0,
      56,    58,    53,    54,    55,    57,     0,    52,    59,    60,
      61,    62,    63,    44,     0,     0,     0,    75,    16,     0,
       0,     0,     0,     0,    28,    22,    20,    49,    21,    68,
       0,    45,     0,     0,     0,     0,     0,    67,    25,     0,
       0,     0,    24,     0,     0,     0,    29,     0,    26,    32,
       0,     0,    30,    31,     0,    33,     0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,   -35,   -35,   -35,   121,   -13,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -19,   -35,    96,   -34,   -35,   -35,
     -35,    -2,   105,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    13,    14,    52,    16,    24,    53,    54,
      55,    56,    57,    58,    59,    28,    60,    61,   105,    62,
      63,    64,    18,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    27,    77,    -2,     4,    96,   110,   111,    82,    36,
      32,     3,    72,    84,    85,    75,    19,    87,    37,   112,
      20,    33,    76,    34,    35,     5,     6,    71,    49,     7,
      25,   104,     8,    33,     9,    10,    11,    21,    90,    91,
      92,    93,    94,    95,   109,    22,   113,    74,    49,   116,
      12,    96,    88,    89,    23,   118,    26,    30,    69,    38,
      66,    86,    97,    98,    99,   100,   101,   102,    70,     7,
     120,   121,     8,    40,     9,    10,    11,   104,   127,    73,
      78,    79,    43,    44,    45,    46,    80,    47,    48,    83,
     106,   107,    38,   119,   123,   124,   125,   137,    51,   115,
     140,   129,    49,   128,   135,   131,    40,   132,   133,   134,
     146,    38,   141,   144,   138,    43,    44,    45,    46,    38,
      47,    48,   130,    15,    68,    40,    29,     0,     0,     0,
       0,    51,   136,    40,    43,    44,    45,    46,     0,    47,
      48,     0,    43,    44,    45,    46,     0,    47,    48,     0,
      51,   139,    38,     0,     0,     0,     0,     0,    51,   145,
       0,    39,     0,     0,     6,     0,    40,     7,     0,    41,
       8,    42,     9,    10,    11,    43,    44,    45,    46,     0,
      47,    48,     0,    38,     0,     0,     0,     0,     0,    49,
      50,    51,    39,     0,     0,     6,     0,    40,     7,     0,
      41,     8,    42,     9,    10,    11,    43,    44,    45,    46,
       0,    47,    48,     0,    38,     0,     0,     0,     0,     0,
      49,    67,    51,    39,     0,     0,     6,     0,    40,     7,
       0,    41,     8,    42,     9,    10,    11,    43,    44,    45,
      46,     0,    47,    48,    90,    91,    92,    93,    94,    95,
       0,    49,     0,    51,     0,     0,     0,    96,     0,     0,
       0,    90,    91,    92,    93,    94,    95,     0,    97,    98,
      99,   100,   101,   102,    96,     0,     0,   103,     0,     0,
       0,     0,     0,   104,     0,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   108,     0,     0,     0,     0,     0,
     104,    90,    91,    92,    93,    94,    95,     6,     0,     0,
       7,     0,     0,     8,    96,     9,    10,    11,    90,    91,
      92,    93,    94,    95,     0,    97,    98,    99,   100,   101,
     102,    96,     0,     0,   114,    31,     0,     0,     0,     0,
     104,     0,    97,    98,    99,   100,   101,   102,    90,    91,
      92,    93,    94,    95,     0,   117,     0,   104,     0,     0,
       0,    96,     0,     0,     0,    90,    91,    92,    93,    94,
      95,     0,    97,    98,    99,   100,   101,   102,    96,     0,
       0,     0,     0,     0,     0,   122,     0,   104,     0,    97,
      98,    99,   100,   101,   102,    90,    91,    92,    93,    94,
      95,     0,   126,     0,   104,     0,     0,     0,    96,     0,
       0,     0,    90,    91,    92,    93,    94,    95,     0,    97,
      98,    99,   100,   101,   102,    96,     0,     0,     0,     0,
       0,     0,   142,     0,   104,     0,    97,    98,    99,   100,
     101,   102,    90,    91,    92,    93,    94,    95,     0,   143,
       0,   104,     0,     0,     0,    96,     0,     0,     0,    90,
      91,    92,    93,    94,    95,     0,    97,    98,    99,   100,
     101,   102,    96,     0,     0,     0,    38,     0,     0,   147,
       0,   104,     0,    97,    98,    99,   100,   101,   102,     0,
      40,     0,     0,    38,     0,     0,     0,     0,   104,    43,
      44,    45,    46,     0,    47,    48,     0,    40,     0,     0,
       0,     0,    81,     0,     0,    51,    43,    44,    45,    46,
       6,    47,    48,     7,     0,     0,     8,     0,     9,    10,
      11,     0,    51
};

static const yytype_int16 yycheck[] =
{
       2,    20,    36,     0,     1,    27,    22,    23,    42,    38,
      23,     0,    31,    47,    48,    34,    47,    51,    47,    35,
      37,    23,    35,    51,    52,    22,    23,    47,    48,    26,
      37,    53,    29,    35,    31,    32,    33,    19,    14,    15,
      16,    17,    18,    19,    78,    19,    80,    47,    48,    83,
      47,    27,    51,    52,    50,    89,    48,    22,    18,    11,
      47,    47,    38,    39,    40,    41,    42,    43,    37,    26,
     104,   105,    29,    25,    31,    32,    33,    53,    54,    37,
      50,    19,    34,    35,    36,    37,    50,    39,    40,    50,
      37,    18,    11,    37,    37,    19,    18,   131,    50,    51,
     134,    18,    48,   122,    18,    50,    25,   126,    21,    50,
     144,    11,    18,    50,   133,    34,    35,    36,    37,    11,
      39,    40,   124,     2,    28,    25,    21,    -1,    -1,    -1,
      -1,    50,    51,    25,    34,    35,    36,    37,    -1,    39,
      40,    -1,    34,    35,    36,    37,    -1,    39,    40,    -1,
      50,    51,    11,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    20,    -1,    -1,    23,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    40,    -1,    11,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    20,    -1,    -1,    23,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    40,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    20,    -1,    -1,    23,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    14,    15,    16,    17,    18,    19,
      -1,    48,    -1,    50,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    19,    -1,    38,    39,
      40,    41,    42,    43,    27,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      53,    14,    15,    16,    17,    18,    19,    23,    -1,    -1,
      26,    -1,    -1,    29,    27,    31,    32,    33,    14,    15,
      16,    17,    18,    19,    -1,    38,    39,    40,    41,    42,
      43,    27,    -1,    -1,    47,    51,    -1,    -1,    -1,    -1,
      53,    -1,    38,    39,    40,    41,    42,    43,    14,    15,
      16,    17,    18,    19,    -1,    51,    -1,    53,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    -1,    38,    39,    40,    41,    42,    43,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    38,
      39,    40,    41,    42,    43,    14,    15,    16,    17,    18,
      19,    -1,    51,    -1,    53,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    -1,    38,
      39,    40,    41,    42,    43,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    53,    -1,    38,    39,    40,    41,
      42,    43,    14,    15,    16,    17,    18,    19,    -1,    51,
      -1,    53,    -1,    -1,    -1,    27,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    -1,    38,    39,    40,    41,
      42,    43,    27,    -1,    -1,    -1,    11,    -1,    -1,    51,
      -1,    53,    -1,    38,    39,    40,    41,    42,    43,    -1,
      25,    -1,    -1,    11,    -1,    -1,    -1,    -1,    53,    34,
      35,    36,    37,    -1,    39,    40,    -1,    25,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    34,    35,    36,    37,
      23,    39,    40,    26,    -1,    -1,    29,    -1,    31,    32,
      33,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    57,     0,     1,    22,    23,    26,    29,    31,
      32,    33,    47,    58,    59,    60,    61,    76,    77,    47,
      37,    19,    19,    50,    62,    37,    48,    69,    70,    77,
      22,    51,    61,    76,    51,    52,    38,    47,    11,    20,
      25,    28,    30,    34,    35,    36,    37,    39,    40,    48,
      49,    50,    60,    63,    64,    65,    66,    67,    68,    69,
      71,    72,    74,    75,    76,    78,    47,    49,    71,    18,
      37,    47,    69,    37,    47,    69,    61,    72,    50,    19,
      50,    47,    72,    50,    72,    72,    47,    72,    51,    52,
      14,    15,    16,    17,    18,    19,    27,    38,    39,    40,
      41,    42,    43,    47,    53,    73,    37,    18,    47,    72,
      22,    23,    35,    72,    47,    51,    72,    51,    72,    37,
      72,    72,    51,    37,    19,    18,    51,    54,    69,    18,
      76,    50,    69,    21,    50,    18,    51,    72,    69,    51,
      72,    18,    51,    51,    50,    51,    72,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    59,    59,    60,    60,    61,    62,    62,
      63,    63,    64,    64,    65,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    69,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    76,
      76,    77,    77,    77,    77,    77,    78,    78,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     2,     0,     5,
       4,     4,     4,     4,     4,     3,     5,     2,     2,     3,
       3,     3,     3,     2,     5,     5,     7,     2,     3,     6,
       7,     8,     7,     9,    10,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     4,     3,     1,
       4,     1,     1,     1,     1,     5,     1,     1,     1,     1
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
#line 837 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 4: /* IDENT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 843 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 5: /* NUMBER  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 849 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 6: /* TYPE_ID  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 855 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 7: /* FUNCTION  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 861 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 8: /* TOK_PARAM  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 867 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 9: /* TOK_PROTOTYPE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 873 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 10: /* BLOCK  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 879 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 11: /* TOK_NULLPTR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 885 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 12: /* TOK_INDEX  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 891 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 13: /* CALL  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 897 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 14: /* TOK_GE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 903 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 15: /* TOK_LE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 909 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 16: /* TOK_EQ  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 915 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 17: /* TOK_NE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 921 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 18: /* TOK_GT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 927 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 19: /* TOK_LT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 933 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 20: /* TOK_IF  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 939 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 21: /* TOK_ELSE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 945 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 22: /* TOK_STRUCT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 951 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 23: /* TOK_ARRAY  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 957 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 24: /* TOK_NOT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 963 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 25: /* TOK_ALLOC  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 969 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 26: /* TOK_PTR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 975 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 27: /* TOK_ARROW  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 981 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 28: /* TOK_WHILE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 987 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 29: /* TOK_VOID  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 993 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 30: /* TOK_RETURN  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 999 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 31: /* TOK_INT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1005 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 32: /* TOK_CHAR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1011 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 33: /* TOK_STRING  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1017 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 34: /* TOK_CHARCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1023 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 35: /* TOK_STRINGCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1029 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 36: /* TOK_INTCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1035 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 37: /* TOK_IDENT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1041 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 38: /* '='  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1047 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 39: /* '+'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1053 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 40: /* '-'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1059 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 41: /* '*'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1065 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 42: /* '/'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1071 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 43: /* '%'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1077 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 44: /* '^'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1083 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 45: /* POS  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1089 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 46: /* NEG  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1095 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 47: /* ';'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1101 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 48: /* '{'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1107 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 49: /* '}'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1113 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 50: /* '('  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1119 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 51: /* ')'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1125 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 52: /* ','  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1131 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 53: /* '['  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1137 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 54: /* ']'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1143 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 56: /* start  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1149 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 57: /* program  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1155 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 58: /* struct  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1161 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 59: /* function  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1167 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 60: /* vardecl  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1173 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 61: /* identif  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1179 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 62: /* param  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1185 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 63: /* callParam  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1191 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 64: /* call  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1197 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 65: /* while  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1203 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 66: /* ifelse  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1209 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 67: /* return  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1215 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 68: /* alloc  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1221 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 69: /* block  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1227 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 70: /* blockBody  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1233 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 71: /* state  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1239 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 72: /* express  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1245 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 73: /* binop  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1251 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 74: /* unop  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1257 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 75: /* var  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1263 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 76: /* type  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1269 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 77: /* type_id  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1275 "yyparse.cpp" /* yacc.c:684  */
        break;

    case 78: /* constant  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1281 "yyparse.cpp" /* yacc.c:684  */
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
#line 1627 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 4: /* IDENT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1633 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 5: /* NUMBER  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1639 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 6: /* TYPE_ID  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1645 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 7: /* FUNCTION  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1651 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 8: /* TOK_PARAM  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1657 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 9: /* TOK_PROTOTYPE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1663 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 10: /* BLOCK  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1669 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 11: /* TOK_NULLPTR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1675 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 12: /* TOK_INDEX  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1681 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 13: /* CALL  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1687 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 14: /* TOK_GE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1693 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 15: /* TOK_LE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1699 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 16: /* TOK_EQ  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1705 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 17: /* TOK_NE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1711 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 18: /* TOK_GT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1717 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 19: /* TOK_LT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1723 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 20: /* TOK_IF  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1729 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 21: /* TOK_ELSE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1735 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 22: /* TOK_STRUCT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1741 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 23: /* TOK_ARRAY  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1747 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 24: /* TOK_NOT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1753 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 25: /* TOK_ALLOC  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1759 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 26: /* TOK_PTR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1765 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 27: /* TOK_ARROW  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1771 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 28: /* TOK_WHILE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1777 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 29: /* TOK_VOID  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1783 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 30: /* TOK_RETURN  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1789 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 31: /* TOK_INT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1795 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 32: /* TOK_CHAR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1801 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 33: /* TOK_STRING  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1807 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 34: /* TOK_CHARCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1813 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 35: /* TOK_STRINGCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1819 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 36: /* TOK_INTCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1825 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 37: /* TOK_IDENT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1831 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 38: /* '='  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1837 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 39: /* '+'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1843 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 40: /* '-'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1849 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 41: /* '*'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1855 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 42: /* '/'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1861 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 43: /* '%'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1867 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 44: /* '^'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1873 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 45: /* POS  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1879 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 46: /* NEG  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1885 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 47: /* ';'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1891 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 48: /* '{'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1897 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 49: /* '}'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1903 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 50: /* '('  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1909 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 51: /* ')'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1915 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 52: /* ','  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1921 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 53: /* '['  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1927 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 54: /* ']'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1933 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 56: /* start  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1939 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 57: /* program  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1945 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 58: /* struct  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1951 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 59: /* function  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1957 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 60: /* vardecl  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1963 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 61: /* identif  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1969 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 62: /* param  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1975 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 63: /* callParam  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1981 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 64: /* call  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1987 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 65: /* while  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1993 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 66: /* ifelse  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1999 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 67: /* return  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2005 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 68: /* alloc  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2011 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 69: /* block  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2017 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 70: /* blockBody  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2023 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 71: /* state  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2029 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 72: /* express  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2035 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 73: /* binop  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2041 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 74: /* unop  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2047 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 75: /* var  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2053 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 76: /* type  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2059 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 77: /* type_id  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2065 "yyparse.cpp" /* yacc.c:1257  */
        break;

    case 78: /* constant  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2071 "yyparse.cpp" /* yacc.c:1257  */
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

#line 2161 "yyparse.cpp" /* yacc.c:1429  */
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
#line 47 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) = nullptr; }
#line 2343 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 50 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2349 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 51 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2355 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 52 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2361 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 53 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]); }
#line 2367 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 54 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2373 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 55 "parser.y" /* yacc.c:1646  */
    { (yyval) = parser::root; }
#line 2379 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 60 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-1]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyval) = (yyvsp[-4])->adopt((yyvsp[-3]));
       }
#line 2389 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[0]));
         (yyval) = (yyvsp[-3])->adopt((yyvsp[-2]),(yyvsp[-1]));
       }
#line 2398 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 84 "parser.y" /* yacc.c:1646  */
    {  
                  destroy ( (yyvsp[-1]), (yyvsp[0])) ; 
                  (yyvsp[-2]) = (yyvsp[-2])->symChange((yyvsp[-2]),TOK_PARAM);
                  (yyval) = new astree(FUNCTION, (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
               }
#line 2409 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 91 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]),(yyvsp[0]));
                  (yyval) = new astree(FUNCTION, (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
               }
#line 2419 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 97 "parser.y" /* yacc.c:1646  */
    {
                 destroy((yyvsp[-1]));
                 (yyvsp[-2]) = (yyvsp[-2])->symChange((yyvsp[-2]),TOK_PARAM);
                 (yyval) = new astree(FUNCTION,(yyvsp[-3])->lloc,"");
                 (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
                 (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2431 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 105 "parser.y" /* yacc.c:1646  */
    {
                 destroy((yyvsp[-1]));
                 (yyval) = new astree(FUNCTION,(yyvsp[-3])->lloc,"");
                 (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
                 (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2442 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 114 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = new astree(TYPE_ID,(yyvsp[-2])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-2]),(yyvsp[-1]));
               }
#line 2452 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 120 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-2]),(yyvsp[0]));
                  (yyval) = new astree(TYPE_ID,(yyvsp[-4])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-4]),(yyvsp[-3]));
                  (yyval) = (yyval)->adopt((yyvsp[-1]));
               }
#line 2463 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 129 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = new astree(TYPE_ID, (yyvsp[-1])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-1]),(yyvsp[0]));
               }
#line 2472 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 136 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = new astree(TOK_PARAM, (yyvsp[-1])->lloc, "(");
                  (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2481 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 141 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]));
                  // $$ = new astree(TOK_PARAM, $1->lloc, "(");
                  (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));
               }
#line 2491 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 150 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),CALL);
                  (yyval) = (yyval)->adopt((yyvsp[-2]),(yyvsp[0])); 
                  
               }
#line 2501 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 156 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]));
                  (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));
               }
#line 2510 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 164 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[0]));
         (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),CALL);
         (yyval) = (yyval)->adopt((yyvsp[-2]));
      }
#line 2520 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 170 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[0]));
         (yyval) = (yyvsp[-1]);
      }
#line 2529 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-3]),(yyvsp[-1]));
         (yyval) = (yyvsp[-4])->adopt((yyvsp[-2]),(yyvsp[0]));
       }
#line 2538 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 184 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-3]),(yyvsp[-1]));
         (yyval) = (yyvsp[-4])-> adopt((yyvsp[-2]),(yyvsp[0]));
       }
#line 2547 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 189 "parser.y" /* yacc.c:1646  */
    {
          destroy((yyvsp[-5]),(yyvsp[-3]));
          destroy((yyvsp[-1]));
          (yyvsp[-6]) = (yyvsp[-6])->adopt((yyvsp[-4]),(yyvsp[-2]));
          (yyvsp[-6]) = (yyvsp[-6])->adopt((yyvsp[0]));
          (yyval) = (yyvsp[-6]);          
       }
#line 2559 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 199 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[0]));
           (yyval) = (yyvsp[-1]);
        }
#line 2568 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 204 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[0]));
           (yyval) = (yyvsp[-2])->adopt((yyvsp[-1]));
        }
#line 2577 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 211 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-4]),(yyvsp[-2]));
         destroy((yyvsp[-1]),(yyvsp[0]));
         (yyval) = (yyvsp[-5])->adopt((yyvsp[-3]));
       }
#line 2587 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 217 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-5]),(yyvsp[-3]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyval) = (yyvsp[-6])->adopt((yyvsp[-4]),(yyvsp[-1]));
       }
#line 2597 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 224 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-6]),(yyvsp[-5]));
         destroy((yyvsp[-2]));
         destroy((yyvsp[-3]),(yyvsp[0]));
         (yyval) = (yyvsp[-7])->adopt((yyvsp[-4]),(yyvsp[-1]));
       }
#line 2608 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 232 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-5]),(yyvsp[-4]));
         destroy((yyvsp[-1]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyval) = (yyvsp[-6])->adopt((yyvsp[-3]));
       }
#line 2619 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 240 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-7]),(yyvsp[-5]));
         destroy((yyvsp[-3]),(yyvsp[-2]));
         destroy((yyvsp[-1]),(yyvsp[0]));
         (yyval) = (yyvsp[-8])->adopt((yyvsp[-6]),(yyvsp[-4]));
       }
#line 2630 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 248 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-8]),(yyvsp[-6]));
         destroy((yyvsp[-4]),(yyvsp[-3]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyvsp[-9]) = (yyvsp[-9])->adopt((yyvsp[-7]),(yyvsp[-5]));
         (yyval) = (yyvsp[-9])->adopt((yyvsp[-1]));
       }
#line 2642 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 259 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = (yyvsp[-1]);
               }
#line 2651 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 267 "parser.y" /* yacc.c:1646  */
    { 
               // destroy($1); 
               (yyval) = new astree(BLOCK,(yyvsp[-1])->lloc,"{"); 
               (yyval) = (yyval)->adopt((yyvsp[0]));
             }
#line 2661 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 273 "parser.y" /* yacc.c:1646  */
    {
               (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),BLOCK);
               (yyvsp[-1]) = (yyvsp[-1])->adopt((yyvsp[0]));
            }
#line 2670 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 278 "parser.y" /* yacc.c:1646  */
    {
               (yyval) = (yyvsp[0])->symChange((yyvsp[0]),BLOCK);
            }
#line 2678 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 285 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2686 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 289 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2694 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 293 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2702 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 297 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2710 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 301 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2718 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 305 "parser.y" /* yacc.c:1646  */
    {
            destroy((yyvsp[0]));
            (yyval)=(yyvsp[-1]);
         }
#line 2727 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 322 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1])->adopt ((yyvsp[-2]), (yyvsp[0])); 
         }
#line 2735 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 326 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2743 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 330 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2751 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 334 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2759 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 338 "parser.y" /* yacc.c:1646  */
    {
            destroy((yyvsp[0]));
            (yyval) = new astree(TOK_PARAM,(yyvsp[-2])->lloc,"(");
            (yyval) = (yyval)->adopt((yyvsp[-1]));
         }
#line 2769 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 344 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2777 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 348 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2785 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 354 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2793 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 358 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2801 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 362 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2809 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 366 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2817 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 370 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2825 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 374 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2833 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 378 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2841 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 382 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2849 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 386 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2857 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 390 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2865 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 394 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2873 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 398 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2881 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 404 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), POS); 
         }
#line 2889 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 408 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), NEG); 
         }
#line 2897 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 415 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = (yyvsp[0]);
               }
#line 2905 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 419 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = new astree(TOK_INDEX,(yyvsp[-2])->lloc,"[");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-1]));
               }
#line 2915 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 425 "parser.y" /* yacc.c:1646  */
    {
                  //get clarification for if we need to swap $1 & $3
                  (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
               }
#line 2924 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 431 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2930 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 433 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[-2]),(yyvsp[0]));
           (yyval) = (yyvsp[-3])->adopt((yyvsp[-1]));
        }
#line 2939 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 439 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2945 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 440 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2951 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 441 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2957 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 442 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2963 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 444 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[-3]),(yyvsp[0]));
           destroy((yyvsp[-2]));
           (yyval) = (yyvsp[-4])->adopt((yyvsp[-1]));
        }
#line 2973 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 451 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2979 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 452 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2985 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 453 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2991 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 454 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2997 "yyparse.cpp" /* yacc.c:1646  */
    break;


#line 3001 "yyparse.cpp" /* yacc.c:1646  */
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
#line 457 "parser.y" /* yacc.c:1906  */


const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}
