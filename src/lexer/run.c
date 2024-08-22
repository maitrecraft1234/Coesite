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
        /* switch (current.type) { */
        /*     case tk_eof: return lexems; */
        /*     case tk_comment_start: */
        /*     case tk_comment_line: TODO; */
        /*     case tk_string_container: TODO;//string litterals */
        /*     case tk_unkown:TODO;// */
        /*     case tk_comment_end:TODO;//syntax error */
        /*     default: lexem_push(&lexems, current.type, current.line, current.len); TODO;//FIX THIS S */
        /* } */
        printf("%.*s type:%d\n", current.len, current.chars,current.type);
        if (current.type == tk_let)
            tokenizer_error("let", tokenizer);
        if(current.type == tk_eof)
            return 0;
    } while (1);
}
