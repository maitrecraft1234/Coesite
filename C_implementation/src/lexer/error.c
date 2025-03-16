/*
** EPITECH PROJECT, 2024
** src/lexem/error
** File description:
** error
*/

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "characters/macros.h"
#include "general/macros.h"
#include "lexer/type.h"
#include "tokenizer/macros.h"
#include "tokenizer/macros.h"
#include "tokenizer/types.h"

static const char *helper_find_line_start(lexem_t *lexem,
    tokenizer_t *tokenizer)
{
    char const *cur = lexem->chars;

    while (!IS_NEWLINE(*cur) && cur > tokenizer->code) {
        --cur;
    }
    return cur + IS_NEWLINE(*cur);
}

static const char *helper_find_line_end(lexem_t *lexem, tokenizer_t *tokenizer)
{
    char const *cur = lexem->chars + lexem->len;

    while (!IS_NEWLINE(*cur) && cur < tokenizer->code
            + tokenizer->code_len) {
        ++cur;
    }
    return cur;
}

static size_t helper_numer_lengh(size_t num)
{
    if (num == 0)
        return 1;
    return (size_t)floor(log10(num)) + 1;
}

static void helper_print_str(const char *start,
    const char *end, lexem_t *lexem)
{
    while (start < end) {
        if (lexem->chars == start)
            fprintf(stderr, "\033[31m");
        if (lexem->chars + lexem->len == start)
            fprintf(stderr, "\033[0m");
        fputc(*start, stderr);
        ++start;
    }
    putc('\n', stderr);
}

static void helper_print_arrow(size_t len, size_t word_len)
{
    if (word_len == 0)
        return;
    --word_len;
    while (len > 0) {
        fputc(len > word_len ? ' ' : '~', stderr);
        --len;
    }
    putc('^', stderr);
}

void lexem_error(lexem_t *lexem, tokenizer_t *tokenizer)
{
    char const *line_start = helper_find_line_start(lexem, tokenizer);
    char const *line_end = helper_find_line_end(lexem, tokenizer);
    char const *cur = lexem->chars + lexem->len;

    fprintf(stderr, "  %lu | ", lexem->line);
    helper_print_str(line_start, line_end, lexem);
    helper_print_arrow(helper_numer_lengh(lexem->line) + 4 +
        (cur - line_start), lexem->len);
    putc('\n', stderr);
}
