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

    bin_op_high.left = left_expr;
    bin_op_high.op = CUR_LEXEM(parser).type == lx_op_mul
        ? pxe_dbg_mul_bop_e
        : pxe_dbg_div_bop_e;
    ++parser->lexem_index;
    bin_op_high.right = parser_dbg_parse_no_left_req(parser);
    return bin_op_high;
}

static pxe_dbg_bin_op_t parser_dbg_parse_bin_op_low(parser_t *parser,
        pxe_dbg_statement_no_left_req_t *left_expr)
{
    pxe_dbg_bin_op_t bin_op = {0};

    if (CUR_LEXEM(parser).type == lx_op_mul ||
        CUR_LEXEM(parser).type == lx_op_div) {
        bin_op.high = parser_dbg_parse_bin_op_high(parser, left_expr);
        bin_op.type = pxe_dbg_bin_op_high_e;
    } else {
        bin_op.left_nr = left_expr;
        bin_op.type = pxe_dbg_bin_op_low_e;
    }
    if (CUR_LEXEM(parser).type != lx_op_plus &&
        CUR_LEXEM(parser).type != lx_op_minus) {
        return bin_op;
    }
    bin_op.op = CUR_LEXEM(parser).type == lx_op_plus
        ? pxe_dbg_plus_bop_e
        : pxe_dbg_minus_bop_e;
    ++parser->lexem_index;
    bin_op.right = parser_dbg_parse_statement(parser);
    return bin_op;
}

px_dbg_statement_t *parser_dbg_parse_statement(parser_t *parser)
{
    px_dbg_statement_t *statement = malloc(sizeof(px_dbg_statement_t));
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
