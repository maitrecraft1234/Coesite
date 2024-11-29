/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/tokenizer/types
** File description:
** types
*/

#ifndef TOKENIZER_T_H_
    #define TOKENIZER_T_H_
    #include <stddef.h>
    #include <stdbool.h>
    #include "general/macros.h"

typedef struct tokenizer_s {
    char const *code;
    size_t line;
    size_t code_len;
    size_t cursor;
    bool is_code_dynamic_allocation;
} tokenizer_t;

//the shorter one should be on top in case of conflicts (ex: =, ==)
    #define XVT_NONE (char *)0

    #define XVT_DBG X(DBG, "dbg")
    #define XVT_LET X(LET, "let") XVT_DBG
    #define XVT_KNONE X(NONE, "None") XVT_LET
    #define XVT_TRUE X(BOOL_TRUE, "True") XVT_KNONE
    #define XVT_FALSE X(BOOL_FALSE, "False") XVT_TRUE
    #define XVT_RETURN X(RETURN , "return") XVT_FALSE
    #define XV_TOKENS_KEYWORDS XVT_RETURN

    #define XVT_BRACKET_CLOSE X(BRACKET_CLOSE, "}")
    #define XVT_BRACKET_OPEN X(BRACKET_OPEN, "{") XVT_BRACKET_CLOSE
    #define XVT_PAR_CLOSE X(PAR_CLOSE, ")") XVT_BRACKET_OPEN
    #define XVT_PAR_OPEN X(PAR_OPEN, "(") XVT_PAR_CLOSE
    #define XVT_STRING_CONTAINER X(STRING_CONTAINER, "\"") XVT_PAR_OPEN
    #define XVT_ESCAPE_CHAR X(ESCAPE_CHAR, "\\") XVT_STRING_CONTAINER
    #define XVT_OP_NOT X(OP_NOT, "!") XVT_ESCAPE_CHAR
    #define XVT_EO_EXPR X(EO_EXPR, ";") XVT_OP_NOT
    #define XVT_ASSIGN X(ASSIGN, "=") XVT_EO_EXPR
    #define XVT_OP_CMP_GT X(OP_CMP_GT, ">") XVT_ASSIGN
    #define XVT_OP_CMP_LT X(OP_CMP_LT, "<") XVT_OP_CMP_GT
    #define XVT_OP_MUL X(OP_MUL, "*") XVT_OP_CMP_LT
    #define XVT_OP_DIV X(OP_DIV, "/") XVT_OP_MUL
    #define XVT_OP_PLUS X(OP_PLUS, "+") XVT_OP_DIV
    #define XVT_OP_MINUS X(OP_MINUS, "-") XVT_OP_PLUS
    #define XVT_OR X(OP_OR, "||") XVT_OP_MINUS
    #define XVT_OP_AND X(OP_AND, "&&") XVT_OR
    #define XVT_CMP_LE X(OP_CMP_LE, "<=") XVT_OP_AND
    #define XVT_CMP_GE X(OP_CMP_GE, ">=") XVT_CMP_LE
    #define XVT_CMP_EQ X(OP_CMP_EQ, "==") XVT_CMP_GE
    #define XVT_COMMENT_LINE X(COMMENT_LINE, "//") XVT_CMP_EQ
    #define XVT_COMMENT_START X(COMMENT_START, "/*") XVT_COMMENT_LINE
    #define XVT_UNKNOWN X(UNKOWN, XVT_NONE) XVT_COMMENT_START
    #define XV_TOKENS_SEPS X(EOP, XVT_NONE) XVT_UNKNOWN

    #define XV_TOKENS XV_TOKENS_SEPS XV_TOKENS_KEYWORDS

typedef enum {
    #define X_IMPL(t, id) TK_##t,
    XV_TOKENS
    #undef X_IMPL
} token_type_t;

typedef struct token_s {
    char const *chars;
    size_t len;
    size_t line;
    token_type_t type;
} token_t;

extern const char *token_nospace[];
extern const size_t token_nospace_len[];
extern const char *token_keywords[];
extern const size_t token_keywords_len[];
extern const char *token_lookup[];
#endif
