#include "general/macros.h"
#include "lexer/type.h"
#include "parser/macros.h"
#include "parser/function.h"
#include "general/dynamic_array.h"

void parser_parse_dbg(parser_t *parser)
{
    size_t exrp_len = parser_block_size(parser);
    px_dbg_t expr;

    if (exrp_len == 0)
        return;
    ++parser->lexem_index;
    --exrp_len;
    while (exrp_len > 0) {
        TODO;
        --exrp_len;
        ++parser->lexem_index;
    }
    da_push(parser->defs, &expr, sizeof expr);
}
