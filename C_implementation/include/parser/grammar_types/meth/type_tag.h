/*
** EPITECH PROJECT, 2024
** include/parser/grammar_types/meth/type_tag
** File description:
** list of relevant type for tagged unions (this is good because is
** prevents conflits and allows for the union to be the explicit enum)
*/

#ifndef METH_TYPE_TAG_H_
    #define METH_TYPE_TAG_H_

typedef enum {
    PGM_LITERAL,
    PGM_STATEMENT,
    PGM_BLOCK,
    PGM_EXPRESSION,
    PGM_DECL,
    PGM_IF,
    PGM_WHILE,
    PGM_ELSE,
    PGM_RETURN,
    PGM_GROUPING,
    PGM_IDENTIFIER,
    PGM_UNARY,
    PGM_MULTIPLICATIVE,
    PGM_ADDITIVE,
    PGM_PRIMARY,
    PGM_TERMINAL,
    PGM_FN_CALL,
    PGM_ASSIGNMENT,
    PGM_ERROR,
} meth_tag_t;

#endif
