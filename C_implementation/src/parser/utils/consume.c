/*
** EPITECH PROJECT, 2024
** /home/vj/test/language_name_unkown/src/parser/utils/consume
** File description:
** consumes a lexem and return it
*/

#include <parser/type.h>
#include <parser/macros.h>

lexem_t parser_consume_lexem(parser_t *parser)
{
    lexem_t lexem = CUR_LEXEM(parser);

    ++parser->lexem_index;
    return lexem;
}

lexem_id_t parser_consume_lexem_id(parser_t *parser)
{
    lexem_id_t type = CUR_LEXEM(parser).type;

    ++parser->lexem_index;
    return type;
}
