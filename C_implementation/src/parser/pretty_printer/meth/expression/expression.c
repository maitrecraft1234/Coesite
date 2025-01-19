/*
** EPITECH PROJECT, 2025
** src/parser/pretty_printer/meth/expression
** File description:
** pretty printer for expression
*/

#include "parser/grammar_types/meth/expression.h"
#include <stdio.h>
#include "general/macros.h"
#include "lexer/functions.h"
#include "parser/print/functions.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/meth/type_tag.h"


void parser_dump_meth_expr_mul(pgmx_multiplicative_t *expr)
{
    printf("(");
    parser_dump_meth_primary(&expr->left);
    for (size_t i = 0; i < DA_LEN(expr->ops); ++i) {
        lexem_dbg_id_print(expr->ops[i].operator);
        parser_dump_meth_primary(&expr->ops[i].right);
    }
    printf(")");
}

void parser_dump_meth_expression(pgm_expression_t *expr)
{
    printf("(");
    parser_dump_meth_expr_mul(&expr->left);
    for (size_t i = 0; i < DA_LEN(expr->ops); ++i) {
        lexem_dbg_id_print(expr->ops[i].operator);
        parser_dump_meth_expr_mul(&expr->ops[i].right);
    }
    printf(")");
}
