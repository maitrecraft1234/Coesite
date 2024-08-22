#include "string.h"
#include "general/macros.h"
#include "tokenizer/types.h"
#include "tokenizer/globals_declare.h"

token_type_t tokenizer_id_keyword(char const *restrict const chars,
    size_t const len)
{
    for(size_t i = 1; i < ARRAY_SIZE(token_keywords) - 1; ++i) {
        if (!token_keywords[i] || token_keywords_len[i] != len)
            continue;
        if (!strncmp(chars, token_keywords[i], len)) {
            return i;
        }
    }
    return tk_unkown;
}

token_type_t tokenizer_id_nospace(char const *chars, size_t len)
{
    for(size_t i = 1; i < ARRAY_SIZE(token_nospace) - 1; ++i) {
        if (!token_nospace[i] || len < token_nospace_len[i])
            continue;
        if (!strncmp(chars, token_nospace[i], token_nospace_len[i])) {
            return i;
        }
    }
    return tk_unkown;
}
