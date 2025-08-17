/*
** EPITECH PROJECT, 2024
** include/parser/macros
** File description:
** man man
*/

#ifndef PARSER_MACROS_H_
    #define PARSER_MACROS_H_
    #include "lexer/macros.h"
    #include "general/dynamic_array.h"
    #include <assert.h>

    #define CUR_LEXEM_UNSAFE(p) ((p)->lexems[(p)->lexem_index])
    #define LEXEMS_DONE(p) ((p)->lexem_index < DA_LEN((p)->lexems))
    #define CUR_LEXEM(p) (LEXEMS_DONE(p) ? CUR_LEXEM_UNSAFE(p) : EOF_LEXEM)
    #define IMPL_ASTCR(p, t) assert(CUR_LEXEM(p).type == t)
    #define ASSERT_CUR_IS(parser, type) IMPL_ASTCR(parser, type)

    #define NEXT_LEXEM_UNSAFE(p) ((p)->lexems[(p)->lexem_index + 1])
    #define NLEXEMS_DONE(p) ((p)->lexem_index + 1 < DA_LEN((p)->lexems))
    #define NEXT_LEXEM(p) (NLEXEMS_DONE(p) ? NEXT_LEXEM_UNSAFE(p) : EOF_LEXEM)
    #define IMPL_NASTCR(p, t) assert(NEXT_LEXEM(p).type == t)
    #define ASSERT_NEXT_IS(parser, type) IMPL_NASTCR(parser, type)

#endif
