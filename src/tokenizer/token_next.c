/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/tokenizer/token_next
** File description:
** token_next
*/

#include <stdbool.h>
#include <string.h>
#include "characters/macros.h"
#include "tokenizer/types.h"
#include "tokenizer/macros.h"
#include "tokenizer/local_functions.h"

static void tokenizer_skip_whitespace(tokenizer_t *tokenizer)
{
    while (!TOKENIZER_IS_DONE(tokenizer) &&
            IS_WHITE_SPACE(TOKENIZER_CURSOR_CHAR(tokenizer))) {
        if (IS_NEWLINE(TOKENIZER_CURSOR_CHAR(tokenizer)))
            ++tokenizer->line;
        ++tokenizer->cursor;
    }
}

static token_type_t tokenizer_find_token_end(tokenizer_t *tokenizer)
{
    token_type_t nstok = tokenizer_id_nospace(tokenizer->code +
        tokenizer->cursor, tokenizer->code_len - tokenizer->cursor);

    if (nstok != tk_unkown) {
        tokenizer->cursor += token_nospace_len[nstok];
        return nstok;
    }
    while (!TOKENIZER_IS_DONE(tokenizer) &&
            !IS_WHITE_SPACE(TOKENIZER_CURSOR_CHAR(tokenizer)) &&
            (nstok == tk_unkown)) {
        ++tokenizer->cursor;
        nstok = tokenizer_id_nospace(tokenizer->code + tokenizer->cursor,
            tokenizer->code_len - tokenizer->cursor);
    }
    return tk_unkown;
}

token_t tokenizer_token_next(tokenizer_t *tokenizer)
{
    token_t next_token = {.chars = tokenizer->code};
    size_t cursor;

    tokenizer_skip_whitespace(tokenizer);
    next_token.line = tokenizer->line;
    if (TOKENIZER_IS_DONE(tokenizer))
        return TOKEN_EOF;
    cursor = tokenizer->cursor;
    next_token.chars += tokenizer->cursor;
    next_token.type = tokenizer_find_token_end(tokenizer);
    next_token.len = tokenizer->cursor - cursor;
    if (next_token.type == tk_unkown)
        next_token.type = tokenizer_id_keyword(next_token.chars,
            next_token.len);
    next_token.line = tokenizer->line;
    return next_token;
}
