/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/lexer/type
** File description:
** type
*/

#ifndef LEXER_TYPE_H_
    #define LEXER_TYPE_H_

    #include <stddef.h>
    #include "tokenizer/types.h"


    #define XV_BOOL X(lit_bool, )
    #define XV_STR X(lit_str, ) XV_BOOL
    #define XV_INT X(lit_int, ) XV_STR
    #define XV_FLOAT X(lit_float, ) XV_INT

    #define XV_LITERRALS XV_FLOAT

//this should be commpatible with the token_id_t with no need for anything

typedef enum lexem_id lexem_id_t;
typedef struct lexem lexem_t;
typedef struct lexer_s lexer_t;

enum lexem_id {
    #define X_IMPL(t, id) lx_##t,
    XV_TOKENS
    XV_LITERRALS
    #undef X_IMPL
    lx_identifer,
    lx_error,
};

struct lexem {
    const char *chars;
    size_t len;
    size_t line;
    lexem_id_t type;
    #warning THIS NEEDS TO BE REFACTORED MAYBE
    union {
        long lit_int;
        char *lit_str;
        bool lit_bool;
    };
};

struct lexer_s {
    lexem_t *lexems;
    tokenizer_t *tokenizer;
};

#endif
