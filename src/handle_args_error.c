/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** handle_arg_error
*/

#include "navy.h"
#include "my.h"

int handle_args_error(const int ac, const char **av)
{
    if (!(2 <= ac && ac <= 3)) {
        my_printf("%s: Invalid number of arguments", av[0]);
        my_printf(" (got %d, expected 2 or 3).\n", ac);
        return 1;
    }
    if (ac == 3) {
        if (!my_str_isnum(av[1])) {
            my_printf("%s: Invalid pid (should be a number).\n", av[0]);
            return 1;
        }
    }
    if (!file_is_valid(av[1 + (ac == 3)])) {
        my_printf("%s: Given file path does not lead to a "
        "valid file.\n", av[0]);
        return 1;
    }
    return 0;
}
