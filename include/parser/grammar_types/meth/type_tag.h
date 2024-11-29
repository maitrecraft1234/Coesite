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
    PGM_STATEMET,
    PGM_BLOCK,
    PGM_EXPRESSION,
    PGM_DECL,
    PGM_RETURN,
    PGM_GROUPING,
    PGM_LITERAL,
    PGM_IDENTIFIER,
    PGM_UNARY,
    PGM_MULTIPLICATIVE,
    PGM_ADDITIVE,
    PGM_PRIMARY
} meth_tag_t;

#endif
