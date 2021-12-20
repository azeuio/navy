/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** get_word_count
*/

#include "my.h"

int get_word_count(char const *str)
{
    int i = 0;
    int in_word = 0;
    int result = 0;

    while (str[i] != '\0') {
        if (!my_isalnum(str[i]) && in_word) {
            in_word = 0;
        }
        if (my_isalnum(str[i]) && !in_word) {
            in_word = 1;
            result++;
        }
        i++;
    }
    return (result);
}