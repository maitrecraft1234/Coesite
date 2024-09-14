/*
** EPITECH PROJECT, 2024
** src/lexer/unkown/unkown_id
** File description:
** unkown_id
*/

#include "general/macros.h"
#include "lexer/type.h"
#include "lexer/functions.h"

int lexem_id_unkown(lexem_t **lexem, token_t *token)
{
    if (lexem_lit_int_isit(token)) {
        lexem_push_from_litint(&lexem, token);
    } else {
#warning VARIABLES
        TODO;
    }
    return 0;
}
