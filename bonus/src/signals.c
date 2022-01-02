/*
** EPITECH PROJECT, 2021
** navy
** File description:
** signals
*/

#include "my.h"
#include "navy.h"
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

int get_connection(void)
{
    int connection = receive_signal();

    send_signal(connection, 42);
    ennemy_pid = connection;
    return connection;
}

int connect_to(int destination, int pid)
{
    ennemy_pid = destination;
    send_signal(destination, pid);
    receive_signal();
    my_printf("successfully connected\n");
    return 0;
}