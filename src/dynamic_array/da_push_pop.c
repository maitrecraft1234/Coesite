/*
** EPITECH PROJECT, 2024
** /home/vj/code/da/src/da_modify
** File description:
** functions for simple modifications of the da
** push to add and pop to remove ()
*/

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include "general/dynamic_array.h"

void *da_push(void *array, const void *data, size_t size)
{
    da_info_t *info = (da_info_t *)array - 1;

    while (info->len + size >= info->cappacity) {
        info->cappacity *= 1.5;
        info = realloc(info, info->cappacity);
        assert(info != NULL);
        array = info + 1;
    }
    memcpy((unsigned char *)info + info->len, data, size);
    info->len += size;
    return array;
}

void *da_acces(void *array, size_t conv_i)
{
    da_info_t *info = (da_info_t *)array - 1;

    conv_i += sizeof(da_info_t);
    assert(conv_i < info->len);
    return array;
}

void da_pop(void *array, size_t size)
{
    DA_INFO(array).len -= size;
}
