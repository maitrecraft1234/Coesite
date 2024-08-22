#ifndef GENERAL_MACROS_H_
#define GENERAL_MACROS_H_

#define IS_PTR_SIZE(s) (sizeof(s) == sizeof(void *))
#define COOL_STRLEN(s) (IS_PTR_SIZE(s) ? strlen(s) : sizeof(s))
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(*arr))

#include <stdio.h>
#include <stdlib.h>

#define CLR_ER(er) "\33[01;31m"er"\33[00m"
#define CLR_WARN(er) "\33[01;35m"er"\33[00m"
#define ERROR(fmt, ...) fprintf(stderr, CLR_ER("ERROR: ")fmt, __VA_ARGS__)
#define LOG(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#define WARN(fmt, ...) fprintf(stderr, CLR_WARN("WARNING: ")fmt, __VA_ARGS__)

static inline void macro_impl_todo(int line, char *file)
{
    printf("TODO: on file: %s, line: %d\n", file, line);
    exit(127);
}

#define TODO macro_impl_todo(__LINE__, __FILE__)

#endif
