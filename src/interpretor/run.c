/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/interpretor/run
** File description:
** interpretor_run
*/

#include "lexer/functions.h"
#include "lexer/type.h"
#include "parser/dbg/functions.h"
#include "parser/type.h"
#include "parser/function.h"
#include "tokenizer/types.h"
#include "tokenizer/functions.h"
#include "general/dynamic_array.h"
#include "interpretor/functions.h"
#include <errno.h>

static void interpretor_run_on_tokenizer(tokenizer_t *tokenizer)
{
    lexem_t *lexems = lexems_generate(tokenizer);
    parser_t parser = parser_create();

    parser.lexems = lexems;
    parser_run(&parser);
    print_dbg_statment(parser.defs->dbg.block.statement);
    long res = interpretor_dbg_eval_statement(parser.defs->dbg.block.statement);
    printf("\n%ld\n", res);
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
