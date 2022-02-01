/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** connect_to
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "navy.h"

Test(connect_to, connect_to_self, .signal=SIGUSR1)
{
    int pid = getpid();
    int child_pid = fork();

    if (child_pid == 0)
        connect_to(pid);
    else {
        usleep(100);
        kill(child_pid, SIGUSR2);
    }
}