/*
** EPITECH PROJECT, 2024
** src/parser/meth/expression/grouping
** File description:
** %
*/

#include <parser/type.h>
#include <parser/macros.h>
#include <parser/function.h>
#include "parser/grammar_types/meth/expression.h"
#include <assert.h>
#include "lexer/type.h"
#include <general/macros.h>

pgmx_grouping_t pgm_expr_grouping(parser_t *parser)
{
    pgmx_grouping_t grouping = {0};

    assert(parser_consume_lexem_id(parser) == LX_PAR_OPEN);
    HEAPIFY(grouping.expr, pgm_expression(parser));
    return grouping;
}
