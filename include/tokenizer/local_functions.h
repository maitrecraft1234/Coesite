/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/tokenizer/local_functions
** File description:
** local_functions
*/

#ifndef TOKENIZER_LOCAL_FUNCTION_H_
    #define TOKENIZER_LOCAL_FUNCTION_H_

    #include "tokenizer/types.h"

token_type_t tokenizer_id_keyword(char const *restrict const chars,
    size_t const len);

token_type_t tokenizer_id_nospace(char const *chars, size_t len);


#endif
