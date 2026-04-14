/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 178 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
