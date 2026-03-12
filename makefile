all: lex.yy.c meta1_lexer


lex.yy.c: meta1_lexer.l 
	lex meta1_lexer.l

meta1_lexer: lex.yy.c
	gcc lex.yy.c -o meta1_lexer


