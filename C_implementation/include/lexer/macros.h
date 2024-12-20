/*
** EPITECH PROJECT, 2024
** include/lexer/macros
** File description:
** macros
*/

#ifndef LEX_MACRO_H_
    #define LEX_MACRO_H_

    #include "type.h"

// reason for this is that the coding style wont allow it the way I had
// it written before and it would be a pointless refactor
static const lexem_t EOP_LEXEM = {.type = LX_EOP};
    #define EOF_LEXEM EOP_LEXEM

#endif
