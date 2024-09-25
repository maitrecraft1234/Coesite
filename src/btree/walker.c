/*
** EPITECH PROJECT, 2024
** walker
** File description:
** walk
*/

#include "general/btree.h"

btree_walker_t btree_walk(btree_t *tree)
{
    return (btree_walker_t) {
        .current = &tree->root,
        .tree = tree
    };
}

void btree_go_root(btree_walker_t *cursor)
{
    cursor->current = &cursor->tree->root;
}

void btree_go_parent(btree_walker_t *cursor)
{
    if (!(*cursor->current)->parent)
        return;
    cursor->current = &(*cursor->current)->parent;
}

void btree_go_left(btree_walker_t *cursor)
{
    if (!(*cursor->current)->left)
        return;
    cursor->current = &(*cursor->current)->left;
}

void btree_go_right(btree_walker_t *cursor)
{
    if (!(*cursor->current)->right)
        return;
    cursor->current = &(*cursor->current)->right;
}
