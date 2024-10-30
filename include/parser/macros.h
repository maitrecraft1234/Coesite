/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/parser/macros
** File description:
** man man
*/

#ifndef PARSER_MACROS_H_
    #define PARSER_MACROS_H_
    #include "lexer/macros.h"
    #include "general/dynamic_array.h"

    #define CUR_LEXEM_UNSAFE(p) ((p)->lexems[(p)->lexem_index])
    #define LEXEMS_DONE(p) ((p)->lexem_index < DA_LEN((p)->lexems))
    #define CUR_LEXEM(p) (LEXEMS_DONE(p) ? CUR_LEXEM_UNSAFE(p) : EOF_LEXEM)

#endif
