/*
** EPITECH PROJECT, 2025
** /home/vj/coding/Swag-lang/C_implementation/src/parser/error/error
** File description:
** parser error
*/

#include <stdio.h>
#include <errno.h>
#include "general/macros.h"
#include "parser/type.h"
#include "parser/macros.h"
#include "lexer/functions.h"

void parser_error(parser_t *parser, const char *expected)
{
    ERROR("Expected %s\n", expected);
    lexem_error(&CUR_LEXEM_UNSAFE(parser), parser->tokenizer);
    errno = 1;
    ++parser->lexem_index;
}
