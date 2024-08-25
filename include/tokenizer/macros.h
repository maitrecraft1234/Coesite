#ifndef TOKENIZER_MACROS_H_
#define TOKENIZER_MACROS_H_
#include <stdbool.h>

#include <characters/macros.h>

#define TOKENIZER_IS_DONE_N(t, n) ((t)->code_len <= (t)->cursor + (n))
#define TOKENIZER_IS_DONE(t) ((t)->code_len <= (t)->cursor)
#define TOKENIZER_REMAINING_LEN(t) ((t)->code_len - (t)->cursor)
#define TOKENIZER_CURSOR_CHAR(t) ((t)->code[(t)->cursor])
#define TOKENIZER_PEAK_UNSAFE(t, n) ((t)->code[(t)->cursor + (n)])
#define TOKENIZER_PEAK(t, n) TOKENIZER_IS_DONE_N(t, n) ? TOKENIZER_PEAK_UNSAFE(t, n) : 0

#define TOKEN_EOF ((token_t) {.type = tk_eof})

#endif
