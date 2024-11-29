/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/parser/meth/types
** File description:
** C equivalent for the ebnf
*/

#ifndef PGM_DECLARATION_H_
    #define PGM_DECLARATION_H_

typedef struct meth_decl_s meth_decl_t;

    #warning TYPESYSTEM needs to be made and args
typedef int type_t;
typedef char identifier_t[512];
typedef struct args *args_t;
typedef void *meth_block_t;

struct meth_decl_s {
    identifier_t name;
    type_t return_type;
    args_t args;
    meth_block_t block;
};
#endif
