/*
** EPITECH PROJECT, 2024
** include/parser/meth/types
** File description:
** C equivalent for the ebnf
*/

#ifndef PGM_DEFINITION_H_
    #define PGM_DEFINITION_H_

    #include <parser/grammar_types/meth/block.h>
    #include <parser/grammar_types/general.h>

typedef struct pgm_args *pgm_args_t;

//this is not ideal but it will do while
//attributes are purely boolean
typedef struct pgm_attribute_s {
    int no_return : 1;
    int pure : 1;
    int entry : 1; // this will change
} pgm_attribute_t;

typedef struct pgm_def_s {
    pgm_attribute_t attributes;
    pg_identifier_t name;
    pg_type_t return_type;
    pgm_args_t args;
    pgm_block_t block;
} pgm_def_t;
#endif
