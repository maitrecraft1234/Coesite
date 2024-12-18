/*
** EPITECH PROJECT, 2024
** src/parser/meth/expression/literal
** File description:
** litterals and whatnot
*/

#include <parser/type.h>
#include <parser/macros.h>
#include <parser/function.h>
#include <assert.h>
#include <general/macros.h>
#include "lexer/type.h"

pgmx_literal_t pgm_expr_literal(parser_t *parser)
{
    pgmx_literal_t literal = {0};
    lexem_t lexem = parser_consume_lexem(parser);

    if (lexem.type == LX_IDENTIFER) {
        literal.type = PGM_IDENTIFIER;
        literal.identifier = pgm_identifier(parser);
        return literal;
    }
    if (lexem.type == LX_LIT_INT || lexem.type == LX_LIT_STR ||
            lexem.type == LX_LIT_BOOL) {
        literal.type = PGM_LITERAL;
        literal.literal = pgm_lit_primitive(parser);
        return literal;
    }
    UNREACHABLE;
}
