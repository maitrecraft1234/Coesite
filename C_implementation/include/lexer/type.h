/*
** EPITECH PROJECT, 2024
** include/lexer/type
** File description:
** type
*/

#ifndef LEXER_TYPE_H_
    #define LEXER_TYPE_H_

    #include <stddef.h>
    #include "tokenizer/types.h"
    #include "parser/grammar_types/general.h"


    #define XV_BOOL X(LIT_BOOL, )
    #define XV_STR X(LIT_STR, ) XV_BOOL
    #define XV_INT X(LIT_INT, ) XV_STR
    #define XV_FLOAT X(LIT_FLOAT, ) XV_INT

    #define XV_LITERRALS XV_FLOAT

//this should be commpatible with the token_id_t with no need for anything

typedef enum lexem_id lexem_id_t;
typedef struct lexem_s lexem_t;
typedef struct lexer_s lexer_t;

enum lexem_id {
    #define X_IMPL(t, id) LX_##t,
    XV_TOKENS
    XV_LITERRALS
    #undef X_IMPL
    LX_IDENTIFIER,
    LX_ERROR,
};

struct lexem_s {
    const char *chars;
    size_t len;
    size_t line;
    lexem_id_t type;
    pg_lit_primitive_t lit;
};

struct lexer_s {
    lexem_t *lexems;
    tokenizer_t *tokenizer;
};

#endif
