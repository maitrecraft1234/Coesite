#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "types.h"

#ifndef LL_NODE_DATA_OVERRIDE_T
#define LL_NODE_DATA_OVERRIDE_T struct {long a; char *val;}
#endif


typedef LL_NODE_DATA_OVERRIDE_T ll_node_data_t;

#ifndef LL_NODE_DATA_DESTROY
#define LL_NODE_DATA_DESTORY(data)
#endif

//define if you want the data to be copied using a specicfi gfunction
#ifndef LL_NODE_DATA_CPY
#define LL_NODE_DATA_CPY(data) (*data)
#endif

typedef struct ll_node_s {
    ll_node_data_t data;
    struct ll_node_s *next;
} ll_node_t;

typedef struct linked_list_s {
    ll_node_t *head;
    ll_node_t *tail;
} linked_list_t;

linked_list_t ll_create(void);
void ll_destroy(linked_list_t *);
ll_node_t *ll_node_create(ll_node_t *next, ll_node_data_t *data);
void ll_node_destroy(ll_node_t *node);
void ll_insert(linked_list_t *list, ll_node_data_t *data);
void ll_append(linked_list_t *list, ll_node_data_t *data);
ll_node_t **ll_search(
        linked_list_t *list,
        ll_node_data_t *data,
        int (*comparator)(ll_node_data_t *, ll_node_data_t *)
        );
void ll_foreach(linked_list_t *list,
    void (*action)(ll_node_t *prev, ll_node_t *current));

#endif
