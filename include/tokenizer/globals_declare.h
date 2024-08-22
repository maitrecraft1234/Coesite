#ifndef TOKENIZER_GLOBALS_DECLARE_H_
#define TOKENIZER_GLOBALS_DECLARE_H_
#include "tokenizer/types.h"

const char *token_nospace[] = {
#define X(t, s) [tk_##t] = (void *)s,
    XV_TOKENS_SEPS
#undef X
};

const size_t token_nospace_len[] = {
#define X(t, s) [tk_##t] = sizeof(s) - 1,
    XV_TOKENS_SEPS
#undef X
};

const char *token_keywords[] = {
#define X(t, s) [tk_##t] = (void *)s,
    XV_TOKENS_KEYWORDS
#undef X
};

const size_t token_keywords_len[] = {
#define X(t, s) [tk_##t] = sizeof(s) - 1,
    XV_TOKENS_KEYWORDS
#undef X
};
#endif
