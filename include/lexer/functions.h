#ifndef LEXER_FUNCTION_H_
#define LEXER_FUNCTION_H_

#include "lexer/type.h"

lexem_t *lexems_generate(tokenizer_t *tokenizer);
void lexem_push_from_token(lexem_t **array, token_t *tk);
void lexem_push_from_strtoken(lexem_t **array, tokenizer_t *tk);

#endif
