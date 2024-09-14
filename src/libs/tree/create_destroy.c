#include <stdlib.h>
#include "btree.h"

btree_node_t *btree_node_create(
    btree_node_t *left,
    btree_node_t *rigth,
    btree_data_t *data
)
{
    btree_node_t *node = malloc(sizeof *node);

    if (!node)
        return node;
    node->left = left;
    node->right = rigth;
    node->data = BTREE_USERDATA_CPY(data);
    return node;
}

void btree_node_destroy(btree_node_t *n)
{
    BTREE_USERDATA_DESTROY(n->data);
    free(n);
}

static void helper_destroy_req(btree_node_t *n)
{
    if (!n)
        return;
    helper_destroy_req(n->left);
    helper_destroy_req(n->right);
    btree_node_destroy(n);
}

btree_t btree_create(void)
{
    return (btree_t){.root = NULL};
}

void btree_destroy(btree_t *tree)
{
    helper_destroy_req(tree->root);
    tree->root = NULL;
}
