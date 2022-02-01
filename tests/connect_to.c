/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** connect_to
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include "navy.h"

Test(connect_to, connect_to_self, .signal=SIGUSR1, .init=cr_redirect_stdout)
{
    int pid = getpid();
    int child_pid = fork();

    if (child_pid == 0)
        cr_assert_eq(connect_to(pid), 0);
    else {
        usleep(100);
        kill(child_pid, SIGUSR2);
    }
}

Test(connect_to, connect_to_1, .init=cr_redirect_stdout)
{
    int got = connect_to(1);

    cr_assert_eq(got, 84);
}