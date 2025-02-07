/*
** EPITECH PROJECT, 2025
** src/parser/pretty_printer/meth/block
** File description:
** parser dump meth block
*/

#include "parser/grammar_types/meth/block.h"
#include <stddef.h>
#include "general/dynamic_array.h"
#include "parser/grammar_types/meth/type_tag.h"
#include <general/macros.h>
#include "parser/print/functions.h"

static void helper_dump_el(struct pgm_block_el_s *el)
{
    switch (el->type) {
        case PGM_STATEMENT:
            return parser_dump_meth_statement(&el->statment);
        case PGM_BLOCK:
            return parser_dump_meth_block(el->block);
        default:
            UNREACHABLE;
    }
}

void parser_dump_meth_block(pgm_block_t *block)
{
    puts("{");
    for (size_t i = 0; i < DA_LEN(block->pgm_block_el); ++i)
        helper_dump_el(block->pgm_block_el + i);
    puts("}");
}
