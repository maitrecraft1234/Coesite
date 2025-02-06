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

// some additional logic for function calls will
// probably come here
static pgmx_terminal_t pgm_identifier(parser_t *parser)
{
    pgmx_terminal_t identifier = {0};
    lexem_t lexem = parser_consume_lexem(parser);

    assert(lexem.type == LX_IDENTIFER);
    identifier.type = PGM_IDENTIFIER;
    identifier.identifier.name = lexem.chars;
    identifier.identifier.size = lexem.len;
    return identifier;
}

pgmx_terminal_t pgm_expr_terminal(parser_t *parser)
{
    pgmx_terminal_t terminal = {0};

    lexem_t lexem = CUR_LEXEM(parser);

    if (lexem.type == LX_IDENTIFER) {
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
