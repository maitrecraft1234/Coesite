/*
** EPITECH PROJECT, 2024
** include/parser/global
** File description:
** global declarations ig (idk what I need globals for but sure
*/

#ifndef PARSER_GLOBAL_H_
    #define PARSER_GLOBAL_H_

    #include <parser/function.h>
    #include "lexer/type.h"

// error is the last element of the enum
static px_def_t (*const parsing_action[LX_ERROR])(parser_t *) = {
    [LX_METH] = (void *)pgm_def,
    [LX_LET] = (void *)pg_global,
};

#endif
