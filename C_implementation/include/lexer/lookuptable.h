/*
** EPITECH PROJECT, 2024
** include/lexer/lookuptable
** File description:
** lookup table for debuggin purpuses
*/

#ifndef LEXER_LOOKUPTABLE_H_
    #define LEXER_LOOKUPTABLE_H_

    #include "type.h"

static const char *lookup_table[] = {
    #define X_IMPL(a, b) [LX_##a] = #a,
    XV_TOKENS
    XV_LITERRALS
    #undef X_IMPL
};

#endif
