/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/parser/type
** File description:
** parser types and stuff
*/

#ifndef PARSER_TYPE_H
    #define PARSER_TYPE_H

    #include <general/btree.h>
    #include <lexer/type.h>
    #include "parser/grammar_types/meth/definition.h"
    #include <parser/grammar_types/general.h>

typedef struct def_s {
    union {
        pgm_def_t meth;
    };
    enum {
        PD_METH,
        PD_ERR,
    } type;
    pg_attribute_t attributes;
} px_def_t;

typedef struct parser_s {
    px_def_t *defs;
    lexem_t *lexems;
    size_t lexem_index;
} parser_t;


#endif
