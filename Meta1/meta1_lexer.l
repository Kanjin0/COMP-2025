%{
    /* place here any C variables and definitions */

    #include <string.h>
    #include <stdlib.h>

    int line = 1;
    int column = 1;

    char* string_buffer = NULL;
    int string_buffer_size = 0;
    int string_buffer_index = 0;

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
    }

    void free_string_buffer(){
        free(string_buffer);
        string_buffer = NULL;
        string_buffer_index = 0;
        string_buffer_size = 0;
    }

%}

            /* por alguma razão, usar [aA-zZ] dá erro e, provavelmente, inclui mais caracteres do que os que devia no termo alpha
             (provavel que faça incluir [ e ], fazendo String[] ser detetado como identifier ao invés de RSQ STRING LSQ)*/
digit       [0-9]
alpha       [a-zA-Z]            
number      0|[1-9]([0-9_]*{digit})?
exponent    [eE][+-]?{number}

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

whitespace [ \t\n]


%X COMMENT STRLIT

%%

    /* yytext is a pointer to a string, you stupid fuck */

    /* treating reserved keywords/symbols */

{BOOLLIT}           { printf("BOOLLIT(%s)\n",yytext); }
{AND}               { printf("AND\n"); }
{ASSIGN}            { printf("ASSIGN\n"); }
{STAR}              { printf("STAR\n"); }
{COMMA}             { printf("COMMA\n"); }
{DIV}               { printf("DIV\n"); }
{EQ}                { printf("EQ\n"); }
{GE}                { printf("GE\n"); }
{GT}                { printf("GT\n"); }
{LBRACE}            { printf("LBRACE\n"); }
{LE}                { printf("LE\n"); }
{LPAR}              { printf("LPAR\n"); }
{LSQ}               { printf("LSQ\n"); }
{LT}                { printf("LT\n"); }
{MINUS}             { printf("MINUS\n"); }
{MOD}               { printf("MOD\n"); }
{NE}                { printf("NE\n"); }
{NOT}               { printf("NOT\n"); }
{OR}                { printf("OR\n"); }
{PLUS}              { printf("PLUS\n"); }
{RBRACE}            { printf("RBRACE\n"); }
{RPAR}              { printf("RPAR\n"); }
{RSQ}               { printf("RSQ\n"); }
{SEMICOLON}         { printf("SEMICOLON\n"); }
{ARROW}             { printf("ARROW\n"); }
{LSHIFT}            { printf("LSHIFT\n"); }
{RSHIFT}            { printf("RSHIFT\n"); }
{XOR}               { printf("XOR\n"); }
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


    /* treating general stuff */

{alpha}({alpha}|{digit}|"_"|"$")*                                                           { printf("INDENTIFIER(%s)\n",yytext); }
{number}                                                                                    { printf("NATURAL(%s)\n",yytext); }
({number}"."({number})?|"."{number})({exponent})?|{number}{exponent}                        { printf("DECIMAL(%s)\n",yytext); }


{whitespace}               { if(strcmp(yytext,"\n") == 0){ line++; column = 1;} }


    /* treating strings */

"\""                       { BEGIN(STRLIT); init_string_buffer(); }

<STRLIT>\\[ntrf\\\"]      {
                            ensure_string_buffer_capacity(2);
                            switch(yytext[1]) /* verificar com o stor se é para dar print da string com o \n a ser interpretado ou só com ele escrito */
                                {
                                case 'n' : string_buffer[string_buffer_index++] = '\\'; string_buffer[string_buffer_index++] = 'n' ; break;
                                case 't' : string_buffer[string_buffer_index++] = '\\'; string_buffer[string_buffer_index++] = 't' ; break;
                                case 'r' : string_buffer[string_buffer_index++] = '\\'; string_buffer[string_buffer_index++] = 'r' ; break;
                                case 'f' : string_buffer[string_buffer_index++] = '\\'; string_buffer[string_buffer_index++] = 'f' ; break;
                                case '\\': string_buffer[string_buffer_index++] = '\\'; string_buffer[string_buffer_index++] = '\\'; break;
                                case '"' : string_buffer[string_buffer_index++] = '"' ; break;
                                }
                          }

<STRLIT>\\[^ntrf\\\"]     { printf("Line %d, column %d: invalid escape sequence (//%c)\n",line,column - yyleng + 1,yytext[1]);
                            ensure_string_buffer_capacity(1);
                            string_buffer[string_buffer_index++] = yytext[1]; /* add invalid escape sequence char so the lexer continues running */ 
                          }

<STRLIT>[^\\\n\"]+        { /* normal string words */ /* "everything character that's not a \, \n or " (of those that aren't already triggering one of the rules above) */ 
                            ensure_string_buffer_capacity(yyleng);
                            memcpy(string_buffer + string_buffer_index, yytext, yyleng);
                            string_buffer_index += yyleng; 
                          }

<STRLIT>"\""              { 
                            ensure_string_buffer_capacity(1);
                            string_buffer[string_buffer_index++] = '\0'; /* found the end of the string, print it all */
                            printf("STRLIT(\"%s\")\n",string_buffer); 
                            free_string_buffer();
                            BEGIN(INITIAL); 
                          }

<STRLIT>\n                { /* unterminated string */
                            printf("Line %d, column %d: unterminated string\n",line,column - yyleng + 1);
                            line++; column = 1;
                            free_string_buffer();
                            BEGIN(INITIAL);
                            }
<STRLIT><<EOF>>           { /* unterminated string encountered EOF */
                             printf("Line %d, column %d: unterminated string encounter EOF\n",line,column - yyleng + 1);
                             free_string_buffer();
                             BEGIN(INITIAL);
                             yyterminate();
                            }



    /* treating comments */

"/*"                       { BEGIN(COMMENT); }
<COMMENT>"*/"              { BEGIN(INITIAL); }
<COMMENT>"\n"              { column = 1; line++; }
<COMMENT>.                 { ; }

    /* treating errors */

.                          { printf("Line %d, column %d: unrecognized character (%s)\n",line,column - yyleng + 1,yytext); }
%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    free_string_buffer(); /* Clean up any remaining memory */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
