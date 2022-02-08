/*
** EPITECH PROJECT, 2021
** myradar
** File description:
** my_put_nbr_base_unsigned
*/

#include "my.h"
#include <stdlib.h>

static void fill(int result[], int value, int len)
{
    for (int i = 0; i < len; i++) {
        result[i] = value;
    }
}

int *get_powers_of_base_unsigned_ull(unsigned long long n, int base)
{
    int len = get_nbr_len_in_base_unsigned(n, base);
    int *result = malloc(sizeof(int) * (len + 1));
    int i = 0;

    fill(result, 0, len + 1);
    while (n != 0) {
        result[len - i - 1] = n % base;
        i++;
        n /= base;
    }
    result[len] = -1;
    return (result);
}

void my_put_nbr_base_unsigned_ull(unsigned long long nbr, char const *base_str)
{
    if (nbr == 0) {
        my_putchar('0');
        return;
    }
    int *powers_of_base = get_powers_of_base_unsigned_ull(nbr,
    my_strlen(base_str));
    int i = 0;
    while (powers_of_base[i] != -1) {
        my_putchar(base_str[powers_of_base[i]]);
        i++;
    }
}

int *get_powers_of_base_unsigned_uh(unsigned short n, int base)
{
    int len = get_nbr_len_in_base_unsigned(n, base);
    int *result = malloc(sizeof(int) * (len + 1));
    int i = 0;

    fill(result, 0, len + 1);
    while (n != 0) {
        result[len - i - 1] = n % base;
        i++;
        n /= base;
    }
    result[len] = -1;
    return (result);
}

void my_put_nbr_base_unsigned_uh(unsigned short nbr, char const *base_str)
{
    if (nbr == 0) {
        my_putchar('0');
        return;
    }
    int *powers_of_base = get_powers_of_base_unsigned_uh(nbr,
    my_strlen(base_str));
    int i = 0;
    while (powers_of_base[i] != -1) {
        my_putchar(base_str[powers_of_base[i]]);
        i++;
    }
}
