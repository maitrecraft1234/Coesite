/*
** EPITECH PROJECT, 2024
** src/parser/meth/decl
** File description:
** parse declaration for meth
*/

#include <parser/function.h>
#include <string.h>
#include "general/macros.h"
#include "lexer/functions.h"
#include "general/dynamic_array.h"
#include "lexer/type.h"
#include "parser/type.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/definition.h"
#include <parser/macros.h>
#include <assert.h>

static pgm_attribute_t helper_pgm_attr(pg_attribute_t *attributes)
{
    pgm_attribute_t attr;

    for (size_t i = 0; i < DA_LEN(attributes->attributes); ++i) {
        if (attributes->attributes->type == LX_PURE) {
            attr.pure = true;
            continue;
        }
        if (attributes->attributes->type == LX_NORETURN) {
            attr.no_return = true;
            continue;
        }
        if (attributes->attributes->type == LX_ENTRY) {
            attr.entry = true;
            continue;
        }
    }
    return attr;
}

static pgm_args_t helper_error(parser_t *parser, char *expected)
{
    pgm_args_t res = {0};

    parser_error(parser, expected);
    return res;
}

pgm_args_t pgm_def_args(parser_t *parser)
{
    pgm_args_t args;
    pgm_arg_t arg = {0};

    if (CUR_LEXEM(parser).type != LX_PAR_OPEN)
        return helper_error(parser, "(");
    ++parser->lexem_index;
    while (CUR_LEXEM(parser).type != LX_PAR_CLOSE) {
        if (CUR_LEXEM(parser).type == LX_COMMA)
            ++parser->lexem_index;
        if (CUR_LEXEM(parser).type != LX_IDENTIFIER)
            return helper_error(parser, "identifier");
        arg.name.name = CUR_LEXEM(parser).chars;
        arg.name.size = CUR_LEXEM(parser).len;
        ++parser->lexem_index;
        DA_PUSH(args, arg);
    }
    ASSERT_CUR_IS(parser, LX_PAR_CLOSE);
    ++parser->lexem_index;
    return args;
}

static pgm_def_t helper_pgm_def(parser_t *parser, pg_attribute_t *attr)
{
    pgm_def_t res = {.attributes = helper_pgm_attr(attr)};

    res.name.name = CUR_LEXEM(parser).chars;
    res.name.size = CUR_LEXEM(parser).len;
    ++parser->lexem_index;
    res.args = pgm_def_args(parser);
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
