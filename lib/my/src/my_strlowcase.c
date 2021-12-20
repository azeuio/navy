/*
** EPITECH PROJECT, 2021
** strcase
** File description:
** turns str to lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return (str);
}
