/*
** EPITECH PROJECT, 2025
** src/parser/pretty_printer/meth/statement
** File description:
** parser pretty printer for statements
*/

#include "general/macros.h"
#include "parser/print/functions.h"
#include "parser/grammar_types/meth/type_tag.h"

void parser_dump_meth_return(pgm_expression_t *ret)
{
    printf("return ");
    parser_dump_meth_expression(ret);
    printf(";\n");
}

void parser_dump_meth_statement(pgm_statement_t *stm)
{
    switch (stm->type) {
        case PGM_DECL:
            return parser_dump_meth_declaration(&stm->decl);
        case PGM_EXPRESSION:
            return parser_dump_meth_expression(&stm->expr);
        case PGM_RETURN:
            return parser_dump_meth_return(&stm->ret);
        default:
            UNREACHABLE;
    }
    printf(";\n");
}
