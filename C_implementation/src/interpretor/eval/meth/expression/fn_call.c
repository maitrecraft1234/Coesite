/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/def
** File description:
** evaluates a meth funcion call
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "general/hashtable/hashtable.h"
#include "general/macros.h"
#include "interpretor/functions.h"
#include "parser/print/functions.h"
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/type_tag.h"

pg_lit_primitive_t interpretor_eval_meth_fn_call(interpretor_t *interpretor,
        pgmx_terminal_t *call)
{
    assert(call->type == PGM_FN_CALL);
    if (ht_search(interpretor->vars,
            HT_KEY_FROM(call->fn_call.name, call->fn_call.size)))
            TODO;
    if (strncmp(call->fn_call.name, "dbg", call->fn_call.size) == 0) {
        parser_dump_lit_primitive(REF_FUNC_CALL(interpretor_eval_meth_expr(
                interpretor, call->fn_call.meth_args)));
        putchar('\n');
        return (pg_lit_primitive_t) {.type = PGT_VOID};
    }
    TODO;
    //type error
    return (pg_lit_primitive_t) {.type = PGT_U64, .value.u64 = 0};
}
