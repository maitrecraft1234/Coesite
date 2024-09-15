#include "btree.h"

void btree_go_leftmost(btree_walker_t *cursor)
{
    while ((*cursor->current)->left)
        cursor->current = &(*cursor->current)->left;
}

void btree_go_rightmost(btree_walker_t *cursor)
{
    while ((*cursor->current)->right)
        cursor->current = &(*cursor->current)->right;
}
