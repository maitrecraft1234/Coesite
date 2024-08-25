#include <ctype.h>
#include <stdbool.h>
#include "general/dynamic_array.h"
#include "general/macros.h"
#include "lexer/type.h"
#include "tokenizer/types.h"

bool lit_int_isit(token_t *token)
{
    if (isdigit(*token->chars))
        return true;
    return false;
}

#warning alernative bases and infinite int type shall be added also NEGATIVE are unary actually so its not handled here
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
    lexem_t new = {.type = lx_lit_int, .len = token->len,
            .lit_int = 0, .line = token->line, .chars = token->chars};

    if (!lit_int_is_valid(token)) {
        new.type = lx_error; // or something like that
        TODO; //error handling once again
    }
    for (size_t i = 0; i < token->len; ++i) {
        new.lit_int = (new.lit_int * 10) + (token->chars[i] - '0'); //maybe should check for intmax and stuff but not now
    }
    *lexems = da_push(*lexems, &new, sizeof new);
}
