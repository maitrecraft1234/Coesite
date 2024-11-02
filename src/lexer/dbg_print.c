/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/lexer/dbg_print
** File description:
** dbg_print
*/

#include "lexer/type.h"
#include "lexer/functions.h"

static char *lookup_table[50] = {
#define X_IMPL(a, b) [lx_##a] = #a,
    XV_TOKENS
    XV_LITERRALS
#undef X_IMPL
};

void lexem_dbg_print(lexem_t *lexem)
{
    if (lexem->type == lx_lit_int) {
        printf("%s: %ld\n", lookup_table[lexem->type], lexem->lit_int);
    } else {
        printf("%s\n", lookup_table[lexem->type]);
    }
}
