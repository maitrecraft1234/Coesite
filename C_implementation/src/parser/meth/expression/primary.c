/*
** EPITECH PROJECT, 2024
** src/parser/meth/expression/primary
** File description:
** parsing primary expression member and whatnot
*/

#include <parser/type.h>
#include <parser/macros.h>
#include <parser/function.h>
#include "general/macros.h"
#include "lexer/type.h"
#include "parser/grammar_types/meth/expression.h"
#include "parser/grammar_types/meth/type_tag.h"

// note that refactoring this into some more x macros
// is needed for coding style although a table could work as well
static void helper_id_type(parser_t *parser, pgmx_primary_t *primary)
{
    switch (CUR_LEXEM(parser).type) {
        case LX_LIT_INT:
        case LX_LIT_FLOAT:
        case LX_LIT_STR:
        case LX_LIT_BOOL:
        case LX_IDENTIFER:
            primary->type = PGM_LITERAL;
            primary->literal = pgm_expr_literal(parser);
            break;
        case LX_OP_PLUS:
        case LX_OP_MINUS:
            primary->type = PGM_UNARY;
            primary->unary = pgm_expr_unary(parser);
            break;
        case LX_PAR_OPEN:
            primary->type = PGM_GROUPING;
            primary->grouping = pgm_expr_grouping(parser);
            break;
        case LX_BRACKET_OPEN:
            primary->type = PGM_BLOCK;
            HEAPIFY(primary->block, pgm_block(parser));
            break;
    }
}

pgmx_primary_t pgm_expr_primary(parser_t *parser)
{
    pgmx_primary_t primary;

    helper_id_type(parser, &primary);
    return primary;
}
