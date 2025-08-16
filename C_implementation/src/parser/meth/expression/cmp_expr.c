//this need to be added in the grammar

#include <parser/type.h>
#include <assert.h>
#include "general/macros.h"
#include "lexer/type.h"
#include "parser/macros.h"
#include "tokenizer/types.h"
#include <general/dynamic_array.h>
#include <parser/function.h>

static bool is_cmp_operator(lexem_id_t id)
{
    switch (id) {
        case LX_OP_CMP_GT:
        case LX_OP_CMP_LT:
        case LX_OP_CMP_GE:
        case LX_OP_CMP_LE:
        case LX_OP_CMP_EQ:
            return true;
        default:
            return false;
    }
}

pgmx_cmp_t pgm_expr_cmp(parser_t *parser)
{
    pgmx_cmp_t cmp = {.ops = da_create(),
        .left = pgm_expr_additive(parser)};
    struct pgmx_cmp_op_s op = {0};

    for (lexem_t cur = CUR_LEXEM(parser); is_cmp_operator(cur.type);
            cur = CUR_LEXEM(parser)) {
        DA_PUSH(cmp.ops, op);
        ++parser->lexem_index;
        assert(is_cmp_operator(cur.type));
        DA_LAST(cmp.ops).operator = cur.type;
        DA_LAST(cmp.ops).right = pgm_expr_additive(parser);
    }
    return cmp;
}
