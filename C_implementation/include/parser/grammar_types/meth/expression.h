/*
** EPITECH PROJECT, 2024
** include/parser/grammar_types/meth/expression
** File description:
** expression for meth
*/

#ifndef PGM_EXPRESSION_H_
    #define PGM_EXPRESSION_H_
    #include "parser/grammar_types/general.h"
    #include "type_tag.h"
    #include "lexer/type.h"

typedef struct pgmx_additive_s pgm_expression_t;

typedef struct {
    pgm_expression_t *expr;
} pgmx_grouping_t;

typedef struct {
    lexem_id_t operator;
    pgm_expression_t *expr;
} pgmx_unary_t;

typedef struct terminal_s {
    union {
        pg_lit_primitive_t literal;
        pg_identifier_t identifier;
    };
    meth_tag_t type;
} pgmx_terminal_t;

typedef struct {
    union {
        pgmx_terminal_t literal;
        pgmx_grouping_t grouping;
        pgmx_unary_t unary;
        struct pgm_block_s *block;
    };
    meth_tag_t type;
} pgmx_primary_t;

typedef struct {
    pgmx_primary_t left;
    struct {
        lexem_id_t operator;
        pgmx_primary_t right;
    } *ops;
} pgmx_multiplicative_t;

typedef struct pgmx_additive_s {
    pgmx_multiplicative_t left;
    struct pgmx_additive_op_s {
        lexem_id_t operator;
        pgmx_multiplicative_t right;
    } *ops;
} pgmx_additive_t;

#endif
