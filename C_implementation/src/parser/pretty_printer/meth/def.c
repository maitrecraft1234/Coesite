/*
** EPITECH PROJECT, 2025
** src/parser/pretty_printer/meth/def
** File description:
** pretty printer for meth
*/

#include "parser/print/functions.h"

// still need to print attributes and all that jaz
void parser_dump_meth(pgm_def_t *meth)
{
    printf("meth_def: %.*s\n", (int)meth->name.size, meth->name.name);
    parser_dump_meth_block(&meth->block);
}
