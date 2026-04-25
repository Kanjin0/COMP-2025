#ifndef SEMANTICS_H
#define SEMANTICS_H

#include "ast.h"

/* ---------- Symbol entry ---------- */
typedef struct symbol {
    char *name;
    enum type type;                /* return / variable type */
    enum type *param_types;        /* NULL for variables */
    int param_count;               /* -1 if not a method */
    int is_param;                  /* 1 = formal parameter */
    int line, col;
    struct symbol *next;
} symbol;

/* ---------- Symbol table ---------- */
typedef struct symbol_table {
    char *name;                    /* e.g. "Class Factorial" or "Method factorial(int)" */
    symbol *head;
    struct symbol_table *next;
} symbol_table;

/* ---------- Public API ---------- */
symbol_table *create_table(const char *name);
symbol *insert_symbol(symbol_table *tbl, const char *name, enum type type,
                       enum type *param_types, int param_count, int is_param,
                       int line, int col);
symbol *lookup_local(symbol_table *tbl, const char *name);
symbol *lookup_global(symbol_table *global_tbl, symbol_table *local_tbl, const char *name);

void build_tables(ast_node *root);
void check_types(ast_node *root);
void print_tables(void);

extern symbol_table *global_table;
extern symbol_table *tables_head;
extern int semantic_errors;

#endif