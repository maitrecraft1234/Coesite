/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/dbg/uop
** File description:
** grouping
*/

#include "lexer/type.h"
#include "parser/dbg/types.h"
#include "parser/dbg/functions.h"
#include "parser/macros.h"

bool parser_dbg_is_grouping(parser_t *parser)
{
    if (CUR_LEXEM(parser).type == lx_par_open) {
        return true;
    }
    return false;
}

pxe_dbg_grouping_t parser_dbg_parse_grouping(parser_t *parser)
{
    pxe_dbg_grouping_t grouping;

    ++parser->lexem_index;
    grouping.statement = parser_dbg_parse_statement(parser);
    if (CUR_LEXEM(parser).type != lx_par_close)
        TODO;
    ++parser->lexem_index;
    return grouping;
}
