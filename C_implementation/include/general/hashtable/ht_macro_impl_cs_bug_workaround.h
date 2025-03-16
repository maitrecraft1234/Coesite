/*
** EPITECH PROJECT, 2025
** include/general/hashtable/ht_macro_impl_cs_bug_workaround
** File description:
** workaround a bug in the cs
*/


#ifndef HASHTABLE_CSBUG_WORKAROUND_MACRO_H_
    #define HASHTABLE_CSBUG_WORKAROUND_MACRO_H_

    #include <stddef.h>

typedef struct ht_key_s {
    const char *key;
    size_t key_len;
} *ht_key_t;

static inline struct ht_key_s ht_intokey_impl(const char *s, size_t len)
{
    return (struct ht_key_s) { .key = s, .key_len = len };
}

#endif
