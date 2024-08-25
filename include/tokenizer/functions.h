#ifndef TOKENIZER_FN_H_
#define TOKENIZER_FN_H_
#include <stdbool.h>
#include "tokenizer/types.h"

tokenizer_t tokenizer_create_from_file(char const *filepath);
tokenizer_t tokenizer_create(char const *code, size_t len);
token_t tokenizer_token_next(tokenizer_t *tokenizer);
void tokenizer_destroy(tokenizer_t *tokenizer);
void tokenizer_error(char *msg, tokenizer_t *tokenizer);
void tokenizer_skip_line(tokenizer_t *tokenizer);
char tokenizer_advance(tokenizer_t *tokenizer);
void tokenizer_skip_while(tokenizer_t *tokenizer,
    const char *stop, size_t stop_len);
#endif
