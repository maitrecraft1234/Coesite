/*
** EPITECH PROJECT, 2025
** include/interpretor/types
** File description:
** types for the interpretor
*/

#ifndef INTERPRETOR_TYPES_H_
    #define INTERPRETOR_TYPES_H_

    #include "general/hashtable/hashtable.h"

    typedef struct interpretor_s {
        hashtable_t *vars;
    } interpretor_t;

#endif
