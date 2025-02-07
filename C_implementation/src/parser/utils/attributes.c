/*
** EPITECH PROJECT, 2024
** src/parser/utils/attributes
** File description:
** utility for parsin declaration attributes
*/

#include "general/dynamic_array.h"
#include <parser/grammar_types/general.h>
#include <errno.h>
#include <parser/type.h>
#include "lexer/macros.h"
#include "lexer/type.h"
#include "parser/function.h"
#include <parser/macros.h>

pg_attribute_t parser_get_attributes(parser_t *parser)
{
    pg_attribute_t attributes = {.attributes = da_create()};
    lexem_t cur = CUR_LEXEM(parser);

    if (cur.type != LX_BRACKET_OPEN)
        return attributes;
    for (; cur.type != LX_EOP; cur = parser_consume_lexem(parser)) {
        if (cur.type == LX_BRACKET_CLOSE)
            return attributes;
        DA_PUSH(attributes.attributes, cur);
    }
    parser_error(parser, "']'");
    return attributes;
}
