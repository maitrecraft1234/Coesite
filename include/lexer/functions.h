/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/lexer/functions
** File description:
** functions
*/

#ifndef LEXER_FUNCTION_H_
    #define LEXER_FUNCTION_H_

    #include "lexer/type.h"

extern lexem_t *lexems_generate(tokenizer_t *tokenizer);
extern void lexem_push_from_token(lexem_t **array, token_t *tk);
extern void lexem_push_from_strtoken(lexem_t **array, tokenizer_t *tk);
extern void lexem_push_from_litint(lexem_t **lexems, token_t *token);
extern bool lexem_lit_int_isit(token_t *token);
extern void lexem_id_unkown(lexem_t **lexem, token_t *token);
extern void lexem_dbg_print(lexem_t *lexem);

#endif
