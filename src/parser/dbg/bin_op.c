/*
** EPITECH PROJECT, 2024
** src/parser/dbg/bin_op
** File description:
** binary operation file
*/


#include "lexer/type.h"
#include "parser/macros.h"
#include "parser/type.h"
#include "parser/dbg/types.h"
#include "parser/dbg/functions.h"
#include "lexer/macros.h"

bool parser_dbg_is_bin_op(parser_t *parser, px_dbg_statement_t *statement)
{
    if (CUR_LEXEM(parser).type == lx_lit_int) {
        return true;
    }
    return false;
}
