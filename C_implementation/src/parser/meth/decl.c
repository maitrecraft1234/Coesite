/*
** EPITECH PROJECT, 2024
** src/parser/meth/decl
** File description:
** declaration for things and whatnot this is stupid to put in a separate file
*/

#include <parser/function.h>
#include <lexer/macros.h>
#include "parser/grammar_types/general.h"
#include "parser/grammar_types/meth/statement.h"
#include <assert.h>
#include "lexer/type.h"
#include "parser/macros.h"

//since I can't comment withing the function
//the 0xffffffffffff is a placeholder for the semicolon
//this is a temporary solution until the type system is implemented
pgm_decl_t pgm_decl(parser_t *parser)
{
    pgm_decl_t decl = {0};

    assert(CUR_LEXEM(parser).type == LX_LET);
    ++parser->lexem_index;
    if (CUR_LEXEM(parser).type == 0xffffffffffff) {
        ++parser->lexem_index;
    }
    decl.var_name = pg_identifier(parser);
    if (CUR_LEXEM(parser).type != LX_ASSIGN) {
        parser_error(parser, "=");
        parser_skip_past_next(parser, LX_EO_EXPR);
        return decl;
    }
    ++parser->lexem_index;
    decl.expr = pgm_expression(parser);
    return decl;
}
