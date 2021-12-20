/*
** EPITECH PROJECT , 2026
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
    if (ac < 2)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return print_help();
    my_printf("Main function\n");
    board_p1 = load_board(av[1]);
    if (board_p1 == NULL)
        return 84;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            my_printf("%d ", board_p1[i][j]);
        }
        my_printf("\n");
    }
    board_destroy(board_p1);
    return 0;
}