/*
** EPITECH PROJECT, 2025
** include/parser/print/functions
** File description:
** parser pretty printing fuction(s)
*/

#ifndef PARSER_PPRINT_FUNCTIONS_H_
    #define PARSER_PPRINT_FUNCTIONS_H_

    #include "parser/function.h"
    #include "parser/type.h"
    #include "parser/grammar_types/meth/definition.h"
    #include "parser/grammar_types/meth/expression.h"
    #include "parser/grammar_types/meth/statement.h"

    extern void parser_dump(parser_t *parser);
    extern void parser_dump_def(px_def_t *def);
    extern void parser_dump_meth(pgm_def_t *meth);
    extern void parser_dump_meth_block(pgm_block_t *block);
    extern void parser_dump_meth_statement(pgm_statement_t *stm);
    extern void parser_dump_meth_declaration(pgm_decl_t *decl);
    extern void parser_dump_meth_expression(pgm_expression_t *expr);
    extern void parser_dump_meth_return(pgm_expression_t *ret);

#endif
