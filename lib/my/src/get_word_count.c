/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** get_word_count
*/

#include "my.h"
#include <stddef.h>

int get_word_count(const char *str, const char *separators)
{
    int word_count = 1;
    int len = my_strlen(str);
    int i = 0;

    if (len == 0)
        return 0;
    for (i = 0; i < len; i++) {
        if (my_strchr(separators, str[i]) != NULL)
            word_count++;
    }
    return word_count;
}
