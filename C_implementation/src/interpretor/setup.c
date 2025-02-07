/*
** EPITECH PROJECT, 2025
** src/interpretor/setup
** File description:
** setup function for interpretopr datatypes
*/

#include "general/hashtable/hashtable.h"
#include "interpretor/types.h"
#include "general/dynamic_array.h"

// the parser should have already been run don't care enough to enforce this
interpretor_t interpretor_create(interpretor_t *parent, parser_t *parser)
{
    interpretor_t interpretor = {
        .vars = ht_create(hash, 512),
        .parent = parent,
    };

    for (size_t i = 0; i < DA_LEN(parser->defs); ++i) {
        px_def_t def = parser->defs[i];

        interpretor.vars = ht_insert(interpretor.vars,
                HT_KEY_FROM(def.meth.name.name, def.meth.name.size), &def);
    }
    return interpretor;
}

void interpretor_destroy(interpretor_t *interpretor)
{
    if (!interpretor)
        return;
    ht_destroy(interpretor->vars);
    interpretor_destroy(interpretor->parent);
}
