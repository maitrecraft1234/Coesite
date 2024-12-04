/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/include/general/macros
** File description:
** macros
*/

#ifndef GENERAL_MACROS_H_
    #define GENERAL_MACROS_H_

    #define IS_PTR_SIZE(s) (sizeof(s) == sizeof(void *))
    #define COOL_STRLEN(s) (IS_PTR_SIZE(s) ? strlen(s) : (sizeof(s) - 1))
    #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(*arr))

    // note that p should be a variable with a pointer type
    // it is not declared in the macro since it might be usefull
    // in a loop or a struct member which you wouldn't want to be declared
    // and v can be any kind of value (function call are fine because
    // sizeof doesn't evaluate the function)
    #define HEAPIFY(p, v) ((p) = malloc(sizeof v) ? *(p) = v : NULL)

    #include <stdio.h>
    #include <stdlib.h>

    #define CLR_ER(er) "\33[01;31m"er"\33[00m"
    #define CLR_WARN(er) "\33[01;35m"er"\33[00m"
    #define ERROR(fmt, ...) fprintf(stderr, CLR_ER("ERROR: ")fmt, __VA_ARGS__)
    #define LOG(file, fmt, ...) fprintf(file, fmt, __VA_ARGS__)
    #define WARN_STR CLR_WARN("WARNING: ")
    #define WARN(fmt, ...) fprintf(stderr, WARN_STR fmt, __VA_ARGS__)
    #define BOLD(msg, ...) "\33[01m"msg"\33[00m"

static inline void macro_impl_todo(int line, char *file)
{
    ERROR(CLR_ER("TODO! ") BOLD("file: %s, line: %d\n"), file, line);
    exit(127);
}

    #define TODO macro_impl_todo(__LINE__, __FILE__)
    #define TODO_NOBLOCK WARN("TODO! file: %s, line: %d\n", __FILE__, __LINE__)

    #define CASE(c) if (0) case c:

#endif
