/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/parser/dbg/types
** File description:
** this convuluted way of declaring shit helps (me) stay
** close to the ebnf
*/

typedef struct dbg_grouping_s {
    struct dbg_statement_s *statement;
} pxe_dbg_grouping_t;

typedef struct dbg_unary_op {
    enum {
        pxe_dbg_minus_uop_e
    } type;
    int val;
} pxe_dbg_unary_op_t;

typedef struct dbg_statement_no_left_req {
    union {
        pxe_dbg_grouping_t grouping;
        pxe_dbg_unary_op_t u_op;
        int number_lit;
    };
    enum {
        pxe_dbg_grouping_e,
        pxe_dbg_unary_op_e,
        pxe_dbg_litteral_e
    } type;
} pxe_dbg_statement_no_left_req_t;

typedef struct dbg_bin_op_s {
    pxe_dbg_statement_no_left_req_t left;
    enum {
        pxe_dbg_plus_bop_e,
        pxe_dbg_minus_bop_e
    } op;
    struct dbg_statement_s *right;
} pxe_dbg_bin_op_t;

typedef struct dbg_statement_s {
    union {
        pxe_dbg_bin_op_t bin_op;
        pxe_dbg_statement_no_left_req_t left_req;

    };
    enum {
        pxe_dbg_bin_op_e,
        pxe_dbg_statement_no_left_req_e
    } type;
} px_dbg_statement_t;

typedef struct dbg_block_s {
    px_dbg_statement_t statement;
} px_dbg_block_t;

typedef struct dbg_s {
    px_dbg_block_t block;
} px_dbg_t;

