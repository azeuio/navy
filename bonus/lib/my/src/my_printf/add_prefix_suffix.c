/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** add_prefix
*/

#include "my.h"
#include "my_printf.h"

void add_prefix(unsigned long long n, char *format, char specifier)
{
    int left_justify = format[left_justify_fflag];
    if (!left_justify)
        add_padding(n, format, specifier, format[zero_fflag] == 1 ? '0' : ' ');
    if (format[hash_fflag] != 0 && n != 0) {
        if (specifier == 'X' || specifier == 'x') {
            my_putchar('0');
            my_putchar(specifier);
        }
        if (specifier == 'o')
            my_putstr("0");
    }
    add_sign(n, format, specifier);
    add_zeros(n, format, specifier);
}

void add_suffix(unsigned long long n, char *format, char specifier)
{
    int left_justify = format[left_justify_fflag];
    if (!left_justify)
        return;
    format[hash_fflag] = 0;
    add_padding(n, format, specifier, ' ');
}