/*
** EPITECH PROJECT, 2024
** src/parser/meth/decl
** File description:
** parse declaration for meth
*/

#include <parser/function.h>

// static pgm_def_t helper_pgm_def(parser_t *parser)
// TODO

px_def_t pgm_def(parser_t *parser)
{
    px_def_t def = {0};

    def.type = PD_METH;
    def.meth = helper_pgm_def(parser);
    return def;
}
