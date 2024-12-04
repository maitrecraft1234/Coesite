/*
** EPITECH PROJECT, 2024
** include/parser/function
** File description:
** parser functions
*/

#ifndef PARSER_FUNCTION_H

    #define PARSER_FUNCTION_H
    #include "parser/type.h"
    #include "parser/grammar_types/general.h"

extern parser_t parser_create(void);
extern void parser_destroy(parser_t *parser);
extern parser_t parser_create_from_lexems(lexem_t *lexems);
/* extern expr_t parser_parse_statement(parser_t *parser); */
extern void parser_run(parser_t *parser);
extern size_t parser_block_size(parser_t *parser);

extern px_def_t pgm_decl(parser_t *parser);
extern pg_attribute_t parser_get_attributes(parser_t *parser);
extern pgm_block_t pgm_block(parser_t *parser);

#endif
