/*
** EPITECH PROJECT, 2024
** src/lexer/run
** File description:
** interpretor_run
*/

#include "general/dynamic_array.h"
#include "general/macros.h"
#include "lexer/functions.h"
#include "lexer/type.h"
#include "tokenizer/functions.h"
#include "tokenizer/types.h"
#include "tokenizer/functions.h"

static int helper_switch_thanks(
    tokenizer_t *tokenizer,
    token_t *token,
    lexem_t **lexems
)
{
    switch (token->type) {
        case TK_EOP:
            return 1;
        CASE(TK_COMMENT_START)
            tokenizer_skip_while(tokenizer, "*/", 2);
        CASE(TK_COMMENT_LINE)
            tokenizer_skip_line(tokenizer);
        CASE(TK_STRING_CONTAINER)
            lexem_push_from_strtoken(lexems, tokenizer);
        CASE(TK_UNKOWN)
            lexem_id_unkown(lexems, token);
        break;
        default:
            lexem_push_from_token(lexems, token);
    }
    return 0;
}

lexem_t *lexems_generate(tokenizer_t *tokenizer)
{
    token_t current;
    lexem_t *lexems = da_create();

    do {
        current = tokenizer_token_next(tokenizer);
        if (helper_switch_thanks(tokenizer, &current, &lexems))
            break;
    } while (1);
    return lexems;
}
