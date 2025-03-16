/*
** EPITECH PROJECT, 2025
** include/interpretor/types
** File description:
** types for the interpretor
*/

#ifndef INTERPRETOR_TYPES_H_
    #define INTERPRETOR_TYPES_H_

    #include "general/hashtable/hashtable.h"

// this is most likely temporary, this structure might be more representative
// of namespaces
typedef struct interpretor_s {
    hashtable_t *vars;
    struct interpretor_s *parent;
} interpretor_t;

#endif
