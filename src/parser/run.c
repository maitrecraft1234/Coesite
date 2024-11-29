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

void parser_run(parser_t *parser)
{
    px_def_t def;
    lexem_t lexem;

    while (CUR_LEXEM(parser).type != LX_EOP) {
        if (CUR_LEXEM(parser).type == LX_DBG) {
            ++parser->lexem_index;
        } else {
            lexem = CUR_LEXEM(parser);
            TODO_NOBLOCK;
            lexem_dbg_print(&lexem);
            return;
        }
        parser->defs = da_push(parser->defs, &def, sizeof def);
    }
}
