/*
** EPITECH PROJECT, 2021
** strupcase
** File description:
** turns str to uppercase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return (str);
}
