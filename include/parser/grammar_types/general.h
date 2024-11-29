/*
** EPITECH PROJECT, 2024
** include/parser/grammar_types/general
** File description:
** general grammar rules
*/

#ifndef PGM_GENERAL_H_
    #define PGM_GENERAL_H_

    #include "lexer/type.h"

typedef struct pgm_identifier_s {
    char *name;
} pg_identifier_t;

typedef struct pgm_literal_s {
    lexem_id_t type;
    void *value;
} pg_literal_t;

#endif
