/*
** EPITECH PROJECT, 2024
** src/parser/general/lit_primitive
** File description:
** litterals for primitive types
*/

#include <parser/type.h>
#include <parser/macros.h>
#include <parser/function.h>
#include "parser/grammar_types/general.h"
#include <assert.h>
#include "general/macros.h"
#include "lexer/type.h"

//note that the table should be 0 initialized for the
//other members so we only need to check the length
static pg_type_t lexem_type_to_pg_type(lexem_id_t type)
{
    static const pg_type_t pg_types[] = {
        [LX_LIT_STR] = PGT_STRING,
        [LX_LIT_INT] = PGT_INT,
        [LX_LIT_BOOL] = PGT_BOOL,
    };

    return type >= ARRAY_SIZE(pg_types) ? PGT_UNKNOWN : pg_types[type];
}

// for now only integers are parsed properly becuase Iam lazy
// but this should be easy to add more
pg_lit_primitive_t pg_lit_primitive(parser_t *parser)
{
    pg_lit_primitive_t lit = {0};
    lexem_t lexem = parser_consume_lexem(parser);

    lit.type = lexem_type_to_pg_type(lexem.type);
    lit.value = lexem.lit.value;
    return lit;
}
