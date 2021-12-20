/*
** EPITECH PROJECT, 2021
** strcapitalize
** File description:
** capitalize str
*/

#include "my.h"

static int is_char_at_idx_start_of_word(char *str, int idx)
{
    char char_str[2] = {str[idx], 0};
    char prev_char_str[2] = {str[idx - 1], 0};

    if (idx == 0)
        return (1);
    if (my_str_isalpha(char_str) && !my_str_isalpha(prev_char_str))
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int len = my_strlen(str);
    char curr_c[2] = {0, 0};

    if (len == 0)
        return (str);
    for (int i = 0; i < len; i++) {
        curr_c[0] = str[i];
        if (!my_str_isalpha(curr_c))
            continue;
        if (is_char_at_idx_start_of_word(str, i) && my_str_islower(curr_c))
            str[i] -= 32;
        if (!is_char_at_idx_start_of_word(str, i) && my_str_isupper(curr_c))
            str[i] += 32;
    }
    return (str);
}
