/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/parser/type
** File description:
** parser types and stuff
*/

#ifndef PARSER_TYPE_H
    #define PARSER_TYPE_H

#include "general/btree.h"
#include "lexer/type.h"

typedef struct expr_s {
    btree_t *parsed_expr;
} expr_t;

typedef struct parser_s {
    expr_t *expr;
    lexem_t *lexems;
    size_t lexem_index;
} parser_t;


#endif
