/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/interpretor/dbg/eval
** File description:
** evaluates a dbg expression
*/

#include "parser/dbg/functions.h"
#include "parser/dbg/types.h"
#include "interpretor/functions.h"


static long interpretor_dbg_eval_no_left_req(
    pxe_dbg_statement_no_left_req_t *nleft_req)
{
    if (nleft_req->type == pxe_dbg_litteral_e) {
        return nleft_req->number_lit;
    }
    if (nleft_req->type == pxe_dbg_unary_op_e) {
        return -interpretor_dbg_eval_no_left_req(nleft_req->u_op.nl_statement);
    }
    if (nleft_req->type == pxe_dbg_grouping_e) {
        return interpretor_dbg_eval_statement(nleft_req->grouping.statement);
    }
    return 0;
}

long interpretor_dbg_eval_bhoph(pxe_dbg_bin_op_high_t *hlop)
{
    long left = interpretor_dbg_eval_no_left_req(hlop->left);
    long right = interpretor_dbg_eval_no_left_req(hlop->right);

    if (hlop->op == pxe_dbg_mul_bop_e) {
        return left * right;
    }
    if (right == 0) {
        return 0;
    }
    return left / right;
}

long interpretor_dbg_eval_statement(px_dbg_statement_t *statement)
{
    long left = 0;
    long right = 0;

    if (!statement)
        return 0;
    if (statement->type == pxe_dbg_bin_op_e) {
        if (statement->bin_op.type == pxe_dbg_bin_op_low_e)
            left = interpretor_dbg_eval_no_left_req(statement->nleft_req);
        else
            left = interpretor_dbg_eval_bhoph(&statement->bin_op.high);
        if (statement->bin_op.op == pxe_dbg_plus_bop_e ||
            statement->bin_op.op == pxe_dbg_minus_bop_e)
            right = interpretor_dbg_eval_statement(statement->bin_op.right);
        if (statement->bin_op.op == pxe_dbg_plus_bop_e) {
            return left + right;
        }
        if (statement->bin_op.op == pxe_dbg_minus_bop_e) {
            return left - right;
        }
    }
    if (statement->type == pxe_dbg_statement_no_left_req_e) {
        return interpretor_dbg_eval_no_left_req(statement->nleft_req);
    }
    return 0;
}
