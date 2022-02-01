/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** add_padding
*/

#include "my.h"
#include "my_printf.h"

static int get_padding_size(unsigned long long n, int base, char *format)
{
    return format[width_fflags] - format[precision_fflag] -
    (get_nbr_len_in_base(n, base)) *
    ((get_nbr_len_in_base(n, base)) > format[precision_fflag]) -
    format[signed_fflag];
}

static void add_padding_switch(unsigned long long n, char *format,
char specifier, char c)
{
    int h_ff = (n != 0 ? format[hash_fflag] : 0);

    switch (specifier) {
        case 'd':
            print_x_char(get_padding_size(n, 10, format), c);
            break;
        case 'x':
            print_x_char(get_padding_size(n, 16, format) - h_ff * 2, c);
            break;
        case 'o':
            print_x_char(get_padding_size(n, 8, format) - h_ff, c);
            break;
        case 'b':
            print_x_char(get_padding_size(n, 2, format), c);
            break;
    }
}

void add_padding(unsigned long long n, char *format, char specifier, char c)
{
    int size = format[width_fflags] - format[precision_fflag]\
    - format[signed_fflag];

    if (size <= 0 || (format[zero_fflag] == 1 && format[precision_fflag] == 0))
        return;
    if (format[zero_fflag] == 1 && format[precision_fflag] != 0)
        c = ' ';
    specifier = specifier == 'X' ? 'x' : (specifier == 'i' ? 'd' : specifier);
    add_padding_switch(n, format, specifier, c);
}
