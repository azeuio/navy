/*
** EPITECH PROJECT, 2021
** showstr
** File description:
** prints char to terminal if printable else \hex
*/

#include "my.h"

void my_showstr(char const *str)
{
    int len = my_strlen(str);
    char temp[0];

    for (int i = 0; i < len; i++) {
        temp[0] = str[i];
        if (my_str_isprintable(temp)) {
            my_putchar(str[i]);
            continue;
        }
        my_putchar('\\');
        if (get_nbr_len_in_base(str[i], 16) % 2)
            my_putchar('0');
        my_putnbr_base(str[i], "0123456789abcdef");
    }
}
