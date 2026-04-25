all: meta2_parser

meta2_parser: lex.yy.c y.tab.c ast.c
	cc -g -Wall -Wno-unused-function lex.yy.c y.tab.c ast.c -o meta2_parser

y.tab.c y.tab.h: meta2_parser.y
	yacc -d meta2_parser.y

lex.yy.c: meta2_lexer.l y.tab.h
	lex meta2_lexer.l

clean:
	rm -f lex.yy.c y.tab.c y.tab.h meta2_parser
