/*
** EPITECH PROJECT, 2024
** include/general/macros
** File description:
** macros
*/

#ifndef GENERAL_MACROS_H_
    #define GENERAL_MACROS_H_


    #define PANIC(msg) macro_impl_panic(msg, __LINE__, __FILE__)

    #define IS_PTR_SIZE(s) (sizeof(s) == sizeof(void *))
    #define COOL_STRLEN(s) (IS_PTR_SIZE(s) ? strlen(s) : (sizeof(s) - 1))
    #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(*arr))

    // the function is defined later in the file
    #define ALLOC_FAIL PANIC("alloc failed")

    // note that p should be a variable with a pointer type
    // it is not declared in the macro since it might be usefull
    // in a loop or a struct member which you wouldn't want to be declared
    // and v can be any kind of value (function call are fine because
    // sizeof doesn't evaluate the function)
    // note also that in case of a malloc failure the value will
    // still be evaluated
    #define HEAPIFY(p, v) (((p) = malloc(sizeof v)) ? *(p) = v : ALLOC_FAIL)

    // this is a bit hacky but because of the function line
    // limit it can actually prove usefull
    #define REF_FUNC_CALL(func) &((typeof(func)[]) { (func) })[0]

    #include <stdio.h>
    #include <stdlib.h>

    #define CLR_ER(er) "\33[01;31m"er"\33[00m"
    #define CLR_WARN(er) "\33[01;35m"er"\33[00m"
    #define ERROR(fmt, ...) fprintf(stderr, CLR_ER("ERROR: ")fmt, __VA_ARGS__)
    #define LOG(file, fmt, ...) fprintf(file, fmt, __VA_ARGS__)
    #define WARN_STR CLR_WARN("WARNING: ")
    #define WARN(fmt, ...) fprintf(stderr, WARN_STR fmt, __VA_ARGS__)
    #define BOLD(msg, ...) "\33[01m"msg"\33[00m"

    #define EXIT_FAIL_CODE 84
    #define EXIT_FAIL exit(EXIT_FAIL_CODE)

static inline void macro_impl_panic(char *msg, int line, char *file)
{
    ERROR(CLR_ER("%s ") BOLD("file: %s, line: %d\n"), msg, file, line);
    EXIT_FAIL;
}

    #define TODO PANIC("TODO!")
    #define TODO_NOBLOCK WARN("TODO! file: %s, line: %d\n", __FILE__, __LINE__)

    #ifdef DEBUG
        #define UNREACHABLE PANIC("unreachable code")
    #elif defined(__GNUC__)
        #define UNREACHABLE __builtin_unreachable()
    #else
        #define UNREACHABLE *(int *)0 = 0
    #endif

    #define CASE(c) if (0) case c:
    #define DEFAULT if (0) default:

#endif
