/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** av_contains
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "navy.h"

const char *av[5] = {
    "./navy",
    "hello",
    "--help",
    "12345",
    NULL
};

const char *av_empty[1] = {
    NULL
};

Test(av_contains, contains_first)
{
    cr_assert(av_contains(av, "./navy"));
}

Test(av_contains, contains_last)
{
    cr_assert(av_contains(av, "12345"));
}

Test(av_contains, contains_middle)
{
    cr_assert(av_contains(av, "--help"));
}

Test(av_contains, do_not_contain)
{
    int got = av_contains(av, "-h");
    cr_assert_eq(got, 0, "expected %d expected %d", 0, got);
}

Test(av_contains, empty_av)
{
    int got = av_contains(av_empty, "-h");
    cr_assert_eq(got, 0, "expected %d expected %d", 0, got);
}
