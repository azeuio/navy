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

int enemy_pid = -1;

int counter(int sig)
{
    static int cntr = 0;
    static int last_cntr = 0;

    if (sig == 0)
        return cntr;
    if (sig == -1)
        return last_cntr;
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
    return 0;
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
    do {
        pause();
    } while (counter(0) != 0);
    return counter(-1);
}
