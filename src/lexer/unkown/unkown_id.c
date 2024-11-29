/*
** EPITECH PROJECT, 2024
** src/lexer/unkown/unkown_id
** File description:
** unkown_id
*/

#include "general/macros.h"
#include "lexer/type.h"
#include "general/dynamic_array.h"
#include "lexer/functions.h"

#warning a lot more thiongs to do here
static void lexem_push_identifer(lexem_t **lexems, token_t *token)
{
    lexem_t new = {.type = LX_IDENTIFER, .len = token->len,
            .line = token->line, .chars = token->chars};

    *lexems = da_push(*lexems, &new, sizeof new);
}

void lexem_id_unkown(lexem_t **lexem, token_t *token)
{
    if (lexem_lit_int_isit(token))
        lexem_push_from_litint(lexem, token);
    else
        lexem_push_identifer(lexem, token);
}
