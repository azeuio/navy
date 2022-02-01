/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** print_arg
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static int printf_nbr_switch\
(char *str, int specifer_idx, unsigned long long n)
{
    switch (str[specifer_idx]) {
        case 'o':
            my_put_nbr_base_unsigned_ull(n, "01234567");
            return 0;
        case 'x':
            my_put_nbr_base_unsigned_ull(n, "0123456789abcdef");
            return 0;
        case 'X':
            my_put_nbr_base_unsigned_ull(n, "0123456789ABCDEF");
            return 0;
        case 'b':
            my_put_nbr_base_unsigned_ull(n, "01");
            return 0;
        case 'u':
            my_put_nbr_base_unsigned_ull(n, "0123456789");
            return 0;
        default:
            return 1;
    }
}

static unsigned long long get_nbr_arg(char format_len_fflag, va_list *ap)
{
    switch (format_len_fflag) {
        case 'l':
            return va_arg(*ap, long long);
        case 'h':
            return va_arg(*ap, int) & 0b1111111111111111;
        case 0:
            return va_arg(*ap, int) & 0b11111111111111111111111111111111;
    }
    return 0;
}

static void printf_nbr(char *str, int *i, int specifer_idx, va_list *ap)
{
    char *format;
    unsigned long long n;

    get_format_flag(&format, str, i, specifer_idx);
    n = get_nbr_arg(format[len_fflag], ap);
    add_prefix(n, format, str[specifer_idx]);
    if (printf_nbr_switch(str, specifer_idx, n) == 0) {
        free(format);
        return;
    }
    if (format[len_fflag] == 0)
        my_put_nbr(((int)n < 0) ? -n : n);
    else if (format[len_fflag] == 'h')
        my_put_nbr_h(((short)n < 0 && (short)n != -32768) ? -n : n);
    else
        my_put_nbr_base_unsigned_ull(n, "0123456789");
    add_suffix(n, format, str[specifer_idx]);
    free(format);
}

static void print_str_or_nbr_arg\
(int specifier_idx, char *str, int *i, va_list *ap)
{
    switch (str[specifier_idx]) {
        case 's':
            my_putstr(va_arg(*ap, char *));
            break;
        case 'S':
            showstr_octal(va_arg(*ap, char *));
            break;
        case 'c':
            my_putchar(va_arg(*ap, int));
            break;
        case 'p':
            my_putstr("0x");
            my_put_nbr_base_unsigned_ull(va_arg(*ap, long long),
            "0123456789abcdef");
            break;
        default:
            printf_nbr(str, i, specifier_idx, ap);
            break;
    }
}

int print_arg(char *str, int *i, va_list *ap)
{
    int specifier_idx = get_specifier_idx(str, *i);

    if (specifier_idx == -1)
        return (84);
    if (str[specifier_idx] == '%')
        my_putchar('%');
    else
        print_str_or_nbr_arg(specifier_idx, str, i, ap);
    (*i) = specifier_idx;
    return 0;
}
