#include <assert.h>
#include <stddef.h>
#include "general/macros.h"
#include "interpretor/functions.h"
#include "interpretor/types.h"
#include "lexer/type.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/expression.h"
#include "interpretor/builtins/cmp.h"
// actuall definition in here this is not the best way of doing things
// refactor later
#include "interpretor/builtins/cmp_global.h"


pg_lit_primitive_t interpretor_eval_meth_expr_cmp
(interpretor_t *interpretor, pgmx_cmp_t *expr)
{
    pg_lit_primitive_t a =
        interpretor_eval_meth_expr_additive(interpretor, &expr->left);
    pg_lit_primitive_t (*bin_op)(pg_lit_primitive_t *a, pg_lit_primitive_t *b);
    pg_lit_primitive_t b;

    for (size_t i = 0; i < DA_LEN(expr->ops); ++i) {
        b = interpretor_eval_meth_expr_additive(interpretor,
            &expr->ops[i].right);
        if (expr->ops[i].operator == LX_OP_CMP_GT)
            bin_op = cmp_gt_lookup[a.type];
        if (expr->ops[i].operator == LX_OP_CMP_GE)
            bin_op = cmp_ge_lookup[a.type];
        if (expr->ops[i].operator == LX_OP_CMP_LT)
            bin_op = cmp_lt_lookup[a.type];
        if (expr->ops[i].operator == LX_OP_CMP_LE)
            bin_op = cmp_le_lookup[a.type];
        if (expr->ops[i].operator == LX_OP_CMP_EQ)
            bin_op = cmp_eq_lookup[a.type];
        if (!bin_op)
            TODO;
        if (a.type != b.type)
            TODO;
        a = bin_op(&a, &b);
    }
    return a;
}
