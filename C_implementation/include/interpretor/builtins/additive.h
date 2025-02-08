/*
** EPITECH PROJECT, 2025
** include/interpretor/builtins/additive
** File description:
** additive fuctnio proto
*/

#ifndef INTERPRETOR_BUILTINS_ADDITIVE_H_
    #define INTERPRETOR_BUILTINS_ADDITIVE_H_

    #include "parser/grammar_types/general.h"

extern pg_lit_primitive_t ibf_add_u64(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);
extern pg_lit_primitive_t ibf_add_string(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);
extern pg_lit_primitive_t ibf_add_bool(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);

extern pg_lit_primitive_t ibf_sub_u64(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);
extern pg_lit_primitive_t ibf_sub_string(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);
extern pg_lit_primitive_t ibf_sub_bool(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);

extern pg_lit_primitive_t (*const add_lookup[])(pg_lit_primitive_t *,
    pg_lit_primitive_t *);
extern pg_lit_primitive_t (*const sub_lookup[])(pg_lit_primitive_t *,
    pg_lit_primitive_t *);

#endif
