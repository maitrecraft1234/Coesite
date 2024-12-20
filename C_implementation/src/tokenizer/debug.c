/*
** EPITECH PROJECT, 2024
** src/tokenizer/debug
** File description:
** dump dst
*/

#include <stdio.h>
#include "tokenizer/types.h"

void token_dump(token_t *token)
{
    fprintf(stderr,
        "line: %zu, token: %s, token_id : %d, "
    "token_len %zu:, token_chars : %s\n",
        token->line,
        token_lookup[token->type],
        token->type,
        token->len,
        token->chars
        );
}
