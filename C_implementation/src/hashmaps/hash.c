/*
** EPITECH PROJECT, 2024
** hash.c
** File description:
** hash function for secured libraby
*/

#include "general/hashtable/hashtable.h"

unsigned int murmur_hash2(const void *key, size_t len)
{
    unsigned int res = 0xDECAFBAD ^ len;
    const unsigned char *data = (const unsigned char *)key;

    for (unsigned int loop_key; len >= 4; len -= 4) {
        loop_key = *data * 0x5bd1e995;
        loop_key ^= loop_key >> 24;
        loop_key *= 0x5bd1e995;
        res *= 0x5bd1e995;
        res ^= loop_key;
        data += 4;
        len -= 4;
    }
    res ^= (data[2] << 8 * (len - 1)) * 0x5bd1e995;
    res ^= (res >> 13) * 0x5bd1e995;
    res ^= res >> 15;
    return res;
}

size_t hash(ht_key_t key_arg)
{
    size_t seed = 5483;
    const char *key = key_arg->key;
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
