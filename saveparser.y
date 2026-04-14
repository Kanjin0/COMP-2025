%{
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


int print_ast_flag = 0;
int syntax_errors = 0;
ast_node *ast_root = NULL;

// Um dos erros que está a dar é como o do lexer, onde a coluna do erro está incrementada até ao final
// de onde o erro acaba e não onde ele começa

// Para além disso, não está a incluir o campo da string que originou o erro (yytext, i mean)
// pode estar a consumí-lo antes de o poder imprimir, fazendo com que não haja nada

void yyerror(const char *s) {
    extern char* yytext;
    printf("Line %d, col %d: %s: %s\n", token_line, token_column, s, yytext);
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
%type <node> VarDecl VarIDList Statement StatementList Expr ExprList
%type <node> MethodInvocation Assignment ParseArgs

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

%%

Program: CLASS IDENTIFIER LBRACE ProgramDeclList RBRACE {
    $$ = create_node("Program", NULL);
    add_child($$, create_node("Identifier", $2));
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
    $$ = create_node("MethodDecl", NULL);
    add_child($$, $3);
    add_child($$, $4);
} ;

FieldDecl: PUBLIC STATIC Type IDENTIFIER FieldIDList SEMICOLON {
    $$ = create_node("FieldDecl", NULL);
    ast_node *t1 = create_node($3->type, NULL);
    add_child($$, t1);
    add_child($$, create_node("Identifier", $4));
    
    ast_node *curr = $$;
    ast_node *list = $5;
    while(list != NULL) {
        ast_node *fdecl = create_node("FieldDecl", NULL);
        ast_node *tcopy = create_node($3->type, NULL);
        add_child(fdecl, tcopy);
        add_child(fdecl, create_node("Identifier", list->value));
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
    ast_node *tmp = create_node(NULL, $3); 
    if ($1 == NULL) $$ = tmp;
    else { add_sibling($1, tmp); $$ = $1; }
}
| /* empty */ { $$ = NULL; }
;

Type: BOOL { $$ = create_node("Bool", NULL); }
| INT { $$ = create_node("Int", NULL); }
| DOUBLE { $$ = create_node("Double", NULL); }
;

MethodHeader: Type IDENTIFIER LPAR FormalParams RPAR {
    $$ = create_node("MethodHeader", NULL);
    add_child($$, $1);
    add_child($$, create_node("Identifier", $2));
    ast_node *mp = create_node("MethodParams", NULL);
    if ($4) add_child(mp, $4);
    add_child($$, mp);
}
| VOID IDENTIFIER LPAR FormalParams RPAR {
    $$ = create_node("MethodHeader", NULL);
    add_child($$, create_node("Void", NULL));
    add_child($$, create_node("Identifier", $2));
    ast_node *mp = create_node("MethodParams", NULL);
    if ($4) add_child(mp, $4);
    add_child($$, mp);
}
| Type IDENTIFIER LPAR RPAR {
    $$ = create_node("MethodHeader", NULL);
    add_child($$, $1);
    add_child($$, create_node("Identifier", $2));
    add_child($$, create_node("MethodParams", NULL));
}
| VOID IDENTIFIER LPAR RPAR {
    $$ = create_node("MethodHeader", NULL);
    add_child($$, create_node("Void", NULL));
    add_child($$, create_node("Identifier", $2));
    add_child($$, create_node("MethodParams", NULL));
} ;

FormalParams: Type IDENTIFIER FormalParamsList {
    $$ = create_node("ParamDecl", NULL);
    add_child($$, $1);
    add_child($$, create_node("Identifier", $2));
    if ($3 != NULL) add_sibling($$, $3);
}
| STRING LSQ RSQ IDENTIFIER {
    $$ = create_node("ParamDecl", NULL);
    add_child($$, create_node("StringArray", NULL));
    add_child($$, create_node("Identifier", $4));
} ;

FormalParamsList: FormalParamsList COMMA Type IDENTIFIER {
    ast_node *p = create_node("ParamDecl", NULL);
    add_child(p, $3);
    add_child(p, create_node("Identifier", $4));
    if ($1 == NULL) $$ = p;
    else { add_sibling($1, p); $$ = $1; }
}
| /* empty */ { $$ = NULL; }
;

MethodBody: LBRACE MethodBodyContent RBRACE {
    $$ = create_node("MethodBody", NULL);
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
    $$ = create_node("VarDecl", NULL);
    ast_node *t1 = create_node($1->type, NULL);
    add_child($$, t1);
    add_child($$, create_node("Identifier", $2));
    
    ast_node *curr = $$;
    ast_node *list = $3;
    while(list != NULL) {
        ast_node *vdecl = create_node("VarDecl", NULL);
        ast_node *tcopy = create_node($1->type, NULL);
        add_child(vdecl, tcopy);
        add_child(vdecl, create_node("Identifier", list->value));
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
    ast_node *tmp = create_node(NULL, $3);
    if ($1 == NULL) $$ = tmp;
    else { add_sibling($1, tmp); $$ = $1; }
}
| /* empty */ { $$ = NULL; }
;

Statement: LBRACE StatementList RBRACE {
    if ($2 == NULL) {
        $$ = create_node("Block", NULL);
    } else if ($2->sibling == NULL) { 
        // Exactly 1 child -> drop block
        $$ = $2;
    } else {
        // Multi statement -> wrap in block
        $$ = create_node("Block", NULL);
        add_child($$, $2);
    }
}
| IF LPAR Expr RPAR Statement %prec IFX {
    $$ = create_node("If", NULL);
    add_child($$, $3);
    add_child($$, $5 ? $5 : create_node("Block", NULL));
    add_child($$, create_node("Block", NULL)); // Ghost empty else Block
}
| IF LPAR Expr RPAR Statement ELSE Statement {
    $$ = create_node("If", NULL);
    add_child($$, $3);
    add_child($$, $5 ? $5 : create_node("Block", NULL));
    add_child($$, $7 ? $7 : create_node("Block", NULL));
}
| WHILE LPAR Expr RPAR Statement {
    $$ = create_node("While", NULL);
    add_child($$, $3);
    add_child($$, $5 ? $5 : create_node("Block", NULL));
}
| RETURN Expr SEMICOLON {
    $$ = create_node("Return", NULL);
    add_child($$, $2);
}
| RETURN SEMICOLON {
    $$ = create_node("Return", NULL);
}
| MethodInvocation SEMICOLON { $$ = $1; }
| Assignment SEMICOLON { $$ = $1; }
| ParseArgs SEMICOLON { $$ = $1; }
| SEMICOLON { $$ = NULL; }
| PRINT LPAR Expr RPAR SEMICOLON {
    $$ = create_node("Print", NULL);
    add_child($$, $3);
}
| PRINT LPAR STRLIT RPAR SEMICOLON {
    $$ = create_node("Print", NULL);
    add_child($$, create_node("StrLit", $3));
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
    $$ = create_node("Call", NULL);
    add_child($$, create_node("Identifier", $1));
    add_child($$, $3);
    if ($4) add_sibling($3, $4);
}
| IDENTIFIER LPAR RPAR {
    $$ = create_node("Call", NULL);
    add_child($$, create_node("Identifier", $1));
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
    $$ = create_node("Assign", NULL);
    add_child($$, create_node("Identifier", $1));
    add_child($$, $3);
} ;

ParseArgs: PARSEINT LPAR IDENTIFIER LSQ Expr RSQ RPAR {
    $$ = create_node("ParseArgs", NULL);
    add_child($$, create_node("Identifier", $3));
    add_child($$, $5);
}
| PARSEINT LPAR error RPAR { $$ = NULL; }
;

Expr: Expr PLUS Expr { $$ = create_node("Add", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr MINUS Expr { $$ = create_node("Sub", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr STAR Expr { $$ = create_node("Mul", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr DIV Expr { $$ = create_node("Div", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr MOD Expr { $$ = create_node("Mod", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr AND Expr { $$ = create_node("And", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr OR Expr { $$ = create_node("Or", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr XOR Expr { $$ = create_node("Xor", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr LSHIFT Expr { $$ = create_node("Lshift", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr RSHIFT Expr { $$ = create_node("Rshift", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr EQ Expr  { $$ = create_node("Eq", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr GE Expr  { $$ = create_node("Ge", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr GT Expr  { $$ = create_node("Gt", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr LE Expr  { $$ = create_node("Le", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr LT Expr  { $$ = create_node("Lt", NULL); add_child($$, $1); add_child($$, $3); }
    | Expr NE Expr  { $$ = create_node("Ne", NULL); add_child($$, $1); add_child($$, $3); }
    | MINUS Expr %prec UMINUS { $$ = create_node("Minus", NULL); add_child($$, $2); }
    | NOT Expr { $$ = create_node("Not", NULL); add_child($$, $2); }
    | PLUS Expr %prec UPLUS { $$ = create_node("Plus", NULL); add_child($$, $2); }
    | LPAR Expr RPAR { $$ = $2; }
    | MethodInvocation { $$ = $1; }
    | Assignment { $$ = $1; }
    | ParseArgs { $$ = $1; }
    | IDENTIFIER DOTLENGTH { $$ = create_node("Length", NULL); add_child($$, create_node("Identifier", $1)); }
    | IDENTIFIER { $$ = create_node("Identifier", $1); }
    | NATURAL { $$ = create_node("Natural", $1); }
    | DECIMAL { $$ = create_node("Decimal", $1); }
    | BOOLLIT { $$ = create_node("BoolLit", $1); }
    | LPAR error RPAR { $$ = NULL; }
    ;

%%

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
