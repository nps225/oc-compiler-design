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

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 169 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   523

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

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
      49,    52,    42,    40,    53,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    55,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    51,     2,     2,     2,     2,
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
       0,    52,    52,    55,    56,    57,    58,    59,    60,    61,
      65,    72,    79,    85,    93,   102,   108,   117,   124,   129,
     138,   144,   152,   158,   165,   172,   178,   184,   192,   197,
     199,   204,   211,   217,   223,   231,   239,   247,   259,   269,
     274,   281,   291,   296,   302,   306,   311,   315,   319,   323,
     327,   331,   336,   352,   356,   360,   364,   368,   374,   378,
     384,   388,   392,   396,   400,   404,   408,   412,   416,   420,
     424,   428,   434,   438,   442,   449,   453,   459,   466,   467,
     474,   475,   476,   477,   478,   486,   487,   488,   489
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
  "'/'", "'%'", "'^'", "POS", "NEG", "'['", "'('", "';'", "'}'", "')'",
  "','", "'{'", "']'", "$accept", "start", "program", "struct", "function",
  "vardecl", "identif", "param", "callParam", "call", "while", "select",
  "ifelse", "else", "return", "alloc", "blockS", "blockBodyS", "block",
  "blockBody", "multiState", "state", "express", "binop", "unop", "var",
  "type", "type_id", "constant", YY_NULLPTR
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
      43,    45,    42,    47,    37,    94,   294,   295,    91,    40,
      59,   125,    41,    44,   123,    93
};
# endif

#define YYPACT_NINF -101

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -101,    20,     4,  -101,    -7,    -3,    36,    60,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,    33,    45,  -101,  -101,
    -101,    31,   172,    73,    25,    -5,   -37,    68,  -101,    72,
      69,   -33,  -101,    74,   -31,    54,   213,  -101,  -101,    62,
      68,   213,    93,    65,   196,  -101,  -101,  -101,    66,   213,
     213,   213,  -101,    68,  -101,     9,  -101,  -101,  -101,  -101,
    -101,    70,  -101,    68,  -101,   405,  -101,  -101,  -101,    81,
    -101,  -101,   104,  -101,  -101,  -101,  -101,  -101,  -101,   422,
     213,  -101,  -101,   -16,    17,   213,  -101,   458,    99,   -16,
     -16,   240,    75,    68,  -101,   213,    77,  -101,   213,   213,
     213,   213,   213,   213,    90,   213,   213,   213,   213,   213,
     213,   213,  -101,   -37,  -101,  -101,   257,    94,   113,   122,
     295,  -101,  -101,   475,  -101,  -101,   475,  -101,   276,   276,
     276,   276,   276,   276,  -101,   475,   -18,   -18,   -16,   -16,
     -16,   175,    68,   124,    54,    95,    68,  -101,   125,   100,
     131,   120,  -101,    68,  -101,   127,   135,  -101,   312,  -101,
    -101,   350,   117,  -101,  -101,   148,  -101,   367,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     0,     1,     0,     0,     0,     0,    83,    80,
      82,    81,     8,     3,     5,     4,     0,     0,    78,     6,
       7,     0,     0,     0,     0,     0,    17,    40,    10,     0,
       0,     0,    18,     0,     0,     0,     0,    15,    88,     0,
       0,     0,     0,     0,     0,    87,    86,    85,    75,     0,
       0,     0,    52,    43,    46,     0,    56,    48,    49,    50,
      55,     0,    47,    39,    44,     0,    53,    54,    58,     0,
      59,    79,     0,    11,    13,    17,    12,    14,    19,     0,
       0,    27,    25,    74,     0,     0,    30,     0,     0,    72,
      73,     0,     0,    42,    23,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,    84,    16,     0,     0,     0,     0,
       0,    31,    22,    20,    57,    41,    21,    38,    64,    66,
      61,    62,    63,    65,    77,    60,    67,    68,    69,    70,
      71,     0,     0,     0,     0,     0,     0,    76,    29,     0,
       0,     0,    24,     0,    26,     0,     0,    32,     0,    28,
      35,     0,     0,    33,    34,     0,    36,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,  -101,  -101,   168,   -17,  -101,  -101,  -101,
    -101,  -100,  -101,  -101,  -101,  -101,  -101,  -101,   -23,  -101,
     118,   -24,   -35,  -101,  -101,  -101,    -2,   153,  -101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,    14,    54,    16,    25,    55,    56,
      57,    81,    58,   154,    59,    60,    28,    61,    62,    92,
      63,    82,    65,    66,    67,    68,    69,    18,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    79,    36,    64,    -2,     4,    83,    32,    74,    87,
     104,    77,   104,    37,    89,    90,    91,    73,    78,    76,
       3,    53,    33,    53,   108,   109,   110,     5,     6,    64,
     111,     7,   111,    33,     8,    21,     9,    10,    11,    97,
     117,   118,   148,    19,    20,   116,   152,    34,    35,     6,
     120,   119,     7,   123,    12,     8,    22,     9,    10,    11,
     126,    94,    95,   128,   129,   130,   131,   132,   133,    97,
     135,   136,   137,   138,   139,   140,   141,    31,     6,    38,
      23,     7,    24,    26,     8,    27,     9,    10,    11,    39,
      40,    71,     6,    41,    42,     7,    30,    43,     8,    44,
       9,    10,    11,    45,    46,    47,    48,    72,    49,    50,
      38,    80,    75,    84,    85,    88,   158,    51,    52,   113,
     161,    96,    53,   114,    41,    42,   125,   127,   134,   159,
     167,    38,   143,   144,    45,    46,    47,    48,    38,    49,
      50,   145,   150,   149,   151,    41,    42,   153,    51,   155,
     156,   122,    41,    42,   162,    45,    46,    47,    48,    38,
      49,    50,    45,    46,    47,    48,   165,    49,    50,    51,
      15,    93,   157,    41,    42,    29,    51,     0,     0,   160,
       0,     0,     0,    45,    46,    47,    48,     0,    49,    50,
      98,    99,   100,   101,   102,   103,     0,    51,     0,     7,
     166,     0,     8,   104,     9,    10,    11,    38,     0,     0,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
       0,    41,    42,   111,    38,     0,     0,     0,     0,     0,
     147,    45,    46,    47,    48,     0,    49,    50,    41,    42,
       0,     0,     0,     0,     0,    51,    86,     0,    45,    46,
      47,    48,     0,    49,    50,    98,    99,   100,   101,   102,
     103,     0,    51,     0,     0,     0,     0,     0,   104,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   105,
     106,   107,   108,   109,   110,   104,     0,     0,   111,     0,
       0,     0,   124,     0,     0,     0,   105,   106,   107,   108,
     109,   110,     0,     0,   104,   111,     0,     0,     0,   142,
      98,    99,   100,   101,   102,   103,   106,   107,   108,   109,
     110,     0,     0,   104,   111,     0,     0,    98,    99,   100,
     101,   102,   103,     0,   105,   106,   107,   108,   109,   110,
     104,     0,     0,   111,     0,     0,     0,   146,     0,     0,
       0,   105,   106,   107,   108,   109,   110,     0,     0,     0,
     111,     0,     0,     0,   163,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   105,
     106,   107,   108,   109,   110,   104,     0,     0,   111,     0,
       0,     0,   164,     0,     0,     0,   105,   106,   107,   108,
     109,   110,     0,     0,     0,   111,     0,     0,     0,   168,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   104,     0,     0,     0,    98,    99,   100,
     101,   102,   103,     0,   105,   106,   107,   108,   109,   110,
     104,     0,     0,   111,     0,   112,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,     0,     0,     0,
     111,     0,   115,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   105,   106,   107,
     108,   109,   110,   104,     0,     0,   111,     0,   121,     0,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
       0,     0,     0,   111
};

static const yytype_int16 yycheck[] =
{
       2,    36,    39,    27,     0,     1,    41,    24,    31,    44,
      28,    34,    28,    50,    49,    50,    51,    50,    35,    50,
       0,    54,    24,    54,    42,    43,    44,    23,    24,    53,
      48,    27,    48,    35,    30,    38,    32,    33,    34,    63,
      23,    24,   142,    50,    51,    80,   146,    52,    53,    24,
      85,    34,    27,    88,    50,    30,    20,    32,    33,    34,
      95,    52,    53,    98,    99,   100,   101,   102,   103,    93,
     105,   106,   107,   108,   109,   110,   111,    52,    24,    11,
      20,    27,    49,    38,    30,    54,    32,    33,    34,    21,
      22,    19,    24,    25,    26,    27,    23,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    38,    40,    41,
      11,    49,    38,    20,    49,    49,   151,    49,    50,    38,
     155,    51,    54,    19,    25,    26,    51,    50,    38,   153,
     165,    11,    38,    20,    35,    36,    37,    38,    11,    40,
      41,    19,   144,    19,    49,    25,    26,    22,    49,    49,
      19,    52,    25,    26,    19,    35,    36,    37,    38,    11,
      40,    41,    35,    36,    37,    38,    49,    40,    41,    49,
       2,    53,    52,    25,    26,    22,    49,    -1,    -1,    52,
      -1,    -1,    -1,    35,    36,    37,    38,    -1,    40,    41,
      15,    16,    17,    18,    19,    20,    -1,    49,    -1,    27,
      52,    -1,    30,    28,    32,    33,    34,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    25,    26,    48,    11,    -1,    -1,    -1,    -1,    -1,
      55,    35,    36,    37,    38,    -1,    40,    41,    25,    26,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    35,    36,
      37,    38,    -1,    40,    41,    15,    16,    17,    18,    19,
      20,    -1,    49,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    39,
      40,    41,    42,    43,    44,    28,    -1,    -1,    48,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    -1,    -1,    28,    48,    -1,    -1,    -1,    52,
      15,    16,    17,    18,    19,    20,    40,    41,    42,    43,
      44,    -1,    -1,    28,    48,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    39,    40,    41,    42,    43,    44,
      28,    -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    52,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    39,
      40,    41,    42,    43,    44,    28,    -1,    -1,    48,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    39,    40,    41,    42,    43,    44,
      28,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    -1,    50,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    39,    40,    41,
      42,    43,    44,    28,    -1,    -1,    48,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,     0,     1,    23,    24,    27,    30,    32,
      33,    34,    50,    59,    60,    61,    62,    82,    83,    50,
      51,    38,    20,    20,    49,    63,    38,    54,    72,    83,
      23,    52,    62,    82,    52,    53,    39,    50,    11,    21,
      22,    25,    26,    29,    31,    35,    36,    37,    38,    40,
      41,    49,    50,    54,    61,    64,    65,    66,    68,    70,
      71,    73,    74,    76,    77,    78,    79,    80,    81,    82,
      84,    19,    38,    50,    74,    38,    50,    74,    62,    78,
      49,    67,    77,    78,    20,    49,    50,    78,    49,    78,
      78,    78,    75,    76,    52,    53,    51,    77,    15,    16,
      17,    18,    19,    20,    28,    39,    40,    41,    42,    43,
      44,    48,    50,    38,    19,    50,    78,    23,    24,    34,
      78,    50,    52,    78,    52,    51,    78,    50,    78,    78,
      78,    78,    78,    78,    38,    78,    78,    78,    78,    78,
      78,    78,    52,    38,    20,    19,    52,    55,    67,    19,
      82,    49,    67,    22,    69,    49,    19,    52,    78,    77,
      52,    78,    19,    52,    52,    49,    52,    78,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    58,    58,    58,    58,
      59,    60,    60,    60,    60,    61,    61,    62,    63,    63,
      64,    64,    65,    65,    66,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    72,    73,
      73,    74,    75,    75,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    80,    81,    81,    81,    82,    82,
      83,    83,    83,    83,    83,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     2,     0,
       3,     4,     4,     4,     4,     3,     5,     2,     2,     3,
       3,     3,     3,     2,     5,     1,     6,     2,     2,     0,
       2,     3,     6,     7,     8,     7,     9,    10,     4,     1,
       0,     3,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     1,     4,     3,     1,     4,
       1,     1,     1,     1,     5,     1,     1,     1,     1
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
#line 846 "parser.tab.c" /* yacc.c:684  */
        break;

    case 4: /* IDENT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 852 "parser.tab.c" /* yacc.c:684  */
        break;

    case 5: /* NUMBER  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 858 "parser.tab.c" /* yacc.c:684  */
        break;

    case 6: /* TYPE_ID  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 864 "parser.tab.c" /* yacc.c:684  */
        break;

    case 7: /* FUNCTION  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 870 "parser.tab.c" /* yacc.c:684  */
        break;

    case 8: /* TOK_PARAM  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 876 "parser.tab.c" /* yacc.c:684  */
        break;

    case 9: /* TOK_PROTOTYPE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 882 "parser.tab.c" /* yacc.c:684  */
        break;

    case 10: /* BLOCK  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 888 "parser.tab.c" /* yacc.c:684  */
        break;

    case 11: /* TOK_NULLPTR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 894 "parser.tab.c" /* yacc.c:684  */
        break;

    case 12: /* TOK_INDEX  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 900 "parser.tab.c" /* yacc.c:684  */
        break;

    case 13: /* CALL  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 906 "parser.tab.c" /* yacc.c:684  */
        break;

    case 14: /* ENDIF  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 912 "parser.tab.c" /* yacc.c:684  */
        break;

    case 15: /* TOK_GE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 918 "parser.tab.c" /* yacc.c:684  */
        break;

    case 16: /* TOK_LE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 924 "parser.tab.c" /* yacc.c:684  */
        break;

    case 17: /* TOK_EQ  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 930 "parser.tab.c" /* yacc.c:684  */
        break;

    case 18: /* TOK_NE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 936 "parser.tab.c" /* yacc.c:684  */
        break;

    case 19: /* TOK_GT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 942 "parser.tab.c" /* yacc.c:684  */
        break;

    case 20: /* TOK_LT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 948 "parser.tab.c" /* yacc.c:684  */
        break;

    case 21: /* TOK_IF  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 954 "parser.tab.c" /* yacc.c:684  */
        break;

    case 22: /* TOK_ELSE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 960 "parser.tab.c" /* yacc.c:684  */
        break;

    case 23: /* TOK_STRUCT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 966 "parser.tab.c" /* yacc.c:684  */
        break;

    case 24: /* TOK_ARRAY  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 972 "parser.tab.c" /* yacc.c:684  */
        break;

    case 25: /* TOK_NOT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 978 "parser.tab.c" /* yacc.c:684  */
        break;

    case 26: /* TOK_ALLOC  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 984 "parser.tab.c" /* yacc.c:684  */
        break;

    case 27: /* TOK_PTR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 990 "parser.tab.c" /* yacc.c:684  */
        break;

    case 28: /* TOK_ARROW  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 996 "parser.tab.c" /* yacc.c:684  */
        break;

    case 29: /* TOK_WHILE  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1002 "parser.tab.c" /* yacc.c:684  */
        break;

    case 30: /* TOK_VOID  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1008 "parser.tab.c" /* yacc.c:684  */
        break;

    case 31: /* TOK_RETURN  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1014 "parser.tab.c" /* yacc.c:684  */
        break;

    case 32: /* TOK_INT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1020 "parser.tab.c" /* yacc.c:684  */
        break;

    case 33: /* TOK_CHAR  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1026 "parser.tab.c" /* yacc.c:684  */
        break;

    case 34: /* TOK_STRING  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1032 "parser.tab.c" /* yacc.c:684  */
        break;

    case 35: /* TOK_CHARCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1038 "parser.tab.c" /* yacc.c:684  */
        break;

    case 36: /* TOK_STRINGCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1044 "parser.tab.c" /* yacc.c:684  */
        break;

    case 37: /* TOK_INTCON  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1050 "parser.tab.c" /* yacc.c:684  */
        break;

    case 38: /* TOK_IDENT  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1056 "parser.tab.c" /* yacc.c:684  */
        break;

    case 39: /* '='  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1062 "parser.tab.c" /* yacc.c:684  */
        break;

    case 40: /* '+'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1068 "parser.tab.c" /* yacc.c:684  */
        break;

    case 41: /* '-'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1074 "parser.tab.c" /* yacc.c:684  */
        break;

    case 42: /* '*'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1080 "parser.tab.c" /* yacc.c:684  */
        break;

    case 43: /* '/'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1086 "parser.tab.c" /* yacc.c:684  */
        break;

    case 44: /* '%'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1092 "parser.tab.c" /* yacc.c:684  */
        break;

    case 45: /* '^'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1098 "parser.tab.c" /* yacc.c:684  */
        break;

    case 46: /* POS  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1104 "parser.tab.c" /* yacc.c:684  */
        break;

    case 47: /* NEG  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1110 "parser.tab.c" /* yacc.c:684  */
        break;

    case 48: /* '['  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1116 "parser.tab.c" /* yacc.c:684  */
        break;

    case 49: /* '('  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1122 "parser.tab.c" /* yacc.c:684  */
        break;

    case 50: /* ';'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1128 "parser.tab.c" /* yacc.c:684  */
        break;

    case 51: /* '}'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1134 "parser.tab.c" /* yacc.c:684  */
        break;

    case 52: /* ')'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1140 "parser.tab.c" /* yacc.c:684  */
        break;

    case 53: /* ','  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1146 "parser.tab.c" /* yacc.c:684  */
        break;

    case 54: /* '{'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1152 "parser.tab.c" /* yacc.c:684  */
        break;

    case 55: /* ']'  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1158 "parser.tab.c" /* yacc.c:684  */
        break;

    case 57: /* start  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1164 "parser.tab.c" /* yacc.c:684  */
        break;

    case 58: /* program  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1170 "parser.tab.c" /* yacc.c:684  */
        break;

    case 59: /* struct  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1176 "parser.tab.c" /* yacc.c:684  */
        break;

    case 60: /* function  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1182 "parser.tab.c" /* yacc.c:684  */
        break;

    case 61: /* vardecl  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1188 "parser.tab.c" /* yacc.c:684  */
        break;

    case 62: /* identif  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1194 "parser.tab.c" /* yacc.c:684  */
        break;

    case 63: /* param  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1200 "parser.tab.c" /* yacc.c:684  */
        break;

    case 64: /* callParam  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1206 "parser.tab.c" /* yacc.c:684  */
        break;

    case 65: /* call  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1212 "parser.tab.c" /* yacc.c:684  */
        break;

    case 66: /* while  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1218 "parser.tab.c" /* yacc.c:684  */
        break;

    case 67: /* select  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1224 "parser.tab.c" /* yacc.c:684  */
        break;

    case 68: /* ifelse  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1230 "parser.tab.c" /* yacc.c:684  */
        break;

    case 69: /* else  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1236 "parser.tab.c" /* yacc.c:684  */
        break;

    case 70: /* return  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1242 "parser.tab.c" /* yacc.c:684  */
        break;

    case 71: /* alloc  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1248 "parser.tab.c" /* yacc.c:684  */
        break;

    case 72: /* blockS  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1254 "parser.tab.c" /* yacc.c:684  */
        break;

    case 73: /* blockBodyS  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1260 "parser.tab.c" /* yacc.c:684  */
        break;

    case 74: /* block  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1266 "parser.tab.c" /* yacc.c:684  */
        break;

    case 75: /* blockBody  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1272 "parser.tab.c" /* yacc.c:684  */
        break;

    case 76: /* multiState  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1278 "parser.tab.c" /* yacc.c:684  */
        break;

    case 77: /* state  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1284 "parser.tab.c" /* yacc.c:684  */
        break;

    case 78: /* express  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1290 "parser.tab.c" /* yacc.c:684  */
        break;

    case 79: /* binop  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1296 "parser.tab.c" /* yacc.c:684  */
        break;

    case 80: /* unop  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1302 "parser.tab.c" /* yacc.c:684  */
        break;

    case 81: /* var  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1308 "parser.tab.c" /* yacc.c:684  */
        break;

    case 82: /* type  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1314 "parser.tab.c" /* yacc.c:684  */
        break;

    case 83: /* type_id  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1320 "parser.tab.c" /* yacc.c:684  */
        break;

    case 84: /* constant  */
#line 21 "parser.y" /* yacc.c:684  */
      { astree::dump (yyoutput, ((*yyvaluep))); }
#line 1326 "parser.tab.c" /* yacc.c:684  */
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
#line 1672 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 4: /* IDENT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1678 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 5: /* NUMBER  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1684 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 6: /* TYPE_ID  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1690 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 7: /* FUNCTION  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1696 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 8: /* TOK_PARAM  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1702 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 9: /* TOK_PROTOTYPE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1708 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 10: /* BLOCK  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1714 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 11: /* TOK_NULLPTR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1720 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 12: /* TOK_INDEX  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1726 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 13: /* CALL  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1732 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 14: /* ENDIF  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1738 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 15: /* TOK_GE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1744 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 16: /* TOK_LE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1750 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 17: /* TOK_EQ  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1756 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 18: /* TOK_NE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1762 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 19: /* TOK_GT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1768 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 20: /* TOK_LT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1774 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 21: /* TOK_IF  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1780 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 22: /* TOK_ELSE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1786 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 23: /* TOK_STRUCT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1792 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 24: /* TOK_ARRAY  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1798 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 25: /* TOK_NOT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1804 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 26: /* TOK_ALLOC  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1810 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 27: /* TOK_PTR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1816 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 28: /* TOK_ARROW  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1822 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 29: /* TOK_WHILE  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1828 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 30: /* TOK_VOID  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1834 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 31: /* TOK_RETURN  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1840 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 32: /* TOK_INT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1846 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 33: /* TOK_CHAR  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1852 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 34: /* TOK_STRING  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1858 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 35: /* TOK_CHARCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1864 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 36: /* TOK_STRINGCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1870 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 37: /* TOK_INTCON  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1876 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 38: /* TOK_IDENT  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1882 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 39: /* '='  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1888 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 40: /* '+'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1894 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 41: /* '-'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1900 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 42: /* '*'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1906 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 43: /* '/'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1912 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 44: /* '%'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1918 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 45: /* '^'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1924 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 46: /* POS  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1930 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 47: /* NEG  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1936 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 48: /* '['  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1942 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 49: /* '('  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1948 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 50: /* ';'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1954 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 51: /* '}'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1960 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 52: /* ')'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1966 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 53: /* ','  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1972 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* '{'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1978 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* ']'  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1984 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 57: /* start  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1990 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 58: /* program  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 1996 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 59: /* struct  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2002 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 60: /* function  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2008 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 61: /* vardecl  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2014 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 62: /* identif  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2020 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 63: /* param  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2026 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 64: /* callParam  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2032 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 65: /* call  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2038 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 66: /* while  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2044 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 67: /* select  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2050 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 68: /* ifelse  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2056 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 69: /* else  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2062 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 70: /* return  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2068 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 71: /* alloc  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2074 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 72: /* blockS  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2080 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 73: /* blockBodyS  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2086 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 74: /* block  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2092 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 75: /* blockBody  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2098 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 76: /* multiState  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2104 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 77: /* state  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2110 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 78: /* express  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2116 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 79: /* binop  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2122 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 80: /* unop  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2128 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 81: /* var  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2134 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 82: /* type  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2140 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 83: /* type_id  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2146 "parser.tab.c" /* yacc.c:1257  */
        break;

    case 84: /* constant  */
#line 20 "parser.y" /* yacc.c:1257  */
      { destroy (((*yyvaluep))); }
#line 2152 "parser.tab.c" /* yacc.c:1257  */
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

#line 2242 "parser.tab.c" /* yacc.c:1429  */
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
#line 2424 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2430 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 2442 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]); }
#line 2448 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-2]); }
#line 2454 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 60 "parser.y" /* yacc.c:1646  */
    { destroy ((yyvsp[0])); (yyval) = (yyvsp[-1]); }
#line 2460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval) = parser::root; }
#line 2466 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "parser.y" /* yacc.c:1646  */
    {
         // destroy($4);
         (yyval) = (yyvsp[-2])->adopt((yyvsp[-1]),(yyvsp[0]));
       }
#line 2475 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 73 "parser.y" /* yacc.c:1646  */
    {  
                  destroy ( (yyvsp[-1]), (yyvsp[0])) ; 
                  (yyvsp[-2]) = (yyvsp[-2])->symChange((yyvsp[-2]),TOK_PARAM);
                  (yyval) = new astree(FUNCTION, (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
               }
#line 2486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 80 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]),(yyvsp[0]));
                  (yyval) = new astree(FUNCTION, (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
               }
#line 2496 "parser.tab.c" /* yacc.c:1646  */
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
#line 2508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 94 "parser.y" /* yacc.c:1646  */
    {
                 destroy((yyvsp[-1]));
                 (yyval) = new astree(FUNCTION,(yyvsp[-3])->lloc,"");
                 (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-2]));
                 (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 103 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = new astree(TYPE_ID,(yyvsp[-2])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-2]),(yyvsp[-1]));
               }
#line 2529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 109 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-2]),(yyvsp[0]));
                  (yyval) = new astree(TYPE_ID,(yyvsp[-4])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-4]),(yyvsp[-3]));
                  (yyval) = (yyval)->adopt((yyvsp[-1]));
               }
#line 2540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = new astree(TYPE_ID, (yyvsp[-1])->lloc,"");
                  (yyval) = (yyval)->adopt((yyvsp[-1]),(yyvsp[0]));
               }
#line 2549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 125 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = new astree(TOK_PARAM, (yyvsp[-1])->lloc, "(");
                  (yyval) = (yyval)->adopt((yyvsp[0]));
               }
#line 2558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]));
                  // $$ = new astree(TOK_PARAM, $1->lloc, "(");
                  (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));
               }
#line 2568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 139 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),CALL);
                  (yyval) = (yyval)->adopt((yyvsp[-2]),(yyvsp[0])); 
                  
               }
#line 2578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 145 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]));
                  (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));
               }
#line 2587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 153 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[0]));
         (yyval) = (yyvsp[-1])->symChange((yyvsp[-1]),CALL);
         (yyval) = (yyval)->adopt((yyvsp[-2]));
      }
#line 2597 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 159 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[0]));
         (yyval) = (yyvsp[-1]);
      }
#line 2606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-3]),(yyvsp[-1]));
         (yyval) = (yyvsp[-4])->adopt((yyvsp[-2]),(yyvsp[0]));
       }
#line 2615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 173 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[0]);
        }
#line 2623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 179 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-4]),(yyvsp[-2]));
         (yyval) = (yyvsp[-5])-> adopt((yyvsp[-3]),(yyvsp[-1]));
         (yyval) = (yyval)->adopt((yyvsp[0]));
       }
#line 2633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 185 "parser.y" /* yacc.c:1646  */
    {
          destroy((yyvsp[-1]));
          (yyval) = (yyval)->adopt((yyvsp[0]));  
       }
#line 2642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 193 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-1]));
         (yyval) = (yyvsp[0]);
      }
#line 2651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 200 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[0]));
           (yyval) = (yyvsp[-1]);
        }
#line 2660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 205 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[0]));
           (yyval) = (yyvsp[-2])->adopt((yyvsp[-1]));
        }
#line 2669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 212 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-4]),(yyvsp[-2]));
         destroy((yyvsp[-1]),(yyvsp[0]));
         (yyval) = (yyvsp[-5])->adopt((yyvsp[-3]));
       }
#line 2679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 218 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-5]),(yyvsp[-3]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyval) = (yyvsp[-6])->adopt((yyvsp[-4]),(yyvsp[-1]));
       }
#line 2689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 225 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-6]),(yyvsp[-5]));
         destroy((yyvsp[-2]));
         destroy((yyvsp[-3]),(yyvsp[0]));
         (yyval) = (yyvsp[-7])->adopt((yyvsp[-4]),(yyvsp[-1]));
       }
#line 2700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 233 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-5]),(yyvsp[-4]));
         destroy((yyvsp[-1]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyval) = (yyvsp[-6])->adopt((yyvsp[-3]));
       }
#line 2711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 241 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-7]),(yyvsp[-5]));
         destroy((yyvsp[-3]),(yyvsp[-2]));
         destroy((yyvsp[-1]),(yyvsp[0]));
         (yyval) = (yyvsp[-8])->adopt((yyvsp[-6]),(yyvsp[-4]));
       }
#line 2722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 249 "parser.y" /* yacc.c:1646  */
    {
         destroy((yyvsp[-8]),(yyvsp[-6]));
         destroy((yyvsp[-4]),(yyvsp[-3]));
         destroy((yyvsp[-2]),(yyvsp[0]));
         (yyvsp[-9]) = (yyvsp[-9])->adopt((yyvsp[-7]),(yyvsp[-5]));
         (yyval) = (yyvsp[-9])->adopt((yyvsp[-1]));
       }
#line 2734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 260 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[-1]),(yyvsp[0]));
                  (yyval) = (yyvsp[-3])->symChange((yyvsp[-3]),BLOCK);
                  (yyval) = (yyval)->adopt((yyvsp[-2]));
               }
#line 2744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 270 "parser.y" /* yacc.c:1646  */
    { 
                
               (yyval) = (yyvsp[0]);
             }
#line 2753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 282 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = (yyvsp[-2])->symChange((yyvsp[-2]),BLOCK);
                  (yyval) = (yyval)->adopt((yyvsp[-1]));
               }
#line 2763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 292 "parser.y" /* yacc.c:1646  */
    { 
                
               (yyval) = (yyvsp[0]);
             }
#line 2772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 303 "parser.y" /* yacc.c:1646  */
    {
              (yyval) = (yyvsp[0]);
           }
#line 2780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 307 "parser.y" /* yacc.c:1646  */
    {
              (yyval) = (yyvsp[-1])->adopt((yyvsp[0]));
           }
#line 2788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 312 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 316 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 320 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2812 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 324 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 328 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 332 "parser.y" /* yacc.c:1646  */
    {
            destroy((yyvsp[0]));
            (yyval)=(yyvsp[-1]);
         }
#line 2837 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 337 "parser.y" /* yacc.c:1646  */
    {
             (yyval) = new astree(BLOCK,(yyvsp[0])->lloc,"{");
         }
#line 2845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 353 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 357 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2861 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 361 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 365 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2877 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 369 "parser.y" /* yacc.c:1646  */
    {
            destroy((yyvsp[0]));
            (yyval) = new astree(TOK_PARAM,(yyvsp[-2])->lloc,"(");
            (yyval) = (yyval)->adopt((yyvsp[-1]));
         }
#line 2887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 375 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2895 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 379 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
         }
#line 2903 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 385 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 389 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2919 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 393 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2927 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 397 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 401 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2943 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 405 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2951 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 409 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 413 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2967 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 417 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2975 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 421 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2983 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 425 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2991 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 429 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
        }
#line 2999 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 435 "parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), POS); 
         }
#line 3007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 439 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), NEG); 
         }
#line 3015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 443 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = (yyvsp[-1])->adopt_sym ((yyvsp[0]), NEG); 
         }
#line 3023 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 450 "parser.y" /* yacc.c:1646  */
    {
                  (yyval) = (yyvsp[0]);
               }
#line 3031 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 454 "parser.y" /* yacc.c:1646  */
    {
                  destroy((yyvsp[0]));
                  (yyval) = new astree(TOK_INDEX,(yyvsp[-2])->lloc,"[");
                  (yyval) = (yyval)->adopt((yyvsp[-3]),(yyvsp[-1]));
               }
#line 3041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 460 "parser.y" /* yacc.c:1646  */
    {
                  //get clarification for if we need to swap $1 & $3
                  (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0]));
               }
#line 3050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 466 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3056 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 468 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[-2]),(yyvsp[0]));
           (yyval) = (yyvsp[-3])->adopt((yyvsp[-1]));
        }
#line 3065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 474 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3071 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 475 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 476 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 477 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 479 "parser.y" /* yacc.c:1646  */
    {
           destroy((yyvsp[-3]),(yyvsp[0]));
           destroy((yyvsp[-2]));
           (yyval) = (yyvsp[-4])->adopt((yyvsp[-1]));
        }
#line 3099 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 486 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3105 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 487 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3111 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 488 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3117 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 489 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 3123 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 3127 "parser.tab.c" /* yacc.c:1646  */
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
#line 492 "parser.y" /* yacc.c:1906  */


const char* parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}
