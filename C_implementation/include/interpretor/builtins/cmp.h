//since all these return bools mabe
//pg_lit_primitive is wrong but we will see later
#ifndef INTERPRETOR_BUILTINS_CMP_H_
    #define INTERPRETOR_BUILTINS_CMP_H_

    #include "parser/grammar_types/general.h"

extern pg_lit_primitive_t ibf_gt_u64(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);

extern pg_lit_primitive_t ibf_ge_u64(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);

extern pg_lit_primitive_t ibf_lt_u64(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);

extern pg_lit_primitive_t ibf_le_u64(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);

extern pg_lit_primitive_t ibf_eq_u64(pg_lit_primitive_t *a,
    pg_lit_primitive_t *b);

extern pg_lit_primitive_t (*const cmp_gt_lookup[])(pg_lit_primitive_t *,
    pg_lit_primitive_t *);
extern pg_lit_primitive_t (*const cmp_ge_lookup[])(pg_lit_primitive_t *,
        pg_lit_primitive_t *);
extern pg_lit_primitive_t (*const cmp_lt_lookup[])(pg_lit_primitive_t *,
    pg_lit_primitive_t *);
extern pg_lit_primitive_t (*const cmp_le_lookup[])(pg_lit_primitive_t *,
    pg_lit_primitive_t *);
extern pg_lit_primitive_t (*const cmp_gt_lookup[])(pg_lit_primitive_t *,
    pg_lit_primitive_t *);
extern pg_lit_primitive_t (*const cmp_eq_lookup[])(pg_lit_primitive_t *,
    pg_lit_primitive_t *);

#endif
