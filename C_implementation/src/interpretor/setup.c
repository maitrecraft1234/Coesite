/*
** EPITECH PROJECT, 2025
** src/interpretor/setup
** File description:
** setup function for interpretopr datatypes
*/

#include "general/hashtable/hashtable.h"
#include "interpretor/functions.h"
#include "parser/type.h"
#include "general/dynamic_array.h"

// the parser should have already been run don't care enough to enforce this
interpretor_t interpretor_create(interpretor_t *parent)
{
    interpretor_t interpretor = {
        .vars = ht_create(hash, 512),
        .parent = parent,
    };

    return interpretor;
}

void interpretor_fill_from_def(interpretor_t *interpretor, parser_t *parser)
{
    px_def_t *def = parser->defs;
    pgm_def_t meth;

    for (size_t i = 0; i < DA_LEN(def); ++i) {
        if (def[i].type == LX_METH) {
            meth = def[i].meth;
            ht_insert(interpretor->vars,
                    HT_KEY_FROM(meth.name.name, meth.name.size), def + i);
        }
        if (def[i].type == LX_LET) {
            ht_insert(interpretor->vars, HT_KEY_FROM(def[i].global.name.name,
                    def[i].global.name.size), def + i);
        }
    }
}

void interpretor_destroy(interpretor_t *interpretor)
{
    if (!interpretor)
        return;
    ht_destroy(interpretor->vars);
}
