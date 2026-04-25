all: meta3_parser

meta3_parser: lex.yy.c y.tab.c ast.c semantics.c
	cc -g -Wall -Wno-unused-function lex.yy.c y.tab.c ast.c semantics.c -o meta3_parser

y.tab.c y.tab.h: meta3_parser.y
	yacc -d meta3_parser.y

lex.yy.c: meta3_lexer.l y.tab.h
	lex meta3_lexer.l

clean:
	rm -f lex.yy.c y.tab.c y.tab.h meta3_parser
