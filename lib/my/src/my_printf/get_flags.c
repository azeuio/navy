/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get_flags
*/

#include "my.h"
#include "my_printf.h"
#include <stdlib.h>

static void add_format_flag(char **all_flags, char c)
{
    switch (c) {
        case '-':
            (*all_flags)[left_justify_fflag] = 1;
            break;
        case '+':
            (*all_flags)[signed_fflag] = 1;
            break;
        case ' ':
            (*all_flags)[space_fflag] = 1;
            break;
        case '#':
            (*all_flags)[hash_fflag] = 1;
            break;
        case '0':
            (*all_flags)[zero_fflag] = 1;
            break;
        default:
            break;
    }
}

static void add_width_and_len_flag(char **all_flags, int *j, char *str)
{
    switch (str[*j]) {
        case '.':
            (*all_flags)[precision_fflag] = my_getnbr(str + (*j));
            (*j) += get_nbr_len_in_base((*all_flags)[precision_fflag], 10) + 1;
            break;
        case 'h':
            (*all_flags)[len_fflag] = 'h';
            break;
        case 'l':
            (*all_flags)[len_fflag] = 'l';
            break;
        default:
            break;
    }
    if (my_isnum(str[*j]) && str[*j] != '0') {
        (*all_flags)[width_fflags] = my_getnbr(str + (*j));
        (*j) += get_nbr_len_in_base((*all_flags)[width_fflags], 10) - 1;
    }
}

void get_format_flag(char **all_flags, char *str, int *i, int flag_idx)
{
    (*all_flags) = malloc(sizeof(char) * 9);
    for (int k = 0; k < 9; k++)
        (*all_flags)[k] = 0;
    for (int j = (*i); j < flag_idx; j++) {
        add_format_flag(all_flags, str[j]);
        add_width_and_len_flag(all_flags, &j, str);
    }
}
