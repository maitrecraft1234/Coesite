//this is incomplete for now but it doens
//t matter too much I don't think
#ifndef INTERPRETOR_CMP_GLOBAL_H_
    #define INTERPRETOR_CMP_GLOBAL_H_

    #include "interpretor/builtins/cmp.h"
    #include "parser/grammar_types/general.h"

pg_lit_primitive_t (*const cmp_gt_lookup[PGT_COUNT]) (pg_lit_primitive_t *,
    pg_lit_primitive_t *) = {
    [PGT_U64] = ibf_gt_u64,
    [PGT_INT] = NULL,
    [PGT_STRING] = NULL,
    [PGT_BOOL] = NULL,
};

pg_lit_primitive_t (*const cmp_ge_lookup[PGT_COUNT]) (pg_lit_primitive_t *,
    pg_lit_primitive_t *) = {
    [PGT_U64] = ibf_ge_u64,
    [PGT_INT] = NULL,
    [PGT_STRING] = NULL,
    [PGT_BOOL] = NULL,
};

pg_lit_primitive_t (*const cmp_lt_lookup[PGT_COUNT]) (pg_lit_primitive_t *,
    pg_lit_primitive_t *) = {
    [PGT_U64] = ibf_lt_u64,
    [PGT_INT] = NULL,
    [PGT_STRING] = NULL,
    [PGT_BOOL] = NULL,
};

pg_lit_primitive_t (*const cmp_le_lookup[PGT_COUNT]) (pg_lit_primitive_t *,
    pg_lit_primitive_t *) = {
    [PGT_U64] = ibf_le_u64,
    [PGT_INT] = NULL,
    [PGT_STRING] = NULL,
    [PGT_BOOL] = NULL,
};

pg_lit_primitive_t (*const cmp_eq_lookup[PGT_COUNT]) (pg_lit_primitive_t *,
    pg_lit_primitive_t *) = {
    [PGT_U64] = ibf_eq_u64,
    [PGT_INT] = NULL,
    [PGT_STRING] = NULL,
    [PGT_BOOL] = NULL,
};

#endif
