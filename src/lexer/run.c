#include "general/dynamic_array.h"
#include "general/macros.h"
#include "lexer/functions.h"
#include "lexer/type.h"
#include "tokenizer/functions.h"
#include "tokenizer/types.h"
#include "tokenizer/functions.h"

lexem_t *lexems_generate(tokenizer_t *tokenizer)
{
    token_t current;
    lexem_t *lexems = da_create();

    do {
        current = tokenizer_token_next(tokenizer);
        switch (current.type) {
        case tk_eof: return lexems;
        case tk_comment_start: tokenizer_skip_while(tokenizer,
           token_nospace[tk_comment_end], token_nospace_len[tk_comment_end]);
        case tk_comment_line: tokenizer_skip_line(tokenizer);
        case tk_string_container: lexem_push_from_strtoken(&lexems, tokenizer);
        case tk_comment_end:TODO;//syntax error
        case tk_unkown:TODO;//might be a litteral
        default: lexem_push_from_token(&lexems, &current);
        }
    } while (1);
}
