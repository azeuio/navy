/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** strdup clone
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *new = NULL;

    if (src == NULL)
        return (NULL);
    new = my_strcat(new, src);
    return (new);
}
