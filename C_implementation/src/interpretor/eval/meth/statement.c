/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/statement
** File description:
** statemnt evaluator
*/

#include <stddef.h>
#include "parser/grammar_types/meth/statement.h"
#include "general/macros.h"
#include "interpretor/types.h"
#include "interpretor/functions.h"
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

pg_lit_primitive_t interpretor_eval_meth_statement(interpretor_t *interpretor,
    pgm_statement_t *statement)
{
    pg_lit_primitive_t res;

    switch (statement->type) {
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
