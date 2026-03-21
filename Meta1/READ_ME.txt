No terminal:

make (compila tudo o que estiver salvo no ficheiro .l)

bash test.sh ./meta1_lexer (para realizar os testes) (caso apareça como sem permissões, usar um chmod no test.sh deve resolver)

para ver as diferenças entre os resultados dos testes que estão incorretos, só copiar o comando entre aspas que eles disponibilizam e usar no terminal

Caso não estejam (por alguma razão), os ficheiros .out, .out_temp (do folder java) e o ficheiro meta1_lexer.l devem estar todos com end of line sequence
colocada em LF (no VSCode, troca-se isto no canto inferior direito, onde devem aparecer as letras CRLF entre o tipo de encoding e o language mode 
(neste caso deve aparecer algo como UTF-8 CRLF ou LF Lex/Flex)(Caso estejam, trocar CRLF para LF))