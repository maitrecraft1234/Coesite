/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/tokenizer/functions
** File description:
** functions
*/

#ifndef TOKENIZER_FN_H_
    #define TOKENIZER_FN_H_
    #include <stdbool.h>
    #include "tokenizer/types.h"

extern tokenizer_t tokenizer_create_from_file(char const *filepath);
extern tokenizer_t tokenizer_create(char const *code, size_t len);
extern token_t tokenizer_token_next(tokenizer_t *tokenizer);
extern void tokenizer_destroy(tokenizer_t *tokenizer);
extern void tokenizer_error(char *msg, tokenizer_t *tokenizer);
extern void tokenizer_skip_line(tokenizer_t *tokenizer);
extern char tokenizer_advance(tokenizer_t *tokenizer);
extern void tokenizer_skip_while(tokenizer_t *tokenizer,
    const char *stop, size_t stop_len);
extern void token_dump(token_t *token);
#endif
