/*
** EPITECH PROJECT, 2024
** src/parser/meth/statment
** File description:
** statement parser for meth
*/

#include <parser/grammar_types/meth/type_tag.h>
#include <parser/grammar_types/meth/statement.h>
#include <parser/grammar_types/meth/block.h>
#include <parser/macros.h>
#include <parser/function.h>
#include "general/macros.h"
#include "lexer/type.h"
#include "tokenizer/functions.h"
#include "tokenizer/types.h"

// this is a horrible way to do this but whatever
static pgm_statement_t helper_error(parser_t *parser, char *expected,
    pgm_statement_t *statement)
{
    lexem_t cur = CUR_LEXEM(parser);

    if (cur.type != LX_EO_EXPR)
        parser_error(parser, expected);
    parser_skip_past_next(parser, LX_EO_EXPR);
    return *statement;
}

pgm_statement_t pgm_statement(parser_t *parser)
{
    pgm_statement_t statement = {0};
    lexem_t cur = CUR_LEXEM(parser);

    switch (cur.type) {
        case TK_LET:
            statement.type = PGM_DECL;
            statement.decl = pgm_decl(parser);
            break;
        case TK_RETURN:
            statement.type = PGM_RETURN;
            ++parser->lexem_index;
            statement.ret = pgm_expression(parser);
            break;
        default:
            statement.type = PGM_EXPRESSION;
            statement.expr = pgm_expression(parser);
    }
    return helper_error(parser, ";", &statement);
}
