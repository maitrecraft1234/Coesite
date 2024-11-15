/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/tokenizer/debug
** File description:
** dump dst
*/

#include <stdio.h>
#include "tokenizer/types.h"

static char *token_lookup[] = {
#define X_IMPL(a, b) [tk_##a] = #a,
    XV_TOKENS
#undef X_IMPL
};

void token_dump(token_t *token)
{
    fprintf(stderr, "line: %zu, token: %s", token->line,
            token_lookup[token->type]);
}
