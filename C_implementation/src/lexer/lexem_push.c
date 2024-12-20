/*
** EPITECH PROJECT, 2024
** src/lexer/lexem_push
** File description:
** lexem_push
*/

#include "general/dynamic_array.h"
#include "lexer/type.h"
#include "lexer/functions.h"

void lexem_push_from_token(lexem_t **array, token_t *tk)
{
    lexem_t new = {
        .type = (lexem_id_t)tk->type,
        .len = tk->len,
        .chars = tk->chars,
        .line = tk->line
    };

    *array = da_push(*array, &new, sizeof new);
}
