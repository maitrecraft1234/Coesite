/*
** EPITECH PROJECT, 2024
** hash.c
** File description:
** hash function for secured libraby
*/

#include "hashtable.h"

size_t hash(ht_key_t key_arg)
{
    size_t seed = 5483;
    char *key = key_arg->key;
    size_t key_len = key_arg->key_len;

    for (; key_len > 0; --key_len) {
        seed = (seed << 13) ^ seed;
        seed = ((seed * (seed * seed * 15731 + 789221)
                + 1376312589) & 0x7fffffff);
        seed *= *key == 0 ? 1 : *key;
        ++key;
    }
    return seed;
}
