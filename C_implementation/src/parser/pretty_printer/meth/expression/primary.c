/*
** EPITECH PROJECT, 2025
** src/parser/pretty_printer/meth/expression/primary
** File description:
** qehuoqgh
*/

#include "parser/function.h"
#include "parser/grammar_types/meth/expression.h"

void parser_dump_meth_primary(pgmx_primary_t *primary)
{
    switch (primary->type) {
        case PGM_BLOCK:
            return parser_dump_meth_block(primary->block);
        case PGM_GROUPING:
            return parser_dump_meth_expression(primary->grouping.expr);
        case PGM_UNARY:
            lexem_dbg_id_print(primary->unary.operator);
            return parser_dump_meth_expression(primary->unary.expr);
        case PGM_LITERAL:
            return (void)printf(" %ld ", primary->literal.literal.value);
        default:
            UNREACHABLE;
    }
}
