#ifndef TOKENIZER_T_H_
#define TOKENIZER_T_H_
#include <stddef.h>
#include <stdbool.h>

typedef struct tokenizer_s {
    char const *code;
    size_t line;
    size_t code_len;
    size_t cursor;
    bool is_code_dynamic_allocation;
} tokenizer_t;

//the shorter one should be on top in case of conflicts (ex: =, ==)
#define XVT_NONE (char *)0

#define XVT_LET X(let,"let")
#define XVT_KNONE X(none, "None") XVT_LET
#define XVT_TRUE X(bool_true, "True") XVT_KNONE
#define XVT_FALSE X(bool_false, "False") XVT_TRUE
#define XVT_RETURN X(return, "return") XVT_FALSE
#define XV_TOKENS_KEYWORDS XVT_RETURN

#define XVT_BRACKET_CLOSE X(bracket_close, "}")
#define XVT_BRACKET_OPEN X(bracket_open, "{") XVT_BRACKET_CLOSE
#define XVT_PAR_CLOSE X(par_close, ")") XVT_BRACKET_OPEN
#define XVT_PAR_OPEN X(par_open, "(") XVT_PAR_CLOSE
#define XVT_STRING_CONTAINER X(string_container, "\"") XVT_PAR_OPEN
#define XVT_ESCAPE_CHAR X(escape_char, "\\") XVT_STRING_CONTAINER
#define XVT_OP_NOT X(op_not, "!") XVT_ESCAPE_CHAR
#define XVT_EO_EXPR X(eo_expr, ";") XVT_OP_NOT
#define XVT_ASSIGN X(assign, "=") XVT_EO_EXPR
#define XVT_CMP_GT X(op_cmp_gt, ">") XVT_ASSIGN
#define XVT_OP_CMP_LT X(op_cmp_lt, "<") XVT_CMP_GT
#define XVT_OR X(op_or, "||") XVT_OP_CMP_LT
#define XVT_OP_AND X(op_and, "&&") XVT_OR
#define XVT_CMP_LE X(op_cmp_le, "<=") XVT_OP_AND
#define XVT_CMP_GE X(op_cmp_ge, ">=") XVT_CMP_LE
#define XVT_CMP_EQ X(op_cmp_eq, "==") XVT_CMP_GE
#define XVT_COMMENT_LINE X(comment_line, "//") XVT_CMP_EQ
#define XVT_COMMENT_END X(comment_end, "*/") XVT_COMMENT_LINE
#define XVT_COMMENT_START X(comment_start, "/*") XVT_COMMENT_END
#define XVT_UNKNOWN X(unkown, XVT_NONE) XVT_COMMENT_START
#define XV_TOKENS_SEPS X(eof, XVT_NONE) XVT_UNKNOWN

#define XV_TOKENS XV_TOKENS_SEPS XV_TOKENS_KEYWORDS

typedef enum {
#define X(t, id) tk_##t,
    XV_TOKENS
#undef X
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
#endif
