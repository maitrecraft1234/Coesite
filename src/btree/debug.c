/*
** EPITECH PROJECT, 2024
** debug
** File description:
** debug
*/

#include <stddef.h>
#include <stdio.h>
#include "btree.h"

static void helper_dump_req(btree_node_t *n, size_t level)
{
    if (!n)
        return;
    helper_dump_req(n->left, level + 1);
    for (size_t i = 0; i < level; i++)
        puts("  ");
    BTREE_USERDATA_PRINT(n->data);
    helper_dump_req(n->right, level + 1);
}

void btree_dump(btree_t *tree)
{
    btree_node_t *root = tree->root;
    helper_dump_req(root, 0);
}
