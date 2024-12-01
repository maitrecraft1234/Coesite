/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/run
** File description:
** run the parser and whatnot
*/

#include "general/macros.h"
#include "lexer/functions.h"
#include "lexer/type.h"
#include "parser/type.h"
#include "general/dynamic_array.h"
#include "parser/function.h"
#include "parser/macros.h"

static const px_def_t (*parsing_action[] )(parser_t *) = {
    [LX_METH] = pgm_decl;
};

void parser_run(parser_t *parser)
{
    px_def_t def;
    lexem_t lexem = CUR_LEXEM(parser);
    lexem_id_t ctype = lexem.type;
    const px_def_t (*act)(parser_t *) = 0;

    while (ctype != LX_EOP) {
        act = parsing_action[ctype];
        if (!act)
            TODO;
        def = act(parser);
        parser->defs = da_push(parser->defs, &def, sizeof def);
        lexem = CUR_LEXEM(parser);
        ctype = lexem.type;
    }
}
