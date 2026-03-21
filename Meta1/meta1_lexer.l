%{
    /* place here any C variables and definitions */

    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>

    int line = 1;
    int column = 1;

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

    #define STRING_BUFFER_INITIAL_SIZE 64
    #define STRING_BUFFER_GROWTH_FACTOR 2
    #define YY_USER_ACTION column += yyleng;

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

    /* Helper function to print string with escape sequences */
    void print_escaped_string(char *str) {
        printf("STRLIT(\"");
        for (int i = 0; str[i] != '\0'; i++) {
            switch (str[i]) {
                case '\n': printf("\\n"); break;
                case '\t': printf("\\t"); break;
                case '\r': printf("\\r"); break;
                case '\f': printf("\\f"); break;
                case '\\': printf("\\\\"); break;
                case '"': printf("\\\""); break;
                default: printf("%c", str[i]); break;
            }
        }
        printf("\")\n");
    }

%}

digit       [0-9]           

/* NATURAL: 0 or sequence starting with non-zero digit, can have underscores, ends with digit */
natural     0|[1-9]([0-9_]*[0-9])?

/* Number parts */
digits      {digit}([0-9_]*{digit})?
exponent    [eE][+-]?{digits}

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

/* Only these five are RESERVED */
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

whitespace [ \t\n\r]

/* it needs to be down here, otherwise, some of the reserved words or even other ones might get mistaken as an identifier due to precendence in rule position */
identifier  [_$a-zA-Z][_$a-zA-Z0-9]*

%x MLINE_COMMENT STRLIT SLINE_COMMENT

%%

    /* yytext is a pointer to a string */

    /* RESERVED tokens - these must come first */
{INCREMENT}         { printf("RESERVED(%s)\n", yytext); }
{DECREMENT}         { printf("RESERVED(%s)\n", yytext); }
{NULL_LIT}          { printf("RESERVED(%s)\n", yytext); }
{INTEGER_ID}        { printf("RESERVED(%s)\n", yytext); }
{SYSTEM_ID}         { printf("RESERVED(%s)\n", yytext); }
{ABSTRACT_ID}       { printf("RESERVED(%s)\n", yytext); }
{CONTINUE_ID}       { printf("RESERVED(%s)\n", yytext); }
{SWITCH_ID}         { printf("RESERVED(%s)\n", yytext); }
{ASSERT_ID}         { printf("RESERVED(%s)\n", yytext); }
{DEFAULT_ID}        { printf("RESERVED(%s)\n", yytext); }
{PACKAGE_ID}        { printf("RESERVED(%s)\n", yytext); }
{SYNCHRONIZED_ID}   { printf("RESERVED(%s)\n", yytext); }
{DO_ID}             { printf("RESERVED(%s)\n", yytext); }
{GOTO_ID}           { printf("RESERVED(%s)\n", yytext); }
{PRIVATE}           { printf("RESERVED(%s)\n", yytext); }
{THIS_ID}           { printf("RESERVED(%s)\n", yytext); }
{BREAK_ID}          { printf("RESERVED(%s)\n", yytext); }
{IMPLEMENTS_ID}     { printf("RESERVED(%s)\n", yytext); }
{PROTECTED_ID}      { printf("RESERVED(%s)\n", yytext); }
{THROW_ID}          { printf("RESERVED(%s)\n", yytext); }
{BYTE_ID}           { printf("RESERVED(%s)\n", yytext); }
{IMPORT_ID}         { printf("RESERVED(%s)\n", yytext); }
{THROWS_ID}         { printf("RESERVED(%s)\n", yytext); }
{CASE_ID}           { printf("RESERVED(%s)\n", yytext); }
{ENUM_ID}           { printf("RESERVED(%s)\n", yytext); }
{INSTANCEOF_ID}     { printf("RESERVED(%s)\n", yytext); }
{TRANSIENT_ID}      { printf("RESERVED(%s)\n", yytext); }
{CATCH_ID}          { printf("RESERVED(%s)\n", yytext); }
{EXTENDS_ID}        { printf("RESERVED(%s)\n", yytext); }
{SHORT_ID}          { printf("RESERVED(%s)\n", yytext); }
{TRY_ID}            { printf("RESERVED(%s)\n", yytext); }
{CHAR_ID}           { printf("RESERVED(%s)\n", yytext); }
{FINAL_ID}          { printf("RESERVED(%s)\n", yytext); }
{INTERFACE_ID}      { printf("RESERVED(%s)\n", yytext); }
{FINALLY_ID}        { printf("RESERVED(%s)\n", yytext); }
{LONG_ID}           { printf("RESERVED(%s)\n", yytext); }
{STRICTFP_ID}       { printf("RESERVED(%s)\n", yytext); }
{VOLATILE_ID}       { printf("RESERVED(%s)\n", yytext); }
{CONST_ID}          { printf("RESERVED(%s)\n", yytext); }
{FLOAT_ID}          { printf("RESERVED(%s)\n", yytext); }
{NATIVE_ID}         { printf("RESERVED(%s)\n", yytext); }
{SUPER_ID}          { printf("RESERVED(%s)\n", yytext); }
{FOR_ID}            { printf("RESERVED(%s)\n", yytext); }
{NEW_ID}            { printf("RESERVED(%s)\n", yytext); }

    /* Multi-character operators */
{AND}               { printf("AND\n"); }
{OR}                { printf("OR\n"); }
{EQ}                { printf("EQ\n"); }
{NE}                { printf("NE\n"); }
{GE}                { printf("GE\n"); }
{LE}                { printf("LE\n"); }
{ARROW}             { printf("ARROW\n"); }
{LSHIFT}            { printf("LSHIFT\n"); }
{RSHIFT}            { printf("RSHIFT\n"); }
{XOR}               { printf("XOR\n"); }

    /* Single-character operators - STAR absolutely first */
{STAR}              { printf("STAR\n"); }
{DIV}               { printf("DIV\n"); }
{MOD}               { printf("MOD\n"); }
{PLUS}              { printf("PLUS\n"); }
{MINUS}             { printf("MINUS\n"); }
{ASSIGN}            { printf("ASSIGN\n"); }
{COMMA}             { printf("COMMA\n"); }
{LT}                { printf("LT\n"); }
{GT}                { printf("GT\n"); }
{NOT}               { printf("NOT\n"); }
{LPAR}              { printf("LPAR\n"); }
{RPAR}              { printf("RPAR\n"); }
{LBRACE}            { printf("LBRACE\n"); }
{RBRACE}            { printf("RBRACE\n"); }
{LSQ}               { printf("LSQ\n"); }
{RSQ}               { printf("RSQ\n"); }
{SEMICOLON}         { printf("SEMICOLON\n"); }

    /* Keywords */
{BOOLLIT}           { printf("BOOLLIT(%s)\n",yytext); }
{BOOL}              { printf("BOOL\n"); }
{CLASS}             { printf("CLASS\n"); }
{DOTLENGTH}         { printf("DOTLENGTH\n"); }
{DOUBLE}            { printf("DOUBLE\n"); }
{ELSE}              { printf("ELSE\n"); }
{IF}                { printf("IF\n"); }
{INT}               { printf("INT\n"); }
{PRINT}             { printf("PRINT\n"); }
{PARSEINT}          { printf("PARSEINT\n"); }
{PUBLIC}            { printf("PUBLIC\n"); }
{RETURN}            { printf("RETURN\n"); }
{STATIC}            { printf("STATIC\n"); }
{STRING}            { printf("STRING\n"); }
{VOID}              { printf("VOID\n"); }
{WHILE}             { printf("WHILE\n"); }

    /* Comment patterns */
"/*"                { 
    BEGIN(MLINE_COMMENT); 
    comment_start_line = line;
    comment_start_column = column - yyleng;
}
"//"                { BEGIN(SLINE_COMMENT); }

    /* treating general stuff */

    /* DECIMAL patterns - must come BEFORE natural */
    /* Format: integer part . fractional part exponent? */
{natural}"."{digits}{exponent}?       { printf("DECIMAL(%s)\n",yytext); }
    /* Format: integer part . exponent? (with optional fractional) */
{natural}"."{digits}?{exponent}?      { printf("DECIMAL(%s)\n",yytext); }
    /* Format: . fractional part exponent? */
"."{digits}{exponent}?                 { printf("DECIMAL(%s)\n",yytext); }
    /* Format: integer part exponent (no dot) */
{natural}{exponent}                   { printf("DECIMAL(%s)\n",yytext); }

    /* Then NATURAL */
{natural}                          { printf("NATURAL(%s)\n",yytext); }


    /* Then IDENTIFIER */
{identifier}                       { printf("IDENTIFIER(%s)\n",yytext); }

{whitespace} { 
    if (yytext[0] == '\n') { 
        line++; 
        column = 1;
    } else if (yytext[0] == '\r') {
        /* Handle carriage return */
        column = 1;
    } else if (yytext[0] == '\t') {
        column += 8 - ((column - 1) % 8);
    }
    /* Ignore other whitespace */
}


    /* treating strings */

"\""                       { 
    BEGIN(STRLIT); 
    init_string_buffer(); 
    string_start_line = line;
    string_start_column = column - yyleng;
}

    /* Valid escape sequences */
<STRLIT>\\[ntrf\\\"]      {
    ensure_string_buffer_capacity(1);
    switch(yytext[1]) 
    {
        case 'n' : string_buffer[string_buffer_index++] = '\n'; break;
        case 't' : string_buffer[string_buffer_index++] = '\t'; break;
        case 'r' : string_buffer[string_buffer_index++] = '\r'; break;
        case 'f' : string_buffer[string_buffer_index++] = '\f'; break;
        case '\\': string_buffer[string_buffer_index++] = '\\'; break;
        case '"' : string_buffer[string_buffer_index++] = '"'; break;
    }
}

    /* Backslash at end of line - line continuation */
<STRLIT>\\\n               {
    line++;
    column = 1;
    /* Don't add anything to buffer */
}

<STRLIT>\\\r\n             {
    line++;
    column = 1;
    /* Don't add anything to buffer */
}

<STRLIT>\\\r               {
    line++;
    column = 1;
    /* Don't add anything to buffer */
}

    /* Invalid escape sequences - any other backslash combination */
<STRLIT>\\[^ntrf\\\n\r\"]   { 
    printf("Line %d, col %d: invalid escape sequence (%s)\n",
           line, column - yyleng, yytext);
    string_has_invalid_escape = 1;
}

    /* Unterminated string - newline without backslash */
<STRLIT>\n                {
    printf("Line %d, col %d: unterminated string literal\n", 
           string_start_line, string_start_column);
    
    free_string_buffer();
    BEGIN(INITIAL);
    /* Let whitespace rule handle the newline */
}

    /* Normal string characters */
<STRLIT>[^\\\n\r\"]+      {
    ensure_string_buffer_capacity(yyleng);
    memcpy(string_buffer + string_buffer_index, yytext, yyleng);
    string_buffer_index += yyleng; 
}

    /* End of string */
<STRLIT>"\""              { 
    if (string_has_invalid_escape) {
        /* String had invalid escapes - discard it */
        free_string_buffer();
        BEGIN(INITIAL);
    } else {
        /* Valid string - print it */
        ensure_string_buffer_capacity(1);
        string_buffer[string_buffer_index] = '\0';
        print_escaped_string(string_buffer);
        free_string_buffer();
        BEGIN(INITIAL);
    }
}

    /* EOF in string */
<STRLIT><<EOF>>           {
    printf("Line %d, col %d: unterminated string literal\n", 
           string_start_line, string_start_column);
    free_string_buffer();
    BEGIN(INITIAL);
    yyterminate();
}


    /* treating comments - continuation */

<MLINE_COMMENT>"*/"              { BEGIN(INITIAL); }

<MLINE_COMMENT>\n|\r\n|\r        { 
    /* Handle all types of line endings */
    if (yytext[yyleng-1] == '\n' || yytext[0] == '\r') line++; 
    column = 1; 
}

<MLINE_COMMENT>.                 { /* ignore */ }

<MLINE_COMMENT><<EOF>>           { 
    printf("Line %d, col %d: unterminated comment\n", 
           comment_start_line, comment_start_column);
    BEGIN(INITIAL);
    yyterminate();
}

<SLINE_COMMENT>\n|\r\n|\r        { 
    if (yytext[yyleng-1] == '\n' || yytext[0] == '\r') line++; 
    column = 1; 
    BEGIN(INITIAL); 
}

<SLINE_COMMENT>.                 { /* ignore */ }

<SLINE_COMMENT><<EOF>>           { BEGIN(INITIAL); }


    /* illegal characters - everything else */

.                          { 
    printf("Line %d, col %d: illegal character (%s)\n", 
           line, column - yyleng, yytext); 
}

%%

extern int yylex();
int main() {
    yylex();
    free_string_buffer();
    return 0;
}

int yywrap() {
    return 1;
}