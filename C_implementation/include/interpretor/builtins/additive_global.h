/*
** EPITECH PROJECT, 2025
** include/interpretor/builtins/additive_global
** File description:
** global declaration coz its goota be in a head whatever the reason
*/

#ifndef INTERPRETOR_ADDITIVE_GLOBAL_H_
    #define INTERPRETOR_ADDITIVE_GLOBAL_H_

    #include "interpretor/builtins/additive.h"
    #include "parser/grammar_types/general.h"

pg_lit_primitive_t (*const add_lookup[PGT_COUNT]) (pg_lit_primitive_t *,
    pg_lit_primitive_t *) = {
    [PGT_U64] = ibf_add_u64,
    [PGT_INT] = ibf_add_u64,
    [PGT_STRING] = ibf_add_string,
    [PGT_BOOL] = ibf_add_bool,
};

pg_lit_primitive_t (*const sub_lookup[PGT_COUNT]) (pg_lit_primitive_t *,
    pg_lit_primitive_t *) = {
    [PGT_U64] = ibf_sub_u64,
    [PGT_INT] = ibf_sub_u64,
    [PGT_STRING] = ibf_sub_string,
    [PGT_BOOL] = ibf_sub_bool,
};

#endif
