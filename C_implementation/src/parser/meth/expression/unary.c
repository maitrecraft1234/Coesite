/*
** EPITECH PROJECT, 2024
** src/parser/meth/expression/unary
** File description:
** unary parsing
*/

#include <parser/type.h>
#include <parser/macros.h>
#include <parser/function.h>
#include <assert.h>

// note that the assert probably should be changed into something
// that can be expended without changing two places or more
pgmx_unary_t pgm_expr_unary(parser_t *parser)
{
    pgmx_unary_t unary = {0};

    unary.operator = parser_consume_lexem_id(parser);
    assert(unary.operator == LX_OP_PLUS || unary.operator == LX_OP_MINUS);
    HEAPIFY(unary.expr, pgm_expression(parser));
    return unary;
}
