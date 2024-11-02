#include "general/macros.h"
#include "lexer/type.h"
#include "parser/dbg/functions.h"
#include "parser/dbg/types.h"
#include "parser/macros.h"
#include "parser/function.h"
#include "general/dynamic_array.h"

px_dbg_t parser_parse_dbg(parser_t *parser)
{
    px_dbg_t expr;
    expr.block_len = parser_block_size(parser);

    if (expr.block_len == 0)
        return expr;
    ++parser->lexem_index;
    --expr.block_len;
    expr.block.statement = parser_dbg_parse_statement(parser);
    parser->defs = da_push(parser->defs, &expr, sizeof expr);
    ++parser->lexem_index;
    return expr;
}
