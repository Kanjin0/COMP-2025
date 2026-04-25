#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include "ast.h"
#include "semantics.h"

symbol_table *global_table = NULL;
symbol_table *tables_head  = NULL;
static symbol_table *tables_tail = NULL;
int semantic_errors = 0;

/* ---- forward declarations ---- */
static char *build_param_sig(enum type *param_types, int count);
static int is_compatible(enum type formal, enum type actual);
static void annotate(ast_node *node, enum type t);

/* ================================================================
   SYMBOL TABLE MANAGEMENT
   ================================================================ */

symbol_table *create_table(const char *name) {
    symbol_table *t = malloc(sizeof(symbol_table));
    t->name = strdup(name);
    t->head = NULL;
    t->next = NULL;
    if (tables_head == NULL) { tables_head = tables_tail = t; }
    else { tables_tail->next = t; tables_tail = t; }
    return t;
}

/* helper: find a variable/field (non‑method) symbol */
static symbol *lookup_variable(symbol_table *tbl, const char *name) {
    for (symbol *s = tbl->head; s; s = s->next)
        if (strcmp(s->name, name) == 0 && s->param_count < 0)
            return s;
    return NULL;
}

symbol *insert_symbol(symbol_table *tbl, const char *name, enum type type,
                       enum type *param_types, int param_count, int is_param,
                       int line, int col) {
    if (strcmp(name, "_") == 0) {
        if (line > 0) {
            printf("Line %d, col %d: Symbol _ is reserved\n", line, col);
            semantic_errors++;
        }
        return NULL;
    }

    if (param_count >= 0) {                      /* method */
        for (symbol *s = tbl->head; s; s = s->next) {
            if (strcmp(s->name, name) == 0 && s->param_count == param_count) {
                int same = 1;
                for (int i = 0; i < param_count; i++) {
                    if (s->param_types[i] != param_types[i]) {
                        same = 0; break;
                    }
                }
                if (same) {
                    char *sig = build_param_sig(param_types, param_count);
                    printf("Line %d, col %d: Symbol %s%s already defined\n",
                           line, col, name, sig);
                    free(sig);
                    semantic_errors++;
                    return NULL;
                }
            }
        }
    } else {                                     /* variable / field */
        if (lookup_variable(tbl, name) != NULL) {
            if (line > 0) {
                printf("Line %d, col %d: Symbol %s already defined\n", line, col, name);
                semantic_errors++;
            }
            return NULL;
        }
    }

    symbol *s = malloc(sizeof(symbol));
    s->name        = strdup(name);
    s->type        = type;
    s->param_types = param_types;
    s->param_count = param_count;
    s->is_param    = is_param;
    s->line        = line;
    s->col         = col;
    s->next        = NULL;
    if (tbl->head == NULL) { tbl->head = s; }
    else {
        symbol *cur = tbl->head;
        while (cur->next) cur = cur->next;
        cur->next = s;
    }
    return s;
}

symbol *lookup_local(symbol_table *tbl, const char *name) {
    for (symbol *s = tbl->head; s; s = s->next)
        if (strcmp(s->name, name) == 0) return s;
    return NULL;
}

symbol *lookup_global(symbol_table *global_tbl, symbol_table *local_tbl, const char *name) {
    symbol *s = NULL;
    if (local_tbl)  s = lookup_local(local_tbl, name);
    if (!s && global_tbl) s = lookup_local(global_tbl, name);
    return s;
}

/* ================================================================
   HELPERS
   ================================================================ */

static enum type ast_cat_to_type(enum category ast_type) {
    switch (ast_type) {
        case Int:          return type_int;
        case Double:       return type_double;
        case Bool:         return type_boolean;
        case Void:         return type_void;
        case StringArray:  return type_string_array;
        default:           return type_undef;
    }
}

static char *build_param_sig(enum type *param_types, int count) {
    int len = 2;
    for (int i = 0; i < count; i++) {
        len += strlen(type_name(param_types[i]));
        if (i < count - 1) len += 1;
    }
    char *sig = malloc(len + 1);
    sig[0] = '('; sig[1] = '\0';
    for (int i = 0; i < count; i++) {
        strcat(sig, type_name(param_types[i]));
        if (i < count - 1) strcat(sig, ",");
    }
    strcat(sig, ")");
    return sig;
}

static int is_compatible(enum type formal, enum type actual) {
    if (formal == actual) return 1;
    if (formal == type_double && actual == type_int) return 1;
    return 0;
}

static void annotate(ast_node *node, enum type t) {
    if (node) {
        node->type = t;
        node->type_set = 1;
    }
}

/* ================================================================
   PHASE 1: BUILD SYMBOL TABLES
   ================================================================ */

static char **accepted_signatures = NULL;
static int accepted_count = 0;

static void add_accepted_signature(const char *sig) {
    accepted_signatures = realloc(accepted_signatures, (accepted_count+1) * sizeof(char*));
    accepted_signatures[accepted_count++] = strdup(sig);
}

static int is_accepted_signature(const char *sig) {
    for (int i = 0; i < accepted_count; i++)
        if (strcmp(accepted_signatures[i], sig) == 0)
            return 1;
    return 0;
}

static void build_method_table(ast_node *method_decl, enum type ret_type,
                                const char *method_name,
                                enum type *param_types, int param_count) {
    char *sig = build_param_sig(param_types, param_count);
    int tname_len = strlen("Method ") + strlen(method_name) + strlen(sig) + 1;
    char *tname = malloc(tname_len + 1);
    sprintf(tname, "Method %s%s", method_name, sig);
    symbol_table *mtbl = create_table(tname);
    free(tname);
    free(sig);

    insert_symbol(mtbl, "return", ret_type, NULL, -1, 0, 0, 0);

    ast_node *header = method_decl->child;
    ast_node *mp = header ? header->child : NULL;
    if (mp) mp = mp->sibling;
    if (mp) mp = mp->sibling;
    if (mp && mp->category == MethodParams) {
        ast_node *param = mp->child;
        for (int i = 0; i < param_count && param; i++, param = param->sibling) {
            ast_node *id_node = param->child ? param->child->sibling : NULL;
            if (id_node) {
                if (!lookup_local(mtbl, id_node->value))
                    insert_symbol(mtbl, id_node->value, param_types[i],
                                  NULL, -1, 1, id_node->line, id_node->column);
            }
        }
    }
}

void build_tables(ast_node *root) {
    if (!root || root->category != Program) return;

    ast_node *class_id = root->child;
    const char *class_name = class_id ? class_id->value : "Unknown";

    int cname_len = strlen("Class ") + strlen(class_name) + 1;
    char *cname = malloc(cname_len);
    sprintf(cname, "Class %s", class_name);
    global_table = create_table(cname);
    free(cname);

    ast_node *decl = class_id ? class_id->sibling : NULL;
    while (decl) {
        if (decl->category == MethodDecl) {
            ast_node *header = decl->child;
            if (!header) { decl = decl->sibling; continue; }

            ast_node *type_node = header->child;
            ast_node *id_node   = type_node ? type_node->sibling : NULL;
            ast_node *mp        = id_node   ? id_node->sibling   : NULL;

            enum type ret_type   = ast_cat_to_type(type_node ? type_node->category : Void);
            const char *method_name = id_node ? id_node->value : "unknown";

            int param_count = 0;
            if (mp && mp->category == MethodParams) {
                ast_node *p = mp->child;
                while (p) { param_count++; p = p->sibling; }
            }
            enum type *param_types = param_count > 0 ? malloc(param_count * sizeof(enum type)) : NULL;
            if (mp && mp->category == MethodParams) {
                ast_node *p = mp->child;
                for (int i = 0; p; i++, p = p->sibling) {
                    ast_node *ptype = p->child;
                    param_types[i] = ast_cat_to_type(ptype ? ptype->category : Void);
                }
            }

            /* check duplicate parameter names BEFORE trying to insert method */
            if (mp && mp->category == MethodParams) {
                ast_node *p1 = mp->child;
                for (int i = 0; p1; i++, p1 = p1->sibling) {
                    ast_node *pid1 = p1->child ? p1->child->sibling : NULL;
                    if (!pid1) continue;
                    ast_node *p2 = mp->child;
                    for (int j = 0; j < i; j++, p2 = p2->sibling) {
                        ast_node *pid2 = p2->child ? p2->child->sibling : NULL;
                        if (pid2 && strcmp(pid1->value, pid2->value) == 0) {
                            printf("Line %d, col %d: Symbol %s already defined\n",
                                   pid1->line, pid1->column, pid1->value);
                            semantic_errors++;
                            break;
                        }
                    }
                }
            }

            char *sig = build_param_sig(param_types, param_count);
            symbol *ms = insert_symbol(global_table, method_name, ret_type,
                                       param_types, param_count, 0,
                                       id_node ? id_node->line : 0,
                                       id_node ? id_node->column : 0);
            if (ms != NULL) {
                build_method_table(decl, ret_type, method_name, param_types, param_count);
                add_accepted_signature(sig);
                decl->is_duplicate = 0;
            } else {
                decl->is_duplicate = 1;
                free(param_types);
            }
            free(sig);

        } else if (decl->category == FieldDecl) {
            ast_node *type_node = decl->child;
            ast_node *id_node   = type_node ? type_node->sibling : NULL;
            enum type ftype     = type_node ? ast_cat_to_type(type_node->category) : type_undef;
            if (id_node) {
                insert_symbol(global_table, id_node->value, ftype,
                              NULL, -1, 0, id_node->line, id_node->column);
            }
            decl->is_duplicate = 0;
        }
        decl = decl->sibling;
    }
}

/* ================================================================
   PHASE 1 OUTPUT: PRINT TABLES
   ================================================================ */
void print_tables(void) {
    for (symbol_table *t = tables_head; t; t = t->next) {
        printf("===== %s Symbol Table =====\n", t->name);
        for (symbol *s = t->head; s; s = s->next) {
            printf("%s\t", s->name);
            if (s->param_count >= 0) {
                printf("(");
                for (int i = 0; i < s->param_count; i++) {
                    printf("%s", type_name(s->param_types[i]));
                    if (i < s->param_count - 1) printf(",");
                }
                printf(")\t");
            } else {
                printf("\t");
            }
            printf("%s", type_name(s->type));
            if (s->is_param) printf("\tparam");
            printf("\n");
        }
        if (t->next) printf("\n");
    }
    printf("\n");
}

/* ================================================================
   HELPER: find method table by name+params
   ================================================================ */
static symbol_table *find_method_table(const char *method_name,
                                        enum type *param_types, int param_count) {
    char *sig = build_param_sig(param_types, param_count);
    int len = strlen("Method ") + strlen(method_name) + strlen(sig) + 1;
    char *tname = malloc(len + 1);
    sprintf(tname, "Method %s%s", method_name, sig);
    symbol_table *found = NULL;
    for (symbol_table *t = tables_head; t; t = t->next) {
        if (strcmp(t->name, tname) == 0) { found = t; break; }
    }
    free(tname); free(sig);
    return found;
}

/* ================================================================
   PHASE 2: TYPE CHECKING
   ================================================================ */

static enum type check_call(ast_node *call_node, symbol_table *local_tbl);
static void check_stmt(ast_node *node, symbol_table *local_tbl, enum type method_ret_type);

static char *remove_underscores(const char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != '_') result[j++] = str[i];
    }
    result[j] = '\0';
    return result;
}

static enum type check_expr(ast_node *node, symbol_table *local_tbl) {
    if (!node) return type_undef;

    switch (node->category) {
        case Natural: {
            char *clean = remove_underscores(node->value);
            long long v = atoll(clean);
            free(clean);
            node->type = type_int;
            node->type_set = 1;
            if (v > 2147483647LL || v < -2147483648LL) {
                printf("Line %d, col %d: Number %s out of bounds\n",
                       node->line, node->column, node->value);
                semantic_errors++;
            }
            return node->type;
        }
        case Decimal: {
            char *clean = remove_underscores(node->value);
            errno = 0;
            double val = strtod(clean, NULL);
            int out_of_bounds = 0;
            if (errno == ERANGE) {
                if (val == 0.0) {
                    if (strcmp(clean, "0") && strcmp(clean, "0.0") &&
                        strcmp(clean, "0e0") && strcmp(clean, "0E0"))
                        out_of_bounds = 1;
                } else if (val == HUGE_VAL || val == -HUGE_VAL) {
                    out_of_bounds = 1;
                }
            }
            free(clean);
            annotate(node, type_double);
            if (out_of_bounds) {
                printf("Line %d, col %d: Number %s out of bounds\n",
                       node->line, node->column, node->value);
                semantic_errors++;
            }
            return type_double;
        }
        case BoolLit:       annotate(node, type_boolean);  return type_boolean;
        case StrLit:        annotate(node, type_string);   return type_string;

        case Identifier: {
            symbol *s = lookup_global(global_table, local_tbl, node->value);
            if (!s) {
                printf("Line %d, col %d: Cannot find symbol %s\n",
                       node->line, node->column, node->value);
                semantic_errors++;
                node->type = type_undef;
                node->type_set = 1;
            } else {
                /* prefer a field/variable over a method with the same name */
                if (s->param_count >= 0) {
                    symbol *nonmethod = NULL;
                    for (symbol *cur = global_table->head; cur; cur = cur->next)
                        if (strcmp(cur->name, node->value) == 0 && cur->param_count < 0) {
                            nonmethod = cur; break;
                        }
                    if (!nonmethod && local_tbl)
                        for (symbol *cur = local_tbl->head; cur; cur = cur->next)
                            if (strcmp(cur->name, node->value) == 0 && cur->param_count < 0) {
                                nonmethod = cur; break;
                            }
                    if (nonmethod) s = nonmethod;
                }

                if (s->param_count >= 0) {
                    char *sig = build_param_sig(s->param_types, s->param_count);
                    node->annotated_str = sig;
                    annotate(node, s->type);
                } else {
                    annotate(node, s->type);
                }
            }
            return node->type;
        }

        case Length: {
            enum type child_t = check_expr(node->child, local_tbl);
            if (child_t != type_string_array) {
                printf("Line %d, col %d: Operator .length cannot be applied to type %s\n",
                       node->line, node->column, type_name(child_t));
                semantic_errors++;
            }
            annotate(node, type_int);
            return type_int;
        }

        case ParseArgs: {
            ast_node *arr = node->child;
            ast_node *idx = arr ? arr->sibling : NULL;
            enum type arr_t = check_expr(arr, local_tbl);
            enum type idx_t = idx ? check_expr(idx, local_tbl) : type_undef;
            if (arr_t != type_string_array) {
                printf("Line %d, col %d: Operator Integer.parseInt cannot be applied to types %s, %s\n",
                       node->line, node->column, type_name(arr_t), type_name(idx_t));
                semantic_errors++;
            } else if (idx_t != type_int) {
                printf("Line %d, col %d: Operator Integer.parseInt cannot be applied to types %s, %s\n",
                       node->line, node->column, type_name(arr_t), type_name(idx_t));
                semantic_errors++;
            }
            annotate(node, type_int);
            return type_int;
        }

        case Call: {
            enum type ret = check_call(node, local_tbl);
            annotate(node, ret);
            return ret;
        }

        case Assign: {
            ast_node *lhs = node->child;
            ast_node *rhs = lhs ? lhs->sibling : NULL;
            enum type ltype = check_expr(lhs, local_tbl);
            enum type rtype = rhs ? check_expr(rhs, local_tbl) : type_undef;

            /* assignment to/from arrays is never allowed */
            if (ltype == type_string_array || rtype == type_string_array) {
                printf("Line %d, col %d: Operator = cannot be applied to types %s, %s\n",
                       node->line, node->column, type_name(ltype), type_name(rtype));
                semantic_errors++;
                annotate(node, ltype);
                return ltype;
            }

            if (ltype != type_undef && (rtype == type_undef || ltype != rtype)) {
                if (!(ltype == type_double && rtype == type_int)) {
                    printf("Line %d, col %d: Operator = cannot be applied to types %s, %s\n",
                           node->line, node->column, type_name(ltype), type_name(rtype));
                    semantic_errors++;
                }
            }
            annotate(node, ltype);
            return ltype;
        }

        case Minus: case Plus: {
            enum type ot = check_expr(node->child, local_tbl);
            if (ot != type_int && ot != type_double && ot != type_undef) {
                printf("Line %d, col %d: Operator %s cannot be applied to type %s\n",
                       node->line, node->column,
                       node->category == Minus ? "-" : "+", type_name(ot));
                semantic_errors++;
                node->type = type_undef;
            } else {
                annotate(node, ot);
            }
            node->type_set = 1;
            return node->type;
        }

        case Not: {
            enum type ot = check_expr(node->child, local_tbl);
            if (ot != type_boolean && ot != type_undef) {
                printf("Line %d, col %d: Operator ! cannot be applied to type %s\n",
                       node->line, node->column, type_name(ot));
                semantic_errors++;
            }
            node->type = type_boolean;
            node->type_set = 1;
            return type_boolean;
        }

        case Add: case Sub: case Mul: case Div: case Mod:
        case Lshift: case Rshift: {
            ast_node *lhs = node->child;
            ast_node *rhs = lhs ? lhs->sibling : NULL;
            enum type lt = check_expr(lhs, local_tbl);
            enum type rt = check_expr(rhs, local_tbl);
            const char *op_sym = "";
            switch (node->category) {
                case Add: op_sym = "+"; break;
                case Sub: op_sym = "-"; break;
                case Mul: op_sym = "*"; break;
                case Div: op_sym = "/"; break;
                case Mod: op_sym = "%"; break;
                case Lshift: op_sym = "<<"; break;
                case Rshift: op_sym = ">>"; break;
                default: break;
            }

            int valid = 0;
            enum type result_type = type_undef;
            if (node->category == Lshift || node->category == Rshift) {
                if (lt == type_int && rt == type_int) {
                    valid = 1; result_type = type_int;
                }
            } else {
                if (lt == type_int && rt == type_int) {
                    valid = 1; result_type = type_int;
                } else if ((lt == type_int || lt == type_double) &&
                           (rt == type_int || rt == type_double)) {
                    valid = 1; result_type = type_double;
                }
            }

            if (!valid) {
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",
                       node->line, node->column, op_sym, type_name(lt), type_name(rt));
                semantic_errors++;
                if (node->category == Lshift || node->category == Rshift)
                    result_type = type_int;
                else
                    result_type = type_undef;
            }
            annotate(node, result_type);
            node->type_set = 1;
            return node->type;
        }

        case And: case Or: {
            ast_node *lhs = node->child;
            ast_node *rhs = lhs ? lhs->sibling : NULL;
            enum type lt = check_expr(lhs, local_tbl);
            enum type rt = check_expr(rhs, local_tbl);
            const char *op_sym = node->category == And ? "&&" : "||";
            if (lt == type_boolean && rt == type_boolean) {
                annotate(node, type_boolean);
            } else {
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",
                       node->line, node->column, op_sym, type_name(lt), type_name(rt));
                semantic_errors++;
                node->type = type_boolean;
            }
            node->type_set = 1;
            return node->type;
        }

        case Xor: {
            ast_node *lhs = node->child;
            ast_node *rhs = lhs ? lhs->sibling : NULL;
            enum type lt = check_expr(lhs, local_tbl);
            enum type rt = check_expr(rhs, local_tbl);
            if (lt == type_int && rt == type_int) {
                annotate(node, type_int);
            } else {
                printf("Line %d, col %d: Operator ^ cannot be applied to types %s, %s\n",
                       node->line, node->column, type_name(lt), type_name(rt));
                semantic_errors++;
                node->type = type_int;
            }
            node->type_set = 1;
            return node->type;
        }

        case Eq: case Ne: {
            ast_node *lhs = node->child;
            ast_node *rhs = lhs ? lhs->sibling : NULL;
            enum type lt = check_expr(lhs, local_tbl);
            enum type rt = check_expr(rhs, local_tbl);
            const char *op_sym = (node->category == Eq) ? "==" : "!=";
            int numeric = (lt == type_int || lt == type_double) &&
                          (rt == type_int || rt == type_double);
            int boolean_both = (lt == type_boolean && rt == type_boolean);
            if (!numeric && !boolean_both) {
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",
                       node->line, node->column, op_sym, type_name(lt), type_name(rt));
                semantic_errors++;
            }
            node->type = type_boolean;
            node->type_set = 1;
            return type_boolean;
        }
        case Lt: case Le: case Gt: case Ge: {
            ast_node *lhs = node->child;
            ast_node *rhs = lhs ? lhs->sibling : NULL;
            enum type lt = check_expr(lhs, local_tbl);
            enum type rt = check_expr(rhs, local_tbl);
            const char *op_sym = "";
            switch (node->category) {
                case Lt: op_sym = "<";  break;
                case Le: op_sym = "<="; break;
                case Gt: op_sym = ">";  break;
                case Ge: op_sym = ">="; break;
                default: break;
            }
            int numeric = (lt == type_int || lt == type_double) &&
                          (rt == type_int || rt == type_double);
            if (!numeric) {
                printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",
                       node->line, node->column, op_sym, type_name(lt), type_name(rt));
                semantic_errors++;
            }
            node->type = type_boolean;
            node->type_set = 1;
            return type_boolean;
        }

        default:
            return type_undef;
    }
}

static enum type check_call(ast_node *call_node, symbol_table *local_tbl) {
    ast_node *id_node = call_node->child;
    if (!id_node) { call_node->type = type_undef; call_node->type_set = 1; return type_undef; }

    const char *method_name = id_node->value;

    int arg_count = 0;
    ast_node *arg = id_node->sibling;
    ast_node *args[64];
    while (arg && arg_count < 64) { args[arg_count++] = arg; arg = arg->sibling; }

    enum type arg_types[64];
    for (int i = 0; i < arg_count; i++)
        arg_types[i] = check_expr(args[i], local_tbl);

    symbol *candidates[64];
    int cand_count = 0;
    for (symbol *s = global_table->head; s; s = s->next) {
        if (strcmp(s->name, method_name) == 0 && s->param_count >= 0) {
            candidates[cand_count++] = s;
        }
    }

    if (cand_count == 0) {
        char *attempt_sig = build_param_sig(arg_types, arg_count);
        printf("Line %d, col %d: Cannot find symbol %s%s\n",
               id_node->line, id_node->column, method_name, attempt_sig);
        free(attempt_sig);
        semantic_errors++;
        id_node->type = type_undef; id_node->type_set = 1;
        call_node->type = type_undef; call_node->type_set = 1;
        return type_undef;
    }

    symbol *exact = NULL;
    for (int i = 0; i < cand_count; i++) {
        symbol *s = candidates[i];
        if (s->param_count != arg_count) continue;
        int match = 1;
        for (int j = 0; j < arg_count; j++) {
            if (s->param_types[j] != arg_types[j]) { match = 0; break; }
        }
        if (match) { exact = s; break; }
    }
    if (exact) {
        char *sig = build_param_sig(exact->param_types, exact->param_count);
        id_node->annotated_str = sig;
        annotate(call_node, exact->type);
        return exact->type;
    }

    symbol *compat[64]; int compat_count = 0;
    for (int i = 0; i < cand_count; i++) {
        symbol *s = candidates[i];
        if (s->param_count != arg_count) continue;
        int ok = 1;
        for (int j = 0; j < arg_count; j++) {
            if (!is_compatible(s->param_types[j], arg_types[j])) {
                ok = 0; break;
            }
        }
        if (ok) compat[compat_count++] = s;
    }
    if (compat_count == 1) {
        char *sig = build_param_sig(compat[0]->param_types, compat[0]->param_count);
        id_node->annotated_str = sig;
        annotate(call_node, compat[0]->type);
        return compat[0]->type;
    }
    if (compat_count > 1) {
        char *attempt_sig = build_param_sig(arg_types, arg_count);
        printf("Line %d, col %d: Reference to method %s%s is ambiguous\n",
               id_node->line, id_node->column, method_name, attempt_sig);
        free(attempt_sig);
        semantic_errors++;
        id_node->type = type_undef; id_node->type_set = 1;
        call_node->type = type_undef; call_node->type_set = 1;
        return type_undef;
    }

    char *attempt_sig = build_param_sig(arg_types, arg_count);
    printf("Line %d, col %d: Cannot find symbol %s%s\n",
           id_node->line, id_node->column, method_name, attempt_sig);
    free(attempt_sig);
    semantic_errors++;
    id_node->type = type_undef; id_node->type_set = 1;
    call_node->type = type_undef; call_node->type_set = 1;
    return type_undef;
}

static void check_stmt(ast_node *node, symbol_table *local_tbl, enum type method_ret_type) {
    if (!node) return;

    switch (node->category) {
        case VarDecl: {
            ast_node *type_node = node->child;
            ast_node *id_node   = type_node ? type_node->sibling : NULL;
            enum type vtype     = type_node ? ast_cat_to_type(type_node->category) : type_undef;
            if (id_node) {
                insert_symbol(local_tbl, id_node->value, vtype,
                              NULL, -1, 0, id_node->line, id_node->column);
            }
            break;
        }

        case If:
        case While: {
            ast_node *cond = node->child;
            enum type cond_type = check_expr(cond, local_tbl);
            if (cond_type != type_boolean) {
                printf("Line %d, col %d: Incompatible type %s in %s statement\n",
                       cond ? cond->line : node->line,
                       cond ? cond->column : node->column,
                       type_name(cond_type),
                       node->category == If ? "if" : "while");
                semantic_errors++;
            }
            ast_node *branch = cond ? cond->sibling : NULL;
            while (branch) {
                check_stmt(branch, local_tbl, method_ret_type);
                branch = branch->sibling;
            }
            break;
        }

        case Return: {
            if (node->child) {
                enum type expr_type = check_expr(node->child, local_tbl);
                if (method_ret_type == type_void) {
                    printf("Line %d, col %d: Incompatible type %s in return statement\n",
                           node->child->line, node->child->column, type_name(expr_type));
                    semantic_errors++;
                } else {
                    if (expr_type == type_undef) {
                        printf("Line %d, col %d: Incompatible type undef in return statement\n",
                               node->child->line, node->child->column);
                        semantic_errors++;
                    } else if (expr_type != method_ret_type &&
                               !(method_ret_type == type_double && expr_type == type_int)) {
                        printf("Line %d, col %d: Incompatible type %s in return statement\n",
                               node->child->line, node->child->column, type_name(expr_type));
                        semantic_errors++;
                    }
                }
            } else {
                if (method_ret_type != type_void) {
                    printf("Line %d, col %d: Incompatible type void in return statement\n",
                           node->line, node->column);
                    semantic_errors++;
                }
            }
            break;
        }

        case Print: {
            if (node->child) {
                enum type argt = check_expr(node->child, local_tbl);
                if (argt != type_int && argt != type_double &&
                    argt != type_boolean && argt != type_string) {
                    printf("Line %d, col %d: Incompatible type %s in System.out.print statement\n",
                           node->child->line, node->child->column, type_name(argt));
                    semantic_errors++;
                }
            }
            break;
        }

        case Block: {
            ast_node *s = node->child;
            while (s) { check_stmt(s, local_tbl, method_ret_type); s = s->sibling; }
            break;
        }

        case Assign:
        case Call:
        case ParseArgs:
            check_expr(node, local_tbl);
            break;

        default:
            break;
    }
}

void check_types(ast_node *root) {
    if (!root) return;
    ast_node *decl = root->child ? root->child->sibling : NULL;
    while (decl) {
        if (decl->category == MethodDecl && !decl->is_duplicate) {
            ast_node *header = decl->child;
            ast_node *body   = header ? header->sibling : NULL;

            ast_node *type_node = header ? header->child : NULL;
            ast_node *id_node   = type_node ? type_node->sibling : NULL;
            ast_node *mp        = id_node   ? id_node->sibling   : NULL;
            const char *mname   = id_node   ? id_node->value     : "";

            int param_count = 0;
            if (mp && mp->category == MethodParams) {
                ast_node *p = mp->child;
                while (p) { param_count++; p = p->sibling; }
            }
            enum type *ptypes = param_count > 0 ? malloc(param_count * sizeof(enum type)) : NULL;
            if (mp && mp->category == MethodParams) {
                ast_node *p = mp->child;
                for (int i = 0; p; i++, p = p->sibling) {
                    ast_node *ptype = p->child;
                    ptypes[i] = ast_cat_to_type(ptype ? ptype->category : Void);
                }
            }

            symbol_table *local_tbl = find_method_table(mname, ptypes, param_count);
            free(ptypes);

            if (local_tbl == NULL) {
                decl = decl->sibling;
                continue;
            }

            symbol *ret_sym = lookup_local(local_tbl, "return");
            enum type method_ret_type = ret_sym ? ret_sym->type : type_void;

            if (body && body->category == MethodBody) {
                ast_node *s = body->child;
                while (s) { check_stmt(s, local_tbl, method_ret_type); s = s->sibling; }
            }
        }
        decl = decl->sibling;
    }
}