/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/expression/builtin/additive/bool
** File description:
** bool
*/

#include "interpretor/builtins/additive.h"
#include "parser/grammar_types/general.h"

pg_lit_primitive_t ibf_add_bool(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_BOOL;
    out.value.boolean = a->value.boolean || b->value.boolean;
    return out;
}

pg_lit_primitive_t ibf_sub_bool(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_BOOL;
    out.value.boolean = (a->value.boolean || b->value.boolean) &&
        a->value.boolean;
    return out;
}
