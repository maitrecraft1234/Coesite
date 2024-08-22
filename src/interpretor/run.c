#include "lexer/functions.h"
#include "tokenizer/types.h"
#include "tokenizer/functions.h"
#include <errno.h>

static void interpretor_run_on_tokenizer(tokenizer_t *tokenizer)
{
    lexems_generate(tokenizer);
}

int interpretor_run_from_file(char const *path)
{
    tokenizer_t tokenizer;

    errno = 0;
    tokenizer = tokenizer_create_from_file(path);
    if (errno != 0)
        return -1;
    interpretor_run_on_tokenizer(&tokenizer);
    tokenizer_destroy(&tokenizer);
    return 0;
}

void interpretor_run_from_string(char const *string, size_t len)
{
    tokenizer_t tokenizer = tokenizer_create(string, len);

    errno = 0;
    interpretor_run_on_tokenizer(&tokenizer);
    tokenizer_destroy(&tokenizer);
}
