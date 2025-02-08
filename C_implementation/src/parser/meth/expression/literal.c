/*
** EPITECH PROJECT, 2024
** src/parser/meth/expression/terminal
** File description:
** litterals and whatnot
*/

#include <parser/type.h>
#include <parser/macros.h>
#include <parser/function.h>
#include <assert.h>
#include <general/macros.h>
#include "lexer/type.h"
#include "parser/grammar_types/meth/expression.h"
#include "general/dynamic_array.h"

static void pgmx_fn_call(parser_t *parser, pgmx_terminal_t *terminal,
    lexem_t *lexem)
{
    pgm_expression_t arg = {0};

    terminal->type = PGM_FN_CALL;
    terminal->fn_call.name = lexem->chars;
    terminal->fn_call.size = lexem->len;
    terminal->fn_call.meth_args = da_create();
    for (lexem_t l = parser_consume_lexem(parser); l.type != LX_PAR_CLOSE;) {
        arg = pgm_expression(parser);
        DA_PUSH(terminal->fn_call.meth_args, arg);
        l = parser_consume_lexem(parser);
        if (l.type == LX_PAR_CLOSE)
            return;
        if (l.type == LX_COMMA)
            continue;
        else {
            parser_error(parser, "',' or ')'");
            return;
        }
    }
}

static pgmx_terminal_t pgm_identifier(parser_t *parser)
{
    pgmx_terminal_t identifier = {0};
    lexem_t lexem = parser_consume_lexem(parser);

    assert(lexem.type == LX_IDENTIFIER);
    if (CUR_LEXEM(parser).type == LX_PAR_OPEN) {
        pgmx_fn_call(parser, &identifier, &lexem);
    } else {
        identifier.type = PGM_IDENTIFIER;
        identifier.identifier.name = lexem.chars;
        identifier.identifier.size = lexem.len;
    }
    return identifier;
}

pgmx_terminal_t pgm_expr_terminal(parser_t *parser)
{
    pgmx_terminal_t terminal = {0};
    lexem_t lexem = CUR_LEXEM(parser);

    if (lexem.type == LX_IDENTIFIER) {
        return pgm_identifier(parser);
    }
    if (lexem.type == LX_LIT_INT || lexem.type == LX_LIT_STR ||
            lexem.type == LX_LIT_BOOL) {
        terminal.type = PGM_LITERAL;
        terminal.literal = pg_lit_primitive(parser);
        return terminal;
    }
    UNREACHABLE;
}
