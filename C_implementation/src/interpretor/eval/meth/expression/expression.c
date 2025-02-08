/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/expression/expression
** File description:
** expression evaluator
*/

#include "interpretor/functions.h"
#include "interpretor/types.h"
#include "parser/grammar_types/general.h"

pg_lit_primitive_t interpretor_eval_meth_expr(interpretor_t *interpretor,
    pgm_expression_t *expr)
{
    return interpretor_eval_meth_expr_additive(interpretor, expr);
}
