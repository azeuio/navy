/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** returns a pointer to the first occurrence in str of the entire sequence
** of characters specified in to_find,
** or a null pointer if the sequence is not present in haystack.
*/

#include <stddef.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int str_len = my_strlen(str);
    int to_find_len = my_strlen(to_find);

    for (int i = 0; i < str_len; i++) {
        if (my_strncmp(str+i, to_find, to_find_len) == 0)
            return (str+i);
    }
    return (NULL);
}
