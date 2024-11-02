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

bool parser_dbg_is_bin_op(lexem_id_t operator)
{
    if (operator == lx_op_plus || operator == lx_op_minus) {
        return true;
    }
    return false;
}
