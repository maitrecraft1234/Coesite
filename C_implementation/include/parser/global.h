/*
** EPITECH PROJECT, 2024
** include/parser/global
** File description:
** global declarations ig (idk what I need globals for but sure
*/

#ifndef PARSER_GLOBAL_H_
    #define PARSER_GLOBAL_H_

#include <parser/function.h>

static const px_def_t (*parsing_action[] )(parser_t *) = {
    [LX_METH] = (void *)pgm_def,
};

#endif
