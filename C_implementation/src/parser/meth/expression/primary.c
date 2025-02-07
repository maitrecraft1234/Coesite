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

static void set_as_terminal(parser_t *parser, pgmx_primary_t *primary)
{
    primary->type = PGM_TERMINAL;
    primary->terminal = pgm_expr_terminal(parser);
}

static void set_as_unary(parser_t *parser, pgmx_primary_t *primary)
{
    primary->type = PGM_UNARY;
    primary->unary = pgm_expr_unary(parser);
}

static void helper_id_type(parser_t *parser, pgmx_primary_t *primary)
{
    switch (CUR_LEXEM(parser).type) {
        case LX_LIT_INT:
        case LX_LIT_FLOAT:
        case LX_LIT_STR:
        case LX_LIT_BOOL:
        case LX_IDENTIFER:
            return set_as_terminal(parser, primary);
        case LX_OP_PLUS:
        case LX_OP_MINUS:
            return set_as_unary(parser, primary);
        case LX_PAR_OPEN:
            primary->type = PGM_GROUPING;
            primary->grouping = pgm_expr_grouping(parser);
            break;
        case LX_BRACE_OPEN:
            primary->type = PGM_BLOCK;
            HEAPIFY(primary->block, pgm_block(parser));
        UNREACHABLE_DEFAULT;
    }
}

pgmx_primary_t pgm_expr_primary(parser_t *parser)
{
    pgmx_primary_t primary;

    helper_id_type(parser, &primary);
    return primary;
}
