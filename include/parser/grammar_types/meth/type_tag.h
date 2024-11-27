/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/parser/grammar_types/meth/type_tag
** File description:
** list of relevant type for tagged unions (this is good because is
** prevents conflits and allows for the union to be the explicit enum)
*/

#ifndef METH_TYPE_TAG_H_
#define METH_TYPE_TAG_H_

typedef enum {
    pgme_statemet,
    pgme_block,
    pgme_expression,
    pgme_decl,
    pgme_return,
    pgme_grouping,
    pgme_literal,
    pgme_identifier,
    pgme_unary,
    pgme_multiplicative,
    pgme_additive,
    pgme_primary
} meth_tag_t;

#endif
