#ifndef BTREE_H_
#define BTREE_H_

#define BTREE_USERDATA_OVERRIDE_T char *
#define BTREE_USERDATA_CPY(data) *data
#define BTREE_USERDATA_DESTROY(data)

typedef BTREE_USERDATA_OVERRIDE_T btree_data_t;

typedef struct btree_node_s {
    struct btree_node_s *left;
    struct btree_node_s *right;
    struct btree_node_s *parent;
    btree_data_t data;
} btree_node_t;


typedef struct btree_s {
    btree_node_t *root;
} btree_t;

btree_t btree_create(void);
void btree_destroy(btree_t *);

btree_node_t *btree_leftmost_node(btree_t *tree);

btree_node_t *btree_node_create(
    btree_node_t *left,
    btree_node_t *rigth,
    btree_data_t *data
);
void btree_node_destroy(btree_node_t *n);

typedef struct btree_walker_s {
    btree_node_t **current;
    btree_t *tree;
} btree_walker_t;

btree_walker_t btree_walk(btree_t *tree);
void btree_goto_left(btree_walker_t *cursor);
void btree_goto_right(btree_walker_t *cursor);
void btree_goto_leftmost(btree_walker_t *cursor);
void btree_goto_rightmost(btree_walker_t *cursor);
void btree_goto_root(btree_walker_t *cursor);

#endif
