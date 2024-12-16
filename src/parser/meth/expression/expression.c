/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/meth/expression/expression
** File description:
** entry point for the expreson parser
*/

#include <parser/type.h>
#include "parser/grammar_types/meth/expression.h"
#include "general/dynamic_array.h"

static pgmx_additive_t pgm_expr_additive(parser_t *parser)
{
    pgmx_additive_t additive = {.ops = da_create(), .left = da_create()};

    //while loop to parse the expression
    return additive;
}

pgm_expression_t pgm_expression(parser_t *parser)
{
    pgm_expression_t expression = {0};

    expression = pgm_expr_additive(parser);
    return expression;
}
