/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** connection
*/

#define _GNU_SOURCE
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include "navy.h"
#include "my.h"

void set_enemy_pid(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1)
        enemy_pid = info->si_pid;
}

int wait_for_connection(void)
{
    struct sigaction act = {0};

    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO | SA_RESTART;
    act.sa_sigaction = set_enemy_pid;
    sigaction(SIGUSR1, &act, NULL);
    pause();
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = NULL;
    act.sa_handler = counter;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    send_signal(enemy_pid, 0);
    return 0;
}

int connect_to(int destination)
{
    int error_while_connecting = kill(destination, SIGUSR1);

    if (error_while_connecting) {
        my_printf("connection failed\n");
        return 84;
    }
    enemy_pid = destination;
    receive_signal();
    my_printf("successfully connected\n");
    return 0;
}
