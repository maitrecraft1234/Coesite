/*
** EPITECH PROJECT, 2024
** src/parser/run
** File description:
** run the parser and whatnot
*/

#include "general/macros.h"
#include "lexer/functions.h"
#include "lexer/type.h"
#include "parser/type.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/definition.h"
#include "parser/function.h"
#include "parser/macros.h"
#include "parser/global.h"

static void helper_error(parser_t *parser)
{
    static const px_def_t err = {.type = PD_ERR};

    parser_error(parser, "definintion");
    DA_PUSH(parser->defs, err);
}

void parser_run(parser_t *parser)
{
    px_def_t def;
    pg_attribute_t attributes = parser_get_attributes(parser);
    lexem_t lexem = CUR_LEXEM(parser);
    px_def_t (*act)(parser_t *, pg_attribute_t *) = 0;

    while (lexem.type != LX_EOP) {
        act = (typeof(act))parsing_action[lexem.type];
        if (!act)
            helper_error(parser);
        else {
            def = act(parser, &attributes);
            parser->defs = da_push(parser->defs, &def, sizeof def);
        }
        da_destroy(attributes.attributes);
        attributes = parser_get_attributes(parser);
        lexem = CUR_LEXEM(parser);
    }
    da_destroy(attributes.attributes);
}
