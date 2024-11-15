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

static long eval_1deep_right(pxe_dbg_bin_op_high_t **hlop)
{
    long left = interpretor_dbg_eval_no_left_req((*hlop)->right->left);

    if ((*hlop)->op == pxe_dbgh_none) {
        *hlop = NULL;
    } else {
        *hlop = (*hlop)->right;
    }
    return left;
}

long interpretor_dbg_eval_bhoph(pxe_dbg_bin_op_high_t *hlop)
{
    long left = interpretor_dbg_eval_no_left_req(hlop->left);
    long right;
    pxe_dbg_bin_op_high_t *rop = hlop;
    long res;

    if (hlop->op == pxe_dbgh_none) {
        return left;
    }
    right = eval_1deep_right(&rop);
    if (hlop->op == pxe_dbg_mul_bop_e) {
        res = left * right;
    } else if (hlop->op == pxe_dbg_div_bop_e) {
        if (right == 0) {
            return 0;
        } else {
            res = left / right;
        }
    }
    if (!rop) {
        return res;
    }
    if (rop->op == pxe_dbg_mul_bop_e) {
        return res * interpretor_dbg_eval_bhoph(rop);
    }
    return res / interpretor_dbg_eval_bhoph(rop);
}

static long interpretor_dbg_eval_lbhop(pxe_dbg_bin_op_t *bop)
{
    long left = interpretor_dbg_eval_bhoph(&bop->left);
    long right;

    if (bop->op == pxe_dbgl_none) {
        return left;
    }
    right = interpretor_dbg_eval_lbhop(bop->right);
    if (bop->op == pxe_dbg_plus_bop_e) {
        return left + right;
    }
    return left - right;
}

long interpretor_dbg_eval_statement(px_dbg_statement_t *statement)
{
    long left = 0;
    long right = 0;

    if (!statement)
        return 0;
    if (statement->type == pxe_dbg_bin_op_e) {
        return interpretor_dbg_eval_lbhop(&statement->bin_op);
    }
    if (statement->type == pxe_dbg_statement_no_left_req_e) {
        return interpretor_dbg_eval_no_left_req(statement->nleft_req);
    }
    return 0;
}
