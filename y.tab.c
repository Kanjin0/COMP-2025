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
#line 1 "meta2_parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

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

// Um dos erros que está a dar é como o do lexer, onde a coluna do erro está incrementada até ao final
// de onde o erro acaba e não onde ele começa

// Para além disso, não está a incluir o campo da string que originou o erro (yytext, i mean)
// pode estar a consumí-lo antes de o poder imprimir, fazendo com que não haja nada

void yyerror(const char *s) {
    printf("Line %d, col %d: %s: %s\n", 
           yyerror_line, yyerror_column, s, yyerror_text);
    syntax_errors++;
}

#line 106 "y.tab.c"

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
#line 36 "meta2_parser.y"

    char *str;
    struct ast_node *node;

#line 270 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


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
  YYSYMBOL_Expr = 74                       /* Expr  */
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
#define YYLAST   420

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

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
       0,    67,    67,    74,    78,    82,    83,    86,    92,   115,
     118,   123,   126,   127,   128,   131,   139,   147,   153,   160,
     166,   172,   179,   182,   187,   191,   195,   198,   222,   227,
     230,   242,   248,   254,   259,   263,   266,   267,   268,   269,
     270,   274,   278,   281,   287,   290,   296,   300,   303,   307,
     310,   316,   321,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352
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
  "ExprList", "Assignment", "ParseArgs", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,     0,    22,     2,   -50,   -50,   131,     9,    34,   -50,
     -50,   -50,   -50,   -50,   152,    50,   -50,   -50,   -50,    80,
      64,    70,    79,   -50,   -50,    -6,    65,   113,    20,    62,
     -50,   105,    86,   -50,    91,   -50,   118,    96,   -19,   108,
     110,   115,   126,   137,   -50,   -50,   -50,   160,   -50,   -50,
     140,   147,   156,   166,   -50,   -50,   -50,   -50,   -50,    81,
     149,   149,   149,   -20,   -50,   -50,   -50,    89,   -50,   149,
     149,   149,   -50,   -50,   -50,   282,   123,    45,   158,   -50,
     -50,   -50,   -50,   197,   188,   193,   -50,   298,   298,   167,
     191,   -50,   194,   215,   -50,   -50,   -50,   -50,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   195,   239,   196,   216,   -50,   -50,
     117,   -50,    16,   -50,    21,   169,   169,   -50,   -50,   159,
     159,   -50,   -50,   -50,   330,   314,   346,    37,    37,   362,
     377,   377,   377,   377,   362,   213,   217,   -50,   149,   -50,
     220,   221,   -50,   149,   226,   -50,   -50,   -50,   261,   -50,
     -50,   298,   169,   219,   -50,   -50
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
       0,     0,     0,    77,    78,    79,    80,     0,    35,     0,
       0,     0,    73,    74,    75,     0,     0,     0,     0,    29,
      36,    37,    38,     0,    19,     0,    46,    49,    50,     0,
       0,    76,     0,     0,    71,    69,    70,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    43,
       0,    20,     0,    47,     0,     0,     0,    81,    72,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,    52,     0,    27,
       0,     0,    45,     0,    31,    33,    41,    40,     0,    28,
      21,    48,     0,     0,    32,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   -50,   -50,   -50,   -50,   -13,   -50,   222,   -50,
     -50,   -50,   -50,   -50,   -49,   -50,   -28,   -50,   -26,   -24,
     -43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,    11,    12,    27,    31,    20,    32,    84,
      24,    28,    48,   120,    49,    78,    72,   124,    73,    74,
      75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    19,    51,     3,    52,    59,    59,    29,    16,    17,
      18,    60,    60,    91,     1,    47,    87,    88,    89,    90,
      30,    37,     4,    38,    93,     5,    94,    95,    96,   119,
      16,    17,    18,   115,    16,    17,    18,    39,    13,    40,
      41,    42,    43,    44,    45,    14,   116,   152,   117,    46,
      50,   153,    51,    21,    52,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    98,    99,   100,   101,   102,   154,   155,    29,    16,
      17,    18,    85,    22,    63,    64,    65,    23,    66,    53,
      92,    33,    63,    64,    65,    25,    66,    50,    50,    51,
      51,    52,    52,    43,    26,   158,    67,    86,    54,   151,
     161,    43,    55,   164,    67,    69,    70,    56,    63,    64,
      65,    57,    66,    69,    70,    58,    63,    64,    65,   114,
      66,    71,     7,    61,    50,    62,    51,    43,    52,    71,
      67,     8,    35,    36,    68,    43,   149,   150,    67,    69,
      70,    76,    63,    64,    65,     9,    66,    69,    70,    37,
      10,    38,    77,    79,    15,    71,    16,    17,    18,    80,
      37,    43,    38,    71,    67,    39,    81,    40,    41,    42,
      43,    44,   118,    69,    70,    82,    39,    46,    40,    41,
      42,    43,    44,   125,    83,   100,   101,   102,    46,    71,
     121,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   126,   122,   123,
     127,   145,   147,   159,   160,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   128,   156,   148,   162,   165,   157,     0,    34,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   146,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   163,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    97,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    98,    99,
     100,   101,   102,   103,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    98,    99,   100,   101,   102,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      98,    99,   100,   101,   102,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,    98,    99,   100,   101,
     102,     0,     0,     0,   106,   107,     0,   109,   110,   111,
     112,    98,    99,   100,   101,   102,     0,     0,     0,   106,
     107
};

static const yytype_int16 yycheck[] =
{
      28,    14,    28,     3,    28,    25,    25,    13,    14,    15,
      16,    31,    31,    33,     9,    28,    59,    60,    61,    62,
      26,     1,     0,     3,    67,    23,    69,    70,    71,    78,
      14,    15,    16,    76,    14,    15,    16,    17,    29,    19,
      20,    21,    22,    23,    24,    11,     1,    26,     3,    29,
      78,    30,    78,     3,    78,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    34,    35,    36,    37,    38,   125,   126,    13,    14,
      15,    16,     1,     3,     3,     4,     5,    23,     7,    27,
       1,    26,     3,     4,     5,    25,     7,   125,   126,   125,
     126,   125,   126,    22,    25,   148,    25,    26,     3,   122,
     153,    22,    26,   162,    25,    34,    35,    26,     3,     4,
       5,     3,     7,    34,    35,    29,     3,     4,     5,     6,
       7,    50,     1,    25,   162,    25,   162,    22,   162,    50,
      25,    10,    29,    30,    29,    22,    29,    30,    25,    34,
      35,    25,     3,     4,     5,    24,     7,    34,    35,     1,
      29,     3,    25,     3,    12,    50,    14,    15,    16,    29,
       1,    22,     3,    50,    25,    17,    29,    19,    20,    21,
      22,    23,    24,    34,    35,    29,    17,    29,    19,    20,
      21,    22,    23,    26,    28,    36,    37,    38,    29,    50,
       3,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    26,    30,    26,
      26,    26,    26,     3,     3,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    26,    29,    27,    18,    26,    29,    -1,    26,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    28,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    34,    35,    36,    37,    38,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    42,    43,    -1,    45,    46,    47,
      48,    34,    35,    36,    37,    38,    -1,    -1,    -1,    42,
      43
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
      35,    50,    70,    72,    73,    74,    25,    25,    69,     3,
      29,    29,    29,    28,    63,     1,    26,    74,    74,    74,
      74,    33,     1,    74,    74,    74,    74,    29,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     6,    74,     1,     3,    24,    68,
      67,     3,    30,    26,    71,    26,    26,    26,    26,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    26,    26,    26,    27,    29,
      30,    60,    26,    30,    68,    68,    29,    29,    74,     3,
       3,    74,    18,    28,    68,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    57,    58,    58,
      59,    59,    60,    60,    60,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    65,    65,    65,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    70,    71,    71,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     4,     4,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     0,
       3,     5,     7,     5,     3,     2,     2,     2,     2,     1,
       5,     5,     2,     2,     0,     5,     3,     4,     3,     0,
       3,     7,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     3
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
  case 2: /* Program: CLASS IDENTIFIER LBRACE ProgramDeclList RBRACE  */
#line 67 "meta2_parser.y"
                                                        {
    (yyval.node) = create_node("Program", NULL);
    add_child((yyval.node), create_node("Identifier", (yyvsp[-3].str)));
    if ((yyvsp[-1].node) != NULL) { add_child((yyval.node), (yyvsp[-1].node)); }
    ast_root = (yyval.node);
}
#line 1489 "y.tab.c"
    break;

  case 3: /* ProgramDeclList: ProgramDeclList MethodDecl  */
#line 74 "meta2_parser.y"
                                            {
    if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
    else { add_sibling((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
}
#line 1498 "y.tab.c"
    break;

  case 4: /* ProgramDeclList: ProgramDeclList FieldDecl  */
#line 78 "meta2_parser.y"
                            {
    if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
    else { add_sibling((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
}
#line 1507 "y.tab.c"
    break;

  case 5: /* ProgramDeclList: ProgramDeclList SEMICOLON  */
#line 82 "meta2_parser.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1513 "y.tab.c"
    break;

  case 6: /* ProgramDeclList: %empty  */
#line 83 "meta2_parser.y"
              { (yyval.node) = NULL; }
#line 1519 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 86 "meta2_parser.y"
                                                  {
    (yyval.node) = create_node("MethodDecl", NULL);
    add_child((yyval.node), (yyvsp[-1].node));
    add_child((yyval.node), (yyvsp[0].node));
}
#line 1529 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type IDENTIFIER FieldIDList SEMICOLON  */
#line 92 "meta2_parser.y"
                                                               {
    (yyval.node) = create_node("FieldDecl", NULL);
    ast_node *t1 = create_node((yyvsp[-3].node)->type, NULL);
    add_child((yyval.node), t1);
    add_child((yyval.node), create_node("Identifier", (yyvsp[-2].str)));
    
    ast_node *curr = (yyval.node);
    ast_node *list = (yyvsp[-1].node);
    while(list != NULL) {
        ast_node *fdecl = create_node("FieldDecl", NULL);
        ast_node *tcopy = create_node((yyvsp[-3].node)->type, NULL);
        add_child(fdecl, tcopy);
        add_child(fdecl, create_node("Identifier", list->value));
        add_sibling(curr, fdecl);
        curr = fdecl;
        
        ast_node *next = list->sibling;
        free(list->value); 
        free(list);        
        list = next;
    }
    free_ast((yyvsp[-3].node)); 
}
#line 1557 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 115 "meta2_parser.y"
                  { (yyval.node) = NULL; }
#line 1563 "y.tab.c"
    break;

  case 10: /* FieldIDList: FieldIDList COMMA IDENTIFIER  */
#line 118 "meta2_parser.y"
                                          {
    ast_node *tmp = create_node(NULL, (yyvsp[0].str)); 
    if ((yyvsp[-2].node) == NULL) (yyval.node) = tmp;
    else { add_sibling((yyvsp[-2].node), tmp); (yyval.node) = (yyvsp[-2].node); }
}
#line 1573 "y.tab.c"
    break;

  case 11: /* FieldIDList: %empty  */
#line 123 "meta2_parser.y"
              { (yyval.node) = NULL; }
#line 1579 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 126 "meta2_parser.y"
           { (yyval.node) = create_node("Bool", NULL); }
#line 1585 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 127 "meta2_parser.y"
      { (yyval.node) = create_node("Int", NULL); }
#line 1591 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 128 "meta2_parser.y"
         { (yyval.node) = create_node("Double", NULL); }
#line 1597 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type IDENTIFIER LPAR FormalParams RPAR  */
#line 131 "meta2_parser.y"
                                                     {
    (yyval.node) = create_node("MethodHeader", NULL);
    add_child((yyval.node), (yyvsp[-4].node));
    add_child((yyval.node), create_node("Identifier", (yyvsp[-3].str)));
    ast_node *mp = create_node("MethodParams", NULL);
    if ((yyvsp[-1].node)) add_child(mp, (yyvsp[-1].node));
    add_child((yyval.node), mp);
}
#line 1610 "y.tab.c"
    break;

  case 16: /* MethodHeader: VOID IDENTIFIER LPAR FormalParams RPAR  */
#line 139 "meta2_parser.y"
                                         {
    (yyval.node) = create_node("MethodHeader", NULL);
    add_child((yyval.node), create_node("Void", NULL));
    add_child((yyval.node), create_node("Identifier", (yyvsp[-3].str)));
    ast_node *mp = create_node("MethodParams", NULL);
    if ((yyvsp[-1].node)) add_child(mp, (yyvsp[-1].node));
    add_child((yyval.node), mp);
}
#line 1623 "y.tab.c"
    break;

  case 17: /* MethodHeader: Type IDENTIFIER LPAR RPAR  */
#line 147 "meta2_parser.y"
                            {
    (yyval.node) = create_node("MethodHeader", NULL);
    add_child((yyval.node), (yyvsp[-3].node));
    add_child((yyval.node), create_node("Identifier", (yyvsp[-2].str)));
    add_child((yyval.node), create_node("MethodParams", NULL));
}
#line 1634 "y.tab.c"
    break;

  case 18: /* MethodHeader: VOID IDENTIFIER LPAR RPAR  */
#line 153 "meta2_parser.y"
                            {
    (yyval.node) = create_node("MethodHeader", NULL);
    add_child((yyval.node), create_node("Void", NULL));
    add_child((yyval.node), create_node("Identifier", (yyvsp[-2].str)));
    add_child((yyval.node), create_node("MethodParams", NULL));
}
#line 1645 "y.tab.c"
    break;

  case 19: /* FormalParams: Type IDENTIFIER FormalParamsList  */
#line 160 "meta2_parser.y"
                                               {
    (yyval.node) = create_node("ParamDecl", NULL);
    add_child((yyval.node), (yyvsp[-2].node));
    add_child((yyval.node), create_node("Identifier", (yyvsp[-1].str)));
    if ((yyvsp[0].node) != NULL) add_sibling((yyval.node), (yyvsp[0].node));
}
#line 1656 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ IDENTIFIER  */
#line 166 "meta2_parser.y"
                            {
    (yyval.node) = create_node("ParamDecl", NULL);
    add_child((yyval.node), create_node("StringArray", NULL));
    add_child((yyval.node), create_node("Identifier", (yyvsp[0].str)));
}
#line 1666 "y.tab.c"
    break;

  case 21: /* FormalParamsList: FormalParamsList COMMA Type IDENTIFIER  */
#line 172 "meta2_parser.y"
                                                         {
    ast_node *p = create_node("ParamDecl", NULL);
    add_child(p, (yyvsp[-1].node));
    add_child(p, create_node("Identifier", (yyvsp[0].str)));
    if ((yyvsp[-3].node) == NULL) (yyval.node) = p;
    else { add_sibling((yyvsp[-3].node), p); (yyval.node) = (yyvsp[-3].node); }
}
#line 1678 "y.tab.c"
    break;

  case 22: /* FormalParamsList: %empty  */
#line 179 "meta2_parser.y"
              { (yyval.node) = NULL; }
#line 1684 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE MethodBodyContent RBRACE  */
#line 182 "meta2_parser.y"
                                            {
    (yyval.node) = create_node("MethodBody", NULL);
    if ((yyvsp[-1].node)) add_child((yyval.node), (yyvsp[-1].node));
}
#line 1693 "y.tab.c"
    break;

  case 24: /* MethodBodyContent: MethodBodyContent Statement  */
#line 187 "meta2_parser.y"
                                               {
    if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
    else { add_sibling((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
}
#line 1702 "y.tab.c"
    break;

  case 25: /* MethodBodyContent: MethodBodyContent VarDecl  */
#line 191 "meta2_parser.y"
                            {
    if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
    else { add_sibling((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
}
#line 1711 "y.tab.c"
    break;

  case 26: /* MethodBodyContent: %empty  */
#line 195 "meta2_parser.y"
              { (yyval.node) = NULL; }
#line 1717 "y.tab.c"
    break;

  case 27: /* VarDecl: Type IDENTIFIER VarIDList SEMICOLON  */
#line 198 "meta2_parser.y"
                                             {
    (yyval.node) = create_node("VarDecl", NULL);
    ast_node *t1 = create_node((yyvsp[-3].node)->type, NULL);
    add_child((yyval.node), t1);
    add_child((yyval.node), create_node("Identifier", (yyvsp[-2].str)));
    
    ast_node *curr = (yyval.node);
    ast_node *list = (yyvsp[-1].node);
    while(list != NULL) {
        ast_node *vdecl = create_node("VarDecl", NULL);
        ast_node *tcopy = create_node((yyvsp[-3].node)->type, NULL);
        add_child(vdecl, tcopy);
        add_child(vdecl, create_node("Identifier", list->value));
        add_sibling(curr, vdecl);
        curr = vdecl;
        
        ast_node *next = list->sibling;
        free(list->value);
        free(list);
        list = next;
    }
    free_ast((yyvsp[-3].node));
}
#line 1745 "y.tab.c"
    break;

  case 28: /* VarIDList: VarIDList COMMA IDENTIFIER  */
#line 222 "meta2_parser.y"
                                      {
    ast_node *tmp = create_node(NULL, (yyvsp[0].str));
    if ((yyvsp[-2].node) == NULL) (yyval.node) = tmp;
    else { add_sibling((yyvsp[-2].node), tmp); (yyval.node) = (yyvsp[-2].node); }
}
#line 1755 "y.tab.c"
    break;

  case 29: /* VarIDList: %empty  */
#line 227 "meta2_parser.y"
              { (yyval.node) = NULL; }
#line 1761 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE StatementList RBRACE  */
#line 230 "meta2_parser.y"
                                       {
    if ((yyvsp[-1].node) == NULL) {
        (yyval.node) = create_node("Block", NULL);
    } else if ((yyvsp[-1].node)->sibling == NULL) { 
        // Exactly 1 child -> drop block
        (yyval.node) = (yyvsp[-1].node);
    } else {
        // Multi statement -> wrap in block
        (yyval.node) = create_node("Block", NULL);
        add_child((yyval.node), (yyvsp[-1].node));
    }
}
#line 1778 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement  */
#line 242 "meta2_parser.y"
                                        {
    (yyval.node) = create_node("If", NULL);
    add_child((yyval.node), (yyvsp[-2].node));
    add_child((yyval.node), (yyvsp[0].node) ? (yyvsp[0].node) : create_node("Block", NULL));
    add_child((yyval.node), create_node("Block", NULL)); // Ghost empty else Block
}
#line 1789 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 248 "meta2_parser.y"
                                             {
    (yyval.node) = create_node("If", NULL);
    add_child((yyval.node), (yyvsp[-4].node));
    add_child((yyval.node), (yyvsp[-2].node) ? (yyvsp[-2].node) : create_node("Block", NULL));
    add_child((yyval.node), (yyvsp[0].node) ? (yyvsp[0].node) : create_node("Block", NULL));
}
#line 1800 "y.tab.c"
    break;

  case 33: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 254 "meta2_parser.y"
                                 {
    (yyval.node) = create_node("While", NULL);
    add_child((yyval.node), (yyvsp[-2].node));
    add_child((yyval.node), (yyvsp[0].node) ? (yyvsp[0].node) : create_node("Block", NULL));
}
#line 1810 "y.tab.c"
    break;

  case 34: /* Statement: RETURN Expr SEMICOLON  */
#line 259 "meta2_parser.y"
                        {
    (yyval.node) = create_node("Return", NULL);
    add_child((yyval.node), (yyvsp[-1].node));
}
#line 1819 "y.tab.c"
    break;

  case 35: /* Statement: RETURN SEMICOLON  */
#line 263 "meta2_parser.y"
                   {
    (yyval.node) = create_node("Return", NULL);
}
#line 1827 "y.tab.c"
    break;

  case 36: /* Statement: MethodInvocation SEMICOLON  */
#line 266 "meta2_parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 1833 "y.tab.c"
    break;

  case 37: /* Statement: Assignment SEMICOLON  */
#line 267 "meta2_parser.y"
                       { (yyval.node) = (yyvsp[-1].node); }
#line 1839 "y.tab.c"
    break;

  case 38: /* Statement: ParseArgs SEMICOLON  */
#line 268 "meta2_parser.y"
                      { (yyval.node) = (yyvsp[-1].node); }
#line 1845 "y.tab.c"
    break;

  case 39: /* Statement: SEMICOLON  */
#line 269 "meta2_parser.y"
            { (yyval.node) = NULL; }
#line 1851 "y.tab.c"
    break;

  case 40: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 270 "meta2_parser.y"
                                 {
    (yyval.node) = create_node("Print", NULL);
    add_child((yyval.node), (yyvsp[-2].node));
}
#line 1860 "y.tab.c"
    break;

  case 41: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 274 "meta2_parser.y"
                                   {
    (yyval.node) = create_node("Print", NULL);
    add_child((yyval.node), create_node("StrLit", (yyvsp[-2].str)));
}
#line 1869 "y.tab.c"
    break;

  case 42: /* Statement: error SEMICOLON  */
#line 278 "meta2_parser.y"
                  { (yyval.node) = NULL; }
#line 1875 "y.tab.c"
    break;

  case 43: /* StatementList: StatementList Statement  */
#line 281 "meta2_parser.y"
                                       {
    if ((yyvsp[0].node) != NULL) {
        if ((yyvsp[-1].node) == NULL) (yyval.node) = (yyvsp[0].node);
        else { add_sibling((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
    } else { (yyval.node) = (yyvsp[-1].node); }
}
#line 1886 "y.tab.c"
    break;

  case 44: /* StatementList: %empty  */
#line 287 "meta2_parser.y"
              { (yyval.node) = NULL; }
#line 1892 "y.tab.c"
    break;

  case 45: /* MethodInvocation: IDENTIFIER LPAR Expr ExprList RPAR  */
#line 290 "meta2_parser.y"
                                                     {
    (yyval.node) = create_node("Call", NULL);
    add_child((yyval.node), create_node("Identifier", (yyvsp[-4].str)));
    add_child((yyval.node), (yyvsp[-2].node));
    if ((yyvsp[-1].node)) add_sibling((yyvsp[-2].node), (yyvsp[-1].node));
}
#line 1903 "y.tab.c"
    break;

  case 46: /* MethodInvocation: IDENTIFIER LPAR RPAR  */
#line 296 "meta2_parser.y"
                       {
    (yyval.node) = create_node("Call", NULL);
    add_child((yyval.node), create_node("Identifier", (yyvsp[-2].str)));
}
#line 1912 "y.tab.c"
    break;

  case 47: /* MethodInvocation: IDENTIFIER LPAR error RPAR  */
#line 300 "meta2_parser.y"
                             { (yyval.node) = NULL; }
#line 1918 "y.tab.c"
    break;

  case 48: /* ExprList: ExprList COMMA Expr  */
#line 303 "meta2_parser.y"
                              {
    if ((yyvsp[-2].node) == NULL) (yyval.node) = (yyvsp[0].node);
    else { add_sibling((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-2].node); }
}
#line 1927 "y.tab.c"
    break;

  case 49: /* ExprList: %empty  */
#line 307 "meta2_parser.y"
              { (yyval.node) = NULL; }
#line 1933 "y.tab.c"
    break;

  case 50: /* Assignment: IDENTIFIER ASSIGN Expr  */
#line 310 "meta2_parser.y"
                                   {
    (yyval.node) = create_node("Assign", NULL);
    add_child((yyval.node), create_node("Identifier", (yyvsp[-2].str)));
    add_child((yyval.node), (yyvsp[0].node));
}
#line 1943 "y.tab.c"
    break;

  case 51: /* ParseArgs: PARSEINT LPAR IDENTIFIER LSQ Expr RSQ RPAR  */
#line 316 "meta2_parser.y"
                                                      {
    (yyval.node) = create_node("ParseArgs", NULL);
    add_child((yyval.node), create_node("Identifier", (yyvsp[-4].str)));
    add_child((yyval.node), (yyvsp[-2].node));
}
#line 1953 "y.tab.c"
    break;

  case 52: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 321 "meta2_parser.y"
                           { (yyval.node) = NULL; }
#line 1959 "y.tab.c"
    break;

  case 53: /* Expr: Expr PLUS Expr  */
#line 324 "meta2_parser.y"
                     { (yyval.node) = create_node("Add", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1965 "y.tab.c"
    break;

  case 54: /* Expr: Expr MINUS Expr  */
#line 325 "meta2_parser.y"
                      { (yyval.node) = create_node("Sub", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1971 "y.tab.c"
    break;

  case 55: /* Expr: Expr STAR Expr  */
#line 326 "meta2_parser.y"
                     { (yyval.node) = create_node("Mul", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1977 "y.tab.c"
    break;

  case 56: /* Expr: Expr DIV Expr  */
#line 327 "meta2_parser.y"
                    { (yyval.node) = create_node("Div", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1983 "y.tab.c"
    break;

  case 57: /* Expr: Expr MOD Expr  */
#line 328 "meta2_parser.y"
                    { (yyval.node) = create_node("Mod", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1989 "y.tab.c"
    break;

  case 58: /* Expr: Expr AND Expr  */
#line 329 "meta2_parser.y"
                    { (yyval.node) = create_node("And", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1995 "y.tab.c"
    break;

  case 59: /* Expr: Expr OR Expr  */
#line 330 "meta2_parser.y"
                   { (yyval.node) = create_node("Or", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 2001 "y.tab.c"
    break;

  case 60: /* Expr: Expr XOR Expr  */
#line 331 "meta2_parser.y"
                    { (yyval.node) = create_node("Xor", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 2007 "y.tab.c"
    break;

  case 61: /* Expr: Expr LSHIFT Expr  */
#line 332 "meta2_parser.y"
                       { (yyval.node) = create_node("Lshift", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 2013 "y.tab.c"
    break;

  case 62: /* Expr: Expr RSHIFT Expr  */
#line 333 "meta2_parser.y"
                       { (yyval.node) = create_node("Rshift", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 2019 "y.tab.c"
    break;

  case 63: /* Expr: Expr EQ Expr  */
#line 334 "meta2_parser.y"
                    { (yyval.node) = create_node("Eq", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 2025 "y.tab.c"
    break;

  case 64: /* Expr: Expr GE Expr  */
#line 335 "meta2_parser.y"
                    { (yyval.node) = create_node("Ge", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 2031 "y.tab.c"
    break;

  case 65: /* Expr: Expr GT Expr  */
#line 336 "meta2_parser.y"
                    { (yyval.node) = create_node("Gt", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 2037 "y.tab.c"
    break;

  case 66: /* Expr: Expr LE Expr  */
#line 337 "meta2_parser.y"
                    { (yyval.node) = create_node("Le", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 2043 "y.tab.c"
    break;

  case 67: /* Expr: Expr LT Expr  */
#line 338 "meta2_parser.y"
                    { (yyval.node) = create_node("Lt", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 2049 "y.tab.c"
    break;

  case 68: /* Expr: Expr NE Expr  */
#line 339 "meta2_parser.y"
                    { (yyval.node) = create_node("Ne", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 2055 "y.tab.c"
    break;

  case 69: /* Expr: MINUS Expr  */
#line 340 "meta2_parser.y"
                              { (yyval.node) = create_node("Minus", NULL); add_child((yyval.node), (yyvsp[0].node)); }
#line 2061 "y.tab.c"
    break;

  case 70: /* Expr: NOT Expr  */
#line 341 "meta2_parser.y"
               { (yyval.node) = create_node("Not", NULL); add_child((yyval.node), (yyvsp[0].node)); }
#line 2067 "y.tab.c"
    break;

  case 71: /* Expr: PLUS Expr  */
#line 342 "meta2_parser.y"
                            { (yyval.node) = create_node("Plus", NULL); add_child((yyval.node), (yyvsp[0].node)); }
#line 2073 "y.tab.c"
    break;

  case 72: /* Expr: LPAR Expr RPAR  */
#line 343 "meta2_parser.y"
                     { (yyval.node) = (yyvsp[-1].node); }
#line 2079 "y.tab.c"
    break;

  case 73: /* Expr: MethodInvocation  */
#line 344 "meta2_parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2085 "y.tab.c"
    break;

  case 74: /* Expr: Assignment  */
#line 345 "meta2_parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2091 "y.tab.c"
    break;

  case 75: /* Expr: ParseArgs  */
#line 346 "meta2_parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 2097 "y.tab.c"
    break;

  case 76: /* Expr: IDENTIFIER DOTLENGTH  */
#line 347 "meta2_parser.y"
                           { (yyval.node) = create_node("Length", NULL); add_child((yyval.node), create_node("Identifier", (yyvsp[-1].str))); }
#line 2103 "y.tab.c"
    break;

  case 77: /* Expr: IDENTIFIER  */
#line 348 "meta2_parser.y"
                 { (yyval.node) = create_node("Identifier", (yyvsp[0].str)); }
#line 2109 "y.tab.c"
    break;

  case 78: /* Expr: NATURAL  */
#line 349 "meta2_parser.y"
              { (yyval.node) = create_node("Natural", (yyvsp[0].str)); }
#line 2115 "y.tab.c"
    break;

  case 79: /* Expr: DECIMAL  */
#line 350 "meta2_parser.y"
              { (yyval.node) = create_node("Decimal", (yyvsp[0].str)); }
#line 2121 "y.tab.c"
    break;

  case 80: /* Expr: BOOLLIT  */
#line 351 "meta2_parser.y"
              { (yyval.node) = create_node("BoolLit", (yyvsp[0].str)); }
#line 2127 "y.tab.c"
    break;

  case 81: /* Expr: LPAR error RPAR  */
#line 352 "meta2_parser.y"
                      { (yyval.node) = NULL; }
#line 2133 "y.tab.c"
    break;


#line 2137 "y.tab.c"

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

#line 355 "meta2_parser.y"


int main(int argc, char **argv) {
    if (argc > 1) {
        if (strcmp(argv[1], "-l") == 0) {
            print_tokens = 1; lex_only = 1;
        } else if (strcmp(argv[1], "-e1") == 0) {
            lex_only = 1;
        } else if (strcmp(argv[1], "-t") == 0) {
            print_ast_flag = 1;
        }
    }

    if (lex_only) {
        while (yylex() != 0);
    } else {
        yyparse();
        if (print_ast_flag && syntax_errors == 0 && ast_root != NULL) {
            print_ast(ast_root, 0);
        }
    }
    
    if (ast_root != NULL) { free_ast(ast_root); }
    free_string_buffer();
    yylex_destroy();
    return 0;
}
