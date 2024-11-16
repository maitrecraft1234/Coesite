/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/parser/meth/types
** File description:
** C equivalent for the ebnf
*/

typedef struct meth_decl_s meth_decl_t;

#warning TYPESYSTEM needs to be made and args
typedef int type;
typedef char identifier_t[512];
typedef struct args *args_t;
typedef void *meth_block_t;

struct meth_decl_s {
    identifier_t name;
    type return_type;
    args_t args;
    meth_block_t block;
};
