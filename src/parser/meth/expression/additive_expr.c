/*
** EPITECH PROJECT, 2024
** /home/vj/test/language_name_unkown/src/parser/meth/expression/additive_expr
** File description:
** additive expression and utils
*/

#include <parser/type.h>
#include <assert.h>
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

pgmx_additive_t pgm_expr_additive(parser_t *parser)
{
    pgmx_additive_t additive = {.ops = da_create(),
        .left = pgm_expr_multiplicative(parser)};
    struct pgmx_additive_op_s op = {0};

    for (lexem_t cur = CUR_LEXEM(parser); is_additive_operator(cur.type);
            cur = CUR_LEXEM(parser)) {
        DA_PUSH(additive.ops, op);
        ++parser->lexem_index;
        assert(is_additive_operator(cur.type));
        DA_LAST(additive.ops).operator = cur.type;
        DA_LAST(additive.ops).right = pgm_expr_multiplicative(parser);
    }
    return additive;
}
