/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/expression/builtin/additive/string
** File description:
** strinv
*/

#include "interpretor/builtins/additive.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/general.h"

// still unsure how to set a lifetime for this
// leaks are fine in some cases but it should be fine actually maybe
pg_lit_primitive_t ibf_add_string(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_STRING;
    out.value.str = da_create_with_cappacity(DA_LEN(a->value.str) +
        DA_LEN(b->value.str));
    out.value.str = da_push(out.value.str, a->value.str, DA_LEN(a->value.str));
    out.value.str = da_push(out.value.str, b->value.str, DA_LEN(b->value.str));
    return out;
}

//idk
pg_lit_primitive_t ibf_sub_string(pg_lit_primitive_t *a, pg_lit_primitive_t *b)
{
    pg_lit_primitive_t out;

    out.type = PGT_STRING;
    out.value.str = a->value.str;
    return out;
}
