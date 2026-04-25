#ifndef AST_H
#define AST_H

enum category {
    Program,
    MethodDecl, FieldDecl,
    MethodHeader, MethodParams, MethodBody,
    ParamDecl, VarDecl, Block,
    If, While, Return, Print,
    Call, Assign, ParseArgs,
    Add, Sub, Mul, Div, Mod,
    And, Or, Xor, Lshift, Rshift,
    Eq, Ne, Lt, Le, Gt, Ge,
    Not, Plus, Minus,
    Length,
    Identifier, Natural, Decimal,
    BoolLit, StrLit,
    Int, Double, Bool, Void, StringArray,
    NullCategory
};

enum type {
    type_int,
    type_double,
    type_boolean,
    type_void,
    type_string_array,
    type_string,
    type_undef
};

typedef struct ast_node {
    enum category category;
    char *value;
    int line;
    int column;
    enum type type;                /* inferred type (for expressions) */
    int type_set;                  /* 1 if type was explicitly set by check_expr */
    int is_duplicate;               /* 1 = duplicate method, skip body checking */
    char *annotated_str;           /* optional string annotation (method signatures) */
    struct ast_node *child;
    struct ast_node *sibling;
} ast_node;

ast_node* create_node(enum category cat, const char *value, int line, int column);
void add_child(ast_node *parent, ast_node *child);
void add_sibling(ast_node *node, ast_node *sibling);
void print_ast(ast_node *node, int depth);
void print_ast_annotated(ast_node *node, int depth);
void free_ast(ast_node *node);

extern const char *category_name[];
const char *type_name(enum type t);

#endif