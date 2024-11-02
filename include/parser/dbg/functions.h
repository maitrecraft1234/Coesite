/*
** EPITECH PROJECT, 2024
** /home/vj/test/language_name_unkown/include/parser/dbg/functions
** File description:
** parser example functions
*/

#ifndef parser_dbg_FUNCTIONS_H_
    #define parser_dbg_FUNCTIONS_H_

    #include <stdbool.h>
    #include "parser/dbg/types.h"
    #include "parser/type.h"

px_dbg_t parser_parse_dbg(parser_t *parser);

px_dbg_statement_t *parser_dbg_parse_statement(
    parser_t *parser);

bool parser_dbg_is_bin_op(lexem_id_t operator);
pxe_dbg_bin_op_t parser_dbg_parse_bin_op(
    parser_t *parser, px_dbg_statement_t *statement);

//might be unused, but it will only be implemented if needed
bool parser_dbg_is_no_left_req(parser_t *parser);
pxe_dbg_statement_no_left_req_t parser_dbg_parse_no_left_req(
    parser_t *parser, px_dbg_statement_t *statement);

bool parser_dbg_is_grouping(parser_t *parser);
pxe_dbg_grouping_t parser_dbg_parse_grouping(
    parser_t *parser, px_dbg_statement_t *statement);

bool parser_dbg_is_unary_op(parser_t *parser);
pxe_dbg_unary_op_t parser_dbg_parse_unary_op(
    parser_t *parser, px_dbg_statement_t *statement);

extern void print_dbg_statment(px_dbg_statement_t *parser);
#endif
