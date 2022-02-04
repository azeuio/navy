/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main
*/

#include "navy.h"
#include "my.h"
#include <stddef.h>
#define _GNU_SOURCE
#include <unistd.h>
#include <signal.h>

static int player1_start_game(const char **av)
{
    board_t my = load_board(av[1]);

    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    wait_for_connection();
    my_printf("enemy connected\n");
    game(my, 1);
    return 0;
}

static int player2_start_game(const char **av)
{
    board_t my = load_board(av[2]);
    int my_pid = getpid();
    struct sigaction act = {0};

    act.sa_handler = counter;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    my_printf("my_pid: %d\n", my_pid);
    if (connect_to(my_getnbr(av[1])) == 84) {
        board_destroy(my);
        return 84;
    }
    game(my, 2);
    return 0;
}

int main(const int ac, const char **av)
{
    if ((av_contains(av, "-h") || av_contains(av, "--help")))
        return print_help();
    if (handle_args_error(ac, av)) {
        my_printf("Try: '%s --help' for more information\n", av[0]);
        return 84;
    }
    if (ac == 2)
        player1_start_game(av);
    else if (ac == 3)
        player2_start_game(av);
    else
        return 84;
    return 0;
}
