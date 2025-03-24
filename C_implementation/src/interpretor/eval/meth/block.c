/*
** EPITECH PROJECT, 2025
** /home/vj/coding/Swag-lang/C_implementation/src/interpretor/eval/meth/block
** File description:
** meth block evaluator
*/

#include "parser/grammar_types/meth/block.h"
#include <assert.h>
#include <stddef.h>
#include "interpretor/types.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/statement.h"
#include "parser/grammar_types/meth/type_tag.h"
#include "interpretor/functions.h"

static pg_lit_primitive_t interpretor_eval_meth_if(
    interpretor_t *interpretor, pgm_bare_cs_t *bare_cs)
{
    pg_lit_primitive_t res = interpretor_eval_meth_expr(interpretor,
        bare_cs->grouping->expr);

    if (res.type != PGT_BOOL) {
        TODO;
    }
    if (res.value.boolean) {
        return interpretor_eval_meth_block(interpretor, bare_cs->block);
    }
    return (pg_lit_primitive_t){0};
}

static pg_lit_primitive_t interpretor_eval_meth_while(
    interpretor_t *interpretor, pgm_bare_cs_t *bare_cs)
{
    pg_lit_primitive_t res;
    pg_lit_primitive_t last = {0};

    while ((res = interpretor_eval_meth_expr(interpretor,
        bare_cs->grouping->expr)).value.boolean) {
        last = interpretor_eval_meth_block(interpretor, bare_cs->block);
    }
    return last;
}

static pg_lit_primitive_t interpretor_eval_meth_block_el(
    interpretor_t *interpretor, struct pgm_block_el_s *block_el)
{
    pg_lit_primitive_t res;

    switch (block_el->type) {
        case PGM_IF:
            res = interpretor_eval_meth_if(interpretor, &block_el->bare_cs);
            break;
        case PGM_WHILE:
            res = interpretor_eval_meth_while(interpretor, &block_el->bare_cs);
            break;
        default:
            assert(block_el->type == PGM_STATEMENT);
            res = interpretor_eval_meth_statement(interpretor,
                &block_el->statment);

    }
    return res;
}

pg_lit_primitive_t interpretor_eval_meth_block(interpretor_t *interpretor,
    pgm_block_t *block)
{
    pgm_statement_t statement;
    pg_lit_primitive_t last;
    interpretor_t subscope = interpretor_create(interpretor);

    for (size_t i = 0; i < DA_LEN(block->pgm_block_el); ++i) {
            if (block->pgm_block_el->type == PGM_BLOCK) {
                interpretor_eval_meth_block(&subscope,
                    block->pgm_block_el[i].block);
                continue;
            }
            last = interpretor_eval_meth_block_el(&subscope,
                &block->pgm_block_el[i]);
    }
    interpretor_destroy(&subscope);
    return last;
}
