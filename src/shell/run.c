/*
** EPITECH PROJECT, 2024
** /home/vj/coding/itlei/src/shell/run
** File description:
** interpretor shell
*/

#include <stdio.h>
#include <stdlib.h>

int shell_run(void)
{
    char *line = NULL;
    size_t len = 0;
    int rv = 0;

    while (getline(&line, &len, stdin) != -1) {
//        rv = interpretor_eval_expr(line);
    }
    free(line);
    return rv;
}
