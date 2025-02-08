/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <unistd.h>

    #include "types.h"

// user defined stuff
// here using arrays

    #define USE_BUILTIN_LINKED_LIST
    #define USE_BUILTIN_DARRAY

// here using linked lists
#if defined(USE_BUILTIN_LINKED_LIST)

    #include "linked_list.h"

    #define HT_BUCKET_T          linked_list_t
    #define HT_BUCKET_ITERATOR_T ll_node_t **

    #define DATA_INIT                   ll_create()
    #define DATA_DESTROY(data)          ll_destroy(&(data))
    #define DATA_APPEND(list, new_data) ll_append(&list, &new_data)

static inline void list_remove_helper_function(ll_node_t **item)
{
    void *tbr = *item;

    *item = (*item)->next;
    ll_node_destroy(tbr);
}

    #define DATA_REMOVE(unused, iter)  list_remove_helper_function(iter)
    #define DATA_NEXT(iter)            ((iter) = &(*(iter))->next)
    #define DATA_REACH_END(list, iter) (NULL == *(iter))
    #define DATA_GET_ITER(list)        (&(list).head)
    #define DATA_ASSIGN(node, new)     ((*(node))->data = (new))
    #define DATA_GET_ID(cur)           ((*cur)->data.id)
    #define DATA_GET_DATA(cur)         ((*cur)->data)
    #define DATA_GET_USER_DATA(cur)    ((*(cur))->data.data)

#elif defined(USE_BUILTIN_DARRAY)

    #include <string.h>
    #include "dynamic_array.h"

    #define HT_BUCKET_T          ht_data_t *
    #define HT_BUCKET_ITERATOR_T HT_BUCKET_T

    #define DATA_INIT                da_create()
    #define DATA_DESTROY(data)       da_destroy(data)
    #define DATA_APPEND(ar, data)    (ar = da_push(ar, &data, sizeof(data)))

static inline void *helper_array_remove(
    void *first_point, void *to_remove, size_t data_size) {
    char *pt = first_point;
    char *data = to_remove;

    memcpy(data, data + data_size, DA_LEN(pt) - (data - pt));
    DA_INFO(pt).len -= data_size;
    return pt;
}
    #define DATA_REMOVE(df, dp) (df = helper_array_remove(df, dp, sizeof(*dp)))
    #define DATA_NEXT(data_point) (++data_point)
    #define DATA_REACH_END(ar, iter) ((ar + DA_LEN(ar)) == iter)
    #define DATA_GET_ITER(data) (data)
    #define DATA_ASSIGN(to, from) (*(to) = (from))
    #define DATA_GET_ID(cur) ((cur)->id)
    #define DATA_GET_DATA(cur) (cur)
    #define DATA_GET_USER_DATA(cur) ((cur)->data)

#endif
// the rest and whatnot

#ifndef HT_BUCKET_T
    #error SOME BUCKET TYPE MUST BE CHOOSEN
#endif
typedef HT_BUCKET_T ht_bucket_t;

#ifndef HT_BUCKET_ITERATOR_T
    #error A TYPE MUST BE DEFINED FOR BUCKET ITERATORS
#endif
typedef HT_BUCKET_ITERATOR_T ht_bucket_iter_t;

// can be modified if you want different type of keys but will
// require a new hash function also easyish to use with other types

typedef struct ht_key_s {
    const char *key;
    size_t key_len;
} *ht_key_t;


    // this is defined in the macros.h but I need it here and
    // I want this to be possible to transfer to other projects (maybe)
    #ifndef REF_FUNC_CALL
        #define REF_FUNC_CALL(func) &((typeof(func)[]) { (func) })[0]
    #endif

static inline struct ht_key_s ht_into_key_impl(const char *s, size_t len)
{
    return (struct ht_key_s) { .key = s, .key_len = len };
}

    // this is a bit hacky but the coding style makes really verbose code
    // hard to write
    #define HT_INTO_KEY(s) ht_into_key_impl((void *)REF_FUNC_CALL(s), sizeof(s))
    #define HT_INTO_KEY_REF(s) REF_FUNC_CALL(HT_INTO_KEY(s))

    #define HT_KEY_FROM(s, l) REF_FUNC_CALL(ht_into_key_impl(s, l))

typedef struct hashtable_s {
    size_t (*hash)(ht_key_t);
    size_t size;
    ht_bucket_t *data;
} hashtable_t;

// Hash function should only be used with default or compatible key type
size_t hash(ht_key_t key);
size_t murmur_hash2(const void *key, size_t len);

// Create & destro table
hashtable_t *ht_create(size_t (*hash)(ht_key_t), size_t cappacity);
void ht_destroy(hashtable_t *ht);

// Handle table
hashtable_t *ht_insert(hashtable_t *ht, ht_key_t key, ht_userdata_t *value);
void ht_remove(hashtable_t *ht, ht_key_t key);
ht_bucket_iter_t ht_search_bucket(hashtable_t *ht, ht_key_t key);
ht_userdata_t *ht_search(hashtable_t *ht, ht_key_t key);
void ht_foreach(hashtable_t *ht, void (*fn)(ht_userdata_t *));

#endif
