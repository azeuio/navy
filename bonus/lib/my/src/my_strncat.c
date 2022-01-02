/*
** EPITECH PROJECT, 2021
** strncat
** File description:
** concatenate strings dest+src up till n char in src
*/

#include <stddef.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int len;
    int lensrc;

    if (src == NULL)
        return (dest);
    if (dest == NULL) {
        return (dest);
    }
    len = my_strlen(dest);
    lensrc = n < my_strlen(src) ? n : my_strlen(src);
    for (int i = 0; i < lensrc + 1; i++) {
        dest[len + i] = src[i];
    }
    dest[len + lensrc] = '\0';
    return (dest);
}
