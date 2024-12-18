/*
** EPITECH PROJECT, 2024
** src/parser/meth/expression/expression
** File description:
** entry point for the expreson parser
*/

#include <parser/type.h>
#include "parser/grammar_types/meth/expression.h"
#include "general/dynamic_array.h"

pgm_expression_t pgm_expression(parser_t *parser)
{
    pgm_expression_t expression = {0};

    expression = pgm_expr_additive(parser);
    return expression;
}
