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
#include "parser/grammar_types/meth/type_tag.h"

pg_lit_primitive_t interpretor_eval_meth_statement(interpretor_t *interpretor,
    pgm_statement_t *statement)
{
    switch (statement->type) {
        case PGM_EXPRESSION:
            return interpretor_eval_meth_expr(interpretor, &statement->expr);
        case PGM_DECL:
            TODO;
            break;
        case PGM_RETURN:
            TODO;
            break;
        UNREACHABLE_DEFAULT;
    }
    UNREACHABLE;
}
