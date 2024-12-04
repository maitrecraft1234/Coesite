/*
** EPITECH PROJECT, 2024
** /home/vj/test/language_name_unkown/src/parser/meth/block
** File description:
** parser for meth block
*/

#include "parser/grammar_types/meth/type_tag.h"
#include <parser/grammar_types/meth/block.h>
#include <parser/type.h>
#include <parser/function.h>
#include <general/dynamic_array.h>
#include <parser/macros.h>
#include <assert.h>
#include "general/macros.h"
#include "lexer/type.h"

//no default in switch fo now as the function is not finished
static struct pgm_block_el_s pgm_block_el(parser_t *parser)
{
    struct pgm_block_el_s res = {0};

    switch (CUR_LEXEM(parser).type) {
        CASE(LX_BRACKET_OPEN) {
                HEAPIFY(res.block, pgm_block(parser));
                res.type = PGM_BLOCK;
        }
        /* CASE(LX_IDENTIFER) { */
        /*         HEAPIFY(res.statment, pgm_statement(parser)); */
        /*         res.type = PGM_STATEMENT; */
        /* } */
    }
    return res;
}

pgm_block_t pgm_block(parser_t *parser)
{
    pgm_block_t block = {0};
    lexem_t cur = CUR_LEXEM(parser);
    struct pgm_block_el_s el;

    assert(cur.type == LX_BRACKET_OPEN);
    ++parser->lexem_index;
    cur = CUR_LEXEM(parser);
    block.pgm_block_el = da_create_with_cappacity(sizeof *block.pgm_block_el);
    while (cur.type != LX_BRACKET_CLOSE) {
        el = pgm_block_el(parser);
        DA_PUSH(block.pgm_block_el, el);
        cur = CUR_LEXEM(parser);
    }
    return block;
}
