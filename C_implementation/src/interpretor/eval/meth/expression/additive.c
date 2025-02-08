/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/expression/additive
** File description:
** additive expression
*/

#include <assert.h>
#include <stddef.h>
#include "general/macros.h"
#include "interpretor/functions.h"
#include "interpretor/types.h"
#include "lexer/type.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/expression.h"
#include "interpretor/builtins/additive.h"

pg_lit_primitive_t interpretor_eval_meth_expr_additive(
        interpretor_t *interpretor, pgmx_additive_t *expr)
{
    pg_lit_primitive_t a =
        interpretor_eval_meth_expr_multiplicative(interpretor, &expr->left);
    pg_lit_primitive_t (*bin_op)(pg_lit_primitive_t *a, pg_lit_primitive_t *b);
    pg_lit_primitive_t b;

    for (size_t i = 0; i < DA_LEN(expr->ops); ++i) {
        b = interpretor_eval_meth_expr_multiplicative(interpretor,
            &expr->ops[i].right);
        if (expr->ops[i].operator == LX_OP_PLUS)
            bin_op = add_lookup[a.type];
        if (expr->ops[i].operator == LX_OP_MINUS)
            bin_op = sub_lookup[a.type];
        if (!bin_op)
            TODO; //type err
        if (a.type != b.type)
            TODO; //type err
        a = bin_op(&a, &b);
    }
    return a;
}
