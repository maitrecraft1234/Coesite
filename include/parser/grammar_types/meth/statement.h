/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/parser/grammar_types/meth/statement
** File description:
** statement ebnf like types
*/

#ifndef PGM_STATEMENT_H_
    #define PGM_STATEMENT_H_

    #include "type_tag.h"
    #include "expression.h"

typedef struct {
    //type
    pgm_expression_t expr;
} pgm_decl_t;

typedef struct pgm_statement {
    union {
        pgm_expression_t expr;
        pgm_decl_t decl;
        pgm_expression_t ret;
    };
    meth_tag_t type;
} pgm_statement_t;

#endif
