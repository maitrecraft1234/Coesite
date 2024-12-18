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
#include "parser/function.h"
#include "parser/macros.h"
#include "parser/global.h"

void parser_run(parser_t *parser)
{
    px_def_t def;
    lexem_t lexem = CUR_LEXEM(parser);
    lexem_id_t ctype = lexem.type;
    px_def_t (*act)(parser_t *, pg_attribute_t *) = 0;
    pg_attribute_t attributes;

    while (ctype != LX_EOP) {
        act = parsing_action[ctype];
        attributes = parser_get_attributes(parser);
        if (!act)
            TODO;
        def = act(parser, &attributes);
        def.attributes = attributes;
        parser->defs = da_push(parser->defs, &def, sizeof def);
        lexem = CUR_LEXEM(parser);
        ctype = lexem.type;
    }
}
