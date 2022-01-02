/*
** EPITECH PROJECT, 2021
** revstr
** File description:
** reversstr
*/

#include "my.h"

static void my_swap_char(char *c, char *c2)
{
    char tmp = *c2;
    *c2 = *c;
    *c = tmp;
}

char *my_revstr(char *str)
{
    int len = my_strlen(str);

    if (str[0] == '\0')
        return (str);
    for (int i = 0; i < len / 2; i++) {
        my_swap_char(&str[i], &str[len - i - 1]);
    }
    return str;
}
