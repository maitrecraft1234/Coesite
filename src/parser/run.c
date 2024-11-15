/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/run
** File description:
** run the parser and whatnot
*/

#include "general/macros.h"
#include "lexer/functions.h"
#include "lexer/type.h"
#include "parser/dbg/functions.h"
#include "parser/type.h"
#include "general/dynamic_array.h"
#include "parser/function.h"
#include "parser/macros.h"

void parser_run(parser_t *parser)
{
    px_def_t def;

    while (CUR_LEXEM(parser).type != lx_eof) {
        /* def = parser_parse_def(parser); */
        if (CUR_LEXEM(parser).type == lx_dbg) {
            ++parser->lexem_index;
            def.dbg = parser_parse_dbg(parser);
            def.type = px_dbg_e;
        } else {
            lexem_t lexem = CUR_LEXEM(parser);
            TODO_NOBLOCK;
            lexem_dbg_print(&lexem);
            return; //
        }
        parser->defs = da_push(parser->defs, &def, sizeof def);
    }
}
