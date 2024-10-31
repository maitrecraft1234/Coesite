#include "general/macros.h"
#include "lexer/type.h"
#include "parser/dbg/functions.h"
#include "parser/macros.h"
#include "parser/function.h"
#include "general/dynamic_array.h"

void parser_parse_dbg(parser_t *parser)
{
    px_dbg_t expr;
    expr.block_len = parser_block_size(parser);

    if (expr.block_len == 0)
        return;
    ++parser->lexem_index;
    --expr.block_len;
    expr.block.statement = parser_dbg_parse_statement(parser,
            &expr.block);
    da_push(parser->defs, &expr, sizeof expr);
}
