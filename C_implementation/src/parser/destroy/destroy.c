/*
** EPITECH PROJECT, 2025
** src/parser/destroy/destroy
** File description:
** parser destroy main file
*/

#include <assert.h>
#include <stddef.h>
#include "parser/type.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/meth/block.h"
#include "parser/grammar_types/meth/expression.h"


static void pgm_block_destroy(pgm_block_t *block);
static void pgm_expression_destroy(pgm_expression_t *expr);

// unary and grouping could be merged into 1 case
static void pgm_expr_primary_destroy(pgmx_primary_t *primary)
{
    switch (primary->type) {
        case PGM_LITERAL:
            break;
        case PGM_UNARY:
            pgm_expression_destroy(primary->unary.expr);
            return free(primary->unary.expr);
        case PGM_GROUPING:
            pgm_expression_destroy(primary->grouping.expr);
            return free(primary->grouping.expr);
        case PGM_BLOCK:
            pgm_block_destroy(primary->block);
            return free(primary->block);
        default:
            UNREACHABLE;
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

// destroys additive
static void pgm_expression_destroy(pgm_expression_t *expr)
{
    for (size_t i = 0; i < DA_LEN(expr->ops); i++) {
        pgm_expr_multiplicative_destroy(&expr->ops[i].right);
    }
    pgm_expr_multiplicative_destroy(&expr->left);
    da_destroy(expr->ops);
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
        if (block->pgm_block_el[i].type == PGM_BLOCK) {
            pgm_block_destroy(block->pgm_block_el[i].block);
        } else if (block->pgm_block_el[i].type == PGM_STATEMENT) {
            pgm_statement_destroy(&block->pgm_block_el[i].statment);
        } else {
            UNREACHABLE;
        }
    }
    da_destroy(block->pgm_block_el);
}

static void parser_def_destroy(px_def_t *def)
{
    assert(def->type == PD_METH);
    pgm_block_destroy(&def->meth.block);
}

void parser_destroy(parser_t *parser)
{
    for (size_t i = 0; i < DA_LEN(parser->defs); i++) {
        parser_def_destroy(&parser->defs[i]);
    }
    da_destroy(parser->defs);
}
