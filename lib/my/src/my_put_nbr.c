/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Displays the number given as a parameter
*/

#include "my.h"

static int my_pow(int a, int b)
{
    int temp = 1;

    for (int i = 0; i < b; i++) {
        temp *= a;
    }
    return (temp);
}

static int get_int_lenght(int n)
{
    int len = 1;

    if (n == 0)
        return (0);
    while (n > 9) {
        len++;
        n /= 10;
    }
    return (len);
}

void print_nbr(int nb)
{
    int truncated;

    for (int len = get_int_lenght(nb) - 1; len >= 0; len--) {
        truncated = nb / my_pow(10, len);
        my_putchar('0' + truncated % 10);
    }
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        if (nb < -2147483647) {
            my_putstr("2147483648");
            return (0);
        }
    }
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    print_nbr(nb);
    return (0);
}

int my_put_nbr_h(short nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        if (nb < -32767) {
            my_putstr("32768");
            return (0);
        }
    }
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    print_nbr(nb);
    return (0);
}
