/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/statement
** File description:
** statemnt evaluator
*/

#include <stddef.h>
#include "parser/grammar_types/meth/statement.h"
#include "general/hashtable/hashtable.h"
#include "general/macros.h"
#include "interpretor/types.h"
#include "interpretor/functions.h"
#include "general/hashtable/ht_macro_impl_cs_bug_workaround.h"
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/type_tag.h"

static pg_lit_primitive_t interpretor_eval_meth_decl(interpretor_t *interpretor,
    pgm_decl_t *decl)
{
    pg_lit_primitive_t res;

    res = interpretor_eval_meth_expr(interpretor, &decl->expr);
    interpretor->vars = ht_insert(interpretor->vars,
        HT_KEY_FROM(decl->var_name.name, decl->var_name.size), &res);
    return res;
}

//not sure why this is expected to return anything
static pg_lit_primitive_t interpretor_eval_meth_assignement(
    interpretor_t *interpretor,
    pgm_assignement_t *ass)
{
    pg_lit_primitive_t r = {.type = PGT_VOID};
    ht_key_t key = HT_KEY_FROM(ass->var_name.name, ass->var_name.size);
    pg_lit_primitive_t *var = ht_search(interpretor->vars, key);
    interpretor_t *i = interpretor;

    while (!var && interpretor->parent) {
        interpretor = interpretor->parent;
        var = ht_search(interpretor->vars, key);
    }
    // the type should be checked here I guess
    var->value = interpretor_eval_meth_expr(i, &ass->expr).value;
    return r;
}

pg_lit_primitive_t interpretor_eval_meth_statement(interpretor_t *interpretor,
    pgm_statement_t *statement)
{
    pg_lit_primitive_t res;

    switch (statement->type) {
        case PGM_ASSIGNMENT:
            return interpretor_eval_meth_assignement(interpretor, &statement->ass);
        case PGM_EXPRESSION:
            return interpretor_eval_meth_expr(interpretor, &statement->expr);
        case PGM_DECL:
            return interpretor_eval_meth_decl(interpretor, &statement->decl);
        case PGM_RETURN:
            res = interpretor_eval_meth_expr(interpretor, &statement->expr);
            TODO;
            res.type = PGT_RETURN;
        UNREACHABLE_DEFAULT;
    }
    UNREACHABLE;
}
