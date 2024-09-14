/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/tokenizer/error
** File description:
** error
*/

#include "general/macros.h"
#include "tokenizer/macros.h"
#include "tokenizer/types.h"
#include <stdio.h>

static const char *helper_find_line_start(tokenizer_t *tok)
{
    char const *cur = &TOKENIZER_CURSOR_CHAR(tok);

    while (*cur != '\n' && cur > tok->code) {
        --cur;
    }
    return cur + (*cur == '\n');
}

static const char *helper_find_line_end(tokenizer_t *tok)
{
    char const *cur = &TOKENIZER_CURSOR_CHAR(tok);

    while (*cur != '\n' && cur < tok->code + tok->code_len) {
        ++cur;
    }
    return cur;
}

#warning there has to be a better way to do this
static int helper_numer_lengh(size_t num)
{
    int res = 0;

    if (num == 0)
        return 1;
    while (num > 0) {
        num /= 10;
        ++res;
    }
    return res;
}

static void helper_print_str(const char *start, const char *end)
{
    while (start < end) {
        fputc(*start, stderr);
        ++start;
    }
    putc('\n', stderr);
}

static void helper_print_arrow(size_t len)
{
    while (len > 0) {
        fputc(' ', stderr);
        --len;
    }
    putc('^', stderr);
}

void tokenizer_error(char *msg, tokenizer_t *tokenizer)
{
    char const *line_start = helper_find_line_start(tokenizer);
    char const *line_end = helper_find_line_end(tokenizer);
    char const *cur = &TOKENIZER_CURSOR_CHAR(tokenizer);

    ERROR("token %s\n", msg);
    LOG("  %lu | ", tokenizer->line);
    helper_print_str(line_start, line_end);
    helper_print_arrow(helper_numer_lengh(tokenizer->line) + 6);
    putc('\n', stderr);
    printf("tok %lu\n", tokenizer->cursor);
}
