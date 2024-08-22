#ifndef TOKENIZER_FN_H_
#define TOKENIZER_FN_H_
#include <stdbool.h>
#include "tokenizer/types.h"

tokenizer_t tokenizer_create_from_file(char const *filepath);
tokenizer_t tokenizer_create(char const *code, size_t len);
token_t tokenizer_token_next(tokenizer_t *tokenizer);
void tokenizer_destroy(tokenizer_t *tokenizer);
void tokenizer_error(char *msg, tokenizer_t *tokenizer);
#endif
