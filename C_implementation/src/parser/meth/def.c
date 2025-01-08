/*
** EPITECH PROJECT, 2024
** src/parser/meth/decl
** File description:
** parse declaration for meth
*/

#include <parser/function.h>
#include <string.h>
#include "general/macros.h"
#include "lexer/type.h"
#include "parser/type.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/definition.h"
#include <parser/macros.h>

static pgm_attribute_t helper_pgm_attr(pg_attribute_t *attributes)
{
    pgm_attribute_t attr;

    for (size_t i = 0; i < DA_LEN(attributes->attributes); ++i) {
        /* if (attributes->attributes == LX_PURE) { */
        /*     attr.pure = true; */
        /*     continue; */
        /* } */
        /* if (attributes->lexems->type == LX_NORETURN) { */
        /*     attr.no_return = true; */
        /*     continue; */
        /* } */
        /* if (attributes->lexems->type == LX_ENTRY) { */
        /*     attr.entry = true; */
        /*     continue; */
        /* } */
        TODO;
    }
    return attr;
}

static pgm_def_t helper_pgm_def(parser_t *parser, pg_attribute_t *attr)
{
    pgm_def_t res = {.attributes = helper_pgm_attr(attr)};

    res.name.name = CUR_LEXEM(parser).chars;
    res.name.size = CUR_LEXEM(parser).len;
    ++parser->lexem_index;
    res.args = 0;
    TODO_NOBLOCK;
    res.block = pgm_block(parser);
    return res;
}

px_def_t pgm_def(parser_t *parser, pg_attribute_t *attributes)
{
    px_def_t def = {0};

    def.type = PD_METH;
    ++parser->lexem_index;
    def.meth = helper_pgm_def(parser, attributes);
    return def;
}
