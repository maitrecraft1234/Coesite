/*
** EPITECH PROJECT, 2024
** src/parser/block_size
** File description:
** utilities for block size
*/

#include "lexer/type.h"
#include "parser/macros.h"
#include "parser/type.h"

size_t parser_block_size(parser_t *parser)
{
    size_t initial_index = parser->lexem_index;
    size_t indent = 1;

    if (CUR_LEXEM(parser).type != LX_BRACKET_OPEN)
        TODO;
    for (parser->lexem_index++; indent; parser->lexem_index++) {
        switch (CUR_LEXEM(parser).type) {
            case LX_BRACKET_OPEN:
                indent++;
                continue;
            case LX_BRACKET_CLOSE:
                indent--;
            default:
                continue;
        }
    }
    indent = parser->lexem_index - initial_index;
    parser->lexem_index = initial_index;
    return indent;
}
