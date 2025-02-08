/*
** EPITECH PROJECT, 2024
** include/interpretor/functions
** File description:
** functions for the interpretor mainly evaluation
*/

#ifndef INTERPRETOR_FUNCTIONS_H_
    #define INTERPRETOR_FUNCTIONS_H_

    #include "interpretor/types.h"

extern interpretor_t interpretor_create(interpretor_t *parent);
extern void interpretor_destroy(interpretor_t *interpretor);

//evaluation fucntions
extern pg_lit_primitive_t interpretor_eval_meth_block(
    interpretor_t *interpretor, pgm_block_t *block);
extern pg_lit_primitive_t interpretor_eval_meth_statement(
    interpretor_t *interpretor, pgm_statement_t *statement);
extern pg_lit_primitive_t interpretor_eval_meth_expr(
    interpretor_t *itnerpretor, pgm_expression_t *expr);
extern pg_lit_primitive_t interpretor_eval_meth_expr_additive(
    interpretor_t *interpretor, pgmx_additive_t *expr);
extern pg_lit_primitive_t interpretor_eval_meth_expr_multiplicative(
        interpretor_t *interpretor, pgmx_multiplicative_t *expr);
extern pg_lit_primitive_t interpretor_eval_meth_expr_primary(
    interpretor_t *interpretor, pgmx_primary_t *prim);
extern pg_lit_primitive_t interpretor_eval_meth_fn_call(
    interpretor_t *interpretor, pgmx_terminal_t *call);

// just call these please
extern void interpretor_run_from_string(char const *string, size_t len);
extern int interpretor_run_from_file(char const *path);
#endif
