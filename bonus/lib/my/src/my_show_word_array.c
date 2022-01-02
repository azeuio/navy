/*
** EPITECH PROJECT, 2021
** show_word_array
** File description:
** shows an array of word
*/

#include "my.h"

void my_show_word_array(char **arr)
{
    int i = 0;
    
    while (arr[i] != 0) {
        my_putstr(arr[i]);
        my_putchar('\n');
        i++;
    }
}
