/*
** EPITECH PROJECT, 2021
** strcat
** File description:
** concatenate strings dest+src
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len;
    int lensrc;

    if (src == NULL)
        return (dest);
    lensrc = my_strlen(src);
    if (dest == NULL) {
        dest = malloc(sizeof(char) * lensrc);
        dest[0] = '\0';
    }
    len = my_strlen(dest);
    for (int i = 0; i < lensrc + 1; i++) {
        dest[len + i] = src[i];
    }
    return (dest);
}
