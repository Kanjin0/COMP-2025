%{
    /* place here any C variables and definitions */

    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "y.tab.h"


    int line = 1;
    int column = 1;
    int print_tokens = 0;

    int token_line;
    int token_column;
    extern int lex_only;

    char* string_buffer = NULL;
    int string_buffer_size = 0;
    int string_buffer_index = 0;
    
    /* Track if we've seen invalid escapes in current string */
    int string_has_invalid_escape = 0;
    int string_start_line = 0;
    int string_start_column = 0;
    
    /* Track comment start position for error messages */
    int comment_start_line = 0;
    int comment_start_column = 0;

    /* For error reporting: store the last returned token's text and position */
    char yyerror_text[1024];   /* enough for any reasonable token */
    int  yyerror_line;
    int  yyerror_column;

    #define SAVE_TOKEN_INFO() do { \
        strncpy(yyerror_text, yytext, sizeof(yyerror_text)-1); \
        yyerror_text[sizeof(yyerror_text)-1] = '\0'; \
        yyerror_line   = token_line;   /* already set by YY_USER_ACTION */ \
        yyerror_column = token_column; \
    } while(0)

    #define STRING_BUFFER_INITIAL_SIZE 64
    #define STRING_BUFFER_GROWTH_FACTOR 2
    #define YY_USER_ACTION { \
        token_line = line; \
        token_column = column; \
        yylloc.first_line = line; \
        yylloc.first_column = column; \
        column += yyleng; \
    }


    void ensure_string_buffer_capacity(int needed_size){
        if(string_buffer_index + needed_size >= string_buffer_size){
            int new_buffer_size = string_buffer_size * STRING_BUFFER_GROWTH_FACTOR + needed_size;

            if(new_buffer_size < STRING_BUFFER_INITIAL_SIZE) new_buffer_size = STRING_BUFFER_INITIAL_SIZE;

            string_buffer = realloc(string_buffer, new_buffer_size);

            if(!string_buffer){
                fprintf(stderr, "Fatal error: out of memory\n");
                exit(1);
            }

            string_buffer_size = new_buffer_size;
        }
    }

    void init_string_buffer(){
        if(!string_buffer){
            string_buffer_size = STRING_BUFFER_INITIAL_SIZE;
            string_buffer = malloc(string_buffer_size);

            if(!string_buffer){
                fprintf(stderr, "Fatal error: out of memory\n");
                exit(1);
            }
        }
        string_buffer_index = 0;
        string_buffer[0] = '\0';
        string_has_invalid_escape = 0;
    }

    void free_string_buffer(){
        free(string_buffer);
        string_buffer = NULL;
        string_buffer_index = 0;
        string_buffer_size = 0;
        string_has_invalid_escape = 0;
    }

%}

BOOLLIT             "true"|"false"
AND                 "&&"
ASSIGN              "="
STAR                "*"
COMMA               ","
DIV                 "/"
EQ                  "=="
GE                  ">="
GT                  ">"
LBRACE              "{"
LE                  "<="
LPAR                "("
LSQ                 "["
LT                  "<"
MINUS               "-"
MOD                 "%"
NE                  "!="
NOT                 "!"
OR                  "||"
PLUS                "+"
RBRACE              "}"
RPAR                ")"
RSQ                 "]"
SEMICOLON           ";"
ARROW               "->"
LSHIFT              "<<"
RSHIFT              ">>"
XOR                 "^"
BOOL                "boolean"
CLASS               "class"
DOTLENGTH           ".length"
DOUBLE              "double"
ELSE                "else"
IF                  "if"
INT                 "int"
PRINT               "System.out.print"
PARSEINT            "Integer.parseInt"
PUBLIC              "public"
RETURN              "return"
STATIC              "static"
STRING              "String"
VOID                "void"
WHILE               "while"

/* All Java keywords not used in Juc - must be RESERVED */
INCREMENT           "++"
DECREMENT           "--"
NULL_LIT            "null"
INTEGER_ID          "Integer"
SYSTEM_ID           "System"
ABSTRACT_ID         "abstract"
CONTINUE_ID         "continue"
SWITCH_ID           "switch"
ASSERT_ID           "assert"
DEFAULT_ID          "default"
PACKAGE_ID          "package"
SYNCHRONIZED_ID     "synchronized"
DO_ID               "do"
GOTO_ID             "goto"
PRIVATE             "private"
THIS_ID             "this"
BREAK_ID            "break"
IMPLEMENTS_ID       "implements"
PROTECTED_ID        "protected"
THROW_ID            "throw"
BYTE_ID             "byte"
IMPORT_ID           "import"
THROWS_ID           "throws"
CASE_ID             "case"
ENUM_ID             "enum"
INSTANCEOF_ID       "instanceof"
TRANSIENT_ID        "transient"
CATCH_ID            "catch"
EXTENDS_ID          "extends"
SHORT_ID            "short"
TRY_ID              "try"
CHAR_ID             "char"
FINAL_ID            "final"
INTERFACE_ID        "interface"
FINALLY_ID          "finally"
LONG_ID             "long"
STRICTFP_ID         "strictfp"
VOLATILE_ID         "volatile"
CONST_ID            "const"
FLOAT_ID            "float"
NATIVE_ID           "native"
SUPER_ID            "super"
FOR_ID              "for"
NEW_ID              "new"

digit       [0-9]           
/* Number parts */
digits      {digit}([0-9_]*{digit})?
exponent    [eE][+-]?{digits}

/* NATURAL: 0 or sequence starting with non-zero digit, can have underscores, ends with digit */
natural     0|[1-9]([0-9_]*[0-9])?

/* it needs to be down here, otherwise, some of the reserved words or even other ones might get mistaken as an identifier due to precendence in rule position */
identifier  [_$a-zA-Z][_$a-zA-Z0-9]*

%x MLINE_COMMENT STRLITERAL SLINE_COMMENT

%%

    /* yytext is a pointer to a string */

    /* RESERVED tokens - these must come first */
{INCREMENT}         { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{DECREMENT}         { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{NULL_LIT}          { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{INTEGER_ID}        { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{SYSTEM_ID}         { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{ABSTRACT_ID}       { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{CONTINUE_ID}       { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{SWITCH_ID}         { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{ASSERT_ID}         { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{DEFAULT_ID}        { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{PACKAGE_ID}        { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{SYNCHRONIZED_ID}   { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{DO_ID}             { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{GOTO_ID}           { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{PRIVATE}           { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{THIS_ID}           { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{BREAK_ID}          { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{IMPLEMENTS_ID}     { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{PROTECTED_ID}      { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{THROW_ID}          { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{BYTE_ID}           { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{IMPORT_ID}         { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{THROWS_ID}         { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{CASE_ID}           { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{ENUM_ID}           { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{INSTANCEOF_ID}     { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{TRANSIENT_ID}      { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{CATCH_ID}          { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{EXTENDS_ID}        { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{SHORT_ID}          { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{TRY_ID}            { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{CHAR_ID}           { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{FINAL_ID}          { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{INTERFACE_ID}      { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{FINALLY_ID}        { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{LONG_ID}           { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{STRICTFP_ID}       { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{VOLATILE_ID}       { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{CONST_ID}          { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{FLOAT_ID}          { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{NATIVE_ID}         { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{SUPER_ID}          { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{FOR_ID}            { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }
{NEW_ID}            { if (print_tokens) printf("RESERVED(%s)\n", yytext); SAVE_TOKEN_INFO();  return RESERVED; }

    /* Multi-character operators */
{AND}               { if (print_tokens) printf("AND\n"); SAVE_TOKEN_INFO(); return AND; }
{OR}                { if (print_tokens) printf("OR\n"); SAVE_TOKEN_INFO(); return OR; }
{EQ}                { if (print_tokens) printf("EQ\n"); SAVE_TOKEN_INFO(); return EQ; }
{NE}                { if (print_tokens) printf("NE\n"); SAVE_TOKEN_INFO(); return NE; }
{GE}                { if (print_tokens) printf("GE\n"); SAVE_TOKEN_INFO(); return GE; }
{LE}                { if (print_tokens) printf("LE\n"); SAVE_TOKEN_INFO(); return LE; }
{ARROW}             { if (print_tokens) printf("ARROW\n"); SAVE_TOKEN_INFO(); return ARROW; }
{LSHIFT}            { if (print_tokens) printf("LSHIFT\n"); SAVE_TOKEN_INFO(); return LSHIFT; }
{RSHIFT}            { if (print_tokens) printf("RSHIFT\n"); SAVE_TOKEN_INFO(); return RSHIFT; }
{XOR}               { if (print_tokens) printf("XOR\n"); SAVE_TOKEN_INFO(); return XOR; }

    /* Single-character operators - STAR absolutely first */
{STAR}              { if (print_tokens) printf("STAR\n"); SAVE_TOKEN_INFO(); return STAR; }
{DIV}               { if (print_tokens) printf("DIV\n"); SAVE_TOKEN_INFO(); return DIV; }
{MOD}               { if (print_tokens) printf("MOD\n"); SAVE_TOKEN_INFO(); return MOD; }
{PLUS}              { if (print_tokens) printf("PLUS\n"); SAVE_TOKEN_INFO(); return PLUS; }
{MINUS}             { if (print_tokens) printf("MINUS\n"); SAVE_TOKEN_INFO(); return MINUS; }
{ASSIGN}            { if (print_tokens) printf("ASSIGN\n"); SAVE_TOKEN_INFO(); return ASSIGN; }
{COMMA}             { if (print_tokens) printf("COMMA\n"); SAVE_TOKEN_INFO(); return COMMA; }
{LT}                { if (print_tokens) printf("LT\n"); SAVE_TOKEN_INFO(); return LT; }
{GT}                { if (print_tokens) printf("GT\n"); SAVE_TOKEN_INFO(); return GT; }
{NOT}               { if (print_tokens) printf("NOT\n"); SAVE_TOKEN_INFO(); return NOT; }
{LPAR}              { if (print_tokens) printf("LPAR\n"); SAVE_TOKEN_INFO(); return LPAR; }
{RPAR}              { if (print_tokens) printf("RPAR\n"); SAVE_TOKEN_INFO(); return RPAR; }
{LBRACE}            { if (print_tokens) printf("LBRACE\n"); SAVE_TOKEN_INFO(); return LBRACE; }
{RBRACE}            { if (print_tokens) printf("RBRACE\n"); SAVE_TOKEN_INFO(); return RBRACE; }
{LSQ}               { if (print_tokens) printf("LSQ\n"); SAVE_TOKEN_INFO(); return LSQ; }
{RSQ}               { if (print_tokens) printf("RSQ\n"); SAVE_TOKEN_INFO(); return RSQ; }
{SEMICOLON}         { if (print_tokens) printf("SEMICOLON\n"); SAVE_TOKEN_INFO(); return SEMICOLON; }

    /* Keywords that ARE used in Juc */
{BOOLLIT}           { if (print_tokens) printf("BOOLLIT(%s)\n",yytext); if (!lex_only) yylval.str = strdup(yytext); SAVE_TOKEN_INFO(); return BOOLLIT; }
{BOOL}              { if (print_tokens) printf("BOOL\n"); SAVE_TOKEN_INFO(); return BOOL; }
{CLASS}             { if (print_tokens) printf("CLASS\n"); SAVE_TOKEN_INFO(); return CLASS; }
{DOTLENGTH}         { if (print_tokens) printf("DOTLENGTH\n"); SAVE_TOKEN_INFO(); return DOTLENGTH; }
{DOUBLE}            { if (print_tokens) printf("DOUBLE\n"); SAVE_TOKEN_INFO(); return DOUBLE; }
{ELSE}              { if (print_tokens) printf("ELSE\n"); SAVE_TOKEN_INFO(); return ELSE; }
{IF}                { if (print_tokens) printf("IF\n"); SAVE_TOKEN_INFO(); return IF; }
{INT}               { if (print_tokens) printf("INT\n"); SAVE_TOKEN_INFO(); return INT; }
{PRINT}             { if (print_tokens) printf("PRINT\n"); SAVE_TOKEN_INFO(); return PRINT; }
{PARSEINT}          { if (print_tokens) printf("PARSEINT\n"); SAVE_TOKEN_INFO(); return PARSEINT; }
{PUBLIC}            { if (print_tokens) printf("PUBLIC\n"); SAVE_TOKEN_INFO(); return PUBLIC; }
{RETURN}            { if (print_tokens) printf("RETURN\n"); SAVE_TOKEN_INFO(); return RETURN; }
{STATIC}            { if (print_tokens) printf("STATIC\n"); SAVE_TOKEN_INFO(); return STATIC; }
{STRING}            { if (print_tokens) printf("STRING\n"); SAVE_TOKEN_INFO(); return STRING; }
{VOID}              { if (print_tokens) printf("VOID\n"); SAVE_TOKEN_INFO(); return VOID; }
{WHILE}             { if (print_tokens) printf("WHILE\n"); SAVE_TOKEN_INFO(); return WHILE; }

    /* Comment patterns */
"/*"                { 
    BEGIN(MLINE_COMMENT); 
    comment_start_line = line;
    comment_start_column = column - yyleng;
}
"//"                { BEGIN(SLINE_COMMENT); }

    /* treating general stuff */

    /* DECIMAL patterns - ordered from most specific to least specific */
{digits}"."{digits}{exponent}          { if (print_tokens) printf("DECIMAL(%s)\n",yytext); if (!lex_only) yylval.str = strdup(yytext); SAVE_TOKEN_INFO(); return DECIMAL; }
{digits}"."{digits}                    { if (print_tokens) printf("DECIMAL(%s)\n",yytext); if (!lex_only) yylval.str = strdup(yytext); SAVE_TOKEN_INFO(); return DECIMAL; }
{digits}"."{exponent}                  { if (print_tokens) printf("DECIMAL(%s)\n",yytext); if (!lex_only) yylval.str = strdup(yytext); SAVE_TOKEN_INFO(); return DECIMAL; }
{digits}"."                            { if (print_tokens) printf("DECIMAL(%s)\n",yytext); if (!lex_only) yylval.str = strdup(yytext); SAVE_TOKEN_INFO(); return DECIMAL; }
"."{digits}{exponent}                  { if (print_tokens) printf("DECIMAL(%s)\n",yytext); if (!lex_only) yylval.str = strdup(yytext); SAVE_TOKEN_INFO(); return DECIMAL; }
"."{digits}                            { if (print_tokens) printf("DECIMAL(%s)\n",yytext); if (!lex_only) yylval.str = strdup(yytext); SAVE_TOKEN_INFO(); return DECIMAL; }
{digits}{exponent}                     { if (print_tokens) printf("DECIMAL(%s)\n",yytext); if (!lex_only) yylval.str = strdup(yytext); SAVE_TOKEN_INFO(); return DECIMAL; }

    /* Then NATURAL */
{natural}                          { if (print_tokens) printf("NATURAL(%s)\n",yytext); if (!lex_only) yylval.str = strdup(yytext); SAVE_TOKEN_INFO(); return NATURAL; }

{identifier}                       { if (print_tokens) printf("IDENTIFIER(%s)\n",yytext); if (!lex_only) yylval.str = strdup(yytext); SAVE_TOKEN_INFO(); return IDENTIFIER; }

\n|\r\n|\r                 { 
    line++;
    column = 1;
}

[ \t\f]                    { 
    /* No printing - just consume whitespace */
}

    /* treating strings */

"\""                       { 
    BEGIN(STRLITERAL); 
    init_string_buffer(); 
    string_start_line = line;
    string_start_column = column - yyleng;
}

    /* Valid escape sequences - store as backslash + character */
<STRLITERAL>\\[ntrf\\\"]      {
    ensure_string_buffer_capacity(2);
    string_buffer[string_buffer_index++] = '\\';
    string_buffer[string_buffer_index++] = yytext[1];
}

    /* Invalid escape sequences - any other backslash combination */
<STRLITERAL>\\|\\[^ntrf\\\n\r\"]   { 
    printf("Line %d, col %d: invalid escape sequence (%s)\n", line, column - yyleng, yytext);
    string_has_invalid_escape = 1;
    /* Don't add anything to buffer for invalid escapes - but continue the string */
}

    /* Unterminated string - newline without closing quote */
<STRLITERAL>\r\n|\n|\r                {
    printf("Line %d, col %d: unterminated string literal\n", 
           string_start_line, string_start_column);
    free_string_buffer();
    BEGIN(INITIAL);
    line++;
    column = 1;
}

    /* Normal string characters - store as-is */
<STRLITERAL>[^\\\n\r\"]+      {
    ensure_string_buffer_capacity(yyleng);
    memcpy(string_buffer + string_buffer_index, yytext, yyleng);
    string_buffer_index += yyleng; 
}

    /* End of string */
<STRLITERAL>"\"" { 
    if (string_has_invalid_escape) {
        /* Invalid string: discard, no token returned */
        free_string_buffer();
        BEGIN(INITIAL);
    } else {
        /* Valid string: build the literal text for error reporting */
        ensure_string_buffer_capacity(1);
        string_buffer[string_buffer_index] = '\0';
        if (print_tokens) printf("STRLIT(\"%s\")\n", string_buffer);
        if (!lex_only) yylval.str = strdup(string_buffer);
        
        /* Save full literal (including quotes) and its start position */
        int len = strlen(string_buffer) + 3;   // +2 quotes + null
        char full_literal[len];
        snprintf(full_literal, len, "\"%s\"", string_buffer);
        strncpy(yyerror_text, full_literal, sizeof(yyerror_text)-1);
        yyerror_text[sizeof(yyerror_text)-1] = '\0';
        yyerror_line   = string_start_line;
        yyerror_column = string_start_column;
        
        free_string_buffer();
        BEGIN(INITIAL);
        return STRLIT;
    }
}

    /* EOF in string */
<STRLITERAL><<EOF>> {
    printf("Line %d, col %d: unterminated string literal\n", 
           string_start_line, string_start_column);
    yyerror_text[0] = '\0';
    yyerror_line = line;
    yyerror_column = column;
    BEGIN(INITIAL);
    return 0;
}


    /* treating comments - continuation */

<MLINE_COMMENT>"*/"              { BEGIN(INITIAL); }

<MLINE_COMMENT>\n|\r\n|\r        { 
    line++; 
    column = 1; 
}

<MLINE_COMMENT>.                 { }

<MLINE_COMMENT><<EOF>> { 
    printf("Line %d, col %d: unterminated comment\n", 
           comment_start_line, comment_start_column);
    yyerror_text[0] = '\0';
    yyerror_line = line;
    yyerror_column = column;
    BEGIN(INITIAL);
    return 0;
}

<SLINE_COMMENT>\n|\r\n|\r        { 
    line++; 
    column = 1; 
    BEGIN(INITIAL); 
}

<SLINE_COMMENT>.                 { }

<SLINE_COMMENT><<EOF>> { 
    yyerror_text[0] = '\0';
    yyerror_line = line;
    yyerror_column = column;
    BEGIN(INITIAL);
    return 0;
}

    /* Default EOF rule (when not in a comment or string) */
<<EOF>> {
    yyerror_text[0] = '\0';
    yyerror_line = line;
    yyerror_column = column;
    return 0;
}

    /* illegal characters - everything else */
.                          { 
    printf("Line %d, col %d: illegal character (%s)\n", 
           line, column - yyleng, yytext); 
}

%%

int yywrap() {
    return 1;
}