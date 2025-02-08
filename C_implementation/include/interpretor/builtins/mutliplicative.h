/*
** EPITECH PROJECT, 2025
** include/interpretor/builtins/multiplicative
** File description:
** mulitive fuctnio proto
*/

#ifndef INTERPRETOR_BUILTINS_MULTIPLICATIVE_H_
    #define INTERPRETOR_BUILTINS_MULTIPLICATIVE_H_

    #include "parser/grammar_types/general.h"

extern pg_lit_primitive_t ibf_mul_u64(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);
extern pg_lit_primitive_t ibf_mul_string(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);
extern pg_lit_primitive_t ibf_mul_bool(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);

extern pg_lit_primitive_t ibf_div_u64(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);
extern pg_lit_primitive_t ibf_div_string(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);
extern pg_lit_primitive_t ibf_div_bool(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);

extern pg_lit_primitive_t (*const mul_lookup[])
    (pg_lit_primitive_t *, pg_lit_primitive_t *);
extern pg_lit_primitive_t (*const div_lookup[])
    (pg_lit_primitive_t *, pg_lit_primitive_t *);

#endif
