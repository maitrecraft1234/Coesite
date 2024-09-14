/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/tokenizer/create
** File description:
** create
*/

#include "tokenizer/types.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

tokenizer_t tokenizer_create(char const *code, size_t len)
{
    tokenizer_t new = {
        .code = code,
        .cursor = 0,
        .code_len = len,
        .line = 1,
        .is_code_dynamic_allocation = false
    };

    return new;
}

static tokenizer_t tokenizer_create_from_safe_file_star_with_size(
    FILE *file,
    size_t size)
{
    char *code = malloc(size);
    tokenizer_t tokenizer;

    if (code == NULL) {
        fclose(file);
        errno = ENOMEM;
        return tokenizer_create(code, 0);
    }
    fseek(file, 0, SEEK_SET);
    errno = size != fread(code, 1, size, file);
    fclose(file);
    tokenizer = tokenizer_create(code, size);
    tokenizer.is_code_dynamic_allocation = true;
    return tokenizer;
}

tokenizer_t tokenizer_create_from_file(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    long tell;

    if (file == NULL) {
        errno = EIO;
        return tokenizer_create(0, 0);
    }
    fseek(file, 0, SEEK_END);
    tell = ftell(file);
    if (tell == -1) {
        fclose(file);
        return tokenizer_create(0, 0);
    }
    return tokenizer_create_from_safe_file_star_with_size(file, tell);
}

void tokenizer_destroy(tokenizer_t *tokenizer)
{
    if (tokenizer->is_code_dynamic_allocation)
        free((void *)tokenizer->code);
}
