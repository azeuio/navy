/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main
*/

#include "navy.h"
#include "my.h"
#include <stddef.h>

int main(int ac, char **av)
{
    board_t board_p1;
    board_t board_p2;

    if (ac < 2)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return print_help();
    if (ac != 3)
        return 84;
    my_printf("Main function\n");
    board_p1 = load_board(av[1]);
    board_p2 = load_board(av[2]);
    if (board_p1 == NULL || board_p2 == NULL) {
        my_printf("Board of player%d couldn't be loaded. (%s)\n",
        (board_p2 == NULL) + 1, av[1 + (board_p2 == NULL)]);
        return 84;
    }
    game(board_p1, board_p2, 1);
    board_destroy(board_p1);
    board_destroy(board_p2);
    return 0;
}