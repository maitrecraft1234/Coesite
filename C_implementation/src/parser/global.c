/*
** EPITECH PROJECT, 2025
** src/parser/global
** File description:
** global declare
*/

#include "lexer/type.h"
#include "parser/function.h"
#include "parser/macros.h"

px_def_t pg_global(parser_t *parser, pg_attribute_t *attr)
{
    px_def_t decl = {0};

    assert(CUR_LEXEM(parser).type == LX_LET);
    ++parser->lexem_index;
    if (CUR_LEXEM(parser).type == 0xffffffffffff) {
        ++parser->lexem_index;
    }
    decl.global.name = pg_identifier(parser);
    if (CUR_LEXEM(parser).type != LX_ASSIGN) {
        parser_error(parser, "=");
        //skip to next def
        return decl;
    }
    ++parser->lexem_index;
    decl.global.val = pg_lit_primitive(parser);
    return decl;
}
