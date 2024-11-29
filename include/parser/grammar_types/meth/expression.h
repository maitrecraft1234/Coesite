/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/parser/grammar_types/meth/expression
** File description:
** expression for meth
*/

#ifndef PGM_EXPRESSION_H_
    #define PGM_EXPRESSION_H_
    #include "type_tag.h"
    #include "lexer/type.h"

typedef struct pgmx_additive_s pgm_expression_t;

typedef struct {
    union {
        /* pgm_identifier_t identifier; */
        /* pgm_literal_t literal; */
        /* pgm_grouping_t grouping; */
        /* pgm_unary_t *unary; */
        /* pgm_block_t *block; */
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
    struct {
        lexem_id_t operator;
        pgmx_multiplicative_t right;
    } *ops;
} pgmx_additive_t;

#endif
