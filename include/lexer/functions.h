#ifndef LEXER_FUNCTION_H_
#define LEXER_FUNCTION_H_

#include "lexer/type.h"

lexem_t *lexems_generate(tokenizer_t *tokenizer);
lexem_t lexem_create(lexem_id_t type, char *line, size_t len);
void lexem_push(lexem_t **array, lexem_id_t type, char *line, size_t len);

#endif
