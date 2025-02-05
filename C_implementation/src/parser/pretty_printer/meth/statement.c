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
}

void parser_dump_meth_statement(pgm_statement_t *stm)
{
    switch (stm->type) {
        case PGM_DECL:
            parser_dump_meth_declaration(&stm->decl);
            break;
        case PGM_EXPRESSION:
            parser_dump_meth_expression(&stm->expr);
            break;
        case PGM_RETURN:
            parser_dump_meth_return(&stm->ret);
            break;
        default:
            UNREACHABLE;
    }
    printf(";\n");
}
