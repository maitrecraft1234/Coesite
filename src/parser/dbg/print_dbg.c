/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/dbg/print_dbg
** File description:
** debug funct ion that prints the syntax tree generated
*/

#include "parser/dbg/functions.h"
#include "parser/dbg/types.h"

static void print_dbg_grouping(pxe_dbg_grouping_t *gr)
{
    printf(" ( ");
    print_dbg_statment(gr->statement);
    printf(" ) ");
}

static void print_dbg_unary_op(pxe_dbg_unary_op_t *u_op)
{
    if (u_op->type == pxe_dbg_minus_uop_e) {
        printf(" - ");
    }
    print_dbg_statment(u_op->statement);
}

static void print_dbg_statment_no_left_req(pxe_dbg_statement_no_left_req_t *nleft_req)
{
    if (nleft_req->type == pxe_dbg_grouping_e) {
        print_dbg_grouping(&nleft_req->grouping);
    } else if (nleft_req->type == pxe_dbg_unary_op_e) {
        print_dbg_unary_op(&nleft_req->u_op);
    } else if (nleft_req->type == pxe_dbg_litteral_e) {
        printf(" %ld ", nleft_req->number_lit);
    }
}

static void print_dbg_binary_op(pxe_dbg_bin_op_t *bin_op)
{
    print_dbg_statment_no_left_req(&bin_op->left);
    if (bin_op->op == pxe_dbg_plus_bop_e) {
        printf(" + ");
    } else if (bin_op->op == pxe_dbg_minus_bop_e) {
        printf(" - ");
    }
    print_dbg_statment(bin_op->right);
}

void print_dbg_statment(px_dbg_statement_t *statement)
{
    if (statement->type == pxe_dbg_bin_op_e) {
        print_dbg_binary_op(&statement->bin_op);
    } else if (statement->type == pxe_dbg_statement_no_left_req_e) {
        print_dbg_statment_no_left_req(&statement->nleft_req);
    }
}
