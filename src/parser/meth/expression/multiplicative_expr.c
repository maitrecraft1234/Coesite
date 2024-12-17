/*
** EPITECH PROJECT, 2024
** /home/vj/test/language_name_unkown/src/parser/meth/expression/multiplicative_expr
** File description:
** multiplicative expression parser
*/

#include <parser/type.h>
#include "general/macros.h"
#include "lexer/type.h"
#include "parser/macros.h"

static bool is_multiplicative_operator(lexem_id_t id)
{
    switch (id) {
        case LX_OP_MUL:
        case LX_OP_DIV:
            return true;
        default:
            return false;
    }
}

pgmx_multiplicative_t pgm_expr_multiplicative(parser_t *parser)
{
    pgmx_multiplicative_t multiplicative = {.ops = da_create(), .left = da_create()};

    for (lexem_t cur = CUR_LEXEM(parser); is_multiplicative_operator(cur.type);
            cur = CUR_LEXEM(parser)) {
        DA_PUSH(multiplicative.ops, cur.type);
        ++parser->lexem_index;
        DA_PUSH(multiplicative.left, pgm_expr_primary(parser));
    }
    return multiplicative;
}
