#include "linked_list.h"

//this would be so much better if it could be a macro but I don't think I can
void ll_foreach(linked_list_t *list,
    void (*action)(ll_node_t *prev, ll_node_t *current))
{
    void *prev = 0;

    for (ll_node_t *cur = list->head;; cur = cur->next) {
        action(prev, cur);
        prev = cur;
        if (cur == list->tail)
            break;
    }
    action(prev, NULL);
}

ll_node_t **ll_search(
        linked_list_t *list,
        ll_node_data_t *data,
        int (*comparator)(ll_node_data_t *, ll_node_data_t *)
        )
{
    for (ll_node_t **cur = &list->head;; cur = &(*cur)->next) {
        if (comparator(data, &(*cur)->data) == 0)
            return cur;
        if (*cur == list->tail)
            break;
    }
    return 0;

}

linked_list_t ll_create(void)
{
    linked_list_t new_list = {.head = 0, .tail = 0};

    return new_list;
}

static void ll_node_destroy_in_foreach_s(ll_node_t *p, ll_node_t *c)
{
    (void)c;
    return ll_node_destroy(p);
}

void ll_destroy(linked_list_t *list)
{
    ll_foreach(list, ll_node_destroy_in_foreach_s);
    list->head = NULL;
    list->tail = NULL;
}
