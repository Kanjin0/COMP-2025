#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ast_node* create_node(const char *type, const char *value) {
    ast_node *node = (ast_node*)malloc(sizeof(ast_node));
    node->type = type ? strdup(type) : NULL;
    node->value = value ? strdup(value) : NULL;
    node->child = NULL;
    node->sibling = NULL;
    return node;
}

void add_child(ast_node *parent, ast_node *child) {
    if (parent == NULL || child == NULL) return;
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        ast_node *sibling = parent->child;
        while (sibling->sibling != NULL) {
            sibling = sibling->sibling;
        }
        sibling->sibling = child;
    }
}

void add_sibling(ast_node *node, ast_node *sibling) {
    if (node == NULL || sibling == NULL) return;
    ast_node *current = node;
    while (current->sibling != NULL) {
        current = current->sibling;
    }
    current->sibling = sibling;
}

void print_ast(ast_node *node, int depth) {
    if (node == NULL) return;
    
    // Add dots corresponding to tree depth
    for (int i = 0; i < depth; i++) {
        printf("..");
    }
    
    // Print value dynamically
    if (node->value != NULL) {
        if(strcmp(node->type,"StrLit") == 0)  printf("%s(\"%s\")\n", node->type, node->value);
        else printf("%s(%s)\n", node->type, node->value);
    } else {
        printf("%s\n", node->type);
    }
    
    // Recurse down and right
    print_ast(node->child, depth + 1);
    print_ast(node->sibling, depth);
}

void free_ast(ast_node *node) {
    if (node == NULL) return;
    free_ast(node->child);
    free_ast(node->sibling);
    
    if (node->type) free(node->type);
    if (node->value) free(node->value);
    free(node);
}
