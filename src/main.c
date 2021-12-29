/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main
*/

#include "navy.h"
#include "my.h"
#include <stddef.h>
#include <unistd.h>
#include <signal.h>

static int player1_start_game(char **av)
{
    board_t my = load_board(av[1]);

    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    get_connection();
    my_printf("ennemy connected\n");
    game(my, 1);
    return 0;
}

static int player2_start_game(char **av)
{
    board_t my = load_board(av[2]);

    connect_to(my_getnbr(av[1]), getpid());
    game(my, 2);
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return print_help();
    if (ac == 2)
        player1_start_game(av);
    else if (ac == 3)
        player2_start_game(av);
    else
        return 84;
    // if (ac != 3)
    //     return 84;
    // my_printf("Main function\n");
    // board_p1 = load_board(av[1]);
    // board_p2 = load_board(av[2]);
    // if (board_p1 == NULL || board_p2 == NULL) {
    //     my_printf("Board of player%d couldn't be loaded. (%s)\n",
    //     (board_p2 == NULL) + 1, av[1 + (board_p2 == NULL)]);
    //     return 84;
    // }
    // game(board_p1, board_p2, 1);
    // board_destroy(board_p1);
    // board_destroy(board_p2);
    return 0;
}