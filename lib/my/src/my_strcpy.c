/*
** EPITECH PROJECT, 2021
** strcpy
** File description:
** clone of strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(src);

    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return (dest);
}
