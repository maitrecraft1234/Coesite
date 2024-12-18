/*
** EPITECH PROJECT, 2024
** include/parser/grammar_types/meth/block
** File description:
** meth block
*/

#ifndef PGM_BLOCK_H_
    #define PGM_BLOCK_H_
    #include "type_tag.h"
    #include "statement.h"

typedef struct pgm_block_s {
    struct pgm_block_el_s {
        union {
            pgm_statement_t statment;
            struct pgm_block_s *block;
        };
        meth_tag_t type;
    }
    *pgm_block_el;
} pgm_block_t;

#endif
