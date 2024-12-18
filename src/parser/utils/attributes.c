/*
** EPITECH PROJECT, 2024
** src/parser/utils/attributes
** File description:
** utility for parsin declaration attributes
*/

#include <parser/grammar_types/general.h>
#include <errno.h>
#include <parser/type.h>
#include "lexer/macros.h"
#include "lexer/type.h"
#include <parser/macros.h>

//static ssize_t helper_count_attributes(parser_t *parser)
//{
//}

#warning for now attributes are skipped
pg_attribute_t parser_get_attributes(parser_t *parser)
{
    pg_attribute_t attributes = {0};
    lexem_id_t cur = CUR_LEXEM(parser).type;

    if (cur != LX_BRACKET_OPEN)
        return (pg_attribute_t){0};
    while (cur != LX_EOP) {
        ++parser->lexem_index;
        if (cur == LX_BRACKET_CLOSE) {
            ++parser->lexem_index;
            return (pg_attribute_t){0};
        }
    }
    errno = 1;
    return (pg_attribute_t){0};
}
