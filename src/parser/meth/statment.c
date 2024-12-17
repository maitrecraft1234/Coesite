/*
** EPITECH PROJECT, 2024
** /home/vj/test/language_name_unkown/src/parser/meth/statment
** File description:
** statement parser for meth
*/

#include <parser/grammar_types/meth/type_tag.h>
#include <parser/grammar_types/meth/statement.h>
#include <parser/grammar_types/meth/block.h>
#include <parser/macros.h>
#include <parser/function.h>
#include "general/macros.h"
#include "tokenizer/types.h"


pgm_statement_t pgm_statement(parser_t *parser)
{
    pgm_statement_t statement = {0};
    lexem_t cur = CUR_LEXEM(parser);

    switch (cur.type) {
        CASE(TK_LET) {
            statement.type = PGM_DECL;
            statement.decl = pgm_decl(parser);
        }
        CASE(TK_RETURN) {
            statement.type = PGM_RETURN;
            ++parser->lexem_index;
            statement.ret = pgm_expression(parser);
        }
        DEFAULT {
            statement.type = PGM_EXPRESSION;
            statement.expr = pgm_expression(parser);
        }

    }
    return statement;
}
