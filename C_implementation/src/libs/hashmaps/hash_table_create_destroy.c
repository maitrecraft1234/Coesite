/*
** EPITECH PROJECT, 2024
** create_delete.c
** File description:
** creating and deleting functions
** for the hashtable
*/

#include <stdlib.h>
#include <unistd.h>
#include "hashtable.h"

hashtable_t *ht_create(size_t (*hashf)(ht_key_t), size_t cappacity)
{
    hashtable_t *out = malloc(sizeof *out + sizeof(*out->data) * cappacity);

    if (!out)
        return NULL;
    out->data = (void *)(out + 1);
    for (size_t i = 0; i < cappacity; ++i) {
        out->data[i] = DATA_INIT;
    }
    out->hash = hashf ? hashf : hash;
    out->size = cappacity;
    return out;
}

void ht_destroy(hashtable_t *ht)
{
    size_t size = ht ? ht->size : 0;

    if (!ht)
        return;
    for (size_t i = 0; i < size; ++i) {
        (void)DATA_DESTROY(ht->data[i]);
    }
    (void)free(ht);
}
