/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/lexer/unkown/unkonw_id_int
** File description:
** unkown_id_int
*/

#include <ctype.h>
#include <stdbool.h>
#include "general/dynamic_array.h"
#include "general/macros.h"
#include "lexer/type.h"
#include "tokenizer/types.h"

bool lexem_lit_int_isit(token_t *token)
{
    if (isdigit(*token->chars))
        return true;
    return false;
}

#warning alernative bases and infinite int type shall be added
bool lit_int_is_valid(token_t *token)
{
    for (size_t i = 0; i < token->len; ++i) {
        if (!isdigit(token->chars[i]))
            return false;
    }
    return true;
}

void lexem_push_from_litint(lexem_t **lexems, token_t *token)
{
    lexem_t new = {.type = LX_LIT_INT, .len = token->len,
            .lit_int = 0, .line = token->line, .chars = token->chars};

    if (!lit_int_is_valid(token)) {
        new.type = LX_LIT_INT;
    }
    for (size_t i = 0; i < token->len; ++i) {
#pragma message("should check for overflow at some point")
        new.lit_int = (new.lit_int * 10) + (token->chars[i] - '0');
    }
    *lexems = da_push(*lexems, &new, sizeof new);
}
