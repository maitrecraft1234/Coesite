/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/expression/builtin/mulitive/bool
** File description:
** bool
*/

#include "interpretor/builtins/mutliplicative.h"
#include "parser/grammar_types/general.h"

pg_lit_primitive_t ibf_mul_bool(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_BOOL;
    out.value.boolean = a->value.boolean && b->value.boolean;
    return out;
}

pg_lit_primitive_t ibf_div_bool(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_BOOL;
    out.value.boolean = a->value.boolean ^ b->value.boolean;
    return out;
}
