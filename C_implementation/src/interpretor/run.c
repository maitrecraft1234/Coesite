/*
** EPITECH PROJECT, 2024
** src/interpretor/run
** File description:
** interpretor_run
*/

#include "lexer/functions.h"
#include "lexer/type.h"
#include "parser/print/functions.h"
#include "parser/type.h"
#include "parser/function.h"
#include "tokenizer/types.h"
#include "tokenizer/functions.h"
#include "general/dynamic_array.h"
#include <errno.h>

static void interpretor_run_on_parser(parser_t *parser)
{
    parser_run(parser);
}

static void interpretor_run_on_tokenizer(tokenizer_t *tokenizer)
{
    lexem_t *lexems = lexems_generate(tokenizer);
    parser_t parser = parser_create();

    parser.lexems = lexems;
    parser_run(&parser);
    parser_dump(&parser);
    parser_destroy(&parser);
    da_destroy(lexems);
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
