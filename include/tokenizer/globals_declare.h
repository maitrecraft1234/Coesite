/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/tokenizer/globals_declare
** File description:
** globals_declare
*/

#ifndef TOKENIZER_GLOBALS_DECLARE_H_
    #define TOKENIZER_GLOBALS_DECLARE_H_
    #include "tokenizer/types.h"

const char *token_nospace[] = {
    #define X_IMPL(t, s) [TK_##t] = (void *)s,
    XV_TOKENS_SEPS
    #undef X_IMPL
};

const size_t token_nospace_len[] = {
    #define X_IMPL(t, s) [TK_##t] = sizeof(s) - 1,
    XV_TOKENS_SEPS
    #undef X_IMPL
};

const char *token_keywords[] = {
    #define X_IMPL(t, s) [TK_##t] = (void *)s,
    XV_TOKENS_KEYWORDS
    #undef X_IMPL
};

const size_t token_keywords_len[] = {
    #define X_IMPL(t, s) [TK_##t] = sizeof(s) - 1,
    XV_TOKENS_KEYWORDS
    #undef X_IMPL
};

const char *token_lookup[] = {
    #define X_IMPL(a, b) [TK_##a] = #a,
    XV_TOKENS
    #undef X_IMPL
};
#endif
