/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/create
** File description:
** parser creation deletion
*/

#include "parser/type.h"
#include "general/dynamic_array.h"
#include "parser/dbg/functions.h"
#include "parser/dbg/types.h"

parser_t parser_create(void)
{
    parser_t parser;

    parser.defs = da_create();
    parser.lexems = NULL;
    parser.lexem_index = 0;
    return parser;
}

static void free_statement(px_dbg_statement_t *statement);

static void free_statment_no_left_req(pxe_dbg_statement_no_left_req_t *nleft_req)
{
    if (nleft_req->type == pxe_dbg_grouping_e) {
        free_statement(nleft_req->grouping.statement);
    } else if (nleft_req->type == pxe_dbg_unary_op_e) {
        free_statement(nleft_req->u_op.statement);
    }
}

static void free_statement(px_dbg_statement_t *statement)
{
    if (statement->type == pxe_dbg_bin_op_e) {
        free_statment_no_left_req(&statement->nleft_req);
        free_statement(statement->bin_op.right);
    } else if (statement->type == pxe_dbg_statement_no_left_req_e) {
        free_statment_no_left_req(&statement->nleft_req);
    }
    free(statement);
}

void parser_destroy(parser_t *parser)
{
    free_statement(parser->defs->dbg.block.statement);
    da_destroy(parser->defs);
}
