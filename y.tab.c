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
#line 1 "meta3_parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

extern int yylex();
extern int token_line;
extern int token_column;
extern int print_tokens;
extern void free_string_buffer();
extern int yylex_destroy();
int lex_only = 0;

extern char yyerror_text[1024];
extern int  yyerror_line;
extern int  yyerror_column;

int print_ast_flag = 0;
int syntax_errors = 0;
ast_node *ast_root = NULL;

void yyerror(const char *s) {
    printf("Line %d, col %d: %s: %s\n",
           yyerror_line, yyerror_column, s, yyerror_text);
    syntax_errors++;
}

#line 101 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    NATURAL = 259,                 /* NATURAL  */
    DECIMAL = 260,                 /* DECIMAL  */
    STRLIT = 261,                  /* STRLIT  */
    BOOLLIT = 262,                 /* BOOLLIT  */
    RESERVED = 263,                /* RESERVED  */
    CLASS = 264,                   /* CLASS  */
    PUBLIC = 265,                  /* PUBLIC  */
    STATIC = 266,                  /* STATIC  */
    VOID = 267,                    /* VOID  */
    STRING = 268,                  /* STRING  */
    INT = 269,                     /* INT  */
    DOUBLE = 270,                  /* DOUBLE  */
    BOOL = 271,                    /* BOOL  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    WHILE = 274,                   /* WHILE  */
    RETURN = 275,                  /* RETURN  */
    PRINT = 276,                   /* PRINT  */
    PARSEINT = 277,                /* PARSEINT  */
    LBRACE = 278,                  /* LBRACE  */
    RBRACE = 279,                  /* RBRACE  */
    LPAR = 280,                    /* LPAR  */
    RPAR = 281,                    /* RPAR  */
    LSQ = 282,                     /* LSQ  */
    RSQ = 283,                     /* RSQ  */
    SEMICOLON = 284,               /* SEMICOLON  */
    COMMA = 285,                   /* COMMA  */
    ASSIGN = 286,                  /* ASSIGN  */
    ARROW = 287,                   /* ARROW  */
    DOTLENGTH = 288,               /* DOTLENGTH  */
    PLUS = 289,                    /* PLUS  */
    MINUS = 290,                   /* MINUS  */
    STAR = 291,                    /* STAR  */
    DIV = 292,                     /* DIV  */
    MOD = 293,                     /* MOD  */
    AND = 294,                     /* AND  */
    OR = 295,                      /* OR  */
    XOR = 296,                     /* XOR  */
    LSHIFT = 297,                  /* LSHIFT  */
    RSHIFT = 298,                  /* RSHIFT  */
    EQ = 299,                      /* EQ  */
    GE = 300,                      /* GE  */
    GT = 301,                      /* GT  */
    LE = 302,                      /* LE  */
    LT = 303,                      /* LT  */
    NE = 304,                      /* NE  */
    NOT = 305,                     /* NOT  */
    UPLUS = 306,                   /* UPLUS  */
    UMINUS = 307,                  /* UMINUS  */
    IFX = 308                      /* IFX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define NATURAL 259
#define DECIMAL 260
#define STRLIT 261
#define BOOLLIT 262
#define RESERVED 263
#define CLASS 264
#define PUBLIC 265
#define STATIC 266
#define VOID 267
#define STRING 268
#define INT 269
#define DOUBLE 270
#define BOOL 271
#define IF 272
#define ELSE 273
#define WHILE 274
#define RETURN 275
#define PRINT 276
#define PARSEINT 277
#define LBRACE 278
#define RBRACE 279
#define LPAR 280
#define RPAR 281
#define LSQ 282
#define RSQ 283
#define SEMICOLON 284
#define COMMA 285
#define ASSIGN 286
#define ARROW 287
#define DOTLENGTH 288
#define PLUS 289
#define MINUS 290
#define STAR 291
#define DIV 292
#define MOD 293
#define AND 294
#define OR 295
#define XOR 296
#define LSHIFT 297
#define RSHIFT 298
#define EQ 299
#define GE 300
#define GT 301
#define LE 302
#define LT 303
#define NE 304
#define NOT 305
#define UPLUS 306
#define UMINUS 307
#define IFX 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "meta3_parser.y"

    char *str;
    struct ast_node *node;

#line 265 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_NATURAL = 4,                    /* NATURAL  */
  YYSYMBOL_DECIMAL = 5,                    /* DECIMAL  */
  YYSYMBOL_STRLIT = 6,                     /* STRLIT  */
  YYSYMBOL_BOOLLIT = 7,                    /* BOOLLIT  */
  YYSYMBOL_RESERVED = 8,                   /* RESERVED  */
  YYSYMBOL_CLASS = 9,                      /* CLASS  */
  YYSYMBOL_PUBLIC = 10,                    /* PUBLIC  */
  YYSYMBOL_STATIC = 11,                    /* STATIC  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_DOUBLE = 15,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 16,                      /* BOOL  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_PRINT = 21,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 22,                  /* PARSEINT  */
  YYSYMBOL_LBRACE = 23,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 24,                    /* RBRACE  */
  YYSYMBOL_LPAR = 25,                      /* LPAR  */
  YYSYMBOL_RPAR = 26,                      /* RPAR  */
  YYSYMBOL_LSQ = 27,                       /* LSQ  */
  YYSYMBOL_RSQ = 28,                       /* RSQ  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_ARROW = 32,                     /* ARROW  */
  YYSYMBOL_DOTLENGTH = 33,                 /* DOTLENGTH  */
  YYSYMBOL_PLUS = 34,                      /* PLUS  */
  YYSYMBOL_MINUS = 35,                     /* MINUS  */
  YYSYMBOL_STAR = 36,                      /* STAR  */
  YYSYMBOL_DIV = 37,                       /* DIV  */
  YYSYMBOL_MOD = 38,                       /* MOD  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_OR = 40,                        /* OR  */
  YYSYMBOL_XOR = 41,                       /* XOR  */
  YYSYMBOL_LSHIFT = 42,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 43,                    /* RSHIFT  */
  YYSYMBOL_EQ = 44,                        /* EQ  */
  YYSYMBOL_GE = 45,                        /* GE  */
  YYSYMBOL_GT = 46,                        /* GT  */
  YYSYMBOL_LE = 47,                        /* LE  */
  YYSYMBOL_LT = 48,                        /* LT  */
  YYSYMBOL_NE = 49,                        /* NE  */
  YYSYMBOL_NOT = 50,                       /* NOT  */
  YYSYMBOL_UPLUS = 51,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 52,                    /* UMINUS  */
  YYSYMBOL_IFX = 53,                       /* IFX  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_Program = 55,                   /* Program  */
  YYSYMBOL_ProgramDeclList = 56,           /* ProgramDeclList  */
  YYSYMBOL_MethodDecl = 57,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 58,                 /* FieldDecl  */
  YYSYMBOL_FieldIDList = 59,               /* FieldIDList  */
  YYSYMBOL_Type = 60,                      /* Type  */
  YYSYMBOL_MethodHeader = 61,              /* MethodHeader  */
  YYSYMBOL_FormalParams = 62,              /* FormalParams  */
  YYSYMBOL_FormalParamsList = 63,          /* FormalParamsList  */
  YYSYMBOL_MethodBody = 64,                /* MethodBody  */
  YYSYMBOL_MethodBodyContent = 65,         /* MethodBodyContent  */
  YYSYMBOL_VarDecl = 66,                   /* VarDecl  */
  YYSYMBOL_VarIDList = 67,                 /* VarIDList  */
  YYSYMBOL_Statement = 68,                 /* Statement  */
  YYSYMBOL_StatementList = 69,             /* StatementList  */
  YYSYMBOL_MethodInvocation = 70,          /* MethodInvocation  */
  YYSYMBOL_ExprList = 71,                  /* ExprList  */
  YYSYMBOL_Assignment = 72,                /* Assignment  */
  YYSYMBOL_ParseArgs = 73,                 /* ParseArgs  */
  YYSYMBOL_Expr = 74,                      /* Expr  */
  YYSYMBOL_ExprNoAssign = 75               /* ExprNoAssign  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   343

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    71,    75,    79,    80,    83,    89,   112,
     115,   120,   123,   124,   125,   128,   136,   144,   150,   157,
     163,   169,   176,   179,   184,   188,   192,   195,   219,   224,
     227,   237,   243,   249,   254,   258,   261,   262,   263,   264,
     265,   269,   273,   276,   282,   285,   291,   295,   298,   302,
     305,   311,   316,   320,   320,   322,   326,   330,   334,   338,
     342,   346,   350,   354,   358,   362,   366,   370,   374,   378,
     382,   386,   390,   394,   398,   399,   400,   401,   405,   408,
     411,   414,   417
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "NATURAL", "DECIMAL", "STRLIT", "BOOLLIT", "RESERVED", "CLASS", "PUBLIC",
  "STATIC", "VOID", "STRING", "INT", "DOUBLE", "BOOL", "IF", "ELSE",
  "WHILE", "RETURN", "PRINT", "PARSEINT", "LBRACE", "RBRACE", "LPAR",
  "RPAR", "LSQ", "RSQ", "SEMICOLON", "COMMA", "ASSIGN", "ARROW",
  "DOTLENGTH", "PLUS", "MINUS", "STAR", "DIV", "MOD", "AND", "OR", "XOR",
  "LSHIFT", "RSHIFT", "EQ", "GE", "GT", "LE", "LT", "NE", "NOT", "UPLUS",
  "UMINUS", "IFX", "$accept", "Program", "ProgramDeclList", "MethodDecl",
  "FieldDecl", "FieldIDList", "Type", "MethodHeader", "FormalParams",
  "FormalParamsList", "MethodBody", "MethodBodyContent", "VarDecl",
  "VarIDList", "Statement", "StatementList", "MethodInvocation",
  "ExprList", "Assignment", "ParseArgs", "Expr", "ExprNoAssign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,    20,    33,    21,   -72,   -72,    11,    23,    43,   -72,
     -72,   -72,   -72,   -72,    94,    58,   -72,   -72,   -72,    62,
      47,    46,    64,   -72,   -72,    53,   147,   -23,    61,    59,
     -72,    84,    65,   -72,    66,   -72,   102,    68,   -11,    89,
      90,    91,    96,    97,   -72,   -72,   -72,   121,   -72,   -72,
     103,   110,   113,    95,   -72,   -72,   -72,   -72,   -72,    24,
     130,   130,   130,   -22,   -72,   -72,   -72,    38,   -72,   163,
     163,   163,   -72,   -72,   -72,   114,   231,   124,    29,   183,
     -72,   -72,   -72,   -72,   142,   117,   118,   -72,   -72,   -72,
     122,   125,   -72,   127,   128,   -20,   -72,   -72,   -72,   -72,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   131,   143,   145,   123,
     -72,   -72,    18,   -72,    22,   -72,    -4,   235,   235,   -72,
     -72,    81,    81,   -72,   -72,   -72,   263,   247,   279,   141,
     141,   295,   205,   205,   205,   205,   295,   152,   153,   -72,
     130,   -72,   169,   180,   -72,   130,   138,   -72,   -72,   -72,
     159,   -72,   -72,   -72,   235,   166,   -72,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     6,     0,     0,     0,     2,
       5,     3,     4,     9,     0,     0,    13,    14,    12,     0,
       0,     0,    11,    26,     7,     0,     0,     0,     0,     0,
      18,     0,     0,    17,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    23,    39,     0,    25,    24,
       0,     0,     0,     0,    22,    16,    15,    10,    42,     0,
       0,     0,     0,    78,    79,    80,    81,     0,    35,     0,
       0,     0,    75,    54,    76,     0,    53,     0,     0,     0,
      29,    36,    37,    38,     0,    19,     0,    46,    49,    50,
       0,     0,    77,     0,     0,    78,    73,    71,    72,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,    43,     0,    20,     0,    47,     0,     0,     0,    82,
      74,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,     0,    52,
       0,    27,     0,     0,    45,     0,    31,    33,    41,    40,
       0,    28,    21,    48,     0,     0,    32,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   -72,   -72,   -72,   -13,   -72,   167,   -72,
     -72,   -72,   -72,   -72,   -71,   -72,   -28,   -72,   -26,   -24,
     -43,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,    11,    12,    27,    31,    20,    32,    85,
      24,    28,    48,   122,    49,    79,    72,   126,    73,    74,
      75,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    19,    51,    59,    52,    59,    35,    36,   121,    60,
       1,    92,     7,    92,    59,    47,    88,    89,    90,    91,
      60,     8,   154,     3,    94,    86,   155,    63,    64,    65,
     118,    66,   119,     4,   117,     9,    16,    17,    18,    93,
      10,    63,    64,    65,     5,    66,    43,   151,   152,    67,
      87,    50,    13,    51,    14,    52,   156,   157,    69,    70,
      43,    21,    37,    67,    38,    22,    29,    16,    17,    18,
      23,    25,    69,    70,    71,    16,    17,    18,    39,    30,
      40,    41,    42,    43,    44,    45,    53,    54,    71,    26,
      46,    55,    56,   166,    63,    64,    65,    58,    66,    50,
      50,    51,    51,    52,    52,    57,    15,   160,    16,    17,
      18,   153,   163,    43,    61,    62,    67,   102,   103,   104,
      68,    77,    78,    84,    80,    69,    70,    63,    64,    65,
     116,    66,    81,    63,    64,    65,    50,    66,    51,    82,
      52,    71,    83,    99,   125,   123,    43,   124,   127,    67,
     150,   128,    43,   129,   130,    67,   164,   147,    69,    70,
      29,    16,    17,    18,    69,    70,    95,    64,    65,   148,
      66,   149,   161,    33,    71,   100,   101,   102,   103,   104,
      71,   158,   159,   162,    37,    43,    38,   165,    67,    96,
      97,    98,   167,    34,     0,     0,     0,    69,    70,     0,
      39,     0,    40,    41,    42,    43,    44,   120,     0,     0,
       0,     0,    46,    71,     0,     0,     0,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    37,     0,    38,   100,
     101,   102,   103,   104,     0,     0,     0,   108,   109,     0,
       0,     0,    39,     0,    40,    41,    42,    43,    44,     0,
       0,     0,     0,     0,    46,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   100,   101,   102,   103,   104,   105,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   100,   101,   102,
     103,   104,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   100,   101,   102,   103,   104,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   100,
     101,   102,   103,   104,     0,     0,     0,   108,   109,     0,
     111,   112,   113,   114
};

static const yytype_int16 yycheck[] =
{
      28,    14,    28,    25,    28,    25,    29,    30,    79,    31,
       9,    33,     1,    33,    25,    28,    59,    60,    61,    62,
      31,    10,    26,     3,    67,     1,    30,     3,     4,     5,
       1,     7,     3,     0,    77,    24,    14,    15,    16,     1,
      29,     3,     4,     5,    23,     7,    22,    29,    30,    25,
      26,    79,    29,    79,    11,    79,   127,   128,    34,    35,
      22,     3,     1,    25,     3,     3,    13,    14,    15,    16,
      23,    25,    34,    35,    50,    14,    15,    16,    17,    26,
      19,    20,    21,    22,    23,    24,    27,     3,    50,    25,
      29,    26,    26,   164,     3,     4,     5,    29,     7,   127,
     128,   127,   128,   127,   128,     3,    12,   150,    14,    15,
      16,   124,   155,    22,    25,    25,    25,    36,    37,    38,
      29,    25,    25,    28,     3,    34,    35,     3,     4,     5,
       6,     7,    29,     3,     4,     5,   164,     7,   164,    29,
     164,    50,    29,    29,    26,     3,    22,    30,    26,    25,
      27,    26,    22,    26,    26,    25,    18,    26,    34,    35,
      13,    14,    15,    16,    34,    35,     3,     4,     5,    26,
       7,    26,     3,    26,    50,    34,    35,    36,    37,    38,
      50,    29,    29,     3,     1,    22,     3,    28,    25,    69,
      70,    71,    26,    26,    -1,    -1,    -1,    34,    35,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    50,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     1,    -1,     3,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    17,    -1,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    29,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    34,    35,    36,
      37,    38,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    43,    -1,
      45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    55,     3,     0,    23,    56,     1,    10,    24,
      29,    57,    58,    29,    11,    12,    14,    15,    16,    60,
      61,     3,     3,    23,    64,    25,    25,    59,    65,    13,
      26,    60,    62,    26,    62,    29,    30,     1,     3,    17,
      19,    20,    21,    22,    23,    24,    29,    60,    66,    68,
      70,    72,    73,    27,     3,    26,    26,     3,    29,    25,
      31,    25,    25,     3,     4,     5,     7,    25,    29,    34,
      35,    50,    70,    72,    73,    74,    75,    25,    25,    69,
       3,    29,    29,    29,    28,    63,     1,    26,    74,    74,
      74,    74,    33,     1,    74,     3,    75,    75,    75,    29,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     6,    74,     1,     3,
      24,    68,    67,     3,    30,    26,    71,    26,    26,    26,
      26,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    26,    26,    26,
      27,    29,    30,    60,    26,    30,    68,    68,    29,    29,
      74,     3,     3,    74,    18,    28,    68,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    57,    58,    58,
      59,    59,    60,    60,    60,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    65,    65,    65,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    70,    71,    71,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     4,     4,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     0,
       3,     5,     7,     5,     3,     2,     2,     2,     2,     1,
       5,     5,     2,     2,     0,     5,     3,     4,     3,     0,
       3,     7,     4,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     1,     1,     2,     1,     1,
       1,     1,     3
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: CLASS IDENTIFIER LBRACE ProgramDeclList RBRACE  */
#line 63 "meta3_parser.y"
                                                        {
    (yyval.node) = create_node(Program, NULL, (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    ast_node *id = create_node(Identifier, (yyvsp[-3].str), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    add_child((yyval.node), id);
    if ((yyvsp[-1].node) != NULL) { add_child((yyval.node), (yyvsp[-1].node)); }
    ast_root = (yyval.node);
}
#line 1600 "y.tab.c"
    break;

  case 3: /* ProgramDeclList: ProgramDeclList MethodDecl  */
#line 71 "meta3_parser.y"
                                            {
    if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
    else { add_sibling((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
}
#line 1609 "y.tab.c"
    break;

  case 4: /* ProgramDeclList: ProgramDeclList FieldDecl  */
#line 75 "meta3_parser.y"
                            {
    if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
    else { add_sibling((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
}
#line 1618 "y.tab.c"
    break;

  case 5: /* ProgramDeclList: ProgramDeclList SEMICOLON  */
#line 79 "meta3_parser.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1624 "y.tab.c"
    break;

  case 6: /* ProgramDeclList: %empty  */
#line 80 "meta3_parser.y"
              { (yyval.node) = NULL; }
#line 1630 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 83 "meta3_parser.y"
                                                  {
    (yyval.node) = create_node(MethodDecl, NULL, (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    add_child((yyval.node), (yyvsp[-1].node));
    add_child((yyval.node), (yyvsp[0].node));
}
#line 1640 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type IDENTIFIER FieldIDList SEMICOLON  */
#line 89 "meta3_parser.y"
                                                               {
    (yyval.node) = create_node(FieldDecl, NULL, (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    ast_node *t1 = create_node((yyvsp[-3].node)->category, NULL, (yyvsp[-3].node)->line, (yyvsp[-3].node)->column);
    add_child((yyval.node), t1);
    add_child((yyval.node), create_node(Identifier, (yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column));

    ast_node *curr = (yyval.node);
    ast_node *list = (yyvsp[-1].node);
    while(list != NULL) {
        ast_node *fdecl = create_node(FieldDecl, NULL, (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        ast_node *tcopy = create_node((yyvsp[-3].node)->category, NULL, (yyvsp[-3].node)->line, (yyvsp[-3].node)->column);
        add_child(fdecl, tcopy);
        add_child(fdecl, create_node(Identifier, list->value, list->line, list->column));
        add_sibling(curr, fdecl);
        curr = fdecl;

        ast_node *next = list->sibling;
        free(list->value);
        free(list);
        list = next;
    }
    free_ast((yyvsp[-3].node));
}
#line 1668 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 112 "meta3_parser.y"
                  { (yyval.node) = NULL; }
#line 1674 "y.tab.c"
    break;

  case 10: /* FieldIDList: FieldIDList COMMA IDENTIFIER  */
#line 115 "meta3_parser.y"
                                          {
    ast_node *tmp = create_node(NullCategory, (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    if ((yyvsp[-2].node) == NULL) (yyval.node) = tmp;
    else { add_sibling((yyvsp[-2].node), tmp); (yyval.node) = (yyvsp[-2].node); }
}
#line 1684 "y.tab.c"
    break;

  case 11: /* FieldIDList: %empty  */
#line 120 "meta3_parser.y"
              { (yyval.node) = NULL; }
#line 1690 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 123 "meta3_parser.y"
              { (yyval.node) = create_node(Bool, NULL, (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1696 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 124 "meta3_parser.y"
              { (yyval.node) = create_node(Int, NULL, (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1702 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 125 "meta3_parser.y"
              { (yyval.node) = create_node(Double, NULL, (yylsp[0]).first_line, (yylsp[0]).first_column); }
#line 1708 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type IDENTIFIER LPAR FormalParams RPAR  */
#line 128 "meta3_parser.y"
                                                     {
    (yyval.node) = create_node(MethodHeader, NULL, (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    add_child((yyval.node), (yyvsp[-4].node));
    add_child((yyval.node), create_node(Identifier, (yyvsp[-3].str), (yylsp[-3]).first_line, (yylsp[-3]).first_column));
    ast_node *mp = create_node(MethodParams, NULL, (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    if ((yyvsp[-1].node)) add_child(mp, (yyvsp[-1].node));
    add_child((yyval.node), mp);
}
#line 1721 "y.tab.c"
    break;

  case 16: /* MethodHeader: VOID IDENTIFIER LPAR FormalParams RPAR  */
#line 136 "meta3_parser.y"
                                         {
    (yyval.node) = create_node(MethodHeader, NULL, (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    add_child((yyval.node), create_node(Void, NULL, (yylsp[-4]).first_line, (yylsp[-4]).first_column));
    add_child((yyval.node), create_node(Identifier, (yyvsp[-3].str), (yylsp[-3]).first_line, (yylsp[-3]).first_column));
    ast_node *mp = create_node(MethodParams, NULL, (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    if ((yyvsp[-1].node)) add_child(mp, (yyvsp[-1].node));
    add_child((yyval.node), mp);
}
#line 1734 "y.tab.c"
    break;

  case 17: /* MethodHeader: Type IDENTIFIER LPAR RPAR  */
#line 144 "meta3_parser.y"
                            {
    (yyval.node) = create_node(MethodHeader, NULL, (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    add_child((yyval.node), (yyvsp[-3].node));
    add_child((yyval.node), create_node(Identifier, (yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column));
    add_child((yyval.node), create_node(MethodParams, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column));
}
#line 1745 "y.tab.c"
    break;

  case 18: /* MethodHeader: VOID IDENTIFIER LPAR RPAR  */
#line 150 "meta3_parser.y"
                            {
    (yyval.node) = create_node(MethodHeader, NULL, (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    add_child((yyval.node), create_node(Void, NULL, (yylsp[-3]).first_line, (yylsp[-3]).first_column));
    add_child((yyval.node), create_node(Identifier, (yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column));
    add_child((yyval.node), create_node(MethodParams, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column));
}
#line 1756 "y.tab.c"
    break;

  case 19: /* FormalParams: Type IDENTIFIER FormalParamsList  */
#line 157 "meta3_parser.y"
                                               {
    (yyval.node) = create_node(ParamDecl, NULL, (yyvsp[-2].node)->line, (yyvsp[-2].node)->column);
    add_child((yyval.node), (yyvsp[-2].node));
    add_child((yyval.node), create_node(Identifier, (yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column));
    if ((yyvsp[0].node) != NULL) add_sibling((yyval.node), (yyvsp[0].node));
}
#line 1767 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ IDENTIFIER  */
#line 163 "meta3_parser.y"
                            {
    (yyval.node) = create_node(ParamDecl, NULL, (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    add_child((yyval.node), create_node(StringArray, NULL, (yylsp[-3]).first_line, (yylsp[-3]).first_column));
    add_child((yyval.node), create_node(Identifier, (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column));
}
#line 1777 "y.tab.c"
    break;

  case 21: /* FormalParamsList: FormalParamsList COMMA Type IDENTIFIER  */
#line 169 "meta3_parser.y"
                                                         {
    ast_node *p = create_node(ParamDecl, NULL, (yyvsp[-1].node)->line, (yyvsp[-1].node)->column);
    add_child(p, (yyvsp[-1].node));
    add_child(p, create_node(Identifier, (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column));
    if ((yyvsp[-3].node) == NULL) (yyval.node) = p;
    else { add_sibling((yyvsp[-3].node), p); (yyval.node) = (yyvsp[-3].node); }
}
#line 1789 "y.tab.c"
    break;

  case 22: /* FormalParamsList: %empty  */
#line 176 "meta3_parser.y"
              { (yyval.node) = NULL; }
#line 1795 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE MethodBodyContent RBRACE  */
#line 179 "meta3_parser.y"
                                            {
    (yyval.node) = create_node(MethodBody, NULL, (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
}
#line 1804 "y.tab.c"
    break;

  case 24: /* MethodBodyContent: MethodBodyContent Statement  */
#line 184 "meta3_parser.y"
                                               {
    if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
    else { add_sibling((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
}
#line 1813 "y.tab.c"
    break;

  case 25: /* MethodBodyContent: MethodBodyContent VarDecl  */
#line 188 "meta3_parser.y"
                            {
    if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
    else { add_sibling((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
}
#line 1822 "y.tab.c"
    break;

  case 26: /* MethodBodyContent: %empty  */
#line 192 "meta3_parser.y"
              { (yyval.node) = NULL; }
#line 1828 "y.tab.c"
    break;

  case 27: /* VarDecl: Type IDENTIFIER VarIDList SEMICOLON  */
#line 195 "meta3_parser.y"
                                             {
    (yyval.node) = create_node(VarDecl, NULL, (yyvsp[-3].node)->line, (yyvsp[-3].node)->column);
    ast_node *t1 = create_node((yyvsp[-3].node)->category, NULL, (yyvsp[-3].node)->line, (yyvsp[-3].node)->column);
    add_child((yyval.node), t1);
    add_child((yyval.node), create_node(Identifier, (yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column));

    ast_node *curr = (yyval.node);
    ast_node *list = (yyvsp[-1].node);
    while(list != NULL) {
        ast_node *vdecl = create_node(VarDecl, NULL, (yyvsp[-3].node)->line, (yyvsp[-3].node)->column);
        ast_node *tcopy = create_node((yyvsp[-3].node)->category, NULL, (yyvsp[-3].node)->line, (yyvsp[-3].node)->column);
        add_child(vdecl, tcopy);
        add_child(vdecl, create_node(Identifier, list->value, list->line, list->column));
        add_sibling(curr, vdecl);
        curr = vdecl;

        ast_node *next = list->sibling;
        free(list->value);
        free(list);
        list = next;
    }
    free_ast((yyvsp[-3].node));
}
#line 1856 "y.tab.c"
    break;

  case 28: /* VarIDList: VarIDList COMMA IDENTIFIER  */
#line 219 "meta3_parser.y"
                                      {
    ast_node *tmp = create_node(NullCategory, (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    if ((yyvsp[-2].node) == NULL) (yyval.node) = tmp;
    else { add_sibling((yyvsp[-2].node), tmp); (yyval.node) = (yyvsp[-2].node); }
}
#line 1866 "y.tab.c"
    break;

  case 29: /* VarIDList: %empty  */
#line 224 "meta3_parser.y"
              { (yyval.node) = NULL; }
#line 1872 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE StatementList RBRACE  */
#line 227 "meta3_parser.y"
                                       {
    if ((yyvsp[-1].node) == NULL) {
        (yyval.node) = NULL;
    } else if ((yyvsp[-1].node)->sibling == NULL) {
        (yyval.node) = (yyvsp[-1].node);
    } else {
        (yyval.node) = create_node(Block, NULL, (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        add_child((yyval.node), (yyvsp[-1].node));
    }
}
#line 1887 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement  */
#line 237 "meta3_parser.y"
                                        {
    (yyval.node) = create_node(If, NULL, (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    add_child((yyval.node), (yyvsp[-2].node));
    add_child((yyval.node), (yyvsp[0].node) ? (yyvsp[0].node) : create_node(Block, NULL, 0, 0));
    add_child((yyval.node), create_node(Block, NULL, 0, 0)); // Ghost empty else Block
}
#line 1898 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 243 "meta3_parser.y"
                                             {
    (yyval.node) = create_node(If, NULL, (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    add_child((yyval.node), (yyvsp[-4].node));
    add_child((yyval.node), (yyvsp[-2].node) ? (yyvsp[-2].node) : create_node(Block, NULL, 0, 0));
    add_child((yyval.node), (yyvsp[0].node) ? (yyvsp[0].node) : create_node(Block, NULL, 0, 0));
}
#line 1909 "y.tab.c"
    break;

  case 33: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 249 "meta3_parser.y"
                                 {
    (yyval.node) = create_node(While, NULL, (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    add_child((yyval.node), (yyvsp[-2].node));
    add_child((yyval.node), (yyvsp[0].node) ? (yyvsp[0].node) : create_node(Block, NULL, 0, 0));
}
#line 1919 "y.tab.c"
    break;

  case 34: /* Statement: RETURN Expr SEMICOLON  */
#line 254 "meta3_parser.y"
                        {
    (yyval.node) = create_node(Return, NULL, (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    add_child((yyval.node), (yyvsp[-1].node));
}
#line 1928 "y.tab.c"
    break;

  case 35: /* Statement: RETURN SEMICOLON  */
#line 258 "meta3_parser.y"
                   {
    (yyval.node) = create_node(Return, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
}
#line 1936 "y.tab.c"
    break;

  case 36: /* Statement: MethodInvocation SEMICOLON  */
#line 261 "meta3_parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 1942 "y.tab.c"
    break;

  case 37: /* Statement: Assignment SEMICOLON  */
#line 262 "meta3_parser.y"
                       { (yyval.node) = (yyvsp[-1].node); }
#line 1948 "y.tab.c"
    break;

  case 38: /* Statement: ParseArgs SEMICOLON  */
#line 263 "meta3_parser.y"
                      { (yyval.node) = (yyvsp[-1].node); }
#line 1954 "y.tab.c"
    break;

  case 39: /* Statement: SEMICOLON  */
#line 264 "meta3_parser.y"
            { (yyval.node) = NULL; }
#line 1960 "y.tab.c"
    break;

  case 40: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 265 "meta3_parser.y"
                                 {
    (yyval.node) = create_node(Print, NULL, (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    add_child((yyval.node), (yyvsp[-2].node));
}
#line 1969 "y.tab.c"
    break;

  case 41: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 269 "meta3_parser.y"
                                   {
    (yyval.node) = create_node(Print, NULL, (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    add_child((yyval.node), create_node(StrLit, (yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column));
}
#line 1978 "y.tab.c"
    break;

  case 42: /* Statement: error SEMICOLON  */
#line 273 "meta3_parser.y"
                  { (yyval.node) = NULL; }
#line 1984 "y.tab.c"
    break;

  case 43: /* StatementList: StatementList Statement  */
#line 276 "meta3_parser.y"
                                       {
    if ((yyvsp[0].node) != NULL) {
        if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
        else { add_sibling((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
    } else { (yyval.node) = (yyvsp[-1].node); }
}
#line 1995 "y.tab.c"
    break;

  case 44: /* StatementList: %empty  */
#line 282 "meta3_parser.y"
              { (yyval.node) = NULL; }
#line 2001 "y.tab.c"
    break;

  case 45: /* MethodInvocation: IDENTIFIER LPAR Expr ExprList RPAR  */
#line 285 "meta3_parser.y"
                                                     {
    (yyval.node) = create_node(Call, NULL, (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    add_child((yyval.node), create_node(Identifier, (yyvsp[-4].str), (yylsp[-4]).first_line, (yylsp[-4]).first_column));
    add_child((yyval.node), (yyvsp[-2].node));
    if ((yyvsp[-1].node)) add_sibling((yyvsp[-2].node), (yyvsp[-1].node));
}
#line 2012 "y.tab.c"
    break;

  case 46: /* MethodInvocation: IDENTIFIER LPAR RPAR  */
#line 291 "meta3_parser.y"
                       {
    (yyval.node) = create_node(Call, NULL, (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    add_child((yyval.node), create_node(Identifier, (yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column));
}
#line 2021 "y.tab.c"
    break;

  case 47: /* MethodInvocation: IDENTIFIER LPAR error RPAR  */
#line 295 "meta3_parser.y"
                             { (yyval.node) = NULL; }
#line 2027 "y.tab.c"
    break;

  case 48: /* ExprList: ExprList COMMA Expr  */
#line 298 "meta3_parser.y"
                              {
    if ((yyvsp[-2].node) == NULL) (yyval.node) = (yyvsp[0].node);
    else { add_sibling((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-2].node); }
}
#line 2036 "y.tab.c"
    break;

  case 49: /* ExprList: %empty  */
#line 302 "meta3_parser.y"
              { (yyval.node) = NULL; }
#line 2042 "y.tab.c"
    break;

  case 50: /* Assignment: IDENTIFIER ASSIGN Expr  */
#line 305 "meta3_parser.y"
                                   {
    (yyval.node) = create_node(Assign, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), create_node(Identifier, (yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column));
    add_child((yyval.node), (yyvsp[0].node));
}
#line 2052 "y.tab.c"
    break;

  case 51: /* ParseArgs: PARSEINT LPAR IDENTIFIER LSQ Expr RSQ RPAR  */
#line 311 "meta3_parser.y"
                                                      {
    (yyval.node) = create_node(ParseArgs, NULL, (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    add_child((yyval.node), create_node(Identifier, (yyvsp[-4].str), (yylsp[-4]).first_line, (yylsp[-4]).first_column));
    add_child((yyval.node), (yyvsp[-2].node));
}
#line 2062 "y.tab.c"
    break;

  case 52: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 316 "meta3_parser.y"
                           { (yyval.node) = NULL; }
#line 2068 "y.tab.c"
    break;

  case 53: /* Expr: ExprNoAssign  */
#line 320 "meta3_parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 2074 "y.tab.c"
    break;

  case 54: /* Expr: Assignment  */
#line 320 "meta3_parser.y"
                                             { (yyval.node) = (yyvsp[0].node); }
#line 2080 "y.tab.c"
    break;

  case 55: /* ExprNoAssign: ExprNoAssign PLUS ExprNoAssign  */
#line 322 "meta3_parser.y"
                                               {
    (yyval.node) = create_node(Add, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2089 "y.tab.c"
    break;

  case 56: /* ExprNoAssign: ExprNoAssign MINUS ExprNoAssign  */
#line 326 "meta3_parser.y"
                                  {
    (yyval.node) = create_node(Sub, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2098 "y.tab.c"
    break;

  case 57: /* ExprNoAssign: ExprNoAssign STAR ExprNoAssign  */
#line 330 "meta3_parser.y"
                                 {
    (yyval.node) = create_node(Mul, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2107 "y.tab.c"
    break;

  case 58: /* ExprNoAssign: ExprNoAssign DIV ExprNoAssign  */
#line 334 "meta3_parser.y"
                                {
    (yyval.node) = create_node(Div, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2116 "y.tab.c"
    break;

  case 59: /* ExprNoAssign: ExprNoAssign MOD ExprNoAssign  */
#line 338 "meta3_parser.y"
                                {
    (yyval.node) = create_node(Mod, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2125 "y.tab.c"
    break;

  case 60: /* ExprNoAssign: ExprNoAssign AND ExprNoAssign  */
#line 342 "meta3_parser.y"
                                {
    (yyval.node) = create_node(And, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2134 "y.tab.c"
    break;

  case 61: /* ExprNoAssign: ExprNoAssign OR ExprNoAssign  */
#line 346 "meta3_parser.y"
                               {
    (yyval.node) = create_node(Or, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2143 "y.tab.c"
    break;

  case 62: /* ExprNoAssign: ExprNoAssign XOR ExprNoAssign  */
#line 350 "meta3_parser.y"
                                {
    (yyval.node) = create_node(Xor, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2152 "y.tab.c"
    break;

  case 63: /* ExprNoAssign: ExprNoAssign LSHIFT ExprNoAssign  */
#line 354 "meta3_parser.y"
                                   {
    (yyval.node) = create_node(Lshift, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2161 "y.tab.c"
    break;

  case 64: /* ExprNoAssign: ExprNoAssign RSHIFT ExprNoAssign  */
#line 358 "meta3_parser.y"
                                   {
    (yyval.node) = create_node(Rshift, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2170 "y.tab.c"
    break;

  case 65: /* ExprNoAssign: ExprNoAssign EQ ExprNoAssign  */
#line 362 "meta3_parser.y"
                               {
    (yyval.node) = create_node(Eq, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2179 "y.tab.c"
    break;

  case 66: /* ExprNoAssign: ExprNoAssign GE ExprNoAssign  */
#line 366 "meta3_parser.y"
                               {
    (yyval.node) = create_node(Ge, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2188 "y.tab.c"
    break;

  case 67: /* ExprNoAssign: ExprNoAssign GT ExprNoAssign  */
#line 370 "meta3_parser.y"
                               {
    (yyval.node) = create_node(Gt, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2197 "y.tab.c"
    break;

  case 68: /* ExprNoAssign: ExprNoAssign LE ExprNoAssign  */
#line 374 "meta3_parser.y"
                               {
    (yyval.node) = create_node(Le, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2206 "y.tab.c"
    break;

  case 69: /* ExprNoAssign: ExprNoAssign LT ExprNoAssign  */
#line 378 "meta3_parser.y"
                               {
    (yyval.node) = create_node(Lt, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2215 "y.tab.c"
    break;

  case 70: /* ExprNoAssign: ExprNoAssign NE ExprNoAssign  */
#line 382 "meta3_parser.y"
                               {
    (yyval.node) = create_node(Ne, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node));
}
#line 2224 "y.tab.c"
    break;

  case 71: /* ExprNoAssign: MINUS ExprNoAssign  */
#line 386 "meta3_parser.y"
                                  {
    (yyval.node) = create_node(Minus, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[0].node));
}
#line 2233 "y.tab.c"
    break;

  case 72: /* ExprNoAssign: NOT ExprNoAssign  */
#line 390 "meta3_parser.y"
                   {
    (yyval.node) = create_node(Not, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[0].node));
}
#line 2242 "y.tab.c"
    break;

  case 73: /* ExprNoAssign: PLUS ExprNoAssign  */
#line 394 "meta3_parser.y"
                                {
    (yyval.node) = create_node(Plus, NULL, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    add_child((yyval.node), (yyvsp[0].node));
}
#line 2251 "y.tab.c"
    break;

  case 74: /* ExprNoAssign: LPAR Expr RPAR  */
#line 398 "meta3_parser.y"
                 { (yyval.node) = (yyvsp[-1].node); }
#line 2257 "y.tab.c"
    break;

  case 75: /* ExprNoAssign: MethodInvocation  */
#line 399 "meta3_parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 2263 "y.tab.c"
    break;

  case 76: /* ExprNoAssign: ParseArgs  */
#line 400 "meta3_parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 2269 "y.tab.c"
    break;

  case 77: /* ExprNoAssign: IDENTIFIER DOTLENGTH  */
#line 401 "meta3_parser.y"
                       {
    (yyval.node) = create_node(Length, NULL, (yylsp[0]).first_line, (yylsp[0]).first_column);
    add_child((yyval.node), create_node(Identifier, (yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column));
}
#line 2278 "y.tab.c"
    break;

  case 78: /* ExprNoAssign: IDENTIFIER  */
#line 405 "meta3_parser.y"
             {
    (yyval.node) = create_node(Identifier, (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
}
#line 2286 "y.tab.c"
    break;

  case 79: /* ExprNoAssign: NATURAL  */
#line 408 "meta3_parser.y"
          {
    (yyval.node) = create_node(Natural, (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
}
#line 2294 "y.tab.c"
    break;

  case 80: /* ExprNoAssign: DECIMAL  */
#line 411 "meta3_parser.y"
          {
    (yyval.node) = create_node(Decimal, (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
}
#line 2302 "y.tab.c"
    break;

  case 81: /* ExprNoAssign: BOOLLIT  */
#line 414 "meta3_parser.y"
          {
    (yyval.node) = create_node(BoolLit, (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
}
#line 2310 "y.tab.c"
    break;

  case 82: /* ExprNoAssign: LPAR error RPAR  */
#line 417 "meta3_parser.y"
                  { (yyval.node) = NULL; }
#line 2316 "y.tab.c"
    break;


#line 2320 "y.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 420 "meta3_parser.y"


int main(int argc, char **argv) {
    int do_semantics = 0;
    if (argc > 1) {
        if (strcmp(argv[1], "-l") == 0) {
            print_tokens = 1; lex_only = 1;
        } else if (strcmp(argv[1], "-e1") == 0) {
            lex_only = 1;
        } else if (strcmp(argv[1], "-t") == 0) {
            print_ast_flag = 1;
        } else if (strcmp(argv[1], "-s") == 0) {
            print_ast_flag = 1;
            do_semantics = 1;
        }
    }

    if (lex_only) {
        while (yylex() != 0);
    } else {
        yyparse();
        if (syntax_errors == 0 && do_semantics && ast_root != NULL) {
            build_tables(ast_root);
            check_types(ast_root);
            print_tables();
            print_ast_annotated(ast_root, 0);
        } else if (print_ast_flag && syntax_errors == 0 && ast_root != NULL) {
            print_ast(ast_root, 0);
        }
    }

    if (ast_root != NULL) { free_ast(ast_root); }
    free_string_buffer();
    yylex_destroy();
    return 0;
}
