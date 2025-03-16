/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/expression/builtin/additive/u64
** File description:
** u64
*/

#include "interpretor/builtins/additive.h"
#include "parser/grammar_types/general.h"

pg_lit_primitive_t ibf_add_u64(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_U64;
    out.value.u64 = a->value.u64 + b->value.u64;
    return out;
}

pg_lit_primitive_t ibf_sub_u64(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_U64;
    out.value.u64 = a->value.u64 - b->value.u64;
    return out;
}
