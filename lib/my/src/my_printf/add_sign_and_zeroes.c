/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** add_sign_and_zeroes
*/

#include "my.h"
#include "my_printf.h"

static void add_zeros_switch\
(unsigned long long n, char *format, char specifier, int size)
{
    int h_ff = n != 0 ? format[hash_fflag] * (format[precision_fflag] == 0): 0;

    switch (specifier)
    {
        case 'd':
            print_x_char(size - get_nbr_len_in_base(n, 10), '0');
            break;
        case 'x':
            print_x_char(size - get_nbr_len_in_base(n, 16) - h_ff * 2, '0');
            break;
        case 'o':
            print_x_char(size - get_nbr_len_in_base(n, 8) - h_ff, '0');
            break;
        case 'b':
            print_x_char(size - get_nbr_len_in_base(n, 2), '0');
            break;
    }
}

void add_zeros(unsigned long long n, char *format, char specifier)
{
    int size = (format[zero_fflag] == 1 && format[precision_fflag] == 0) ? \
    format[width_fflags] : format[precision_fflag];

    if (size == 0)
        return;
    specifier = specifier == 'X' ? 'x' : (specifier == 'i' ? 'd' : specifier);
    add_zeros_switch(n, format, specifier, size);
}

void add_sign(unsigned long long n, char *format, char specifier)
{
    specifier = specifier == 'X' ? 'x' : (specifier == 'i' ? 'd' : specifier);
    if (specifier == 'd' && format[signed_fflag] == 1) {
        my_putstr(((int)n >= 0) ? "+" : "-");
        return;
    }
    if (!(specifier == 'd' && format[signed_fflag] == 0))
        return;
    if (format[len_fflag] == 0 && (int)n < 0 && (int)n != -2147483648)
        my_putstr("-");
    if (format[len_fflag] == 'h' && (short)n < 0 && (short)n != -32768)
        my_putstr("-");
    if (format[len_fflag] == 'l' && (long long)n < 0)
        my_putstr("-");
}