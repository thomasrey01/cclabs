/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "codegen.h"
#include "strtab.h"
#include "symbolTable.h"
#include "semanticsCheck.h"
#include "linkedList.h"
#include "stack.h"

  struct stack *s;
  struct stack *labels;
  int max(int val1, int val2);
  void yyerror(char *msg);    /* forward declaration */
  /* exported by the lexer (made with flex) */
  extern int yylex(void);
  extern char *yytext;
  extern void showErrorLine();
  extern void initLexer(FILE *f);
  extern void finalizeLexer();
  extern int readToken;
  int funcSave;
  struct symbol *createNewSymbol(int idx);
  void assignType(int type, struct symbol *sym);
  void printList(struct symbol *symbol);
  int countList(struct symbol *sym);

#line 99 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_CONST = 4,                      /* CONST  */
  YYSYMBOL_IDENTIFIER = 5,                 /* IDENTIFIER  */
  YYSYMBOL_VAR = 6,                        /* VAR  */
  YYSYMBOL_ARRAY = 7,                      /* ARRAY  */
  YYSYMBOL_RANGE = 8,                      /* RANGE  */
  YYSYMBOL_INTNUMBER = 9,                  /* INTNUMBER  */
  YYSYMBOL_REALNUMBER = 10,                /* REALNUMBER  */
  YYSYMBOL_OF = 11,                        /* OF  */
  YYSYMBOL_FUNCTION = 12,                  /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 13,                 /* PROCEDURE  */
  YYSYMBOL_BEGINTOK = 14,                  /* BEGINTOK  */
  YYSYMBOL_ENDTOK = 15,                    /* ENDTOK  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_THEN = 18,                      /* THEN  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_DO = 21,                        /* DO  */
  YYSYMBOL_RELOPLT = 22,                   /* RELOPLT  */
  YYSYMBOL_RELOPLEQ = 23,                  /* RELOPLEQ  */
  YYSYMBOL_RELOPEQ = 24,                   /* RELOPEQ  */
  YYSYMBOL_RELOPNEQ = 25,                  /* RELOPNEQ  */
  YYSYMBOL_RELOPGEQ = 26,                  /* RELOPGEQ  */
  YYSYMBOL_RELOPGT = 27,                   /* RELOPGT  */
  YYSYMBOL_INTEGER = 28,                   /* INTEGER  */
  YYSYMBOL_REAL = 29,                      /* REAL  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_MOD = 34,                       /* MOD  */
  YYSYMBOL_SKIP = 35,                      /* SKIP  */
  YYSYMBOL_READLN = 36,                    /* READLN  */
  YYSYMBOL_WRITELN = 37,                   /* WRITELN  */
  YYSYMBOL_38_ = 38,                       /* '+'  */
  YYSYMBOL_39_ = 39,                       /* '-'  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '.'  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_55_4 = 55,                      /* $@4  */
  YYSYMBOL_ConstDecl = 56,                 /* ConstDecl  */
  YYSYMBOL_NumericValue = 57,              /* NumericValue  */
  YYSYMBOL_VarDecl = 58,                   /* VarDecl  */
  YYSYMBOL_IdentifierList = 59,            /* IdentifierList  */
  YYSYMBOL_TypeSpec = 60,                  /* TypeSpec  */
  YYSYMBOL_BasicType = 61,                 /* BasicType  */
  YYSYMBOL_FuncProcDecl = 62,              /* FuncProcDecl  */
  YYSYMBOL_SubProgDecl = 63,               /* SubProgDecl  */
  YYSYMBOL_64_5 = 64,                      /* $@5  */
  YYSYMBOL_SubProgHeading = 65,            /* SubProgHeading  */
  YYSYMBOL_66_6 = 66,                      /* $@6  */
  YYSYMBOL_67_7 = 67,                      /* $@7  */
  YYSYMBOL_PossibleParameters = 68,        /* PossibleParameters  */
  YYSYMBOL_Parameters = 69,                /* Parameters  */
  YYSYMBOL_ParameterList = 70,             /* ParameterList  */
  YYSYMBOL_ParamList = 71,                 /* ParamList  */
  YYSYMBOL_CompoundStatement = 72,         /* CompoundStatement  */
  YYSYMBOL_OptionalStatements = 73,        /* OptionalStatements  */
  YYSYMBOL_StatementList = 74,             /* StatementList  */
  YYSYMBOL_Statement = 75,                 /* Statement  */
  YYSYMBOL_76_8 = 76,                      /* $@8  */
  YYSYMBOL_77_9 = 77,                      /* $@9  */
  YYSYMBOL_78_10 = 78,                     /* $@10  */
  YYSYMBOL_79_11 = 79,                     /* $@11  */
  YYSYMBOL_Lhs = 80,                       /* Lhs  */
  YYSYMBOL_81_12 = 81,                     /* $@12  */
  YYSYMBOL_ProcedureCall = 82,             /* ProcedureCall  */
  YYSYMBOL_83_13 = 83,                     /* $@13  */
  YYSYMBOL_Guard = 84,                     /* Guard  */
  YYSYMBOL_BoolAtom = 85,                  /* BoolAtom  */
  YYSYMBOL_Relop = 86,                     /* Relop  */
  YYSYMBOL_ArithExprList = 87,             /* ArithExprList  */
  YYSYMBOL_ArithExpr = 88,                 /* ArithExpr  */
  YYSYMBOL_89_14 = 89,                     /* $@14  */
  YYSYMBOL_90_15 = 90                      /* $@15  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,    40,    38,    45,    39,    43,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    69,    70,    71,    68,    76,    82,    85,
      89,    95,   100,   103,   104,   110,   111,   114,   115,   118,
     119,   122,   122,   125,   125,   129,   129,   135,   136,   139,
     142,   143,   146,   147,   150,   153,   154,   157,   158,   161,
     162,   163,   164,   171,   175,   164,   177,   177,   182,   185,
     188,   192,   193,   193,   200,   201,   201,   204,   205,   206,
     207,   208,   211,   214,   215,   216,   217,   218,   219,   222,
     223,   230,   234,   234,   238,   238,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "CONST",
  "IDENTIFIER", "VAR", "ARRAY", "RANGE", "INTNUMBER", "REALNUMBER", "OF",
  "FUNCTION", "PROCEDURE", "BEGINTOK", "ENDTOK", "ASSIGN", "IF", "THEN",
  "ELSE", "WHILE", "DO", "RELOPLT", "RELOPLEQ", "RELOPEQ", "RELOPNEQ",
  "RELOPGEQ", "RELOPGT", "INTEGER", "REAL", "AND", "OR", "NOT", "DIV",
  "MOD", "SKIP", "READLN", "WRITELN", "'+'", "'-'", "'*'", "'/'", "';'",
  "'.'", "':'", "','", "'['", "']'", "'('", "')'", "$accept", "program",
  "$@1", "$@2", "$@3", "$@4", "ConstDecl", "NumericValue", "VarDecl",
  "IdentifierList", "TypeSpec", "BasicType", "FuncProcDecl", "SubProgDecl",
  "$@5", "SubProgHeading", "$@6", "$@7", "PossibleParameters",
  "Parameters", "ParameterList", "ParamList", "CompoundStatement",
  "OptionalStatements", "StatementList", "Statement", "$@8", "$@9", "$@10",
  "$@11", "Lhs", "$@12", "ProcedureCall", "$@13", "Guard", "BoolAtom",
  "Relop", "ArithExprList", "ArithExpr", "$@14", "$@15", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,     7,    15,   -13,  -115,  -115,  -115,    46,    74,  -115,
      60,    31,    57,    96,  -115,  -115,  -115,    54,  -115,    32,
      82,  -115,    20,   109,   132,   142,   116,   118,  -115,   111,
    -115,  -115,   119,  -115,  -115,  -115,  -115,    -1,   124,  -115,
      31,   159,  -115,   121,   121,     8,    13,  -115,  -115,   121,
     122,  -115,   156,   130,  -115,   157,  -115,  -115,   116,   166,
     123,   131,   134,  -115,   133,   129,    22,  -115,  -115,    13,
      21,    13,    90,  -115,    84,    13,  -115,    21,  -115,    -1,
      21,  -115,   169,    96,    91,   -32,  -115,   112,  -115,    21,
      21,   135,   136,  -115,    21,    59,    34,    64,    13,    13,
     162,  -115,  -115,  -115,  -115,  -115,  -115,    21,    21,    21,
      21,    21,    21,    21,    41,    33,   125,  -115,   125,   138,
     106,    20,   123,  -115,   140,   105,    67,    21,    21,    93,
    -115,  -115,  -115,   153,    -1,  -115,  -115,    59,    59,  -115,
    -115,   125,    -1,    21,  -115,   175,    20,  -115,  -115,  -115,
    -115,  -115,   115,    70,  -115,  -115,   125,   112,  -115,  -115,
    -115,   168,  -115,  -115,    -1,  -115
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     8,     3,     0,    12,
       0,     4,     0,     0,    20,     9,    10,     0,    13,     0,
       5,     7,     0,     0,     0,     0,     0,     0,    12,     0,
      17,    18,     0,    15,    14,    23,    25,    36,     0,    19,
      21,     0,    11,     0,    28,    54,     0,    46,    50,     0,
       0,    41,     0,    35,    37,     0,    40,     6,     0,     0,
       0,     0,     0,    27,     0,     0,    71,    76,    77,     0,
       0,     0,    42,    57,     0,     0,    48,     0,    34,     0,
       0,    22,     0,     0,     0,     0,    30,     0,    26,     0,
       0,     0,     0,    58,     0,    84,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    38,    39,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
      61,    85,    60,    59,     0,    82,    83,    78,    79,    80,
      81,    62,     0,     0,    49,     0,     0,    33,    31,    24,
      53,    56,     0,     0,    43,    47,    70,     0,    32,    73,
      75,     0,    16,    44,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,   160,   -10,
    -114,   -82,  -115,  -115,  -115,  -115,  -115,  -115,  -115,   -16,
    -115,    68,   -12,  -115,  -115,   -79,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,   -18,  -115,  -115,   -81,   -69,  -115,
    -115
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     6,     9,    14,    26,     7,    17,    11,    84,
      32,    33,    20,    27,    58,    28,    43,    44,    62,    61,
      85,    86,    51,    52,    53,    54,   100,   161,   164,    75,
      55,    64,    56,    65,    72,    73,   113,   115,    74,    91,
      92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     117,    95,    97,    19,    45,   124,     1,   147,   116,   126,
     122,   118,     3,    37,    38,     4,    46,   123,    66,    47,
     125,   116,    67,    68,   -51,   129,    66,    29,    63,     5,
      67,    68,   158,    76,    48,    49,    50,    13,   135,   136,
     137,   138,   139,   140,   141,    69,    81,   153,    30,    31,
       8,    93,    70,    96,   -52,   154,   -55,   114,   152,   116,
      70,    71,   142,   155,    98,    99,    15,    16,   -72,    94,
     -74,    98,    99,   120,   156,   162,    22,    23,   143,    10,
     132,   133,   144,   130,    12,   165,   101,   102,   103,   104,
     105,   106,   107,   108,    24,    25,    21,   107,   108,   111,
     112,    18,   109,   110,   111,   112,   101,   102,   103,   104,
     105,   106,   143,   131,    34,   143,   151,   107,   108,   160,
      98,    99,   109,   110,   111,   112,   107,   108,    18,    83,
      37,   109,   110,   111,   112,   121,    23,    35,   107,   108,
      30,    31,   131,   109,   110,   111,   112,    36,   107,   108,
     146,    23,   150,   109,   110,   111,   112,    41,   107,   108,
      39,    42,   159,   109,   110,   111,   112,    57,    59,    60,
      77,    78,    79,    80,    82,    87,    88,    90,   119,    89,
     134,   127,   149,    98,   128,   145,   157,   163,    40,     0,
     148
};

static const yytype_int16 yycheck[] =
{
      79,    70,    71,    13,     5,    87,     3,   121,    77,    90,
      42,    80,     5,    14,    26,     0,    17,    49,     5,    20,
      89,    90,     9,    10,    16,    94,     5,     7,    44,    42,
       9,    10,   146,    49,    35,    36,    37,     6,   107,   108,
     109,   110,   111,   112,   113,    32,    58,   128,    28,    29,
       4,    69,    39,    71,    46,   134,    48,    75,   127,   128,
      39,    48,    21,   142,    30,    31,     9,    10,    46,    48,
      48,    30,    31,    83,   143,   157,    44,    45,    45,     5,
      98,    99,    49,    49,    24,   164,    22,    23,    24,    25,
      26,    27,    33,    34,    12,    13,    42,    33,    34,    40,
      41,     5,    38,    39,    40,    41,    22,    23,    24,    25,
      26,    27,    45,    49,     5,    45,    49,    33,    34,    49,
      30,    31,    38,    39,    40,    41,    33,    34,     5,     6,
      14,    38,    39,    40,    41,    44,    45,     5,    33,    34,
      28,    29,    49,    38,    39,    40,    41,     5,    33,    34,
      44,    45,    47,    38,    39,    40,    41,    46,    33,    34,
      42,    42,    47,    38,    39,    40,    41,    43,     9,    48,
      48,    15,    42,    16,     8,    44,    42,    48,     9,    46,
      18,    46,    42,    30,    48,    47,    11,    19,    28,    -1,
     122
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    51,     5,     0,    42,    52,    56,     4,    53,
       5,    58,    24,     6,    54,     9,    10,    57,     5,    59,
      62,    42,    44,    45,    12,    13,    55,    63,    65,     7,
      28,    29,    60,    61,     5,     5,     5,    14,    72,    42,
      58,    46,    42,    66,    67,     5,    17,    20,    35,    36,
      37,    72,    73,    74,    75,    80,    82,    43,    64,     9,
      48,    69,    68,    69,    81,    83,     5,     9,    10,    32,
      39,    48,    84,    85,    88,    79,    69,    48,    15,    42,
      16,    72,     8,     6,    59,    70,    71,    44,    42,    46,
      48,    89,    90,    84,    48,    88,    84,    88,    30,    31,
      76,    22,    23,    24,    25,    26,    27,    33,    34,    38,
      39,    40,    41,    86,    84,    87,    88,    75,    88,     9,
      59,    44,    42,    49,    61,    88,    87,    46,    48,    88,
      49,    49,    84,    84,    18,    88,    88,    88,    88,    88,
      88,    88,    21,    45,    49,    47,    44,    60,    71,    42,
      47,    49,    88,    87,    75,    75,    88,    11,    60,    47,
      49,    77,    61,    19,    78,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    52,    53,    54,    55,    51,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    64,    63,    66,    65,    67,    65,    68,    68,    69,
      70,    70,    71,    71,    72,    73,    73,    74,    74,    75,
      75,    75,    76,    77,    78,    75,    79,    75,    75,    75,
      75,    80,    81,    80,    82,    83,    82,    84,    84,    84,
      84,    84,    85,    86,    86,    86,    86,    86,    86,    87,
      87,    88,    89,    88,    90,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    12,     6,     0,     1,
       1,     6,     0,     1,     3,     1,     8,     1,     1,     3,
       0,     0,     4,     0,     7,     0,     5,     1,     0,     3,
       1,     3,     4,     3,     3,     1,     0,     1,     3,     3,
       1,     1,     0,     0,     0,     9,     0,     5,     2,     4,
       1,     1,     0,     5,     1,     0,     5,     1,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     0,     5,     0,     5,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* $@1: %empty  */
#line 68 "parser.y"
                                            { printHeaders(); }
#line 1296 "parser.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 69 "parser.y"
                               { printVars((yyvsp[0].iden), 1); }
#line 1302 "parser.tab.c"
    break;

  case 4: /* $@3: %empty  */
#line 70 "parser.y"
                             { printVars((yyvsp[0].iden), 0); }
#line 1308 "parser.tab.c"
    break;

  case 5: /* $@4: %empty  */
#line 71 "parser.y"
                                      { printMain(); }
#line 1314 "parser.tab.c"
    break;

  case 6: /* program: PROGRAM IDENTIFIER ';' $@1 ConstDecl $@2 VarDecl $@3 FuncProcDecl $@4 CompoundStatement '.'  */
#line 73 "parser.y"
                             { printf("}\n"); }
#line 1320 "parser.tab.c"
    break;

  case 7: /* ConstDecl: ConstDecl CONST IDENTIFIER RELOPEQ NumericValue ';'  */
#line 76 "parser.y"
                                                                         { 
                    (yyval.iden) = createNewNode(yylval.ival);
                    (yyval.iden)->next = (yyvsp[-5].iden);
                    assignValue((yyval.iden), (yyvsp[-1].iden));
                    free((yyvsp[-1].iden));
}
#line 1331 "parser.tab.c"
    break;

  case 8: /* ConstDecl: %empty  */
#line 82 "parser.y"
                                       { (yyval.iden) = NULL; }
#line 1337 "parser.tab.c"
    break;

  case 9: /* NumericValue: INTNUMBER  */
#line 85 "parser.y"
                               { (yyval.iden) = createNewNode(-1);
                                (yyval.iden)->type = 0;
                                (yyval.iden)->ival = yylval.ival;
}
#line 1346 "parser.tab.c"
    break;

  case 10: /* NumericValue: REALNUMBER  */
#line 89 "parser.y"
                                { (yyval.iden) = createNewNode(-1);
                                (yyval.iden)->type = 1;
                                (yyval.iden)->rval = yylval.rval;
}
#line 1355 "parser.tab.c"
    break;

  case 11: /* VarDecl: VarDecl VAR IdentifierList ':' TypeSpec ';'  */
#line 95 "parser.y"
                                                                 { 
                        addType((yyvsp[-3].iden), (yyvsp[-1].ival)); 
                        appendToList((yyvsp[-3].iden), (yyvsp[-5].iden)); 
                        (yyval.iden) = (yyvsp[-3].iden);
                    }
#line 1365 "parser.tab.c"
    break;

  case 12: /* VarDecl: %empty  */
#line 100 "parser.y"
                                       { (yyval.iden) = NULL; }
#line 1371 "parser.tab.c"
    break;

  case 13: /* IdentifierList: IDENTIFIER  */
#line 103 "parser.y"
                                { (yyval.iden) = createNewNode(yylval.ival); (yyval.iden)->next = NULL; }
#line 1377 "parser.tab.c"
    break;

  case 14: /* IdentifierList: IdentifierList ',' IDENTIFIER  */
#line 104 "parser.y"
                                                   { 
                        (yyval.iden) = createNewNode(yylval.ival);
                        (yyval.iden)->next = (yyvsp[-2].iden);
}
#line 1386 "parser.tab.c"
    break;

  case 15: /* TypeSpec: BasicType  */
#line 110 "parser.y"
                               { (yyval.ival) = (yyvsp[0].ival); }
#line 1392 "parser.tab.c"
    break;

  case 16: /* TypeSpec: ARRAY '[' INTNUMBER RANGE INTNUMBER ']' OF BasicType  */
#line 111 "parser.y"
                                                                          { (yyval.ival) = (yyvsp[0].ival); }
#line 1398 "parser.tab.c"
    break;

  case 17: /* BasicType: INTEGER  */
#line 114 "parser.y"
                             { (yyval.ival) = 0; }
#line 1404 "parser.tab.c"
    break;

  case 18: /* BasicType: REAL  */
#line 115 "parser.y"
                          { (yyval.ival) = 1; }
#line 1410 "parser.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 122 "parser.y"
                                            { printVars((yyvsp[0].iden)); }
#line 1416 "parser.tab.c"
    break;

  case 22: /* SubProgDecl: SubProgHeading VarDecl $@5 CompoundStatement  */
#line 122 "parser.y"
                                                                                 { }
#line 1422 "parser.tab.c"
    break;

  case 23: /* $@6: %empty  */
#line 125 "parser.y"
                                         { pushStack(yylval.ival, s); }
#line 1428 "parser.tab.c"
    break;

  case 24: /* SubProgHeading: FUNCTION IDENTIFIER $@6 Parameters ':' BasicType ';'  */
#line 125 "parser.y"
                                                                                                     { 
                   funcSave = popStack(s);
                   printFunctionHeader(funcsave, (yyvsp[-3].iden), (yyvsp[-1].ival));
}
#line 1437 "parser.tab.c"
    break;

  case 25: /* $@7: %empty  */
#line 129 "parser.y"
                                          { pushStack(yylval.ival, s); }
#line 1443 "parser.tab.c"
    break;

  case 26: /* SubProgHeading: PROCEDURE IDENTIFIER $@7 PossibleParameters ';'  */
#line 129 "parser.y"
                                                                                                { 
                    funcSave = popStack(s);
                    printFunctionHeader(funcSave, (yyvsp[-1].iden), 2);
}
#line 1452 "parser.tab.c"
    break;

  case 27: /* PossibleParameters: Parameters  */
#line 135 "parser.y"
                                {(yyval.iden) = (yyvsp[0].iden);}
#line 1458 "parser.tab.c"
    break;

  case 28: /* PossibleParameters: %empty  */
#line 136 "parser.y"
                                   {(yyval.iden) = NULL;}
#line 1464 "parser.tab.c"
    break;

  case 29: /* Parameters: '(' ParameterList ')'  */
#line 139 "parser.y"
                                           {(yyval.iden) = (yyvsp[-1].iden);}
#line 1470 "parser.tab.c"
    break;

  case 30: /* ParameterList: ParamList  */
#line 142 "parser.y"
                               { (yyval.iden) = (yyvsp[0].iden); }
#line 1476 "parser.tab.c"
    break;

  case 31: /* ParameterList: ParameterList ';' ParamList  */
#line 143 "parser.y"
                                                 { appendToList((yyvsp[0].iden), (yyvsp[-2].iden)); (yyval.iden) = (yyvsp[0].iden); }
#line 1482 "parser.tab.c"
    break;

  case 32: /* ParamList: VAR IdentifierList ':' TypeSpec  */
#line 146 "parser.y"
                                                     { makeReference((yyvsp[-2].iden), 1); addType((yyvsp[-2].iden), (yyvsp[0].ival)); (yyval.iden) = (yyvsp[-2].iden); }
#line 1488 "parser.tab.c"
    break;

  case 33: /* ParamList: IdentifierList ':' TypeSpec  */
#line 147 "parser.y"
                                                 { makeReference((yyvsp[-2].iden), 0); addType((yyvsp[-2].iden), (yyvsp[0].ival)); (yyval.iden) = (yyvsp[-2].iden); }
#line 1494 "parser.tab.c"
    break;

  case 39: /* Statement: Lhs ASSIGN ArithExpr  */
#line 161 "parser.y"
                                          { printf("=_t%d;", (yyvsp[0].list)); }
#line 1500 "parser.tab.c"
    break;

  case 42: /* $@8: %empty  */
#line 164 "parser.y"
                              {
                    int label = printNextLabel();
                    printIfStmt((yyvsp[0].ival), label);
                    pushStack(label, labels);
                    incrementLabel();
                    incrementLabel();
}
#line 1512 "parser.tab.c"
    break;

  case 43: /* $@9: %empty  */
#line 171 "parser.y"
                                   {
                    int label = peepStack(labels);
                    label += 2;
                    printf("goto lb%d;\n", label);
                   }
#line 1522 "parser.tab.c"
    break;

  case 44: /* $@10: %empty  */
#line 175 "parser.y"
                           { printf("lb%s : ;", popStack(labels)); }
#line 1528 "parser.tab.c"
    break;

  case 45: /* Statement: IF Guard $@8 THEN Statement $@9 ELSE $@10 Statement  */
#line 175 "parser.y"
                                                                               { 
}
#line 1535 "parser.tab.c"
    break;

  case 46: /* $@11: %empty  */
#line 177 "parser.y"
                           {  
                    pushStack(printNextLabel(), labels); 
                   }
#line 1543 "parser.tab.c"
    break;

  case 47: /* Statement: WHILE $@11 Guard DO Statement  */
#line 179 "parser.y"
                                        {
                    printWhileCondition(popStack(labels), (yyvsp[-2].ival));
}
#line 1551 "parser.tab.c"
    break;

  case 48: /* Statement: READLN Parameters  */
#line 182 "parser.y"
                                       { 
                    readInput((yyvsp[0].iden)); 
}
#line 1559 "parser.tab.c"
    break;

  case 49: /* Statement: WRITELN '(' ArithExprList ')'  */
#line 185 "parser.y"
                                                   { 
                    printTokens((yyvsp[-1].list)); 
}
#line 1567 "parser.tab.c"
    break;

  case 51: /* Lhs: IDENTIFIER  */
#line 192 "parser.y"
                                { printIdentifier(yylval.ival); }
#line 1573 "parser.tab.c"
    break;

  case 52: /* $@12: %empty  */
#line 193 "parser.y"
                                { pushStack(yylval.ival); }
#line 1579 "parser.tab.c"
    break;

  case 53: /* Lhs: IDENTIFIER $@12 '[' ArithExpr ']'  */
#line 193 "parser.y"
                                                                              {
                    int idx = popStack(s);
                    printIdentifier(idx);
                    printf("[_t%d]", (yyvsp[-1].list));
}
#line 1589 "parser.tab.c"
    break;

  case 54: /* ProcedureCall: IDENTIFIER  */
#line 200 "parser.y"
                                { callFunc(yylval.ival, NULL); }
#line 1595 "parser.tab.c"
    break;

  case 55: /* $@13: %empty  */
#line 201 "parser.y"
                                { pushStack(yylval.ival, s); }
#line 1601 "parser.tab.c"
    break;

  case 56: /* ProcedureCall: IDENTIFIER $@13 '(' ArithExprList ')'  */
#line 201 "parser.y"
                                                                                     { callFunc(popStack(s), (yyvsp[-1].list)); }
#line 1607 "parser.tab.c"
    break;

  case 57: /* Guard: BoolAtom  */
#line 204 "parser.y"
                              { (yyval.ival) = printBool((yyvsp[0].ival)); (yyval.ival) = (yyvsp[0].ival); }
#line 1613 "parser.tab.c"
    break;

  case 58: /* Guard: NOT Guard  */
#line 205 "parser.y"
                               { (yyval.ival) = printGuard(-1, (yyvsp[0].ival), 0) }
#line 1619 "parser.tab.c"
    break;

  case 59: /* Guard: Guard OR Guard  */
#line 206 "parser.y"
                                    { (yyval.ival) = printGuard((yyvsp[-2].ival), (yyvsp[0].ival), 1); }
#line 1625 "parser.tab.c"
    break;

  case 60: /* Guard: Guard AND Guard  */
#line 207 "parser.y"
                                     { (yyval.ival) = printGuard((yyvsp[-2].ival), (yyvsp[0].ival), 2); }
#line 1631 "parser.tab.c"
    break;

  case 61: /* Guard: '(' Guard ')'  */
#line 208 "parser.y"
                                   { (yyval.ival) = (yyvsp[-1].ival); }
#line 1637 "parser.tab.c"
    break;

  case 62: /* BoolAtom: ArithExpr Relop ArithExpr  */
#line 211 "parser.y"
                                               { (yyval.ival) = printBool((yyvsp[-2].list), (yyvsp[0].list), (yyvsp[-1].ival)); }
#line 1643 "parser.tab.c"
    break;

  case 63: /* Relop: RELOPLT  */
#line 214 "parser.y"
                             { (yyval.ival) = 0; }
#line 1649 "parser.tab.c"
    break;

  case 64: /* Relop: RELOPLEQ  */
#line 215 "parser.y"
                              { (yyval.ival) = 1; }
#line 1655 "parser.tab.c"
    break;

  case 65: /* Relop: RELOPEQ  */
#line 216 "parser.y"
                             { (yyval.ival) = 2; }
#line 1661 "parser.tab.c"
    break;

  case 66: /* Relop: RELOPNEQ  */
#line 217 "parser.y"
                              { (yyval.ival) = 3; }
#line 1667 "parser.tab.c"
    break;

  case 67: /* Relop: RELOPGEQ  */
#line 218 "parser.y"
                              { (yyval.ival) = 4; }
#line 1673 "parser.tab.c"
    break;

  case 68: /* Relop: RELOPGT  */
#line 219 "parser.y"
                             { (yyval.ival) = 5; }
#line 1679 "parser.tab.c"
    break;

  case 69: /* ArithExprList: ArithExpr  */
#line 222 "parser.y"
                               { (yyval.list) = (-1); (yyval.list)->type = (yyvsp[0].list); (yyval.list)->next = NULL;  }
#line 1685 "parser.tab.c"
    break;

  case 70: /* ArithExprList: ArithExprList ',' ArithExpr  */
#line 223 "parser.y"
                                                 {
                    (yyval.list) = createNewNode(-1);
                    (yyval.list)->type = (yyvsp[0].list);
                    (yyval.list)->next = (yyvsp[-2].list);
}
#line 1695 "parser.tab.c"
    break;

  case 71: /* ArithExpr: IDENTIFIER  */
#line 230 "parser.y"
                                {
                   (yyval.list) = createArithNode()
                   (yyval.list) = getType(yylval.ival); 
}
#line 1704 "parser.tab.c"
    break;

  case 72: /* $@14: %empty  */
#line 234 "parser.y"
                                { pushStack(yylval.ival, s); }
#line 1710 "parser.tab.c"
    break;

  case 73: /* ArithExpr: IDENTIFIER $@14 '[' ArithExpr ']'  */
#line 234 "parser.y"
                                                                                {
                    (yyval.list) = getType(popStack(s));
        
}
#line 1719 "parser.tab.c"
    break;

  case 74: /* $@15: %empty  */
#line 238 "parser.y"
                                { pushStack(yylval.ival, s); }
#line 1725 "parser.tab.c"
    break;

  case 75: /* ArithExpr: IDENTIFIER $@15 '(' ArithExprList ')'  */
#line 238 "parser.y"
                                                                                     { 
                    funcSave = popStack(s);
                    (yyval.list) = getFuncType(funcSave);
                    checkFunction(funcSave, (yyvsp[-1].list)); 
                    
}
#line 1736 "parser.tab.c"
    break;

  case 76: /* ArithExpr: INTNUMBER  */
#line 244 "parser.y"
                               { printf("%d\n", yylval.ival); }
#line 1742 "parser.tab.c"
    break;

  case 77: /* ArithExpr: REALNUMBER  */
#line 245 "parser.y"
                                { printf("%lf\n", yylval.rval); }
#line 1748 "parser.tab.c"
    break;

  case 78: /* ArithExpr: ArithExpr '+' ArithExpr  */
#line 246 "parser.y"
                                             { (yyval.list) = max((yyvsp[-2].list), (yyvsp[0].list)); }
#line 1754 "parser.tab.c"
    break;

  case 79: /* ArithExpr: ArithExpr '-' ArithExpr  */
#line 247 "parser.y"
                                             { (yyval.list) = max((yyvsp[-2].list), (yyvsp[0].list)); }
#line 1760 "parser.tab.c"
    break;

  case 80: /* ArithExpr: ArithExpr '*' ArithExpr  */
#line 248 "parser.y"
                                             { (yyval.list) = max((yyvsp[-2].list), (yyvsp[0].list)); }
#line 1766 "parser.tab.c"
    break;

  case 81: /* ArithExpr: ArithExpr '/' ArithExpr  */
#line 249 "parser.y"
                                             { (yyval.list) = 1; }
#line 1772 "parser.tab.c"
    break;

  case 82: /* ArithExpr: ArithExpr DIV ArithExpr  */
#line 250 "parser.y"
                                             { (yyval.list) = 0, noReal((yyvsp[-2].list), (yyvsp[0].list));}
#line 1778 "parser.tab.c"
    break;

  case 83: /* ArithExpr: ArithExpr MOD ArithExpr  */
#line 251 "parser.y"
                                             { (yyval.list) = 0; noReal((yyvsp[-2].list), (yyvsp[0].list));}
#line 1784 "parser.tab.c"
    break;

  case 84: /* ArithExpr: '-' ArithExpr  */
#line 252 "parser.y"
                                   { (yyval.list) = (yyvsp[0].list); }
#line 1790 "parser.tab.c"
    break;

  case 85: /* ArithExpr: '(' ArithExpr ')'  */
#line 253 "parser.y"
                                       { (yyval.list) = (yyvsp[-1].list); }
#line 1796 "parser.tab.c"
    break;


#line 1800 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 256 "parser.y"


int max(int val1, int val2)
{
    return (val1 > val2 ? val1 : val2);
}

int countList(struct symbol *sym)
{
    int cnt = 0;
    struct symbol *temp = sym;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
}

void printList(struct symbol *symbol)
{
    struct symbol *temp = symbol;
    while (temp != NULL) {
        printf("id: %d\n", temp->id);
        temp = temp->next;
    }
}

void assignType(int type, struct symbol *sym)
{
    struct symbol *temp = sym;
    while (temp != NULL) {
        temp->varType = type;
        temp = temp->next;
    }
}

void printToken(int token) {
  /* single character tokens */
  if (token < 256) {
    if (token < 33) {
      /* non-printable character */
      printf("chr(%d)", token);
    } else {
      printf("'%c'", token);
    }
    return;
  }
  /* standard tokens (>255) */
  switch (token) {
  case PROGRAM   : printf("PROGRAM");
    break;
  case CONST     : printf("CONST");
    break;
  case IDENTIFIER: printf("identifier<%s>", yytext);
    break;
  case VAR       : printf("VAR");
    break;
  case ARRAY     : printf("ARRAY");
    break;
  case RANGE     : printf("..");
    break;
  case INTNUMBER : printf("Integer<%d>", yylval.ival);
    break;
  case REALNUMBER: printf("Real<%lf>", yylval.dval);
    break;
  case OF        : printf("OF");
    break;
  case INTEGER   : printf("INTEGER");
    break;
  case REAL      : printf("REAL");
    break;
  case FUNCTION  : printf("FUNCTION");
    break;
  case PROCEDURE : printf("PROCEDURE");
    break;
  case BEGINTOK  : printf("BEGIN");
    break;
  case ENDTOK    : printf("END");
    break;
  case ASSIGN    : printf(":=");
    break;
  case IF        : printf("IF");
    break;
  case THEN      : printf("THEN");
    break;
  case ELSE      : printf("ELSE");
    break;
  case WHILE     : printf("WHILE");
    break;
  case DO        : printf("DO");
    break;
  }
}

void yyerror (char *msg) {
  showErrorLine();
  fprintf (stderr, "%s (detected at token=", msg);
  printToken(yychar);
  printf(").\n");
  exit(EXIT_SUCCESS);  /* EXIT_SUCCESS because we use Themis */
}

int main(int argc, char *argv[]) {
  if (argc > 2) {
    fprintf(stderr, "Usage: %s [pasfile]\n", argv[0]);
    return EXIT_FAILURE;
  }
  initTables();
  s = newStack();
  
  FILE *f = stdin;
  if (argc == 2) {
    f = fopen(argv[1], "r");
    if (f == NULL) {
      fprintf(stderr, "Error: failed to open file\n");
      exit(EXIT_FAILURE);
    }
  }

  initLexer(f);
  yyparse();
  finalizeLexer();

#if 0
  showStringTable();
#endif
  printf("ACCEPTED\n");
  return EXIT_SUCCESS;
}
