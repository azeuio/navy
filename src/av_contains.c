/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** av_contains
*/

#include <stddef.h>
#include "my.h"

int av_contains(const char **av, const char *str)
{
    for (int i = 0; av[i] != NULL; i++) {
        if (my_strcmp((char *)av[i], str) == 0)
            return 1;
    }
    return 0;
}
