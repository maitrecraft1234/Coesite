#ifndef USER_DEFINED_STUFF
#define USER_DEFINED_STUFF

#include <stddef.h>

#define LL_NODE_DATA_OVERRIDE_T ht_data_t
#define HT_TYPE_OVERRIDE char *

#ifndef HT_TYPE_OVERRIDE
#define HT_TYPE_OVERRIDE void *
#endif
typedef HT_TYPE_OVERRIDE ht_userdata_t;

typedef struct hash_data_s {
    ht_userdata_t data;
    size_t id;
} ht_data_t;

#endif
