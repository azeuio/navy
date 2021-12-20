/*
** EPITECH PROJECT, 2021
** put nbr base
** File description:
** prints decimal number unsing base
*/

#include <stdlib.h>
#include "my.h"

int *get_powers_of_base(int n, int base)
{
    int len = get_nbr_len_in_base(n, base);
    int *result = malloc(sizeof(int) * (len + 1));
    int i = 0;

    while (n != 0) {
        result[len - i - 1] = -(n % base);
        i++;
        n /= base;
    }
    result[len] = -1;
    return (result);
}

void my_putnbr_base(int nbr, char const *base_str)
{
    if (nbr == 0) {
        my_putchar('0');
        return;
    }
    if (nbr < 0)
        my_putchar('-');
    else
        nbr = -nbr;
    int *powers_of_base = get_powers_of_base(nbr, my_strlen(base_str));
    int i = 0;
    while (powers_of_base[i] != -1) {
        my_putchar(base_str[powers_of_base[i]]);
        i++;
    }
}

void my_putnbr_base_unsigned(unsigned int nbr, char const *base_str)
{
    if (nbr == 0) {
        my_putchar('0');
        return;
    }
    int *powers_of_base = get_powers_of_base(nbr, my_strlen(base_str));
    int i = 0;
    while (powers_of_base[i] != -1) {
        my_putchar(base_str[powers_of_base[i]]);
        i++;
    }
}

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
    int *powers_of_base = \
    get_powers_of_base_unsigned_ull(nbr, my_strlen(base_str));
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
    int *powers_of_base = \
    get_powers_of_base_unsigned_uh(nbr, my_strlen(base_str));
    int i = 0;
    while (powers_of_base[i] != -1) {
        my_putchar(base_str[powers_of_base[i]]);
        i++;
    }
}
