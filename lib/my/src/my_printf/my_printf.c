/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

void showstr_octal(char *str)
{
    int i = -1;

    do {
        i++;
        if (!my_isprint(str[i])) {
            my_putchar('\\');
            my_putnbr_base(str[i], "01234567");
            continue;
        }
        my_putchar(str[i]);
    } while (str[i] != '\0' && str[i + 1] != '\0');
}

void print_x_char(int x, char c)
{
    for (int i = 0; i < x; i++)
        my_putchar(c);
}

int get_specifier_idx(char *str, int i)
{
    char str_char[2] = " ";

    while (str[i] != '\0') {
        str_char[0] = str[i];
        if (my_strstr("psScoxXbudi%", str_char))
            return i;
        i++;
    }
    return -1;
}

int my_printf(char *str, ...)
{
    va_list ap;
    int print_arg_result = 0;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (print_arg_result == 84)
            return 84;
        print_arg_result = 0;
        if (str[i] == '%') {
            i++;
            print_arg_result = print_arg(str, &i, &ap);
            continue;
        }
        my_putchar(str[i]);
    }
    va_end(ap);
    return 0;
}
