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
    #include "parser/grammar_types/meth/block.h"
    #include "parser/grammar_types/meth/statement.h"
    #include "parser/grammar_types/meth/expression.h"

extern parser_t parser_create(void);
extern void parser_destroy(parser_t *parser);
extern parser_t parser_create_from_lexems(lexem_t *lexems);
/* extern expr_t parser_parse_statement(parser_t *parser); */
extern void parser_run(parser_t *parser);
extern size_t parser_block_size(parser_t *parser);

//naming unclear for this one
extern pg_attribute_t parser_get_attributes(parser_t *parser);

// consume functions
extern lexem_id_t parser_consume_lexem_id(parser_t *parser);
extern lexem_t parser_consume_lexem(parser_t *parser);

// meth parsing functions
// these might allocate memory
// the destruction functions must be created for these
extern px_def_t pgm_def(parser_t *parser, pg_attribute_t *attr);
extern pgm_block_t pgm_block(parser_t *parser);
extern pgm_statement_t pgm_statement(parser_t *parser);
extern pgm_expression_t pgm_expression(parser_t *parser);
extern pgm_decl_t pgm_decl(parser_t *parser);
extern pgmx_additive_t pgm_expr_additive(parser_t *parser);
extern pgmx_multiplicative_t pgm_expr_multiplicative(parser_t *parser);
extern pgmx_primary_t pgm_expr_primary(parser_t *parser);
extern pgmx_grouping_t pgm_expr_grouping(parser_t *parser);
extern pgmx_unary_t pgm_expr_unary(parser_t *parser);

#endif
