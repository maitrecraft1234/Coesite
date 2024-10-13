/*
** EPITECH PROJECT, 2024
** src/btree/walker_go_leftrightmost
** File description:
** idk if this will stay tbh
*/

#include "general/btree.h"

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
