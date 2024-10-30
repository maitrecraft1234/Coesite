/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/run
** File description:
** run the parser and whatnot
*/

#include "parser/type.h"
#include "general/dynamic_array.h"
#include "parser/function.h"
#include "parser/macros.h"

void parser_run(parser_t *parser)
{
    px_def_t def;

    do {
        /* def = parser_parse_def(parser); */
        da_push(parser->defs, &def, sizeof def);
    } while (CUR_LEXEM(parser).type != lx_eof);
}
