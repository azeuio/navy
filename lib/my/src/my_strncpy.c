/*
** EPITECH PROJECT, 2021
** strcpy
** File description:
** copy n char from one string onto another
*/

#include <stddef.h>
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int len;

    if (dest == NULL)
        return (dest);
    if (src == NULL || n < 0) {
        dest[0] = '\n';
        return (dest);
    }
    len = my_strlen(src);
    for (int i = 0; i < n; i++) {
        if (i > len)
            break;
        dest[i] = src[i];
    }
    return (dest);
}
