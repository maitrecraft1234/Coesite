#ifndef TOKENIZER_MACROS_H_
#define TOKENIZER_MACROS_H_
#include <stdbool.h>

#include <characters/macros.h>

#define TOKENIZER_CURSOR_CHAR(t) (t->code[t->cursor])
#define TOKENIZER_IS_DONE(t) (t->code_len <= t->cursor)

#define TOKEN_EOF ((token_t) {.type = tk_eof})

#endif
