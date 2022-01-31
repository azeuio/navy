/*
** EPITECH PROJECT, 2021
** strcmp
** File description:
** strcmp clone
*/

#include <stddef.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int len1;
    int len2;
    int maxlen;

    if (s1 == NULL && s2 != NULL)
        return (-s2[0]);
    if (s1 != NULL && s2 == NULL)
        return (s1[0]);
    if (s1 == NULL && s2 == NULL)
        return (0);
    len1 = my_strlen(s1);
    len2 = my_strlen(s2);
    maxlen = len1 > len2 ? len1 : len2;
    for (; i < maxlen; i++) {
        if (s1[i] - s2[i] != 0)
            return (s1[i] - s2[i]);
    }
    return (0);
}
