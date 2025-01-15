/*
** EPITECH PROJECT, 2025
** src/parser/pretty_printer/meth/declaration
** File description:
** pretty printer for meth statement deckaration
*/

#include <parser/print/functions.h>

void parser_dump_meth_declaration(pgm_decl_t *decl)
{
    printf("let %.*s: type", (int)decl->var_name.size, decl->var_name.name);
    printf(" = ");
    parser_dump_meth_expression(&decl->expr);
    printf(";\n");
}
