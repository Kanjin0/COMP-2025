#ifndef AST_H
#define AST_H
typedef struct ast_node {
    char *type;
    char *value;
    struct ast_node *child;
    struct ast_node *sibling;
} ast_node;
ast_node* create_node(const char *type, const char *value);
void add_child(ast_node *parent, ast_node *child);
void add_sibling(ast_node *node, ast_node *sibling);
void print_ast(ast_node *node, int depth);
void free_ast(ast_node *node);
#endif