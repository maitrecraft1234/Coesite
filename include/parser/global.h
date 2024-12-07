/*
** EPITECH PROJECT, 2024
** /home/vj/test/language_name_unkown/include/parser/global
** File description:
** static globals declaration for use within parser
*/

#ifndef PARSER_GLOBAL_H_
    #define PARSER_GLOBAL_H_

    #include "parser/type.h"
    #include "parser/function.h"
#include "parser/grammar_types/general.h"

// lookup table for parsing actions in top level parser
// this specific table might be replaced by something less
// generic in the future as it isn't going to contain a
// lot of entries, such tables are more likely to be used
// in the parser functions themselves where the number of
// entries is likely to be higher and genericity is more
// useful to keep the functions short.
static px_def_t (*const parsing_action[])(parser_t *, pg_attribute_t *) = {
    [LX_METH] = pgm_def,
};

#endif
