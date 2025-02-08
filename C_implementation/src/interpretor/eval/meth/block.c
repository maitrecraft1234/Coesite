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
#include "parser/grammar_types/meth/statement.h"
#include "parser/grammar_types/meth/type_tag.h"
#include "interpretor/functions.h"

pg_lit_primitive_t interpretor_eval_meth_block(interpretor_t *interpretor,
    pgm_block_t *block)
{
    pgm_statement_t statement;
    pg_lit_primitive_t last;

    for (size_t i = 0; i < DA_LEN(block->pgm_block_el); ++i) {
            if (block->pgm_block_el->type == PGM_BLOCK) {
                interpretor_eval_meth_block(interpretor,
                    block->pgm_block_el[i].block);
                continue;
            }
            assert(block->pgm_block_el[i].type == PGM_STATEMENT);
            statement = block->pgm_block_el[i].statment;
            last = interpretor_eval_meth_statement(interpretor, &statement);
    }
    return last;
}
