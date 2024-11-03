/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/dbg/uop
** File description:
** uop
*/

#include "lexer/type.h"
#include "parser/dbg/types.h"
#include "parser/dbg/functions.h"
#include "parser/macros.h"

bool parser_dbg_is_unary_op(parser_t *parser)
{
    if (CUR_LEXEM(parser).type == lx_op_minus) {
        return true;
    }
    return false;
}

pxe_dbg_unary_op_t parser_dbg_parse_unary_op(parser_t *parser)
{
    pxe_dbg_unary_op_t u_op;

    u_op.type = pxe_dbg_minus_uop_e;
    ++parser->lexem_index;
    u_op.nl_statement = parser_dbg_parse_no_left_req(parser);
    return u_op;
}
