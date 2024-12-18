/*
** EPITECH PROJECT, 2024
** include/characters/macros
** File description:
** macros
*/

#ifndef CHAR_MACROS_
    #define CHAR_MACROS_

    #include <ctype.h>

    #define IS_NEWLINE(c) ((c) == '\n')
    #define IS_WHITE_SPACE(c) (isblank(c) || IS_NEWLINE(c))

#endif
