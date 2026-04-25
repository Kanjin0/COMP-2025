%{
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
%}

%union {
    char *str;
    struct ast_node *node;
}

%token <str> IDENTIFIER NATURAL DECIMAL STRLIT BOOLLIT RESERVED
%token CLASS PUBLIC STATIC VOID STRING INT DOUBLE BOOL IF ELSE WHILE RETURN PRINT PARSEINT
%token LBRACE RBRACE LPAR RPAR LSQ RSQ SEMICOLON COMMA ASSIGN ARROW DOTLENGTH
%token PLUS MINUS STAR DIV MOD AND OR XOR LSHIFT RSHIFT EQ GE GT LE LT NE NOT

%type <node> Program ProgramDeclList MethodDecl FieldDecl FieldIDList Type
%type <node> MethodHeader FormalParams FormalParamsList MethodBody MethodBodyContent
%type <node> VarDecl VarIDList Statement StatementList Expr ExprNoAssign
%type <node> MethodInvocation Assignment ParseArgs ExprList

%right ASSIGN
%left OR
%left AND
%left XOR
%left EQ NE
%left LT LE GT GE
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT UPLUS UMINUS

%nonassoc IFX
%nonassoc ELSE

%locations
%%

Program: CLASS IDENTIFIER LBRACE ProgramDeclList RBRACE {
    $$ = create_node(Program, NULL, @1.first_line, @1.first_column);
    ast_node *id = create_node(Identifier, $2, @2.first_line, @2.first_column);
    add_child($$, id);
    if ($4 != NULL) { add_child($$, $4); }
    ast_root = $$;
} ;

ProgramDeclList: ProgramDeclList MethodDecl {
    if ($1 == NULL) $$ = $2;
    else { add_sibling($1, $2); $$ = $1; }
}
| ProgramDeclList FieldDecl {
    if ($1 == NULL) $$ = $2;
    else { add_sibling($1, $2); $$ = $1; }
}
| ProgramDeclList SEMICOLON { $$ = $1; }
| /* empty */ { $$ = NULL; }
;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody {
    $$ = create_node(MethodDecl, NULL, @1.first_line, @1.first_column);
    add_child($$, $3);
    add_child($$, $4);
} ;

FieldDecl: PUBLIC STATIC Type IDENTIFIER FieldIDList SEMICOLON {
    $$ = create_node(FieldDecl, NULL, @1.first_line, @1.first_column);
    ast_node *t1 = create_node($3->category, NULL, $3->line, $3->column);
    add_child($$, t1);
    add_child($$, create_node(Identifier, $4, @4.first_line, @4.first_column));

    ast_node *curr = $$;
    ast_node *list = $5;
    while(list != NULL) {
        ast_node *fdecl = create_node(FieldDecl, NULL, @1.first_line, @1.first_column);
        ast_node *tcopy = create_node($3->category, NULL, $3->line, $3->column);
        add_child(fdecl, tcopy);
        add_child(fdecl, create_node(Identifier, list->value, list->line, list->column));
        add_sibling(curr, fdecl);
        curr = fdecl;

        ast_node *next = list->sibling;
        free(list->value);
        free(list);
        list = next;
    }
    free_ast($3);
}
| error SEMICOLON { $$ = NULL; }
;

FieldIDList: FieldIDList COMMA IDENTIFIER {
    ast_node *tmp = create_node(NullCategory, $3, @3.first_line, @3.first_column);
    if ($1 == NULL) $$ = tmp;
    else { add_sibling($1, tmp); $$ = $1; }
}
| /* empty */ { $$ = NULL; }
;

Type: BOOL    { $$ = create_node(Bool, NULL, @1.first_line, @1.first_column); }
| INT         { $$ = create_node(Int, NULL, @1.first_line, @1.first_column); }
| DOUBLE      { $$ = create_node(Double, NULL, @1.first_line, @1.first_column); }
;

MethodHeader: Type IDENTIFIER LPAR FormalParams RPAR {
    $$ = create_node(MethodHeader, NULL, @1.first_line, @1.first_column);
    add_child($$, $1);
    add_child($$, create_node(Identifier, $2, @2.first_line, @2.first_column));
    ast_node *mp = create_node(MethodParams, NULL, @3.first_line, @3.first_column);
    if ($4) add_child(mp, $4);
    add_child($$, mp);
}
| VOID IDENTIFIER LPAR FormalParams RPAR {
    $$ = create_node(MethodHeader, NULL, @1.first_line, @1.first_column);
    add_child($$, create_node(Void, NULL, @1.first_line, @1.first_column));
    add_child($$, create_node(Identifier, $2, @2.first_line, @2.first_column));
    ast_node *mp = create_node(MethodParams, NULL, @3.first_line, @3.first_column);
    if ($4) add_child(mp, $4);
    add_child($$, mp);
}
| Type IDENTIFIER LPAR RPAR {
    $$ = create_node(MethodHeader, NULL, @1.first_line, @1.first_column);
    add_child($$, $1);
    add_child($$, create_node(Identifier, $2, @2.first_line, @2.first_column));
    add_child($$, create_node(MethodParams, NULL, @3.first_line, @3.first_column));
}
| VOID IDENTIFIER LPAR RPAR {
    $$ = create_node(MethodHeader, NULL, @1.first_line, @1.first_column);
    add_child($$, create_node(Void, NULL, @1.first_line, @1.first_column));
    add_child($$, create_node(Identifier, $2, @2.first_line, @2.first_column));
    add_child($$, create_node(MethodParams, NULL, @3.first_line, @3.first_column));
} ;

FormalParams: Type IDENTIFIER FormalParamsList {
    $$ = create_node(ParamDecl, NULL, $1->line, $1->column);
    add_child($$, $1);
    add_child($$, create_node(Identifier, $2, @2.first_line, @2.first_column));
    if ($3 != NULL) add_sibling($$, $3);
}
| STRING LSQ RSQ IDENTIFIER {
    $$ = create_node(ParamDecl, NULL, @1.first_line, @1.first_column);
    add_child($$, create_node(StringArray, NULL, @1.first_line, @1.first_column));
    add_child($$, create_node(Identifier, $4, @4.first_line, @4.first_column));
} ;

FormalParamsList: FormalParamsList COMMA Type IDENTIFIER {
    ast_node *p = create_node(ParamDecl, NULL, $3->line, $3->column);
    add_child(p, $3);
    add_child(p, create_node(Identifier, $4, @4.first_line, @4.first_column));
    if ($1 == NULL) $$ = p;
    else { add_sibling($1, p); $$ = $1; }
}
| /* empty */ { $$ = NULL; }
;

MethodBody: LBRACE MethodBodyContent RBRACE {
    $$ = create_node(MethodBody, NULL, @1.first_line, @1.first_column);
    if ($2) add_child($$, $2);
} ;

MethodBodyContent: MethodBodyContent Statement {
    if ($1 == NULL) $$ = $2;
    else { add_sibling($1, $2); $$ = $1; }
}
| MethodBodyContent VarDecl {
    if ($1 == NULL) $$ = $2;
    else { add_sibling($1, $2); $$ = $1; }
}
| /* empty */ { $$ = NULL; }
;

VarDecl: Type IDENTIFIER VarIDList SEMICOLON {
    $$ = create_node(VarDecl, NULL, $1->line, $1->column);
    ast_node *t1 = create_node($1->category, NULL, $1->line, $1->column);
    add_child($$, t1);
    add_child($$, create_node(Identifier, $2, @2.first_line, @2.first_column));

    ast_node *curr = $$;
    ast_node *list = $3;
    while(list != NULL) {
        ast_node *vdecl = create_node(VarDecl, NULL, $1->line, $1->column);
        ast_node *tcopy = create_node($1->category, NULL, $1->line, $1->column);
        add_child(vdecl, tcopy);
        add_child(vdecl, create_node(Identifier, list->value, list->line, list->column));
        add_sibling(curr, vdecl);
        curr = vdecl;

        ast_node *next = list->sibling;
        free(list->value);
        free(list);
        list = next;
    }
    free_ast($1);
} ;

VarIDList: VarIDList COMMA IDENTIFIER {
    ast_node *tmp = create_node(NullCategory, $3, @3.first_line, @3.first_column);
    if ($1 == NULL) $$ = tmp;
    else { add_sibling($1, tmp); $$ = $1; }
}
| /* empty */ { $$ = NULL; }
;

Statement: LBRACE StatementList RBRACE {
    if ($2 == NULL) {
        $$ = NULL;
    } else if ($2->sibling == NULL) {
        $$ = $2;
    } else {
        $$ = create_node(Block, NULL, @1.first_line, @1.first_column);
        add_child($$, $2);
    }
}
| IF LPAR Expr RPAR Statement %prec IFX {
    $$ = create_node(If, NULL, @1.first_line, @1.first_column);
    add_child($$, $3);
    add_child($$, $5 ? $5 : create_node(Block, NULL, 0, 0));
    add_child($$, create_node(Block, NULL, 0, 0)); // Ghost empty else Block
}
| IF LPAR Expr RPAR Statement ELSE Statement {
    $$ = create_node(If, NULL, @1.first_line, @1.first_column);
    add_child($$, $3);
    add_child($$, $5 ? $5 : create_node(Block, NULL, 0, 0));
    add_child($$, $7 ? $7 : create_node(Block, NULL, 0, 0));
}
| WHILE LPAR Expr RPAR Statement {
    $$ = create_node(While, NULL, @1.first_line, @1.first_column);
    add_child($$, $3);
    add_child($$, $5 ? $5 : create_node(Block, NULL, 0, 0));
}
| RETURN Expr SEMICOLON {
    $$ = create_node(Return, NULL, @1.first_line, @1.first_column);
    add_child($$, $2);
}
| RETURN SEMICOLON {
    $$ = create_node(Return, NULL, @1.first_line, @1.first_column);
}
| MethodInvocation SEMICOLON { $$ = $1; }
| Assignment SEMICOLON { $$ = $1; }
| ParseArgs SEMICOLON { $$ = $1; }
| SEMICOLON { $$ = NULL; }
| PRINT LPAR Expr RPAR SEMICOLON {
    $$ = create_node(Print, NULL, @1.first_line, @1.first_column);
    add_child($$, $3);
}
| PRINT LPAR STRLIT RPAR SEMICOLON {
    $$ = create_node(Print, NULL, @1.first_line, @1.first_column);
    add_child($$, create_node(StrLit, $3, @3.first_line, @3.first_column));
}
| error SEMICOLON { $$ = NULL; }
;

StatementList: StatementList Statement {
    if ($2 != NULL) {
        if ($1 == NULL) $$ = $2;
        else { add_sibling($1, $2); $$ = $1; }
    } else { $$ = $1; }
}
| /* empty */ { $$ = NULL; }
;

MethodInvocation: IDENTIFIER LPAR Expr ExprList RPAR {
    $$ = create_node(Call, NULL, @1.first_line, @1.first_column);
    add_child($$, create_node(Identifier, $1, @1.first_line, @1.first_column));
    add_child($$, $3);
    if ($4) add_sibling($3, $4);
}
| IDENTIFIER LPAR RPAR {
    $$ = create_node(Call, NULL, @1.first_line, @1.first_column);
    add_child($$, create_node(Identifier, $1, @1.first_line, @1.first_column));
}
| IDENTIFIER LPAR error RPAR { $$ = NULL; }
;

ExprList: ExprList COMMA Expr {
    if ($1 == NULL) $$ = $3;
    else { add_sibling($1, $3); $$ = $1; }
}
| /* empty */ { $$ = NULL; }
;

Assignment: IDENTIFIER ASSIGN Expr {
    $$ = create_node(Assign, NULL, @2.first_line, @2.first_column);
    add_child($$, create_node(Identifier, $1, @1.first_line, @1.first_column));
    add_child($$, $3);
} ;

ParseArgs: PARSEINT LPAR IDENTIFIER LSQ Expr RSQ RPAR {
    $$ = create_node(ParseArgs, NULL, @1.first_line, @1.first_column);
    add_child($$, create_node(Identifier, $3, @3.first_line, @3.first_column));
    add_child($$, $5);
}
| PARSEINT LPAR error RPAR { $$ = NULL; }
;

/* ----- Expression grammar with split levels ----- */
Expr: ExprNoAssign { $$ = $1; } | Assignment { $$ = $1; } ;

ExprNoAssign: ExprNoAssign PLUS ExprNoAssign   {
    $$ = create_node(Add, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign MINUS ExprNoAssign {
    $$ = create_node(Sub, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign STAR ExprNoAssign {
    $$ = create_node(Mul, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign DIV ExprNoAssign {
    $$ = create_node(Div, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign MOD ExprNoAssign {
    $$ = create_node(Mod, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign AND ExprNoAssign {
    $$ = create_node(And, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign OR ExprNoAssign {
    $$ = create_node(Or, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign XOR ExprNoAssign {
    $$ = create_node(Xor, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign LSHIFT ExprNoAssign {
    $$ = create_node(Lshift, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign RSHIFT ExprNoAssign {
    $$ = create_node(Rshift, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign EQ ExprNoAssign {
    $$ = create_node(Eq, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign GE ExprNoAssign {
    $$ = create_node(Ge, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign GT ExprNoAssign {
    $$ = create_node(Gt, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign LE ExprNoAssign {
    $$ = create_node(Le, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign LT ExprNoAssign {
    $$ = create_node(Lt, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| ExprNoAssign NE ExprNoAssign {
    $$ = create_node(Ne, NULL, @2.first_line, @2.first_column);
    add_child($$, $1); add_child($$, $3);
}
| MINUS ExprNoAssign %prec UMINUS {
    $$ = create_node(Minus, NULL, @1.first_line, @1.first_column);
    add_child($$, $2);
}
| NOT ExprNoAssign {
    $$ = create_node(Not, NULL, @1.first_line, @1.first_column);
    add_child($$, $2);
}
| PLUS ExprNoAssign %prec UPLUS {
    $$ = create_node(Plus, NULL, @1.first_line, @1.first_column);
    add_child($$, $2);
}
| LPAR Expr RPAR { $$ = $2; }
| MethodInvocation { $$ = $1; }
| ParseArgs { $$ = $1; }
| IDENTIFIER DOTLENGTH {
    $$ = create_node(Length, NULL, @2.first_line, @2.first_column);
    add_child($$, create_node(Identifier, $1, @1.first_line, @1.first_column));
}
| IDENTIFIER {
    $$ = create_node(Identifier, $1, @1.first_line, @1.first_column);
}
| NATURAL {
    $$ = create_node(Natural, $1, @1.first_line, @1.first_column);
}
| DECIMAL {
    $$ = create_node(Decimal, $1, @1.first_line, @1.first_column);
}
| BOOLLIT {
    $$ = create_node(BoolLit, $1, @1.first_line, @1.first_column);
}
| LPAR error RPAR { $$ = NULL; }
;

%%

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