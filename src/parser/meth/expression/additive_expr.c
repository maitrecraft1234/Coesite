/*
** EPITECH PROJECT, 2024
** /home/vj/test/language_name_unkown/src/parser/meth/expression/additive_expr
** File description:
** additive expression and utils
*/

#include <parser/type.h>
#include "general/macros.h"
#include "lexer/type.h"
#include "parser/macros.h"
#include "tokenizer/types.h"
#include <general/dynamic_array.h>
#include <parser/function.h>

// if we get to many operators we could expand this switch
// through x-macros to keep it clean and performant
static bool is_additive_operator(lexem_id_t id)
{
    switch (id) {
        case LX_OP_PLUS:
        case LX_OP_MINUS:
            return true;
        default:
            return false;
    }
}

#error I need to fix this and multiplicative_expr.c (I mistook left for an array)
pgmx_additive_t pgm_expr_additive(parser_t *parser)
{
    pgmx_additive_t additive = {.ops = da_create()};

    for (lexem_t cur = CUR_LEXEM(parser); is_additive_operator(cur.type);
            cur = CUR_LEXEM(parser)) {
        DA_PUSH(additive.ops, cur.type);
        ++parser->lexem_index;
        DA_PUSH_FUNC(additive.right, pgm_expr_multiplicative(parser));
    }
    return additive;
}
