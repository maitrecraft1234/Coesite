#include <stddef.h>
#include "btree.h"

void btree_insert_data_at_left(btree_walker_t *cursor, btree_data_t *data)
{
    btree_node_t *node = btree_node_create(*cursor->current, data);

    if (!node)
        return;
    (*cursor->current)->left = node;
}

void btree_insert_data_at_right(btree_walker_t *cursor, btree_data_t *data)
{
    btree_node_t *node = btree_node_create(*cursor->current, data);

    if (!node)
        return;
    (*cursor->current)->right = node;
}

void btree_insert_data_at_root_left(btree_t *tree, btree_data_t *data)
{
    btree_node_t *node = btree_node_create(NULL, data);

    if (!node)
        return;
    node->left = tree->root;
    tree->root = node;
}

void btree_insert_data_at_root_right(btree_t *tree, btree_data_t *data)
{
    btree_node_t *node = btree_node_create(NULL, data);

    if (!node)
        return;
    node->right = tree->root;
    tree->root = node;
}
