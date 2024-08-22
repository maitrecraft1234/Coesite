#include "general/dynamic_array.h"
#include "lexer/type.h"
#include "lexer/functions.h"

void lexem_push(lexem_t **array, lexem_id_t type, char *line, size_t len)
{
    lexem_t new = lexem_create(type, line, len);

    *array = da_push(*array, &new, sizeof new);
}
