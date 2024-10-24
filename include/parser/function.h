/*
** EPITECH PROJECT, 2024
** include/parser/function
** File description:
** parser functions
*/

#ifndef PARSER_FUNCTION_H

    #define PARSER_FUNCTION_H
    #include "parser/type.h"

extern parser_t parser_create(void);
extern void parser_destroy(parser_t *parser);
extern parser_t parser_create_from_lexems(lexem_t *lexems);
extern expr_t parser_parse_statement(parser_t *parser);
extern void parser_run(parser_t *parser);

#endif
