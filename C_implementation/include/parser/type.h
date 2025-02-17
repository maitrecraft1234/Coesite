/*
** EPITECH PROJECT, 2024
** include/parser/type
** File description:
** parser types and stuff
*/

#ifndef PARSER_TYPE_H
    #define PARSER_TYPE_H

    #include <lexer/type.h>
    #include <stddef.h>
    #include <parser/grammar_types/meth/definition.h>
    #include <parser/grammar_types/general.h>

typedef struct def_s {
    union {
        pgm_def_t meth;
        struct pg_global_s {
            pg_lit_primitive_t val;
            pg_identifier_t name;
        } global;
    };
    enum {
        PD_METH,
        PD_GLOBAL,
        PD_ERR,
    } type;
} px_def_t;

typedef struct parser_s {
    px_def_t *defs;
    lexem_t *lexems;
    size_t lexem_index;
    tokenizer_t *tokenizer; // code info for error handling
} parser_t;


#endif
