/*
** EPITECH PROJECT, 2021
** isnum
** File description:
** 1 if is num else 0
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        return (0);
    }
    return (1);
}
