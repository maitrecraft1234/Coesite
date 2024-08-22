#include "general/macros.h"
#include "tokenizer/macros.h"
#include "lexer/type.h"
#include "tokenizer/types.h"

bool litid_str(tokenizer_t *tokenizer)
{
     do {
        if (TOKENIZER_CURSOR_CHAR(tokenizer) == *token_nospace[tk_escape_char])
            TODO;
        ++tokenizer->cursor;
        if (TOKENIZER_IS_DONE(tokenizer))
            break;
    } while(TOKENIZER_CURSOR_CHAR(tokenizer) != *token_nospace[tk_string_container]);

/* #error this is urgent */
     TODO; // A LOT MORE TO BE DONE HERE TOO
}
