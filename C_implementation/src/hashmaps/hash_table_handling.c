/*
** EPITECH PROJECT, 2024
** hash_dump
** File description:
** prints the contents of the given hash table in std out
*/

#include <stdlib.h>
#include <unistd.h>
#include "general/hashtable/hashtable.h"

void ht_remove(hashtable_t *ht, ht_key_t key)
{
    const size_t hash = ht->hash(key);
    const size_t ht_i = hash % ht->size;

    for (ht_bucket_iter_t cur = DATA_GET_ITER(ht->data[ht_i]);
            !DATA_REACH_END(ht->data[ht_i], cur);
            DATA_NEXT(cur)) {
        if (DATA_GET_ID(cur) == hash) {
            DATA_REMOVE(ht->data[ht_i], cur);
        }
    }
}

hashtable_t *ht_insert(hashtable_t *ht, ht_key_t key, ht_userdata_t *value)
{
    const size_t hash = ht->hash(key);
    const size_t ht_i = hash % ht->size;
    ht_bucket_iter_t data_point = ht_search_bucket(ht, key);
    ht_data_t new_data = {.id = hash, .data = *value};

    if (data_point) {
        DATA_ASSIGN(data_point, new_data);
        return ht;
    }
    DATA_APPEND(ht->data[ht_i], new_data);
    return ht;
}

ht_bucket_iter_t ht_search_bucket(hashtable_t *ht, ht_key_t key)
{
    const size_t hash = ht->hash(key);
    const size_t ht_i = hash % ht->size;
    ht_bucket_iter_t cur = DATA_GET_ITER(ht->data[ht_i]);

    while (!DATA_REACH_END(ht->data[ht_i], cur)) {
            if (DATA_GET_ID(cur) == hash) {
                return cur;
            }
            DATA_NEXT(cur);
        }
    return NULL;
}

ht_userdata_t *ht_search(hashtable_t *ht, ht_key_t key)
{
    return &DATA_GET_USER_DATA(ht_search_bucket(ht, key));
}

void ht_foreach(hashtable_t *ht, void (*fn)(ht_userdata_t *))
{
    ht_bucket_iter_t cur;

    for (size_t ht_i = 0; ht_i < ht->size; ++ht_i) {
        cur = DATA_GET_ITER(ht->data[ht_i]);
        while (!DATA_REACH_END(ht->data[ht_i], cur)) {
            fn(&DATA_GET_USER_DATA(cur));
            DATA_NEXT(cur);
        }
    }
}
