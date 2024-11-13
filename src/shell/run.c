/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/shell/run
** File description:
** interpretor shell
*/

#include <stdio.h>
#include <stdlib.h>
#include "itlei.h"

int shell_run(void)
{
    char *line = NULL;
    size_t al = 0;
    int rv = 0;
    long len = 0;

    len = getline(&line, &al, stdin);
    while (len != -1) {
        interpretor_run_from_string(line, len - 1);
        len = getline(&line, &al, stdin);
    }
    free(line);
    return rv;
}
