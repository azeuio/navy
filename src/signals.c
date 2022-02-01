/*
** EPITECH PROJECT, 2021
** navy
** File description:
** signals
*/

#include "my.h"
#include "navy.h"
#define _GNU_SOURCE
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

static int cntr = 0;
static int last_cntr = 0;
int ennemy_pid = -1;

void signal_handler(int sig)
{
    switch (sig) {
        case SIGUSR1:
            last_cntr = cntr;
            cntr++;
            break;
        case SIGUSR2:
            cntr = 0;
            break;
        default:
            break;
    }
}

void send_signal(int destination, int n)
{
    usleep(100);
    for (int i = 0; i <= n; i++) {
        kill(destination, SIGUSR1);
        usleep(100);
    }
    kill(destination, SIGUSR2);
}

int receive_signal(void)
{
    last_cntr = 0;
    cntr = 0;
    do {
        pause();
    } while (cntr != 0);
    return last_cntr;
}

void set_ennemy_pid(int sig, siginfo_t *info, void *context)
{
    ennemy_pid = info->si_pid;
}

int wait_for_connection(void)
{
    struct sigaction act = {0};

    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO | SA_RESTART;
    act.sa_sigaction = set_ennemy_pid;
    sigaction(SIGUSR1, &act, NULL);
    pause();
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = NULL;
    act.sa_handler = signal_handler;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    send_signal(ennemy_pid, 1);
}

int connect_to(int destination)
{
    ennemy_pid = destination;
    kill(destination, SIGUSR1);
    receive_signal();
    my_printf("successfully connected\n");
    return 0;
}