/*
** EPITECH PROJECT, 2024
** /home/vj/code/da/include/da
** File description:
** header for dynamic array library da
*/

#ifndef DYNAMIC_ARRAY_LIB_H_
#define DYNAMIC_ARRAY_LIB_H_
#include <stddef.h>

#define ARRAY_SCALING_FACTOR 1.5

typedef struct {
    size_t len;
    size_t cappacity;
} da_info_t;

//call these function to create and destroy dynamic arrays
void *da_create(void);
void *da_create_with_cappacity(size_t);
void da_destroy(void *darray);

#define DA_INFO(ar) (((da_info_t *)(ar))[-1])
#define DAC(ar, i) (ar = da_acces(ar, sizeof(*ar) * i)[i])
#define DA_LEN(ar) ((DA_INFO(ar).len - sizeof(da_info_t)) / sizeof(*ar))

//used by macros
void *da_acces(void *array, size_t conv_i);

//function for simple utilities
void *da_push(void *array, const void *data, size_t size);
void da_pop(void *array, size_t size);
#endif
