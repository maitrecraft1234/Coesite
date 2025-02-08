/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/expression/primary
** File description:
** primary eval
*/

#include "general/macros.h"
#include "interpretor/functions.h"
#include "interpretor/types.h"
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/expression.h"
#include "parser/grammar_types/meth/type_tag.h"

static pg_lit_primitive_t interpretor_eval_meth_terminal(
    interpretor_t *interpretor, pgmx_terminal_t *term)
{
    if (term->type == PGM_LITERAL)
        return term->literal;
    if (term->type == PGM_FN_CALL)
        return interpretor_eval_meth_fn_call(interpretor, term);
    if (term->type == PGM_IDENTIFIER)
        TODO;
    UNREACHABLE;
}

pg_lit_primitive_t interpretor_eval_meth_expr_primary(
    interpretor_t *interpretor, pgmx_primary_t *prim)
{
    switch (prim->type) {
        case PGM_BLOCK:
            return interpretor_eval_meth_block(interpretor, prim->block);
        case PGM_GROUPING:
            return interpretor_eval_meth_expr(interpretor,
                prim->grouping.expr);
        case PGM_UNARY:
            TODO;
        case PGM_TERMINAL:
            return interpretor_eval_meth_terminal(interpretor,
                &prim->terminal);
        UNREACHABLE_DEFAULT;
    }
}
