/*
** EPITECH PROJECT, 2024
** src/parser/create
** File description:
** parser creation deletion
*/

#include "parser/type.h"
#include "general/dynamic_array.h"

parser_t parser_create(void)
{
    parser_t parser;

    parser.defs = da_create();
    parser.lexems = NULL;
    parser.lexem_index = 0;
    return parser;
}
