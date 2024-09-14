/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/lexer/lexer_create_destroy
** File description:
** lexer_create_destroy
*/

#include "general/dynamic_array.h"
#include "lexer/type.h"
#include "tokenizer/functions.h"
#include "tokenizer/types.h"

lexer_t lexer_create_from_tokenizer(tokenizer_t *tokenizer)
{
    lexer_t lexer = {.lexems = da_create_with_cappacity(0),
        .tokenizer = tokenizer};

    return lexer;
}

//might never be used idk
void lexer_destroy(lexer_t *lexer)
{
    da_destroy(lexer->lexems);
    tokenizer_destroy(lexer->tokenizer);
}
