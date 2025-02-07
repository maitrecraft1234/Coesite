/*
** EPITECH PROJECT, 2024
** include/parser/grammar_types/general
** File description:
** general grammar rules
*/

#ifndef PGM_GENERAL_H_
    #define PGM_GENERAL_H_

    #include <stdbool.h>
    #include <stdint.h>
    #include <stddef.h>

// this reprensentation does not allow for
// user defined types and more complex types
// such as arrays, structs, unions, etc.
// this will be changed in the future
// and shouldn't require too much refactoring
// to change
typedef enum {
    PGT_UNKNOWN,
    PGT_U8,
    PGT_U16,
    PGT_U32,
    PGT_U64,
    PGT_I8,
    PGT_I16,
    PGT_I32,
    PGT_I64,
    PGT_INT,
    PGT_FINT,
    PGT_BOOL,
    PGT_STRING,
    PGT_VOID,
} pg_type_t;

// Should be fairly easy to get from lexems
typedef struct pg_identifier_s {
    const char *name;
    size_t size;
} pg_identifier_t;

// this is a bit of a placeholder for now
// not lexems because I don't want some include loops
typedef struct pg_attribute_s {
    void *attributes;
} pg_attribute_t;

typedef struct pg_lit_primitive_s {
    pg_type_t type;
    union {
    #if UINTPTR_MAX == UINT64_MAX
        uintptr_t u64;
        char *str;
        bool boolean;
    #elif UINTPTR_MAX == UINT32_MAX
        #error platform support not implemented
        uintptr_t u32;
    #elif UINTPTR_MAX == UINT16_MAX
        #error platform support not implemented
        uintptr_t u16;
    #elif UINTPTR_MAX == UINT8_MAX
        #error platform support not implemented
        uintptr_t u8;
    #else
        #error unsupported platform
    #endif
    } value;
} pg_lit_primitive_t;

// can't include lexer/type.h because of include loops
typedef struct pgmx_additive_s pgm_expression_t;

typedef struct pg_fn_call_s {
    const char *name;
    size_t size;
    union { // these are dynamic arrays of expressions
        pgm_expression_t *meth_args;
    };
} pg_fn_call_t;

#endif
