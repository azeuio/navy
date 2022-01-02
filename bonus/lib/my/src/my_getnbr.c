/*
** EPITECH PROJECT, 2021
** number getter
** File description:
** Transforms str_int to int
*/

#include "my.h"

int is_more_than_inf(char const *num, int int_start, int int_end, int is_neg)
{
    char *max = "2147483647";
    char *min = "2147483648";
    int max_len = my_strlen(max);
    
    if (int_end - int_start > max_len)
        return (1);
    if (int_end - int_start < max_len)
        return (0);
    if (my_strcmp((num + int_start), max) == 0 && is_neg == 0)
        return (0);
    if (my_strcmp((num + int_start), min) == 0 && is_neg == 1)
        return (0);
    for (int i = int_start; i < int_end; i++) { 
        if (num[i] < max[i - int_start])
            return (0);
    }
    return (1);
}

static void get_int_range(char const *str, int *start, int *end, int *is_neg)
{
    int strlen = my_strlen(str);

    *end = strlen;
    for (int i = 0; i < strlen; i++) {
        if (str[i] == '-' && *start == -1) {
            *is_neg = !(*is_neg);
            continue;
        }
        if ((str[i] >= '0' && str[i] <= '9') && *start == -1)
            *start = i;
        if ((str[i] < '0' || str[i] > '9') && *start == -1)
            continue;
        if ((str[i] < '0' || str[i] > '9') && *start != -1) {
            *end = i;
            return;
        }
    }
}

static void transform_str_in_nbr(char const *str, int *n, int start, int end)
{
    int len = end - start;
    
    for (int i = start; i <= end; i++) {
        *n += my_compute_power_rec(10, len - 1) * (str[i] - '0');
        len--;
    }
}

int my_getnbr(char const *str)
{
    int int_end = 0;
    int int_start = -1;
    int n = 0;
    int is_neg = 0;

    get_int_range(str, &int_start, &int_end, &is_neg);
    if (int_start == -1)
        return (0);
    if (is_more_than_inf(str, int_start, int_end, is_neg)) {
        return (0);
    }
    transform_str_in_nbr(str, &n, int_start, int_end);
    if (is_neg == 1)
        n *= -1;
    return (n);
}
