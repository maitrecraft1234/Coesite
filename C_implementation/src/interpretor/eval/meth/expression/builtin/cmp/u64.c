#include "interpretor/builtins/cmp.h"
#include "parser/grammar_types/general.h"

pg_lit_primitive_t ibf_gt_u64(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_BOOL;
    out.value.u64 = a->value.u64 > b->value.u64;
    return out;
}

pg_lit_primitive_t ibf_ge_u64(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_BOOL;
    out.value.u64 = a->value.u64 >= b->value.u64;
    return out;
}

pg_lit_primitive_t ibf_lt_u64(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_BOOL;
    out.value.u64 = a->value.u64 < b->value.u64;
    return out;
}

pg_lit_primitive_t ibf_le_u64(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_BOOL;
    out.value.u64 = a->value.u64 <= b->value.u64;
    return out;
}

pg_lit_primitive_t ibf_eq_u64(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_BOOL;
    out.value.u64 = a->value.u64 == b->value.u64;
    return out;
}
