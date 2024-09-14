/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/tokenizer/skip
** File description:
** skip
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "tokenizer/functions.h"
#include "tokenizer/types.h"
#include "tokenizer/macros.h"

void tokenizer_skip_line(tokenizer_t *tokenizer)
{
    while (!TOKENIZER_IS_DONE(tokenizer) &&
            tokenizer_advance(tokenizer) != '\n');
    if (!TOKENIZER_IS_DONE(tokenizer))
        ++tokenizer->line;
}

void tokenizer_skip_while(tokenizer_t *tokenizer,
    const char *stop, size_t stop_len)
{
    while (!TOKENIZER_IS_DONE(tokenizer) &&
        TOKENIZER_CURSOR_CHAR(tokenizer) == *stop &&
        stop_len <= TOKENIZER_REMAINING_LEN(tokenizer) && stop_len == 1 ||
        !strncmp(tokenizer->code + tokenizer->cursor, stop, stop_len)) {
        ++tokenizer->cursor;
        if (TOKENIZER_CURSOR_CHAR(tokenizer) == '\n')
            ++tokenizer->line;
    }
}

char tokenizer_advance(tokenizer_t *tokenizer)
{
    char res = TOKENIZER_CURSOR_CHAR(tokenizer);

    if (TOKENIZER_IS_DONE(tokenizer))
        return EOF;
    ++tokenizer->cursor;
    return res;
}
