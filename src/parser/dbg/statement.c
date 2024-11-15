/*
** EPITECH PROJECT, 2024
** src/parser/dbg/statement
** File description:
** dbg statement parser
*/

#include "lexer/type.h"
#include "parser/dbg/types.h"
#include "parser/dbg/functions.h"
#include "lexer/type.h"
#include "parser/macros.h"

static pxe_dbg_bin_op_high_t parser_dbg_parse_bin_op_high(parser_t *parser,
        pxe_dbg_statement_no_left_req_t *left_expr)
{
    pxe_dbg_bin_op_high_t bin_op_high;
    lexem_id_t type;

    bin_op_high.left = left_expr ? left_expr : parser_dbg_parse_no_left_req(
        parser);
    type = CUR_LEXEM(parser).type;
    if (type == lx_op_mul) {
        bin_op_high.op = pxe_dbg_mul_bop_e;
    } else if (type == lx_op_div) {
        bin_op_high.op = pxe_dbg_div_bop_e;
    } else {
        bin_op_high.op = pxe_dbgh_none;
        return bin_op_high;
    }
    ++parser->lexem_index;
    bin_op_high.right = malloc(sizeof *bin_op_high.right);
    *bin_op_high.right = parser_dbg_parse_bin_op_high(parser, NULL);
    return bin_op_high;
}

static pxe_dbg_bin_op_t parser_dbg_parse_bin_op_low(parser_t *parser,
        pxe_dbg_statement_no_left_req_t *left_expr)
{
    pxe_dbg_bin_op_t bin_op = {0};
    lexem_id_t type;

    bin_op.left = parser_dbg_parse_bin_op_high(parser, left_expr);
    type = CUR_LEXEM(parser).type;
    if (type == lx_op_plus) {
        bin_op.op = pxe_dbg_plus_bop_e;
    } else if (type == lx_op_minus) {
        bin_op.op = pxe_dbg_minus_bop_e;
    } else {
        bin_op.op = pxe_dbgl_none;
        return bin_op;
    }
    ++parser->lexem_index;
    bin_op.right = malloc(sizeof *bin_op.right);
    *bin_op.right =
        parser_dbg_parse_bin_op_low(parser, NULL);
    return bin_op;
}

px_dbg_statement_t *parser_dbg_parse_statement(parser_t *parser)
{
    px_dbg_statement_t *statement = malloc(sizeof *statement);
    pxe_dbg_statement_no_left_req_t *left_expr = parser_dbg_parse_no_left_req(
        parser);

    if (parser_dbg_is_bin_op(CUR_LEXEM(parser).type)) {
        statement->bin_op = parser_dbg_parse_bin_op_low(parser, left_expr);
        statement->type = pxe_dbg_bin_op_e;
        return statement;
    } else {
        statement->nleft_req = left_expr;
        statement->type = pxe_dbg_statement_no_left_req_e;
        return statement;
    }
}
