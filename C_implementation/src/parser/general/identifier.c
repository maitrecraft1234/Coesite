/*
** EPITECH PROJECT, 2025
** src/parser/general/identifier
** File description:
** identifier
*/

#include "lexer/type.h"
#include "parser/function.h"
#include "parser/type.h"
#include "parser/grammar_types/general.h"

pg_identifier_t pg_identifier(parser_t *parser)
{
    lexem_t cur = parser_consume_lexem(parser);

    if (cur.type != LX_IDENTIFIER) {
        parser_error(parser, "identifier");
        return (pg_identifier_t){.size = 0, .name = 0};
    }
    return (pg_identifier_t){.size = cur.len, .name = cur.chars};
}
