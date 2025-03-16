/*
** EPITECH PROJECT, 2025
** include/interpretor/builtins/mulitive_global
** File description:
** global declaration coz its goota be in a head whatever the reason
*/

#ifndef INTERPRETOR_ADDITIVE_GLOBAL_H_
    #define INTERPRETOR_ADDITIVE_GLOBAL_H_

    #include "interpretor/builtins/mutliplicative.h"
    #include "parser/grammar_types/general.h"

pg_lit_primitive_t (*const mul_lookup[PGT_COUNT]) (pg_lit_primitive_t *,
    pg_lit_primitive_t *) = {
    [PGT_U64] = ibf_mul_u64,
    [PGT_INT] = ibf_mul_u64,
    [PGT_STRING] = ibf_mul_string,
    [PGT_BOOL] = ibf_mul_bool,
};

pg_lit_primitive_t (*const div_lookup[PGT_COUNT]) (pg_lit_primitive_t *,
    pg_lit_primitive_t *) = {
    [PGT_U64] = ibf_div_u64,
    [PGT_INT] = ibf_div_u64,
    [PGT_STRING] = ibf_div_string,
    [PGT_BOOL] = ibf_div_bool,
};

#endif
