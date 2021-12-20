/*
** EPITECH PROJECT, 2021
** isalpha
** File description:
** 1 if is alpha else 0
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            continue;
        if (str[i] >= 'a' && str[i] <= 'z')
            continue;
        return (0);
    }
    return (1);
}
