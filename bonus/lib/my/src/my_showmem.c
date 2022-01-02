/*
** EPITECH PROJECT, 2021
** show mem
** File description:
** prints a memory dump and return 0
*/

#include "my.h"

static void print_address(int *address)
{
    int address_len = get_nbr_len_in_base(*address, 16);

    for (int i = 0; i < 8 - (address_len % 8); i++) {
        my_putchar('0');
    }
    my_putnbr_base(*address, "0123456789abcdef");
    my_putstr(": ");
}

static void print_hexcontent(char const *str, int line, int size)
{
    int file_has_ended = 0;
    int tempint = 0;

    for (int c = 0; c < 16; c++) {
        if (str[c + line * 16] == '\0' || (c + line * 16) >= size)
            file_has_ended = 1;
        if (file_has_ended == 1) {
            my_putstr("  ");
        } else {
            tempint = get_nbr_len_in_base(str[c + line * 16], 16);
            for (int k = 0; k < tempint % 2; k++)
                my_putchar('0');
            my_putnbr_base(str[c + line * 16], "0123456789abcdef");
        }
        if (c % 2 == 1)
            my_putchar(' ');
    }
}

static void print_formated_content(char const *str, int line, int size)
{
    int file_has_ended = 0;
    char tempstr[2] = " ";

    for (int i = 0; i < 16; i++) {
        if (str[i + line * 16] == '\0' || (i + line * 16) >= size)
            file_has_ended = 1;
        if ((i + line * 16) >= size && (i + line * 16) % 16 == 0) {
            my_putchar('\n');
            return;
        }
        tempstr[0] = str[i + line * 16];
        if (file_has_ended == 1)
            return;
        if (my_str_isprintable(tempstr) == 0) {
            my_putchar('.');
            continue;
        }
        my_putchar(str[i + line * 16]);
    }
}

int my_showmem(char const *str, int size)
{
    int line = 0;

    if (my_strlen(str) == 0 || size < 0)
        return (0);
    while (1) {
        if ((line * 16) >= size)
            return (0);
        print_address((int *)(str + line * 16));
        print_hexcontent(str, line, size);
        print_formated_content(str, line, size);
        my_putchar('\n');
        line++;
    }
}
