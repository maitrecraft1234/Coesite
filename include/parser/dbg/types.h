/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/parser/dbg/types
** File description:
** this convuluted way of declaring shit helps (me) stay
** close to the ebnf
*/

#ifndef PARSER_DBG_TYPES_H_
    #define PARSER_DBG_TYPES_H_

    #include <stddef.h>

typedef struct dbg_grouping_s {
    struct dbg_statement_s *statement;
} pxe_dbg_grouping_t;

typedef struct dbg_unary_op {
    enum {
        pxe_dbg_minus_uop_e
    } type;
    struct dbg_statement_no_left_req *nl_statement;
} pxe_dbg_unary_op_t;

typedef struct dbg_statement_no_left_req {
    union {
        pxe_dbg_grouping_t grouping;
        pxe_dbg_unary_op_t u_op;
        long number_lit;
    };
    enum {
        pxe_dbg_grouping_e,
        pxe_dbg_unary_op_e,
        pxe_dbg_litteral_e
    } type;
} pxe_dbg_statement_no_left_req_t;

typedef struct pxe_dbg_bin_op_high_s {
    pxe_dbg_statement_no_left_req_t *left;
    enum {
        pxe_dbg_mul_bop_e,
        pxe_dbg_div_bop_e,
        pxe_dbgh_none
    } op;
    struct pxe_dbg_bin_op_high_s *right;
} pxe_dbg_bin_op_high_t;

typedef struct dbg_bin_op_s {
    pxe_dbg_bin_op_high_t left;
    enum {
        pxe_dbg_plus_bop_e,
        pxe_dbg_minus_bop_e,
        pxe_dbgl_none
    } op;
    struct dbg_bin_op_s *right;
} pxe_dbg_bin_op_t;

typedef struct dbg_statement_s {
    union {
        pxe_dbg_bin_op_t bin_op;
        pxe_dbg_statement_no_left_req_t *nleft_req;

    };
    enum {
        pxe_dbg_bin_op_e,
        pxe_dbg_statement_no_left_req_e
    } type;
} px_dbg_statement_t;

typedef struct dbg_block_s {
    px_dbg_statement_t *statement;
} px_dbg_block_t;

typedef struct dbg_s {
    px_dbg_block_t block;
    size_t block_len;
} px_dbg_t;

#endif
