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
    int my_pid = getpid();

    my_printf("my_pid: %d\n", my_pid);
    connect_to(my_getnbr(av[1]), my_pid);
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
    return 0;
}