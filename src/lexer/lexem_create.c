#include <lexer/type.h>

lexem_t lexem_create(lexem_id_t type, char *line, size_t len)
{
    lexem_t lexem = {
        .type = type,
        .len = len,
        .line = line
    };

    return lexem;
}
