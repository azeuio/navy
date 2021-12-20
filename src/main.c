/*
** EPITECH PROJECT , 2026
** navy
** File description:
** main
*/

#include "navy.h"
#include "my.h"

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return print_help();
    my_printf("Main function\n");
    return 0;
}