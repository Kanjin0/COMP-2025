#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

const char *category_name[] = {
    "Program",
    "MethodDecl", "FieldDecl",
    "MethodHeader", "MethodParams", "MethodBody",
    "ParamDecl", "VarDecl", "Block",
    "If", "While", "Return", "Print",
    "Call", "Assign", "ParseArgs",
    "Add", "Sub", "Mul", "Div", "Mod",
    "And", "Or", "Xor", "Lshift", "Rshift",
    "Eq", "Ne", "Lt", "Le", "Gt", "Ge",
    "Not", "Plus", "Minus",
    "Length",
    "Identifier", "Natural", "Decimal",
    "BoolLit", "StrLit",
    "Int", "Double", "Bool", "Void", "StringArray",
    "NullCategory"
};

static const char *category_symbol(enum category cat) {
    switch (cat) {
        case Add:       return "+";
        case Sub:       return "-";
        case Mul:       return "*";
        case Div:       return "/";
        case Mod:       return "%";
        case And:       return "&&";
        case Or:        return "||";
        case Xor:       return "^";
        case Lshift:    return "<<";
        case Rshift:    return ">>";
        case Eq:        return "==";
        case Ne:        return "!=";
        case Lt:        return "<";
        case Le:        return "<=";
        case Gt:        return ">";
        case Ge:        return ">=";
        case Not:       return "!";
        case Plus:      return "+";
        case Minus:     return "-";
        default:        return NULL;   /* use category_name for others */
    }
}

const char *type_name(enum type t) {
    switch (t) {
        case type_int:          return "int";
        case type_double:       return "double";
        case type_boolean:      return "boolean";
        case type_void:         return "void";
        case type_string_array: return "String[]";
        case type_string:       return "String";
        case type_undef:        return "undef";
        default:                return "???";
    }
}

ast_node* create_node(enum category cat, const char *value, int line, int column) {
    ast_node *node = malloc(sizeof(ast_node));
    node->category = cat;
    node->value    = value ? strdup(value) : NULL;
    node->line     = line;
    node->column   = column;
    node->type     = type_undef;
    node->type_set = 0;                /* not explicitly set yet */
    node->annotated_str = NULL;
    node->is_duplicate = 0;
    node->child    = NULL;
    node->sibling  = NULL;
    return node;
}

/* ---------- add child ---------- */
void add_child(ast_node *parent, ast_node *child) {
    if (!parent || !child) return;
    if (!parent->child) {
        parent->child = child;
    } else {
        ast_node *sibling = parent->child;
        while (sibling->sibling) sibling = sibling->sibling;
        sibling->sibling = child;
    }
}

/* ---------- add sibling ---------- */
void add_sibling(ast_node *node, ast_node *sibling) {
    if (!node || !sibling) return;
    ast_node *cur = node;
    while (cur->sibling) cur = cur->sibling;
    cur->sibling = sibling;
}

/* ---------- print un‑annotated AST ---------- */
void print_ast(ast_node *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("..");
    if (node->value) {
        if (node->category == StrLit)
            printf("%s(\"%s\")\n", category_name[node->category], node->value);
        else
            printf("%s(%s)\n", category_name[node->category], node->value);
    } else {
        printf("%s\n", category_name[node->category]);
    }
    print_ast(node->child, depth + 1);
    print_ast(node->sibling, depth);
}

/* returns true if category represents an expression node */
static int is_expression(enum category cat) {
    switch (cat) {
        case Identifier: case Natural: case Decimal: case BoolLit: case StrLit:
        case Add: case Sub: case Mul: case Div: case Mod:
        case And: case Or: case Xor: case Lshift: case Rshift:
        case Eq: case Ne: case Lt: case Le: case Gt: case Ge:
        case Not: case Plus: case Minus:
        case Length: case Call: case Assign: case ParseArgs:
            return 1;
        default:
            return 0;
    }
}

void print_ast_annotated(ast_node *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("..");
    if (node->value) {
        if (node->category == StrLit)
            printf("%s(\"%s\")", category_name[node->category], node->value);
        else
            printf("%s(%s)", category_name[node->category], node->value);
    } else {
        printf("%s", category_name[node->category]);
    }

    /* annotation only if explicitly set or annotated_str is present */
    if (node->annotated_str) {
        printf(" - %s", node->annotated_str);
    } else if (node->type_set) {
        printf(" - %s", type_name(node->type));
    }
    printf("\n");

    print_ast_annotated(node->child, depth + 1);
    print_ast_annotated(node->sibling, depth);
}

void free_ast(ast_node *node) {
    if (!node) return;
    free_ast(node->child);
    free_ast(node->sibling);
    free(node->value);
    free(node->annotated_str);
    free(node);
}