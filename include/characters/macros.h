#ifndef CHAR_MACROS_
#define CHAR_MACROS_

#include <ctype.h>

#define IS_WHITE_SPACE(c) isblank(c)
/* #define IS_WHITE_SPACE(c) ((c) == ' ' || (c) == '\n' || (c) == '\t') */

#endif
