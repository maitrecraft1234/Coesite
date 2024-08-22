#include <criterion/internal/new_asserts.h>
#include <criterion/parameterized.h>
#include <criterion/new/assert.h>
#include "tokenizer/functions.h"
#include "tokenizer/types.h"

#define TOK_CREAT_FS(s) (tokenizer_t){.code = (char *)s, .code_len = sizeof s, .line = 1, .cursor = 0, .is_code_dynamic_allocation = false}

typedef struct {
    tokenizer_t tok;
    token_type_t expected;
} test_params_t;

ParameterizedTestParameters(tokenizer, test_token_next_single)
{

#define X(_, id)  static char s_##_[] = id;
    XVT_COMMENT_START
    XV_TOKENS_KEYWORDS
#undef X

#define X(_, id) (void)s_##_;
    XVT_COMMENT_START
    XV_TOKENS_KEYWORDS
#undef X

    static test_params_t params[] = {
        {.tok = TOK_CREAT_FS(s_let), .expected = tk_let},
        /* {.tok = TOK_CREAT_FS(s_eo_expr)}, */
        /* {.tok = TOK_CREAT_FS(s_par_open)}, */
        /* {.tok = TOK_CREAT_FS(s_op_cmp_eq)}, */
        /* {.tok = TOK_CREAT_FS(s_assign)}, */
        /* {.tok = TOK_CREAT_FS(s_bool_true)}, */
        /* {.tok = TOK_CREAT_FS(s_bool_false)}, */
        /* {.tok = TOK_CREAT_FS(s_none)}, */
        /* {.tok = TOK_CREAT_FS(s_op_not)}, */
        /* {.tok = TOK_CREAT_FS(s_return)}, */
        /* {.tok = TOK_CREAT_FS(s_op_cmp_ge)}, */
    };
    size_t nb_params = (sizeof params) / (sizeof *params);

    return cr_make_param_array(test_params_t, params, nb_params);
}

ParameterizedTest(test_params_t *params, tokenizer, test_token_next_single)
{
    token_t token = tokenizer_token_next(&params->tok);

    if (!params->tok.code)
        cr_skip();
    cr_assert(token.type == params->expected);
    cr_assert(token.len == strlen(params->tok.code));
    __auto_type _ = tokenizer_token_next(&params->tok);
    cr_assert(token.type == tk_eof);
    return ;
}
