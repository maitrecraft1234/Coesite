/*
** EPITECH PROJECT, 2024
** src/main
** File description:
** main
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "itlei.h"

const char default_program[] = "let a = 1;\n" "print(a)";

int main(int argc, char *argv[argc])
{
    errno = 0;
    if (argc == 1) {
        shell_run();
    } else
        interpretor_run_from_file(argv[1]);
    return errno;
}
