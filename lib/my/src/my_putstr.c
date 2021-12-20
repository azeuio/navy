/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Displays the character of a string
*/

#include "my.h"
#include <stddef.h>

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    if (str[0] == '\0') {
        my_putchar('\0');
    }
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
