/*
** EPITECH PROJECT, 2024
** src/parser/dbg/statement
** File description:
** dbg statement parser
*/

#include "lexer/type.h"
#include "parser/dbg/types.h"
#include "parser/dbg/functions.h"
#include "parser/macros.h"

px_dbg_statement_t *parser_dbg_parse_statement(parser_t *parser)
{
    px_dbg_statement_t *statement = malloc(sizeof(px_dbg_statement_t));
    pxe_dbg_statement_no_left_req_t left_expr = parser_dbg_parse_no_left_req(
        parser, statement);

    if (parser_dbg_is_bin_op(CUR_LEXEM(parser).type)) {
        statement->type = pxe_dbg_bin_op_e;
        statement->bin_op.left = left_expr;
        statement->bin_op.op = CUR_LEXEM(parser).type == lx_op_plus
            ? pxe_dbg_plus_bop_e
            : pxe_dbg_minus_bop_e;
        ++parser->lexem_index;
        statement->bin_op.right = parser_dbg_parse_statement(parser);
        return statement;
    } else {
        statement->nleft_req = left_expr;
        statement->type = pxe_dbg_statement_no_left_req_e;
        return statement;
    }
}
