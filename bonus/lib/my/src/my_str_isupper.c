/*
** EPITECH PROJECT, 2021
** islower
** File description:
** islower clone
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if(!(str[i] >= 'A' && str[i] <= 'Z'))
            return (0);
    }
    return (1);
}
