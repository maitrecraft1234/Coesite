/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/dbg/nleft_req
** File description:
** no left req expression parsing
*/

#include "general/macros.h"
#include "lexer/type.h"
#include "parser/dbg/types.h"
#include "parser/dbg/functions.h"
#include "parser/macros.h"

pxe_dbg_statement_no_left_req_t parser_dbg_parse_no_left_req(
    parser_t *parser, px_dbg_statement_t *statement)
{
    pxe_dbg_statement_no_left_req_t nleft_req;

    if (CUR_LEXEM(parser).type == lx_lit_int) {
        nleft_req.type = pxe_dbg_litteral_e;
        nleft_req.number_lit = CUR_LEXEM(parser).lit_int;
        ++parser->lexem_index;
        return nleft_req;
    }
    if (parser_dbg_is_unary_op(parser)) {
        nleft_req.type = pxe_dbg_unary_op_e;
        nleft_req.u_op = parser_dbg_parse_unary_op(parser, statement);
        return nleft_req;
    }
    if (parser_dbg_is_grouping(parser)) {
        nleft_req.type = pxe_dbg_grouping_e;
        nleft_req.grouping = parser_dbg_parse_grouping(parser, statement);
    }
    return nleft_req;
}
