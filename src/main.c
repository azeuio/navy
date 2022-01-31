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

static int handle_args_error(int ac, char **av)
{
    if (!(2 <= ac && ac <= 3)) {
        my_printf("%s: Invalid number of arguments", av[0]);
        my_printf(" (got %d, expected 2 or 3).\n", ac);
        return 1;
    }
    return 0;
}

static int av_contains(const char **av, const char *str)
{
    for (int i = 0; av[i] != NULL; i++) {
        if (my_strstr(av[i], str) == 0)
            return 1;
    }
    my_printf("hi\n");
    return 0;
}

int main(int ac, char **av)
{
    if ((av_contains(av, "-h") || av_contains(av, "--help")))
        return print_help();
    if (handle_args_error(ac, av)) {
        my_printf("Try: '%s --help' for more information\n", av[0]);
        return 84;
    }
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    if (ac == 2)
        player1_start_game(av);
    else if (ac == 3)
        player2_start_game(av);
    else
        return 84;
    return 0;
}