/*
** EPITECH PROJECT, 2025
** src/parser/pretty_printer/print
** File description:
** whateva I be printin
*/

#include <parser/type.h>
#include <stddef.h>
#include <stdio.h>
#include "lexer/functions.h"
#include "parser/macros.h"
#include "parser/print/functions.h"
#include <general/dynamic_array.h>

void parser_dump_def(px_def_t *def)
{
    switch (def->type) {
        case PD_METH:
            return parser_dump_meth(&def->meth);
        case PD_ERR:
            return (void)puts("def invalid syntax node");
        default:
            return (void)puts("AST Provided is invalid at top level def");
    }
}

void parser_dump(parser_t *parser)
{
    if (DA_LEN(parser->lexems) == 0 && CUR_LEXEM(parser).type != LX_EOP) {
        puts("lexems not parsed");
        for (size_t i = 0; i < DA_LEN(parser->lexems); ++i) {
            lexem_dbg_print(&parser->lexems[i]);
        }
        return;
    }
    puts("ast dump");
    for (size_t i = 0; i < DA_LEN(parser->defs); ++i)
        parser_dump_def(&parser->defs[i]);
}
