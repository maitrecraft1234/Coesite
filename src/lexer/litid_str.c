/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/lexer/litid_str
** File description:
** litid_str
*/

#include <string.h>
#include "general/dynamic_array.h"
#include "general/macros.h"
#include "tokenizer/functions.h"
#include "lexer/type.h"
#include "tokenizer/macros.h"
#include "tokenizer/types.h"

static char *litid_str(tokenizer_t *tokenizer)
{
    char *str = 0;
    size_t start = tokenizer->cursor + 1;

    tokenizer_skip_while(tokenizer, token_nospace[TK_STRING_CONTAINER],
        token_nospace_len[TK_STRING_CONTAINER]);
    if (!TOKENIZER_IS_DONE(tokenizer) && tokenizer->cursor > start) {
        str = da_create_with_cappacity(tokenizer->cursor - start);
        strncpy(str, &tokenizer->code[start + 1], tokenizer->cursor - start);
    }
    return str;
}

void lexem_push_from_strtoken(lexem_t **array, tokenizer_t *tk)
{
    char *str = litid_str(tk);
    lexem_t new = {
        .type = LX_LIT_STR,
        .chars = &TOKENIZER_CURSOR_CHAR(tk),
        .line = tk->line,
    };

    if (!str)
        TODO;
    new.lit_str = str;
    new.len = DA_LEN(str);
    *array = da_push(*array, &new, sizeof new);
}
