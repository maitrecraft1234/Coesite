/*
** EPITECH PROJECT, 2024
** src/libs/hashmaps/types
** File description:
** header
*/

#ifndef USER_DEFINED_STUFF
    #define USER_DEFINED_STUFF

    #include <stddef.h>
    #include "parser/grammar_types/general.h"

    #define LL_NODE_DATA_OVERRIDE_T ht_data_t
    #define HT_TYPE_OVERRIDE pg_lit_primitive_t

    #ifndef HT_TYPE_OVERRIDE
        #define HT_TYPE_OVERRIDE void *
    #endif
typedef HT_TYPE_OVERRIDE ht_userdata_t;

typedef struct hash_data_s {
    ht_userdata_t data;
    size_t id;
} ht_data_t;

#endif
