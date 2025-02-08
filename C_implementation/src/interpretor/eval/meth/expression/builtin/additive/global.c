/*
** EPITECH PROJECT, 2025
** src/interpretor/eval/meth/expression/builtin/additive/global
** File description:
** global declaration for the thing 
*/

#include "interpretor/builtins/additive_global.h"

// stupid trick to avoid warnings
static int useless(int a)
{
    (void)add_lookup;
    (void)sub_lookup;
    if (a == 3)
        return 3;
    return useless(a - 1);
}
