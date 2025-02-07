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
    printf("meth_def: ");
    fwrite(meth->name.name, 1, meth->name.size, stdout);
    putchar('\n');
    parser_dump_meth_block(&meth->block);
}
