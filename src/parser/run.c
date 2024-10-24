/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/run
** File description:
** run the parser and whatnot
*/

#include "parser/type.h"
#include "general/dynamic_array.h"
#include "parser/function.h"

void parser_run(parser_t *parser)
{
    expr_t expr;

    do {
        expr = parser_parse_statement(parser);
        da_push(parser->expr, &expr, sizeof expr);
    } while (DA_LEN(parser->lexems) < parser->lexem_index);
}
