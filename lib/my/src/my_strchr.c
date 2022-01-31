/*
** EPITECH PROJECT, 2021
** myradar
** File description:
** my_strchr
*/

#include "my.h"
#include <stddef.h>

char *my_strchr(const char *str, const int c)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c)
            return (char *)(str) + i;
    }
    return NULL;
}
