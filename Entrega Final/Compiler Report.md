
# Relatório do Projeto – Compilador Juc

## Gramática Reescrita

Após concluída e verificada a performance do analisador lexical (lexer), a gramática original, em notação EBNF, foi transformada para uma forma compatível com análise LR(1) do YACC. As principais transformações foram
- Eliminação de repetições e opcionais – as construções `{…}` e `[…]` foram substituídas por regras auxiliares recursivas (ex. `FormalParamsList`, `MethodBodyContent`, `StatementList`, `ExprList`), garantindo que a gramática se mantém LR(1) sem conflitos e permitindo a construção explícita da AST nas ações semânticas.
- Resolução de ambiguidades – as precedências e associatividades dos operadores foram declaradas através das directivas `%left`, `%right` e `%nonassoc`. Por exemplo, `%left PLUS MINUS`, `%left STAR DIV MOD`, `%right ASSIGN`, e `%nonassoc IFX` para o `dangling‑else`. Para operadores unários, utilizou‑se `%right UMINUS UPLUS`. Adicionalmente, dividiu‑se as expressões em `Expr` e `ExprNoAssign`, evitando que uma atribuição dentro de uma expressão gerasse conflitos com os operadores de precedência mais baixa.
- Regras de erro – foram inseridas produções de recuperação (`FieldDecl → error SEMICOLON`, `Statement → error SEMICOLON`, `ParseArgs → PARSEINT LPAR error RPAR`, `MethodInvocation → IDENTIFIER LPAR error RPAR`, `Expr → LPAR error RPAR`) de modo a que o parser sincronize após um erro, evitando a propagação excessiva de mensagens.
- Construção da AST – cada produção reduzida invoca funções que criam nós (`create_node`) e os ligam (`add_child``add_sibling`). Nós `Block` só são criados quando existe mais do que uma instrução; para `if` sem `else`, é inserido um bloco vazio fantasma, mantendo a estrutura de três filhos exigida pela AST. As listas de declarações (`FieldDecl`, `VarDecl`) são desdobradas em nós individuais através de ciclos nas ações semânticas.
A gramática resultante reconhece exatamente a linguagem Juc, incluindo expressões com atribuições encadeadas e invocações de métodos, respeitando a semântica do Java providenciada em conjunto com o enunciado do projeto.

## Algoritmos e Estruturas de Dados

Muito do conteúdo desta secção baseia‑se nas soluções propostas nos tutoriais das aulas PL, com adaptações decorrentes das opções de implementação do grupo.


### Árvore Sintática Abstrata (AST) e Tabelas de Símbolos

A AST é formada por nós `ast_node` com categoria, valor, lista de filhos (em lista ligada) e campos para o tipo inferido (`type`, `type_set`). Inclui ainda `annotated_str` para assinaturas de métodos e `is_duplicate` para marcar métodos repetidos e ignorá‑los na verificação de tipos. A construção ocorre durante a análise sintática, criando‑se os nós e ligando‑os recursivamente. A impressão é feita percorrendo a árvore com indentação proporcional à profundidade.

As tabelas de símbolos são listas ligadas de entradas (`symbol`) que registam nome, tipo, parâmetros (para métodos) e indicação de parâmetro formal. Existe uma tabela global (classe) e uma tabela local por método, criada em `build_tables`. A função percorre a AST ao encontrar `MethodDecl`, insere o método na tabela global (verificando duplicados por assinatura) e constrói a tabela local com `return`, os parâmetros formais e, mais tarde, as variáveis locais. `FieldDecl` insere diretamente na tabela global. Um campo e um método podem coexistir com o mesmo nome; na resolução, uma variávelfield tem prioridade sobre um método.

### Verificação de Tipos e Anotação

A fase `check_types` percorre os métodos não duplicados e invoca `check_stmt` para cada instrução. Esta insere as variáveis na tabela local e chama `check_expr` para as expressões. A tipagem é bottom‑up, com `check_expr` a delegar em `check_expr_internal` para literais inteiros, permitindo distinguir o valor máximo consoante o literal esteja ou não num contexto de menos unário (aceitando assim `-2147483648`).

As regras de tipos seguem as de Java literais inteiros e decimais recebem `int` e `double`, respetivamente, com detecção de overflowunderflow. Identificadores procuram primeiro no escopo local e depois global; métodos sem campo homónimo geram erro. Operadores unários (`-`, `+`, `!`) exigem os tipos numéricos ou `boolean`, sem ignorar operandos `undef`. Operadores binários aritméticos e shifts aplicam promoção para `double` quando necessário; `&&` e `` requerem `boolean`; comparadores aceitam tipos numéricos, e `==``!=` também `boolean`.

Chamadas a métodos (`check_call`) implementam a seleção primeiro correspondência exata de tipos, depois compatível (`int` para `double`); ambiguidade gera erro, senão “Cannot find symbol”. Em caso de erro, o nó é anotado com `undef` para evitar falsos positivos subsequentes. Atribuições verificam a compatibilidade direta ou `int` → `double`, proibindo `String[]`. `ParseArgs` e `.length` devolvem `int` e validam os operandos como `String[]` (e índice `int`).

Sempre que um erro é detectado, a análise continua, anotando‑se o nó com `undef`. Por fim, AST anotada é finalmente impressa se solicitado.