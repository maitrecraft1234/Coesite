/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/parser/statement
** File description:
** parese epr
*/

#include "lexer/type.h"
#include "parser/type.h"
#include "parser/macros.h"
#include "general/macros.h"

#error TODO all these proto
expr_t parser_parse_declaration(parser_t *parser);
expr_t parser_error(parser_t *parser);

expr_t parser_parse_statement(parser_t *parser)
{
    switch (CUR_LEXEM(parser).type) {
        CASE(lx_eo_expr) {
            ++parser->lexem_index;
            return parser_parse_statement(parser);
        }
        CASE(lx_let)
            return parser_parse_declaration(parser);
        CASE(lx_identifer)
            return (expr_t){};
        default:
            parser_error(parser);
    }
}
