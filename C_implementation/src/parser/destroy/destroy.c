/*
** EPITECH PROJECT, 2025
** src/parser/destroy/destroy
** File description:
** parser destroy main file
*/

#include <assert.h>
#include <stddef.h>
#include "general/macros.h"
#include "parser/type.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/meth/block.h"
#include "parser/grammar_types/meth/expression.h"
#include "parser/grammar_types/meth/type_tag.h"
#include "parser/function.h"

void pgm_expr_terminal_destroy(pgmx_terminal_t *terminal)
{
    if (terminal->type == PGM_FN_CALL) {
        for (size_t i = 0; i < DA_LEN(terminal->fn_call.meth_args); i++) {
            pgm_expression_destroy(&terminal->fn_call.meth_args[i]);
        }
        da_destroy(terminal->fn_call.meth_args);
        return;
    }
    if (terminal->type != PGM_LITERAL)
        return;
    switch (terminal->literal.type) {
        case PGT_U64:
        case PGT_INT:
        case PGT_BOOL:
            return;
        case PGT_STRING:
            da_destroy(terminal->literal.value.str);
            return;
        UNREACHABLE_DEFAULT;
    }
}

// unary and grouping could be merged into 1 case
static void pgm_expr_primary_destroy(pgmx_primary_t *primary)
{
    switch (primary->type) {
        case PGM_TERMINAL:
            return pgm_expr_terminal_destroy(&primary->terminal);
        case PGM_UNARY:
            pgm_expression_destroy(primary->unary.expr);
            return free(primary->unary.expr);
        case PGM_GROUPING:
            pgm_expression_destroy(primary->grouping.expr);
            return free(primary->grouping.expr);
        case PGM_BLOCK:
            pgm_block_destroy(primary->block);
            return free(primary->block);
        UNREACHABLE_DEFAULT;
    }
}

static void pgm_expr_multiplicative_destroy(pgmx_multiplicative_t *expr)
{
    for (size_t i = 0; i < DA_LEN(expr->ops); i++) {
        pgm_expr_primary_destroy(&expr->ops[i].right);
    }
    pgm_expr_primary_destroy(&expr->left);
    da_destroy(expr->ops);
}

static void pgm_expr_additive_destroy(pgmx_additive_t *expr)
{
    for (size_t i = 0; i < DA_LEN(expr->ops); i++) {
        pgm_expr_multiplicative_destroy(&expr->ops[i].right);
    }
    pgm_expr_multiplicative_destroy(&expr->left);
    da_destroy(expr->ops);
}

static void pgm_expr_cmp_destroy(pgmx_cmp_t *expr)
{
    for (size_t i = 0; i < DA_LEN(expr->ops); i++) {
        pgm_expr_additive_destroy(&expr->ops[i].right);
    }
    pgm_expr_additive_destroy(&expr->left);
    da_destroy(expr->ops);
}

static void pgm_expression_destroy(pgm_expression_t *expr)
{
    pgm_expr_cmp_destroy(expr);
}

// all these types either are aliases to expression or contain it as its
// first member
static void pgm_statement_destroy(pgm_statement_t *statement)
{
    switch (statement->type) {
        case PGM_EXPRESSION:
        case PGM_DECL:
        case PGM_RETURN:
            pgm_expression_destroy(&statement->expr);
            break;
        default:
            UNREACHABLE;
    }
}

static void pgm_block_destroy(pgm_block_t *block)
{
    for (size_t i = 0; i < DA_LEN(block->pgm_block_el); i++) {
        if (block->pgm_block_el[i].type == PGM_IF ||
            block->pgm_block_el[i].type == PGM_WHILE) {
            pgm_block_destroy(block->pgm_block_el[i].bare_cs.block);
            pgm_expression_destroy(block->pgm_block_el[i].
                bare_cs.grouping->expr);
            free(block->pgm_block_el[i].bare_cs.grouping);
            continue;
        }
        if (block->pgm_block_el[i].type == PGM_BLOCK) {
            pgm_block_destroy(block->pgm_block_el[i].block);
            continue;
        }
        if (block->pgm_block_el[i].type == PGM_STATEMENT) {
            pgm_statement_destroy(&block->pgm_block_el[i].statment);
            continue;
        }
        UNREACHABLE;
    }
    da_destroy(block->pgm_block_el);
}

static void parser_def_destroy(px_def_t *def)
{
    if (def->type == PD_METH)
        return pgm_block_destroy(&def->meth.block);
    if (def->type == PD_GLOBAL)
        return ;
}

void parser_destroy(parser_t *parser)
{
    for (size_t i = 0; i < DA_LEN(parser->defs); i++) {
        parser_def_destroy(&parser->defs[i]);
    }
    da_destroy(parser->defs);
}
