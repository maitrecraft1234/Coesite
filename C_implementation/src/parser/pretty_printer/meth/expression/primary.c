/*
** EPITECH PROJECT, 2025
** src/parser/pretty_printer/meth/expression/primary
** File description:
** qehuoqgh
*/

#include <stdio.h>
#include "general/macros.h"
#include "lexer/functions.h"
#include "parser/function.h"
#include "parser/print/functions.h"
#include "general/dynamic_array.h"
#include "parser/grammar_types/meth/expression.h"
#include "parser/grammar_types/meth/type_tag.h"

// eventually should extract to general gramar
static void parser_dump_lit_primitive(pg_lit_primitive_t *literal)
{
    switch (literal->type) {
        case PGT_INT:
            return (void)printf("%ld ", literal->value.u64);
        case PGT_STRING:
            putchar('"');
            (void)fwrite(literal->value.str, 1, DA_LEN(literal->value.str), stdout);
            return (void)printf("\" ");
        case PGT_BOOL:
            return (void)printf("%s ", literal->value.boolean ? "true" : "false");
        default:
            TODO;
    }
}

void parser_dump_meth_terminal(pgmx_terminal_t *terminal)
{
    putchar(' ');
    switch (terminal->type) {
        case PGM_IDENTIFIER:
            (void)fwrite(terminal->identifier.name,
                    terminal->identifier.size, 1, stdout);
            return (void)putchar(' ');
        case PGM_LITERAL:
            return parser_dump_lit_primitive(&terminal->literal);
        case PGM_FN_CALL:
            (void)fwrite(terminal->fn_call.name, terminal->fn_call.size, 1, stdout);
            putchar('(');
            for (size_t i = 0; i < DA_LEN(terminal->fn_call.meth_args); i++) {
                parser_dump_meth_expression(&terminal->fn_call.meth_args[i]);
                if (i + 1 < DA_LEN(terminal->fn_call.meth_args))
                    putchar(',');
            }
            return (void)putchar(')');
        UNREACHABLE_DEFAULT;
    }
}

void parser_dump_meth_primary(pgmx_primary_t *primary)
{
    switch (primary->type) {
        case PGM_BLOCK:
            return parser_dump_meth_block(primary->block);
        case PGM_GROUPING:
            return parser_dump_meth_expression(primary->grouping.expr);
        case PGM_UNARY:
            lexem_dbg_id_print(primary->unary.operator);
            return parser_dump_meth_expression(primary->unary.expr);
        case PGM_TERMINAL:
            return parser_dump_meth_terminal(&primary->terminal);
        UNREACHABLE_DEFAULT;
    }
}
