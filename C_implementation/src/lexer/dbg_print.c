/*
** EPITECH PROJECT, 2024
** src/lexer/dbg_print
** File description:
** dbg_print
*/

#include "lexer/type.h"
#include "lexer/functions.h"
#include <lexer/lookuptable.h>

void lexem_dbg_print(lexem_t *lexem)
{
    if (lexem->type == LX_LIT_INT) {
        printf("%s: %ld\n", lookup_table[lexem->type], lexem->lit.value);
    } else {
        printf("%s\n", lookup_table[lexem->type]);
    }
}
