/*
** EPITECH PROJECT, 2024
** src/libs/hashmaps/ll_nodes_create_destroy_insert
** File description:
** llinke
*/

#include <stdlib.h>
#include "general/hashtable/linked_list.h"

ll_node_t *ll_node_create(ll_node_t *next, ll_node_data_t *data)
{
    ll_node_t *node = malloc(sizeof *node);

    if (!node) {
        return node;
    }
    node->data = LL_NODE_DATA_CPY(data);
    node->next = next;
    return node;
}

void ll_node_destroy(ll_node_t *node)
{
    if (!node)
        return;
    LL_NODE_DATA_DESTORY(node->data);
    free(node);
}

void ll_insert(linked_list_t *list, ll_node_data_t *data)
{
    ll_node_t *new = ll_node_create(list->head, data);

    if (!new)
        return;
    list->head = new;
    if (!list->tail) {
        list->tail = list->head;
    }
}

void ll_append(linked_list_t *list, ll_node_data_t *data)
{
    ll_node_t *tail = ll_node_create(NULL, data);

    if (!tail)
        return;
    if (list->tail) {
        list->tail->next = tail;
    }
    list->tail = tail;
    if (!list->head)
        list->head = tail;
}
