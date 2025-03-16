/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/expression/multipicative.c
** File description:
** mutliplicative expression
*/

#include <assert.h>
#include <stddef.h>
#include "general/macros.h"
#include "interpretor/functions.h"
#include "interpretor/types.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/expression.h"
#include "interpretor/builtins/mutliplicative.h"

pg_lit_primitive_t interpretor_eval_meth_expr_multiplicative(
    interpretor_t *interpretor, pgmx_multiplicative_t *expr)
{
    pg_lit_primitive_t a =
        interpretor_eval_meth_expr_primary(interpretor, &expr->left);
    pg_lit_primitive_t (*bin_op)(pg_lit_primitive_t *a, pg_lit_primitive_t *b);
    pg_lit_primitive_t b;

    for (size_t i = 0; i < DA_LEN(expr->ops); ++i) {
        b = interpretor_eval_meth_expr_primary(interpretor,
            &expr->ops[i].right);
        if (expr->ops[i].operator == LX_OP_MUL)
            bin_op = mul_lookup[a.type];
        if (expr->ops[i].operator == LX_OP_DIV)
            bin_op = div_lookup[a.type];
        if (!bin_op)
            TODO;
        if (a.type != b.type)
            TODO;
        a = bin_op(&a, &b);
    }
    return a;
}
