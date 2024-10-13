/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/tokenizer/debug
** File description:
** dump dst
*/

#include <stdio.h>
#include "tokenizer/types.h"

void token_dump(token_t *token)
{
    fprintf(stderr, "line: %zu, token: ", token->line);
    for (size_t i = 0; i < token->len; ++i) {
        putc(token->chars[i], stderr);
    }
    putc('\n', stderr);
}
