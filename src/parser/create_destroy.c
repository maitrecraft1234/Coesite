/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/create
** File description:
** parser creation deletion
*/

#include "general/btree.h"
#include "lexer/type.h"
#include "parser/type.h"
#include "general/dynamic_array.h"

parser_t parser_create(void)
{
    parser_t parser;

    parser.expr = da_create();
    parser.lexems = NULL;
    parser.lexem_index = 0;
    return parser;
}

void parser_destroy(parser_t *parser)
{
    da_destroy(parser->expr);
    da_destroy(parser->lexems);
}
